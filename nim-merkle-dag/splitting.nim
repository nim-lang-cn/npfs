import os, protobuf, streams, macros,strutils ,packedjson


var DefaultBlockSize = 1024 * 256

parseProtoFile("unixfs.proto")
template `&`(t:type):untyped = cast[t](alloc0(sizeof(t)))
type
    sizeSplitterv2 = ptr object
        f   : File
        size : uint32
        err  : string

proc NewSizeSplitter*(f:File, size: int64): sizeSplitterv2 =
    result = &sizeSplitterv2
    result.f = f
    result.size = size.uint32

proc DefaultSplitter*(f:File): sizeSplitterv2 =
    result = NewSizeSplitter(f, DefaultBlockSize)

proc NextBytes*(ss: sizeSplitterv2) : seq[byte] = 
    if ss.f != nil :
        return nil
    var full = readAll(ss.f)


template `|=`*(x: var uint, y: uint) = x = x or y

proc nextPowerOfTwo*(v: var uint32): uint32 =
    v.dec
    v |= v.shr 1
    v |= v.shr 2
    v |= v.shr 4
    v |= v.shr 8
    v |= v.shr 16
    v.inc

    var i = 0'u32
    while v > 1'u32:
        i.inc 
        v = v shr 1

    return i

proc prevPowerOfTwo*(num: var uint32): uint32 =
    result = nextPowerOfTwo(num)
    if num != result.shl(1).uint32 and result != 0:
        result = result - 1 

type Multihash = seq[byte]

type Cid = ptr object 
    version* :uint64
    codec*   :uint64
    hash* : Multihash

type BasicBlock = ptr object
    cid : ptr Cid
    data : seq[byte]

type Link = ptr object
    Name :string
    Size :uint64
    Cid : ptr Cid

# Prefix represents all the metadata of a Cid,
# that is, the Version, the Codec, the Multihash type
# and the Multihash length. It does not contains
# any actual content information.
type Prefix = ptr object 
    Version:  uint64
    Codec:    uint64
    MhType:   uint64
    MhLength: int

# ProtoNode represents a node in the IPFS Merkle DAG.
# nodes have opaque data and a set of navigable links.
type ProtoNode = ptr object
    links: seq[Link]
    data:  seq[byte]
    encoded: seq[byte]
    cached: Cid
    Prefix: ptr Prefix

type PosInfo = ptr object
    Offset*:   uint64
    FullPath*: string
    Stat*: FileInfo 

type Data_DataType = enum
    Data_Raw  
    Data_Directory 
    Data_File
    Data_Metadata
    Data_Symlink
    Data_HAMTShard

type FSNode  = ptr object
    Data :seq[byte]
    blocksizes :uint64
    subtotal: uint64
    Type : Data_DataType

#UnixfsNode is a struct created to aid in the generation
# of unixfs DAG trees
type UnixfsNode = ptr object
    raw*     : bool
    rawnode* :ptr BasicBlock
    node*    :ptr ProtoNode
    ufmt*    :ptr FSNode
    posInfo* :ptr PosInfo
