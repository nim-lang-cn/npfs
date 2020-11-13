##  filcrypto Header

##  Generated with cbindgen:0.14.0

const
  DIGEST_BYTES* = 96
  PRIVATE_KEY_BYTES* = 32
  PUBLIC_KEY_BYTES* = 48
  SIGNATURE_BYTES* = 96

type
  FCPResponseStatus* = enum
    FCPResponseStatusFCPNoError = 0, FCPResponseStatusFCPUnclassifiedError = 1,
    FCPResponseStatusFCPCallerError = 2, FCPResponseStatusFCPReceiverError = 3
  FilRegisteredPoStProof* = enum
    filRegisteredPoStProofStackedDrgWinning2KiBV1,
    filRegisteredPoStProofStackedDrgWinning8MiBV1,
    filRegisteredPoStProofStackedDrgWinning512MiBV1,
    filRegisteredPoStProofStackedDrgWinning32GiBV1,
    filRegisteredPoStProofStackedDrgWinning64GiBV1,
    filRegisteredPoStProofStackedDrgWindow2KiBV1,
    filRegisteredPoStProofStackedDrgWindow8MiBV1,
    filRegisteredPoStProofStackedDrgWindow512MiBV1,
    filRegisteredPoStProofStackedDrgWindow32GiBV1,
    filRegisteredPoStProofStackedDrgWindow64GiBV1
  FilRegisteredSealProof* = enum
    filRegisteredSealProofStackedDrg2KiBV1,
    filRegisteredSealProofStackedDrg8MiBV1,
    filRegisteredSealProofStackedDrg512MiBV1,
    filRegisteredSealProofStackedDrg32GiBV1,
    filRegisteredSealProofStackedDrg64GiBV1
  FilBLSSignature* = ref object
    inner*: array[SIGNATURE_BYTES, uint8]





## *
##  AggregateResponse
##

type
  FilAggregateResponse* = ref object
    signature*: FilBLSSignature

  FilClearCacheResponse* = ref object
    errorMsg*: cstring
    statusCode*: FCPResponseStatus

  FilFauxRepResponse* = ref object
    errorMsg*: cstring
    statusCode*: FCPResponseStatus
    commitment*: array[32, uint8]

  FilFinalizeTicketResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    ticket*: array[32, uint8]

  FilGenerateDataCommitmentResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    commD*: array[32, uint8]

  FilGeneratePieceCommitmentResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    commP*: array[32, uint8] ## *
                           ##  The number of unpadded bytes in the original piece plus any (unpadded) = discard
                           ##  alignment bytes added to create a whole merkle tree.
                           ##
    numBytesAligned*: uint64

  FilPoStProof* = ref object
    registeredProof*: FilRegisteredPoStProof
    proofLen*: csize
    proofPtr*: var uint8

  FilGenerateWindowPoStResponse* = ref object
    errorMsg*: cstring
    proofsLen*: csize
    proofsPtr*: ptr FilPoStProof
    faultySectorsLen*: csize
    faultySectorsPtr*: ptr uint64
    statusCode*: FCPResponseStatus

  FilGenerateWinningPoStResponse* = ref object
    errorMsg*: cstring
    proofsLen*: csize
    proofsPtr*: ptr FilPoStProof
    statusCode*: FCPResponseStatus

  FilGenerateWinningPoStSectorChallenge* = ref object
    errorMsg*: cstring
    statusCode*: FCPResponseStatus
    idsPtr*: ptr uint64
    idsLen*: csize

  FilGpuDeviceResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    devicesLen*: csize
    devicesPtr*: cstringArray

  FilBLSDigest* = ref object
    inner*: array[DIGEST_BYTES, uint8]


## *
##  HashResponse
##

type
  FilHashResponse* = ref object
    digest*: FilBLSDigest

  FilInitLogFdResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring

  FilBLSPrivateKey* = ref object
    inner*: array[PRIVATE_KEY_BYTES, uint8]


## *
##  PrivateKeyGenerateResponse
##

type
  FilPrivateKeyGenerateResponse* = ref object
    privateKey*: FilBLSPrivateKey

  FilBLSPublicKey* = ref object
    inner*: array[PUBLIC_KEY_BYTES, uint8]


## *
##  PrivateKeyPublicKeyResponse
##

type
  FilPrivateKeyPublicKeyResponse* = ref object
    publicKey*: FilBLSPublicKey


## *
##  PrivateKeySignResponse
##

