import tables

type Engine = ptr object
    peerRequestQueue: ptr prq
    workSignal: Channel[string]
    outbox: Channel[Envelope] 
    bs: Blockstore
    ledgerMap: Table[string,string]
    ticker: ptr Ticker
