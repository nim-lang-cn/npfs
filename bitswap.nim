import packedjson, tables
import exchange/bitswap/network/interfaces

type blockRequest = JsonNode

type WantManager* = ptr object
    incoming:     Channel[ptr wantSet] 
    connectEvent: Channel[peerStatus]     
    peerReqs     Channel[seq[string]] 
    peers: Table[string]msgQueue
    wl:    ptr ThreadSafe
    bcwl:  ptr ThreadSafe
    network: BitSwapNetwork
    cancel:  proc()
    wantlistGauge: Gauge
    sentHistogram: Histogram
    
#Bitswap instances implement the bitswap protocol.
type Bitswap* = ptr object
    findKeys : Channel[blockRequest] 
    wm : ptr WantManager
    engine : ptr Engine
    network : ptr BitSwapNetwork
    blockstore : ptr  Blockstore
    notifications: ptr PubSub
    newBlocks: Channel[Cid]
    provideKeys: Channel[Cid]
    process: ptr Process
    counters: ptr counters
    dupMetric: ptr Histogram
    allMetric:ptr Histogram
    sessions: seq[ptr Session]
    sessID   :uint64