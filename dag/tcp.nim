import std/asyncnet, std/asyncdispatch, std/streams
import ../dagfs, ./stores

const
  defaultPort = Port(1023)

proc toInt(chars: openArray[char]): int32 =
  for c in chars.items:
    result = (result shl 8) or c.int32

const maxErrorLen = 128

type
  Tag = enum
    errTag = 0'i16
    getTag = 1
    putTag = 2

  MessageBody = object {.union.}
    error: array[maxErrorLen, char]
    putLen: int32
  Message = object {.packed.}
    len: int32
    cid: Cid
    tag: Tag
    body: MessageBody

const
  errMsgBaseSize = 4 + cidSize + 2
  getMsgSize = 4 + cidSize + 2
  putMsgSize = 4 + cidSize + 2 + 4
  minMsgSize = getMsgSize
  maxMsgSize = 4 + cidSize + maxErrorLen

when isMainModule:
  doAssert(maxMsgSize == sizeof(msg))
  
proc `$`(msg: Message): string =
  result = "[" & $msg.cid & "]["
  case msg.tag
  of errTag:
    result.add "err]["
    let n = clamp(msg.len - errMsgBaseSize, 0, maxErrorLen)
    for i in 0..<n:
      result.add msg.body.error[i]
    result.add "]"
  of getTag:
    result.add "get]"
  of putTag:
    result.add "put]["
    result.add $msg.body.putLen
    result.add "]"

type
  TcpServer* = ref TcpServerObj
  TcpServerObj = object
    sock: AsyncSocket
    store: DagfsStore

proc newTcpServer*(store: DagfsStore; port = defaultPort): TcpServer =
  ## Create a new TCP server that serves `store`.
  result = TcpServer(sock: newAsyncSocket(buffered=true), store: store)
  result.sock.bindAddr(port)
  echo "listening on port ", port.int

proc send(sock: AsyncSocket; msg: ptr Message): Future[void] =
  sock.send(msg, msg.len.int)

proc recv(sock: AsyncSocket; msg: ptr Message) {.async.} =
  msg.len = 0
  var n = await sock.recvInto(msg, 4)
  if minMsgSize <= msg.len and msg.len <= maxMsgSize:
    n = await sock.recvInto(addr msg.cid, msg.len-4)
  if n < minMsgSize-4:
    close sock
    #zeroMem(msg, errMsgBaseSize)

proc sendError(sock: AsyncSocket; cid: Cid; str: string): Future[void] =
  var
    msg = Message(tag: errTag)
    str = str
    strLen = min(msg.body.error.len, str.len)
    msgLen = errMsgBaseSize + strLen
  msg.len = msgLen.int32
  copyMem(msg.body.error[0].addr, str[0].addr, strLen)
  when defined(tcpDebug):
    debugEcho "S: ", msg
  sock.send(addr msg)

proc process(server: TcpServer; host: string; client: AsyncSocket) {.async.} =
  ## Process messages from a TCP client.
  echo host, " connected"
  var
    msg: Message
    chunk = ""
  try:
    block loop:
      while not client.isClosed:
        await client.recv(addr msg)
        when defined(tcpDebug):
          debugEcho "C: ", msg
        case msg.tag
        of errTag:
          echo host, ": ", $msg
          break loop
        of getTag:
          try:
            server.store.get(msg.cid, chunk)
            msg.len = putMsgSize
            msg.tag = putTag
            msg.body.putLen = chunk.len.int32
            when defined(tcpDebug):
              debugEcho "S: ", msg
            await client.send(addr msg)
            await client.send(chunk)
          except:
            msg.tag = errTag
            await client.sendError(msg.cid, getCurrentExceptionMsg())
        of putTag:
            # TODO: check if the block is already in the store
          if maxChunkSize < msg.body.putLen:
            await client.sendError(msg.cid, "maximum chunk size is " & $maxChunkSize)
            break
          chunk.setLen msg.body.putLen
          msg.len = getMsgSize
          msg.tag = getTag
          when defined(tcpDebug):
            debugEcho "S: ", msg
          await client.send(addr msg)
          let n = await client.recvInto(chunk[0].addr, chunk.len)
          if n != chunk.len:
            break loop
          let cid = server.store.put(chunk)
          if cid != msg.cid:
            await client.sendError(msg.cid, "put CID mismatch")
        else:
          break loop
  except: discard
  if not client.isClosed:
    close client
  echo host, " closed"

