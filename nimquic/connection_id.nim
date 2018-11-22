import random, math


proc generateConnectionID*(len: uint8): uint64 = 
    result = rand(pow(2.0, 4.0).uint64..pow(2.0,18.0).uint64)
