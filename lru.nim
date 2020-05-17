import tables,lists

type EvictCallback = proc(key: string, value: string)

type LRU* = ref object
    size*  :    int
    evictList*: DoublyLinkedList[pointer]
    items*  :   Table[string,  DoublyLinkedNode[pointer]]
    onEvict* :  EvictCallback


type Cache* = ref object
    lru*  :LRU