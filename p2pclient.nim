import wNim
import libp2p

import chronos, nimcrypto, strutils
import libp2p/daemon/daemonapi
import strformat

when not(compileOption("threads")):
  {.fatal: "Please, compile this program with the --threads:on option!".}

const
  ServerProtocols = @["/test-chat-stream"]

type
  CustomData = ref object
    api: DaemonAPI
    remotes: seq[StreamTransport]
    consoleFd: AsyncFD
    wfd: AsyncFD
    serveFut: Future[void]


type
  MenuID = enum
    idVertical = wIdUser, idHorizontal, idExit, idExample

  Example = object
    name: string
    vfl: string
    show: proc ()

let app = App()
let frame = Frame(title="Nim p2p client", size=(900, 600))
let win = Frame(frame, title="console", size=(400, 400))
let panel = Panel(win)

let splitter = Splitter(frame, style=wSpHorizontal or wDoubleBuffered, size=(8, 8))
let statusBar = StatusBar(frame)
let menuBar = MenuBar(frame)

let console = TextCtrl(splitter.panel1, style= wTeRich or wTeMultiLine or wTeDontWrap or wVScroll or wTeReadOnly)
console.font = Font(12, faceName="Consolas", encoding=wFontEncodingCp1252)

var consoleString = ""

var (rfd, wfd) = createAsyncPipe()
var writePipe = fromPipe(wfd)


let command = TextCtrl(splitter.panel2, style= wBorderSunken)
command.font = Font(12, faceName="Consolas", encoding=wFontEncodingCp1252)
command.wEvent_TextEnter do (): 
    var line = command.getValue()
    let res = waitFor writePipe.write(line & "\r\n")
    consoleString = line & "\r\n"
    console.appendText consoleString
    command.clear


template dhtFindPeer() {.dirty.} =
    var peerId = PeerID.init(parts[1]).value
    consoleString = "= Searching for peer " & peerId.pretty() & "\r\n"
    console.appendText consoleString

    var id = await udata.api.dhtFindPeer(peerId)
    consoleString = "= Peer " & parts[1] & " found at addresses:\r\n"
    console.appendText consoleString

    for item in id.addresses:
      consoleString = $item & "\r\n"
      console.appendText consoleString

proc serveThread(udata: CustomData) {.async.} =
 {.gcsafe.}:
  var transp = fromPipe(udata.consoleFd)

  proc remoteReader(transp: StreamTransport) {.async.} =
    {.gcsafe.}:
      while true:
        var line = await transp.readLine()
        if len(line) == 0:
          break
        consoleString = ">> " & line
        console.appendText consoleString

  while true:
    try:
      var line = await transp.readLine()
      if line.startsWith("/connect"):
        var parts = line.split(" ")
        if len(parts) == 2:
          dhtFindPeer()

          var address = MultiAddress.init(multiCodec("p2p-circuit")).value
          address = MultiAddress.init(multiCodec("p2p"), peerId).value
          consoleString = "= Connecting to peer " & $address & "\r\n"
          console.appendText consoleString
          echo consoleString

          await udata.api.connect(peerId, @[address], 30)
          consoleString = "= Opening stream to peer chat " & parts[1] & "\r\n"
          console.appendText consoleString
          echo consoleString

          var stream = await udata.api.openStream(peerId, ServerProtocols)
          udata.remotes.add(stream.transp)
          consoleString = "= Connected to peer chat " & parts[1] & "\r\n"
          console.appendText consoleString
          echo consoleString

          echo "before remoteReader"
          asyncCheck remoteReader(stream.transp)
      elif line.startsWith("/search"):
        var parts = line.split(" ")
        if len(parts) == 2:
          dhtFindPeer()

      elif line.startsWith("/consearch"):
        var parts = line.split(" ")
        if len(parts) == 2:
          var peerId = PeerID.init(parts[1]).value
          consoleString = "= Searching for peers connected to peer " & parts[1] & "\r\n"
          console.appendText consoleString
          var peers = await udata.api.dhtFindPeersConnectedToPeer(peerId) 
          consoleString = &"= Found {len(peers)} connected to peer {parts[1]}\r\n"
          console.appendText consoleString
          for item in peers:
            var peer = item.peer
            var addresses = newSeq[string]()
            var relay = false
            for a in item.addresses:
              addresses.add($a)
              if a.protoName().value == "/p2p-circuit":
                relay = true
                break
            if relay:
              consoleString = &"""{peer.pretty()} * [{addresses.join(", ")}]"""
              console.appendText consoleString
            else:
              consoleString = &"""{peer.pretty()} [{addresses.join(", ")}]"""
              console.appendText consoleString
      elif line.startsWith("/get"):
        var parts = line.split(" ")
        if len(parts) == 2:
          var dag = parts[1]
          var value = await udata.api.dhtGetValue dag
          echo value
      elif line.startsWith("/exit"):
        break
      
      else:
        var msg = line & "\r\n"
        consoleString = "<< " & line
        var pending = newSeq[Future[int]]()
        for item in udata.remotes:
          pending.add(item.write(msg))
        if len(pending) > 0:
          var results = await all(pending)
    except:
      consoleString = getCurrentException().msg

proc p2pdaemon() {.thread.} =
 {.gcsafe.}:
  var data = new CustomData
  data.remotes = newSeq[StreamTransport]()

  if rfd == asyncInvalidPipe or wfd == asyncInvalidPipe:
      raise newException(ValueError, "Could not initialize pipe!")

  data.consoleFd = rfd

  data.serveFut = serveThread(data)

  consoleString = "= Starting P2P node\r\n"
  console.appendText consoleString
  data.api = waitFor newDaemonApi({DHTFull, Bootstrap})
  var id = waitFor data.api.identity()

  proc streamHandler(api: DaemonAPI, stream: P2PStream) {.async.} =
      {.gcsafe.}:
          consoleString = "= Peer " & stream.peer.pretty() & " joined chat\r\n"
          console.appendText consoleString
          data.remotes.add(stream.transp)
          while true:
              var line = await stream.transp.readLine()
              if len(line) == 0:
                  break
              consoleString = ">> " & line & "\r\n"
              console.appendText consoleString

  waitFor data.api.addHandler(ServerProtocols, streamHandler)
  consoleString = "= Your PeerID is " & id.peer.pretty() & "\r\n"
  console.appendText consoleString
  waitFor data.serveFut

when isMainModule:
  var p2pThread: Thread[void]
  p2pThread.createThread p2pdaemon

  proc switchSplitter(mode: int) =
    splitter.splitMode = mode
    statusBar.refresh()
    let size = frame.clientSize
    splitter.move(size.width div 2, size.height div 2)

  let menu = Menu(menuBar, "&Layout")
  menu.appendRadioItem(idHorizontal, "&Horizontal").check()
  menu.appendRadioItem(idVertical, "&Vertical")
  menu.appendSeparator()
  menu.append(idExit, "E&xit")

  frame.wEvent_Menu do (event: wEvent):
    case event.id
    of idExit:
      frame.close()

    of idVertical:
      if not splitter.isVertical:
        switchSplitter(wSpVertical)

    of idHorizontal:
      if splitter.isVertical:
        switchSplitter(wSpHorizontal)

    else:
      discard

  splitter.panel1.wEvent_Size do ():
    splitter.panel1.autolayout "HV:|[console]|"

  splitter.panel2.wEvent_Size do ():
    splitter.panel2.autolayout "HV:|[command]|"

  switchSplitter(wSpHorizontal)
  frame.center()
  frame.show()

  app.mainLoop()