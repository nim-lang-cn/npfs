import nimssl
import hkdf

proc computeSecrets(connID: string): tuple[clientSecret, serverSecret:seq[byte]] =
    var initialSecret = hkdfExtract(connID, cast[string](quicVersion1Salt))
    result.clientSecret = hkdfExpandLabel(initialSecret, "client in", 32)
    result.serverSecret = hkdfExpandLabel(initialSecret, "server in", 32)
    