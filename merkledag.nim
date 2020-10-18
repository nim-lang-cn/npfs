import hashes, math
import base58/bitcoin, cbor
import std/with
import blake2
import sequtils
import nre, os, strutils, tables, parseopt, streams
import asyncfile, asyncdispatch

const 
  IDENTITY = 0x00
  ID         = IDENTITY
  SHA1       = 0x11
  SHA2_256   = 0x12
  SHA2_512   = 0x13
  SHA3_224   = 0x17
  SHA3_256   = 0x16
  SHA3_384   = 0x15
  SHA3_512   = 0x14
  SHA3       = SHA3_512
  KECCAK_224 = 0x1A
  KECCAK_256 = 0x1B
  KECCAK_384 = 0x1C
  KECCAK_512 = 0x1D
  SHAKE_128 = 0x18
  SHAKE_256 = 0x19
  BLAKE2B_MIN = 0xb201
  BLAKE2B_MAX = 0xb240
  BLAKE2S_MIN = 0xb241
  BLAKE2S_MAX = 0xb260
  MD5 = 0xd5
  DBL_SHA2_256 = 0x56
  MURMUR3_128 = 0x22
  MURMUR3 = MURMUR3_128
  X11 = 0x1100

const
  maxChunkSize* = 1 shl 32 #262144 byte
  digestLen* = 32
  cidSize* = digestLen

type Cid* = string

type EntryKey = enum
  typeKey = 1,
  dataKey = 2,
  sizeKey = 3

type FsType* = enum
  ufsFile = 0,
  ufsDir = 1

type FsKind* = enum
  fileNode,
  dirNode,
  shallowDir,
  shallowFile

type
  FileLink* = object
    cid*: Cid
    size*: int

  FsNode* = ref object
    cid: Cid
    case kind*: FsKind
    of fileNode:
      links*: seq[FileLink]
    of dirNode:
      entries*: OrderedTable[string, FsNode]
    of shallowFile, shallowDir:
      discard
    size: BiggestInt

type
  MissingChunk* = ref object of CatchableError
    cid*: Cid ## Missing chunk identifier
  BufferTooSmall* = object of CatchableError

const
  DirTag* = 0xda3c80 ## CBOR tag for UnixFS directories
  FileTag* = 0xda3c81 ## CBOR tag for UnixFS files

type
  DagfsStore* = ref DagfsStoreObj
  DagfsStoreObj* = object of RootObj
    closeImpl*: proc (s: DagfsStore) {.nimcall, gcsafe.}
    putBufferImpl*: proc (s: DagfsStore; buf: cstring; len: Natural): Cid {.nimcall, gcsafe.}
    putImpl*: proc (s: DagfsStore; chunk: string): Cid {.nimcall, gcsafe.}
    getBufferImpl*: proc (s: DagfsStore; cid: Cid; buf: cstring; len: Natural): int {.nimcall, gcsafe.}
    getImpl*: proc (s: DagfsStore; cid: Cid; result: var string) {.nimcall, gcsafe.}

type
  BlobKind* = enum
    dataBlob, metaBlob

type
  FileStore* = ref FileStoreObj
    ## A store that writes nodes and leafs as files.
  FileStoreObj = object of DagfsStoreObj
    root, buf: string
    
type
  EvalError = object of CatchableError

type
  Env = ref EnvObj

  AtomKind = enum
    atomPath
    atomCid
    atomString
    atomSymbol
    atomError

  Atom = object
    case kind: AtomKind
    of atomPath:
      path: string
    of atomCid:
      cid: Cid
    of atomString:
      str: string
    of atomSymbol:
      sym: string
    of atomError:
      err: string

  Func = proc(env: Env; arg: NodeObj): NodeRef

  NodeKind = enum
    nodeError
    nodeList
    nodeAtom
    nodeFunc

  NodeRef = ref NodeObj # NodeRef is used to chain nodes into lists.
  NodeObj = object # NodeObj is used to mutate nodes without side-effects.
    case kind: NodeKind
    of nodeList:
      headRef, tailRef: NodeRef
    of nodeAtom:
      atom: Atom
    of nodeFunc:
      fun: Func
      name: string
    of nodeError:
      errMsg: string
      errNode: NodeRef
    nextRef: NodeRef

  EnvObj = object
    store: DagfsStore
    bindings: Table[string, NodeObj]
    paths: Table[string, FsNode]
    cids: Table[Cid, FsNode]

proc isRaw*(file: FsNode): bool =
  file.links.len == 0


proc cid*(u: FsNode): Cid =
  u.cid

proc isFile*(u: FsNode): bool = u.kind in { fileNode, shallowFile }
proc isDir*(u: FsNode): bool = u.kind in { dirNode, shallowDir }

proc size*(u: FsNode): BiggestInt =
  if u.kind == dirNode: u.entries.len.BiggestInt
  else: u.size

proc newFsRoot*(): FsNode =
  FsNode(
    cid: "",
    kind: dirNode,
    entries: initOrderedTable[string, FsNode](8))

proc newUnixfsFile*(): FsNode =
  FsNode(kind: fileNode, cid: "")

proc newUnixfsDir*(cid: Cid): FsNode =
  FsNode(cid: cid, kind: dirNode)

proc add*(root: var FsNode; name: string; node: FsNode) =
  root.entries[name] = node

proc del*(dir: var FsNode; name: string) =
  dir.entries.del name

