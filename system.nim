import node, unixfs, routing, datastore, keystore, key, merkledag
import times

type Republisher = ptr object
    r:    ValueStore
    ds:   Datastore
    self:  PrivKey
    ks:   Keystore
    Interval: Duration
    RecordLifetime: Duration

type Root* = ptr object
    node: ProtoNode
    val: FSNode
    repub: Republisher
    dserv: DAGService
    Type: string
