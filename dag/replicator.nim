import std/streams, std/strutils, std/os, cbor
import ../dagfs, ./stores

type
  DagfsReplicator* = ref DagfsReplicatorObj
  DagfsReplicatorObj* = object of DagfsStoreObj
    toStore, fromStore: DagfsStore
    cache: string
    cacheCid: Cid

proc replicatedPut(s: DagfsStore; blk: string): Cid =
  var r = DagfsReplicator(s)
  r.toStore.put blk

proc replicatedGetBuffer(s: DagfsStore; cid: Cid; buf: pointer; len: Natural): int =
  var r = DagfsReplicator(s)
  if r.cacheCid == cid:
    assert(cid.verify(r.cache), "cached block is invalid from previous get")
    if r.cache.len > len:
      raise newException(BufferTooSmall, "")
    result = r.cache.len
    copyMem(buf, r.cache[0].addr, result)
  else:
    try:
      result = r.toStore.getBuffer(cid, buf, len)
      r.cacheCid = cid
      r.cache.setLen result
      copyMem(r.cache[0].addr, buf, result)
      assert(cid.verify(r.cache), "cached block is invalid after copy from To store")
    except MissingObject:
      result = r.fromStore.getBuffer(cid, buf, len)
      r.cacheCid = cid
      r.cache.setLen result
      copyMem(r.cache[0].addr, buf, result)
      assert(cid.verify(r.cache), "replicate cache is invalid after copy from From store")
      discard r.toStore.put r.cache

proc replicatedGet(s: DagfsStore; cid: Cid; result: var string) =
  var r = DagfsReplicator(s)
  try: r.toStore.get(cid, result)
  except MissingObject:
    r.fromStore.get(cid, result)
    discard r.toStore.put result

proc newDagfsReplicator*(toStore, fromStore: DagfsStore): DagfsReplicator =
  ## Blocks retrieved by `get` are not verified.
  DagfsReplicator(
    putImpl: replicatedPut,
    getBufferImpl: replicatedGetBuffer,
    getImpl: replicatedGet,
    toStore: toStore,
    fromStore: fromStore,
    cache: "",
    cacheCid: initCid())
