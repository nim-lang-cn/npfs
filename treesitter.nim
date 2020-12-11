{.experimental: "codeReordering".}
import strformat
import strutils, os
import tables
import sets
import json
import osproc
import hashes
import sequtils
import macros
import streams
import algorithm
import compiler/[ast, idents, modulegraphs, options]

import strformat
import tables
import sets
import algorithm
import sequtils
import strutils

type 
  Vertex* = ref object
    indegree: int
    name: string
    edge: HashSet[string]

proc topoSort*(gl: var OrderedTable[string, Vertex]):seq[string] = 
  var zeroIndegree: seq[string]
  for f,vertex in gl.mpairs:
    var indegree = vertex.indegree
    # echo fmt"{f} with indegree {indegree}"
    if indegree == 0:
      zeroIndegree.add f
  
  while zeroIndegree.len > 0:
    var z = zeroIndegree.pop
    result.add z

    for e in gl[z].edge:
      gl[e].indegree.dec
      for f,vertex in gl.mpairs:
        if f notin result and f notin zeroIndegree and vertex.indegree == 0:
          zeroIndegree.add f
  

proc addEdge*(gl: OrderedTable,k:string,v:string) =
  if not gl[k].edge.contains v:
    gl[k].edge.incl v
    gl[v].inDegree.inc


proc initVertex*(gl:var OrderedTable, k:varargs[string]) =
  for i in k:
    gl[i] = Vertex(name: i)


macro defineEnum(typ: untyped): untyped =
  result = newNimNode(nnkStmtList)

  # Enum mapped to distinct cint
  result.add quote do:
    type `typ`* = distinct cint

  for i in ["+", "-", "*", "div", "mod", "shl", "shr", "or", "and", "xor", "<", "<=", "==", ">", ">="]:
    let
      ni = newIdentNode(i)
      typout = if i[0] in "<=>": newIdentNode("bool") else: typ # comparisons return bool
    if i[0] == '>': # cannot borrow `>` and `>=` from templates
      let
        nopp = if i.len == 2: newIdentNode("<=") else: newIdentNode("<")
      result.add quote do:
        proc `ni`*(x: `typ`, y: cint): `typout` = `nopp`(y, x)
        proc `ni`*(x: cint, y: `typ`): `typout` = `nopp`(y, x)
        proc `ni`*(x, y: `typ`): `typout` = `nopp`(y, x)
    else:
      result.add quote do:
        proc `ni`*(x: `typ`, y: cint): `typout` {.borrow.}
        proc `ni`*(x: cint, y: `typ`): `typout` {.borrow.}
        proc `ni`*(x, y: `typ`): `typout` {.borrow.}
    result.add quote do:
      proc `ni`*(x: `typ`, y: int): `typout` = `ni`(x, y.cint)
      proc `ni`*(x: int, y: `typ`): `typout` = `ni`(x.cint, y)

  let
    divop = newIdentNode("/")   # `/`()
    dlrop = newIdentNode("$")   # `$`()
    notop = newIdentNode("not") # `not`()
  result.add quote do:
    proc `divop`*(x, y: `typ`): `typ` = `typ`((x.float / y.float).cint)
    proc `divop`*(x: `typ`, y: cint): `typ` = `divop`(x, `typ`(y))
    proc `divop`*(x: cint, y: `typ`): `typ` = `divop`(`typ`(x), y)
    proc `divop`*(x: `typ`, y: int): `typ` = `divop`(x, y.cint)
    proc `divop`*(x: int, y: `typ`): `typ` = `divop`(x.cint, y)

    proc `dlrop`*(x: `typ`): string {.borrow.}
    proc `notop`*(x: `typ`): `typ` {.borrow.}

defineEnum(TSInputEncoding)
defineEnum(TSSymbolType)
defineEnum(TSLogType)
defineEnum(TSQueryPredicateStepType)
defineEnum(TSQueryError)

const
  TREE_SITTER_LANGUAGE_VERSION* = 11
  TREE_SITTER_MIN_COMPATIBLE_LANGUAGE_VERSION* = 9
  TSInputEncodingUTF8* = (0).TSInputEncoding
  TSInputEncodingUTF16* = (TSInputEncodingUTF8 + 1).TSInputEncoding
  TSSymbolTypeRegular* = (0).TSSymbolType
  TSSymbolTypeAnonymous* = (TSSymbolTypeRegular + 1).TSSymbolType
  TSSymbolTypeAuxiliary* = (TSSymbolTypeAnonymous + 1).TSSymbolType
  TSLogTypeParse* = (0).TSLogType
  TSLogTypeLex* = (TSLogTypeParse + 1).TSLogType
  TSQueryPredicateStepTypeDone* = (0).TSQueryPredicateStepType
  TSQueryPredicateStepTypeCapture* = (TSQueryPredicateStepTypeDone + 1).TSQueryPredicateStepType
  TSQueryPredicateStepTypeString* = (TSQueryPredicateStepTypeCapture + 1).TSQueryPredicateStepType
  TSQueryErrorNone* = (0).TSQueryError
  TSQueryErrorSyntax* = (TSQueryErrorNone + 1).TSQueryError
  TSQueryErrorNodeType* = (TSQueryErrorSyntax + 1).TSQueryError
  TSQueryErrorField* = (TSQueryErrorNodeType + 1).TSQueryError
  TSQueryErrorCapture* = (TSQueryErrorField + 1).TSQueryError

const
    gAtoms* {.used.} = @[
      "field_identifier",
      "identifier",
      "number_literal",
      "char_literal",
      "preproc_arg",
      "primitive_type",
      "sized_type_specifier",
      "type_identifier"
    ].toHashSet()

    gExpressions* {.used.} = @[
      "parenthesized_expression",
      "bitwise_expression",
      "shift_expression",
      "math_expression",
      "escape_sequence",
      "binary_expression",
      "unary_expression"
    ].toHashSet()

    gEnumVals* {.used.} = @[
      "identifier",
      "number_literal",
      "char_literal"
    ].concat(toSeq(gExpressions.items))
type
    Status* = enum
      success, unknown, error

