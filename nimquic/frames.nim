import tables, strformat, binaryparse, streams, net

const framesType = {"0x00":"PADDING",
                    "0x01":"RST_STREAM",
                    "0x02":"CONNECTION_CLOSE",
                    "0x03":"APPLICATION_CLOSE",
                    "0x04":"MAX_DATA",
                    "0x05":"MAX_STREAM_DATA",
                    "0x06":"MAX_STREAM_ID",
                    "0x07":"PING",
                    "0x08":"BLOCKED",
                    "0x09":"STREAM_BLOCKED",
                    "0x0a":"STREAM_ID_BLOCKED",
                    "0x0b":"NEW_CONNECTION_ID",
                    "0x0c":"STOP_SENDING",
                    "0x0d":"RETIRE_CONNECTION_ID",
                    "0x0e":"PATH_CHALLENGE",
                    "0x0f":"PATH_RESPONSE",
                    "0x10":"STREAM",
                    "0x18":"CYPTO",
                    "0x19":"NEW_TOKEN",
                    "0x1a":"ACK",
                    "0x1b":"ACK"}.toTable


proc variableLengthEncoding*(): byte = 
    var length: uint64
    if length in 0u64..63u64:
        result = 0x00
    elif length in 64u64..16383u64:
        result = 0x01
    elif length in 16384u64..1073741823u64:
        result = 0x10
    elif length in 1073741824u64..4611686018427387903u64:
        result = 0x11

createParser(initialPacket):
    u8: headerType = 0x80
    u32: version
    u4: dcil
    u4: scil

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
    u8: headerType = 0x80
    u32: version = 0x0
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersions[]


when isMainModule:
    import nativesockets, os
    var outData: typeGetter(versionNegoPacket)
    outData.headerType = 0x80
    outData.version = 0
    outData.dcil = 1
    outData.scil = 1
    outData.dcid = @[1u8,2,3,4]
    outData.scid = @[5u8,6,7,8]
    outData.supportedVersions =  @[10'u32, 100, 42_000]
    var ss = newStringStream()
    versionNegoPacket.put(ss, outData)   
    var size = ss.getPosition()
    echo outData
    ss.setPosition(0)
    var outs = ss.readAll().cstring
    let sockfd = createNativeSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
    defer: sockfd.close()
    sockfd.setSockOptInt(SOL_SOCKET, SO_BROADCAST, 1)
    var peer = getAddrInfo("192.168.100.224", Port 1234, sockType = SOCK_DGRAM, protocol = IPPROTO_UDP)
    if sockfd.connect(peer.ai_addr, peer.ai_addrlen.SockLen) < 0'i32:
        freeAddrInfo(peer)
        raiseOSError(osLastError())
    var sent = sockfd.send(outs, cint size, 0) 
    if sent < 0'i32:
        raiseOSError(osLastError())
    else: 
        echo sent