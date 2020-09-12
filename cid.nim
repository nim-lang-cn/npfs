
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
    str: string

const
    Raw = 0x55
    DagProtobuf* = 0x70
    DagCBOR     = 0x71
    Libp2pKey   = 0x72
    GitRaw = 0x78
    EthBlock              = 0x90
    EthBlockList          = 0x91
    EthTxTrie             = 0x92
    EthTx                 = 0x93
    EthTxReceiptTrie      = 0x94
    EthTxReceipt          = 0x95
    EthStateTrie          = 0x96
    EthAccountSnapshot    = 0x97
    EthStorageTrie        = 0x98
    BitcoinBlock          = 0xb0
    BitcoinTx             = 0xb1
    ZcashBlock            = 0xc0
    ZcashTx               = 0xc1
    DecredBlock           = 0xe0
    DecredTx              = 0xe1
    DashBlock             = 0xf0
    DashTx                = 0xf1
    FilCommitmentUnsealed = 0xf101
    FilCommitmentSealed   = 0xf102