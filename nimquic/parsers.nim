import binaryparse, streams
import packet_number

createParser(QuicVersionNegotiationPacket):
    u8: headerType = 0x80
    u32: version = 0x0
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersions[]


createParser(QuicInitialPacket):
    u8: headerType = 0xff
    u32: version
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u2: tokenLength
    u8: token[tokenLength]
    u2: length
    *inferPacketNumber: packetNumber
    u8: payload[]

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
    *inferPacketNumber: packetNumber