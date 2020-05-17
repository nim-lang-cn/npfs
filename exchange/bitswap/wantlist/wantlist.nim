import tables
import ../../../cid

type Entry* = ref object
    Cid:      Cid
    Priority: int
    SesTrk: Table[uint64,string]

type ThreadSafe* = ref object
	`set`: Table[string, Entry]

type Wantlist* = ref object
    `set`: Table[string, Entry]
