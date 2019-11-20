import binaryparse, streams, math, strformat, strutils, algorithm, sequtils
# import packet_number
import varint

# createParser(QuicVersionNegotiationPacket):
#     u8: headerType = 0x80
#     u32: version = 0x0
#     u4: dcil 
#     u4: scil
#     u8: dcid[if dcil != 0: dcil+3 else: 0]
#     u8: scid[if scil != 0: scil+3 else: 0]
#     u32: supportedVersions[]

# createParser(QuicRetryPacket):
#     u8: headerType = 0xfe
#     u32: version
#     u4: dcil
#     u4: scil
#     u8: dcid[if dcil != 0: dcil+3 else: 0]
#     u8: scid[if scil != 0: scil+3 else: 0]
#     u8: odcil
#     u8: odci[odcil]
#     u32: retryToken

# createParser(QuicHandshakePacket):
#     u8: headerType = 0xfd
#     u32: version
#     u4: dcil
#     u4: scil
#     u8: dcid[if dcil != 0: dcil+3 else: 0]
#     u8: scid[if scil != 0: scil+3 else: 0]
#     *packetNumber: inner


var packetNumber* = (get: (proc (s: Stream): tuple[number: uint64] =
    var firstOctet = 0
    s.readDataLE(firstOctet.addr , 1)
    var encodedLength = 0
    var firstBit = uint8 firstOctet shr 7
    if firstBit == 0 :
        encodedLength = 1
    else:
        case firstOctet shr 6 and 0x3
        of 2 :
            encodedLength = 2
        of 3:
            encodedLength = 4
        else: discard
    s.readDataLE(result.number.addr, encodedLength)
    ),
    put: (proc (s: Stream, input: var tuple[number: uint64]) =
        var firstOctet :uint8= 0
        if input.number <= 127'u64:
            s.write input.number and 0x7
        elif input.number <= 16383'u64 :
            s.write uint8 input.number shr 8 and 0x3f or 0x80
            s.write input.number.uint8
        elif input.number <= 1073741823'u64 :
            s.write uint8 input.number shr 24 and 0x3f or 0xc0
            s.write uint8 input.number shr 16
            s.write uint8 input.number shr 8
            s.write uint8 input.number 
        else: discard

    )
)

proc readVarInt*(s:Stream): tuple[varint: uint64] = 
    var firstOctet:uint8 = 0
    s.readDataLE(firstOctet.addr, 1)
    var length = 1 shl (firstOctet and uint(0xC shr 6))
    var b1: uint8 = firstOctet and (0xff - 0xc0)
    if length == 1:
        result.varint = b1
        return
    var b2: uint8
    s.readDataLE(b2.addr, 1)
    if length == 2:
        result.varint = b2 + b1 shl 8
        return
    var b3, b4: uint8
    s.readDataLE(b3.addr, 1)
    s.readDataLE(b4.addr, 1)
    if length == 4:
        result.varint = b4 + b3 shl 8 + b2 shl 16 + b1 shl 24
        return
    var b5, b6,b7,b8: uint8
    s.readDataLE(b5.addr, 1)
    s.readDataLE(b6.addr, 1)
    s.readDataLE(b7.addr, 1)
    s.readDataLE(b8.addr, 1)
    result.varint = b8 + (b7 shl 8) + (b6 shl 16) + (b5 shl 24) + 
                    (b4 shl 32) + (b3 shl 40) + (b2 shl 48) + (b1 shl 56)


proc writeVarInt*(s: Stream, input: var tuple[varint: uint64]) = 
    var buff : seq[uint8]
    var i = cast[ptr array[8,uint8]](addr input.varint)[]
    if input.varint <= maxVarInt1:
        s.writeDataBE(addr i[0], 1)
    elif input.varint <= maxVarInt2:
        var b1 = i[0] or 0x40
        s.writeDataBE(addr(b1), 1)
        s.writeDataBE(addr i[1], 1)
    elif input.varint <= maxVarInt4:
        var b1 = i[0] or 0x80
        s.writeDataBE(addr b1, 1)
        s.writeDataBE(addr i[1], 1)
        s.writeDataBE(addr i[2], 1)
        s.writeDataBE(addr i[3], 1)
    elif input.varint <= maxVarInt8:
        var b1 = i[0] or 0xc0
        s.writeDataBE(addr b1, 1)
        s.writeDataBE(addr i[1], 1)
        s.writeDataBE(addr i[2], 1)
        s.writeDataBE(addr i[3], 1)
        s.writeDataBE(addr i[4], 1)
        s.writeDataBE(addr i[5], 1)
        s.writeDataBE(addr i[6], 1)
        s.writeDataBE(addr i[7], 1)

var variableLengthEncoding* = (get: (proc(s:Stream): tuple[varint: uint64] = s.readVarInt),
    put: (proc (s: Stream, input: var tuple[varint: uint64]) = s.writeVarInt(input)))


var crypto* = (get:(proc(s:Stream): tuple[varint: uint64] = s.readVarInt),
                put:(proc (s: Stream, input: var tuple[varint: uint64]) = s.writeVarInt(input)))

createParser(QuicInitialPacket):
    u8: headerType = 0xff
    u32: version
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    *variableLengthEncoding: token
    u16: length
    *packetNumber: inner
    *crypto :cryptoFrame

proc uintToArray(i: var uint64): seq[uint8] = 
    result  = @cast[array[8,uint8]](i)
    result.reverse()
    echo result.mapIt(it.toHex)

# when isMainModule:
#     var packet :typeGetter(QuicInitialPacket)
#     packet.headerType = 0xff
#     packet.version = 0
#     packet.dcil = 1
#     packet.scil = 1
#     packet.dcid = @[1'u8,2,3,4]
#     packet.scid = @[5'u8,6,7,8]
#     packet.token = (varint: 151288809941952652'u64)
#     packet.length = 4'u16
#     packet.inner = (number: 0xb3'u64)

#     var ss = newStringStream()
#     QuicInitialPacket.put(ss, packet)
#     ss.setPosition 0
#     ss.setPosition(0)
#     var inData = QuicInitialPacket.get(ss)
