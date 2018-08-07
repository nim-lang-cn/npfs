import os


var DefaultBlockSize = 1024 * 256

type
    sizeSplitterv2 = ref object
        f   : File
        size : uint32
        err  : string

proc DefaultSplitter*(f:File): sizeSplitterv2 =
    result = NewSizeSplitter(f, DefaultBlockSize)

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

