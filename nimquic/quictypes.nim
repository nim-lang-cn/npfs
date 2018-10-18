
type  QuicPacketLength = uint16
type  QuicMessageId = uint32 
type  QuicByteCount = uint64
type  QuicConnectionId = uint64
type  QuicPacketCount = uint64
type  QuicPacketNumber = uint64
type  QuicPublicResetNonceProof = uint64
type  QuicStreamOffset = uint64
type DiversificationNonce = array[32, char]
type PacketTimeVector = seq[Table[QuicPacketNumber, QuicTime]]

type  QuicIetfStreamDataLength = uint64
type  QuicIetfStreamId = uint64
type  QuicIetfStreamOffset = uint64

const kQuicPathFrameBufferSize = 8
type QuicPathFrameBuffer = array[kQuicPathFrameBufferSize, uint8]

# Application error code used in the QUIC Stop Sending frame.
type  QuicApplicationErrorCode = uint16

# The connection id sequence number specifies the order that connection
# ids must be used in.
type  QuicConnectionIdSequenceNumber = uint64

# A type for functions which consume data payloads and fins.
type QuicConsumedData = object 
  QuicConsumedData(bytes_consumed: uint, fin_consumed: bool)
  # By default, gtest prints the raw bytes of an object. The bool data
  # member causes this object to have padding bytes, which causes the
  # default gtest object printer to read uninitialize memory. So we need
  # to teach gtest how to print this object.
  QUIC_EXPORT_PRIVATE friend std::ostream& operatorshl(
      std::ostream& os,
      s:QuicConsumedData)
  # How many bytes were consumed.
  bytes_consumed: uint
  # True if an incoming fin was consumed.
  fin_consumed: bool

# QuicAsyncStatus enumerates the possible results of an asynchronous
# operation.
type QuicAsyncStatus = enum
  QUIC_SUCCESS = 0,
  QUIC_FAILURE = 1,
  # QUIC_PENDING results from an operation that will occur asynchronously. When
  # the operation is complete, a callback's |Run| method will be called.
  QUIC_PENDING = 2,

# TODO(wtc): see if WriteStatus can be replaced by QuicAsyncStatus.
type WriteStatus = enum
  WRITE_STATUS_OK,
  WRITE_STATUS_BLOCKED,
  # To make the IsWriteError(WriteStatus) function work properly:
  # - Non-errors MUST be added before WRITE_STATUS_ERROR.
  # - Errors MUST be added after WRITE_STATUS_ERROR.
  WRITE_STATUS_ERROR,
  WRITE_STATUS_MSGOO_BIG,
  WRITE_STATUS_NUM_VALUES,


proc IsWriteError(status: WriteStatus ): bool 
  return status >= WRITE_STATUS_ERROR
}

# A type used to return the result of write calls including either the number
# of bytes written or the error code, depending upon the status.
type QUIC_EXPORT_PRIVATE WriteResult 
  WriteResult(WriteStatus status, int bytes_written_or_error_code)
  WriteResult()

  bool operator==(const WriteResult& other) const 
    if (status != other.status) 
      return false
    }
    switch (status) 
      case WRITE_STATUS_OK:
        return bytes_written == other.bytes_written
      case WRITE_STATUS_BLOCKED:
        return true
      default:
        return error_code == other.error_code
    }
  }

  QUIC_EXPORT_PRIVATE friend std::ostream& operatorshl(std::ostream& os,
                                                      const WriteResult& s)

  WriteStatus status
  union 
    int bytes_written  # only valid when status is WRITE_STATUS_OK
    int error_code     # only valid when status is WRITE_STATUS_ERROR

type TransmissionType = enum
  NOT_RETRANSMISSION,
  FIRSTRANSMISSIONYPE = NOT_RETRANSMISSION,
  HANDSHAKE_RETRANSMISSION,    # Retransmits due to handshake timeouts.
  ALL_UNACKED_RETRANSMISSION,  # Retransmits all unacked packets.
  ALL_INITIAL_RETRANSMISSION,  # Retransmits all initially encrypted packets.
  LOSS_RETRANSMISSION,         # Retransmits due to loss detection.
  RTO_RETRANSMISSION,          # Retransmits due to retransmit time out.
  TLP_RETRANSMISSION,          # Tail loss probes.
  PROBING_RETRANSMISSION,      # Retransmission in order to probe bandwidth.
  LASTRANSMISSIONYPE = PROBING_RETRANSMISSION,