type
  Feature* = enum
    ast2
  Symbol* = object
    name*: string
    parent*: string
    kind*: NimSymKind
    override*: string
  StringHash = HashSet[string]
  OnSymbol* = proc(sym: var Symbol) {.cdecl.}
  OnSymbolOverrideFinal* = proc(typ: string): StringHash {.cdecl.}

  State* = ref object
    # Command line arguments to toast - some forwarded from cimport.nim
    compile*: seq[string]      # `--compile` to create `{.compile.}` entries in generated wrapper
    convention*: string        # `--convention | -C` to change calling convention from cdecl default
    debug*: bool               # `cDebug()` or `--debug | -d` to enable debug mode
    defines*: seq[string]      # Symbols added by `cDefine()` and `--define | -D` for C/C++ preprocessor/compiler
    dynlib*: string            # `cImport(dynlib)` or `--dynlib | -l` to specify variable containing library name
    exclude*: seq[string]      # files or directories to exclude from the wrapped output
    feature*: seq[Feature]     # `--feature | -f` feature flags enabled
    includeDirs*: seq[string]  # Paths added by `cIncludeDir()` and `--includeDirs | -I` for C/C++ preprocessor/compiler
    mode*: string              # `cImport(mode)` or `--mode | -m` to override detected compiler mode - c or cpp
    nim*: string               # `--nim` to specify full path to Nim compiler
    noComments*: bool          # `--noComments | -c` to disable rendering comments in wrappers
    noHeader*: bool            # `--noHeader | -H` to skip {.header.} pragma in wrapper
    passC*: seq[string]        # `--passC` to create `{.passC.}` entries in the generated wrapper
    passL*: seq[string]        # `--passL` to create `{.passL.}` entries in the generated wrapper
    past*: bool                # `--past | -a` to print tree-sitter AST of code
    pluginSourcePath*: string  # `--pluginSourcePath` specified path to plugin file to compile and load
    pnim*: bool                # `--pnim | -n` to render Nim wrapper for header
    preprocess*: bool          # `--preprocess | -p` to enable preprocessing of code before wrapping
    prefix*: seq[string]       # `--prefix` strings to strip from start of identifiers
    recurse*: bool             # `--recurse | -r` to recurse into #include files in headers specified
    replace*: OrderedTableRef[string, string]
                               # `--replace | -G` replacement rules for identifiers
    suffix*: seq[string]       # `--suffix` strings to strip from end of identifiers
    symOverride*: seq[string]  # `cSkipSymbol()`, `cOverride()` and `--symOverride | -O` symbols to skip during wrapping
    typeMap*: TableRef[string, string]
                               # `--typeMap | -T` to map instances of type X to Y - e.g. ABC=cint

    # Data fields
    code*: string              # Contents of header file currently being processed
    currentHeader*: string     # Const name of header being currently processed
    impShort*: string          # Short base name for pragma in output
    outputHandle*: File        # `--output | -o` open file handle
    sourceFile*: string        # Full path of header being currently processed
    functionDef*: string

    # Plugin callbacks
    onSymbol*, onSymbolOverride*: OnSymbol
    onSymbolOverrideFinal*: OnSymbolOverrideFinal

    # Symbol tables
    constIdentifiers*: HashSet[string]     # Const names for enum casting
    identifiers*: TableRef[string, string] # Symbols that have been declared so far indexed by nimName
    skippedSyms*: HashSet[string]          # Symbols that have been skipped due to being unwrappable or
                                            # the user provided override is blank
    headersProcessed*: HashSet[string]     # Headers already processed directly or recursively

    # Nim compiler objects
    constSection*, enumSection*, pragmaSection*, procSection*, typeSection*, varSection*: PNode
    identCache*: IdentCache
    config*: ConfigRef
    graph*: ModuleGraph

    # Table of symbols to generated AST PNode - used to implement forward declarations
    identifierNodes*: TableRef[string, PNode]

    # Used for the exprparser.nim module
    currentExpr*, currentTyCastName*: string
    # Controls whether or not the current expression
    # should validate idents against currently defined idents
    skipIdentValidation*: bool

    # Top level header for wrapper output - include imported types, pragmas and other info
    wrapperHeader*: string
    # cimport.nim specific
    compcache*: seq[string]    # `cCompile()` list of files already processed
    nocache*: bool             # `cDisableCaching()` to disable caching of artifacts
    overrides*: string         # `cOverride()` code which gets added to `cPlugin()` output
    pluginSource*: string      # `cPlugin()` generated code to write to plugin file from
    searchDirs*: seq[string]   # `cSearchPath()` added directories for header search

  Config* = ref object
    NimMajor*: int
    NimMinor*: int
    NimPatch*: int

    paths*: OrderedSet[string]
    nimblePaths*: OrderedSet[string]
    nimcacheDir*: string
    outDir*: string

  MultipleValueSetting* {.pure.} = enum ## \
                      ## settings resulting in a seq of string values
    nimblePaths,      ## the nimble path(s)
    searchPaths,      ## the search path for modules
    lazyPaths,        ## experimental: even more paths
    commandArgs,      ## the arguments passed to the Nim compiler
    cincludes,        ## the #include paths passed to the C/C++ compiler
    clibs  

  SingleValueSetting* {.pure.} = enum ## \
                      ## settings resulting in a single string value
    arguments,        ## experimental: the arguments passed after '-r'
    outFile,          ## experimental: the output file
    outDir,           ## the output directory
    nimcacheDir,      ## the location of the 'nimcache' directory
    projectName,      ## the project's name that is being compiled
    projectPath,      ## experimental: some path to the project that is being compiled
    projectFull,      ## the full path to the project that is being compiled
    command,          ## experimental: the command (e.g. 'c', 'cpp', 'doc') passed to
                      ## the Nim compiler
    commandLine,      ## experimental: the command line passed to Nim
    linkOptions,      ## additional options passed to the linker
    compileOptions,   ## additional options passed to the C/C++ compiler
    ccompilerPath     ## the path to the C/C++ compiler
    backend           ## the backend (eg: c|cpp|objc|js); both `nim doc --backend:js`
                      ## and `nim js` would imply backend=js
                      

when nimvm:
  var
    gStateCT* {.compileTime, used.} = new(State)
else:
  var
    gState* = State(mode:"c",includeDirs: @["/mnt/c/openssl","/mnt/c/openssl/ssl","/mnt/c/openssl/include","/mnt/c/nghttp3/lib/includes","/mnt/c/nghttp3/lib","/mnt/c/ngtcp2/crypto/includes",
      "/mnt/c/ngtcp2/crypto","/mnt/c/ngtcp2/lib","/mnt/c/ngtcp2/lib/includes","/mnt/c/ngtcp2/third-party","/mnt/c/ngtcp2/third-party/http-parser"])

proc querySettingSeq*(setting: MultipleValueSetting): seq[string] {.
  compileTime, noSideEffect.} = discard


proc querySetting*(setting: SingleValueSetting): string {.
  compileTime, noSideEffect.} = discard

proc stripName(path, projectName: string): string =
  # Remove `pname_d|r` tail from path
  let
    (head, tail) = path.splitPath()
  if projectName in tail:
    result = head
  else:
    result = path

proc getProjectDir*(): string =
  ## Get project directory for this compilation - returns `""` at runtime
  when nimvm:
    when (NimMajor, NimMinor, NimPatch) >= (1, 2, 0):
      # If nim v1.2.0+, get from `std/compilesettings`
      result = querySetting(projectFull).parentDir()
    else:
      # Get from `macros`
      result = getProjectPath()
  else:
    discard

proc getCurrentNimCompiler*(): string =
  when nimvm:
    result = getCurrentCompilerExe()
    when defined(nimsuggest):
      result = result.replace("nimsuggest", "nim")
  else:
    result = gState.nim

proc sanitizePath*(path: string, noQuote = false, sep = $DirSep): string =
  result = path.multiReplace([("\\\\", sep), ("\\", sep), ("/", sep)])
  if not noQuote:
    result = result.quoteShell

proc fixCmd*(cmd: string): string =
  when defined(Windows):
    # Replace 'cd d:\abc' with 'd: && cd d:\abc`
    var filteredCmd = cmd
    if cmd.toLower().startsWith("cd"):
      var
        colonIndex = cmd.find(":")
        driveLetter = cmd.substr(colonIndex-1, colonIndex)
      if (driveLetter[0].isAlphaAscii() and
          driveLetter[1] == ':' and
          colonIndex == 4):
        filteredCmd = &"{driveLetter} && {cmd}"
    result = "cmd /c " & filteredCmd
  elif defined(posix):
    result = cmd
  else:
    doAssert false


proc getJson(projectDir: string): JsonNode =
  # Get `nim dump` json value for `projectDir`
  var
    cmd = &"{getCurrentNimCompiler()} --hints:off --dump.format:json dump dummy"
    dump = ""
    ret = 0

  if projectDir.len != 0:
    # Run `nim dump` in `projectDir` if specified
    cmd = &"cd {projectDir.sanitizePath} && " & cmd

  cmd = fixCmd(cmd)
  when nimvm:
    (dump, ret) = gorgeEx(cmd)
  else:
    (dump, ret) = execCmdEx(cmd)

  try:
    result = parseJson(dump)
  except JsonParsingError as e:
    echo "# Failed to parse `nim dump` output: " & e.msg

proc jsonToSeq(node: JsonNode, key: string): seq[string] =
  # Convert JsonArray to seq[string] for specified `key`
  if node.hasKey(key):
    for elem in node[key].getElems():
      result.add elem.getStr()

proc getOsCacheDir(): string =
  # OS default cache directory
  when defined(posix):
    result = getEnv("XDG_CACHE_HOME", getHomeDir() / ".cache") / "nim"
  else:
    result = getHomeDir() / "nimcache"

proc getAbsoluteDir(projectDir, path: string): string =
  # Path is relative to `projectDir` if not absolute
  if path.isAbsolute():
    result = path
  else:
    result = (projectDir / path).normalizedPath()

