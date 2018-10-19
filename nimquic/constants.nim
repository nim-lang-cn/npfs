# Simple time constants.
const kNumSecondsPerMinute: uint64 = 60
const kNumSecondsPerHour: uint64 = kNumSecondsPerMinute * 60
const kNumSecondsPerWeek: uint64 = kNumSecondsPerHour * 24 * 7
const kNumMicrosPerMilli: uint64 = 1000
const kNumMicrosPerSecond: uint64 = 1000 * 1000

# Default number of connections for N-connection emulation.
const kDefaultNumConnections: uint32 = 2
# Default initial maximum size in bytes of a QUIC packet.
const kDefaultMaxPacketSize: QuicByteCount = 1350
# Default initial maximum size in bytes of a QUIC packet for servers.
const kDefaultServerMaxPacketSize: QuicByteCount = 1000
# The maximum packet size of any QUIC packet, based on ethernet's max size,
# minus the IP and UDP headers. IPv6 has a 40 byte header, UDP adds an
# additional 8 bytes.  This is a total overhead of 48 bytes.  Ethernet's
# max packet size is 1500 bytes,  1500 - 48 = 1452.
const kMaxPacketSize: QuicByteCount = 1452
# ETH_MAX_MTU - MAX(sizeof(iphdr), sizeof(ip6_hdr)) - sizeof(udphdr).
const kMaxGsoPacketSize: QuicByteCount = 65535 - 40 - 8
# Default maximum packet size used in the Linux TCP implementation.
# Used in QUIC for congestion window computations in bytes.
const kDefaultTCPMSS: QuicByteCount = 1460
const kMaxSegmentSize: QuicByteCount = kDefaultTCPMSS

# We match SPDY's use of 32 (since we'd compete with SPDY).
const kInitialCongestionWindow: QuicPacketCount = 32

# Minimum size of initial flow control window, for both stream and session.
const kMinimumFlowControlSendWindow: uint32_t = 16 * 1024  # 16 KB

# Maximum flow control receive window limits for connection and stream.
const kStreamReceiveWindowLimit: QuicByteCount = 16 * 1024 * 1024   # 16 MB
const kSessionReceiveWindowLimit: QuicByteCount = 24 * 1024 * 1024  # 24 MB

# Default limit on the size of uncompressed headers.
const kDefaultMaxUncompressedHeaderSize: QuicByteCount = 16 * 1024  # 16 KB

# Minimum size of the CWND, in packets, when doing bandwidth resumption.
const kMinCongestionWindowForBandwidthResumption: QuicPacketCount = 10

# Maximum number of tracked packets.
const kMaxTrackedPackets: QuicPacketCount = 10000

# Default size of the socket receive buffer in bytes.
const kDefaultSocketReceiveBuffer: QuicByteCount = 1024 * 1024

# Don't allow a client to suggest an RTT shorter than 10ms.
const kMinInitialRoundTripTimeUs: uint32_t = 10 * kNumMicrosPerMilli

# Don't allow a client to suggest an RTT longer than 15 seconds.
const kMaxInitialRoundTripTimeUs: uint32_t = 15 * kNumMicrosPerSecond

# Maximum number of open streams per connection.
const kDefaultMaxStreamsPerConnection: uint = 100

# Number of bytes reserved for public flags in the packet header.
const kPublicFlagsSize: uint = 1
# Number of bytes reserved for version number in the packet header.
const kQuicVersionSize: uint = 4
# Number of bytes reserved for path id in the packet header.
const kQuicPathIdSize: uint = 1
# Number of bytes reserved for private flags in the packet header.
const kPrivateFlagsSize: uint = 1

# Signifies that the QuicPacket will contain version of the protocol.
const kIncludeVersion: bool = true
# Signifies that the QuicPacket will contain path id.
const kIncludePathId: bool = true
# Signifies that the QuicPacket will include a diversification nonce.
const kIncludeDiversificationNonce: bool = true

# Stream ID is reserved to denote an invalid ID.
const kInvalidStreamId: QuicStreamId = 0

# Reserved ID for the crypto stream.
const kCryptoStreamId: QuicStreamId = 1

# Reserved ID for the headers stream.
const kHeadersStreamId: QuicStreamId = 3

# Header key used to identify final offset on data stream when sending HTTP/2
# trailing headers over QUIC.
QUIC_EXPORT_PRIVATE extern const char* const kFinalOffsetHeaderKey

# Default maximum delayed ack time, in ms.
# Uses a 25ms delayed ack timer. Helps with better signaling
# in low-bandwidth (< ~384 kbps), where an ack is sent per packet.
const kDefaultDelayedAckTimeMs: int64 = 25

# Minimum tail loss probe time in ms.
const kMinTailLossProbeTimeoutMs: int64 = 10

# The timeout before the handshake succeeds.
const kInitialIdleTimeoutSecs: int64 = 5
# The default idle timeout.
const kDefaultIdleTimeoutSecs: int64 = 30
# The maximum idle timeout that can be negotiated.
const kMaximumIdleTimeoutSecs: int64 = 60 * 10  # 10 minutes.
# The default timeout for a connection until the crypto handshake succeeds.
const kMaxTimeForCryptoHandshakeSecs: int64 = 10  # 10 secs.

