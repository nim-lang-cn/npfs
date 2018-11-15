import tables, strformat, binaryparse, streams, net
include parsers, quic_data_writer

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

proc GetVarInt62Len*(value: uint64):int =
  if (value and kVarInt62ErrorMask) != 0:
    echo fmt"Attempted to encode a value, {value}, that is too big for VarInt62"
    result = 0
  if (value and kVarInt62Mask8Bytes) != 0:
    result = 8
  if (value and kVarInt62Mask4Bytes) != 0:
    result = 4
  if (value and kVarInt62Mask2Bytes) != 0:
    result = 2
  result = 1

proc WriteVarInt62*(value: uint64): bool = 
    result = true

when isMainModule:
    import nativesockets, os
    var outData: typeGetter(QuicVersionNegotiationPacket)
    outData.headerType = 0x80
    outData.version = 0
    outData.dcil = 1
    outData.scil = 1
    outData.dcid = @[1u8,2,3,4]
    outData.scid = @[5u8,6,7,8]
    outData.supportedVersions =  @[10'u32, 100, 42_000]
    var ss = newStringStream()
    QuicVersionNegotiationPacket.put(ss, outData)   
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