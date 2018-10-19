import quictypes, strutils

type QuicData* = object of RootObj
    buffer: ptr char
    length: uint
    ownsBuffer: bool

type QuicConnectionIdLength = enum
  PACKET_0BYTE_CONNECTION_ID = 0,
  PACKET_8BYTE_CONNECTION_ID = 8

type QuicPacket* = object of QuicData
    buffer* : ptr char
    destinationConnectionIdLength: QuicConnectionIdLength
    sourceConnectionIdLength: QuicConnectionIdLength
    includesVersion: bool
    includesDiversificationNonce: bool
    packetNumberLength: QuicPacketNumberLength

type QuicEncryptedPacket* = object of QuicData

type QuicReceivedPacket* = object of QuicEncryptedPacket
    receiptTime*: QuicTime
    ttl*: int

type SerializedPacket* = object
    encryptedBuffer*: ptr char
    encryptedLength*: QuicPacketLength
    retransimittableFrames*: QuicFrames
    hasCryptoHandshake*: IsHandshake
    numPaddingBytes*: int16
    packetNumber*: QuicPacketNumber
    packetNumberLength*: QuicPacketNumberLength
    encryptionLevel*: EncryptionLevel
    hasAck*: bool
    hasStopWaiting*: bool
    transmissionType*: TransmissionType
    originalPacketNumber*: QuicPacketNumber
    largestAcked*: QuicPacketNumber

type QuicPacketHeader* = object
    destinationConnectionId*: uint64
    destinationConnectionIdLength*: QuicConnectionIdLength
    sourceConnectionId*: uint64
    sourceConnectionIdLength*: QuicConnectionIdLength
    resetFlag* : bool
    versionFlag*: bool
    hasPossibleStatelessResetToken*: bool
    packetNumberLength*: QuicPacketNumberLength
    version*: parsedQuicVersion
    nonce*: DiversificationNonce
    packetNumber* : QuicPacketNumber
    form* : QuicIetfPacketHeaderForm
    longPacketType* : QuicLongHeaderType
    possibleStatelessResetToken*: QuicUint128

type SerializedPacketDeleter* = object


type OwningSerializedPacketPointer = ptr SerializedPacket|SerializedPacketDeleter

proc `$`(header: QuicPacketHeader): string = 
    result = "{ destination_connection_id: " & header.destinationConnectionId &
             ",destination_connection_id_length:" & header.destination_connection_id_length &
             ", source_connection_id:" & header.sourceConnectionId & 
             ", source_connection_id_lenght" & header.sourceConnectionIdLength &
             ", packet_number_length" & header.packetNumberLength &
             ", reset_flag" & header.resetFlag &
             ", version_flag" & header.versionFlag
    if header.versionFlag:
        result.add ", version: " & parsedQuicVersionToString(header.version)
    if header.nonce != nil: 
        result.add ", diversification_nonce: " & 
                   QuicStringPiece(header.nonce.data(),header.nonce.size()).toHex()
    result.add ", packet_number: " & header.packetNumber & "}\n"

proc clone*(packet: QuicEncryptedPacket): ptr QuicEncryptedPacket = 
    result = cast[ptr QuicEncryptedPacket]alloc0(packet.length)
    copyMem(result, packet.data, packet.length)
    result[].ownsBuffer = true

proc `$`*(packet: QuicEncryptedPacket): string =
    result = packet.length & "-byte data"

proc clone*(packet: QuicReceivedPacket): ptr QuicReceivedPacket = 
    result = cast[ptr QuicReceivedPacket]alloc0(packet.length)
    copyMem(result, packet.data, packet.length)

proc `=destroy`*(serializedPacket: SerializedPacket) = 
    if serializedPacket.retransimittableFrames != nil:
        deleteFrames(serializedPacket.retransimittableFrames)
    serializedPacket.encryptedBuffer = nil
    serializedPacket.encryptedLength = 0
    serializedPacket.largestAcked = 0

proc copyBuffer*(packet: serializedPacket): ptr char = 
    result = cast[ptr char]alloc0(packet.encryptedLength)
    copyMem(result, packet.data, packet.length)