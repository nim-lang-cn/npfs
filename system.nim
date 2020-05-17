import node, unixfs, routing, datastore, keystore, key, merkledag
import times

type Republisher = ref object
    r:   ptr ValueStore
    ds:  ptr Datastore
    self: ptr PrivKey
    ks:  ptr Keystore
    Interval: ptr Duration
    RecordLifetime: ptr Duration

type Root* = ref object
    node: ptr ProtoNode
    val: ptr FSNode
    repub: ptr Republisher
    dserv: ptr DAGService
    Type: string
