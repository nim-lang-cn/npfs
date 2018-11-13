import epollserver, nativesockets

type QuicServer* = object of EpollCallbackInterface
    dispatcher* : ptr QuicDispatcher
    epollServer*: EpollServer
    port*: int
    fd*: int
    packetsDropped*: QuicPacketCount
    overflowSupported*: bool
    silentClose*: bool
    config*: QuicConfig
    cryptoConfig*: QuicCryptoServerConfig
    cryptoConfigOptions*: ConfigOptions
    versionManager*: QuicVersionManager
    packetReader*: QuicPacketReader
    quicSimpleServerBackend*: QuicSimpleServerBackend
    weakFactory*: WeakPtrFactory<QuicServer>

proc name(s: QuicServer): string = "QuicServer"
proc createUDPSocketAndListen(s: QuicServer, address: ptr QuicSocketAddress): bool = 
    createNativeSocket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP)

proc waitForEvents(s: QuicServer) = discard

proc start(s: QuicServer) = discard

proc run(s: QuicServer) = discard

proc shutDown(s: QuicServer) = discard

proc onRegistration(s: QuicServer, eps: EpollServer, fd: int, eventMask: int) = discard

proc onModification(s: QuicServer, fd: int, eventMask: int) = discard

proc onEvent(s: QuicServer, fd: int, event: ptr EpollEvent) = discard

proc onUnregistration(s: QuicServer, fd: int, replaced: bool) = discard

proc onShutDown(s: QuicServer, eps: EpollServer, fd: int) = discard

proc setChloMultiplier(s: QuicServer, mutiplier: uint) = 
    cryptoConfig.setChloMultiplier(mutiplier)

proc setPreSharedKey(s: QuicServer,key: string) = 
    cryptoConfig.setPreSharedKey(key)

proc overflowSupported(s: QuicServer): bool = s.overflowSupported
proc packetsDropped(s: QuicServer) = s.packetsDropped
proc port(s: QuicServer): int = s.port
proc createWrite(s: QuicServer, fd: int): QuicPacketWriter = discard
proc createQuicDispatcher(s: QuicServer): createQuicDispatcher = discard
proc config(s: QuicServer): ptr QuicConfig = s.config
proc cryptoConfig(s: QuicServer): QuicCryptoServerConfig = s.cryptoConfig
proc epollServer(s: QuicServer): ptr EpollServer = s.epollServer
proc dispathcer(s: QuicServer): ptr QuicDispatcher = s.dispathcer.get()
proc versionManager(s: QuicServer): ptr QuicVersionManager = s.versionManager
proc serverBackend(s: QuicServer): ptr QuicSimpleServerBackend = s.QuicSimpleServerBackend
proc setSlientClose(s: QuicServer, value: bool) = s.slientClose = value

proc initialize(s: QuicServer)