# Default limit on the number of undecryptable packets the connection buffers
# before the CHLO/SHLO arrive.
const kDefaultMaxUndecryptablePackets: uint = 10

# Default ping timeout.
const kPingTimeoutSecs: int64 = 15  # 15 secs.

# Minimum number of RTTs between Server Config Updates (SCUP) sent to client.
const kMinIntervalBetweenServerConfigUpdatesRTTs: int = 10

# Minimum time between Server Config Updates (SCUP) sent to client.
const kMinIntervalBetweenServerConfigUpdatesMs: int = 1000

# Minimum number of packets between Server Config Updates (SCUP).
const kMinPacketsBetweenServerConfigUpdates: int = 100

# The number of open streams that a server will accept is set to be slightly
# larger than the negotiated limit. Immediately closing the connection if the
# client opens slightly too many streams is not ideal: the client may have sent
# a FIN that was lost, and simultaneously opened a new stream. The number of
# streams a server accepts is a fixed increment over the negotiated limit, or a
# percentage increase, whichever is larger.
const kMaxStreamsMultiplier: float = 1.1
const kMaxStreamsMinimumIncrement: int = 10

# Available streams are ones with IDs less than the highest stream that has
# been opened which have neither been opened or reset. The limit on the number
# of available streams is 10 times the limit on the number of open streams.
const kMaxAvailableStreamsMultiplier: int = 10

# Track the number of promises that are not yet claimed by a
# corresponding get.  This must be smaller than
# kMaxAvailableStreamsMultiplier, because RST on a promised stream my
# create available streams entries.
const kMaxPromisedStreamsMultiplier: int = kMaxAvailableStreamsMultiplier - 1

# TCP RFC calls for 1 second RTO however Linux differs from this default and
# define the minimum RTO to 200ms, we will use the same until we have data to
# support a higher or lower value.
const kMinRetransmissionTimeMs: int64 = 200
# The delayed ack time must not be greater than half the min RTO.
static:
    (kDefaultDelayedAckTimeMs <= kMinRetransmissionTimeMs / 2,
              "Delayed ack time must be less than or equal half the MinRTO")

# We define an unsigned 16-bit floating point value, inspired by IEEE floats
# (http:#en.wikipedia.org/wiki/Half_precision_floating-point_format),
# with 5-bit exponent (bias 1), 11-bit mantissa (effective 12 with hidden
# bit) and denormals, but without signs, transfinites or fractions. Wire format
# 16 bits (little-endian byte order) are split into exponent (high 5) and
# mantissa (low 11) and decoded as:
#   uint64 value
#   if (exponent == 0) value = mantissa
#   else value = (mantissa | 1 << 11) << (exponent - 1)
const kUFloat16ExponentBits: int = 5
const kUFloat16MaxExponent: int = (1 << kUFloat16ExponentBits) - 2     # 30
const kUFloat16MantissaBits: int = 16 - kUFloat16ExponentBits          # 11
const kUFloat16MantissaEffectiveBits: int = kUFloat16MantissaBits + 1  # 12
const kUFloat16MaxValue: uint64 =  # 0x3FFC0000000
    ((UINT64_C(1) << kUFloat16MantissaEffectiveBits) - 1)
    << kUFloat16MaxExponent

# kDiversificationNonceSize is the size, in bytes, of the nonce that a server
# may set in the packet header to ensure that its INITIAL keys are not
# duplicated.
const kDiversificationNonceSize: uint = 32

# The largest gap in packets we'll accept without closing the connection.
# This will likely have to be tuned.
const kMaxPacketGap: QuicPacketNumber = 5000

# The maximum number of random padding bytes to add.
const kMaxNumRandomPaddingBytes: QuicByteCount = 256

# The size of stream send buffer data slice size in bytes. A data slice is
# piece of stream data stored in contiguous memory, and a stream frame can
# contain data from multiple data slices.
const kQuicStreamSendBufferSliceSize: QuicByteCount = 4 * 1024

# For When using Random Initial Packet Numbers, they can start
# anyplace in the range 1...((2^31)-1) or 0x7fffffff
const kMaxRandomInitialPacketNumber: QuicPacketNumber = 0x7fffffff

# Used to represent an invalid or no control frame id.
const kInvalidControlFrameId: QuicControlFrameId = 0

# The max length a stream can have.
const kMaxStreamLength: QuicByteCount = (UINT64_C(1) << 62) - 1

# The max value that can be encoded using IETF Var Ints.
const kMaxIetfVarInt: uint64 = UINT64_C(0x3fffffffffffffff)

# The maximum stream id value that is supported - (2^32)-1
const kMaxQuicStreamId: QuicStreamId = 0xffffffff

# Number of bytes reserved for packet header type.
const kPacketHeaderTypeSize: uint = 1

# Number of bytes reserved for connection ID length.
const kConnectionIdLengthSize: uint = 1

# Length of an encoded variable length connection ID, in bytes.
const kQuicConnectionIdLength: uint = 8

# Minimum length of random bytes in IETF stateless reset packet.
const kMinRandomBytesLengthInStatelessReset: uint = 20

# Maximum length allowed for the token in a NEW_TOKEN frame.
const kMaxNewTokenTokenLength: uint = 0xffff
