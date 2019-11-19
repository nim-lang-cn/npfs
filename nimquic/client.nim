import os, binaryparse, streams,net
include parsers


proc main() = 
    let socket = newSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)

    createParser(QuicVersionNegotiationPacket):
        u8: headerType 
        u32: version 
        u4: dcil 
        u4: scil
        u8: dcid[if dcil != 0: dcil+3 else: 0]
        u8: scid[if scil != 0: scil+3 else: 0]
        u32: supportedVersions[]

    var packet :typeGetter(QuicVersionNegotiationPacket)

    var ss = newStringStream()
    QuicVersionNegotiationPacket.put(ss,packet)
    var buff = ss.readAll()
    socket.sendTo("127.0.0.1", Port(5000), buff)

main()