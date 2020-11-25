import math
import tables
import deques
import binaryparse
import streams
import posix

const
  AV_CODEC_HW_CONFIG_METHOD_HW_DEVICE_CTX* = 0x00000001
  AV_CODEC_HW_CONFIG_METHOD_HW_FRAMES_CTX* = 0x00000002
  AV_CODEC_HW_CONFIG_METHOD_INTERNAL* = 0x00000004
  AV_CODEC_HW_CONFIG_METHOD_AD_HOC* = 0x00000008
  ERANGE = 34


type
  AVDiscard* = enum 
    AVDISCARD_NONE = -16,       ## /< discard nothing
    AVDISCARD_DEFAULT = 0,      ## /< discard useless packets like 0 size packets in avi
    AVDISCARD_NONREF = 8,       ## /< discard all non reference
    AVDISCARD_BIDIR = 16,       ## /< discard all bidirectional frames
    AVDISCARD_NONINTRA = 24,    ## /< discard all non intra frames
    AVDISCARD_NONKEY = 32,      ## /< discard all frames except keyframes
    AVDISCARD_ALL = 48          ## /< discard all

  SwrDitherType* = enum
    SWR_DITHER_NONE = 0, SWR_DITHER_RECTANGULAR, SWR_DITHER_TRIANGULAR,
    SWR_DITHER_TRIANGULAR_HIGHPASS, SWR_DITHER_NS = 64, SWR_DITHER_NS_LIPSHITZ,
    SWR_DITHER_NS_F_WEIGHTED, SWR_DITHER_NS_MODIFIED_E_WEIGHTED,
    SWR_DITHER_NS_IMPROVED_E_WEIGHTED, SWR_DITHER_NS_SHIBATA,
    SWR_DITHER_NS_LOW_SHIBATA, SWR_DITHER_NS_HIGH_SHIBATA, SWR_DITHER_NB

  AVColorPrimaries* = enum
    AVCOL_PRI_RESERVED0 = 0, AVCOL_PRI_BT709 = 1, AVCOL_PRI_UNSPECIFIED = 2,
    AVCOL_PRI_RESERVED = 3, AVCOL_PRI_BT470M = 4, AVCOL_PRI_BT470BG = 5,
    AVCOL_PRI_SMPTE170M = 6, AVCOL_PRI_SMPTE240M = 7, AVCOL_PRI_FILM = 8,
    AVCOL_PRI_BT2020 = 9, AVCOL_PRI_SMPTE428 = 10, AVCOL_PRI_SMPTE431 = 11,
    AVCOL_PRI_SMPTE432 = 12, AVCOL_PRI_EBU3213 = 22, AVCOL_PRI_NB

const
  AVCOL_PRI_SMPTEST428_1 = AVCOL_PRI_SMPTE428
  AVCOL_PRI_JEDEC_P22 = AVCOL_PRI_EBU3213

const SAMPLE_ARRAY_SIZE = (8 * 65536)
type
  SwrEngine* = enum
    SWR_ENGINE_SWR, SWR_ENGINE_SOXR, SWR_ENGINE_NB

  RDFTransformType* = enum
    DFT_R2C, IDFT_C2R, IDFT_R2C, DFT_C2R

  DCTTransformType* = enum
    DCT_II = 0, DCT_III, DCT_I, DST_I

  SwrFilterType* = enum
    SWR_FILTER_TYPE_CUBIC, SWR_FILTER_TYPE_BLACKMAN_NUTTALL,
    SWR_FILTER_TYPE_KAISER

  AVStreamParseType* = enum
    AVSTREAM_PARSE_NONE, AVSTREAM_PARSE_FULL, AVSTREAM_PARSE_HEADERS,
    AVSTREAM_PARSE_TIMESTAMPS, AVSTREAM_PARSE_FULL_ONCE, AVSTREAM_PARSE_FULL_RAW

  AVAudioServiceType* = enum
    AV_AUDIO_SERVICE_TYPE_MAIN = 0, AV_AUDIO_SERVICE_TYPE_EFFECTS = 1,
    AV_AUDIO_SERVICE_TYPE_VISUALLY_IMPAIRED = 2,
    AV_AUDIO_SERVICE_TYPE_HEARING_IMPAIRED = 3, AV_AUDIO_SERVICE_TYPE_DIALOGUE = 4,
    AV_AUDIO_SERVICE_TYPE_COMMENTARY = 5, AV_AUDIO_SERVICE_TYPE_EMERGENCY = 6,
    AV_AUDIO_SERVICE_TYPE_VOICE_OVER = 7, AV_AUDIO_SERVICE_TYPE_KARAOKE = 8, AV_AUDIO_SERVICE_TYPE_NB ## /< Not part of ABI


  AVColorSpace* = enum
    AVCOL_SPC_RGB = 0, AVCOL_SPC_BT709 = 1, AVCOL_SPC_UNSPECIFIED = 2,
    AVCOL_SPC_RESERVED = 3, AVCOL_SPC_FCC = 4, AVCOL_SPC_BT470BG = 5,
    AVCOL_SPC_SMPTE170M = 6, AVCOL_SPC_SMPTE240M = 7, AVCOL_SPC_YCGCO = 8,
    AVCOL_SPC_BT2020_NCL = 9, AVCOL_SPC_BT2020_CL = 10, AVCOL_SPC_SMPTE2085 = 11,
    AVCOL_SPC_CHROMA_DERIVED_NCL = 12, AVCOL_SPC_CHROMA_DERIVED_CL = 13,
    AVCOL_SPC_ICTCP = 14, AVCOL_SPC_NB
  AVOptionType* = enum
    AV_OPT_TYPE_FLAGS, AV_OPT_TYPE_INT, AV_OPT_TYPE_INT64, AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT, AV_OPT_TYPE_STRING, AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY, AV_OPT_TYPE_DICT, AV_OPT_TYPE_UINT64, AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE, AV_OPT_TYPE_PIXEL_FMT, AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE, AV_OPT_TYPE_DURATION, AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT, AV_OPT_TYPE_BOOL

  AVEscapeMode* = enum
    AV_ESCAPE_MODE_AUTO, AV_ESCAPE_MODE_BACKSLASH, AV_ESCAPE_MODE_QUOTE


  AVMediaType* = enum
    AVMEDIA_TYPE_UNKNOWN = -1, AVMEDIA_TYPE_VIDEO, AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA, AVMEDIA_TYPE_SUBTITLE, AVMEDIA_TYPE_ATTACHMENT,
    AVMEDIA_TYPE_NB


  AVPictureType* = enum
    AV_PICTURE_TYPE_NONE = 0, AV_PICTURE_TYPE_I, AV_PICTURE_TYPE_P,
    AV_PICTURE_TYPE_B, AV_PICTURE_TYPE_S, AV_PICTURE_TYPE_SI, AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI


type
  AVRational* = ref object
    num*: int
    den*: int

  av_intfloat32* {.union.}  = ref object 
    i*: uint32
    f*: cfloat

  av_intfloat64*{.union.} = ref object 
    i*: uint64
    f*: cdouble

  AVRounding* = enum
    AV_ROUND_ZERO = 0, AV_ROUND_INF = 1, AV_ROUND_DOWN = 2, AV_ROUND_UP = 3,
    AV_ROUND_NEAR_INF = 5, AV_ROUND_PASS_MINMAX = 8192

  AVClassCategory* = enum
    AV_CLASS_CATEGORY_NA = 0, AV_CLASS_CATEGORY_INPUT, AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER, AV_CLASS_CATEGORY_DEMUXER, AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER, AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER, AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER, AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT, AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT, AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT, AV_CLASS_CATEGORY_NB
    
  AVOptionUnion* {.bycopy,union.} = object 
    i64*: int64
    dbl*: cdouble
    str*: cstring
    q*: AVRational

  AVOption* = ref object
    name*: cstring
    help*: cstring
    offset*: int
    t*: AVOptionType
    default_val*: AVOptionUnion
    min*: cdouble
    max*: cdouble
    flags*: int
    unit*: cstring

  AVOptionRange* = ref object
    str*: cstring
    value_min*: cdouble
    value_max*: cdouble
    component_min*: cdouble
    component_max*: cdouble
    is_range*: int

  AVOptionRanges* = ref object
    range*: AVOptionRange
    nb_ranges*: int
    nb_components*: int

  AVClass* = ref object
    class_name*: cstring
    item_name*: proc (ctx: pointer): cstring
    option*: AVOption
    version*: int
    log_level_offset_offset*: int
    parent_log_context_offset*: int
    child_next*: proc (obj: pointer; prev: pointer): pointer
    child_class_next*: proc (prev: AVClass): AVClass
    category*: AVClassCategory
    get_category*: proc (ctx: pointer): AVClassCategory
    query_ranges*: proc (a1: AVOptionRanges; obj: pointer; key: cstring;flags: int): int
    child_class_iterate*: proc (iter: pointer): AVClass

  AVPixelFormat* = enum
    AV_PIX_FMT_NONE = -1, AV_PIX_FMT_YUV420P, AV_PIX_FMT_YUYV422, AV_PIX_FMT_RGB24,
    AV_PIX_FMT_BGR24, AV_PIX_FMT_YUV422P, AV_PIX_FMT_YUV444P, AV_PIX_FMT_YUV410P,
    AV_PIX_FMT_YUV411P, AV_PIX_FMT_GRAY8, AV_PIX_FMT_MONOWHITE,
    AV_PIX_FMT_MONOBLACK, AV_PIX_FMT_PAL8, AV_PIX_FMT_YUVJ420P,
    AV_PIX_FMT_YUVJ422P, AV_PIX_FMT_YUVJ444P, AV_PIX_FMT_UYVY422,
    AV_PIX_FMT_UYYVYY411, AV_PIX_FMT_BGR8, AV_PIX_FMT_BGR4, AV_PIX_FMT_BGR4_BYTE,
    AV_PIX_FMT_RGB8, AV_PIX_FMT_RGB4, AV_PIX_FMT_RGB4_BYTE, AV_PIX_FMT_NV12,
    AV_PIX_FMT_NV21, AV_PIX_FMT_ARGB, AV_PIX_FMT_RGBA, AV_PIX_FMT_ABGR,
    AV_PIX_FMT_BGRA, AV_PIX_FMT_GRAY16BE, AV_PIX_FMT_GRAY16LE, AV_PIX_FMT_YUV440P,
    AV_PIX_FMT_YUVJ440P, AV_PIX_FMT_YUVA420P, AV_PIX_FMT_RGB48BE,
    AV_PIX_FMT_RGB48LE, AV_PIX_FMT_RGB565BE, AV_PIX_FMT_RGB565LE,
    AV_PIX_FMT_RGB555BE, AV_PIX_FMT_RGB555LE, AV_PIX_FMT_BGR565BE,
    AV_PIX_FMT_BGR565LE, AV_PIX_FMT_BGR555BE, AV_PIX_FMT_BGR555LE,
    AV_PIX_FMT_VAAPI_MOCO, AV_PIX_FMT_VAAPI_IDCT, AV_PIX_FMT_VAAPI_VLD,
    AV_PIX_FMT_YUV420P16LE, AV_PIX_FMT_YUV420P16BE, AV_PIX_FMT_YUV422P16LE,
    AV_PIX_FMT_YUV422P16BE, AV_PIX_FMT_YUV444P16LE, AV_PIX_FMT_YUV444P16BE,
    AV_PIX_FMT_DXVA2_VLD, AV_PIX_FMT_RGB444LE, AV_PIX_FMT_RGB444BE,
    AV_PIX_FMT_BGR444LE, AV_PIX_FMT_BGR444BE, AV_PIX_FMT_YA8, AV_PIX_FMT_BGR48BE,
    AV_PIX_FMT_BGR48LE, AV_PIX_FMT_YUV420P9BE, AV_PIX_FMT_YUV420P9LE,
    AV_PIX_FMT_YUV420P10BE, AV_PIX_FMT_YUV420P10LE, AV_PIX_FMT_YUV422P10BE,
    AV_PIX_FMT_YUV422P10LE, AV_PIX_FMT_YUV444P9BE, AV_PIX_FMT_YUV444P9LE,
    AV_PIX_FMT_YUV444P10BE, AV_PIX_FMT_YUV444P10LE, AV_PIX_FMT_YUV422P9BE,
    AV_PIX_FMT_YUV422P9LE, AV_PIX_FMT_GBRP, AV_PIX_FMT_GBRP9BE, AV_PIX_FMT_GBRP9LE,
    AV_PIX_FMT_GBRP10BE, AV_PIX_FMT_GBRP10LE, AV_PIX_FMT_GBRP16BE,
    AV_PIX_FMT_GBRP16LE, AV_PIX_FMT_YUVA422P, AV_PIX_FMT_YUVA444P,
    AV_PIX_FMT_YUVA420P9BE, AV_PIX_FMT_YUVA420P9LE, AV_PIX_FMT_YUVA422P9BE,
    AV_PIX_FMT_YUVA422P9LE, AV_PIX_FMT_YUVA444P9BE, AV_PIX_FMT_YUVA444P9LE,
    AV_PIX_FMT_YUVA420P10BE, AV_PIX_FMT_YUVA420P10LE, AV_PIX_FMT_YUVA422P10BE,
    AV_PIX_FMT_YUVA422P10LE, AV_PIX_FMT_YUVA444P10BE, AV_PIX_FMT_YUVA444P10LE,
    AV_PIX_FMT_YUVA420P16BE, AV_PIX_FMT_YUVA420P16LE, AV_PIX_FMT_YUVA422P16BE,
    AV_PIX_FMT_YUVA422P16LE, AV_PIX_FMT_YUVA444P16BE, AV_PIX_FMT_YUVA444P16LE,
    AV_PIX_FMT_VDPAU, AV_PIX_FMT_XYZ12LE, AV_PIX_FMT_XYZ12BE, AV_PIX_FMT_NV16,
    AV_PIX_FMT_NV20LE, AV_PIX_FMT_NV20BE, AV_PIX_FMT_RGBA64BE, AV_PIX_FMT_RGBA64LE,
    AV_PIX_FMT_BGRA64BE, AV_PIX_FMT_BGRA64LE, AV_PIX_FMT_YVYU422,
    AV_PIX_FMT_YA16BE, AV_PIX_FMT_YA16LE, AV_PIX_FMT_GBRAP, AV_PIX_FMT_GBRAP16BE,
    AV_PIX_FMT_GBRAP16LE, AV_PIX_FMT_QSV, AV_PIX_FMT_MMAL, AV_PIX_FMT_D3D11VA_VLD,
    AV_PIX_FMT_CUDA, AV_PIX_FMT_0RGB, AV_PIX_FMT_RGB0, AV_PIX_FMT_0BGR,
    AV_PIX_FMT_BGR0, AV_PIX_FMT_YUV420P12BE, AV_PIX_FMT_YUV420P12LE,
    AV_PIX_FMT_YUV420P14BE, AV_PIX_FMT_YUV420P14LE, AV_PIX_FMT_YUV422P12BE,
    AV_PIX_FMT_YUV422P12LE, AV_PIX_FMT_YUV422P14BE, AV_PIX_FMT_YUV422P14LE,
    AV_PIX_FMT_YUV444P12BE, AV_PIX_FMT_YUV444P12LE, AV_PIX_FMT_YUV444P14BE,
    AV_PIX_FMT_YUV444P14LE, AV_PIX_FMT_GBRP12BE, AV_PIX_FMT_GBRP12LE,
    AV_PIX_FMT_GBRP14BE, AV_PIX_FMT_GBRP14LE, AV_PIX_FMT_YUVJ411P,
    AV_PIX_FMT_BAYER_BGGR8, AV_PIX_FMT_BAYER_RGGB8, AV_PIX_FMT_BAYER_GBRG8,
    AV_PIX_FMT_BAYER_GRBG8, AV_PIX_FMT_BAYER_BGGR16LE, AV_PIX_FMT_BAYER_BGGR16BE,
    AV_PIX_FMT_BAYER_RGGB16LE, AV_PIX_FMT_BAYER_RGGB16BE,
    AV_PIX_FMT_BAYER_GBRG16LE, AV_PIX_FMT_BAYER_GBRG16BE,
    AV_PIX_FMT_BAYER_GRBG16LE, AV_PIX_FMT_BAYER_GRBG16BE, AV_PIX_FMT_XVMC,
    AV_PIX_FMT_YUV440P10LE, AV_PIX_FMT_YUV440P10BE, AV_PIX_FMT_YUV440P12LE,
    AV_PIX_FMT_YUV440P12BE, AV_PIX_FMT_AYUV64LE, AV_PIX_FMT_AYUV64BE,
    AV_PIX_FMT_VIDEOTOOLBOX, AV_PIX_FMT_P010LE, AV_PIX_FMT_P010BE,
    AV_PIX_FMT_GBRAP12BE, AV_PIX_FMT_GBRAP12LE, AV_PIX_FMT_GBRAP10BE,
    AV_PIX_FMT_GBRAP10LE, AV_PIX_FMT_MEDIACODEC, AV_PIX_FMT_GRAY12BE,
    AV_PIX_FMT_GRAY12LE, AV_PIX_FMT_GRAY10BE, AV_PIX_FMT_GRAY10LE,
    AV_PIX_FMT_P016LE, AV_PIX_FMT_P016BE, AV_PIX_FMT_D3D11, AV_PIX_FMT_GRAY9BE,
    AV_PIX_FMT_GRAY9LE, AV_PIX_FMT_GBRPF32BE, AV_PIX_FMT_GBRPF32LE,
    AV_PIX_FMT_GBRAPF32BE, AV_PIX_FMT_GBRAPF32LE, AV_PIX_FMT_DRM_PRIME,
    AV_PIX_FMT_OPENCL, AV_PIX_FMT_GRAY14BE, AV_PIX_FMT_GRAY14LE,
    AV_PIX_FMT_GRAYF32BE, AV_PIX_FMT_GRAYF32LE, AV_PIX_FMT_YUVA422P12BE,
    AV_PIX_FMT_YUVA422P12LE, AV_PIX_FMT_YUVA444P12BE, AV_PIX_FMT_YUVA444P12LE,
    AV_PIX_FMT_NV24, AV_PIX_FMT_NV42, AV_PIX_FMT_VULKAN, AV_PIX_FMT_Y210BE,
    AV_PIX_FMT_Y210LE, AV_PIX_FMT_X2RGB10LE, AV_PIX_FMT_X2RGB10BE, AV_PIX_FMT_NB


  AVColorTransferCharacteristic* = enum
    AVCOL_TRC_RESERVED0 = 0, AVCOL_TRC_BT709 = 1, AVCOL_TRC_UNSPECIFIED = 2,
    AVCOL_TRC_RESERVED = 3, AVCOL_TRC_GAMMA22 = 4, AVCOL_TRC_GAMMA28 = 5,
    AVCOL_TRC_SMPTE170M = 6, AVCOL_TRC_SMPTE240M = 7, AVCOL_TRC_LINEAR = 8,
    AVCOL_TRC_LOG = 9, AVCOL_TRC_LOG_SQRT = 10, AVCOL_TRC_IEC61966_2_4 = 11,
    AVCOL_TRC_BT1361_ECG = 12, AVCOL_TRC_IEC61966_2_1 = 13, AVCOL_TRC_BT2020_10 = 14,
    AVCOL_TRC_BT2020_12 = 15, AVCOL_TRC_SMPTE2084 = 16, AVCOL_TRC_SMPTE428 = 17,
    AVCOL_TRC_ARIB_STD_B67 = 18, AVCOL_TRC_NB

const
  AVCOL_TRC_SMPTEST2084 = AVCOL_TRC_SMPTE2084
  AVCOL_TRC_SMPTEST428_1 = AVCOL_TRC_SMPTE428
  AV_PIX_FMT_VAAPI = AV_PIX_FMT_VAAPI_VLD
  AV_PIX_FMT_Y400A = AV_PIX_FMT_YA8
  AV_PIX_FMT_GRAY8A = AV_PIX_FMT_YA8
  AV_PIX_FMT_GBR24P = AV_PIX_FMT_GBRP
  AVCOL_SPC_YCOCG = AVCOL_SPC_YCGCO


type
  AVColorRange* = enum
    AVCOL_RANGE_UNSPECIFIED = 0, AVCOL_RANGE_MPEG = 1, AVCOL_RANGE_JPEG = 2,
    AVCOL_RANGE_NB

type
  AVChromaLocation* = enum
    AVCHROMA_LOC_UNSPECIFIED = 0, AVCHROMA_LOC_LEFT = 1, AVCHROMA_LOC_CENTER = 2,
    AVCHROMA_LOC_TOPLEFT = 3, AVCHROMA_LOC_TOP = 4, AVCHROMA_LOC_BOTTOMLEFT = 5,
    AVCHROMA_LOC_BOTTOM = 6, AVCHROMA_LOC_NB

type
  AVComponentDescriptor* = tuple
    plane: int
    step: int
    offset: int
    shift: int
    depth: int
    step_minus1: int
    depth_minus1: int
    offset_plus1: int

  AVPixFmtDescriptor* = ref object
    name*: cstring
    nb_components*: uint8
    log2_chroma_w*: uint8
    log2_chroma_h*: uint8
    flags*: uint64
    comp*: seq[AVComponentDescriptor]
    alias*: cstring

  AVDictionaryEntry* = ref object
    key*: cstring
    value*: cstring

  AVSampleFormat* = enum
    AV_SAMPLE_FMT_NONE = -1, AV_SAMPLE_FMT_U8, AV_SAMPLE_FMT_S16, AV_SAMPLE_FMT_S32,
    AV_SAMPLE_FMT_FLT, AV_SAMPLE_FMT_DBL, AV_SAMPLE_FMT_U8P, AV_SAMPLE_FMT_S16P,
    AV_SAMPLE_FMT_S32P, AV_SAMPLE_FMT_FLTP, AV_SAMPLE_FMT_DBLP, AV_SAMPLE_FMT_S64,
    AV_SAMPLE_FMT_S64P, AV_SAMPLE_FMT_NB

type
  AVBuffer* = ref object
    data*: ptr uint8
    size*: int  
    refcount*: int64
    free*: proc (opaque: pointer; data: uint8) 
    opaque*: pointer           
    flags*: cint 
    flagsInternal*: cint

type
  AVBufferRef* = ref object
    buffer*: AVBuffer
    data*: ptr uint8
    size*: int

  AVMatrixEncoding* = enum
    AV_MATRIX_ENCODING_NONE, AV_MATRIX_ENCODING_DOLBY, AV_MATRIX_ENCODING_DPLII,
    AV_MATRIX_ENCODING_DPLIIX, AV_MATRIX_ENCODING_DPLIIZ,
    AV_MATRIX_ENCODING_DOLBYEX, AV_MATRIX_ENCODING_DOLBYHEADPHONE,
    AV_MATRIX_ENCODING_NB

type
  AVFrameSideDataType* = enum
    AV_FRAME_DATA_PANSCAN, AV_FRAME_DATA_A53_CC, AV_FRAME_DATA_STEREO3D,
    AV_FRAME_DATA_MATRIXENCODING, AV_FRAME_DATA_DOWNMIX_INFO,
    AV_FRAME_DATA_REPLAYGAIN, AV_FRAME_DATA_DISPLAYMATRIX, AV_FRAME_DATA_AFD,
    AV_FRAME_DATA_MOTION_VECTORS, AV_FRAME_DATA_SKIP_SAMPLES,
    AV_FRAME_DATA_AUDIO_SERVICE_TYPE, AV_FRAME_DATA_MASTERING_DISPLAY_METADATA,
    AV_FRAME_DATA_GOP_TIMECODE, AV_FRAME_DATA_SPHERICAL,
    AV_FRAME_DATA_CONTENT_LIGHT_LEVEL, AV_FRAME_DATA_ICC_PROFILE,
    AV_FRAME_DATA_QP_TABLE_PROPERTIES, AV_FRAME_DATA_QP_TABLE_DATA,
    AV_FRAME_DATA_S12M_TIMECODE, AV_FRAME_DATA_DYNAMIC_HDR_PLUS,
    AV_FRAME_DATA_REGIONS_OF_INTEREST, AV_FRAME_DATA_VIDEO_ENC_PARAMS,
    AV_FRAME_DATA_SEI_UNREGISTERED

