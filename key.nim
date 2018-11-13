import random

type PrivKey* = object

const
    RSA* = 0
    Ed25519* = 1
    Secp256k1* = 2

const KeyTypes* :array[3, int] = [RSA, Ed25519, Secp256k1]

