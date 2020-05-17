import cid
type BasicBlock* = ref object
    cid : Cid
    data : seq[byte]