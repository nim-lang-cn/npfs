import binaryparse, streams, math
# import packet_number

createParser(QuicVersionNegotiationPacket):
    u8: headerType = 0x80
    u32: version = 0x0
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersions[]

var packetNumber* = (get: (proc (s: Stream): tuple[number: seq[uint8]] =
    result.number = @[]
    var firstOctet = 0
    s.readDataLE(firstOctet.addr , 1)
    var encodedLength : uint8= 0
    var firstBit = uint8 firstOctet shr 7
    if firstBit == 0 :
        encodedLength = 1
        result.number.add 0
        s.readDataLE(result.number.addr , 1)
    else:
        var pattern = firstOctet shr 6 and 0x3
        if pattern == 2 :
            encodedLength = 2
            for i in 0'u8..<encodedLength:
                result.number.add 0
                s.readDataLE(result.number.addr, 1)
        elif pattern == 3:
            encodedLength = 4
            for i in 0'u8..<encodedLength:
                result.number.add 0
                s.readDataLE(result.number.addr, 1)
    
    ),
    put: (proc (s: Stream, input: var tuple[number: uint32]) =
        var firstOctet :uint8= 0
        var encodedNumber : seq[uint8]
        if input.number in 0'u32..127'u32:
            s.write input.number shr 25
        elif input.number in 128'u32..16383'u32 :
            s.write input.number shr 18
        elif input.number in 16384'u32..1073741823'u32 :
            s.write input.number 
        else: discard

    )
)

createParser(QuicInitialPacket):
    u8: headerType = 0xff
    u32: version
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u2: tokenLength
    u1: token[if tokenLength != 0: tokenLength*8 - 2 else: 0]
    u16: length
    *packetNumber: inner
    u32: payload[]

createParser(QuicRetryPacket):
    u8: headerType = 0xfe
    u32: version
    u4: dcil
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u8: odcil
    u8: odci[odcil]
    u32: retryToken

createParser(QuicHandshakePacket):
    u8: headerType = 0xfd
    u32: version
    u4: dcil
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    *packetNumber: number


when isMainModule:
    var packet :typeGetter(QuicInitialPacket)
    packet.headerType = 0xff
    packet.version = 0
    packet.dcil = 1
    packet.scil = 1
    packet.dcid = @[1'u8,2,3,4]
    packet.scid = @[5'u8,6,7,8]
    packet.tokenLength = 1
    packet.token = @[1'u8]
    packet.length = 1
    packet.inner = 0
    packet.number = @[9'u8, '\xb3'.uint8]

    var ss = newStringStream()
    QuicInitialPacket.put(ss, packet)
    ss.setPosition 0
    echo cast[seq[byte]](ss.readAll())
    ss.setPosition(0)
    var inData = QuicInitialPacket.get(ss)
    echo inData.number