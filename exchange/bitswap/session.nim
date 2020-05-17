import notifications/notifications
import times
import tables, times
import ../../bitswap
import ../../cid
import notifications/notifications

type cidQueue* = ref object
    elems*:  seq[Cid] 
    eset*:   ref Set

type Loggable* = ref object

type Session* = ref object
    tofetch:  ref cidQueue
    activePeers: Table[string,string]
    activePeersArr: seq[string]
    bs  : ref Bitswap
    incoming: Channel[blkRecv] 
    newReqs: Channel[seq[Cid]] 
    cancelKeys: Channel[seq[Cid]] 
    interestReqs: Channel[interestReq] 
    interest:  ref Cache
    liveWants: Table[string,string]
    tick: string 
    baseTickDelay : Duration
    latTotal :Duration
    fetchcnt :int
    notif : ref PubSub
    uuid : ref Loggable
    id  :uint64
    tag :string