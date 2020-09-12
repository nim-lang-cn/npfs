import json
import blocks,format,merkledag, format, cid, system,multihash
import nimSHA2

type Link* = ref object
    name: string 
    hash: string
    size: uint64

type Object* = ref object
    Hash:  string
    Links: seq[Link]
    Size:  string

type V1Builder* = ref object 
    Codec:uint64
    MhType:uint64
    MhLength: int

proc sum(b:V1Builder, data:string): Cid = 
    var hash = computeSHA256(data, 32)
    result = Cid(str: $hash)

proc getcodec(b:V1Builder):uint64 = DagProtobuf

proc WithCodec(p:V1Builder, c:uint64):V1Builder = 
    if c == DagProtobuf: p
    else:  V1Builder(Codec:c, Mhtype: SHA2_256)

#Adder holds the switches passed to the `add` command.
type Adder* = ref object
    blockstore: BasicBlock
    dagService: DAGService
    outChan: Channel[pointer]
    progress: bool
    hidden: bool
    pin: bool
    trickle: bool
    rawLeaves: bool
    silent: bool
    wrap: bool
    noCopy: bool
    chunker: string
    root: Node
    mroot: Root
    tempRoot:  Cid
    cidBuilder: V1Builder
    liveNodes: uint64

type ProgressReader* = ref object
    file: File
    path: string
    outChan: Channel[pointer]
    bytes:   int64
    lastProgress: int64

type ProgressReader2 = ref object
    reader: ProgressReader
    fileInfo: File

proc mfsRoot(adder: Adder): Root = 
    if adder.mroot != nil:
        return adder.mroot
    var rnode = ProtoNode(data:d)
    rnode.setCidBuilder(adder.cidBuilder)
    var mr = mfs.newRoot(adder.ctx, adder.dagService, rnode, nil)
    adder.mroot = mr
    return adder.mroot

# SetMfsRoot sets `r` as the root for Adder.
proc setMfsRoot(adder: Adder, r: Root) = 
    adder.mroot = r

# Constructs a node from reader's data, and adds it. Doesn't pin.
proc add(adder: Adder , reader: Reader): Node = 
    var chnk = fromString(reader, Chunker)

    var params = ihelper.DagBuilderParams(
        dagserv:    adder.dagService,
        rawLeaves:  adder.rawLeaves,
        maxlinks:   ihelper.defaultLinksPerBlock,
        noCopy:     adder.noCopy,
        cidBuilder: adder.cidBuilder,
    )

    if adder.trickle:
        return trickle.layout(params.new(chnk))

    return balanced.layout(params.new(chnk))

# RootNode returns the root node of the Added.
proc RootNode(adder: Adder): ipld.Node = 
    if adder.root != nil:
        return adder.root, nil

    var mr = adder.mfsRoot()

    var root = mr.GetDirectory().GetNode()

    if !adder.Wrap and len(root.Links()) == 1:
        var nd = root.Links()[0].GetNode(adder.ctx, adder.dagService)
        root = nd

    adder.root = root
    return root
}

# Recursively pins the root node of Adder and
# writes the pin state to the backing datastore.
proc PinRoot(adder: Adder): string = 
    root := adder.RootNode()
    if !adder.Pin :
        return ""
    rnk := root.cid()
    adder.dagService.Add(adder.ctx, root)
    if adder.tempRoot.Defined() :
        adder.pinning.Unpin(adder.ctx, adder.tempRoot, true)
        adder.tempRoot = rnk

    adder.pinning.PinWithMode(rnk, pin.Recursive)
    return adder.pinning.Flush()

# Finalize flushes the mfs root directory and returns the mfs root node.
proc finalize(adder: Adder): Node = 
    mr, = adder.mfsRoot()
    var root: FSNode
    var rootdir = mr.getDirectory()
    root = rootdir
    err = root.flush()
    var name: string
    if !adder.wrap : 
        children, = rootdir.listNames(adder.ctx)
        if len(children) == 0: 
            return ""
        name = children[0]
        root = rootdir.Child(name)
    err = adder.outputDirs(name, root)
    err = mr.Close()
    return root.GetNode()


proc outputDirs(adder: Adder, path: string, fsn: FSNode): string = 
    case fsn :
    of mfs.File:
        return ""
    of mfs.Directory:
        var names = fsn.listNames(adder.ctx)
        for _, name := range names :
            child = fsn.child(name)
            var childpath = gopath.join(path, name)
            err = adder.outputDirs(childpath, child)
            fsn.uncache(name)
            
        var nd = fsn.getNode()
        outputDagnode(out, path, nd)
        
# Add builds a merkledag node from a reader, adds it to the blockstore,
# and returns the key representing that node.
# If you want to pin it, use NewAdder() and Adder.PinRoot().
proc add*(n: IpfsNode, r: Reader): string = 
    return addWithContext(n.context(), n, r)

