#              Asyncdispatch2 Test Suite
#                 (c) Copyright 2018
#         Status Research & Development GmbH
#
#              Licensed under either of
#  Apache License, version 2.0, (LICENSE-APACHEv2)
#              MIT license (LICENSE-MIT)

import unittest
import ../asyncdispatch2

var testLockResult = ""
var testEventResult = ""
var testQueue1Result = 0
var testQueue2Result = 0
var testQueue3Result = 0

proc testLock(n: int, lock: AsyncLock) {.async.} =
  await lock.acquire()
  testLockResult = testLockResult & $n
  lock.release()

proc test1(): string =
  var lock = newAsyncLock()
  lock.own()
  discard testLock(0, lock)
  discard testLock(1, lock)
  discard testLock(2, lock)
  discard testLock(3, lock)
  discard testLock(4, lock)
  discard testLock(5, lock)
  discard testLock(6, lock)
  discard testLock(7, lock)
  discard testLock(8, lock)
  discard testLock(9, lock)
  lock.release()
  ## There must be exactly 20 poll() calls
  for i in 0..<20:
    poll()
  result = testLockResult

proc testEvent(n: int, ev: AsyncEvent) {.async.} =
  await ev.wait()
  testEventResult = testEventResult & $n

proc test2(): string =
  var event = newAsyncEvent()
  event.clear()
  discard testEvent(0, event)
  discard testEvent(1, event)
  discard testEvent(2, event)
  discard testEvent(3, event)
  discard testEvent(4, event)
  discard testEvent(5, event)
  discard testEvent(6, event)
  discard testEvent(7, event)
  discard testEvent(8, event)
  discard testEvent(9, event)
  event.fire()
  ## There must be exactly 2 poll() calls
  poll()
  poll()
  result = testEventResult

proc task1(aq: AsyncQueue[int]) {.async.} =
  var item1 = await aq.get()
  var item2 = await aq.get()
  testQueue1Result = item1 + item2

proc task2(aq: AsyncQueue[int]) {.async.} =
  await aq.put(1000)
  await aq.put(2000)

proc test3(): int =
  var queue = newAsyncQueue[int](1)
  discard task1(queue)
  discard task2(queue)
  ## There must be exactly 2 poll() calls
  poll()
  poll()
  result = testQueue1Result

const testsCount = 1000
const queueSize = 10

proc task3(aq: AsyncQueue[int]) {.async.} =
  for i in 1..testsCount:
    var item = await aq.get()
    testQueue2Result -= item

proc task4(aq: AsyncQueue[int]) {.async.} =
  for i in 1..testsCount:
    await aq.put(i)
    testQueue2Result += i

proc test4(): int =
  var queue = newAsyncQueue[int](queueSize)
  waitFor(task3(queue) and task4(queue))
  result = testQueue2Result

proc task51(aq: AsyncQueue[int]) {.async.} =
  var item1 = await aq.popFirst()
  var item2 = await aq.popLast()
  var item3 = await aq.get()
  testQueue3Result = item1 - item2 + item3

proc task52(aq: AsyncQueue[int]) {.async.} =
  await aq.put(100)
  await aq.addLast(1000)
  await aq.addFirst(2000)

proc test5(): int =
  var queue = newAsyncQueue[int](3)
  discard task51(queue)
  discard task52(queue)
  poll()
  poll()
  result = testQueue3Result

proc test6(): bool =
  var queue = newAsyncQueue[int]()
  queue.putNoWait(1)
  queue.putNoWait(2)
  queue.putNoWait(3)
  queue.putNoWait(4)
  queue.putNoWait(5)
  queue.clear()
  result = (len(queue) == 0)

proc test7(): bool =
  var queue = newAsyncQueue[int]()
  var arr1 = @[1, 2, 3, 4, 5]
  var arr2 = @[2, 2, 2, 2, 2]
  var arr3 = @[1, 2, 3, 4, 5]
  queue.putNoWait(1)
  queue.putNoWait(2)
  queue.putNoWait(3)
  queue.putNoWait(4)
  queue.putNoWait(5)
  var index = 0
  for item in queue.items():
    result = (item == arr1[index])
    inc(index)

  if not result: return

  queue[0] = 2

  result = (queue[0] == 2)

  if not result: return

  for item in queue.mitems():
    item = 2

  index = 0
  for item in queue.items():
    result = (item == arr2[index])
    inc(index)

  if not result: return

  queue[0] = 1
  queue[1] = 2
  queue[2] = 3
  queue[3] = 4
  queue[^1] = 5

  for i, item in queue.pairs():
    result = (item == arr3[i])

proc test8(): bool =
  var q0 = newAsyncQueue[int]()
  q0.putNoWait(1)
  q0.putNoWait(2)
  q0.putNoWait(3)
  q0.putNoWait(4)
  q0.putNoWait(5)
  result = ($q0 == "[1, 2, 3, 4, 5]")
  if not result: return

  var q1 = newAsyncQueue[string]()
  q1.putNoWait("1")
  q1.putNoWait("2")
  q1.putNoWait("3")
  q1.putNoWait("4")
  q1.putNoWait("5")
  result = ($q1 == "[\"1\", \"2\", \"3\", \"4\", \"5\"]")

proc test9(): bool =
  var q = newAsyncQueue[int]()
  q.putNoWait(1)
  q.putNoWait(2)
  q.putNoWait(3)
  q.putNoWait(4)
  q.putNoWait(5)
  result = (5 in q and not(6 in q))

when isMainModule:
  suite "Asynchronous sync primitives test suite":
    test "AsyncLock() behavior test":
      check test1() == "0123456789"
    test "AsyncEvent() behavior test":
      check test2() == "0123456789"
    test "AsyncQueue() behavior test":
      check test3() == 3000
    test "AsyncQueue() many iterations test":
      check test4() == 0
    test "AsyncQueue() addLast/addFirst/popLast/popFirst test":
      check test5() == 1100
    test "AsyncQueue() clear test":
      check test6() == true
    test "AsyncQueue() iterators/assignments test":
      check test7() == true
    test "AsyncQueue() representation test":
      check test8() == true
    test "AsyncQueue() contains test":
      check test9() == true
