import message
import exchange/bitswap/network/interfaces

type msgQueue* = object
    p: string
    `out`:   BitSwapMessage
    network: BitSwapNetwork
    wl:      ThreadSafe
    sender:  MessageSender
    refcnt: int
    work Channel[string]
    done Channel[string]

type WantManager* = object
    incoming:     Channel[ptr wantSet] 
    connectEvent: Channel[peerStatus]     
    peerReqs     Channel[seq[string]] 
    peers: Table[string]msgQueue
    wl:    ThreadSafe
    bcwl:  ThreadSafe
    network: BitSwapNetwork
    cancel:  proc()
    wantlistGauge: Gauge
    sentHistogram: Histogram