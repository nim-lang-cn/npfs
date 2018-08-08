import tables
import ../../../cid

type Entry* = object
    Cid:      Cid
    Priority: int
    SesTrk: Table[uint64,string]

type ThreadSafe* = object
	`set`: Table[string, Entry]

type Wantlist* = object
    `set`: Table[string, Entry]
