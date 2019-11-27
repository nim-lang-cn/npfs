import os, binaryparse, streams,net
include parsers, aead_aesgcm


proc main() = 
    var cryptoFrame: typeGetter(CryptoFrame)
    cryptoFrame.offSet = 1
    cryptoFrame.length = 10
    cryptoFrame.data = toSeq 1'u8..9'u8

    var initialPacket: typeGetter(QuicInitialPacket)
    initialPacket.headerType = 0b1100_0000
    initialPacket.version = 1
    initialPacket.dcil = 1
    initialPacket.scil = 1
    initialPacket.dcid = @[1'u8,2,3,4]
    initialPacket.scid = @[5'u8,6,7,8]
    initialPacket.token = (varint: 151288809941952652'u64)
    initialPacket.length = 4'u16
    initialPacket.inner = (number: 0xb3'u64)
    initialPacket.frame = (offSet: 1'u16, length:10'u16, data: toSeq 1'u8..9'u8)

    var ss = newStringStream()
    QuicInitialPacket.put(ss,initialPacket)
    ss.setPosition(0)
    var buff = ss.readAll()
    var packet = cast[seq[byte]](buff)

    var sampleOffset = 1 + connId.len + 4
    echo sampleOffset

    var sample = packet[sampleOffset..sampleOffset+15]
    echo sample.len

    var connId = @[0x83'u8, 0x94, 0xc8, 0xf0, 0x3e, 0x51, 0x57, 0x08]
    var connStr = cast[string](connId)
    var (clientSecret, serverSecret) = computeSecrets(sha256, connStr)

    var clientHp: seq[byte]
    var clientAead = sha256.newAEAD(aes128, connStr, PerspectiveClient, clientHp)
    
    var ectx, dctx: ECB[aes128]
    var key: array[aes128.sizeKey, byte]
    var plainText: array[aes128.sizeBlock * 2, byte]
    var mask: array[aes128.sizeBlock * 2, byte]

    ectx.init(clientHp)
    ectx.encrypt(addr plainText[0], addr mask[0], sample.len.uint)
    ectx.clear()

    var pnLen:uint64 = packet[0].byte and 0x30 + 1
    if (packet[0].int and 0x80) == 0x80:
        packet[0] = packet[0] xor byte(mask[0] and 0x0f)
    else:
        packet[0] = packet[0] xor byte(mask[0] and 0x1f)
    
    ss.setPosition(8)
    var pnOffSet = 8 +  variableLengthEncoding.get(ss).varint + 2
    for i in 0..pnLen:
        packet[pnOffSet + i] = packet[pnOffSet + i] xor mask[1+i]


    var crypto = clientAead.seal($sample, $packet)

    let socket = newSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
    socket.sendTo("127.0.0.1", Port(5000), addr crypto[0], crypto.len)

main()

