type EpollCallbackInterface* = object of RootObj

proc onRegistration(eci: EpollCallbackInterface, eps: epollServer, fd: int,
        eventMask: int) = discard

proc onModification(eci: EpollCallbackInterface, fd: int, eventMask: int) = discard

proc onEvent(eci: EpollCallbackInterface, fd: int, event: EpollEvent) = discard

proc onUnregistration(eci: EpollCallbackInterface, fd: int, replaced: bool) = discard

proc onShutDown(eci: EpollCallbackInterface, eps: ptr EpollServer, fd: int) = discard

proc name(eci: EpollCallbackInterface): string = discard

type AlarmCBMap = seq[ptr AlarmCB]

type EpollServer* = object
    epollFD*: int
    cbMap*: FDToCBMap
    allAlarms*: AlarmCBMap
    alarmMap*: timeToAlarmCBMap
    timeoutInus*: int64
    recordedNowInus*: int64
    alarmsReregisteredAndShouldBeSkipped*: AlarmCBMap
    readyList*: LIST_HEAD(ReadyList, CBAndEventMask)
    tmpList*: LIST_HEAD(TmpList, CBAndEventMask)
    readyListSize*: int
    eventsSize*: int
    events*: array[256, EpollEvent]
    wakeCB*: ptr ReadPipeCallback
    readFd*: int
    writeFd*: int
    inWaitForEventsAndExecuteCallbacks*: bool
    inShutDown*: bool

proc registerFD(eps: EpollServer, fd: int, cb: ptr CB, eventMask: int) = discard

proc registerFDForWrite(eps: EpollServer, fd: int, cb: ptr CB) = discard

proc registerFDForReadWrite(eps: EpollServer, fd: int, cb: ptr CB) = discard

proc registerFDForRead(eps: EpollServer, fd: int, cb: ptr CB) = discard

proc unRegisterFD(eps: EpollServer, fd: int) = discard

proc modifyCallback(eps: EpollServer, fd: int, eventMask: int) = discard

proc stopRead(eps: EpollServer, fd: int) = discard

proc startRead(eps: EpollServer, fd: int) = discard

proc stopWrite(eps: EpollServer, fd: int) = discard

proc startWrite(eps: EpollServer, fd: int) = discard

proc handleEvent(eps: EpollServer, fd: int, eventMask: int) = discard

proc waitForEventsAndExecutableCallbacks(eps: EpollServer) = discard

proc setFDRead(eps: EpollServer, fd: int, eventsToFake: int) = discard

proc setFDNotReady(eps: EpollServer, fd: int) = discard

proc isFDReady(eps: EpollServer, fd: int) = discard

proc readyListSize(eps: EpollServer): uint = readyListSize

proc verifyReadyList(eps: EpollServer) = discard

proc registerAlarm(eps: EpollServer, timeoutTimeInus: int64, ac: ptr AlarmCB) = discard

proc registerAlarmApproximateDelta(eps: EpollServer, deltaInus: int64,
        ac: ptr AlarmCB) =
    registerAlarm(ApproximateNowInUsec() + deltaInus, ac)

proc unRegisterAlarm(eps: EpollServer, iteratorToken: AlarmRegToken) = discard

proc numFDRegistered(eps: EpollServer): int = discard

proc wake(eps: EpollServer) = discard

proc nowInUsec(eps: EpollServer): int64 = discard

proc approximateNowInUsec(eps: EpollServer): int64 = discard

proc eventMaskToString(eventMask: int): string = discard

proc logStateOnCrash(eps: EpollServer) = discard

proc setTimeoutInus(eps: EpollServer, timeoutInus: int64) = discard

proc timeoutInus(eps: EpollServer): int = timeoutInus

proc inShutDown(eps: EpollServer): bool = inShutDown

proc setNonblocking(eps: EpollServer) = discard

proc epollWaitImpl(eps: EpollServer,
                   epfd: int,
                   events: EpollEvent,
                   maxEvents: int,
                   timeoutInms: int): int = discard

type CBAndEventMask* = object
    cb*: EpollCallbackInterface
    entry*: LIST_ENTRY(CBAndEventMask)
    fd*: int
    eventMask: int
    eventsAsserted: int
    eventsToFake: int
    inUse: bool

type CBAndEventMaskHash* = object

type FDToCBMap = set[CBAndEventMask]

proc delFD(eps: EpollServer, fd: int) = discard

proc addFD(eps: EpollServer, fd: int, eventMask: int) = discard

proc modFD(eps: EpollServer, fd: int, eventMask: int) = discard

proc modifyFD(eps: EpollServer, fd: int, removeEvent: int, addEvent: int) = discard

proc waitForEventsAndCallHandleEvents(eps: EpollServer, timeoutInus: int64,
        events: seq[EpollEvent])

proc callReadyListCallbacks(eps: EpollServer) = discard

proc addToReadyList(eps: EpollServer, cbAndMask: ptr CBAndEventMask) = discard

proc removeFromReadyList(eps: EpollServer, cbAndMask: ptr CBAndEventMask) = discard

proc callAndReregisterAlarmEvents(eps: EpollServer) = discard

proc cleanupFDToCBMap(eps: EpollServer) = discard

proc cleanupTimeToAlarmCBMap(eps: EpollServer) = discard

type EpollAlarmCallbackInterface* = object of RootObj

proc onAlarm*(eci: EpollAlarmCallbackInterface): int64 = discard

proc onRegistration*(eci: EpollAlarmCallbackInterface, token: alarmRegToken,
        eps: EpollServer) = discard

proc onUnregistration(eci: EpollAlarmCallbackInterface) = discard

proc onShutDown(eps: EpollServer) = discard

type EpollAlarm* = object of EpollAlarmCallbackInterface
    token*: AlarmRegToken
    eps*: EpollServer
    registered*: bool

proc unregisterIfRegistered(alarm: EpollAlarm) = discard

proc registered(alarm: EpollAlarm): bool = registered

proc eps*(alarm: ptr EpollAlarm): ptr EpollServer = eps