proc getNimConfig*(projectDir = ""): Config =
  # Get `paths` - list of paths to be forwarded to Nim
  result = new(Config)
  var
    libPath, version: string
    lazyPaths, searchPaths: seq[string]

  when nimvm:
    result.NimMajor = NimMajor
    result.NimMinor = NimMinor
    result.NimPatch = NimPatch
    when (NimMajor, NimMinor, NimPatch) >= (1, 2, 0):
      # Get value at compile time from `std/compilesettings`
      libPath = getCurrentCompilerExe().parentDir().parentDir() / "lib"
      lazyPaths = querySettingSeq(MultipleValueSetting.lazyPaths)
      searchPaths = querySettingSeq(MultipleValueSetting.searchPaths)
      result.nimcacheDir = stripName(
        querySetting(SingleValueSetting.nimcacheDir),
        querySetting(SingleValueSetting.projectName)
      )
      result.outDir = querySetting(SingleValueSetting.outDir)
  else:
    discard
  let
    # Get project directory for < v1.2.0 at compile time
    projectDir = if projectDir.len != 0: projectDir else: getProjectDir()

  # Not Nim v1.2.0+ or runtime
  if libPath.len == 0:
    let
      dumpJson = getJson(projectDir)

    if dumpJson != nil:
      if dumpJson.hasKey("version"):
        version = dumpJson["version"].getStr()
      lazyPaths = jsonToSeq(dumpJson, "lazyPaths")
      searchPaths = jsonToSeq(dumpJson, "lib_paths")
      if dumpJson.hasKey("libpath"):
        libPath = dumpJson["libpath"].getStr()
      elif searchPaths.len != 0:
        # Usually `libPath` is last entry in `searchPaths`
        libPath = searchPaths[^1]

      if dumpJson.hasKey("nimcache"):
        result.nimcacheDir = stripName(dumpJson["nimcache"].getStr(), "dummy")
      if dumpJson.hasKey("outdir"):
        result.outDir = dumpJson["outdir"].getStr()

  # Parse version
  if version.len != 0:
    let
      splversion = version.split({'.'}, maxsplit = 3)
    result.NimMajor = splversion[0].parseInt()
    result.NimMinor = splversion[1].parseInt()
    result.NimPatch = splversion[2].parseInt()

  # Find non standard lib paths added to `searchPath`
  for path in searchPaths:
    let
      path = getAbsoluteDir(projectDir, path)
    if libPath notin path:
      result.paths.incl path

  # Find `nimblePaths` in `lazyPaths`
  for path in lazyPaths:
    let
      path = getAbsoluteDir(projectDir, path)
      (_, tail) = path.strip(leading = false, chars = {'/', '\\'}).splitPath()
    if tail == "pkgs":
      # Nimble path probably
      result.nimblePaths.incl path

  # Find `paths` in `lazyPaths` that aren't within `nimblePaths`
  # Have to do this separately since `nimblePaths` could be after
  # packages in `lazyPaths`
  for path in lazyPaths:
    let
      path = getAbsoluteDir(projectDir, path)
    var skip = false
    for npath in result.nimblePaths:
      if npath in path:
        skip = true
        break
    if not skip:
      result.paths.incl path

  if result.nimcacheDir.len == 0:
    result.nimcacheDir = getOsCacheDir()

  if result.outDir.len == 0:
    result.outDir = projectDir

proc getNimcacheDir*(projectDir = ""): string =
  ## Get nimcache directory for current compilation or specified `projectDir`
  let
    cfg = getNimConfig(projectDir)
  result = cfg.nimcacheDir

proc getNimteropCacheDir*(): string =
  result = getNimcacheDir() / "nimterop"

proc execAction*(cmd: string, retry = 0, die = true, cache = false,
                 cacheKey = "", onRetry: proc() = nil,
                 onError: proc(output: string, err: int) = nil): tuple[output: string, ret: int] =
  let
    ccmd = fixCmd(cmd)

  when nimvm:
    # Cache results for speedup if cache = true
    # Else cache for preserving functionality in nimsuggest and nimcheck
    let
      hash = (ccmd & cacheKey).hash().abs()
      cachePath = getNimteropCacheDir() / "execCache" / "nimterop_" & $hash
      cacheFile = cachePath & ".txt"
      retFile = cachePath & "_ret.txt"

    when defined(nimsuggest) or defined(nimcheck):
      # Load results from cache file if generated in previous run
      if fileExists(cacheFile) and fileExists(retFile):
        result.output = cacheFile.readFile()
        result.ret = retFile.readFile().parseInt()
      elif die:
        doAssert false, "Results not cached - run nim c/cpp at least once\n" & ccmd
    else:
      if cache and fileExists(cacheFile) and fileExists(retFile) and not compileOption("forceBuild"):
        # Return from cache when requested
        result.output = cacheFile.readFile()
        result.ret = retFile.readFile().parseInt()
      else:
        # Execute command and store results in cache
        (result.output, result.ret) = gorgeEx(ccmd)
        if result.ret == 0 or die == false:
          # mkdir for execCache dir (circular dependency)
          let dir = cacheFile.parentDir()
          if not dirExists(dir):
            let flag = when not defined(Windows): "-p" else: ""
            discard execAction(&"mkdir {flag} {dir.sanitizePath}")
          cacheFile.writeFile(result.output)
          retFile.writeFile($result.ret)
  else:
    # Used by toast
    (result.output, result.ret) = execCmdEx(ccmd)

  # On failure, retry or die as requested
  if result.ret != 0:
    if retry > 0:
      if not onRetry.isNil:
        onRetry()
      sleep(500)
      result = execAction(cmd, retry = retry - 1, die, cache, cacheKey)
    else:
      if not onError.isNil:
        onError(result.output, result.ret)

      doAssert not die, "Command failed: " & $result.ret & "\ncmd: " & ccmd &
                        "\nresult:\n" & result.output

proc rmFile*(source: string, dir = false) =
  ## Remove a file or pattern at compile time
  let
    source = source.replace("/", $DirSep)
    cmd =
      when defined(Windows):
        if dir:
          "rd /s/q"
        else:
          "del /q/f"
      else:
        "rm -rf"
    exists =
      if dir:
        dirExists(source)
      else:
        fileExists(source)

  if exists:
    discard execAction(&"{cmd} {source.sanitizePath}", retry = 2)


proc rmDir*(dir: string) =
  ## Remove a directory or pattern at compile time
  rmFile(dir, dir = true)

proc getProjectCacheDir*(name: string, forceClean = true): string =
  result = getNimteropCacheDir() / name

  if forceClean and compileOption("forceBuild"):
    echo "# Removing " & result
    rmDir(result)

const
  cacheDir* = getProjectCacheDir("nimterop", forceClean = false)

const sourcePath = cacheDir / "treesitter" / "lib"

when defined(Linux) and defined(gcc):
  {.passC: "-std=c11".}

{.passC: "-I$1" % (sourcePath / "include").}
{.passC: "-I$1" % (sourcePath / "src").}

{.compile: sourcePath / "src" / "lib.c".}
{.push hint[ConvFromXtoItselfNotNeeded]: off.}
{.pragma: impapiHdr, header: sourcePath / "include" / "tree_sitter" / "api.h".}
{.pragma: imptreeHdr, header: sourcePath / "include" / "tree_sitter" / "tree.h".}

type
  TSSymbol* {.importc, impapiHdr.} = uint16
  TSFieldId* {.importc, impapiHdr.} = uint16
  TSLanguage* {.importc, impapiHdr, incompleteStruct.} = object
  TSParser* {.importc, impapiHdr, incompleteStruct.} = object
  TSTree* {.importc, impapiHdr, incompleteStruct.} = object
  TSQuery* {.importc, impapiHdr, incompleteStruct.} = object
  TSQueryCursor* {.importc, impapiHdr, incompleteStruct.} = object
  TSPoint* {.bycopy, importc, impapiHdr.} = object
    row*: uint32
    column*: uint32

  TSRange* {.bycopy, importc, impapiHdr.} = object
    start_point*: TSPoint
    end_point*: TSPoint
    start_byte*: uint32
    end_byte*: uint32

  TSInput* {.bycopy, importc, impapiHdr.} = object
    payload*: pointer
    read*: proc (payload: pointer; byte_index: uint32; position: TSPoint;
               bytes_read: ptr uint32): cstring {.cdecl.}
    encoding*: TSInputEncoding

  TSLogger* {.bycopy, importc, impapiHdr.} = object
    payload*: pointer
    log*: proc (payload: pointer; a2: TSLogType; a3: cstring) {.cdecl.}

  TSInputEdit* {.bycopy, importc, impapiHdr.} = object
    start_byte*: uint32
    old_end_byte*: uint32
    new_end_byte*: uint32
    start_point*: TSPoint
    old_end_point*: TSPoint
    new_end_point*: TSPoint

  TSNode* {.bycopy, importc, impapiHdr.} = object
    context*: array[4, uint32]
    id*: pointer
    tree*: ptr TSTree

  TSTreeCursor* {.bycopy, importc, impapiHdr.} = object
    tree*: pointer
    id*: pointer
    context*: array[2, uint32]

  TSQueryCapture* {.bycopy, importc, impapiHdr.} = object
    node*: TSNode
    index*: uint32

  TSQueryMatch* {.bycopy, importc, impapiHdr.} = object
    id*: uint32
    pattern_index*: uint16
    capture_count*: uint16
    captures*: ptr TSQueryCapture

  TSQueryPredicateStep* {.bycopy, importc, impapiHdr.} = object
    `type`*: TSQueryPredicateStepType
    value_id*: uint32