type HasRetransmittableData = enum
  NO_RETRANSMITTABLE_DATA,
  HAS_RETRANSMITTABLE_DATA,

type IsHandshake = enum
  NOT_HANDSHAKE, IS_HANDSHAKE 

type class Perspective = enum
    IS_SERVER, IS_CLIENT 

# Describes whether a ConnectionClose was originated by the peer.
type ConnectionCloseSource = enum 
    FROM_PEER, FROM_SELF 

# Should a connection be closed silently or not.
enum class ConnectionCloseBehavior 
  SILENT_CLOSE,
  SEND_CONNECTION_CLOSE_PACKET,
  SEND_CONNECTION_CLOSE_PACKET_WITH_NO_ACK
}

enum QuicFrameType : uint8 
  # Regular frame types. The values set here cannot change without the
  # introduction of a new QUIC version.
  PADDING_FRAME = 0,
  RST_STREAM_FRAME = 1,
  CONNECTION_CLOSE_FRAME = 2,
  GOAWAY_FRAME = 3,
  WINDOW_UPDATE_FRAME = 4,
  BLOCKED_FRAME = 5,
  STOP_WAITING_FRAME = 6,
  PING_FRAME = 7,

  # STREAM and ACK frames are special frames. They are encoded differently on
  # the wire and their values do not need to be stable.
  STREAM_FRAME,
  ACK_FRAME,
  # The path MTU discovery frame is encoded as a PING frame on the wire.
  MTU_DISCOVERY_FRAME,

  # These are for IETF-specific frames for which there is no mapping
  # from Google QUIC frames. These are valid/allowed if and only if IETF-
  # QUIC has been negotiated. Values are not important, they are not
  # the values that are in the packets (see QuicIetfFrameType, below).
  APPLICATION_CLOSE_FRAME,
  NEW_CONNECTION_ID_FRAME,
  MAX_STREAM_ID_FRAME,
  STREAM_ID_BLOCKED_FRAME,
  PATH_RESPONSE_FRAME,
  PATH_CHALLENGE_FRAME,
  STOP_SENDING_FRAME,
  MESSAGE_FRAME,
  CRYPTO_FRAME,
  NEWOKEN_FRAME,

  NUM_FRAMEYPES

# Ietf frame types. These are defined in the IETF QUIC Specification.
# Explicit values are given in the enum so that we can be sure that
# the symbol will map to the correct stream type.
# All types are defined here, even if we have not yet implmented the
# quic/core/stream/.... stuff needed.
# Note: The protocol specifies that frame types are varint-62 encoded,
# further stating that the shortest encoding must be used.  The current set of
# frame types all have values less than 0x40 (64) so can be encoded in a single
# byte, with the two most significant bits being 0. Thus, the following
# enumerations are valid as both the numeric values of frame types AND their
# encodings.
type QuicIetfFrameType = enum
  IETF_PADDING = 0x00,
  IETF_RST_STREAM = 0x01,
  IETF_CONNECTION_CLOSE = 0x02,
  IETF_APPLICATION_CLOSE = 0x03,
  IETF_MAX_DATA = 0x04,
  IETF_MAX_STREAM_DATA = 0x05,
  IETF_MAX_STREAM_ID = 0x06,
  IETF_PING = 0x07,
  IETF_BLOCKED = 0x08,
  IETF_STREAM_BLOCKED = 0x09,
  IETF_STREAM_ID_BLOCKED = 0x0a,
  IETF_NEW_CONNECTION_ID = 0x0b,
  IETF_STOP_SENDING = 0x0c,
  IETF_ACK = 0x0d,
  IETF_PATH_CHALLENGE = 0x0e,
  IETF_PATH_RESPONSE = 0x0f,
  # the low-3 bits of the stream frame type value are actually flags
  # declaring what parts of the frame are/are-not present, as well as
  # some other control information. The code would then do something
  # along the lines of "if ((frameype & 0xf8) == 0x10)" to determine
  # whether the frame is a stream frame or not, and then examine each
  # bit specifically when/as needed.
  IETF_STREAM = 0x10,
  IETF_CRYPTO = 0x18,
  IETF_NEWOKEN = 0x19,

  # MESSAGE frame type is not yet determined, use 0x2x temporarily to give
  # stream frame some wiggle room.
  IETF_EXTENSION_MESSAGE_NO_LENGTH = 0x20,
  IETF_EXTENSION_MESSAGE = 0x21,
}
# Masks for the bits that indicate the frame is a Stream frame vs the
# bits used as flags.
#define IETF_STREAM_FRAMEYPE_MASK 0xfffffffffffffff8
#define IETF_STREAM_FRAME_FLAG_MASK 0x07
#define IS_IETF_STREAM_FRAME(_stype_) \
  (((_stype_)&IETF_STREAM_FRAMEYPE_MASK) == IETF_STREAM)

