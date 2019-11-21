import os, binaryparse, streams,net
include parsers


proc main() = 
    let socket = newSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)

    var cryptoFrame: typeGetter(CryptoFrame)
    cryptoFrame.offSet = 1
    cryptoFrame.length = 10
    cryptoFrame.data = toSeq 1'u8..9'u8

    var initialPacket :typeGetter(QuicInitialPacket)
    initialPacket.headerType = 0b1100_0000
    initialPacket.version = 1
    initialPacket.dcil = 1
    initialPacket.scil = 1
    initialPacket.dcid = @[1'u8,2,3,4]
    initialPacket.scid = @[5'u8,6,7,8]
    initialPacket.token = (varint: 151288809941952652'u64)
    initialPacket.length = 4'u16
    initialPacket.inner = (number: 0xb3'u64)
    initialPacket.frame = (offSet: 1'u16, length:10'u16, data: toSeq 1'u8..9'u8)

    var ss = newStringStream()
    QuicInitialPacket.put(ss,initialPacket)
    ss.setPosition(0)
    var buff = ss.readAll()
    echo cast[seq[uint8]](buff)
    socket.sendTo("127.0.0.1", Port(5000), addr buff[0], buff.len)

main()