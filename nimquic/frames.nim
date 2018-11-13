import tables, strformat, binaryparse, streams

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

createParser(longHeader):
    u1: headerType = 1

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

createParser(versionNegoPacket):
    u1: headerType = 0x80
    u32: version = 0x0
    u4: dcil 
    u4: scil
    u8: dcid[if dcil != 0: dcil+3 else: 0]
    u8: scid[if scil != 0: scil+3 else: 0]
    u32: supportedVersion[]


createParser(initialPacket):
    u1: headerType = 1
    u7: initialPacket = 0x7f
    u32: version
    u4: dcil
    u4: scil

when isMainModule:
    import nativesockets, os
    var outData: typeGetter(versionNegoPacket)
    outData.headerType = 0x80
    outData.version = 0
    outData.dcil = 1
    outData.scil = 1
    outData.dcid = @[15u8]
    outData.scid = @[15u8]
    echo outData
    var outs = newStringStream()
    versionNegoPacket.put(outs, outData)   
    outs.setPosition(0)
    var frame = cast[seq[byte]](outs.readAll())
    echo frame
    let sockfd = createNativeSocket(nativesockets.AF_INET, nativesockets.SOCK_DGRAM, Protocol.IPPROTO_UDP)
    var peer = getAddrInfo("192.168.100.9", Port 80, sockType = SOCK_DGRAM, protocol = IPPROTO_UDP)
    echo sockfd.sendto(addr frame, sizeof(frame).cint, 0.cint, peer.ai_addr, SockLen sizeof(peer.ai_addrlen))
    var error : OSErrorCode = osLastError()
    if error != 0.OSErrorCode  : echo osErrorMsg error