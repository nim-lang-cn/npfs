import errors, os, fmt, strconv, strings 

proc FromString*(f:File, chunker:String): sizeSplitterv2 =
    case chunker
    of "" , "default" :
        var full = readAll(F)
        return nil
    else:
        return nil
        error("unrecognized chunker option: '$1'" %chunker)

