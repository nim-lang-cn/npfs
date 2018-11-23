import sequtils, strutils, endians
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

proc hkdfExpand*(prk, info: string, length: int): seq[uint8] =
    var prev: string
    if length > 255 * sha256.sizeDigest:
        echo "hkdf: requested too much output"
    
    result.setLen length
    for i in 1..length :
        prev = $sha256.hmac(prk, cast[string](prev) & info & $i)
        copyMem(addr result[0], addr prev[0], prev.len)

proc hkdfExpandLabel*(secret: string, label: string, length: int): seq[byte] =
    const prefix = "quic "
    var qlabel = @[0'u8, 0]
    var n = uint16 length
    bigEndian16(addr qlabel[0], addr n)
    qlabel[2] = uint8 prefix.len + label.len
    
    qlabel.add (cast[seq[uint8]](prefix & label))
    result = hkdfExpand(secret, cast[string](qlabel), length)

proc hkdfExtract*(key: string, data: string): string =
    result = $sha256.hmac(key, data)


when isMainModule:
    echo hkdfExtract(cast[string](quicVersion1Salt), "a")