proc isUnixfs*(bin: string): bool =
  ## Check if a string contains a UnixFS node in CBOR form.
  var
    s = newStringStream bin
    c: CborParser
  try:
    c.open s
    c.next
    if c.kind == CborEventKind.cborTag:
      result = c.tag == DirTag or c.tag == FileTag
  except ValueError: discard
  close s

func `%`*(cid: Cid): CborNode = CborNode(kind:cborBytes,bytes: cid.mapIt(it.byte)) 

proc `%`*(u: FsNode): CborNode =
  case u.kind
  of fileNode:
    result = initCborArray()
    result.tag = FileTag
    result.seq.setLen u.links.len
    for i in 0..u.links.high:
      var L = initCborMap()
      L.map[% dataKey.int] = % u.links[i].cid
      L.map[% sizeKey.int] = % u.links[i].size
      result.seq[i] = L
  of dirNode:
    result = initCborMap()
    result.tag = DirTag
    for name, node in u.entries:
      var entry = initCborMap()
      case node.kind
      of fileNode, shallowFile:
        entry.map[% typeKey.int] = % ufsFile.int
        entry.map[% dataKey.int] = % node.cid
        entry.map[% sizeKey.int] = % node.size.int
      of dirNode:
        entry.map[% typeKey.int] = % ufsDir.int
        entry.map[% dataKey.int] = % node.cid
        entry.map[% sizeKey.int] = % node.entries.len
      of shallowdir:
        entry.map[% typeKey.int] = % ufsDir.int
        entry.map[% dataKey.int] = % node.cid
        entry.map[% sizeKey.int] = % node.size.int
      result.map[% name] = entry
  else:
    raiseAssert "shallow FsNodes can not be encoded"

template parseAssert(cond: bool; msg = "") =
  if not cond: raise newException(
    ValueError,
    if msg == "": "invalid UnixFS CBOR" else: "invalid UnixFS CBOR, " & msg)

proc take*(cid: var Cid; buf: string) =
  cid.add buf

proc parseFs*(raw: string; cid: Cid): FsNode =
  ## Parse a string containing CBOR data into a FsNode.
  new result
  result.cid = cid
  var
    c: CborParser
    buf = ""
  open(c, newStringStream(raw))
  next c
  parseAssert(c.kind == CborEventKind.cborTag, "data not tagged")
  let tag = c.tag
  if tag == FileTag:
    result.kind = fileNode
    next c
    parseAssert(c.kind == CborEventKind.cborArray, "file data not an array")
    let nLinks = c.arrayLen
    result.links = newSeq[FileLink](nLinks)
    for i in 0..<nLinks:
      next c
      parseAssert(c.kind == CborEventKind.cborMap, "file array does not contain maps")
      let nAttrs = c.mapLen
      for _ in 1..nAttrs:
        next c
        parseAssert(c.kind == CborEventKind.cborPositive, "link map key not an integer")
        let key = c.nextInt.EntryKey
        next c
        case key
        of typeKey:
          parseAssert(false, "type file links are not supported")
        of dataKey:
          parseAssert(c.kind == CborEventKind.cborBytes, "CID not encoded as bytes")
          buf = $c.nextBytes 
          result.links[i].cid.take buf
        of sizeKey:
          parseAssert(c.kind == CborEventKind.cborPositive, "link size not encoded properly")
          result.links[i].size = c.nextInt.int
          result.size.inc result.links[i].size
  elif tag == DirTag:
    result.kind = dirNode
    next c
    parseAssert(c.kind == CborEventKind.cborMap)
    let dirLen = c.mapLen
    parseAssert(dirLen != -1, raw)
    result.entries = initOrderedTable[string, FsNode](dirLen.nextPowerOfTwo)
    for i in 1 .. dirLen:
      next c
      parseAssert(c.kind == CborEventKind.cborText, raw)
      buf = $c.nextText
      parseAssert(not buf.contains({ '/', '\0'}), raw)
      next c
      parseAssert(c.kind == CborEventKind.cborMap)
      let nAttrs = c.mapLen
      parseAssert(nAttrs > 1, raw)
      let entry = new FsNode
      result.entries[buf] = entry
      for i in 1 .. nAttrs:
        next c
        parseAssert(c.kind == CborEventKind.cborPositive)
        case c.nextInt.EntryKey
        of typeKey:
          next c
          case c.nextInt.FsType
          of ufsFile: entry.kind = shallowFile
          of ufsDir: entry.kind = shallowDir
        of dataKey:
          next c
          buf = $c.nextBytes 
          entry.cid.take buf
        of sizeKey:
          next c
          entry.size = c.nextInt
  else:
    parseAssert(false, raw)
  next c
  parseAssert(c.kind == cborEof, "trailing data")

proc toStream*(node: FsNode; s: Stream) =
  s.writeCbor %node

iterator items*(dir: FsNode): (string, FsNode) =
  assert(dir.kind == dirNode)
  for k, v in dir.entries.pairs:
    yield (k, v)

proc containsFile*(dir: FsNode; name: string): bool =
  doAssert(dir.kind == dirNode)
  dir.entries.contains name

proc `[]`*(dir: FsNode; name: string): FsNode =
  if dir.kind == dirNode:
    result = dir.entries.getOrDefault name

