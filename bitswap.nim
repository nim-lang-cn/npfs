import json, tables, wantmanager, blocks, interfaces, process
import exchange/bitswap/network/interfaces
import exchange/bitswap/decision/engine
import exchange/bitswap/notifications/notifications

type blockRequest = JsonNode

type counters* = object
    blocksRecvd :   uint64
    dupBlocksRecvd: uint64
    dupDataRecvd :  uint64
    blocksSent  :   uint64
    dataSent   :    uint64
    dataRecvd   :   uint64
    messagesRecvd:  uint64
    
#Bitswap instances implement the bitswap protocol.
type Bitswap* = object
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