# These are the values encoded in the low-order 3 bits of the
# IETF_STREAMx frame type.
#define IETF_STREAM_FRAME_FIN_BIT 0x01
#define IETF_STREAM_FRAME_LEN_BIT 0x02
#define IETF_STREAM_FRAME_OFF_BIT 0x04

type QuicConnectionIdLength = enum
  PACKET_0BYTE_CONNECTION_ID = 0,
  PACKET_8BYTE_CONNECTION_ID = 8

type QuicPacketNumberLength = enum
  PACKET_1BYTE_PACKET_NUMBER = 1,
  PACKET_2BYTE_PACKET_NUMBER = 2,
  PACKET_4BYTE_PACKET_NUMBER = 4,
  # TODO(rch): Remove this when we remove QUIC_VERSION_39.
  PACKET_6BYTE_PACKET_NUMBER = 6,
  PACKET_8BYTE_PACKET_NUMBER = 8

# Used to indicate a QuicSequenceNumberLength using two flag bits.
type QuicPacketNumberLengthFlags = enum
  PACKET_FLAGS_1BYTE_PACKET = 0,           # 00
  PACKET_FLAGS_2BYTE_PACKET = 1,           # 01
  PACKET_FLAGS_4BYTE_PACKET = 1 shl 1,      # 10
  PACKET_FLAGS_8BYTE_PACKET = 1 shl 1 or 1,  # 11


# The public flags are specified in one byte.
type QuicPacketPublicFlags = enum
  PACKET_PUBLIC_FLAGS_NONE = 0,
  # Bit 0: Does the packet header contains version info?
  PACKET_PUBLIC_FLAGS_VERSION = 1 shl 0,
  # Bit 1: Is this packet a public reset packet?
  PACKET_PUBLIC_FLAGS_RST = 1 shl 1,
  # Bit 2: indicates the header includes a nonce.
  PACKET_PUBLIC_FLAGS_NONCE = 1 shl 2,
  # Bit 3: indicates whether a ConnectionID is included.
  PACKET_PUBLIC_FLAGS_0BYTE_CONNECTION_ID = 0,
  PACKET_PUBLIC_FLAGS_8BYTE_CONNECTION_ID = 1 shl 3,
  # QUIC_VERSION_32 and earlier use two bits for an 8 byte
  # connection id.
  PACKET_PUBLIC_FLAGS_8BYTE_CONNECTION_ID_OLD = 1 shl 3 | 1 shl 2,
  # Bits 4 and 5 describe the packet number length as follows:
  # --00----: 1 byte
  # --01----: 2 bytes
  # --10----: 4 bytes
  # --11----: 6 bytes
  PACKET_PUBLIC_FLAGS_1BYTE_PACKET = PACKET_FLAGS_1BYTE_PACKET shl 4,
  PACKET_PUBLIC_FLAGS_2BYTE_PACKET = PACKET_FLAGS_2BYTE_PACKET shl 4,
  PACKET_PUBLIC_FLAGS_4BYTE_PACKET = PACKET_FLAGS_4BYTE_PACKET shl 4,
  PACKET_PUBLIC_FLAGS_6BYTE_PACKET = PACKET_FLAGS_8BYTE_PACKET shl 4,
  # Reserved, unimplemented flags:
  # Bit 7: indicates the presence of a second flags byte.
  PACKET_PUBLIC_FLAGSWO_OR_MORE_BYTES = 1 shl 7,
  # All bits set (bits 6 and 7 are not currently used): 00111111
  PACKET_PUBLIC_FLAGS_MAX = (1 shl 6) - 1,

