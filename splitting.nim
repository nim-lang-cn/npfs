import os, protobuf, streams, macros,strutils ,json


var DefaultBlockSize = 1024 * 256

template `&`(t:type):untyped = cast[ptr t](alloc0(sizeof(t)))
type
    sizeSplitterv2 = ref object
        f   : File
        size : uint32
        err  : string

proc NewSizeSplitter*(f:File, size: int64):ptr sizeSplitterv2 =
    result = &sizeSplitterv2
    result.f = f
    result.size = size.uint32

proc DefaultSplitter*(f:File): ptr sizeSplitterv2 =
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














  
type blockstore* = ref object
    datastore : Batching
    rehash : bool

type blockService* = ref object
    blockstore : Blockstore
    exchange   : Interface
    checkFirst : bool

type FSRepo* = ref object
    closed :bool
    path :string
    lockfile : Closer
    config   : ptr Config
    ds       : Datastore
    keystore : Keystore
    filemgr  : FileManager
    

