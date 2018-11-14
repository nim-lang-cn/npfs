import binaryparse, streams


createParser(QuicVersionNegotiationPacket):
    u8: headerType = 0x80
    u32: version = 0x0
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersions[]
