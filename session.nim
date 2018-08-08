import tables, times
import cid, bitswap

type cidQueue = object
    elems:  Cid
    eset:   Set

type Session = object
    tofetch:  cidQueue
    activePeers: Table[string,string]
    activePeersArr: seq[string]
    bs  : Bitswap
    incoming: Channel[blkRecv] 
    newReqs: Channel[seq[Cid]] 
    cancelKeys: Channel[seq[Cid]] 
    interestReqs: Channel[interestReq] 
    interest:  Cache
    liveWants: Table[string,string]
    tick: string 
    baseTickDelay : Duration
    latTotal :Duration
    fetchcnt :int
    notif : PubSub
    uuid : Loggable
    id  :uint64
    tag :string