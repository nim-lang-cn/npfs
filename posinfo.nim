type PosInfo* = ref object
    Offset*:   uint64
    FullPath*: string
    Stat*: File 