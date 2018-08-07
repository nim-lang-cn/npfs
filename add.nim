import packedjson
import blocks,format,merkledag, format, cid, system
type AddedObject = JsonNode

#Adder holds the switches passed to the `add` command.
type Adder* = ptr object
    blockstore : ptr BasicBlock
    dagService : ptr DAGService
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
    root      : ptr Node
    mroot     : ptr Root
    tempRoot : ptr Cid
    Prefix   : ptr Prefix
    liveNodes: uint64