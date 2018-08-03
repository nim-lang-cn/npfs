#              Asyncdispatch2 Test Suite
#                 (c) Copyright 2018
#         Status Research & Development GmbH
#
#              Licensed under either of
#  Apache License, version 2.0, (LICENSE-APACHEv2)
#              MIT license (LICENSE-MIT)

import unittest, strutils
import ../asyncdispatch2

when not defined(windows):
  import posix

  var signalCounter = 0

  proc signalProc(udata: pointer) =
    var cdata = cast[ptr CompletionData](udata)
    signalCounter = cast[int](cdata.udata)
    removeSignal(int(cdata.fd))

  proc asyncProc() {.async.} =
    await sleepAsync(500)

  proc test(signal, value: int): bool =
    discard addSignal(signal, signalProc, cast[pointer](value))
    var fut = asyncProc()
    discard posix.kill(posix.getpid(), cint(signal))
    waitFor(fut)
    signalCounter == value

else:
  const
    SIGINT = 0
    SIGTERM = 0
  proc test(signal, value: int): bool = true

when isMainModule:
  suite "Signal handling test suite":
    test "SIGINT test":
      check test(SIGINT, 31337) == true
    test "SIGTERM test":
      check test(SIGTERM, 65537) == true
