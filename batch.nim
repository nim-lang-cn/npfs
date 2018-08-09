import merkledag, format

type Batch* = object
    ds : DAGService

    cancel : func()

    activeCommits : int
    err      :     string
    commitResults : Channel[string]

    nodes : seq[Node]
    size : int

    MaxSize* : int
    MaxNodes* : int

proc add* (nd: Node): Batch =
    discard