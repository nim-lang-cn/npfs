import random

proc generateConnectionID*(len: uint8 = 0): seq[uint8] = 
    randomize()
    for i in 1..rand(4..18):
        result.add uint8 rand(0..255)
    
when isMainModule:
    echo generateConnectionID().len
