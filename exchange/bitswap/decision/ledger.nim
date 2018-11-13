import tables

type Receipt* = object
    Peer:      string
    Value:     float64
    Sent:      uint64
    Recv:      uint64
    Exchanged: uint64

type debtRatio* = object
    BytesSent: uint64
    BytesRecv: uint64

type ledger* = object
    Partner : string
    Accounting : debtRatio
    lastExchange: string
    exchangeCount: uint64
    wantList: ptr Wantlist
    sentToPeer: Table[string,string]
    `ref` :int