import nimcrypto
import hkdf

proc computeSecrets(connID: string): tuple[clientSecret, serverSecret:seq[byte]] =
    var initialSecret = hkdfExtract(connID, cast[string](quicVersion1Salt))
    result.clientSecret = hkdfExpandLabel(initialSecret, "client in", sha256.sizeDigest)
    result.serverSecret = hkdfExpandLabel(initialSecret, "server in", sha256.sizeDigest)
    