type
  AVActiveFormatDescription* = enum
    AV_AFD_SAME = 8, AV_AFD_4_3 = 9, AV_AFD_16_9 = 10, AV_AFD_14_9 = 11,
    AV_AFD_4_3_SP_14_9 = 13, AV_AFD_16_9_SP_14_9 = 14, AV_AFD_SP_4_3 = 15


type
  AVFrameSideData* = ref object
    t*: AVFrameSideDataType
    data*: uint8
    size*: int
    metadata*: OrderedTable[string,string]
    buf*: AVBufferRef

  AVRegionOfInterest* = ref object
    self_size*: uint32
    top*: int
    bottom*: int
    left*: int
    right*: int
    qoffset*: AVRational

  AVFrame* = ref object
    data*: seq[ptr uint8]
    linesize*: seq[int]
    extended_data*: seq[uint8]
    width*: int
    height*: int
    nb_samples*: int
    format*: int
    key_frame*: int
    pict_type*: AVPictureType
    sample_aspect_ratio*: AVRational
    pts*: int64
    pkt_pts*: int64
    pkt_dts*: int64
    coded_picture_number*: int
    display_picture_number*: int
    quality*: int
    opaque*: pointer
    error*: array[8, uint64]
    repeat_pict*: int
    interlaced_frame*: int
    top_field_first*: int
    palette_has_changed*: int
    reordered_opaque*: int64
    sample_rate*: int
    channel_layout*: uint64
    buf*: seq[AVBufferRef]
    extended_buf*: seq[AVBufferRef]
    nb_extended_buf*: int
    side_data*: AVFrameSideData
    nb_side_data*: int
    flags*: int
    color_range*: AVColorRange
    color_primaries*: AVColorPrimaries
    color_trc*: AVColorTransferCharacteristic
    colorspace*: AVColorSpace
    chroma_location*: AVChromaLocation
    best_effort_timestamp*: int64
    pkt_pos*: int64
    pkt_duration*: int64
    metadata*: OrderedTable[string,string]
    decode_error_flags*: int
    channels*: int
    pkt_size*: int
    qscale_table*: int8
    qstride*: int
    qscale_type*: int
    qp_table_buf*: AVBufferRef
    hw_frames_ctx*: AVBufferRef
    opaque_ref*: AVBufferRef
    crop_top*: uint
    crop_bottom*: uint
    crop_left*: uint
    crop_right*: uint
    private_ref*: AVBufferRef

  AVHWDeviceType* = enum
    AV_HWDEVICE_TYPE_NONE, AV_HWDEVICE_TYPE_VDPAU, AV_HWDEVICE_TYPE_CUDA,
    AV_HWDEVICE_TYPE_VAAPI, AV_HWDEVICE_TYPE_DXVA2, AV_HWDEVICE_TYPE_QSV,
    AV_HWDEVICE_TYPE_VIDEOTOOLBOX, AV_HWDEVICE_TYPE_D3D11VA, AV_HWDEVICE_TYPE_DRM,
    AV_HWDEVICE_TYPE_OPENCL, AV_HWDEVICE_TYPE_MEDIACODEC, AV_HWDEVICE_TYPE_VULKAN

type
  AVHWFrameTransferDirection* = enum 
    AV_HWFRAME_TRANSFER_DIRECTION_FROM, 
    AV_HWFRAME_TRANSFER_DIRECTION_TO

  HWContextType* = ref object
    t*: AVHWDeviceType
    name*: cstring 
    pixFmts*: AVPixelFormat 
    deviceHwctxSize*: uint  
    devicePrivSize*: uint 
    deviceHwconfigSize*: uint 
    framesHwctxSize*: uint  
    framesPrivSize*: uint
    deviceCreate*: proc (ctx: AVHWDeviceContext; device: cstring;
                       opts: OrderedTableRef[string,string]; flags: cint): cint
    deviceDerive*: proc (dstCtx: AVHWDeviceContext;
                       srcCtx: AVHWDeviceContext; opts: OrderedTableRef[string,string];
                       flags: cint): cint
    deviceInit*: proc (ctx: AVHWDeviceContext): cint
    deviceUninit*: proc (ctx: AVHWDeviceContext)
    framesGetConstraints*: proc (ctx: AVHWDeviceContext; hwconfig: pointer;
                               constraints: AVHWFramesConstraints): cint
    framesInit*: proc (ctx: AVHWFramesContext): cint
    framesUninit*: proc (ctx: AVHWFramesContext)
    framesGetBuffer*: proc (ctx: AVHWFramesContext; frame: AVFrame): cint
    transferGetFormats*: proc (ctx: AVHWFramesContext;dir: AVHWFrameTransferDirection;formats: AVPixelFormat): cint
    transferDataTo*: proc (ctx: AVHWFramesContext; dst: AVFrame;
                         src: AVFrame): cint
    transferDataFrom*: proc (ctx: AVHWFramesContext; dst: AVFrame;
                           src: AVFrame): cint
    mapTo*: proc (ctx: ptr AVHWFramesContext; dst: AVFrame; src: AVFrame;
                flags: cint): cint
    mapFrom*: proc (ctx: ptr AVHWFramesContext; dst: AVFrame; src: AVFrame;
                  flags: cint): cint
    framesDeriveTo*: proc (dstCtx: AVHWFramesContext;
                         srcCtx: AVHWFramesContext; flags: cint): cint
    framesDeriveFrom*: proc (dstCtx: AVHWFramesContext;
                           srcCtx: AVHWFramesContext; flags: cint): cint


  AVHWDeviceInternal* = ref object
    hwType*: HWContextType
    priv*: pointer 
    sourceDevice*: AVBufferRef

  AVHWDeviceContext* = ref object
    av_class*: AVClass
    internal*: AVHWDeviceInternal
    t*: AVHWDeviceType
    hwctx*: pointer
    free*: proc (ctx: AVHWDeviceContext)
    user_opaque*: pointer

  AVBufferPool* = ref object
    # mutex*: AVMutex
    # pool*: ptr BufferPoolEntry
    refcount*: int
    size*: cint
    opaque*: pointer
    alloc*: proc (size: cint): ptr AVBufferRef
    alloc2*: proc (opaque: pointer; size: cint): ptr AVBufferRef
    poolFree*: proc (opaque: pointer)



  AVHWFramesInternal* = ref object
    hwType*: HWContextType
    priv*: pointer
    poolInternal*: AVBufferPool 
    sourceFrames*: AVBufferRef 
    sourceAllocationMapFlags*: cint


  AVHWFramesContext* = ref object
    av_class*: AVClass
    internal*: AVHWFramesInternal
    device_ref*: AVBufferRef
    device_ctx*: AVHWDeviceContext
    hwctx*: pointer
    free*: proc (ctx: AVHWFramesContext)
    user_opaque*: pointer
    pool*: AVBufferPool
    initial_pool_size*: int
    format*: AVPixelFormat
    sw_format*: AVPixelFormat
    width*: int
    height*: int

  AVHWFramesConstraints* = ref object
    valid_hw_formats*: AVPixelFormat
    valid_sw_formats*: AVPixelFormat
    min_width*: int
    min_height*: int
    max_width*: int
    max_height*: int


const
  AV_HWFRAME_MAP_READ* = 1 shl 0
  AV_HWFRAME_MAP_WRITE* = 1 shl 1
  AV_HWFRAME_MAP_OVERWRITE* = 1 shl 2
  AV_HWFRAME_MAP_DIRECT* = 1 shl 3

type
  AVCodecID* = enum
    AV_CODEC_ID_NONE, AV_CODEC_ID_MPEG1VIDEO, AV_CODEC_ID_MPEG2VIDEO,
    AV_CODEC_ID_H261, AV_CODEC_ID_H263, AV_CODEC_ID_RV10, AV_CODEC_ID_RV20,
    AV_CODEC_ID_MJPEG, AV_CODEC_ID_MJPEGB, AV_CODEC_ID_LJPEG, AV_CODEC_ID_SP5X,
    AV_CODEC_ID_JPEGLS, AV_CODEC_ID_MPEG4, AV_CODEC_ID_RAWVIDEO,
    AV_CODEC_ID_MSMPEG4V1, AV_CODEC_ID_MSMPEG4V2, AV_CODEC_ID_MSMPEG4V3,
    AV_CODEC_ID_WMV1, AV_CODEC_ID_WMV2, AV_CODEC_ID_H263P, AV_CODEC_ID_H263I,
    AV_CODEC_ID_FLV1, AV_CODEC_ID_SVQ1, AV_CODEC_ID_SVQ3, AV_CODEC_ID_DVVIDEO,
    AV_CODEC_ID_HUFFYUV, AV_CODEC_ID_CYUV, AV_CODEC_ID_H264, AV_CODEC_ID_INDEO3,
    AV_CODEC_ID_VP3, AV_CODEC_ID_THEORA, AV_CODEC_ID_ASV1, AV_CODEC_ID_ASV2,
    AV_CODEC_ID_FFV1, AV_CODEC_ID_4XM, AV_CODEC_ID_VCR1, AV_CODEC_ID_CLJR,
    AV_CODEC_ID_MDEC, AV_CODEC_ID_ROQ, AV_CODEC_ID_INTERPLAY_VIDEO,
    AV_CODEC_ID_XAN_WC3, AV_CODEC_ID_XAN_WC4, AV_CODEC_ID_RPZA,
    AV_CODEC_ID_CINEPAK, AV_CODEC_ID_WS_VQA, AV_CODEC_ID_MSRLE,
    AV_CODEC_ID_MSVIDEO1, AV_CODEC_ID_IDCIN, AV_CODEC_ID_8BPS, AV_CODEC_ID_SMC,
    AV_CODEC_ID_FLIC, AV_CODEC_ID_TRUEMOTION1, AV_CODEC_ID_VMDVIDEO,
    AV_CODEC_ID_MSZH, AV_CODEC_ID_ZLIB, AV_CODEC_ID_QTRLE, AV_CODEC_ID_TSCC,
    AV_CODEC_ID_ULTI, AV_CODEC_ID_QDRAW, AV_CODEC_ID_VIXL, AV_CODEC_ID_QPEG,
    AV_CODEC_ID_PNG, AV_CODEC_ID_PPM, AV_CODEC_ID_PBM, AV_CODEC_ID_PGM,
    AV_CODEC_ID_PGMYUV, AV_CODEC_ID_PAM, AV_CODEC_ID_FFVHUFF, AV_CODEC_ID_RV30,
    AV_CODEC_ID_RV40, AV_CODEC_ID_VC1, AV_CODEC_ID_WMV3, AV_CODEC_ID_LOCO,
    AV_CODEC_ID_WNV1, AV_CODEC_ID_AASC, AV_CODEC_ID_INDEO2, AV_CODEC_ID_FRAPS,
    AV_CODEC_ID_TRUEMOTION2, AV_CODEC_ID_BMP, AV_CODEC_ID_CSCD,
    AV_CODEC_ID_MMVIDEO, AV_CODEC_ID_ZMBV, AV_CODEC_ID_AVS, AV_CODEC_ID_SMACKVIDEO,
    AV_CODEC_ID_NUV, AV_CODEC_ID_KMVC, AV_CODEC_ID_FLASHSV, AV_CODEC_ID_CAVS,
    AV_CODEC_ID_JPEG2000, AV_CODEC_ID_VMNC, AV_CODEC_ID_VP5, AV_CODEC_ID_VP6,
    AV_CODEC_ID_VP6F, AV_CODEC_ID_TARGA, AV_CODEC_ID_DSICINVIDEO,
    AV_CODEC_ID_TIERTEXSEQVIDEO, AV_CODEC_ID_TIFF, AV_CODEC_ID_GIF,
    AV_CODEC_ID_DXA, AV_CODEC_ID_DNXHD, AV_CODEC_ID_THP, AV_CODEC_ID_SGI,
    AV_CODEC_ID_C93, AV_CODEC_ID_BETHSOFTVID, AV_CODEC_ID_PTX, AV_CODEC_ID_TXD,
    AV_CODEC_ID_VP6A, AV_CODEC_ID_AMV, AV_CODEC_ID_VB, AV_CODEC_ID_PCX,
    AV_CODEC_ID_SUNRAST, AV_CODEC_ID_INDEO4, AV_CODEC_ID_INDEO5, AV_CODEC_ID_MIMIC,
    AV_CODEC_ID_RL2, AV_CODEC_ID_ESCAPE124, AV_CODEC_ID_DIRAC, AV_CODEC_ID_BFI,
    AV_CODEC_ID_CMV, AV_CODEC_ID_MOTIONPIXELS, AV_CODEC_ID_TGV, AV_CODEC_ID_TGQ,
    AV_CODEC_ID_TQI, AV_CODEC_ID_AURA, AV_CODEC_ID_AURA2, AV_CODEC_ID_V210X,
    AV_CODEC_ID_TMV, AV_CODEC_ID_V210, AV_CODEC_ID_DPX, AV_CODEC_ID_MAD,
    AV_CODEC_ID_FRWU, AV_CODEC_ID_FLASHSV2, AV_CODEC_ID_CDGRAPHICS,
    AV_CODEC_ID_R210, AV_CODEC_ID_ANM, AV_CODEC_ID_BINKVIDEO, AV_CODEC_ID_IFF_ILBM,
    AV_CODEC_ID_KGV1, AV_CODEC_ID_YOP, AV_CODEC_ID_VP8, AV_CODEC_ID_PICTOR,
    AV_CODEC_ID_ANSI, AV_CODEC_ID_A64_MULTI, AV_CODEC_ID_A64_MULTI5,
    AV_CODEC_ID_R10K, AV_CODEC_ID_MXPEG, AV_CODEC_ID_LAGARITH, AV_CODEC_ID_PRORES,
    AV_CODEC_ID_JV, AV_CODEC_ID_DFA, AV_CODEC_ID_WMV3IMAGE, AV_CODEC_ID_VC1IMAGE,
    AV_CODEC_ID_UTVIDEO, AV_CODEC_ID_BMV_VIDEO, AV_CODEC_ID_VBLE,
    AV_CODEC_ID_DXTORY, AV_CODEC_ID_V410, AV_CODEC_ID_XWD, AV_CODEC_ID_CDXL,
    AV_CODEC_ID_XBM, AV_CODEC_ID_ZEROCODEC, AV_CODEC_ID_MSS1, AV_CODEC_ID_MSA1,
    AV_CODEC_ID_TSCC2, AV_CODEC_ID_MTS2, AV_CODEC_ID_CLLC, AV_CODEC_ID_MSS2,
    AV_CODEC_ID_VP9, AV_CODEC_ID_AIC, AV_CODEC_ID_ESCAPE130, AV_CODEC_ID_G2M,
    AV_CODEC_ID_WEBP, AV_CODEC_ID_HNM4_VIDEO, AV_CODEC_ID_HEVC, AV_CODEC_ID_FIC,
    AV_CODEC_ID_ALIAS_PIX, AV_CODEC_ID_BRENDER_PIX, AV_CODEC_ID_PAF_VIDEO,
    AV_CODEC_ID_EXR, AV_CODEC_ID_VP7, AV_CODEC_ID_SANM, AV_CODEC_ID_SGIRLE,
    AV_CODEC_ID_MVC1, AV_CODEC_ID_MVC2, AV_CODEC_ID_HQX, AV_CODEC_ID_TDSC,
    AV_CODEC_ID_HQ_HQA, AV_CODEC_ID_HAP, AV_CODEC_ID_DDS, AV_CODEC_ID_DXV,
    AV_CODEC_ID_SCREENPRESSO, AV_CODEC_ID_RSCC, AV_CODEC_ID_AVS2, AV_CODEC_ID_PGX,
    AV_CODEC_ID_AVS3, AV_CODEC_ID_Y41P = 0x00008000, AV_CODEC_ID_AVRP,
    AV_CODEC_ID_012V, AV_CODEC_ID_AVUI, AV_CODEC_ID_AYUV, AV_CODEC_ID_TARGA_Y216,
    AV_CODEC_ID_V308, AV_CODEC_ID_V408, AV_CODEC_ID_YUV4, AV_CODEC_ID_AVRN,
    AV_CODEC_ID_CPIA, AV_CODEC_ID_XFACE, AV_CODEC_ID_SNOW, AV_CODEC_ID_SMVJPEG,
    AV_CODEC_ID_APNG, AV_CODEC_ID_DAALA, AV_CODEC_ID_CFHD,
    AV_CODEC_ID_TRUEMOTION2RT, AV_CODEC_ID_M101, AV_CODEC_ID_MAGICYUV,
    AV_CODEC_ID_SHEERVIDEO, AV_CODEC_ID_YLC, AV_CODEC_ID_PSD, AV_CODEC_ID_PIXLET,
    AV_CODEC_ID_SPEEDHQ, AV_CODEC_ID_FMVC, AV_CODEC_ID_SCPR,
    AV_CODEC_ID_CLEARVIDEO, AV_CODEC_ID_XPM, AV_CODEC_ID_AV1,
    AV_CODEC_ID_BITPACKED, AV_CODEC_ID_MSCC, AV_CODEC_ID_SRGC, AV_CODEC_ID_SVG,
    AV_CODEC_ID_GDV, AV_CODEC_ID_FITS, AV_CODEC_ID_IMM4, AV_CODEC_ID_PROSUMER,
    AV_CODEC_ID_MWSC, AV_CODEC_ID_WCMV, AV_CODEC_ID_RASC, AV_CODEC_ID_HYMT,
    AV_CODEC_ID_ARBC, AV_CODEC_ID_AGM, AV_CODEC_ID_LSCR, AV_CODEC_ID_VP4,
    AV_CODEC_ID_IMM5, AV_CODEC_ID_MVDV, AV_CODEC_ID_MVHA, AV_CODEC_ID_CDTOONS,
    AV_CODEC_ID_MV30, AV_CODEC_ID_NOTCHLC, AV_CODEC_ID_PFM, AV_CODEC_ID_MOBICLIP,
    AV_CODEC_ID_PHOTOCD, AV_CODEC_ID_IPU, AV_CODEC_ID_ARGO, AV_CODEC_ID_CRI,
    AV_CODEC_ID_FIRST_AUDIO = 0x00010000, AV_CODEC_ID_PCM_S16BE,
    AV_CODEC_ID_PCM_U16LE, AV_CODEC_ID_PCM_U16BE, AV_CODEC_ID_PCM_S8,
    AV_CODEC_ID_PCM_U8, AV_CODEC_ID_PCM_MULAW, AV_CODEC_ID_PCM_ALAW,
    AV_CODEC_ID_PCM_S32LE, AV_CODEC_ID_PCM_S32BE, AV_CODEC_ID_PCM_U32LE,
    AV_CODEC_ID_PCM_U32BE, AV_CODEC_ID_PCM_S24LE, AV_CODEC_ID_PCM_S24BE,
    AV_CODEC_ID_PCM_U24LE, AV_CODEC_ID_PCM_U24BE, AV_CODEC_ID_PCM_S24DAUD,
    AV_CODEC_ID_PCM_ZORK, AV_CODEC_ID_PCM_S16LE_PLANAR, AV_CODEC_ID_PCM_DVD,
    AV_CODEC_ID_PCM_F32BE, AV_CODEC_ID_PCM_F32LE, AV_CODEC_ID_PCM_F64BE,
    AV_CODEC_ID_PCM_F64LE, AV_CODEC_ID_PCM_BLURAY, AV_CODEC_ID_PCM_LXF,
    AV_CODEC_ID_S302M, AV_CODEC_ID_PCM_S8_PLANAR, AV_CODEC_ID_PCM_S24LE_PLANAR,
    AV_CODEC_ID_PCM_S32LE_PLANAR, AV_CODEC_ID_PCM_S16BE_PLANAR,
    AV_CODEC_ID_PCM_S64LE = 0x00010800, AV_CODEC_ID_PCM_S64BE,
    AV_CODEC_ID_PCM_F16LE, AV_CODEC_ID_PCM_F24LE, AV_CODEC_ID_PCM_VIDC,
    AV_CODEC_ID_ADPCM_IMA_QT = 0x00011000, AV_CODEC_ID_ADPCM_IMA_WAV,
    AV_CODEC_ID_ADPCM_IMA_DK3, AV_CODEC_ID_ADPCM_IMA_DK4,
    AV_CODEC_ID_ADPCM_IMA_WS, AV_CODEC_ID_ADPCM_IMA_SMJPEG, AV_CODEC_ID_ADPCM_MS,
    AV_CODEC_ID_ADPCM_4XM, AV_CODEC_ID_ADPCM_XA, AV_CODEC_ID_ADPCM_ADX,
    AV_CODEC_ID_ADPCM_EA, AV_CODEC_ID_ADPCM_G726, AV_CODEC_ID_ADPCM_CT,
    AV_CODEC_ID_ADPCM_SWF, AV_CODEC_ID_ADPCM_YAMAHA, AV_CODEC_ID_ADPCM_SBPRO_4,
    AV_CODEC_ID_ADPCM_SBPRO_3, AV_CODEC_ID_ADPCM_SBPRO_2, AV_CODEC_ID_ADPCM_THP,
    AV_CODEC_ID_ADPCM_IMA_AMV, AV_CODEC_ID_ADPCM_EA_R1, AV_CODEC_ID_ADPCM_EA_R3,
    AV_CODEC_ID_ADPCM_EA_R2, AV_CODEC_ID_ADPCM_IMA_EA_SEAD,
    AV_CODEC_ID_ADPCM_IMA_EA_EACS, AV_CODEC_ID_ADPCM_EA_XAS,
    AV_CODEC_ID_ADPCM_EA_MAXIS_XA, AV_CODEC_ID_ADPCM_IMA_ISS,
    AV_CODEC_ID_ADPCM_G722, AV_CODEC_ID_ADPCM_IMA_APC, AV_CODEC_ID_ADPCM_VIMA,
    AV_CODEC_ID_ADPCM_AFC = 0x00011800, AV_CODEC_ID_ADPCM_IMA_OKI,
    AV_CODEC_ID_ADPCM_DTK, AV_CODEC_ID_ADPCM_IMA_RAD, AV_CODEC_ID_ADPCM_G726LE,
    AV_CODEC_ID_ADPCM_THP_LE, AV_CODEC_ID_ADPCM_PSX, AV_CODEC_ID_ADPCM_AICA,
    AV_CODEC_ID_ADPCM_IMA_DAT4, AV_CODEC_ID_ADPCM_MTAF, AV_CODEC_ID_ADPCM_AGM,
    AV_CODEC_ID_ADPCM_ARGO, AV_CODEC_ID_ADPCM_IMA_SSI, AV_CODEC_ID_ADPCM_ZORK,
    AV_CODEC_ID_ADPCM_IMA_APM, AV_CODEC_ID_ADPCM_IMA_ALP,
    AV_CODEC_ID_ADPCM_IMA_MTF, AV_CODEC_ID_ADPCM_IMA_CUNNING,
    AV_CODEC_ID_ADPCM_IMA_MOFLEX, AV_CODEC_ID_AMR_NB = 0x00012000,
    AV_CODEC_ID_AMR_WB, AV_CODEC_ID_RA_144 = 0x00013000, AV_CODEC_ID_RA_288,
    AV_CODEC_ID_ROQ_DPCM = 0x00014000, AV_CODEC_ID_INTERPLAY_DPCM,
    AV_CODEC_ID_XAN_DPCM, AV_CODEC_ID_SOL_DPCM,
    AV_CODEC_ID_SDX2_DPCM = 0x00014800, AV_CODEC_ID_GREMLIN_DPCM,
    AV_CODEC_ID_DERF_DPCM, AV_CODEC_ID_MP2 = 0x00015000, AV_CODEC_ID_MP3,
    AV_CODEC_ID_AAC, AV_CODEC_ID_AC3, AV_CODEC_ID_DTS, AV_CODEC_ID_VORBIS,
    AV_CODEC_ID_DVAUDIO, AV_CODEC_ID_WMAV1, AV_CODEC_ID_WMAV2, AV_CODEC_ID_MACE3,
    AV_CODEC_ID_MACE6, AV_CODEC_ID_VMDAUDIO, AV_CODEC_ID_FLAC, AV_CODEC_ID_MP3ADU,
    AV_CODEC_ID_MP3ON4, AV_CODEC_ID_SHORTEN, AV_CODEC_ID_ALAC,
    AV_CODEC_ID_WESTWOOD_SND1, AV_CODEC_ID_GSM, AV_CODEC_ID_QDM2, AV_CODEC_ID_COOK,
    AV_CODEC_ID_TRUESPEECH, AV_CODEC_ID_TTA, AV_CODEC_ID_SMACKAUDIO,
    AV_CODEC_ID_QCELP, AV_CODEC_ID_WAVPACK, AV_CODEC_ID_DSICINAUDIO,
    AV_CODEC_ID_IMC, AV_CODEC_ID_MUSEPACK7, AV_CODEC_ID_MLP, AV_CODEC_ID_GSM_MS,
    AV_CODEC_ID_ATRAC3, AV_CODEC_ID_APE, AV_CODEC_ID_NELLYMOSER,
    AV_CODEC_ID_MUSEPACK8, AV_CODEC_ID_SPEEX, AV_CODEC_ID_WMAVOICE,
    AV_CODEC_ID_WMAPRO, AV_CODEC_ID_WMALOSSLESS, AV_CODEC_ID_ATRAC3P,
    AV_CODEC_ID_EAC3, AV_CODEC_ID_SIPR, AV_CODEC_ID_MP1, AV_CODEC_ID_TWINVQ,
    AV_CODEC_ID_TRUEHD, AV_CODEC_ID_MP4ALS, AV_CODEC_ID_ATRAC1,
    AV_CODEC_ID_BINKAUDIO_RDFT, AV_CODEC_ID_BINKAUDIO_DCT, AV_CODEC_ID_AAC_LATM,
    AV_CODEC_ID_QDMC, AV_CODEC_ID_CELT, AV_CODEC_ID_G723_1, AV_CODEC_ID_G729,
    AV_CODEC_ID_8SVX_EXP, AV_CODEC_ID_8SVX_FIB, AV_CODEC_ID_BMV_AUDIO,
    AV_CODEC_ID_RALF, AV_CODEC_ID_IAC, AV_CODEC_ID_ILBC, AV_CODEC_ID_OPUS,
    AV_CODEC_ID_COMFORT_NOISE, AV_CODEC_ID_TAK, AV_CODEC_ID_METASOUND,
    AV_CODEC_ID_PAF_AUDIO, AV_CODEC_ID_ON2AVC, AV_CODEC_ID_DSS_SP,
    AV_CODEC_ID_CODEC2, AV_CODEC_ID_FFWAVESYNTH = 0x00015800, AV_CODEC_ID_SONIC,
    AV_CODEC_ID_SONIC_LS, AV_CODEC_ID_EVRC, AV_CODEC_ID_SMV, AV_CODEC_ID_DSD_LSBF,
    AV_CODEC_ID_DSD_MSBF, AV_CODEC_ID_DSD_LSBF_PLANAR,
    AV_CODEC_ID_DSD_MSBF_PLANAR, AV_CODEC_ID_4GV, AV_CODEC_ID_INTERPLAY_ACM,
    AV_CODEC_ID_XMA1, AV_CODEC_ID_XMA2, AV_CODEC_ID_DST, AV_CODEC_ID_ATRAC3AL,
    AV_CODEC_ID_ATRAC3PAL, AV_CODEC_ID_DOLBY_E, AV_CODEC_ID_APTX,
    AV_CODEC_ID_APTX_HD, AV_CODEC_ID_SBC, AV_CODEC_ID_ATRAC9, AV_CODEC_ID_HCOM,
    AV_CODEC_ID_ACELP_KELVIN, AV_CODEC_ID_MPEGH_3D_AUDIO, AV_CODEC_ID_SIREN,
    AV_CODEC_ID_HCA, AV_CODEC_ID_FASTAUDIO,
    AV_CODEC_ID_FIRST_SUBTITLE = 0x00017000, AV_CODEC_ID_DVB_SUBTITLE,
    AV_CODEC_ID_TEXT, AV_CODEC_ID_XSUB, AV_CODEC_ID_SSA, AV_CODEC_ID_MOV_TEXT,
    AV_CODEC_ID_HDMV_PGS_SUBTITLE, AV_CODEC_ID_DVB_TELETEXT, AV_CODEC_ID_SRT,
    AV_CODEC_ID_MICRODVD = 0x00017800, AV_CODEC_ID_EIA_608, AV_CODEC_ID_JACOSUB,
    AV_CODEC_ID_SAMI, AV_CODEC_ID_REALTEXT, AV_CODEC_ID_STL,
    AV_CODEC_ID_SUBVIEWER1, AV_CODEC_ID_SUBVIEWER, AV_CODEC_ID_SUBRIP,
    AV_CODEC_ID_WEBVTT, AV_CODEC_ID_MPL2, AV_CODEC_ID_VPLAYER, AV_CODEC_ID_PJS,
    AV_CODEC_ID_ASS, AV_CODEC_ID_HDMV_TEXT_SUBTITLE, AV_CODEC_ID_TTML,
    AV_CODEC_ID_ARIB_CAPTION, AV_CODEC_ID_FIRST_UNKNOWN = 0x00018000,
    AV_CODEC_ID_SCTE_35, AV_CODEC_ID_EPG, AV_CODEC_ID_BINTEXT = 0x00018800,
    AV_CODEC_ID_XBIN, AV_CODEC_ID_IDF, AV_CODEC_ID_OTF, AV_CODEC_ID_SMPTE_KLV,
    AV_CODEC_ID_DVD_NAV, AV_CODEC_ID_TIMED_ID3, AV_CODEC_ID_BIN_DATA,
    AV_CODEC_ID_PROBE = 0x00019000, AV_CODEC_ID_MPEG2TS = 0x00020000,
    AV_CODEC_ID_MPEG4SYSTEMS = 0x00020001, AV_CODEC_ID_FFMETADATA = 0x00021000,
    AV_CODEC_ID_WRAPPED_AVFRAME = 0x00021001

