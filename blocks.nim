import cid
type BasicBlock* = ptr object
    cid : Cid
    data : seq[byte]