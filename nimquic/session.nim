import net, winlean, deques, nativeSockets, os
include transport_parameters

type QuicServerId* = ref object
    host*: string
    port*: uint16
    privacyModeEnabled*: bool

type SocketTag* = ref object

type QuicSessionKey* = ref object
    serverId: QuicServerId
    socketTag: SocketTag


type SessionRunner* = ref object

proc onHandshakeComplete*(s: SessionRunner) = discard
proc retireConnectionID*(id: uint64) = discard
proc removeConnectionID*(id: uint64) = discard

type Config* = ref object
    Versions: seq[uint64]
    ConnectionIDLength: int
    HandshakeTimeout: uint64
    IdleTimeout: uint64
    MaxReceiveStreamFlowControlWindow: uint64
    MaxReceiveConnectionFlowControlWindow:uint64
    MaxIncomingStreams:int
    MaxIncomingUniStreams:int
    keepalive: bool

type Cookie* = ref object

proc AcceptCookie*(config: Config, clientAddr: SockAddr, cookie:Cookie):bool = discard

type streamManager* = ref object

type Stream* = ref object
proc GetOrOpenSendStream*(sm: streamManager, streamId: uint64) = discard
proc GetOrOpenReceiveStream*(sm: streamManager, streamId: uint64) = discard
proc OpenStream*(sm: streamManager, stream: Stream) = discard
proc OpenUniStream*(sm: streamManager, stream: Stream) = discard
proc OpenStreamSync*(sm: streamManager, stream: Stream) = discard
proc OpenUniStreamSync*(sm: streamManager, stream: Stream) = discard
proc AcceptStream*(sm: streamManager, stream: Stream) = discard
proc AcceptUniStream*(sm: streamManager, stream: Stream) = discard
proc DeleteStream*(sm: streamManager, stream: Stream) = discard
proc UpdateLimits*(sm: streamManager, stream: Stream) = discard
proc HandleMaxStreamsFrame*(sm: streamManager, stream: Stream) = discard
proc CloseWithError*(sm: streamManager, stream: Stream) = discard


type RTTStats* = ref object
    minRTT: uint64
    latestRTT: uint64
    smoothedRTT: uint64
    meanDeviation: uint64
    

type cryptoStreamManager = ref object 

type SentPacketHandler = ref object
type ReceivedPacketHandler = ref object
type framer = ref object

type ConnectionFlowController* = ref object

type unpacker* = ref object
type packer* = ref object
type cryptoStreamHandler* = ref object
type receivedPacket* = ref object
    remoteAddr: SockAddr


type packedPacket = ref object
type Session*[T] = ref object
    sessionRunner*: SessionRunner
    destConnID*: uint64
    srcConnID*: uint64
    perspective*: int
    version*: uint32
    config*: ptr Config
    conn*: ptr Socket
    streamsMap*: streamManager
    rttStats*: ptr RTTStats
    cryptoStreamManager*: cryptoStreamManager
    sentPacketHandler*: ptr SentPacketHandler
    receivedPacketHandler*: ptr ReceivedPacketHandler
    framer*: framer
    windowUpdateQueue*: Deque[T]
    connFlowController*: ptr ConnectionFlowController
    unpacker: unpacker
    packer: packer
    cryptoStreamHandler: ptr cryptoStreamHandler
    receivedPackets: Channel[receivedPacket]
    sendingScheduled: Channel[string]
    closed: bool
    closeChan: Channel[string]
    connectionClosePacket*: packedPacket
    packetsReceivedAfterClose*: int
    ctx*: int
    ctxCancel*: int
    undecryptablePackets: seq[receivedPacket]
    clientHelloWritten: Channel[string]
    handshakeCompleteChan: Channel[string]
    handshakeComplete: bool
    receivedFirstPacket: bool
    receivedFirstForwardSecurePacket: bool
    lastRcvdPacketNumber: uint64
    largestRcvdPacketNumber: uint64
    sessionCreationTime: uint64
    lastNetworkActivityTime: uint64
    pacingDeadline: uint64
    peerParams: typeGetter(TransportParameters)
    timer: uint64
    keepAlivePingSent: bool
    logger: uint64



var size = ss.getPosition()
var outs = ss.readAll().cstring
let sockfd = createNativeSocket(Domain.AF_INET, SOCK_DGRAM, IPPROTO_UDP)
defer: sockfd.close()
sockfd.setSockOptInt(SOL_SOCKET, SO_BROADCAST, 1)
var peer = getAddrInfo("192.168.100.224", Port 1234, sockType = SOCK_DGRAM, protocol = IPPROTO_UDP)
if sockfd.connect(peer.ai_addr, peer.ai_addrlen.SockLen) < 0'i32:
    freeAddrInfo(peer)
    raiseOSError(osLastError())
var sent = sockfd.send(outs, cint size, 0) 
if sent < 0'i32:
    raiseOSError(osLastError())
else: 
    echo sent
    
var session = Session[string](conn:sockfd)