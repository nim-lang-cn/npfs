import os, protobuf, streams, macros,strutils ,packedjson

parseProtoFile("unixfs.proto")

type
    sizeSplitterv2 = ref object
        f   : File
        size : uint32
        err  : string

proc NewSizeSplitter*(f:File, size: int64): sizeSplitterv2 =
    result = new(sizeSplitterv2)
    result.f = f
    result.size = size.uint32

proc NextBytes*(ss: ref sizeSplitterv2) : seq[byte] = 
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

type Multihash = distinct seq[byte]

type Cid = object 
    version* :uint64
    codec*   :uint64
    hash* : Multihash

type BasicBlock = object
    cid : ptr Cid
    data : seq[byte]

type Link = object
    Name :string
    Size :uint64
    Cid : ptr Cid

# Prefix represents all the metadata of a Cid,
# that is, the Version, the Codec, the Multihash type
# and the Multihash length. It does not contains
# any actual content information.
type Prefix = object 
    Version:  uint64
    Codec:    uint64
    MhType:   uint64
    MhLength: int

# ProtoNode represents a node in the IPFS Merkle DAG.
# nodes have opaque data and a set of navigable links.
type ProtoNode = object
    links: seq[Link]
    data:  seq[byte]
    encoded: seq[byte]
    cached: Cid
    Prefix: ptr Prefix

type PosInfo = object
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

type FSNode  = object
    Data :seq[byte]
    blocksizes :uint64
    subtotal: uint64
    Type : Data_DataType

#UnixfsNode is a struct created to aid in the generation
# of unixfs DAG trees
type UnixfsNode = ref object
    raw*     : bool
    rawnode* :ptr BasicBlock
    node*    :ptr ProtoNode
    ufmt*    :ptr FSNode
    posInfo* :ptr PosInfo