const
  AV_CODEC_ID_PCM_S16LE = AV_CODEC_ID_FIRST_AUDIO
  AV_CODEC_ID_DVD_SUBTITLE = AV_CODEC_ID_FIRST_SUBTITLE
  AV_CODEC_ID_TTF = AV_CODEC_ID_FIRST_UNKNOWN

type
  AVFieldOrder* = enum
    AV_FIELD_UNKNOWN, AV_FIELD_PROGRESSIVE, AV_FIELD_TT, AV_FIELD_BB, AV_FIELD_TB,
    AV_FIELD_BT


type
  AVCodecParameters* = ref object
    codec_type*: AVMediaType
    codec_id*: AVCodecID
    codec_tag*: uint32
    extradata*: uint8
    extradata_size*: int
    format*: int
    bit_rate*: int64
    bits_per_coded_sample*: int
    bits_per_raw_sample*: int
    profile*: int
    level*: int
    width*: int
    height*: int
    sample_aspect_ratio*: AVRational
    field_order*: AVFieldOrder
    color_range*: AVColorRange
    color_primaries*: AVColorPrimaries
    color_trc*: AVColorTransferCharacteristic
    color_space*: AVColorSpace
    chroma_location*: AVChromaLocation
    video_delay*: int
    channel_layout*: uint64
    channels*: int
    sample_rate*: int
    block_align*: int
    frame_size*: int
    initial_padding*: int
    trailing_padding*: int
    seek_preroll*: int

  AVPacketSideDataType* = enum
    AV_PKT_DATA_PALETTE, AV_PKT_DATA_NEW_EXTRADATA, AV_PKT_DATA_PARAM_CHANGE,
    AV_PKT_DATA_H263_MB_INFO, AV_PKT_DATA_REPLAYGAIN, AV_PKT_DATA_DISPLAYMATRIX,
    AV_PKT_DATA_STEREO3D, AV_PKT_DATA_AUDIO_SERVICE_TYPE,
    AV_PKT_DATA_QUALITY_STATS, AV_PKT_DATA_FALLBACK_TRACK,
    AV_PKT_DATA_CPB_PROPERTIES, AV_PKT_DATA_SKIP_SAMPLES, AV_PKT_DATA_JP_DUALMONO,
    AV_PKT_DATA_STRINGS_METADATA, AV_PKT_DATA_SUBTITLE_POSITION,
    AV_PKT_DATA_MATROSKA_BLOCKADDITIONAL, AV_PKT_DATA_WEBVTT_IDENTIFIER,
    AV_PKT_DATA_WEBVTT_SETTINGS, AV_PKT_DATA_METADATA_UPDATE,
    AV_PKT_DATA_MPEGTS_STREAM_ID, AV_PKT_DATA_MASTERING_DISPLAY_METADATA,
    AV_PKT_DATA_SPHERICAL, AV_PKT_DATA_CONTENT_LIGHT_LEVEL, AV_PKT_DATA_A53_CC,
    AV_PKT_DATA_ENCRYPTION_INIT_INFO, AV_PKT_DATA_ENCRYPTION_INFO,
    AV_PKT_DATA_AFD, AV_PKT_DATA_PRFT, AV_PKT_DATA_ICC_PROFILE,
    AV_PKT_DATA_DOVI_CONF, AV_PKT_DATA_S12M_TIMECODE, AV_PKT_DATA_NB


type
  AVPacketSideData* = ref object
    data*: string
    size*: int
    t*: AVPacketSideDataType

  AVPacket* = ref object
    buf*: AVBufferRef
    pts*: int64
    dts*: int64
    data*: uint8
    size*: int
    stream_index*: int
    flags*: int
    side_data*: seq[AVPacketSideData]
    side_data_elems*: int
    duration*: int64
    pos*: int64
    convergence_duration*: int64

  AVPacketList* = ref object
    pkt*: AVPacket
    next*: AVPacketList

  AVSideDataParamChangeFlags* = enum
    AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_COUNT = 0x00000001,
    AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_LAYOUT = 0x00000002,
    AV_SIDE_DATA_PARAM_CHANGE_SAMPLE_RATE = 0x00000004,
    AV_SIDE_DATA_PARAM_CHANGE_DIMENSIONS = 0x00000008


type
  AVBSFContext* = ref object
    av_class*: AVClass
    filter*: AVBitStreamFilter
    # internal*: AVBSFInternal
    priv_data*: pointer
    par_in*: AVCodecParameters
    par_out*: AVCodecParameters
    time_base_in*: AVRational
    time_base_out*: AVRational

  AVBitStreamFilter* = ref object
    name*: cstring
    codec_ids*: AVCodecID
    priv_class*: AVClass
    priv_data_size*: int
    init*: proc (ctx: AVBSFContext): int
    filter*: proc (ctx: AVBSFContext; pkt: AVPacket): int
    close*: proc (ctx: AVBSFContext)
    flush*: proc (ctx: AVBSFContext)

  AVProfile* = ref object
    profile*: int
    name*: cstring



  RcOverride* = ref object
    start_frame*: int
    end_frame*: int
    qscale*: int
    quality_factor*: cfloat

  AVCodecHWConfig* = ref object
    pix_fmt*: AVPixelFormat
    methods*: int
    device_type*: AVHWDeviceType

  AVCodecDescriptor* = ref object
    id*: AVCodecID
    t*: AVMediaType
    name*: cstring
    long_name*: cstring
    props*: int
    mime_types*: cstringArray
    profiles*: AVProfile

  DecodeSimpleContext* = ref object
    inPkt*: AVPacket

  EncodeSimpleContext* = ref object
    inFrame*: AVFrame


  AVCodecInternal*  = ref object
    isCopy*: cint 
    lastAudioFrame*: cint
    toFree*: AVFrame
    pool*: AVBufferRef
    threadCtx*: pointer
    ds*: DecodeSimpleContext
    bsf*: AVBSFContext 
    lastPktProps*: AVPacket
    pktProps*: AVPacketList
    pktPropsTail*: AVPacketList 
    byteBuffer*: uint8
    byteBufferSize*: cuint
    frameThreadEncoder*: pointer
    es*: EncodeSimpleContext 
    skipSamples*: cint        
    hwaccelPrivData*: pointer 
    draining*: cint 
    bufferPkt*: AVPacket
    bufferFrame*: AVFrame
    drainingDone*: cint
    compatDecodeWarned*: cint 
    compatDecodeConsumed*: uint 
    compatDecodePartialSize*: uint
    compatDecodeFrame*: AVFrame
    compatEncodePacket*: AVPacket
    showedMultiPacketWarning*: cint
    skipSamplesMultiplier*: cint 
    nbDrainingErrors*: cint    
    changedFramesDropped*: cint
    initialFormat*: cint
    initialWidth*: cint
    initialHeight*: cint
    initialSampleRate*: cint
    initialChannels*: cint
    initialChannelLayout*: uint64


  AVHWAccel* {.bycopy.} = object
    name*: cstring
    t*: AVMediaType
    id*: AVCodecID
    pixFmt*: AVPixelFormat
    capabilities*: cint
    allocFrame*: proc (avctx: ptr AVCodecContext; frame: ptr AVFrame): cint
    startFrame*: proc (avctx: ptr AVCodecContext; buf: ptr uint8; bufSize: uint32): cint
    decodeParams*: proc (avctx: ptr AVCodecContext; t: cint; buf: ptr uint8;
                       bufSize: uint32): cint
    decodeSlice*: proc (avctx: ptr AVCodecContext; buf: ptr uint8; bufSize: uint32): cint
    endFrame*: proc (avctx: ptr AVCodecContext): cint
    framePrivDataSize*: cint
    # decodeMb*: proc (s: ptr MpegEncContext)
    init*: proc (avctx: ptr AVCodecContext): cint
    uninit*: proc (avctx: ptr AVCodecContext): cint
    privDataSize*: cint
    capsInternal*: cint
    frameParams*: proc (avctx: ptr AVCodecContext; hwFramesCtx: ptr AVBufferRef): cint


  AVCodecContext* = ref object
    av_class*: AVClass
    log_level_offset*: int
    codec_type*: AVMediaType
    codec*: AVCodec
    codec_id*: AVCodecID
    codec_tag*: cuint
    priv_data*: pointer
    internal*: AVCodecInternal
    opaque*: pointer
    bit_rate*: int64
    bit_rate_tolerance*: int
    global_quality*: int
    compression_level*: int
    flags*: int
    flags2*: int
    extradata*: uint8
    extradata_size*: int
    time_base*: AVRational
    ticks_per_frame*: int
    delay*: int
    width*: int
    height*: int
    coded_width*: int
    coded_height*: int
    gop_size*: int
    pix_fmt*: AVPixelFormat
    draw_horiz_band*: proc (s: AVCodecContext; src: AVFrame;offset: array[8, int]; y: int; t: int; height: int)
    get_format*: proc (s: AVCodecContext; fmt: AVPixelFormat): AVPixelFormat
    max_b_frames*: int
    b_quant_factor*: cfloat
    b_frame_strategy*: int
    b_quant_offset*: cfloat
    has_b_frames*: int
    mpeg_quant*: int
    i_quant_factor*: cfloat
    i_quant_offset*: cfloat
    lumi_masking*: cfloat
    temporal_cplx_masking*: cfloat
    spatial_cplx_masking*: cfloat
    p_masking*: cfloat
    dark_masking*: cfloat
    slice_count*: int
    prediction_method*: int
    slice_offset*: int
    sample_aspect_ratio*: AVRational
    me_cmp*: int
    me_sub_cmp*: int
    mb_cmp*: int
    ildct_cmp*: int
    dia_size*: int
    last_predictor_count*: int
    pre_me*: int
    me_pre_cmp*: int
    pre_dia_size*: int
    me_subpel_quality*: int
    me_range*: int
    slice_flags*: int
    mb_decision*: int
    intra_matrix*: uint16
    inter_matrix*: uint16
    scenechange_threshold*: int
    noise_reduction*: int
    intra_dc_precision*: int
    skip_top*: int
    skip_bottom*: int
    mb_lmin*: int
    mb_lmax*: int
    me_penalty_compensation*: int
    bidir_refine*: int
    brd_scale*: int
    keyint_min*: int
    refs*: int
    chromaoffset*: int
    mv0_threshold*: int
    b_sensitivity*: int
    color_primaries*: AVColorPrimaries
    color_trc*: AVColorTransferCharacteristic
    colorspace*: AVColorSpace
    color_range*: AVColorRange
    chroma_sample_location*: AVChromaLocation
    slices*: int
    field_order*: AVFieldOrder
    sample_rate*: int
    channels*: int
    sample_fmt*: AVSampleFormat
    frame_size*: int
    frame_number*: int
    block_align*: int
    cutoff*: int
    channel_layout*: uint64
    request_channel_layout*: uint64
    audio_service_type*: AVAudioServiceType
    request_sample_fmt*: AVSampleFormat
    get_buffer2*: proc (s: AVCodecContext; frame: AVFrame; flags: int): int
    refcounted_frames*: int
    qcompress*: cfloat
    qblur*: cfloat
    qmin*: int
    qmax*: int
    max_qdiff*: int
    rc_buffer_size*: int
    rc_override_count*: int
    rc_override*: RcOverride
    rc_max_rate*: int64
    rc_min_rate*: int64
    rc_max_available_vbv_use*: cfloat
    rc_min_vbv_overflow_use*: cfloat
    rc_initial_buffer_occupancy*: int
    coder_type*: int
    context_model*: int
    frame_skip_threshold*: int
    frame_skip_factor*: int
    frame_skip_exp*: int
    frame_skip_cmp*: int
    trellis*: int
    min_prediction_order*: int
    max_prediction_order*: int
    timecode_frame_start*: int64
    rtp_callback*: proc (avctx: AVCodecContext; data: pointer; size: int;mb_nb: int)
    rtp_payload_size*: int
    mv_bits*: int
    header_bits*: int
    i_tex_bits*: int
    p_tex_bits*: int
    i_count*: int
    p_count*: int
    skip_count*: int
    misc_bits*: int
    frame_bits*: int
    stats_out*: cstring
    stats_in*: cstring
    workaround_bugs*: int
    strict_std_compliance*: int
    error_concealment*: int
    debug*: int
    err_recognition*: int
    reordered_opaque*: int64
    hwaccel*: AVHWAccel
    hwaccel_context*: pointer
    error*: array[8, uint64]
    dct_algo*: int
    idct_algo*: int
    bits_per_coded_sample*: int
    bits_per_raw_sample*: int
    lowres*: int
    coded_frame*: AVFrame
    thread_count*: int
    thread_type*: int
    active_thread_type*: int
    thread_safe_callbacks*: int
    execute*: proc (c: AVCodecContext;
                  `func`: proc (c2: AVCodecContext; arg: pointer): int;
                  arg2: pointer; result: int; count: int; size: int): int
    execute2*: proc (c: AVCodecContext; `func`: proc (c2: AVCodecContext;
        arg: pointer; jobnr: int; threadnr: int): int; arg2: pointer; result: int;
                   count: int): int
    nsse_weight*: int
    profile*: int
    level*: int
    skip_loop_filter*: AVDiscard
    skip_idct*: AVDiscard
    skip_frame*: AVDiscard
    subtitle_header*: uint8
    subtitle_header_size*: int
    vbv_delay*: uint64
    side_data_only_packets*: int
    initial_padding*: int
    framerate*: AVRational
    sw_pix_fmt*: AVPixelFormat
    pkt_timebase*: AVRational
    codec_descriptor*: AVCodecDescriptor
    pts_correction_num_faulty_pts*: int64
    pts_correction_num_faulty_dts*: int64
    pts_correction_last_pts*: int64
    pts_correction_last_dts*: int64
    sub_charenc*: cstring
    sub_charenc_mode*: int
    skip_alpha*: int
    seek_preroll*: int
    debug_mv*: int
    chroma_intra_matrix*: uint16
    dump_separator*: uint8
    codec_whitelist*: cstring
    properties*: cuint
    coded_side_data*: AVPacketSideData
    nb_coded_side_data*: int
    hw_frames_ctx*: AVBufferRef
    sub_text_format*: int
    trailing_padding*: int
    max_pixels*: int64
    hw_device_ctx*: AVBufferRef
    hwaccel_flags*: int
    apply_cropping*: int
    extra_hw_frames*: int
    discard_damaged_percentage*: int
    max_samples*: int64
    export_side_data*: int

  AVCodecDefault* = ref object
    key*: ptr uint8
    value*: ptr uint8

  AVCodecHWConfigInternal*  = ref object
    public*: AVCodecHWConfig
    hwaccel*: ptr AVHWAccel

  AVSubtitleRect* = ref object
    x*: int
    y*: int
    w*: int
    h*: int
    nb_colors*: int
    pict*: AVPicture
    data*: array[4, uint8]
    linesize*: array[4, int]
    t*: AVSubtitleType
    text*: cstring
    ass*: cstring
    flags*: int

  AVSubtitle* = ref object
    format*: uint16
    start_display_time*: uint32
    end_display_time*: uint32
    num_rects*: cuint
    rects*: AVSubtitleRect
    pts*: int64

  AVCodec* = ref object
    name*: cstring
    long_name*: cstring
    t*: AVMediaType
    id*: AVCodecID
    capabilities*: int
    supported_framerates*: AVRational
    pix_fmts*: AVPixelFormat
    supported_samplerates*: int
    sample_fmts*: AVSampleFormat
    channel_layouts*: uint64
    max_lowres*: uint8
    priv_class*: AVClass
    profiles*: AVProfile
    wrapper_name*: cstring
    priv_data_size*: int
    next*: AVCodec
    update_thread_context*: proc (dst: AVCodecContext; src: AVCodecContext): int
    defaults*: AVCodecDefault
    init_static_data*: proc (codec: AVCodec)
    init*: proc (a1: AVCodecContext): int
    encode_sub*: proc (a1: AVCodecContext; buf: uint8; buf_size: int;sub: AVSubtitle): int
    encode2*: proc (avctx: AVCodecContext; avpkt: AVPacket; frame: AVFrame;
                  got_packet_ptr: int): int
    decode*: proc (a1: AVCodecContext; outdata: pointer; outdata_size: int;
                 avpkt: AVPacket): int
    close*: proc (a1: AVCodecContext): int
    receive_packet*: proc (avctx: AVCodecContext; avpkt: AVPacket): int
    receive_frame*: proc (avctx: AVCodecContext; frame: AVFrame): int
    flush*: proc (a1: AVCodecContext)
    caps_internal*: int
    bsfs*: cstring
    hw_configs*: AVCodecHWConfigInternal
    codec_tags*: uint32

  AVPanScan* = ref object
    id*: int
    width*: int
    height*: int
    position*: array[3, array[2, int16]]

  AVCPBProperties* = ref object
    max_bitrate*: int
    min_bitrate*: int
    avg_bitrate*: int
    buffer_size*: int
    vbv_delay*: uint64

  AVProducerReferenceTime* = ref object
    wallclock*: int64
    flags*: int
  

  AVPicture* = ref object
    data*: array[8, uint8]
    linesize*: array[8, int]

  AVSubtitleType* = enum
    SUBTITLE_NONE, SUBTITLE_BITMAP, SUBTITLE_TEXT, SUBTITLE_ASS

  



  AVPictureStructure* = enum
    AV_PICTURE_STRUCTURE_UNKNOWN, AV_PICTURE_STRUCTURE_TOP_FIELD,
    AV_PICTURE_STRUCTURE_BOTTOM_FIELD, AV_PICTURE_STRUCTURE_FRAME

  AVIODirEntryType* = enum
    AVIO_ENTRY_UNKNOWN, AVIO_ENTRY_BLOCK_DEVICE, AVIO_ENTRY_CHARACTER_DEVICE,
    AVIO_ENTRY_DIRECTORY, AVIO_ENTRY_NAMED_PIPE, AVIO_ENTRY_SYMBOLIC_LINK,
    AVIO_ENTRY_SOCKET, AVIO_ENTRY_FILE, AVIO_ENTRY_SERVER, AVIO_ENTRY_SHARE,
    AVIO_ENTRY_WORKGROUP
    
  AVIODataMarkerType* = enum
    AVIO_DATA_MARKER_HEADER, AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT, AVIO_DATA_MARKER_UNKNOWN,
    AVIO_DATA_MARKER_TRAILER, AVIO_DATA_MARKER_FLUSH_POINT

