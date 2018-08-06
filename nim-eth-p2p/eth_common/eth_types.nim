import stint, nimcrypto, times, rlp, endians
export stint

type
  Hash256* = MDigest[256]
  KeccakHash* = Hash256

  EthTime* = Time

  VMWord* = UInt256

  BlockNonce* = array[8, byte]
  Blob* = seq[byte]

  BloomFilter* = array[256, byte]
  EthAddress* = array[20, byte]

  DifficultyInt* = UInt256
  GasInt* = int64
  ## Type alias used for gas computation
  # For reference - https://github.com/status-im/nimbus/issues/35#issuecomment-391726518

  Transaction* = object
    accountNonce*:  uint64
    gasPrice*:      GasInt
    gasLimit*:      GasInt
    to*:            EthAddress
    value*:         UInt256
    payload*:       Blob
    V*, R*, S*:     UInt256

  BlockNumber* = UInt256

  BlockHeader* = object
    parentHash*:    Hash256
    ommersHash*:    Hash256
    coinbase*:      EthAddress
    stateRoot*:     Hash256
    txRoot*:        Hash256
    receiptRoot*:   Hash256
    bloom*:         BloomFilter
    difficulty*:    DifficultyInt
    blockNumber*:   BlockNumber
    gasLimit*:      GasInt
    gasUsed*:       GasInt
    timestamp*:     EthTime
    extraData*:     Blob
    mixDigest*:     Hash256
    nonce*:         BlockNonce

  BlockBody* = object
    transactions*:  seq[Transaction]
    uncles*:        seq[BlockHeader]

  Log* = object
    address*:       EthAddress
    topics*:        seq[int32]
    data*:          Blob

  Receipt* = object
    stateRoot*:     Blob
    gasUsed*:       GasInt
    bloom*:         BloomFilter
    logs*:          seq[Log]

  AccessList* = object
    # XXX: Specify the structure of this

  ShardTransaction* = object
    chain*:         uint
    shard*:         uint
    to*:            EthAddress
    data*:          Blob
    gas*:           GasInt
    accessList*:    AccessList
    code*:          Blob
    salt*:          Hash256

  CollationHeader* = object
    shard*:         uint
    expectedPeriod*: uint
    periodStartPrevHash*: Hash256
    parentHash*:    Hash256
    txRoot*:        Hash256
    coinbase*:      EthAddress
    stateRoot*:     Hash256
    receiptRoot*:   Hash256
    blockNumber*:   BlockNumber

  HashOrNum* = object
    case isHash*: bool
    of true:
      hash*: Hash256
    else:
      number*: BlockNumber

  BlocksRequest* = object
    startBlock*: HashOrNum
    maxResults*, skip*: uint
    reverse*: bool

  AbstractChainDB* = ref object of RootRef

  BlockHeaderRef* = ref BlockHeader
  BlockBodyRef* = ref BlockBody

when BlockNumber is int64:
  ## The goal of these templates is to make it easier to switch
  ## the block number type to a different representation
  template vmWordToBlockNumber*(word: VMWord): BlockNumber =
    BlockNumber(word.toInt)

  template blockNumberToVmWord*(n: BlockNumber): VMWord =
    u256(n)

  template toBlockNumber*(n: SomeInteger): BlockNumber =
    int64(n)

else:
  template vmWordToBlockNumber*(word: VMWord): BlockNumber =
    word

  template blockNumberToVmWord*(n: BlockNumber): VMWord =
    n

  template toBlockNumber*(n: SomeInteger): BlockNumber =
    u256(n)

proc toBlockNonce*(n: uint64): BlockNonce =
  bigEndian64(addr result[0], unsafeAddr n)

proc toUint*(n: BlockNonce): uint64 =
  bigEndian64(addr result, unsafeAddr n[0])

#
# Rlp serialization:
#

proc read*(rlp: var Rlp, T: typedesc[StUint]): T {.inline.} =
  if rlp.isBlob:
    let bytes = rlp.toBytes
    if bytes.len > 0:
      result.initFromBytesBE(bytes.toOpenArray)
    else:
      result = 0.to(T)
  else:
    raise newException(RlpTypeMismatch, "Unsigned integer expected, but the source RLP is a list")

  rlp.skipElem

proc append*(rlpWriter: var RlpWriter, value: StUint) =
  if value > 128:
    let bytes = value.toByteArrayBE
    let nonZeroBytes = significantBytesBE(bytes)
    rlpWriter.append bytes.toOpenArray(bytes.len - nonZeroBytes,
                                       bytes.len - 1)
  else:
    rlpWriter.append(value.toInt)

proc read*(rlp: var Rlp, T: typedesc[Stint]): T {.inline.} =
  # The Ethereum Yellow Paper defines the RLP serialization only
  # for unsigned integers:
  {.error: "RLP serialization of signed integers is not allowed".}
  discard

proc append*(rlpWriter: var RlpWriter, value: Stint) =
  # The Ethereum Yellow Paper defines the RLP serialization only
  # for unsigned integers:
  {.error: "RLP serialization of signed integers is not allowed".}
  discard

proc read*(rlp: var Rlp, T: typedesc[MDigest]): T {.inline.} =
  result.data = rlp.read(type(result.data))

proc append*(rlpWriter: var RlpWriter, a: MDigest) {.inline.} =
  rlpWriter.append(a.data)


proc read*(rlp: var Rlp, T: typedesc[Time]): T {.inline.} =
  result = fromUnix(rlp.read(int64))

proc append*(rlpWriter: var RlpWriter, t: Time) {.inline.} =
  rlpWriter.append(t.toUnix())

proc rlpHash*[T](v: T): Hash256 =
  keccak256.digest(rlp.encode(v).toOpenArray)

func blockHash*(h: BlockHeader): KeccakHash {.inline.} = rlpHash(h)

proc notImplemented =
  assert false, "Method not impelemented"

template deref*(r: BlockHeaderRef | BlockBodyRef): auto =
  r[]

method genesisHash*(db: AbstractChainDb): KeccakHash {.base.} =
  notImplemented()

method getBlockHeader*(db: AbstractChainDb, b: HashOrNum): BlockHeaderRef {.base.} =
  notImplemented()

method getBestBlockHeader*(db: AbstractChainDb): BlockHeaderRef {.base.} =
  notImplemented()

method getSuccessorHeader*(db: AbstractChainDb,
                           h: BlockHeader): BlockHeaderRef {.base.} =
  notImplemented()

method getBlockBody*(db: AbstractChainDb, blockHash: KeccakHash): BlockBodyRef {.base.} =
  notImplemented()
