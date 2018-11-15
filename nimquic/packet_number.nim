const
    PacketNumberLenInvalid*:uint8 = 0
    PacketNumberLen1*:uint8 = 1
    PacketNumberLen2*:uint8 = 2
    PacketNumberLen4*:uint8 = 4
    PacketNumberLen6*:uint8 = 6

proc DecodePacketNumber*(packetNumberLength: uint8, 
                        lastPacketNumber: uint64, 
                        wirePacketNumber: uint64, 
                        version: uint32): uint64 = 
    var expectedPn = lastPacketNumber + 1
    var pnWin = uint64 1 shl packetNumberLength
    var pnHwin = uint64 pnWin div 2
    var pnMask = pnWin - 1
    var candidatePn = expectedPn and not pnMask or wirePacketNumber
    if candidatePn <= expectedPn - pnHwin:
        result = candidatePn + pnWin
    if candidatePn > expectedPn + pnHwin and candidatePn > pnWin:
        result = candidatePn - pnWin
    result = candidatePn
  

proc GetPacketNumberLengthForHeader(packetNumber, leastUnacked: uint64, version: uint32): uint8 =
    var diff = packetNumber - leastUnacked
    if diff < (1 shl (14 - 1)) :
        result = PacketNumberLen2
    result = PacketNumberLen4

proc GetPacketNumberLength*(packetNumber: uint64): uint8 = 
    if packetNumber < (1 shl (uint8(PacketNumberLen1) * 8)):
        result = PacketNumberLen1
    if packetNumber < (1 shl (uint8(PacketNumberLen2) * 8)):
        result = PacketNumberLen2
    if packetNumber < (1 shl (uint8(PacketNumberLen4) * 8)):
        result = PacketNumberLen4
    result = PacketNumberLen6