type
  FilPrivateKeySignResponse* = ref object
    signature*: FilBLSSignature

  FilSealCommitPhase1Response* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    sealCommitPhase1OutputPtr*: var uint8
    sealCommitPhase1OutputLen*: csize

  FilSealCommitPhase2Response* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    proofPtr*: var uint8
    proofLen*: csize

  FilSealPreCommitPhase1Response* = ref object
    errorMsg*: cstring
    statusCode*: FCPResponseStatus
    sealPreCommitPhase1OutputPtr*: var uint8
    sealPreCommitPhase1OutputLen*: csize

  FilSealPreCommitPhase2Response* = ref object
    errorMsg*: cstring
    statusCode*: FCPResponseStatus
    registeredProof*: FilRegisteredSealProof
    commD*: array[32, uint8]
    commR*: array[32, uint8]


## *
##
##

type
  FilStringResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    stringVal*: cstring

  FilUnsealRangeResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring

  FilVerifySealResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    isValid*: bool

  FilVerifyWindowPoStResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    isValid*: bool

  FilVerifyWinningPoStResponse* = ref object
    statusCode*: FCPResponseStatus
    errorMsg*: cstring
    isValid*: bool

  FilWriteWithAlignmentResponse* = ref object
    commP*: array[32, uint8]
    errorMsg*: cstring
    leftAlignmentUnpadded*: uint64
    statusCode*: FCPResponseStatus
    totalWriteUnpadded*: uint64

  FilWriteWithoutAlignmentResponse* = ref object
    commP*: array[32, uint8]
    errorMsg*: cstring
    statusCode*: FCPResponseStatus
    totalWriteUnpadded*: uint64

  FilPublicPieceInfo* = ref object
    numBytes*: uint64
    commP*: array[32, uint8]

  Fil32ByteArray* = ref object
    inner*: array[32, uint8]

  FilPrivateReplicaInfo* = ref object
    registeredProof*: FilRegisteredPoStProof
    cacheDirPath*: cstring
    commR*: array[32, uint8]
    replicaPath*: cstring
    sectorId*: uint64

  FilPublicReplicaInfo* = ref object
    registeredProof*: FilRegisteredPoStProof
    commR*: array[32, uint8]
    sectorId*: uint64


## *
##  Aggregate signatures together into a new signature
##
##  # Arguments
##
##  * `flattened_signatures_ptr` - pointer to a byte array containing signatures
##  * `flattened_signatures_len` - length of the byte array (multiple of SIGNATURE_BYTES) = discard
##
##  Returns `NULL` on error. Result must be freed using `destroy_aggregate_response`.
##

proc filAggregate*(flattenedSignaturesPtr: var uint8; flattenedSignaturesLen: csize): FilAggregateResponse = discard
proc filClearCache*(sectorSize: uint64; cacheDirPath: cstring): FilClearCacheResponse = discard
proc filDestroyAggregateResponse*(p: var FilAggregateResponse) = discard
proc filDestroyClearCacheResponse*(p: var FilClearCacheResponse) = discard
proc filDestroyFauxrepResponse*(p: var FilFauxRepResponse) = discard
proc filDestroyFinalizeTicketResponse*(p: var FilFinalizeTicketResponse) = discard
proc filDestroyGenerateDataCommitmentResponse*(
    p: var FilGenerateDataCommitmentResponse) = discard
proc filDestroyGeneratePieceCommitmentResponse*(
    p: var FilGeneratePieceCommitmentResponse) = discard
proc filDestroyGenerateWindowPostResponse*(
    p: var FilGenerateWindowPoStResponse) = discard
proc filDestroyGenerateWinningPostResponse*(p: var FilGenerateWinningPoStResponse) = discard
proc filDestroyGenerateWinningPostSectorChallenge*(p: var FilGenerateWinningPoStSectorChallenge) = discard
proc filDestroyGpuDeviceResponse*(p: var FilGpuDeviceResponse) = discard
proc filDestroyHashResponse*(p: var FilHashResponse) = discard
proc filDestroyInitLogFdResponse*(p: var FilInitLogFdResponse) = discard
proc filDestroyPrivateKeyGenerateResponse*(p: var FilPrivateKeyGenerateResponse) = discard
proc filDestroyPrivateKeyPublicKeyResponse*(p: var FilPrivateKeyPublicKeyResponse) = discard
proc filDestroyPrivateKeySignResponse*(p: var FilPrivateKeySignResponse) = discard
proc filDestroySealCommitPhase1Response*(p: var FilSealCommitPhase1Response) = discard
proc filDestroySealCommitPhase2Response*(p: var FilSealCommitPhase2Response) = discard
proc filDestroySealPreCommitPhase1Response*(p: var FilSealPreCommitPhase1Response) = discard
proc filDestroySealPreCommitPhase2Response*(p: var FilSealPreCommitPhase2Response) = discard
proc filDestroyStringResponse*(p: var FilStringResponse) = discard
proc filDestroyUnsealRangeResponse*(p: var FilUnsealRangeResponse) = discard
## *
##  Deallocates a VerifySealResponse.
##
##

