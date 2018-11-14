import nativesockets, os, binaryparse, streams
include parsers

const cap = 30
var buf : array[cap, byte]
var packet: string

proc toStr*(a: openArray[byte]): string =
    result = newString len a
    for idx, val in a:
      result[idx] = char val

proc main() = 

    let sockfd = createNativeSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
    defer: sockfd.close()

    var peer = getAddrInfo("0.0.0.0", Port 1234, sockType = SOCK_DGRAM, protocol = IPPROTO_UDP)
    if sockfd.bindAddr(peer.ai_addr, SockLen peer.ai_addrlen) < 0i32:
        freeAddrInfo(peer)
        raiseOSError(osLastError())

    createParser(QuicVersionNegotiationPacket):
        u8: headerType 
        u32: version 
        u4: dcil 
        u4: scil
        u8: dcid[if dcil != 0: dcil+3 else: 0]
        u8: scid[if scil != 0: scil+3 else: 0]
        u32: supportedVersions[]

    while true:
        var bytes = recv(sockfd, addr buf , cap, 0)
        echo buf
        var packet = toStr buf
        var ss = newStringStream(packet)
        try:
            var readData = QuicVersionNegotiationPacket.get(ss)
            echo readData
        except:
            var e = getCurrentException()
            echo getStackTrace(e)
            echo getCurrentExceptionMsg()

main()