proc `[]`*(dir: FsNode; index: int): (string, FsNode) =
  result[0] = ""
  if dir.kind == dirNode:
    var i = 0
    for name, node in dir.entries.pairs:
      if i == index:
        result = (name, node)
        break
      inc i

proc lookupFile*(dir: FsNode; name: string): tuple[cid: Cid, size: BiggestInt] =
  let f = dir.entries[name]
  if f.kind == fileNode:
    with result:
      cid = f.cid
      size = f.size

proc close*(s: DagfsStore) =
  ## Close active store resources.
  if not s.closeImpl.isNil: s.closeImpl(s)

proc putBuffer*(s: DagfsStore; buf: cstring; len: Natural): Cid =
  ## Put a chunk into the store.
  assert(0 < len and len <= maxChunkSize)
  assert(not s.putBufferImpl.isNil)
  s.putBufferImpl(s, buf, len)

proc put*(s: DagfsStore; chunk: string): Cid =
  ## Place a raw block to the store. The hash argument specifies a required
  ## hash algorithm, or defaults to a algorithm choosen by the store
  ## implementation.
  assert(0 < chunk.len and chunk.len <= maxChunkSize)
  assert(not s.putImpl.isNil)
  s.putImpl(s, chunk)

proc getBuffer*(s: DagfsStore; cid: Cid; buf: cstring; len: Natural): int =
  ## Copy a raw block from the store into a buffer pointer.
  assert(0 < len)
  assert(not s.getBufferImpl.isNil)
  result = s.getBufferImpl(s, cid, buf, len)
  assert(result > 0)

proc get*(s: DagfsStore; cid: Cid; result: var string) =
  ## Retrieve a raw block from the store.
  assert(not s.getImpl.isNil)
  s.getImpl(s, cid, result)
  assert(result.len > 0)

proc get*(s: DagfsStore; cid: Cid): string =
  ## Retrieve a raw block from the store.
  result = ""
  s.get(cid, result)

proc putDag*(s: DagfsStore; dag: CborNode): Cid =
  ## Place an Dagfs node in the store.
  var raw = encode dag
  s.put raw

proc getDag*(s: DagfsStore; cid: Cid): CborNode =
  ## Retrieve an CBOR DAG from the store.
  let stream = newStringStream(s.get(cid))
  result = readCbor stream
  close stream

proc dagHash*(buf: cstring; len: Natural): Cid =
  assert(len <= maxChunkSize)
  var b: Blake2b
  blake2b_init(b, digestLen, nil, 0)
  blake2b_update(b, buf, len)
  var s = blake2b_final(b)
  for i in 0..digestLen-1: result.add s[i].char

proc dagHash*(data: string): Cid =
  ## Generate a CID for a string of data using the BLAKE2b hash algorithm.
  assert(data.len <= maxChunkSize)
  var b: Blake2b
  blake2b_init(b, digestLen, nil, 0)
  blake2b_update(b, data, data.len)
  var s = blake2b_final(b)
  for i in 0..digestLen-1: result.add s[i].char
  # copyMem(result[0].addr, s[0].addr, digestLen)

proc addFile*(store: DagfsStore; path: string): FsNode =
  ## Add a file to the store and a FsNode.
  let
    file = openAsync(path, fmRead)
    fileSize = file.getFileSize
    u = newUnixfsFile()
  u.links = newSeqOfCap[FileLink](1)
  var
    buf = newString(min(maxChunKSize, fileSize))
    pos = 0
  let shortLen = fileSize mod maxChunKSize
  if 0 < shortLen:
    buf.setLen shortLen
  while true:
    let n = waitFor file.readBuffer(buf[0].addr, buf.len)
    buf.setLen n
    let cid = store.put(buf)
    u.links.add FileLink(cid: cid, size: buf.len)
    u.size.inc buf.len
    pos.inc n
    if pos >= fileSize: break
    buf.setLen maxChunkSize
  close file
  if u.size == 0:
    u.cid = dagHash("")
  else:
    if u.links.len == 1:
      u.cid = u.links[0].cid
    else:
      u.cid = store.putDag(%u)
  result = u

proc addDir*(store: DagfsStore; dirPath: string): FsNode =
  var dRoot = newFsRoot()
  for kind, path in walkDir dirPath:
    var child: FsNode
    case kind
    of pcFile:
      child = store.addFile path
    of pcDir:
      child = store.addDir(path)
    else: continue
    dRoot.add path.extractFilename, child
  let
    dag = %dRoot
    cid = store.putDag(dag)
  result = newUnixfsDir(cid)

# proc openCid*(store: DagfsStore; cid: Cid): FsNode =
#   result = parseFs(store.get(cid), cid)

template raiseMissing*(cid: Cid) =
  raise MissingChunk(msg: "chunk missing from store", cid: cid)

proc openDir*(store: DagfsStore; cid: Cid): FsNode =
  var raw = ""
  try: store.get(cid, raw)
  except MissingChunk: raiseMissing cid
    # this sucks
  result = parseFs(raw, cid)
  assert(result.kind == dirNode)

proc walk*(store: DagfsStore; dir: FsNode; path: string; cache = true): FsNode =
  ## Walk a path down a root.
  assert(dir.kind == dirNode)
  result = dir
  var raw = ""
  for name in split(path, DirSep):
    if name == "": continue
    if result.kind == fileNode:
      result = nil
      break
    var next = result[name]
    if next.isNil:
      result = nil
      break
    if (next.kind in {shallowFile, shallowDir}):
      store.get(next.cid, raw)
      next = parseFs(raw, next.cid)
      if cache:
        result.entries[name] = next
    result = next