proc filDestroyVerifySealResponse*(p: var FilVerifySealResponse) = discard
proc filDestroyVerifyWindowPostResponse*(p: var FilVerifyWindowPoStResponse) = discard
## *
##  Deallocates a VerifyPoStResponse.
##
##

proc filDestroyVerifyWinningPostResponse*(p: var FilVerifyWinningPoStResponse) = discard
proc filDestroyWriteWithAlignmentResponse*(p: var FilWriteWithAlignmentResponse) = discard
proc filDestroyWriteWithoutAlignmentResponse*(p: var FilWriteWithoutAlignmentResponse) = discard
proc filFauxrep*(registeredProof: FilRegisteredSealProof; cacheDirPath: cstring;
                sealedSectorPath: cstring): FilFauxRepResponse = discard
proc filFauxrep2*(registeredProof: FilRegisteredSealProof; cacheDirPath: cstring;
                 existingPAuxPath: cstring): FilFauxRepResponse = discard
## *
##  Returns the merkle root for a sector containing the provided pieces.
##

proc filGenerateDataCommitment*(registeredProof: FilRegisteredSealProof;
                               piecesPtr: ptr FilPublicPieceInfo; piecesLen: csize): FilGenerateDataCommitmentResponse = discard
## *
##  Returns the merkle root for a piece after piece padding and alignment.
##  The caller is responsible for closing the passed in file descriptor.
##

proc filGeneratePieceCommitment*(registeredProof: FilRegisteredSealProof;
                                pieceFdRaw: cint; unpaddedPieceSize: uint64): FilGeneratePieceCommitmentResponse = discard
## *
##  TODO: document
##
##

proc filGenerateWindowPost*(randomness: Fil32ByteArray;
                           replicasPtr: ptr FilPrivateReplicaInfo;
                           replicasLen: csize; proverId: Fil32ByteArray): FilGenerateWindowPoStResponse = discard
## *
##  TODO: document
##
##

proc filGenerateWinningPost*(randomness: Fil32ByteArray;
                            replicasPtr: ptr FilPrivateReplicaInfo;
                            replicasLen: csize; proverId: Fil32ByteArray): FilGenerateWinningPoStResponse = discard
## *
##  TODO: document
##
##

proc filGenerateWinningPostSectorChallenge*(
    registeredProof: FilRegisteredPoStProof; randomness: Fil32ByteArray;
    sectorSetLen: uint64; proverId: Fil32ByteArray): FilGenerateWinningPoStSectorChallenge = discard
## *
##  Returns an array of strings containing the device names that can be used.
##

proc filGetGpuDevices*(): FilGpuDeviceResponse = discard
## *
##  Returns the number of user bytes that will fit into a staged sector.
##
##

proc filGetMaxUserBytesPerStagedSector*(registeredProof: FilRegisteredSealProof): uint64 = discard
## *
##  Returns the identity of the circuit for the provided PoSt proof type.
##
##

proc filGetPostCircuitIdentifier*(registeredProof: FilRegisteredPoStProof): FilStringResponse = discard
## *
##  Returns the CID of the Groth parameter file for generating a PoSt.
##
##

proc filGetPostParamsCid*(registeredProof: FilRegisteredPoStProof): FilStringResponse = discard
## *
##  Returns the path from which the proofs library expects to find the Groth
##  parameter file used when generating a PoSt.
##
##

proc filGetPostParamsPath*(registeredProof: FilRegisteredPoStProof): FilStringResponse = discard
## *
##  Returns the CID of the verifying key-file for verifying a PoSt proof.
##
##

proc filGetPostVerifyingKeyCid*(registeredProof: FilRegisteredPoStProof): FilStringResponse = discard
## *
##  Returns the path from which the proofs library expects to find the verifying
##  key-file used when verifying a PoSt proof.
##
##

