import cid
type BasicBlock* = ptr object
    cid : ptr Cid
    data : seq[byte]