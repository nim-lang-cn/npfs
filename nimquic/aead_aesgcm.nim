import nimcrypto
import hkdf
import endians, sequtils

const 
    PerspectiveServer = 1
    PerspectiveClient = 2
    gcmStandardNonceSize* = 12
    gcmBlockSize* = 16

type AeadAESGCM*[T] = object
    otherIV:   seq[uint8]
    myIV:      seq[uint8]
    encrypter: GCM[T]
    decrypter: GCM[T]

proc computeSecrets*(HashType: typedesc ,connID: string): tuple[clientSecret, serverSecret: string] =
    var initialSecret = hkdfExtract(HashType, cast[string](quicVersion1Salt), connID)
    result.clientSecret = hkdfExpandLabel(HashType,initialSecret, "client in", sha256.sizeDigest)
    result.serverSecret = hkdfExpandLabel(HashType,initialSecret, "server in", sha256.sizeDigest)

proc computeAEADKeyAndIV*(HashType: typedesc,secret: string): tuple[key,iv: string] = 
    result.key = hkdfExpandLabel(HashType,secret, "key", 16)
    result.iv = hkdfExpandLabel(HashType,secret, "iv", 12)

proc newAEAD*(HashType: typedesc ,connectionId: string, pers: int): AeadAESGCM =  
    var (clientSecret, serverSecret) = computeSecrets(HashType, connectionId)
    var mySecret, otherSecret: string
    if pers == PerspectiveClient:
        mySecret = clientSecret
        otherSecret = serverSecret
    else:
        mySecret = serverSecret
        otherSecret = clientSecret
    var (myKey, myIV) = computeAEADKeyAndIV(HashType,mySecret)
    var (otherKey, otherIV) = computeAEADKeyAndIV(HashType,otherSecret)
    var ectx, dctx: GCM[aes128]
    result = AeadAESGCM[aes128](otherIV, myIV, ectx, dctx)

proc makeNonce*(iv: seq[uint8], packetNumber: uint64): seq[uint8] =
    result.setLen iv.len
    bigEndian64(unsafeAddr result[4], unsafeAddr packetNumber)
    for i in 0..<iv.len:
        result[i] = result[i] xor iv[i]

proc seal*(aead: AeadAESGCM, dst: string, nonce: string, plaintext: string, data: string): seq[uint8] =
    if nonce.len != 12:
        echo "crypto/cipher: incorrect nonce length given to GCM"
    if plaintext.len > (1 shl 32 - 2)*16:
        echo "crypto/cipher: message too large for GCM"
    var counter, tagMask, tagOut: array[gcmTagSize, uint8]
    if nonce.len == gcmStandardNonceSize :
        copyMem(addr counter[0] , addr nonce[0], nonce.len)
        counter[gcmBlockSize - 1] = 1
    # else:
        #ghash(nonce)
    # var etag: array[aes128.sizeBlock, uint8]
    # var plainText = newSeq[byte](len(iv))
    # var encText = newSeq[byte](len(key))
    # var decText = newSeq[byte](len(key))
    # var aadText = newSeq[byte](len(key)) 
    # aead.encrypter.init(key, iv, aad)
    # aead.encrypter.encrypt(key, iv, aad)
    # aead.encrypter.getTag(etag)
    # aead.encrypter.clear()


proc open*(aead: AeadAESGCM, key: string, iv: string, aad: string): seq[uint8] =
    var dtag: array[aes128.sizeBlock, uint8] 
    aead.decrypter.init(key, iv, aad)
    aead.decrypter.dencrypt(key, iv, aad)
    aead.decrypter.getTag(dtag)
    aead.decrypter.clear()

when isMainModule:
    import strutils, strformat
    var connId = @[0x83'u8, 0x94, 0xc8, 0xf0, 0x3e, 0x51, 0x57, 0x08]
    var connStr = cast[string](connId)
    var (clientSecret, serverSecret) = computeSecrets(sha256, connStr)
    echo clientSecret.len
    echo serverSecret.len
    echo cast[seq[uint8]](clientSecret)
    echo cast[seq[uint8]](serverSecret)

    #var clientSecret = [159 83 100 87 243 42 30 10 232 100 188 179 202 241 35 81 16 99 14 29 31 179 56 53 189 5 65 112 249 155 247 220]
    #var severSecret = [176 135 220 215 71 141 218 138 133 143 191 61 96 92 136 133 134 192 163 169 135 84 35 173 79 17 79 11 163 142 90 46]