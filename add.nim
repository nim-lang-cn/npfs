import packedjson
import blocks,format,merkledag, format, cid, system
type AddedObject = JsonNode

#Adder holds the switches passed to the `add` command.
type Adder* = object
    blockstore : BasicBlock
    dagService : DAGService
    Out        :Channel[AddedObject]
    Progress   :bool
    Hidden     :bool
    Pin        :bool
    Trickle    :bool
    RawLeaves  :bool
    Silent     :bool
    Wrap       :bool
    NoCopy     :bool
    Chunker    :string
    root      :  Node
    mroot     :  Root
    tempRoot :  Cid
    Prefix   :  Prefix
    liveNodes: uint64