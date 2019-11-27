import endians, math, strformat
import nimcrypto 
import sequtils

# var initialSalt* = 0xc3eef712c72ebb5a11a7d2432bb46365bef9f502
var initialSalt* = @[0xc3'u8, 0xee, 0xf7, 0x12, 0xc7, 0x2e, 0xbb, 0x5a, 0x11, 0xa7, 0xd2, 0x43, 0x2b, 0xb4, 0x63, 0x65, 0xbe, 0xf9, 0xf5, 0x02]
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
    for i in 1'u8..ceil:
        var t = HashType.hmac(prk, result.concat(info, @[i]))
        result.add t.data
    if result.len > length:
        result = result[0..length-1]


proc hkdfExpandLabel*(HashType: typedesc, secret: openArray[uint8], 
                      label: string, length: int): seq[uint8] =
    const prefix = "tls13 "
    var qlabel = newSeq[uint8](2 + 1 + prefix.len + label.len + 1)
    var n = uint16 length
    bigEndian16(addr qlabel[0], addr n)
    qlabel[2] = uint8 prefix.len + label.len
    var concatenate = prefix & label
    for i,c in concatenate:
        qlabel[3+i] = c.uint8
    result = hkdfExpand(HashType, secret, qlabel, length)

proc hkdfExtract*(HashType: typedesc, salt: string, secret: string): MDigest[HashType.bits] =
    HashType.hmac(salt, secret)


