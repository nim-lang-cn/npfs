import ipendpoint, posix, net

type QuicSocketAddressImpl* = object
    socketAddress: IPEndPoint
    
proc isInitialized*(address: QuicSocketAddressImpl): bool = discard

proc toString*(address: QuicSocketAddressImpl): string = discard

proc fromSocket(address: QuicSocketAddressImpl, fd: int): int = discard

proc normalized(address: QuicSocketAddressImpl): QuicSocketAddressImpl = discard

proc host(address: QuicSocketAddressImpl): IpAddress = discard

proc port(address: QuicSocketAddressImpl): uint16 = discard

proc genericAddress*(address: QuicSocketAddressImpl): Sockaddr_storage = discard

type QuicSocketAddress* = object
    impl*: QuicSocketAddressImpl


proc isInitialized*(address: QuicSocketAddress): bool = discard

proc toString*(address: QuicSocketAddress): string = discard

proc fromSocket(address: QuicSocketAddress, fd: int): int = discard

proc normalized(address: QuicSocketAddress): QuicSocketAddress = discard

proc host(address: QuicSocketAddress): IpAddress = discard

proc port(address: QuicSocketAddress): uint16 = discard

proc genericAddress*(address: QuicSocketAddress): Sockaddr_storage = discard

proc impl(address: QuicSocketAddress): QuicSocketAddressImpl = discard