# The private flags are specified in one byte.
type QuicPacketPrivateFlags = enum
  PACKET_PRIVATE_FLAGS_NONE = 0,
  # Bit 0: Does this packet contain an entropy bit?
  PACKET_PRIVATE_FLAGS_ENTROPY = 1 shl 0,
  # (bits 1-7 are not used): 00000001
  PACKET_PRIVATE_FLAGS_MAX = (1 shl 1) - 1

# Defines for all types of congestion control algorithms that can be used in
# QUIC. Note that this is separate from the congestion feedback type -
# some congestion control algorithms may use the same feedback type
# (Reno and Cubic are the classic example for that).
type CongestionControlType = enum 
    kCubicBytes, kRenoBytes, kBBR, kPCC 

type LossDetectionType = enum 
  kNack,          # Used to mimic TCP's loss detection.
  kTime,          # Time based loss detection.
  kAdaptiveTime,  # Adaptive time based loss detection.
  kLazyFack,      # Nack based but with FACK disabled for the first ack.
# EncryptionLevel enumerates the stages of encryption that a QUIC connection
# progresses through. When retransmitting a packet, the encryption level needs
# to be specified so that it is retransmitted at a level which the peer can
# understand.
type EncryptionLevel = enum 
  ENCRYPTION_NONE = 0,
  ENCRYPTION_INITIAL = 1,
  ENCRYPTION_FORWARD_SECURE = 2,
  NUM_ENCRYPTION_LEVELS,

type AddressChangeType = enum 
  # IP address and port remain unchanged.
  NO_CHANGE,
  # Port changed, but IP address remains unchanged.
  PORT_CHANGE,
  # IPv4 address changed, but within the /24 subnet (port may have changed.)
  IPV4_SUBNET_CHANGE,
  # IPv4 address changed, excluding /24 subnet change (port may have changed.)
  IPV4O_IPV4_CHANGE,
  # IP address change from an IPv4 to an IPv6 address (port may have changed.)
  IPV4O_IPV6_CHANGE,
  # IP address change from an IPv6 to an IPv4 address (port may have changed.)
  IPV6O_IPV4_CHANGE,
  # IP address change from an IPv6 to an IPv6 address (port may have changed.)
  IPV6O_IPV6_CHANGE,

type StreamSendingState = enum
  # Sender has more data to send on this stream.
  NO_FIN,
  # Sender is done sending on this stream.
  FIN,
  # Sender is done sending on this stream and random padding needs to be
  # appended after all stream frames.
  FIN_AND_PADDING,

type SentPacketState = enum
  # The packet has been sent and waiting to be acked.
  OUTSTANDING,
  FIRST_PACKET_STATE = OUTSTANDING,
  # The packet was never sent.
  NEVER_SENT,
  # The packet has been acked.
  ACKED,
  # This packet is not expected to be acked.
  UNACKABLE,
  # States below are corresponding to retransmission types in TransmissionType.
  # This packet has been retransmitted when retransmission timer fires in
  # HANDSHAKE mode.
  HANDSHAKE_RETRANSMITTED,
  # This packet is considered as lost, this is used for LOST_RETRANSMISSION.
  LOST,
  # This packet has been retransmitted when TLP fires.
  TLP_RETRANSMITTED,
  # This packet has been retransmitted when RTO fires.
  RTO_RETRANSMITTED,
  # This packet has been retransmitted for probing purpose.
  PROBE_RETRANSMITTED,
  LAST_PACKET_STATE = PROBE_RETRANSMITTED,

type PacketHeaderFormat = enum
  IETF_QUIC_LONG_HEADER_PACKET,
  IETF_QUIC_SHORT_HEADER_PACKET,
  GOOGLE_QUIC_PACKET,

# Information about a newly acknowledged packet.
type AckedPacket* = object
  packet_number:QuicPacketNumber
  # Number of bytes sent in the packet that was acknowledged.
   bytes_acked:QuicPacketLength
  # The time |packet_number| was received by the peer, according to the
  # optional timestamp the peer included in the ACK frame which acknowledged
  # |packet_number|. Zero if no timestamp was available for this packet.
   receiveimestamp:QuicTime

# A vector of acked packets.
type  AckedPacketVector = seq[AckedPacket]

# Information about a newly lost packet.
type LostPacket = object
    packet_number: QuicPacketNumber
    bytes_lost : QuicPacketLength

