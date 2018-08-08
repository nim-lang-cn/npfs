import tables
import ../../../blocks

type Engine* = object
    peerRequestQueue: prq
    workSignal: Channel[string]
    outbox: Channel[Envelope] 
    bs: BasicBlock
    ledgerMap: Table[string,string]
    ticker: Ticker
