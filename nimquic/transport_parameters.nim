import endians, streams, sequtils
import binaryparse
import varint, parsers


var 
    originalConnectionIDParameterID = 0x0
    idleTimeoutParameterID = 0x1
    statelessResetTokenParameterID = 0x2
    maxPacketSizeParameterID = 0x3
    initialMaxDataParameterID = 0x4
    initialMaxStreamDataBidiLocalParameterID = 0x5
    initialMaxStreamDataBidiRemoteParameterID = 0x6
    initialMaxStreamDataUniParameterID = 0x7
    initialMaxStreamsBidiParameterID = 0x8
    initialMaxStreamsUniParameterID = 0x9
    disableMigrationParameterID = 0xc


# type TransportParameters* = object
#     initialMaxStreamDataBidiLocal*: uint64
#     initialMaxStreamDataBidiRemote*: uint64
#     initialMaxStreamDataUni*: uint64
#     initialMaxData*: uint64
#     maxPacketSize*: uint64
#     maxUniStreams*: uint64
#     maxBidiStreams*: uint64
#     idleTimeout*: uint64
#     disableMigration*: bool
#     statelessResetToken*: seq[byte]
#     originalConnectionId*: seq[byte]

# proc writeVarInt*(s: pointer, i: uint64) = 
#     var buff : seq[uint8]
#     var ptrarray = cast[array[8, uint8]](i)
#     if i <= maxVarInt1:
#         buff.add uint8(i) 
#     elif i <= maxVarInt2:
#         var b1 = ptrarray[0] or 0x40
#         buff.add b1
#         buff.add ptrarray[1]
#     elif i <= maxVarInt4:
#         var b1 = ptrarray[0] or 0x80
#         buff.add b1
#         buff.add ptrarray[1..3]
#     elif i <= maxVarInt8:
#         var b1 = ptrarray[0] or 0xc0
#         buff.add b1
#         buff.add ptrarray[1..7]
var variableLengthEncoding = (get: (proc(s:Stream): tuple[varint: uint64] = s.readVarInt),
    put: (proc (s: Stream, input: var tuple[varint: uint64]) = s.writeVarInt(input)))

var DisableMigration = (get: (proc(s:Stream): tuple[varint: uint16] = 
        s.readDataLE(addr result.varint, 2)),
    put: (proc(s: Stream, input: var tuple[varint: uint16]) = 
        if input.varint == 1:
            var disable = disableMigrationParameterID
            s.writeDataBE(addr disable, 2)
            var migrate = 0
            s.writeDataBE(addr migrate, 2)))

var StatelessResetToken = (
    get: (proc(s:Stream): tuple[varint: seq[uint8]] = 
        s.readDataLE(addr result.varint, 2)),
    put: (proc(s: Stream, input: var tuple[varint: seq[uint8]]) = 
        if input.varint.len != 0:
            var token = statelessResetTokenParameterID
            s.writeDataBE(addr token, 2)
            var tokenLen = input.varint.len
            s.writeDataBE(addr tokenLen, 2)
            s.writeDataBE(addr input.varint, 2)
        )
    )
            
            
var OriginalConnectionID = (
    get: (proc(s:Stream): tuple[varint: seq[uint8]] = 
        s.readDataLE(addr result.varint, 2)),
    put: (proc(s: Stream, input: var tuple[varint: seq[uint8]]) = 
        if input.varint.len != 0:
            var connectId = originalConnectionIDParameterID
            s.writeDataBE(addr connectId, 2)
            var connectIdLen = input.varint.len
            s.writeDataBE(addr connectIdLen, 2)
            s.writeDataBE(addr input.varint, 2)
        )
    )

createParser(TransportParameters):
    u16: initialMaxStreamDataBidiLocalParameterID
    u16: initialMaxStreamDataBidiLocalLength
    *variableLengthEncoding: initialMaxStreamDataBidiLocal

    u16: initialMaxStreamDataBidiRemoteParameterID
    u16: initialMaxStreamDataBidiRemoteLength
    *variableLengthEncoding: initialMaxStreamDataBidiRemote

    u16: initialMaxStreamDataUniParameterID
    u16: initialMaxStreamDataUniLength
    *variableLengthEncoding: initialMaxStreamDataUni

    u16: initialMaxDataParameterID
    u16: initialMaxDataLength
    *variableLengthEncoding: initialMaxData

    u16: initialMaxStreamsBidiParameterID
    u16: maxBidiStreamsLength
    *variableLengthEncoding: maxBidiStreams

    u16: initialMaxStreamsUniParameterID
    u16: maxUniStreamsLength
    *variableLengthEncoding: maxUniStreams

    u16: idleTimeoutParameterID
    u16: idleTimeoutLength
    *variableLengthEncoding: idleTimeout

    u16: maxPacketSizeParameterID
    u16: maxReceivePacketSizeLength
    *variableLengthEncoding: maxReceivePacketSize
    *DisableMigration: disableMigration
    *StatelessResetToken: statelessResetToken
    *OriginalConnectionID: originalConnectionID


