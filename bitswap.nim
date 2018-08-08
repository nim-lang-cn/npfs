import packedjson, tables, wantmanager, blocks
import exchange/bitswap/network/interfaces
import exchange/bitswap/decision/engine

type blockRequest = JsonNode

#Bitswap instances implement the bitswap protocol.
type Bitswap* = ptr object
    findKeys : Channel[blockRequest] 
    wm : WantManager
    engine :  Engine
    network :  BitSwapNetwork
    blockstore :   BasicBlock
    notifications:  PubSub
    newBlocks: Channel[Cid]
    provideKeys: Channel[Cid]
    process:  Process
    counters:  counters
    dupMetric:  Histogram
    allMetric:  Histogram
    sessions: seq[Session]
    sessID   :uint64