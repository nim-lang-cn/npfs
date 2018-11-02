import posix, net

type IPEndPoint* = object
    address*: IpAddress
    port*: uint16

proc address*(ip: IPEndPoint): IPAddress = ip.address

proc port*(ip: IPEndPoint): uint16 = ip.port

proc getFamily(ip: IPEndPoint): IpAddressFamily = discard

proc getSocketAddrFamily(ip: IPEndPoint): int = discard

proc toSockAddr(ip: IPEndPoint, 
                address: ptr SockAddr, 
                addressLength: uint): bool = discard

proc fromSockAddr(ip: IPEndPoint, 
                  address: ptr SockAddr, 
                  addressLength: uint): bool = discard

proc toString(ip: IPEndPoint): string = discard

proc ToStringWithoutPort(ip: IPEndPoint): string = discard