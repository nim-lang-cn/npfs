type QuicPacket* = object

type QuicConnectionIdLength = enum
  PACKET_0BYTE_CONNECTION_ID = 0,
  PACKET_8BYTE_CONNECTION_ID = 8

type QuicPacketHeader* = object
    destinationConnectionId: uint64
    destinationConnectionIdLength: QuicConnectionIdLength
    sourceConnectionId: uint64
