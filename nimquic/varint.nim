import streams
const 
    maxVarInt1 = 63
    maxVarInt2 = 16383
    maxVarInt4 = 1073741823
    maxVarInt8 = 4611686018427387903

proc readVarInt*(s: Stream) =
    s.readData(1) 