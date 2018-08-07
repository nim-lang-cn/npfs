type Root* = ptr object
    node: ptr ProtoNode
    val: FSNode
    repub: *Republisher
    dserv: ipld.DAGService
    Type: string
