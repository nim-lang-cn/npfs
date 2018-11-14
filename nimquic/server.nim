import nativesockets, os, binaryparse, streams

let sockfd = createNativeSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
var peer = getAddrInfo("192.168.100.224", Port 1234, sockType = SOCK_DGRAM, protocol = IPPROTO_UDP)
if sockfd.bindAddr(peer.ai_addr, SockLen peer.ai_addrlen) < 0i32:
    freeAddrInfo(peer)
    raiseOSError(osLastError())

createParser(versionNegoPacket):
    u8: headerType 
    u32: version 
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersion[]

var buf: array[15, byte]

while true:
    var bytes = recv(sockfd, addr buf , cint sizeof buf, 0)
    echo buf
    var content = cast[cstring](addr buf[0])
    var ss = newStringStream( $content)
    var readData = versionNegoPacket.get(ss)
    echo readData