iterator fileChunks*(store: DagfsStore; file: FsNode): string =
  ## Iterate over the links in a file and return futures for link data.
  if file.isRaw:
    yield store.get(file.cid)
  else:
    var
      i = 0
      chunk = ""
    while i < file.links.len:
      store.get(file.links[i].cid, chunk)
      yield chunk
      inc i

proc readBuffer*(store: DagfsStore; file: FsNode; pos: BiggestInt;
                 buf: pointer; size: int): int =
  ## Read a UnixFS file into a buffer. May return zero for any failure.
  assert(pos > -1)
  var
    filePos = 0
    chunk = ""
  if pos < file.size:
    # if file.cid.isRaw:
    #   let pos = pos.int
    #   store.get(file.cid, chunk)
    #   if pos < chunk.high:
    #     copyMem(buf, chunk[pos].addr, min(chunk.len - pos, size))
    #   result = size
    # else:
    block:
      for i in 0..file.links.high:
        let linkSize = file.links[i].size
        if filePos <= pos and pos < filePos+linkSize:
          store.get(file.links[i].cid, chunk)
          let
            chunkPos = int(pos - filePos)
            n = min(chunk.len-chunkPos, size)
          copyMem(buf, chunk[chunkPos].addr, n)
          result = n
          break
        filePos.inc linkSize


proc parentAndFile(fs: FileStore; cid: Cid): (string, string) =
  ## Generate the parent path and file path of CID within the store.
  let digest = toHex cid
  result[0]  = fs.root / digest[0..1]
  result[1]  = result[0] / digest[2..digestLen+1]

proc parseCid*(s: string): Cid =
  ## Detect CID encoding and parse from a string.
  var raw = parseHexStr s
  if raw.len != digestLen:
    raise newException(ValueError, "invalid ID length")
  result = s

const zeroChunk* = parseCid "8ddb61928ec76e4ee904cd79ed977ab6f5d9187f1102975060a6ba6ce10e5481"
    ## CID of zero chunk of maximum size.

proc fsPutBuffer(s: DagfsStore; buf: cstring; len: Natural): Cid =
  var fs = FileStore(s)
  result = dagHash(buf, len)
  if result != zeroChunk:
    let (dir, path) = fs.parentAndFile(result)
    if not existsDir dir:
      createDir dir
    if not existsFile path:
      fs.buf.setLen(len)
      copyMem(addr fs.buf[0], buf, fs.buf.len)
      let
        tmp = fs.root / "tmp"
      writeFile(tmp, fs.buf)
      moveFile(tmp, path)

proc fsPut(s: DagfsStore; chunk: string): Cid =
  var fs = FileStore(s)
  result = dagHash chunk
  
  if result != zeroChunk:
    let (dir, path) = fs.parentAndFile(result)
    if not existsDir dir:
      createDir dir
    if not existsFile path:
      let
        tmp = fs.root / "tmp"
      writeFile(tmp, chunk)
      moveFile(tmp, path)
    

proc fsGetBuffer(s: DagfsStore; cid: Cid; buf: cstring; len: Natural): int =
  var fs = FileStore(s)
  let (_, path) = fs.parentAndFile cid
  if existsFile path:
    let fSize = path.getFileSize
    if maxChunkSize < fSize:
      discard tryRemoveFile path
      raiseMissing cid
    if len.int64 < fSize:
      raise newException(BufferTooSmall, "file is $1 bytes, buffer is $2" % [$fSize, $len])
    let file = open(path, fmRead)
    result = file.readBuffer(buf, len)
    close file
  if result == 0:
    raiseMissing cid

proc fsGet(s: DagfsStore; cid: Cid; result: var string) =
  var fs = FileStore(s)
  let (_, path) = fs.parentAndFile cid
  if existsFile path:
    let fSize = path.getFileSize
    if fSize > maxChunkSize:
      discard tryRemoveFile path
      raiseMissing cid
    result.setLen fSize.int
    let
     file = open(path, fmRead)
     n = file.readChars(result, 0, result.len)
    close file
    doAssert(n == result.len)
  else:
    raiseMissing cid

proc newFileStore*(root: string): FileStore =
  if not existsDir(root):
    createDir root
  new result
  result.putBufferImpl = fsPutBuffer
  result.putImpl = fsPut
  result.getBufferImpl = fsGetBuffer
  result.getImpl = fsGet
  result.root = root
  result.buf = ""

proc `==`*(cbor: CborNode; cid: Cid): bool =
  ## Compare a CBOR node with a CID.
  if cbor.kind == cborBytes:
    for i in 0..<digestLen:
      if cid[i] != cbor.bytes[i].char:
        return false
    result = true

proc writeUvarint*(s: Stream; n: SomeInteger) =
  var n = n
  while true:
    let c = int8(n and 0x7f)
    n = n shr 7
    if n == 0:
      s.write((char)c.char)
      break
    else:
      s.write((char)c or 0x80)

proc readUvarint*(s: Stream): BiggestInt =
  ## Read an IPFS varint
  var shift: int
  while shift < (9*8):
    let c = (BiggestInt)s.readChar
    result = result or ((c and 0x7f) shl shift)
    if (c and 0x80) == 0:
      break
    shift.inc 7

