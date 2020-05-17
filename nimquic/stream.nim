import tables, hostportpair, log

type State* = enum
    STATE_NONE,
    STATE_HANDLE_PROMISE,
    STATE_HANDLE_PROMISE_COMPLETE,
    STATE_REQUEST_STREAM,
    STATE_REQUEST_STREAM_COMPLETE,
    STATE_SET_REQUEST_PRIORITY,
    STATE_SEND_HEADERS,
    STATE_SEND_HEADERS_COMPLETE,
    STATE_READ_REQUEST_BODY,
    STATE_READ_REQUEST_BODY_COMPLETE,
    STATE_SEND_BODY,
    STATE_SEND_BODY_COMPLETE,
    STATE_OPEN

type CreateSessionFailure* = enum
    CREATION_ERROR_CONNECTING_SOCKET,
    CREATION_ERROR_SETTING_RECEIVE_BUFFER,
    CREATION_ERROR_SETTING_SEND_BUFFER,
    CREATION_ERROR_SETTING_DO_NOT_FRAGMENT,
    CREATION_ERROR_MAX

type InitialRttEstimateSource* = enum
    INITIAL_RTT_DEFAULT,
    INITIAL_RTT_CACHED,
    INITIAL_RTT_2G,
    INITIAL_RTT_3G,
    INITIAL_RTT_SOURCE_MAX

type QuicPlatformNotification* = enum
  NETWORK_CONNECTED,
  NETWORK_MADE_DEFAULT,
  NETWORK_DISCONNECTED,
  NETWORK_SOON_TO_DISCONNECT,
  NETWORK_IP_ADDRESS_CHANGED,
  NETWORK_NOTIFICATION_MAX

const kQuicSessionMaxRecvWindowSize: int32 = 15 * 1024 * 1024
const kQuicStreamMaxRecvWindowSize: int32 = 6 * 1024 * 1024
const kQuicSocketReceiveBufferSize = 1024 * 1024
const kMaxUndecryptablePackets = 100

type Stream* = ref object

type Value* = ref object


proc NetLogQuicStreamFactoryJobCallback(serverId : QuicServerId, captureMode: NetLogCaptureMode): TableRef[string,string] = 
    result = initTable[string, string]()
    result["server_id"] = "https://" & hostForURL serverId & ":" serverId.port

proc NetLogQuicConnectionMigrationTriggerCallback(trigger: string, captureMode: NetLogCaptureMode): TableRef[string,string] =
    result = initTable[string, string]()
    result["trigger"] = trigger

type ScopedConnectionMigrationEventLog* = ref object
    netLog : NetLogWithSource

type UMA_HISTOGRAM_ENUMERATION* = ref object
    space: string
type UMA_HISTOGRAM_BOOLEAN* = ref object

proc histogramCreateSessionFailure*(error: CreateSessionFailure) = discard
    UMA_HISTOGRAM_ENUMERATION("Net.QuicSession.CreationError", error, CREATION_ERROR_MAX)

proc logPlatformNotificationInHistogram*(notification: QuicPlatformNotification) = discard
    UMA_HISTOGRAM_ENUMERATION("Net.QuicSession.PlatformNotification", NETWORK_NOTIFICATION_MAX

proc logStaleHostRacing*(used: bool) = 
    UMA_HISTOGRAM_BOOLEAN("Net.QuicSession.StaleHostRacing", used)

proc setInitialRttEstimate*(estimate: TimeDelta, 
                           source: InitialRttEstimateSource, 
                           config: QuicConfig) = 
    UMA_HISTOGRAM_ENUMERATION("Net.QuicSession.InitialRttEsitmateSource", source,
                              INITIAL_RTT_SOURCE_MAX)
    