type
  AVCodecParserContext* = ref object
    priv_data*: pointer
    parser*: AVCodecParser
    frame_offset*: int64
    cur_offset*: int64
    next_frame_offset*: int64
    pict_type*: int
    repeat_pict*: int
    pts*: int64
    dts*: int64
    last_pts*: int64
    last_dts*: int64
    fetch_timestamp*: int
    cur_frame_start_index*: int
    cur_frame_offset*: array[4, int64]
    cur_frame_pts*: array[4, int64]
    cur_frame_dts*: array[4, int64]
    flags*: int
    offset*: int64
    cur_frame_end*: array[4, int64]
    key_frame*: int
    convergence_duration*: int64
    dts_sync_point*: int
    dts_ref_dts_delta*: int
    pts_dts_delta*: int
    cur_frame_pos*: array[4, int64]
    pos*: int64
    last_pos*: int64
    duration*: int
    field_order*: AVFieldOrder
    picture_structure*: AVPictureStructure
    output_picture_number*: int
    width*: int
    height*: int
    coded_width*: int
    coded_height*: int
    format*: int

  AVCodecParser* = ref object
    codec_ids*: array[5, int]
    priv_data_size*: int
    parser_init*: proc (s: AVCodecParserContext): int
    parser_parse*: proc (s: AVCodecParserContext; avctx: AVCodecContext;
                       poutbuf: uint8; poutbuf_size: int;
                       buf: uint8; buf_size: int): int
    parser_close*: proc (s: AVCodecParserContext)
    split*: proc (avctx: AVCodecContext; buf: uint8; buf_size: int): int
    next*: AVCodecParser

  AVBitStreamFilterContext* = ref object
    priv_data*: pointer
    filter*: AVBitStreamFilter
    parser*: AVCodecParserContext
    next*: AVBitStreamFilterContext
    args*: cstring

  AVLockOp* = enum
    AV_LOCK_CREATE, AV_LOCK_OBTAIN, AV_LOCK_RELEASE, AV_LOCK_DESTROY


  AVIOInterruptCB* = ref object
    callback*: proc (a1: pointer): int
    opaque*: pointer

  AVIODirEntry* = ref object
    name*: cstring
    t*: int
    utf8*: int
    size*: int64
    modification_timestamp*: int64
    access_timestamp*: int64
    status_change_timestamp*: int64
    user_id*: int64
    group_id*: int64
    filemode*: int64


  AVIOContext* = ref object
    av_class*: AVClass
    buffer*: cuchar
    buffer_size*: int
    buf_ptr*: cuchar
    buf_end*: cuchar
    opaque*: pointer
    read_packet*: proc (opaque: pointer; buf: uint8; buf_size: int): int
    write_packet*: proc (opaque: pointer; buf: uint8; buf_size: int): int
    seek*: proc (opaque: pointer; offset: int64; whence: int): int64
    pos*: int64
    eof_reached*: int
    write_flag*: int
    max_packet_size*: int
    checksum*: culong
    checksum_ptr*: cuchar
    update_checksum*: proc (checksum: culong; buf: uint8; size: cuint): culong
    error*: int
    read_pause*: proc (opaque: pointer; pause: int): int
    read_seek*: proc (opaque: pointer; stream_index: int; timestamp: int64;
                    flags: int): int64
    seekable*: int
    maxsize*: int64
    direct*: int
    bytes_read*: int64
    seek_count*: int
    writeout_count*: int
    orig_buffer_size*: int
    short_seek_threshold*: int
    protocol_whitelist*: cstring
    protocol_blacklist*: cstring
    write_data_type*: proc (opaque: pointer; buf: uint8; buf_size: int;
                          t: AVIODataMarkerType; time: int64): int
    ignore_boundary_point*: int
    current_type*: AVIODataMarkerType
    last_time*: int64
    short_seek_get*: proc (opaque: pointer): int
    written*: int64
    buf_ptr_max*: cuchar
    min_packet_size*: int

  AVProbeData* = ref object
    filename*: cstring
    buf*: cuchar
    buf_size*: int
    mime_type*: cstring

  AVCodecTag* = ref object
    id*: AVCodecID
    tag*: cuint

  CodecMime* = ref object
    str*: array[32, char]
    id*: AVCodecID

  AVIndexEntry* = ref object
    pos*: int64
    timestamp*: int64
    flags* {.bitsize: 2.}: int
    size* {.bitsize: 30.}: int
    min_distance*: int

  AVStream* = ref object
    index*: int
    id*: int
    codec*: AVCodecContext
    priv_data*: pointer
    time_base*: AVRational
    start_time*: int64
    duration*: int64
    nb_frames*: int64
    disposition*: int
    `discard`*: AVDiscard
    sample_aspect_ratio*: AVRational
    metadata*: OrderedTable[string,string]
    avg_frame_rate*: AVRational
    attached_pic*: AVPacket
    side_data*: AVPacketSideData
    nb_side_data*: int
    event_flags*: int
    r_frame_rate*: AVRational
    recommended_encoder_configuration*: cstring
    codecpar*: AVCodecParameters
    unused*: pointer
    pts_wrap_bits*: int
    first_dts*: int64
    cur_dts*: int64
    last_IP_pts*: int64
    last_IP_duration*: int
    probe_packets*: int
    codec_info_nb_frames*: int
    need_parsing*: AVStreamParseType
    parser*: AVCodecParserContext
    unused7*: pointer
    unused6*: AVProbeData
    unused5*: array[16 + 1, int64]
    unused2*: pointer
    unused3*: int
    unused4*: cuint
    stream_identifier*: int
    program_num*: int
    pmt_version*: int
    pmt_stream_idx*: int
    # internal*: AVStreamInternal

  AVDeviceInfo* = ref object
    device_name*: cstring
    device_description*: cstring

  AVDeviceInfoList* = ref object
    devices*: AVDeviceInfo
    nb_devices*: int
    default_device*: int

  AVDeviceCapabilitiesQuery* = ref object
    av_class*: AVClass
    device_context*: AVFormatContext
    codec*: AVCodecID
    sample_format*: AVSampleFormat
    pixel_format*: AVPixelFormat
    sample_rate*: int
    channels*: int
    channel_layout*: int64
    window_width*: int
    window_height*: int
    frame_width*: int
    frame_height*: int
    fps*: AVRational

  AVInputFormat* = ref object
    name*: cstring
    long_name*: cstring
    flags*: int
    extensions*: cstring
    codec_tag*: AVCodecTag
    priv_class*: AVClass
    mime_type*: cstring
    next*: AVInputFormat
    raw_codec_id*: int
    priv_data_size*: int
    read_probe*: proc (a1: AVProbeData): int
    read_header*: proc (a1: AVFormatContext): int
    read_packet*: proc (a1: AVFormatContext; pkt: AVPacket): int
    read_close*: proc (a1: AVFormatContext): int
    read_seek*: proc (a1: AVFormatContext; stream_index: int; timestamp: int64;
                    flags: int): int
    read_timestamp*: proc (s: AVFormatContext; stream_index: int;
                         pos: int64; pos_limit: int64): int64
    read_play*: proc (a1: AVFormatContext): int
    read_pause*: proc (a1: AVFormatContext): int
    read_seek2*: proc (s: AVFormatContext; stream_index: int; min_ts: int64;
                     ts: int64; max_ts: int64; flags: int): int
    get_device_list*: proc (s: AVFormatContext; device_list: AVDeviceInfoList): int
    create_device_capabilities*: proc (s: AVFormatContext;caps: AVDeviceCapabilitiesQuery): int
    free_device_capabilities*: proc (s: AVFormatContext;caps: AVDeviceCapabilitiesQuery): int

  AVFormatContext* = ref object
    av_class*: AVClass
    iformat*: AVInputFormat
    oformat*: AVOutputFormat
    priv_data*: pointer
    pb*: AVIOContext
    ctx_flags*: int
    nb_streams*: cuint
    streams*: AVStream
    filename*: array[1024, char]
    url*: cstring
    start_time*: int64
    duration*: int64
    bit_rate*: int64
    packet_size*: cuint
    max_delay*: int
    flags*: int
    probesize*: int64
    max_analyze_duration*: int64
    key*: uint8
    keylen*: int
    nb_programs*: cuint
    programs*: AVProgram
    video_codec_id*: AVCodecID
    audio_codec_id*: AVCodecID
    subtitle_codec_id*: AVCodecID
    max_index_size*: cuint
    max_picture_buffer*: cuint
    nb_chapters*: cuint
    chapters*: AVChapter
    metadata*: OrderedTable[string,string]
    start_time_realtime*: int64
    fps_probe_size*: int
    error_recognition*: int
    interrupt_callback*: AVIOInterruptCB
    debug*: int
    max_interleave_delta*: int64
    strict_std_compliance*: int
    event_flags*: int
    max_ts_probe*: int
    avoid_negative_ts*: int
    ts_id*: int
    audio_preload*: int
    max_chunk_duration*: int
    max_chunk_size*: int
    use_wallclock_as_timestamps*: int
    avio_flags*: int
    duration_estimation_method*: AVDurationEstimationMethod
    skip_initial_bytes*: int64
    correct_ts_overflow*: cuint
    seek2any*: int
    flush_packets*: int
    probe_score*: int
    format_probesize*: int
    codec_whitelist*: cstring
    format_whitelist*: cstring
    # internal*: AVFormatInternal
    io_repositioned*: int
    video_codec*: AVCodec
    audio_codec*: AVCodec
    subtitle_codec*: AVCodec
    data_codec*: AVCodec
    metadata_header_padding*: int
    opaque*: pointer
    # control_message_cb*: av_format_control_message
    output_ts_offset*: int64
    dump_separator*: uint8
    data_codec_id*: AVCodecID
    open_cb*: proc (s: AVFormatContext; p: AVIOContext; url: cstring;
                  flags: int; int_cb: AVIOInterruptCB;
                  options: OrderedTable[string,string]): int
    protocol_whitelist*: cstring
    io_open*: proc (s: AVFormatContext; pb: AVIOContext; url: cstring;
                  flags: int; options: OrderedTable[string,string]): int
    io_close*: proc (s: AVFormatContext; pb: AVIOContext)
    protocol_blacklist*: cstring
    max_streams*: int
    skip_estimate_duration_from_pts*: int
    max_probe_packets*: int


  SwsVector* = ref object
    coeff*: cdouble
    length*: int

  SwsFilter* = ref object
    lumH*: SwsVector
    lumV*: SwsVector
    chrH*: SwsVector
    chrV*: SwsVector

  FFTComplex* = ref object
    re*: float
    im*: float



  AVOutputFormat* = ref object
    name*: cstring
    long_name*: cstring
    mime_type*: cstring
    extensions*: cstring
    audio_codec*: AVCodecID
    video_codec*: AVCodecID
    subtitle_codec*: AVCodecID
    flags*: int
    codec_tag*: AVCodecTag
    priv_class*: AVClass
    next*: AVOutputFormat
    priv_data_size*: int
    write_header*: proc (a1: AVFormatContext): int
    write_packet*: proc (a1: AVFormatContext; pkt: AVPacket): int
    write_trailer*: proc (a1: AVFormatContext): int
    interleave_packet*: proc (a1: AVFormatContext; `out`: AVPacket;
                            `in`: AVPacket; flush: int): int
    query_codec*: proc (id: AVCodecID; std_compliance: int): int
    get_output_timestamp*: proc (s: AVFormatContext; stream: int;
                               dts: int64; wall: int64)
    control_message*: proc (s: AVFormatContext; t: int; data: pointer;
                          data_size: uint): int
    write_uncoded_frame*: proc (a1: AVFormatContext; stream_index: int;
                              frame: AVFrame; flags: cuint): int
    # get_device_list*: proc (s: AVFormatContext; device_list: AVDeviceInfoList): int
    # create_device_capabilities*: proc (s: AVFormatContext;caps: AVDeviceCapabilitiesQuery): int
    # free_device_capabilities*: proc (s: AVFormatContext;caps: AVDeviceCapabilitiesQuery): int
    data_codec*: AVCodecID
    init*: proc (a1: AVFormatContext): int
    deinit*: proc (a1: AVFormatContext)
    check_bitstream*: proc (a1: AVFormatContext; pkt: AVPacket): int


  AVProgram* = ref object
    id*: int
    flags*: int
    `discard`*: AVDiscard
    stream_index*: cuint
    nb_stream_indexes*: cuint
    metadata*: OrderedTable[string,string]
    program_num*: int
    pmt_pid*: int
    pcr_pid*: int
    pmt_version*: int
    start_time*: int64
    end_time*: int64
    pts_wrap_reference*: int64
    pts_wrap_behavior*: int

  AVChapter* = ref object
    id*: int
    time_base*: AVRational
    start*: int64
    `end`*: int64
    metadata*: OrderedTable[string,string]

  AVDurationEstimationMethod* = enum
    AVFMT_DURATION_FROM_PTS, AVFMT_DURATION_FROM_STREAM,
    AVFMT_DURATION_FROM_BITRATE



  AVTimebaseSource* = enum
    AVFMT_TBCF_AUTO = -1, AVFMT_TBCF_DECODER, AVFMT_TBCF_DEMUXER,
    AVFMT_TBCF_R_FRAMERATE

const
  AV_OPT_FLAG_IMPLICIT_KEY* = 1

type
  AVDeviceRect* = ref object
    x*: int
    y*: int
    width*: int
    height*: int

const
    AV_APP_TO_DEV_NONE = ('E'.ord or ('N'.ord shl 8) or ('O'.ord shl 16) or ('N'.ord shl 24)) 
    AV_APP_TO_DEV_WINDOW_SIZE = ('M'.ord or ('O'.ord shl 8) or ('E'.ord shl 16) or ('G'.ord shl 24))
    AV_APP_TO_DEV_WINDOW_REPAINT = ('A'.ord or ('P'.ord shl 8) or ('E'.ord shl 16) or ('R'.ord shl 24)) 
    AV_APP_TO_DEV_PAUSE = ((' ').ord or ('U'.ord shl 8) or ('A'.ord shl 16) or ('P'.ord shl 24))
    AV_APP_TO_DEV_PLAY = ('Y'.ord or ('A'.ord shl 8) or ('L'.ord shl 16) or ('P'.ord shl 24))
    AV_APP_TO_DEV_TOGGLE_PAUSE = ('T'.ord or ('U'.ord shl 8) or ('A'.ord shl 16) or ('P'.ord shl 24)) 
    AV_APP_TO_DEV_SET_VOLUME = ('L'.ord or ('O'.ord shl 8) or ('V'.ord shl 16) or ('S'.ord shl 24))
    AV_APP_TO_DEV_MUTE = ('T'.ord or ('U'.ord shl 8) or ('M'.ord shl 16) or ((' ').ord shl 24))
    AV_APP_TO_DEV_UNMUTE = ('T'.ord or ('U'.ord shl 8) or ('M'.ord shl 16) or ('U'.ord shl 24)) 
    AV_APP_TO_DEV_TOGGLE_MUTE = ('T'.ord or ('U'.ord shl 8) or ('M'.ord shl 16) or ('T'.ord shl 24)) 
    AV_APP_TO_DEV_GET_VOLUME = ('L'.ord or ('O'.ord shl 8) or ('V'.ord shl 16) or ('G'.ord shl 24)) 
    AV_APP_TO_DEV_GET_MUTE = ('T'.ord or ('U'.ord shl 8) or ('M'.ord shl 16) or ('G'.ord shl 24))


