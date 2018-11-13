import cid
type Link* = object
    Name :string
    Size :uint64
    Cid : Cid

# ProtoNode represents a node in the IPFS Merkle DAG.
# nodes have opaque data and a set of navigable links.
type ProtoNode* = object
    links: seq[Link]
    data:  seq[byte]
    encoded: seq[byte]
    cached: Cid
    Prefix: Prefix