proc filGetPostVerifyingKeyPath*(registeredProof: FilRegisteredPoStProof): FilStringResponse = discard
## *
##  Returns the version of the provided seal proof.
##
##

proc filGetPostVersion*(registeredProof: FilRegisteredPoStProof): FilStringResponse = discard
## *
##  Returns the identity of the circuit for the provided seal proof.
##
##

proc filGetSealCircuitIdentifier*(registeredProof: FilRegisteredSealProof): FilStringResponse = discard
## *
##  Returns the CID of the Groth parameter file for sealing.
##
##

proc filGetSealParamsCid*(registeredProof: FilRegisteredSealProof): FilStringResponse = discard
## *
##  Returns the path from which the proofs library expects to find the Groth
##  parameter file used when sealing.
##
##

proc filGetSealParamsPath*(registeredProof: FilRegisteredSealProof): FilStringResponse = discard
## *
##  Returns the CID of the verifying key-file for verifying a seal proof.
##
##

proc filGetSealVerifyingKeyCid*(registeredProof: FilRegisteredSealProof): FilStringResponse = discard
## *
##  Returns the path from which the proofs library expects to find the verifying
##  key-file used when verifying a seal proof.
##
##

proc filGetSealVerifyingKeyPath*(registeredProof: FilRegisteredSealProof): FilStringResponse = discard
## *
##  Returns the version of the provided seal proof type.
##
##

proc filGetSealVersion*(registeredProof: FilRegisteredSealProof): FilStringResponse = discard
## *
##  Compute the digest of a message
##
##  # Arguments
##
##  * `message_ptr` - pointer to a message byte array
##  * `message_len` - length of the byte array
##

proc filHash*(messagePtr: var uint8; messageLen: csize): FilHashResponse = discard
## *
##  Verify that a signature is the aggregated signature of the hhashed messages
##
##  # Arguments
##
##  * `signature_ptr`             - pointer to a signature byte array (SIGNATURE_BYTES long) = discard
##  * `messages_ptr`              - pointer to an array containing the pointers to the messages
##  * `messages_sizes_ptr`        - pointer to an array containing the lengths of the messages
##  * `messages_len`              - length of the two messages arrays
##  * `flattened_public_keys_ptr` - pointer to a byte array containing public keys
##  * `flattened_public_keys_len` - length of the array
##

proc filHashVerify*(signaturePtr: var uint8; flattenedMessagesPtr: var uint8;
                   flattenedMessagesLen: csize; messageSizesPtr: ptr csize;
                   messageSizesLen: csize; flattenedPublicKeysPtr: var uint8;
                   flattenedPublicKeysLen: csize): cint = discard
## *
##  Initializes the logger with a file descriptor where logs will be logged into.
##
##  This is usually a pipe that was opened on the receiving side of the logs. The logger is
##  initialized on the invocation, subsequent calls won't have any effect.
##
##  This function must be called right at the start, before any other call. Else the logger will
##  be initializes implicitely and log to stderr.
##

proc filInitLogFd*(logFd: cint): FilInitLogFdResponse = discard
## *
##  Generate a new private key
##

proc filPrivateKeyGenerate*(): FilPrivateKeyGenerateResponse = discard
## *
##  Generate a new private key with seed
##
##  **Warning**: Use this function only for testing or with very secure seeds
##
##  # Arguments
##
##  * `raw_seed` - a seed byte array with 32 bytes
##
##  Returns `NULL` when passed a NULL pointer.
##

proc filPrivateKeyGenerateWithSeed*(rawSeed: Fil32ByteArray): FilPrivateKeyGenerateResponse = discard
## *
##  Generate the public key for a private key
##
##  # Arguments
##
##  * `raw_private_key_ptr` - pointer to a private key byte array
##
##  Returns `NULL` when passed invalid arguments.
##

proc filPrivateKeyPublicKey*(rawPrivateKeyPtr: var uint8): FilPrivateKeyPublicKeyResponse = discard
## *
##  Sign a message with a private key and return the signature
##
##  # Arguments
##
##  * `raw_private_key_ptr` - pointer to a private key byte array
##  * `message_ptr` - pointer to a message byte array
##  * `message_len` - length of the byte array
##
##  Returns `NULL` when passed invalid arguments.
##

proc filPrivateKeySign*(rawPrivateKeyPtr: var uint8; messagePtr: var uint8;
                       messageLen: csize): FilPrivateKeySignResponse = discard
## *
##  TODO: document
##
##

