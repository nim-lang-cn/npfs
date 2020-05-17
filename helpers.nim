import blocks,node
#UnixfsNode is a struct created to aid in the generation
# of unixfs DAG trees
type UnixfsNode* = ref object
    raw*     : bool
    rawnode* :ptr BasicBlock
    node*    :ptr ProtoNode
    ufmt*    :ptr FSNode
    posInfo* :ptr PosInfo