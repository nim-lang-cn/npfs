import tables,lists

type EvictCallback = proc(key: string, value: string)

type LRU* = object
    size  :    int
    evictList: DoublyLinkedList
    items  :   Table[string,  DoublyLinkedNode]
    onEvict :  EvictCallback


type Cache = object
    lru  :LRU