import os, binaryparse, streams,net, strformat
include parsers, aead_aesgcm

proc main() = 
    var cryptoFrame: typeGetter(CryptoFrame)
    cryptoFrame.offSet = 1
    cryptoFrame.length = 10
    cryptoFrame.data = toSeq 1'u8..9'u8

    var initialPacket: typeGetter(QuicInitialPacket)
    initialPacket.header.headerType = 0b1100_0011
    initialPacket.header.version = 0xff000017'u32
    initialPacket.header.dcil = 0x0
    initialPacket.header.scil = 0x8
    initialPacket.header.dcid = @[0x83'u8, 0x94, 0xc8, 0xf0, 0x3e, 0x51, 0x57, 0x08]
    initialPacket.header.scid = @[0'u8]
    initialPacket.header.token = (varint: 0'u64)
    initialPacket.header.pnlength = 0x449e #449e 包号长度额外变长编码？
    initialPacket.header.pn = (number: 0x2'u64)
    initialPacket.frame = (offSet: 1'u16, length:10'u16, data: toSeq 1'u8..9'u8)

    var headerStream = newStringStream()
    LongHeader.put(headerStream,initialPacket.header)
    headerStream.setPosition(0)
    var header = headerStream.readAll()
    var headerPayload = cast[seq[byte]](header)
    echo "header:" & headerPayload.toHex
    # c3ff000017088394c8f03e515708 0000 449e 00000002
    # C3FF000017088394C8F03E515708 0000 449E 00000002

    # var frameStream = newStringStream()
    # CryptoFrame.put(frameStream,initialPacket.frame)
    # frameStream.setPosition(0)
    # var frame = frameStream.readAll()


    var connId = @[0x83'u8, 0x94, 0xc8, 0xf0, 0x3e, 0x51, 0x57, 0x08]
    var connStr = cast[string](connId)

    var (clientSecret, serverSecret) = sha256.computeSecrets(connStr)
    
    var (clientKey, clientIV, clientHp) = sha256.computeAEADKeyAndIV(clientSecret)
    var (serverKey, serverIV, serverHp) = sha256.computeAEADKeyAndIV(serverSecret)

    # echo clientKey.toHex
    # echo clientIV.toHex
    # echo clientHp.toHex
    # echo serverKey.toHex
    # echo serverIV.toHex
    # echo serverHp.toHex
    # var serverIVU64 =cast[uint64](serverIV)
    var clientIVU64 = cast[uint64](clientIV)
    var nonce = cast[seq[uint8]](initialPacket.header.pn.number xor clientIVU64)
    echo &"{initialPacket.header.pn.number:064b}"
    echo &"{clientIVU64:064b}"
    echo cast[uint64](nonce).int.toBin 64


    var cryptoAndPaddingPayload = @[0x06'u8,0x00,0x40,0xc4,0x01,0x00,0x00,0xc0,0x03,0x03,0x66,0x60,0x26,0x1f,0xf9,0x47,0xce,0xa4,0x9c,0xce,0x6c,0xfa,0xd6,0x87,0xf4,0x57,0xcf,0x1b,0x14,0x53,0x1b,0xa1,
                                    0x41,0x31,0xa0,0xe8,0xf3,0x09,0xa1,0xd0,0xb9,0xc4,0x00,0x00,0x06,0x13,0x01,0x13,0x03,0x13,0x02,0x01,0x00,0x00,0x91,0x00,0x00,0x00,0x0b,0x00,0x09,0x00,0x00,0x06,
                                    0x73,0x65,0x72,0x76,0x65,0x72,0xff,0x01,0x00,0x01,0x00,0x00,0x0a,0x00,0x14,0x00,0x12,0x00,0x1d,0x00,0x17,0x00,0x18,0x00,0x19,0x01,0x00,0x01,0x01,0x01,0x02,0x01,
                                    0x03,0x01,0x04,0x00,0x23,0x00,0x00,0x00,0x33,0x00,0x26,0x00,0x24,0x00,0x1d,0x00,0x20,0x4c,0xfd,0xfc,0xd1,0x78,0xb7,0x84,0xbf,0x32,0x8c,0xae,0x79,0x3b,0x13,0x6f,
                                    0x2a,0xed,0xce,0x00,0x5f,0xf1,0x83,0xd7,0xbb,0x14,0x95,0x20,0x72,0x36,0x64,0x70,0x37,0x00,0x2b,0x00,0x03,0x02,0x03,0x04,0x00,0x0d,0x00,0x20,0x00,0x1e,0x04,0x03,
                                    0x05,0x03,0x06,0x03,0x02,0x03,0x08,0x04,0x08,0x05,0x08,0x06,0x04,0x01,0x05,0x01,0x06,0x01,0x02,0x01,0x04,0x02,0x05,0x02,0x06,0x02,0x02,0x02,0x00,0x2d,0x00,0x02,
                                    0x01,0x01,0x00,0x1c,0x00,0x02,0x40,0x01]
    var padding = repeat(0'u8, 1162 - cryptoAndPaddingPayload.len)
    cryptoAndPaddingPayload = concat(cryptoAndPaddingPayload, padding)

    var packet = authenticatedEncryption(clientKey, clientIV, cryptoAndPaddingPayload, headerPayload)
    echo packet.toHex
    # 8CED78F5171F760C7FE1A6F903BA1F9DB98E832B0C4A692BB751B1F6AE2F226021B2879E021BB2B8E2C01C1CEB15356DA884F8FA6B792F06F8D41763C62D238661B18E99168BBDBADC800162021FCCA23E28354B81637A8C59C159A12C6CDDB93C2EA37FC339B6148D4AD45926B61DDD24AC59B60ABE163B739A5DE2ABF408FD3B6736A29EA3D63D6D0F28D72A4376DB9EB026CE0869DD73D7808D15B29CA3ED5CF86580C2D5CA307EB2D8CE015BD55E34C86BA93754049153A3DF2BFE81B5D108093CEE32F6173073BA6026E8C8A7B1E979391DD6121431BB4550978DB289F9EBE600DB8A05E44D77FB8E78495F8EB9ECB53EEB1D01F457A0C0241879873CA50BCB88E7CEBECE27AD0321541F453A256379E467C46B5E6D5F679CFD2DA6BDA836FFF45BA74B185E3B82F60D716BCFA39A29621EDB67D8AB19694BBB2A31891AE2322B55DE32A3EBB23215761F04EFB627D7DF5D9A10A46977EBF115C9270594B828AFAE026A2579159AC1E78318E61FBD96EBF8493D4694C442B333BD6AF2E0E0D53C84E8F4E684B2AB755F98F82813C6771D794E41459CDC438E12E9D1DE60949131BF797C01F82E89B4DBDF332F089DACC104019F2A2DB450D52E28726426709E4C11C89EF7A1864ABB661DF7DDC9A5E204567A4DB6B955B92029E760C4FBF23E13F6285D64BE6EEBC38546698BA517C4929609ECB564E99930DA611CCFAE86028A0227368EE02A4DF14FC28896C16D901E4C78809E9B24E336A4DF1E6249AC99400D860C4341C1B9F39564F7E6727CAA69392E2D356CBBB4604DD3D9431EF95D15E713F03861CF3BB59EF5574048337B92C3002857B2371C689DDE9259E6C18E2E510C84BCBDF047C08A1E0DD567A7DF22E0C90126DF681B44816C43BB8EA7FAEE6B9E205AAC29B0331C7611403ACEAA6A9927F336C12263A852E16B3768B9BF7207AF57859AE9C3C84BEA0C4E289354F9DA0ECB62335A1465BFDCF9F9456EC753E4B2EF5065C0A2EA0669E6EFABC109C1FC3EC238C80245FE07042F1F54AC55960FEA5CDE8DD57863C6BC79C0D1D6024C7D25A8FEC22B653B599E6E667ED3930E7CE2BAC5894653348B634F8FF23327947323131527E6DF253E53A46F118E3770173515E7248B86A32C873A8EC4E3694FD69D5CFE6D65DD52E11198F32FB2DBF23CADBB1DA95A37AD7DAD15D50F2973126D06FAB02B6C2A6C556EAF9D39B9FEC3AE61A40D0E6C29E452F6D7375083F782035CB865B34075EA0B5E27FC0C72458F8CB523FC1F7728D1FF04C9A6E35D41A82FD47FFB801D723E64840AA88F517C6816A3365F8D40D9EACA05F1A6AB24C3840C59F33D7032D6EB2476ADC936E67D2E00B34DE42C4E740B43CA7B7D056EAFAB1D3BF9EB4DCD4C2C8CBD01ED491714ECA9E066C75E1DC467D2054518E492C7C121523832E6CAA04CF2E127C09AA7D47E5DDE706EF9F5D11D34E1988E78C4DF96DFD07956C8E39FE93CA8AF208BE670A1EDE4E23CD8CC32650F69B571A0072D77AF57909008D3369F20D68AA8351E5CF0D9CE08EDD5CE81A7EECABF53F57CB5E264AD93F70E95C6CA57FEBAA64AB1C6F0D04FB0BC5CA3EA527F51980A913EF7C60900B65AD81176CA4575E0ECD459E63D2C9FFDA2642401
    # Protecting the payload produces output that is sampled for header protection. How?
    # TODO 得到如下的包加密后的前16字节结果
    # 头保护采样从包加密结果的密文中取前16个字节，应当如下
    # var sample = @[0x53'u8,0x50,0x64,0xa4,0x26,0x8a,0x0d,0x9d,0x7b,0x1c,0x9d,0x25,0x0a,0xe3,0x55,0x16]
    # 535064a4268a0d9d7b1c9d250ae35516

    # short header
    # var sampleOffset = 1 + connId.len + 4
    # long header
    var tokenLength = cast[seq[uint8]](initialPacket.header.token.varint).len
    var sampleOffset = 7 + initialPacket.header.dcid.len + initialPacket.header.scid.len + 4 + tokenLength
    echo sampleOffset

    var sample = packet[sampleOffset..sampleOffset+15]
    var sample1 = @[0x53'u8,0x50,0x64,0xa4,0x26,0x8a,0x0d,0x9d,0x7b,0x1c,0x9d,0x25,0x0a,0xe3,0x55,0x16]
    assert sample == sample1, sample.toHex

    
    var mask: array[aes128.sizeBlock * 2, byte]

    # This section defines the packet protection algorithm for
    # AEAD_AES_128_GCM, AEAD_AES_128_CCM, and AEAD_AES_256_GCM.
    # AEAD_AES_128_GCM and AEAD_AES_128_CCM use 128-bit AES [AES] in
    # electronic code-book (ECB) mode. AEAD_AES_256_GCM uses 256-bit AES
    # in ECB mode.

    var ectx: ECB[aes128]

    ectx.init(clientHp)
    ectx.encrypt(sample, mask)
    ectx.clear()

    # 833b343aaa
    echo "mask:" & mask[0..4].toHex

    var pnLen:uint64 = packet[0].byte and 0x30 + 1
    if (packet[0].int and 0x80) == 0x80:
        packet[0] = packet[0] xor byte(mask[0] and 0x0f)
    else:
        packet[0] = packet[0] xor byte(mask[0] and 0x1f)
    
    # ss.setPosition(8)
    # var pnOffSet = 8 +  variableLengthEncoding.get(ss).varint + 2
    # for i in 0..pnLen:
    #     packet[pnOffSet + i] = packet[pnOffSet + i] xor mask[1+i]



    let socket = newSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
    socket.sendTo("127.0.0.1", Port(5000), addr packet[0], packet.len)

main()