proc serve*(server: TcpServer) {.async.} =
  ## Service client connections to server.
  listen server.sock
  while not server.sock.isClosed:
    let (host, sock) = await server.sock.acceptAddr()
    asyncCheck server.process(host, sock)

proc close*(server: TcpServer) =
  ## Close a TCP server.
  close server.sock

type
  TcpClient* = ref TcpClientObj
  TcpClientObj = object of DagfsStoreObj
    sock: AsyncSocket
    buf: string

proc tcpClientPutBuffer(s: DagfsStore; buf: pointer; len: Natural): Cid =
  var client = TcpClient(s)
  result = dagHash(buf, len)
  if result != zeroChunk:
    var msg: Message
    block put:
      msg.len = putMsgSize
      msg.cid = result
      msg.tag = putTag
      msg.body.putLen = len.int32
      when defined(tcpDebug):
        debugEcho "C: ", msg
      waitFor client.sock.send(addr msg)
    block get:
      waitFor client.sock.recv(addr msg)
      when defined(tcpDebug):
        debugEcho "S: ", msg
      case msg.tag
      of getTag:
        if msg.cid == result:
          waitFor client.sock.send(buf, len)
        else:
          close client.sock
          raiseAssert "server sent out-of-order \"get\" message"
      of errTag:
        raiseAssert $msg
      else:
        raiseAssert "invalid server message"

proc tcpClientPut(s: DagfsStore; chunk: string): Cid =
  var client = TcpClient(s)
  result = dagHash chunk
  if result != zeroChunk:
    var msg: Message
    block put:
      msg.len = putMsgSize
      msg.cid = result
      msg.tag = putTag
      msg.body.putLen = chunk.len.int32
      when defined(tcpDebug):
        debugEcho "C: ", msg
      waitFor client.sock.send(addr msg)
    block get:
      waitFor client.sock.recv(addr msg)
      when defined(tcpDebug):
        debugEcho "S: ", msg
      case msg.tag
      of getTag:
        if msg.cid == result:
          waitFor client.sock.send(chunk)
        else:
          close client.sock
          raiseAssert "server sent out-of-order \"get\" message"
      of errTag:
        raiseAssert $msg
      else:
        raiseAssert "invalid server message"

proc tcpClientGetBuffer(s: DagfsStore; cid: Cid; buf: pointer; len: Natural): int =
  var
    client = TcpClient(s)
    msg: Message
  block get:
    msg.len = getMsgSize
    msg.cid = cid
    msg.tag = getTag
    when defined(tcpDebug):
      debugEcho "C: ", msg
    waitFor client.sock.send(addr msg)
  block put:
    waitFor client.sock.recv(addr msg)
    when defined(tcpDebug):
      debugEcho "S: ", msg
    case msg.tag
    of putTag:
      doAssert(msg.cid == cid)
      result = msg.body.putLen.int
      doAssert(result <= len)
      let n = waitFor client.sock.recvInto(buf, result)
      doAssert(n == result)
    of errTag:
      raise MissingChunk(msg: $msg, cid: cid)
    else:
      raiseMissing cid

proc tcpClientGet(s: DagfsStore; cid: Cid; result: var string) =
  result.setLen maxChunkSize
  let n = s.getBuffer(cid, result[0].addr, result.len)
  result.setLen n
  assert(result.dagHash == cid)

proc newTcpClient*(host: string; port = defaultPort): TcpClient =
  new result
  result.sock = waitFor asyncnet.dial(host, port, buffered=true)
  result.buf = ""
  result.putBufferImpl = tcpClientPutBuffer
  result.putImpl = tcpClientPut
  result.getBufferImpl = tcpClientGetBuffer
  result.getImpl = tcpClientGet

proc close*(client: TcpClient) =
  ## Close a TCP client connection.
  close client.sock