const len8tab: array[256,uint8] = [
  0x00.uint8, 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
  0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
  0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
  0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
]

proc len64(y: uint64): int =
  var x = y
  if x >= 1 shl 32 :
    x = x shr 32
    result = 32
  if x >= 1 shl 16:
    x = x shr 16
    result += 16
  if x >= 1 shl 8:
    x = x shr 8
    result += 8
  return result + int(len8tab[x])

proc uvarintSize(num: uint64): int = 
  var bits = len64(num)
  var q= bits div 7
  var r = bits mod 7
  var size = q
  if r > 0 or size == 0 :
    size.inc
  result = size

proc putUvarint(buf: var seq[byte], y :uint64): int =
  var i = 0
  var x = y
  while x >= 0x80 :
    buf[i] = byte(x) or 0x80
    x = x shl 7
    i.inc
  buf[i] = byte(x)
  return i + 1

proc encode*(buf:seq[byte], code:var uint64): seq[byte] = 
  result = newSeqOfCap[byte](uvarintSize(code) + uvarintSize(uint64(len(buf)))+len(buf))
  var n = putUvarint(result, code)
  var tmp = result[n..^1]
  n += putUvarint(tmp, uint64(len(buf)))
  result.add buf

proc fromUvarint(buf: seq[byte]): (uint64, int) =
  var x: uint64
  var s: uint
  for i, b in buf:
    if b < 0x80 :
      if i > 9 or i == 9 and b > 1 :
        return (0'u64, 0)
      elif b == 0 and s > 0 :
        return (0'u64, 0)
      return (x or uint64(b) shl s, i + 1)
    x = x or uint64(b and 0x7f) shl s
    s += 7
  return (0'u64, 0)

proc uvarint(buf: seq[byte]): (uint64, seq[byte]) =
  var (n, c) = fromUvarint(buf)
  if c == 0:
    return (n, buf)
  elif c < 0:
    return (n, buf[-c..^1])
  else:
    return (n, buf[-c..^1])

proc readMultihashFromBuf(buf: seq[byte]): (int, uint64, seq[byte]) =
  var bufl = len(buf)
  if bufl < 2:
    return (0, 0'u64, @[])
  
  var tmp = buf
  var code, length:uint64

  (code, tmp) = uvarint(tmp)
  (length, tmp) = uvarint(tmp)
  if length > 1 shl 32 :
    return (0, 0'u64, @[])
  if int(length) > len(tmp) :
    return (0, 0'u64, @[])

  var rlen = (bufl - len(tmp)) + int(length)
  return (rlen, code, tmp[0..length])

type DecodedMultihash = object
  code: uint64
  name: string
  length: int
  digest: seq[byte]




let codes = {IDENTITY:     "identity",
  SHA1:         "sha1",
  SHA2_256:     "sha2-256",
  SHA2_512:     "sha2-512",
  SHA3_224:     "sha3-224",
  SHA3_256:     "sha3-256",
  SHA3_384:     "sha3-384",
  SHA3_512:     "sha3-512",
  DBL_SHA2_256: "dbl-sha2-256",
  MURMUR3_128:  "murmur3-128",
  KECCAK_224:   "keccak-224",
  KECCAK_256:   "keccak-256",
  KECCAK_384:   "keccak-384",
  KECCAK_512:   "keccak-512",
  SHAKE_128:    "shake-128",
  SHAKE_256:    "shake-256",
  X11:          "x11",
  MD5:          "md5",
}.toTable

proc decode*(buf: seq[byte]):DecodedMultihash = 
  var (rlen, c,hdig) = readMultihashFromBuf(buf)
  with result:
    code = c
    name = codes[c.int]
    length = hdig.len
    digest = hdig

proc toIpfs*(cid: Cid): string =
  const
    multiRaw = 0x55
    multiBlake2b_256 = 0xb220
  let s = newStringStream()
  s.writeUvarint 1
  s.writeUvarint multiRaw
  s.writeUvarint multi_blake2b_256
  s.writeUvarint digestLen
  s.write cid
  s.setPosition 0
  result =  bitcoin.encode(s.readAll)
  close s


iterator simpleChunks*(s: Stream; size = maxChunkSize): string =
  doAssert(size <= maxChunkSize)
  var tmp = newString(size)
  while not s.atEnd:
    tmp.setLen(size)
    tmp.setLen(s.readData(tmp[0].addr, size))
    yield tmp

proc print(a: Atom; s: Stream)
proc print(ast: NodeRef; s: Stream)

proc newAtom(c: Cid): Atom =
  Atom(kind: atomCid, cid: c)

proc newAtomError(msg: string): Atom =
  Atom(kind: atomError, err: msg)

proc newAtomPath(s: string): Atom =
  try:
    let path = expandFilename s
    Atom(kind: atomPath, path: path)
  except OSError:
    newAtomError("invalid path '$1'" % s)

proc newAtomString(s: string): Atom =
  Atom(kind: atomString, str: s)

proc newNodeError(msg: string; n: NodeObj): NodeRef =
  var p = new NodeRef
  p[] = n
  NodeRef(kind: nodeError, errMsg: msg, errNode: p)

proc newNode(a: Atom): NodeRef =
  NodeRef(kind: nodeAtom, atom: a)

proc newNodeList(): NodeRef =
  NodeRef(kind: nodeList)

proc next(n: NodeObj | NodeRef): NodeObj =
  ## Return a copy of list element that follows Node n.
  assert(not n.nextRef.isNil, "next element is nil")
  result = n.nextRef[]

proc head(list: NodeObj | NodeRef): NodeObj =
  ## Return the start element of a list Node.
  list.headRef[]

proc `next=`(n, p: NodeRef) =
  ## Return a copy of list element that follows Node n.
  assert(n.nextRef.isNil, "append to node that is not at the end of a list")
  n.nextRef = p

iterator list(n: NodeObj): NodeObj =
  ## Iterate over members of a list node.
  var n = n.headRef
  while not n.isNil:
    yield n[]
    n = n.nextRef

iterator walk(n: NodeObj): NodeObj =
  ## Walk down the singly linked list starting from a member node.
  var n = n
  while not n.nextRef.isNil:
    yield n
    n = n.nextRef[]
  yield n

proc append(list, n: NodeRef) =
  ## Append a node to the end of a list node.
  if list.headRef.isNil:
    list.headRef = n
    list.tailRef = n
  else:
    list.tailRef.next = n
    while not list.tailRef.nextRef.isNil:
      assert(list.tailRef != list.tailRef.nextRef)
      list.tailRef = list.tailRef.nextRef

proc append(list: NodeRef; n: NodeObj) =
  let p = new NodeRef
  p[] = n
  list.append p

proc getFile(env: Env; path: string): FsNode =
  result = env.paths.getOrDefault path
  if result.isNil:
    result = env.store.addFile(path)
    assert(not result.isNil)
    env.paths[path] = result

proc getDir(env: Env; path: string): FsNode =
  result = env.paths.getOrDefault path
  if result.isNil:
    result = env.store.addDir(path)
    assert(not result.isNil)
    env.paths[path] = result

proc getUnixfs(env: Env; cid: Cid): FsNode =
  result = env.cids.getOrDefault cid
  if result.isNil:
    var raw = ""
    env.store.get(cid, raw)
    result = parseFs(raw, cid)
    env.cids[cid] = result

type
  Tokens = seq[string]

  Reader = ref object
    buffer: string
    tokens: Tokens
    pos: int

proc newReader(): Reader =
  Reader(buffer: "", tokens: newSeq[string]())

proc next(r: Reader): string =
  assert(r.pos < r.tokens.len, $r.tokens)
  result = r.tokens[r.pos]
  inc r.pos

proc peek(r: Reader): string =
  assert(r.pos < r.tokens.len, $r.tokens)
  r.tokens[r.pos]

proc print(a: Atom; s: Stream) =
  case a.kind
  of atomPath:
    s.write a.path
  of atomCid:
    s.write $a.cid
  of atomString:
    s.write '"'
    s.write a.str
    s.write '"'
  #[
  of atomData:
    let fut = newFutureStream[string]()
    asyncCheck env.store.fileStream(a.fileCid, fut)
    while true:
      let (valid, chunk) = fut.read()
      if not valid: break
      f.write chunk
    ]#
  of atomSymbol:
    s.write a.sym
  of atomError:
    s.write "«"
    s.write a.err
    s.write "»"

proc print(ast: NodeObj; s: Stream) =
  case ast.kind:
  of nodeAtom:
    ast.atom.print(s)
  of nodeList:
    s.write "\n("
    for n in ast.list:
      s.write " "
      n.print(s)
    s.write ")"
  of nodeFunc:
    s.write "#<procedure "
    s.write ast.name
    s.write ">"
  of nodeError:
    s.write "«"
    s.write ast.errMsg
    s.write ": "
    ast.errNode.print s
    s.write "»"

proc print(ast: NodeRef; s: Stream) =
  if ast.isNil:
    s.write "«nil»"
  else:
    ast[].print s

proc readAtom(r: Reader): Atom =
  let token = r.next
  block:
    if token[token.low] == '"':
      if token[token.high] != '"':
        newAtomError("invalid string '$1'" % token)
      else:
        newAtomString(token[1..token.len-2])
    elif token.contains DirSep:
      # TODO: memoize this, store a table of paths to atoms
      newAtomPath token
    elif token.len == 46 or token.len > 48:
      Atom(kind: atomCid, cid: token.parseCid)
    else:
      Atom(kind: atomSymbol, sym: token.normalize)
  #except:
   # newAtomError(getCurrentExceptionMsg())

proc readForm(r: Reader): NodeRef

proc readList(r: Reader): NodeRef =
  result = newNodeList()
  while true:
    if (r.pos == r.tokens.len):
      return nil
    let p = r.peek
    case p[p.high]
    of ')':
      discard r.next
      break
    else:
      result.append r.readForm

proc readForm(r: Reader): NodeRef =
  case r.peek[0]
  of '(':
    discard r.next
    r.readList
  else:
    r.readAtom.newNode

proc tokenizer(s: string): Tokens =
  # TODO: this sucks
  let tokens = s.findAll(re"""[\s,]*(~@|[\[\]{}()'`~^@]|"(?:\\.|[^\\"])*"|;.*|[^\s\[\]{}('"`,;)]*)""")
  result = newSeqOfCap[string] tokens.len
  for s in tokens:
    let t = s.strip(leading = true, trailing = false).strip(leading = false, trailing = true)
    if t.len > 0:
      result.add t

proc read(r: Reader; line: string): NodeRef =
  r.pos = 0
  if r.buffer.len > 0:
    r.buffer.add " "
    r.buffer.add line
    r.tokens = r.buffer.tokenizer
  else:
    r.tokens = line.tokenizer
  result = r.readForm
  if result.isNil:
    r.buffer = line
  else:
    r.buffer.setLen 0

proc assertArgCount(args: NodeObj; len: int) =
  var arg = args
  for _ in 2..len:
    doAssert(not arg.nextRef.isNil)
    arg = arg.next
  doAssert(arg.nextRef.isNil)

##
# Builtin functions
#

proc applyFunc(env: Env; args: NodeObj): NodeRef =
  assertArgCount(args, 2)
  let
    fn = args
    ln = fn.next
  fn.fun(env, ln.head)

proc cborFunc(env: Env; arg: NodeObj): NodeRef =
  assertArgCount(arg, 1)
  let
    a = arg.atom
    ufsNode = env.getUnixfs a.cid
    diag = $ %ufsNode
  diag.newAtomString.newNode

proc copyFunc(env: Env; args: NodeObj): NodeRef =
  assertArgCount(args, 3)
  let
    x = args
    y = x.next
    z = y.next
  var root = newFsRoot()
  let dir = env.getUnixfs x.atom.cid
  for name, node in dir.items:
    root.add(name, node)
  root.add(z.atom.str, dir[y.atom.str])
  let cid = env.store.putDag(%root)
  cid.newAtom.newNode

proc consFunc(env: Env; args: NodeObj): NodeRef =
  assertArgCount(args, 2)
  result = newNodeList()
  let
    car = args
    cdr = args.next
  result.append car
  result.append cdr.head

proc defineFunc(env: Env; args: NodeObj): NodeRef =
  assertArgCount(args, 2)
  let
    symN = args
    val = args.next
  env.bindings[symN.atom.sym] = val
  new result
  result[] = val

proc globFunc(env: Env; args: NodeObj): NodeRef =
  result = newNodeList()
  for n in args.walk:
    let a = n.atom
    case a.kind
    of atomPath:
      result.append n
    of atomString:
      for match in walkPattern a.str:
        result.append match.newAtomPath.newNode
    else:
      result = newNodeError("invalid glob argument", n)

proc ingestFunc(env: Env; args: NodeObj): NodeRef =
  var root = newFsRoot()
  for n in args.walk:
    let
      a = n.atom
      name = a.path.extractFilename
      info = a.path.getFileInfo
    case info.kind
    of pcFile, pcLinkToFile:
      let file = env.getFile a.path
      root.add(name, file)
    of pcDir, pcLinkToDir:
      let dir = env.getDir a.path
      root.add(name, dir)
  let
    cid = env.store.putDag(%root)
  cid.newAtom.newNode

proc listFunc(env: Env; args: NodeObj): NodeRef =
  ## Standard Lisp 'list' function.
  result = newNodeList()
  new result.headRef
  result.headRef[] = args
  result.tailRef = result.headRef
  while not result.tailRef.nextRef.isNil:
    result.tailRef = result.tailRef.nextRef

proc lsFunc(env: Env; args: NodeObj): NodeRef =
  result = newNodeList()
  for n in args.walk:
    let 
      a = n.atom
      ufsNode = env.getUnixfs a.cid
    if ufsNode.isDir:
      for name, u in ufsNode.items:
        let e = newNodeList()
        e.append u.cid.newAtom.newNode
        e.append name.newAtomString.newNode
        result.append e

proc mapFunc(env: Env; args: NodeObj): NodeRef =
  assertArgCount(args, 2)
  result = newNodeList()
  let f = args.fun
  for v in args.next.list:
    result.append f(env, v)

proc mergeFunc(env: Env; args: NodeObj): NodeRef =
  var root = newFsRoot()
  for n in args.walk:
    let
      a = n.atom
      dir = env.getUnixfs a.cid
    for name, node in dir.items:
      root.add(name, node)
  let cid = env.store.putDag(%root)
  cid.newAtom.newNode

proc pathFunc(env: Env; arg: NodeObj): NodeRef =
  result = arg.atom.str.newAtomPath.newNode

proc rootFunc(env: Env; args: NodeObj): NodeRef =
  var root = newFsRoot()
  let
    name = args.atom.str
    cid = args.next.atom.cid
    ufs = env.getUnixfs cid
  root.add(name, ufs)
  let rootCid = env.store.putDag(%root)
  rootCid.newAtom.newNode

proc walkFunc(env: Env; args: NodeObj): NodeRef =
  let
    rootCid = args.atom.cid
    walkPath = args.next.atom.str
    root = env.getUnixfs rootCid
    final = env.store.walk(root, walkPath)
  if final.isNil:
    result = newNodeError("no walk to '$1'" % walkPath, args)
  else:
     result = final.cid.newAtom.newNode

##
# Environment
#

proc bindEnv(env: Env; name: string; fun: Func) =
  assert(not env.bindings.contains name)
  env.bindings[name] = NodeObj(kind: nodeFunc, fun: fun, name: name)

proc newEnv(store: DagfsStore): Env =
  result = Env(
    store: store,
    bindings: initTable[string, NodeObj](),
    paths: initTable[string, FsNode](),
    cids: initTable[Cid, FsNode]())
  result.bindEnv "apply", applyFunc
  result.bindEnv "cbor", cborFunc
  result.bindEnv "cons", consFunc
  result.bindEnv "copy", copyFunc
  result.bindEnv "define", defineFunc
  result.bindEnv "glob", globFunc
  result.bindEnv "ingest", ingestFunc
  result.bindEnv "list", listFunc
  result.bindEnv "ls", lsFunc
  result.bindEnv "map", mapFunc
  result.bindEnv "merge", mergeFunc
  result.bindEnv "path", pathFunc
  result.bindEnv "root", rootFunc
  result.bindEnv "walk", walkFunc

proc eval(ast: NodeRef; env: Env): NodeRef

proc eval_ast(ast: NodeRef; env: Env): NodeRef =
  result = ast
  case ast.kind
  of nodeList:
    result = newNodeList()
    while not ast.headRef.isNil:
      # cut out the head of the list and evaluate
      let n = ast.headRef
      ast.headRef = n.nextRef
      n.nextRef = nil
      let x = n.eval(env)
      result.append x
  of nodeAtom:
    if ast.atom.kind == atomSymbol:
      if env.bindings.contains ast.atom.sym:
        result = new NodeRef
        result[] = env.bindings[ast.atom.sym]
  else: discard

proc eval(ast: NodeRef; env: Env): NodeRef =
  var input = ast[]
  try:
    if ast.kind == nodeList:
      if ast.headRef == nil:
        newNodeList()
      else:
        let
          ast = eval_ast(ast, env)
          head = ast.headRef
        if head.kind == nodeFunc:
          if not head.nextRef.isNil:
            input = head.next
            head.fun(env, input)
          else:
            input = NodeObj(kind: nodeList)
            head.fun(env, input)
        else:
          input = head[]
          newNodeError("not a function", input)
    else:
      eval_ast(ast, env)
  except EvalError:
    newNodeError(getCurrentExceptionMsg(), input)
  except FieldError:
    newNodeError("invalid argument", input)
  except MissingChunk:
    newNodeError("chunk not in store", input)
  except OSError:
    newNodeError(getCurrentExceptionMsg(), input)

var scripted = false

when defined(windows):
  var url = "d:/videos/"
else:
  url = "/mnt/d/videos"
proc openStore(): FileStore =
  # const key = "BLOB_STORE_URL"
  # var url = os.getEnv key
  # if url == "":
  #   url = "/mnt/d/videos"
  newFileStore(url)

import rdstdin

proc readLineSimple(prompt: string; line: var TaintedString): bool =
  stdin.readLine(line)

proc replMain() =
  let
    store = openStore()
    env = newEnv(store)
    outStream = stdout.newFileStream
    readLine = if scripted: readLineSimple else: readLineFromStdin

  var
    reader = newReader()
    line = newStringOfCap 128
  while readLine("> ", line):
    if line.len > 0:
      let ast = reader.read(line)
      if not ast.isNil:
        ast.eval(env).print(outStream)
        outStream.write "\n"
        flush outStream

proc contains*(store: FileStore; trie: FsNode; name: Cid): bool =
  if trie.isDir:
    for k,v in trie.entries:
      if contains(store, v, name): 
        result = true
        break
  else:
      result = trie.links.anyIt(it.cid == name)

# proc fsOpenBlobStream(s: FileStore; id: Cid; size: BiggestInt): FileStream =
#   var fs = FileStore(s)
#   try:
#     let
#       path = fs.root / "data" / id.toBase58
#       file = openAsync(path, fmRead)
#     result = FsBlobStream(
#       closeImpl: fsBlobClose,
#       sizeImpl: fsBlobSize,
#       setPosImpl: setPosFs,
#       getPosImpl: getPosFs,
#       readImpl: fsBlobRead,
#       path: path, file: file,
#     )
#   except:
#     raise newException(KeyError, "blob not in file-system store")


proc emptyMain() =
  let
    store = openStore()
    cid = store.putDag(%newFsRoot())


proc dumpMain() =
  var args = newSeq[string]()
  for kind, key, val in getopt():
    if kind == cmdArgument:
      args.add key
  if args.len > 1:
    let store = openStore()
    for i in 1..args.high:
      try:
        for chunk in store.fileChunks(parseFs(store.get(args[i]), args[i])):
          write(stdout, chunk)
      except:
        writeLine(stderr, "failed to dump '", args[i], "', ", getCurrentExceptionMsg())
        quit(-1)


proc ingestMain() {.async.} =
  var args = newSeq[string]()
  for kind, key, val in getopt():
    if kind == cmdArgument:
      args.add key
  if args.len > 1:
    var fs: FsNode
    let store = newFileStore(url)
    for i in 1..args.high:
      let path = normalizedPath args[i]
      var fileInfo = getFileInfo(args[i])
      if fileInfo.kind == pcFile:
        fs = store.addFile args[i]
      else:
        fs = store.addDir args[i]
    let final = store.putDag(%fs)
    writeLine(stdout, toIpfs final)


when isMainModule:
  var cmd = ""
  for kind, key, val in getopt():
    if kind == cmdArgument:
      cmd = key
      break
  case normalize(cmd)
  of "": quit("no subcommand specified")
  of "empty": emptyMain()
  of "repl": replMain()
  of "dump": dumpMain()
  of "ingest": waitFor ingestMain()
  else: quit("no such subcommand " & cmd)