const
    AV_DEV_TO_APP_NONE = ('E'.ord or ('N'.ord shl 8) or ('O'.ord shl 16) or ('N'.ord shl 24))
    AV_DEV_TO_APP_CREATE_WINDOW_BUFFER = ('E'.ord or ('R'.ord shl 8) or ('C'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_PREPARE_WINDOW_BUFFER = ('E'.ord or ('R'.ord shl 8) or ('P'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_DISPLAY_WINDOW_BUFFER = ('S'.ord or ('I'.ord shl 8) or ('D'.ord shl 16) or ('B'.ord shl 24)) 
    AV_DEV_TO_APP_DESTROY_WINDOW_BUFFER = ('S'.ord or ('E'.ord shl 8) or ('D'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_BUFFER_OVERFLOW = ('L'.ord or ('F'.ord shl 8) or ('O'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_BUFFER_UNDERFLOW = ('L'.ord or ('F'.ord shl 8) or ('U'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_BUFFER_READABLE = ((' ').ord or ('D'.ord shl 8) or ('R'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_BUFFER_WRITABLE = ((' ').ord or ('R'.ord shl 8) or ('W'.ord shl 16) or ('B'.ord shl 24))
    AV_DEV_TO_APP_MUTE_STATE_CHANGED = ('T'.ord or ('U'.ord shl 8) or ('M'.ord shl 16) or ('C'.ord shl 24))
    AV_DEV_TO_APP_VOLUME_LEVEL_CHANGED = ('L'.ord or ('O'.ord shl 8) or ('V'.ord shl 16) or ('C'.ord shl 24))


type
  AVFilter* = ref object
    name*: cstring
    description*: cstring
    # inputs*: AVFilterPad
    # outputs*: AVFilterPad
    priv_class*: AVClass
    flags*: int
    preinit*: proc (ctx: AVFilterContext): int
    init*: proc (ctx: AVFilterContext): int
    init_dict*: proc (ctx: AVFilterContext; options: OrderedTable[string,string]): int
    uninit*: proc (ctx: AVFilterContext)
    query_formats*: proc (a1: AVFilterContext): int
    priv_size*: int
    flags_internal*: int
    next*: AVFilter
    process_command*: proc (a1: AVFilterContext; cmd: cstring; arg: cstring;
                          res: cstring; res_len: int; flags: int): int
    init_opaque*: proc (ctx: AVFilterContext; opaque: pointer): int
    activate*: proc (ctx: AVFilterContext): int

  AVFilterGraph* = ref object
    avClass*: AVClass
    filters*: AVFilterContext
    nbFilters*: cuint
    scaleSwsOpts*: cstring     
    resampleLavrOpts*: cstring 
    threadType*: cint
    nbThreads*: cint
    # internal*: AVFilterGraphInternal
    opaque*: pointer
    # execute*: AvfilterExecuteFunc
    aresampleSwrOpts*: cstring
    # sinkLinks*: AVFilterLink
    sinkLinksCount*: cint
    disableAutoConvert*: cuint


  AVFilterContext* = ref object
    av_class*: AVClass
    filter*: AVFilter
    name*: cstring
    # input_pads*: AVFilterPad
    # inputs*: AVFilterLink
    nb_inputs*: cuint
    # output_pads*: AVFilterPad
    # outputs*: AVFilterLink
    nb_outputs*: cuint
    priv*: pointer
    graph*: AVFilterGraph
    thread_type*: int
    # internal*: AVFilterInternal
    # command_queue*: AVFilterCommand
    enable_str*: cstring
    enable*: pointer
    var_values*: cdouble
    is_disabled*: int
    hw_device_ctx*: AVBufferRef
    nb_threads*: int
    ready*: cuint
    extra_hw_frames*: int

  AVFilterFormats* = ref object
    nbFormats*: cuint          ## /< number of formats
    formats*: cint          ## /< list of media formats
    refcount*: cuint           ## /< number of references to this list
    refs*: AVFilterFormats ## /< references to this list


  AVFilterFormatsConfig* = ref object
    formats*: AVFilterFormats
    samplerates*: AVFilterFormats
    # channel_layouts*: AVFilterChannelLayouts



type
  VideoStateShowMode* = enum
    SHOW_MODE_NONE = -1, SHOW_MODE_VIDEO = 0, SHOW_MODE_WAVES, SHOW_MODE_RDFT,
    SHOW_MODE_NB

type
  MyAVPacketList* = ref object
    pkt*: AVPacket
    next*: MyAVPacketList
    serial*: cint


  PacketQueue* = ref object
    firstPkt*: MyAVPacketList
    lastPkt*: MyAVPacketList
    nbPackets*: cint
    size*: cint
    duration*: int64
    abortRequest*: cint
    serial*: cint
    # mutex*: SDL_mutex
    # cond*: SDL_cond

const VIDEO_PICTURE_QUEUE_SIZE = 3
const SUBPICTURE_QUEUE_SIZE = 16
const SAMPLE_QUEUE_SIZE = 9
const FRAME_QUEUE_SIZE = 16


type
  AudioParams* = ref object
    freq*: cint
    channels*: cint
    channelLayout*: int64
    fmt*: AVSampleFormat
    frameSize*: cint
    bytesPerSec*: cint

  Clock* = ref object
    pts*: cdouble              
    ptsDrift*: cdouble         
    lastUpdated*: cdouble
    speed*: cdouble
    serial*: cint              
    paused*: cint
    queueSerial*: cint      


type
  Frame* = ref object
    frame*: AVFrame
    sub*: AVSubtitle
    serial*: cint
    pts*: cdouble              
    duration*: cdouble         
    pos*: int64               
    width*: cint
    height*: cint
    format*: cint
    sar*: AVRational
    uploaded*: cint
    flipV*: cint

  FrameQueue* = ref object
    queue*: Deque[Frame]
    rindex*: cint
    windex*: cint
    size*: cint
    maxSize*: cint
    keepLast*: cint
    rindexShown*: cint
    # mutex*: SDL_mutex
    # cond*: SDL_cond
    pktq*: PacketQueue


const
  AV_SYNC_AUDIO_MASTER* = 0     ##  default choice
  AV_SYNC_VIDEO_MASTER* = 1
  AV_SYNC_EXTERNAL_CLOCK* = 2   ##  synchronize to an external clock

type
  Decoder* = ref object
    pkt*: AVPacket
    queue*: PacketQueue
    avctx*: AVCodecContext
    pktSerial*: cint
    finished*: cint
    packetPending*: cint
    # emptyQueueCond*: SDL_cond
    startPts*: int64
    startPtsTb*: AVRational
    nextPts*: int64
    nextPtsTb*: AVRational
    # decoderTid*: SDL_Thread


type
  VideoState* = ref object
    # readTid*: SDL_Thread
    iformat*: AVInputFormat
    abortRequest*: int
    forceRefresh*: int
    paused*: int
    lastPaused*: int
    queueAttachmentsReq*: int
    seekReq*: int
    seekFlags*: int
    seekPos*: int64
    seekRel*: int64
    readPauseReturn*: int
    ic*: AVFormatContext
    realtime*: int
    audclk*: Clock
    vidclk*: Clock
    extclk*: Clock
    pictq*: FrameQueue
    subpq*: FrameQueue
    sampq*: FrameQueue
    auddec*: Decoder
    viddec*: Decoder
    subdec*: Decoder
    audioStream*: int
    avSyncType*: int
    audioClock*: cdouble
    audioClockSerial*: int
    audioDiffCum*: cdouble     ##  used for AV difference average computation
    audioDiffAvgCoef*: cdouble
    audioDiffThreshold*: cdouble
    audioDiffAvgCount*: int
    audioSt*: AVStream
    audioq*: PacketQueue
    audioHwBufSize*: int
    audioBuf*: uint8
    audioBuf1*: uint8
    audioBufSize*: cuint       ##  in bytes
    audioBuf1Size*: cuint
    audioBufIndex*: int       ##  in bytes
    audioWriteBufSize*: int
    audioVolume*: int
    muted*: int
    audioSrc*: AudioParams
    audioFilterSrc*: AudioParams
    audioTgt*: AudioParams
    # swrCtx*: SwrContext
    frameDropsEarly*: int
    frameDropsLate*: int
    showMode*: VideoStateShowMode
    sampleArray*: array[SAMPLE_ARRAY_SIZE, int16]
    sampleArrayIndex*: int
    lastIStart*: int
    # rdft*: RDFTContext
    rdftBits*: int
    rdftData*: float
    xpos*: int
    lastVisTime*: cdouble
    # visTexture*: SDL_Texture
    # subTexture*: SDL_Texture
    # vidTexture*: SDL_Texture
    subtitleStream*: int
    subtitleSt*: AVStream
    subtitleq*: PacketQueue
    frameTimer*: cdouble
    frameLastReturnedTime*: cdouble
    frameLastFilterDelay*: cdouble
    videoStream*: int
    videoSt*: AVStream
    videoq*: PacketQueue
    maxFrameDuration*: cdouble ##  maximum duration of a frame - above this, we consider the jump a timestamp discontinuity
    # imgConvertCtx*: SwsContext
    # subConvertCtx*: SwsContext
    eof*: int
    filename*: cstring
    width*: int
    height*: int
    xleft*: int
    ytop*: int
    step*: int
    vfilterIdx*: int
    inVideoFilter*: AVFilterContext ##  the first filter in the video chain
    outVideoFilter*: AVFilterContext ##  the last filter in the video chain
    inAudioFilter*: AVFilterContext ##  the first filter in the audio chain
    outAudioFilter*: AVFilterContext ##  the last filter in the audio chain
    agraph*: AVFilterGraph  ##  audio filter graph
    lastVideoStream*: int
    lastAudioStream*: int
    lastSubtitleStream*: int
    # continueReadThread*: SDL_cond

const EAGAIN = 11
const EINVAL = 22
const averror_Eof = -('E'.ord or ('O'.ord shl 8) or ('F'.ord shl 16) or (' '.ord shl 24))
const AVERROR_INPUT_CHANGED    =  (-0x636e6701)
const AV_INPUT_BUFFER_PADDING_SIZE = 64
const AV_CODEC_CAP_PARAM_CHANGE = (1 shl 14)
const AV_EF_EXPLODE  = (1 shl 3) 
const AV_CODEC_CAP_DR1 = (1 shl  1)
const AV_CODEC_CAP_TRUNCATED = (1 shl  3)
const HAVE_THREADS = 1
const FF_DEBUG_THREADS = 0x00010000
const AV_PIX_FMT_FLAG_BE* = 1 shl 0
const AV_PIX_FMT_FLAG_PAL* = 1 shl 1
const AV_PIX_FMT_FLAG_BITSTREAM* = 1 shl 2
const AV_PIX_FMT_FLAG_HWACCEL = 1 shl 3
const AV_PIX_FMT_FLAG_PLANAR = 1 shl 4
const AV_NUM_DATA_POINTERS = 8


proc MKTAG(a,b,c,d:auto):int = (a.ord or (b.ord shl 8) or (c.ord shl 16) or (d.ord shl 24))
template FFERRTAG(a, b, c, d):untyped = -MKTAG(a, b, c, d)
const AVERROR_INVALIDDATA =  FFERRTAG( 'I','N','D','A')

template FFALIGN(x: int, a:int):int = ((x+a-1) and not(a-1))
var atomicLock*: Pthread_mutex

var avPixFmtDescriptors = newOrderedTable(
  {AV_PIX_FMT_YUV420P.ord: AVPixFmtDescriptor(name:"yuv420p",nb_components:3,log2_chroma_w:1,log2_chroma_h:1,
      comp: @[(0, 1, 0, 0, 8, 0, 7, 1),        
            (1, 1, 0, 0, 8, 0, 7, 1 ),        
            (2, 1, 0, 0, 8, 0, 7, 1 )], flags: AV_PIX_FMT_FLAG_PLANAR)},

  )

proc streamClose*(videoState: VideoState) =
  videoState.abortRequest = 1
#   sDL_WaitThread(videoState.readTid, nil)
#   if videoState.audioStream >= 0:
#     streamComponentClose(videoState, videoState.audioStream)
#   if videoState.videoStream >= 0:
#     streamComponentClose(videoState, videoState.videoStream)
#   if videoState.subtitleStream >= 0:
#     streamComponentClose(videoState, videoState.subtitleStream)
#   avformatCloseInput(videoState.ic)
#   packetQueueDestroy(videoState.videoq)
#   packetQueueDestroy(videoState.audioq)
#   packetQueueDestroy(videoState.subtitleq)
#   frameQueueDestory(videoState.pictq)
#   frameQueueDestory(videoState.sampq)
#   frameQueueDestory(videoState.subpq)
#   sDL_DestroyCond(videoState.continueReadThread)
#   swsFreeContext(videoState.imgConvertCtx)
#   swsFreeContext(videoState.subConvertCtx)
#   avFree(videoState.filename)
#   if videoState.visTexture:
#     sDL_DestroyTexture(videoState.visTexture)
#   if videoState.vidTexture:
#     sDL_DestroyTexture(videoState.vidTexture)
#   if videoState.subTexture:
#     sDL_DestroyTexture(videoState.subTexture)
#   avFree(videoState)

proc frameQueueInit*(f: FrameQueue; pktq: PacketQueue; maxSize: cint;keepLast: cint): cint =
#   f.mutex = sDL_CreateMutex()
#   if not ():
#     echo("SDL_CreateMutex(): %s\n", sDL_GetError())
#     return -(ENOMEM)
#   if not (f.cond = sDL_CreateCond()):
#     echo("SDL_CreateCond(): %s\n", sDL_GetError())
#     return -(ENOMEM)
  f.pktq = pktq
  f.maxSize = min(maxSize, FRAME_QUEUE_SIZE)
  f.keepLast = not not keepLast
  for i in 0..<f.queue.len:
    f.queue[i].frame = AVFrame()
  return 0

var fileIformat*: AVInputFormat

proc packetQueueInit*(q: PacketQueue): cint =
#   q.mutex = sDL_CreateMutex()
#   if q.mutex != nil:
#     echo("SDL_CreateMutex(): %s\n", sDL_GetError())
#     return -(ENOMEM)
#   q.cond = sDL_CreateCond()
#   if q.cond != nil:
#     echo("SDL_CreateCond(): %s\n", sDL_GetError())
#     return -(ENOMEM)
  q.abortRequest = 1
  return 0

# proc bufferReplace*(dst: AVBufferRef; src: AVBufferRef) =
#   var b: AVBuffer
#   b = (dst[]).buffer
#   if src:
#     dst[][] = src[][]
#     avFreep(src)
#   else:
#     avFreep(dst)
#   if atomicFetchSubExplicit(b.refcount, 1, memoryOrderAcqRel) == 1:
#     b.free(b.opaque, b.data)
#     avFreep(b)

# proc avBufferUnref*(buf: AVBufferRef) =
#   bufferReplace(buf, nil)


proc avPacketFreeSideData*(pkt: AVPacket) =
  var i: cint
  i = 0
#   while i < pkt.sideDataElems:
#     avFreep(pkt.sideData[i].data)
#     inc(i)
#   avFreep(pkt.sideData)
  pkt.sideDataElems = 0




proc avPacketUnref*(pkt: var AVPacket) =
  avPacketFreeSideData(pkt)
#   avBufferUnref(pkt.buf)
  pkt.pos = -1
  pkt.data = 0
  pkt.size = 0

proc packetQueueFlush*(q: PacketQueue) =
  var
    pkt: MyAVPacketList
    pkt1:  MyAVPacketList
#   sDL_LockMutex(q.mutex)
  pkt = q.firstPkt
  while pkt != nil:
    pkt1 = pkt.next
    avPacketUnref(pkt.pkt)
    # avFreep(pkt)
    pkt = pkt1
  q.lastPkt = nil
  q.firstPkt = nil
  q.nbPackets = 0
  q.size = 0
  q.duration = 0
#   sDL_UnlockMutex(q.mutex)

proc packetQueueDestroy*(q:  PacketQueue) =
  packetQueueFlush(q)
#   sDL_DestroyMutex(q.mutex)
#   sDL_DestroyCond(q.cond)

proc packetQueueAbort*(q: PacketQueue) =
#   sDL_LockMutex(q.mutex)
  q.abortRequest = 1
#   sDL_CondSignal(q.cond)
#   sDL_UnlockMutex(q.mutex)
var flushPkt*: AVPacket

proc packetQueuePutPrivate*(q: PacketQueue; pkt: AVPacket): cint =
  var pkt1 = MyAVPacketList()
  if q.abortRequest != 0:
    return -1
  pkt1.pkt = pkt
  pkt1.next = nil
  if pkt == flushPkt:
    inc(q.serial)
  pkt1.serial = q.serial
  if q.lastPkt == nil:
    q.firstPkt = pkt1
  else:
    q.lastPkt.next = pkt1
  q.lastPkt = pkt1
  inc(q.nbPackets)
  inc(q.size, pkt1.pkt.size + sizeof((pkt1[])))
  q.duration += pkt1.pkt.duration
#   sDL_CondSignal(q.cond)
  return 0


proc packetQueueStart*(q: PacketQueue) =
#   sDL_LockMutex(q.mutex)
  q.abortRequest = 0
  echo packetQueuePutPrivate(q, flushPkt)
#   sDL_UnlockMutex(q.mutex)

proc avClipC(a:int, amin:int, amax:int):int = 
    if a < amin:  amin
    elif a > amax:  amax
    else:  a

# proc packetQueueGet*(q: PacketQueue; pkt: AVPacket; b: cint;serial: cint): cint =
#   var pkt1: MyAVPacketList
#   var result: cint
# #   sDL_LockMutex(q.mutex)
#   while true:
#     if q.abortRequest != 0:
#       result = -1
#       break
#     pkt1 = q.firstPkt
#     if pkt1 != nil:
#       q.firstPkt = pkt1.next
#       q.nbPackets -= 1
#       dec(q.size, pkt1.pkt.size + sizeof(pkt1))
#       q.duration -= pkt1.pkt.duration
#       pkt = pkt1.pkt
#       serial = pkt1.serial
#       result = 1
#       break
#     elif b == 0:
#       result = 0
#       break
#     # else:
#     #   sDL_CondWait(q.cond, q.mutex)
# #   sDL_UnlockMutex(q.mutex)
#   return result

proc decoderInit*(d:  Decoder; avctx:  AVCodecContext; queue:  PacketQueue) =
  d.avctx = avctx
  d.queue = queue
  d.startPts = 0
  d.pktSerial = -1



proc avcodecIsOpen*(s: AVCodecContext): auto = s.internal != nil

proc avCodecIsDecoder*(codec: AVCodec): auto =
  codec != nil and (codec.decode != nil or codec.receiveFrame != nil)

const AV_CODEC_FLAG_DROPCHANGED   =  (1 shl 5)


proc getFrameDefaults*(frame: var AVFrame) =
  frame.pktPos = -1
  frame.pktSize = -1
  frame.keyFrame = 1
  frame.sample_aspect_ratio = AVRational(num:0, den:1)
  frame.format = -1
#   frame.extendedData = frame.data
  frame.colorPrimaries = AVCOL_PRI_UNSPECIFIED
  frame.colorTrc = AVCOL_TRC_UNSPECIFIED
  frame.colorspace = AVCOL_SPC_UNSPECIFIED
  frame.colorRange = AVCOL_RANGE_UNSPECIFIED
  frame.chromaLocation = AVCHROMA_LOC_UNSPECIFIED

# proc avFrameMoveRef*(dst: AVFrame; src: AVFrame) =
#   dst[] = src[]
#   if src.extendedData == src.data:
#     dst.extendedData = dst.data
#   getFrameDefaults(src)

proc avBsfReceivePacket*(ctx: AVBSFContext; pkt: AVPacket): cint =
  return cint ctx.filter.filter(ctx, pkt)

proc avprivPacketListPut*(packetBuffer: var AVPacketList;
                         plastPktl: var AVPacketList; pkt: AVPacket; copy: proc (
    dst: ptr AVPacket; src: ptr AVPacket): cint; flags: cint): cint =
  var pktl = AVPacketList()
  if copy != nil:
    pktl.pkt =  pkt
  else:
    pktl.pkt =  pkt
    # result = avPacketMakeRefcounted(pkt)
    # avPacketMoveRef(pktl.pkt, pkt)
  if packetBuffer != nil:
    plastPktl.next = pktl
  else:
    packetBuffer = pktl
  ##  Add the packet in the buffered packet list.
  plastPktl = pktl
  return 0


template isEmpty(t:untyped):bool = t.data == 0 and t.side_data_elems == 0

proc avPacketAddSideData*(pkt: var AVPacket; t: AVPacketSideDataType;data: string; size: int): cint =
  var tmp = AVPacketSideData()
  var elems: int = pkt.sideDataElems
  for i in 0..<elems:
    if pkt.sideData[i].t == t:
      pkt.sideData[i].data = data
      pkt.sideData[i].size = int size
      return 0
  if elems + 1 > AV_PKT_DATA_NB.int:
    return -ERANGE
  pkt.sideData.add tmp
  return 0



proc avPacketNewSideData*(pkt: var AVPacket; t: AVPacketSideDataType; size: int): string =
  result = newString(size + AV_INPUT_BUFFER_PADDING_SIZE)
  if size > int.high - AV_INPUT_BUFFER_PADDING_SIZE:
    return 
  echo avPacketAddSideData(pkt, t, result, size)
  return result


proc avPacketCopyProps*(dst: var AVPacket; src: AVPacket): cint =
  var i: cint
  dst.pts = src.pts
  dst.dts = src.dts
  dst.pos = src.pos
  dst.duration = src.duration
  dst.convergenceDuration = src.convergenceDuration
  dst.flags = src.flags
  dst.streamIndex = src.streamIndex
  dst.sideDataElems = 0
  i = 0
  while i < src.sideDataElems:
    var size = src.sideData[i].size
    var srcData = src.sideData[i].data
    var dstData = avPacketNewSideData(dst, src.sideData[i].t, size)
    # copyMem(dstData, srcData, size)
    inc(i)
  return 0

proc avprivPacketListGet*(pktBuffer: var AVPacketList;pktBufferEnd:var AVPacketList; pkt:var AVPacket): cint =
  var pktl = AVPacketList()
  pktl = pktBuffer
  pkt = pktl.pkt
  pktBuffer = pktl.next
  if pktl.next == nil:
    pktBufferEnd = nil
  return 0

proc extractPacketProps*(avci: AVCodecInternal; pkt: AVPacket): cint =
  result = avprivPacketListPut(avci.pktProps, avci.pktPropsTail, pkt, nil, 0)
  avci.pktPropsTail.pkt.size = pkt.size
  avci.pktPropsTail.pkt.data = 1
  if is_Empty(avci.lastPktProps):
    result = avprivPacketListGet(avci.pktProps, avci.pktPropsTail, avci.lastPktProps)
  return result

proc avPacketGetSideData*(pkt: var AVPacket; t: AVPacketSideDataType;size: ptr cint): string =
    var i: cint
    i = 0
    while i < pkt.sideDataElems:
        if pkt.sideData[i].t == t:
            if size != nil:
                size[] = cint pkt.sideData[i].size
            return pkt.sideData[i].data
        inc(i)
    if size != nil:
        size[] = 0
    return ""


# proc avImageFillMaxPixsteps*(maxPixsteps: array[4, cint];
#                             maxPixstepComps: array[4, cint];
#                             pixdesc: ptr AVPixFmtDescriptor) =
#   var i: cint
# #   memset(maxPixsteps, 0, 4 * sizeof((maxPixsteps[0])))
# #   if maxPixstepComps:
#     # memset(maxPixstepComps, 0, 4 * sizeof((maxPixstepComps[0])))
#   i = 0
#   while i < 4:
#     var comp: ptr AVComponentDescriptor = (pixdesc.comp[i])
#     if comp.step > maxPixsteps[comp.plane]:
#       maxPixsteps[comp.plane] = comp.step
#       if maxPixstepComps:
#         maxPixstepComps[comp.plane] = i
#     inc(i)


proc imageGetLinesize*(width: auto; plane: int; maxStep: cint; maxStepComp: int; desc: AVPixFmtDescriptor): cint {.inline.} =
  var
    s: cint
    shiftedW: cint
  s =  if (maxStepComp == 1 or maxStepComp == 2): desc.log2ChromaW.cint else: 0
  shiftedW = cint ((width + (1 shl s) - 1)) shr s
  if shiftedW != 0 and maxStep > int.high div shiftedW:
    return -(EINVAL)
  result = maxStep * shiftedW
  if (desc.flags and AV_PIX_FMT_FLAG_BITSTREAM) != 0:
    result = (result + 7) shr 3
  return result

proc avPixFmtDescGet(pixFmt:int): AVPixFmtDescriptor = avPixFmtDescriptors[pix_fmt]

# proc avImageGetLinesize*(pixFmt: AVPixelFormat; width: cint; plane: cint): cint =
#   var desc: ptr AVPixFmtDescriptor = avPixFmtDescGet(pixFmt)
#   var maxStep: array[4, cint]
#   ##  max pixel step for each plane
#   var maxStepComp: array[4, cint]
#   ##  the component for each plane which has the max pixel step
#   if not desc or desc.flags and av_Pix_Fmt_Flag_Hwaccel:
#     return -(EINVAL)
#   avImageFillMaxPixsteps(maxStep, maxStepComp, desc)
#   return imageGetLinesize(width, plane, maxStep[plane], maxStepComp[plane], desc)


# proc avImageCheckSize2*(w: cuint; h: cuint; maxPixels: int64; pixFmt: AVPixelFormat;
#                        logOffset: cint; logCtx: pointer): cint =
#   ##  ImgUtils imgutils = {
#   ##      .class      = &imgutils_class,
#   ##      .log_offset = log_offset,
#   ##      .log_ctx    = log_ctx,
#   ##  };
#   var stride: int64 = avImageGetLinesize(pixFmt, w, 0)
#   if stride <= 0:
#     stride = 8 * w
#   inc(stride, 128 * 8)
#   if cast[cint](w) <= 0 or cast[cint](h) <= 0 or stride >= int.high or stride * (uint64)(h + 128) >= int.high:
#     echo("Picture size %ux%u is invalid\n", w, h)
#     return -(EINVAL)
#   if maxPixels < int64.high:
#     if w * cast[int64](h) > maxPixels:
#       echo("Picture size %ux%u exceeds specified max pixel count %lld, see the documentation if you wish to increase it\n", w, h, maxPixels)
#       return -EINVAL
#   return 0
# import compiler/trees

# template AV_CEIL_RSHIFT(a,b:untyped):untyped = 
#     if not isConstExpr(b): 
#       -(-a shr b)
#     else:
#       (a + (1 shl b) - 1) shr b

proc ffSetDimensions*(s:var AVCodecContext; width: cint; height: cint): cint =
#   result = avImageCheckSize2(width, height, s.maxPixels, av_Pix_Fmt_None, 0, s)
#   if result < 0:
#     height = 0
#     width = 0 
  s.codedWidth = width
  s.codedHeight = height
  s.width = width
  s.height = height
  # s.width = AV_CEIL_RSHIFT(width, s.lowres)
  # s.height = AV_CEIL_RSHIFT(height, s.lowres)
  return result



proc applyParamChange*(avctx: var AVCodecContext; avpkt: var AVPacket): cint =
  var size: cint
  var data = newStringStream avPacketGetSideData(avpkt, AV_PKT_DATA_PARAM_CHANGE, size.addr)
  var flags: int32
  var val: int64
  if (avctx.codec.capabilities and AV_CODEC_CAP_PARAM_CHANGE) == 0:
    echo("This decoder does not support parameter changes, but PARAM_CHANGE side data was sent to it.\n")
    result = -EINVAL
  if size < 4:
    echo "size < 4"
  
  data.readDataLE(flags.addr, 4)
  echo flags
#   flags = bytestreamGetLe32(data)
  dec(size, 4)
  if (flags and AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_COUNT.ord) != 0:
    if size < 4:
        echo "size < 4"
    data.readDataLE(val.addr, 4)
    # val = bytestreamGetLe32(data)
    if val <= 0 or val > int.high:
      echo("Invalid channel count")
    avctx.channels = int val
    dec(size, 4)
  if (flags and AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_LAYOUT.ord) != 0:
    if size < 8:
      echo "size < 8"
    data.readDataLE(avctx.channelLayout.addr, 4)
    # avctx.channelLayout = bytestreamGetLe64(data)
    dec(size, 8)
  if (flags and AV_SIDE_DATA_PARAM_CHANGE_SAMPLE_RATE.ord) != 0:
    if size < 4:
      echo "size < 8"
    data.readDataLE(val.addr, 4)
    # val = bytestreamGetLe32(data)
    if val <= 0 or val > int.high:
      echo("Invalid sample rate")
      result = cint AVERROR_INVALIDDATA
    avctx.sampleRate = int val
    dec(size, 4)
  if (flags and AV_SIDE_DATA_PARAM_CHANGE_DIMENSIONS.ord) != 0:
    if size < 8:
        echo "size < 8"

    data.readDataLE(avctx.width.addr, 4)
    data.readDataLE(avctx.height.addr, 4)
    # avctx.width = bytestreamGetLe32(data)
    # avctx.height = bytestreamGetLe32(data)
    dec(size, 8)
    result = ffSetDimensions(avctx, avctx.width.cint, avctx.height.cint)
  return 0
  echo("PARAM_CHANGE side data too small.\n")
  result = cint AVERROR_INVALIDDATA
  if result < 0:
    echo("Error applying parameter changes.\n")
    if (avctx.errRecognition and AV_EF_EXPLODE) != 0:
      return result
  return 0


proc ffDecodeGetPacket*(avctx: var AVCodecContext; pkt: var AVPacket): cint =
  var avci:  AVCodecInternal = avctx.internal
  if avci.draining != 0:
    return averror_Eof
  result = avBsfReceivePacket(avci.bsf, pkt)
  if result == averror_Eof:
    avci.draining = 1
  if result < 0:
    return result
  result = extractPacketProps(avctx.internal, pkt)
  result = applyParamChange(avctx, pkt)
  if avctx.codec.receiveFrame != nil:
    inc(avci.compatDecodeConsumed, pkt.size)
  return 0
#   avPacketUnref(pkt)
  return result



type
  MemoryOrder* = enum
    memoryOrderRelaxed, memoryOrderConsume, memoryOrderAcquire, memoryOrderRelease,
    memoryOrderAcqRel, memoryOrderSeqCst

const AV_CODEC_CAP_DELAY = (1 shl  5)
const FF_THREAD_FRAME =  1 
const FF_THREAD_SLICE = 2 

type
  PthreadT* {.bycopy.} = object
    handle*: pointer
    `func`*: proc (arg: pointer): pointer
    arg*: pointer
    result*: pointer

  PerThreadContext*  = ref object
    parent*: FrameThreadContext
    thread*: PthreadT
    threadInit*: cint
    inputCond*: ptr Pthread_cond   ## /< Used to wait for a new packet from the main thread.
    progressCond*:ptr Pthread_cond ## /< Used by child threads to wait for progress to change.
    outputCond*:ptr Pthread_cond  ## /< Used by the main thread to wait for frames to finish.
    mutex*: ptr Pthread_mutex      ## /< Mutex used to protect the contents of the PerThreadContext.
    progressMutex*: ptr Pthread_mutex ## /< Mutex used to protect frame progress values and progress_cond.
    avctx*: AVCodecContext  ## /< Context used to decode packets passed to this thread.
    avpkt*: AVPacket           ## /< Input packet (for decoding) or output (for encoding).
    frame*: ptr AVFrame         ## /< Output frame (for decoding) or input (for encoding).
    gotFrame*: cint            ## /< The output of got_picture_ptr from the last avcodec_decode_video() call.
    result*: cint              ## /< The result of the last codec decode/encode() call.
    state*: int 
    releasedBuffers*: ptr ptr AVFrame
    numReleasedBuffers*: cint
    releasedBuffersAllocated*: cint
    requestedFrame*: AVFrame ## /< AVFrame the codec passed to get_buffer()
    requestedFlags*: cint      ## /< flags passed to get_buffer() for requested_frame
    availableFormats*: ptr AVPixelFormat ## /< Format array for get_format()
    resultFormat*: AVPixelFormat ## /< get_format() result
    die*: cint                 ## /< Set when the thread should exit.
    hwaccelSerializing*: cint
    asyncSerializing*: cint
    debugThreads*: int   

  FrameThreadContext* = ref object
    threads*: PerThreadContext ## /< The contexts for each thread.
    prevThread*: PerThreadContext ## /< The last thread submit_packet() was called on.
    bufferMutex*: Pthread_mutex 
    hwaccelMutex*: Pthread_mutex
    asyncMutex*: Pthread_mutex
    asyncCond*: Pthread_cond
    asyncLock*: cint
    nextDecoding*: cint        ## /< The next context to submit a packet to.
    nextFinished*: cint        ## /< The next context to return output from.
    delaying*: cint 

const
  STATE_INPUT_READY* = 0
  STATE_SETTING_UP* = 1
  STATE_GET_BUFFER* = 2
  STATE_GET_FORMAT* = 3
  STATE_SETUP_FINISHED* = 4

# proc updateContextFromUser*(dst: var AVCodecContext; src: AVCodecContext): cint =
#   dst.flags = src.flags
#   dst.drawHorizBand = src.drawHorizBand
#   dst.getBuffer2 = src.getBuffer2
#   dst.opaque = src.opaque
#   dst.debug = src.debug
#   dst.debugMv = src.debugMv
#   dst.sliceFlags = src.sliceFlags
#   dst.flags2 = src.flags2
#   dst.exportSideData = src.exportSideData
#   dst.skipLoopFilter = src.skipLoopFilter
#   dst.skipIdct = src.skipIdct
#   dst.skipFrame = src.skipFrame
#   dst.frameNumber = src.frameNumber
#   dst.reorderedOpaque = src.reorderedOpaque
#   dst.threadSafeCallbacks = src.threadSafeCallbacks
#   if src.sliceCount != 0 and src.sliceOffset != 0:
#     if dst.sliceCount < src.sliceCount:
#       var err: cint = avReallocpArray(addr(dst.sliceOffset), src.sliceCount, sizeof(dst.sliceOffset))
#       if err < 0:
#         return err
#     copyMem(dst.sliceOffset, src.sliceOffset,src.sliceCount * sizeof((dst.sliceOffset[])))
#   dst.sliceCount = src.sliceCount
#   return 0


# proc updateContextFromThread*(dst: ptr AVCodecContext; src: ptr AVCodecContext; forUser: cint): cint =
#   var err: cint = 0
#   if dst != src and (forUser != 0 or src.codec.updateThreadContext != nil):
#     dst.timeBase = src.timeBase
#     dst.framerate = src.framerate
#     dst.width = src.width
#     dst.height = src.height
#     dst.pixFmt = src.pixFmt
#     dst.swPixFmt = src.swPixFmt
#     dst.codedWidth = src.codedWidth
#     dst.codedHeight = src.codedHeight
#     dst.hasBFrames = src.hasBFrames
#     dst.idctAlgo = src.idctAlgo
#     dst.bitsPerCodedSample = src.bitsPerCodedSample
#     dst.sampleAspectRatio = src.sampleAspectRatio
#     dst.profile = src.profile
#     dst.level = src.level
#     dst.bitsPerRawSample = src.bitsPerRawSample
#     dst.ticksPerFrame = src.ticksPerFrame
#     dst.colorPrimaries = src.colorPrimaries
#     dst.colorTrc = src.colorTrc
#     dst.colorspace = src.colorspace
#     dst.colorRange = src.colorRange
#     dst.chromaSampleLocation = src.chromaSampleLocation
#     dst.hwaccel = src.hwaccel
#     dst.hwaccelContext = src.hwaccelContext
#     dst.channels = src.channels
#     dst.sampleRate = src.sampleRate
#     dst.sampleFmt = src.sampleFmt
#     dst.channelLayout = src.channelLayout
#     dst.internal.hwaccelPrivData = src.internal.hwaccelPrivData
#     if not not dst.hwFramesCtx != not not src.hwFramesCtx or
#         (dst.hwFramesCtx and dst.hwFramesCtx.data != src.hwFramesCtx.data):
#       avBufferUnref(addr(dst.hwFramesCtx))
#       if src.hwFramesCtx:
#         dst.hwFramesCtx = avBufferRef(src.hwFramesCtx)
#         if not dst.hwFramesCtx:
#           return -(ENOMEM)
#     dst.hwaccelFlags = src.hwaccelFlags
#     err = avBufferReplace(addr(dst.internal.pool), src.internal.pool)
#     if err < 0:
#       return err
#   if forUser:
#     dst.codedFrame = src.codedFrame
#   else:
#     if dst.codec.updateThreadContext:
#       err = dst.codec.updateThreadContext(dst, src)
#   return err



proc atomicStore*[T](obj: ptr T; desired: T) {.inline.} =
  discard pthreadMutexLock(addr(atomicLock))
  obj[] = desired
  discard pthreadMutexUnlock(addr(atomicLock))

proc atomicLoad*(obj: ptr int): int {.inline.} =
  discard pthreadMutexLock(addr(atomicLock))
  result = obj[]
  discard pthreadMutexUnlock(addr(atomicLock))


proc avImageFillMaxPixsteps*(maxPixsteps: var array[4, cint];
                            maxPixstepComps:var array[4, cint];
                            pixdesc: AVPixFmtDescriptor) =
  for i in 0..3:
    var comp: AVComponentDescriptor = pixdesc.comp[i]
    if comp.step > maxPixsteps[comp.plane]:
      maxPixsteps[comp.plane] = cint comp.step
      maxPixstepComps[comp.plane] = cint i


proc avImageFillLinesizes*(linesizes: var seq[int]; pixFmt: int; width: auto): cint =
  var desc = avPixFmtDescriptors[pixFmt]
  var maxStep: array[4, cint]
  var maxStepComp: array[4, cint]
  if desc == nil or (desc.flags and AV_PIX_FMT_FLAG_HWACCEL) != 0:
    return -(EINVAL)
  for i in 0..3:
    var comp: AVComponentDescriptor = desc.comp[i]
    if comp.step > maxStep[comp.plane]:
      maxStep[comp.plane] = cint comp.step
      maxStepComp[comp.plane] = cint i
  for i in 0..3:
    result = imageGetLinesize(width, i, maxStep[i], maxStepComp[i], desc)
    if result < 0:
      return result
    linesizes[i] = result
  return 0

const FF_API_PSEUDOPAL:uint = uint 56 < 57

proc avImageFillPlaneSizes*(sizes: var seq[uint]; pixFmt: int;height: cint; linesizes: seq[int]): cint =
  var  hasPlane: array[4, int]
  var desc = avPixFmtDescGet(pixFmt.ord)
  sizes[0] = uint linesizes[0] * height
  if (desc.flags and AV_PIX_FMT_FLAG_PAL) != 0 or (desc.flags and FF_API_PSEUDOPAL) != 0:
    sizes[1] = 256 * 4
    return 0
  for i in 0..3:
    hasPlane[desc.comp[i].plane] = 1
  for i in 1..3:
    if hasPlane[i] != 0:
      var s = if (i == 1 or i == 2): desc.log2ChromaH.cint else: 0
      var h =  (height + (1 shl s) - 1) shr s
      if linesizes[i].uint64 > uint64.high div h.uint64:
        return -(EINVAL)
      sizes[i] = uint h * linesizes[i]
  return 0

proc avImageFillPointers*(data: var seq[ptr uint8]; pixFmt: int;height: cint; p: ptr uint8; linesizes: seq[int]): cint =
  var linesizes1: seq[int] = newSeq[int](4)
  var sizes: seq[uint] = newSeq[uint](4)
  for i in 0..3:
    linesizes1[i] = linesizes[i]
  result = avImageFillPlaneSizes(sizes, pixFmt, height, linesizes1)
  for i in 0..3:
    result += cint sizes[i]
  data[0] = p
  for i in 1..3:
    if sizes[i] != 0:
      data[i] = data[i - 1] + sizes[i - 1].uint8
  return result


proc getVideoBuffer*(frame: var AVFrame; align:var cint): cint =
  var desc: AVPixFmtDescriptor = avPixFmtDescriptors[frame.format]
  var
    i: cint
    paddedHeight: cint
    totalSize: cint
  var planePadding: cint = max(16 + 16, align)
  var linesizes: seq[int] = newSeq[int](4)
  var sizes: seq[uint] = newSeq[uint](4)
  if desc == nil:
    return -(EINVAL)
  # result = avImageCheckSize(frame.width, frame.height, 0, nil)
  if frame.linesize[0] == 0:
    if align <= 0:
      align = 32
    i = 1
    while i <= align:
      result = avImageFillLinesizes(frame.linesize, frame.format, FFALIGN(frame.width, i))
      if result < 0: return result
      if (frame.linesize[0] and (align - 1)) == 0: break
      inc(i, i)
    for i in 0..3:
      if frame.linesize[i] != 0:
        frame.linesize[i] = FFALIGN(frame.linesize[i], align)
  for i in 0..3: 
    linesizes[i] = frame.linesize[i]
  paddedHeight = cint FFALIGN(frame.height, 32)
  result = avImageFillPlaneSizes(sizes, frame.format, paddedHeight, linesizes)
  if result < 0:
    return result
  totalSize = 4 * planePadding
  for i in 0..3:
    if sizes[i].int > int.high - totalSize:
      return -(EINVAL)
    totalSize += sizes[i].cint
  # frame.buf[0] = avBufferAlloc(totalSize)
  if frame.buf[0] == nil:
    result = -(ENOMEM)
  result = avImageFillPointers(frame.data, frame.format, paddedHeight, frame.buf[0].data, frame.linesize)
  for i in 1..3:
    if frame.data[i] != 0:
      inc(frame.data[i], i * planePadding)
  frame.extendedData = frame.data
  result = 0
  # avFrameUnref(frame)


# proc avBufferCreate*(data: ptr uint8; size: cint;
#                     free: proc (opaque: pointer; data: ptr uint8); opaque: pointer;
#                     flags: cint): ptr AVBufferRef =
  
#   var buf = avMallocz(sizeof(AVBuffer))
#   buf.data = data
#   buf.size = size
#   buf.free = if free != nil : free else: avBufferDefaultFree
#   buf.opaque = opaque
#   atomicInit(addr(buf.refcount), 1)
#   buf.flags = flags
#   result = avMallocz(sizeof((result[])))
#   result.buffer = buf
#   result.data = data
#   result.size = size


# proc avBufferAlloc*(size: cint): ptr AVBufferRef =
#   var data = avMalloc(size)
#   result = avBufferCreate(data, size, avBufferDefaultFree, nil, 0)

# proc avBufferRef*(buf: ptr AVBufferRef): ptr AVBufferRef =
#   result = avMallocz(sizeof((result[])))
#   result[] = buf[]
#   atomicFetchAddExplicit(addr(buf.buffer.refcount), 1)
#   return result


type
  SampleFmtInfo* = ref object
    name*: string
    bits*: cint
    planar*: cint
    altform*: AVSampleFormat   

var  sampleFmtInfos = newOrderedTable({
    AV_SAMPLE_FMT_U8.ord: SampleFmtInfo(name:"u8", bits:8, planar: 0, altform:AV_SAMPLE_FMT_U8P),
    # [AV_SAMPLE_FMT_S16]  = { .name =  "s16", .bits = 16, .planar = 0, .altform = AV_SAMPLE_FMT_S16P },
    # [AV_SAMPLE_FMT_S32]  = { .name =  "s32", .bits = 32, .planar = 0, .altform = AV_SAMPLE_FMT_S32P },
    # [AV_SAMPLE_FMT_S64]  = { .name =  "s64", .bits = 64, .planar = 0, .altform = AV_SAMPLE_FMT_S64P },
    # [AV_SAMPLE_FMT_FLT]  = { .name =  "flt", .bits = 32, .planar = 0, .altform = AV_SAMPLE_FMT_FLTP },
    # [AV_SAMPLE_FMT_DBL]  = { .name =  "dbl", .bits = 64, .planar = 0, .altform = AV_SAMPLE_FMT_DBLP },
    # [AV_SAMPLE_FMT_U8P]  = { .name =  "u8p", .bits =  8, .planar = 1, .altform = AV_SAMPLE_FMT_U8   },
    # [AV_SAMPLE_FMT_S16P] = { .name = "s16p", .bits = 16, .planar = 1, .altform = AV_SAMPLE_FMT_S16  },
    # [AV_SAMPLE_FMT_S32P] = { .name = "s32p", .bits = 32, .planar = 1, .altform = AV_SAMPLE_FMT_S32  },
    # [AV_SAMPLE_FMT_S64P] = { .name = "s64p", .bits = 64, .planar = 1, .altform = AV_SAMPLE_FMT_S64  },
    # [AV_SAMPLE_FMT_FLTP] = { .name = "fltp", .bits = 32, .planar = 1, .altform = AV_SAMPLE_FMT_FLT  },
    # [AV_SAMPLE_FMT_DBLP] = { .name = "dblp", .bits = 64, .planar = 1, .altform = AV_SAMPLE_FMT_DBL  },
})

proc avSampleFmtIsPlanar*(sampleFmt: int): cint =
  return sampleFmtInfos[sampleFmt].planar

proc avPopcountC*(x: uint32): cint {.inline.} =
  result = x.cint
  dec(result, (result shr 1) and 0x55555555)
  result = (result and 0x33333333) + ((result shr 2) and 0x33333333)
  result = (result + (result shr 4)) and 0x0F0F0F0F
  result += result shr 8
  result = (result + (result shr 16)) and 0x0000003F

proc avPopcount64C*(x: uint64): cint {.inline.} =
  cint avPopcountC(x.uint32) + avPopcountC(uint32(x shr 32))

proc avGetChannelLayoutNbChannels*(channelLayout: uint64): cint = avPopcount64C(channelLayout)

proc avGetBytesPerSample*(sampleFmt: int): cint =
  result = if sampleFmt < 0 or sampleFmt >= AV_SAMPLE_FMT_NB.ord: 0 else: sampleFmtInfos[sampleFmt].bits shr 3

proc avSamplesGetBufferSize*(linesize: ptr int; nbChannels: cint; nbSamples: cint;
                            sampleFmt: int; align: var cint): cint =
  var sampleSize: cint = avGetBytesPerSample(sampleFmt.ord)
  var planar: cint = avSampleFmtIsPlanar(sampleFmt.ord)
  if sampleSize == 0 or nbSamples <= 0 or nbChannels <= 0:
    return -(EINVAL)
  var sample = nbSamples
  if align == 0:
    align = 1
    sample = cint FFALIGN(nbSamples, 32)
  if nbChannels > int.high div align or (nbChannels * sample) > (int.high - (align * nbChannels)) div sampleSize:
    return -(EINVAL)
  var size:cint =  if planar != 0: cint FFALIGN(nbSamples * sampleSize, align) else: cint FFALIGN(nbSamples * sampleSize * nbChannels, align)
  if size != 0:
    linesize[] = size
  result = if planar != 0: cint size * nbChannels else: cint size


proc getAudioBuffer*(frame: var AVFrame; align: var cint): cint =
  var planar: cint = avSampleFmtIsPlanar(frame.format)
  if frame.channels == 0:
    frame.channels = avGetChannelLayoutNbChannels(frame.channelLayout)
  var channels = cint frame.channels
  var planes = if planar != 0: channels else: 1
  # check_Channels_Consistency(frame)
  if frame.linesize[0] == 0:
    result = avSamplesGetBufferSize(frame.linesize[0].addr, channels, frame.nbSamples.cint, frame.format, align)
  if planes > AV_NUM_DATA_POINTERS:
    frame.extendedData.setLen planes
    frame.extendedBuf.setLen planes - AV_NUM_DATA_POINTERS
    frame.nbExtendedBuf = planes - AV_NUM_DATA_POINTERS
  else:
    frame.extendedData = frame.data
  for i in 0..<min(planes, AV_NUM_DATA_POINTERS):
    frame.buf[i] = AVBufferRef(size: frame.linesize[0])
    frame.data[i] = frame.buf[i].data[]
    frame.extendedData[i] = frame.data[i]
  for i in 0..<planes - AV_NUM_DATA_POINTERS:
    frame.extendedBuf[i] = AVBufferRef(size:frame.linesize[0])
    frame.extendedData[i + AV_NUM_DATA_POINTERS] = frame.extendedBuf[i].data[]
  return 0

proc avFrameGetBuffer*(frame: var AVFrame; align: var cint): cint =
  if frame.format < 0:
    return -(EINVAL)
  if frame.width > 0 and frame.height > 0:
    return getVideoBuffer(frame, align)
  elif frame.nbSamples > 0 and (frame.channelLayout or frame.channels.uint64) > 0:
    return getAudioBuffer(frame, align)
  return -(EINVAL)

# proc avFrameRef*(dst: var AVFrame; src: AVFrame): cint =
#   dst.format = src.format
#   dst.width = src.width
#   dst.height = src.height
#   dst.channels = src.channels
#   dst.channelLayout = src.channelLayout
#   dst.nbSamples = src.nbSamples
#   result = frameCopyProps(dst, src, 0)
#   if result < 0:
#     return result
#   if src.buf[0] == nil:
#     result = avFrameGetBuffer(dst, 0)
#     result = avFrameCopy(dst, src)
#     return result
#   for i in 0..<src.buf.len:
#     if src.buf[i] == nil:
#       continue
#     dst.buf[i] = src.buf[i]
#   if src.extendedBuf != nil:
#     dst.extendedBuf = avMalloczArray(sizeof((dst.extendedBuf[])), src.nbExtendedBuf)
#     dst.nbExtendedBuf = src.nbExtendedBuf
#     for i in 0..<src.nbExtendedBuf:
#       dst.extendedBuf[i] = src.extendedBuf[i]
#   if src.hwFramesCtx != nil:
#     dst.hwFramesCtx = src.hwFramesCtx
#   if src.extendedData != src.data:
#     var ch = src.channels
#     check_Channels_Consistency(src)
#     dst.extendedData = avMallocArray(sizeof(dst.extendedData[]), ch)
#     copyMem(dst.extendedData, src.extendedData, sizeof((src.extendedData[]) * ch))
#   else:
#     dst.extendedData = dst.data
#   copyMem(dst.data, src.data, sizeof((src.data)))
#   copyMem(dst.linesize, src.linesize, sizeof((src.linesize)))
#   result = 0
#   avFrameUnref(dst)
#   return result

type
  HWMapDescriptor* = ref object
    source*: AVFrame
    hwFramesCtx*: AVBufferRef
    unmap*: proc (ctx: ptr AVHWFramesContext; hwmap: ptr HWMapDescriptor)
    priv*: pointer

proc avHwframeMap*(dst: var AVFrame; src: AVFrame; flags: cint): cint =
  var
    srcFrames: ptr AVHWFramesContext
    dstFrames: ptr AVHWFramesContext
  var hwmap: ptr HWMapDescriptor
  if src.hwFramesCtx != nil and dst.hwFramesCtx != nil:
    srcFrames = cast[ptr AVHWFramesContext](src.hwFramesCtx.data)
    dstFrames = cast[ptr AVHWFramesContext](dst.hwFramesCtx.data)
    if (srcFrames == dstFrames and src.format == dstFrames.swFormat.ord and dst.format == dstFrames.format.ord) or
        (srcFrames.internal.sourceFrames != nil and srcFrames.internal.sourceFrames.data == dstFrames):
      if src.buf[0] == nil:
        echo("Invalid mapping found when attempting unmap.\n")
        return -(EINVAL)
      hwmap = cast[ptr HWMapDescriptor](src.buf[0].data)
      dst = hwmap.source
      return 0
  if src.hwFramesCtx != nil:
    srcFrames = cast[ptr AVHWFramesContext](src.hwFramesCtx.data)
    if srcFrames.format.ord == src.format and srcFrames.internal.hwType.mapFrom != nil:
      result = srcFrames.internal.hwType.mapFrom(srcFrames, dst, src, flags)
      if result != -(ENOSYS):
        return result
  if dst.hwFramesCtx != nil:
    dstFrames = cast[ptr AVHWFramesContext](dst.hwFramesCtx.data)
    if dstFrames.format.ord == dst.format and dstFrames.internal.hwType.mapTo != nil:
      result = dstFrames.internal.hwType.mapTo(dstFrames, dst, src, flags)
      if result != -(ENOSYS):
        return result
  return -(ENOSYS)


proc avHwframeGetBuffer*(hwframeRef: AVBufferRef; frame: var AVFrame; flags: cint): cint =
  var ctx = cast[ptr AVHWFramesContext](hwframeRef.data)
  if ctx[].internal.sourceFrames != nil:
    var srcFrame: AVFrame
    frame.format = ctx[].format.ord
    frame.hwFramesCtx = hwframeRef
    if frame.hwFramesCtx == nil:
      return - ENOMEM
    result = avHwframeGetBuffer(ctx[].internal.sourceFrames, srcFrame, 0)
    if result < 0:
      return result
    result = avHwframeMap(frame, srcFrame, ctx.internal.sourceAllocationMapFlags)
    if result != 0:
      echo("Failed to map frame into derived frame context: %d.\n", result)
      return result
    return 0
  if ctx.internal.hwType.framesGetBuffer == nil:
    return -(Enosys)
  if ctx.pool == nil:
    return -(EINVAL)
  frame.hwFramesCtx = hwframeRef
  if frame.hwFramesCtx == nil:
    return -(ENOMEM)
  result = ctx.internal.hwType.framesGetBuffer(ctx[], frame)
  if result < 0:
    return result
  frame.extendedData = frame.data
  return 0

type
  FramePool* = ref object
    pools*: array[4, ptr AVBufferPool] 
    format*: cint
    width*: cint
    height*: cint
    strideAlign*: array[AV_NUM_DATA_POINTERS, cint]
    linesize*: array[4, cint]
    planes*: cint
    channels*: cint
    samples*: cint

proc framePoolAlloc*(): ptr AVBufferRef =
  var pool = FramePool()
  result.buffer = AVBuffer(data:cast[ptr uint8](pool) ,size: sizeof(FramePool))
  # result = avBufferCreate(cast[ptr uint8](pool), sizeof(pool[]), framePoolFree, nil, 0)

const STRIDE_ALIGN = 64
proc avcodecAlignDimensions2*(s: var AVCodecContext; width: var auto; height: var auto;
                             linesizeAlign: var array[AV_NUM_DATA_POINTERS, cint]) =
  var i: cint
  var wAlign = 1
  var hAlign = 1
  var desc = avPixFmtDescGet(s.pixFmt.ord)
  if desc != nil:
    wAlign = 1 shl desc.log2ChromaW
    hAlign = 1 shl desc.log2ChromaH
  case s.pixFmt
  of AV_PIX_FMT_YUV420P, AV_PIX_FMT_YUYV422, AV_PIX_FMT_YVYU422, AV_PIX_FMT_UYVY422,
    AV_PIX_FMT_YUV422P, AV_PIX_FMT_YUV440P, AV_PIX_FMT_YUV444P, AV_PIX_FMT_GBRP,
    AV_PIX_FMT_GBRAP, AV_PIX_FMT_GRAY8, AV_PIX_FMT_GRAY16BE, AV_PIX_FMT_GRAY16LE,
    AV_PIX_FMT_YUVJ420P, AV_PIX_FMT_YUVJ422P, AV_PIX_FMT_YUVJ440P,
    AV_PIX_FMT_YUVJ444P, AV_PIX_FMT_YUVA420P, AV_PIX_FMT_YUVA422P,
    AV_PIX_FMT_YUVA444P, AV_PIX_FMT_YUV420P9le, AV_PIX_FMT_YUV420P9be,
    AV_PIX_FMT_YUV420P10le, AV_PIX_FMT_YUV420P10be, AV_PIX_FMT_YUV420P12le,
    AV_PIX_FMT_YUV420P12be, AV_PIX_FMT_YUV420P14le, AV_PIX_FMT_YUV420P14be,
    AV_PIX_FMT_YUV420P16le, AV_PIX_FMT_YUV420P16be, AV_PIX_FMT_YUVA420P9LE,
    AV_PIX_FMT_YUVA420P9BE, AV_PIX_FMT_YUVA420P10LE, AV_PIX_FMT_YUVA420P10BE,
    AV_PIX_FMT_YUVA420P16LE, AV_PIX_FMT_YUVA420P16BE, AV_PIX_FMT_YUV422P9LE,
    AV_PIX_FMT_YUV422P9BE, AV_PIX_FMT_YUV422P10LE, AV_PIX_FMT_YUV422P10BE,
    AV_PIX_FMT_YUV422P12LE, AV_PIX_FMT_YUV422P12BE, AV_PIX_FMT_YUV422P14LE,
    AV_PIX_FMT_YUV422P14BE, AV_PIX_FMT_YUV422P16LE, AV_PIX_FMT_YUV422P16BE,
    AV_PIX_FMT_YUVA422P9LE, AV_PIX_FMT_YUVA422P9BE, AV_PIX_FMT_YUVA422P10LE,
    AV_PIX_FMT_YUVA422P10BE, AV_PIX_FMT_YUVA422P12LE, AV_PIX_FMT_YUVA422P12BE,
    AV_PIX_FMT_YUVA422P16LE, AV_PIX_FMT_YUVA422P16BE, AV_PIX_FMT_YUV440P10LE,
    AV_PIX_FMT_YUV440P10BE, AV_PIX_FMT_YUV440P12LE, AV_PIX_FMT_YUV440P12BE,
    AV_PIX_FMT_YUV444P9LE, AV_PIX_FMT_YUV444P9BE, AV_PIX_FMT_YUV444P10LE,
    AV_PIX_FMT_YUV444P10BE, AV_PIX_FMT_YUV444P12LE, AV_PIX_FMT_YUV444P12BE,
    AV_PIX_FMT_YUV444P14LE, AV_PIX_FMT_YUV444P14BE, AV_PIX_FMT_YUV444P16LE,
    AV_PIX_FMT_YUV444P16BE, AV_PIX_FMT_YUVA444P9LE, AV_PIX_FMT_YUVA444P9BE,
    AV_PIX_FMT_YUVA444P10LE, AV_PIX_FMT_YUVA444P10BE, AV_PIX_FMT_YUVA444P12LE,
    AV_PIX_FMT_YUVA444P12BE, AV_PIX_FMT_YUVA444P16LE, AV_PIX_FMT_YUVA444P16BE,
    AV_PIX_FMT_GBRP9LE, AV_PIX_FMT_GBRP9BE, AV_PIX_FMT_GBRP10LE,
    AV_PIX_FMT_GBRP10BE, AV_PIX_FMT_GBRP12LE, AV_PIX_FMT_GBRP12BE,
    AV_PIX_FMT_GBRP14LE, AV_PIX_FMT_GBRP14BE, AV_PIX_FMT_GBRP16LE,
    AV_PIX_FMT_GBRP16BE, AV_PIX_FMT_GBRAP12LE, AV_PIX_FMT_GBRAP12BE,
    AV_PIX_FMT_GBRAP16LE, AV_PIX_FMT_GBRAP16BE:
    wAlign = 16
    hAlign = 16 * 2
  of AV_PIX_FMT_YUV411P, AV_PIX_FMT_YUVJ411P, AV_PIX_FMT_UYYVYY411:
    wAlign = 32
    hAlign = 16 * 2
  of AV_PIX_FMT_YUV410P:
    if s.codecId == AV_CODEC_ID_SVQ1:
      wAlign = 64
      hAlign = 64
  of AV_PIX_FMT_RGB555LE:
    if s.codecId == AV_CODEC_ID_RPZA:
      wAlign = 4
      hAlign = 4
    if s.codecId == AV_CODEC_ID_INTERPLAY_VIDEO:
      wAlign = 8
      hAlign = 8
  of AV_PIX_FMT_PAL8, AV_PIX_FMT_BGR8, AV_PIX_FMT_RGB8:
    if s.codecId == AV_CODEC_ID_SMC or s.codecId == AV_CODEC_ID_CINEPAK:
      wAlign = 4
      hAlign = 4
    if s.codecId == AV_CODEC_ID_JV or s.codecId == AV_CODEC_ID_INTERPLAY_VIDEO:
      wAlign = 8
      hAlign = 8
  of AV_PIX_FMT_BGR24:
    if (s.codecId == AV_CODEC_ID_MSZH) or (s.codecId == AV_CODEC_ID_ZLIB):
      wAlign = 4
      hAlign = 4
  of AV_PIX_FMT_RGB24:
    if s.codecId == AV_CODEC_ID_CINEPAK:
      wAlign = 4
      hAlign = 4
  else:
    discard
  if s.codecId == AV_CODEC_ID_IFF_ILBM:
    wAlign = max(wAlign, 8)
  width = cint FFALIGN(width, wAlign)
  height = cint FFALIGN(height, hAlign)
  if s.codecId == AV_CODEC_ID_H264 or s.lowres != 0 or s.codecId == AV_CODEC_ID_VP5 or
      s.codecId == AV_CODEC_ID_VP6 or s.codecId == AV_CODEC_ID_VP6F or
      s.codecId == AV_CODEC_ID_VP6A:

    inc(height, 2)
    width = max(width, 32)
  for i in 0..3:
    linesizeAlign[i] = STRIDE_ALIGN


proc updateFramePool*(avctx: var AVCodecContext; frame: AVFrame): cint =
  var pool = if avctx.internal.pool != nil: cast[ptr FramePool](avctx.internal.pool.data) else: nil
  var
    ch: cint
    planes: cint
  if avctx.codecType == AVMEDIA_TYPE_AUDIO:
    var planar: cint = avSampleFmtIsPlanar(frame.format)
    ch = cint frame.channels
    planes = if planar != 0: ch else: 1
  if pool != nil and pool.format == frame.format:
    if avctx.codecType == AVMEDIA_TYPE_VIDEO and pool.width == frame.width and
        pool.height == frame.height:
      return 0
    if avctx.codecType == AVMEDIA_TYPE_AUDIO and pool.planes == planes and
        pool.channels == ch and frame.nbSamples == pool.samples:
      return 0
  var poolBuf = framePoolAlloc()
  pool = cast[ptr FramePool](poolBuf.data)
  case avctx.codecType
  of AVMEDIA_TYPE_VIDEO:
    var linesize = newSeq[int](4)
    var w = frame.width
    var h = frame.height
    var unaligned: cint
    var linesize1 = newSeq[int](4)
    var size = newSeq[uint](4)
    avcodecAlignDimensions2(avctx, w, h, pool.strideAlign)
    while true:
      result = avImageFillLinesizes(linesize, avctx.pixFmt.ord, w)
      if result < 0:
        return
      inc(w, w and not (w - 1))
      unaligned = 0
      for i in 0..4:
        unaligned = cint unaligned or (linesize[i] mod pool.strideAlign[i]) 
      if unaligned == 0:
        break
    for i in 0..3:
      linesize1[i] = linesize[i]
    result = avImageFillPlaneSizes(size, avctx.pixFmt.ord, h.cint, linesize1)
    if result < 0:
      return
    for i in 0..3:
      pool.linesize[i] = cint linesize[i]
      if size[i] != 0:
        if size[i] > int.high - (16 + STRIDE_ALIGN - 1):
          result = -(EINVAL)
          return
        pool.pools[i] = avBufferPoolInit(size[i] + 16 + STRIDE_ALIGN - 1, if config_Memory_Poisoning: nil else: avBufferAllocz)
        if pool.pools[i] == nil:
          result = -(ENOMEM)
          return
    pool.format = frame.format
    pool.width = frame.width
    pool.height = frame.height
  of AVMEDIA_TYPE_AUDIO:
    result = avSamplesGetBufferSize(addr(pool.linesize[0]), ch, frame.nbSamples,frame.format, 0)
    if result < 0:
      return
    pool.pools[0] = avBufferPoolInit(pool.linesize[0], nil)
    if pool.pools[0] == 0:
      result = -(ENOMEM)
      return
    pool.format = frame.format
    pool.planes = planes
    pool.channels = ch
    pool.samples = frame.nbSamples
  else:
    discard
  # avBufferUnref(addr(avctx.internal.pool))
  avctx.internal.pool = poolBuf
  result = 0
  # avBufferUnref(addr(poolBuf))

proc videoGetBuffer*(s: ptr AVCodecContext; pic: ptr AVFrame): cint =
  var pool: ptr FramePool = cast[ptr FramePool](s.internal.pool.data)
  var desc: ptr AVPixFmtDescriptor = avPixFmtDescGet(pic.format)
  var i: cint
  if pic.data[0] or pic.data[1] or pic.data[2] or pic.data[3]:
    echo( "pic->data[*]!=NULL in avcodec_default_get_buffer\n")
    return -1
  if desc == nil:
    echo("Unable to get pixel format descriptor for format %s\n",
          avGetPixFmtName(pic.format))
    return -(EINVAL)
  pic.extendedData = pic.data
  for i in 0..3:
    if pool.pools[i] != nil:
      pic.linesize[i] = pool.linesize[i]
      pic.buf[i] = avBufferPoolGet(pool.pools[i])
      if pic.buf[i] == nil:
        return
      pic.data[i] = pic.buf[i].data
  for i in 0..<AV_NUM_DATA_POINTERS:
    pic.data[i] = nil
    pic.linesize[i] = 0
  if (desc.flags and AV_PIX_FMT_FLAG_PAL) != 0 or ((desc.flags and ff_Pseudopal) and pic.data[1] != nil):
    avprivSetSystematicPal2(cast[ptr uint32](pic.data[1]), pic.format)
  if (s.debug and ff_Debug_Buffers) != 0:
    echo("default_get_buffer called on pic %p\n", pic)
  return 0
  # avFrameUnref(pic)
  return -(ENOMEM)


proc avcodecDefaultGetBuffer2*(avctx:var AVCodecContext; frame: var AVFrame;flags: int): int =
  if avctx.hwFramesCtx != nil:
    result = avHwframeGetBuffer(avctx.hwFramesCtx, frame, 0)
    frame.width = avctx.codedWidth
    frame.height = avctx.codedHeight
    return result
  result = updateFramePool(avctx, frame)
  if result < 0:
    return 
  case avctx.codecType
  of AVMEDIA_TYPE_VIDEO:
    return videoGetBuffer(avctx, frame)
  of AVMEDIA_TYPE_AUDIO:
    return audioGetBuffer(avctx, frame)
  else:
    return -1

proc audioGetBuffer*(avctx: ptr AVCodecContext; frame: ptr AVFrame): cint =
  var pool: ptr FramePool = cast[ptr FramePool](avctx.internal.pool.data)
  var planes: cint = pool.planes
  frame.linesize[0] = pool.linesize[0]
  if planes > AV_NUM_DATA_POINTERS:
    frame.extendedData.setLen planes
    frame.nbExtendedBuf = planes - AV_NUM_DATA_POINTERS
    frame.extendedBuf.setLen frame.nbExtendedBuf
  else:
    frame.extendedData = frame.data
  for i in 0..<min(planes, AV_NUM_DATA_POINTERS):
    frame.buf[i] = avBufferPoolGet(pool.pools[0])
    frame.data[i] = frame.buf[i].data
    frame.extendedData[i] = frame.buf[i].data
  for i in 0..<frame.nbExtendedBuf:
    frame.extendedBuf[i] = avBufferPoolGet(pool.pools[0])
    frame.extendedData[i + AV_NUM_DATA_POINTERS] = frame.extendedBuf[i].data
  if (avctx.debug and ff_Debug_Buffers) != 0:
    echo("default_get_buffer called on frame %p", frame)
  return 0
  


proc avcodecDefaultGetFormat*(avctx: AVCodecContext; fmt: AVPixelFormat): AVPixelFormat =
  var desc: ptr AVPixFmtDescriptor
  var config: ptr AVCodecHWConfig
  var
    i: cint
    n: cint
  if avctx.hwDeviceCtx != nil and avctx.codec.hwConfigs != nil:
    var deviceCtx = cast[ptr AVHWDeviceContext](avctx.hwDeviceCtx.data)
    i = 0
    while true:
      config = addr(avctx.codec.hwConfigs[i].public)
      if config == nil:
        break
      if (config.methods and av_Codec_Hw_Config_Method_Hw_Device_Ctx) != 0:
        continue
      if deviceCtx.t != config.deviceType:
        continue
      n = 0
      while fmt[n] != AV_PIX_FMT_NONE:
        if config.pixFmt == fmt[n]:
          return fmt[n]
        inc(n)
      inc(i)
  n = 0
  while fmt[n] != av_Pix_Fmt_None:
    nil
    inc(n)
  desc = avPixFmtDescGet(fmt[n - 1])
  if not (desc.flags and av_Pix_Fmt_Flag_Hwaccel):
    return fmt[n - 1]
  n = 0
  while fmt[n] != av_Pix_Fmt_None:
    i = 0
    while true:
      config = avcodecGetHwConfig(avctx.codec, i)
      if not config:
        break
      if config.pixFmt == fmt[n]:
        break
      inc(i)
    if not config:
      ##  No specific config available, so the decoder must be able
      ##  to handle this format without any additional setup.
      return fmt[n]
    if config.methods and av_Codec_Hw_Config_Method_Internal:
      ##  Usable with only internal setup.
      return fmt[n]
    inc(n)
  ##  Nothing is usable, give up.
  return av_Pix_Fmt_None

proc ffGetBuffer*(avctx: AVCodecContext; frame: AVFrame; flags: cint): cint =
  var hwaccel: AVHWAccel = avctx.hwaccel
  var overrideDimensions: cint = 1
  if avctx.codecType == AVMEDIA_TYPE_VIDEO:
    # result = avImageCheckSize2(FFALIGN(avctx.width, STRIDE_ALIGN), avctx.height, avctx.maxPixels, av_Pix_Fmt_None, 0, avctx)
    if avctx.width > int.high - STRIDE_ALIGN or result < 0 or avctx.pixFmt.ord < 0:
      echo("video_get_buffer: image parameters invalid\n")
      result = -(EINVAL)
    if frame.width <= 0 or frame.height <= 0:
      frame.width = max(avctx.width, avctx.codedWidth)
      frame.height = max(avctx.height, avctx.codedHeight)
      overrideDimensions = 0
    if frame.data[0] != nil or frame.data[1] != nil or frame.data[2] != nil or frame.data[3] != nil:
      echo("pic->data[*]!=NULL in get_buffer_internal\n")
      result = -(EINVAL)
  elif avctx.codecType == AVMEDIA_TYPE_AUDIO:
    if frame.nbSamples * cast[int64](avctx.channels) > avctx.maxSamples:
      echo("samples per frame %d, exceeds max_samples %lld, frame.nbSamples, avctx.maxSamples")
      result = -EINVAL
  result = ffDecodeFrameProps(avctx, frame)
  if hwaccel != nil:
    if hwaccel.allocFrame != nil:
      result = hwaccel.allocFrame(avctx, frame)
      return
  else:
    avctx.swPixFmt = avctx.pixFmt
  result = avctx.getBuffer2(avctx, frame, flags)
  if result < 0:
    return
  validateAvframeAllocation(avctx, frame)
  result = ffAttachDecodeData(frame)
  if result < 0:
    return
  if avctx.codecType == AVMEDIA_TYPE_VIDEO and overrideDimensions == 0 and (avctx.codec.capsInternal and ff_Codec_Cap_Exports_Cropping) == 0:
    frame.width = avctx.width
    frame.height = avctx.height
  if result < 0:
    echo("get_buffer() failed\n")
    # avFrameUnref(frame)
  return result


proc submitPacket*(p: var PerThreadContext; userAvctx: AVCodecContext; avpkt: AVPacket): cint =
  var fctx: FrameThreadContext = p.parent
  var prevThread: PerThreadContext = fctx.prevThread
  var codec: AVCodec = p.avctx.codec
  if avpkt.size == 0 and (codec.capabilities and AV_CODEC_CAP_DELAY) == 0:
    return 0
  discard pthread_mutex_lock(p.mutex)
  p.avctx = userAvctx
  # result = updateContextFromUser(p.avctx, userAvctx)

  # atomicStoreExplicit(p.debugThreads, (p.avctx.debug and FF_DEBUG_THREADS) != 0, memoryOrderRelaxed)
  atomicStore(p.debugThreads.addr, p.avctx.debug and FF_DEBUG_THREADS)
  # releaseDelayedBuffers(p)
  if prevThread != nil:
    var err: cint
    if atomicLoad(prevThread.state.addr) == STATE_SETTING_UP:
      discard pthread_mutex_lock(prevThread.progressMutex)
      while true:
        if atomicLoad(prevThread.state.addr) == STATE_SETTING_UP:
          discard pthread_cond_wait(prevThread.progressCond, prevThread.progressMutex)
      discard pthread_mutex_unlock(prevThread.progressMutex)
    p.avctx = prevThread.avctx
  atomicStore(p.state.addr, STATE_SETTING_UP)
  discard pthread_cond_signal(p.inputCond)
  discard pthread_mutex_unlock(p.mutex)

  if p.avctx.threadSafeCallbacks == 0 and (p.avctx.getFormat != avcodecDefaultGetFormat or p.avctx.getBuffer2 != avcodecDefaultGetBuffer2):
    while atomicLoad(p.state.addr) != STATE_SETUP_FINISHED and atomicLoad(p.state.addr) != STATE_INPUT_READY:
      var callDone: cint = 1
      discard pthread_mutex_lock(p.progressMutex)
      while atomicLoad(p.state.addr) == STATE_SETTING_UP:
        discard pthread_cond_wait(p.progressCond, p.progressMutex)
      case atomicLoad(p.state.addr)
      of STATE_GET_BUFFER:
        p.result = ffGetBuffer(p.avctx, p.requestedFrame, p.requestedFlags)
      of STATE_GET_FORMAT:
        p.resultFormat = ffGetFormat(p.avctx, p.availableFormats)
      else:
        callDone = 0
      if callDone != 0:
        atomicStore(p.state.addr, STATE_SETTING_UP)
        discard pthread_cond_signal(p.progressCond)
      discard pthread_mutex_unlock(p.progressMutex)
  fctx.prevThread = p
  inc(fctx.nextDecoding)
  return 0


proc ffThreadDecodeFrame*(avctx: var AVCodecContext; picture: var AVFrame;gotPicturePtr: var cint; avpkt: var AVPacket): cint =
  var fctx: FrameThreadContext = cast[FrameThreadContext](avctx.internal.threadCtx)
  var finished: cint = fctx.nextFinished
  var p: PerThreadContext
  var err: cint
  # asyncUnlock(fctx)
  p = fctx.threads[fctx.nextDecoding]
  err = submitPacket(p, avctx, avpkt)
  if fctx.nextDecoding > (avctx.threadCount - 1 - int(avctx.codecId.ord == AV_CODEC_ID_FFV1.ord)):
    fctx.delaying = 0
  if fctx.delaying != 0:
    gotPicturePtr[] = 0
    if avpkt.size:
      err = avpkt.size
      break finish
  while true:
    p = fctx.threads[inc(finished)]
    if atomicLoad(p.state) != STATE_INPUT_READY:
      pthread_mutex_lock(p.progressMutex)
      while atomicLoadExplicit(p.state, memoryOrderRelaxed) != STATE_INPUT_READY:
        pthread_cond_wait(p.outputCond, p.progressMutex)
      pthread_mutex_unlock(p.progressMutex)
    avFrameMoveRef(picture, p.frame)
    gotPicturePtr[] = p.gotFrame
    picture.pktDts = p.avpkt.dts
    err = p.result
    p.gotFrame = 0
    p.result = 0
    if finished >= avctx.threadCount:
      finished = 0
    if not (not avpkt.size and not gotPicturePtr[] and err >= 0 and finished != fctx.nextFinished):
      break
  updateContextFromThread(avctx, p.avctx, 1)
  if fctx.nextDecoding >= avctx.threadCount:
    fctx.nextDecoding = 0
  fctx.nextFinished = finished
  if err >= 0:
    err = avpkt.size
  # asyncLock(fctx)
  return err

proc guessCorrectPts*(ctx: ptr AVCodecContext; reorderedPts: int64; dts: int64): int64 =
  var pts: int64
  if dts != 0:
    inc(ctx.ptsCorrectionNumFaultyDts, dts <= ctx.ptsCorrectionLastDts)
    ctx.ptsCorrectionLastDts = dts
  elif reorderedPts != 0:
    ctx.ptsCorrectionLastDts = reorderedPts
  if reorderedPts != 0:
    inc(ctx.ptsCorrectionNumFaultyPts, reorderedPts <= ctx.ptsCorrectionLastPts)
    ctx.ptsCorrectionLastPts = reorderedPts
  elif dts != 0:
    ctx.ptsCorrectionLastPts = dts
  if (ctx.ptsCorrectionNumFaultyPts <= ctx.ptsCorrectionNumFaultyDts or
      dts == 0) and reorderedPts != 0:
    pts = reorderedPts
  else:
    pts = dts
  return pts


proc decodeSimpleInternal*(avctx: var AVCodecContext; frame: AVFrame; discardedSamples:var int64): cint  =
  var avci = avctx.internal
  var ds = avci.ds
  var pkt = ds.inPkt
  var
    gotFrame: cint
    actualGotFrame: cint
  if pkt.data == 0 and avci.draining == 0:
    avPacketUnref(pkt)
    result = ffDecodeGetPacket(avctx, pkt)
    if result < 0 and result != averror_Eof:
      return result
  if avci.drainingDone != 0:
    return averror_Eof
  if pkt.data == 0 and (avctx.codec.capabilities and AV_CODEC_CAP_DELAY) == 0 and (avctx.activeThreadType and FF_THREAD_FRAME) == 0:
    return averror_Eof
  gotFrame = 0
  if HAVE_THREADS != 0 and (avctx.activeThreadType and FF_THREAD_FRAME) != 0:
    result = ffThreadDecodeFrame(avctx, frame, gotFrame, pkt)
  else:
    result = avctx.codec.decode(avctx, frame, gotFrame, pkt)
    if (avctx.codec.capsInternal and ff_Codec_Cap_Sets_Pkt_Dts) != 0:
      frame.pktDts = pkt.dts
    if avctx.codec.t == AVMEDIA_TYPE_VIDEO:
      if avctx.hasBFrames == 0:
        frame.pktPos = pkt.pos
      if (avctx.codec.capabilities and AV_CODEC_CAP_DR1) == 0:
        if frame.sampleAspectRatio.num == 0:
          frame.sampleAspectRatio = avctx.sampleAspectRatio
        if frame.width == 0:
          frame.width = avctx.width
        if frame.height == 0:
          frame.height = avctx.height
        if frame.format == AV_PIX_FMT_NONE:
          frame.format = avctx.pixFmt
  emmsC()
  actualGotFrame = gotFrame
  if avctx.codec.t == AVMEDIA_TYPE_VIDEO:
    if (frame.flags and av_Frame_Flag_Discard) != 0 :
      gotFrame = 0
    if gotFrame != 0:
      frame.bestEffortTimestamp = guessCorrectPts(avctx, frame.pts, frame.pktDts)
  elif avctx.codec.t == AVMEDIA_TYPE_AUDIO:
    var side: uint8
    var sideSize: cint
    var discardPadding: uint32 = 0
    var skipReason: uint8 = 0
    var discardReason: uint8 = 0
    if result >= 0 and gotFrame != 0:
      frame.bestEffortTimestamp = guessCorrectPts(avctx, frame.pts, frame.pktDts)
      if frame.format == AV_SAMPLE_FMT_NONE:
        frame.format = avctx.sampleFmt
      if  frame.channelLayout == 0:
        frame.channelLayout = avctx.channelLayout
      if frame.channels == 0:
        frame.channels = avctx.channels
      if frame.sampleRate == 0:
        frame.sampleRate = avctx.sampleRate
    side = avPacketGetSideData(avci.lastPktProps, AV_PKT_DATA_SKIP_SAMPLES, sideSize)
    if side != 0 and sideSize >= 10:
      avci.skipSamples = av_Rl32(side) * avci.skipSamplesMultiplier
      discardPadding = av_Rl32(side + 4)
      echo("skip %d / discard %d samples due to side data\n", avci.skipSamples,cast[cint](discardPadding))
      skipReason = av_Rl8(side + 8)
      discardReason = av_Rl8(side + 9)
    if (frame.flags and av_Frame_Flag_Discard) != 0 and gotFrame != 0 and  (avctx.flags2 and av_Codec_Flag2Skip_Manual) == 0:
      avci.skipSamples = max(0, avci.skipSamples - frame.nbSamples)
      gotFrame = 0
      inc(discardedSamples, frame.nbSamples)
    if avci.skipSamples > 0 and gotFrame != 0 and (avctx.flags2 and av_Codec_Flag2Skip_Manual) == 0:
      if frame.nbSamples <= avci.skipSamples:
        gotFrame = 0
        inc(discardedSamples, frame.nbSamples)
        dec(avci.skipSamples, frame.nbSamples)
        echo( "skip whole frame, skip left: %d\n",avci.skipSamples)
      else:
        avSamplesCopy(frame.extendedData, frame.extendedData, 0, avci.skipSamples,frame.nbSamples - avci.skipSamples, avctx.channels,frame.format)
        if avctx.pktTimebase.num != 0 and avctx.sampleRate != 0:
          var diff_ts = av_rescale_q(avci.skip_samples, AVRational(num:1, den:avctx.sample_rate), avctx.pkt_timebase)
          if frame.pts != 0:
            inc(frame.pts, diffTs)
          if frame.pktPts != 0:
            inc(frame.pktPts, diffTs)
          if frame.pktDts != 0:
            inc(frame.pktDts, diffTs)
          if frame.pktDuration >= diffTs:
            dec(frame.pktDuration, diffTs)
        else:
          echo("Could not update timestamps for skipped samples.")
        echo( "skip %d/%d samples", avci.skipSamples, frame.nbSamples)
        discardedSamples += avci.skipSamples
        dec(frame.nbSamples, avci.skipSamples)
        avci.skipSamples = 0
    if discardPadding > 0 and discardPadding <= frame.nbSamples and gotFrame != 0 and (avctx.flags2 and av_Codec_Flag2Skip_Manual) == 0:
      if discardPadding == frame.nbSamples:
        inc(discardedSamples, frame.nbSamples)
        gotFrame = 0
      else:
        if avctx.pktTimebase.num != 0 and avctx.sampleRate != 0:
          var diff_ts = av_rescale_q(frame.nb_samples - discard_padding,AVRational(num:1, den:avctx.sample_rate),avctx.pkt_timebase)
          frame.pktDuration = diffTs
        else:
          echo("Could not update timestamps for discarded samples.\n")
        echo("discard %d/%d samples\n", discardPadding, frame.nbSamples)
        dec(frame.nbSamples, discardPadding)
    if (avctx.flags2 and av_Codec_Flag2Skip_Manual) != 0 and gotFrame != 0:
      var fside = avFrameNewSideData(frame, av_Frame_Data_Skip_Samples, 10)
      if fside != nil:
        av_Wl32(fside.data, avci.skipSamples)
        av_Wl32(fside.data + 4, discardPadding)
        av_Wl8(fside.data + 8, skipReason)
        av_Wl8(fside.data + 9, discardReason)
        avci.skipSamples = 0
  if avctx.codec.t == AVMEDIA_TYPE_AUDIO and avci.showedMultiPacketWarning == 0 and result >= 0 and result != pkt.size and
      (avctx.codec.capabilities and av_Codec_Cap_Subframes) == 0:
    echo( "Multiple frames in a packet.\n")
    avci.showedMultiPacketWarning = 1
  # if gotFrame == 0:
    # avFrameUnref(frame)
  if result >= 0 and avctx.codec.t == AVMEDIA_TYPE_VIDEO and not (avctx.flags and av_Codec_Flag_Truncated):
    result = pkt.size
  if avctx.framerate.num > 0 and avctx.framerate.den > 0:
    if avci.draining != 0 and actualGotFrame == 0:
      if result < 0:
        var nbErrorsMax: cint = 20 +
            (if HAVE_THREADS != 0 and (avctx.activeThreadType and ff_Thread_Frame): avctx.threadCount else: 1)
        if inc(avci.nbDrainingErrors) >= nbErrorsMax:
          echo("Too many errors when draining, this is a bug. Stop draining and force EOF.\n")
          avci.drainingDone = 1
          result = averror_Bug
      else:
        avci.drainingDone = 1
  inc(avci.compatDecodeConsumed, result)
  if result >= pkt.size or result < 0:
    avPacketUnref(pkt)
    avPacketUnref(avci.lastPktProps)
  else:
    var consumed: cint = result
    inc(pkt.data, consumed)
    dec(pkt.size, consumed)
    dec(avci.lastPktProps.size, consumed)
    pkt.pts = 0
    pkt.dts = 0
    avci.lastPktProps.pts = 0
    avci.lastPktProps.dts = 0
  return if result < 0: result else: 0


proc decodeSimpleReceiveFrame*(avctx: AVCodecContext; frame: AVFrame): cint =
  var result: cint
  var discardedSamples: int64 = 0
  while frame.buf[0] == nil:
    if discardedSamples > avctx.maxSamples:
      return -EAGAIN
    result = decodeSimpleInternal(avctx, frame, discardedSamples)
    if result < 0:
      return result
  return 0


type
  FrameDecodeData* = ref object
    postProcess*: proc (logctx: pointer; frame: var AVFrame): cint 
    postProcessOpaque*: pointer
    postProcessOpaqueFree*: proc (opaque: pointer) 
    hwaccelPriv*: pointer
    hwaccelPrivFree*: proc (priv: pointer)

proc decodeReceiveFrameInternal*(avctx: var AVCodecContext; frame: var AVFrame): cint =
  var avci: AVCodecInternal = avctx.internal
  var result: cint
  if avctx.codec.receiveFrame != nil:
    result = avctx.codec.receiveFrame(avctx, frame)
    # if result != -(eagain):
    #   avPacketUnref(avci.lastPktProps)
  else:
    result = decodeSimpleReceiveFrame(avctx, frame)
  if result == averror_Eof:
    avci.drainingDone = 1
  if result == 0:
    if frame.privateRef != nil:
      var fdd: FrameDecodeData = cast[FrameDecodeData](frame.privateRef.data)
      if fdd.postProcess != nil:
        result = fdd.postProcess(avctx.addr, frame)
        if result < 0:
          # avFrameUnref(frame)
          return result
  # avBufferUnref(frame.privateRef)
  return result


proc avcodecReceiveFrame*(avctx: AVCodecContext; frame: var AVFrame): cint =
  var avci: AVCodecInternal = avctx.internal
#   avFrameUnref(frame)
  if not avcodecIsOpen(avctx) or not avCodecIsDecoder(avctx.codec):
    return -EINVAL
  if avci.bufferFrame.buf[0] != nil:
    frame = avci.bufferFrame
  else:
    result = decodeReceiveFrameInternal(avctx, frame)
    if result < 0:
      return result
  if avctx.codecType == AVMEDIA_TYPE_VIDEO:
    result = applyCropping(avctx, frame)
    if result < 0:
      # avFrameUnref(frame)
      return result
  inc(avctx.frameNumber)
  if (avctx.flags and AV_CODEC_FLAG_DROPCHANGED) != 0:
    if avctx.frameNumber == 1:
      avci.initialFormat = frame.format
      case avctx.codecType
      of AVMEDIA_TYPE_VIDEO:
        avci.initialWidth = frame.width
        avci.initialHeight = frame.height
      of AVMEDIA_TYPE_AUDIO:
        avci.initialSampleRate = if frame.sampleRate: frame.sampleRate else: avctx.sampleRate
        avci.initialChannels = frame.channels
        avci.initialChannelLayout = frame.channelLayout
    if avctx.frameNumber > 1:
      var changed = avci.initialFormat != frame.format
      case avctx.codecType
      of AVMEDIA_TYPE_VIDEO:
        changed = changed or (avci.initialWidth != frame.width or avci.initialHeight != frame.height)
      of AVMEDIA_TYPE_AUDIO:
        changed = changed or (avci.initialSampleRate != frame.sampleRate or avci.initialSampleRate != avctx.sampleRate or avci.initialChannels != frame.channels or avci.initialChannelLayout != frame.channelLayout)
      else:
          discard
      if changed:
        inc(avci.changedFramesDropped)
        echo( "dropped changed frame #%d pts %lld drop count: %d \n", avctx.frameNumber, frame.pts,avci.changedFramesDropped)
        # avFrameUnref(frame)
        return AVERROR_INPUT_CHANGED
  return 0

var inputFilename*: cstring
var windowTitle*: cstring
var defaultWidth*: cint = 640
var defaultHeight*: cint = 480
var screenWidth*: cint = 0
var screenHeight*: cint = 0
var screenLeft*: cint
var screenTop*: cint
var audioDisable*: cint
var videoDisable*: cint
var subtitleDisable*: cint
var wantedStreamSpec*: array[AVMEDIA_TYPE_NB, cstring]
var seekByBytes*: cint = -1
var seekInterval*: cfloat = 10
var displayDisable*: cint
var borderless*: cint
var alwaysontop*: cint
var startupVolume*: cint = 100
var showStatus*: cint = -1
var avSyncType*: cint = av_Sync_Audio_Master
var startTime*: int64 
var duration*: int64
var fast*: cint = 0
var genpts*: cint = 0
var lowres*: cint = 0
var decoderReorderPts*: cint = -1
var autoexit*: cint
var exitOnKeydown*: cint
var exitOnMousedown*: cint
var loop*: cint = 1
var framedrop*: cint = -1
var infiniteBuffer*: cint = -1
var showMode*: ShowMode
var audioCodecName*: cstring
var subtitleCodecName*: cstring
var videoCodecName*: cstring
var rdftspeed*: cdouble = 0.02
var cursorLastShown*: int64
var cursorHidden*: cint = 0
var vfiltersList*: cstringArray 
var nbVfilters*: cint = 0
var afilters*: cstring 
var autorotate*: cint = 1
var findStreamInfo*: cint = 1
var filterNbthreads*: cint = 0
##  current context
var isFullScreen*: cint
var audioCallbackTime*: int64


const
  FF_QUIT_EVENT* = (sdl_Userevent + 2)

var window*: SDL_Window
var renderer*: SDL_Renderer
var rendererInfo*: SDL_RendererInfo
var audioDev*: SDL_AudioDeviceID


proc decoderDecodeFrame*(d: Decoder; frame: AVFrame; sub: AVSubtitle): cint =
    while true:
        if d.queue.serial == d.pktSerial:
          while true:
            if d.queue.abortRequest != 0:
                return -1
            case d.avctx.codecType
            of AVMEDIA_TYPE_VIDEO:
                result = avcodecReceiveFrame(d.avctx, frame)
                if result >= 0:
                    if decoderReorderPts == -1:
                        frame.pts = frame.bestEffortTimestamp
                    elif decoderReorderPts == 0:
                        frame.pts = frame.pktDts
            of AVMEDIA_TYPE_AUDIO:
                result = avcodecReceiveFrame(d.avctx, frame)
                if result >= 0:
                    var tb = AVRational(num:1, den:frame.sample_rate)
                    if frame.pts != 0:
                        frame.pts = avRescaleQ(frame.pts, d.avctx.pktTimebase, tb)
                    elif d.nextPts != 0:
                        frame.pts = avRescaleQ(d.nextPts, d.nextPtsTb, tb)
                    if frame.pts != 0:
                        d.nextPts = frame.pts + frame.nbSamples
                        d.nextPtsTb = tb
            else:discard
            if result == averror_Eof:
                d.finished = d.pktSerial
                avcodecFlushBuffers(d.avctx)
                return 0
            if result >= 0:
                return 1
            if not (result != EAGAIN):
                break
        while true:
        #   if d.queue.nbPackets == 0:
        #     sDL_CondSignal(d.emptyQueueCond)
            if d.packetPending != 0:
                # avPacketMoveRef(pkt, d.pkt)
                d.packetPending = 0
            else:
                while true:
                    if d.queue.abortRequest != 0:
                        result = -1
                        break
                    
                    var pkt = d.queue.firstPkt
                    d.queue.firstPkt = pkt.next
                    d.queue.nbPackets -= 1
                    d.queue.size -= cint pkt.pkt.size + sizeof(pkt)
                    d.queue.duration -= pkt.pkt.duration
                    d.pktSerial= pkt.serial
                    result = 1
                    break
                    # if packetQueueGet(d.queue, pkt, 1, d.pktSerial) < 0:
                    if d.queue.serial == d.pktSerial:
                        break
                    #   avPacketUnref(pkt)
        if pkt.data == flushPkt.data:
            avcodecFlushBuffers(d.avctx)
            d.finished = 0
            d.nextPts = d.startPts
            d.nextPtsTb = d.startPtsTb
        else:
            if d.avctx.codecType == avmedia_Type_Subtitle:
                var gotFrame: cint = 0
                result = avcodecDecodeSubtitle2(d.avctx, sub, gotFrame, pkt)
                if result < 0:
                    result = -(eagain)
                else:
                    if gotFrame and not pkt.data:
                        d.packetPending = 1
                        avPacketMoveRef(d.pkt, pkt)
                    result = if gotFrame: 0 else: (if pkt.data: -(eagain) else: averror_Eof)
            else:
                if avcodecSendPacket(d.avctx, pkt) == -(eagain):
                    echo("Receive_frame and send_packet both returned EAGAIN, which is an API violation.\n")
                    d.packetPending = 1
            #   avPacketMoveRef(d.pkt, pkt)
        #   avPacketUnref(pkt)

# proc decoderDestroy*(d: Decoder) =
#   avPacketUnref(d.pkt)
#   avcodecFreeContext(d.avctx)

proc getVideoFrame*(vs: VideoState; frame: var AVFrame): cint =
  var gotPicture = decoderDecodeFrame(vs.viddec, frame, nil)
  if gotPicture != 0:
    var dpts: cdouble = Nan
    if frame.pts != 0:
      dpts = avQ2d(vs.videoSt.timeBase) * frame.pts
    frame.sampleAspectRatio = avGuessSampleAspectRatio(vs.ic, vs.videoSt, frame)
    if framedrop > 0 or (framedrop and getMasterSyncType(vs) != av_Sync_Video_Master):
      if frame.pts != 0:
        var diff: cdouble = dpts - getMasterClock(vs)
        if Nan != diff and abs(diff) < av_Nosync_Threshold and diff - vs.frameLastFilterDelay < 0 and vs.viddec.pktSerial == vs.vidclk.serial and vs.videoq.nbPackets:
          inc(vs.frameDropsEarly)
          # avFrameUnref(frame)
          gotPicture = 0
  return gotPicture

proc videoThread*(arg: VideoState): cint =
  var vs:  VideoState = arg
  var frame = AVFrame()  
  var pts: cdouble
  var duration: cdouble
  var result: cint
  var tb: AVRational = vs.videoSt.timeBase
  var frameRate: AVRational = avGuessFrameRate(vs.ic, vs.videoSt, nil)
  var graph: AVFilterGraph
  var
    filtOut: AVFilterContext 
    filtIn: AVFilterContext
  var lastW: cint = 0
  var lastH: cint = 0
  var lastFormat: AVPixelFormat = -2
  var lastSerial: cint = -1
  var lastVfilterIdx: cint = 0
  while true:
    result = getVideoFrame(vs, frame)
    if  result == 0:
      continue
    if lastW != frame.width or lastH != frame.height or lastFormat != frame.format or lastSerial != vs.viddec.pktSerial or lastVfilterIdx != vs.vfilterIdx:
      echo("Video frame changed from size:%dx%d format:%s serial:%d to size:%dx%d format:%s serial:%d\n",
            lastW, lastH,
            cast[cstring](avXIfNull(avGetPixFmtName(lastFormat), "none")),
            lastSerial, frame.width, frame.height,
            cast[cstring](avXIfNull(avGetPixFmtName(frame.format), "none")),
            vs.viddec.pktSerial)
      avfilterGraphFree(graph)
      graph = avfilterGraphAlloc()
      graph.nbThreads = filterNbthreads
      result = configureVideoFilters(graph, vs, if vfiltersList: vfiltersList[vs.vfilterIdx] else: nil, frame)
      if result < 0:
        var event: SDL_Event
        event.t = ff_Quit_Event
        event.user.data1 = vs
        sDL_PushEvent(event)
        return
      filtIn = vs.inVideoFilter
      filtOut = vs.outVideoFilter
      lastW = frame.width
      lastH = frame.height
      lastFormat = frame.format
      lastSerial = vs.viddec.pktSerial
      lastVfilterIdx = vs.vfilterIdx
      frameRate = avBuffersinkGetFrameRate(filtOut)
    result = avBuffersrcAddFrame(filtIn, frame)
    if result < 0:
      return
    while result >= 0:
      vs.frameLastReturnedTime = avGettimeRelative() div 1000000.0
      result = avBuffersinkGetFrameFlags(filtOut, frame, 0)
      if result < 0:
        if result == averror_Eof:
          vs.viddec.finished = vs.viddec.pktSerial
        result = 0
        break
      vs.frameLastFilterDelay = avGettimeRelative() div 1000000.0 - vs.frameLastReturnedTime
      if abs(vs.frameLastFilterDelay) > av_Nosync_Threshold div 10.0:
        vs.frameLastFilterDelay = 0
      tb = avBuffersinkGetTimeBase(filtOut)
      duration = if frame_rate.num != 0 and frame_rate.den != 0: av_q2d(AVRational(num:frame_rate.den, den:frame_rate.num)) else: 0
      pts = if (frame.pts == 0): Nan else: frame.pts * avQ2d(tb)
      result = queuePicture(vs, frame, pts, duration, frame.pktPos, vs.viddec.pktSerial)
    #   avFrameUnref(frame)
      if vs.videoq.serial != vs.viddec.pktSerial:
        break
#   avfilterGraphFree(graph)
#   avFrameFree(frame)
  return 0

proc initClock*(c: var Clock; queueSerial: cint) =
  c.speed = 1.0
  c.paused = 0
  c.queueSerial = queueSerial
  setClock(c, Nan, -1)

proc streamOpen*(filename: string; iformat: AVInputFormat): VideoState =
  var videoState = VideoState(filename:filename, iformat:iformat)
  with videoState:
    video_stream = -1
    last_video_stream = -1
    audio_stream = -1
    last_audio_stream = -1
    subtitle_stream = -1
    last_subtitle_stream = -1
  ##  start video display
  echo frameQueueInit(videoState.pictq, videoState.videoq, VIDEO_PICTURE_QUEUE_SIZE, 1)
  echo frameQueueInit(videoState.subpq, videoState.subtitleq, SUBPICTURE_QUEUE_SIZE, 0)
  echo frameQueueInit(videoState.sampq, videoState.audioq, SAMPLE_QUEUE_SIZE, 1)
  if packetQueueInit(videoState.videoq) < 0 or packetQueueInit((videoState.audioq)) < 0 or packetQueueInit((videoState.subtitleq)) < 0:
#   videoState.continue_read_thread = SDL_CreateCond()
  initClock(videoState.vidclk, videoState.videoq.serial)
  initClock(videoState.audclk, videoState.audioq.serial)
  initClock(videoState.extclk, videoState.extclk.serial)
  videoState.audio_clock_serial = -1
  if startup_volume < 0:
    echo("-volume=%d < 0, setting to 0\n", startup_volume)
  if startup_volume > 100:
    echo("-volume=%d > 100, setting to 100\n",startup_volume)
  startup_volume = avClipC(startup_volume, 0, 100)
  startup_volume = avClipC(SDL_MIX_MAXVOLUME * startup_volume div 100, 0, SDL_MIX_MAXVOLUME)
  videoState.audio_volume = startup_volume
  videoState.muted = 0
  videoState.av_sync_type = av_sync_type
  videoState.read_tid = SDL_CreateThread(read_thread, "read_thread", videoState)
  return videoState

var videoState = streamOpen("/mnt/d/videos/mov.mp4", fileIformat)
