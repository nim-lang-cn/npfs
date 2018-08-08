import notifications/notifications
import times
import tables
import ../../bitswap
import ../../cid


type cidQueue = ptr object
    elems :seq[Cid]
    eset  :seq[Set]

type Session* = ptr object
    tofetch:        cidQueue
    activePeers:    Table[string, string]
    activePeersArr:  seq[string]

    bs     :      Bitswap
    incoming :    Channel[blkRecv] 
    newReqs   :   Channel[Cid] 
    cancelKeys :  Channel[Cid] 
    interestReqs: Channel[interestReq] 

    interest : Cache
    liveWants: Table[string,Time]

    tick    :   Timer
    baseTickDelay: Duration

    latTotal: Duration
    fetchcnt: int

    notif: PubSub

    uuid: logging.Loggable

    id : uint64
    tag: string