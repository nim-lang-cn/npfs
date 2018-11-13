import cid
type BasicBlock* = object
    cid : Cid
    data : seq[byte]