import nativesockets, os, binaryparse, streams
import utils

let sockfd = createNativeSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
defer: sockfd.close()

var peer = getAddrInfo("0.0.0.0", Port 1234, sockType = SOCK_DGRAM, protocol = IPPROTO_UDP)
if sockfd.bindAddr(peer.ai_addr, SockLen peer.ai_addrlen) < 0i32:
    freeAddrInfo(peer)
    raiseOSError(osLastError())

var readSupportedVersions = (get: (proc (s: Stream): tuple[supportedVersions: seq[uint32]] =
    result.supportedVersions = @[]
    while not s.atEnd:
      result.supportedVersions.add 0
      s.readDataLE(result.supportedVersions[^1].addr , 4)
    ),
    put: (proc (s: Stream, input: var tuple[supportedVersions: seq[uint32]]) =
     for supportedVersion in input.supportedVersions:
       s.write supportedVersion
   )
)

createParser(versionNegoPacket):
    u8: headerType 
    u32: version 
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersions[]

echo sizeof versionNegoPacket
const cap = 26
var buf : array[cap, byte]
var packet: string

while true:
    var bytes = recv(sockfd, addr buf , cap, 0)
    echo buf
    var packet = toStr buf
    echo cast[seq[byte]](packet)
    var ss = newStringStream(packet)
    try:
        var readData = versionNegoPacket.get(ss)
        echo readData
    except:
        var e = getCurrentException()
        echo getStackTrace(e)
        echo getCurrentExceptionMsg()