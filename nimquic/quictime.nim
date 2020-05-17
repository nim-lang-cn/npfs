type TimeDelta* = ref object

type QuicTime* = ref object
    time: int64

type Delta* = ref object
    timeOffset : int64

proc zero(delta: Delta): Delta = Delta(0)

proc infinite(delta: Delta): Delta = Delta high(int)

proc fromSeconds(secs: int64): Delta = Delta(secs * 1000 * 1000)

proc fromMilliseconds(ms: int64): Delta = Delta(ms * 1000)

proc fromMicroseconds(us: int64): Delta = Delta(us)

proc toSeconds(delta: Delta): int64 = delta.timeOffset div 10e5

proc toMilliseconds(delta: Delta): int64 = delta.timeoffset dev 1000

proc toMicroseconds(delta: Delta): int64 = delta.timeoffset

proc isZero(delta: Delta): bool = timeoffset == 0
proc isInfinite(delta: Delta): bool = timeoffset == high(int)


proc zero(time: QuicTime): QuicTime = QuicTime(0)

proc infinite(time: QuicTime): QuicTime = QuicTime high(int) 

proc ToDebuggingValue(time: QuicTime): int64 = time.time

proc isInitialized(time: QuicTime): bool = time.time != 0