# proc marshal(s: Stream, p: TransportParameters) =
#     # initial_max_stream_data_bidi_local
    # bigEndian16(addr result[0], initialMaxStreamDataBidiLocalParameterID)
    # bigEndian16(addr result[2], unsafeAddr varIntLen p.initialMaxStreamDataBidiLocal)
    # writeVarInt(addr result[4], p.initialMaxStreamDataBidiLocal)
    # # initial_max_stream_data_bidi_remote
    # bigEndian16(addr result[6], unsafeAddr initialMaxStreamDataBidiRemoteParameterID)
    # bigEndian16(addr result[8], unsafeAddr varIntLen p.initialMaxStreamDataBidiRemote)
    # writeVarInt(addr result[10], p.InitialMaxStreamDataBidiRemote)
    # # initial_max_stream_data_uni
    # bigEndian16(addr result[12], unsafeAddr initialMaxStreamDataUniParameterID)
    # bigEndian16(addr result[14], unsafeAddr varIntLen p.initialMaxStreamDataUni)
    # writeVarInt(addr result[16], p.initialMaxStreamDataUni)
    # # initial_max_data
    # bigEndian16(addr result[18], unsafeAddr initialMaxDataParameterID)
    # bigEndian16(addr result[20], unsafeAddr varIntLen p.initialMaxData)
    # writeVarInt(addr result[22], p.initialMaxData)
    # # initial_max_bidi_streams
    # bigEndian16(addr result[24], unsafeAddr initialMaxStreamsBidiParameterID)
    # bigEndian16(addr result[26], unsafeAddr varIntLen p.maxBidiStreams)
    # writeVarInt(addr result[28], p.maxBidiStreams)
    # # initial_max_uni_streams
    # bigEndian16(addr result[30], unsafeAddr initialMaxStreamsBidiParameterID)
    # bigEndian16(addr result[32], unsafeAddr varIntLen p.maxBidiStreams)
    # writeVarInt(addr result[34], p.maxBidiStreams)
    # # idle_timeout
    # bigEndian16(addr result[30], unsafeAddr idleTimeoutParameterID)
    # bigEndian16(addr result[32], unsafeAddr varIntLen p.idleTimeout/time.Second)
    # writeVarInt(addr result[34], p.maxBidiStreams)
    # # max_packet_size
    # bigEndian16(addr result[30], unsafeAddr maxPacketSizeParameterID)
    # bigEndian16(addr result[32], unsafeAddr varIntLen maxReceivePacketSize)
    # writeVarInt(addr result[34], p.maxReceivePacketSize)
    # # disable_migration
    # if p.disableMigration:
    #     bigEndian16(addr result[30], unsafeAddr maxPacketSizeParameterID)
    #     bigEndian16(addr result[32], unsafeAddr varIntLen maxReceivePacketSize)
    # if p.statelessResetToken.len > 0:
    #     bigEndian16(addr result[30], unsafeAddr statelessResetTokenParameterID)
    #     bigEndian16(addr result[32], unsafeAddr varIntLen statelessResetToken)
    #     copyMem(addr result[], p.statelessResetToken, p.statelessResetToken.len)
    # # original_connection_id
    # if p.originalConnectionId.len > 0 :
    #     bigEndian16(addr result[30], unsafeAddr statelessResetTokenParameterID)
    #     bigEndian16(addr result[32], unsafeAddr varIntLen statelessResetToken)
    #     copyMem(addr result[], p.originalConnectionId, p.originalConnectionId.len)

when isMainModule:
    var b = 127
    var ss = newStringStream()
    ss.writeDataBE( cast[ptr array[2,uint8]](addr b), 2)
    # ss.writeDataBE(addr b, 2)
    ss.setPosition 0
    var read = ss.readAll()
    echo cast[seq[uint8]](read)