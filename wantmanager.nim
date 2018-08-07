import message

type msgQueue = ptr object
    p: ID
    `out`:   BitSwapMessage
    network: BitSwapNetwork
    wl:      ptr ThreadSafe
    sender:  MessageSender
    refcnt: int
    work Channel[]
    done Channel[]