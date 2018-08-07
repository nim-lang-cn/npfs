import protobuf

parseProtoFile("unixfs.proto")

type FSNode*  = ptr object
    Data :seq[byte]
    blocksizes :uint64
    subtotal: uint64
    Type : unixfs_pb_Data_DataType