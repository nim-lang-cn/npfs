import streams, binaryparse, math, strformat
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
    result = candidatePn 
    if candidatePn <= expectedPn - pnHwin:
        result = candidatePn + pnWin
    if candidatePn > expectedPn + pnHwin and candidatePn > pnWin:
        result = candidatePn - pnWin
  
proc delta(a, b :uint64): uint64 =
    if a < b :
        result =  b - a
    result =  a - b
    
proc closestTo(target, a, b :uint64): uint64 =
    if delta(target, a) < delta(target, b) :
        result =  a
    result =  b

proc InferPacketNumber(packetNumberLength: uint8,
                       lastPacketNumber: uint64,
                       wirePacketNumber: uint64,
                       version: uint32):uint64 =
    var epochDelta: uint64
    case packetNumberLength 
    of PacketNumberLen1:
        epochDelta = 1 shl 7
    of PacketNumberLen2:
        epochDelta = 1 shl 14
    of PacketNumberLen4:
        epochDelta = 1 shl 30
    else: discard
    
    var epoch = lastPacketNumber and not (epochDelta - 1)
    var prevEpochBegin = epoch - epochDelta
    var nextEpochBegin = epoch + epochDelta
    result =  closestTo(
        lastPacketNumber+1,
        epoch+wirePacketNumber,
        closestTo(lastPacketNumber+1, 
                  prevEpochBegin+wirePacketNumber, 
                  nextEpochBegin+wirePacketNumber),
    )

proc GetPacketNumberLengthForHeader(packetNumber, 
                                    leastUnacked: uint64, 
                                    version: uint32): uint8 =
    var diff = packetNumber - leastUnacked
    if diff < (1 shl (14 - 1)) :
        result = PacketNumberLen2
    result = PacketNumberLen4

proc getPacketNumberLength*(packetNumber: uint64): uint8 = 
    if packetNumber < (1 shl (uint8(PacketNumberLen1) * 8)):
        result = PacketNumberLen1
    if packetNumber < (1 shl (uint8(PacketNumberLen2) * 8)):
        result = PacketNumberLen2
    if packetNumber < (1 shl (uint8(PacketNumberLen4) * 8)):
        result = PacketNumberLen4

when isMainModule:
    import strformat, math
    var number = DecodePacketNumber(14, 0xaa82f30e'u64, 0x9b3, 0)
    echo fmt"{number :#x}"