# A vector of lost packets.
type LostPacketVector = seq[LostPacket]

type QuicIetfTransportErrorCodes = enum
  NO_IETF_QUIC_ERROR = 0x0,
  INTERNAL_ERROR = 0x1,
  SERVER_BUSY_ERROR = 0x2,
  FLOW_CONTROL_ERROR = 0x3,
  STREAM_ID_ERROR = 0x4,
  STREAM_STATE_ERROR = 0x5,
  FINAL_OFFSET_ERROR = 0x6,
  FRAME_ENCODING_ERROR = 0x7,
  TRANSPORT_PARAMETER_ERROR = 0x8,
  VERSION_NEGOTIATION_ERROR = 0x9,
  PROTOCOL_VIOLATION = 0xA,
  INVALID_MIGRATION = 0xC,
  FRAME_ERROR_base = 0x100,  # add frame type to this base

type QuicIetfPacketHeaderForm = enum
  # Long header is used for packets that are sent prior to the completion of
  # version negotiation and establishment of 1-RTT keys.
  LONG_HEADER,
  # Short header is used after the version and 1-RTT keys are negotiated.
  SHORT_HEADER,

# Used in long header to explicitly indicate the packet type.
type QuicLongHeaderType = enum
  VERSION_NEGOTIATION = 0,  # Value does not matter.
  ZERO_RTT_PROTECTED = 0x7C,
  HANDSHAKE = 0x7D,
  RETRY = 0x7E,
  INITIAL = 0x7F,
  INVALID_PACKETYPE,

# Used in short header to determine the size of packet number field.
type QuicShortHeaderType = enum
  SHORT_HEADER_1_BYTE_PACKET_NUMBER = 0,
  SHORT_HEADER_2_BYTE_PACKET_NUMBER = 1,
  SHORT_HEADER_4_BYTE_PACKET_NUMBER = 2,

type QuicPacketHeaderTypeFlags = enum 
  # Bit 2: Reserved for experimentation for short header.
  FLAGS_EXPERIMENTATION_BIT = 1 shl 2,
  # Bit 3: Google QUIC Demultiplexing bit, the short header always sets this
  # bit to 0, allowing to distinguish Google QUIC packets from short header
  # packets.
  FLAGS_DEMULTIPLEXING_BIT = 1 shl 3,
  # Bits 4 and 5: Reserved bits for short header.
  FLAGS_SHORT_HEADER_RESERVED_1 = 1 shl 4,
  FLAGS_SHORT_HEADER_RESERVED_2 = 1 shl 5,
  # Bit 6: Indicates the key phase, which allows the receipt of the packet to
  # identify the packet protection keys that are used to protect the packet.
  FLAGS_KEY_PHASE_BIT = 1 shl 6,
  # Bit 7: Indicates the header is long or short header.
  FLAGS_LONG_HEADER = 1 shl 7,

type MessageStatus = enum
  MESSAGE_STATUS_SUCCESS,
  MESSAGE_STATUS_ENCRYPTION_NOT_ESTABLISHED,  # Failed to send message because
                                              # encryption is not established
                                              # yet.
  MESSAGE_STATUS_UNSUPPORTED,  # Failed to send message because MESSAGE frame
                               # is not supported by the connection.
  MESSAGE_STATUS_BLOCKED,      # Failed to send message because connection is
                           # congestion control blocked or underlying socket is
                           # write blocked.
  MESSAGE_STATUSOO_LARGE,  # Failed to send message because the message is
                             # too large to fit into a single packet.
  MESSAGE_STATUS_INTERNAL_ERROR,  # Failed to send message because connection
                                  # reaches an invalid state.

# Used to return the result of SendMessage calls
type MessageResult = object
  MessageStatus status
  # Only valid when status is MESSAGE_STATUS_SUCCESS.
  QuicMessageId message_id

type WriteStreamDataResult = enum
  WRITE_SUCCESS,
  STREAM_MISSING,  # Trying to write data of a nonexistent stream (e.g.
                   # closed).
  WRITE_FAILED,    # Trying to write nonexistent data of a stream

type StreamType = enum
  # Bidirectional streams allow for data to be sent in both directions.
  BIDIRECTIONAL,
  # Unidirectional streams carry data in one direction only.
  WRITE_UNIDIRECTIONAL,
  READ_UNIDIRECTIONAL,