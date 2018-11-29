import sequtils, strutils, endians, math, strformat
import nimcrypto 

var quicVersion1Salt* = @[0x9c'u8, 0x10, 0x8f, 0x98, 0x52, 
                          0x0a, 0x5c, 0x5c, 0x32, 0x96,
                          0x8e, 0x95, 0x0e, 0x8a, 0x2c, 
                          0x5f, 0xe0, 0x6d, 0x6c, 0x38]

# HKDF-Expand(PRK, info, L) -> OKM
# Options:
#     Hash     a hash function; HashLen denotes the length of the
#             hash function output in octets
# Inputs:
#     PRK      a pseudorandom key of at least HashLen octets
#              (usually, the output from the extract step)
#     info     optional context and application specific information
#              (can be a zero-length string)
#     L        length of output keying material in octets
#              (<= 255*HashLen)
#  Output:
#     OKM      output keying material (of L octets)
#  The output OKM is calculated as follows:
#  N = ceil(L/HashLen)
#  T = T(1) | T(2) | T(3) | ... | T(N)
#  OKM = first L octets of T
#  where:
#  T(0) = empty string (zero length)
#  T(1) = HMAC-Hash(PRK, T(0) | info | 0x01)
#  T(2) = HMAC-Hash(PRK, T(1) | info | 0x02)
#  T(3) = HMAC-Hash(PRK, T(2) | info | 0x03)
#  ...
#  (where the constant concatenated to the end of each T(n) is a single octet.)

proc hkdfExpand*(HashType: typedesc, prk:string, info: seq[uint8], length: int): string =
    var prev: seq[uint8]
    if length > 255 * HashType.sizeDigest:
        echo "hkdf: requested too much output"
    var expander: HMAC[HashType]
    defer: expander.clear()
    for i in 1'u8..ceil(length/HashType.sizeDigest).uint8:
        expander.init(prk)
        expander.update(prev)
        expander.update(info)
        expander.update([i])
        result &= $expander.finish()

proc hkdfExpandLabel*(HashType: typedesc, secret: string, label: string, length: int): string =
    const prefix = "quic "
    var qlabel = newSeq[uint8](2 + 1 + prefix.len + label.len + 1)
    var n = uint16 length
    bigEndian16(addr qlabel[0], addr n)
    qlabel[2] = uint8 prefix.len + label.len
    var concated = prefix & label
    for i,c in concated:
        qlabel[3+i] = uint8 c
    var qlabelStr = cast[string](qlabel)
    result = hkdfExpand(HashType, secret, qlabel, length)

proc hkdfExtract*(HashType: typedesc, salt: string, secret: string): string =
    $HashType.hmac(salt, secret)


when isMainModule:
    # import nimcrypto/pbkdf2
    var connId = @[0x83'u8, 0x94, 0xc8, 0xf0, 0x3e, 0x51, 0x57, 0x08]
    var salt = cast[string](quicVersion1Salt)
    var secret = cast[string](connId)
    const prefix = "quic "
    const label = "server in"
    var initialSecret = hkdfExtract(sha256, cast[string](quicVersion1Salt), cast[string](connId))
    # echo initialSecret
    
    #nim:1F7372897A5CD48E3B1E49BFFBD89A5E5B7F96A62B7290498380B27EA7903F1D
    #go: b087dcd7478dda8a858fbf3d605c888586c0a3a9875423ad4f114f0ba38e5a2e
    echo "serverSecret:" & hkdfExpandLabel(sha256, initialSecret, label, sha256.sizeDigest)

    # var ikm = 0x0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b 
    # var ikmSeq = 0x0b.repeat 22
    # echo ikmSeq
    # var ikmStr = cast[string](ikmSeq)
    # var salt1 = 0x000102030405060708090a0b0c
    # var saltSeq = @[0'u8,1,2, 3,4,5,6,7,8,9,0xa,0xb,0xc]
    # var saltStr = cast[string](saltSeq)
    # var info = 0xf0f1f2f3f4f5f6f7f8f9 
    # var infoSeq = @[0xf0'u8, 0xf1, 0xf2, 0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9] 
    # var infoStr = cast[string](infoSeq)
    # var prk = hkdfExtract(sha256, saltStr,ikmStr)
    # echo "prk:" & $prk.len
    # echo hkdfExpand(sha256, prk, infoStr, 42).len