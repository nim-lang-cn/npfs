import streams
import binaryparse
const 
    maxVarInt1*: uint64 = 63
    maxVarInt2* = 16383
    maxVarInt4* = 1073741823
    maxVarInt8* = 4611686018427387903'u64

# proc readVarInt*(s: Stream) =
#     s.readData(1) 

proc varIntLen*(s: Stream, l: uint64) =
    var length = l
    if length <= maxVarInt1:
        s.writeDataBE(cast[ptr array[1,uint8]](addr length), 1)
    if length <= maxVarInt2:
        s.writeDataBE(cast[ptr array[2,uint8]](addr length), 2)
    if length <= maxVarInt4:
        s.writeDataBE(cast[ptr array[4,uint8]](addr length), 4)
    if length <= maxVarInt8:
        s.writeDataBE(cast[ptr array[8,uint8]](addr length), 8)