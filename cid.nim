
type Multihash = seq[byte]


# Prefix represents all the metadata of a Cid,
# that is, the Version, the Codec, the Multihash type
# and the Multihash length. It does not contains
# any actual content information.
type Prefix* = ref object 
    Version:  uint64
    Codec:    uint64
    MhType:   uint64
    MhLength: int
    
type Cid* = ref object 
    version* :uint64
    codec*   :uint64
    hash* : Multihash