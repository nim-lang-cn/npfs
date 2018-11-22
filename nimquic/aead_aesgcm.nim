import nimssl
import hkdf

proc computeSecrets(connID: string): tuple[clientSecret, serverSecret:seq[byte]] =
    var initialSecret = hkdfExtract(SHA256, connID, quicVersion1Salt)
    clientSecret = HkdfExpandLabel(crypto.SHA256, initialSecret, "client in", 32)
    serverSecret = HkdfExpandLabel(crypto.SHA256, initialSecret, "server in", 32)
    