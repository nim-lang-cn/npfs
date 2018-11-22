import sequtils, strutils, endians
import nimcrypto 

var quicVersion1Salt* = @[0x9c'u8, 0x10, 0x8f, 0x98, 0x52, 
                          0x0a, 0x5c, 0x5c, 0x32, 0x96,
                          0x8e, 0x95, 0x0e, 0x8a, 0x2c, 
                          0x5f, 0xe0, 0x6d, 0x6c, 0x38]

proc hkdfExpand*(prk, info: string, l: int): seq[byte] =
    var 
        expander = sha256.hmac(prk, info)
        res: seq[byte]
        counter  = byte(1)
        prev: seq[byte]
    var p = res
    if l > 255 * 32:
        echo "hkdf: requested too much output"
    # while len(p) > 0 :
    #     expander.Reset()
    #     expander.Write(prev)
    #     expander.Write(info)
    #     expander.Write([]byte{counter})
    #     prev = expander.Sum(prev[:0])
    #     counter++
    #     n := copy(p, prev)
    #     p = p[n:]
    result = res

proc hkdfExpandLabel*(secret: string, label: string, length: int): seq[byte] =
    const prefix = "quic "
    var qlabel: string
    var n = length
    bigEndian16(addr qlabel[0], addr n)
    bigEndian16(addr qlabel[1], addr n)
    qlabel[2] = char prefix.len + label.len
    qlabel.add prefix & label
    result = hkdfExpand(secret, qlabel, length)

proc hkdfExtract*(key: string, data: string): string =
    result = $sha256.hmac(key, data)


when isMainModule:
    echo hkdfExtract(cast[string](quicVersion1Salt), "a")