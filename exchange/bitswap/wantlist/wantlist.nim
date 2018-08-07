import tables
import ../../../cid

type Entry = ptr object
    Cid:      ptr Cid
    Priority: int
    SesTrk: Table[uint64,string]

type Wantlist = ptr object
    `set`: Table[string,Entry]
