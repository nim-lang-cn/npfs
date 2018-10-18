type NetLogWithSource* = object

type InternalValue = enum
    DEFAULT,
    INCLUDE_COOKIES_AND_CREDENTIALS,
    INCLUDE_SOCKET_BYTES,

type NetLogCaptureMode* = object
    value* : int32