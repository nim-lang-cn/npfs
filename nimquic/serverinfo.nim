import session, parseopt, strutils, strformat

type FailureReason* = enum
    WAIT_FOR_DATA_READY_INVALID_ARGUMENT_FAILURE = 0,
    GET_BACKEND_FAILURE = 1,
    OPEN_FAILURE = 2,
    CREATE_OR_OPEN_FAILURE = 3,
    PARSE_NO_DATA_FAILURE = 4,
    PARSE_FAILURE = 5,
    READ_FAILURE = 6,
    READY_TO_PERSIST_FAILURE = 7,
    PERSIST_NO_BACKEND_FAILURE = 8,
    WRITE_FAILURE = 9,
    NO_FAILURE = 10,
    PARSE_DATA_DECODE_FAILURE = 11,
    NUM_OF_FAILURES = 12,

type State* = object
    serverConfig*: string
    sourceAddressToken*: string
    certSct*: string
    chloHash*: string
    certs*: seq[string]
    serverConfigSig*: string

type QuicServerInfo* = object
    state*: State
    serverId*: QuicServerId

proc parse*(data: string): bool = 
    var state = State()
    state.clear()
    result = parseInnter(data)
    if !result :
        state.clear()

const kQuicCryptoConfigVersion* = "2"

type Pickle* = object
type PickleIterator* = object

proc parseInner(state:  var State , data: string): bool =
    var op = initOptParser()
    var command_line_args : seq[string]
    var version : string 
    var numCerts: string
    for kind, key, val in op.getopt():
        case kind
        of cmdArgument:
            command_line_args.add key
        of cmdLongOption:
            case key
            of "version":
                version = val 
            of "server_config":
                state.serverConfig = val
            of "source_address_token":
                state.sourceAddressToken = val
            of "cert_sct":
                state.certSct = val
            of "chlo_hash":
                state.chloHash = val
            of "server_config_sig":
                state.serverConfigSig = val
            of "numCerts":
                numCerts = val
            of "cert":
                state.certs.add string(val)
        of cmdShortOption:
            continue
        of cmdEnd: echo "end"
    if version != kQuicCryptoConfigVersion:
        result = false

proc serializeInner*(state: State): string = 
    result = kQuicCryptoConfigVersion
    result.add state.serverConfig
    result.add state.sourceAddressToken
    result.add state.certSct
    result.add state.chloHash
    result.add state.serverConfigSig
    result.add state.certs.len
    for cert in state.certs:
        result.add cert
        
proc serialize*(state: State): string =
    var pickledData = serializeInner(state)
