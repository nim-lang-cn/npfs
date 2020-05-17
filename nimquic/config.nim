import quictime, constants, quictime, errorcodes, tables

type QuicFixedTagVector = ref object
    sendValues: seq[uint32]
    hasSendValues: bool
    receive_values: seq[uint32]
    has_receive_values: bool

type QuicNegotiableUint32* = ref object

type QuicFixedUint32* = ref object 


type QuicConfig* = ref object
    maxTimeBeforeCryptoHandshake: Delta
    maxIdleTimeBeforeCryptoHandshake: Delta
    maxUndecryptablePackets: uint
    connectionOptions: QuicFixedTagVector
    clientConnectionOptions: QuicFixedTagVector
    idleNetworkTimeoutSeconds: QuicNegotiableUint32
    silentClose: QuicNegotiableUint32
    maxIncomingDynamicStreams: QuicFixedUint32
    bytesForConnectionId: QuicFixedUint32
    initialRoundTripTimeus: QuicFixedUint32
    initialStreamFlowControlWindowBytes: QuicFixedUint32
    initialSessionFlowControlWindowBytes: QuicFixedUint32
    connectionMigrationDisabled: QuicFixedUint32
    alternateServerAddress: QuicFixedSocketAddress
    supportMaxHeaderListSize : QuicFixedUint32
    statelessResetToken : QuicFixedUint128
    createSessionTagIndicators : seq[uint32]

type QuicSocketAddress* = ref object

proc setInitialRoundTripTimeUsToSend(rtt_us : uint32) = initialRoundTripTimeus.setSendValue(rtt)

proc hasReceivedInitialRoundTripTimeUs(): bool = initialRoundTripTimeus.hasReceivedValue()

proc receivedInitialRoundTripTimeUs():int32 = initialRoundTripTimeus.getReceivedValue()

proc hasInitialRoundTripTimeUsToSend(): bool = initialRoundTripTimeus.hasSendValue()

proc getInitialRoundTripTimeUsToSend(): uint32 = initialRoundTripTimeus.getSendValue()

proc setInitialStreamFlowControlWindowToSend(windowBytes: uint32) = 
    if windowsBytes < kMinimumFlowControlSendWindow:
        windowsBytes = kMinimumFlowControlSendWindow
    initialStreamFlowControlWindowBytes.setSendValue(windowBytes)

proc getInitialSessionFlowControlWindowToSend(): uint32 = 
    initialSessionFlowControlWindowBytes.getSendValue()

proc hasReceivedInitialSessionFlowControlWindowBytes():bool = 
    initialSessionFlowControlWindowBytes.hasReceivedValue()

proc receivedInitialSessionFlowControlWindowBytes(): uint32 = 
     initialSessionFlowControlWindowBytes.getReceivedValue()

proc setDisableConnectionMigration() = connectionMigrationDisabled.setSendValue(1)

proc setAlternateServerAddressToSend(alternateServerAddress: QuicSocketAddress) = 
    alternateServerAddress.setSendValue(alternateServerAddress)

proc hasReceivedAlternateServerAddress():bool = alternateServerAddress.hasReceivedValue()

proc receivedAlternateServerAddress():QuicSocketAddress = alternateServerAddress.getReceivedValue()

proc setSupportMaxHeaderListSize() = supportMaxHeaderListSize.setSendValue(1)

proc supportMaxHeaderListSize() = supportMaxHeaderListSize.hasReceivedValue()

proc setStatelessResetTokenToSend(statelessResetToken: QuicUint128) = 
    statelessResetToken.setSendValue(statelessResetToken)

proc hasReceivedStatelessResetToken():bool = 
    statelessResetToken.getReceivedValue()

proc negotiated(): bool = idleNetworkTimeoutSeconds.negotiated()

proc setCreateSessionTagIndicators(tags: seq[uint32]) = createSessionTagIndicators = tags

proc createSesionTagIndicators(): seq[uint32] = createSesionTagIndicators

proc setDefaults() = 
    idleNetworkTimeoutSeconds.set(kMaximumIdleTimeoutSecs, 
                                  kDefaultIdleTimeoutSecs)
    silentClose.set(1,0)
    setMaxIncomingDynamicStreamsToSend(kDefaultMaxStreamsPerConnection)
    maxTimeBeforeCryptoHandshake = fromSeconds(kMaxTimeForCryptoHandshakeSecs)
    maxIdleTimeBeforeCryptoHandshake = fromSeconds(kInitialIdleTimeoutSecs)
    maxUndecryptablePackets = kDefaultMaxUndecryptablePackets

    setInitialStreamFlowControlWindowToSend(kMinimumFlowControlSendWindow)
    setInitialSessionFlowControlWindowToSend(kMinimumFlowControlSendWindow)
    setSupportMaxHeaderListSize()



proc toHandshakeMessage(out: CryptoHandshakeMessage) = 
    idleNetworkTimeoutSeconds.toHandshakeMessage(out)
    silentClose.toHandshakeMessage(out)
    maxIncomingDynamicStreams.toHandshakeMessage out
    bytesForConnectionId.toHandshakeMessage out
    initialRoundTripTimeus.toHandshakeMessage out
    initialStreamFlowControlWindowBytes.toHandshakeMessage out
    connectionMigrationDisabled.toHandshakeMessage out
    connectionOptions.toHandshakeMessage out
    alternateServerAddress.toHandshakeMessage out
    supportMaxHeaderListSize.toHandshakeMessage out
    statelessResetToken.toHandshakeMessage out

type helloType* = ref object



proc processPeerHello*(config: QuicConfig, 
                       peerHello: CryptoHandshakeMessage,
                       helloType: HelloType,
                       errorDetails: string): QuicErrorCode = 
    var error : QuicErrorCode = QUIC_NO_ERROR
    error = idleNetworkTimeoutSeconds.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = silentClose.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = maxIncomingDynamicStreams.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = bytesForConnectionId.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = initialRoundTripTimeus.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = initialStreamFlowControlWindowBytes.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = initialSessionFlowControlWindowBytes.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = connectionMigrationDisabled.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = connectionOptions.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = alternateServerAddress.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = supportMaxHeaderListSize.processPeerHello(peerHello, helloType, errorDetails)
    if error == QUIC_NO_ERROR:
        error = statelessResetToken.processPeerHello(peerHello, helloType, errorDetails)

type Perspective* = ref object
type QuicVersionLabel* = ref object

type optionalParam[T] = ref object
        present: bool
        value: T

type TransportParameters* = ref object
    perspective: Perspective
    version : QuicVersionLabel
    supportedVersions : QuicVersionLabelVector
    statelessResetToken : seq[uint8]
    initialMaxStreamData: uint32
    initialMaxData: uint32
    idleTimeout: uint16
    initialMaxBidiStreams: optionalParam[uint16]
    initialMaxUniStreams: optionalParam[uint16]
    maxPacketSize: optionalParam[uint16]
    ackDelayExponent: optionalParam[uint8]
    googleQuicParams: CryptoHandshakeMessage
    
proc fillTransportParameters(params: TransportParameters): bool =

proc processTransportParameters(params: TransportParameters, 
                                helloType: HelloType,
                                errorDetails: string): QuicErrorCode = 

