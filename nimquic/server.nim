import net, os, binaryparse, streams
include parsers

const cap = 1500
var buf : array[cap, byte]

proc toStr*(a: openArray[byte]): string =
    result = newString a.len
    for idx, val in a:
      result[idx] = char val

proc main() = 

    let socket = newSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
    defer: socket.close()

    socket.bindAddr(Port(5000), "0.0.0.0")

    createParser(QuicInitialPacket):
        u8: headerType = 0b11000000
        u32: version
        u4: dcil 
        u4: scil
        u8: dcid[if dcil != 0: dcil+3 else: 0]
        u8: scid[if scil != 0: scil+3 else: 0]
        *variableLengthEncoding: token
        u16: length
        *packetNumber: inner
        *cryptoFrame : frame

    while true:
        var bytes = socket.recv(addr buf, cap)
        var packet = toStr buf
        var ss = newStringStream(packet)
        try:
            var readData = QuicInitialPacket.get(ss)
            echo "readData:" & $readData
        except:
            var e = getCurrentException()
            echo getStackTrace(e)
            echo getCurrentExceptionMsg()

main()