# AddWithContext does the same as Add, but with a custom context.
proc addWithContext(ctx: context, n: IpfsNode, r Reader): string = 
    defer: n.Blockstore.pinLock().unlock()
    fileAdder, = newAdder(ctx, n.pinning, n.blockstore, n.DAG)
    node, = fileAdder.add(r)
    return node.cid()

# AddR recursively adds files in |path|.
proc addR*(n: *core.IpfsNode, root: string): string = 
    defer: n.Blockstore.PinLock().Unlock()
    var stat = os.Lstat(root)
    f = files.newSerialFile(filepath.Base(root), root, false, stat)
    defer: f.Close()

    fileAdder = newAdder(n.context(), n.Pinning, n.Blockstore, n.DAG)
    err = fileAdder.addFile(f)
    nd = fileAdder.finalize()
    return nd

# addWrapped adds data from a reader, and wraps it with a directory object
# to preserve the filename.
# Returns the path of the added file ("<dir hash>/filename"), the DAG node of
# the directory, and and string if any.
proc addWrapped*(n: core.IpfsNode, r: Reader, filename: string): ipld.Node = 
    var file = files.newReaderFile(filename, filename, nopCloser(r), nil)
    fileAdder = newAdder(n.context(), n.pinning, n.blockstore, n.DAG)
    fileAdder.wrap = true
    defer: n.Blockstore.pinLock().unlock()
    fileAdder.addFile(file)
    dagnode = fileAdder.finalize()
    c := dagnode.cid()
    result = dagnode

proc addNode(adder: Adder, node: ipld.Node, path: string): string =
    if path == "" :
        path = node.cid()
    var pi = node.(*posinfo.filestoreNode)
    node = pi.Node

    mr, = adder.mfsRoot()
    dir := gopath.dir(path)
    if dir != "." :
        opts := mfs.MkdirOpts(mkparents: true,flush: false, cidBuilder: adder.cidBuilder)
        mfs.mkdir(mr, dir, opts)

    mfs.putNode(mr, path, node)

    if !adder.Silent :
        result = outputDagnode(adder.Out, path, node)

# AddFile adds the given file while respecting the adder.
proc AddFile(adder: Adder, file: File): string =
    return adder.addFile(file)

proc addFile(adder: Adder, file: File): string =
    if adder.liveNodes >= liveCacheSize: 
        var mr = adder.mfsRoot()
        if mr.FlushMemFree(adder.ctx):
            return ""
        adder.liveNodes = 0
    adder.liveNodes.inc

    if file.IsDirectory() :
        return adder.addDir(file)
    
    var s = file.(*files.symlink)
    sdata = symlinkData(s.target)

    dagnode := dag.nodeWithData(sdata)
    dagnode.setCidBuilder(adder.cidBuilder)
    err = adder.dagService.add(adder.ctx, dagnode)

    result = adder.addNode(dagnode, s.fileName())

    # case for regular file
    # if the progress flag was specified, wrap the file so that we can send
    # progress updates to the client (over the output channel)
    var reader: io.Reader = file
    if adder.progress: 
        var rdr = progressReader(file: file, outChan: out)
        if fi = file.(files.fileInfo):
            reader = progressReader2(rdr, fi)
        else:
            reader = rdr

    dagnode = adder.add(reader)

    var addFileName = file.fileName()
    var    addFileInfo = file.(files.fileInfo)
    if addFileInfo.absPath() == os.stdin.name() and adder.name != "" :
        addFileName = adder.name
        adder.name = ""
    return adder.addNode(dagnode, addFileName)
}

proc addDir(adder: Adder, dir: File): string = 
    var mr = adder.mfsRoot()
    err = mfs.mkdir(mr, dir.fileName(), 
            mfs.mkdirOpts(mkparents: true, flush: false, cidBuilder: adder.cidBuilder))

    while true:
        file, = dir.nextFile()
        if err != nil and err != io.EOF:
            return err
        if file == nil:
            break
        if files.isHidden(file) and !adder.hidden:
            continue
        err = adder.addFile(file)
        if err != nil:
            return err

# outputDagnode sends dagnode info over the output channel
proc outputDagnode(out: Channel[AddedObject], name: string, dn: ipld.Node): string = 
    var o = getOutput(dn)
    out.send %*{"hash": o.Hash, "name": name, "size": o.Size}

# from core/commands/object.go
proc getOutput(dagnode: ipld.Node): Object = 
    var c = dagnode.cid()
    s = dagnode.size()

    var output = Object(
        Hash:  c,
        Size:  parseInt(s, 10),
        Links: make([]Link, len(dagnode.Links())),
    )

    for i, link in  dagnode.Links() :
        output.Links[i] = Link(Name: link.Name, Size: link.Size)

    return output, nil

proc Read(i: ProgressReader, p: seq[byte]): int = 
    n, = i.file.Read(p)

    i.bytes += int64(n)
    if i.bytes-i.lastProgress >= progressReaderIncrement or err == io.EOF :
        i.lastProgress = i.bytes
        i.out.send %*{"name":  i.file.fileName(), "bytes": i.bytes}

    return n