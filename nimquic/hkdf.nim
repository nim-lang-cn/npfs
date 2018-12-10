import sequtils, strutils, endians, math, strformat
import nimcrypto 

var quicVersion1Salt* = @[0x9c'u8, 0x10, 0x8f, 0x98, 0x52, 
                          0x0a, 0x5c, 0x5c, 0x32, 0x96,
                          0x8e, 0x95, 0x0e, 0x8a, 0x2c, 
                          0x5f, 0xe0, 0x6d, 0x6c, 0x38]

# https://tools.ietf.org/html/rfc5869
proc hkdfExpand*(HashType: typedesc, prk:openArray[uint8], 
                info: seq[uint8], length: int): seq[uint8] =
    # var prev: string
    if length > 255 * HashType.sizeDigest:
        echo "hkdf: requested too much output"
    var expander: HMAC[HashType]
    defer: expander.clear()
    var ceil = ceil(length/HashType.sizeDigest).uint8
    expander.init(prk)
    for i in 1'u8..ceil:
        expander.update(result)
        expander.update(info)
        expander.update([i])
        var data = expander.finish().data
        result.add data
    if result.len > length:
        result = result[0..length]


proc hkdfExpandLabel*(HashType: typedesc, secret: openArray[uint8], 
                      label: string, length: int): seq[uint8] =
    const prefix = "quic "
    var qlabel = newSeq[uint8](2 + 1 + prefix.len + label.len + 1)
    var n = uint16 length
    bigEndian16(addr qlabel[0], addr n)
    qlabel[2] = uint8 prefix.len + label.len
    var concated = prefix & label
    for i,c in concated:
        qlabel[3+i] = uint8 c
    # echo qlabel
    result = hkdfExpand(HashType, secret, qlabel, length)

proc hkdfExtract*(HashType: typedesc, salt: string, secret: string): MDigest[HashType.bits] =
    HashType.hmac(salt, secret)


when isMainModule:
    var connId = @[0x83'u8, 0x94, 0xc8, 0xf0, 0x3e, 0x51, 0x57, 0x08]
    var salt = cast[string](quicVersion1Salt)
    var secret = cast[string](connId)

    let prefix = "quic "
    let serverLabel = "server in"
    var initialSecret = hkdfExtract(sha256, salt, secret)
    echo hkdfExpandLabel(sha256, initialSecret.data, serverLabel, sha256.sizeDigest).mapIt(it.toHex)
