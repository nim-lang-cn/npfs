import tables,lists

type EvictCallback = proc(key: string, value: string)

type LRU* = object
    size*  :    int
    evictList*: DoublyLinkedList[pointer]
    items*  :   Table[string,  DoublyLinkedNode[pointer]]
    onEvict* :  EvictCallback


type Cache* = object
    lru*  :LRU