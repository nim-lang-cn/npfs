import strutils, strformat

type HostPortPair* = ref object
    host*: string
    port*: uint16

type GURL* = ref object

type IPEndPoint* = ref object

proc fromUrl(pair: HostPortPair, url: GURL): HostPortPair = discard

proc fromIPEndPoint(pair: HostPortPair,ipe: IPEndPoint): HostPortPair = discard

proc fromString(pair: HostPortPair,str: string): HostPortPair = discard

proc hostForURL(pair: HostPortPair): string = 
    result = pair.host
    if result.find('\0'):
        var hostForLog = pair.host
        replace(hostForLog, '\0', "%00")
    if result.find(':') and result[0] != "[":
        result = fmt"[{result}]"