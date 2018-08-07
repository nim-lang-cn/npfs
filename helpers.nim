import blocks,node
#UnixfsNode is a struct created to aid in the generation
# of unixfs DAG trees
type UnixfsNode* = ptr object
    raw*     : bool
    rawnode* :ptr BasicBlock
    node*    :ptr ProtoNode
    ufmt*    :ptr FSNode
    posInfo* :ptr PosInfo