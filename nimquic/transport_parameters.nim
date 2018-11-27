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


var DisableMigration = (get: (proc(s:Stream): tuple[disabled: uint16] = 
        s.readDataLE(addr result.disabled, 2)),
    put: (proc(s: Stream, input: var tuple[disabled: uint16]) = 
        if input.disabled == 1:
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




when isMainModule:
    # var b = 127
    # ss.writeDataBE(cast[ptr array[2,uint8]](addr b), 2)
    # ss.writeDataBE(addr b, 2)
    # ss.setPosition 0
    var ss = newStringStream()

    var transportParams : typeGetter(TransportParameters)
    transportParams.idleTimeout = (varint: 1'u64)
    transportParams.disableMigration = (disabled: 1'u16)
    TransportParameters.put(ss, transportParams)
    ss.setPosition 0
    var read = ss.readAll()
    echo cast[seq[uint8]](read)