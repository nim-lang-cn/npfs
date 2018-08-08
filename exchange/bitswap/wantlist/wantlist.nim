import tables
import ../../../cid

type Entry* = ptr object
    Cid:      Cid
    Priority: int
    SesTrk: Table[uint64,string]

type ThreadSafe* = ptr object
	`set`: Table[string, Entry]

type Wantlist* = ptr object
    `set`: Table[string, Entry]
