import net, os, binaryparse, streams
include parsers

const cap = 1500

proc toStr*(a: openArray[byte]): string =
    result = newString a.len
    for idx, val in a:
      result[idx] = char val

proc main() = 

    let socket = newSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
    defer: socket.close()

    socket.bindAddr(Port(5000), "0.0.0.0")
    while true:
        var
            address: string
            buf: string
            port: Port
        var bytes = socket.recvFrom(buf, cap, address, port)
        var ss = newStringStream(buf)
        try:
            var readData = QuicInitialPacket.get(ss)
            echo "readData:" & $readData
        except:
            var e = getCurrentException()
            echo getStackTrace(e)
            echo getCurrentExceptionMsg()

main()