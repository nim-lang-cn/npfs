import tables, times
import cid,bitsawp

type cidQueue = ptr object
    elems: ptr Cid
    eset:  ptr Set

type Session = ptr object
    tofetch: ptr cidQueue
    activePeers: Table[string,string]
    activePeersArr: seq[peer.ID]
    bs  :ptr Bitswap
    incoming: Channel[blkRecv] 
    newReqs: Channel[seq[Cid]] 
    cancelKeys: Channel[seq[Cid]] 
    interestReqs: Channel[interestReq] 
    interest: ptr Cache
    liveWants: Table[string,string]
    tick: string 
    baseTickDelay : Duration
    latTotal :Duration
    fetchcnt :int
    notif : PubSub
    uuid : Loggable
    id  :uint64
    tag :string