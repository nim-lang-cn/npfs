type QuicServerId* = object
    host*: string
    port*: uint16
    privacyModeEnabled*: bool

type SocketTag* = object

type QuicSessionKey* = object
    serverId: QuicServerId
    socketTag: SocketTag