proc filSealCommitPhase1*(registeredProof: FilRegisteredSealProof;
                         commR: Fil32ByteArray; commD: Fil32ByteArray;
                         cacheDirPath: cstring; replicaPath: cstring;
                         sectorId: uint64; proverId: Fil32ByteArray;
                         ticket: Fil32ByteArray; seed: Fil32ByteArray;
                         piecesPtr: ptr FilPublicPieceInfo; piecesLen: csize): FilSealCommitPhase1Response = discard
proc filSealCommitPhase2*(sealCommitPhase1OutputPtr: var uint8;
                         sealCommitPhase1OutputLen: csize; sectorId: uint64;
                         proverId: Fil32ByteArray): FilSealCommitPhase2Response = discard
## *
##  TODO: document
##
##

proc filSealPreCommitPhase1*(registeredProof: FilRegisteredSealProof;
                            cacheDirPath: cstring; stagedSectorPath: cstring;
                            sealedSectorPath: cstring; sectorId: uint64;
                            proverId: Fil32ByteArray; ticket: Fil32ByteArray;
                            piecesPtr: ptr FilPublicPieceInfo; piecesLen: csize): FilSealPreCommitPhase1Response = discard
## *
##  TODO: document
##
##

proc filSealPreCommitPhase2*(sealPreCommitPhase1OutputPtr: var uint8;sealPreCommitPhase1OutputLen: csize;cacheDirPath: cstring; sealedSectorPath: cstring): FilSealPreCommitPhase2Response = discard
## *
##  TODO: document
##

proc filUnsealRange*(registeredProof: FilRegisteredSealProof;
                    cacheDirPath: cstring; sealedSectorFdRaw: cint;
                    unsealOutputFdRaw: cint; sectorId: uint64;
                    proverId: Fil32ByteArray; ticket: Fil32ByteArray;
                    commD: Fil32ByteArray; unpaddedByteIndex: uint64;
                    unpaddedBytesAmount: uint64): FilUnsealRangeResponse = discard
## *
##  Verify that a signature is the aggregated signature of hashes - pubkeys
##
##  # Arguments
##
##  * `signature_ptr`             - pointer to a signature byte array (SIGNATURE_BYTES long) = discard
##  * `flattened_digests_ptr`     - pointer to a byte array containing digests
##  * `flattened_digests_len`     - length of the byte array (multiple of DIGEST_BYTES) = discard
##  * `flattened_public_keys_ptr` - pointer to a byte array containing public keys
##  * `flattened_public_keys_len` - length of the array
##

proc filVerify*(signaturePtr: var uint8; flattenedDigestsPtr: var uint8;
               flattenedDigestsLen: csize; flattenedPublicKeysPtr: var uint8;
               flattenedPublicKeysLen: csize): cint = discard
## *
##  Verifies the output of seal.
##
##

proc filVerifySeal*(registeredProof: FilRegisteredSealProof; commR: Fil32ByteArray;
                   commD: Fil32ByteArray; proverId: Fil32ByteArray;
                   ticket: Fil32ByteArray; seed: Fil32ByteArray; sectorId: uint64;
                   proofPtr: var uint8; proofLen: csize): FilVerifySealResponse = discard
## *
##  Verifies that a proof-of-spacetime is valid.
##

proc filVerifyWindowPost*(randomness: Fil32ByteArray;
                         replicasPtr: ptr FilPublicReplicaInfo; replicasLen: csize;
                         proofsPtr: ptr FilPoStProof; proofsLen: csize;
                         proverId: Fil32ByteArray): FilVerifyWindowPoStResponse = discard
## *
##  Verifies that a proof-of-spacetime is valid.
##

proc filVerifyWinningPost*(randomness: Fil32ByteArray;
                          replicasPtr: ptr FilPublicReplicaInfo;
                          replicasLen: csize; proofsPtr: ptr FilPoStProof;
                          proofsLen: csize; proverId: Fil32ByteArray): FilVerifyWinningPoStResponse = discard
## *
##  TODO: document
##
##

proc filWriteWithAlignment*(registeredProof: FilRegisteredSealProof; srcFd: cint;
                           srcSize: uint64; dstFd: cint;
                           existingPieceSizesPtr: ptr uint64;
                           existingPieceSizesLen: csize): FilWriteWithAlignmentResponse = discard
## *
##  TODO: document
##
##

proc filWriteWithoutAlignment*(registeredProof: FilRegisteredSealProof;
                              srcFd: cint; srcSize: uint64; dstFd: cint): FilWriteWithoutAlignmentResponse = discard