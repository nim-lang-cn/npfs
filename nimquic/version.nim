type QuicTransportVersion = enum
    QUIC_VERSION_UNSUPPORTED = 0,
    # Version 1 was the first version of QUIC that supported versioning.
    # Version 2 decoupled versioning of non-cryptographic parameters from the
    #           SCFG.
    # Version 3 moved public flags into the beginning of the packet.
    # Version 4 added support for variable-length connection IDs.
    # Version 5 made specifying FEC groups optional.
    # Version 6 introduced variable-length packet numbers.
    # Version 7 introduced a lower-overhead encoding for stream frames.
    # Version 8 made salt length equal to digest length for the RSA-PSS
    #           signatures.
    # Version 9 added stream priority.
    # Version 10 redid the frame type numbering.
    # Version 11 reduced the length of null encryption authentication tag
    #            from 16 to 12 bytes.
    # Version 12 made the sequence numbers in the ACK frames variable-sized.
    # Version 13 added the dedicated header stream.
    # Version 14 added byte_offset to RST_STREAM frame.
    # Version 15 added a list of packets recovered using FEC to the ACK frame.
    # Version 16 added STOP_WAITING frame.
    # Version 17 added per-stream flow control.
    # Version 18 added PING frame.
    # Version 19 added connection-level flow control
    # Version 20 allowed to set stream- and connection-level flow control windows
    #            to different values.
    # Version 21 made header and crypto streams flow-controlled.
    # Version 22 added support for SCUP (server config update) messages.
    # Version 23 added timestamps into the ACK frame.
    # Version 24 added SPDY/4 header compression.
    # Version 25 added support for SPDY/4 header keys and removed error_details
    #            from RST_STREAM frame.
    # Version 26 added XLCT (expected leaf certificate) tag into CHLO.
    # Version 27 added a nonce into SHLO.
    # Version 28 allowed receiver to refuse creating a requested stream.
    # Version 29 added support for QUIC_STREAM_NO_ERROR.
    # Version 30 added server-side support for certificate transparency.
    # Version 31 incorporated the hash of CHLO into the crypto proof supplied by
    #            the server.
    # Version 32 removed FEC-related fields from wire format.
    # Version 33 added diversification nonces.
    # Version 34 removed entropy bits from packets and ACK frames, removed
    #            private flag from packet header and changed the ACK format to
    #            specify ranges of packets acknowledged rather than missing
    #            ranges.

    QUIC_VERSION_35 = 35,  # Allows endpoints to independently set stream limit.

    # Version 36 added support for forced head-of-line blocking experiments.
    # Version 37 added perspective into null encryption.
    # Version 38 switched to IETF padding frame format and support for NSTP (no
    #            stop waiting frame) connection option.

    QUIC_VERSION_39 = 39,  # Integers and floating numbers are written in big
                        # endian. Dot not ack acks. Send a connection level
                        # WINDOW_UPDATE every 20 sent packets which do not
                        # contain retransmittable frames.

    # Version 40 was an attempt to convert QUIC to IETF frame format; it was
    #            never shipped due to a bug.
    # Version 41 was a bugfix for version 40.  The working group changed the wire
    #            format before it shipped, which caused it to be never shipped
    #            and all the changes from it to be reverted.  No changes from v40
    #            or v41 are present in subsequent versions.
    # Version 42 allowed receiving overlapping stream data.

    QUIC_VERSION_43 = 43,  # PRIORITY frames are sent by client and accepted by
                        # server.
    QUIC_VERSION_44 = 44,  # Use IETF header format.
    QUIC_VERSION_45 = 45,  # Added MESSAGE frame.
    QUIC_VERSION_99 = 99,  # Dumping ground for IETF QUIC changes which are not
                        # yet ready for production.

enum HandshakeProtocol* = enum
  PROTOCOL_UNSUPPORTED,
  PROTOCOL_QUIC_CRYPTO,
  PROTOCOL_TLS1_3,


type ParsedQuicVersion* = object
    handshakeProtocol: HandshakeProtocol
    transportVersion: QuicTransportVersion

type ParsedQuicVersionVector* = seq[ParsedQuicVersion]

proc ParsedQuicVersion(handshakeProtocol: HandshakeProtocol, 
                       transportVersion: QuicTransportVersion)

const kSupportedTransportVersions = [
    QUIC_VERSION_99, QUIC_VERSION_45, QUIC_VERSION_44,
    QUIC_VERSION_43, QUIC_VERSION_39, QUIC_VERSION_35
]

const kSupportedHandshakeProtocols = [PROTOCOL_QUIC_CRYPTO, PROTOCOL_TLS1_3]