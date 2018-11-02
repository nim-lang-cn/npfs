type QuicCryptoServerConfig* = object
    expiryTime*: QuicWallTime
    channelIdEnabled: bool
    tokenBindingParams: seq[uint32]
    id: string
    orbit: string
    p256: bool
    TESTING: ptr char


proc generateConfig(config: QuicCryptoServerConfig,
                    rand: QuicRandom, 
                    clock: QuicClock, 
                    options: ConfigOptions): 
                    ptr QuicServerConfigProtobuf = discard

proc addConfig(config: QuicCryptoServerConfig,
               protobuf: ptr QuicServerConfigProtobuf, 
               now: QuicWallTime): 
               ptr CryptoHandshakeMessage = discard

proc addDefaultConfig(config: QuicCryptoServerConfig,
                      rand: ptr QuicRandom,
                      clock: QuicClock, 
                      options: ConfigOptions):
                      ptr CryptoHandshakeMessage = discard

proc setConfigs(config: QuicCryptoServerConfig,
                protobufs: seq[ptr QuicServerConfigProtobuf], 
                now: QuicWallTime): bool = discard

proc setSourceAddressTokenKeys(config: QuicCryptoServerConfig,
                               keys: seq[string]) = discard

proc getConfigIds(config: QuicCryptoServerConfig, scids: seq[string]) = discard

proc validateClientHello(config: QuicCryptoServerConfig,
                         clientHello: CryptoHandshakeMessage,
                         clientIp: QuicIpAddress,
                         serverAddress: QuicSocketAddress,
                         version: QuicTransportVersion,
                         clock: ptr QuicClock,
                         cryptoProof: ptr QuicSignedServerConfig,
                         doneCb: ptr ValidateClientHelloResultCallback) = discard

proc processClientHello*() = discard

proc buildServerConfigUpdateMessage*() = discard

proc setEphemeralKeySource(ephemeralKeySource: ptr EphemeralKeySource) = discard

proc setReplayProtection(on: bool) = discard

proc setChloMultiplier(multiplier: uint) = discard

proc setSourceAddressTokenFutureSecs(futureSecs: uint32) = discard

proc setSourceAddressTokenLifetimeSecs(lifetimeSecs: uint32) = discard

proc setEnableServingSct(enableServingSct: bool) = discard

proc AcquirePrimaryConfigChangedCb(cb: ptr PrimaryConfigChangedCallback) = discard

proc numberOfConfigs(): int = discard

proc setRejectionObserver() = discard



