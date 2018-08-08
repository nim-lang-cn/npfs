import notifications/notifications
import times
import tables, times
import ../../bitswap
import ../../cid
import notifications/notifications

type cidQueue* = object
    elems*:  seq[Cid] 
    eset*:   ptr Set

type Loggable* = object

type Session* = object
    tofetch:  ptr cidQueue
    activePeers: Table[string,string]
    activePeersArr: seq[string]
    bs  : ptr Bitswap
    incoming: Channel[blkRecv] 
    newReqs: Channel[seq[Cid]] 
    cancelKeys: Channel[seq[Cid]] 
    interestReqs: Channel[interestReq] 
    interest:  ptr Cache
    liveWants: Table[string,string]
    tick: string 
    baseTickDelay : Duration
    latTotal :Duration
    fetchcnt :int
    notif : ptr PubSub
    uuid : ptr Loggable
    id  :uint64
    tag :string