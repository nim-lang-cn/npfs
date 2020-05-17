include transport_parameters, aead_aesgcm
import binaryparse
import streams


type cryptoSetup* = ref object
    tlsConf: Config
    messageChan: Channel[seq[uint8]]
    readEncLevel: int
    writeEncLevel: int
    handshakeErrChan: Channel[string]
    messageErrChan: Channel[string]
    hankShakeDone: Channel[string]
    receivedTransportParams: Channel[typeGetter TransportParameters]
    closeChan: Channel[string]
    clientHelloWritten: bool
    clientHelloWrittenChan: Channel[string]
    initialStream: Stream
    initialAEAD: AeadAESGCM[aes128]
    handeshakeStream: Stream
    handshakeOpener: AeadAESGCM[aes128]
    handshakeSealer: AeadAESGCM[aes128]
    opener: AeadAESGCM[aes128]
    sealer: AeadAESGCM[aes128]
    receiveWriteKey: Channel[string]
    receivedReadKey: Channel[string]
    logger: int
    perspective: int

proc handleParamsCallback*(c: cryptoSetup, p: typeGetter TransportParameters) = 
    discard

proc newCryptoSetup*(): cryptoSetup = 
    discard open(result.receiveWriteKey)
    open(result.messageChan)