proc ts_parser_new*(): ptr TSParser {.importc, cdecl, impapiHdr.}
proc ts_parser_delete*(parser: ptr TSParser) {.importc, cdecl, impapiHdr.}
proc ts_parser_set_language*(self: ptr TSParser; language: ptr TSLanguage): bool {.
    importc, cdecl, impapiHdr.}
proc ts_parser_language*(self: ptr TSParser): ptr TSLanguage {.importc, cdecl, impapiHdr.}
proc ts_parser_set_included_ranges*(self: ptr TSParser; ranges: ptr TSRange;
                                   length: uint32) {.importc, cdecl, impapiHdr.}
proc ts_parser_included_ranges*(self: ptr TSParser; length: ptr uint32): ptr TSRange {.
    importc, cdecl, impapiHdr.}
proc ts_parser_parse*(self: ptr TSParser; old_tree: ptr TSTree; input: TSInput): ptr TSTree {.
    importc, cdecl, impapiHdr.}
proc ts_parser_parse_string*(self: ptr TSParser; old_tree: ptr TSTree; string: cstring;
                            length: uint32): ptr TSTree {.importc, cdecl, impapiHdr.}
proc ts_parser_parse_string_encoding*(self: ptr TSParser; old_tree: ptr TSTree;
                                     string: cstring; length: uint32;
                                     encoding: TSInputEncoding): ptr TSTree {.
    importc, cdecl, impapiHdr.}
proc ts_parser_reset*(self: ptr TSParser) {.importc, cdecl, impapiHdr.}
proc ts_parser_set_timeout_micros*(self: ptr TSParser; timeout: uint64) {.importc,
    cdecl, impapiHdr.}
proc ts_parser_timeout_micros*(self: ptr TSParser): uint64 {.importc, cdecl, impapiHdr.}
proc ts_parser_set_cancellation_flag*(self: ptr TSParser; flag: ptr uint) {.importc,
    cdecl, impapiHdr.}
proc ts_parser_cancellation_flag*(self: ptr TSParser): ptr uint {.importc, cdecl,
    impapiHdr.}
proc ts_parser_set_logger*(self: ptr TSParser; logger: TSLogger) {.importc, cdecl,
    impapiHdr.}
proc ts_parser_logger*(self: ptr TSParser): TSLogger {.importc, cdecl, impapiHdr.}
proc ts_parser_print_dot_graphs*(self: ptr TSParser; file: cint) {.importc, cdecl,
    impapiHdr.}
proc ts_parser_halt_on_error*(self: ptr TSParser; halt: bool) {.importc, cdecl,
    impapiHdr.}
proc ts_tree_copy*(self: ptr TSTree): ptr TSTree {.importc, cdecl, impapiHdr.}
proc ts_tree_delete*(self: ptr TSTree) {.importc, cdecl, impapiHdr.}
proc ts_tree_root_node*(self: ptr TSTree): TSNode {.importc, cdecl, impapiHdr.}
proc ts_tree_language*(a1: ptr TSTree): ptr TSLanguage {.importc, cdecl, impapiHdr.}
proc ts_tree_edit*(self: ptr TSTree; edit: ptr TSInputEdit) {.importc, cdecl, impapiHdr.}
proc ts_tree_get_changed_ranges*(old_tree: ptr TSTree; new_tree: ptr TSTree;
                                length: ptr uint32): ptr TSRange {.importc, cdecl,
    impapiHdr.}
