import tables

type CryptoHandshakeMessage* = object
    tag: uint32
    tagValueMap: Table[uint32, string]
    minimumSize: uint
    serialized: QuicData

proc clear(message: CryptoHandshakeMessage) = discard
proc getSerialized(message: CryptoHandshakeMessage): QuicData = discard

proc mkakeDirty(message: CryptoHandshakeMessage): QuicData = 
    serialized.reset()
proc setValue[T](tag: uint32, v: T) = 
    tagValueMap[tag] = cast[string](v)

proc setVector[T](tag: uint32, v: seq[T]) = 
    if v.len == 0:
        tagValueMap[tag] = ""
    else:
        tagValueMap[tag] = cast[string](v)

proc setVersion(tag: uint32, version: ParsedQuicVersion) 

proc setVersionVector(tag: uint32, versions: ParsedQuicVersion) 