proc ts_tree_print_dot_graph*(a1: ptr TSTree; a2: File) {.importc, cdecl, impapiHdr.}
proc ts_node_type*(a1: TSNode): cstring {.importc, cdecl, impapiHdr.}
proc ts_node_symbol*(a1: TSNode): TSSymbol {.importc, cdecl, impapiHdr.}
proc ts_node_start_byte*(a1: TSNode): uint32 {.importc, cdecl, impapiHdr.}
proc ts_node_start_point*(a1: TSNode): TSPoint {.importc, cdecl, impapiHdr.}
proc ts_node_end_byte*(a1: TSNode): uint32 {.importc, cdecl, impapiHdr.}
proc ts_node_end_point*(a1: TSNode): TSPoint {.importc, cdecl, impapiHdr.}
proc ts_node_string*(a1: TSNode): cstring {.importc, cdecl, impapiHdr.}
proc ts_node_is_null*(a1: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_node_is_named*(a1: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_node_is_missing*(a1: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_node_is_extra*(a1: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_node_has_changes*(a1: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_node_has_error*(a1: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_node_parent*(a1: TSNode): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_child*(a1: TSNode; a2: uint32): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_child_count*(a1: TSNode): uint32 {.importc, cdecl, impapiHdr.}
proc ts_node_named_child*(a1: TSNode; a2: uint32): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_named_child_count*(a1: TSNode): uint32 {.importc, cdecl, impapiHdr.}
proc ts_node_child_by_field_name*(self: TSNode; field_name: cstring;
                                 field_name_length: uint32): TSNode {.importc,
    cdecl, impapiHdr.}
proc ts_node_child_by_field_id*(a1: TSNode; a2: TSFieldId): TSNode {.importc, cdecl,
    impapiHdr.}
proc ts_node_next_sibling*(a1: TSNode): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_prev_sibling*(a1: TSNode): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_next_named_sibling*(a1: TSNode): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_prev_named_sibling*(a1: TSNode): TSNode {.importc, cdecl, impapiHdr.}
proc ts_node_first_child_for_byte*(a1: TSNode; a2: uint32): TSNode {.importc, cdecl,
    impapiHdr.}
proc ts_node_first_named_child_for_byte*(a1: TSNode; a2: uint32): TSNode {.importc,
    cdecl, impapiHdr.}
proc ts_node_descendant_for_byte_range*(a1: TSNode; a2: uint32; a3: uint32): TSNode {.
    importc, cdecl, impapiHdr.}
proc ts_node_descendant_for_point_range*(a1: TSNode; a2: TSPoint; a3: TSPoint): TSNode {.
    importc, cdecl, impapiHdr.}
proc ts_node_named_descendant_for_byte_range*(a1: TSNode; a2: uint32; a3: uint32): TSNode {.
    importc, cdecl, impapiHdr.}
proc ts_node_named_descendant_for_point_range*(a1: TSNode; a2: TSPoint; a3: TSPoint): TSNode {.
    importc, cdecl, impapiHdr.}
proc ts_node_edit*(a1: ptr TSNode; a2: ptr TSInputEdit) {.importc, cdecl, impapiHdr.}
proc ts_node_eq*(a1: TSNode; a2: TSNode): bool {.importc, cdecl, impapiHdr.}
proc ts_tree_cursor_new*(a1: TSNode): TSTreeCursor {.importc, cdecl, impapiHdr.}
proc ts_tree_cursor_delete*(a1: ptr TSTreeCursor) {.importc, cdecl, impapiHdr.}
proc ts_tree_cursor_reset*(a1: ptr TSTreeCursor; a2: TSNode) {.importc, cdecl, impapiHdr.}
proc ts_tree_cursor_current_node*(a1: ptr TSTreeCursor): TSNode {.importc, cdecl,
    impapiHdr.}
proc ts_tree_cursor_current_field_name*(a1: ptr TSTreeCursor): cstring {.importc,
    cdecl, impapiHdr.}
proc ts_tree_cursor_current_field_id*(a1: ptr TSTreeCursor): TSFieldId {.importc,
    cdecl, impapiHdr.}
proc ts_tree_cursor_goto_parent*(a1: ptr TSTreeCursor): bool {.importc, cdecl,
    impapiHdr.}
proc ts_tree_cursor_goto_next_sibling*(a1: ptr TSTreeCursor): bool {.importc, cdecl,
    impapiHdr.}
proc ts_tree_cursor_goto_first_child*(a1: ptr TSTreeCursor): bool {.importc, cdecl,
    impapiHdr.}
proc ts_tree_cursor_goto_first_child_for_byte*(a1: ptr TSTreeCursor; a2: uint32): int64 {.
    importc, cdecl, impapiHdr.}
proc ts_tree_cursor_copy*(a1: ptr TSTreeCursor): TSTreeCursor {.importc, cdecl,
    impapiHdr.}
proc ts_query_new*(language: ptr TSLanguage; source: cstring; source_len: uint32;
                  error_offset: ptr uint32; error_type: ptr TSQueryError): ptr TSQuery {.
    importc, cdecl, impapiHdr.}
proc ts_query_delete*(a1: ptr TSQuery) {.importc, cdecl, impapiHdr.}
proc ts_query_pattern_count*(a1: ptr TSQuery): uint32 {.importc, cdecl, impapiHdr.}
proc ts_query_capture_count*(a1: ptr TSQuery): uint32 {.importc, cdecl, impapiHdr.}
proc ts_query_string_count*(a1: ptr TSQuery): uint32 {.importc, cdecl, impapiHdr.}
proc ts_query_start_byte_for_pattern*(a1: ptr TSQuery; a2: uint32): uint32 {.importc,
    cdecl, impapiHdr.}
proc ts_query_predicates_for_pattern*(self: ptr TSQuery; pattern_index: uint32;
                                     length: ptr uint32): ptr TSQueryPredicateStep {.
    importc, cdecl, impapiHdr.}
proc ts_query_capture_name_for_id*(a1: ptr TSQuery; id: uint32; length: ptr uint32): cstring {.
    importc, cdecl, impapiHdr.}
proc ts_query_string_value_for_id*(a1: ptr TSQuery; id: uint32; length: ptr uint32): cstring {.
    importc, cdecl, impapiHdr.}
proc ts_query_disable_capture*(a1: ptr TSQuery; a2: cstring; a3: uint32) {.importc,
    cdecl, impapiHdr.}
proc ts_query_cursor_new*(): ptr TSQueryCursor {.importc, cdecl, impapiHdr.}
proc ts_query_cursor_delete*(a1: ptr TSQueryCursor) {.importc, cdecl, impapiHdr.}
proc ts_query_cursor_exec*(a1: ptr TSQueryCursor; a2: ptr TSQuery; a3: TSNode) {.importc,
    cdecl, impapiHdr.}
proc ts_query_cursor_set_byte_range*(a1: ptr TSQueryCursor; a2: uint32; a3: uint32) {.
    importc, cdecl, impapiHdr.}
proc ts_query_cursor_set_point_range*(a1: ptr TSQueryCursor; a2: TSPoint; a3: TSPoint) {.
    importc, cdecl, impapiHdr.}
proc ts_query_cursor_next_match*(a1: ptr TSQueryCursor; match: ptr TSQueryMatch): bool {.
    importc, cdecl, impapiHdr.}
proc ts_query_cursor_remove_match*(a1: ptr TSQueryCursor; id: uint32) {.importc, cdecl,
    impapiHdr.}
proc ts_query_cursor_next_capture*(a1: ptr TSQueryCursor; match: ptr TSQueryMatch;
                                  capture_index: ptr uint32): bool {.importc, cdecl,
    impapiHdr.}
proc ts_language_symbol_count*(a1: ptr TSLanguage): uint32 {.importc, cdecl, impapiHdr.}
proc ts_language_symbol_name*(a1: ptr TSLanguage; a2: TSSymbol): cstring {.importc,
    cdecl, impapiHdr.}
proc ts_language_symbol_for_name*(self: ptr TSLanguage; string: cstring;
                                 length: uint32; is_named: bool): TSSymbol {.importc,
    cdecl, impapiHdr.}
proc ts_language_field_count*(a1: ptr TSLanguage): uint32 {.importc, cdecl, impapiHdr.}
proc ts_language_field_name_for_id*(a1: ptr TSLanguage; a2: TSFieldId): cstring {.
    importc, cdecl, impapiHdr.}
proc ts_language_field_id_for_name*(a1: ptr TSLanguage; a2: cstring; a3: uint32): TSFieldId {.
    importc, cdecl, impapiHdr.}
proc ts_language_symbol_type*(a1: ptr TSLanguage; a2: TSSymbol): TSSymbolType {.
    importc, cdecl, impapiHdr.}
proc ts_language_version*(a1: ptr TSLanguage): uint32 {.importc, cdecl, impapiHdr.}
# proc ts_tree_get_cached_parent*(t: ptr TSTree , n:TSNode ):TSNode {.importc, cdecl, imptreeHdr.}

{.pop.}


proc nimteropRoot*(): string =
  currentSourcePath.parentDir.parentDir

proc nimteropSrcDir*(): string =
  nimteropRoot() / "nimterop"

proc toastExePath*(): string =
  nimteropSrcDir() / ("toast".addFileExt ExeExt)

proc testsIncludeDir*(): string =
  nimteropRoot() / "tests" / "include"


# static:
#   treesitterSetup()


proc isNil*(node: TSNode): bool =
  node.tsNodeIsNull()

proc len*(node: TSNode): int =
  if not node.tsNodeIsNull:
    result = node.tsNodeNamedChildCount().int

proc `[]`*(node: TSNode, i: SomeInteger): TSNode =
  if i < type(i)(node.len()):
    result = node.tsNodeNamedChild(i.uint32)

const csrcDir = cacheDir / "treesitter_c" / "src"


{.passC: "-I$1" % csrcDir.}

{.compile: csrcDir / "parser.c".}

proc treeSitterC*(): ptr TSLanguage {.importc: "tree_sitter_c".}

const cppsrcDir = cacheDir / "treesitter_cpp" / "src"

{.compile: cppsrcDir / "parser_cpp.c".}
{.compile: cppsrcDir / "scanner.cc".}

proc treeSitterCpp*(): ptr TSLanguage {.importc: "tree_sitter_cpp".}

proc getLineCol*(code: var string, node: TSNode): tuple[line, col: int] =
  # Get line number and column info for node
  let
    point = node.tsNodeStartPoint()
  result.line = point.row.int + 1
  result.col = point.column.int + 1

proc getName*(node: TSNode): string {.inline.} =
  if not node.isNil:
    return $node.tsNodeType()

proc getNodeVal*(code: var string, node: TSNode): string =
  if not node.isNil:
    return code[node.tsNodeStartByte() .. node.tsNodeEndByte()-1]

proc getNodeVal*(gState: State, node: TSNode): string =
  gState.code.getNodeVal(node)

proc getAtom*(node: TSNode): TSNode =
  if not node.isNil:
    # Get child node which is topmost atom
    if node.getName() in gAtoms:
      return node
    elif node.len != 0:
      if node[0].getName() in ["type_qualifier", "comment"]:
        # Skip const, volatile
        if node.len > 1:
          return node[1].getAtom()
        else:
          return
      else:
        return node[0].getAtom()

proc getStartAtom*(node: TSNode): int =
  if not node.isNil:
    # Skip const, volatile and other type qualifiers
    for i in 0 .. node.len - 1:
      if node[i].getAtom().getName() notin gAtoms:
        result += 1
      else:
        break

proc getConstQualifier*(gState: State, node: TSNode): bool =
  # Check if node siblings have type_qualifier = `const`
  var
    curr = node.tsNodePrevNamedSibling()
  while not curr.isNil:
    # Check previous siblings
    if curr.getName() == "type_qualifier" and
      gState.getNodeVal(curr) == "const":
        return true
    curr = curr.tsNodePrevNamedSibling()

  # Check immediate next sibling
  curr = node.tsNodePrevNamedSibling()
  if curr.getName() == "type_qualifier" and
    gState.getNodeVal(curr) == "const":
      return true

proc getXCount*(node: TSNode, ntype: string, reverse = false): int =
  if not node.isNil:
    # Get number of ntype nodes nested in tree
    var
      cnode = node
    while ntype in cnode.getName():
      result += 1
      if reverse:
        cnode = cnode.tsNodeParent()
      else:
        if cnode.len != 0:
          if cnode[0].getName() == "type_qualifier":
            # Skip const, volatile
            if cnode.len > 1:
              cnode = cnode[1]
            else:
              break
          else:
            cnode = cnode[0]
        else:
          break

proc getPtrCount*(node: TSNode, reverse = false): int =
  node.getXCount("pointer_declarator", reverse)

proc getArrayCount*(node: TSNode, reverse = false): int =
  node.getXCount("array_declarator")

proc getDeclarator*(node: TSNode): TSNode =
  if not node.isNil:
    # Return if child is a function or array declarator
    if node.getName() in ["function_declarator", "array_declarator"]:
      return node
    elif node.len != 0:
      return node[0].getDeclarator()

proc getVarargs*(node: TSNode): bool =
  # Detect ... and add {.varargs.}
  #
  # `node` is the param list
  #
  # ... is an unnamed node, second last node and ) is last node
  let
    nlen = node.tsNodeChildCount()
  if nlen > 1.uint32:
    let
      nval = node.tsNodeChild(nlen - 2.uint32).getName()
    if nval == "...":
      result = true


proc printLisp*(code: var string, root: TSNode): string =
  var
    node = root
    nextnode: TSNode
    depth = 0

  while true:
    if not node.tsNodeIsNull() and depth > -1:
      result &= spaces(depth)
      let
        (line, col) = code.getLineCol(node)
      result &= &"({$node.tsNodeType()} {line} {col} {node.tsNodeEndByte() - node.tsNodeStartByte()}"
      let
        val = code.getNodeVal(node)
      if "\n" notin val and " " notin val:
        result &= &" \"{val}\""
    else:
      break

    if node.len() != 0:
      result &= "\n"
      nextnode = node[0]
      depth += 1
    else:
      result &= ")\n"
      nextnode = node.tsNodeNextNamedSibling()

    if nextnode.tsNodeIsNull:
      while true:
        node = node.tsNodeParent()
        depth -= 1
        if depth == -1:
          break
        result &= spaces(depth) & ")\n"
        if node == root:
          break
        if not node.tsNodeNextNamedSibling().tsNodeIsNull():
          node = node.tsNodeNextNamedSibling()
          break
    else:
      node = nextnode

    if node == root:
      break

proc printLisp*(gState: State, root: TSNode): string =
  printLisp(gState.code, root)


proc getCompilerMode*(path: string): string =
  ## Determines a target language mode from an input filename, if one is not already specified.
  let file = path.splitFile()
  if file.ext in [".hxx", ".hpp", ".hh", ".H", ".h++", ".cpp", ".cxx", ".cc", ".C", ".c++"]:
    result = "cpp"
  elif file.ext in [".h", ".c"]:
    result = "c"

proc expandSymlinkAbs*(path: string): string =
  try:
    result = path.expandFilename().normalizedPath()
  except:
    result = path
  result = result.sanitizePath(noQuote = true)

template withCodeAst*(code: string, mode: string, body: untyped): untyped =
  ## A simple template to inject the TSNode into a body of code
  mixin treeSitterC
  mixin treeSitterCpp

  var parser {.inject.} = tsParserNew()
  defer:
    parser.tsParserDelete()

  if mode == "c":
    doAssert parser.tsParserSetLanguage(treeSitterC()), "Failed to load C parser"
  elif mode == "cpp":
    doAssert parser.tsParserSetLanguage(treeSitterCpp()), "Failed to load C++ parser"
  else:
    doAssert false, "Invalid parser " & mode

  var
    tree {.inject.} = parser.tsParserParseString(nil, code.cstring, code.len.uint32)
    root {.inject.} = tree.tsTreeRootNode()
  body
  defer:
    tree.tsTreeDelete()


proc getNodeError*(gState: State, node: TSNode): bool;    


proc processNode(gState: State, node: TSNode): Status =
  const
    known = ["preproc_def", "type_definition",
      "struct_specifier", "union_specifier", "enum_specifier","declaration"].toHashSet()

  result = success
  let
    name = node.getName()
  if name in known:
    # Recognized top-level nodes
    if gState.getNodeError(node):
      result = Status.error
    # else:
      # Process nodes
    #   case name
    #   of "preproc_def":
    #     gState.addConst(node)
    #   of "type_definition":
    #     if node.len > 0 and node[0].getName() == "enum_specifier":
    #       gState.addEnum(node)
    #     elif node.len > 0 and node[0].getName() == "union_specifier":
    #       gState.addType(node, union = true)
    #     else:
    #       gState.addType(node)
    #   of "struct_specifier":
    #     gState.addType(node)
    #   of "union_specifier":
    #     gState.addType(node, union = true)
    #   of "enum_specifier":
    #     gState.addEnum(node)
    #   of "declaration":
    #     gState.addDecl(node)
  elif name == "function_definition":
    # Separate since we only need to check function_declarator for errors and
    # not the compound_statement which could have errors but does not impact
    # wrapper generation
    gState.functionDef.add "[" & gState.currentHeader & "]" & gState.code.getNodeVal(node) & "\n"
    # gState.addDef(node)
  else:
    # Unknown, will check child nodes
    result = unknown

proc searchTree(gState: State, root: TSNode) =
  # Search AST generated by tree-sitter for recognized elements
  var
    node = root
    nextnode: TSNode
    depth = 0
    processed = success

  while true:
    if not node.tsNodeIsNull and depth > -1:
      processed = gState.processNode(node)
    else:
      break

    if processed == unknown and node.len != 0:
      nextnode = node[0]
      depth += 1
    else:
      nextnode = node.tsNodeNextNamedSibling()

    if nextnode.tsNodeIsNull:
      while true:
        node = node.tsNodeParent()
        depth -= 1
        if depth == -1:
          break
        if node == root:
          break
        if not node.tsNodeNextNamedSibling().isNil:
          node = node.tsNodeNextNamedSibling()
          break
    else:
      node = nextnode
    if node == root:
      break




proc firstChildInTree*(node: TSNode, ntype: string): TSNode =
  # Search for node type in tree - first children
  var
    cnode = node
  while not cnode.isNil:
    if cnode.getName() == ntype:
      return cnode
    if cnode.len != 0:
      for i in 0 ..< cnode.len:
        if cnode[i].getName() != "comment":
          cnode = cnode[i]
          break
    else:
      cnode = cnode[0]

proc mostNestedChildInTree*(node: TSNode): TSNode =
  # Search for the most nested child of node's type in tree
  var
    cnode = node
    ntype = cnode.getName()
  while not cnode.isNil and cnode.len != 0 and cnode[0].getName() == ntype:
    cnode = cnode[0]
  result = cnode

proc anyChildInTree*(node: TSNode, ntype: string): TSNode =
  # Search for node type anywhere in tree - depth first
  var
    cnode = node
  while not cnode.isNil:
    if cnode.getName() == ntype:
      return cnode
    for i in 0 ..< cnode.len:
      let
        ccnode = cnode[i].anyChildInTree(ntype)
      if not ccnode.isNil:
        return ccnode
    if cnode != node:
      cnode = cnode.tsNodeNextNamedSibling()
    else:
      break

  
proc any*(node: TSNode, ntype: varargs[string]): seq[TSNode] =
  # Search for node type anywhere in tree - depth first
  var cnode = node
  while not cnode.isNil:
    if cnode.getName() in ntype:
      result.add cnode
    for i in 0 ..< cnode.len:
      let ccnode = cnode[i].any(ntype)
      result.add ccnode
    if cnode != node:
      cnode = cnode.tsNodeNextNamedSibling()
    else:
      break

proc getNodeError*(gState: State, node: TSNode): bool =
  let err = node.any("ERROR")
  echo &"# tree-sitter parse error: '{gState.getNodeVal(node).splitLines()[0]}', skipped"
  result = true

proc allRec*(node: TSNode, ntype: varargs[string]):seq[TSNode] =
  if not node.isNil:
    if node.getName in ntype:
      result.add node
    for i in 0..< node.len:
      result.add allRec(node[i],ntype)

proc getGccModeArg*(mode: string): string =
  ## Produces a GCC argument that explicitly sets the language mode to be used by the compiler.
  if mode == "cpp":
    result = "-xc++"
  elif mode == "c":
    result = "-xc"

proc getCompiler*(): string =
  var
    compiler =
      when defined(gcc):
        "gcc"
      elif defined(clang):
        "clang"
      else:
        doAssert false, "Nimterop only supports gcc and clang at this time"
  result = getEnv("CC", compiler)

proc isIncluded(gState: State, file: string): bool {.inline.} =
  # Check if the specified file should be excluded from wrapped output
  for excl in gState.exclude:
    if file.startsWith(excl):
      return
  result = true


proc getPreprocessor*(gState: State, fullpath: string) =
  # Get preprocessed output from the C/C++ compiler
  var
    args: seq[string]
    start = false
    sfile = fullpath.sanitizePath(noQuote = true)

    sfileName = sfile.extractFilename()
    pDir = sfile.expandFilename().parentDir()
    includeDirs: seq[string]

  args.add @["-E", "-dD", getGccModeArg(gState.mode), "-w"]
  if not gState.noComments:
    args.add "-CC"

  for inc in gState.includeDirs:
    args.add &"-I{inc.sanitizePath}"
    includeDirs.add inc.absolutePath().sanitizePath(noQuote = true)

  for def in gState.defines:
    args.add &"-D{def}"

  args.add @[ &"{fullpath.sanitizePath}"]

  # Include content only from file
  var
    p = startProcess(getCompiler(), args = args, options = {poStdErrToStdOut, poUsePath})
    outp = p.outputStream()
    line = ""
    newHeaders: HashSet[string]

  # Include content only from file
  # gState.code = ""
  while true:
    if outp.readLine(line):
      # We want to keep blank lines here for comment processing
      if line.len > 10 and line[0] == '#' and line[1] == ' ' and line.contains('"'):
        # # 1 "path/to/file.h" 1
        start = false
        line = line.split('"')[1].sanitizePath(noQuote = true)
        # echo "line: ",line

        if sfile == line or (DirSep notin line and sfileName == line) or line.contains "FFmpeg":
          start = true
        elif gState.recurse:
          if (pDir == "" or pDir in line) and line notin gState.headersProcessed:
            newHeaders.incl line
            start = gState.isIncluded(line)
          else:
            for inc in includeDirs:
              if line.startsWith(inc) and line notin gState.headersProcessed:
                newHeaders.incl line
                start = gState.isIncluded(line)
                if start:
                  break
      elif "error:" in line:
          echo line
      else:
        if start:
          if "#undef" in line:
            continue
          gState.code.add line & "\n"
    elif not p.running(): break
  p.close()
  gState.headersProcessed.incl newHeaders

var typeDeclaration,funcDeclaration: string


proc topParent(n:TSNode,ntype: string):TSNode =
  result = n
  while not result.isNil:
    result = result.tsNodeParent
    if result.getName == ntype:
      break

var stdTypes: seq[string] = @["string","unordered_map","string_view","array","vector","pair","FILE","sockaddr","socklen_t","cmsghdr","T","operator","F","in6_addr","nanoseconds","ifstream","ostream"]


var funcState = State(mode:"cpp")

var funcGraph: OrderedTable[string, Vertex]
var typeGraph: OrderedTable[string, Vertex]
var funcDef: Table[string, TSNode]
var processedCall: HashSet[string]

var preprocessedFuncs: string

proc getAnyMostChildren*(node:TSNode, ntype:string):TSNode =
  result = (var anyType = node.any(ntype); anyType.sort(proc(x,y:TSNode):int = int x.len < y.len); anyType[0])

proc find(gRoot:TSNode, funcRoot:TSNode, state:State) = 
  var r = gRoot
  var calls = r.allRec("call_expression")

  for call in calls:
    var callIdent = state.getNodeVal call.firstChildInTree("identifier")
    if callIdent == "":
      callIdent = state.getNodeVal call.firstChildInTree("field_expression")
    if callIdent == "": 
      callIdent = state.getNodeVal call.firstChildInTree("scoped_identifier")
    if funcDef.hasKey callIdent:
      if not funcGraph.hasKey callIdent:
          funcGraph.initVertex(callIdent)
      else:
          var functionDeclarator = call.topParent("function_definition").any("function_declarator")
          if functionDeclarator.len != 0:
            var def = state.getNodeVal functionDeclarator[0]
            funcGraph.initVertex(def)
            funcGraph.addEdge(def, callIdent)
      if callIdent notin processedCall:
        processedCall.incl callIdent
        
        r = funcDef[callIdent]
        find(r, funcRoot, funcState)


proc findFunctionDefinition() = 
  funcState.code = readFile("funcs.cpp")
  gState.code = readFile("server.cpp")
  var parser = tsParserNew()
  defer: parser.tsParserDelete()

  if parser.tsParserSetLanguage(treeSitterCpp()):
    var gTree = parser.tsParserParseString(nil, gState.code.cstring, gState.code.len.uint32)
    var gRoot = gTree.tsTreeRootNode()
    defer: gTree.tsTreeDelete()
    var funcTree = parser.tsParserParseString(nil, funcState.code.cstring, funcState.code.len.uint32)
    var funcRoot = funcTree.tsTreeRootNode()
    defer: funcTree.tsTreeDelete()

    for i in 0..<funcRoot.len:
      if funcRoot[i].getName == "function_definition":
        var ident = funcState.getNodeVal funcRoot[i].any("identifier")[0]
        funcDef[ident] = funcRoot[i]

    find(gRoot, funcRoot, gState)
    echo funcGraph.topoSort()

proc findTypeSpecifiers(n:TSNode): seq[TSNode] =
  var specifiers = n.any("struct_specifier","enum_specifier","union_specifier")
  for s in specifiers:
    if s.tsNodeParent.getName in ["type_definition","field_declaration"]:
      continue
    if s.getName in ["struct_specifier","union_specifier"]:
      if s.any("field_declaration_list").len > 0:
        result.add s
    elif s.getName == "enum_specifier":
      if s.any("enumerator_list").len > 0:
        result.add s


var typeDefs: Table[string, string]
var funcDefs: Table[string,string]

var typeCalls, funcCalls: Table[string,string]
var typeSpecifier: Table[string,string]

proc addTypeCalls(state:State, typeIdent:string, n:TSNode) =
    var typeIdentifier = n.any("type_identifier")
    for t in typeIdentifier:
      var childTypeIdent = state.getNodeVal t
      if not typeCalls.hasKey childTypeIdent:
        typeGraph.initVertex childTypeIdent
        typeCalls[childTypeIdent] = typeIdent

var undefined = @["av_mallocz", "av_free", "av_malloc", "av_malloc_array", "av_freep", "av_frame_free", "av_packet_free", "av_log", "av_dict_get", "av_cpu_count", "avcodec_alloc_context3", "av_opt_copy", "av_dict_copy", "av_dict_set", "avcodec_open2", "av_dict_free", "av_bsf_list_parse_str", "av_strerror", "av_bsf_init", "av_bsf_free", "av_buffer_unref", "av_buffer_ref", "av_frame_unref", "av_packet_unref", "av_opt_free", "av_packet_alloc", "av_init_packet", "av_packet_make_refcounted", "av_frame_alloc", "av_frame_ref", "avcodec_receive_frame", "av_rescale_q", "avcodec_flush_buffers", "av_packet_move_ref", 
"avcodec_decode_subtitle2", "avcodec_send_packet", "avcodec_free_context", "avsubtitle_free", "av_mul_q", "av_rescale", "sws_getCachedContext", "sws_scale", "av_gettime_relative", "av_rdft_end", "av_rdft_init", "av_rdft_calc", "swr_free", "avformat_close_input", "sws_freeContext", "avformat_network_deinit", "av_bprint_init", "av_bprintf", "av_log_get_level", "av_bprint_finalize", "av_frame_move_ref", "av_guess_sample_aspect_ratio", "avfilter_inout_alloc", "av_strdup", "avfilter_graph_parse_ptr", "avfilter_link", "avfilter_graph_config", "avfilter_inout_free", "av_guess_frame_rate", "av_strlcatf", "avfilter_get_by_name", "avfilter_graph_create_filter", "av_int_list_length_for_size", "av_opt_set_bin", "avfilter_graph_free", "avfilter_graph_alloc", "av_opt_set", "av_get_sample_fmt_name", "av_opt_set_int", "av_get_channel_layout_nb_channels", "av_get_packed_sample_fmt", "av_get_channel_layout_string", "av_buffersrc_add_frame", "av_buffersink_get_time_base", "av_buffersink_get_frame_flags", "av_get_pix_fmt_name", "av_buffersink_get_frame_rate", "av_usleep", "av_samples_get_buffer_size", "av_get_default_channel_layout", "swr_alloc_set_opts", "swr_init", "swr_set_compensation", "av_fast_malloc", "swr_convert", "av_get_bytes_per_sample", "av_log2", "avcodec_parameters_to_context", "avcodec_find_decoder", "avcodec_find_decoder_by_name", "avcodec_get_name", "av_dict_set_int", "av_buffersink_get_sample_rate", "av_buffersink_get_channels", "av_buffersink_get_channel_layout", "av_match_name", "av_realloc_f", "av_opt_get", "av_reallocp", "avio_rl16", "avio_r8", "avio_flush", "avio_context_free", "avio_open_dyn_buf", "avio_w8", "avio_rb16", "avio_seek", "av_strcasecmp", "avio_rb32", "avio_skip", "avio_get_str", "av_strncasecmp", "av_buffer_alloc", "av_asprintf", "avio_rb24", "uncompress", "av_strlcpy", "avformat_new_stream", "av_dynarray_add", "av_dynarray_add_nofree", "av_bprint_chars", "av_parser_close", "av_opt_set_dict", "av_match_list", "av_filename_number_test", "av_opt_set_defaults", "avformat_queue_attached_pictures", "avio_closep", "avformat_free_context", "av_strstart", "avio_alloc_context", "av_mallocz_array", "__imp_WSAStartup", "__imp_WSACleanup", "avio_close", "av_format_inject_global_side_data", "avformat_find_stream_info", "avformat_seek_file", "av_dump_format", "av_get_media_type_string", "av_find_best_stream", "av_read_pause", "av_read_play", "av_packet_ref", "av_read_frame", "av_find_program_from_stream", "av_compare_ts", "avio_size", "av_find_input_format", "av_parse_time", "av_realloc_array", "av_stream_get_side_data", "av_realloc", "avcodec_get_class", "avcodec_find_encoder", "av_opt_find", "avformat_get_class", "sws_get_class", "swr_get_class", "av_log_set_level", "sws_alloc_context", "swr_alloc", "av_strtod", "av_log_format_line2", "av_log_default_callback", "av_opt_get_key_value", "av_log_set_callback", "av_log_set_flags", "avdevice_register_all", "avformat_network_init"]

var enablePreprocessing = false

proc process(source: string) =
    var state = State(mode:"cpp",includeDirs: @["/mnt/c/openssl","/mnt/c/openssl/ssl","/mnt/c/openssl/include","/mnt/c/nghttp3/lib/includes","/mnt/c/nghttp3/lib","/mnt/c/ngtcp2/crypto/includes",
      "/mnt/c/ngtcp2/crypto","/mnt/c/ngtcp2/lib","/mnt/c/ngtcp2/lib/includes","/mnt/c/ngtcp2/third-party","/mnt/c/ngtcp2/third-party/http-parser"])
    state.code &= readFile(source)
    # preprocessedFuncs &= state.code
    # 把所有type_definition的最后一个节点type_identifier和function_definition的any identifier的第一个放入definition表里, 把type_identifier和call_expression按照topParent:call的形式放入call表
    #与definition表匹配，匹配到的将topParent->definition的边加入DAG中，完成后进行排序
    #将排序的结果倒着写入文件
    withCodeAst(state.code, state.mode):
      if not enablePreprocessing:
        echo state.code.printLisp root
      if not fileExists "all.cpp":
        var preprocInclude = root.any("preproc_include")
        #找函数和类型定义
        var definitions = root.any("type_definition","function_definition")
        for def in definitions:
          case def.getName
          of "type_definition":
            # echo state.getNodeVal def
            var typeIdentNode = def[0].tsNodeNextNamedSibling
            if typeIdentNode.len > 0:  #形如typedef void (*sk_X509_ALGOR_freefunc)(X509_ALGOR *a);
              var typeIdent = state.getNodeVal typeIdentNode.anyChildInTree("type_identifier")
              if not typeDefs.hasKey typeIdent:
                typeGraph.initVertex typeIdent
                typeDefs[typeIdent] = state.getNodeVal def 
              else:
                echo fmt"duplicated typeDefs: {state.getNodeVal def}, old value: {typeDefs[typeIdent]}"
            else: #形如typedef struct/union/enum {} X;
              var typeIdent = state.getNodeVal typeIdentNode
              if not typeDefs.hasKey typeIdent:
                typeGraph.initVertex typeIdent
                typeDefs[typeIdent] = state.getNodeVal def
              else:
                echo fmt"duplicated typeDefs: {state.getNodeVal def}, old value: {typeDefs[typeIdent]}"
              state.addTypeCalls(typeIdent, def)
          of "function_definition":
            var identifier = def.anyChildInTree("identifier")
            if not identifier.isNil:
              var funcIdent = state.getNodeVal identifier
              funcGraph.initVertex funcIdent
              funcDefs[funcIdent] = state.getNodeVal def

        #找类型调用
        var specifiers = root.findTypeSpecifiers()#找到不是字段声明的struct/union/enum关键字,可能包含定义
        for s in specifiers:
          var specifier = state.getNodeVal s
          var specifierIdent = state.getNodeVal s[0]
          if typeDefs.hasKey(specifierIdent) and typeDefs[specifierIdent] != specifier:
            typeDefs[specifierIdent] = typeDefs[specifierIdent] & specifier
          else:
            typeGraph.initVertex specifierIdent
            echo fmt"duplicated typeSpecifier: {state.getNodeVal s}, old value: {typeSpecifier[specifierIdent]}"
          state.addTypeCalls(specifierIdent, s)

        for parent,ident in typeCalls:
          if typeDefs.hasKey ident:
            typeGraph.addEdge(parent,ident)
        #找函数调用
        var calls = root.any("call_expression")
        for call in calls:
            var callee = state.getNodeVal call.firstChildInTree("identifier")
            var functionDefinition = call.topParent("function_definition")
            if not functionDefinition.isNil:
              var functionDeclarator = functionDefinition.anyChildInTree("function_declarator")
              if not functionDeclarator.isNil:
                var caller = state.getNodeVal functionDeclarator[0]
                funcGraph.initVertex caller
                if not funcCalls.hasKey caller:
                  funcCalls[caller] = callee
            # else:
              # echo "call_expression not from function_definition: ", state.getNodeVal call

        for parent,ident in funcCalls:
          if funcDefs.hasKey(ident):
            funcGraph.addEdge(parent, ident)
      else:
        
        #TODO: 如果目标文件中有未定义的函数声明，在声明后追加定义
        if undefined.len != 0:
          var targetState = State(mode:"cpp", code: readFile("ffplay.cc"))
          withCodeAst(targetState.code, targetState.mode):
            var delarations = root.any("declaration")
            for d in delarations:
              var fd = d.anyChildInTree("function_declarator")
              if not fd.isNil:
                var ds = targetState.getNodeVal d
                if ds.startsWith "extern": continue
                var caller = targetState.getNodeVal fd[0]
                if caller in undefined:
                  echo caller
          


var source: seq[string] = @["test.c"]
var all: string
var hAndC: seq[string]

# if enablePreprocessing:
#   var csources = @["/mnt/c/nghttp3/lib","/mnt/c/ngtcp2/crypto","/mnt/c/ngtcp2/lib","/mnt/c/ngtcp2/third-party/http-parser","/mnt/c/ngtcp2/examples"]
#   for dir in csources:
#     for f in walkDirRec(dir):
#       let(path,name,ext) = splitFile f
#       if "test" notin path and "test" notin name and "client" notin name and "h09" notin name and "demos" notin path and "gnutls" notin path and ext in [".c",".cc"]:
#         hAndC.add f

#   for hc in hAndC:
#     all &= readFile(hc)
#     # preprocess(hc) 
#   writeFile("all.cpp",all)
#   # quit()
#   process("all.cpp") 

#   # var sorted = funcGraph.topoSort()
#   # echo sorted.join("->")
#   # var sortedFunc: string
#   # while sorted.len > 0:
#   #   var s = sorted.pop
#   #   if funcDefs.hasKey s:
#   #     sortedFunc &= funcDefs[s]
#   # writeFile("sortedFunc.cpp", sortedFunc)
#   var sortedTypes = typeGraph.topoSort()
#   var sortedType: string
#   while sortedTypes.len > 0:
#     var s = sortedTypes.pop
#     if typeDefs.hasKey(s):
#       sortedType &= typeDefs[s]

#   writeFile("sortedType.cpp", sortedType)
  
#   # writeFile("funcsPreprocessed.cpp", preprocessedFuncs)
#   # findFunctionDefinition()
# else:
#   for src in source:
#       let src = src.expandSymlinkAbs()
#       process(src)
gState.includeDirs = @["/mnt/c/FFmpeg", "/mnt/c/msys64/mingw64/x86_64-w64-mingw32/include/"]
gState.getPreprocessor("/mnt/c/FFmpeg/libavformat/mov.c")
writeFile("mov.c",gState.code)
echo "finish"