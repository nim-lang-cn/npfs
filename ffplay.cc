#include <stddef.h>
#include <inttypes.h>
#include <math.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <iconv.h>
#include <fcntl.h>
#include <zlib.h>
#include <stdatomic.h>
#include <inttypes.h>
#include <math.h>
#include <signal.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <iconv.h>
#include "ev.h"
#include <sys/types.h>
#include <getopt.h>
#include <fcntl.h>

// #include <chrono>
// #include <cstdlib>
// #include <cassert>
// #include <netdb.h>
// #include <vector>
// #include <unordered_map>
// #include <map>
// #include <string>
// #include <deque>
// #include <string_view>
// #include <array>
// #include <memory>
// #include <random>
// #include <functional>
// #include <iostream>
// #include <functional>
// #include <fstream>
// #include <cstring>
// #include <algorithm>
// #include <limits>
// #include <arpa/inet.h>
#if CONFIG_ZLIB
#include <zlib.h>
#endif
// #include <bcrypt.h>
#ifdef _WIN32
#undef open
#undef lseek
#undef stat
#undef fstat
#endif
#include <share.h>
#include <errno.h>
#include "config.h"
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <sys/mman.h>
#endif
#include "config.h"
#define AV_GCC_VERSION_AT_LEAST(x, y) (__GNUC__ > (x) || __GNUC__ == (x) && __GNUC_MINOR__ >= (y))
#define AV_GCC_VERSION_AT_MOST(x, y) (__GNUC__ < (x) || __GNUC__ == (x) && __GNUC_MINOR__ <= (y))
#define AV_HAS_BUILTIN(x) 0
#define inline __attribute__((always_inline)) inline
#define av_extern_inline extern inline
#define av_warn_unused_result __attribute__((warn_unused_result))
#define av_noinline __attribute__((noinline))
#define av_pure __attribute__((pure))
#define av_const __attribute__((const))
#define av_cold __attribute__((cold))
#define av_flatten __attribute__((flatten))
#define attribute_deprecated __attribute__((deprecated))
#define AV_NOWARN_DEPRECATED(code) _Pragma("GCC diagnostic push") _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"") code _Pragma("GCC diagnostic pop")
#define av_unused __attribute__((unused))
#define av_used __attribute__((used))
#define av_alias __attribute__((may_alias))
#define av_uninit(x) x = x
#define av_builtin_constant_p __builtin_constant_p
#define av_printf_format(fmtpos, attrpos) __attribute__((__format__(__printf__, fmtpos, attrpos)))
#define av_noreturn __attribute__((noreturn))
#define AV_STRINGIFY(s) AV_TOSTRING(s)
#define AV_TOSTRING(s) #s
#define AV_GLUE(a, b) a##b
#define AV_JOIN(a, b) AV_GLUE(a, b)
#define AV_PRAGMA(s) _Pragma(#s)
#define FFALIGN(x, a) (((x) + (a)-1) & ~((a)-1))
#define AV_VERSION_INT(a, b, c) ((a) << 16 | (b) << 8 | (c))
#define AV_VERSION_DOT(a, b, c) a##.##b##.##c
#define AV_VERSION(a, b, c) AV_VERSION_DOT(a, b, c)
#define AV_VERSION_MAJOR(a) ((a) >> 16)
#define AV_VERSION_MINOR(a) (((a)&0x00FF00) >> 8)
#define AV_VERSION_MICRO(a) ((a)&0xFF)
#define LIBAVUTIL_VERSION_MAJOR 56
#define LIBAVUTIL_VERSION_MINOR 60
#define LIBAVUTIL_VERSION_MICRO 100
#define LIBAVUTIL_VERSION_INT AV_VERSION_INT(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)
#define LIBAVUTIL_VERSION AV_VERSION(LIBAVUTIL_VERSION_MAJOR, LIBAVUTIL_VERSION_MINOR, LIBAVUTIL_VERSION_MICRO)
#define LIBAVUTIL_BUILD LIBAVUTIL_VERSION_INT
#define LIBAVUTIL_IDENT "Lavu" AV_STRINGIFY(LIBAVUTIL_VERSION)
#define FF_API_VAAPI (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_FRAME_QP (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_PLUS1_MINUS1 (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_ERROR_FRAME (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_PKT_PTS (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_CRYPTO_SIZE_T (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_FRAME_GET_SET (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_PSEUDOPAL (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_CHILD_CLASS_NEXT (LIBAVUTIL_VERSION_MAJOR < 57)
#define FF_API_D2STR (LIBAVUTIL_VERSION_MAJOR < 58)
#define AV_LOG_SKIP_REPEATED 1
#define AV_LOG_PRINT_LEVEL 2
#define AVPALETTE_SIZE 1024
#define AVPALETTE_COUNT 256



enum
{
    STATE_INPUT_READY,
    STATE_SETTING_UP,
    STATE_GET_BUFFER,
    STATE_GET_FORMAT,
    STATE_SETUP_FINISHED,
};
enum AVLockOp
{
    AV_LOCK_CREATE,  ///< Create a mutex
    AV_LOCK_OBTAIN,  ///< Lock the mutex
    AV_LOCK_RELEASE, ///< Unlock the mutex
    AV_LOCK_DESTROY, ///< Free mutex resources
};
enum
{
    CHILD_CLASS_ITER_AVIO = 0,
    CHILD_CLASS_ITER_MUX,
    CHILD_CLASS_ITER_DEMUX,
    CHILD_CLASS_ITER_DONE,

};

enum AVColorPrimaries
{
    AVCOL_PRI_RESERVED0 = 0,
    AVCOL_PRI_BT709 = 1, ///< also ITU-R BT1361 / IEC 61966-2-4 / SMPTE RP177 Annex B
    AVCOL_PRI_UNSPECIFIED = 2,
    AVCOL_PRI_RESERVED = 3,
    AVCOL_PRI_BT470M = 4,    ///< also FCC Title 47 Code of Federal Regulations 73.682 (a)(20)
    AVCOL_PRI_BT470BG = 5,   ///< also ITU-R BT601-6 625 / ITU-R BT1358 625 / ITU-R BT1700 625 PAL & SECAM
    AVCOL_PRI_SMPTE170M = 6, ///< also ITU-R BT601-6 525 / ITU-R BT1358 525 / ITU-R BT1700 NTSC
    AVCOL_PRI_SMPTE240M = 7, ///< functionally identical to above
    AVCOL_PRI_FILM = 8,      ///< colour filters using Illuminant C
    AVCOL_PRI_BT2020 = 9,    ///< ITU-R BT2020
    AVCOL_PRI_SMPTE428 = 10, ///< SMPTE ST 428-1 (CIE 1931 XYZ)
    AVCOL_PRI_SMPTEST428_1 = AVCOL_PRI_SMPTE428,
    AVCOL_PRI_SMPTE431 = 11, ///< SMPTE ST 431-2 (2011) / DCI P3
    AVCOL_PRI_SMPTE432 = 12, ///< SMPTE ST 432-1 (2010) / P3 D65 / Display P3
    AVCOL_PRI_EBU3213 = 22,  ///< EBU Tech. 3213-1 / JEDEC P22 phosphors
    AVCOL_PRI_JEDEC_P22 = AVCOL_PRI_EBU3213,
    AVCOL_PRI_NB ///< Not part of ABI
};

enum AVColorTransferCharacteristic
{
    AVCOL_TRC_RESERVED0 = 0,
    AVCOL_TRC_BT709 = 1, ///< also ITU-R BT1361
    AVCOL_TRC_UNSPECIFIED = 2,
    AVCOL_TRC_RESERVED = 3,
    AVCOL_TRC_GAMMA22 = 4,   ///< also ITU-R BT470M / ITU-R BT1700 625 PAL & SECAM
    AVCOL_TRC_GAMMA28 = 5,   ///< also ITU-R BT470BG
    AVCOL_TRC_SMPTE170M = 6, ///< also ITU-R BT601-6 525 or 625 / ITU-R BT1358 525 or 625 / ITU-R BT1700 NTSC
    AVCOL_TRC_SMPTE240M = 7,
    AVCOL_TRC_LINEAR = 8,        ///< "Linear transfer characteristics"
    AVCOL_TRC_LOG = 9,           ///< "Logarithmic transfer characteristic (100:1 range)"
    AVCOL_TRC_LOG_SQRT = 10,     ///< "Logarithmic transfer characteristic (100 * Sqrt(10) : 1 range)"
    AVCOL_TRC_IEC61966_2_4 = 11, ///< IEC 61966-2-4
    AVCOL_TRC_BT1361_ECG = 12,   ///< ITU-R BT1361 Extended Colour Gamut
    AVCOL_TRC_IEC61966_2_1 = 13, ///< IEC 61966-2-1 (sRGB or sYCC)
    AVCOL_TRC_BT2020_10 = 14,    ///< ITU-R BT2020 for 10-bit system
    AVCOL_TRC_BT2020_12 = 15,    ///< ITU-R BT2020 for 12-bit system
    AVCOL_TRC_SMPTE2084 = 16,    ///< SMPTE ST 2084 for 10-, 12-, 14- and 16-bit systems
    AVCOL_TRC_SMPTEST2084 = AVCOL_TRC_SMPTE2084,
    AVCOL_TRC_SMPTE428 = 17, ///< SMPTE ST 428-1
    AVCOL_TRC_SMPTEST428_1 = AVCOL_TRC_SMPTE428,
    AVCOL_TRC_ARIB_STD_B67 = 18, ///< ARIB STD-B67, known as "Hybrid log-gamma"
    AVCOL_TRC_NB                 ///< Not part of ABI
};

enum AVColorSpace
{
    AVCOL_SPC_RGB = 0,   ///< order of coefficients is actually GBR, also IEC 61966-2-1 (sRGB)
    AVCOL_SPC_BT709 = 1, ///< also ITU-R BT1361 / IEC 61966-2-4 xvYCC709 / SMPTE RP177 Annex B
    AVCOL_SPC_UNSPECIFIED = 2,
    AVCOL_SPC_RESERVED = 3,
    AVCOL_SPC_FCC = 4,       ///< FCC Title 47 Code of Federal Regulations 73.682 (a)(20)
    AVCOL_SPC_BT470BG = 5,   ///< also ITU-R BT601-6 625 / ITU-R BT1358 625 / ITU-R BT1700 625 PAL & SECAM / IEC 61966-2-4 xvYCC601
    AVCOL_SPC_SMPTE170M = 6, ///< also ITU-R BT601-6 525 / ITU-R BT1358 525 / ITU-R BT1700 NTSC
    AVCOL_SPC_SMPTE240M = 7, ///< functionally identical to above
    AVCOL_SPC_YCGCO = 8,     ///< Used by Dirac / VC-2 and H.264 FRext, see ITU-T SG16
    AVCOL_SPC_YCOCG = AVCOL_SPC_YCGCO,
    AVCOL_SPC_BT2020_NCL = 9,          ///< ITU-R BT2020 non-constant luminance system
    AVCOL_SPC_BT2020_CL = 10,          ///< ITU-R BT2020 constant luminance system
    AVCOL_SPC_SMPTE2085 = 11,          ///< SMPTE 2085, Y'2'zD'x
    AVCOL_SPC_CHROMA_DERIVED_NCL = 12, ///< Chromaticity-derived non-constant luminance system
    AVCOL_SPC_CHROMA_DERIVED_CL = 13,  ///< Chromaticity-derived constant luminance system
    AVCOL_SPC_ICTCP = 14,              ///< ITU-R BT.2100-0, ICtCp
    AVCOL_SPC_NB                       ///< Not part of ABI
};

enum AVColorRange
{
    AVCOL_RANGE_UNSPECIFIED = 0,
    AVCOL_RANGE_MPEG = 1,
    AVCOL_RANGE_JPEG = 2,
    AVCOL_RANGE_NB ///< Not part of ABI
};

enum AVChromaLocation
{
    AVCHROMA_LOC_UNSPECIFIED = 0,
    AVCHROMA_LOC_LEFT = 1,    ///< MPEG-2/4 4:2:0, H.264 default for 4:2:0
    AVCHROMA_LOC_CENTER = 2,  ///< MPEG-1 4:2:0, JPEG 4:2:0, H.263 4:2:0
    AVCHROMA_LOC_TOPLEFT = 3, ///< ITU-R 601, SMPTE 274M 296M S314M(DV 4:1:1), mpeg2 4:2:2
    AVCHROMA_LOC_TOP = 4,
    AVCHROMA_LOC_BOTTOMLEFT = 5,
    AVCHROMA_LOC_BOTTOM = 6,
    AVCHROMA_LOC_NB ///< Not part of ABI
};

enum AVPixelFormat
{
    AV_PIX_FMT_NONE = -1,
    AV_PIX_FMT_YUV420P,    ///< planar YUV 4:2:0, 12bpp, (1 Cr & Cb sample per 2x2 Y samples)
    AV_PIX_FMT_YUYV422,    ///< packed YUV 4:2:2, 16bpp, Y0 Cb Y1 Cr
    AV_PIX_FMT_RGB24,      ///< packed RGB 8:8:8, 24bpp, RGBRGB...
    AV_PIX_FMT_BGR24,      ///< packed RGB 8:8:8, 24bpp, BGRBGR...
    AV_PIX_FMT_YUV422P,    ///< planar YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
    AV_PIX_FMT_YUV444P,    ///< planar YUV 4:4:4, 24bpp, (1 Cr & Cb sample per 1x1 Y samples)
    AV_PIX_FMT_YUV410P,    ///< planar YUV 4:1:0,  9bpp, (1 Cr & Cb sample per 4x4 Y samples)
    AV_PIX_FMT_YUV411P,    ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples)
    AV_PIX_FMT_GRAY8,      ///<        Y        ,  8bpp
    AV_PIX_FMT_MONOWHITE,  ///<        Y        ,  1bpp, 0 is white, 1 is black, in each byte pixels are ordered from the msb to the lsb
    AV_PIX_FMT_MONOBLACK,  ///<        Y        ,  1bpp, 0 is black, 1 is white, in each byte pixels are ordered from the msb to the lsb
    AV_PIX_FMT_PAL8,       ///< 8 bits with AV_PIX_FMT_RGB32 palette
    AV_PIX_FMT_YUVJ420P,   ///< planar YUV 4:2:0, 12bpp, full scale (JPEG), deprecated in favor of AV_PIX_FMT_YUV420P and setting color_range
    AV_PIX_FMT_YUVJ422P,   ///< planar YUV 4:2:2, 16bpp, full scale (JPEG), deprecated in favor of AV_PIX_FMT_YUV422P and setting color_range
    AV_PIX_FMT_YUVJ444P,   ///< planar YUV 4:4:4, 24bpp, full scale (JPEG), deprecated in favor of AV_PIX_FMT_YUV444P and setting color_range
    AV_PIX_FMT_UYVY422,    ///< packed YUV 4:2:2, 16bpp, Cb Y0 Cr Y1
    AV_PIX_FMT_UYYVYY411,  ///< packed YUV 4:1:1, 12bpp, Cb Y0 Y1 Cr Y2 Y3
    AV_PIX_FMT_BGR8,       ///< packed RGB 3:3:2,  8bpp, (msb)2B 3G 3R(lsb)
    AV_PIX_FMT_BGR4,       ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1B 2G 1R(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    AV_PIX_FMT_BGR4_BYTE,  ///< packed RGB 1:2:1,  8bpp, (msb)1B 2G 1R(lsb)
    AV_PIX_FMT_RGB8,       ///< packed RGB 3:3:2,  8bpp, (msb)2R 3G 3B(lsb)
    AV_PIX_FMT_RGB4,       ///< packed RGB 1:2:1 bitstream,  4bpp, (msb)1R 2G 1B(lsb), a byte contains two pixels, the first pixel in the byte is the one composed by the 4 msb bits
    AV_PIX_FMT_RGB4_BYTE,  ///< packed RGB 1:2:1,  8bpp, (msb)1R 2G 1B(lsb)
    AV_PIX_FMT_NV12,       ///< planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V)
    AV_PIX_FMT_NV21,       ///< as above, but U and V bytes are swapped
    AV_PIX_FMT_ARGB,       ///< packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
    AV_PIX_FMT_RGBA,       ///< packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
    AV_PIX_FMT_ABGR,       ///< packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
    AV_PIX_FMT_BGRA,       ///< packed BGRA 8:8:8:8, 32bpp, BGRABGRA...
    AV_PIX_FMT_GRAY16BE,   ///<        Y        , 16bpp, big-endian
    AV_PIX_FMT_GRAY16LE,   ///<        Y        , 16bpp, little-endian
    AV_PIX_FMT_YUV440P,    ///< planar YUV 4:4:0 (1 Cr & Cb sample per 1x2 Y samples)
    AV_PIX_FMT_YUVJ440P,   ///< planar YUV 4:4:0 full scale (JPEG), deprecated in favor of AV_PIX_FMT_YUV440P and setting color_range
    AV_PIX_FMT_YUVA420P,   ///< planar YUV 4:2:0, 20bpp, (1 Cr & Cb sample per 2x2 Y & A samples)
    AV_PIX_FMT_RGB48BE,    ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as big-endian
    AV_PIX_FMT_RGB48LE,    ///< packed RGB 16:16:16, 48bpp, 16R, 16G, 16B, the 2-byte value for each R/G/B component is stored as little-endian
    AV_PIX_FMT_RGB565BE,   ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
    AV_PIX_FMT_RGB565LE,   ///< packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
    AV_PIX_FMT_RGB555BE,   ///< packed RGB 5:5:5, 16bpp, (msb)1X 5R 5G 5B(lsb), big-endian   , X=unused/undefined
    AV_PIX_FMT_RGB555LE,   ///< packed RGB 5:5:5, 16bpp, (msb)1X 5R 5G 5B(lsb), little-endian, X=unused/undefined
    AV_PIX_FMT_BGR565BE,   ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
    AV_PIX_FMT_BGR565LE,   ///< packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian
    AV_PIX_FMT_BGR555BE,   ///< packed BGR 5:5:5, 16bpp, (msb)1X 5B 5G 5R(lsb), big-endian   , X=unused/undefined
    AV_PIX_FMT_BGR555LE,   ///< packed BGR 5:5:5, 16bpp, (msb)1X 5B 5G 5R(lsb), little-endian, X=unused/undefined
    AV_PIX_FMT_VAAPI_MOCO, ///< HW acceleration through VA API at motion compensation entry-point, Picture.data[3] contains a vaapi_render_state struct which contains macroblocks as well as various fields extracted from headers
    AV_PIX_FMT_VAAPI_IDCT, ///< HW acceleration through VA API at IDCT entry-point, Picture.data[3] contains a vaapi_render_state struct which contains fields extracted from headers
    AV_PIX_FMT_VAAPI_VLD,  ///< HW decoding through VA API, Picture.data[3] contains a VASurfaceID
    AV_PIX_FMT_VAAPI = AV_PIX_FMT_VAAPI_VLD,
    AV_PIX_FMT_YUV420P16LE,              ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P16BE,              ///< planar YUV 4:2:0, 24bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV422P16LE,              ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P16BE,              ///< planar YUV 4:2:2, 32bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P16LE,              ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P16BE,              ///< planar YUV 4:4:4, 48bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_DXVA2_VLD,                ///< HW decoding through DXVA2, Picture.data[3] contains a LPDIRECT3DSURFACE9 pointer
    AV_PIX_FMT_RGB444LE,                 ///< packed RGB 4:4:4, 16bpp, (msb)4X 4R 4G 4B(lsb), little-endian, X=unused/undefined
    AV_PIX_FMT_RGB444BE,                 ///< packed RGB 4:4:4, 16bpp, (msb)4X 4R 4G 4B(lsb), big-endian,    X=unused/undefined
    AV_PIX_FMT_BGR444LE,                 ///< packed BGR 4:4:4, 16bpp, (msb)4X 4B 4G 4R(lsb), little-endian, X=unused/undefined
    AV_PIX_FMT_BGR444BE,                 ///< packed BGR 4:4:4, 16bpp, (msb)4X 4B 4G 4R(lsb), big-endian,    X=unused/undefined
    AV_PIX_FMT_YA8,                      ///< 8 bits gray, 8 bits alpha
    AV_PIX_FMT_Y400A = AV_PIX_FMT_YA8,   ///< alias for AV_PIX_FMT_YA8
    AV_PIX_FMT_GRAY8A = AV_PIX_FMT_YA8,  ///< alias for AV_PIX_FMT_YA8
    AV_PIX_FMT_BGR48BE,                  ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as big-endian
    AV_PIX_FMT_BGR48LE,                  ///< packed RGB 16:16:16, 48bpp, 16B, 16G, 16R, the 2-byte value for each R/G/B component is stored as little-endian
    AV_PIX_FMT_YUV420P9BE,               ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P9LE,               ///< planar YUV 4:2:0, 13.5bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P10BE,              ///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P10LE,              ///< planar YUV 4:2:0, 15bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV422P10BE,              ///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P10LE,              ///< planar YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P9BE,               ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P9LE,               ///< planar YUV 4:4:4, 27bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P10BE,              ///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P10LE,              ///< planar YUV 4:4:4, 30bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P9BE,               ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P9LE,               ///< planar YUV 4:2:2, 18bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_GBRP,                     ///< planar GBR 4:4:4 24bpp
    AV_PIX_FMT_GBR24P = AV_PIX_FMT_GBRP, // alias for #AV_PIX_FMT_GBRP
    AV_PIX_FMT_GBRP9BE,                  ///< planar GBR 4:4:4 27bpp, big-endian
    AV_PIX_FMT_GBRP9LE,                  ///< planar GBR 4:4:4 27bpp, little-endian
    AV_PIX_FMT_GBRP10BE,                 ///< planar GBR 4:4:4 30bpp, big-endian
    AV_PIX_FMT_GBRP10LE,                 ///< planar GBR 4:4:4 30bpp, little-endian
    AV_PIX_FMT_GBRP16BE,                 ///< planar GBR 4:4:4 48bpp, big-endian
    AV_PIX_FMT_GBRP16LE,                 ///< planar GBR 4:4:4 48bpp, little-endian
    AV_PIX_FMT_YUVA422P,                 ///< planar YUV 4:2:2 24bpp, (1 Cr & Cb sample per 2x1 Y & A samples)
    AV_PIX_FMT_YUVA444P,                 ///< planar YUV 4:4:4 32bpp, (1 Cr & Cb sample per 1x1 Y & A samples)
    AV_PIX_FMT_YUVA420P9BE,              ///< planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), big-endian
    AV_PIX_FMT_YUVA420P9LE,              ///< planar YUV 4:2:0 22.5bpp, (1 Cr & Cb sample per 2x2 Y & A samples), little-endian
    AV_PIX_FMT_YUVA422P9BE,              ///< planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), big-endian
    AV_PIX_FMT_YUVA422P9LE,              ///< planar YUV 4:2:2 27bpp, (1 Cr & Cb sample per 2x1 Y & A samples), little-endian
    AV_PIX_FMT_YUVA444P9BE,              ///< planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), big-endian
    AV_PIX_FMT_YUVA444P9LE,              ///< planar YUV 4:4:4 36bpp, (1 Cr & Cb sample per 1x1 Y & A samples), little-endian
    AV_PIX_FMT_YUVA420P10BE,             ///< planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA420P10LE,             ///< planar YUV 4:2:0 25bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA422P10BE,             ///< planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA422P10LE,             ///< planar YUV 4:2:2 30bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA444P10BE,             ///< planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA444P10LE,             ///< planar YUV 4:4:4 40bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA420P16BE,             ///< planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA420P16LE,             ///< planar YUV 4:2:0 40bpp, (1 Cr & Cb sample per 2x2 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA422P16BE,             ///< planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA422P16LE,             ///< planar YUV 4:2:2 48bpp, (1 Cr & Cb sample per 2x1 Y & A samples, little-endian)
    AV_PIX_FMT_YUVA444P16BE,             ///< planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, big-endian)
    AV_PIX_FMT_YUVA444P16LE,             ///< planar YUV 4:4:4 64bpp, (1 Cr & Cb sample per 1x1 Y & A samples, little-endian)
    AV_PIX_FMT_VDPAU,                    ///< HW acceleration through VDPAU, Picture.data[3] contains a VdpVideoSurface
    AV_PIX_FMT_XYZ12LE,                  ///< packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as little-endian, the 4 lower bits are set to 0
    AV_PIX_FMT_XYZ12BE,                  ///< packed XYZ 4:4:4, 36 bpp, (msb) 12X, 12Y, 12Z (lsb), the 2-byte value for each X/Y/Z is stored as big-endian, the 4 lower bits are set to 0
    AV_PIX_FMT_NV16,                     ///< interleaved chroma YUV 4:2:2, 16bpp, (1 Cr & Cb sample per 2x1 Y samples)
    AV_PIX_FMT_NV20LE,                   ///< interleaved chroma YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_NV20BE,                   ///< interleaved chroma YUV 4:2:2, 20bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_RGBA64BE,                 ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    AV_PIX_FMT_RGBA64LE,                 ///< packed RGBA 16:16:16:16, 64bpp, 16R, 16G, 16B, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian
    AV_PIX_FMT_BGRA64BE,                 ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as big-endian
    AV_PIX_FMT_BGRA64LE,                 ///< packed RGBA 16:16:16:16, 64bpp, 16B, 16G, 16R, 16A, the 2-byte value for each R/G/B/A component is stored as little-endian
    AV_PIX_FMT_YVYU422,                  ///< packed YUV 4:2:2, 16bpp, Y0 Cr Y1 Cb
    AV_PIX_FMT_YA16BE,                   ///< 16 bits gray, 16 bits alpha (big-endian)
    AV_PIX_FMT_YA16LE,                   ///< 16 bits gray, 16 bits alpha (little-endian)
    AV_PIX_FMT_GBRAP,                    ///< planar GBRA 4:4:4:4 32bpp
    AV_PIX_FMT_GBRAP16BE,                ///< planar GBRA 4:4:4:4 64bpp, big-endian
    AV_PIX_FMT_GBRAP16LE,                ///< planar GBRA 4:4:4:4 64bpp, little-endian
    AV_PIX_FMT_QSV,
    AV_PIX_FMT_MMAL,
    AV_PIX_FMT_D3D11VA_VLD, ///< HW decoding through Direct3D11 via old API, Picture.data[3] contains a ID3D11VideoDecoderOutputView pointer
    AV_PIX_FMT_CUDA,
    AV_PIX_FMT_0RGB,           ///< packed RGB 8:8:8, 32bpp, XRGBXRGB...   X=unused/undefined
    AV_PIX_FMT_RGB0,           ///< packed RGB 8:8:8, 32bpp, RGBXRGBX...   X=unused/undefined
    AV_PIX_FMT_0BGR,           ///< packed BGR 8:8:8, 32bpp, XBGRXBGR...   X=unused/undefined
    AV_PIX_FMT_BGR0,           ///< packed BGR 8:8:8, 32bpp, BGRXBGRX...   X=unused/undefined
    AV_PIX_FMT_YUV420P12BE,    ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P12LE,    ///< planar YUV 4:2:0,18bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV420P14BE,    ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), big-endian
    AV_PIX_FMT_YUV420P14LE,    ///< planar YUV 4:2:0,21bpp, (1 Cr & Cb sample per 2x2 Y samples), little-endian
    AV_PIX_FMT_YUV422P12BE,    ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P12LE,    ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV422P14BE,    ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), big-endian
    AV_PIX_FMT_YUV422P14LE,    ///< planar YUV 4:2:2,28bpp, (1 Cr & Cb sample per 2x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P12BE,    ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P12LE,    ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_YUV444P14BE,    ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), big-endian
    AV_PIX_FMT_YUV444P14LE,    ///< planar YUV 4:4:4,42bpp, (1 Cr & Cb sample per 1x1 Y samples), little-endian
    AV_PIX_FMT_GBRP12BE,       ///< planar GBR 4:4:4 36bpp, big-endian
    AV_PIX_FMT_GBRP12LE,       ///< planar GBR 4:4:4 36bpp, little-endian
    AV_PIX_FMT_GBRP14BE,       ///< planar GBR 4:4:4 42bpp, big-endian
    AV_PIX_FMT_GBRP14LE,       ///< planar GBR 4:4:4 42bpp, little-endian
    AV_PIX_FMT_YUVJ411P,       ///< planar YUV 4:1:1, 12bpp, (1 Cr & Cb sample per 4x1 Y samples) full scale (JPEG), deprecated in favor of AV_PIX_FMT_YUV411P and setting color_range
    AV_PIX_FMT_BAYER_BGGR8,    ///< bayer, BGBG..(odd line), GRGR..(even line), 8-bit samples
    AV_PIX_FMT_BAYER_RGGB8,    ///< bayer, RGRG..(odd line), GBGB..(even line), 8-bit samples
    AV_PIX_FMT_BAYER_GBRG8,    ///< bayer, GBGB..(odd line), RGRG..(even line), 8-bit samples
    AV_PIX_FMT_BAYER_GRBG8,    ///< bayer, GRGR..(odd line), BGBG..(even line), 8-bit samples
    AV_PIX_FMT_BAYER_BGGR16LE, ///< bayer, BGBG..(odd line), GRGR..(even line), 16-bit samples, little-endian
    AV_PIX_FMT_BAYER_BGGR16BE, ///< bayer, BGBG..(odd line), GRGR..(even line), 16-bit samples, big-endian
    AV_PIX_FMT_BAYER_RGGB16LE, ///< bayer, RGRG..(odd line), GBGB..(even line), 16-bit samples, little-endian
    AV_PIX_FMT_BAYER_RGGB16BE, ///< bayer, RGRG..(odd line), GBGB..(even line), 16-bit samples, big-endian
    AV_PIX_FMT_BAYER_GBRG16LE, ///< bayer, GBGB..(odd line), RGRG..(even line), 16-bit samples, little-endian
    AV_PIX_FMT_BAYER_GBRG16BE, ///< bayer, GBGB..(odd line), RGRG..(even line), 16-bit samples, big-endian
    AV_PIX_FMT_BAYER_GRBG16LE, ///< bayer, GRGR..(odd line), BGBG..(even line), 16-bit samples, little-endian
    AV_PIX_FMT_BAYER_GRBG16BE, ///< bayer, GRGR..(odd line), BGBG..(even line), 16-bit samples, big-endian
    AV_PIX_FMT_XVMC,           ///< XVideo Motion Acceleration via common packet passing
    AV_PIX_FMT_YUV440P10LE,    ///< planar YUV 4:4:0,20bpp, (1 Cr & Cb sample per 1x2 Y samples), little-endian
    AV_PIX_FMT_YUV440P10BE,    ///< planar YUV 4:4:0,20bpp, (1 Cr & Cb sample per 1x2 Y samples), big-endian
    AV_PIX_FMT_YUV440P12LE,    ///< planar YUV 4:4:0,24bpp, (1 Cr & Cb sample per 1x2 Y samples), little-endian
    AV_PIX_FMT_YUV440P12BE,    ///< planar YUV 4:4:0,24bpp, (1 Cr & Cb sample per 1x2 Y samples), big-endian
    AV_PIX_FMT_AYUV64LE,       ///< packed AYUV 4:4:4,64bpp (1 Cr & Cb sample per 1x1 Y & A samples), little-endian
    AV_PIX_FMT_AYUV64BE,       ///< packed AYUV 4:4:4,64bpp (1 Cr & Cb sample per 1x1 Y & A samples), big-endian
    AV_PIX_FMT_VIDEOTOOLBOX,   ///< hardware decoding through Videotoolbox
    AV_PIX_FMT_P010LE,         ///< like NV12, with 10bpp per component, data in the high bits, zeros in the low bits, little-endian
    AV_PIX_FMT_P010BE,         ///< like NV12, with 10bpp per component, data in the high bits, zeros in the low bits, big-endian
    AV_PIX_FMT_GBRAP12BE,      ///< planar GBR 4:4:4:4 48bpp, big-endian
    AV_PIX_FMT_GBRAP12LE,      ///< planar GBR 4:4:4:4 48bpp, little-endian
    AV_PIX_FMT_GBRAP10BE,      ///< planar GBR 4:4:4:4 40bpp, big-endian
    AV_PIX_FMT_GBRAP10LE,      ///< planar GBR 4:4:4:4 40bpp, little-endian
    AV_PIX_FMT_MEDIACODEC,     ///< hardware decoding through MediaCodec
    AV_PIX_FMT_GRAY12BE,       ///<        Y        , 12bpp, big-endian
    AV_PIX_FMT_GRAY12LE,       ///<        Y        , 12bpp, little-endian
    AV_PIX_FMT_GRAY10BE,       ///<        Y        , 10bpp, big-endian
    AV_PIX_FMT_GRAY10LE,       ///<        Y        , 10bpp, little-endian
    AV_PIX_FMT_P016LE,         ///< like NV12, with 16bpp per component, little-endian
    AV_PIX_FMT_P016BE,         ///< like NV12, with 16bpp per component, big-endian
    AV_PIX_FMT_D3D11,
    AV_PIX_FMT_GRAY9BE,    ///<        Y        , 9bpp, big-endian
    AV_PIX_FMT_GRAY9LE,    ///<        Y        , 9bpp, little-endian
    AV_PIX_FMT_GBRPF32BE,  ///< IEEE-754 single precision planar GBR 4:4:4,     96bpp, big-endian
    AV_PIX_FMT_GBRPF32LE,  ///< IEEE-754 single precision planar GBR 4:4:4,     96bpp, little-endian
    AV_PIX_FMT_GBRAPF32BE, ///< IEEE-754 single precision planar GBRA 4:4:4:4, 128bpp, big-endian
    AV_PIX_FMT_GBRAPF32LE, ///< IEEE-754 single precision planar GBRA 4:4:4:4, 128bpp, little-endian
    AV_PIX_FMT_DRM_PRIME,
    AV_PIX_FMT_OPENCL,
    AV_PIX_FMT_GRAY14BE,     ///<        Y        , 14bpp, big-endian
    AV_PIX_FMT_GRAY14LE,     ///<        Y        , 14bpp, little-endian
    AV_PIX_FMT_GRAYF32BE,    ///< IEEE-754 single precision Y, 32bpp, big-endian
    AV_PIX_FMT_GRAYF32LE,    ///< IEEE-754 single precision Y, 32bpp, little-endian
    AV_PIX_FMT_YUVA422P12BE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), 12b alpha, big-endian
    AV_PIX_FMT_YUVA422P12LE, ///< planar YUV 4:2:2,24bpp, (1 Cr & Cb sample per 2x1 Y samples), 12b alpha, little-endian
    AV_PIX_FMT_YUVA444P12BE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), 12b alpha, big-endian
    AV_PIX_FMT_YUVA444P12LE, ///< planar YUV 4:4:4,36bpp, (1 Cr & Cb sample per 1x1 Y samples), 12b alpha, little-endian
    AV_PIX_FMT_NV24,         ///< planar YUV 4:4:4, 24bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved (first byte U and the following byte V)
    AV_PIX_FMT_NV42,         ///< as above, but U and V bytes are swapped
    AV_PIX_FMT_VULKAN,
    AV_PIX_FMT_Y210BE,    ///< packed YUV 4:2:2 like YUYV422, 20bpp, data in the high bits, big-endian
    AV_PIX_FMT_Y210LE,    ///< packed YUV 4:2:2 like YUYV422, 20bpp, data in the high bits, little-endian
    AV_PIX_FMT_X2RGB10LE, ///< packed RGB 10:10:10, 30bpp, (msb)2X 10R 10G 10B(lsb), little-endian, X=unused/undefined
    AV_PIX_FMT_X2RGB10BE, ///< packed RGB 10:10:10, 30bpp, (msb)2X 10R 10G 10B(lsb), big-endian, X=unused/undefined
    AV_PIX_FMT_NB         ///< number of pixel formats, DO NOT USE THIS if you want to link with shared libav* because the number of formats might differ between versions
};
enum AVEscapeMode
{
    AV_ESCAPE_MODE_AUTO,      ///< Use auto-selected escaping mode.
    AV_ESCAPE_MODE_BACKSLASH, ///< Use backslash escaping.
    AV_ESCAPE_MODE_QUOTE,     ///< Use single-quote escaping.
};
enum AVMediaType
{
    AVMEDIA_TYPE_UNKNOWN = -1, ///< Usually treated as AVMEDIA_TYPE_DATA
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO,
    AVMEDIA_TYPE_DATA, ///< Opaque data information usually continuous
    AVMEDIA_TYPE_SUBTITLE,
    AVMEDIA_TYPE_ATTACHMENT, ///< Opaque data information usually sparse
    AVMEDIA_TYPE_NB
};
enum AVPictureType
{
    AV_PICTURE_TYPE_NONE = 0, ///< Undefined
    AV_PICTURE_TYPE_I,        ///< Intra
    AV_PICTURE_TYPE_P,        ///< Predicted
    AV_PICTURE_TYPE_B,        ///< Bi-dir predicted
    AV_PICTURE_TYPE_S,        ///< S(GMC)-VOP MPEG-4
    AV_PICTURE_TYPE_SI,       ///< Switching Intra
    AV_PICTURE_TYPE_SP,       ///< Switching Predicted
    AV_PICTURE_TYPE_BI,       ///< BI type
};

enum AVRounding
{
    AV_ROUND_ZERO = 0,     ///< Round toward zero.
    AV_ROUND_INF = 1,      ///< Round away from zero.
    AV_ROUND_DOWN = 2,     ///< Round toward -infinity.
    AV_ROUND_UP = 3,       ///< Round toward +infinity.
    AV_ROUND_NEAR_INF = 5, ///< Round to nearest and halfway cases away from zero.
    AV_ROUND_PASS_MINMAX = 8192,
};
typedef enum
{
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT,
    AV_CLASS_CATEGORY_NB ///< not part of ABI/API
} AVClassCategory;

enum AVFrameSideDataType
{
    AV_FRAME_DATA_PANSCAN,
    AV_FRAME_DATA_A53_CC,
    AV_FRAME_DATA_STEREO3D,
    AV_FRAME_DATA_MATRIXENCODING,
    AV_FRAME_DATA_DOWNMIX_INFO,
    AV_FRAME_DATA_REPLAYGAIN,
    AV_FRAME_DATA_DISPLAYMATRIX,
    AV_FRAME_DATA_AFD,
    AV_FRAME_DATA_MOTION_VECTORS,
    AV_FRAME_DATA_SKIP_SAMPLES,
    AV_FRAME_DATA_AUDIO_SERVICE_TYPE,
    AV_FRAME_DATA_MASTERING_DISPLAY_METADATA,
    AV_FRAME_DATA_GOP_TIMECODE,
    AV_FRAME_DATA_SPHERICAL,
    AV_FRAME_DATA_CONTENT_LIGHT_LEVEL,
    AV_FRAME_DATA_ICC_PROFILE,
    AV_FRAME_DATA_QP_TABLE_PROPERTIES,
    AV_FRAME_DATA_QP_TABLE_DATA,
    AV_FRAME_DATA_S12M_TIMECODE,
    AV_FRAME_DATA_DYNAMIC_HDR_PLUS,
    AV_FRAME_DATA_REGIONS_OF_INTEREST,
    AV_FRAME_DATA_VIDEO_ENC_PARAMS,
    AV_FRAME_DATA_SEI_UNREGISTERED,
};

enum AVActiveFormatDescription
{
    AV_AFD_SAME = 8,
    AV_AFD_4_3 = 9,
    AV_AFD_16_9 = 10,
    AV_AFD_14_9 = 11,
    AV_AFD_4_3_SP_14_9 = 13,
    AV_AFD_16_9_SP_14_9 = 14,
    AV_AFD_SP_4_3 = 15,
};
enum AVSampleFormat
{
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,   ///< unsigned 8 bits
    AV_SAMPLE_FMT_S16,  ///< signed 16 bits
    AV_SAMPLE_FMT_S32,  ///< signed 32 bits
    AV_SAMPLE_FMT_FLT,  ///< float
    AV_SAMPLE_FMT_DBL,  ///< double
    AV_SAMPLE_FMT_U8P,  ///< unsigned 8 bits, planar
    AV_SAMPLE_FMT_S16P, ///< signed 16 bits, planar
    AV_SAMPLE_FMT_S32P, ///< signed 32 bits, planar
    AV_SAMPLE_FMT_FLTP, ///< float, planar
    AV_SAMPLE_FMT_DBLP, ///< double, planar
    AV_SAMPLE_FMT_S64,  ///< signed 64 bits
    AV_SAMPLE_FMT_S64P, ///< signed 64 bits, planar
    AV_SAMPLE_FMT_NB    ///< Number of sample formats. DO NOT USE if linking dynamically
};

enum AVCodecID
{
    AV_CODEC_ID_NONE,
    AV_CODEC_ID_MPEG1VIDEO,
    AV_CODEC_ID_MPEG2VIDEO, ///< preferred ID for MPEG-1/2 video decoding
    AV_CODEC_ID_H261,
    AV_CODEC_ID_H263,
    AV_CODEC_ID_RV10,
    AV_CODEC_ID_RV20,
    AV_CODEC_ID_MJPEG,
    AV_CODEC_ID_MJPEGB,
    AV_CODEC_ID_LJPEG,
    AV_CODEC_ID_SP5X,
    AV_CODEC_ID_JPEGLS,
    AV_CODEC_ID_MPEG4,
    AV_CODEC_ID_RAWVIDEO,
    AV_CODEC_ID_MSMPEG4V1,
    AV_CODEC_ID_MSMPEG4V2,
    AV_CODEC_ID_MSMPEG4V3,
    AV_CODEC_ID_WMV1,
    AV_CODEC_ID_WMV2,
    AV_CODEC_ID_H263P,
    AV_CODEC_ID_H263I,
    AV_CODEC_ID_FLV1,
    AV_CODEC_ID_SVQ1,
    AV_CODEC_ID_SVQ3,
    AV_CODEC_ID_DVVIDEO,
    AV_CODEC_ID_HUFFYUV,
    AV_CODEC_ID_CYUV,
    AV_CODEC_ID_H264,
    AV_CODEC_ID_INDEO3,
    AV_CODEC_ID_VP3,
    AV_CODEC_ID_THEORA,
    AV_CODEC_ID_ASV1,
    AV_CODEC_ID_ASV2,
    AV_CODEC_ID_FFV1,
    AV_CODEC_ID_4XM,
    AV_CODEC_ID_VCR1,
    AV_CODEC_ID_CLJR,
    AV_CODEC_ID_MDEC,
    AV_CODEC_ID_ROQ,
    AV_CODEC_ID_INTERPLAY_VIDEO,
    AV_CODEC_ID_XAN_WC3,
    AV_CODEC_ID_XAN_WC4,
    AV_CODEC_ID_RPZA,
    AV_CODEC_ID_CINEPAK,
    AV_CODEC_ID_WS_VQA,
    AV_CODEC_ID_MSRLE,
    AV_CODEC_ID_MSVIDEO1,
    AV_CODEC_ID_IDCIN,
    AV_CODEC_ID_8BPS,
    AV_CODEC_ID_SMC,
    AV_CODEC_ID_FLIC,
    AV_CODEC_ID_TRUEMOTION1,
    AV_CODEC_ID_VMDVIDEO,
    AV_CODEC_ID_MSZH,
    AV_CODEC_ID_ZLIB,
    AV_CODEC_ID_QTRLE,
    AV_CODEC_ID_TSCC,
    AV_CODEC_ID_ULTI,
    AV_CODEC_ID_QDRAW,
    AV_CODEC_ID_VIXL,
    AV_CODEC_ID_QPEG,
    AV_CODEC_ID_PNG,
    AV_CODEC_ID_PPM,
    AV_CODEC_ID_PBM,
    AV_CODEC_ID_PGM,
    AV_CODEC_ID_PGMYUV,
    AV_CODEC_ID_PAM,
    AV_CODEC_ID_FFVHUFF,
    AV_CODEC_ID_RV30,
    AV_CODEC_ID_RV40,
    AV_CODEC_ID_VC1,
    AV_CODEC_ID_WMV3,
    AV_CODEC_ID_LOCO,
    AV_CODEC_ID_WNV1,
    AV_CODEC_ID_AASC,
    AV_CODEC_ID_INDEO2,
    AV_CODEC_ID_FRAPS,
    AV_CODEC_ID_TRUEMOTION2,
    AV_CODEC_ID_BMP,
    AV_CODEC_ID_CSCD,
    AV_CODEC_ID_MMVIDEO,
    AV_CODEC_ID_ZMBV,
    AV_CODEC_ID_AVS,
    AV_CODEC_ID_SMACKVIDEO,
    AV_CODEC_ID_NUV,
    AV_CODEC_ID_KMVC,
    AV_CODEC_ID_FLASHSV,
    AV_CODEC_ID_CAVS,
    AV_CODEC_ID_JPEG2000,
    AV_CODEC_ID_VMNC,
    AV_CODEC_ID_VP5,
    AV_CODEC_ID_VP6,
    AV_CODEC_ID_VP6F,
    AV_CODEC_ID_TARGA,
    AV_CODEC_ID_DSICINVIDEO,
    AV_CODEC_ID_TIERTEXSEQVIDEO,
    AV_CODEC_ID_TIFF,
    AV_CODEC_ID_GIF,
    AV_CODEC_ID_DXA,
    AV_CODEC_ID_DNXHD,
    AV_CODEC_ID_THP,
    AV_CODEC_ID_SGI,
    AV_CODEC_ID_C93,
    AV_CODEC_ID_BETHSOFTVID,
    AV_CODEC_ID_PTX,
    AV_CODEC_ID_TXD,
    AV_CODEC_ID_VP6A,
    AV_CODEC_ID_AMV,
    AV_CODEC_ID_VB,
    AV_CODEC_ID_PCX,
    AV_CODEC_ID_SUNRAST,
    AV_CODEC_ID_INDEO4,
    AV_CODEC_ID_INDEO5,
    AV_CODEC_ID_MIMIC,
    AV_CODEC_ID_RL2,
    AV_CODEC_ID_ESCAPE124,
    AV_CODEC_ID_DIRAC,
    AV_CODEC_ID_BFI,
    AV_CODEC_ID_CMV,
    AV_CODEC_ID_MOTIONPIXELS,
    AV_CODEC_ID_TGV,
    AV_CODEC_ID_TGQ,
    AV_CODEC_ID_TQI,
    AV_CODEC_ID_AURA,
    AV_CODEC_ID_AURA2,
    AV_CODEC_ID_V210X,
    AV_CODEC_ID_TMV,
    AV_CODEC_ID_V210,
    AV_CODEC_ID_DPX,
    AV_CODEC_ID_MAD,
    AV_CODEC_ID_FRWU,
    AV_CODEC_ID_FLASHSV2,
    AV_CODEC_ID_CDGRAPHICS,
    AV_CODEC_ID_R210,
    AV_CODEC_ID_ANM,
    AV_CODEC_ID_BINKVIDEO,
    AV_CODEC_ID_IFF_ILBM,
    AV_CODEC_ID_KGV1,
    AV_CODEC_ID_YOP,
    AV_CODEC_ID_VP8,
    AV_CODEC_ID_PICTOR,
    AV_CODEC_ID_ANSI,
    AV_CODEC_ID_A64_MULTI,
    AV_CODEC_ID_A64_MULTI5,
    AV_CODEC_ID_R10K,
    AV_CODEC_ID_MXPEG,
    AV_CODEC_ID_LAGARITH,
    AV_CODEC_ID_PRORES,
    AV_CODEC_ID_JV,
    AV_CODEC_ID_DFA,
    AV_CODEC_ID_WMV3IMAGE,
    AV_CODEC_ID_VC1IMAGE,
    AV_CODEC_ID_UTVIDEO,
    AV_CODEC_ID_BMV_VIDEO,
    AV_CODEC_ID_VBLE,
    AV_CODEC_ID_DXTORY,
    AV_CODEC_ID_V410,
    AV_CODEC_ID_XWD,
    AV_CODEC_ID_CDXL,
    AV_CODEC_ID_XBM,
    AV_CODEC_ID_ZEROCODEC,
    AV_CODEC_ID_MSS1,
    AV_CODEC_ID_MSA1,
    AV_CODEC_ID_TSCC2,
    AV_CODEC_ID_MTS2,
    AV_CODEC_ID_CLLC,
    AV_CODEC_ID_MSS2,
    AV_CODEC_ID_VP9,
    AV_CODEC_ID_AIC,
    AV_CODEC_ID_ESCAPE130,
    AV_CODEC_ID_G2M,
    AV_CODEC_ID_WEBP,
    AV_CODEC_ID_HNM4_VIDEO,
    AV_CODEC_ID_HEVC,
    AV_CODEC_ID_FIC,
    AV_CODEC_ID_ALIAS_PIX,
    AV_CODEC_ID_BRENDER_PIX,
    AV_CODEC_ID_PAF_VIDEO,
    AV_CODEC_ID_EXR,
    AV_CODEC_ID_VP7,
    AV_CODEC_ID_SANM,
    AV_CODEC_ID_SGIRLE,
    AV_CODEC_ID_MVC1,
    AV_CODEC_ID_MVC2,
    AV_CODEC_ID_HQX,
    AV_CODEC_ID_TDSC,
    AV_CODEC_ID_HQ_HQA,
    AV_CODEC_ID_HAP,
    AV_CODEC_ID_DDS,
    AV_CODEC_ID_DXV,
    AV_CODEC_ID_SCREENPRESSO,
    AV_CODEC_ID_RSCC,
    AV_CODEC_ID_AVS2,
    AV_CODEC_ID_PGX,
    AV_CODEC_ID_AVS3,
    AV_CODEC_ID_Y41P = 0x8000,
    AV_CODEC_ID_AVRP,
    AV_CODEC_ID_012V,
    AV_CODEC_ID_AVUI,
    AV_CODEC_ID_AYUV,
    AV_CODEC_ID_TARGA_Y216,
    AV_CODEC_ID_V308,
    AV_CODEC_ID_V408,
    AV_CODEC_ID_YUV4,
    AV_CODEC_ID_AVRN,
    AV_CODEC_ID_CPIA,
    AV_CODEC_ID_XFACE,
    AV_CODEC_ID_SNOW,
    AV_CODEC_ID_SMVJPEG,
    AV_CODEC_ID_APNG,
    AV_CODEC_ID_DAALA,
    AV_CODEC_ID_CFHD,
    AV_CODEC_ID_TRUEMOTION2RT,
    AV_CODEC_ID_M101,
    AV_CODEC_ID_MAGICYUV,
    AV_CODEC_ID_SHEERVIDEO,
    AV_CODEC_ID_YLC,
    AV_CODEC_ID_PSD,
    AV_CODEC_ID_PIXLET,
    AV_CODEC_ID_SPEEDHQ,
    AV_CODEC_ID_FMVC,
    AV_CODEC_ID_SCPR,
    AV_CODEC_ID_CLEARVIDEO,
    AV_CODEC_ID_XPM,
    AV_CODEC_ID_AV1,
    AV_CODEC_ID_BITPACKED,
    AV_CODEC_ID_MSCC,
    AV_CODEC_ID_SRGC,
    AV_CODEC_ID_SVG,
    AV_CODEC_ID_GDV,
    AV_CODEC_ID_FITS,
    AV_CODEC_ID_IMM4,
    AV_CODEC_ID_PROSUMER,
    AV_CODEC_ID_MWSC,
    AV_CODEC_ID_WCMV,
    AV_CODEC_ID_RASC,
    AV_CODEC_ID_HYMT,
    AV_CODEC_ID_ARBC,
    AV_CODEC_ID_AGM,
    AV_CODEC_ID_LSCR,
    AV_CODEC_ID_VP4,
    AV_CODEC_ID_IMM5,
    AV_CODEC_ID_MVDV,
    AV_CODEC_ID_MVHA,
    AV_CODEC_ID_CDTOONS,
    AV_CODEC_ID_MV30,
    AV_CODEC_ID_NOTCHLC,
    AV_CODEC_ID_PFM,
    AV_CODEC_ID_MOBICLIP,
    AV_CODEC_ID_PHOTOCD,
    AV_CODEC_ID_IPU,
    AV_CODEC_ID_ARGO,
    AV_CODEC_ID_CRI,
    AV_CODEC_ID_FIRST_AUDIO = 0x10000, ///< A dummy id pointing at the start of audio codecs
    AV_CODEC_ID_PCM_S16LE = 0x10000,
    AV_CODEC_ID_PCM_S16BE,
    AV_CODEC_ID_PCM_U16LE,
    AV_CODEC_ID_PCM_U16BE,
    AV_CODEC_ID_PCM_S8,
    AV_CODEC_ID_PCM_U8,
    AV_CODEC_ID_PCM_MULAW,
    AV_CODEC_ID_PCM_ALAW,
    AV_CODEC_ID_PCM_S32LE,
    AV_CODEC_ID_PCM_S32BE,
    AV_CODEC_ID_PCM_U32LE,
    AV_CODEC_ID_PCM_U32BE,
    AV_CODEC_ID_PCM_S24LE,
    AV_CODEC_ID_PCM_S24BE,
    AV_CODEC_ID_PCM_U24LE,
    AV_CODEC_ID_PCM_U24BE,
    AV_CODEC_ID_PCM_S24DAUD,
    AV_CODEC_ID_PCM_ZORK,
    AV_CODEC_ID_PCM_S16LE_PLANAR,
    AV_CODEC_ID_PCM_DVD,
    AV_CODEC_ID_PCM_F32BE,
    AV_CODEC_ID_PCM_F32LE,
    AV_CODEC_ID_PCM_F64BE,
    AV_CODEC_ID_PCM_F64LE,
    AV_CODEC_ID_PCM_BLURAY,
    AV_CODEC_ID_PCM_LXF,
    AV_CODEC_ID_S302M,
    AV_CODEC_ID_PCM_S8_PLANAR,
    AV_CODEC_ID_PCM_S24LE_PLANAR,
    AV_CODEC_ID_PCM_S32LE_PLANAR,
    AV_CODEC_ID_PCM_S16BE_PLANAR,
    AV_CODEC_ID_PCM_S64LE = 0x10800,
    AV_CODEC_ID_PCM_S64BE,
    AV_CODEC_ID_PCM_F16LE,
    AV_CODEC_ID_PCM_F24LE,
    AV_CODEC_ID_PCM_VIDC,
    AV_CODEC_ID_ADPCM_IMA_QT = 0x11000,
    AV_CODEC_ID_ADPCM_IMA_WAV,
    AV_CODEC_ID_ADPCM_IMA_DK3,
    AV_CODEC_ID_ADPCM_IMA_DK4,
    AV_CODEC_ID_ADPCM_IMA_WS,
    AV_CODEC_ID_ADPCM_IMA_SMJPEG,
    AV_CODEC_ID_ADPCM_MS,
    AV_CODEC_ID_ADPCM_4XM,
    AV_CODEC_ID_ADPCM_XA,
    AV_CODEC_ID_ADPCM_ADX,
    AV_CODEC_ID_ADPCM_EA,
    AV_CODEC_ID_ADPCM_G726,
    AV_CODEC_ID_ADPCM_CT,
    AV_CODEC_ID_ADPCM_SWF,
    AV_CODEC_ID_ADPCM_YAMAHA,
    AV_CODEC_ID_ADPCM_SBPRO_4,
    AV_CODEC_ID_ADPCM_SBPRO_3,
    AV_CODEC_ID_ADPCM_SBPRO_2,
    AV_CODEC_ID_ADPCM_THP,
    AV_CODEC_ID_ADPCM_IMA_AMV,
    AV_CODEC_ID_ADPCM_EA_R1,
    AV_CODEC_ID_ADPCM_EA_R3,
    AV_CODEC_ID_ADPCM_EA_R2,
    AV_CODEC_ID_ADPCM_IMA_EA_SEAD,
    AV_CODEC_ID_ADPCM_IMA_EA_EACS,
    AV_CODEC_ID_ADPCM_EA_XAS,
    AV_CODEC_ID_ADPCM_EA_MAXIS_XA,
    AV_CODEC_ID_ADPCM_IMA_ISS,
    AV_CODEC_ID_ADPCM_G722,
    AV_CODEC_ID_ADPCM_IMA_APC,
    AV_CODEC_ID_ADPCM_VIMA,
    AV_CODEC_ID_ADPCM_AFC = 0x11800,
    AV_CODEC_ID_ADPCM_IMA_OKI,
    AV_CODEC_ID_ADPCM_DTK,
    AV_CODEC_ID_ADPCM_IMA_RAD,
    AV_CODEC_ID_ADPCM_G726LE,
    AV_CODEC_ID_ADPCM_THP_LE,
    AV_CODEC_ID_ADPCM_PSX,
    AV_CODEC_ID_ADPCM_AICA,
    AV_CODEC_ID_ADPCM_IMA_DAT4,
    AV_CODEC_ID_ADPCM_MTAF,
    AV_CODEC_ID_ADPCM_AGM,
    AV_CODEC_ID_ADPCM_ARGO,
    AV_CODEC_ID_ADPCM_IMA_SSI,
    AV_CODEC_ID_ADPCM_ZORK,
    AV_CODEC_ID_ADPCM_IMA_APM,
    AV_CODEC_ID_ADPCM_IMA_ALP,
    AV_CODEC_ID_ADPCM_IMA_MTF,
    AV_CODEC_ID_ADPCM_IMA_CUNNING,
    AV_CODEC_ID_ADPCM_IMA_MOFLEX,
    AV_CODEC_ID_AMR_NB = 0x12000,
    AV_CODEC_ID_AMR_WB,
    AV_CODEC_ID_RA_144 = 0x13000,
    AV_CODEC_ID_RA_288,
    AV_CODEC_ID_ROQ_DPCM = 0x14000,
    AV_CODEC_ID_INTERPLAY_DPCM,
    AV_CODEC_ID_XAN_DPCM,
    AV_CODEC_ID_SOL_DPCM,
    AV_CODEC_ID_SDX2_DPCM = 0x14800,
    AV_CODEC_ID_GREMLIN_DPCM,
    AV_CODEC_ID_DERF_DPCM,
    AV_CODEC_ID_MP2 = 0x15000,
    AV_CODEC_ID_MP3, ///< preferred ID for decoding MPEG audio layer 1, 2 or 3
    AV_CODEC_ID_AAC,
    AV_CODEC_ID_AC3,
    AV_CODEC_ID_DTS,
    AV_CODEC_ID_VORBIS,
    AV_CODEC_ID_DVAUDIO,
    AV_CODEC_ID_WMAV1,
    AV_CODEC_ID_WMAV2,
    AV_CODEC_ID_MACE3,
    AV_CODEC_ID_MACE6,
    AV_CODEC_ID_VMDAUDIO,
    AV_CODEC_ID_FLAC,
    AV_CODEC_ID_MP3ADU,
    AV_CODEC_ID_MP3ON4,
    AV_CODEC_ID_SHORTEN,
    AV_CODEC_ID_ALAC,
    AV_CODEC_ID_WESTWOOD_SND1,
    AV_CODEC_ID_GSM, ///< as in Berlin toast format
    AV_CODEC_ID_QDM2,
    AV_CODEC_ID_COOK,
    AV_CODEC_ID_TRUESPEECH,
    AV_CODEC_ID_TTA,
    AV_CODEC_ID_SMACKAUDIO,
    AV_CODEC_ID_QCELP,
    AV_CODEC_ID_WAVPACK,
    AV_CODEC_ID_DSICINAUDIO,
    AV_CODEC_ID_IMC,
    AV_CODEC_ID_MUSEPACK7,
    AV_CODEC_ID_MLP,
    AV_CODEC_ID_GSM_MS,
    AV_CODEC_ID_ATRAC3,
    AV_CODEC_ID_APE,
    AV_CODEC_ID_NELLYMOSER,
    AV_CODEC_ID_MUSEPACK8,
    AV_CODEC_ID_SPEEX,
    AV_CODEC_ID_WMAVOICE,
    AV_CODEC_ID_WMAPRO,
    AV_CODEC_ID_WMALOSSLESS,
    AV_CODEC_ID_ATRAC3P,
    AV_CODEC_ID_EAC3,
    AV_CODEC_ID_SIPR,
    AV_CODEC_ID_MP1,
    AV_CODEC_ID_TWINVQ,
    AV_CODEC_ID_TRUEHD,
    AV_CODEC_ID_MP4ALS,
    AV_CODEC_ID_ATRAC1,
    AV_CODEC_ID_BINKAUDIO_RDFT,
    AV_CODEC_ID_BINKAUDIO_DCT,
    AV_CODEC_ID_AAC_LATM,
    AV_CODEC_ID_QDMC,
    AV_CODEC_ID_CELT,
    AV_CODEC_ID_G723_1,
    AV_CODEC_ID_G729,
    AV_CODEC_ID_8SVX_EXP,
    AV_CODEC_ID_8SVX_FIB,
    AV_CODEC_ID_BMV_AUDIO,
    AV_CODEC_ID_RALF,
    AV_CODEC_ID_IAC,
    AV_CODEC_ID_ILBC,
    AV_CODEC_ID_OPUS,
    AV_CODEC_ID_COMFORT_NOISE,
    AV_CODEC_ID_TAK,
    AV_CODEC_ID_METASOUND,
    AV_CODEC_ID_PAF_AUDIO,
    AV_CODEC_ID_ON2AVC,
    AV_CODEC_ID_DSS_SP,
    AV_CODEC_ID_CODEC2,
    AV_CODEC_ID_FFWAVESYNTH = 0x15800,
    AV_CODEC_ID_SONIC,
    AV_CODEC_ID_SONIC_LS,
    AV_CODEC_ID_EVRC,
    AV_CODEC_ID_SMV,
    AV_CODEC_ID_DSD_LSBF,
    AV_CODEC_ID_DSD_MSBF,
    AV_CODEC_ID_DSD_LSBF_PLANAR,
    AV_CODEC_ID_DSD_MSBF_PLANAR,
    AV_CODEC_ID_4GV,
    AV_CODEC_ID_INTERPLAY_ACM,
    AV_CODEC_ID_XMA1,
    AV_CODEC_ID_XMA2,
    AV_CODEC_ID_DST,
    AV_CODEC_ID_ATRAC3AL,
    AV_CODEC_ID_ATRAC3PAL,
    AV_CODEC_ID_DOLBY_E,
    AV_CODEC_ID_APTX,
    AV_CODEC_ID_APTX_HD,
    AV_CODEC_ID_SBC,
    AV_CODEC_ID_ATRAC9,
    AV_CODEC_ID_HCOM,
    AV_CODEC_ID_ACELP_KELVIN,
    AV_CODEC_ID_MPEGH_3D_AUDIO,
    AV_CODEC_ID_SIREN,
    AV_CODEC_ID_HCA,
    AV_CODEC_ID_FASTAUDIO,
    AV_CODEC_ID_FIRST_SUBTITLE = 0x17000, ///< A dummy ID pointing at the start of subtitle codecs.
    AV_CODEC_ID_DVD_SUBTITLE = 0x17000,
    AV_CODEC_ID_DVB_SUBTITLE,
    AV_CODEC_ID_TEXT, ///< raw UTF-8 text
    AV_CODEC_ID_XSUB,
    AV_CODEC_ID_SSA,
    AV_CODEC_ID_MOV_TEXT,
    AV_CODEC_ID_HDMV_PGS_SUBTITLE,
    AV_CODEC_ID_DVB_TELETEXT,
    AV_CODEC_ID_SRT,
    AV_CODEC_ID_MICRODVD = 0x17800,
    AV_CODEC_ID_EIA_608,
    AV_CODEC_ID_JACOSUB,
    AV_CODEC_ID_SAMI,
    AV_CODEC_ID_REALTEXT,
    AV_CODEC_ID_STL,
    AV_CODEC_ID_SUBVIEWER1,
    AV_CODEC_ID_SUBVIEWER,
    AV_CODEC_ID_SUBRIP,
    AV_CODEC_ID_WEBVTT,
    AV_CODEC_ID_MPL2,
    AV_CODEC_ID_VPLAYER,
    AV_CODEC_ID_PJS,
    AV_CODEC_ID_ASS,
    AV_CODEC_ID_HDMV_TEXT_SUBTITLE,
    AV_CODEC_ID_TTML,
    AV_CODEC_ID_ARIB_CAPTION,
    AV_CODEC_ID_FIRST_UNKNOWN = 0x18000, ///< A dummy ID pointing at the start of various fake codecs.
    AV_CODEC_ID_TTF = 0x18000,
    AV_CODEC_ID_SCTE_35, ///< Contain timestamp estimated through PCR of program stream.
    AV_CODEC_ID_EPG,
    AV_CODEC_ID_BINTEXT = 0x18800,
    AV_CODEC_ID_XBIN,
    AV_CODEC_ID_IDF,
    AV_CODEC_ID_OTF,
    AV_CODEC_ID_SMPTE_KLV,
    AV_CODEC_ID_DVD_NAV,
    AV_CODEC_ID_TIMED_ID3,
    AV_CODEC_ID_BIN_DATA,
    AV_CODEC_ID_PROBE = 0x19000, ///< codec_id is not known (like AV_CODEC_ID_NONE) but lavf should attempt to identify it
    AV_CODEC_ID_MPEG2TS = 0x20000,
    AV_CODEC_ID_MPEG4SYSTEMS = 0x20001,
    AV_CODEC_ID_FFMETADATA = 0x21000,      ///< Dummy codec for streams containing only metadata information.
    AV_CODEC_ID_WRAPPED_AVFRAME = 0x21001, ///< Passthrough codec, AVFrames wrapped in 
};
enum AVStreamParseType
{
    AVSTREAM_PARSE_NONE,
    AVSTREAM_PARSE_FULL,
    AVSTREAM_PARSE_HEADERS,
    AVSTREAM_PARSE_TIMESTAMPS,
    AVSTREAM_PARSE_FULL_ONCE,
    AVSTREAM_PARSE_FULL_RAW,
};
typedef enum
{
    SDL_WINDOWEVENT_NONE,
    SDL_WINDOWEVENT_SHOWN,
    SDL_WINDOWEVENT_HIDDEN,
    SDL_WINDOWEVENT_EXPOSED,
    SDL_WINDOWEVENT_MOVED,
    SDL_WINDOWEVENT_RESIZED,
    SDL_WINDOWEVENT_SIZE_CHANGED,
    SDL_WINDOWEVENT_MINIMIZED,
    SDL_WINDOWEVENT_MAXIMIZED,
    SDL_WINDOWEVENT_RESTORED,
    SDL_WINDOWEVENT_ENTER,
    SDL_WINDOWEVENT_LEAVE,
    SDL_WINDOWEVENT_FOCUS_GAINED,
    SDL_WINDOWEVENT_FOCUS_LOST,
    SDL_WINDOWEVENT_CLOSE,
    SDL_WINDOWEVENT_TAKE_FOCUS,
    SDL_WINDOWEVENT_HIT_TEST
} SDL_WindowEventID;

typedef enum
{
    SDL_DISPLAYEVENT_NONE,
    SDL_DISPLAYEVENT_ORIENTATION
} SDL_DisplayEventID;

typedef enum
{
    SDL_ORIENTATION_UNKNOWN,
    SDL_ORIENTATION_LANDSCAPE,
    SDL_ORIENTATION_LANDSCAPE_FLIPPED,
    SDL_ORIENTATION_PORTRAIT,
    SDL_ORIENTATION_PORTRAIT_FLIPPED
} SDL_DisplayOrientation;

typedef void *SDL_GLContext;

typedef enum
{
    SDL_GL_RED_SIZE,
    SDL_GL_GREEN_SIZE,
    SDL_GL_BLUE_SIZE,
    SDL_GL_ALPHA_SIZE,
    SDL_GL_BUFFER_SIZE,
    SDL_GL_DOUBLEBUFFER,
    SDL_GL_DEPTH_SIZE,
    SDL_GL_STENCIL_SIZE,
    SDL_GL_ACCUM_RED_SIZE,
    SDL_GL_ACCUM_GREEN_SIZE,
    SDL_GL_ACCUM_BLUE_SIZE,
    SDL_GL_ACCUM_ALPHA_SIZE,
    SDL_GL_STEREO,
    SDL_GL_MULTISAMPLEBUFFERS,
    SDL_GL_MULTISAMPLESAMPLES,
    SDL_GL_ACCELERATED_VISUAL,
    SDL_GL_RETAINED_BACKING,
    SDL_GL_CONTEXT_MAJOR_VERSION,
    SDL_GL_CONTEXT_MINOR_VERSION,
    SDL_GL_CONTEXT_EGL,
    SDL_GL_CONTEXT_FLAGS,
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
    SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,
    SDL_GL_CONTEXT_RELEASE_BEHAVIOR,
    SDL_GL_CONTEXT_RESET_NOTIFICATION,
    SDL_GL_CONTEXT_NO_ERROR
} SDL_GLattr;

typedef enum
{
    SDL_GL_CONTEXT_PROFILE_CORE = 0x0001,
    SDL_GL_CONTEXT_PROFILE_COMPATIBILITY = 0x0002,
    SDL_GL_CONTEXT_PROFILE_ES = 0x0004
} SDL_GLprofile;

typedef enum
{
    SDL_GL_CONTEXT_DEBUG_FLAG = 0x0001,
    SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG = 0x0002,
    SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG = 0x0004,
    SDL_GL_CONTEXT_RESET_ISOLATION_FLAG = 0x0008
} SDL_GLcontextFlag;

typedef enum
{
    SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE = 0x0000,
    SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH = 0x0001
} SDL_GLcontextReleaseFlag;

typedef enum
{
    SDL_GL_CONTEXT_RESET_NO_NOTIFICATION = 0x0000,
    SDL_GL_CONTEXT_RESET_LOSE_CONTEXT = 0x0001
} SDL_GLContextResetNotification;

#define AV_PIX_FMT_NE(be, le) AV_PIX_FMT_##le
#define AV_PIX_FMT_RGB32 AV_PIX_FMT_NE(ARGB, BGRA)
#define AV_PIX_FMT_RGB32_1 AV_PIX_FMT_NE(RGBA, ABGR)
#define AV_PIX_FMT_BGR32 AV_PIX_FMT_NE(ABGR, RGBA)
#define AV_PIX_FMT_BGR32_1 AV_PIX_FMT_NE(BGRA, ARGB)
#define AV_PIX_FMT_0RGB32 AV_PIX_FMT_NE(0RGB, BGR0)
#define AV_PIX_FMT_0BGR32 AV_PIX_FMT_NE(0BGR, RGB0)
#define AV_PIX_FMT_GRAY9 AV_PIX_FMT_NE(GRAY9BE, GRAY9LE)
#define AV_PIX_FMT_GRAY10 AV_PIX_FMT_NE(GRAY10BE, GRAY10LE)
#define AV_PIX_FMT_GRAY12 AV_PIX_FMT_NE(GRAY12BE, GRAY12LE)
#define AV_PIX_FMT_GRAY14 AV_PIX_FMT_NE(GRAY14BE, GRAY14LE)
#define AV_PIX_FMT_GRAY16 AV_PIX_FMT_NE(GRAY16BE, GRAY16LE)
#define AV_PIX_FMT_YA16 AV_PIX_FMT_NE(YA16BE, YA16LE)
#define AV_PIX_FMT_RGB48 AV_PIX_FMT_NE(RGB48BE, RGB48LE)
#define AV_PIX_FMT_RGB565 AV_PIX_FMT_NE(RGB565BE, RGB565LE)
#define AV_PIX_FMT_RGB555 AV_PIX_FMT_NE(RGB555BE, RGB555LE)
#define AV_PIX_FMT_RGB444 AV_PIX_FMT_NE(RGB444BE, RGB444LE)
#define AV_PIX_FMT_RGBA64 AV_PIX_FMT_NE(RGBA64BE, RGBA64LE)
#define AV_PIX_FMT_BGR48 AV_PIX_FMT_NE(BGR48BE, BGR48LE)
#define AV_PIX_FMT_BGR565 AV_PIX_FMT_NE(BGR565BE, BGR565LE)
#define AV_PIX_FMT_BGR555 AV_PIX_FMT_NE(BGR555BE, BGR555LE)
#define AV_PIX_FMT_BGR444 AV_PIX_FMT_NE(BGR444BE, BGR444LE)
#define AV_PIX_FMT_BGRA64 AV_PIX_FMT_NE(BGRA64BE, BGRA64LE)
#define AV_PIX_FMT_YUV420P9 AV_PIX_FMT_NE(YUV420P9BE, YUV420P9LE)
#define AV_PIX_FMT_YUV422P9 AV_PIX_FMT_NE(YUV422P9BE, YUV422P9LE)
#define AV_PIX_FMT_YUV444P9 AV_PIX_FMT_NE(YUV444P9BE, YUV444P9LE)
#define AV_PIX_FMT_YUV420P10 AV_PIX_FMT_NE(YUV420P10BE, YUV420P10LE)
#define AV_PIX_FMT_YUV422P10 AV_PIX_FMT_NE(YUV422P10BE, YUV422P10LE)
#define AV_PIX_FMT_YUV440P10 AV_PIX_FMT_NE(YUV440P10BE, YUV440P10LE)
#define AV_PIX_FMT_YUV444P10 AV_PIX_FMT_NE(YUV444P10BE, YUV444P10LE)
#define AV_PIX_FMT_YUV420P12 AV_PIX_FMT_NE(YUV420P12BE, YUV420P12LE)
#define AV_PIX_FMT_YUV422P12 AV_PIX_FMT_NE(YUV422P12BE, YUV422P12LE)
#define AV_PIX_FMT_YUV440P12 AV_PIX_FMT_NE(YUV440P12BE, YUV440P12LE)
#define AV_PIX_FMT_YUV444P12 AV_PIX_FMT_NE(YUV444P12BE, YUV444P12LE)
#define AV_PIX_FMT_YUV420P14 AV_PIX_FMT_NE(YUV420P14BE, YUV420P14LE)
#define AV_PIX_FMT_YUV422P14 AV_PIX_FMT_NE(YUV422P14BE, YUV422P14LE)
#define AV_PIX_FMT_YUV444P14 AV_PIX_FMT_NE(YUV444P14BE, YUV444P14LE)
#define AV_PIX_FMT_YUV420P16 AV_PIX_FMT_NE(YUV420P16BE, YUV420P16LE)
#define AV_PIX_FMT_YUV422P16 AV_PIX_FMT_NE(YUV422P16BE, YUV422P16LE)
#define AV_PIX_FMT_YUV444P16 AV_PIX_FMT_NE(YUV444P16BE, YUV444P16LE)
#define AV_PIX_FMT_GBRP9 AV_PIX_FMT_NE(GBRP9BE, GBRP9LE)
#define AV_PIX_FMT_GBRP10 AV_PIX_FMT_NE(GBRP10BE, GBRP10LE)
#define AV_PIX_FMT_GBRP12 AV_PIX_FMT_NE(GBRP12BE, GBRP12LE)
#define AV_PIX_FMT_GBRP14 AV_PIX_FMT_NE(GBRP14BE, GBRP14LE)
#define AV_PIX_FMT_GBRP16 AV_PIX_FMT_NE(GBRP16BE, GBRP16LE)
#define AV_PIX_FMT_GBRAP10 AV_PIX_FMT_NE(GBRAP10BE, GBRAP10LE)
#define AV_PIX_FMT_GBRAP12 AV_PIX_FMT_NE(GBRAP12BE, GBRAP12LE)
#define AV_PIX_FMT_GBRAP16 AV_PIX_FMT_NE(GBRAP16BE, GBRAP16LE)
#define AV_PIX_FMT_BAYER_BGGR16 AV_PIX_FMT_NE(BAYER_BGGR16BE, BAYER_BGGR16LE)
#define AV_PIX_FMT_BAYER_RGGB16 AV_PIX_FMT_NE(BAYER_RGGB16BE, BAYER_RGGB16LE)
#define AV_PIX_FMT_BAYER_GBRG16 AV_PIX_FMT_NE(BAYER_GBRG16BE, BAYER_GBRG16LE)
#define AV_PIX_FMT_BAYER_GRBG16 AV_PIX_FMT_NE(BAYER_GRBG16BE, BAYER_GRBG16LE)
#define AV_PIX_FMT_GBRPF32 AV_PIX_FMT_NE(GBRPF32BE, GBRPF32LE)
#define AV_PIX_FMT_GBRAPF32 AV_PIX_FMT_NE(GBRAPF32BE, GBRAPF32LE)
#define AV_PIX_FMT_GRAYF32 AV_PIX_FMT_NE(GRAYF32BE, GRAYF32LE)
#define AV_PIX_FMT_YUVA420P9 AV_PIX_FMT_NE(YUVA420P9BE, YUVA420P9LE)
#define AV_PIX_FMT_YUVA422P9 AV_PIX_FMT_NE(YUVA422P9BE, YUVA422P9LE)
#define AV_PIX_FMT_YUVA444P9 AV_PIX_FMT_NE(YUVA444P9BE, YUVA444P9LE)
#define AV_PIX_FMT_YUVA420P10 AV_PIX_FMT_NE(YUVA420P10BE, YUVA420P10LE)
#define AV_PIX_FMT_YUVA422P10 AV_PIX_FMT_NE(YUVA422P10BE, YUVA422P10LE)
#define AV_PIX_FMT_YUVA444P10 AV_PIX_FMT_NE(YUVA444P10BE, YUVA444P10LE)
#define AV_PIX_FMT_YUVA422P12 AV_PIX_FMT_NE(YUVA422P12BE, YUVA422P12LE)
#define AV_PIX_FMT_YUVA444P12 AV_PIX_FMT_NE(YUVA444P12BE, YUVA444P12LE)
#define AV_PIX_FMT_YUVA420P16 AV_PIX_FMT_NE(YUVA420P16BE, YUVA420P16LE)
#define AV_PIX_FMT_YUVA422P16 AV_PIX_FMT_NE(YUVA422P16BE, YUVA422P16LE)
#define AV_PIX_FMT_YUVA444P16 AV_PIX_FMT_NE(YUVA444P16BE, YUVA444P16LE)
#define AV_PIX_FMT_XYZ12 AV_PIX_FMT_NE(XYZ12BE, XYZ12LE)
#define AV_PIX_FMT_NV20 AV_PIX_FMT_NE(NV20BE, NV20LE)
#define AV_PIX_FMT_AYUV64 AV_PIX_FMT_NE(AYUV64BE, AYUV64LE)
#define AV_PIX_FMT_P010 AV_PIX_FMT_NE(P010BE, P010LE)
#define AV_PIX_FMT_P016 AV_PIX_FMT_NE(P016BE, P016LE)
#define AV_PIX_FMT_Y210 AV_PIX_FMT_NE(Y210BE, Y210LE)
#define AV_PIX_FMT_X2RGB10 AV_PIX_FMT_NE(X2RGB10BE, X2RGB10LE)
#define MKTAG(a, b, c, d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define MKBETAG(a, b, c, d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))
#define AVERROR(e) (-(e))
#define AVUNERROR(e) (-(e))
#define FFERRTAG(a, b, c, d) (-(int)MKTAG(a, b, c, d))
#define AVERROR_BSF_NOT_FOUND FFERRTAG(0xF8, 'B', 'S', 'F')
#define AVERROR_BUG FFERRTAG('B', 'U', 'G', '!')
#define AVERROR_BUFFER_TOO_SMALL FFERRTAG('B', 'U', 'F', 'S')
#define AVERROR_DECODER_NOT_FOUND FFERRTAG(0xF8, '2', '1', 'C')
#define AVERROR_DEMUXER_NOT_FOUND FFERRTAG(0xF8, '2', '1', 'M')
#define AVERROR_ENCODER_NOT_FOUND FFERRTAG(0xF8, '1', 'N', 'C')
#define AVERROR_EOF FFERRTAG('1', 'O', 'F', ' ')
#define AVERROR_EXIT FFERRTAG('1', 'X', 'I', 'T')
#define AVERROR_EXTERNAL FFERRTAG('1', 'X', 'T', ' ')
#define AVERROR_FILTER_NOT_FOUND FFERRTAG(0xF8, 'F', 'I', 'L')
#define AVERROR_INVALIDDATA FFERRTAG('I', 'N', '2', 'A')
#define AVERROR_MUXER_NOT_FOUND FFERRTAG(0xF8, 'M', 'U', 'X')
#define AVERROR_OPTION_NOT_FOUND FFERRTAG(0xF8, 'O', 'P', 'T')
#define AVERROR_PATCHWELCOME FFERRTAG('P', 'A', 'W', '1')
#define AVERROR_PROTOCOL_NOT_FOUND FFERRTAG(0xF8, 'P', 'R', 'O')
#define AVERROR_STREAM_NOT_FOUND FFERRTAG(0xF8, 'S', 'T', 'R')
#define AVERROR_BUG2 FFERRTAG('B', 'U', 'G', ' ')
#define AVERROR_UNKNOWN FFERRTAG('U', 'N', 'K', 'N')
#define AVERROR_EXPERIMENTAL (-0x2bb2afa8)
#define AVERROR_INPUT_CHANGED (-0x636e6701)
#define AVERROR_OUTPUT_CHANGED (-0x636e6702)
#define AVERROR_HTTP_BAD_REQUEST FFERRTAG(0xF8, '4', '0', '0')
#define AVERROR_HTTP_UNAUTHORIZED FFERRTAG(0xF8, '4', '0', '1')
#define AVERROR_HTTP_FORBIDDEN FFERRTAG(0xF8, '4', '0', '3')
#define AVERROR_HTTP_NOT_FOUND FFERRTAG(0xF8, '4', '0', '4')
#define AVERROR_HTTP_OTHER_4XX FFERRTAG(0xF8, '4', 'X', 'X')
#define AVERROR_HTTP_SERVER_ERROR FFERRTAG(0xF8, '5', 'X', 'X')
#define AV_ERROR_MAX_STRING_SIZE 64
#define av_err2str(errnum) av_make_error_string((char[AV_ERROR_MAX_STRING_SIZE]){0}, AV_ERROR_MAX_STRING_SIZE, errnum)
#define DECLARE_ALIGNED(n, t, v) t __attribute__((aligned(n))) v
#define DECLARE_ASM_ALIGNED(n, t, v) t av_used __attribute__((aligned(n))) v
#define DECLARE_ASM_CONST(n, t, v) static const t av_used __attribute__((aligned(n))) v
#define av_malloc_attrib __attribute__((__malloc__))
#define av_alloc_size(...) __attribute__((alloc_size(__VA_ARGS__)))
#define M_LOG2_10 3.32192809488736234787
#define M_PHI 1.61803398874989484820
#define AV_IS_INPUT_DEVICE(category) (((category) == AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT) || ((category) == AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT) || ((category) == AV_CLASS_CATEGORY_DEVICE_INPUT))
#define AV_IS_OUTPUT_DEVICE(category) (((category) == AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT) || ((category) == AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT) || ((category) == AV_CLASS_CATEGORY_DEVICE_OUTPUT))
#define AV_LOG_QUIET -8
#define AV_LOG_PANIC 0
#define AV_LOG_FATAL 8
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_INFO 32
#define AV_LOG_VERBOSE 40
#define AV_LOG_DEBUG 48
#define AV_LOG_TRACE 56
#define AV_LOG_MAX_OFFSET (AV_LOG_TRACE - AV_LOG_QUIET)
#define AV_LOG_C(x) ((x) << 8)
#define AV_FOURCC_MAX_STRING_SIZE 32
#define av_fourcc2str(fourcc) av_fourcc_make_string((char[AV_FOURCC_MAX_STRING_SIZE]){0}, fourcc)
#define AV_PIX_FMT_FLAG_BE (1 << 0)
#define AV_PIX_FMT_FLAG_PAL (1 << 1)
#define AV_PIX_FMT_FLAG_BITSTREAM (1 << 2)
#define AV_PIX_FMT_FLAG_HWACCEL (1 << 3)
#define AV_PIX_FMT_FLAG_PLANAR (1 << 4)
#define AV_PIX_FMT_FLAG_RGB (1 << 5)
#define AV_PIX_FMT_FLAG_PSEUDOPAL (1 << 6)
#define AV_PIX_FMT_FLAG_ALPHA (1 << 7)
#define AV_PIX_FMT_FLAG_BAYER (1 << 8)
#define AV_PIX_FMT_FLAG_FLOAT (1 << 9)
#define FF_LOSS_RESOLUTION 0x0001
#define FF_LOSS_DEPTH 0x0002
#define FF_LOSS_COLORSPACE 0x0004
#define FF_LOSS_ALPHA 0x0008
#define FF_LOSS_COLORQUANT 0x0010
#define FF_LOSS_CHROMA 0x0020
#define AV_DICT_MATCH_CASE 1
#define AV_DICT_IGNORE_SUFFIX 2
#define AV_DICT_DONT_STRDUP_KEY 4
#define AV_DICT_DONT_STRDUP_VAL 8
#define AV_DICT_DONT_OVERWRITE 16
#define AV_DICT_APPEND 32
#define AV_DICT_MULTIKEY 64
#define ID3v2_HEADER_SIZE 10
#define ID3v2_DEFAULT_MAGIC "ID3"
#define ID3v2_FLAG_DATALEN 0x0001
#define ID3v2_FLAG_UNSYNCH 0x0002
#define ID3v2_FLAG_ENCRYPTION 0x0004
#define ID3v2_FLAG_COMPRESSION 0x0008
#define PROBE_BUF_MAX (1 << 20)
#define PROBE_BUF_MIN 2048
#define VIDEO_PICTURE_QUEUE_SIZE 3
#define SUBPICTURE_QUEUE_SIZE 16
#define SAMPLE_QUEUE_SIZE 9
#define FRAME_QUEUE_SIZE FFMAX(SAMPLE_QUEUE_SIZE, FFMAX(VIDEO_PICTURE_QUEUE_SIZE, SUBPICTURE_QUEUE_SIZE))
#define AV_ESCAPE_FLAG_WHITESPACE (1 << 0)
#define AV_ESCAPE_FLAG_STRICT (1 << 1)

#define AV_UTF8_FLAG_ACCEPT_INVALID_BIG_CODES 1
#define AV_UTF8_FLAG_ACCEPT_NON_CHARACTERS 2
#define AV_UTF8_FLAG_ACCEPT_SURROGATES 4
#define AV_UTF8_FLAG_EXCLUDE_XML_INVALID_CONTROL_CODES 8
#define AV_UTF8_FLAG_ACCEPT_ALL AV_UTF8_FLAG_ACCEPT_INVALID_BIG_CODES | AV_UTF8_FLAG_ACCEPT_NON_CHARACTERS | AV_UTF8_FLAG_ACCEPT_SURROGATES

#define FF_LAMBDA_SHIFT 7
#define FF_LAMBDA_SCALE (1 << FF_LAMBDA_SHIFT)
#define FF_QP2LAMBDA 118
#define FF_LAMBDA_MAX (256 * 128 - 1)
#define FF_QUALITY_SCALE FF_LAMBDA_SCALE
#define AV_NOPTS_VALUE ((int64_t)UINT64_C(0x8000000000000000))
#define AV_TIME_BASE 1000000
#define AV_TIME_BASE_Q   (AVRational) { 1, AV_TIME_BASE }

#define AV_HAVE_BIGENDIAN 0
#define AV_HAVE_FAST_UNALIGNED 1
#define AV_NE(be, le) (le)
#define RSHIFT(a, b) ((a) > 0 ? ((a) + ((1 << (b)) >> 1)) >> (b) : ((a) + ((1 << (b)) >> 1) - 1) >> (b))
#define ROUNDED_DIV(a, b) (((a) >= 0 ? (a) + ((b) >> 1) : (a) - ((b) >> 1)) / (b))
#define AV_CEIL_RSHIFT(a, b) (!av_builtin_constant_p(b) ? -((-(a)) >> (b)) : ((a) + (1 << (b)) - 1) >> (b))
#define FF_CEIL_RSHIFT AV_CEIL_RSHIFT
#define FFUDIV(a, b) (((a) > 0 ? (a) : (a) - (b) + 1) / (b))
#define FFUMOD(a, b) ((a) - (b)*FFUDIV(a, b))
#define FFABS(a) ((a) >= 0 ? (a) : (-(a)))
#define FFSIGN(a) ((a) > 0 ? 1 : -1)
#define FFNABS(a) ((a) <= 0 ? (a) : (-(a)))
#define FFDIFFSIGN(x, y) (((x) > (y)) - ((x) < (y)))
#define FFMAX(a, b) ((a) > (b) ? (a) : (b))
#define FFMAX3(a, b, c) FFMAX(FFMAX(a, b), c)
#define FFMIN(a, b) ((a) > (b) ? (b) : (a))
#define FFMIN3(a, b, c) FFMIN(FFMIN(a, b), c)
#define FFSWAP(type, a, b) \
    do                     \
    {                      \
        type SWAP_tmp = b; \
        b = a;             \
        a = SWAP_tmp;      \
    } while (0)
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define av_ceil_log2 av_ceil_log2_c
#define av_clip av_clip_c
#define av_clip64 av_clip64_c
#define av_clip_uint8 av_clip_uint8_c
#define av_clip_int8 av_clip_int8_c
#define av_clip_uint16 av_clip_uint16_c
#define av_clip_int16 av_clip_int16_c
#define av_clipl_int32 av_clipl_int32_c
#define av_clip_intp2 av_clip_intp2_c
#define av_clip_uintp2 av_clip_uintp2_c
#define av_mod_uintp2 av_mod_uintp2_c
#define av_sat_add32 av_sat_add32_c
#define av_sat_dadd32 av_sat_dadd32_c
#define av_sat_sub32 av_sat_sub32_c
#define av_sat_dsub32 av_sat_dsub32_c
#define av_sat_add64 av_sat_add64_c
#define av_sat_sub64 av_sat_sub64_c
#define av_clipf av_clipf_c
#define av_clipd av_clipd_c
#define av_popcount av_popcount_c
#define av_popcount64 av_popcount64_c
#define av_parity av_parity_c
#define HAVE_WINAPIFAMILY_H 0
#define WINAPI_FAMILY_WINRT 0
#define __WINDOWS__ 1
#define __WIN32__ 1
#define SDL_DEPRECATED __attribute__((deprecated))
#define SDL_UNUSED __attribute__((unused))
#define DECLSPEC __declspec(dllexport)
#define SDLCALL
#define SDL_INLINE __inline__
#define SDL_FORCE_INLINE __attribute__((always_inline)) static __inline__
#define SDL_NORETURN __attribute__((noreturn))
#define HAVE_STDINT_H 1
#define SIZEOF_VOIDP 8
#define HAVE_DDRAW_H 1
#define HAVE_DINPUT_H 1
#define HAVE_DSOUND_H 1
#define HAVE_DXGI_H 1
#define HAVE_XINPUT_H 1
#define HAVE_MMDEVICEAPI_H 1
#define HAVE_AUDIOCLIENT_H 1
#define HAVE_STDARG_H 1
#define HAVE_STDDEF_H 1
#define SDL_AUDIO_DRIVER_WASAPI 1
#define SDL_AUDIO_DRIVER_DSOUND 1
#define SDL_AUDIO_DRIVER_WINMM 1
#define SDL_AUDIO_DRIVER_DISK 1
#define SDL_AUDIO_DRIVER_DUMMY 1
#define SDL_JOYSTICK_DINPUT 1
#define SDL_JOYSTICK_XINPUT 1
#define SDL_JOYSTICK_HIDAPI 1
#define SDL_HAPTIC_DINPUT 1
#define SDL_HAPTIC_XINPUT 1
#define SDL_SENSOR_DUMMY 1
#define SDL_LOADSO_WINDOWS 1
#define SDL_THREAD_WINDOWS 1
#define SDL_TIMER_WINDOWS 1
#define SDL_VIDEO_DRIVER_DUMMY 1
#define SDL_VIDEO_DRIVER_WINDOWS 1
#define SDL_VIDEO_RENDER_D3D 1
#define SDL_VIDEO_RENDER_D3D11 0
#define SDL_VIDEO_OPENGL 1
#define SDL_VIDEO_OPENGL_WGL 1
#define SDL_VIDEO_RENDER_OGL 1
#define SDL_VIDEO_RENDER_OGL_ES2 1
#define SDL_VIDEO_OPENGL_ES2 1
#define SDL_VIDEO_OPENGL_EGL 1
#define SDL_VIDEO_VULKAN 1
#define SDL_POWER_WINDOWS 1
#define SDL_FILESYSTEM_WINDOWS 1
#define SDL_arraysize(array) (sizeof(array) / sizeof(array[0]))
#define SDL_TABLESIZE(table) SDL_arraysize(table)
#define SDL_STRINGIFY_ARG(arg) #arg
#define SDL_reinterpret_cast(type, expression) ((type)(expression))
#define SDL_static_cast(type, expression) ((type)(expression))
#define SDL_const_cast(type, expression) ((type)(expression))
#define SDL_FOURCC(A, B, C, D) ((SDL_static_cast(uint32_t, SDL_static_cast(Uint8, (A))) << 0) | (SDL_static_cast(uint32_t, SDL_static_cast(Uint8, (B))) << 8) | (SDL_static_cast(uint32_t, SDL_static_cast(Uint8, (C))) << 16) | (SDL_static_cast(uint32_t, SDL_static_cast(Uint8, (D))) << 24))
#define SDL_MAX_SINT8 ((Sint8)0x7F)
#define SDL_MIN_SINT8 ((Sint8)(~0x7F))
typedef int8_t Sint8;
#define SDL_MAX_UINT8 ((Uint8)0xFF)
#define SDL_MIN_UINT8 ((Uint8)0x00)
typedef uint8_t Uint8;
#define SDL_MAX_SINT16 ((Sint16)0x7FFF)
#define SDL_MIN_SINT16 ((Sint16)(~0x7FFF))
typedef int16_t Sint16;
#define SDL_MAX_UINT16 ((Uint16)0xFFFF)
#define SDL_MIN_UINT16 ((Uint16)0x0000)
typedef uint16_t Uint16;
#define SDL_MAX_SINT32 ((Sint32)0x7FFFFFFF)
#define SDL_MIN_SINT32 ((Sint32)(~0x7FFFFFFF))
typedef int32_t Sint32;
#define SDL_MAX_UINT32 ((uint32_t)0xFFFFFFFFu)
#define SDL_MIN_UINT32 ((uint32_t)0x00000000)
typedef uint32_t uint32_t;
#define SDL_MAX_SINT64 ((Sint64)0x7FFFFFFFFFFFFFFFll)
#define SDL_MIN_SINT64 ((Sint64)(~0x7FFFFFFFFFFFFFFFll))
typedef int64_t Sint64;
#define SDL_MAX_UINT64 ((Uint64)0xFFFFFFFFFFFFFFFFull)
#define SDL_MIN_UINT64 ((Uint64)(0x0000000000000000ull))
typedef uint64_t Uint64;
#define SDL_PRIs64 "I64d"
#define SDL_PRIu64 PRIu64
#define SDL_PRIx64 PRIx64
#define SDL_PRIX64 PRIX64
#define SDL_IN_BYTECAP(x)
#define SDL_INOUT_Z_CAP(x)
#define SDL_OUT_Z_CAP(x)
#define SDL_OUT_CAP(x)
#define SDL_OUT_BYTECAP(x)
#define SDL_OUT_Z_BYTECAP(x)
#define SDL_PRINTF_FORMAT_STRING
#define SDL_SCANF_FORMAT_STRING
#define SDL_PRINTF_VARARG_FUNC(fmtargnumber) __attribute__((format(__printf__, fmtargnumber, fmtargnumber + 1)))
#define SDL_SCANF_VARARG_FUNC(fmtargnumber) __attribute__((format(__scanf__, fmtargnumber, fmtargnumber + 1)))
#define SDL_COMPILE_TIME_ASSERT(name, x) typedef int SDL_compile_time_assert_##name[(x)*2 - 1]

#define UDPLITE_SEND_CSCOV                               10
#define UDPLITE_RECV_CSCOV                               11
#ifndef IPPROTO_UDPLITE
#define IPPROTO_UDPLITE                                  136
#endif
#ifndef IPV6_ADD_MEMBERSHIP
#define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
#endif
#define UDP_TX_BUF_SIZE 32768
#define UDP_RX_BUF_SIZE 393216
#define UDP_MAX_PKT_SIZE 65536
#define UDP_HEADER_SIZE 8

#   define AV_WL32(p, val) do {                 \
        uint32_t d = (val);                     \
        ((uint8_t*)(p))[0] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
        ((uint8_t*)(p))[2] = (d)>>16;           \
        ((uint8_t*)(p))[3] = (d)>>24;           \
    } while(0)

static av_const uint16_t av_bswap16(uint16_t x)
{
    x = (x >> 8) | (x << 8);
    return x;
}
static av_const uint32_t av_bswap32(uint32_t x)
{
    return x << 16 | x >> 16;
}
static inline uint64_t av_const av_bswap64(uint64_t x)
{
    return (uint64_t)av_bswap32(x) << 32 | av_bswap32(x >> 32);
}

#if defined(__GNUC__)

union unaligned_64 { uint64_t l; } __attribute__((packed)) av_alias;
union unaligned_32 { uint32_t l; } __attribute__((packed)) av_alias;
union unaligned_16 { uint16_t l; } __attribute__((packed)) av_alias;

#   define AV_RN(s, p) (((const union unaligned_##s *) (p))->l)
#   define AV_WN(s, p, v) ((((union unaligned_##s *) (p))->l) = (v))

#elif defined(_MSC_VER) && (defined(_M_ARM) || defined(_M_X64) || defined(_M_ARM64)) && AV_HAVE_FAST_UNALIGNED

#   define AV_RN(s, p) (*((const __unaligned uint##s##_t*)(p)))
#   define AV_WN(s, p, v) (*((__unaligned uint##s##_t*)(p)) = (v))

#elif AV_HAVE_FAST_UNALIGNED

#   define AV_RN(s, p) (((const av_alias##s*)(p))->u##s)
#   define AV_WN(s, p, v) (((av_alias##s*)(p))->u##s = (v))

#else

#ifndef AV_RB16
#   define AV_RB16(x)                           \
    ((((const uint8_t*)(x))[0] << 8) |          \
      ((const uint8_t*)(x))[1])
#endif
#ifndef AV_WB16
#   define AV_WB16(p, val) do {                 \
        uint16_t d = (val);                     \
        ((uint8_t*)(p))[1] = (d);               \
        ((uint8_t*)(p))[0] = (d)>>8;            \
    } while(0)
#endif

#ifndef AV_RL16
#   define AV_RL16(x)                           \
    ((((const uint8_t*)(x))[1] << 8) |          \
      ((const uint8_t*)(x))[0])
#endif
#ifndef AV_WL16
#   define AV_WL16(p, val) do {                 \
        uint16_t d = (val);                     \
        ((uint8_t*)(p))[0] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
    } while(0)
#endif

#ifndef AV_RB32
#   define AV_RB32(x)                                \
    (((uint32_t)((const uint8_t*)(x))[0] << 24) |    \
               (((const uint8_t*)(x))[1] << 16) |    \
               (((const uint8_t*)(x))[2] <<  8) |    \
                ((const uint8_t*)(x))[3])
#endif
#ifndef AV_WB32
#   define AV_WB32(p, val) do {                 \
        uint32_t d = (val);                     \
        ((uint8_t*)(p))[3] = (d);               \
        ((uint8_t*)(p))[2] = (d)>>8;            \
        ((uint8_t*)(p))[1] = (d)>>16;           \
        ((uint8_t*)(p))[0] = (d)>>24;           \
    } while(0)
#endif

#ifndef AV_RL32
#   define AV_RL32(x)                                \
    (((uint32_t)((const uint8_t*)(x))[3] << 24) |    \
               (((const uint8_t*)(x))[2] << 16) |    \
               (((const uint8_t*)(x))[1] <<  8) |    \
                ((const uint8_t*)(x))[0])
#endif
#ifndef AV_WL32
#   define AV_WL32(p, val) do {                 \
        uint32_t d = (val);                     \
        ((uint8_t*)(p))[0] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
        ((uint8_t*)(p))[2] = (d)>>16;           \
        ((uint8_t*)(p))[3] = (d)>>24;           \
    } while(0)
#endif

#ifndef AV_RB64
#   define AV_RB64(x)                                   \
    (((uint64_t)((const uint8_t*)(x))[0] << 56) |       \
     ((uint64_t)((const uint8_t*)(x))[1] << 48) |       \
     ((uint64_t)((const uint8_t*)(x))[2] << 40) |       \
     ((uint64_t)((const uint8_t*)(x))[3] << 32) |       \
     ((uint64_t)((const uint8_t*)(x))[4] << 24) |       \
     ((uint64_t)((const uint8_t*)(x))[5] << 16) |       \
     ((uint64_t)((const uint8_t*)(x))[6] <<  8) |       \
      (uint64_t)((const uint8_t*)(x))[7])
#endif
#ifndef AV_WB64
#   define AV_WB64(p, val) do {                 \
        uint64_t d = (val);                     \
        ((uint8_t*)(p))[7] = (d);               \
        ((uint8_t*)(p))[6] = (d)>>8;            \
        ((uint8_t*)(p))[5] = (d)>>16;           \
        ((uint8_t*)(p))[4] = (d)>>24;           \
        ((uint8_t*)(p))[3] = (d)>>32;           \
        ((uint8_t*)(p))[2] = (d)>>40;           \
        ((uint8_t*)(p))[1] = (d)>>48;           \
        ((uint8_t*)(p))[0] = (d)>>56;           \
    } while(0)
#endif

#ifndef AV_RL64
#   define AV_RL64(x)                                   \
    (((uint64_t)((const uint8_t*)(x))[7] << 56) |       \
     ((uint64_t)((const uint8_t*)(x))[6] << 48) |       \
     ((uint64_t)((const uint8_t*)(x))[5] << 40) |       \
     ((uint64_t)((const uint8_t*)(x))[4] << 32) |       \
     ((uint64_t)((const uint8_t*)(x))[3] << 24) |       \
     ((uint64_t)((const uint8_t*)(x))[2] << 16) |       \
     ((uint64_t)((const uint8_t*)(x))[1] <<  8) |       \
      (uint64_t)((const uint8_t*)(x))[0])
#endif
#ifndef AV_WL64
#   define AV_WL64(p, val) do {                 \
        uint64_t d = (val);                     \
        ((uint8_t*)(p))[0] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
        ((uint8_t*)(p))[2] = (d)>>16;           \
        ((uint8_t*)(p))[3] = (d)>>24;           \
        ((uint8_t*)(p))[4] = (d)>>32;           \
        ((uint8_t*)(p))[5] = (d)>>40;           \
        ((uint8_t*)(p))[6] = (d)>>48;           \
        ((uint8_t*)(p))[7] = (d)>>56;           \
    } while(0)
#endif

#if AV_HAVE_BIGENDIAN
#   define AV_RN(s, p)    AV_RB##s(p)
#   define AV_WN(s, p, v) AV_WB##s(p, v)
#else
#   define AV_RN(s, p)    AV_RL##s(p)
#   define AV_WN(s, p, v) AV_WL##s(p, v)
#endif

#endif /* HAVE_FAST_UNALIGNED */

#ifndef AV_RN16
#   define AV_RN16(p) AV_RN(16, p)
#endif

#ifndef AV_RN32
#   define AV_RN32(p) AV_RN(32, p)
#endif

#ifndef AV_RN64
#   define AV_RN64(p) AV_RN(64, p)
#endif

#ifndef AV_WN16
#   define AV_WN16(p, v) AV_WN(16, p, v)
#endif

#ifndef AV_WN32
#   define AV_WN32(p, v) AV_WN(32, p, v)
#endif

#ifndef AV_WN64
#   define AV_WN64(p, v) AV_WN(64, p, v)
#endif

#if AV_HAVE_BIGENDIAN
#   define AV_RB(s, p)    AV_RN##s(p)
#   define AV_WB(s, p, v) AV_WN##s(p, v)
#   define AV_RL(s, p)    av_bswap##s(AV_RN##s(p))
#   define AV_WL(s, p, v) AV_WN##s(p, av_bswap##s(v))
#else
#   define AV_RB(s, p)    av_bswap##s(AV_RN##s(p))
#   define AV_WB(s, p, v) AV_WN##s(p, av_bswap##s(v))
#   define AV_RL(s, p)    AV_RN##s(p)
#   define AV_WL(s, p, v) AV_WN##s(p, v)
#endif

#define AV_RB8(x)     (((const uint8_t*)(x))[0])
#define AV_WB8(p, d)  do { ((uint8_t*)(p))[0] = (d); } while(0)

#define AV_RL8(x)     AV_RB8(x)
#define AV_WL8(p, d)  AV_WB8(p, d)

#ifndef AV_RB16
#   define AV_RB16(p)    AV_RB(16, p)
#endif
#ifndef AV_WB16
#   define AV_WB16(p, v) AV_WB(16, p, v)
#endif

#ifndef AV_RL16
#   define AV_RL16(p)    AV_RL(16, p)
#endif
#ifndef AV_WL16
#   define AV_WL16(p, v) AV_WL(16, p, v)
#endif

#ifndef AV_RB32
#   define AV_RB32(p)    AV_RB(32, p)
#endif
#ifndef AV_WB32
#   define AV_WB32(p, v) AV_WB(32, p, v)
#endif

#ifndef AV_RL32
#   define AV_RL32(p)    AV_RL(32, p)
#endif
#ifndef AV_WL32
#   define AV_WL32(p, v) AV_WL(32, p, v)
#endif

#ifndef AV_RB64
#   define AV_RB64(p)    AV_RB(64, p)
#endif
#ifndef AV_WB64
#   define AV_WB64(p, v) AV_WB(64, p, v)
#endif

#ifndef AV_RL64
#   define AV_RL64(p)    AV_RL(64, p)
#endif
#ifndef AV_WL64
#   define AV_WL64(p, v) AV_WL(64, p, v)
#endif

#ifndef AV_RB24
#   define AV_RB24(x)                           \
    ((((const uint8_t*)(x))[0] << 16) |         \
     (((const uint8_t*)(x))[1] <<  8) |         \
      ((const uint8_t*)(x))[2])
#endif
#ifndef AV_WB24
#   define AV_WB24(p, d) do {                   \
        ((uint8_t*)(p))[2] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
        ((uint8_t*)(p))[0] = (d)>>16;           \
    } while(0)
#endif

#ifndef AV_RL24
#   define AV_RL24(x)                           \
    ((((const uint8_t*)(x))[2] << 16) |         \
     (((const uint8_t*)(x))[1] <<  8) |         \
      ((const uint8_t*)(x))[0])
#endif
#ifndef AV_WL24
#   define AV_WL24(p, d) do {                   \
        ((uint8_t*)(p))[0] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
        ((uint8_t*)(p))[2] = (d)>>16;           \
    } while(0)
#endif

#ifndef AV_RB48
#   define AV_RB48(x)                                     \
    (((uint64_t)((const uint8_t*)(x))[0] << 40) |         \
     ((uint64_t)((const uint8_t*)(x))[1] << 32) |         \
     ((uint64_t)((const uint8_t*)(x))[2] << 24) |         \
     ((uint64_t)((const uint8_t*)(x))[3] << 16) |         \
     ((uint64_t)((const uint8_t*)(x))[4] <<  8) |         \
      (uint64_t)((const uint8_t*)(x))[5])
#endif
#ifndef AV_WB48
#   define AV_WB48(p, darg) do {                \
        uint64_t d = (darg);                    \
        ((uint8_t*)(p))[5] = (d);               \
        ((uint8_t*)(p))[4] = (d)>>8;            \
        ((uint8_t*)(p))[3] = (d)>>16;           \
        ((uint8_t*)(p))[2] = (d)>>24;           \
        ((uint8_t*)(p))[1] = (d)>>32;           \
        ((uint8_t*)(p))[0] = (d)>>40;           \
    } while(0)
#endif

#ifndef AV_RL48
#   define AV_RL48(x)                                     \
    (((uint64_t)((const uint8_t*)(x))[5] << 40) |         \
     ((uint64_t)((const uint8_t*)(x))[4] << 32) |         \
     ((uint64_t)((const uint8_t*)(x))[3] << 24) |         \
     ((uint64_t)((const uint8_t*)(x))[2] << 16) |         \
     ((uint64_t)((const uint8_t*)(x))[1] <<  8) |         \
      (uint64_t)((const uint8_t*)(x))[0])
#endif
#ifndef AV_WL48
#   define AV_WL48(p, darg) do {                \
        uint64_t d = (darg);                    \
        ((uint8_t*)(p))[0] = (d);               \
        ((uint8_t*)(p))[1] = (d)>>8;            \
        ((uint8_t*)(p))[2] = (d)>>16;           \
        ((uint8_t*)(p))[3] = (d)>>24;           \
        ((uint8_t*)(p))[4] = (d)>>32;           \
        ((uint8_t*)(p))[5] = (d)>>40;           \
    } while(0)
#endif

/*
 * The AV_[RW]NA macros access naturally aligned data
 * in a type-safe way.
 */

#define AV_RNA(s, p)    (((const av_alias##s*)(p))->u##s)
#define AV_WNA(s, p, v) (((av_alias##s*)(p))->u##s = (v))

#ifndef AV_RN16A
#   define AV_RN16A(p) AV_RNA(16, p)
#endif

#ifndef AV_RN32A
#   define AV_RN32A(p) AV_RNA(32, p)
#endif

#ifndef AV_RN64A
#   define AV_RN64A(p) AV_RNA(64, p)
#endif

#ifndef AV_WN16A
#   define AV_WN16A(p, v) AV_WNA(16, p, v)
#endif

#ifndef AV_WN32A
#   define AV_WN32A(p, v) AV_WNA(32, p, v)
#endif

#ifndef AV_WN64A
#   define AV_WN64A(p, v) AV_WNA(64, p, v)
#endif

#if AV_HAVE_BIGENDIAN
#   define AV_RLA(s, p)    av_bswap##s(AV_RN##s##A(p))
#   define AV_WLA(s, p, v) AV_WN##s##A(p, av_bswap##s(v))
#else
#   define AV_RLA(s, p)    AV_RN##s##A(p)
#   define AV_WLA(s, p, v) AV_WN##s##A(p, v)
#endif

#ifndef AV_RL64A
#   define AV_RL64A(p) AV_RLA(64, p)
#endif
#ifndef AV_WL64A
#   define AV_WL64A(p, v) AV_WLA(64, p, v)
#endif

/*
 * The AV_COPYxxU macros are suitable for copying data to/from unaligned
 * memory locations.
 */

#define AV_COPYU(n, d, s) AV_WN##n(d, AV_RN##n(s));

#ifndef AV_COPY16U
#   define AV_COPY16U(d, s) AV_COPYU(16, d, s)
#endif

#ifndef AV_COPY32U
#   define AV_COPY32U(d, s) AV_COPYU(32, d, s)
#endif

#ifndef AV_COPY64U
#   define AV_COPY64U(d, s) AV_COPYU(64, d, s)
#endif

#ifndef AV_COPY128U
#   define AV_COPY128U(d, s)                                    \
    do {                                                        \
        AV_COPY64U(d, s);                                       \
        AV_COPY64U((char *)(d) + 8, (const char *)(s) + 8);     \
    } while(0)
#endif

/* Parameters for AV_COPY*, AV_SWAP*, AV_ZERO* must be
 * naturally aligned. They may be implemented using MMX,
 * so emms_c() must be called before using any float code
 * afterwards.
 */

#define AV_COPY(n, d, s) \
    (((av_alias##n*)(d))->u##n = ((const av_alias##n*)(s))->u##n)

#ifndef AV_COPY16
#   define AV_COPY16(d, s) AV_COPY(16, d, s)
#endif

#ifndef AV_COPY32
#   define AV_COPY32(d, s) AV_COPY(32, d, s)
#endif

#ifndef AV_COPY64
#   define AV_COPY64(d, s) AV_COPY(64, d, s)
#endif

#ifndef AV_COPY128
#   define AV_COPY128(d, s)                    \
    do {                                       \
        AV_COPY64(d, s);                       \
        AV_COPY64((char*)(d)+8, (char*)(s)+8); \
    } while(0)
#endif

#define AV_SWAP(n, a, b) FFSWAP(av_alias##n, *(av_alias##n*)(a), *(av_alias##n*)(b))

#ifndef AV_SWAP64
#   define AV_SWAP64(a, b) AV_SWAP(64, a, b)
#endif

#define AV_ZERO(n, d) (((av_alias##n*)(d))->u##n = 0)

#ifndef AV_ZERO16
#   define AV_ZERO16(d) AV_ZERO(16, d)
#endif

#ifndef AV_ZERO32
#   define AV_ZERO32(d) AV_ZERO(32, d)
#endif

#ifndef AV_ZERO64
#   define AV_ZERO64(d) AV_ZERO(64, d)
#endif

#ifndef AV_ZERO128
#   define AV_ZERO128(d)         \
    do {                         \
        AV_ZERO64(d);            \
        AV_ZERO64((char*)(d)+8); \
    } while(0)
#endif


#define AV_RL32(p)    AV_RL(32, p)

#define ff_mutex_init    pthread_mutex_init
#define ff_mutex_lock    pthread_mutex_lock
#define ff_mutex_unlock  pthread_mutex_unlock
#define ff_mutex_destroy pthread_mutex_destroy

#define AVMutex pthread_mutex_t
#define AV_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER


static inline void av_write_bswap64(void *p, uint64_t v)
{
    __asm__ ("stdbrx  %1, %y0" : "=Z"(*(uint64_t*)p) : "r"(v));
}

#   if    defined(AV_RN16) && !defined(AV_RL16)
#       define AV_RL16(p) AV_RN16(p)
#   elif !defined(AV_RN16) &&  defined(AV_RL16)
#       define AV_RN16(p) AV_RL16(p)
#   endif

#   if    defined(AV_WN16) && !defined(AV_WL16)
#       define AV_WL16(p, v) AV_WN16(p, v)
#   elif !defined(AV_WN16) &&  defined(AV_WL16)
#       define AV_WN16(p, v) AV_WL16(p, v)
#   endif

#   if    defined(AV_RN24) && !defined(AV_RL24)
#       define AV_RL24(p) AV_RN24(p)
#   elif !defined(AV_RN24) &&  defined(AV_RL24)
#       define AV_RN24(p) AV_RL24(p)
#   endif

#   if    defined(AV_WN24) && !defined(AV_WL24)
#       define AV_WL24(p, v) AV_WN24(p, v)
#   elif !defined(AV_WN24) &&  defined(AV_WL24)
#       define AV_WN24(p, v) AV_WL24(p, v)
#   endif

#   if    defined(AV_RN32) && !defined(AV_RL32)
#       define AV_RL32(p) AV_RN32(p)
#   elif !defined(AV_RN32) &&  defined(AV_RL32)
#       define AV_RN32(p) AV_RL32(p)
#   endif

#   if    defined(AV_WN32) && !defined(AV_WL32)
#       define AV_WL32(p, v) AV_WN32(p, v)
#   elif !defined(AV_WN32) &&  defined(AV_WL32)
#       define AV_WN32(p, v) AV_WL32(p, v)
#   endif

#   if    defined(AV_RN48) && !defined(AV_RL48)
#       define AV_RL48(p) AV_RN48(p)
#   elif !defined(AV_RN48) &&  defined(AV_RL48)
#       define AV_RN48(p) AV_RL48(p)
#   endif

#   if    defined(AV_WN48) && !defined(AV_WL48)
#       define AV_WL48(p, v) AV_WN48(p, v)
#   elif !defined(AV_WN48) &&  defined(AV_WL48)
#       define AV_WN48(p, v) AV_WL48(p, v)
#   endif

#   if    defined(AV_RN64) && !defined(AV_RL64)
#       define AV_RL64(p) AV_RN64(p)
#   elif !defined(AV_RN64) &&  defined(AV_RL64)
#       define AV_RN64(p) AV_RL64(p)
#   endif

#   if    defined(AV_WN64) && !defined(AV_WL64)
#       define AV_WL64(p, v) AV_WN64(p, v)
#   elif !defined(AV_WN64) &&  defined(AV_WL64)
#       define AV_WN64(p, v) AV_WL64(p, v)
#   endif


#if ARCH_X86_64
// TODO: Benchmark and optionally enable on other 64-bit architectures.
typedef uint64_t BitBuf;
#define AV_WBBUF AV_WB64
#define AV_WLBUF AV_WL64
#else
typedef uint32_t BitBuf;
#define AV_WBBUF AV_WB32
#define AV_WLBUF AV_WL32
#endif


#if AV_HAVE_BIGENDIAN
#define av_be2ne16(x) (x)
#define av_be2ne32(x) (x)
#define av_be2ne64(x) (x)
#define av_le2ne16(x) av_bswap16(x)
#define av_le2ne32(x) av_bswap32(x)
#define av_le2ne64(x) av_bswap64(x)
#define AV_BE2NEC(s, x) (x)
#define AV_LE2NEC(s, x) AV_BSWAPC(s, x)
#else
#define av_be2ne16(x) av_bswap16(x)
#define av_be2ne32(x) av_bswap32(x)
#define av_be2ne64(x) av_bswap64(x)
#define av_le2ne16(x) (x)
#define av_le2ne32(x) (x)
#define av_le2ne64(x) (x)
#define AV_BE2NEC(s, x) AV_BSWAPC(s, x)
#define AV_LE2NEC(s, x) (x)
#endif

#define AV_BE2NE16C(x) AV_BE2NEC(16, x)
#define AV_BE2NE32C(x) AV_BE2NEC(32, x)
#define AV_BE2NE64C(x) AV_BE2NEC(64, x)
#define AV_LE2NE16C(x) AV_LE2NEC(16, x)
#define AV_LE2NE32C(x) AV_LE2NEC(32, x)
#define AV_LE2NE64C(x) AV_LE2NEC(64, x)

#define LIBAVRESAMPLE_VERSION_MAJOR  4
#define LIBAVRESAMPLE_VERSION_MINOR  0
#define LIBAVRESAMPLE_VERSION_MICRO  0

#define LIBAVRESAMPLE_VERSION_INT  AV_VERSION_INT(LIBAVRESAMPLE_VERSION_MAJOR, \
                                                  LIBAVRESAMPLE_VERSION_MINOR, \
                                                  LIBAVRESAMPLE_VERSION_MICRO)
#define LIBAVRESAMPLE_VERSION          AV_VERSION(LIBAVRESAMPLE_VERSION_MAJOR, \
                                                  LIBAVRESAMPLE_VERSION_MINOR, \
                                                  LIBAVRESAMPLE_VERSION_MICRO)
#define LIBAVRESAMPLE_BUILD        LIBAVRESAMPLE_VERSION_INT

#define LIBAVRESAMPLE_IDENT        "Lavr" AV_STRINGIFY(LIBAVRESAMPLE_VERSION)

#if defined(_WIN32) && CONFIG_SHARED && !defined(BUILDING_avcodec)
#    define av_export_avcodec __declspec(dllimport)
#else
#    define av_export_avcodec
#endif
#define AV_SUBTITLE_FLAG_FORCED 0x00000001
#define LIBAVFORMAT_VERSION_MAJOR 58
#define LIBAVFORMAT_VERSION_MINOR 63
#define LIBAVFORMAT_VERSION_MICRO 100
#define LIBAVFORMAT_VERSION_INT AV_VERSION_INT(LIBAVFORMAT_VERSION_MAJOR, LIBAVFORMAT_VERSION_MINOR, LIBAVFORMAT_VERSION_MICRO)
#define LIBAVFORMAT_VERSION AV_VERSION(LIBAVFORMAT_VERSION_MAJOR, LIBAVFORMAT_VERSION_MINOR, LIBAVFORMAT_VERSION_MICRO)
#define LIBAVFORMAT_BUILD LIBAVFORMAT_VERSION_INT
// #define LIBAVFORMAT_IDENT "Lavf" AV_STRINGIFY(LIBAVFORMAT_VERSION)
#define FF_API_COMPUTE_PKT_FIELDS2 (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_OLD_OPEN_CALLBACKS (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_LAVF_AVCTX (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_HTTP_USER_AGENT (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_HLS_WRAP (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_HLS_USE_LOCALTIME (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_LAVF_KEEPSIDE_FLAG (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_OLD_ROTATE_API (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_FORMAT_GET_SET (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_OLD_AVIO_EOF_0 (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_LAVF_FFSERVER (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_FORMAT_FILENAME (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_OLD_RTSP_OPTIONS (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_DASH_MIN_SEG_DURATION (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_LAVF_MP4A_LATM (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_AVIOFORMAT (LIBAVFORMAT_VERSION_MAJOR < 59)
#define FF_API_R_FRAME_RATE 1
#define AVIO_SEEKABLE_NORMAL (1 << 0)
#define AVIO_SEEKABLE_TIME (1 << 1)
#define AVSEEK_SIZE 0x10000
#define AVSEEK_FORCE 0x20000
#define AVIO_FLAG_READ 1
#define AVIO_FLAG_WRITE 2
#define AVIO_FLAG_READ_WRITE (AVIO_FLAG_READ | AVIO_FLAG_WRITE)
#define AVIO_FLAG_NONBLOCK 8
#define AVIO_FLAG_DIRECT 0x8000
#define AVPROBE_SCORE_RETRY (AVPROBE_SCORE_MAX / 4)
#define AVPROBE_SCORE_STREAM_RETRY (AVPROBE_SCORE_MAX / 4 - 1)
#define AVPROBE_SCORE_EXTENSION 50
#define AVPROBE_SCORE_MIME 75
#define AVPROBE_SCORE_MAX 100
#define AVPROBE_PADDING_SIZE 32
/// Demuxer will use avio_open, no opened file should be provided by the caller.
#define AVFMT_NOFILE 0x0001
#define AVFMT_NEEDNUMBER 0x0002
#define AVFMT_SHOW_IDS 0x0008
#define AVFMT_GLOBALHEADER 0x0040
#define AVFMT_NOTIMESTAMPS 0x0080
#define AVFMT_GENERIC_INDEX 0x0100
#define AVFMT_TS_DISCONT 0x0200
#define AVFMT_VARIABLE_FPS 0x0400
#define AVFMT_NODIMENSIONS 0x0800
#define AVFMT_NOSTREAMS 0x1000
#define AVFMT_NOBINSEARCH 0x2000
#define AVFMT_NOGENSEARCH 0x4000
#define AVFMT_NO_BYTE_SEEK 0x8000
#define AVFMT_ALLOW_FLUSH 0x10000
#define AVFMT_TS_NONSTRICT 0x20000
#define AVFMT_TS_NEGATIVE 0x40000
#define AVFMT_SEEK_TO_PTS 0x4000000
#define ff_const59
#define AVINDEX_KEYFRAME 0x0001
#define AVINDEX_DISCARD_FRAME 0x0002
#define AV_DISPOSITION_DEFAULT 0x0001
#define AV_DISPOSITION_DUB 0x0002
#define AV_DISPOSITION_ORIGINAL 0x0004
#define AV_DISPOSITION_COMMENT 0x0008
#define AV_DISPOSITION_LYRICS 0x0010
#define AV_DISPOSITION_KARAOKE 0x0020
#define AV_DISPOSITION_FORCED 0x0040
#define AV_DISPOSITION_HEARING_IMPAIRED 0x0080
#define AV_DISPOSITION_VISUAL_IMPAIRED 0x0100
#define AV_DISPOSITION_CLEAN_EFFECTS 0x0200
#define AV_DISPOSITION_ATTACHED_PIC 0x0400
#define AV_DISPOSITION_TIMED_THUMBNAILS 0x0800
#define AV_DISPOSITION_CAPTIONS 0x10000
#define AV_DISPOSITION_DESCRIPTIONS 0x20000
#define AV_DISPOSITION_METADATA 0x40000
#define AV_DISPOSITION_DEPENDENT 0x80000
#define AV_DISPOSITION_STILL_IMAGE 0x100000
#define AV_PTS_WRAP_IGNORE 0
#define AV_PTS_WRAP_ADD_OFFSET 1
#define AV_PTS_WRAP_SUB_OFFSET -1
#define AVSTREAM_EVENT_FLAG_METADATA_UPDATED 0x0001
#define MAX_STD_TIMEBASES (30 * 12 + 30 + 3 + 6)
#define MAX_REORDER_DELAY 16
#define AVOnce char
#define AV_ONCE_INIT 0
#define AV_PROGRAM_RUNNING 1
#define AVFMTCTX_NOHEADER 0x0001
#define AVFMTCTX_UNSEEKABLE 0x0002
#define AVFMT_FLAG_GENPTS 0x0001
#define AVFMT_FLAG_IGNIDX 0x0002
#define AVFMT_FLAG_NONBLOCK 0x0004
#define AVFMT_FLAG_IGNDTS 0x0008
#define AVFMT_FLAG_NOFILLIN 0x0010
#define AVFMT_FLAG_NOPARSE 0x0020
#define AVFMT_FLAG_NOBUFFER 0x0040
#define AVFMT_FLAG_CUSTOM_IO 0x0080
#define AVFMT_FLAG_DISCARD_CORRUPT 0x0100
#define AVFMT_FLAG_FLUSH_PACKETS 0x0200
#define AVFMT_FLAG_BITEXACT 0x0400
#define AVFMT_FLAG_MP4A_LATM 0x8000
#define AVFMT_FLAG_SORT_DTS 0x10000
#define AVFMT_FLAG_PRIV_OPT 0x20000
#define AVFMT_FLAG_KEEP_SIDE_DATA 0x40000
#define AVFMT_FLAG_FAST_SEEK 0x80000
#define AVFMT_FLAG_SHORTEST 0x100000
#define AVFMT_FLAG_AUTO_BSF 0x200000
#define FF_FDEBUG_TS 0x0001
#define AVFMT_EVENT_FLAG_METADATA_UPDATED 0x0001
#define AVFMT_AVOID_NEG_TS_AUTO -1
#define AVFMT_AVOID_NEG_TS_MAKE_NON_NEGATIVE 1
#define AVFMT_AVOID_NEG_TS_MAKE_ZERO 2

#define media_type_string av_get_media_type_string

void *grow_array(void *array, int elem_size, int *size, int new_size);
#define GROW_ARRAY(array, nb_elems) array = grow_array(array, sizeof(*array), &nb_elems, nb_elems + 1)

#define GET_PIX_FMT_NAME(pix_fmt)\
    const char *name = av_get_pix_fmt_name(pix_fmt);

#define GET_CODEC_NAME(id)\
    const char *name = avcodec_descriptor_get(id)->name;

#define GET_SAMPLE_FMT_NAME(sample_fmt)\
    const char *name = av_get_sample_fmt_name(sample_fmt)

#define GET_SAMPLE_RATE_NAME(rate)\
    char name[16];\
    snprintf(name, sizeof(name), "%d", rate);

#define GET_CH_LAYOUT_NAME(ch_layout)\
    char name[16];\
    snprintf(name, sizeof(name), "0x%"PRIx64, ch_layout);

#define GET_CH_LAYOUT_DESC(ch_layout)\
    char name[128];\
    av_get_channel_layout_string(name, sizeof(name), 0, ch_layout);

#define X86_AMD3DNOW(flags)         CPUEXT(flags, AMD3DNOW)
#define X86_AMD3DNOWEXT(flags)      CPUEXT(flags, AMD3DNOWEXT)
#define X86_MMX(flags)              CPUEXT(flags, MMX)
#define X86_MMXEXT(flags)           CPUEXT(flags, MMXEXT)
#define X86_SSE(flags)              CPUEXT(flags, SSE)
#define X86_SSE2(flags)             CPUEXT(flags, SSE2)
#define X86_SSE2_FAST(flags)        CPUEXT_FAST(flags, SSE2)
#define X86_SSE2_SLOW(flags)        CPUEXT_SLOW(flags, SSE2)
#define X86_SSE3(flags)             CPUEXT(flags, SSE3)
#define X86_SSE3_FAST(flags)        CPUEXT_FAST(flags, SSE3)
#define X86_SSE3_SLOW(flags)        CPUEXT_SLOW(flags, SSE3)
#define X86_SSSE3(flags)            CPUEXT(flags, SSSE3)
#define X86_SSSE3_FAST(flags)       CPUEXT_FAST(flags, SSSE3)
#define X86_SSSE3_SLOW(flags)       CPUEXT_SLOW(flags, SSSE3)
#define X86_SSE4(flags)             CPUEXT(flags, SSE4)
#define X86_SSE42(flags)            CPUEXT(flags, SSE42)
#define X86_AVX(flags)              CPUEXT(flags, AVX)
#define X86_AVX_FAST(flags)         CPUEXT_FAST(flags, AVX)
#define X86_AVX_SLOW(flags)         CPUEXT_SLOW(flags, AVX)
#define X86_XOP(flags)              CPUEXT(flags, XOP)
#define X86_FMA3(flags)             CPUEXT(flags, FMA3)
#define X86_FMA4(flags)             CPUEXT(flags, FMA4)
#define X86_AVX2(flags)             CPUEXT(flags, AVX2)
#define X86_AESNI(flags)            CPUEXT(flags, AESNI)
#define X86_AVX512(flags)           CPUEXT(flags, AVX512)

#define CPUEXT_SUFFIX(flags, suffix, cpuext)                            \
    (HAVE_ ## cpuext ## suffix && ((flags) & AV_CPU_FLAG_ ## cpuext))

#define CPUEXT_SUFFIX_FAST2(flags, suffix, cpuext, slow_cpuext)         \
    (HAVE_ ## cpuext ## suffix && ((flags) & AV_CPU_FLAG_ ## cpuext) && \
     !((flags) & AV_CPU_FLAG_ ## slow_cpuext ## SLOW))

#define CPUEXT_SUFFIX_SLOW2(flags, suffix, cpuext, slow_cpuext)         \
    (HAVE_ ## cpuext ## suffix && ((flags) & AV_CPU_FLAG_ ## cpuext) && \
     ((flags) & AV_CPU_FLAG_ ## slow_cpuext ## SLOW))

#define CPUEXT_SUFFIX_FAST(flags, suffix, cpuext) CPUEXT_SUFFIX_FAST2(flags, suffix, cpuext, cpuext)
#define CPUEXT_SUFFIX_SLOW(flags, suffix, cpuext) CPUEXT_SUFFIX_SLOW2(flags, suffix, cpuext, cpuext)

#define CPUEXT(flags, cpuext) CPUEXT_SUFFIX(flags, , cpuext)
#define CPUEXT_FAST(flags, cpuext) CPUEXT_SUFFIX_FAST(flags, , cpuext)
#define CPUEXT_SLOW(flags, cpuext) CPUEXT_SUFFIX_SLOW(flags, , cpuext)

#define EXTERNAL_AMD3DNOW(flags)    CPUEXT_SUFFIX(flags, _EXTERNAL, AMD3DNOW)
#define EXTERNAL_AMD3DNOWEXT(flags) CPUEXT_SUFFIX(flags, _EXTERNAL, AMD3DNOWEXT)
#define EXTERNAL_MMX(flags)         CPUEXT_SUFFIX(flags, _EXTERNAL, MMX)
#define EXTERNAL_MMXEXT(flags)      CPUEXT_SUFFIX(flags, _EXTERNAL, MMXEXT)
#define EXTERNAL_SSE(flags)         CPUEXT_SUFFIX(flags, _EXTERNAL, SSE)
#define EXTERNAL_SSE2(flags)        CPUEXT_SUFFIX(flags, _EXTERNAL, SSE2)
#define EXTERNAL_SSE2_FAST(flags)   CPUEXT_SUFFIX_FAST(flags, _EXTERNAL, SSE2)
#define EXTERNAL_SSE2_SLOW(flags)   CPUEXT_SUFFIX_SLOW(flags, _EXTERNAL, SSE2)
#define EXTERNAL_SSE3(flags)        CPUEXT_SUFFIX(flags, _EXTERNAL, SSE3)
#define EXTERNAL_SSE3_FAST(flags)   CPUEXT_SUFFIX_FAST(flags, _EXTERNAL, SSE3)
#define EXTERNAL_SSE3_SLOW(flags)   CPUEXT_SUFFIX_SLOW(flags, _EXTERNAL, SSE3)
#define EXTERNAL_SSSE3(flags)       CPUEXT_SUFFIX(flags, _EXTERNAL, SSSE3)
#define EXTERNAL_SSSE3_FAST(flags)  CPUEXT_SUFFIX_FAST(flags, _EXTERNAL, SSSE3)
#define EXTERNAL_SSSE3_SLOW(flags)  CPUEXT_SUFFIX_SLOW(flags, _EXTERNAL, SSSE3)
#define EXTERNAL_SSE4(flags)        CPUEXT_SUFFIX(flags, _EXTERNAL, SSE4)
#define EXTERNAL_SSE42(flags)       CPUEXT_SUFFIX(flags, _EXTERNAL, SSE42)
#define EXTERNAL_AVX(flags)         CPUEXT_SUFFIX(flags, _EXTERNAL, AVX)
#define EXTERNAL_AVX_FAST(flags)    CPUEXT_SUFFIX_FAST(flags, _EXTERNAL, AVX)
#define EXTERNAL_AVX_SLOW(flags)    CPUEXT_SUFFIX_SLOW(flags, _EXTERNAL, AVX)
#define EXTERNAL_XOP(flags)         CPUEXT_SUFFIX(flags, _EXTERNAL, XOP)
#define EXTERNAL_FMA3(flags)        CPUEXT_SUFFIX(flags, _EXTERNAL, FMA3)
#define EXTERNAL_FMA3_FAST(flags)   CPUEXT_SUFFIX_FAST2(flags, _EXTERNAL, FMA3, AVX)
#define EXTERNAL_FMA3_SLOW(flags)   CPUEXT_SUFFIX_SLOW2(flags, _EXTERNAL, FMA3, AVX)
#define EXTERNAL_FMA4(flags)        CPUEXT_SUFFIX(flags, _EXTERNAL, FMA4)
#define EXTERNAL_AVX2(flags)        CPUEXT_SUFFIX(flags, _EXTERNAL, AVX2)
#define EXTERNAL_AVX2_FAST(flags)   CPUEXT_SUFFIX_FAST2(flags, _EXTERNAL, AVX2, AVX)
#define EXTERNAL_AVX2_SLOW(flags)   CPUEXT_SUFFIX_SLOW2(flags, _EXTERNAL, AVX2, AVX)
#define EXTERNAL_AESNI(flags)       CPUEXT_SUFFIX(flags, _EXTERNAL, AESNI)
#define EXTERNAL_AVX512(flags)      CPUEXT_SUFFIX(flags, _EXTERNAL, AVX512)

#define INLINE_AMD3DNOW(flags)      CPUEXT_SUFFIX(flags, _INLINE, AMD3DNOW)
#define INLINE_AMD3DNOWEXT(flags)   CPUEXT_SUFFIX(flags, _INLINE, AMD3DNOWEXT)
#define INLINE_MMX(flags)           CPUEXT_SUFFIX(flags, _INLINE, MMX)
#define INLINE_MMXEXT(flags)        CPUEXT_SUFFIX(flags, _INLINE, MMXEXT)
#define INLINE_SSE(flags)           CPUEXT_SUFFIX(flags, _INLINE, SSE)
#define INLINE_SSE2(flags)          CPUEXT_SUFFIX(flags, _INLINE, SSE2)
#define INLINE_SSE2_FAST(flags)     CPUEXT_SUFFIX_FAST(flags, _INLINE, SSE2)
#define INLINE_SSE2_SLOW(flags)     CPUEXT_SUFFIX_SLOW(flags, _INLINE, SSE2)
#define INLINE_SSE3(flags)          CPUEXT_SUFFIX(flags, _INLINE, SSE3)
#define INLINE_SSE3_FAST(flags)     CPUEXT_SUFFIX_FAST(flags, _INLINE, SSE3)
#define INLINE_SSE3_SLOW(flags)     CPUEXT_SUFFIX_SLOW(flags, _INLINE, SSE3)
#define INLINE_SSSE3(flags)         CPUEXT_SUFFIX(flags, _INLINE, SSSE3)
#define INLINE_SSSE3_FAST(flags)    CPUEXT_SUFFIX_FAST(flags, _INLINE, SSSE3)
#define INLINE_SSSE3_SLOW(flags)    CPUEXT_SUFFIX_SLOW(flags, _INLINE, SSSE3)
#define INLINE_SSE4(flags)          CPUEXT_SUFFIX(flags, _INLINE, SSE4)
#define INLINE_SSE42(flags)         CPUEXT_SUFFIX(flags, _INLINE, SSE42)
#define INLINE_AVX(flags)           CPUEXT_SUFFIX(flags, _INLINE, AVX)
#define INLINE_AVX_FAST(flags)      CPUEXT_SUFFIX_FAST(flags, _INLINE, AVX)
#define INLINE_AVX_SLOW(flags)      CPUEXT_SUFFIX_SLOW(flags, _INLINE, AVX)
#define INLINE_XOP(flags)           CPUEXT_SUFFIX(flags, _INLINE, XOP)
#define INLINE_FMA3(flags)          CPUEXT_SUFFIX(flags, _INLINE, FMA3)
#define INLINE_FMA4(flags)          CPUEXT_SUFFIX(flags, _INLINE, FMA4)
#define INLINE_AVX2(flags)          CPUEXT_SUFFIX(flags, _INLINE, AVX2)
#define INLINE_AESNI(flags)         CPUEXT_SUFFIX(flags, _INLINE, AESNI)


static AVMutex avformat_mutex = AV_MUTEX_INITIALIZER;

typedef struct AVRational
{
    int num; ///< Numerator
    int den; ///< Denominator
} AVRational;




static inline size_t av_strnlen(const char *s, size_t len)
{
    size_t i;
    for (i = 0; i < len && s[i]; i++)
        ;
    return i;
}

static inline int av_isdigit(int c)
{
    return c >= '0' && c <= '9';
}

static inline int av_isgraph(int c)
{
    return c > 32 && c < 127;
}

static inline int av_isspace(int c)
{
    return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
}

static inline int av_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c ^= 0x20;
    return c;
}

static inline int av_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c ^= 0x20;
    return c;
}

static inline int av_isxdigit(int c)
{
    c = av_tolower(c);
    return av_isdigit(c) || (c >= 'a' && c <= 'f');
}

static inline int ff_thread_once(char *control, void (*routine)(void))
{
    if (!*control) {
        routine();
        *control = 1;
    }
    return 0;
}

typedef enum
{
    SDL_POWERSTATE_UNKNOWN,
    SDL_POWERSTATE_ON_BATTERY,
    SDL_POWERSTATE_NO_BATTERY,
    SDL_POWERSTATE_CHARGING,
    SDL_POWERSTATE_CHARGED
} SDL_PowerState;

extern SDL_PowerState SDL_GetPowerInfo(int *secs, int *pct);

typedef enum
{
    SDL_RENDERER_SOFTWARE = 0x00000001,
    SDL_RENDERER_ACCELERATED = 0x00000002,
    SDL_RENDERER_PRESENTVSYNC = 0x00000004,
    SDL_RENDERER_TARGETTEXTURE = 0x00000008
} SDL_RendererFlags;

typedef struct SDL_RendererInfo
{
    const char *name;
    uint32_t flags;
    uint32_t num_texture_formats;
    uint32_t texture_formats[16];
    int max_texture_width;
    int max_texture_height;
} SDL_RendererInfo;

typedef enum
{
    SDL_ScaleModeNearest,
    SDL_ScaleModeLinear,
    SDL_ScaleModeBest
} SDL_ScaleMode;

typedef enum
{
    SDL_TEXTUREACCESS_STATIC,
    SDL_TEXTUREACCESS_STREAMING,
    SDL_TEXTUREACCESS_TARGET
} SDL_TextureAccess;

typedef enum
{
    SDL_TEXTUREMODULATE_NONE = 0x00000000,
    SDL_TEXTUREMODULATE_COLOR = 0x00000001,
    SDL_TEXTUREMODULATE_ALPHA = 0x00000002
} SDL_TextureModulate;

typedef enum
{
    SDL_FLIP_NONE = 0x00000000,
    SDL_FLIP_HORIZONTAL = 0x00000001,
    SDL_FLIP_VERTICAL = 0x00000002
} SDL_RendererFlip;
typedef struct SpecifierOpt
{
    char *specifier;
    union
    {
        uint8_t *str;
        int i;
        int64_t i64;
        uint64_t ui64;
        float f;
        double dbl;
    } u;
} SpecifierOpt;

typedef struct OptionDef
{
    const char *name;
    int flags;
    union
    {
        void *dst_ptr;
        int (*func_arg)(void *, const char *, const char *);
        size_t off;
    } u;
    const char *help;
    const char *argname;
} OptionDef;
typedef struct Option
{
    const OptionDef *opt;
    const char *key;
    const char *val;
} Option;

typedef struct OptionGroupDef
{
    const char *name;
    const char *sep;
    int flags;
} OptionGroupDef;

struct AVOptionRanges;
typedef struct AVExpr AVExpr;

typedef struct AVClass
{
    const char *class_name;
    const char *(*item_name)(void *ctx);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *obj, void *prev);
    const struct AVClass *(*child_class_next)(const struct AVClass *prev);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *ctx);
    int (*query_ranges)(struct AVOptionRanges **, void *obj, const char *key, int flags);
    const struct AVClass *(*child_class_iterate)(void **iter);
} AVClass;
typedef struct AVComponentDescriptor
{
    int plane;
    int step;
    int offset;
    int shift;
    int depth;
    int step_minus1;
    int depth_minus1;
    int offset_plus1;
} AVComponentDescriptor;

typedef struct AVPixFmtDescriptor
{
    const char *name;
    uint8_t nb_components; ///< The number of components each pixel has, (1-4)
    uint8_t log2_chroma_w;
    uint8_t log2_chroma_h;
    uint64_t flags;
    AVComponentDescriptor comp[4];
    const char *alias;
} AVPixFmtDescriptor;
enum AVFieldOrder
{
    AV_FIELD_UNKNOWN,
    AV_FIELD_PROGRESSIVE,
    AV_FIELD_TT, //< Top coded_first, top displayed first
    AV_FIELD_BB, //< Bottom coded first, bottom displayed first
    AV_FIELD_TB, //< Top coded first, bottom displayed first
    AV_FIELD_BT, //< Bottom coded first, top displayed first
};

typedef struct AVCodecParameters
{
    enum AVMediaType codec_type;
    enum AVCodecID codec_id;
    uint32_t codec_tag;
    uint8_t *extradata;
    int extradata_size;
    int format;
    int64_t bit_rate;
    int bits_per_coded_sample;
    int bits_per_raw_sample;
    int profile;
    int level;
    int width;
    int height;
    AVRational sample_aspect_ratio;
    enum AVFieldOrder field_order;
    enum AVColorRange color_range;
    enum AVColorPrimaries color_primaries;
    enum AVColorTransferCharacteristic color_trc;
    enum AVColorSpace color_space;
    enum AVChromaLocation chroma_location;
    int video_delay;
    uint64_t channel_layout;
    int channels;
    int sample_rate;
    int block_align;
    int frame_size;
    int initial_padding;
    int trailing_padding;
    int seek_preroll;
} AVCodecParameters;

typedef struct AVDictionaryEntry
{
    char *key;
    char *value;
} AVDictionaryEntry;

typedef struct AVDictionary AVDictionary;

struct ff_pad_helper_AVBPrint
{
    char *str;
    unsigned len;
    unsigned size;
    unsigned size_max;
    char reserved_internal_buffer[1];
};
typedef struct AVBPrint
{
    char *str;
    unsigned len;
    unsigned size;
    unsigned size_max;
    char reserved_internal_buffer[1];
    char reserved_padding[1024 - sizeof(struct ff_pad_helper_AVBPrint)];
} AVBPrint;
typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef
{
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;
typedef struct AVFrameSideData
{
    enum AVFrameSideDataType type;
    uint8_t *data;
    int size;
    AVDictionary *metadata;
    AVBufferRef *buf;
} AVFrameSideData;

typedef struct AVRegionOfInterest
{
    uint32_t self_size;
    int top;
    int bottom;
    int left;
    int right;
    AVRational qoffset;
} AVRegionOfInterest;
typedef struct AVFrame
{
    uint8_t *data[8];
    int linesize[8];
    uint8_t **extended_data;
    int width, height;
    int nb_samples;
    int format;
    int key_frame;
    enum AVPictureType pict_type;
    AVRational sample_aspect_ratio;
    int64_t pts;
    int64_t pkt_pts;
    int64_t pkt_dts;
    int coded_picture_number;
    int display_picture_number;
    int quality;
    void *opaque;
    uint64_t error[8];
    int repeat_pict;
    int interlaced_frame;
    int top_field_first;
    int palette_has_changed;
    int64_t reordered_opaque;
    int sample_rate;
    uint64_t channel_layout;
    AVBufferRef *buf[8];
    AVBufferRef **extended_buf;
    int nb_extended_buf;
    AVFrameSideData **side_data;
    int nb_side_data;
    int flags;
    enum AVColorRange color_range;
    enum AVColorPrimaries color_primaries;
    enum AVColorTransferCharacteristic color_trc;
    enum AVColorSpace colorspace;
    enum AVChromaLocation chroma_location;
    int64_t best_effort_timestamp;
    int64_t pkt_pos;
    int64_t pkt_duration;
    AVDictionary *metadata;
    int decode_error_flags;
    int channels;
    int pkt_size;
    int8_t *qscale_table;
    int qstride;
    int qscale_type;
    AVBufferRef *qp_table_buf;
    AVBufferRef *hw_frames_ctx;
    AVBufferRef *opaque_ref;
    size_t crop_top;
    size_t crop_bottom;
    size_t crop_left;
    size_t crop_right;
    AVBufferRef *private_ref;
} AVFrame;
typedef struct OptionGroup
{
    const OptionGroupDef *group_def;
    const char *arg;
    Option *opts;
    int nb_opts;
    AVDictionary *codec_opts;
    AVDictionary *format_opts;
    AVDictionary *resample_opts;
    AVDictionary *sws_dict;
    AVDictionary *swr_opts;
} OptionGroup;

typedef struct OptionGroupList
{
    const OptionGroupDef *group_def;
    OptionGroup *groups;
    int nb_groups;
} OptionGroupList;

typedef struct OptionParseContext
{
    OptionGroup global_opts;
    OptionGroupList *groups;
    int nb_groups;
    OptionGroup cur_group;
} OptionParseContext;
enum
{
    AV_CODEC_HW_CONFIG_METHOD_HW_DEVICE_CTX = 0x01,
    AV_CODEC_HW_CONFIG_METHOD_HW_FRAMES_CTX = 0x02,
    AV_CODEC_HW_CONFIG_METHOD_INTERNAL = 0x04,
    AV_CODEC_HW_CONFIG_METHOD_AD_HOC = 0x08,
};
enum
{
    AV_FRAME_CROP_UNALIGNED = 1 << 0,
};
enum AVHWDeviceType
{
    AV_HWDEVICE_TYPE_NONE,
    AV_HWDEVICE_TYPE_VDPAU,
    AV_HWDEVICE_TYPE_CUDA,
    AV_HWDEVICE_TYPE_VAAPI,
    AV_HWDEVICE_TYPE_DXVA2,
    AV_HWDEVICE_TYPE_QSV,
    AV_HWDEVICE_TYPE_VIDEOTOOLBOX,
    AV_HWDEVICE_TYPE_D3D11VA,
    AV_HWDEVICE_TYPE_DRM,
    AV_HWDEVICE_TYPE_OPENCL,
    AV_HWDEVICE_TYPE_MEDIACODEC,
    AV_HWDEVICE_TYPE_VULKAN,
};

typedef struct AVHWDeviceInternal AVHWDeviceInternal;
typedef struct AVHWDeviceContext
{
    const AVClass *av_class;
    AVHWDeviceInternal *internal;
    enum AVHWDeviceType type;
    void *hwctx;
    void (*free)(struct AVHWDeviceContext *ctx);
    void *user_opaque;
} AVHWDeviceContext;

typedef struct AVHWFramesInternal AVHWFramesInternal;
typedef struct AVBufferPool AVBufferPool;

typedef struct AVHWFramesContext
{
    const AVClass *av_class;
    AVHWFramesInternal *internal;
    AVBufferRef *device_ref;
    AVHWDeviceContext *device_ctx;
    void *hwctx;
    void (*free)(struct AVHWFramesContext *ctx);
    void *user_opaque;
    AVBufferPool *pool;
    int initial_pool_size;
    enum AVPixelFormat format;
    enum AVPixelFormat sw_format;
    int width, height;
} AVHWFramesContext;
typedef struct AVCodecHWConfig
{
    enum AVPixelFormat pix_fmt;
    int methods;
    enum AVHWDeviceType device_type;
} AVCodecHWConfig;
typedef struct AVCodecDescriptor
{
    enum AVCodecID id;
    enum AVMediaType type;
    const char *name;
    const char *long_name;
    int props;
    const char *const *mime_types;
    const struct AVProfile *profiles;
} AVCodecDescriptor;
enum AVDiscard
{
    AVDISCARD_NONE = -16,    ///< discard nothing
    AVDISCARD_DEFAULT = 0,   ///< discard useless packets like 0 size packets in avi
    AVDISCARD_NONREF = 8,    ///< discard all non reference
    AVDISCARD_BIDIR = 16,    ///< discard all bidirectional frames
    AVDISCARD_NONINTRA = 24, ///< discard all non intra frames
    AVDISCARD_NONKEY = 32,   ///< discard all frames except keyframes
    AVDISCARD_ALL = 48,      ///< discard all
};

enum AVAudioServiceType
{
    AV_AUDIO_SERVICE_TYPE_MAIN = 0,
    AV_AUDIO_SERVICE_TYPE_EFFECTS = 1,
    AV_AUDIO_SERVICE_TYPE_VISUALLY_IMPAIRED = 2,
    AV_AUDIO_SERVICE_TYPE_HEARING_IMPAIRED = 3,
    AV_AUDIO_SERVICE_TYPE_DIALOGUE = 4,
    AV_AUDIO_SERVICE_TYPE_COMMENTARY = 5,
    AV_AUDIO_SERVICE_TYPE_EMERGENCY = 6,
    AV_AUDIO_SERVICE_TYPE_VOICE_OVER = 7,
    AV_AUDIO_SERVICE_TYPE_KARAOKE = 8,
    AV_AUDIO_SERVICE_TYPE_NB, ///< Not part of ABI
};

typedef struct RcOverride
{
    int start_frame;
    int end_frame;
    int qscale; // If this is 0 then quality_factor will be used instead.
    float quality_factor;
} RcOverride;
enum AVPacketSideDataType
{
    AV_PKT_DATA_PALETTE,
    AV_PKT_DATA_NEW_EXTRADATA,
    AV_PKT_DATA_PARAM_CHANGE,
    AV_PKT_DATA_H263_MB_INFO,
    AV_PKT_DATA_REPLAYGAIN,
    AV_PKT_DATA_DISPLAYMATRIX,
    AV_PKT_DATA_STEREO3D,
    AV_PKT_DATA_AUDIO_SERVICE_TYPE,
    AV_PKT_DATA_QUALITY_STATS,
    AV_PKT_DATA_FALLBACK_TRACK,
    AV_PKT_DATA_CPB_PROPERTIES,
    AV_PKT_DATA_SKIP_SAMPLES,
    AV_PKT_DATA_JP_DUALMONO,
    AV_PKT_DATA_STRINGS_METADATA,
    AV_PKT_DATA_SUBTITLE_POSITION,
    AV_PKT_DATA_MATROSKA_BLOCKADDITIONAL,
    AV_PKT_DATA_WEBVTT_IDENTIFIER,
    AV_PKT_DATA_WEBVTT_SETTINGS,
    AV_PKT_DATA_METADATA_UPDATE,
    AV_PKT_DATA_MPEGTS_STREAM_ID,
    AV_PKT_DATA_MASTERING_DISPLAY_METADATA,
    AV_PKT_DATA_SPHERICAL,
    AV_PKT_DATA_CONTENT_LIGHT_LEVEL,
    AV_PKT_DATA_A53_CC,
    AV_PKT_DATA_ENCRYPTION_INIT_INFO,
    AV_PKT_DATA_ENCRYPTION_INFO,
    AV_PKT_DATA_AFD,
    AV_PKT_DATA_PRFT,
    AV_PKT_DATA_ICC_PROFILE,
    AV_PKT_DATA_DOVI_CONF,
    AV_PKT_DATA_S12M_TIMECODE,
    AV_PKT_DATA_NB
};
enum AVSideDataParamChangeFlags
{
    AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_COUNT = 0x0001,
    AV_SIDE_DATA_PARAM_CHANGE_CHANNEL_LAYOUT = 0x0002,
    AV_SIDE_DATA_PARAM_CHANGE_SAMPLE_RATE = 0x0004,
    AV_SIDE_DATA_PARAM_CHANGE_DIMENSIONS = 0x0008,
};
enum AVSubtitleType
{
    SUBTITLE_NONE,
    SUBTITLE_BITMAP, ///< A bitmap, pict will be set
    SUBTITLE_TEXT,
    SUBTITLE_ASS,
};
typedef enum
{
    SDL_THREAD_PRIORITY_LOW,
    SDL_THREAD_PRIORITY_NORMAL,
    SDL_THREAD_PRIORITY_HIGH,
    SDL_THREAD_PRIORITY_TIME_CRITICAL
} SDL_ThreadPriority;
enum
{
    AV_SYNC_AUDIO_MASTER,
    AV_SYNC_VIDEO_MASTER,
    AV_SYNC_EXTERNAL_CLOCK,
};
enum ShowMode
{
    SHOW_MODE_NONE = -1,
    SHOW_MODE_VIDEO = 0,
    SHOW_MODE_WAVES,
    SHOW_MODE_RDFT,
    SHOW_MODE_NB
};
enum AVDurationEstimationMethod
{
    AVFMT_DURATION_FROM_PTS,    ///< Duration accurately estimated from PTSes
    AVFMT_DURATION_FROM_STREAM, ///< Duration estimated from a stream with a known duration
    AVFMT_DURATION_FROM_BITRATE ///< Duration estimated from bitrate (less accurate)
};
enum AVIODirEntryType
{
    AVIO_ENTRY_UNKNOWN,
    AVIO_ENTRY_BLOCK_DEVICE,
    AVIO_ENTRY_CHARACTER_DEVICE,
    AVIO_ENTRY_DIRECTORY,
    AVIO_ENTRY_NAMED_PIPE,
    AVIO_ENTRY_SYMBOLIC_LINK,
    AVIO_ENTRY_SOCKET,
    AVIO_ENTRY_FILE,
    AVIO_ENTRY_SERVER,
    AVIO_ENTRY_SHARE,
    AVIO_ENTRY_WORKGROUP,
};

typedef struct AVBSFInternal AVBSFInternal;

typedef struct AVBSFContext
{
    const AVClass *av_class;
    const struct AVBitStreamFilter *filter;
    AVBSFInternal *internal;
    void *priv_data;
    AVCodecParameters *par_in;
    AVCodecParameters *par_out;
    AVRational time_base_in;
    AVRational time_base_out;
} AVBSFContext;
typedef struct AVPacketSideData
{
    uint8_t *data;
    int size;
    enum AVPacketSideDataType type;
} AVPacketSideData;
typedef struct AVPacket
{
    AVBufferRef *buf;
    int64_t pts;
    int64_t dts;
    uint8_t *data;
    int size;
    int stream_index;
    int flags;
    AVPacketSideData *side_data;
    int side_data_elems;
    int64_t duration;
    int64_t pos; ///< byte position in stream, -1 if unknown
    int64_t convergence_duration;
} AVPacket;

typedef struct AVBitStreamFilter
{
    const char *name;
    const enum AVCodecID *codec_ids;
    const AVClass *priv_class;
    int priv_data_size;
    int (*init)(AVBSFContext *ctx);
    int (*filter)(AVBSFContext *ctx, AVPacket *pkt);
    void (*close)(AVBSFContext *ctx);
    void (*flush)(AVBSFContext *ctx);
} AVBitStreamFilter;

typedef struct AVProfile
{
    int profile;
    const char *name; ///< short name for the profile
} AVProfile;

typedef struct AVCodecDefault AVCodecDefault;

struct MpegEncContext;
typedef struct AVCodecContext AVCodecContext;
typedef struct AVHWAccel
{
    const char *name;
    enum AVMediaType type;
    enum AVCodecID id;
    enum AVPixelFormat pix_fmt;
    int capabilities;
    int (*alloc_frame)(AVCodecContext *avctx, AVFrame *frame);
    int (*start_frame)(AVCodecContext *avctx, const uint8_t *buf, uint32_t buf_size);
    int (*decode_params)(AVCodecContext *avctx, int type, const uint8_t *buf, uint32_t buf_size);
    int (*decode_slice)(AVCodecContext *avctx, const uint8_t *buf, uint32_t buf_size);
    int (*end_frame)(AVCodecContext *avctx);
    int frame_priv_data_size;
    void (*decode_mb)(struct MpegEncContext *s);
    int (*init)(AVCodecContext *avctx);
    int (*uninit)(AVCodecContext *avctx);
    int priv_data_size;
    int caps_internal;
    int (*frame_params)(AVCodecContext *avctx, AVBufferRef *hw_frames_ctx);
} AVHWAccel;

typedef struct AVPicture
{
    uint8_t *data[8]; ///< pointers to the image data planes
    int linesize[8];  ///< number of bytes per line
} AVPicture;


typedef struct AVSubtitleRect
{
    int x;         ///< top left corner  of pict, undefined when pict is not set
    int y;         ///< top left corner  of pict, undefined when pict is not set
    int w;         ///< width            of pict, undefined when pict is not set
    int h;         ///< height           of pict, undefined when pict is not set
    int nb_colors; ///< number of colors in pict, undefined when pict is not set
    AVPicture pict;
    uint8_t *data[4];
    int linesize[4];
    enum AVSubtitleType type;
    char *text; ///< 0 terminated plain UTF-8 text
    char *ass;
    int flags;
} AVSubtitleRect;

typedef struct AVSubtitle
{
    uint16_t format;
    uint32_t start_display_time;
    uint32_t end_display_time;
    unsigned num_rects;
    AVSubtitleRect **rects;
    int64_t pts; ///< Same as packet pts, in AV_TIME_BASE
} AVSubtitle;

typedef struct AVCodec
{
    const char *name;
    const char *long_name;
    enum AVMediaType type;
    enum AVCodecID id;
    int capabilities;
    const AVRational *supported_framerates; ///< array of supported framerates, or NULL if any, array is terminated by {0,0}
    const enum AVPixelFormat *pix_fmts;     ///< array of supported pixel formats, or NULL if unknown, array is terminated by -1
    const int *supported_samplerates;       ///< array of supported audio samplerates, or NULL if unknown, array is terminated by 0
    const enum AVSampleFormat *sample_fmts; ///< array of supported sample formats, or NULL if unknown, array is terminated by -1
    const uint64_t *channel_layouts;        ///< array of support channel layouts, or NULL if unknown. array is terminated by 0
    uint8_t max_lowres;                     ///< maximum value for lowres supported by the decoder
    const AVClass *priv_class;              ///< AVClass for the private context
    const AVProfile *profiles;              ///< array of recognized profiles, or NULL if unknown, array is terminated by {FF_PROFILE_UNKNOWN}
    const char *wrapper_name;
    int priv_data_size;
    struct AVCodec *next;
    int (*update_thread_context)(struct AVCodecContext *dst, const struct AVCodecContext *src);
    const AVCodecDefault *defaults;
    void (*init_static_data)(struct AVCodec *codec);
    int (*init)(struct AVCodecContext *);
    int (*encode_sub)(struct AVCodecContext *, uint8_t *buf, int buf_size,
                      const struct AVSubtitle *sub);
    int (*encode2)(struct AVCodecContext *avctx, struct AVPacket *avpkt,
                   const struct AVFrame *frame, int *got_packet_ptr);
    int (*decode)(struct AVCodecContext *, void *outdata, int *outdata_size, struct AVPacket *avpkt);
    int (*close)(struct AVCodecContext *);
    int (*receive_packet)(struct AVCodecContext *avctx, struct AVPacket *avpkt);
    int (*receive_frame)(struct AVCodecContext *avctx, struct AVFrame *frame);
    void (*flush)(struct AVCodecContext *);
    int caps_internal;
    const char *bsfs;
    const struct AVCodecHWConfigInternal **hw_configs;
    const uint32_t *codec_tags;
} AVCodec;



typedef struct AVPacketList
{
    AVPacket pkt;
    struct AVPacketList *next;
} AVPacketList;
typedef struct MyAVPacketList
{
    AVPacket pkt;
    struct MyAVPacketList *next;
    int serial;
} MyAVPacketList;
struct SDL_mutex;
typedef struct SDL_mutex SDL_mutex;
struct SDL_semaphore;
typedef struct SDL_semaphore SDL_sem;
struct SDL_Thread;
typedef struct SDL_Thread SDL_Thread;

typedef unsigned long SDL_threadID;

typedef unsigned int SDL_TLSID;
typedef struct SDL_cond SDL_cond;
typedef struct PacketQueue
{
    MyAVPacketList *first_pkt, *last_pkt;
    int nb_packets;
    int size;
    int64_t duration;
    int abort_request;
    int serial;
    SDL_mutex *mutex;
    SDL_cond *cond;
} PacketQueue;


typedef struct AudioParams
{
    int freq;
    int channels;
    int64_t channel_layout;
    enum AVSampleFormat fmt;
    int frame_size;
    int bytes_per_sec;
} AudioParams;

typedef struct Clock
{
    double pts;
    double pts_drift;
    double last_updated;
    double speed;
    int serial;
    int paused;
    int *queue_serial;
} Clock;

typedef struct Frame
{
    AVFrame *frame;
    AVSubtitle sub;
    int serial;
    double pts;
    double duration;
    int64_t pos;
    int width;
    int height;
    int format;
    AVRational sar;
    int uploaded;
    int flip_v;
} Frame;

typedef struct FrameQueue
{
    Frame queue[((9) > (((3) > (16) ? (3) : (16))) ? (9) : (((3) > (16) ? (3) : (16))))];
    int rindex;
    int windex;
    int size;
    int max_size;
    int keep_last;
    int rindex_shown;
    SDL_mutex *mutex;
    SDL_cond *cond;
    PacketQueue *pktq;
} FrameQueue;


typedef struct Decoder
{
    AVPacket pkt;
    PacketQueue *queue;
    AVCodecContext *avctx;
    int pkt_serial;
    int finished;
    int packet_pending;
    SDL_cond *empty_queue_cond;
    int64_t start_pts;
    AVRational start_pts_tb;
    int64_t next_pts;
    AVRational next_pts_tb;
    SDL_Thread *decoder_tid;
} Decoder;



typedef struct AVFormatInternal
{
    int nb_interleaved_streams;
    struct AVPacketList *packet_buffer;
    struct AVPacketList *packet_buffer_end;
    int64_t data_offset; 
    struct AVPacketList *raw_packet_buffer;
    struct AVPacketList *raw_packet_buffer_end;
    struct AVPacketList *parse_queue;
    struct AVPacketList *parse_queue_end;
    int raw_packet_buffer_remaining_size;
    int64_t offset;
    AVRational offset_timebase;
    int inject_global_side_data;
    int avoid_negative_ts_use_pts;
    int64_t shortest_end;
    int initialized;
    int streams_initialized;
    AVDictionary *id3v2_meta;
    int prefer_codec_framerate;
}AVFormatInternal;

typedef struct AVIOInterruptCB
{
    int (*callback)(void *);
    void *opaque;
} AVIOInterruptCB;



typedef struct AVIODirEntry
{
    char *name;
    int type;
    int utf8;
    int64_t size;
    int64_t modification_timestamp;
    int64_t access_timestamp;
    int64_t status_change_timestamp;
    int64_t user_id;
    int64_t group_id;
    int64_t filemode;
} AVIODirEntry;

typedef struct URLContext URLContext;
typedef struct URLProtocol
{
    const char *name;
    int (*url_open)(URLContext *h, const char *url, int flags);
    int (*url_open2)(URLContext *h, const char *url, int flags, AVDictionary **options);
    int (*url_accept)(URLContext *s, URLContext **c);
    int (*url_handshake)(URLContext *c);
    int (*url_read)(URLContext *h, unsigned char *buf, int size);
    int (*url_write)(URLContext *h, const unsigned char *buf, int size);
    int64_t (*url_seek)(URLContext *h, int64_t pos, int whence);
    int (*url_close)(URLContext *h);
    int (*url_read_pause)(URLContext *h, int pause);
    int64_t (*url_read_seek)(URLContext *h, int stream_index,
                             int64_t timestamp, int flags);
    int (*url_get_file_handle)(URLContext *h);
    int (*url_get_multi_file_handle)(URLContext *h, int **handles,
                                     int *numhandles);
    int (*url_get_short_seek)(URLContext *h);
    int (*url_shutdown)(URLContext *h, int flags);
    int priv_data_size;
    const AVClass *priv_data_class;
    int flags;
    int (*url_check)(URLContext *h, int mask);
    int (*url_open_dir)(URLContext *h);
    int (*url_read_dir)(URLContext *h, AVIODirEntry **next);
    int (*url_close_dir)(URLContext *h);
    int (*url_delete)(URLContext *h);
    int (*url_move)(URLContext *h_src, URLContext *h_dst);
    const char *default_whitelist;
} URLProtocol;

typedef struct URLContext
{
    const AVClass *av_class; 
    const struct URLProtocol *prot;
    void *priv_data;
    char *filename; 
    int flags;
    int max_packet_size; 
    int is_streamed;     
    int is_connected;
    AVIOInterruptCB interrupt_callback;
    int64_t rw_timeout; 
    const char *protocol_whitelist;
    const char *protocol_blacklist;
    int min_packet_size; 
} URLContext;

typedef struct AVIODirContext
{
    URLContext *url_context;
} AVIODirContext;

enum AVIODataMarkerType
{
    AVIO_DATA_MARKER_HEADER,
    AVIO_DATA_MARKER_SYNC_POINT,
    AVIO_DATA_MARKER_BOUNDARY_POINT,
    AVIO_DATA_MARKER_UNKNOWN,
    AVIO_DATA_MARKER_TRAILER,
    AVIO_DATA_MARKER_FLUSH_POINT,
};
typedef struct AVIOContext
{
    const AVClass *av_class;
    unsigned char *buffer;
    int buffer_size;
    unsigned char *buf_ptr;
    unsigned char *buf_end;
    void *opaque;
    int (*read_packet)(void *opaque, uint8_t *buf, int buf_size);
    int (*write_packet)(void *opaque, uint8_t *buf, int buf_size);
    int64_t (*seek)(void *opaque, int64_t offset, int whence);
    int64_t pos;
    int eof_reached;
    int write_flag;
    int max_packet_size;
    unsigned long checksum;
    unsigned char *checksum_ptr;
    unsigned long (*update_checksum)(unsigned long checksum, const uint8_t *buf, unsigned int size);
    int error;
    int (*read_pause)(void *opaque, int pause);
    int64_t (*read_seek)(void *opaque, int stream_index,
                         int64_t timestamp, int flags);
    int seekable;
    int64_t maxsize;
    int direct;
    int64_t bytes_read;
    int seek_count;
    int writeout_count;
    int orig_buffer_size;
    int short_seek_threshold;
    const char *protocol_whitelist;
    const char *protocol_blacklist;
    int (*write_data_type)(void *opaque, uint8_t *buf, int buf_size,
                           enum AVIODataMarkerType type, int64_t time);
    int ignore_boundary_point;
    enum AVIODataMarkerType current_type;
    int64_t last_time;
    int (*short_seek_get)(void *opaque);
    int64_t written;
    unsigned char *buf_ptr_max;
    int min_packet_size;
} AVIOContext;

typedef struct AVIndexEntry
{
    int64_t pos;
    int64_t timestamp;
    int flags : 2;
    int size : 30; //Yeah, trying to keep the size of this small to reduce memory requirements (it is 24 vs. 32 bytes due to possible 8-byte alignment).
    int min_distance;
} AVIndexEntry;
typedef struct AVStreamInfo
{
    int64_t last_dts;
    int64_t duration_gcd;
    int duration_count;
    int64_t rfps_duration_sum;
    double (*duration_error)[2][(30 * 12 + 30 + 3 + 6)];
    int64_t codec_info_duration;
    int64_t codec_info_duration_fields;
    int frame_delay_evidence;
    int found_decoder;
    int64_t last_duration;
    int64_t fps_first_dts;
    int fps_first_dts_idx;
    int64_t fps_last_dts;
    int fps_last_dts_idx;
} AVStreamInfo;

typedef struct FFFrac
{
    int64_t val, num, den;
} FFFrac;

typedef struct AVStreamInternal
{
    int reorder;
    AVBSFContext *bsfc;
    int bitstream_checked;
    AVCodecContext *avctx;
    int avctx_inited;
    enum AVCodecID orig_codec_id;
    struct
    {
        AVBSFContext *bsf;
        AVPacket *pkt;
        int inited;
    } extract_extradata;
    int need_context_update;
    int is_intra_only;
    FFFrac *priv_pts;
}AVStreamInternal;
struct AVBPrint;

struct AVFormatContext;

struct AVDeviceInfoList;
struct AVDeviceCapabilitiesQuery;
struct AVCodecTag;

typedef struct AVProbeData
{
    const char *filename;
    unsigned char *buf;
    int buf_size;
    const char *mime_type;
} AVProbeData;
typedef struct AVStream
{
    int index;
    int id;
    AVCodecContext *codec;
    void *priv_data;
    AVRational time_base;
    int64_t start_time;
    int64_t duration;
    int64_t nb_frames; ///< number of frames in this stream if known or 0
    int disposition;
    enum AVDiscard discard; ///< Selects which packets can be discarded at will and do not need to be demuxed.
    AVRational sample_aspect_ratio;
    AVDictionary *metadata;
    AVRational avg_frame_rate;
    AVPacket attached_pic;
    AVPacketSideData *side_data;
    int nb_side_data;
    int event_flags;
    AVRational r_frame_rate;
    char *recommended_encoder_configuration;
    AVCodecParameters *codecpar;
    AVStreamInfo *info;
    int pts_wrap_bits;
    // Timestamp generation support:
    int64_t first_dts;
    int64_t cur_dts;
    int64_t last_IP_pts;
    int last_IP_duration;
    int probe_packets;
    int codec_info_nb_frames;
    enum AVStreamParseType need_parsing;
    struct AVCodecParserContext *parser;
    struct AVPacketList *last_in_packet_buffer;
    AVProbeData probe_data;
    int64_t pts_buffer[16 + 1];
    AVIndexEntry *index_entries;
    int nb_index_entries;
    unsigned int index_entries_allocated_size;
    int stream_identifier;
    int program_num;
    int pmt_version;
    int pmt_stream_idx;
    int64_t interleaver_chunk_size;
    int64_t interleaver_chunk_duration;
    int request_probe;
    int skip_to_keyframe;
    int skip_samples;
    int64_t start_skip_samples;
    int64_t first_discard_sample;
    int64_t last_discard_sample;
    int nb_decoded_frames;
    int64_t mux_ts_offset;
    int64_t pts_wrap_reference;
    int pts_wrap_behavior;
    int update_initial_durations_done;
    int64_t pts_reorder_error[16 + 1];
    uint8_t pts_reorder_error_count[16 + 1];
    int64_t last_dts_for_order_check;
    uint8_t dts_ordered;
    uint8_t dts_misordered;
    int inject_global_side_data;
    AVRational display_aspect_ratio;
    AVStreamInternal *internal;
} AVStream;
typedef struct AVChapter
{
    int id;               ///< unique ID to identify the chapter
    AVRational time_base; ///< time base in which the start/end timestamps are specified
    int64_t start, end;   ///< chapter start/end time in time_base units
    AVDictionary *metadata;
} AVChapter;
typedef struct AVProgram
{
    int id;
    int flags;
    enum AVDiscard discard; ///< selects which program to discard and which to feed to the caller
    unsigned int *stream_index;
    unsigned int nb_stream_indexes;
    AVDictionary *metadata;
    int program_num;
    int pmt_pid;
    int pcr_pid;
    int pmt_version;
    int64_t start_time;
    int64_t end_time;
    int64_t pts_wrap_reference; ///< reference dts for wrap detection
    int pts_wrap_behavior;      ///< behavior on wrap detection
} AVProgram;
typedef int (*av_format_control_message)(struct AVFormatContext *s, int type,
                                         void *data, size_t data_size);

typedef int (*AVOpenCallback)(struct AVFormatContext *s, AVIOContext **pb, const char *url, int flags,
                              const AVIOInterruptCB *int_cb, AVDictionary **options);
typedef struct AVFormatContext
{
    const AVClass *av_class;
    struct AVInputFormat *iformat;
    struct AVOutputFormat *oformat;
    void *priv_data;
    AVIOContext *pb;
    int ctx_flags;
    unsigned int nb_streams;
    AVStream **streams;
    char filename[1024];
    char *url;
    int64_t start_time;
    int64_t duration;
    int64_t bit_rate;
    unsigned int packet_size;
    int max_delay;
    int flags;
    int64_t probesize;
    int64_t max_analyze_duration;
    const uint8_t *key;
    int keylen;
    unsigned int nb_programs;
    AVProgram **programs;
    enum AVCodecID video_codec_id;
    enum AVCodecID audio_codec_id;
    enum AVCodecID subtitle_codec_id;
    unsigned int max_index_size;
    unsigned int max_picture_buffer;
    unsigned int nb_chapters;
    AVChapter **chapters;
    AVDictionary *metadata;
    int64_t start_time_realtime;
    int fps_probe_size;
    int error_recognition;
    AVIOInterruptCB interrupt_callback;
    int debug;
    int64_t max_interleave_delta;
    int strict_std_compliance;
    int event_flags;
    int max_ts_probe;
    int avoid_negative_ts;
    int ts_id;
    int audio_preload;
    int max_chunk_duration;
    int max_chunk_size;
    int use_wallclock_as_timestamps;
    int avio_flags;
    enum AVDurationEstimationMethod duration_estimation_method;
    int64_t skip_initial_bytes;
    unsigned int correct_ts_overflow;
    int seek2any;
    int flush_packets;
    int probe_score;
    int format_probesize;
    char *codec_whitelist;
    char *format_whitelist;
    AVFormatInternal *internal;
    int io_repositioned;
    AVCodec *video_codec;
    AVCodec *audio_codec;
    AVCodec *subtitle_codec;
    AVCodec *data_codec;
    int metadata_header_padding;
    void *opaque;
    av_format_control_message control_message_cb;
    int64_t output_ts_offset;
    uint8_t *dump_separator;
    enum AVCodecID data_codec_id;
    int (*open_cb)(struct AVFormatContext *s, AVIOContext **p, const char *url, int flags, const AVIOInterruptCB *int_cb, AVDictionary **options);
    char *protocol_whitelist;
    int (*io_open)(struct AVFormatContext *s, AVIOContext **pb, const char *url,
                   int flags, AVDictionary **options);
    void (*io_close)(struct AVFormatContext *s, AVIOContext *pb);
    char *protocol_blacklist;
    int max_streams;
    int skip_estimate_duration_from_pts;
    int max_probe_packets;
} AVFormatContext;
typedef struct AVOutputFormat
{
    const char *name;
    const char *long_name;
    const char *mime_type;
    const char *extensions;
    enum AVCodecID audio_codec;
    enum AVCodecID video_codec;
    enum AVCodecID subtitle_codec;
    int flags;
    const struct AVCodecTag *const *codec_tag;
    const AVClass *priv_class; ///< AVClass for the private context
    struct AVOutputFormat *next;
    int priv_data_size;
    int (*write_header)(struct AVFormatContext *);
    int (*write_packet)(struct AVFormatContext *, AVPacket *pkt);
    int (*write_trailer)(struct AVFormatContext *);
    int (*interleave_packet)(struct AVFormatContext *, AVPacket *out,
                             AVPacket *in, int flush);
    int (*query_codec)(enum AVCodecID id, int std_compliance);
    void (*get_output_timestamp)(struct AVFormatContext *s, int stream,
                                 int64_t *dts, int64_t *wall);
    int (*control_message)(struct AVFormatContext *s, int type,
                           void *data, size_t data_size);
    int (*write_uncoded_frame)(struct AVFormatContext *, int stream_index,
                               AVFrame **frame, unsigned flags);
    int (*get_device_list)(struct AVFormatContext *s, struct AVDeviceInfoList *device_list);
    int (*create_device_capabilities)(struct AVFormatContext *s, struct AVDeviceCapabilitiesQuery *caps);
    int (*free_device_capabilities)(struct AVFormatContext *s, struct AVDeviceCapabilitiesQuery *caps);
    enum AVCodecID data_codec;
    int (*init)(struct AVFormatContext *);
    void (*deinit)(struct AVFormatContext *);
    int (*check_bitstream)(struct AVFormatContext *, const AVPacket *pkt);
} AVOutputFormat;

typedef struct AVInputFormat
{
    const char *name;
    const char *long_name;
    int flags;
    const char *extensions;
    const struct AVCodecTag *const *codec_tag;
    const AVClass *priv_class; ///< AVClass for the private context
    const char *mime_type;
    struct AVInputFormat *next;
    int raw_codec_id;
    int priv_data_size;
    int (*read_probe)(const AVProbeData *);
    int (*read_header)(struct AVFormatContext *);
    int (*read_packet)(struct AVFormatContext *, AVPacket *pkt);
    int (*read_close)(struct AVFormatContext *);
    int (*read_seek)(struct AVFormatContext *,
                     int stream_index, int64_t timestamp, int flags);
    int64_t (*read_timestamp)(struct AVFormatContext *s, int stream_index,
                              int64_t *pos, int64_t pos_limit);
    int (*read_play)(struct AVFormatContext *);
    int (*read_pause)(struct AVFormatContext *);
    int (*read_seek2)(struct AVFormatContext *s, int stream_index, int64_t min_ts, int64_t ts, int64_t max_ts, int flags);
    int (*get_device_list)(struct AVFormatContext *s, struct AVDeviceInfoList *device_list);
    int (*create_device_capabilities)(struct AVFormatContext *s, struct AVDeviceCapabilitiesQuery *caps);
    int (*free_device_capabilities)(struct AVFormatContext *s, struct AVDeviceCapabilitiesQuery *caps);
} AVInputFormat;
enum RDFTransformType
{
    DFT_R2C,
    IDFT_C2R,
    IDFT_R2C,
    DFT_C2R,
};

typedef struct RDFTContext RDFTContext;
typedef struct DCTContext DCTContext;

enum DCTTransformType
{
    DCT_II = 0,
    DCT_III,
    DCT_I,
    DST_I,
};

typedef float FFTSample;

typedef struct FFTComplex
{
    FFTSample re, im;
} FFTComplex;

typedef struct FFTContext FFTContext;
struct SDL_Texture;
typedef struct SDL_Texture SDL_Texture;

typedef struct AVFilterContext AVFilterContext;
typedef struct AVFilterLink AVFilterLink;
typedef struct AVFilterPad AVFilterPad;
typedef struct AVFilterFormats AVFilterFormats;
typedef struct AVFilterChannelLayouts AVFilterChannelLayouts;
typedef struct AVFilter
{
    const char *name;
    const char *description;
    const AVFilterPad *inputs;
    const AVFilterPad *outputs;
    const AVClass *priv_class;
    int flags;
    int (*preinit)(AVFilterContext *ctx);
    int (*init)(AVFilterContext *ctx);
    int (*init_dict)(AVFilterContext *ctx, AVDictionary **options);
    void (*uninit)(AVFilterContext *ctx);
    int (*query_formats)(AVFilterContext *);
    int priv_size;      ///< size of private data to allocate for the filter
    int flags_internal; ///< Additional flags for avfilter internal use only.
    struct AVFilter *next;
    int (*process_command)(AVFilterContext *, const char *cmd, const char *arg, char *res, int res_len, int flags);
    int (*init_opaque)(AVFilterContext *ctx, void *opaque);
    int (*activate)(AVFilterContext *ctx);
} AVFilter;
typedef struct AVFilterInternal AVFilterInternal;

struct AVFilterContext
{
    const AVClass *av_class;     ///< needed for av_log() and filters common options
    const AVFilter *filter;      ///< the AVFilter of which this is an instance
    char *name;                  ///< name of this filter instance
    AVFilterPad *input_pads;     ///< array of input pads
    AVFilterLink **inputs;       ///< array of pointers to input links
    unsigned nb_inputs;          ///< number of input pads
    AVFilterPad *output_pads;    ///< array of output pads
    AVFilterLink **outputs;      ///< array of pointers to output links
    unsigned nb_outputs;         ///< number of output pads
    void *priv;                  ///< private data for use by the filter
    struct AVFilterGraph *graph; ///< filtergraph this filter belongs to
    int thread_type;
    AVFilterInternal *internal;
    struct AVFilterCommand *command_queue;
    char *enable_str;   ///< enable expression string
    void *enable;       ///< parsed expression (AVExpr*)
    double *var_values; ///< variable values for the enable expression
    int is_disabled;    ///< the enabled state from the last expression evaluation
    AVBufferRef *hw_device_ctx;
    int nb_threads;
    unsigned ready;
    int extra_hw_frames;
};

typedef struct AVFilterFormatsConfig
{
    AVFilterFormats *formats;
    AVFilterFormats *samplerates;
    AVFilterChannelLayouts *channel_layouts;
} AVFilterFormatsConfig;

enum AVLINKEnum
{
    AVLINK_UNINIT = 0, ///< not started
    AVLINK_STARTINIT,  ///< started, but incomplete
    AVLINK_INIT        ///< complete
};

struct AVFilterLink
{
    AVFilterContext *src;           ///< source filter
    AVFilterPad *srcpad;            ///< output pad on the source filter
    AVFilterContext *dst;           ///< dest filter
    AVFilterPad *dstpad;            ///< input pad on the dest filter
    enum AVMediaType type;          ///< filter media type
    int w;                          ///< agreed upon image width
    int h;                          ///< agreed upon image height
    AVRational sample_aspect_ratio; ///< agreed upon sample aspect ratio
    uint64_t channel_layout;       
    int sample_rate;                ///< samples per second
    int format;                     ///< agreed upon media format
    AVRational time_base;
    AVFilterFormatsConfig incfg;
    AVFilterFormatsConfig outcfg;
    enum AVLINKEnum init_state;
    struct AVFilterGraph *graph;
    int64_t current_pts;
    int64_t current_pts_us;
    int age_index;
    AVRational frame_rate;
    AVFrame *partial_buf;
    int partial_buf_size;
    int min_samples;
    int max_samples;
    int channels;
    unsigned flags;
    int64_t frame_count_in, frame_count_out;
    void *frame_pool;
    int frame_wanted_out;
    AVBufferRef *hw_frames_ctx;
    char reserved[0xF000];
};

typedef struct AVFilterGraphInternal AVFilterGraphInternal;

enum
{
    AVFILTER_AUTO_CONVERT_ALL = 0,
    AVFILTER_AUTO_CONVERT_NONE = -1,
};
typedef struct AVFilterInOut
{
    char *name;
    AVFilterContext *filter_ctx;
    int pad_idx;
    struct AVFilterInOut *next;
} AVFilterInOut;
typedef struct AVBufferSinkParams
{
    const enum AVPixelFormat *pixel_fmts; ///< list of allowed pixel formats, terminated by AV_PIX_FMT_NONE
} AVBufferSinkParams;
typedef struct AVABufferSinkParams
{
    const enum AVSampleFormat *sample_fmts; ///< list of allowed sample formats, terminated by AV_SAMPLE_FMT_NONE
    const int64_t *channel_layouts;         ///< list of allowed channel layouts, terminated by -1
    const int *channel_counts;              ///< list of allowed channel counts, terminated by -1
    int all_channel_counts;                 ///< if not 0, accept any channel count or layout
    int *sample_rates;                      ///< list of allowed sample rates, terminated by -1
} AVABufferSinkParams;
typedef int(avfilter_action_func)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);

typedef int(avfilter_execute_func)(AVFilterContext *ctx, avfilter_action_func *func,
                                   void *arg, int *ret, int nb_jobs);
typedef struct AVFilterGraph
{
    const AVClass *av_class;
    AVFilterContext **filters;
    unsigned nb_filters;
    char *scale_sws_opts;     ///< sws options to use for the auto-inserted scale filters
    char *resample_lavr_opts; ///< libavresample options to use for the auto-inserted resample filters
    int thread_type;
    int nb_threads;
    AVFilterGraphInternal *internal;
    void *opaque;
    avfilter_execute_func *execute;
    char *aresample_swr_opts; ///< swr options to use for the auto-inserted aresample filters, Access ONLY through AVOptions
    AVFilterLink **sink_links;
    int sink_links_count;
    unsigned disable_auto_convert;
} AVFilterGraph;

typedef struct VideoState
{
    SDL_Thread *read_tid;
    AVInputFormat *iformat;
    int abort_request;
    int force_refresh;
    int paused;
    int last_paused;
    int queue_attachments_req;
    int seek_req;
    int seek_flags;
    int64_t seek_pos;
    int64_t seek_rel;
    int read_pause_return;
    AVFormatContext *ic;
    int realtime;
    Clock audclk;
    Clock vidclk;
    Clock extclk;
    FrameQueue pictq;
    FrameQueue subpq;
    FrameQueue sampq;
    Decoder auddec;
    Decoder viddec;
    Decoder subdec;
    int audio_stream;
    int av_sync_type;
    double audio_clock;
    int audio_clock_serial;
    double audio_diff_cum;
    double audio_diff_avg_coef;
    double audio_diff_threshold;
    int audio_diff_avg_count;
    AVStream *audio_st;
    PacketQueue audioq;
    int audio_hw_buf_size;
    uint8_t *audio_buf;
    uint8_t *audio_buf1;
    unsigned int audio_buf_size;
    unsigned int audio_buf1_size;
    int audio_buf_index;
    int audio_write_buf_size;
    int audio_volume;
    int muted;
    struct AudioParams audio_src;
    struct AudioParams audio_filter_src;
    struct AudioParams audio_tgt;
    struct SwrContext *swr_ctx;
    int frame_drops_early;
    int frame_drops_late;
    enum ShowMode show_mode;
    int16_t sample_array[(8 * 65536)];
    int sample_array_index;
    int last_i_start;
    RDFTContext *rdft;
    int rdft_bits;
    FFTSample *rdft_data;
    int xpos;
    double last_vis_time;
    SDL_Texture *vis_texture;
    SDL_Texture *sub_texture;
    SDL_Texture *vid_texture;
    int subtitle_stream;
    AVStream *subtitle_st;
    PacketQueue subtitleq;
    double frame_timer;
    double frame_last_returned_time;
    double frame_last_filter_delay;
    int video_stream;
    AVStream *video_st;
    PacketQueue videoq;
    double max_frame_duration; // maximum duration of a frame - above this, we consider the jump a timestamp discontinuity
    struct SwsContext *img_convert_ctx;
    struct SwsContext *sub_convert_ctx;
    int eof;
    char *filename;
    int width, height, xleft, ytop;
    int step;
    int vfilter_idx;
    AVFilterContext *in_video_filter;  // the first filter in the video chain
    AVFilterContext *out_video_filter; // the last filter in the video chain
    AVFilterContext *in_audio_filter;  // the first filter in the audio chain
    AVFilterContext *out_audio_filter; // the last filter in the audio chain
    AVFilterGraph *agraph;             // audio filter graph
    int last_video_stream, last_audio_stream, last_subtitle_stream;
    SDL_cond *continue_read_thread;
} VideoState;
struct TextureFormatEntry
{
    enum AVPixelFormat format;
    int texture_fmt;
};
typedef struct ID3v2ExtraMetaGEOB
{
    uint32_t datasize;
    uint8_t *mime_type;
    uint8_t *file_name;
    uint8_t *description;
    uint8_t *data;
} ID3v2ExtraMetaGEOB;

typedef struct ID3v2ExtraMetaAPIC
{
    AVBufferRef *buf;
    const char *type;
    uint8_t *description;
    enum AVCodecID id;
} ID3v2ExtraMetaAPIC;

typedef struct ID3v2ExtraMetaPRIV
{
    uint8_t *owner;
    uint8_t *data;
    uint32_t datasize;
} ID3v2ExtraMetaPRIV;

typedef struct ID3v2ExtraMetaCHAP
{
    uint8_t *element_id;
    uint32_t start, end;
    AVDictionary *meta;
} ID3v2ExtraMetaCHAP;

typedef struct ID3v2ExtraMeta
{
    const char *tag;
    struct ID3v2ExtraMeta *next;
    union
    {
        ID3v2ExtraMetaAPIC apic;
        ID3v2ExtraMetaCHAP chap;
        ID3v2ExtraMetaGEOB geob;
        ID3v2ExtraMetaPRIV priv;
    } data;
} ID3v2ExtraMeta;

enum ID3v2Encoding
{
    ID3v2_ENCODING_ISO8859 = 0,
    ID3v2_ENCODING_UTF16BOM = 1,
    ID3v2_ENCODING_UTF16BE = 2,
    ID3v2_ENCODING_UTF8 = 3,
};
typedef struct ID3v2EMFunc {
    const char *tag3;
    const char *tag4;
    void (*read)(AVFormatContext *s, AVIOContext *pb, int taglen,
                 const char *tag, ID3v2ExtraMeta **extra_meta,
                 int isv34);
    void (*free)(void *obj);
} ID3v2EMFunc;
typedef struct AVMetadataConv {
    const char *native;
    const char *generic;
} AVMetadataConv;
typedef struct AVFifoBuffer {
    uint8_t *buffer;
    uint8_t *rptr, *wptr, *end;
    uint32_t rndx, wndx;
} AVFifoBuffer;

typedef struct IPSourceFilters {
    int nb_include_addrs;
    int nb_exclude_addrs;
    struct sockaddr_storage *include_addrs;
    struct sockaddr_storage *exclude_addrs;
} IPSourceFilters;


typedef struct UDPContext {
    const AVClass *class;
    int udp_fd;
    int ttl;
    int udplite_coverage;
    int buffer_size;
    int pkt_size;
    int is_multicast;
    int is_broadcast;
    int local_port;
    int reuse_socket;
    int overrun_nonfatal;
    struct sockaddr_storage dest_addr;
    int dest_addr_len;
    int is_connected;

    
    int circular_buffer_size;
    AVFifoBuffer *fifo;
    int circular_buffer_error;
    int64_t bitrate; 
    int64_t burst_bits;
    int close_req;
#if HAVE_PTHREAD_CANCEL
    pthread_t circular_buffer_thread;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int thread_started;
#endif
    uint8_t tmp[UDP_MAX_PKT_SIZE+4];
    int remaining_in_dg;
    char *localaddr;
    int timeout;
    struct sockaddr_storage local_addr_storage;
    char *sources;
    char *block;
    IPSourceFilters filters;
} UDPContext;

typedef struct PixelFormatTag {
    enum AVPixelFormat pix_fmt;
    unsigned int fourcc;
} PixelFormatTag;


const AVMetadataConv ff_id3v2_34_metadata_conv[] = {
    { "TALB", "album"        },
    { "TCOM", "composer"     },
    { "TCON", "genre"        },
    { "TCOP", "copyright"    },
    { "TENC", "encoded_by"   },
    { "TIT2", "title"        },
    { "TLAN", "language"     },
    { "TPE1", "artist"       },
    { "TPE2", "album_artist" },
    { "TPE3", "performer"    },
    { "TPOS", "disc"         },
    { "TPUB", "publisher"    },
    { "TRCK", "track"        },
    { "TSSE", "encoder"      },
    { "USLT", "lyrics"       },
    { 0 }
};
const AVMetadataConv ff_id3v2_4_metadata_conv[] = {
    { "TCMP", "compilation"   },
    { "TDRC", "date"          },
    { "TDRL", "date"          },
    { "TDEN", "creation_time" },
    { "TSOA", "album-sort"    },
    { "TSOP", "artist-sort"   },
    { "TSOT", "title-sort"    },
    { 0 }
};
#define ID3v1_GENRE_MAX 191
const char * const ff_id3v1_genre_str[ID3v1_GENRE_MAX + 1] = {
      [0] = "Blues",
      [1] = "Classic Rock",
      [2] = "Country",
      [3] = "Dance",
      [4] = "Disco",
      [5] = "Funk",
      [6] = "Grunge",
      [7] = "Hip-Hop",
      [8] = "Jazz",
      [9] = "Metal",
     [10] = "New Age",
     [11] = "Oldies",
     [12] = "Other",
     [13] = "Pop",
     [14] = "R&B",
     [15] = "Rap",
     [16] = "Reggae",
     [17] = "Rock",
     [18] = "Techno",
     [19] = "Industrial",
     [20] = "Alternative",
     [21] = "Ska",
     [22] = "Death Metal",
     [23] = "Pranks",
     [24] = "Soundtrack",
     [25] = "Euro-Techno",
     [26] = "Ambient",
     [27] = "Trip-Hop",
     [28] = "Vocal",
     [29] = "Jazz+Funk",
     [30] = "Fusion",
     [31] = "Trance",
     [32] = "Classical",
     [33] = "Instrumental",
     [34] = "Acid",
     [35] = "House",
     [36] = "Game",
     [37] = "Sound Clip",
     [38] = "Gospel",
     [39] = "Noise",
     [40] = "AlternRock",
     [41] = "Bass",
     [42] = "Soul",
     [43] = "Punk",
     [44] = "Space",
     [45] = "Meditative",
     [46] = "Instrumental Pop",
     [47] = "Instrumental Rock",
     [48] = "Ethnic",
     [49] = "Gothic",
     [50] = "Darkwave",
     [51] = "Techno-Industrial",
     [52] = "Electronic",
     [53] = "Pop-Folk",
     [54] = "Eurodance",
     [55] = "Dream",
     [56] = "Southern Rock",
     [57] = "Comedy",
     [58] = "Cult",
     [59] = "Gangsta",
     [60] = "Top 40",
     [61] = "Christian Rap",
     [62] = "Pop/Funk",
     [63] = "Jungle",
     [64] = "Native American",
     [65] = "Cabaret",
     [66] = "New Wave",
     [67] = "Psychedelic",
     [68] = "Rave",
     [69] = "Showtunes",
     [70] = "Trailer",
     [71] = "Lo-Fi",
     [72] = "Tribal",
     [73] = "Acid Punk",
     [74] = "Acid Jazz",
     [75] = "Polka",
     [76] = "Retro",
     [77] = "Musical",
     [78] = "Rock & Roll",
     [79] = "Hard Rock",
     [80] = "Folk",
     [81] = "Folk-Rock",
     [82] = "National Folk",
     [83] = "Swing",
     [84] = "Fast Fusion",
     [85] = "Bebop",
     [86] = "Latin",
     [87] = "Revival",
     [88] = "Celtic",
     [89] = "Bluegrass",
     [90] = "Avantgarde",
     [91] = "Gothic Rock",
     [92] = "Progressive Rock",
     [93] = "Psychedelic Rock",
     [94] = "Symphonic Rock",
     [95] = "Slow Rock",
     [96] = "Big Band",
     [97] = "Chorus",
     [98] = "Easy Listening",
     [99] = "Acoustic",
    [100] = "Humour",
    [101] = "Speech",
    [102] = "Chanson",
    [103] = "Opera",
    [104] = "Chamber Music",
    [105] = "Sonata",
    [106] = "Symphony",
    [107] = "Booty Bass",
    [108] = "Primus",
    [109] = "Porn Groove",
    [110] = "Satire",
    [111] = "Slow Jam",
    [112] = "Club",
    [113] = "Tango",
    [114] = "Samba",
    [115] = "Folklore",
    [116] = "Ballad",
    [117] = "Power Ballad",
    [118] = "Rhythmic Soul",
    [119] = "Freestyle",
    [120] = "Duet",
    [121] = "Punk Rock",
    [122] = "Drum Solo",
    [123] = "A Cappella",
    [124] = "Euro-House",
    [125] = "Dance Hall",
    [126] = "Goa",
    [127] = "Drum & Bass",
    [128] = "Club-House",
    [129] = "Hardcore Techno",
    [130] = "Terror",
    [131] = "Indie",
    [132] = "BritPop",
    [133] = "Negerpunk",
    [134] = "Polsk Punk",
    [135] = "Beat",
    [136] = "Christian Gangsta Rap",
    [137] = "Heavy Metal",
    [138] = "Black Metal",
    [139] = "Crossover",
    [140] = "Contemporary Christian",
    [141] = "Christian Rock",
    [142] = "Merengue",
    [143] = "Salsa",
    [144] = "Thrash Metal",
    [145] = "Anime",
    [146] = "Jpop",
    [147] = "Synthpop",
    [148] = "Abstract",
    [149] = "Art Rock",
    [150] = "Baroque",
    [151] = "Bhangra",
    [152] = "Big Beat",
    [153] = "Breakbeat",
    [154] = "Chillout",
    [155] = "Downtempo",
    [156] = "Dub",
    [157] = "EBM",
    [158] = "Eclectic",
    [159] = "Electro",
    [160] = "Electroclash",
    [161] = "Emo",
    [162] = "Experimental",
    [163] = "Garage",
    [164] = "Global",
    [165] = "IDM",
    [166] = "Illbient",
    [167] = "Industro-Goth",
    [168] = "Jam Band",
    [169] = "Krautrock",
    [170] = "Leftfield",
    [171] = "Lounge",
    [172] = "Math Rock",
    [173] = "New Romantic",
    [174] = "Nu-Breakz",
    [175] = "Post-Punk",
    [176] = "Post-Rock",
    [177] = "Psytrance",
    [178] = "Shoegaze",
    [179] = "Space Rock",
    [180] = "Trop Rock",
    [181] = "World Music",
    [182] = "Neoclassical",
    [183] = "Audiobook",
    [184] = "Audio Theatre",
    [185] = "Neue Deutsche Welle",
    [186] = "Podcast",
    [187] = "Indie Rock",
    [188] = "G-Funk",
    [189] = "Dubstep",
    [190] = "Garage Rock",
    [191] = "Psybient"
};
typedef struct CodecMime{
    char str[32];
    enum AVCodecID id;
} CodecMime;
const CodecMime ff_id3v2_mime_tags[] = {
    { "image/gif",  AV_CODEC_ID_GIF   },
    { "image/jpeg", AV_CODEC_ID_MJPEG },
    { "image/jpg",  AV_CODEC_ID_MJPEG },
    { "image/png",  AV_CODEC_ID_PNG   },
    { "image/tiff", AV_CODEC_ID_TIFF  },
    { "image/bmp",  AV_CODEC_ID_BMP   },
    { "JPG",        AV_CODEC_ID_MJPEG }, 
    { "PNG",        AV_CODEC_ID_PNG   }, 
    { "",           AV_CODEC_ID_NONE  },
};
const char * const ff_id3v2_picture_types[21] = {
    "Other",
    "32x32 pixels 'file icon'",
    "Other file icon",
    "Cover (front)",
    "Cover (back)",
    "Leaflet page",
    "Media (e.g. label side of CD)",
    "Lead artist/lead performer/soloist",
    "Artist/performer",
    "Conductor",
    "Band/Orchestra",
    "Composer",
    "Lyricist/text writer",
    "Recording Location",
    "During recording",
    "During performance",
    "Movie/video screen capture",
    "A bright coloured fish",
    "Illustration",
    "Band/artist logotype",
    "Publisher/Studio logotype",
};
typedef enum
{
    ShapeModeDefault,
    ShapeModeBinarizeAlpha,
    ShapeModeReverseBinarizeAlpha,
    ShapeModeColorKey
} WindowShapeMode;
typedef enum
{
    SDL_PIXELTYPE_UNKNOWN,
    SDL_PIXELTYPE_INDEX1,
    SDL_PIXELTYPE_INDEX4,
    SDL_PIXELTYPE_INDEX8,
    SDL_PIXELTYPE_PACKED8,
    SDL_PIXELTYPE_PACKED16,
    SDL_PIXELTYPE_PACKED32,
    SDL_PIXELTYPE_ARRAYU8,
    SDL_PIXELTYPE_ARRAYU16,
    SDL_PIXELTYPE_ARRAYU32,
    SDL_PIXELTYPE_ARRAYF16,
    SDL_PIXELTYPE_ARRAYF32
} SDL_PixelType;

typedef enum
{
    SDL_BITMAPORDER_NONE,
    SDL_BITMAPORDER_4321,
    SDL_BITMAPORDER_1234
} SDL_BitmapOrder;

typedef enum
{
    SDL_PACKEDORDER_NONE,
    SDL_PACKEDORDER_XRGB,
    SDL_PACKEDORDER_RGBX,
    SDL_PACKEDORDER_ARGB,
    SDL_PACKEDORDER_RGBA,
    SDL_PACKEDORDER_XBGR,
    SDL_PACKEDORDER_BGRX,
    SDL_PACKEDORDER_ABGR,
    SDL_PACKEDORDER_BGRA
} SDL_PackedOrder;

typedef enum
{
    SDL_ARRAYORDER_NONE,
    SDL_ARRAYORDER_RGB,
    SDL_ARRAYORDER_RGBA,
    SDL_ARRAYORDER_ARGB,
    SDL_ARRAYORDER_BGR,
    SDL_ARRAYORDER_BGRA,
    SDL_ARRAYORDER_ABGR
} SDL_ArrayOrder;

typedef enum
{
    SDL_PACKEDLAYOUT_NONE,
    SDL_PACKEDLAYOUT_332,
    SDL_PACKEDLAYOUT_4444,
    SDL_PACKEDLAYOUT_1555,
    SDL_PACKEDLAYOUT_5551,
    SDL_PACKEDLAYOUT_565,
    SDL_PACKEDLAYOUT_8888,
    SDL_PACKEDLAYOUT_2101010,
    SDL_PACKEDLAYOUT_1010102
} SDL_PackedLayout;
typedef enum
{
    SDL_PIXELFORMAT_UNKNOWN,
    SDL_PIXELFORMAT_INDEX1LSB =
        ((1 << 28) | ((SDL_PIXELTYPE_INDEX1) << 24) | ((SDL_BITMAPORDER_4321) << 20) | ((0) << 16) | ((1) << 8) | ((0) << 0)),
    SDL_PIXELFORMAT_INDEX1MSB =
        ((1 << 28) | ((SDL_PIXELTYPE_INDEX1) << 24) | ((SDL_BITMAPORDER_1234) << 20) | ((0) << 16) | ((1) << 8) | ((0) << 0)),
    SDL_PIXELFORMAT_INDEX4LSB =
        ((1 << 28) | ((SDL_PIXELTYPE_INDEX4) << 24) | ((SDL_BITMAPORDER_4321) << 20) | ((0) << 16) | ((4) << 8) | ((0) << 0)),
    SDL_PIXELFORMAT_INDEX4MSB =
        ((1 << 28) | ((SDL_PIXELTYPE_INDEX4) << 24) | ((SDL_BITMAPORDER_1234) << 20) | ((0) << 16) | ((4) << 8) | ((0) << 0)),
    SDL_PIXELFORMAT_INDEX8 =
        ((1 << 28) | ((SDL_PIXELTYPE_INDEX8) << 24) | ((0) << 20) | ((0) << 16) | ((8) << 8) | ((1) << 0)),
    SDL_PIXELFORMAT_RGB332 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED8) << 24) | ((SDL_PACKEDORDER_XRGB) << 20) | ((SDL_PACKEDLAYOUT_332) << 16) | ((8) << 8) | ((1) << 0)),
    SDL_PIXELFORMAT_RGB444 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_XRGB) << 20) | ((SDL_PACKEDLAYOUT_4444) << 16) | ((12) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_BGR444 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_XBGR) << 20) | ((SDL_PACKEDLAYOUT_4444) << 16) | ((12) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_RGB555 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_XRGB) << 20) | ((SDL_PACKEDLAYOUT_1555) << 16) | ((15) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_BGR555 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_XBGR) << 20) | ((SDL_PACKEDLAYOUT_1555) << 16) | ((15) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_ARGB4444 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_ARGB) << 20) | ((SDL_PACKEDLAYOUT_4444) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_RGBA4444 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_RGBA) << 20) | ((SDL_PACKEDLAYOUT_4444) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_ABGR4444 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_ABGR) << 20) | ((SDL_PACKEDLAYOUT_4444) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_BGRA4444 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_BGRA) << 20) | ((SDL_PACKEDLAYOUT_4444) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_ARGB1555 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_ARGB) << 20) | ((SDL_PACKEDLAYOUT_1555) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_RGBA5551 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_RGBA) << 20) | ((SDL_PACKEDLAYOUT_5551) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_ABGR1555 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_ABGR) << 20) | ((SDL_PACKEDLAYOUT_1555) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_BGRA5551 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_BGRA) << 20) | ((SDL_PACKEDLAYOUT_5551) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_RGB565 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_XRGB) << 20) | ((SDL_PACKEDLAYOUT_565) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_BGR565 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED16) << 24) | ((SDL_PACKEDORDER_XBGR) << 20) | ((SDL_PACKEDLAYOUT_565) << 16) | ((16) << 8) | ((2) << 0)),
    SDL_PIXELFORMAT_RGB24 =
        ((1 << 28) | ((SDL_PIXELTYPE_ARRAYU8) << 24) | ((SDL_ARRAYORDER_RGB) << 20) | ((0) << 16) | ((24) << 8) | ((3) << 0)),
    SDL_PIXELFORMAT_BGR24 =
        ((1 << 28) | ((SDL_PIXELTYPE_ARRAYU8) << 24) | ((SDL_ARRAYORDER_BGR) << 20) | ((0) << 16) | ((24) << 8) | ((3) << 0)),
    SDL_PIXELFORMAT_RGB888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_XRGB) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((24) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_RGBX8888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_RGBX) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((24) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_BGR888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_XBGR) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((24) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_BGRX8888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_BGRX) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((24) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_ARGB8888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_ARGB) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((32) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_RGBA8888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_RGBA) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((32) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_ABGR8888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_ABGR) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((32) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_BGRA8888 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_BGRA) << 20) | ((SDL_PACKEDLAYOUT_8888) << 16) | ((32) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_ARGB2101010 =
        ((1 << 28) | ((SDL_PIXELTYPE_PACKED32) << 24) | ((SDL_PACKEDORDER_ARGB) << 20) | ((SDL_PACKEDLAYOUT_2101010) << 16) | ((32) << 8) | ((4) << 0)),
    SDL_PIXELFORMAT_RGBA32 = SDL_PIXELFORMAT_ABGR8888,
    SDL_PIXELFORMAT_ARGB32 = SDL_PIXELFORMAT_BGRA8888,
    SDL_PIXELFORMAT_BGRA32 = SDL_PIXELFORMAT_ARGB8888,
    SDL_PIXELFORMAT_ABGR32 = SDL_PIXELFORMAT_RGBA8888,
    SDL_PIXELFORMAT_YV12 =
        ((((uint32_t)(((Uint8)(('Y'))))) << 0) | (((uint32_t)(((Uint8)(('V'))))) << 8) | (((uint32_t)(((Uint8)(('1'))))) << 16) | (((uint32_t)(((Uint8)(('2'))))) << 24)),
    SDL_PIXELFORMAT_IYUV =
        ((((uint32_t)(((Uint8)(('I'))))) << 0) | (((uint32_t)(((Uint8)(('Y'))))) << 8) | (((uint32_t)(((Uint8)(('U'))))) << 16) | (((uint32_t)(((Uint8)(('V'))))) << 24)),
    SDL_PIXELFORMAT_YUY2 =
        ((((uint32_t)(((Uint8)(('Y'))))) << 0) | (((uint32_t)(((Uint8)(('U'))))) << 8) | (((uint32_t)(((Uint8)(('Y'))))) << 16) | (((uint32_t)(((Uint8)(('2'))))) << 24)),
    SDL_PIXELFORMAT_UYVY =
        ((((uint32_t)(((Uint8)(('U'))))) << 0) | (((uint32_t)(((Uint8)(('Y'))))) << 8) | (((uint32_t)(((Uint8)(('V'))))) << 16) | (((uint32_t)(((Uint8)(('Y'))))) << 24)),
    SDL_PIXELFORMAT_YVYU =
        ((((uint32_t)(((Uint8)(('Y'))))) << 0) | (((uint32_t)(((Uint8)(('V'))))) << 8) | (((uint32_t)(((Uint8)(('Y'))))) << 16) | (((uint32_t)(((Uint8)(('U'))))) << 24)),
    SDL_PIXELFORMAT_NV12 =
        ((((uint32_t)(((Uint8)(('N'))))) << 0) | (((uint32_t)(((Uint8)(('V'))))) << 8) | (((uint32_t)(((Uint8)(('1'))))) << 16) | (((uint32_t)(((Uint8)(('2'))))) << 24)),
    SDL_PIXELFORMAT_NV21 =
        ((((uint32_t)(((Uint8)(('N'))))) << 0) | (((uint32_t)(((Uint8)(('V'))))) << 8) | (((uint32_t)(((Uint8)(('2'))))) << 16) | (((uint32_t)(((Uint8)(('1'))))) << 24)),
    SDL_PIXELFORMAT_EXTERNAL_OES =
        ((((uint32_t)(((Uint8)(('O'))))) << 0) | (((uint32_t)(((Uint8)(('1'))))) << 8) | (((uint32_t)(((Uint8)(('S'))))) << 16) | (((uint32_t)(((Uint8)((' '))))) << 24))
} SDL_PixelFormatEnum;

enum  AVResampleDitherMethod {
    AV_RESAMPLE_DITHER_NONE,            /**< Do not use dithering */
    AV_RESAMPLE_DITHER_RECTANGULAR,     /**< Rectangular Dither */
    AV_RESAMPLE_DITHER_TRIANGULAR,      /**< Triangular Dither*/
    AV_RESAMPLE_DITHER_TRIANGULAR_HP,   /**< Triangular Dither with High Pass */
    AV_RESAMPLE_DITHER_TRIANGULAR_NS,   /**< Triangular Dither with Noise Shaping */
    AV_RESAMPLE_DITHER_NB,              /**< Number of dither types. Not part of ABI. */
};

enum RemapPoint {
    REMAP_NONE,
    REMAP_IN_COPY,
    REMAP_IN_CONVERT,
    REMAP_OUT_COPY,
    REMAP_OUT_CONVERT,
};
enum  AVMixCoeffType {
    AV_MIX_COEFF_TYPE_Q8,   /** 16-bit 8.8 fixed-point                      */
    AV_MIX_COEFF_TYPE_Q15,  /** 32-bit 17.15 fixed-point                    */
    AV_MIX_COEFF_TYPE_FLT,  /** floating-point                              */
    AV_MIX_COEFF_TYPE_NB,   /** Number of coeff types. Not part of ABI      */
};


enum  AVResampleFilterType {
    AV_RESAMPLE_FILTER_TYPE_CUBIC,              /**< Cubic */
    AV_RESAMPLE_FILTER_TYPE_BLACKMAN_NUTTALL,   /**< Blackman Nuttall Windowed Sinc */
    AV_RESAMPLE_FILTER_TYPE_KAISER,             /**< Kaiser Windowed Sinc */
};

enum AVMatrixEncoding
{
    AV_MATRIX_ENCODING_NONE,
    AV_MATRIX_ENCODING_DOLBY,
    AV_MATRIX_ENCODING_DPLII,
    AV_MATRIX_ENCODING_DPLIIX,
    AV_MATRIX_ENCODING_DPLIIZ,
    AV_MATRIX_ENCODING_DOLBYEX,
    AV_MATRIX_ENCODING_DOLBYHEADPHONE,
    AV_MATRIX_ENCODING_NB
};


typedef struct SDL_Color
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} SDL_Color;

#define SDL_Colour SDL_Color

typedef struct SDL_Palette
{
    int ncolors;
    SDL_Color *colors;
    uint32_t version;
    int refcount;
} SDL_Palette;

typedef struct SDL_PixelFormat
{
    uint32_t format;
    SDL_Palette *palette;
    Uint8 BitsPerPixel;
    Uint8 BytesPerPixel;
    Uint8 padding[2];
    uint32_t Rmask;
    uint32_t Gmask;
    uint32_t Bmask;
    uint32_t Amask;
    Uint8 Rloss;
    Uint8 Gloss;
    Uint8 Bloss;
    Uint8 Aloss;
    Uint8 Rshift;
    Uint8 Gshift;
    Uint8 Bshift;
    Uint8 Ashift;
    int refcount;
    struct SDL_PixelFormat *next;
} SDL_PixelFormat;

typedef union
{
    Uint8 binarizationCutoff;
    SDL_Color colorKey;
} SDL_WindowShapeParams;
typedef struct IDirect3DDevice9 IDirect3DDevice9;

typedef struct SDL_WindowShapeMode
{
    WindowShapeMode mode;
    SDL_WindowShapeParams parameters;
} SDL_WindowShapeMode;

typedef struct SDL_version
{
    Uint8 major;
    Uint8 minor;
    Uint8 patch;
} SDL_version;

typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;


typedef struct DitherDSPContext {

    void (*quantize)(int16_t *dst, const float *src, float *dither, int len);

    int ptr_align;      ///< src and dst constraints for quantize()
    int samples_align;  ///< len constraints for quantize()

    void (*dither_int_to_float)(float *dst, int *src0, int len);
} DitherDSPContext;

typedef struct DitherState {
    int mute;
    unsigned int seed;
    AVLFG lfg;
    float *noise_buf;
    int noise_buf_size;
    int noise_buf_ptr;
    float dither_a[4];
    float dither_b[4];
} DitherState;

#define AVRESAMPLE_MAX_CHANNELS 32
#define SWR_CH_MAX 64

#define SQRT3_2      1.22474487139158904909  /* sqrt(3/2) */

#define NS_TAPS 20

#if ARCH_X86_64
typedef int64_t integer;
#else
typedef int integer;
#endif

typedef struct ChannelMapInfo {
    int channel_map[AVRESAMPLE_MAX_CHANNELS];   /**< source index of each output channel, -1 if not remapped */
    int do_remap;                               /**< remap needed */
    int channel_copy[AVRESAMPLE_MAX_CHANNELS];  /**< dest index to copy from */
    int do_copy;                                /**< copy needed */
    int channel_zero[AVRESAMPLE_MAX_CHANNELS];  /**< dest index to zero */
    int do_zero;                                /**< zeroing needed */
    int input_map[AVRESAMPLE_MAX_CHANNELS];     /**< dest index of each input channel */
} ChannelMapInfo;

typedef struct SWresampleAudioData{
    uint8_t *ch[SWR_CH_MAX];    ///< samples buffer per channel
    uint8_t *data;              ///< samples buffer
    int ch_count;               ///< number of channels
    int bps;                    ///< bytes per sample
    int count;                  ///< number of samples
    int planar;                 ///< 1 if planar audio, 0 otherwise
    enum AVSampleFormat fmt;    ///< sample format
} SWresampleAudioData;

typedef struct AVAudioResampleContext AVAudioResampleContext;

typedef void (mix_func)(uint8_t **src, void **matrix, int len, int out_ch,
                        int in_ch);
struct AudioMix {
    AVAudioResampleContext *avr;
    enum AVSampleFormat fmt;
    enum AVMixCoeffType coeff_type;
    uint64_t in_layout;
    uint64_t out_layout;
    int in_channels;
    int out_channels;

    int ptr_align;
    int samples_align;
    int has_optimized_func;
    const char *func_descr;
    const char *func_descr_generic;
    mix_func *mix;
    mix_func *mix_generic;

    int in_matrix_channels;
    int out_matrix_channels;
    int output_zero[AVRESAMPLE_MAX_CHANNELS];
    int input_skip[AVRESAMPLE_MAX_CHANNELS];
    int output_skip[AVRESAMPLE_MAX_CHANNELS];
    int16_t *matrix_q8[AVRESAMPLE_MAX_CHANNELS];
    int32_t *matrix_q15[AVRESAMPLE_MAX_CHANNELS];
    float   *matrix_flt[AVRESAMPLE_MAX_CHANNELS];
    void   **matrix;
};
typedef struct AudioMix AudioMix;
typedef struct ResampleContext ResampleContext;




#define AVRESAMPLE_MAX_CHANNELS 32


typedef struct AVAudioFifo {
    AVFifoBuffer **buf;             /**< single buffer for interleaved, per-channel buffers for planar */
    int nb_buffers;                 /**< number of buffers */
    int nb_samples;                 /**< number of samples currently in the FIFO */
    int allocated_samples;          /**< current allocated size, in samples */

    int channels;                   /**< number of channels */
    enum AVSampleFormat sample_fmt; /**< sample format */
    int sample_size;                /**< size, in bytes, of one sample in a buffer */
}AVAudioFifo;


typedef void (conv_func_type)(uint8_t *po, const uint8_t *pi, int is, int os, uint8_t *end);
typedef void (simd_func_type)(uint8_t **dst, const uint8_t **src, int len);

typedef struct SWresampleAudioConvert {
    int channels;
    int  in_simd_align_mask;
    int out_simd_align_mask;
    conv_func_type *conv_f;
    simd_func_type *simd_f;
    const int *ch_map;
    uint8_t silence[8]; ///< silence input sample
}SWresampleAudioConvert;

typedef struct AudioData {
    const AVClass *class;               /**< AVClass for logging            */
    uint8_t *data[AVRESAMPLE_MAX_CHANNELS]; /**< data plane pointers        */
    uint8_t *buffer;                    /**< data buffer                    */
    unsigned int buffer_size;           /**< allocated buffer size          */
    int allocated_samples;              /**< number of samples the buffer can hold */
    int nb_samples;                     /**< current number of samples      */
    enum AVSampleFormat sample_fmt;     /**< sample format                  */
    int channels;                       /**< channel count                  */
    int allocated_channels;             /**< allocated channel count        */
    int is_planar;                      /**< sample format is planar        */
    int planes;                         /**< number of data planes          */
    int sample_size;                    /**< bytes per sample               */
    int stride;                         /**< sample byte offset within a plane */
    int read_only;                      /**< data is read-only              */
    int allow_realloc;                  /**< realloc is allowed             */
    int ptr_align;                      /**< minimum data pointer alignment */
    int samples_align;                  /**< allocated samples alignment    */
    const char *name;                   /**< name for debug logging         */
} AudioData;

enum ConvFuncType {
    CONV_FUNC_TYPE_FLAT,
    CONV_FUNC_TYPE_INTERLEAVE,
    CONV_FUNC_TYPE_DEINTERLEAVE,
};

typedef void (conv_func_flat)(uint8_t *out, const uint8_t *in, int len);

typedef void (conv_func_interleave)(uint8_t *out, uint8_t *const *in,
                                    int len, int channels);

typedef void (conv_func_deinterleave)(uint8_t **out, const uint8_t *in, int len,
                                      int channels);

typedef struct DitherContext DitherContext;
struct AudioConvert {
    AVAudioResampleContext *avr;
    DitherContext *dc;
    enum AVSampleFormat in_fmt;
    enum AVSampleFormat out_fmt;
    int apply_map;
    int channels;
    int planes;
    int ptr_align;
    int samples_align;
    int has_optimized_func;
    const char *func_descr;
    const char *func_descr_generic;
    enum ConvFuncType func_type;
    conv_func_flat         *conv_flat;
    conv_func_flat         *conv_flat_generic;
    conv_func_interleave   *conv_interleave;
    conv_func_interleave   *conv_interleave_generic;
    conv_func_deinterleave *conv_deinterleave;
    conv_func_deinterleave *conv_deinterleave_generic;
};
typedef struct AudioConvert AudioConvert;
typedef struct DitherContext {
    DitherDSPContext  ddsp;
    enum AVResampleDitherMethod method;
    int apply_map;
    ChannelMapInfo *ch_map_info;

    int mute_dither_threshold;  // threshold for disabling dither
    int mute_reset_threshold;   // threshold for resetting noise shaping
    const float *ns_coef_b;     // noise shaping coeffs
    const float *ns_coef_a;     // noise shaping coeffs

    int channels;
    DitherState *state;         // dither states for each channel

    AudioData *flt_data;        // input data in fltp
    AudioData *s16_data;        // dithered output in s16p
    AudioConvert *ac_in;        // converter for input to fltp
    AudioConvert *ac_out;       // converter for s16p to s16 (if needed)

    void (*quantize)(int16_t *dst, const float *src, float *dither, int len);
    int samples_align;
}DitherContext;





typedef struct AVAudioResampleContext {
    const AVClass *av_class;        /**< AVClass for logging and AVOptions  */

    uint64_t in_channel_layout;                 /**< input channel layout   */
    enum AVSampleFormat in_sample_fmt;          /**< input sample format    */
    int in_sample_rate;                         /**< input sample rate      */
    uint64_t out_channel_layout;                /**< output channel layout  */
    enum AVSampleFormat out_sample_fmt;         /**< output sample format   */
    int out_sample_rate;                        /**< output sample rate     */
    enum AVSampleFormat internal_sample_fmt;    /**< internal sample format */
    enum AVMixCoeffType mix_coeff_type;         /**< mixing coefficient type */
    double center_mix_level;                    /**< center mix level       */
    double surround_mix_level;                  /**< surround mix level     */
    double lfe_mix_level;                       /**< lfe mix level          */
    int normalize_mix_level;                    /**< enable mix level normalization */
    int force_resampling;                       /**< force resampling       */
    int filter_size;                            /**< length of each FIR filter in the resampling filterbank relative to the cutoff frequency */
    int phase_shift;                            /**< log2 of the number of entries in the resampling polyphase filterbank */
    int linear_interp;                          /**< if 1 then the resampling FIR filter will be linearly interpolated */
    double cutoff;                              /**< resampling cutoff frequency. 1.0 corresponds to half the output sample rate */
    enum AVResampleFilterType filter_type;      /**< resampling filter type */
    int kaiser_beta;                            /**< beta value for Kaiser window (only applicable if filter_type == AV_FILTER_TYPE_KAISER) */
    enum AVResampleDitherMethod dither_method;  /**< dither method          */

    int in_channels;        /**< number of input channels                   */
    int out_channels;       /**< number of output channels                  */
    int resample_channels;  /**< number of channels used for resampling     */
    int downmix_needed;     /**< downmixing is needed                       */
    int upmix_needed;       /**< upmixing is needed                         */
    int mixing_needed;      /**< either upmixing or downmixing is needed    */
    int resample_needed;    /**< resampling is needed                       */
    int in_convert_needed;  /**< input sample format conversion is needed   */
    int out_convert_needed; /**< output sample format conversion is needed  */
    int in_copy_needed;     /**< input data copy is needed                  */

    AudioData *in_buffer;           /**< buffer for converted input         */
    AudioData *resample_out_buffer; /**< buffer for output from resampler   */
    AudioData *out_buffer;          /**< buffer for converted output        */
    AVAudioFifo *out_fifo;          /**< FIFO for output samples            */

    AudioConvert *ac_in;        /**< input sample format conversion context  */
    AudioConvert *ac_out;       /**< output sample format conversion context */
    ResampleContext *resample;  /**< resampling context                      */
    AudioMix *am;               /**< channel mixing context                  */
    enum AVMatrixEncoding matrix_encoding;      /**< matrixed stereo encoding */

    /**
     * mix matrix
     * only used if avresample_set_matrix() is called before avresample_open()
     */
    double *mix_matrix;

    int use_channel_map;
    enum RemapPoint remap_point;
    ChannelMapInfo ch_map_info;
}AVAudioResampleContext;




struct ResampleContext {
    AVAudioResampleContext *avr;
    AudioData *buffer;
    uint8_t *filter_bank;
    int filter_length;
    int ideal_dst_incr;
    int dst_incr;
    unsigned int index;
    int frac;
    int src_incr;
    int compensation_distance;
    int phase_shift;
    int phase_mask;
    int linear;
    enum AVResampleFilterType filter_type;
    int kaiser_beta;
    void (*set_filter)(void *filter, double *tab, int phase, int tap_count);
    void (*resample_one)(struct ResampleContext *c, void *dst0,
                         int dst_index, const void *src0,
                         unsigned int index, int frac);
    void (*resample_nearest)(void *dst0, int dst_index,
                             const void *src0, unsigned int index);
    int padding_size;
    int initial_padding_filled;
    int initial_padding_samples;
    int final_padding_filled;
    int final_padding_samples;
};



typedef struct AVDeviceCapabilitiesQuery
{
    const AVClass *av_class;
    AVFormatContext *device_context;
    enum AVCodecID codec;
    enum AVSampleFormat sample_format;
    enum AVPixelFormat pixel_format;
    int sample_rate;
    int channels;
    int64_t channel_layout;
    int window_width;
    int window_height;
    int frame_width;
    int frame_height;
    AVRational fps;
} AVDeviceCapabilitiesQuery;

typedef struct AVDeviceInfo
{
    char *device_name;
    char *device_description;
} AVDeviceInfo;

typedef struct AVDeviceInfoList
{
    AVDeviceInfo **devices;
    int nb_devices;
    int default_device;
} AVDeviceInfoList;

// when used for filters they must have an odd number of elements
// coeffs cannot be shared between vectors
typedef struct SwsVector
{
    double *coeff; ///< pointer to the list of coefficients
    int length;    ///< number of coefficients in the vector
} SwsVector;
// vectors can be shared
typedef struct SwsFilter
{
    SwsVector *lumH;
    SwsVector *lumV;
    SwsVector *chrH;
    SwsVector *chrV;
} SwsFilter;

enum SwrDitherType
{
    SWR_DITHER_NONE = 0,
    SWR_DITHER_RECTANGULAR,
    SWR_DITHER_TRIANGULAR,
    SWR_DITHER_TRIANGULAR_HIGHPASS,
    SWR_DITHER_NS = 64, ///< not part of API/ABI
    SWR_DITHER_NS_LIPSHITZ,
    SWR_DITHER_NS_F_WEIGHTED,
    SWR_DITHER_NS_MODIFIED_E_WEIGHTED,
    SWR_DITHER_NS_IMPROVED_E_WEIGHTED,
    SWR_DITHER_NS_SHIBATA,
    SWR_DITHER_NS_LOW_SHIBATA,
    SWR_DITHER_NS_HIGH_SHIBATA,
    SWR_DITHER_NB, ///< not part of API/ABI
};

enum SwrEngine
{
    SWR_ENGINE_SWR,
    SWR_ENGINE_SOXR,
    SWR_ENGINE_NB, ///< not part of API/ABI
};

enum SwrFilterType
{
    SWR_FILTER_TYPE_CUBIC,
    SWR_FILTER_TYPE_BLACKMAN_NUTTALL,
    SWR_FILTER_TYPE_KAISER,
};



typedef void (mix_1_1_func_type)(void *out, const void *in, void *coeffp, integer index, integer len);
typedef void (mix_2_1_func_type)(void *out, const void *in1, const void *in2, void *coeffp, integer index1, integer index2, integer len);
typedef void (mix_any_func_type)(uint8_t **out, const uint8_t **in1, void *coeffp, integer len);

struct SWresampleDitherContext {
    int method;
    int noise_pos;
    float scale;
    float noise_scale;                              ///< Noise scale
    int ns_taps;                                    ///< Noise shaping dither taps
    float ns_scale;                                 ///< Noise shaping dither scale
    float ns_scale_1;                               ///< Noise shaping dither scale^-1
    int ns_pos;                                     ///< Noise shaping dither position
    float ns_coeffs[NS_TAPS];                       ///< Noise shaping filter coefficients
    float ns_errors[SWR_CH_MAX][2*NS_TAPS];
    SWresampleAudioData noise;                                ///< noise used for dithering
    SWresampleAudioData temp;                                 ///< temporary storage when writing into the input buffer isn't possible
    int output_sample_bits;                         ///< the number of used output bits, needed to scale dither correctly
};

struct SwrContext {
    const AVClass *av_class;                        ///< AVClass used for AVOption and av_log()
    int log_level_offset;                           ///< logging level offset
    void *log_ctx;                                  ///< parent logging context
    enum AVSampleFormat  in_sample_fmt;             ///< input sample format
    enum AVSampleFormat int_sample_fmt;             ///< internal sample format (AV_SAMPLE_FMT_FLTP or AV_SAMPLE_FMT_S16P)
    enum AVSampleFormat out_sample_fmt;             ///< output sample format
    int64_t  in_ch_layout;                          ///< input channel layout
    int64_t out_ch_layout;                          ///< output channel layout
    int      in_sample_rate;                        ///< input sample rate
    int     out_sample_rate;                        ///< output sample rate
    int flags;                                      ///< miscellaneous flags such as SWR_FLAG_RESAMPLE
    float slev;                                     ///< surround mixing level
    float clev;                                     ///< center mixing level
    float lfe_mix_level;                            ///< LFE mixing level
    float rematrix_volume;                          ///< rematrixing volume coefficient
    float rematrix_maxval;                          ///< maximum value for rematrixing output
    int matrix_encoding;                            /**< matrixed stereo encoding */
    const int *channel_map;                         ///< channel index (or -1 if muted channel) map
    int used_ch_count;                              ///< number of used input channels (mapped channel count if channel_map, otherwise in.ch_count)
    int engine;

    int user_in_ch_count;                           ///< User set input channel count
    int user_out_ch_count;                          ///< User set output channel count
    int user_used_ch_count;                         ///< User set used channel count
    int64_t user_in_ch_layout;                      ///< User set input channel layout
    int64_t user_out_ch_layout;                     ///< User set output channel layout
    enum AVSampleFormat user_int_sample_fmt;        ///< User set internal sample format
    int user_dither_method;                         ///< User set dither method

    struct SWresampleDitherContext dither;

    int filter_size;                                /**< length of each FIR filter in the resampling filterbank relative to the cutoff frequency */
    int phase_shift;                                /**< log2 of the number of entries in the resampling polyphase filterbank */
    int linear_interp;                              /**< if 1 then the resampling FIR filter will be linearly interpolated */
    int exact_rational;                             /**< if 1 then enable non power of 2 phase_count */
    double cutoff;                                  /**< resampling cutoff frequency (swr: 6dB point; soxr: 0dB point). 1.0 corresponds to half the output sample rate */
    int filter_type;                                /**< swr resampling filter type */
    double kaiser_beta;                                /**< swr beta value for Kaiser window (only applicable if filter_type == AV_FILTER_TYPE_KAISER) */
    double precision;                               /**< soxr resampling precision (in bits) */
    int cheby;                                      /**< soxr: if 1 then passband rolloff will be none (Chebyshev) & irrational ratio approximation precision will be higher */

    float min_compensation;                         ///< swr minimum below which no compensation will happen
    float min_hard_compensation;                    ///< swr minimum below which no silence inject / sample drop will happen
    float soft_compensation_duration;               ///< swr duration over which soft compensation is applied
    float max_soft_compensation;                    ///< swr maximum soft compensation in seconds over soft_compensation_duration
    float async;                                    ///< swr simple 1 parameter async, similar to ffmpegs -async
    int64_t firstpts_in_samples;                    ///< swr first pts in samples

    int resample_first;                             ///< 1 if resampling must come first, 0 if rematrixing
    int rematrix;                                   ///< flag to indicate if rematrixing is needed (basically if input and output layouts mismatch)
    int rematrix_custom;                            ///< flag to indicate that a custom matrix has been defined

    SWresampleAudioData in;                                   ///< input audio data
    SWresampleAudioData postin;                               ///< post-input audio data: used for rematrix/resample
    SWresampleAudioData midbuf;                               ///< intermediate audio data (postin/preout)
    SWresampleAudioData preout;                               ///< pre-output audio data: used for rematrix/resample
    SWresampleAudioData out;                                  ///< converted output audio data
    SWresampleAudioData in_buffer;                            ///< cached audio data (convert and resample purpose)
    SWresampleAudioData silence;                              ///< temporary with silence
    SWresampleAudioData drop_temp;                            ///< temporary used to discard output
    int in_buffer_index;                            ///< cached buffer position
    int in_buffer_count;                            ///< cached buffer length
    int resample_in_constraint;                     ///< 1 if the input end was reach before the output end, 0 otherwise
    int flushed;                                    ///< 1 if data is to be flushed and no further input is expected
    int64_t outpts;                                 ///< output PTS
    int64_t firstpts;                               ///< first PTS
    int drop_output;                                ///< number of output samples to drop
    double delayed_samples_fixup;                   ///< soxr 0.1.1: needed to fixup delayed_samples after flush has been called.

    struct SWresampleAudioConvert *in_convert;                ///< input conversion context
    struct SWresampleAudioConvert *out_convert;               ///< output conversion context
    struct SWresampleAudioConvert *full_convert;              ///< full conversion context (single conversion for input and output)
    struct ResampleContext *resample;               ///< resampling context
    struct Resampler const *resampler;              ///< resampler virtual function table

    double matrix[SWR_CH_MAX][SWR_CH_MAX];          ///< floating point rematrixing coefficients
    float matrix_flt[SWR_CH_MAX][SWR_CH_MAX];       ///< single precision floating point rematrixing coefficients
    uint8_t *native_matrix;
    uint8_t *native_one;
    uint8_t *native_simd_one;
    uint8_t *native_simd_matrix;
    int32_t matrix32[SWR_CH_MAX][SWR_CH_MAX];       ///< 17.15 fixed point rematrixing coefficients
    uint8_t matrix_ch[SWR_CH_MAX][SWR_CH_MAX+1];    ///< Lists of input channels per output channel that have non zero rematrixing coefficients
    mix_1_1_func_type *mix_1_1_f;
    mix_1_1_func_type *mix_1_1_simd;

    mix_2_1_func_type *mix_2_1_f;
    mix_2_1_func_type *mix_2_1_simd;

    mix_any_func_type *mix_any_f;

    /* TODO: callbacks for ASM optimizations */
};
typedef struct SwrContext SwrContext;


typedef struct ResampleContext * (* resample_init_func)(struct ResampleContext *c, int out_rate, int in_rate, int filter_size, int phase_shift, int linear,
                                    double cutoff, enum AVSampleFormat format, enum SwrFilterType filter_type, double kaiser_beta, double precision, int cheby, int exact_rational);
typedef void    (* resample_free_func)(struct ResampleContext **c);
typedef int     (* multiple_resample_func)(struct ResampleContext *c, SWresampleAudioData *dst, int dst_size, SWresampleAudioData *src, int src_size, int *consumed);
typedef int     (* resample_flush_func)(struct SwrContext *c);
typedef int     (* set_compensation_func)(struct ResampleContext *c, int sample_delta, int compensation_distance);
typedef int64_t (* get_delay_func)(struct SwrContext *s, int64_t base);
typedef int     (* invert_initial_buffer_func)(struct ResampleContext *c, SWresampleAudioData *dst, const SWresampleAudioData *src, int src_size, int *dst_idx, int *dst_count);
typedef int64_t (* get_out_samples_func)(struct SwrContext *s, int in_samples);

struct Resampler {
  resample_init_func            init;
  resample_free_func            free;
  multiple_resample_func        multiple_resample;
  resample_flush_func           flush;
  set_compensation_func         set_compensation;
  get_delay_func                get_delay;
  invert_initial_buffer_func    invert_initial_buffer;
  get_out_samples_func          get_out_samples;
};

extern struct Resampler const swri_resampler;
extern struct Resampler const swri_soxr_resampler;



static inline int av_clip_c(int a, int amin, int amax)
{
    if (a < amin)
        return amin;
    else if (a > amax)
        return amax;
    else
        return a;
}

static inline int64_t av_clip64_c(int64_t a, int64_t amin, int64_t amax)
{
    if (a < amin)
        return amin;
    else if (a > amax)
        return amax;
    else
        return a;
}

static inline uint8_t av_clip_uint8_c(int a)
{
    if (a & (~0xFF))
        return (~a) >> 31;
    else
        return a;
}

static inline int8_t av_clip_int8_c(int a)
{
    if ((a + 0x80U) & ~0xFF)
        return (a >> 31) ^ 0x7F;
    else
        return a;
}

static inline uint16_t av_clip_uint16_c(int a)
{
    if (a & (~0xFFFF))
        return (~a) >> 31;
    else
        return a;
}

static inline int16_t av_clip_int16_c(int a)
{
    if ((a + 0x8000U) & ~0xFFFF)
        return (a >> 31) ^ 0x7FFF;
    else
        return a;
}

static inline int32_t av_clipl_int32_c(int64_t a)
{
    if ((a + 0x80000000u) & ~0xFFFFFFFFULL)
        return (int32_t)((a >> 63) ^ 0x7FFFFFFF);
    else
        return (int32_t)a;
}

static inline int av_clip_intp2_c(int a, int p)
{
    if (((unsigned)a + (1 << p)) & ~((2 << p) - 1))
        return (a >> 31) ^ ((1 << p) - 1);
    else
        return a;
}

static inline unsigned av_clip_uintp2_c(int a, int p)
{
    if (a & ~((1 << p) - 1))
        return (~a) >> 31 & ((1 << p) - 1);
    else
        return a;
}

static inline unsigned av_mod_uintp2_c(unsigned a, unsigned p)
{
    return a & ((1U << p) - 1);
}

static inline int av_sat_add32_c(int a, int b)
{
    return av_clipl_int32_c((int64_t)a + b);
}

static inline int av_sat_dadd32_c(int a, int b)
{
    return av_sat_add32_c(a, av_sat_add32_c(b, b));
}

static inline int av_sat_sub32_c(int a, int b)
{
    return av_clipl_int32_c((int64_t)a - b);
}

static inline int av_sat_dsub32_c(int a, int b)
{
    return av_sat_sub32_c(a, av_sat_add32_c(b, b));
}

static inline int64_t av_sat_add64_c(int64_t a, int64_t b)
{
    int64_t tmp;
    return !__builtin_add_overflow(a, b, &tmp) ? tmp : (tmp < 0 ? 9223372036854775807LL : (-9223372036854775807LL - 1));
}

static inline int64_t av_sat_sub64_c(int64_t a, int64_t b)
{
    int64_t tmp;
    return !__builtin_sub_overflow(a, b, &tmp) ? tmp : (tmp < 0 ? 9223372036854775807LL : (-9223372036854775807LL - 1));
}

static inline float av_clipf_c(float a, float amin, float amax)
{
    if (a < amin)
        return amin;
    else if (a > amax)
        return amax;
    else
        return a;
}

static inline double av_clipd_c(double a, double amin, double amax)
{
    if (a < amin)
        return amin;
    else if (a > amax)
        return amax;
    else
        return a;
}
int av_log2(unsigned v);
static inline int av_ceil_log2_c(int x)
{
    return av_log2((x - 1U) << 1);
}

static inline int av_popcount_c(uint32_t x)
{
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x += x >> 8;
    return (x + (x >> 16)) & 0x3F;
}

static inline int av_popcount64_c(uint64_t x)
{
    return av_popcount_c((uint32_t)x) + av_popcount_c((uint32_t)(x >> 32));
}

static inline int av_parity_c(uint32_t v)
{
    return av_popcount_c(v) & 1;
}


static inline int av_size_mult(size_t a, size_t b, size_t *r)
{
    size_t t = a * b;
    if ((a | b) >= ((size_t)1 << (sizeof(size_t) * 4)) && a && t / a != b)
        return (-(22));
    *r = t;
    return 0;
}


static inline AVRational av_make_q(int num, int den)
{
    AVRational r = {num, den};
    return r;
}

static inline int av_cmp_q(AVRational a, AVRational b)
{
    const int64_t tmp = a.num * (int64_t)b.den - b.num * (int64_t)a.den;
    if (tmp)
        return (int)((tmp ^ a.den ^ b.den) >> 63) | 1;
    else if (b.den && a.den)
        return 0;
    else if (a.num && b.num)
        return (a.num >> 31) - (b.num >> 31);
    else
        return (-0x7fffffff - 1);
}

static inline double av_q2d(AVRational a)
{
    return a.num / (double)a.den;
}

static inline AVRational av_inv_q(AVRational q)
{
    AVRational r = {q.den, q.num};
    return r;
}

union av_intfloat32
{
    uint32_t i;
    float f;
};

union av_intfloat64
{
    uint64_t i;
    double f;
};

static inline float av_int2float(uint32_t i)
{
    union av_intfloat32 v;
    v.i = i;
    return v.f;
}

static inline uint32_t av_float2int(float f)
{
    union av_intfloat32 v;
    v.f = f;
    return v.i;
}

static inline double av_int2double(uint64_t i)
{
    union av_intfloat64 v;
    v.i = i;
    return v.f;
}

static inline uint64_t av_double2int(double f)
{
    union av_intfloat64 v;
    v.f = f;
    return v.i;
}


int av_escape(char **dst, const char *src, const char *special_chars, enum AVEscapeMode mode, int flags);
const char *av_get_media_type_string(enum AVMediaType media_type);
int av_strstart(const char *str, const char *pfx, const char **ptr);
int av_stristart(const char *str, const char *pfx, const char **ptr);
char *av_stristr(const char *haystack, const char *needle);
char *av_strnstr(const char *haystack, const char *needle, size_t hay_length);
size_t av_strlcpy(char *dst, const char *src, size_t size);
size_t av_strlcat(char *dst, const char *src, size_t size);
size_t av_strlcatf(char *dst, size_t size, const char *fmt, ...);
char *av_asprintf(const char *fmt, ...);
char *av_d2str(double d);
char *av_get_token(const char **buf, const char *term);
char *av_strtok(char *s, const char *delim, char **saveptr);
int av_strcasecmp(const char *a, const char *b);
int av_strncasecmp(const char *a, const char *b, size_t n);
char *av_strireplace(const char *str, const char *from, const char *to);
const char *av_basename(const char *path);
const char *av_dirname(char *path);
int av_match_name(const char *name, const char *names);
char *av_append_path_component(const char *path, const char *component);
int av_utf8_decode(int32_t *codep, const uint8_t **bufp, const uint8_t *buf_end,unsigned int flags);
int av_match_list(const char *name, const char *list, char separator);
int av_sscanf(const char *string, const char *format, ...);
unsigned avutil_version(void);
const char *av_version_info(void);
const char *avutil_configuration(void);
const char *avutil_license(void);
char av_get_picture_type_char(enum AVPictureType pict_type);
int av_log2_16bit(unsigned v);
int av_strerror(int errnum, char *errbuf, size_t errbuf_size);
void *av_malloc(size_t size);
void *av_mallocz(size_t size);
void *av_malloc_array(size_t nmemb, size_t size);
void *av_mallocz_array(size_t nmemb, size_t size);
void *av_calloc(size_t nmemb, size_t size);
void *av_realloc(void *ptr, size_t size);
int av_reallocp(void *ptr, size_t size);
void *av_realloc_f(void *ptr, size_t nelem, size_t elsize);
void *av_realloc_array(void *ptr, size_t nmemb, size_t size);
int av_reallocp_array(void *ptr, size_t nmemb, size_t size);
void *av_fast_realloc(void *ptr, unsigned int *size, size_t min_size);
void av_fast_malloc(void *ptr, unsigned int *size, size_t min_size);
void av_fast_mallocz(void *ptr, unsigned int *size, size_t min_size);
void av_free(void *ptr);
void av_freep(void *ptr);
char *av_strdup(const char *s);
char *av_strndup(const char *s, size_t len);
void *av_memdup(const void *p, size_t size);
void av_memcpy_backptr(uint8_t *dst, int back, int cnt);
void av_dynarray_add(void *tab_ptr, int *nb_ptr, void *elem);
int av_dynarray_add_nofree(void *tab_ptr, int *nb_ptr, void *elem);
void *av_dynarray2_add(void **tab_ptr, int *nb_ptr, size_t elem_size,const uint8_t *elem_data);
void av_max_alloc(size_t max);
int av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max);
AVRational av_mul_q(AVRational b, AVRational c);
AVRational av_div_q(AVRational b, AVRational c);
AVRational av_add_q(AVRational b, AVRational c);
AVRational av_sub_q(AVRational b, AVRational c);
AVRational av_d2q(double d, int max);
int av_nearer_q(AVRational q, AVRational q1, AVRational q2);
int av_find_nearest_q_idx(AVRational q, const AVRational *q_list);
uint32_t av_q2intfloat(AVRational q);
AVRational av_gcd_q(AVRational a, AVRational b, int max_den, AVRational def);

static inline char *av_make_error_string(char *errbuf, size_t errbuf_size, int errnum)
{
    av_strerror(errnum, errbuf, errbuf_size);
    return errbuf;
}
int64_t av_gcd(int64_t a, int64_t b);

int64_t av_rescale(int64_t a, int64_t b, int64_t c);

int64_t av_rescale_rnd(int64_t a, int64_t b, int64_t c, enum AVRounding rnd);

int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq);

int64_t av_rescale_q_rnd(int64_t a, AVRational bq, AVRational cq,
                         enum AVRounding rnd);

int av_compare_ts(int64_t ts_a, AVRational tb_a, int64_t ts_b, AVRational tb_b);

int64_t av_compare_mod(uint64_t a, uint64_t b, uint64_t mod);

int64_t av_rescale_delta(AVRational in_tb, int64_t in_ts, AVRational fs_tb, int duration, int64_t *last, AVRational out_tb);

int64_t av_add_stable(AVRational ts_tb, int64_t ts, AVRational inc_tb, int64_t inc);

void av_log(void *avcl, int level, const char *fmt, ...);

void av_log_once(void *avcl, int initial_level, int subsequent_level, int *state, const char *fmt, ...);

void av_vlog(void *avcl, int level, const char *fmt, va_list vl);

int av_log_get_level(void);

void av_log_set_level(int level);

void av_log_set_callback(void (*callback)(void *, int, const char *, va_list));

void av_log_default_callback(void *avcl, int level, const char *fmt,va_list vl);

const char *av_default_item_name(void *ptr)
{
    return (*(AVClass **) ptr)->class_name;
}
AVClassCategory av_default_get_category(void *ptr);

void av_log_format_line(void *ptr, int level, const char *fmt, va_list vl,char *line, int line_size, int *print_prefix);

int av_log_format_line2(void *ptr, int level, const char *fmt, va_list vl,char *line, int line_size, int *print_prefix);
void av_log_set_flags(int arg);
int av_log_get_flags(void);

static inline void *av_x_if_null(const void *p, const void *x)
{
    return (void *)(intptr_t)(p ? p : x);
}



const char *av_get_sample_fmt_name(enum AVSampleFormat sample_fmt);

enum AVSampleFormat av_get_sample_fmt(const char *name);

enum AVSampleFormat av_get_alt_sample_fmt(enum AVSampleFormat sample_fmt, int planar);

enum AVSampleFormat av_get_packed_sample_fmt(enum AVSampleFormat sample_fmt);

enum AVSampleFormat av_get_planar_sample_fmt(enum AVSampleFormat sample_fmt);
char *av_get_sample_fmt_string(char *buf, int buf_size, enum AVSampleFormat sample_fmt);

int av_get_bytes_per_sample(enum AVSampleFormat sample_fmt);

int av_sample_fmt_is_planar(enum AVSampleFormat sample_fmt);

int av_samples_get_buffer_size(int *linesize, int nb_channels, int nb_samples,
                               enum AVSampleFormat sample_fmt, int align);
int av_samples_fill_arrays(uint8_t **audio_data, int *linesize,
                           const uint8_t *buf,
                           int nb_channels, int nb_samples,
                           enum AVSampleFormat sample_fmt, int align);
int av_samples_alloc(uint8_t **audio_data, int *linesize, int nb_channels,
                     int nb_samples, enum AVSampleFormat sample_fmt, int align);

int av_samples_alloc_array_and_samples(uint8_t ***audio_data, int *linesize, int nb_channels,
                                       int nb_samples, enum AVSampleFormat sample_fmt, int align);

int av_samples_copy(uint8_t **dst, uint8_t *const *src, int dst_offset,
                    int src_offset, int nb_samples, int nb_channels,
                    enum AVSampleFormat sample_fmt);

int av_samples_set_silence(uint8_t **audio_data, int offset, int nb_samples,
                           int nb_channels, enum AVSampleFormat sample_fmt);
#define AVUTIL_AVASSERT_H
#define av_assert0(cond)                                                                                          \
    do                                                                                                            \
    {                                                                                                             \
        if (!(cond))                                                                                              \
        {                                                                                                         \
            av_log(NULL, AV_LOG_PANIC, "Assertion %s failed at %s:%d\n", AV_STRINGIFY(cond), __FILE__, __LINE__); \
            abort();                                                                                              \
        }                                                                                                         \
    } while (0)
#define av_assert1(cond) ((void)0)
#define av_assert2(cond) ((void)0)
#define av_assert2_fpu() ((void)0)

static inline int ff_fast_malloc(void *ptr, unsigned int *size, size_t min_size, int zero_realloc)
{
    void *val;

    memcpy(&val, ptr, sizeof(val));
    if (min_size <= *size) {
        av_assert0(val || !min_size);
        return 0;
    }
    min_size = FFMAX(min_size + min_size / 16 + 32, min_size);
    av_freep(ptr);
    val = zero_realloc ? av_mallocz(min_size) : av_malloc(min_size);
    memcpy(ptr, &val, sizeof(val));
    if (!val)
        min_size = 0;
    *size = min_size;
    return 1;
}

void av_assert0_fpu(void);
#define AVUTIL_TIME_H

int64_t av_gettime(void);

int64_t av_gettime_relative(void);

int av_gettime_relative_is_monotonic(void);

int av_usleep(unsigned usec);
#define FF_PAD_STRUCTURE(name, size, ...)                                              \
    struct ff_pad_helper_##name                                                        \
    {                                                                                  \
        __VA_ARGS__                                                                    \
    };                                                                                 \
    typedef struct name                                                                \
    {                                                                                  \
        __VA_ARGS__ char reserved_padding[size - sizeof(struct ff_pad_helper_##name)]; \
    } name;
#define AV_BPRINT_SIZE_UNLIMITED ((unsigned)-1)
#define AV_BPRINT_SIZE_AUTOMATIC 1
#define AV_BPRINT_SIZE_COUNT_ONLY 0

unsigned av_int_list_length_for_size(unsigned elsize, const void *list, uint64_t term);
#define av_int_list_length(list, term) av_int_list_length_for_size(sizeof(*(list)), list, term)

FILE *av_fopen_utf8(const char *path, const char *mode);
AVRational av_get_time_base_q(void);
int av_expr_parse_and_eval(double *res, const char *s,
                           const char *const *const_names, const double *const_values,
                           const char *const *func1_names, double (*const *funcs1)(void *, double),
                           const char *const *func2_names, double (*const *funcs2)(void *, double, double),
                           void *opaque, int log_offset, void *log_ctx);
int av_expr_parse(AVExpr **expr, const char *s,
                  const char *const *const_names,
                  const char *const *func1_names, double (*const *funcs1)(void *, double),
                  const char *const *func2_names, double (*const *funcs2)(void *, double, double),
                  int log_offset, void *log_ctx);
double av_expr_eval(AVExpr *e, const double *const_values, void *opaque);
int av_expr_count_vars(AVExpr *e, unsigned *counter, int size);
int av_expr_count_func(AVExpr *e, unsigned *counter, int size, int arg);
void av_expr_free(AVExpr *e);
double av_strtod(const char *numstr, char **tail);
char *av_fourcc_make_string(char *buf, uint32_t fourcc);

int av_get_bits_per_pixel(const AVPixFmtDescriptor *pixdesc);

int av_get_padded_bits_per_pixel(const AVPixFmtDescriptor *pixdesc);

const AVPixFmtDescriptor *av_pix_fmt_desc_get(enum AVPixelFormat pix_fmt);

const AVPixFmtDescriptor *av_pix_fmt_desc_next(const AVPixFmtDescriptor *prev);

enum AVPixelFormat av_pix_fmt_desc_get_id(const AVPixFmtDescriptor *desc);

int av_pix_fmt_get_chroma_sub_sample(enum AVPixelFormat pix_fmt,
                                     int *h_shift, int *v_shift);

int av_pix_fmt_count_planes(enum AVPixelFormat pix_fmt);

const char *av_color_range_name(enum AVColorRange range);

int av_color_range_from_name(const char *name);

const char *av_color_primaries_name(enum AVColorPrimaries primaries);

int av_color_primaries_from_name(const char *name);

const char *av_color_transfer_name(enum AVColorTransferCharacteristic transfer);

int av_color_transfer_from_name(const char *name);

const char *av_color_space_name(enum AVColorSpace space);

int av_color_space_from_name(const char *name);

const char *av_chroma_location_name(enum AVChromaLocation location);

int av_chroma_location_from_name(const char *name);

enum AVPixelFormat av_get_pix_fmt(const char *name);

const char *av_get_pix_fmt_name(enum AVPixelFormat pix_fmt);

char *av_get_pix_fmt_string(char *buf, int buf_size,
                            enum AVPixelFormat pix_fmt);

void av_read_image_line2(void *dst, const uint8_t *data[4],
                         const int linesize[4], const AVPixFmtDescriptor *desc,
                         int x, int y, int c, int w, int read_pal_component,
                         int dst_element_size);

void av_read_image_line(uint16_t *dst, const uint8_t *data[4],
                        const int linesize[4], const AVPixFmtDescriptor *desc,
                        int x, int y, int c, int w, int read_pal_component);

void av_write_image_line2(const void *src, uint8_t *data[4],
                          const int linesize[4], const AVPixFmtDescriptor *desc,
                          int x, int y, int c, int w, int src_element_size);

void av_write_image_line(const uint16_t *src, uint8_t *data[4],
                         const int linesize[4], const AVPixFmtDescriptor *desc,
                         int x, int y, int c, int w);

enum AVPixelFormat av_pix_fmt_swap_endianness(enum AVPixelFormat pix_fmt);

int av_get_pix_fmt_loss(enum AVPixelFormat dst_pix_fmt,
                        enum AVPixelFormat src_pix_fmt,
                        int has_alpha);

enum AVPixelFormat av_find_best_pix_fmt_of_2(enum AVPixelFormat dst_pix_fmt1, enum AVPixelFormat dst_pix_fmt2,
                                             enum AVPixelFormat src_pix_fmt, int has_alpha, int *loss_ptr);

void av_image_fill_max_pixsteps(int max_pixsteps[4], int max_pixstep_comps[4],
                                const AVPixFmtDescriptor *pixdesc);

int av_image_get_linesize(enum AVPixelFormat pix_fmt, int width, int plane);

int av_image_fill_linesizes(int linesizes[4], enum AVPixelFormat pix_fmt, int width);

int av_image_fill_plane_sizes(size_t size[4], enum AVPixelFormat pix_fmt,
                              int height, const ptrdiff_t linesizes[4]);

int av_image_fill_pointers(uint8_t *data[4], enum AVPixelFormat pix_fmt, int height,
                           uint8_t *ptr, const int linesizes[4]);

int av_image_alloc(uint8_t *pointers[4], int linesizes[4],
                   int w, int h, enum AVPixelFormat pix_fmt, int align);

void av_image_copy_plane(uint8_t *dst, int dst_linesize,
                         const uint8_t *src, int src_linesize,
                         int bytewidth, int height);

void av_image_copy(uint8_t *dst_data[4], int dst_linesizes[4],
                   const uint8_t *src_data[4], const int src_linesizes[4],
                   enum AVPixelFormat pix_fmt, int width, int height);

void av_image_copy_uc_from(uint8_t *dst_data[4], const ptrdiff_t dst_linesizes[4],
                           const uint8_t *src_data[4], const ptrdiff_t src_linesizes[4],
                           enum AVPixelFormat pix_fmt, int width, int height);

int av_image_fill_arrays(uint8_t *dst_data[4], int dst_linesize[4],
                         const uint8_t *src,
                         enum AVPixelFormat pix_fmt, int width, int height, int align);

int av_image_get_buffer_size(enum AVPixelFormat pix_fmt, int width, int height, int align);

int av_image_copy_to_buffer(uint8_t *dst, int dst_size,
                            const uint8_t *const src_data[4], const int src_linesize[4],
                            enum AVPixelFormat pix_fmt, int width, int height, int align);

int av_image_check_size(unsigned int w, unsigned int h, int log_offset, void *log_ctx);

int av_image_check_size2(unsigned int w, unsigned int h, int64_t max_pixels, enum AVPixelFormat pix_fmt, int log_offset, void *log_ctx);

int av_image_check_sar(unsigned int w, unsigned int h, AVRational sar);

int av_image_fill_black(uint8_t *dst_data[4], const ptrdiff_t dst_linesize[4],
                        enum AVPixelFormat pix_fmt, enum AVColorRange range,
                        int width, int height);

AVDictionaryEntry *av_dict_get(const AVDictionary *m, const char *key, const AVDictionaryEntry *prev, int flags);

int av_dict_count(const AVDictionary *m);

int av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags);

int av_dict_set_int(AVDictionary **pm, const char *key, int64_t value, int flags);

int av_dict_parse_string(AVDictionary **pm, const char *str,
                         const char *key_val_sep, const char *pairs_sep,
                         int flags);

int av_dict_copy(AVDictionary **dst, const AVDictionary *src, int flags);

void av_dict_free(AVDictionary **m);

int av_dict_get_string(const AVDictionary *m, char **buffer,
                       const char key_val_sep, const char pairs_sep);

int av_parse_ratio(AVRational *q, const char *str, int max,
                   int log_offset, void *log_ctx);
#define av_parse_ratio_quiet(rate, str, max) av_parse_ratio(rate, str, max, AV_LOG_MAX_OFFSET, NULL)

int av_parse_video_size(int *width_ptr, int *height_ptr, const char *str);

int av_parse_video_rate(AVRational *rate, const char *str);

int av_parse_color(uint8_t *rgba_color, const char *color_string, int slen,
                   void *log_ctx);

const char *av_get_known_color_name(int color_idx, const uint8_t **rgb);

int av_parse_time(int64_t *timeval, const char *timestr, int duration);

int av_find_info_tag(char *arg, int arg_size, const char *tag1, const char *info);

char *av_small_strptime(const char *p, const char *fmt, struct tm *dt);

time_t av_timegm(struct tm *tm);
void av_bprint_init(AVBPrint *buf, unsigned size_init, unsigned size_max);

void av_bprint_init_for_buffer(AVBPrint *buf, char *buffer, unsigned size);

void av_bprintf(AVBPrint *buf, const char *fmt, ...);

void av_vbprintf(AVBPrint *buf, const char *fmt, va_list vl_arg);

void av_bprint_chars(AVBPrint *buf, char c, unsigned n);

void av_bprint_append_data(AVBPrint *buf, const char *data, unsigned size);

struct tm;

void av_bprint_strftime(AVBPrint *buf, const char *fmt, const struct tm *tm);

void av_bprint_get_buffer(AVBPrint *buf, unsigned size,
                          unsigned char **mem, unsigned *actual_size);

void av_bprint_clear(AVBPrint *buf);

static inline int av_bprint_is_complete(const AVBPrint *buf)
{
    return buf->len < buf->size;
}

int av_bprint_finalize(AVBPrint *buf, char **ret_str);
void av_bprint_escape(AVBPrint *dstbuf, const char *src, const char *special_chars,
                      enum AVEscapeMode mode, int flags);
#define AVFORMAT_AVFORMAT_H

AVBufferRef *av_buffer_alloc(int size);

AVBufferRef *av_buffer_allocz(int size);
#define AV_BUFFER_FLAG_READONLY (1 << 0)

#define AV_CPU_FLAG_FORCE 0x80000000
#define AV_CPU_FLAG_MMX 0x0001
#define AV_CPU_FLAG_MMXEXT 0x0002
#define AV_CPU_FLAG_MMX2 0x0002
#define AV_CPU_FLAG_3DNOW 0x0004
#define AV_CPU_FLAG_SSE 0x0008
#define AV_CPU_FLAG_SSE2 0x0010
#define AV_CPU_FLAG_SSE2SLOW 0x40000000
///< than regular MMX/SSE (e.g. Core1)
#define AV_CPU_FLAG_3DNOWEXT 0x0020
#define AV_CPU_FLAG_SSE3 0x0040
#define AV_CPU_FLAG_SSE3SLOW 0x20000000
///< than regular MMX/SSE (e.g. Core1)
#define AV_CPU_FLAG_SSSE3 0x0080
#define AV_CPU_FLAG_SSSE3SLOW 0x4000000
#define AV_CPU_FLAG_ATOM 0x10000000
#define AV_CPU_FLAG_SSE4 0x0100
#define AV_CPU_FLAG_SSE42 0x0200
#define AV_CPU_FLAG_AESNI 0x80000
#define AV_CPU_FLAG_AVX 0x4000
#define AV_CPU_FLAG_AVXSLOW 0x8000000
#define AV_CPU_FLAG_XOP 0x0400
#define AV_CPU_FLAG_FMA4 0x0800
#define AV_CPU_FLAG_CMOV 0x1000
#define AV_CPU_FLAG_AVX2 0x8000
#define AV_CPU_FLAG_FMA3 0x10000
#define AV_CPU_FLAG_BMI1 0x20000
#define AV_CPU_FLAG_BMI2 0x40000
#define AV_CPU_FLAG_AVX512 0x100000
#define AV_CPU_FLAG_ALTIVEC 0x0001
#define AV_CPU_FLAG_VSX 0x0002
#define AV_CPU_FLAG_POWER8 0x0004
#define AV_CPU_FLAG_ARMV5TE (1 << 0)
#define AV_CPU_FLAG_ARMV6 (1 << 1)
#define AV_CPU_FLAG_ARMV6T2 (1 << 2)
#define AV_CPU_FLAG_VFP (1 << 3)
#define AV_CPU_FLAG_VFPV3 (1 << 4)
#define AV_CPU_FLAG_NEON (1 << 5)
#define AV_CPU_FLAG_ARMV8 (1 << 6)
#define AV_CPU_FLAG_VFP_VM (1 << 7)
#define AV_CPU_FLAG_SETEND (1 << 16)
#define AV_CPU_FLAG_MMI (1 << 0)
#define AV_CPU_FLAG_MSA (1 << 1)


#define AVUTIL_CHANNEL_LAYOUT_H
#define AV_CH_FRONT_LEFT 0x00000001
#define AV_CH_FRONT_RIGHT 0x00000002
#define AV_CH_FRONT_CENTER 0x00000004
#define AV_CH_LOW_FREQUENCY 0x00000008
#define AV_CH_BACK_LEFT 0x00000010
#define AV_CH_BACK_RIGHT 0x00000020
#define AV_CH_FRONT_LEFT_OF_CENTER 0x00000040
#define AV_CH_FRONT_RIGHT_OF_CENTER 0x00000080
#define AV_CH_BACK_CENTER 0x00000100
#define AV_CH_SIDE_LEFT 0x00000200
#define AV_CH_SIDE_RIGHT 0x00000400
#define AV_CH_TOP_CENTER 0x00000800
#define AV_CH_TOP_FRONT_LEFT 0x00001000
#define AV_CH_TOP_FRONT_CENTER 0x00002000
#define AV_CH_TOP_FRONT_RIGHT 0x00004000
#define AV_CH_TOP_BACK_LEFT 0x00008000
#define AV_CH_TOP_BACK_CENTER 0x00010000
#define AV_CH_TOP_BACK_RIGHT 0x00020000
#define AV_CH_STEREO_LEFT 0x20000000
#define AV_CH_STEREO_RIGHT 0x40000000
#define AV_CH_WIDE_LEFT 0x0000000080000000ULL
#define AV_CH_WIDE_RIGHT 0x0000000100000000ULL
#define AV_CH_SURROUND_DIRECT_LEFT 0x0000000200000000ULL
#define AV_CH_SURROUND_DIRECT_RIGHT 0x0000000400000000ULL
#define AV_CH_LOW_FREQUENCY_2 0x0000000800000000ULL
#define AV_CH_TOP_SIDE_LEFT 0x0000001000000000ULL
#define AV_CH_TOP_SIDE_RIGHT 0x0000002000000000ULL
#define AV_CH_BOTTOM_FRONT_CENTER 0x0000004000000000ULL
#define AV_CH_BOTTOM_FRONT_LEFT 0x0000008000000000ULL
#define AV_CH_BOTTOM_FRONT_RIGHT 0x0000010000000000ULL
#define AV_CH_LAYOUT_NATIVE 0x8000000000000000ULL
#define AV_CH_LAYOUT_MONO (AV_CH_FRONT_CENTER)
#define AV_CH_LAYOUT_STEREO (AV_CH_FRONT_LEFT | AV_CH_FRONT_RIGHT)
#define AV_CH_LAYOUT_2POINT1 (AV_CH_LAYOUT_STEREO | AV_CH_LOW_FREQUENCY)
#define AV_CH_LAYOUT_2_1 (AV_CH_LAYOUT_STEREO | AV_CH_BACK_CENTER)
#define AV_CH_LAYOUT_SURROUND (AV_CH_LAYOUT_STEREO | AV_CH_FRONT_CENTER)
#define AV_CH_LAYOUT_3POINT1 (AV_CH_LAYOUT_SURROUND | AV_CH_LOW_FREQUENCY)
#define AV_CH_LAYOUT_4POINT0 (AV_CH_LAYOUT_SURROUND | AV_CH_BACK_CENTER)
#define AV_CH_LAYOUT_4POINT1 (AV_CH_LAYOUT_4POINT0 | AV_CH_LOW_FREQUENCY)
#define AV_CH_LAYOUT_2_2 (AV_CH_LAYOUT_STEREO | AV_CH_SIDE_LEFT | AV_CH_SIDE_RIGHT)
#define AV_CH_LAYOUT_QUAD (AV_CH_LAYOUT_STEREO | AV_CH_BACK_LEFT | AV_CH_BACK_RIGHT)
#define AV_CH_LAYOUT_5POINT0 (AV_CH_LAYOUT_SURROUND | AV_CH_SIDE_LEFT | AV_CH_SIDE_RIGHT)
#define AV_CH_LAYOUT_5POINT1 (AV_CH_LAYOUT_5POINT0 | AV_CH_LOW_FREQUENCY)
#define AV_CH_LAYOUT_5POINT0_BACK (AV_CH_LAYOUT_SURROUND | AV_CH_BACK_LEFT | AV_CH_BACK_RIGHT)
#define AV_CH_LAYOUT_5POINT1_BACK (AV_CH_LAYOUT_5POINT0_BACK | AV_CH_LOW_FREQUENCY)
#define AV_CH_LAYOUT_6POINT0 (AV_CH_LAYOUT_5POINT0 | AV_CH_BACK_CENTER)
#define AV_CH_LAYOUT_6POINT0_FRONT (AV_CH_LAYOUT_2_2 | AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER)
#define AV_CH_LAYOUT_HEXAGONAL (AV_CH_LAYOUT_5POINT0_BACK | AV_CH_BACK_CENTER)
#define AV_CH_LAYOUT_6POINT1 (AV_CH_LAYOUT_5POINT1 | AV_CH_BACK_CENTER)
#define AV_CH_LAYOUT_6POINT1_BACK (AV_CH_LAYOUT_5POINT1_BACK | AV_CH_BACK_CENTER)
#define AV_CH_LAYOUT_6POINT1_FRONT (AV_CH_LAYOUT_6POINT0_FRONT | AV_CH_LOW_FREQUENCY)
#define AV_CH_LAYOUT_7POINT0 (AV_CH_LAYOUT_5POINT0 | AV_CH_BACK_LEFT | AV_CH_BACK_RIGHT)
#define AV_CH_LAYOUT_7POINT0_FRONT (AV_CH_LAYOUT_5POINT0 | AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER)
#define AV_CH_LAYOUT_7POINT1 (AV_CH_LAYOUT_5POINT1 | AV_CH_BACK_LEFT | AV_CH_BACK_RIGHT)
#define AV_CH_LAYOUT_7POINT1_WIDE (AV_CH_LAYOUT_5POINT1 | AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER)
#define AV_CH_LAYOUT_7POINT1_WIDE_BACK (AV_CH_LAYOUT_5POINT1_BACK | AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER)
#define AV_CH_LAYOUT_OCTAGONAL (AV_CH_LAYOUT_5POINT0 | AV_CH_BACK_LEFT | AV_CH_BACK_CENTER | AV_CH_BACK_RIGHT)
#define AV_CH_LAYOUT_HEXADECAGONAL (AV_CH_LAYOUT_OCTAGONAL | AV_CH_WIDE_LEFT | AV_CH_WIDE_RIGHT | AV_CH_TOP_BACK_LEFT | AV_CH_TOP_BACK_RIGHT | AV_CH_TOP_BACK_CENTER | AV_CH_TOP_FRONT_CENTER | AV_CH_TOP_FRONT_LEFT | AV_CH_TOP_FRONT_RIGHT)
#define AV_CH_LAYOUT_STEREO_DOWNMIX (AV_CH_STEREO_LEFT | AV_CH_STEREO_RIGHT)
#define AV_CH_LAYOUT_22POINT2 (AV_CH_LAYOUT_5POINT1_BACK | AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER | AV_CH_BACK_CENTER | AV_CH_LOW_FREQUENCY_2 | AV_CH_SIDE_LEFT | AV_CH_SIDE_RIGHT | AV_CH_TOP_FRONT_LEFT | AV_CH_TOP_FRONT_RIGHT | AV_CH_TOP_FRONT_CENTER | AV_CH_TOP_CENTER | AV_CH_TOP_BACK_LEFT | AV_CH_TOP_BACK_RIGHT | AV_CH_TOP_SIDE_LEFT | AV_CH_TOP_SIDE_RIGHT | AV_CH_TOP_BACK_CENTER | AV_CH_BOTTOM_FRONT_CENTER | AV_CH_BOTTOM_FRONT_LEFT | AV_CH_BOTTOM_FRONT_RIGHT)


uint64_t av_get_channel_layout(const char *name);
int av_get_extended_channel_layout(const char *name, uint64_t *channel_layout, int *nb_channels);

void av_get_channel_layout_string(char *buf, int buf_size, int nb_channels, uint64_t channel_layout);

struct AVBPrint;

void av_bprint_channel_layout(struct AVBPrint *bp, int nb_channels, uint64_t channel_layout);

int av_get_channel_layout_nb_channels(uint64_t channel_layout);

int64_t av_get_default_channel_layout(int nb_channels);

int av_get_channel_layout_channel_index(uint64_t channel_layout,
                                        uint64_t channel);

uint64_t av_channel_layout_extract_channel(uint64_t channel_layout, int index);

const char *av_get_channel_name(uint64_t channel);

const char *av_get_channel_description(uint64_t channel);

int av_get_standard_channel_layout(unsigned index, uint64_t *layout,
                                   const char **name);
AVBufferRef *av_buffer_create(uint8_t *data, int size,
                              void (*free)(void *opaque, uint8_t *data),
                              void *opaque, int flags);

void av_buffer_default_free(void *opaque, uint8_t *data);

AVBufferRef *av_buffer_ref(AVBufferRef *buf);

void av_buffer_unref(AVBufferRef **buf);

int av_buffer_is_writable(const AVBufferRef *buf);

void *av_buffer_get_opaque(const AVBufferRef *buf);

int av_buffer_get_ref_count(const AVBufferRef *buf);

int av_buffer_make_writable(AVBufferRef **buf);
int av_buffer_realloc(AVBufferRef **buf, int size);
int av_buffer_replace(AVBufferRef **dst, AVBufferRef *src);


AVBufferPool *av_buffer_pool_init(int size, AVBufferRef *(*alloc)(int size));
AVBufferPool *av_buffer_pool_init2(int size, void *opaque,
                                   AVBufferRef *(*alloc)(void *opaque, int size),
                                   void (*pool_free)(void *opaque));

void av_buffer_pool_uninit(AVBufferPool **pool);

AVBufferRef *av_buffer_pool_get(AVBufferPool *pool);

void *av_buffer_pool_buffer_get_opaque(AVBufferRef *ref);
int av_get_cpu_flags(void);

void av_force_cpu_flags(int flags);

void av_set_cpu_flags_mask(int mask);

int av_parse_cpu_flags(const char *s);

int av_parse_cpu_caps(unsigned *flags, const char *s);

int av_cpu_count(void);

size_t av_cpu_max_align(void);

int64_t av_frame_get_best_effort_timestamp(const AVFrame *frame);

void av_frame_set_best_effort_timestamp(AVFrame *frame, int64_t val);

int64_t av_frame_get_pkt_duration(const AVFrame *frame);

void av_frame_set_pkt_duration(AVFrame *frame, int64_t val);

int64_t av_frame_get_pkt_pos(const AVFrame *frame);

void av_frame_set_pkt_pos(AVFrame *frame, int64_t val);

int64_t av_frame_get_channel_layout(const AVFrame *frame);

void av_frame_set_channel_layout(AVFrame *frame, int64_t val);

int av_frame_get_channels(const AVFrame *frame);

void av_frame_set_channels(AVFrame *frame, int val);

int av_frame_get_sample_rate(const AVFrame *frame);

void av_frame_set_sample_rate(AVFrame *frame, int val);

AVDictionary *av_frame_get_metadata(const AVFrame *frame);

void av_frame_set_metadata(AVFrame *frame, AVDictionary *val);

int av_frame_get_decode_error_flags(const AVFrame *frame);

void av_frame_set_decode_error_flags(AVFrame *frame, int val);

int av_frame_get_pkt_size(const AVFrame *frame);

void av_frame_set_pkt_size(AVFrame *frame, int val);

int8_t *av_frame_get_qp_table(AVFrame *f, int *stride, int *type);

int av_frame_set_qp_table(AVFrame *f, AVBufferRef *buf, int stride, int type);

enum AVColorSpace av_frame_get_colorspace(const AVFrame *frame);

void av_frame_set_colorspace(AVFrame *frame, enum AVColorSpace val);

enum AVColorRange av_frame_get_color_range(const AVFrame *frame);

void av_frame_set_color_range(AVFrame *frame, enum AVColorRange val);

const char *av_get_colorspace_name(enum AVColorSpace val);

AVFrame *av_frame_alloc(void);

void av_frame_free(AVFrame **frame);
int av_frame_ref(AVFrame *dst, const AVFrame *src);

AVFrame *av_frame_clone(const AVFrame *src);

void av_frame_unref(AVFrame *frame);

void av_frame_move_ref(AVFrame *dst, AVFrame *src);
int av_frame_get_buffer(AVFrame *frame, int align);
int av_frame_is_writable(AVFrame *frame);

int av_frame_make_writable(AVFrame *frame);

int av_frame_copy(AVFrame *dst, const AVFrame *src);

int av_frame_copy_props(AVFrame *dst, const AVFrame *src);

AVBufferRef *av_frame_get_plane_buffer(AVFrame *frame, int plane);

AVFrameSideData *av_frame_new_side_data(AVFrame *frame,
                                        enum AVFrameSideDataType type,
                                        int size);
AVFrameSideData *av_frame_new_side_data_from_buf(AVFrame *frame,
                                                 enum AVFrameSideDataType type,
                                                 AVBufferRef *buf);

AVFrameSideData *av_frame_get_side_data(const AVFrame *frame,
                                        enum AVFrameSideDataType type);

void av_frame_remove_side_data(AVFrame *frame, enum AVFrameSideDataType type);


int av_frame_apply_cropping(AVFrame *frame, int flags);

const char *av_frame_side_data_name(enum AVFrameSideDataType type);



enum AVHWDeviceType av_hwdevice_find_type_by_name(const char *name);
const char *av_hwdevice_get_type_name(enum AVHWDeviceType type);

enum AVHWDeviceType av_hwdevice_iterate_types(enum AVHWDeviceType prev);

AVBufferRef *av_hwdevice_ctx_alloc(enum AVHWDeviceType type);

int av_hwdevice_ctx_init(AVBufferRef *ref);
int av_hwdevice_ctx_create(AVBufferRef **device_ctx, enum AVHWDeviceType type,
                           const char *device, AVDictionary *opts, int flags);
int av_hwdevice_ctx_create_derived(AVBufferRef **dst_ctx,
                                   enum AVHWDeviceType type,
                                   AVBufferRef *src_ctx, int flags);
int av_hwdevice_ctx_create_derived_opts(AVBufferRef **dst_ctx,
                                        enum AVHWDeviceType type,
                                        AVBufferRef *src_ctx,
                                        AVDictionary *options, int flags);

AVBufferRef *av_hwframe_ctx_alloc(AVBufferRef *device_ctx);

int av_hwframe_ctx_init(AVBufferRef *ref);

int av_hwframe_get_buffer(AVBufferRef *hwframe_ctx, AVFrame *frame, int flags);
int av_hwframe_transfer_data(AVFrame *dst, const AVFrame *src, int flags);

enum AVHWFrameTransferDirection
{
    AV_HWFRAME_TRANSFER_DIRECTION_FROM,
    AV_HWFRAME_TRANSFER_DIRECTION_TO,
};
int av_hwframe_transfer_get_formats(AVBufferRef *hwframe_ctx,
                                    enum AVHWFrameTransferDirection dir,
                                    enum AVPixelFormat **formats, int flags);

typedef struct AVHWFramesConstraints
{
    enum AVPixelFormat *valid_hw_formats;
    enum AVPixelFormat *valid_sw_formats;
    int min_width;
    int min_height;
    int max_width;
    int max_height;
} AVHWFramesConstraints;

void *av_hwdevice_hwconfig_alloc(AVBufferRef *device_ctx);
AVHWFramesConstraints *av_hwdevice_get_hwframe_constraints(AVBufferRef *ref,
                                                           const void *hwconfig);

void av_hwframe_constraints_free(AVHWFramesConstraints **constraints);

enum
{
    AV_HWFRAME_MAP_READ = 1 << 0,
    AV_HWFRAME_MAP_WRITE = 1 << 1,
    AV_HWFRAME_MAP_OVERWRITE = 1 << 2,
    AV_HWFRAME_MAP_DIRECT = 1 << 3,
};
int av_hwframe_map(AVFrame *dst, const AVFrame *src, int flags);
int av_hwframe_ctx_create_derived(AVBufferRef **derived_frame_ctx,
                                  enum AVPixelFormat format,
                                  AVBufferRef *derived_device_ctx,
                                  AVBufferRef *source_frame_ctx,
                                  int flags);
#define AVCODEC_BSF_H
#define AVCODEC_CODEC_ID_H
#define AV_CODEC_ID_IFF_BYTERUN1 AV_CODEC_ID_IFF_ILBM
#define AV_CODEC_ID_H265 AV_CODEC_ID_HEVC


enum AVMediaType avcodec_get_type(enum AVCodecID codec_id);

const char *avcodec_get_name(enum AVCodecID id);
#define AV_NUM_DATA_POINTERS 8
#define AV_FRAME_FLAG_CORRUPT (1 << 0)
#define AV_FRAME_FLAG_DISCARD (1 << 2)
#define FF_DECODE_ERROR_INVALID_BITSTREAM 1
#define FF_DECODE_ERROR_MISSING_REFERENCE 2
#define FF_DECODE_ERROR_CONCEALMENT_ACTIVE 4
#define FF_DECODE_ERROR_DECODE_SLICES 8



AVCodecParameters *avcodec_parameters_alloc(void);

void avcodec_parameters_free(AVCodecParameters **par);

int avcodec_parameters_copy(AVCodecParameters *dst, const AVCodecParameters *src);
#define AVCODEC_PACKET_H
#define AVCODEC_VERSION_H
#define LIBAVCODEC_VERSION_MAJOR 58
#define LIBAVCODEC_VERSION_MINOR 112
#define LIBAVCODEC_VERSION_MICRO 100
#define LIBAVCODEC_VERSION_INT AV_VERSION_INT(LIBAVCODEC_VERSION_MAJOR, LIBAVCODEC_VERSION_MINOR, LIBAVCODEC_VERSION_MICRO)
#define LIBAVCODEC_VERSION AV_VERSION(LIBAVCODEC_VERSION_MAJOR, LIBAVCODEC_VERSION_MINOR, LIBAVCODEC_VERSION_MICRO)
#define LIBAVCODEC_BUILD LIBAVCODEC_VERSION_INT
// #define LIBAVCODEC_IDENT "Lavc" AV_STRINGIFY(LIBAVCODEC_VERSION)
#define FF_API_LOWRES (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_DEBUG_MV (LIBAVCODEC_VERSION_MAJOR < 58)
#define FF_API_AVCTX_TIMEBASE (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_CODED_FRAME (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_SIDEDATA_ONLY_PKT (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_VDPAU_PROFILE (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_CONVERGENCE_DURATION (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_AVPICTURE (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_AVPACKET_OLD_API (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_RTP_CALLBACK (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_VBV_DELAY (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_CODER_TYPE (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_STAT_BITS (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_PRIVATE_OPT (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_ASS_TIMING (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_OLD_BSF (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_COPY_CONTEXT (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_GET_CONTEXT_DEFAULTS (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_NVENC_OLD_NAME (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_STRUCT_VAAPI_CONTEXT (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_MERGE_SD_API (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_TAG_STRING (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_GETCHROMA (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_CODEC_GET_SET (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_USER_VISIBLE_AVHWACCEL (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_LOCKMGR (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_NEXT (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_UNSANITIZED_BITRATES (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_OPENH264_SLICE_MODE (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_OPENH264_CABAC (LIBAVCODEC_VERSION_MAJOR < 59)
#define FF_API_UNUSED_CODEC_CAPS (LIBAVCODEC_VERSION_MAJOR < 59)



#define AV_PKT_DATA_QUALITY_FACTOR AV_PKT_DATA_QUALITY_STATS


#define AV_PKT_FLAG_KEY 0x0001
#define AV_PKT_FLAG_CORRUPT 0x0002
#define AV_PKT_FLAG_DISCARD 0x0004
#define AV_PKT_FLAG_TRUSTED 0x0008
#define AV_PKT_FLAG_DISPOSABLE 0x0010



AVPacket *av_packet_alloc(void);

AVPacket *av_packet_clone(const AVPacket *src);

void av_packet_free(AVPacket **pkt);

void av_init_packet(AVPacket *pkt);

int av_new_packet(AVPacket *pkt, int size);

void av_shrink_packet(AVPacket *pkt, int size);

int av_grow_packet(AVPacket *pkt, int grow_by);
int av_packet_from_data(AVPacket *pkt, uint8_t *data, int size);

int av_dup_packet(AVPacket *pkt);

int av_copy_packet(AVPacket *dst, const AVPacket *src);

int av_copy_packet_side_data(AVPacket *dst, const AVPacket *src);

void av_free_packet(AVPacket *pkt);

uint8_t *av_packet_new_side_data(AVPacket *pkt, enum AVPacketSideDataType type,
                                 int size);
int av_packet_add_side_data(AVPacket *pkt, enum AVPacketSideDataType type,
                            uint8_t *data, size_t size);

int av_packet_shrink_side_data(AVPacket *pkt, enum AVPacketSideDataType type,
                               int size);

uint8_t *av_packet_get_side_data(const AVPacket *pkt, enum AVPacketSideDataType type,
                                 int *size);

int av_packet_merge_side_data(AVPacket *pkt);

int av_packet_split_side_data(AVPacket *pkt);

const char *av_packet_side_data_name(enum AVPacketSideDataType type);

uint8_t *av_packet_pack_dictionary(AVDictionary *dict, int *size);

int av_packet_unpack_dictionary(const uint8_t *data, int size, AVDictionary **dict);

void av_packet_free_side_data(AVPacket *pkt);
int av_packet_ref(AVPacket *dst, const AVPacket *src);

void av_packet_unref(AVPacket *pkt);

void av_packet_move_ref(AVPacket *dst, AVPacket *src);

int av_packet_copy_props(AVPacket *dst, const AVPacket *src);
int av_packet_make_refcounted(AVPacket *pkt);

int av_packet_make_writable(AVPacket *pkt);

void av_packet_rescale_ts(AVPacket *pkt, AVRational tb_src, AVRational tb_dst);


const AVBitStreamFilter *av_bsf_get_by_name(const char *name);

const AVBitStreamFilter *av_bsf_iterate(void **opaque);
int av_bsf_alloc(const AVBitStreamFilter *filter, AVBSFContext **ctx);

int av_bsf_init(AVBSFContext *ctx);
int av_bsf_send_packet(AVBSFContext *ctx, AVPacket *pkt);
int av_bsf_receive_packet(AVBSFContext *ctx, AVPacket *pkt);

void av_bsf_flush(AVBSFContext *ctx);

void av_bsf_free(AVBSFContext **ctx);

const AVClass *av_bsf_get_class(void);

typedef struct AVBSFList AVBSFList;

AVBSFList *av_bsf_list_alloc(void);

void av_bsf_list_free(AVBSFList **lst);

int av_bsf_list_append(AVBSFList *lst, AVBSFContext *bsf);

int av_bsf_list_append2(AVBSFList *lst, const char *bsf_name, AVDictionary **options);
int av_bsf_list_finalize(AVBSFList **lst, AVBSFContext **bsf);
int av_bsf_list_parse_str(const char *str, AVBSFContext **bsf);

int av_bsf_get_null_filter(AVBSFContext **bsf);
#define AVCODEC_CODEC_H
#define AV_CODEC_CAP_DRAW_HORIZ_BAND (1 << 0)
#define AV_CODEC_CAP_DR1 (1 << 1)
#define AV_CODEC_CAP_TRUNCATED (1 << 3)
#define AV_CODEC_CAP_DELAY (1 << 5)
#define AV_CODEC_CAP_SMALL_LAST_FRAME (1 << 6)
#define AV_CODEC_CAP_SUBFRAMES (1 << 8)
#define AV_CODEC_CAP_EXPERIMENTAL (1 << 9)
#define AV_CODEC_CAP_CHANNEL_CONF (1 << 10)
#define AV_CODEC_CAP_FRAME_THREADS (1 << 12)
#define AV_CODEC_CAP_SLICE_THREADS (1 << 13)
#define AV_CODEC_CAP_PARAM_CHANGE (1 << 14)
#define AV_CODEC_CAP_AUTO_THREADS (1 << 15)
#define AV_CODEC_CAP_VARIABLE_FRAME_SIZE (1 << 16)
#define AV_CODEC_CAP_AVOID_PROBING (1 << 17)
#define AV_CODEC_CAP_INTRA_ONLY 0x40000000
#define AV_CODEC_CAP_LOSSLESS 0x80000000
#define AV_CODEC_CAP_HARDWARE (1 << 18)
#define AV_CODEC_CAP_HYBRID (1 << 19)
#define AV_CODEC_CAP_ENCODER_REORDERED_OPAQUE (1 << 20)
#define AV_CODEC_CAP_ENCODER_FLUSH (1 << 21)


const AVCodec *av_codec_iterate(void **opaque);

AVCodec *avcodec_find_decoder(enum AVCodecID id);

AVCodec *avcodec_find_decoder_by_name(const char *name);

AVCodec *avcodec_find_encoder(enum AVCodecID id);

AVCodec *avcodec_find_encoder_by_name(const char *name);

int av_codec_is_encoder(const AVCodec *codec);

int av_codec_is_decoder(const AVCodec *codec);


const AVCodecHWConfig *avcodec_get_hw_config(const AVCodec *codec, int index);
#define AVCODEC_CODEC_DESC_H


#define AV_CODEC_PROP_INTRA_ONLY (1 << 0)
#define AV_CODEC_PROP_LOSSY (1 << 1)
#define AV_CODEC_PROP_LOSSLESS (1 << 2)
#define AV_CODEC_PROP_REORDER (1 << 3)
#define AV_CODEC_PROP_BITMAP_SUB (1 << 16)
#define AV_CODEC_PROP_TEXT_SUB (1 << 17)

const AVCodecDescriptor *avcodec_descriptor_get(enum AVCodecID id);

const AVCodecDescriptor *avcodec_descriptor_next(const AVCodecDescriptor *prev);

const AVCodecDescriptor *avcodec_descriptor_get_by_name(const char *name);
#define AV_INPUT_BUFFER_PADDING_SIZE 64
#define AV_INPUT_BUFFER_MIN_SIZE 16384


#define AV_CODEC_FLAG_UNALIGNED (1 << 0)
#define AV_CODEC_FLAG_QSCALE (1 << 1)
#define AV_CODEC_FLAG_4MV (1 << 2)
#define AV_CODEC_FLAG_OUTPUT_CORRUPT (1 << 3)
#define AV_CODEC_FLAG_QPEL (1 << 4)
#define AV_CODEC_FLAG_DROPCHANGED (1 << 5)
#define AV_CODEC_FLAG_PASS1 (1 << 9)
#define AV_CODEC_FLAG_PASS2 (1 << 10)
#define AV_CODEC_FLAG_LOOP_FILTER (1 << 11)
#define AV_CODEC_FLAG_GRAY (1 << 13)
#define AV_CODEC_FLAG_PSNR (1 << 15)
#define AV_CODEC_FLAG_TRUNCATED (1 << 16)
#define AV_CODEC_FLAG_INTERLACED_DCT (1 << 18)
#define AV_CODEC_FLAG_LOW_DELAY (1 << 19)
#define AV_CODEC_FLAG_GLOBAL_HEADER (1 << 22)
#define AV_CODEC_FLAG_BITEXACT (1 << 23)
#define AV_CODEC_FLAG_AC_PRED (1 << 24)
#define AV_CODEC_FLAG_INTERLACED_ME (1 << 29)
#define AV_CODEC_FLAG_CLOSED_GOP (1U << 31)
#define AV_CODEC_FLAG2_FAST (1 << 0)
#define AV_CODEC_FLAG2_NO_OUTPUT (1 << 2)
#define AV_CODEC_FLAG2_LOCAL_HEADER (1 << 3)
#define AV_CODEC_FLAG2_DROP_FRAME_TIMECODE (1 << 13)
#define AV_CODEC_FLAG2_CHUNKS (1 << 15)
#define AV_CODEC_FLAG2_IGNORE_CROP (1 << 16)
#define AV_CODEC_FLAG2_SHOW_ALL (1 << 22)
#define AV_CODEC_FLAG2_EXPORT_MVS (1 << 28)
#define AV_CODEC_FLAG2_SKIP_MANUAL (1 << 29)
#define AV_CODEC_FLAG2_RO_FLUSH_NOOP (1 << 30)
#define AV_CODEC_EXPORT_DATA_MVS (1 << 0)
#define AV_CODEC_EXPORT_DATA_PRFT (1 << 1)
#define AV_CODEC_EXPORT_DATA_VIDEO_ENC_PARAMS (1 << 2)
#define AV_GET_BUFFER_FLAG_REF (1 << 0)
#define FF_COMPRESSION_DEFAULT -1
#define FF_PRED_LEFT 0
#define FF_PRED_PLANE 1
#define FF_PRED_MEDIAN 2
#define FF_CMP_SAD 0
#define FF_CMP_SSE 1
#define FF_CMP_SATD 2
#define FF_CMP_DCT 3
#define FF_CMP_PSNR 4
#define FF_CMP_BIT 5
#define FF_CMP_RD 6
#define FF_CMP_ZERO 7
#define FF_CMP_VSAD 8
#define FF_CMP_VSSE 9
#define FF_CMP_NSSE 10
#define FF_CMP_W53 11
#define FF_CMP_W97 12
#define FF_CMP_DCTMAX 13
#define FF_CMP_DCT264 14
#define FF_CMP_MEDIAN_SAD 15
#define FF_CMP_CHROMA 256
#define SLICE_FLAG_CODED_ORDER 0x0001
#define SLICE_FLAG_ALLOW_FIELD 0x0002
#define SLICE_FLAG_ALLOW_PLANE 0x0004
#define FF_MB_DECISION_SIMPLE 0
#define FF_MB_DECISION_BITS 1
#define FF_MB_DECISION_RD 2
#define FF_CODER_TYPE_VLC 0
#define FF_CODER_TYPE_AC 1
#define FF_CODER_TYPE_RAW 2
#define FF_CODER_TYPE_RLE 3
#define FF_BUG_AUTODETECT 1
#define FF_BUG_XVID_ILACE 4
#define FF_BUG_UMP4 8
#define FF_BUG_NO_PADDING 16
#define FF_BUG_AMV 32
#define FF_BUG_QPEL_CHROMA 64
#define FF_BUG_STD_QPEL 128
#define FF_BUG_QPEL_CHROMA2 256
#define FF_BUG_DIRECT_BLOCKSIZE 512
#define FF_BUG_EDGE 1024
#define FF_BUG_HPEL_CHROMA 2048
#define FF_BUG_DC_CLIP 4096
#define FF_BUG_MS 8192
#define FF_BUG_TRUNCATED 16384
#define FF_BUG_IEDGE 32768
#define FF_COMPLIANCE_VERY_STRICT 2
#define FF_COMPLIANCE_STRICT 1
#define FF_COMPLIANCE_NORMAL 0
#define FF_COMPLIANCE_UNOFFICIAL -1
#define FF_COMPLIANCE_EXPERIMENTAL -2
#define FF_EC_GUESS_MVS 1
#define FF_EC_DEBLOCK 2
#define FF_EC_FAVOR_INTER 256
#define FF_DEBUG_PICT_INFO 1
#define FF_DEBUG_RC 2
#define FF_DEBUG_BITSTREAM 4
#define FF_DEBUG_MB_TYPE 8
#define FF_DEBUG_QP 16
#define FF_DEBUG_DCT_COEFF 0x00000040
#define FF_DEBUG_SKIP 0x00000080
#define FF_DEBUG_STARTCODE 0x00000100
#define FF_DEBUG_ER 0x00000400
#define FF_DEBUG_MMCO 0x00000800
#define FF_DEBUG_BUGS 0x00001000
#define FF_DEBUG_BUFFERS 0x00008000
#define FF_DEBUG_THREADS 0x00010000
#define FF_DEBUG_GREEN_MD 0x00800000
#define FF_DEBUG_NOMC 0x01000000
#define AV_EF_CRCCHECK (1 << 0)
#define AV_EF_BITSTREAM (1 << 1)
#define AV_EF_BUFFER (1 << 2)
#define AV_EF_EXPLODE (1 << 3)
#define AV_EF_IGNORE_ERR (1 << 15)
#define AV_EF_CAREFUL (1 << 16)
#define AV_EF_COMPLIANT (1 << 17)
#define AV_EF_AGGRESSIVE (1 << 18)
#define FF_DCT_AUTO 0
#define FF_DCT_FASTINT 1
#define FF_DCT_INT 2
#define FF_DCT_MMX 3
#define FF_DCT_ALTIVEC 5
#define FF_DCT_FAAN 6
#define FF_IDCT_AUTO 0
#define FF_IDCT_INT 1
#define FF_IDCT_SIMPLE 2
#define FF_IDCT_SIMPLEMMX 3
#define FF_IDCT_ARM 7
#define FF_IDCT_ALTIVEC 8
#define FF_IDCT_SIMPLEARM 10
#define FF_IDCT_XVID 14
#define FF_IDCT_SIMPLEARMV5TE 16
#define FF_IDCT_SIMPLEARMV6 17
#define FF_IDCT_FAAN 20
#define FF_IDCT_SIMPLENEON 22
#define FF_IDCT_NONE 24
#define FF_IDCT_SIMPLEAUTO 128
#define FF_THREAD_FRAME 1
#define FF_THREAD_SLICE 2
#define FF_PROFILE_UNKNOWN -99
#define FF_PROFILE_RESERVED -100
#define FF_PROFILE_AAC_MAIN 0
#define FF_PROFILE_AAC_LOW 1
#define FF_PROFILE_AAC_SSR 2
#define FF_PROFILE_AAC_LTP 3
#define FF_PROFILE_AAC_HE 4
#define FF_PROFILE_AAC_HE_V2 28
#define FF_PROFILE_AAC_LD 22
#define FF_PROFILE_AAC_ELD 38
#define FF_PROFILE_MPEG2_AAC_LOW 128
#define FF_PROFILE_MPEG2_AAC_HE 131
#define FF_PROFILE_DNXHD 0
#define FF_PROFILE_DNXHR_LB 1
#define FF_PROFILE_DNXHR_SQ 2
#define FF_PROFILE_DNXHR_HQ 3
#define FF_PROFILE_DNXHR_HQX 4
#define FF_PROFILE_DNXHR_444 5
#define FF_PROFILE_DTS 20
#define FF_PROFILE_DTS_ES 30
#define FF_PROFILE_DTS_96_24 40
#define FF_PROFILE_DTS_HD_HRA 50
#define FF_PROFILE_DTS_HD_MA 60
#define FF_PROFILE_DTS_EXPRESS 70
#define FF_PROFILE_MPEG2_422 0
#define FF_PROFILE_MPEG2_HIGH 1
#define FF_PROFILE_MPEG2_SS 2
#define FF_PROFILE_MPEG2_SNR_SCALABLE 3
#define FF_PROFILE_MPEG2_MAIN 4
#define FF_PROFILE_MPEG2_SIMPLE 5
#define FF_PROFILE_H264_CONSTRAINED (1 << 9)
#define FF_PROFILE_H264_INTRA (1 << 11)
#define FF_PROFILE_H264_BASELINE 66
#define FF_PROFILE_H264_CONSTRAINED_BASELINE (66 | FF_PROFILE_H264_CONSTRAINED)
#define FF_PROFILE_H264_MAIN 77
#define FF_PROFILE_H264_EXTENDED 88
#define FF_PROFILE_H264_HIGH 100
#define FF_PROFILE_H264_HIGH_10 110
#define FF_PROFILE_H264_HIGH_10_INTRA (110 | FF_PROFILE_H264_INTRA)
#define FF_PROFILE_H264_MULTIVIEW_HIGH 118
#define FF_PROFILE_H264_HIGH_422 122
#define FF_PROFILE_H264_HIGH_422_INTRA (122 | FF_PROFILE_H264_INTRA)
#define FF_PROFILE_H264_STEREO_HIGH 128
#define FF_PROFILE_H264_HIGH_444 144
#define FF_PROFILE_H264_HIGH_444_PREDICTIVE 244
#define FF_PROFILE_H264_HIGH_444_INTRA (244 | FF_PROFILE_H264_INTRA)
#define FF_PROFILE_H264_CAVLC_444 44
#define FF_PROFILE_VC1_SIMPLE 0
#define FF_PROFILE_VC1_MAIN 1
#define FF_PROFILE_VC1_COMPLEX 2
#define FF_PROFILE_VC1_ADVANCED 3
#define FF_PROFILE_MPEG4_SIMPLE 0
#define FF_PROFILE_MPEG4_SIMPLE_SCALABLE 1
#define FF_PROFILE_MPEG4_CORE 2
#define FF_PROFILE_MPEG4_MAIN 3
#define FF_PROFILE_MPEG4_N_BIT 4
#define FF_PROFILE_MPEG4_SCALABLE_TEXTURE 5
#define FF_PROFILE_MPEG4_SIMPLE_FACE_ANIMATION 6
#define FF_PROFILE_MPEG4_BASIC_ANIMATED_TEXTURE 7
#define FF_PROFILE_MPEG4_HYBRID 8
#define FF_PROFILE_MPEG4_ADVANCED_REAL_TIME 9
#define FF_PROFILE_MPEG4_CORE_SCALABLE 10
#define FF_PROFILE_MPEG4_ADVANCED_CODING 11
#define FF_PROFILE_MPEG4_ADVANCED_CORE 12
#define FF_PROFILE_MPEG4_ADVANCED_SCALABLE_TEXTURE 13
#define FF_PROFILE_MPEG4_SIMPLE_STUDIO 14
#define FF_PROFILE_MPEG4_ADVANCED_SIMPLE 15
#define FF_PROFILE_JPEG2000_CSTREAM_RESTRICTION_0 1
#define FF_PROFILE_JPEG2000_CSTREAM_RESTRICTION_1 2
#define FF_PROFILE_JPEG2000_CSTREAM_NO_RESTRICTION 32768
#define FF_PROFILE_JPEG2000_DCINEMA_2K 3
#define FF_PROFILE_JPEG2000_DCINEMA_4K 4
#define FF_PROFILE_VP9_0 0
#define FF_PROFILE_VP9_1 1
#define FF_PROFILE_VP9_2 2
#define FF_PROFILE_VP9_3 3
#define FF_PROFILE_HEVC_MAIN 1
#define FF_PROFILE_HEVC_MAIN_10 2
#define FF_PROFILE_HEVC_MAIN_STILL_PICTURE 3
#define FF_PROFILE_HEVC_REXT 4
#define FF_PROFILE_AV1_MAIN 0
#define FF_PROFILE_AV1_HIGH 1
#define FF_PROFILE_AV1_PROFESSIONAL 2
#define FF_PROFILE_MJPEG_HUFFMAN_BASELINE_DCT 0xc0
#define FF_PROFILE_MJPEG_HUFFMAN_EXTENDED_SEQUENTIAL_DCT 0xc1
#define FF_PROFILE_MJPEG_HUFFMAN_PROGRESSIVE_DCT 0xc2
#define FF_PROFILE_MJPEG_HUFFMAN_LOSSLESS 0xc3
#define FF_PROFILE_MJPEG_JPEG_LS 0xf7
#define FF_PROFILE_SBC_MSBC 1
#define FF_PROFILE_PRORES_PROXY 0
#define FF_PROFILE_PRORES_LT 1
#define FF_PROFILE_PRORES_STANDARD 2
#define FF_PROFILE_PRORES_HQ 3
#define FF_PROFILE_PRORES_4444 4
#define FF_PROFILE_PRORES_XQ 5
#define FF_PROFILE_ARIB_PROFILE_A 0
#define FF_PROFILE_ARIB_PROFILE_C 1
#define FF_PROFILE_KLVA_SYNC 0
#define FF_PROFILE_KLVA_ASYNC 1
#define FF_LEVEL_UNKNOWN -99
#define FF_SUB_CHARENC_MODE_DO_NOTHING -1
#define FF_SUB_CHARENC_MODE_AUTOMATIC 0
#define FF_SUB_CHARENC_MODE_PRE_DECODER 1
#define FF_SUB_CHARENC_MODE_IGNORE 2
#define FF_DEBUG_VIS_MV_P_FOR 0x00000001
#define FF_DEBUG_VIS_MV_B_FOR 0x00000002
#define FF_DEBUG_VIS_MV_B_BACK 0x00000004
#define FF_CODEC_PROPERTY_LOSSLESS 0x00000001
#define FF_CODEC_PROPERTY_CLOSED_CAPTIONS 0x00000002
#define FF_SUB_TEXT_FMT_ASS 0
#define FF_SUB_TEXT_FMT_ASS_WITH_TIMINGS 1
#define AV_HWACCEL_CODEC_CAP_EXPERIMENTAL 0x0200
#define AV_HWACCEL_FLAG_IGNORE_LEVEL (1 << 0)
#define AV_HWACCEL_FLAG_ALLOW_HIGH_DEPTH (1 << 1)
#define AV_HWACCEL_FLAG_ALLOW_PROFILE_MISMATCH (1 << 2)

typedef struct AVPanScan
{
    int id;
    int width;
    int height;
    int16_t position[3][2];
} AVPanScan;

typedef struct AVCPBProperties
{
    int max_bitrate;
    int min_bitrate;
    int avg_bitrate;
    int buffer_size;
    uint64_t vbv_delay;
} AVCPBProperties;

typedef struct AVProducerReferenceTime
{
    int64_t wallclock;
    int flags;
} AVProducerReferenceTime;

#define FF_CODEC_CAP_INIT_THREADSAFE        (1 << 0)

#define FF_CODEC_CAP_INIT_CLEANUP           (1 << 1)

#define FF_CODEC_CAP_SETS_PKT_DTS           (1 << 2)

#define FF_CODEC_CAP_SKIP_FRAME_FILL_PARAM  (1 << 3)

#define FF_CODEC_CAP_EXPORTS_CROPPING       (1 << 4)

#define FF_CODEC_CAP_SLICE_THREAD_HAS_MF    (1 << 5)

#define FF_CODEC_CAP_ALLOCATE_PROGRESS      (1 << 6)


#define FF_CODEC_TAGS_END -1


#ifdef TRACE
#   define ff_tlog(ctx, ...) av_log(ctx, AV_LOG_TRACE, __VA_ARGS__)
#else
#   define ff_tlog(ctx, ...) do { } while(0)
#endif


#define FF_DEFAULT_QUANT_BIAS 999999

#define FF_QSCALE_TYPE_MPEG1 0
#define FF_QSCALE_TYPE_MPEG2 1
#define FF_QSCALE_TYPE_H264  2
#define FF_QSCALE_TYPE_VP56  3

#define FF_SANE_NB_CHANNELS 512U

#define FF_SIGNBIT(x) ((x) >> CHAR_BIT * sizeof(x) - 1)

#if HAVE_SIMD_ALIGN_64
#   define STRIDE_ALIGN 64 
#elif HAVE_SIMD_ALIGN_32
#   define STRIDE_ALIGN 32
#elif HAVE_SIMD_ALIGN_16
#   define STRIDE_ALIGN 16
#else
#   define STRIDE_ALIGN 8
#endif

typedef struct DecodeSimpleContext {
    AVPacket *in_pkt;
} DecodeSimpleContext;

typedef struct EncodeSimpleContext {
    AVFrame *in_frame;
} EncodeSimpleContext;

typedef struct AVCodecInternal {
    
    int is_copy;

    
    int last_audio_frame;

    AVFrame *to_free;

    AVBufferRef *pool;

    void *thread_ctx;

    DecodeSimpleContext ds;
    AVBSFContext *bsf;

    
    AVPacket *last_pkt_props;
    AVPacketList *pkt_props;
    AVPacketList *pkt_props_tail;

    
    uint8_t *byte_buffer;
    unsigned int byte_buffer_size;

    void *frame_thread_encoder;

    EncodeSimpleContext es;

    
    int skip_samples;

    
    void *hwaccel_priv_data;

    
    int draining;

    
    AVPacket *buffer_pkt;
    AVFrame *buffer_frame;
    int draining_done;
    int compat_decode_warned;
    
    size_t compat_decode_consumed;
    
    size_t compat_decode_partial_size;
    AVFrame *compat_decode_frame;
    AVPacket *compat_encode_packet;

    int showed_multi_packet_warning;

    int skip_samples_multiplier;

    
    int nb_draining_errors;

    
    int changed_frames_dropped;
    int initial_format;
    int initial_width, initial_height;
    int initial_sample_rate;
    int initial_channels;
    uint64_t initial_channel_layout;
} AVCodecInternal;

struct AVCodecDefault {
    const uint8_t *key;
    const uint8_t *value;
};

typedef struct AVCodecContext
{
    const AVClass *av_class;
    int log_level_offset;
    enum AVMediaType codec_type;
    const struct AVCodec *codec;
    enum AVCodecID codec_id;
    unsigned int codec_tag;
    void *priv_data;
    struct AVCodecInternal *internal;
    void *opaque;
    int64_t bit_rate;
    int bit_rate_tolerance;
    int global_quality;
    int compression_level;
    int flags;
    int flags2;
    uint8_t *extradata;
    int extradata_size;
    AVRational time_base;
    int ticks_per_frame;
    int delay;
    int width, height;
    int coded_width, coded_height;
    int gop_size;
    enum AVPixelFormat pix_fmt;
    void (*draw_horiz_band)(struct AVCodecContext *s,
                            const AVFrame *src, int offset[8],
                            int y, int type, int height);
    enum AVPixelFormat (*get_format)(struct AVCodecContext *s, const enum AVPixelFormat *fmt);
    int max_b_frames;
    float b_quant_factor;
    int b_frame_strategy;
    float b_quant_offset;
    int has_b_frames;
    int mpeg_quant;
    float i_quant_factor;
    float i_quant_offset;
    float lumi_masking;
    float temporal_cplx_masking;
    float spatial_cplx_masking;
    float p_masking;
    float dark_masking;
    int slice_count;
    int prediction_method;
    int *slice_offset;
    AVRational sample_aspect_ratio;
    int me_cmp;
    int me_sub_cmp;
    int mb_cmp;
    int ildct_cmp;
    int dia_size;
    int last_predictor_count;
    int pre_me;
    int me_pre_cmp;
    int pre_dia_size;
    int me_subpel_quality;
    int me_range;
    int slice_flags;
    int mb_decision;
    uint16_t *intra_matrix;
    uint16_t *inter_matrix;
    int scenechange_threshold;
    int noise_reduction;
    int intra_dc_precision;
    int skip_top;
    int skip_bottom;
    int mb_lmin;
    int mb_lmax;
    int me_penalty_compensation;
    int bidir_refine;
    int brd_scale;
    int keyint_min;
    int refs;
    int chromaoffset;
    int mv0_threshold;
    int b_sensitivity;
    enum AVColorPrimaries color_primaries;
    enum AVColorTransferCharacteristic color_trc;
    enum AVColorSpace colorspace;
    enum AVColorRange color_range;
    enum AVChromaLocation chroma_sample_location;
    int slices;
    enum AVFieldOrder field_order;
    int sample_rate;                ///< samples per second
    int channels;                   ///< number of audio channels
    enum AVSampleFormat sample_fmt; ///< sample format
    int frame_size;
    int frame_number;
    int block_align;
    int cutoff;
    uint64_t channel_layout;
    uint64_t request_channel_layout;
    enum AVAudioServiceType audio_service_type;
    enum AVSampleFormat request_sample_fmt;
    int (*get_buffer2)(struct AVCodecContext *s, AVFrame *frame, int flags);
    int refcounted_frames;
    float qcompress; ///< amount of qscale change between easy & hard scenes (0.0-1.0)
    float qblur;     ///< amount of qscale smoothing over time (0.0-1.0)
    int qmin;
    int qmax;
    int max_qdiff;
    int rc_buffer_size;
    int rc_override_count;
    RcOverride *rc_override;
    int64_t rc_max_rate;
    int64_t rc_min_rate;
    float rc_max_available_vbv_use;
    float rc_min_vbv_overflow_use;
    int rc_initial_buffer_occupancy;
    int coder_type;
    int context_model;
    int frame_skip_threshold;
    int frame_skip_factor;
    int frame_skip_exp;
    int frame_skip_cmp;
    int trellis;
    int min_prediction_order;
    int max_prediction_order;
    int64_t timecode_frame_start;
    void (*rtp_callback)(struct AVCodecContext *avctx, void *data, int size, int mb_nb);
    int rtp_payload_size;
    int mv_bits;
    int header_bits;
    int i_tex_bits;
    int p_tex_bits;
    int i_count;
    int p_count;
    int skip_count;
    int misc_bits;
    int frame_bits;
    char *stats_out;
    char *stats_in;
    int workaround_bugs;
    int strict_std_compliance;
    int error_concealment;
    int debug;
    int err_recognition;
    int64_t reordered_opaque;
    const struct AVHWAccel *hwaccel;
    void *hwaccel_context;
    uint64_t error[8];
    int dct_algo;
    int idct_algo;
    int bits_per_coded_sample;
    int bits_per_raw_sample;
    int lowres;
    AVFrame *coded_frame;
    int thread_count;
    int thread_type;
    int active_thread_type;
    int thread_safe_callbacks;
    int (*execute)(struct AVCodecContext *c, int (*func)(struct AVCodecContext *c2, void *arg), void *arg2, int *ret, int count, int size);
    int (*execute2)(struct AVCodecContext *c, int (*func)(struct AVCodecContext *c2, void *arg, int jobnr, int threadnr), void *arg2, int *ret, int count);
    int nsse_weight;
    int profile;
    int level;
    enum AVDiscard skip_loop_filter;
    enum AVDiscard skip_idct;
    enum AVDiscard skip_frame;
    uint8_t *subtitle_header;
    int subtitle_header_size;
    uint64_t vbv_delay;
    int side_data_only_packets;
    int initial_padding;
    AVRational framerate;
    enum AVPixelFormat sw_pix_fmt;
    AVRational pkt_timebase;
    const AVCodecDescriptor *codec_descriptor;
    int64_t pts_correction_num_faulty_pts; /// Number of incorrect PTS values so far
    int64_t pts_correction_num_faulty_dts; /// Number of incorrect DTS values so far
    int64_t pts_correction_last_pts;       /// PTS of the last frame
    int64_t pts_correction_last_dts;       /// DTS of the last frame
    char *sub_charenc;
    int sub_charenc_mode;
    int skip_alpha;
    int seek_preroll;
    int debug_mv;
    uint16_t *chroma_intra_matrix;
    uint8_t *dump_separator;
    char *codec_whitelist;
    unsigned properties;
    AVPacketSideData *coded_side_data;
    int nb_coded_side_data;
    AVBufferRef *hw_frames_ctx;
    int sub_text_format;
    int trailing_padding;
    int64_t max_pixels;
    AVBufferRef *hw_device_ctx;
    int hwaccel_flags;
    int apply_cropping;
    int extra_hw_frames;
    int discard_damaged_percentage;
    int64_t max_samples;
    int export_side_data;
} AVCodecContext;


#define MAX_THREADS 64
#define BUFFER_SIZE (2*MAX_THREADS)

typedef struct{
    void *indata;
    void *outdata;
    int64_t return_code;
    unsigned index;
} Task;

typedef struct{
    AVCodecContext *parent_avctx;
    pthread_mutex_t buffer_mutex;

    AVFifoBuffer *task_fifo;
    pthread_mutex_t task_fifo_mutex;
    pthread_cond_t task_fifo_cond;

    Task finished_tasks[BUFFER_SIZE];
    pthread_mutex_t finished_task_mutex;
    pthread_cond_t finished_task_cond;

    unsigned task_index;
    unsigned finished_task_index;

    pthread_t worker[MAX_THREADS];
    atomic_int exit;
} ThreadContext;

enum AVPictureStructure
{
    AV_PICTURE_STRUCTURE_UNKNOWN,      //< unknown
    AV_PICTURE_STRUCTURE_TOP_FIELD,    //< coded as top field
    AV_PICTURE_STRUCTURE_BOTTOM_FIELD, //< coded as bottom field
    AV_PICTURE_STRUCTURE_FRAME,        //< coded as frame
};
#define AV_PARSER_PTS_NB 4
#define PARSER_FLAG_COMPLETE_FRAMES 0x0001
#define PARSER_FLAG_ONCE 0x0002
#define PARSER_FLAG_FETCHED_OFFSET 0x0004
#define PARSER_FLAG_USE_CODEC_TS 0x1000

typedef struct AVCodecParserContext
{
    void *priv_data;
    struct AVCodecParser *parser;
    int64_t frame_offset;
    int64_t cur_offset;
    int64_t next_frame_offset;
    int pict_type;
    int repeat_pict;
    int64_t pts;
    int64_t dts;
    int64_t last_pts;
    int64_t last_dts;
    int fetch_timestamp;
    int cur_frame_start_index;
    int64_t cur_frame_offset[4];
    int64_t cur_frame_pts[4];
    int64_t cur_frame_dts[4];
    int flags;
    // Set if the parser has a valid file offset
    int64_t offset; ///< byte offset from starting packet start
    int64_t cur_frame_end[4];
    int key_frame;
    int64_t convergence_duration;
    int dts_sync_point;
    int dts_ref_dts_delta;
    int pts_dts_delta;
    int64_t cur_frame_pos[4];
    int64_t pos;
    int64_t last_pos;
    int duration;
    enum AVFieldOrder field_order;
    enum AVPictureStructure picture_structure;
    int output_picture_number;
    int width;
    int height;
    int coded_width;
    int coded_height;
    int format;
} AVCodecParserContext;

typedef struct AVCodecParser
{
    int codec_ids[5];
    int priv_data_size;
    int (*parser_init)(AVCodecParserContext *s);
    int (*parser_parse)(AVCodecParserContext *s,
                        AVCodecContext *avctx,
                        const uint8_t **poutbuf, int *poutbuf_size,
                        const uint8_t *buf, int buf_size);
    void (*parser_close)(AVCodecParserContext *s);
    int (*split)(AVCodecContext *avctx, const uint8_t *buf, int buf_size);
    struct AVCodecParser *next;
} AVCodecParser;



typedef struct AVBitStreamFilterContext
{
    void *priv_data;
    const struct AVBitStreamFilter *filter;
    AVCodecParserContext *parser;
    struct AVBitStreamFilterContext *next;
    char *args;
} AVBitStreamFilterContext;


void av_fifo_reset(AVFifoBuffer *f)
{
    f->wptr = f->rptr = f->buffer;
    f->wndx = f->rndx = 0;
}

static AVFifoBuffer *fifo_alloc_common(void *buffer, size_t size)
{
    AVFifoBuffer *f;
    if (!buffer)
        return NULL;
    f = av_mallocz(sizeof(AVFifoBuffer));
    if (!f) {
        av_free(buffer);
        return NULL;
    }
    f->buffer = buffer;
    f->end    = f->buffer + size;
    av_fifo_reset(f);
    return f;
}

AVFifoBuffer *av_fifo_alloc(unsigned int size)
{
    void *buffer = av_malloc(size);
    return fifo_alloc_common(buffer, size);
}

AVFifoBuffer *av_fifo_alloc_array(size_t nmemb, size_t size)
{
    void *buffer = av_malloc_array(nmemb, size);
    return fifo_alloc_common(buffer, nmemb * size);
}

void av_fifo_free(AVFifoBuffer *f)
{
    if (f) {
        av_freep(&f->buffer);
        av_free(f);
    }
}

void av_fifo_freep(AVFifoBuffer **f)
{
    if (f) {
        av_fifo_free(*f);
        *f = NULL;
    }
}



int av_fifo_size(const AVFifoBuffer *f)
{
    return (uint32_t)(f->wndx - f->rndx);
}

int av_fifo_space(const AVFifoBuffer *f)
{
    return f->end - f->buffer - av_fifo_size(f);
}


void av_fifo_drain(AVFifoBuffer *f, int size)
{
    av_assert2(av_fifo_size(f) >= size);
    f->rptr += size;
    if (f->rptr >= f->end)
        f->rptr -= f->end - f->buffer;
    f->rndx += size;
}


int av_fifo_generic_read(AVFifoBuffer *f, void *dest, int buf_size,
                         void (*func)(void *, void *, int))
{
// Read memory barrier needed for SMP here in theory
    do {
        int len = FFMIN(f->end - f->rptr, buf_size);
        if (func)
            func(dest, f->rptr, len);
        else {
            memcpy(dest, f->rptr, len);
            dest = (uint8_t *)dest + len;
        }
// memory barrier needed for SMP here in theory
        av_fifo_drain(f, len);
        buf_size -= len;
    } while (buf_size > 0);
    return 0;
}


int av_fifo_realloc2(AVFifoBuffer *f, unsigned int new_size)
{
    unsigned int old_size = f->end - f->buffer;

    if (old_size < new_size) {
        int len          = av_fifo_size(f);
        AVFifoBuffer *f2 = av_fifo_alloc(new_size);

        if (!f2)
            return AVERROR(ENOMEM);
        av_fifo_generic_read(f, f2->buffer, len, NULL);
        f2->wptr += len;
        f2->wndx += len;
        av_free(f->buffer);
        *f = *f2;
        av_free(f2);
    }
    return 0;
}

int av_fifo_grow(AVFifoBuffer *f, unsigned int size)
{
    unsigned int old_size = f->end - f->buffer;
    if(size + (unsigned)av_fifo_size(f) < size)
        return AVERROR(EINVAL);

    size += av_fifo_size(f);

    if (old_size < size)
        return av_fifo_realloc2(f, FFMAX(size, 2*old_size));
    return 0;
}


int av_fifo_generic_write(AVFifoBuffer *f, void *src, int size,
                          int (*func)(void *, void *, int))
{
    int total = size;
    uint32_t wndx= f->wndx;
    uint8_t *wptr= f->wptr;

    do {
        int len = FFMIN(f->end - wptr, size);
        if (func) {
            len = func(src, wptr, len);
            if (len <= 0)
                break;
        } else {
            memcpy(wptr, src, len);
            src = (uint8_t *)src + len;
        }
// Write memory barrier needed for SMP here in theory
        wptr += len;
        if (wptr >= f->end)
            wptr = f->buffer;
        wndx    += len;
        size    -= len;
    } while (size > 0);
    f->wndx= wndx;
    f->wptr= wptr;
    return total - size;
}

int av_fifo_generic_peek_at(AVFifoBuffer *f, void *dest, int offset, int buf_size, void (*func)(void*, void*, int))
{
    uint8_t *rptr = f->rptr;

    av_assert2(offset >= 0);

    
    av_assert2(buf_size + (unsigned)offset <= f->wndx - f->rndx);

    if (offset >= f->end - rptr)
        rptr += offset - (f->end - f->buffer);
    else
        rptr += offset;

    while (buf_size > 0) {
        int len;

        if (rptr >= f->end)
            rptr -= f->end - f->buffer;

        len = FFMIN(f->end - rptr, buf_size);
        if (func)
            func(dest, rptr, len);
        else {
            memcpy(dest, rptr, len);
            dest = (uint8_t *)dest + len;
        }

        buf_size -= len;
        rptr     += len;
    }

    return 0;
}

int av_fifo_generic_peek(AVFifoBuffer *f, void *dest, int buf_size,
                         void (*func)(void *, void *, int))
{
// Read memory barrier needed for SMP here in theory
    uint8_t *rptr = f->rptr;

    do {
        int len = FFMIN(f->end - rptr, buf_size);
        if (func)
            func(dest, rptr, len);
        else {
            memcpy(dest, rptr, len);
            dest = (uint8_t *)dest + len;
        }
// memory barrier needed for SMP here in theory
        rptr += len;
        if (rptr >= f->end)
            rptr -= f->end - f->buffer;
        buf_size -= len;
    } while (buf_size > 0);

    return 0;
}

int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags);

#define FF_REGET_BUFFER_FLAG_READONLY 1 ///< the returned buffer does not need to be writable

int ff_reget_buffer(AVCodecContext *avctx, AVFrame *frame, int flags);

int ff_thread_can_start_frame(AVCodecContext *avctx);

int avpriv_h264_has_num_reorder_frames(AVCodecContext *avctx);


int ff_codec_open2_recursive(AVCodecContext *avctx, const AVCodec *codec, AVDictionary **options);


int avpriv_bprint_to_extradata(AVCodecContext *avctx, struct AVBPrint *buf);

const uint8_t *avpriv_find_start_code(const uint8_t *p,
                                      const uint8_t *end,
                                      uint32_t *state);

int avpriv_codec_get_cap_skip_frame_fill_param(const AVCodec *codec);


int ff_set_dimensions(AVCodecContext *s, int width, int height);


int ff_set_sar(AVCodecContext *avctx, AVRational sar);


int ff_side_data_update_matrix_encoding(AVFrame *frame,
                                        enum AVMatrixEncoding matrix_encoding);


int ff_get_format(AVCodecContext *avctx, const enum AVPixelFormat *fmt);


AVCPBProperties *ff_add_cpb_side_data(AVCodecContext *avctx);


int ff_alloc_timecode_sei(const AVFrame *frame, AVRational rate, size_t prefix_len,
                     void **data, size_t *sei_size);


int64_t ff_guess_coded_bitrate(AVCodecContext *avctx);


int ff_int_from_list_or_default(void *ctx, const char * val_name, int val,
                                const int * array_valid_values, int default_value);

void ff_dvdsub_parse_palette(uint32_t *palette, const char *p);




AVRational av_codec_get_pkt_timebase(const AVCodecContext *avctx);

void av_codec_set_pkt_timebase(AVCodecContext *avctx, AVRational val);

const AVCodecDescriptor *av_codec_get_codec_descriptor(const AVCodecContext *avctx);

void av_codec_set_codec_descriptor(AVCodecContext *avctx, const AVCodecDescriptor *desc);

unsigned av_codec_get_codec_properties(const AVCodecContext *avctx);

int av_codec_get_lowres(const AVCodecContext *avctx);

void av_codec_set_lowres(AVCodecContext *avctx, int val);

int av_codec_get_seek_preroll(const AVCodecContext *avctx);

void av_codec_set_seek_preroll(AVCodecContext *avctx, int val);

uint16_t *av_codec_get_chroma_intra_matrix(const AVCodecContext *avctx);

void av_codec_set_chroma_intra_matrix(AVCodecContext *avctx, uint16_t *val);

struct AVSubtitle;

int av_codec_get_max_lowres(const AVCodec *codec);





AVCodec *av_codec_next(const AVCodec *c);

unsigned avcodec_version(void);

const char *avcodec_configuration(void);

const char *avcodec_license(void);

void avcodec_register(AVCodec *codec);

void avcodec_register_all(void);
AVCodecContext *avcodec_alloc_context3(const AVCodec *codec);

void avcodec_free_context(AVCodecContext **avctx);

int avcodec_get_context_defaults3(AVCodecContext *s, const AVCodec *codec);

const AVClass *avcodec_get_class(void);

const AVClass *avcodec_get_frame_class(void);

const AVClass *avcodec_get_subtitle_rect_class(void);

int avcodec_copy_context(AVCodecContext *dest, const AVCodecContext *src);

int avcodec_parameters_from_context(AVCodecParameters *par,
                                    const AVCodecContext *codec);

int avcodec_parameters_to_context(AVCodecContext *codec,
                                  const AVCodecParameters *par);
int avcodec_open2(AVCodecContext *avctx, const AVCodec *codec, AVDictionary **options);

void avsubtitle_free(AVSubtitle *sub);

int avcodec_default_get_buffer2(AVCodecContext *s, AVFrame *frame, int flags);

void avcodec_align_dimensions(AVCodecContext *s, int *width, int *height);

void avcodec_align_dimensions2(AVCodecContext *s, int *width, int *height,
                               int linesize_align[8]);

int avcodec_enum_to_chroma_pos(int *xpos, int *ypos, enum AVChromaLocation pos);

enum AVChromaLocation avcodec_chroma_pos_to_enum(int xpos, int ypos);

int avcodec_decode_audio4(AVCodecContext *avctx, AVFrame *frame,
                          int *got_frame_ptr, const AVPacket *avpkt);

int avcodec_decode_video2(AVCodecContext *avctx, AVFrame *picture,
                          int *got_picture_ptr,
                          const AVPacket *avpkt);
int avcodec_decode_subtitle2(AVCodecContext *avctx, AVSubtitle *sub,
                             int *got_sub_ptr,
                             AVPacket *avpkt);
int avcodec_send_packet(AVCodecContext *avctx, const AVPacket *avpkt);
int avcodec_receive_frame(AVCodecContext *avctx, AVFrame *frame);
int avcodec_send_frame(AVCodecContext *avctx, const AVFrame *frame);
int avcodec_receive_packet(AVCodecContext *avctx, AVPacket *avpkt);
int avcodec_get_hw_frames_parameters(AVCodecContext *avctx,
                                     AVBufferRef *device_ref,
                                     enum AVPixelFormat hw_pix_fmt,
                                     AVBufferRef **out_frames_ref);
                                     const AVCodecParser *av_parser_iterate(void **opaque);

AVCodecParser *av_parser_next(const AVCodecParser *c);

void av_register_codec_parser(AVCodecParser *parser);

AVCodecParserContext *av_parser_init(int codec_id);

int av_parser_parse2(AVCodecParserContext *s,
                     AVCodecContext *avctx,
                     uint8_t **poutbuf, int *poutbuf_size,
                     const uint8_t *buf, int buf_size,
                     int64_t pts, int64_t dts,
                     int64_t pos);

int av_parser_change(AVCodecParserContext *s,
                     AVCodecContext *avctx,
                     uint8_t **poutbuf, int *poutbuf_size,
                     const uint8_t *buf, int buf_size, int keyframe);
void av_parser_close(AVCodecParserContext *s);

int avcodec_encode_audio2(AVCodecContext *avctx, AVPacket *avpkt,
                          const AVFrame *frame, int *got_packet_ptr);

int avcodec_encode_video2(AVCodecContext *avctx, AVPacket *avpkt,
                          const AVFrame *frame, int *got_packet_ptr);

int avcodec_encode_subtitle(AVCodecContext *avctx, uint8_t *buf, int buf_size,
                            const AVSubtitle *sub);

int avpicture_alloc(AVPicture *picture, enum AVPixelFormat pix_fmt, int width, int height);

void avpicture_free(AVPicture *picture);

int avpicture_fill(AVPicture *picture, const uint8_t *ptr,
                   enum AVPixelFormat pix_fmt, int width, int height);

int avpicture_layout(const AVPicture *src, enum AVPixelFormat pix_fmt,
                     int width, int height,
                     unsigned char *dest, int dest_size);

int avpicture_get_size(enum AVPixelFormat pix_fmt, int width, int height);

void av_picture_copy(AVPicture *dst, const AVPicture *src,
                     enum AVPixelFormat pix_fmt, int width, int height);

int av_picture_crop(AVPicture *dst, const AVPicture *src,
                    enum AVPixelFormat pix_fmt, int top_band, int left_band);

int av_picture_pad(AVPicture *dst, const AVPicture *src, int height, int width, enum AVPixelFormat pix_fmt,
                   int padtop, int padbottom, int padleft, int padright, int *color);

void avcodec_get_chroma_sub_sample(enum AVPixelFormat pix_fmt, int *h_shift, int *v_shift);

unsigned int avcodec_pix_fmt_to_codec_tag(enum AVPixelFormat pix_fmt);

int avcodec_get_pix_fmt_loss(enum AVPixelFormat dst_pix_fmt, enum AVPixelFormat src_pix_fmt,
                             int has_alpha);
enum AVPixelFormat avcodec_find_best_pix_fmt_of_list(const enum AVPixelFormat *pix_fmt_list,
                                                     enum AVPixelFormat src_pix_fmt,
                                                     int has_alpha, int *loss_ptr);

enum AVPixelFormat avcodec_find_best_pix_fmt_of_2(enum AVPixelFormat dst_pix_fmt1, enum AVPixelFormat dst_pix_fmt2,
                                                  enum AVPixelFormat src_pix_fmt, int has_alpha, int *loss_ptr);

enum AVPixelFormat avcodec_find_best_pix_fmt2(enum AVPixelFormat dst_pix_fmt1, enum AVPixelFormat dst_pix_fmt2,
                                              enum AVPixelFormat src_pix_fmt, int has_alpha, int *loss_ptr);

enum AVPixelFormat avcodec_default_get_format(struct AVCodecContext *s, const enum AVPixelFormat *fmt);

size_t av_get_codec_tag_string(char *buf, size_t buf_size, unsigned int codec_tag);

void avcodec_string(char *buf, int buf_size, AVCodecContext *enc, int encode);

const char *av_get_profile_name(const AVCodec *codec, int profile);

const char *avcodec_profile_name(enum AVCodecID codec_id, int profile);

int avcodec_default_execute(AVCodecContext *c, int (*func)(AVCodecContext *c2, void *arg2), void *arg, int *ret, int count, int size);
int avcodec_default_execute2(AVCodecContext *c, int (*func)(AVCodecContext *c2, void *arg2, int, int), void *arg, int *ret, int count);

int avcodec_fill_audio_frame(AVFrame *frame, int nb_channels,
                             enum AVSampleFormat sample_fmt, const uint8_t *buf,
                             int buf_size, int align);
void avcodec_flush_buffers(AVCodecContext *avctx);

int av_get_bits_per_sample(enum AVCodecID codec_id);

enum AVCodecID av_get_pcm_codec(enum AVSampleFormat fmt, int be);

int av_get_exact_bits_per_sample(enum AVCodecID codec_id);

int av_get_audio_frame_duration(AVCodecContext *avctx, int frame_bytes);

int av_get_audio_frame_duration2(AVCodecParameters *par, int frame_bytes);
void av_register_bitstream_filter(AVBitStreamFilter *bsf);

AVBitStreamFilterContext *av_bitstream_filter_init(const char *name);

int av_bitstream_filter_filter(AVBitStreamFilterContext *bsfc,
                               AVCodecContext *avctx, const char *args,
                               uint8_t **poutbuf, int *poutbuf_size,
                               const uint8_t *buf, int buf_size, int keyframe);

void av_bitstream_filter_close(AVBitStreamFilterContext *bsf);

const AVBitStreamFilter *av_bitstream_filter_next(const AVBitStreamFilter *f);

const AVBitStreamFilter *av_bsf_next(void **opaque);

void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size);

void av_fast_padded_mallocz(void *ptr, unsigned int *size, size_t min_size);

unsigned int av_xiphlacing(unsigned char *s, unsigned int v);

void av_register_hwaccel(AVHWAccel *hwaccel);

AVHWAccel *av_hwaccel_next(const AVHWAccel *hwaccel);
int av_lockmgr_register(int (*cb)(void **mutex, enum AVLockOp op));
int avcodec_is_open(AVCodecContext *s);

#define FF_MAX_EXTRADATA_SIZE ((1 << 28) - AV_INPUT_BUFFER_PADDING_SIZE)

AVCPBProperties *av_cpb_properties_alloc(size_t *size);







const char *avio_find_protocol_name(const char *url);
int avio_check(const char *url, int flags);

int avpriv_io_move(const char *url_src, const char *url_dst);

int avpriv_io_delete(const char *url);

int avio_open_dir(AVIODirContext **s, const char *url, AVDictionary **options);

int avio_read_dir(AVIODirContext *s, AVIODirEntry **next);

int avio_close_dir(AVIODirContext **s);

void avio_free_directory_entry(AVIODirEntry **entry);
AVIOContext *avio_alloc_context(
    unsigned char *buffer,
    int buffer_size,
    int write_flag,
    void *opaque,
    int (*read_packet)(void *opaque, uint8_t *buf, int buf_size),
    int (*write_packet)(void *opaque, uint8_t *buf, int buf_size),
    int64_t (*seek)(void *opaque, int64_t offset, int whence));

void avio_context_free(AVIOContext **s);

void avio_w8(AVIOContext *s, int b);
void avio_write(AVIOContext *s, const unsigned char *buf, int size);
void avio_wl64(AVIOContext *s, uint64_t val);
void avio_wb64(AVIOContext *s, uint64_t val);
void avio_wl32(AVIOContext *s, unsigned int val);
void avio_wb32(AVIOContext *s, unsigned int val);
void avio_wl24(AVIOContext *s, unsigned int val);
void avio_wb24(AVIOContext *s, unsigned int val);
void avio_wl16(AVIOContext *s, unsigned int val);
void avio_wb16(AVIOContext *s, unsigned int val);

int avio_put_str(AVIOContext *s, const char *str);

int avio_put_str16le(AVIOContext *s, const char *str);

int avio_put_str16be(AVIOContext *s, const char *str);

void avio_write_marker(AVIOContext *s, int64_t time, enum AVIODataMarkerType type);


int64_t avio_seek(AVIOContext *s, int64_t offset, int whence);

int64_t avio_skip(AVIOContext *s, int64_t offset);

static inline int64_t avio_tell(AVIOContext *s)
{
    return avio_seek(s, 0,
                     1);
}

int64_t avio_size(AVIOContext *s);

int avio_feof(AVIOContext *s);

int avio_printf(AVIOContext *s, const char *fmt, ...);

void avio_print_string_array(AVIOContext *s, const char *strings[]);
// #define avio_print(s, ...) avio_print_string_array(s, (const char *[]){__VA_ARGS__, NULL})

void avio_flush(AVIOContext *s);

int avio_read(AVIOContext *s, unsigned char *buf, int size);

int avio_read_partial(AVIOContext *s, unsigned char *buf, int size);

int avio_r8(AVIOContext *s);
unsigned int avio_rl16(AVIOContext *s);
unsigned int avio_rl24(AVIOContext *s);
unsigned int avio_rl32(AVIOContext *s);
uint64_t avio_rl64(AVIOContext *s);
unsigned int avio_rb16(AVIOContext *s);
unsigned int avio_rb24(AVIOContext *s);
unsigned int avio_rb32(AVIOContext *s);
uint64_t avio_rb64(AVIOContext *s);
int avio_get_str(AVIOContext *pb, int maxlen, char *buf, int buflen);

int avio_get_str16le(AVIOContext *pb, int maxlen, char *buf, int buflen);
int avio_get_str16be(AVIOContext *pb, int maxlen, char *buf, int buflen);


int avio_open(AVIOContext **s, const char *url, int flags);
int avio_open2(AVIOContext **s, const char *url, int flags,
               const AVIOInterruptCB *int_cb, AVDictionary **options);

int avio_close(AVIOContext *s);

int avio_closep(AVIOContext **s);

int avio_open_dyn_buf(AVIOContext **s);

int avio_get_dyn_buf(AVIOContext *s, uint8_t **pbuffer);

int avio_close_dyn_buf(AVIOContext *s, uint8_t **pbuffer);

const char *avio_enum_protocols(void **opaque, int output);

const AVClass *avio_protocol_get_class(const char *name);

int avio_pause(AVIOContext *h, int pause);
int64_t avio_seek_time(AVIOContext *h, int stream_index,
                       int64_t timestamp, int flags);



int avio_read_to_bprint(AVIOContext *h, struct AVBPrint *pb, size_t max_size);

int avio_accept(AVIOContext *s, AVIOContext **c);
int avio_handshake(AVIOContext *c);

int av_get_packet(AVIOContext *s, AVPacket *pkt, int size);
int av_append_packet(AVIOContext *s, AVPacket *pkt, int size);





AVRational av_stream_get_r_frame_rate(const AVStream *s);

void av_stream_set_r_frame_rate(AVStream *s, AVRational r);

char *av_stream_get_recommended_encoder_configuration(const AVStream *s);

void av_stream_set_recommended_encoder_configuration(AVStream *s, char *configuration);

struct AVCodecParserContext *av_stream_get_parser(const AVStream *s);

int64_t av_stream_get_end_pts(const AVStream *st);


int av_format_get_probe_score(const AVFormatContext *s);

AVCodec *av_format_get_video_codec(const AVFormatContext *s);

void av_format_set_video_codec(AVFormatContext *s, AVCodec *c);

AVCodec *av_format_get_audio_codec(const AVFormatContext *s);

void av_format_set_audio_codec(AVFormatContext *s, AVCodec *c);

AVCodec *av_format_get_subtitle_codec(const AVFormatContext *s);

void av_format_set_subtitle_codec(AVFormatContext *s, AVCodec *c);

AVCodec *av_format_get_data_codec(const AVFormatContext *s);

void av_format_set_data_codec(AVFormatContext *s, AVCodec *c);

int av_format_get_metadata_header_padding(const AVFormatContext *s);

void av_format_set_metadata_header_padding(AVFormatContext *s, int c);

void *av_format_get_opaque(const AVFormatContext *s);

void av_format_set_opaque(AVFormatContext *s, void *opaque);

av_format_control_message av_format_get_control_message_cb(const AVFormatContext *s);

void av_format_set_control_message_cb(AVFormatContext *s, av_format_control_message callback);
AVOpenCallback av_format_get_open_cb(const AVFormatContext *s);
void av_format_set_open_cb(AVFormatContext *s, AVOpenCallback callback);

void av_format_inject_global_side_data(AVFormatContext *s);

enum AVDurationEstimationMethod av_fmt_ctx_get_duration_estimation_method(const AVFormatContext *ctx);

unsigned avformat_version(void);

const char *avformat_configuration(void);

const char *avformat_license(void);

void av_register_all(void);

void av_register_input_format(AVInputFormat *format);

void av_register_output_format(AVOutputFormat *format);

int avformat_network_init(void);

int avformat_network_deinit(void);

AVInputFormat *av_iformat_next(const AVInputFormat *f);

AVOutputFormat *av_oformat_next(const AVOutputFormat *f);


// #include "allformats.c"



#define IO_BUFFER_SIZE 32768


void avformat_free_context(AVFormatContext *s);

const AVClass *avformat_get_class(void);

AVStream *avformat_new_stream(AVFormatContext *s, const AVCodec *c);

int av_stream_add_side_data(AVStream *st, enum AVPacketSideDataType type,
                            uint8_t *data, size_t size);

uint8_t *av_stream_new_side_data(AVStream *stream,
                                 enum AVPacketSideDataType type, int size);

uint8_t *av_stream_get_side_data(const AVStream *stream,
                                 enum AVPacketSideDataType type, int *size);

AVProgram *av_new_program(AVFormatContext *s, int id);

int avformat_alloc_output_context2(AVFormatContext **ctx, AVOutputFormat *oformat,
                                   const char *format_name, const char *filename);

AVInputFormat *av_find_input_format(const char *short_name);

AVInputFormat *av_probe_input_format(AVProbeData *pd, int is_opened);

AVInputFormat *av_probe_input_format3(AVProbeData *pd, int is_opened, int *score_ret);

int av_probe_input_buffer2(AVIOContext *pb, AVInputFormat **fmt,
                           const char *url, void *logctx,
                           unsigned int offset, unsigned int max_probe_size);

int av_probe_input_buffer(AVIOContext *pb, AVInputFormat **fmt,
                          const char *url, void *logctx,
                          unsigned int offset, unsigned int max_probe_size);


int av_demuxer_open(AVFormatContext *ic);

int avformat_find_stream_info(AVFormatContext *ic, AVDictionary **options);

AVProgram *av_find_program_from_stream(AVFormatContext *ic, AVProgram *last, int s);

void av_program_add_stream_index(AVFormatContext *ac, int progid, unsigned int idx);

int av_find_best_stream(AVFormatContext *ic,
                        enum AVMediaType type,
                        int wanted_stream_nb,
                        int related_stream,
                        AVCodec **decoder_ret,
                        int flags);

int av_read_frame(AVFormatContext *s, AVPacket *pkt);

int av_seek_frame(AVFormatContext *s, int stream_index, int64_t timestamp,
                  int flags);

int avformat_seek_file(AVFormatContext *s, int stream_index, int64_t min_ts, int64_t ts, int64_t max_ts, int flags);

int avformat_flush(AVFormatContext *s);

int av_read_play(AVFormatContext *s);

int av_read_pause(AVFormatContext *s);

void avformat_close_input(AVFormatContext **s);
#define AVSEEK_FLAG_BACKWARD 1
#define AVSEEK_FLAG_BYTE 2
#define AVSEEK_FLAG_ANY 4
#define AVSEEK_FLAG_FRAME 8
#define AVSTREAM_INIT_IN_WRITE_HEADER 0
#define AVSTREAM_INIT_IN_INIT_OUTPUT 1

int avformat_write_header(AVFormatContext *s, AVDictionary **options);
int avformat_init_output(AVFormatContext *s, AVDictionary **options);
int av_write_frame(AVFormatContext *s, AVPacket *pkt);
int av_interleaved_write_frame(AVFormatContext *s, AVPacket *pkt);

int av_write_uncoded_frame(AVFormatContext *s, int stream_index,
                           AVFrame *frame);

int av_interleaved_write_uncoded_frame(AVFormatContext *s, int stream_index,
                                       AVFrame *frame);

int av_write_uncoded_frame_query(AVFormatContext *s, int stream_index);

int av_write_trailer(AVFormatContext *s);

AVOutputFormat *av_guess_format(const char *short_name,
                                const char *filename,
                                const char *mime_type);

enum AVCodecID av_guess_codec(AVOutputFormat *fmt, const char *short_name,
                              const char *filename, const char *mime_type,
                              enum AVMediaType type);

int av_get_output_timestamp(struct AVFormatContext *s, int stream,
                            int64_t *dts, int64_t *wall);

void av_hex_dump(FILE *f, const uint8_t *buf, int size);

void av_hex_dump_log(void *avcl, int level, const uint8_t *buf, int size);

void av_pkt_dump2(FILE *f, const AVPacket *pkt, int dump_payload, const AVStream *st);

void av_pkt_dump_log2(void *avcl, int level, const AVPacket *pkt, int dump_payload,
                      const AVStream *st);

enum AVCodecID av_codec_get_id(const struct AVCodecTag *const *tags, unsigned int tag);

unsigned int av_codec_get_tag(const struct AVCodecTag *const *tags, enum AVCodecID id);

int av_codec_get_tag2(const struct AVCodecTag *const *tags, enum AVCodecID id,
                      unsigned int *tag);

int av_find_default_stream_index(AVFormatContext *s);

int av_index_search_timestamp(AVStream *st, int64_t timestamp, int flags);

int av_add_index_entry(AVStream *st, int64_t pos, int64_t timestamp,
                       int size, int distance, int flags);

void av_url_split(char *proto, int proto_size,
                  char *authorization, int authorization_size,
                  char *hostname, int hostname_size,
                  int *port_ptr,
                  char *path, int path_size,
                  const char *url);

void av_dump_format(AVFormatContext *ic,
                    int index,
                    const char *url,
                    int is_output);
#define AV_FRAME_FILENAME_FLAGS_MULTIPLE 1

int av_get_frame_filename2(char *buf, int buf_size,
                           const char *path, int number, int flags);

int av_get_frame_filename(char *buf, int buf_size,
                          const char *path, int number);

int av_filename_number_test(const char *filename);

int av_sdp_create(AVFormatContext *ac[], int n_files, char *buf, int size);

int av_match_ext(const char *filename, const char *extensions);

int avformat_query_codec(const AVOutputFormat *ofmt, enum AVCodecID codec_id,
                         int std_compliance);

const struct AVCodecTag *avformat_get_riff_video_tags(void);

const struct AVCodecTag *avformat_get_riff_audio_tags(void);

const struct AVCodecTag *avformat_get_mov_video_tags(void);

const struct AVCodecTag *avformat_get_mov_audio_tags(void);

AVRational av_guess_sample_aspect_ratio(AVFormatContext *format, AVStream *stream, AVFrame *frame);

AVRational av_guess_frame_rate(AVFormatContext *ctx, AVStream *stream, AVFrame *frame);

int avformat_match_stream_specifier(AVFormatContext *s, AVStream *st,
                                    const char *spec);

int avformat_queue_attached_pictures(AVFormatContext *s);

int av_apply_bitstream_filters(AVCodecContext *codec, AVPacket *pkt,
                               AVBitStreamFilterContext *bsfc);

enum AVTimebaseSource
{
    AVFMT_TBCF_AUTO = -1,
    AVFMT_TBCF_DECODER,
    AVFMT_TBCF_DEMUXER,
    AVFMT_TBCF_R_FRAMERATE,
};

int avformat_transfer_internal_stream_timing_info(const AVOutputFormat *ofmt,
                                                  AVStream *ost, const AVStream *ist,
                                                  enum AVTimebaseSource copy_tb);

AVRational av_stream_get_codec_timebase(const AVStream *st);
#define AVDEVICE_AVDEVICE_H
#define AVDEVICE_VERSION_H
#define LIBAVDEVICE_VERSION_MAJOR 58
#define LIBAVDEVICE_VERSION_MINOR 11
#define LIBAVDEVICE_VERSION_MICRO 102
#define LIBAVDEVICE_VERSION_INT AV_VERSION_INT(LIBAVDEVICE_VERSION_MAJOR, LIBAVDEVICE_VERSION_MINOR, LIBAVDEVICE_VERSION_MICRO)
#define LIBAVDEVICE_VERSION AV_VERSION(LIBAVDEVICE_VERSION_MAJOR, LIBAVDEVICE_VERSION_MINOR, LIBAVDEVICE_VERSION_MICRO)
#define LIBAVDEVICE_BUILD LIBAVDEVICE_VERSION_INT
// #define LIBAVDEVICE_IDENT "Lavd" AV_STRINGIFY(LIBAVDEVICE_VERSION)
#define AVUTIL_OPT_H
#define AV_OPT_FLAG_ENCODING_PARAM 1
#define AV_OPT_FLAG_DECODING_PARAM 2
#define AV_OPT_FLAG_AUDIO_PARAM 8
#define AV_OPT_FLAG_VIDEO_PARAM 16
#define AV_OPT_FLAG_SUBTITLE_PARAM 32
#define AV_OPT_FLAG_EXPORT 64
#define AV_OPT_FLAG_READONLY 128
#define AV_OPT_FLAG_BSF_PARAM (1 << 8)
#define AV_OPT_FLAG_RUNTIME_PARAM (1 << 15)
#define AV_OPT_FLAG_FILTERING_PARAM (1 << 16)
#define AV_OPT_FLAG_DEPRECATED (1 << 17)
#define AV_OPT_FLAG_CHILD_CONSTS (1 << 18)

enum AVOptionType
{
    AV_OPT_TYPE_FLAGS,
    AV_OPT_TYPE_INT,
    AV_OPT_TYPE_INT64,
    AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT,
    AV_OPT_TYPE_STRING,
    AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY, ///< offset must point to a pointer immediately followed by an int for the length
    AV_OPT_TYPE_DICT,
    AV_OPT_TYPE_UINT64,
    AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE, ///< offset must point to two consecutive integers
    AV_OPT_TYPE_PIXEL_FMT,
    AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE, ///< offset must point to AVRational
    AV_OPT_TYPE_DURATION,
    AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT,
    AV_OPT_TYPE_BOOL,
};

typedef struct AVOption
{
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union
    {
        int64_t i64;
        double dbl;
        const char *str;
        AVRational q;
    } default_val;
    double min; ///< minimum valid value for the option
    double max; ///< maximum valid value for the option
    int flags;
    const char *unit;
} AVOption;

typedef struct AVOptionRange
{
    const char *str;
    double value_min, value_max;
    double component_min, component_max;
    int is_range;
} AVOptionRange;

typedef struct AVOptionRanges
{
    AVOptionRange **range;
    int nb_ranges;
    int nb_components;
} AVOptionRanges;

enum
{
    AV_OPT_FLAG_IMPLICIT_KEY = 1,
};
typedef struct AVDeviceRect
{
    int x;
    int y;
    int width;
    int height;
} AVDeviceRect;

enum AVAppToDevMessageType
{
    AV_APP_TO_DEV_NONE = (('1') | (('N') << 8) | (('O') << 16) | ((unsigned)('N') << 24)),
    AV_APP_TO_DEV_WINDOW_SIZE = (('M') | (('O') << 8) | (('1') << 16) | ((unsigned)('G') << 24)),
    AV_APP_TO_DEV_WINDOW_REPAINT = (('A') | (('P') << 8) | (('1') << 16) | ((unsigned)('R') << 24)),
    AV_APP_TO_DEV_PAUSE = ((' ') | (('U') << 8) | (('A') << 16) | ((unsigned)('P') << 24)),
    AV_APP_TO_DEV_PLAY = (('Y') | (('A') << 8) | (('L') << 16) | ((unsigned)('P') << 24)),
    AV_APP_TO_DEV_TOGGLE_PAUSE = (('T') | (('U') << 8) | (('A') << 16) | ((unsigned)('P') << 24)),
    AV_APP_TO_DEV_SET_VOLUME = (('L') | (('O') << 8) | (('V') << 16) | ((unsigned)('S') << 24)),
    AV_APP_TO_DEV_MUTE = (('T') | (('U') << 8) | (('M') << 16) | ((unsigned)(' ') << 24)),
    AV_APP_TO_DEV_UNMUTE = (('T') | (('U') << 8) | (('M') << 16) | ((unsigned)('U') << 24)),
    AV_APP_TO_DEV_TOGGLE_MUTE = (('T') | (('U') << 8) | (('M') << 16) | ((unsigned)('T') << 24)),
    AV_APP_TO_DEV_GET_VOLUME = (('L') | (('O') << 8) | (('V') << 16) | ((unsigned)('G') << 24)),
    AV_APP_TO_DEV_GET_MUTE = (('T') | (('U') << 8) | (('M') << 16) | ((unsigned)('G') << 24)),
};

enum AVDevToAppMessageType
{
    AV_DEV_TO_APP_NONE = (('1') | (('N') << 8) | (('O') << 16) | ((unsigned)('N') << 24)),
    AV_DEV_TO_APP_CREATE_WINDOW_BUFFER = (('1') | (('R') << 8) | (('C') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_PREPARE_WINDOW_BUFFER = (('1') | (('R') << 8) | (('P') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_DISPLAY_WINDOW_BUFFER = (('S') | (('I') << 8) | (('2') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_DESTROY_WINDOW_BUFFER = (('S') | (('1') << 8) | (('2') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_BUFFER_OVERFLOW = (('L') | (('F') << 8) | (('O') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_BUFFER_UNDERFLOW = (('L') | (('F') << 8) | (('U') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_BUFFER_READABLE = ((' ') | (('2') << 8) | (('R') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_BUFFER_WRITABLE = ((' ') | (('R') << 8) | (('W') << 16) | ((unsigned)('B') << 24)),
    AV_DEV_TO_APP_MUTE_STATE_CHANGED = (('T') | (('U') << 8) | (('M') << 16) | ((unsigned)('C') << 24)),
    AV_DEV_TO_APP_VOLUME_LEVEL_CHANGED = (('L') | (('O') << 8) | (('V') << 16) | ((unsigned)('C') << 24)),
};

int av_opt_show2(void *obj, void *av_log_obj, int req_flags, int rej_flags);

void av_opt_set_defaults(void *s);

void av_opt_set_defaults2(void *s, int mask, int flags);

int av_set_options_string(void *ctx, const char *opts,
                          const char *key_val_sep, const char *pairs_sep);

int av_opt_set_from_string(void *ctx, const char *opts,
                           const char *const *shorthand,
                           const char *key_val_sep, const char *pairs_sep);

void av_opt_free(void *obj);

int av_opt_flag_is_set(void *obj, const char *field_name, const char *flag_name);

int av_opt_set_dict(void *obj, struct AVDictionary **options);

int av_opt_set_dict2(void *obj, struct AVDictionary **options, int search_flags);

int av_opt_get_key_value(const char **ropts,
                         const char *key_val_sep, const char *pairs_sep,
                         unsigned flags,
                         char **rkey, char **rval);


int av_opt_eval_flags(void *obj, const AVOption *o, const char *val, int *flags_out);
int av_opt_eval_int(void *obj, const AVOption *o, const char *val, int *int_out);
int av_opt_eval_int64(void *obj, const AVOption *o, const char *val, int64_t *int64_out);
int av_opt_eval_float(void *obj, const AVOption *o, const char *val, float *float_out);
int av_opt_eval_double(void *obj, const AVOption *o, const char *val, double *double_out);
int av_opt_eval_q(void *obj, const AVOption *o, const char *val, AVRational *q_out);
#define AV_OPT_SEARCH_CHILDREN (1 << 0)
#define AV_OPT_SEARCH_FAKE_OBJ (1 << 1)
#define AV_OPT_ALLOW_NULL (1 << 2)
#define AV_OPT_MULTI_COMPONENT_RANGE (1 << 12)

const AVOption *av_opt_find(void *obj, const char *name, const char *unit,
                            int opt_flags, int search_flags);

const AVOption *av_opt_find2(void *obj, const char *name, const char *unit,
                             int opt_flags, int search_flags, void **target_obj);

const AVOption *av_opt_next(const void *obj, const AVOption *prev);

void *av_opt_child_next(void *obj, void *prev);

const AVClass *av_opt_child_class_next(const AVClass *parent, const AVClass *prev);

const AVClass *av_opt_child_class_iterate(const AVClass *parent, void **iter);

int av_opt_set(void *obj, const char *name, const char *val, int search_flags);
int av_opt_set_int(void *obj, const char *name, int64_t val, int search_flags);
int av_opt_set_double(void *obj, const char *name, double val, int search_flags);
int av_opt_set_q(void *obj, const char *name, AVRational val, int search_flags);
int av_opt_set_bin(void *obj, const char *name, const uint8_t *val, int size, int search_flags);
int av_opt_set_image_size(void *obj, const char *name, int w, int h, int search_flags);
int av_opt_set_pixel_fmt(void *obj, const char *name, enum AVPixelFormat fmt, int search_flags);
int av_opt_set_sample_fmt(void *obj, const char *name, enum AVSampleFormat fmt, int search_flags);
int av_opt_set_video_rate(void *obj, const char *name, AVRational val, int search_flags);
int av_opt_set_channel_layout(void *obj, const char *name, int64_t ch_layout, int search_flags);

int av_opt_set_dict_val(void *obj, const char *name, const AVDictionary *val, int search_flags);
#define av_opt_set_int_list(obj, name, val, term, flags) (av_int_list_length(val, term) > INT_MAX / sizeof(*(val)) ? AVERROR(EINVAL) : av_opt_set_bin(obj, name, (const uint8_t *)(val), av_int_list_length(val, term) * sizeof(*(val)), flags))

int av_opt_get(void *obj, const char *name, int search_flags, uint8_t **out_val);
int av_opt_get_int(void *obj, const char *name, int search_flags, int64_t *out_val);
int av_opt_get_double(void *obj, const char *name, int search_flags, double *out_val);
int av_opt_get_q(void *obj, const char *name, int search_flags, AVRational *out_val);
int av_opt_get_image_size(void *obj, const char *name, int search_flags, int *w_out, int *h_out);
int av_opt_get_pixel_fmt(void *obj, const char *name, int search_flags, enum AVPixelFormat *out_fmt);
int av_opt_get_sample_fmt(void *obj, const char *name, int search_flags, enum AVSampleFormat *out_fmt);
int av_opt_get_video_rate(void *obj, const char *name, int search_flags, AVRational *out_val);
int av_opt_get_channel_layout(void *obj, const char *name, int search_flags, int64_t *ch_layout);

int av_opt_get_dict_val(void *obj, const char *name, int search_flags, AVDictionary **out_val);

void *av_opt_ptr(const AVClass *avclass, void *obj, const char *name);

void av_opt_freep_ranges(AVOptionRanges **ranges);

int av_opt_query_ranges(AVOptionRanges **, void *obj, const char *key, int flags);

int av_opt_copy(void *dest, const void *src);

int av_opt_query_ranges_default(AVOptionRanges **, void *obj, const char *key, int flags);

int av_opt_is_set_to_default(void *obj, const AVOption *o);

int av_opt_is_set_to_default_by_name(void *obj, const char *name, int search_flags);
#define AV_OPT_SERIALIZE_SKIP_DEFAULTS 0x00000001
#define AV_OPT_SERIALIZE_OPT_FLAGS_EXACT 0x00000002

int av_opt_serialize(void *obj, int opt_flags, int flags, char **buffer,
                     const char key_val_sep, const char pairs_sep);

unsigned avdevice_version(void);

const char *avdevice_configuration(void);

const char *avdevice_license(void);

void avdevice_register_all(void);

AVInputFormat *av_input_audio_device_next(AVInputFormat *d);

AVInputFormat *av_input_video_device_next(AVInputFormat *d);

AVOutputFormat *av_output_audio_device_next(AVOutputFormat *d);

AVOutputFormat *av_output_video_device_next(AVOutputFormat *d);


int avdevice_app_to_dev_control_message(struct AVFormatContext *s,
                                        enum AVAppToDevMessageType type,
                                        void *data, size_t data_size);

int avdevice_dev_to_app_control_message(struct AVFormatContext *s,
                                        enum AVDevToAppMessageType type,
                                        void *data, size_t data_size);


static void *  worker(void *v);
void ff_frame_thread_encoder_free(AVCodecContext *avctx){
    int i;
    ThreadContext *c= avctx->internal->frame_thread_encoder;

    pthread_mutex_lock(&c->task_fifo_mutex);
    atomic_store(&c->exit, 1);
    pthread_cond_broadcast(&c->task_fifo_cond);
    pthread_mutex_unlock(&c->task_fifo_mutex);

    for (i=0; i<avctx->thread_count; i++) {
         pthread_join(c->worker[i], NULL);
    }

    while (av_fifo_size(c->task_fifo) > 0) {
        Task task;
        AVFrame *frame;
        av_fifo_generic_read(c->task_fifo, &task, sizeof(task), NULL);
        frame = task.indata;
        av_frame_free(&frame);
        task.indata = NULL;
    }

    for (i=0; i<BUFFER_SIZE; i++) {
        if (c->finished_tasks[i].outdata != NULL) {
            AVPacket *pkt = c->finished_tasks[i].outdata;
            av_packet_free(&pkt);
            c->finished_tasks[i].outdata = NULL;
        }
    }

    pthread_mutex_destroy(&c->task_fifo_mutex);
    pthread_mutex_destroy(&c->finished_task_mutex);
    pthread_mutex_destroy(&c->buffer_mutex);
    pthread_cond_destroy(&c->task_fifo_cond);
    pthread_cond_destroy(&c->finished_task_cond);
    av_fifo_freep(&c->task_fifo);
    av_freep(&avctx->internal->frame_thread_encoder);
}


int ff_frame_thread_encoder_init(AVCodecContext *avctx, AVDictionary *options){
    int i=0;
    ThreadContext *c;


    if(   !(avctx->thread_type & FF_THREAD_FRAME)
       || !(avctx->codec->capabilities & AV_CODEC_CAP_FRAME_THREADS))
        return 0;

    if(   !avctx->thread_count
       && avctx->codec_id == AV_CODEC_ID_MJPEG
       && !(avctx->flags & AV_CODEC_FLAG_QSCALE)) {
        av_log(avctx, AV_LOG_DEBUG,
               "Forcing thread count to 1 for MJPEG encoding, use -thread_type slice "
               "or a constant quantizer if you want to use multiple cpu cores\n");
        avctx->thread_count = 1;
    }
    if(   avctx->thread_count > 1
       && avctx->codec_id == AV_CODEC_ID_MJPEG
       && !(avctx->flags & AV_CODEC_FLAG_QSCALE))
        av_log(avctx, AV_LOG_WARNING,
               "MJPEG CBR encoding works badly with frame multi-threading, consider "
               "using -threads 1, -thread_type slice or a constant quantizer.\n");

    if (avctx->codec_id == AV_CODEC_ID_HUFFYUV ||
        avctx->codec_id == AV_CODEC_ID_FFVHUFF) {
        int warn = 0;
        int context_model = 0;
        AVDictionaryEntry *con = av_dict_get(options, "context", NULL, AV_DICT_MATCH_CASE);

        if (con && con->value)
            context_model = atoi(con->value);

        if (avctx->flags & AV_CODEC_FLAG_PASS1)
            warn = 1;
        else if(context_model > 0) {
            AVDictionaryEntry *t = av_dict_get(options, "non_deterministic",
                                               NULL, AV_DICT_MATCH_CASE);
            warn = !t || !t->value || !atoi(t->value) ? 1 : 0;
        }
        // huffyuv does not support these with multiple frame threads currently
        if (warn) {
            av_log(avctx, AV_LOG_WARNING,
               "Forcing thread count to 1 for huffyuv encoding with first pass or context 1\n");
            avctx->thread_count = 1;
        }
    }

    if(!avctx->thread_count) {
        avctx->thread_count = av_cpu_count();
        avctx->thread_count = FFMIN(avctx->thread_count, MAX_THREADS);
    }

    if(avctx->thread_count <= 1)
        return 0;

    if(avctx->thread_count > MAX_THREADS)
        return AVERROR(EINVAL);

    av_assert0(!avctx->internal->frame_thread_encoder);
    c = avctx->internal->frame_thread_encoder = av_mallocz(sizeof(ThreadContext));
    if(!c)
        return AVERROR(ENOMEM);

    c->parent_avctx = avctx;

    c->task_fifo = av_fifo_alloc_array(BUFFER_SIZE, sizeof(Task));
    if(!c->task_fifo)
        goto fail;

    pthread_mutex_init(&c->task_fifo_mutex, NULL);
    pthread_mutex_init(&c->finished_task_mutex, NULL);
    pthread_mutex_init(&c->buffer_mutex, NULL);
    pthread_cond_init(&c->task_fifo_cond, NULL);
    pthread_cond_init(&c->finished_task_cond, NULL);
    atomic_init(&c->exit, 0);

    for(i=0; i<avctx->thread_count ; i++){
        AVDictionary *tmp = NULL;
        int ret;
        void *tmpv;
        AVCodecContext *thread_avctx = avcodec_alloc_context3(avctx->codec);
        if(!thread_avctx)
            goto fail;
        tmpv = thread_avctx->priv_data;
        *thread_avctx = *avctx;
        ret = av_opt_copy(thread_avctx, avctx);
        if (ret < 0)
            goto fail;
        thread_avctx->priv_data = tmpv;
        thread_avctx->internal = NULL;
        if (avctx->codec->priv_class) {
            int ret = av_opt_copy(thread_avctx->priv_data, avctx->priv_data);
            if (ret < 0)
                goto fail;
        } else if (avctx->codec->priv_data_size) {
            memcpy(thread_avctx->priv_data, avctx->priv_data, avctx->codec->priv_data_size);
        }
        thread_avctx->thread_count = 1;
        thread_avctx->active_thread_type &= ~FF_THREAD_FRAME;

        av_dict_copy(&tmp, options, 0);
        av_dict_set(&tmp, "threads", "1", 0);
        if(avcodec_open2(thread_avctx, avctx->codec, &tmp) < 0) {
            av_dict_free(&tmp);
            goto fail;
        }
        av_dict_free(&tmp);
        av_assert0(!thread_avctx->internal->frame_thread_encoder);
        thread_avctx->internal->frame_thread_encoder = c;
        if(pthread_create(&c->worker[i], NULL, worker, thread_avctx)) {
            goto fail;
        }
    }

    avctx->active_thread_type = FF_THREAD_FRAME;

    return 0;
fail:
    avctx->thread_count = i;
    av_log(avctx, AV_LOG_ERROR, "ff_frame_thread_encoder_init failed\n");
    ff_frame_thread_encoder_free(avctx);
    return -1;
}
int ff_thread_init(AVCodecContext *s)
{
    return -1;
}


static void codec_parameters_reset(AVCodecParameters *par)
{
    av_freep(&par->extradata);

    memset(par, 0, sizeof(*par));

    par->codec_type          = AVMEDIA_TYPE_UNKNOWN;
    par->codec_id            = AV_CODEC_ID_NONE;
    par->format              = -1;
    par->field_order         = AV_FIELD_UNKNOWN;
    par->color_range         = AVCOL_RANGE_UNSPECIFIED;
    par->color_primaries     = AVCOL_PRI_UNSPECIFIED;
    par->color_trc           = AVCOL_TRC_UNSPECIFIED;
    par->color_space         = AVCOL_SPC_UNSPECIFIED;
    par->chroma_location     = AVCHROMA_LOC_UNSPECIFIED;
    par->sample_aspect_ratio = (AVRational){ 0, 1 };
    par->profile             = FF_PROFILE_UNKNOWN;
    par->level               = FF_LEVEL_UNKNOWN;
}


int avcodec_parameters_from_context(AVCodecParameters *par,
                                    const AVCodecContext *codec)
{
    codec_parameters_reset(par);

    par->codec_type = codec->codec_type;
    par->codec_id   = codec->codec_id;
    par->codec_tag  = codec->codec_tag;

    par->bit_rate              = codec->bit_rate;
    par->bits_per_coded_sample = codec->bits_per_coded_sample;
    par->bits_per_raw_sample   = codec->bits_per_raw_sample;
    par->profile               = codec->profile;
    par->level                 = codec->level;

    switch (par->codec_type) {
    case AVMEDIA_TYPE_VIDEO:
        par->format              = codec->pix_fmt;
        par->width               = codec->width;
        par->height              = codec->height;
        par->field_order         = codec->field_order;
        par->color_range         = codec->color_range;
        par->color_primaries     = codec->color_primaries;
        par->color_trc           = codec->color_trc;
        par->color_space         = codec->colorspace;
        par->chroma_location     = codec->chroma_sample_location;
        par->sample_aspect_ratio = codec->sample_aspect_ratio;
        par->video_delay         = codec->has_b_frames;
        break;
    case AVMEDIA_TYPE_AUDIO:
        par->format           = codec->sample_fmt;
        par->channel_layout   = codec->channel_layout;
        par->channels         = codec->channels;
        par->sample_rate      = codec->sample_rate;
        par->block_align      = codec->block_align;
        par->frame_size       = codec->frame_size;
        par->initial_padding  = codec->initial_padding;
        par->trailing_padding = codec->trailing_padding;
        par->seek_preroll     = codec->seek_preroll;
        break;
    case AVMEDIA_TYPE_SUBTITLE:
        par->width  = codec->width;
        par->height = codec->height;
        break;
    }

    if (codec->extradata) {
        par->extradata = av_mallocz(codec->extradata_size + AV_INPUT_BUFFER_PADDING_SIZE);
        if (!par->extradata)
            return AVERROR(ENOMEM);
        memcpy(par->extradata, codec->extradata, codec->extradata_size);
        par->extradata_size = codec->extradata_size;
    }

    return 0;
}

int ff_decode_bsfs_init(AVCodecContext *avctx)
{
    AVCodecInternal *avci = avctx->internal;
    int ret;

    if (avci->bsf)
        return 0;

    ret = av_bsf_list_parse_str(avctx->codec->bsfs, &avci->bsf);
    if (ret < 0) {
        av_log(avctx, AV_LOG_ERROR, "Error parsing decoder bitstream filters '%s': %s\n", avctx->codec->bsfs, av_err2str(ret));
        if (ret != AVERROR(ENOMEM))
            ret = AVERROR_BUG;
        goto fail;
    }

    
    avci->bsf->time_base_in = (AVRational){ 1, 90000 };
    ret = avcodec_parameters_from_context(avci->bsf->par_in, avctx);
    if (ret < 0)
        goto fail;

    ret = av_bsf_init(avci->bsf);
    if (ret < 0)
        goto fail;

    return 0;
fail:
    av_bsf_free(&avci->bsf);
    return ret;
}

typedef struct AVSliceThread AVSliceThread;

typedef struct WorkerContext
{
    AVSliceThread *ctx;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_t thread;
    int done;
} WorkerContext;

struct AVSliceThread
{
    WorkerContext *workers;
    int nb_threads;
    int nb_active_threads;
    int nb_jobs;
    atomic_uint first_job;
    atomic_uint current_job;
    pthread_mutex_t done_mutex;
    pthread_cond_t done_cond;
    int done;
    int finished;

    void *priv;
    void (*worker_func)(void *priv, int jobnr, int threadnr, int nb_jobs, int nb_threads);
    void (*main_func)(void *priv);
};
typedef struct AVSliceThread AVSliceThread;


void avpriv_slicethread_free(AVSliceThread **pctx)
{
    AVSliceThread *ctx;
    int nb_workers, i;

    if (!pctx || !*pctx)
        return;

    ctx = *pctx;
    nb_workers = ctx->nb_threads;
    if (!ctx->main_func)
        nb_workers--;

    ctx->finished = 1;
    for (i = 0; i < nb_workers; i++) {
        WorkerContext *w = &ctx->workers[i];
        pthread_mutex_lock(&w->mutex);
        w->done = 0;
        pthread_cond_signal(&w->cond);
        pthread_mutex_unlock(&w->mutex);
    }

    for (i = 0; i < nb_workers; i++) {
        WorkerContext *w = &ctx->workers[i];
        pthread_join(w->thread, NULL);
        pthread_cond_destroy(&w->cond);
        pthread_mutex_destroy(&w->mutex);
    }

    pthread_cond_destroy(&ctx->done_cond);
    pthread_mutex_destroy(&ctx->done_mutex);
    av_freep(&ctx->workers);
    av_freep(pctx);
}
typedef int(action_func)(AVCodecContext *c, void *arg);
typedef int(action_func2)(AVCodecContext *c, void *arg, int jobnr, int threadnr);
typedef int(main_func)(AVCodecContext *c);
typedef struct SliceThreadContext
{
    AVSliceThread *thread;
    action_func *func;
    action_func2 *func2;
    main_func *mainfunc;
    void *args;
    int *rets;
    int job_size;

    int *entries;
    int entries_count;
    int thread_count;
    pthread_cond_t *progress_cond;
    pthread_mutex_t *progress_mutex;
} SliceThreadContext;
void ff_slice_thread_free(AVCodecContext *avctx)
{
    SliceThreadContext *c = avctx->internal->thread_ctx;
    int i;

    avpriv_slicethread_free(&c->thread);

    for (i = 0; i < c->thread_count; i++) {
        pthread_mutex_destroy(&c->progress_mutex[i]);
        pthread_cond_destroy(&c->progress_cond[i]);
    }

    av_freep(&c->entries);
    av_freep(&c->progress_mutex);
    av_freep(&c->progress_cond);
    av_freep(&avctx->internal->thread_ctx);
}
typedef struct PerThreadContext
{
    struct FrameThreadContext *parent;
    pthread_t thread;
    int thread_init;
    pthread_cond_t input_cond;      ///< Used to wait for a new packet from the main thread.
    pthread_cond_t progress_cond;   ///< Used by child threads to wait for progress to change.
    pthread_cond_t output_cond;     ///< Used by the main thread to wait for frames to finish.
    pthread_mutex_t mutex;          ///< Mutex used to protect the contents of the PerThreadContext.
    pthread_mutex_t progress_mutex; ///< Mutex used to protect frame progress values and progress_cond.
    AVCodecContext *avctx;          ///< Context used to decode packets passed to this thread.
    AVPacket avpkt;                 ///< Input packet (for decoding) or output (for encoding).
    AVFrame *frame;                 ///< Output frame (for decoding) or input (for encoding).
    int got_frame;                  ///< The output of got_picture_ptr from the last avcodec_decode_video() call.
    int result;                     ///< The result of the last codec decode/encode() call.
    atomic_int state;
    AVFrame **released_buffers;
    int num_released_buffers;
    int released_buffers_allocated;
    AVFrame *requested_frame;                    ///< AVFrame the codec passed to get_buffer()
    int requested_flags;                         ///< flags passed to get_buffer() for requested_frame
    const enum AVPixelFormat *available_formats; ///< Format array for get_format()
    enum AVPixelFormat result_format;            ///< get_format() result
    int die;                                     ///< Set when the thread should exit.
    int hwaccel_serializing;
    int async_serializing;
    atomic_int debug_threads; ///< Set if the FF_DEBUG_THREADS option is set.
} PerThreadContext;

typedef struct FrameThreadContext
{
    PerThreadContext *threads;     ///< The contexts for each thread.
    PerThreadContext *prev_thread; ///< The last thread submit_packet() was called on.

    pthread_mutex_t buffer_mutex; ///< Mutex used to protect get/release_buffer().

    pthread_mutex_t hwaccel_mutex;
    pthread_mutex_t async_mutex;
    pthread_cond_t async_cond;
    int async_lock;
    int next_decoding; ///< The next context to submit a packet to.
    int next_finished; ///< The next context to return output from.
    int delaying;
} FrameThreadContext;

static void async_lock(FrameThreadContext *fctx)
{
    pthread_mutex_lock(&fctx->async_mutex);
    while (fctx->async_lock)
        pthread_cond_wait(&fctx->async_cond, &fctx->async_mutex);
    fctx->async_lock = 1;
    pthread_mutex_unlock(&fctx->async_mutex);
}
static void async_unlock(FrameThreadContext *fctx)
{
    pthread_mutex_lock(&fctx->async_mutex);
    av_assert0(fctx->async_lock);
    fctx->async_lock = 0;
    pthread_cond_broadcast(&fctx->async_cond);
    pthread_mutex_unlock(&fctx->async_mutex);
}

static void park_frame_worker_threads(FrameThreadContext *fctx, int thread_count)
{
    int i;

    async_unlock(fctx);

    for (i = 0; i < thread_count; i++) {
        PerThreadContext *p = &fctx->threads[i];

        if (atomic_load(&p->state) != STATE_INPUT_READY) {
            pthread_mutex_lock(&p->progress_mutex);
            while (atomic_load(&p->state) != STATE_INPUT_READY)
                pthread_cond_wait(&p->output_cond, &p->progress_mutex);
            pthread_mutex_unlock(&p->progress_mutex);
        }
        p->got_frame = 0;
    }

    async_lock(fctx);
}
int av_buffer_replace(AVBufferRef **pdst, AVBufferRef *src)
{
    AVBufferRef *dst = *pdst;
    AVBufferRef *tmp;

    if (!src) {
        av_buffer_unref(pdst);
        return 0;
    }

    if (dst && dst->buffer == src->buffer) {
        
        dst->data = src->data;
        dst->size = src->size;
        return 0;
    }

    tmp = av_buffer_ref(src);
    if (!tmp)
        return AVERROR(ENOMEM);

    av_buffer_unref(pdst);
    *pdst = tmp;
    return 0;
}

static int update_context_from_thread(AVCodecContext *dst, AVCodecContext *src, int for_user)
{
    int err = 0;

    if (dst != src && (for_user || src->codec->update_thread_context)) {
        dst->time_base = src->time_base;
        dst->framerate = src->framerate;
        dst->width     = src->width;
        dst->height    = src->height;
        dst->pix_fmt   = src->pix_fmt;
        dst->sw_pix_fmt = src->sw_pix_fmt;

        dst->coded_width  = src->coded_width;
        dst->coded_height = src->coded_height;

        dst->has_b_frames = src->has_b_frames;
        dst->idct_algo    = src->idct_algo;

        dst->bits_per_coded_sample = src->bits_per_coded_sample;
        dst->sample_aspect_ratio   = src->sample_aspect_ratio;

        dst->profile = src->profile;
        dst->level   = src->level;

        dst->bits_per_raw_sample = src->bits_per_raw_sample;
        dst->ticks_per_frame     = src->ticks_per_frame;
        dst->color_primaries     = src->color_primaries;

        dst->color_trc   = src->color_trc;
        dst->colorspace  = src->colorspace;
        dst->color_range = src->color_range;
        dst->chroma_sample_location = src->chroma_sample_location;

        dst->hwaccel = src->hwaccel;
        dst->hwaccel_context = src->hwaccel_context;

        dst->channels       = src->channels;
        dst->sample_rate    = src->sample_rate;
        dst->sample_fmt     = src->sample_fmt;
        dst->channel_layout = src->channel_layout;
        dst->internal->hwaccel_priv_data = src->internal->hwaccel_priv_data;

        if (!!dst->hw_frames_ctx != !!src->hw_frames_ctx ||
            (dst->hw_frames_ctx && dst->hw_frames_ctx->data != src->hw_frames_ctx->data)) {
            av_buffer_unref(&dst->hw_frames_ctx);

            if (src->hw_frames_ctx) {
                dst->hw_frames_ctx = av_buffer_ref(src->hw_frames_ctx);
                if (!dst->hw_frames_ctx)
                    return AVERROR(ENOMEM);
            }
        }

        dst->hwaccel_flags = src->hwaccel_flags;

        err = av_buffer_replace(&dst->internal->pool, src->internal->pool);
        if (err < 0)
            return err;
    }

    if (for_user) {
#if FF_API_CODED_FRAME
        dst->coded_frame = src->coded_frame;
#endif
    } else {
        if (dst->codec->update_thread_context)
            err = dst->codec->update_thread_context(dst, src);
    }

    return err;
}
static void release_delayed_buffers(PerThreadContext *p)
{
    FrameThreadContext *fctx = p->parent;

    while (p->num_released_buffers > 0) {
        AVFrame *f;

        pthread_mutex_lock(&fctx->buffer_mutex);
        av_assert0(p->avctx->codec_type == AVMEDIA_TYPE_VIDEO ||
                   p->avctx->codec_type == AVMEDIA_TYPE_AUDIO);
        f = p->released_buffers[--p->num_released_buffers];
        f->extended_data = f->data;
        av_frame_unref(f);

        pthread_mutex_unlock(&fctx->buffer_mutex);
    }
}
void ff_frame_thread_free(AVCodecContext *avctx, int thread_count)
{
    FrameThreadContext *fctx = avctx->internal->thread_ctx;
    const AVCodec *codec = avctx->codec;
    int i, j;

    park_frame_worker_threads(fctx, thread_count);

    if (fctx->prev_thread && avctx->internal->hwaccel_priv_data !=
                             fctx->prev_thread->avctx->internal->hwaccel_priv_data) {
        if (update_context_from_thread(avctx, fctx->prev_thread->avctx, 1) < 0) {
            av_log(avctx, AV_LOG_ERROR, "Failed to update user thread.\n");
        }
    }

    if (fctx->prev_thread && fctx->prev_thread != fctx->threads)
        if (update_context_from_thread(fctx->threads->avctx, fctx->prev_thread->avctx, 0) < 0) {
            av_log(avctx, AV_LOG_ERROR, "Final thread update failed\n");
            fctx->prev_thread->avctx->internal->is_copy = fctx->threads->avctx->internal->is_copy;
            fctx->threads->avctx->internal->is_copy = 1;
        }

    for (i = 0; i < thread_count; i++) {
        PerThreadContext *p = &fctx->threads[i];

        pthread_mutex_lock(&p->mutex);
        p->die = 1;
        pthread_cond_signal(&p->input_cond);
        pthread_mutex_unlock(&p->mutex);

        if (p->thread_init)
            pthread_join(p->thread, NULL);
        p->thread_init=0;

        if (codec->close && p->avctx)
            codec->close(p->avctx);

        release_delayed_buffers(p);
        av_frame_free(&p->frame);
    }

    for (i = 0; i < thread_count; i++) {
        PerThreadContext *p = &fctx->threads[i];

        pthread_mutex_destroy(&p->mutex);
        pthread_mutex_destroy(&p->progress_mutex);
        pthread_cond_destroy(&p->input_cond);
        pthread_cond_destroy(&p->progress_cond);
        pthread_cond_destroy(&p->output_cond);
        av_packet_unref(&p->avpkt);

        for (j = 0; j < p->released_buffers_allocated; j++)
            av_frame_free(&p->released_buffers[j]);
        av_freep(&p->released_buffers);

        if (p->avctx) {
            if (codec->priv_class)
                av_opt_free(p->avctx->priv_data);
            av_freep(&p->avctx->priv_data);

            av_freep(&p->avctx->slice_offset);
        }

        if (p->avctx) {
            av_buffer_unref(&p->avctx->internal->pool);
            av_freep(&p->avctx->internal);
            av_buffer_unref(&p->avctx->hw_frames_ctx);
        }

        av_freep(&p->avctx);
    }

    av_freep(&fctx->threads);
    pthread_mutex_destroy(&fctx->buffer_mutex);
    pthread_mutex_destroy(&fctx->hwaccel_mutex);
    pthread_mutex_destroy(&fctx->async_mutex);
    pthread_cond_destroy(&fctx->async_cond);

    av_freep(&avctx->internal->thread_ctx);

    if (avctx->priv_data && avctx->codec && avctx->codec->priv_class)
        av_opt_free(avctx->priv_data);
    avctx->codec = NULL;
}
void ff_thread_free(AVCodecContext *avctx)
{
    if (avctx->active_thread_type&FF_THREAD_FRAME)
        ff_frame_thread_free(avctx, avctx->thread_count);
    else
        ff_slice_thread_free(avctx);
}

void ff_thread_flush(AVCodecContext *avctx)
{
    int i;
    FrameThreadContext *fctx = avctx->internal->thread_ctx;

    if (!fctx)
        return;

    park_frame_worker_threads(fctx, avctx->thread_count);
    if (fctx->prev_thread)
    {
        if (fctx->prev_thread != &fctx->threads[0])
            update_context_from_thread(fctx->threads[0].avctx, fctx->prev_thread->avctx, 0);
    }

    fctx->next_decoding = fctx->next_finished = 0;
    fctx->delaying = 1;
    fctx->prev_thread = NULL;
    for (i = 0; i < avctx->thread_count; i++)
    {
        PerThreadContext *p = &fctx->threads[i];
        p->got_frame = 0;
        av_frame_unref(p->frame);
        p->result = 0;

        release_delayed_buffers(p);

        if (avctx->codec->flush)
            avctx->codec->flush(p->avctx);
    }
}
void avpriv_packet_list_free(AVPacketList **pkt_buf, AVPacketList **pkt_buf_end)
{
    AVPacketList *tmp = *pkt_buf;

    while (tmp) {
        AVPacketList *pktl = tmp;
        tmp = pktl->next;
        av_packet_unref(&pktl->pkt);
        av_freep(&pktl);
    }
    *pkt_buf     = NULL;
    *pkt_buf_end = NULL;
}

typedef struct AVCodecHWConfigInternal
{
    AVCodecHWConfig public;
    const AVHWAccel *hwaccel;
} AVCodecHWConfigInternal;

typedef struct ThreadFrame
{
    AVFrame *f;
    AVCodecContext *owner[2];
    AVBufferRef *progress;
} ThreadFrame;
typedef uint64_t BitBuf;

typedef struct PutBitContext
{
    BitBuf bit_buf;
    int bit_left;
    uint8_t *buf, *buf_ptr, *buf_end;
    int size_in_bits;
} PutBitContext;

static const int BUF_BITS = 8 * sizeof(BitBuf);
static inline void init_put_bits(PutBitContext *s, uint8_t *buffer,
                                 int buffer_size)
{
    if (buffer_size < 0) {
        buffer_size = 0;
        buffer      = NULL;
    }

    s->size_in_bits = 8 * buffer_size;
    s->buf          = buffer;
    s->buf_end      = s->buf + buffer_size;
    s->buf_ptr      = s->buf;
    s->bit_left     = BUF_BITS;
    s->bit_buf      = 0;
}

static inline void put_bits_no_assert(PutBitContext *s, int n, BitBuf value)
{
    BitBuf bit_buf;
    int bit_left;

    bit_buf  = s->bit_buf;
    bit_left = s->bit_left;

    /* XXX: optimize */
#ifdef BITSTREAM_WRITER_LE
    bit_buf |= value << (BUF_BITS - bit_left);
    if (n >= bit_left) {
        if (s->buf_end - s->buf_ptr >= sizeof(BitBuf)) {
            AV_WLBUF(s->buf_ptr, bit_buf);
            s->buf_ptr += sizeof(BitBuf);
        } else {
            av_log(NULL, AV_LOG_ERROR, "Internal error, put_bits buffer too small\n");
            av_assert2(0);
        }
        bit_buf     = value >> bit_left;
        bit_left   += BUF_BITS;
    }
    bit_left -= n;
#else
    if (n < bit_left) {
        bit_buf     = (bit_buf << n) | value;
        bit_left   -= n;
    } else {
        bit_buf   <<= bit_left;
        bit_buf    |= value >> (n - bit_left);
        if (s->buf_end - s->buf_ptr >= sizeof(BitBuf)) {
            AV_WBBUF(s->buf_ptr, bit_buf);
            s->buf_ptr += sizeof(BitBuf);
        } else {
            av_log(NULL, AV_LOG_ERROR, "Internal error, put_bits buffer too small\n");
            av_assert2(0);
        }
        bit_left   += BUF_BITS - n;
        bit_buf     = value;
    }
#endif

    s->bit_buf  = bit_buf;
    s->bit_left = bit_left;
}

static inline void put_bits(PutBitContext *s, int n, BitBuf value)
{
    av_assert2(n <= 31 && value < (1UL << n));
    put_bits_no_assert(s, n, value);
}

static inline void put_bits_le(PutBitContext *s, int n, BitBuf value)
{
    BitBuf bit_buf;
    int bit_left;

    av_assert2(n <= 31 && value < (1UL << n));

    bit_buf  = s->bit_buf;
    bit_left = s->bit_left;

    bit_buf |= value << (BUF_BITS - bit_left);
    if (n >= bit_left) {
        if (s->buf_end - s->buf_ptr >= sizeof(BitBuf)) {
            AV_WLBUF(s->buf_ptr, bit_buf);
            s->buf_ptr += sizeof(BitBuf);
        } else {
            av_log(NULL, AV_LOG_ERROR, "Internal error, put_bits buffer too small\n");
            av_assert2(0);
        }
        bit_buf     = value >> bit_left;
        bit_left   += BUF_BITS;
    }
    bit_left -= n;

    s->bit_buf  = bit_buf;
    s->bit_left = bit_left;
}

static inline void put_sbits(PutBitContext *pb, int n, int32_t value)
{
    av_assert2(n >= 0 && n <= 31);

    put_bits(pb, n, av_mod_uintp2(value, n));
}


static void  put_bits32(PutBitContext *s, uint32_t value)
{
    BitBuf bit_buf;
    int bit_left;

    if (BUF_BITS > 32) {
        put_bits_no_assert(s, 32, value);
        return;
    }

    bit_buf  = s->bit_buf;
    bit_left = s->bit_left;

#ifdef BITSTREAM_WRITER_LE
    bit_buf |= (BitBuf)value << (BUF_BITS - bit_left);
    if (s->buf_end - s->buf_ptr >= sizeof(BitBuf)) {
        AV_WLBUF(s->buf_ptr, bit_buf);
        s->buf_ptr += sizeof(BitBuf);
    } else {
        av_log(NULL, AV_LOG_ERROR, "Internal error, put_bits buffer too small\n");
        av_assert2(0);
    }
    bit_buf     = (uint64_t)value >> bit_left;
#else
    bit_buf     = (uint64_t)bit_buf << bit_left;
    bit_buf    |= (BitBuf)value >> (BUF_BITS - bit_left);
    if (s->buf_end - s->buf_ptr >= sizeof(BitBuf)) {
        AV_WBBUF(s->buf_ptr, bit_buf);
        s->buf_ptr += sizeof(BitBuf);
    } else {
        av_log(NULL, AV_LOG_ERROR, "Internal error, put_bits buffer too small\n");
        av_assert2(0);
    }
    bit_buf     = value;
#endif

    s->bit_buf  = bit_buf;
    s->bit_left = bit_left;
}


static inline void put_bits64(PutBitContext *s, int n, uint64_t value)
{
    av_assert2((n == 64) || (n < 64 && value < (UINT64_C(1) << n)));

    if (n < 32)
        put_bits(s, n, value);
    else if (n == 32)
        put_bits32(s, value);
    else if (n < 64) {
        uint32_t lo = value & 0xffffffff;
        uint32_t hi = value >> 32;
#ifdef BITSTREAM_WRITER_LE
        put_bits32(s, lo);
        put_bits(s, n - 32, hi);
#else
        put_bits(s, n - 32, hi);
        put_bits32(s, lo);
#endif
    } else {
        uint32_t lo = value & 0xffffffff;
        uint32_t hi = value >> 32;
#ifdef BITSTREAM_WRITER_LE
        put_bits32(s, lo);
        put_bits32(s, hi);
#else
        put_bits32(s, hi);
        put_bits32(s, lo);
#endif

    }
}


static inline uint8_t *put_bits_ptr(PutBitContext *s)
{
    return s->buf_ptr;
}


static inline void skip_put_bytes(PutBitContext *s, int n)
{
    av_assert2((put_bits_count(s) & 7) == 0);
    av_assert2(s->bit_left == BUF_BITS);
    av_assert0(n <= s->buf_end - s->buf_ptr);
    s->buf_ptr += n;
}


static inline void skip_put_bits(PutBitContext *s, int n)
{
    unsigned bits = BUF_BITS - s->bit_left + n;
    s->buf_ptr += sizeof(BitBuf) * (bits / BUF_BITS);
    s->bit_left = BUF_BITS - (bits & (BUF_BITS - 1));
}


static inline void set_put_bits_buffer_size(PutBitContext *s, int size)
{
    av_assert0(size <= INT_MAX/8 - BUF_BITS);
    s->buf_end = s->buf + size;
    s->size_in_bits = 8*size;
}

static inline void flush_put_bits(PutBitContext *s)
{
#ifndef BITSTREAM_WRITER_LE
    if (s->bit_left < BUF_BITS)
        s->bit_buf <<= s->bit_left;
#endif
    while (s->bit_left < BUF_BITS) {
        av_assert0(s->buf_ptr < s->buf_end);
#ifdef BITSTREAM_WRITER_LE
        *s->buf_ptr++ = s->bit_buf;
        s->bit_buf  >>= 8;
#else
        *s->buf_ptr++ = s->bit_buf >> (BUF_BITS - 8);
        s->bit_buf  <<= 8;
#endif
        s->bit_left  += 8;
    }
    s->bit_left = BUF_BITS;
    s->bit_buf  = 0;
}

// #include "utils.c"


static void *  worker(void *v){
    AVCodecContext *avctx = v;
    ThreadContext *c = avctx->internal->frame_thread_encoder;
    AVPacket *pkt = NULL;

    while (!atomic_load(&c->exit)) {
        int got_packet = 0, ret;
        AVFrame *frame;
        Task task;

        if(!pkt) pkt = av_packet_alloc();
        if(!pkt) continue;
        av_init_packet(pkt);

        pthread_mutex_lock(&c->task_fifo_mutex);
        while (av_fifo_size(c->task_fifo) <= 0 || atomic_load(&c->exit)) {
            if (atomic_load(&c->exit)) {
                pthread_mutex_unlock(&c->task_fifo_mutex);
                goto end;
            }
            pthread_cond_wait(&c->task_fifo_cond, &c->task_fifo_mutex);
        }
        av_fifo_generic_read(c->task_fifo, &task, sizeof(task), NULL);
        pthread_mutex_unlock(&c->task_fifo_mutex);
        frame = task.indata;

        ret = avctx->codec->encode2(avctx, pkt, frame, &got_packet);
        if(got_packet) {
            int ret2 = av_packet_make_refcounted(pkt);
            if (ret >= 0 && ret2 < 0)
                ret = ret2;
            pkt->pts = pkt->dts = frame->pts;
        } else {
            pkt->data = NULL;
            pkt->size = 0;
        }
        pthread_mutex_lock(&c->buffer_mutex);
        av_frame_unref(frame);
        pthread_mutex_unlock(&c->buffer_mutex);
        av_frame_free(&frame);
        pthread_mutex_lock(&c->finished_task_mutex);
        c->finished_tasks[task.index].outdata = pkt; pkt = NULL;
        c->finished_tasks[task.index].return_code = ret;
        pthread_cond_signal(&c->finished_task_cond);
        pthread_mutex_unlock(&c->finished_task_mutex);
    }
end:
    av_free(pkt);
    pthread_mutex_lock(&c->buffer_mutex);
    // avcodec_close(avctx);
    pthread_mutex_unlock(&c->buffer_mutex);
    av_freep(&avctx);
    return NULL;
}


int ff_thread_video_encode_frame(AVCodecContext *avctx, AVPacket *pkt, const AVFrame *frame, int *got_packet_ptr){
    ThreadContext *c = avctx->internal->frame_thread_encoder;
    Task task;
    int ret;

    av_assert1(!*got_packet_ptr);

    if(frame){
        AVFrame *new = av_frame_alloc();
        if(!new)
            return AVERROR(ENOMEM);
        ret = av_frame_ref(new, frame);
        if(ret < 0) {
            av_frame_free(&new);
            return ret;
        }

        task.index = c->task_index;
        task.indata = (void*)new;
        pthread_mutex_lock(&c->task_fifo_mutex);
        av_fifo_generic_write(c->task_fifo, &task, sizeof(task), NULL);
        pthread_cond_signal(&c->task_fifo_cond);
        pthread_mutex_unlock(&c->task_fifo_mutex);

        c->task_index = (c->task_index+1) % BUFFER_SIZE;
    }

    pthread_mutex_lock(&c->finished_task_mutex);
    if (c->task_index == c->finished_task_index ||
        (frame && !c->finished_tasks[c->finished_task_index].outdata &&
         (c->task_index - c->finished_task_index) % BUFFER_SIZE <= avctx->thread_count)) {
            pthread_mutex_unlock(&c->finished_task_mutex);
            return 0;
        }

    while (!c->finished_tasks[c->finished_task_index].outdata) {
        pthread_cond_wait(&c->finished_task_cond, &c->finished_task_mutex);
    }
    task = c->finished_tasks[c->finished_task_index];
    *pkt = *(AVPacket*)(task.outdata);
    if(pkt->data)
        *got_packet_ptr = 1;
    av_freep(&c->finished_tasks[c->finished_task_index].outdata);
    c->finished_task_index = (c->finished_task_index+1) % BUFFER_SIZE;
    pthread_mutex_unlock(&c->finished_task_mutex);

    return task.return_code;
}
extern const uint8_t ff_log2_run[41];


int ff_match_2uint16(const uint16_t (*tab)[2], int size, int a, int b);

unsigned int avpriv_toupper4(unsigned int x);

void ff_color_frame(AVFrame *frame, const int color[4]);


int ff_alloc_packet2(AVCodecContext *avctx, AVPacket *avpkt, int64_t size, int64_t min_size);


static inline int64_t ff_samples_to_time_base(AVCodecContext *avctx, int64_t samples)
{
    if(samples == AV_NOPTS_VALUE)
        return AV_NOPTS_VALUE;
    return av_rescale_q(samples, (AVRational){ 1, avctx->sample_rate },
                        avctx->time_base);
}


static inline float ff_exp2fi(int x) {
    
    if (-126 <= x && x <= 128)
        return av_int2float((x+127) << 23);
    
    else if (x > 128)
        return INFINITY;
    
    else if (x > -150)
        return av_int2float(1 << (x+149));
    
    else
        return 0;
}


av_warn_unused_result
int swri_realloc_audio(SWresampleAudioData *a, int count);

void swri_noise_shaping_int16 (SwrContext *s, SWresampleAudioData *dsts, const SWresampleAudioData *srcs, const SWresampleAudioData *noises, int count);
void swri_noise_shaping_int32 (SwrContext *s, SWresampleAudioData *dsts, const SWresampleAudioData *srcs, const SWresampleAudioData *noises, int count);
void swri_noise_shaping_float (SwrContext *s, SWresampleAudioData *dsts, const SWresampleAudioData *srcs, const SWresampleAudioData *noises, int count);
void swri_noise_shaping_double(SwrContext *s, SWresampleAudioData *dsts, const SWresampleAudioData *srcs, const SWresampleAudioData *noises, int count);

av_warn_unused_result
int swri_rematrix_init(SwrContext *s);
void swri_rematrix_free(SwrContext *s);
int swri_rematrix(SwrContext *s, SWresampleAudioData *out, SWresampleAudioData *in, int len, int mustcopy);
int swri_rematrix_init_x86(struct SwrContext *s);

av_warn_unused_result
int swri_get_dither(SwrContext *s, void *dst, int len, unsigned seed, enum AVSampleFormat noise_fmt);
av_warn_unused_result
int swri_dither_init(SwrContext *s, enum AVSampleFormat out_fmt, enum AVSampleFormat in_fmt);

void swri_audio_convert_init_aarch64(struct AudioConvert *ac,
                                 enum AVSampleFormat out_fmt,
                                 enum AVSampleFormat in_fmt,
                                 int channels);
void swri_audio_convert_init_arm(struct AudioConvert *ac,
                                 enum AVSampleFormat out_fmt,
                                 enum AVSampleFormat in_fmt,
                                 int channels);
void swri_audio_convert_init_x86(struct AudioConvert *ac,
                                 enum AVSampleFormat out_fmt,
                                 enum AVSampleFormat in_fmt,
                                 int channels);

extern const AVOption av_device_capabilities[];

int avdevice_capabilities_create(AVDeviceCapabilitiesQuery **caps, AVFormatContext *s,
                                 AVDictionary **device_options);

void avdevice_capabilities_free(AVDeviceCapabilitiesQuery **caps, AVFormatContext *s);


int avdevice_list_devices(struct AVFormatContext *s, AVDeviceInfoList **device_list);

void avdevice_free_list_devices(AVDeviceInfoList **device_list);

int avdevice_list_input_sources(struct AVInputFormat *device, const char *device_name,
                                AVDictionary *device_options, AVDeviceInfoList **device_list);
int avdevice_list_output_sinks(struct AVOutputFormat *device, const char *device_name,
                               AVDictionary *device_options, AVDeviceInfoList **device_list);
#define LIBSWSCALE_VERSION_MAJOR 5
#define LIBSWSCALE_VERSION_MINOR 8
#define LIBSWSCALE_VERSION_MICRO 100
#define LIBSWSCALE_VERSION_INT AV_VERSION_INT(LIBSWSCALE_VERSION_MAJOR, LIBSWSCALE_VERSION_MINOR, LIBSWSCALE_VERSION_MICRO)
#define LIBSWSCALE_VERSION AV_VERSION(LIBSWSCALE_VERSION_MAJOR, LIBSWSCALE_VERSION_MINOR, LIBSWSCALE_VERSION_MICRO)
#define LIBSWSCALE_BUILD LIBSWSCALE_VERSION_INT
#define LIBSWSCALE_IDENT "SwS" AV_STRINGIFY(LIBSWSCALE_VERSION)
#define FF_API_SWS_VECTOR (LIBSWSCALE_VERSION_MAJOR < 6)

unsigned swscale_version(void);

const char *swscale_configuration(void);

const char *swscale_license(void);
#define SWS_FAST_BILINEAR 1
#define SWS_BILINEAR 2
#define SWS_BICUBIC 4
#define SWS_X 8
#define SWS_POINT 0x10
#define SWS_AREA 0x20
#define SWS_BICUBLIN 0x40
#define SWS_GAUSS 0x80
#define SWS_SINC 0x100
#define SWS_LANCZOS 0x200
#define SWS_SPLINE 0x400
#define SWS_SRC_V_CHR_DROP_MASK 0x30000
#define SWS_SRC_V_CHR_DROP_SHIFT 16
#define SWS_PARAM_DEFAULT 123456
#define SWS_PRINT_INFO 0x1000
#define SWS_FULL_CHR_H_INT 0x2000
#define SWS_FULL_CHR_H_INP 0x4000
#define SWS_DIRECT_BGR 0x8000
#define SWS_ACCURATE_RND 0x40000
#define SWS_BITEXACT 0x80000
#define SWS_ERROR_DIFFUSION 0x800000
#define SWS_MAX_REDUCE_CUTOFF 0.002
#define SWS_CS_ITU709 1
#define SWS_CS_FCC 4
#define SWS_CS_ITU601 5
#define SWS_CS_ITU624 5
#define SWS_CS_SMPTE170M 5
#define SWS_CS_SMPTE240M 7
#define SWS_CS_DEFAULT 5
#define SWS_CS_BT2020 9

const int *sws_getCoefficients(int colorspace);

int sws_isSupportedInput(enum AVPixelFormat pix_fmt);

int sws_isSupportedOutput(enum AVPixelFormat pix_fmt);

int sws_isSupportedEndiannessConversion(enum AVPixelFormat pix_fmt);

struct SwsContext *sws_alloc_context(void);

int sws_init_context(struct SwsContext *sws_context, SwsFilter *srcFilter, SwsFilter *dstFilter);

void sws_freeContext(struct SwsContext *swsContext);

struct SwsContext *sws_getContext(int srcW, int srcH, enum AVPixelFormat srcFormat,
                                  int dstW, int dstH, enum AVPixelFormat dstFormat,
                                  int flags, SwsFilter *srcFilter,
                                  SwsFilter *dstFilter, const double *param);

int sws_scale(struct SwsContext *c, const uint8_t *const srcSlice[],
              const int srcStride[], int srcSliceY, int srcSliceH,
              uint8_t *const dst[], const int dstStride[]);

int sws_setColorspaceDetails(struct SwsContext *c, const int inv_table[4],
                             int srcRange, const int table[4], int dstRange,
                             int brightness, int contrast, int saturation);

int sws_getColorspaceDetails(struct SwsContext *c, int **inv_table,
                             int *srcRange, int **table, int *dstRange,
                             int *brightness, int *contrast, int *saturation);

SwsVector *sws_allocVec(int length);

SwsVector *sws_getGaussianVec(double variance, double quality);

void sws_scaleVec(SwsVector *a, double scalar);

void sws_normalizeVec(SwsVector *a, double height);
SwsVector *sws_getConstVec(double c, int length);
SwsVector *sws_getIdentityVec(void);
void sws_convVec(SwsVector *a, SwsVector *b);
void sws_addVec(SwsVector *a, SwsVector *b);
void sws_subVec(SwsVector *a, SwsVector *b);
void sws_shiftVec(SwsVector *a, int shift);
SwsVector *sws_cloneVec(SwsVector *a);
void sws_printVec2(SwsVector *a, AVClass *log_ctx, int log_level);

void sws_freeVec(SwsVector *a);

SwsFilter *sws_getDefaultFilter(float lumaGBlur, float chromaGBlur,
                                float lumaSharpen, float chromaSharpen,
                                float chromaHShift, float chromaVShift,
                                int verbose);
void sws_freeFilter(SwsFilter *filter);

struct SwsContext *sws_getCachedContext(struct SwsContext *context,
                                        int srcW, int srcH, enum AVPixelFormat srcFormat,
                                        int dstW, int dstH, enum AVPixelFormat dstFormat,
                                        int flags, SwsFilter *srcFilter,
                                        SwsFilter *dstFilter, const double *param);

void sws_convertPalette8ToPacked32(const uint8_t *src, uint8_t *dst, int num_pixels, const uint8_t *palette);

void sws_convertPalette8ToPacked24(const uint8_t *src, uint8_t *dst, int num_pixels, const uint8_t *palette);

const AVClass *sws_get_class(void);



FFTContext *av_fft_init(int nbits, int inverse);

void av_fft_permute(FFTContext *s, FFTComplex *z);

void av_fft_calc(FFTContext *s, FFTComplex *z);

void av_fft_end(FFTContext *s);

FFTContext *av_mdct_init(int nbits, int inverse, double scale);
void av_imdct_calc(FFTContext *s, FFTSample *output, const FFTSample *input);
void av_imdct_half(FFTContext *s, FFTSample *output, const FFTSample *input);
void av_mdct_calc(FFTContext *s, FFTSample *output, const FFTSample *input);
void av_mdct_end(FFTContext *s);

RDFTContext *av_rdft_init(int nbits, enum RDFTransformType trans);
void av_rdft_calc(RDFTContext *s, FFTSample *data);
void av_rdft_end(RDFTContext *s);

DCTContext *av_dct_init(int nbits, enum DCTTransformType type);
void av_dct_calc(DCTContext *s, FFTSample *data);
void av_dct_end(DCTContext *s);
#define LIBSWRESAMPLE_VERSION_MAJOR 3
#define LIBSWRESAMPLE_VERSION_MINOR 8
#define LIBSWRESAMPLE_VERSION_MICRO 100
#define LIBSWRESAMPLE_VERSION_INT AV_VERSION_INT(LIBSWRESAMPLE_VERSION_MAJOR, LIBSWRESAMPLE_VERSION_MINOR, LIBSWRESAMPLE_VERSION_MICRO)
#define LIBSWRESAMPLE_VERSION AV_VERSION(LIBSWRESAMPLE_VERSION_MAJOR, LIBSWRESAMPLE_VERSION_MINOR, LIBSWRESAMPLE_VERSION_MICRO)
#define LIBSWRESAMPLE_BUILD LIBSWRESAMPLE_VERSION_INT
// #define LIBSWRESAMPLE_IDENT "SwR" AV_STRINGIFY(LIBSWRESAMPLE_VERSION)
#define SWR_FLAG_RESAMPLE 1



const AVClass *swr_get_class(void);

struct SwrContext *swr_alloc(void);

int swr_init(struct SwrContext *s);

int swr_is_initialized(struct SwrContext *s);

struct SwrContext *swr_alloc_set_opts(struct SwrContext *s,
                                      int64_t out_ch_layout, enum AVSampleFormat out_sample_fmt, int out_sample_rate,
                                      int64_t in_ch_layout, enum AVSampleFormat in_sample_fmt, int in_sample_rate,
                                      int log_offset, void *log_ctx);

void swr_free(struct SwrContext **s);

void swr_close(struct SwrContext *s);

int swr_convert(struct SwrContext *s, uint8_t **out, int out_count,const uint8_t **in, int in_count);

int64_t swr_next_pts(struct SwrContext *s, int64_t pts);

int swr_set_compensation(struct SwrContext *s, int sample_delta, int compensation_distance);

int swr_set_channel_mapping(struct SwrContext *s, const int *channel_map);

int swr_build_matrix(uint64_t in_layout, uint64_t out_layout,
                     double center_mix_level, double surround_mix_level,
                     double lfe_mix_level, double rematrix_maxval,
                     double rematrix_volume, double *matrix,
                     int stride, enum AVMatrixEncoding matrix_encoding,
                     void *log_ctx);

int swr_set_matrix(struct SwrContext *s, const double *matrix, int stride);

int swr_drop_output(struct SwrContext *s, int count);

int swr_inject_silence(struct SwrContext *s, int count);

int64_t swr_get_delay(struct SwrContext *s, int64_t base);

int swr_get_out_samples(struct SwrContext *s, int in_samples);

unsigned swresample_version(void);

const char *swresample_configuration(void);

const char *swresample_license(void);

int swr_convert_frame(SwrContext *swr,
                      AVFrame *output, const AVFrame *input);

int swr_config_frame(SwrContext *swr, const AVFrame *out, const AVFrame *in);
#define LIBAVFILTER_VERSION_MAJOR 7
#define LIBAVFILTER_VERSION_MINOR 88
#define LIBAVFILTER_VERSION_MICRO 100
#define LIBAVFILTER_VERSION_INT AV_VERSION_INT(LIBAVFILTER_VERSION_MAJOR, LIBAVFILTER_VERSION_MINOR, LIBAVFILTER_VERSION_MICRO)
#define LIBAVFILTER_VERSION AV_VERSION(LIBAVFILTER_VERSION_MAJOR, LIBAVFILTER_VERSION_MINOR, LIBAVFILTER_VERSION_MICRO)
#define LIBAVFILTER_BUILD LIBAVFILTER_VERSION_INT
// #define LIBAVFILTER_IDENT "Lavfi" AV_STRINGIFY(LIBAVFILTER_VERSION)
#define FF_API_OLD_FILTER_OPTS_ERROR (LIBAVFILTER_VERSION_MAJOR < 8)
#define FF_API_LAVR_OPTS (LIBAVFILTER_VERSION_MAJOR < 8)
#define FF_API_FILTER_GET_SET (LIBAVFILTER_VERSION_MAJOR < 8)
#define FF_API_SWS_PARAM_OPTION (LIBAVFILTER_VERSION_MAJOR < 8)

unsigned avfilter_version(void);

const char *avfilter_configuration(void);

const char *avfilter_license(void);



int avfilter_pad_count(const AVFilterPad *pads);

const char *avfilter_pad_get_name(const AVFilterPad *pads, int pad_idx);

enum AVMediaType avfilter_pad_get_type(const AVFilterPad *pads, int pad_idx);
#define AVFILTER_FLAG_DYNAMIC_INPUTS (1 << 0)
#define AVFILTER_FLAG_DYNAMIC_OUTPUTS (1 << 1)
#define AVFILTER_FLAG_SLICE_THREADS (1 << 2)
#define AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC (1 << 16)
#define AVFILTER_FLAG_SUPPORT_TIMELINE_INTERNAL (1 << 17)
#define AVFILTER_FLAG_SUPPORT_TIMELINE (AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC | AVFILTER_FLAG_SUPPORT_TIMELINE_INTERNAL)


#define AVFILTER_THREAD_SLICE (1 << 0)


int avfilter_link(AVFilterContext *src, unsigned srcpad,
                  AVFilterContext *dst, unsigned dstpad);

void avfilter_link_free(AVFilterLink **link);

int avfilter_link_get_channels(AVFilterLink *link);

void avfilter_link_set_closed(AVFilterLink *link, int closed);

int avfilter_config_links(AVFilterContext *filter);
#define AVFILTER_CMD_FLAG_ONE 1
#define AVFILTER_CMD_FLAG_FAST 2

int avfilter_process_command(AVFilterContext *filter, const char *cmd, const char *arg, char *res, int res_len, int flags);

const AVFilter *av_filter_iterate(void **opaque);

void avfilter_register_all(void);

int avfilter_register(AVFilter *filter);

const AVFilter *avfilter_next(const AVFilter *prev);

const AVFilter *avfilter_get_by_name(const char *name);

int avfilter_init_str(AVFilterContext *ctx, const char *args);

int avfilter_init_dict(AVFilterContext *ctx, AVDictionary **options);

void avfilter_free(AVFilterContext *filter);

int avfilter_insert_filter(AVFilterLink *link, AVFilterContext *filt,
                           unsigned filt_srcpad_idx, unsigned filt_dstpad_idx);

const AVClass *avfilter_get_class(void);


AVFilterGraph *avfilter_graph_alloc(void);

AVFilterContext *avfilter_graph_alloc_filter(AVFilterGraph *graph,
                                             const AVFilter *filter,
                                             const char *name);

AVFilterContext *avfilter_graph_get_filter(AVFilterGraph *graph, const char *name);

int avfilter_graph_create_filter(AVFilterContext **filt_ctx, const AVFilter *filt,
                                 const char *name, const char *args, void *opaque,
                                 AVFilterGraph *graph_ctx);

void avfilter_graph_set_auto_convert(AVFilterGraph *graph, unsigned flags);



int avfilter_graph_config(AVFilterGraph *graphctx, void *log_ctx);

void avfilter_graph_free(AVFilterGraph **graph);



AVFilterInOut *avfilter_inout_alloc(void);

void avfilter_inout_free(AVFilterInOut **inout);

int avfilter_graph_parse(AVFilterGraph *graph, const char *filters,
                         AVFilterInOut *inputs, AVFilterInOut *outputs,
                         void *log_ctx);

int avfilter_graph_parse_ptr(AVFilterGraph *graph, const char *filters,
                             AVFilterInOut **inputs, AVFilterInOut **outputs,
                             void *log_ctx);

int avfilter_graph_parse2(AVFilterGraph *graph, const char *filters,
                          AVFilterInOut **inputs,
                          AVFilterInOut **outputs);

int avfilter_graph_send_command(AVFilterGraph *graph, const char *target, const char *cmd, const char *arg, char *res, int res_len, int flags);

int avfilter_graph_queue_command(AVFilterGraph *graph, const char *target, const char *cmd, const char *arg, int flags, double ts);

char *avfilter_graph_dump(AVFilterGraph *graph, const char *options);

int avfilter_graph_request_oldest(AVFilterGraph *graph);
#define AVFILTER_BUFFERSINK_H

int av_buffersink_get_frame_flags(AVFilterContext *ctx, AVFrame *frame, int flags);
#define AV_BUFFERSINK_FLAG_PEEK 1
#define AV_BUFFERSINK_FLAG_NO_REQUEST 2



AVBufferSinkParams *av_buffersink_params_alloc(void);



AVABufferSinkParams *av_abuffersink_params_alloc(void);

void av_buffersink_set_frame_size(AVFilterContext *ctx, unsigned frame_size);

enum AVMediaType av_buffersink_get_type(const AVFilterContext *ctx);
AVRational av_buffersink_get_time_base(const AVFilterContext *ctx);
int av_buffersink_get_format(const AVFilterContext *ctx);

AVRational av_buffersink_get_frame_rate(const AVFilterContext *ctx);
int av_buffersink_get_w(const AVFilterContext *ctx);
int av_buffersink_get_h(const AVFilterContext *ctx);
AVRational av_buffersink_get_sample_aspect_ratio(const AVFilterContext *ctx);

int av_buffersink_get_channels(const AVFilterContext *ctx);
uint64_t av_buffersink_get_channel_layout(const AVFilterContext *ctx);
int av_buffersink_get_sample_rate(const AVFilterContext *ctx);

AVBufferRef *av_buffersink_get_hw_frames_ctx(const AVFilterContext *ctx);
int av_buffersink_get_frame(AVFilterContext *ctx, AVFrame *frame);
int av_buffersink_get_samples(AVFilterContext *ctx, AVFrame *frame, int nb_samples);

enum
{
    AV_BUFFERSRC_FLAG_NO_CHECK_FORMAT = 1,
    AV_BUFFERSRC_FLAG_PUSH = 4,
    AV_BUFFERSRC_FLAG_KEEP_REF = 8,
};
typedef struct AVBufferSrcParameters
{
    int format;
    AVRational time_base;
    int width, height;
    AVRational sample_aspect_ratio;
    AVRational frame_rate;
    AVBufferRef *hw_frames_ctx;
    int sample_rate;
    uint64_t channel_layout;
} AVBufferSrcParameters;

typedef enum
{
    SDL_FALSE = 0,
    SDL_TRUE = 1
} SDL_bool;
typedef enum
{
    DUMMY_ENUM_VALUE
} SDL_DUMMY_ENUM;

typedef enum
{
    SDL_ASSERTION_RETRY,
    SDL_ASSERTION_BREAK,
    SDL_ASSERTION_ABORT,
    SDL_ASSERTION_IGNORE,
    SDL_ASSERTION_ALWAYS_IGNORE
} SDL_AssertState;

typedef struct SDL_AssertData
{
    int always_ignore;
    unsigned int trigger_count;
    const char *condition;
    const char *filename;
    int linenum;
    const char *function;
    const struct SDL_AssertData *next;
} SDL_AssertData;

unsigned av_buffersrc_get_nb_failed_requests(AVFilterContext *buffer_src);



AVBufferSrcParameters *av_buffersrc_parameters_alloc(void);

int av_buffersrc_parameters_set(AVFilterContext *ctx, AVBufferSrcParameters *param);

int av_buffersrc_write_frame(AVFilterContext *ctx, const AVFrame *frame);

int av_buffersrc_add_frame(AVFilterContext *ctx, AVFrame *frame);

int av_buffersrc_add_frame_flags(AVFilterContext *buffer_src,
                                 AVFrame *frame, int flags);

int av_buffersrc_close(AVFilterContext *ctx, int64_t pts, unsigned flags);
extern const char *SDL_GetPlatform(void);




typedef int SDL_compile_time_assert_uint8[(sizeof(Uint8) == 1) * 2 - 1];
typedef int SDL_compile_time_assert_sint8[(sizeof(Sint8) == 1) * 2 - 1];
typedef int SDL_compile_time_assert_uint16[(sizeof(Uint16) == 2) * 2 - 1];
typedef int SDL_compile_time_assert_sint16[(sizeof(Sint16) == 2) * 2 - 1];
typedef int SDL_compile_time_assert_uint32[(sizeof(uint32_t) == 4) * 2 - 1];
typedef int SDL_compile_time_assert_sint32[(sizeof(Sint32) == 4) * 2 - 1];
typedef int SDL_compile_time_assert_uint64[(sizeof(Uint64) == 8) * 2 - 1];
typedef int SDL_compile_time_assert_sint64[(sizeof(Sint64) == 8) * 2 - 1];


typedef int SDL_compile_time_assert_enum[(sizeof(SDL_DUMMY_ENUM) == sizeof(int)) * 2 - 1];
#define SDL_stack_alloc(type, count) (type *)SDL_malloc(sizeof(type) * (count))
#define SDL_stack_free(data) SDL_free(data)

extern void *SDL_malloc(size_t size);
extern void *SDL_calloc(size_t nmemb, size_t size);
extern void *SDL_realloc(void *mem, size_t size);
extern void SDL_free(void *mem);

typedef void *(*SDL_malloc_func)(size_t size);
typedef void *(*SDL_calloc_func)(size_t nmemb, size_t size);
typedef void *(*SDL_realloc_func)(void *mem, size_t size);
typedef void (*SDL_free_func)(void *mem);

extern void SDL_GetMemoryFunctions(SDL_malloc_func *malloc_func,
                                   SDL_calloc_func *calloc_func,
                                   SDL_realloc_func *realloc_func,
                                   SDL_free_func *free_func);

extern int SDL_SetMemoryFunctions(SDL_malloc_func malloc_func,
                                  SDL_calloc_func calloc_func,
                                  SDL_realloc_func realloc_func,
                                  SDL_free_func free_func);

extern int SDL_GetNumAllocations(void);

extern char *SDL_getenv(const char *name);
extern int SDL_setenv(const char *name, const char *value, int overwrite);

extern void SDL_qsort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));

extern int SDL_abs(int x);
#define SDL_min(x, y) (((x) < (y)) ? (x) : (y))
#define SDL_max(x, y) (((x) > (y)) ? (x) : (y))

extern int SDL_isdigit(int x);
extern int SDL_isspace(int x);
extern int SDL_isupper(int x);
extern int SDL_islower(int x);
extern int SDL_toupper(int x);
extern int SDL_tolower(int x);

extern void *SDL_memset(void *dst, int c, size_t len);
#define SDL_zero(x) SDL_memset(&(x), 0, sizeof((x)))
#define SDL_zerop(x) SDL_memset((x), 0, sizeof(*(x)))
#define SDL_zeroa(x) SDL_memset((x), 0, sizeof((x)))
// static inline void SDL_memset4(void *dst, uint32_t val, size_t dwords)
// {
//     size_t _n = (dwords + 3) / 4;
//     uint32_t *_p = ((uint32_t *)(dst));
//     uint32_t _val = (val);
//     if (dwords == 0)
//         return;
//     switch (dwords % 4)
//     {
//     case 0:
//         do
//         {
//             *_p++ = _val;
//         case 3:
//             *_p++ = _val;
//         case 2:
//             *_p++ = _val;
//         case 1:
//             *_p++ = _val;
//         } while (--_n);
//     }
// }

extern void *SDL_memcpy(void *dst, const void *src, size_t len);

extern void *SDL_memmove(void *dst, const void *src, size_t len);
extern int SDL_memcmp(const void *s1, const void *s2, size_t len);

extern size_t SDL_wcslen(const wchar_t *wstr);
extern size_t SDL_wcslcpy(wchar_t *dst, const wchar_t *src, size_t maxlen);
extern size_t SDL_wcslcat(wchar_t *dst, const wchar_t *src, size_t maxlen);
extern wchar_t *SDL_wcsdup(const wchar_t *wstr);
extern wchar_t *SDL_wcsstr(const wchar_t *haystack, const wchar_t *needle);

extern int SDL_wcscmp(const wchar_t *str1, const wchar_t *str2);
extern int SDL_wcsncmp(const wchar_t *str1, const wchar_t *str2, size_t maxlen);

extern size_t SDL_strlen(const char *str);
extern size_t SDL_strlcpy(char *dst, const char *src, size_t maxlen);
extern size_t SDL_utf8strlcpy(char *dst, const char *src, size_t dst_bytes);
extern size_t SDL_strlcat(char *dst, const char *src, size_t maxlen);
extern char *SDL_strdup(const char *str);
extern char *SDL_strrev(char *str);
extern char *SDL_strupr(char *str);
extern char *SDL_strlwr(char *str);
extern char *SDL_strchr(const char *str, int c);
extern char *SDL_strrchr(const char *str, int c);
extern char *SDL_strstr(const char *haystack, const char *needle);
extern char *SDL_strtokr(char *s1, const char *s2, char **saveptr);
extern size_t SDL_utf8strlen(const char *str);

extern char *SDL_itoa(int value, char *str, int radix);
extern char *SDL_uitoa(unsigned int value, char *str, int radix);
extern char *SDL_ltoa(long value, char *str, int radix);
extern char *SDL_ultoa(unsigned long value, char *str, int radix);
extern char *SDL_lltoa(Sint64 value, char *str, int radix);
extern char *SDL_ulltoa(Uint64 value, char *str, int radix);

extern int SDL_atoi(const char *str);
extern double SDL_atof(const char *str);
extern long SDL_strtol(const char *str, char **endp, int base);
extern unsigned long SDL_strtoul(const char *str, char **endp, int base);
extern Sint64 SDL_strtoll(const char *str, char **endp, int base);
extern Uint64 SDL_strtoull(const char *str, char **endp, int base);
extern double SDL_strtod(const char *str, char **endp);

extern int SDL_strcmp(const char *str1, const char *str2);
extern int SDL_strncmp(const char *str1, const char *str2, size_t maxlen);
extern int SDL_strcasecmp(const char *str1, const char *str2);
extern int SDL_strncasecmp(const char *str1, const char *str2, size_t len);

extern int SDL_sscanf(const char *text, const char *fmt, ...);
extern int SDL_vsscanf(const char *text, const char *fmt, va_list ap);
extern int SDL_snprintf(char *text, size_t maxlen, const char *fmt, ...);
extern int SDL_vsnprintf(char *text, size_t maxlen, const char *fmt, va_list ap);

extern double SDL_acos(double x);
extern float SDL_acosf(float x);
extern double SDL_asin(double x);
extern float SDL_asinf(float x);
extern double SDL_atan(double x);
extern float SDL_atanf(float x);
extern double SDL_atan2(double x, double y);
extern float SDL_atan2f(float x, float y);
extern double SDL_ceil(double x);
extern float SDL_ceilf(float x);
extern double SDL_copysign(double x, double y);
extern float SDL_copysignf(float x, float y);
extern double SDL_cos(double x);
extern float SDL_cosf(float x);
extern double SDL_exp(double x);
extern float SDL_expf(float x);
extern double SDL_fabs(double x);
extern float SDL_fabsf(float x);
extern double SDL_floor(double x);
extern float SDL_floorf(float x);
extern double SDL_fmod(double x, double y);
extern float SDL_fmodf(float x, float y);
extern double SDL_log(double x);
extern float SDL_logf(float x);
extern double SDL_log10(double x);
extern float SDL_log10f(float x);
extern double SDL_pow(double x, double y);
extern float SDL_powf(float x, float y);
extern double SDL_scalbn(double x, int n);
extern float SDL_scalbnf(float x, int n);
extern double SDL_sin(double x);
extern float SDL_sinf(float x);
extern double SDL_sqrt(double x);
extern float SDL_sqrtf(float x);
extern double SDL_tan(double x);
extern float SDL_tanf(float x);
#define SDL_ICONV_ERROR (size_t) - 1
#define SDL_ICONV_E2BIG (size_t) - 2
#define SDL_ICONV_EILSEQ (size_t) - 3
#define SDL_ICONV_EINVAL (size_t) - 4
typedef struct _SDL_iconv_t *SDL_iconv_t;
extern SDL_iconv_t SDL_iconv_open(const char *tocode,
                                  const char *fromcode);
extern int SDL_iconv_close(SDL_iconv_t cd);
extern size_t SDL_iconv(SDL_iconv_t cd, const char **inbuf,
                        size_t *inbytesleft, char **outbuf,
                        size_t *outbytesleft);

extern char *SDL_iconv_string(const char *tocode,
                              const char *fromcode,
                              const char *inbuf,
                              size_t inbytesleft);
#define SDL_iconv_utf8_locale(S) SDL_iconv_string("", "UTF-8", S, SDL_strlen(S) + 1)
#define SDL_iconv_utf8_ucs2(S) (Uint16 *)SDL_iconv_string("UCS-2-INTERNAL", "UTF-8", S, SDL_strlen(S) + 1)
#define SDL_iconv_utf8_ucs4(S) (uint32_t *)SDL_iconv_string("UCS-4-INTERNAL", "UTF-8", S, SDL_strlen(S) + 1)

static inline void *SDL_memcpy4(void *dst, const void *src, size_t dwords)
{
    return SDL_memcpy(dst, src, dwords * 4);
}
#define SDL_MAIN_AVAILABLE
#define SDLMAIN_DECLSPEC

typedef int (*SDL_main_func)(int argc, char *argv[]);
extern int SDL_main(int argc, char *argv[]);

extern void SDL_SetMainReady(void);

extern int SDL_RegisterApp(char *name, uint32_t style, void *hInst);
extern void SDL_UnregisterApp(void);
#define SDL_assert_h_
#define SDL_ASSERT_LEVEL 2
// #define SDL_TriggerBreakpoint() __asm__ __volatile__("int $3\n\t")
#define SDL_FUNCTION __func__
#define SDL_FILE __FILE__
#define SDL_LINE __LINE__
#define SDL_NULL_WHILE_LOOP_CONDITION (0)
#define SDL_disabled_assert(condition) \
    do                                 \
    {                                  \
        (void)sizeof((condition));     \
    } while (SDL_NULL_WHILE_LOOP_CONDITION)



extern SDL_AssertState SDL_ReportAssertion(SDL_AssertData *,
                                           const char *,
                                           const char *, int);
// #define SDL_enabled_assert(condition)                                                                                         \
//     do                                                                                                                        \
//     {                                                                                                                         \
//         while (!(condition))                                                                                                  \
//         {                                                                                                                     \
//             static struct SDL_AssertData sdl_assert_data = {0, 0, #condition, 0, 0, 0, 0};                                    \
//             const SDL_AssertState sdl_assert_state = SDL_ReportAssertion(&sdl_assert_data, SDL_FUNCTION, SDL_FILE, SDL_LINE); \
//             if (sdl_assert_state == SDL_ASSERTION_RETRY)                                                                      \
//             {                                                                                                                 \
//                 continue;                                                                                                     \
//             }                                                                                                                 \
//             else if (sdl_assert_state == SDL_ASSERTION_BREAK)                                                                 \
//             {                                                                                                                 \
//                 SDL_TriggerBreakpoint();                                                                                      \
//             }                                                                                                                 \
//             break;                                                                                                            \
//         }                                                                                                                     \
//     } while (SDL_NULL_WHILE_LOOP_CONDITION)
#define SDL_assert(condition) SDL_enabled_assert(condition)
#define SDL_assert_release(condition) SDL_enabled_assert(condition)
#define SDL_assert_paranoid(condition) SDL_disabled_assert(condition)
#define SDL_assert_always(condition) SDL_enabled_assert(condition)

typedef SDL_AssertState (*SDL_AssertionHandler)(
    const SDL_AssertData *data, void *userdata);

extern void SDL_SetAssertionHandler(
    SDL_AssertionHandler handler,
    void *userdata);

extern SDL_AssertionHandler SDL_GetDefaultAssertionHandler(void);
extern SDL_AssertionHandler SDL_GetAssertionHandler(void **puserdata);
extern const SDL_AssertData *SDL_GetAssertionReport(void);

extern void SDL_ResetAssertionReport(void);
#define SDL_assert_state SDL_AssertState
#define SDL_assert_data SDL_AssertData

typedef int SDL_SpinLock;

extern SDL_bool SDL_AtomicTryLock(SDL_SpinLock *lock);

extern void SDL_AtomicLock(SDL_SpinLock *lock);

extern void SDL_AtomicUnlock(SDL_SpinLock *lock);
// #define SDL_CompilerBarrier() __asm__ __volatile__("" \
//                                                    :  \
//                                                    :  \
//                                                    : "memory")
extern void SDL_MemoryBarrierReleaseFunction(void);
extern void SDL_MemoryBarrierAcquireFunction(void);
#define SDL_MemoryBarrierRelease() SDL_CompilerBarrier()
#define SDL_MemoryBarrierAcquire() SDL_CompilerBarrier()

typedef struct
{
    int value;
} SDL_atomic_t;

extern SDL_bool SDL_AtomicCAS(SDL_atomic_t *a, int oldval, int newval);

extern int SDL_AtomicSet(SDL_atomic_t *a, int v);

extern int SDL_AtomicGet(SDL_atomic_t *a);

extern int SDL_AtomicAdd(SDL_atomic_t *a, int v);
#define SDL_AtomicIncRef(a) SDL_AtomicAdd(a, 1)
#define SDL_AtomicDecRef(a) (SDL_AtomicAdd(a, -1) == 1)

extern SDL_bool SDL_AtomicCASPtr(void **a, void *oldval, void *newval);

extern void *SDL_AtomicSetPtr(void **a, void *v);

extern void *SDL_AtomicGetPtr(void **a);

extern int SDL_SetError(const char *fmt, ...);
extern const char *SDL_GetError(void);
extern void SDL_ClearError(void);
#define SDL_OutOfMemory() SDL_Error(SDL_ENOMEM)
#define SDL_Unsupported() SDL_Error(SDL_UNSUPPORTED)
#define SDL_InvalidParamError(param) SDL_SetError("Parameter '%s' is invalid", (param))
typedef enum
{
    SDL_ENOMEM,
    SDL_EFREAD,
    SDL_EFWRITE,
    SDL_EFSEEK,
    SDL_UNSUPPORTED,
    SDL_LASTERROR
} SDL_errorcode;

extern int SDL_Error(SDL_errorcode code);
#define SDL_endian_h_
#define SDL_LIL_ENDIAN 1234
#define SDL_BIG_ENDIAN 4321
#define SDL_BYTEORDER SDL_LIL_ENDIAN
// static inline Uint16
// SDL_Swap16(Uint16 x)
// {
//     __asm__("xchgb %b0,%h0"
//             : "=Q"(x)
//             : "0"(x));
//     return x;
// }
// static inline uint32_t
// SDL_Swap32(uint32_t x)
// {
//     __asm__("bswapl %0"
//             : "=r"(x)
//             : "0"(x));
//     return x;
// }
// static inline Uint64
// SDL_Swap64(Uint64 x)
// {
//     __asm__("bswapq %0"
//             : "=r"(x)
//             : "0"(x));
//     return x;
// }
// static inline float
// SDL_SwapFloat(float x)
// {
//     union
//     {
//         float f;
//         uint32_t ui32;
//     } swapper;
//     swapper.f = x;
//     swapper.ui32 = SDL_Swap32(swapper.ui32);
//     return swapper.f;
// }
#define SDL_SwapLE16(X) (X)
#define SDL_SwapLE32(X) (X)
#define SDL_SwapLE64(X) (X)
#define SDL_SwapFloatLE(X) (X)
#define SDL_SwapBE16(X) SDL_Swap16(X)
#define SDL_SwapBE32(X) SDL_Swap32(X)
#define SDL_SwapBE64(X) SDL_Swap64(X)
#define SDL_SwapFloatBE(X) SDL_SwapFloat(X)
#define SDL_mutex_h_
#define SDL_MUTEX_TIMEDOUT 1
#define SDL_MUTEX_MAXWAIT (~(uint32_t)0)



extern SDL_mutex *SDL_CreateMutex(void);
#define SDL_mutexP(m) SDL_LockMutex(m)
extern int SDL_LockMutex(SDL_mutex *mutex);

extern int SDL_TryLockMutex(SDL_mutex *mutex);
#define SDL_mutexV(m) SDL_UnlockMutex(m)
extern int SDL_UnlockMutex(SDL_mutex *mutex);

extern void SDL_DestroyMutex(SDL_mutex *mutex);

extern SDL_sem *SDL_CreateSemaphore(uint32_t initial_value);

extern void SDL_DestroySemaphore(SDL_sem *sem);

extern int SDL_SemWait(SDL_sem *sem);

extern int SDL_SemTryWait(SDL_sem *sem);
extern int SDL_SemWaitTimeout(SDL_sem *sem, uint32_t ms);
extern int SDL_SemPost(SDL_sem *sem);
extern uint32_t SDL_SemValue(SDL_sem *sem);
extern SDL_cond *SDL_CreateCond(void);
extern void SDL_DestroyCond(SDL_cond *cond);
extern int SDL_CondSignal(SDL_cond *cond);
extern int SDL_CondBroadcast(SDL_cond *cond);
extern int SDL_CondWait(SDL_cond *cond, SDL_mutex *mutex);
extern int SDL_CondWaitTimeout(SDL_cond *cond,
                               SDL_mutex *mutex, uint32_t ms);


typedef int (*SDL_ThreadFunction)(void *data);
#define SDL_PASSED_BEGINTHREAD_ENDTHREAD

typedef uintptr_t (*pfnSDL_CurrentBeginThread)(void *, unsigned, unsigned (*func)(void *),
                                               void *, unsigned, unsigned *);
typedef void (*pfnSDL_CurrentEndThread)(unsigned code);
#define SDL_beginthread _beginthreadex
#define SDL_endthread _endthreadex

extern SDL_Thread *
SDL_CreateThread(SDL_ThreadFunction fn, const char *name, void *data,
                 pfnSDL_CurrentBeginThread pfnBeginThread,
                 pfnSDL_CurrentEndThread pfnEndThread);

extern SDL_Thread *
SDL_CreateThreadWithStackSize(int (*fn)(void *),
                              const char *name, const size_t stacksize, void *data,
                              pfnSDL_CurrentBeginThread pfnBeginThread,
                              pfnSDL_CurrentEndThread pfnEndThread);
#define SDL_CreateThread(fn, name, data) SDL_CreateThread(fn, name, data, (pfnSDL_CurrentBeginThread)SDL_beginthread, (pfnSDL_CurrentEndThread)SDL_endthread)
#define SDL_CreateThreadWithStackSize(fn, name, stacksize, data) SDL_CreateThreadWithStackSize(fn, name, data, (pfnSDL_CurrentBeginThread)_beginthreadex, (pfnSDL_CurrentEndThread)SDL_endthread)

extern const char *SDL_GetThreadName(SDL_Thread *thread);

extern SDL_threadID SDL_ThreadID(void);

extern SDL_threadID SDL_GetThreadID(SDL_Thread *thread);

extern int SDL_SetThreadPriority(SDL_ThreadPriority priority);

extern void SDL_WaitThread(SDL_Thread *thread, int *status);

extern void SDL_DetachThread(SDL_Thread *thread);

extern SDL_TLSID SDL_TLSCreate(void);

extern void *SDL_TLSGet(SDL_TLSID id);

extern int SDL_TLSSet(SDL_TLSID id, const void *value, void (*destructor)(void *));
#define SDL_rwops_h_
#define SDL_RWOPS_UNKNOWN 0U
#define SDL_RWOPS_WINFILE 1U
#define SDL_RWOPS_STDFILE 2U
#define SDL_RWOPS_JNIFILE 3U
#define SDL_RWOPS_MEMORY 4U
#define SDL_RWOPS_MEMORY_RO 5U

typedef struct SDL_RWops
{
    Sint64 (*size)(struct SDL_RWops *context);
    Sint64 (*seek)(struct SDL_RWops *context, Sint64 offset,
                   int whence);
    size_t (*read)(struct SDL_RWops *context, void *ptr,
                   size_t size, size_t maxnum);
    size_t (*write)(struct SDL_RWops *context, const void *ptr,
                    size_t size, size_t num);
    int (*close)(struct SDL_RWops *context);
    uint32_t type;
    union
    {
        struct
        {
            SDL_bool append;
            void *h;
            struct
            {
                void *data;
                size_t size;
                size_t left;
            } buffer;
        } windowsio;
        struct
        {
            Uint8 *base;
            Uint8 *here;
            Uint8 *stop;
        } mem;
        struct
        {
            void *data1;
            void *data2;
        } unknown;
    } hidden;
} SDL_RWops;

extern SDL_RWops *SDL_RWFromFile(const char *file,
                                 const char *mode);

extern SDL_RWops *SDL_RWFromFP(void *fp,
                               SDL_bool autoclose);

extern SDL_RWops *SDL_RWFromMem(void *mem, int size);
extern SDL_RWops *SDL_RWFromConstMem(const void *mem,
                                     int size);

extern SDL_RWops *SDL_AllocRW(void);
extern void SDL_FreeRW(SDL_RWops *area);
#define RW_SEEK_SET 0
#define RW_SEEK_CUR 1
#define RW_SEEK_END 2

extern Sint64 SDL_RWsize(SDL_RWops *context);

extern Sint64 SDL_RWseek(SDL_RWops *context,
                         Sint64 offset, int whence);

extern Sint64 SDL_RWtell(SDL_RWops *context);

extern size_t SDL_RWread(SDL_RWops *context,
                         void *ptr, size_t size, size_t maxnum);

extern size_t SDL_RWwrite(SDL_RWops *context,
                          const void *ptr, size_t size, size_t num);

extern int SDL_RWclose(SDL_RWops *context);
extern void *SDL_LoadFile_RW(SDL_RWops *src, size_t *datasize,
                             int freesrc);
extern void *SDL_LoadFile(const char *file, size_t *datasize);

extern Uint8 SDL_ReadU8(SDL_RWops *src);
extern Uint16 SDL_ReadLE16(SDL_RWops *src);
extern Uint16 SDL_ReadBE16(SDL_RWops *src);
extern uint32_t SDL_ReadLE32(SDL_RWops *src);
extern uint32_t SDL_ReadBE32(SDL_RWops *src);
extern Uint64 SDL_ReadLE64(SDL_RWops *src);
extern Uint64 SDL_ReadBE64(SDL_RWops *src);

extern size_t SDL_WriteU8(SDL_RWops *dst, Uint8 value);
extern size_t SDL_WriteLE16(SDL_RWops *dst, Uint16 value);
extern size_t SDL_WriteBE16(SDL_RWops *dst, Uint16 value);
extern size_t SDL_WriteLE32(SDL_RWops *dst, uint32_t value);
extern size_t SDL_WriteBE32(SDL_RWops *dst, uint32_t value);
extern size_t SDL_WriteLE64(SDL_RWops *dst, Uint64 value);
extern size_t SDL_WriteBE64(SDL_RWops *dst, Uint64 value);

typedef Uint16 SDL_AudioFormat;
#define SDL_AUDIO_MASK_BITSIZE (0xFF)
#define SDL_AUDIO_MASK_DATATYPE (1 << 8)
#define SDL_AUDIO_MASK_ENDIAN (1 << 12)
#define SDL_AUDIO_MASK_SIGNED (1 << 15)
#define SDL_AUDIO_BITSIZE(x) (x & SDL_AUDIO_MASK_BITSIZE)
#define SDL_AUDIO_ISFLOAT(x) (x & SDL_AUDIO_MASK_DATATYPE)
#define SDL_AUDIO_ISBIGENDIAN(x) (x & SDL_AUDIO_MASK_ENDIAN)
#define SDL_AUDIO_ISSIGNED(x) (x & SDL_AUDIO_MASK_SIGNED)
#define SDL_AUDIO_ISINT(x) (!SDL_AUDIO_ISFLOAT(x))
#define SDL_AUDIO_ISLITTLEENDIAN(x) (!SDL_AUDIO_ISBIGENDIAN(x))
#define SDL_AUDIO_ISUNSIGNED(x) (!SDL_AUDIO_ISSIGNED(x))
#define AUDIO_U8 0x0008
#define AUDIO_S8 0x8008
#define AUDIO_U16LSB 0x0010
#define AUDIO_S16LSB 0x8010
#define AUDIO_U16MSB 0x1010
#define AUDIO_S16MSB 0x9010
#define AUDIO_U16 AUDIO_U16LSB
#define AUDIO_S16 AUDIO_S16LSB
#define AUDIO_S32LSB 0x8020
#define AUDIO_S32MSB 0x9020
#define AUDIO_S32 AUDIO_S32LSB
#define AUDIO_F32LSB 0x8120
#define AUDIO_F32MSB 0x9120
#define AUDIO_F32 AUDIO_F32LSB
#define AUDIO_U16SYS AUDIO_U16LSB
#define AUDIO_S16SYS AUDIO_S16LSB
#define AUDIO_S32SYS AUDIO_S32LSB
#define AUDIO_F32SYS AUDIO_F32LSB
#define SDL_AUDIO_ALLOW_FREQUENCY_CHANGE 0x00000001
#define SDL_AUDIO_ALLOW_FORMAT_CHANGE 0x00000002
#define SDL_AUDIO_ALLOW_CHANNELS_CHANGE 0x00000004
#define SDL_AUDIO_ALLOW_SAMPLES_CHANGE 0x00000008
#define SDL_AUDIO_ALLOW_ANY_CHANGE (SDL_AUDIO_ALLOW_FREQUENCY_CHANGE | SDL_AUDIO_ALLOW_FORMAT_CHANGE | SDL_AUDIO_ALLOW_CHANNELS_CHANGE | SDL_AUDIO_ALLOW_SAMPLES_CHANGE)
typedef void (*SDL_AudioCallback)(void *userdata, Uint8 *stream,
                                  int len);
typedef struct SDL_AudioSpec
{
    int freq;
    SDL_AudioFormat format;
    Uint8 channels;
    Uint8 silence;
    Uint16 samples;
    Uint16 padding;
    uint32_t size;
    SDL_AudioCallback callback;
    void *userdata;
} SDL_AudioSpec;

struct SDL_AudioCVT;
typedef void (*SDL_AudioFilter)(struct SDL_AudioCVT *cvt,
                                SDL_AudioFormat format);
#define SDL_AUDIOCVT_MAX_FILTERS 9
#define SDL_AUDIOCVT_PACKED __attribute__((packed))

typedef struct SDL_AudioCVT
{
    int needed;
    SDL_AudioFormat src_format;
    SDL_AudioFormat dst_format;
    double rate_incr;
    Uint8 *buf;
    int len;
    int len_cvt;
    int len_mult;
    double len_ratio;
    SDL_AudioFilter filters[9 + 1];
    int filter_index;
} SDL_AudioCVT;

extern int SDL_GetNumAudioDrivers(void);
extern const char *SDL_GetAudioDriver(int index);

extern int SDL_AudioInit(const char *driver_name);
extern void SDL_AudioQuit(void);

extern const char *SDL_GetCurrentAudioDriver(void);
extern int SDL_OpenAudio(SDL_AudioSpec *desired,
                         SDL_AudioSpec *obtained);

typedef uint32_t SDL_AudioDeviceID;
extern int SDL_GetNumAudioDevices(int iscapture);
extern const char *SDL_GetAudioDeviceName(int index,
                                          int iscapture);
extern SDL_AudioDeviceID SDL_OpenAudioDevice(const char
                                                 *device,
                                             int iscapture,
                                             const SDL_AudioSpec *
                                                 desired,
                                             SDL_AudioSpec *
                                                 obtained,
                                             int
                                                 allowed_changes);

typedef enum
{
    SDL_AUDIO_STOPPED = 0,
    SDL_AUDIO_PLAYING,
    SDL_AUDIO_PAUSED
} SDL_AudioStatus;
extern SDL_AudioStatus SDL_GetAudioStatus(void);

extern SDL_AudioStatus
SDL_GetAudioDeviceStatus(SDL_AudioDeviceID dev);

extern void SDL_PauseAudio(int pause_on);
extern void SDL_PauseAudioDevice(SDL_AudioDeviceID dev,
                                 int pause_on);
extern SDL_AudioSpec *SDL_LoadWAV_RW(SDL_RWops *src,
                                     int freesrc,
                                     SDL_AudioSpec *spec,
                                     Uint8 **audio_buf,
                                     uint32_t *audio_len);
#define SDL_LoadWAV(file, spec, audio_buf, audio_len) SDL_LoadWAV_RW(SDL_RWFromFile(file, "rb"), 1, spec, audio_buf, audio_len)

extern void SDL_FreeWAV(Uint8 *audio_buf);

extern int SDL_BuildAudioCVT(SDL_AudioCVT *cvt,
                             SDL_AudioFormat src_format,
                             Uint8 src_channels,
                             int src_rate,
                             SDL_AudioFormat dst_format,
                             Uint8 dst_channels,
                             int dst_rate);
extern int SDL_ConvertAudio(SDL_AudioCVT *cvt);

struct _SDL_AudioStream;
typedef struct _SDL_AudioStream SDL_AudioStream;
extern SDL_AudioStream *SDL_NewAudioStream(const SDL_AudioFormat src_format,
                                           const Uint8 src_channels,
                                           const int src_rate,
                                           const SDL_AudioFormat dst_format,
                                           const Uint8 dst_channels,
                                           const int dst_rate);
extern int SDL_AudioStreamPut(SDL_AudioStream *stream, const void *buf, int len);
extern int SDL_AudioStreamGet(SDL_AudioStream *stream, void *buf, int len);
extern int SDL_AudioStreamAvailable(SDL_AudioStream *stream);
extern int SDL_AudioStreamFlush(SDL_AudioStream *stream);

extern void SDL_AudioStreamClear(SDL_AudioStream *stream);

extern void SDL_FreeAudioStream(SDL_AudioStream *stream);
#define SDL_MIX_MAXVOLUME 128

extern void SDL_MixAudio(Uint8 *dst, const Uint8 *src,
                         uint32_t len, int volume);

extern void SDL_MixAudioFormat(Uint8 *dst,
                               const Uint8 *src,
                               SDL_AudioFormat format,
                               uint32_t len, int volume);
extern int SDL_QueueAudio(SDL_AudioDeviceID dev, const void *data, uint32_t len);
extern uint32_t SDL_DequeueAudio(SDL_AudioDeviceID dev, void *data, uint32_t len);
extern uint32_t SDL_GetQueuedAudioSize(SDL_AudioDeviceID dev);
extern void SDL_ClearQueuedAudio(SDL_AudioDeviceID dev);

extern void SDL_LockAudio(void);
extern void SDL_LockAudioDevice(SDL_AudioDeviceID dev);
extern void SDL_UnlockAudio(void);
extern void SDL_UnlockAudioDevice(SDL_AudioDeviceID dev);

extern void SDL_CloseAudio(void);
extern void SDL_CloseAudioDevice(SDL_AudioDeviceID dev);

extern int SDL_SetClipboardText(const char *text);

extern char *SDL_GetClipboardText(void);

extern SDL_bool SDL_HasClipboardText(void);
#define SDL_CACHELINE_SIZE 128

extern int SDL_GetCPUCount(void);

extern int SDL_GetCPUCacheLineSize(void);

extern SDL_bool SDL_HasRDTSC(void);

extern SDL_bool SDL_HasAltiVec(void);

extern SDL_bool SDL_HasMMX(void);

extern SDL_bool SDL_Has3DNow(void);

extern SDL_bool SDL_HasSSE(void);

extern SDL_bool SDL_HasSSE2(void);

extern SDL_bool SDL_HasSSE3(void);

extern SDL_bool SDL_HasSSE41(void);

extern SDL_bool SDL_HasSSE42(void);

extern SDL_bool SDL_HasAVX(void);

extern SDL_bool SDL_HasAVX2(void);

extern SDL_bool SDL_HasAVX512F(void);

extern SDL_bool SDL_HasARMSIMD(void);

extern SDL_bool SDL_HasNEON(void);

extern int SDL_GetSystemRAM(void);
extern size_t SDL_SIMDGetAlignment(void);
extern void *SDL_SIMDAlloc(const size_t len);

extern void SDL_SIMDFree(void *ptr);
#define SDL_ALPHA_OPAQUE 255
#define SDL_ALPHA_TRANSPARENT 0


#define SDL_DEFINE_PIXELFOURCC(A, B, C, D) SDL_FOURCC(A, B, C, D)
#define SDL_DEFINE_PIXELFORMAT(type, order, layout, bits, bytes) ((1 << 28) | ((type) << 24) | ((order) << 20) | ((layout) << 16) | ((bits) << 8) | ((bytes) << 0))
#define SDL_PIXELFLAG(X) (((X) >> 28) & 0x0F)
#define SDL_PIXELTYPE(X) (((X) >> 24) & 0x0F)
#define SDL_PIXELORDER(X) (((X) >> 20) & 0x0F)
#define SDL_PIXELLAYOUT(X) (((X) >> 16) & 0x0F)
#define SDL_BITSPERPIXEL(X) (((X) >> 8) & 0xFF)
#define SDL_BYTESPERPIXEL(X) (SDL_ISPIXELFORMAT_FOURCC(X) ? ((((X) == SDL_PIXELFORMAT_YUY2) || ((X) == SDL_PIXELFORMAT_UYVY) || ((X) == SDL_PIXELFORMAT_YVYU)) ? 2 : 1) : (((X) >> 0) & 0xFF))
#define SDL_ISPIXELFORMAT_INDEXED(format) (!SDL_ISPIXELFORMAT_FOURCC(format) && ((SDL_PIXELTYPE(format) == SDL_PIXELTYPE_INDEX1) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_INDEX4) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_INDEX8)))
#define SDL_ISPIXELFORMAT_PACKED(format) (!SDL_ISPIXELFORMAT_FOURCC(format) && ((SDL_PIXELTYPE(format) == SDL_PIXELTYPE_PACKED8) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_PACKED16) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_PACKED32)))
#define SDL_ISPIXELFORMAT_ARRAY(format) (!SDL_ISPIXELFORMAT_FOURCC(format) && ((SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYU8) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYU16) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYU32) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYF16) || (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYF32)))
#define SDL_ISPIXELFORMAT_ALPHA(format) ((SDL_ISPIXELFORMAT_PACKED(format) && ((SDL_PIXELORDER(format) == SDL_PACKEDORDER_ARGB) || (SDL_PIXELORDER(format) == SDL_PACKEDORDER_RGBA) || (SDL_PIXELORDER(format) == SDL_PACKEDORDER_ABGR) || (SDL_PIXELORDER(format) == SDL_PACKEDORDER_BGRA))) || (SDL_ISPIXELFORMAT_ARRAY(format) && ((SDL_PIXELORDER(format) == SDL_ARRAYORDER_ARGB) || (SDL_PIXELORDER(format) == SDL_ARRAYORDER_RGBA) || (SDL_PIXELORDER(format) == SDL_ARRAYORDER_ABGR) || (SDL_PIXELORDER(format) == SDL_ARRAYORDER_BGRA))))
#define SDL_ISPIXELFORMAT_FOURCC(format) ((format) && (SDL_PIXELFLAG(format) != 1))



extern const char *SDL_GetPixelFormatName(uint32_t format);

extern SDL_bool SDL_PixelFormatEnumToMasks(uint32_t format,
                                           int *bpp,
                                           uint32_t *Rmask,
                                           uint32_t *Gmask,
                                           uint32_t *Bmask,
                                           uint32_t *Amask);

extern uint32_t SDL_MasksToPixelFormatEnum(int bpp,
                                         uint32_t Rmask,
                                         uint32_t Gmask,
                                         uint32_t Bmask,
                                         uint32_t Amask);

extern SDL_PixelFormat *SDL_AllocFormat(uint32_t pixel_format);

extern void SDL_FreeFormat(SDL_PixelFormat *format);

extern SDL_Palette *SDL_AllocPalette(int ncolors);

extern int SDL_SetPixelFormatPalette(SDL_PixelFormat *format,
                                     SDL_Palette *palette);

extern int SDL_SetPaletteColors(SDL_Palette *palette,
                                const SDL_Color *colors,
                                int firstcolor, int ncolors);

extern void SDL_FreePalette(SDL_Palette *palette);

extern uint32_t SDL_MapRGB(const SDL_PixelFormat *format,
                         Uint8 r, Uint8 g, Uint8 b);

extern uint32_t SDL_MapRGBA(const SDL_PixelFormat *format,
                          Uint8 r, Uint8 g, Uint8 b,
                          Uint8 a);

extern void SDL_GetRGB(uint32_t pixel,
                       const SDL_PixelFormat *format,
                       Uint8 *r, Uint8 *g, Uint8 *b);

extern void SDL_GetRGBA(uint32_t pixel,
                        const SDL_PixelFormat *format,
                        Uint8 *r, Uint8 *g, Uint8 *b,
                        Uint8 *a);

extern void SDL_CalculateGammaRamp(float gamma, Uint16 *ramp);

typedef struct SDL_Point
{
    int x;
    int y;
} SDL_Point;

typedef struct SDL_FPoint
{
    float x;
    float y;
} SDL_FPoint;

typedef struct SDL_Rect
{
    int x, y;
    int w, h;
} SDL_Rect;

typedef struct SDL_FRect
{
    float x;
    float y;
    float w;
    float h;
} SDL_FRect;

static inline SDL_bool SDL_PointInRect(const SDL_Point *p, const SDL_Rect *r)
{
    return ((p->x >= r->x) && (p->x < (r->x + r->w)) &&
            (p->y >= r->y) && (p->y < (r->y + r->h)))
               ? SDL_TRUE
               : SDL_FALSE;
}

static inline SDL_bool SDL_RectEmpty(const SDL_Rect *r)
{
    return ((!r) || (r->w <= 0) || (r->h <= 0)) ? SDL_TRUE : SDL_FALSE;
}

static inline SDL_bool SDL_RectEquals(const SDL_Rect *a, const SDL_Rect *b)
{
    return (a && b && (a->x == b->x) && (a->y == b->y) &&
            (a->w == b->w) && (a->h == b->h))
               ? SDL_TRUE
               : SDL_FALSE;
}

extern SDL_bool SDL_HasIntersection(const SDL_Rect *A,
                                    const SDL_Rect *B);

extern SDL_bool SDL_IntersectRect(const SDL_Rect *A,
                                  const SDL_Rect *B,
                                  SDL_Rect *result);

extern void SDL_UnionRect(const SDL_Rect *A,
                          const SDL_Rect *B,
                          SDL_Rect *result);

extern SDL_bool SDL_EnclosePoints(const SDL_Point *points,
                                  int count,
                                  const SDL_Rect *clip,
                                  SDL_Rect *result);

extern SDL_bool SDL_IntersectRectAndLine(const SDL_Rect *
                                             rect,
                                         int *X1,
                                         int *Y1, int *X2,
                                         int *Y2);

typedef enum
{
    SDL_BLENDMODE_NONE = 0x00000000,
    SDL_BLENDMODE_BLEND = 0x00000001,
    SDL_BLENDMODE_ADD = 0x00000002,
    SDL_BLENDMODE_MOD = 0x00000004,
    SDL_BLENDMODE_MUL = 0x00000008,
    SDL_BLENDMODE_INVALID = 0x7FFFFFFF
} SDL_BlendMode;

typedef enum
{
    SDL_BLENDOPERATION_ADD = 0x1,
    SDL_BLENDOPERATION_SUBTRACT = 0x2,
    SDL_BLENDOPERATION_REV_SUBTRACT = 0x3,
    SDL_BLENDOPERATION_MINIMUM = 0x4,
    SDL_BLENDOPERATION_MAXIMUM = 0x5
} SDL_BlendOperation;

typedef enum
{
    SDL_BLENDFACTOR_ZERO = 0x1,
    SDL_BLENDFACTOR_ONE = 0x2,
    SDL_BLENDFACTOR_SRC_COLOR = 0x3,
    SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR = 0x4,
    SDL_BLENDFACTOR_SRC_ALPHA = 0x5,
    SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA = 0x6,
    SDL_BLENDFACTOR_DST_COLOR = 0x7,
    SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR = 0x8,
    SDL_BLENDFACTOR_DST_ALPHA = 0x9,
    SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA = 0xA
} SDL_BlendFactor;
extern SDL_BlendMode SDL_ComposeCustomBlendMode(SDL_BlendFactor srcColorFactor,
                                                SDL_BlendFactor dstColorFactor,
                                                SDL_BlendOperation colorOperation,
                                                SDL_BlendFactor srcAlphaFactor,
                                                SDL_BlendFactor dstAlphaFactor,
                                                SDL_BlendOperation alphaOperation);
#define SDL_SWSURFACE 0
#define SDL_PREALLOC 0x00000001
#define SDL_RLEACCEL 0x00000002
#define SDL_DONTFREE 0x00000004
#define SDL_SIMD_ALIGNED 0x00000008
#define SDL_MUSTLOCK(S) (((S)->flags & SDL_RLEACCEL) != 0)

typedef struct SDL_Surface
{
    uint32_t flags;
    SDL_PixelFormat *format;
    int w, h;
    int pitch;
    void *pixels;
    void *userdata;
    int locked;
    void *lock_data;
    SDL_Rect clip_rect;
    struct SDL_BlitMap *map;
    int refcount;
} SDL_Surface;

typedef int (*SDL_blit)(struct SDL_Surface *src, SDL_Rect *srcrect,
                        struct SDL_Surface *dst, SDL_Rect *dstrect);

typedef enum
{
    SDL_YUV_CONVERSION_JPEG,
    SDL_YUV_CONVERSION_BT601,
    SDL_YUV_CONVERSION_BT709,
    SDL_YUV_CONVERSION_AUTOMATIC
} SDL_YUV_CONVERSION_MODE;
extern SDL_Surface *SDL_CreateRGBSurface(uint32_t flags, int width, int height, int depth,
                                         uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);

extern SDL_Surface *SDL_CreateRGBSurfaceWithFormat(uint32_t flags, int width, int height, int depth, uint32_t format);

extern SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels,
                                             int width,
                                             int height,
                                             int depth,
                                             int pitch,
                                             uint32_t Rmask,
                                             uint32_t Gmask,
                                             uint32_t Bmask,
                                             uint32_t Amask);
extern SDL_Surface *SDL_CreateRGBSurfaceWithFormatFrom(void *pixels, int width, int height, int depth, int pitch, uint32_t format);
extern void SDL_FreeSurface(SDL_Surface *surface);

extern int SDL_SetSurfacePalette(SDL_Surface *surface,
                                 SDL_Palette *palette);
extern int SDL_LockSurface(SDL_Surface *surface);

extern void SDL_UnlockSurface(SDL_Surface *surface);

extern SDL_Surface *SDL_LoadBMP_RW(SDL_RWops *src,
                                   int freesrc);
#define SDL_LoadBMP(file) SDL_LoadBMP_RW(SDL_RWFromFile(file, "rb"), 1)
extern int SDL_SaveBMP_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst);
#define SDL_SaveBMP(surface, file) SDL_SaveBMP_RW(surface, SDL_RWFromFile(file, "wb"), 1)

extern int SDL_SetSurfaceRLE(SDL_Surface *surface,
                             int flag);

extern int SDL_SetColorKey(SDL_Surface *surface,
                           int flag, uint32_t key);

extern SDL_bool SDL_HasColorKey(SDL_Surface *surface);

extern int SDL_GetColorKey(SDL_Surface *surface,
                           uint32_t *key);
extern int SDL_SetSurfaceColorMod(SDL_Surface *surface,
                                  Uint8 r, Uint8 g, Uint8 b);
extern int SDL_GetSurfaceColorMod(SDL_Surface *surface,
                                  Uint8 *r, Uint8 *g,
                                  Uint8 *b);

extern int SDL_SetSurfaceAlphaMod(SDL_Surface *surface,
                                  Uint8 alpha);

extern int SDL_GetSurfaceAlphaMod(SDL_Surface *surface,
                                  Uint8 *alpha);

extern int SDL_SetSurfaceBlendMode(SDL_Surface *surface,
                                   SDL_BlendMode blendMode);

extern int SDL_GetSurfaceBlendMode(SDL_Surface *surface,
                                   SDL_BlendMode *blendMode);
extern SDL_bool SDL_SetClipRect(SDL_Surface *surface,
                                const SDL_Rect *rect);

extern void SDL_GetClipRect(SDL_Surface *surface,
                            SDL_Rect *rect);
extern SDL_Surface *SDL_DuplicateSurface(SDL_Surface *surface);
extern SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, const SDL_PixelFormat *fmt, uint32_t flags);
extern SDL_Surface *SDL_ConvertSurfaceFormat(SDL_Surface *src, uint32_t pixel_format, uint32_t flags);

extern int SDL_ConvertPixels(int width, int height,
                             uint32_t src_format,
                             const void *src, int src_pitch,
                             uint32_t dst_format,
                             void *dst, int dst_pitch);
extern int SDL_FillRect(SDL_Surface *dst, const SDL_Rect *rect, uint32_t color);
extern int SDL_FillRects(SDL_Surface *dst, const SDL_Rect *rects, int count, uint32_t color);
#define SDL_BlitSurface SDL_UpperBlit
extern int SDL_UpperBlit(SDL_Surface *src, const SDL_Rect *srcrect,
                         SDL_Surface *dst, SDL_Rect *dstrect);
extern int SDL_LowerBlit(SDL_Surface *src, SDL_Rect *srcrect,
                         SDL_Surface *dst, SDL_Rect *dstrect);
extern int SDL_SoftStretch(SDL_Surface *src,
                           const SDL_Rect *srcrect,
                           SDL_Surface *dst,
                           const SDL_Rect *dstrect);
#define SDL_BlitScaled SDL_UpperBlitScaled
extern int SDL_UpperBlitScaled(SDL_Surface *src, const SDL_Rect *srcrect,
                               SDL_Surface *dst, SDL_Rect *dstrect);

extern int SDL_LowerBlitScaled(SDL_Surface *src, SDL_Rect *srcrect,
                               SDL_Surface *dst, SDL_Rect *dstrect);

extern void SDL_SetYUVConversionMode(SDL_YUV_CONVERSION_MODE mode);

extern SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionMode(void);

extern SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionModeForResolution(int width, int height);

typedef struct
{
    uint32_t format;
    int w;
    int h;
    int refresh_rate;
    void *driverdata;
} SDL_DisplayMode;
typedef struct SDL_Window SDL_Window;

typedef enum
{
    SDL_WINDOW_FULLSCREEN = 0x00000001,
    SDL_WINDOW_OPENGL = 0x00000002,
    SDL_WINDOW_SHOWN = 0x00000004,
    SDL_WINDOW_HIDDEN = 0x00000008,
    SDL_WINDOW_BORDERLESS = 0x00000010,
    SDL_WINDOW_RESIZABLE = 0x00000020,
    SDL_WINDOW_MINIMIZED = 0x00000040,
    SDL_WINDOW_MAXIMIZED = 0x00000080,
    SDL_WINDOW_INPUT_GRABBED = 0x00000100,
    SDL_WINDOW_INPUT_FOCUS = 0x00000200,
    SDL_WINDOW_MOUSE_FOCUS = 0x00000400,
    SDL_WINDOW_FULLSCREEN_DESKTOP = (SDL_WINDOW_FULLSCREEN | 0x00001000),
    SDL_WINDOW_FOREIGN = 0x00000800,
    SDL_WINDOW_ALLOW_HIGHDPI = 0x00002000,
    SDL_WINDOW_MOUSE_CAPTURE = 0x00004000,
    SDL_WINDOW_ALWAYS_ON_TOP = 0x00008000,
    SDL_WINDOW_SKIP_TASKBAR = 0x00010000,
    SDL_WINDOW_UTILITY = 0x00020000,
    SDL_WINDOW_TOOLTIP = 0x00040000,
    SDL_WINDOW_POPUP_MENU = 0x00080000,
    SDL_WINDOW_VULKAN = 0x10000000
} SDL_WindowFlags;
#define SDL_WINDOWPOS_UNDEFINED_MASK 0x1FFF0000u
#define SDL_WINDOWPOS_UNDEFINED_DISPLAY(X) (SDL_WINDOWPOS_UNDEFINED_MASK | (X))
#define SDL_WINDOWPOS_UNDEFINED SDL_WINDOWPOS_UNDEFINED_DISPLAY(0)
#define SDL_WINDOWPOS_ISUNDEFINED(X) (((X)&0xFFFF0000) == SDL_WINDOWPOS_UNDEFINED_MASK)
#define SDL_WINDOWPOS_CENTERED_MASK 0x2FFF0000u
#define SDL_WINDOWPOS_CENTERED_DISPLAY(X) (SDL_WINDOWPOS_CENTERED_MASK | (X))
#define SDL_WINDOWPOS_CENTERED SDL_WINDOWPOS_CENTERED_DISPLAY(0)
#define SDL_WINDOWPOS_ISCENTERED(X) (((X)&0xFFFF0000) == SDL_WINDOWPOS_CENTERED_MASK)



extern int SDL_GetNumVideoDrivers(void);

extern const char *SDL_GetVideoDriver(int index);
extern int SDL_VideoInit(const char *driver_name);

extern void SDL_VideoQuit(void);

extern const char *SDL_GetCurrentVideoDriver(void);

extern int SDL_GetNumVideoDisplays(void);

extern const char *SDL_GetDisplayName(int displayIndex);

extern int SDL_GetDisplayBounds(int displayIndex, SDL_Rect *rect);
extern int SDL_GetDisplayUsableBounds(int displayIndex, SDL_Rect *rect);

extern int SDL_GetDisplayDPI(int displayIndex, float *ddpi, float *hdpi, float *vdpi);

extern SDL_DisplayOrientation SDL_GetDisplayOrientation(int displayIndex);

extern int SDL_GetNumDisplayModes(int displayIndex);

extern int SDL_GetDisplayMode(int displayIndex, int modeIndex,
                              SDL_DisplayMode *mode);

extern int SDL_GetDesktopDisplayMode(int displayIndex, SDL_DisplayMode *mode);

extern int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode *mode);
extern SDL_DisplayMode *SDL_GetClosestDisplayMode(int displayIndex, const SDL_DisplayMode *mode, SDL_DisplayMode *closest);

extern int SDL_GetWindowDisplayIndex(SDL_Window *window);
extern int SDL_SetWindowDisplayMode(SDL_Window *window,
                                    const SDL_DisplayMode
                                        *mode);

extern int SDL_GetWindowDisplayMode(SDL_Window *window,
                                    SDL_DisplayMode *mode);

extern uint32_t SDL_GetWindowPixelFormat(SDL_Window *window);
extern SDL_Window *SDL_CreateWindow(const char *title,
                                    int x, int y, int w,
                                    int h, uint32_t flags);

extern SDL_Window *SDL_CreateWindowFrom(const void *data);

extern uint32_t SDL_GetWindowID(SDL_Window *window);

extern SDL_Window *SDL_GetWindowFromID(uint32_t id);

extern uint32_t SDL_GetWindowFlags(SDL_Window *window);

extern void SDL_SetWindowTitle(SDL_Window *window,
                               const char *title);

extern const char *SDL_GetWindowTitle(SDL_Window *window);

extern void SDL_SetWindowIcon(SDL_Window *window,
                              SDL_Surface *icon);
extern void *SDL_SetWindowData(SDL_Window *window,
                               const char *name,
                               void *userdata);

extern void *SDL_GetWindowData(SDL_Window *window,
                               const char *name);
extern void SDL_SetWindowPosition(SDL_Window *window,
                                  int x, int y);

extern void SDL_GetWindowPosition(SDL_Window *window,
                                  int *x, int *y);
extern void SDL_SetWindowSize(SDL_Window *window, int w,
                              int h);
extern void SDL_GetWindowSize(SDL_Window *window, int *w,
                              int *h);
extern int SDL_GetWindowBordersSize(SDL_Window *window,
                                    int *top, int *left,
                                    int *bottom, int *right);
extern void SDL_SetWindowMinimumSize(SDL_Window *window,
                                     int min_w, int min_h);

extern void SDL_GetWindowMinimumSize(SDL_Window *window,
                                     int *w, int *h);
extern void SDL_SetWindowMaximumSize(SDL_Window *window,
                                     int max_w, int max_h);

extern void SDL_GetWindowMaximumSize(SDL_Window *window,
                                     int *w, int *h);
extern void SDL_SetWindowBordered(SDL_Window *window,
                                  SDL_bool bordered);
extern void SDL_SetWindowResizable(SDL_Window *window,
                                   SDL_bool resizable);

extern void SDL_ShowWindow(SDL_Window *window);

extern void SDL_HideWindow(SDL_Window *window);

extern void SDL_RaiseWindow(SDL_Window *window);

extern void SDL_MaximizeWindow(SDL_Window *window);

extern void SDL_MinimizeWindow(SDL_Window *window);

extern void SDL_RestoreWindow(SDL_Window *window);

extern int SDL_SetWindowFullscreen(SDL_Window *window,
                                   uint32_t flags);
extern SDL_Surface *SDL_GetWindowSurface(SDL_Window *window);

extern int SDL_UpdateWindowSurface(SDL_Window *window);

extern int SDL_UpdateWindowSurfaceRects(SDL_Window *window,
                                        const SDL_Rect *rects,
                                        int numrects);

extern void SDL_SetWindowGrab(SDL_Window *window,
                              SDL_bool grabbed);

extern SDL_bool SDL_GetWindowGrab(SDL_Window *window);

extern SDL_Window *SDL_GetGrabbedWindow(void);

extern int SDL_SetWindowBrightness(SDL_Window *window, float brightness);

extern float SDL_GetWindowBrightness(SDL_Window *window);

extern int SDL_SetWindowOpacity(SDL_Window *window, float opacity);
extern int SDL_GetWindowOpacity(SDL_Window *window, float *out_opacity);

extern int SDL_SetWindowModalFor(SDL_Window *modal_window, SDL_Window *parent_window);
extern int SDL_SetWindowInputFocus(SDL_Window *window);
extern int SDL_SetWindowGammaRamp(SDL_Window *window,
                                  const Uint16 *red,
                                  const Uint16 *green,
                                  const Uint16 *blue);
extern int SDL_GetWindowGammaRamp(SDL_Window *window,
                                  Uint16 *red,
                                  Uint16 *green,
                                  Uint16 *blue);

typedef enum
{
    SDL_HITTEST_NORMAL,
    SDL_HITTEST_DRAGGABLE,
    SDL_HITTEST_RESIZE_TOPLEFT,
    SDL_HITTEST_RESIZE_TOP,
    SDL_HITTEST_RESIZE_TOPRIGHT,
    SDL_HITTEST_RESIZE_RIGHT,
    SDL_HITTEST_RESIZE_BOTTOMRIGHT,
    SDL_HITTEST_RESIZE_BOTTOM,
    SDL_HITTEST_RESIZE_BOTTOMLEFT,
    SDL_HITTEST_RESIZE_LEFT
} SDL_HitTestResult;

typedef SDL_HitTestResult (*SDL_HitTest)(SDL_Window *win,
                                         const SDL_Point *area,
                                         void *data);
extern int SDL_SetWindowHitTest(SDL_Window *window,
                                SDL_HitTest callback,
                                void *callback_data);

extern void SDL_DestroyWindow(SDL_Window *window);

extern SDL_bool SDL_IsScreenSaverEnabled(void);

extern void SDL_EnableScreenSaver(void);

extern void SDL_DisableScreenSaver(void);
extern int SDL_GL_LoadLibrary(const char *path);

extern void *SDL_GL_GetProcAddress(const char *proc);

extern void SDL_GL_UnloadLibrary(void);

extern SDL_bool SDL_GL_ExtensionSupported(const char
                                              *extension);

extern void SDL_GL_ResetAttributes(void);

extern int SDL_GL_SetAttribute(SDL_GLattr attr, int value);

extern int SDL_GL_GetAttribute(SDL_GLattr attr, int *value);

extern SDL_GLContext SDL_GL_CreateContext(SDL_Window *
                                              window);

extern int SDL_GL_MakeCurrent(SDL_Window *window,
                              SDL_GLContext context);

extern SDL_Window *SDL_GL_GetCurrentWindow(void);

extern SDL_GLContext SDL_GL_GetCurrentContext(void);
extern void SDL_GL_GetDrawableSize(SDL_Window *window, int *w,
                                   int *h);
extern int SDL_GL_SetSwapInterval(int interval);

extern int SDL_GL_GetSwapInterval(void);

extern void SDL_GL_SwapWindow(SDL_Window *window);

extern void SDL_GL_DeleteContext(SDL_GLContext context);

typedef enum
{
    SDL_SCANCODE_UNKNOWN = 0,
    SDL_SCANCODE_A = 4,
    SDL_SCANCODE_B = 5,
    SDL_SCANCODE_C = 6,
    SDL_SCANCODE_D = 7,
    SDL_SCANCODE_E = 8,
    SDL_SCANCODE_F = 9,
    SDL_SCANCODE_G = 10,
    SDL_SCANCODE_H = 11,
    SDL_SCANCODE_I = 12,
    SDL_SCANCODE_J = 13,
    SDL_SCANCODE_K = 14,
    SDL_SCANCODE_L = 15,
    SDL_SCANCODE_M = 16,
    SDL_SCANCODE_N = 17,
    SDL_SCANCODE_O = 18,
    SDL_SCANCODE_P = 19,
    SDL_SCANCODE_Q = 20,
    SDL_SCANCODE_R = 21,
    SDL_SCANCODE_S = 22,
    SDL_SCANCODE_T = 23,
    SDL_SCANCODE_U = 24,
    SDL_SCANCODE_V = 25,
    SDL_SCANCODE_W = 26,
    SDL_SCANCODE_X = 27,
    SDL_SCANCODE_Y = 28,
    SDL_SCANCODE_Z = 29,
    SDL_SCANCODE_1 = 30,
    SDL_SCANCODE_2 = 31,
    SDL_SCANCODE_3 = 32,
    SDL_SCANCODE_4 = 33,
    SDL_SCANCODE_5 = 34,
    SDL_SCANCODE_6 = 35,
    SDL_SCANCODE_7 = 36,
    SDL_SCANCODE_8 = 37,
    SDL_SCANCODE_9 = 38,
    SDL_SCANCODE_0 = 39,
    SDL_SCANCODE_RETURN = 40,
    SDL_SCANCODE_ESCAPE = 41,
    SDL_SCANCODE_BACKSPACE = 42,
    SDL_SCANCODE_TAB = 43,
    SDL_SCANCODE_SPACE = 44,
    SDL_SCANCODE_MINUS = 45,
    SDL_SCANCODE_EQUALS = 46,
    SDL_SCANCODE_LEFTBRACKET = 47,
    SDL_SCANCODE_RIGHTBRACKET = 48,
    SDL_SCANCODE_BACKSLASH = 49,
    SDL_SCANCODE_NONUSHASH = 50,
    SDL_SCANCODE_SEMICOLON = 51,
    SDL_SCANCODE_APOSTROPHE = 52,
    SDL_SCANCODE_GRAVE = 53,
    SDL_SCANCODE_COMMA = 54,
    SDL_SCANCODE_PERIOD = 55,
    SDL_SCANCODE_SLASH = 56,
    SDL_SCANCODE_CAPSLOCK = 57,
    SDL_SCANCODE_F1 = 58,
    SDL_SCANCODE_F2 = 59,
    SDL_SCANCODE_F3 = 60,
    SDL_SCANCODE_F4 = 61,
    SDL_SCANCODE_F5 = 62,
    SDL_SCANCODE_F6 = 63,
    SDL_SCANCODE_F7 = 64,
    SDL_SCANCODE_F8 = 65,
    SDL_SCANCODE_F9 = 66,
    SDL_SCANCODE_F10 = 67,
    SDL_SCANCODE_F11 = 68,
    SDL_SCANCODE_F12 = 69,
    SDL_SCANCODE_PRINTSCREEN = 70,
    SDL_SCANCODE_SCROLLLOCK = 71,
    SDL_SCANCODE_PAUSE = 72,
    SDL_SCANCODE_INSERT = 73,
    SDL_SCANCODE_HOME = 74,
    SDL_SCANCODE_PAGEUP = 75,
    SDL_SCANCODE_DELETE = 76,
    SDL_SCANCODE_END = 77,
    SDL_SCANCODE_PAGEDOWN = 78,
    SDL_SCANCODE_RIGHT = 79,
    SDL_SCANCODE_LEFT = 80,
    SDL_SCANCODE_DOWN = 81,
    SDL_SCANCODE_UP = 82,
    SDL_SCANCODE_NUMLOCKCLEAR = 83,
    SDL_SCANCODE_KP_DIVIDE = 84,
    SDL_SCANCODE_KP_MULTIPLY = 85,
    SDL_SCANCODE_KP_MINUS = 86,
    SDL_SCANCODE_KP_PLUS = 87,
    SDL_SCANCODE_KP_ENTER = 88,
    SDL_SCANCODE_KP_1 = 89,
    SDL_SCANCODE_KP_2 = 90,
    SDL_SCANCODE_KP_3 = 91,
    SDL_SCANCODE_KP_4 = 92,
    SDL_SCANCODE_KP_5 = 93,
    SDL_SCANCODE_KP_6 = 94,
    SDL_SCANCODE_KP_7 = 95,
    SDL_SCANCODE_KP_8 = 96,
    SDL_SCANCODE_KP_9 = 97,
    SDL_SCANCODE_KP_0 = 98,
    SDL_SCANCODE_KP_PERIOD = 99,
    SDL_SCANCODE_NONUSBACKSLASH = 100,
    SDL_SCANCODE_APPLICATION = 101,
    SDL_SCANCODE_POWER = 102,
    SDL_SCANCODE_KP_EQUALS = 103,
    SDL_SCANCODE_F13 = 104,
    SDL_SCANCODE_F14 = 105,
    SDL_SCANCODE_F15 = 106,
    SDL_SCANCODE_F16 = 107,
    SDL_SCANCODE_F17 = 108,
    SDL_SCANCODE_F18 = 109,
    SDL_SCANCODE_F19 = 110,
    SDL_SCANCODE_F20 = 111,
    SDL_SCANCODE_F21 = 112,
    SDL_SCANCODE_F22 = 113,
    SDL_SCANCODE_F23 = 114,
    SDL_SCANCODE_F24 = 115,
    SDL_SCANCODE_EXECUTE = 116,
    SDL_SCANCODE_HELP = 117,
    SDL_SCANCODE_MENU = 118,
    SDL_SCANCODE_SELECT = 119,
    SDL_SCANCODE_STOP = 120,
    SDL_SCANCODE_AGAIN = 121,
    SDL_SCANCODE_UNDO = 122,
    SDL_SCANCODE_CUT = 123,
    SDL_SCANCODE_COPY = 124,
    SDL_SCANCODE_PASTE = 125,
    SDL_SCANCODE_FIND = 126,
    SDL_SCANCODE_MUTE = 127,
    SDL_SCANCODE_VOLUMEUP = 128,
    SDL_SCANCODE_VOLUMEDOWN = 129,
    SDL_SCANCODE_KP_COMMA = 133,
    SDL_SCANCODE_KP_EQUALSAS400 = 134,
    SDL_SCANCODE_INTERNATIONAL1 = 135,
    SDL_SCANCODE_INTERNATIONAL2 = 136,
    SDL_SCANCODE_INTERNATIONAL3 = 137,
    SDL_SCANCODE_INTERNATIONAL4 = 138,
    SDL_SCANCODE_INTERNATIONAL5 = 139,
    SDL_SCANCODE_INTERNATIONAL6 = 140,
    SDL_SCANCODE_INTERNATIONAL7 = 141,
    SDL_SCANCODE_INTERNATIONAL8 = 142,
    SDL_SCANCODE_INTERNATIONAL9 = 143,
    SDL_SCANCODE_LANG1 = 144,
    SDL_SCANCODE_LANG2 = 145,
    SDL_SCANCODE_LANG3 = 146,
    SDL_SCANCODE_LANG4 = 147,
    SDL_SCANCODE_LANG5 = 148,
    SDL_SCANCODE_LANG6 = 149,
    SDL_SCANCODE_LANG7 = 150,
    SDL_SCANCODE_LANG8 = 151,
    SDL_SCANCODE_LANG9 = 152,
    SDL_SCANCODE_ALTERASE = 153,
    SDL_SCANCODE_SYSREQ = 154,
    SDL_SCANCODE_CANCEL = 155,
    SDL_SCANCODE_CLEAR = 156,
    SDL_SCANCODE_PRIOR = 157,
    SDL_SCANCODE_RETURN2 = 158,
    SDL_SCANCODE_SEPARATOR = 159,
    SDL_SCANCODE_OUT = 160,
    SDL_SCANCODE_OPER = 161,
    SDL_SCANCODE_CLEARAGAIN = 162,
    SDL_SCANCODE_CRSEL = 163,
    SDL_SCANCODE_EXSEL = 164,
    SDL_SCANCODE_KP_00 = 176,
    SDL_SCANCODE_KP_000 = 177,
    SDL_SCANCODE_THOUSANDSSEPARATOR = 178,
    SDL_SCANCODE_DECIMALSEPARATOR = 179,
    SDL_SCANCODE_CURRENCYUNIT = 180,
    SDL_SCANCODE_CURRENCYSUBUNIT = 181,
    SDL_SCANCODE_KP_LEFTPAREN = 182,
    SDL_SCANCODE_KP_RIGHTPAREN = 183,
    SDL_SCANCODE_KP_LEFTBRACE = 184,
    SDL_SCANCODE_KP_RIGHTBRACE = 185,
    SDL_SCANCODE_KP_TAB = 186,
    SDL_SCANCODE_KP_BACKSPACE = 187,
    SDL_SCANCODE_KP_A = 188,
    SDL_SCANCODE_KP_B = 189,
    SDL_SCANCODE_KP_C = 190,
    SDL_SCANCODE_KP_D = 191,
    SDL_SCANCODE_KP_E = 192,
    SDL_SCANCODE_KP_F = 193,
    SDL_SCANCODE_KP_XOR = 194,
    SDL_SCANCODE_KP_POWER = 195,
    SDL_SCANCODE_KP_PERCENT = 196,
    SDL_SCANCODE_KP_LESS = 197,
    SDL_SCANCODE_KP_GREATER = 198,
    SDL_SCANCODE_KP_AMPERSAND = 199,
    SDL_SCANCODE_KP_DBLAMPERSAND = 200,
    SDL_SCANCODE_KP_VERTICALBAR = 201,
    SDL_SCANCODE_KP_DBLVERTICALBAR = 202,
    SDL_SCANCODE_KP_COLON = 203,
    SDL_SCANCODE_KP_HASH = 204,
    SDL_SCANCODE_KP_SPACE = 205,
    SDL_SCANCODE_KP_AT = 206,
    SDL_SCANCODE_KP_EXCLAM = 207,
    SDL_SCANCODE_KP_MEMSTORE = 208,
    SDL_SCANCODE_KP_MEMRECALL = 209,
    SDL_SCANCODE_KP_MEMCLEAR = 210,
    SDL_SCANCODE_KP_MEMADD = 211,
    SDL_SCANCODE_KP_MEMSUBTRACT = 212,
    SDL_SCANCODE_KP_MEMMULTIPLY = 213,
    SDL_SCANCODE_KP_MEMDIVIDE = 214,
    SDL_SCANCODE_KP_PLUSMINUS = 215,
    SDL_SCANCODE_KP_CLEAR = 216,
    SDL_SCANCODE_KP_CLEARENTRY = 217,
    SDL_SCANCODE_KP_BINARY = 218,
    SDL_SCANCODE_KP_OCTAL = 219,
    SDL_SCANCODE_KP_DECIMAL = 220,
    SDL_SCANCODE_KP_HEXADECIMAL = 221,
    SDL_SCANCODE_LCTRL = 224,
    SDL_SCANCODE_LSHIFT = 225,
    SDL_SCANCODE_LALT = 226,
    SDL_SCANCODE_LGUI = 227,
    SDL_SCANCODE_RCTRL = 228,
    SDL_SCANCODE_RSHIFT = 229,
    SDL_SCANCODE_RALT = 230,
    SDL_SCANCODE_RGUI = 231,
    SDL_SCANCODE_MODE = 257,
    SDL_SCANCODE_AUDIONEXT = 258,
    SDL_SCANCODE_AUDIOPREV = 259,
    SDL_SCANCODE_AUDIOSTOP = 260,
    SDL_SCANCODE_AUDIOPLAY = 261,
    SDL_SCANCODE_AUDIOMUTE = 262,
    SDL_SCANCODE_MEDIASELECT = 263,
    SDL_SCANCODE_WWW = 264,
    SDL_SCANCODE_MAIL = 265,
    SDL_SCANCODE_CALCULATOR = 266,
    SDL_SCANCODE_COMPUTER = 267,
    SDL_SCANCODE_AC_SEARCH = 268,
    SDL_SCANCODE_AC_HOME = 269,
    SDL_SCANCODE_AC_BACK = 270,
    SDL_SCANCODE_AC_FORWARD = 271,
    SDL_SCANCODE_AC_STOP = 272,
    SDL_SCANCODE_AC_REFRESH = 273,
    SDL_SCANCODE_AC_BOOKMARKS = 274,
    SDL_SCANCODE_BRIGHTNESSDOWN = 275,
    SDL_SCANCODE_BRIGHTNESSUP = 276,
    SDL_SCANCODE_DISPLAYSWITCH = 277,
    SDL_SCANCODE_KBDILLUMTOGGLE = 278,
    SDL_SCANCODE_KBDILLUMDOWN = 279,
    SDL_SCANCODE_KBDILLUMUP = 280,
    SDL_SCANCODE_EJECT = 281,
    SDL_SCANCODE_SLEEP = 282,
    SDL_SCANCODE_APP1 = 283,
    SDL_SCANCODE_APP2 = 284,
    SDL_SCANCODE_AUDIOREWIND = 285,
    SDL_SCANCODE_AUDIOFASTFORWARD = 286,
    SDL_NUM_SCANCODES = 512
} SDL_Scancode;

typedef Sint32 SDL_Keycode;
#define SDLK_SCANCODE_MASK (1 << 30)
#define SDL_SCANCODE_TO_KEYCODE(X) (X | SDLK_SCANCODE_MASK)

typedef enum
{
    SDLK_UNKNOWN = 0,
    SDLK_RETURN = '\r',
    SDLK_ESCAPE = '\033',
    SDLK_BACKSPACE = '\b',
    SDLK_TAB = '\t',
    SDLK_SPACE = ' ',
    SDLK_EXCLAIM = '!',
    SDLK_QUOTEDBL = '"',
    SDLK_HASH = '#',
    SDLK_PERCENT = '%',
    SDLK_DOLLAR = '$',
    SDLK_AMPERSAND = '&',
    SDLK_QUOTE = '\'',
    SDLK_LEFTPAREN = '(',
    SDLK_RIGHTPAREN = ')',
    SDLK_ASTERISK = '*',
    SDLK_PLUS = '+',
    SDLK_COMMA = ',',
    SDLK_MINUS = '-',
    SDLK_PERIOD = '.',
    SDLK_SLASH = '/',
    SDLK_0 = '0',
    SDLK_1 = '1',
    SDLK_2 = '2',
    SDLK_3 = '3',
    SDLK_4 = '4',
    SDLK_5 = '5',
    SDLK_6 = '6',
    SDLK_7 = '7',
    SDLK_8 = '8',
    SDLK_9 = '9',
    SDLK_COLON = ':',
    SDLK_SEMICOLON = ';',
    SDLK_LESS = '<',
    SDLK_EQUALS = '=',
    SDLK_GREATER = '>',
    SDLK_QUESTION = '?',
    SDLK_AT = '@',
    SDLK_LEFTBRACKET = '[',
    SDLK_BACKSLASH = '\\',
    SDLK_RIGHTBRACKET = ']',
    SDLK_CARET = '^',
    SDLK_UNDERSCORE = '_',
    SDLK_BACKQUOTE = '`',
    SDLK_a = 'a',
    SDLK_b = 'b',
    SDLK_c = 'c',
    SDLK_d = 'd',
    SDLK_e = 'e',
    SDLK_f = 'f',
    SDLK_g = 'g',
    SDLK_h = 'h',
    SDLK_i = 'i',
    SDLK_j = 'j',
    SDLK_k = 'k',
    SDLK_l = 'l',
    SDLK_m = 'm',
    SDLK_n = 'n',
    SDLK_o = 'o',
    SDLK_p = 'p',
    SDLK_q = 'q',
    SDLK_r = 'r',
    SDLK_s = 's',
    SDLK_t = 't',
    SDLK_u = 'u',
    SDLK_v = 'v',
    SDLK_w = 'w',
    SDLK_x = 'x',
    SDLK_y = 'y',
    SDLK_z = 'z',
    SDLK_CAPSLOCK = (SDL_SCANCODE_CAPSLOCK | (1 << 30)),
    SDLK_F1 = (SDL_SCANCODE_F1 | (1 << 30)),
    SDLK_F2 = (SDL_SCANCODE_F2 | (1 << 30)),
    SDLK_F3 = (SDL_SCANCODE_F3 | (1 << 30)),
    SDLK_F4 = (SDL_SCANCODE_F4 | (1 << 30)),
    SDLK_F5 = (SDL_SCANCODE_F5 | (1 << 30)),
    SDLK_F6 = (SDL_SCANCODE_F6 | (1 << 30)),
    SDLK_F7 = (SDL_SCANCODE_F7 | (1 << 30)),
    SDLK_F8 = (SDL_SCANCODE_F8 | (1 << 30)),
    SDLK_F9 = (SDL_SCANCODE_F9 | (1 << 30)),
    SDLK_F10 = (SDL_SCANCODE_F10 | (1 << 30)),
    SDLK_F11 = (SDL_SCANCODE_F11 | (1 << 30)),
    SDLK_F12 = (SDL_SCANCODE_F12 | (1 << 30)),
    SDLK_PRINTSCREEN = (SDL_SCANCODE_PRINTSCREEN | (1 << 30)),
    SDLK_SCROLLLOCK = (SDL_SCANCODE_SCROLLLOCK | (1 << 30)),
    SDLK_PAUSE = (SDL_SCANCODE_PAUSE | (1 << 30)),
    SDLK_INSERT = (SDL_SCANCODE_INSERT | (1 << 30)),
    SDLK_HOME = (SDL_SCANCODE_HOME | (1 << 30)),
    SDLK_PAGEUP = (SDL_SCANCODE_PAGEUP | (1 << 30)),
    SDLK_DELETE = '\177',
    SDLK_END = (SDL_SCANCODE_END | (1 << 30)),
    SDLK_PAGEDOWN = (SDL_SCANCODE_PAGEDOWN | (1 << 30)),
    SDLK_RIGHT = (SDL_SCANCODE_RIGHT | (1 << 30)),
    SDLK_LEFT = (SDL_SCANCODE_LEFT | (1 << 30)),
    SDLK_DOWN = (SDL_SCANCODE_DOWN | (1 << 30)),
    SDLK_UP = (SDL_SCANCODE_UP | (1 << 30)),
    SDLK_NUMLOCKCLEAR = (SDL_SCANCODE_NUMLOCKCLEAR | (1 << 30)),
    SDLK_KP_DIVIDE = (SDL_SCANCODE_KP_DIVIDE | (1 << 30)),
    SDLK_KP_MULTIPLY = (SDL_SCANCODE_KP_MULTIPLY | (1 << 30)),
    SDLK_KP_MINUS = (SDL_SCANCODE_KP_MINUS | (1 << 30)),
    SDLK_KP_PLUS = (SDL_SCANCODE_KP_PLUS | (1 << 30)),
    SDLK_KP_ENTER = (SDL_SCANCODE_KP_ENTER | (1 << 30)),
    SDLK_KP_1 = (SDL_SCANCODE_KP_1 | (1 << 30)),
    SDLK_KP_2 = (SDL_SCANCODE_KP_2 | (1 << 30)),
    SDLK_KP_3 = (SDL_SCANCODE_KP_3 | (1 << 30)),
    SDLK_KP_4 = (SDL_SCANCODE_KP_4 | (1 << 30)),
    SDLK_KP_5 = (SDL_SCANCODE_KP_5 | (1 << 30)),
    SDLK_KP_6 = (SDL_SCANCODE_KP_6 | (1 << 30)),
    SDLK_KP_7 = (SDL_SCANCODE_KP_7 | (1 << 30)),
    SDLK_KP_8 = (SDL_SCANCODE_KP_8 | (1 << 30)),
    SDLK_KP_9 = (SDL_SCANCODE_KP_9 | (1 << 30)),
    SDLK_KP_0 = (SDL_SCANCODE_KP_0 | (1 << 30)),
    SDLK_KP_PERIOD = (SDL_SCANCODE_KP_PERIOD | (1 << 30)),
    SDLK_APPLICATION = (SDL_SCANCODE_APPLICATION | (1 << 30)),
    SDLK_POWER = (SDL_SCANCODE_POWER | (1 << 30)),
    SDLK_KP_EQUALS = (SDL_SCANCODE_KP_EQUALS | (1 << 30)),
    SDLK_F13 = (SDL_SCANCODE_F13 | (1 << 30)),
    SDLK_F14 = (SDL_SCANCODE_F14 | (1 << 30)),
    SDLK_F15 = (SDL_SCANCODE_F15 | (1 << 30)),
    SDLK_F16 = (SDL_SCANCODE_F16 | (1 << 30)),
    SDLK_F17 = (SDL_SCANCODE_F17 | (1 << 30)),
    SDLK_F18 = (SDL_SCANCODE_F18 | (1 << 30)),
    SDLK_F19 = (SDL_SCANCODE_F19 | (1 << 30)),
    SDLK_F20 = (SDL_SCANCODE_F20 | (1 << 30)),
    SDLK_F21 = (SDL_SCANCODE_F21 | (1 << 30)),
    SDLK_F22 = (SDL_SCANCODE_F22 | (1 << 30)),
    SDLK_F23 = (SDL_SCANCODE_F23 | (1 << 30)),
    SDLK_F24 = (SDL_SCANCODE_F24 | (1 << 30)),
    SDLK_EXECUTE = (SDL_SCANCODE_EXECUTE | (1 << 30)),
    SDLK_HELP = (SDL_SCANCODE_HELP | (1 << 30)),
    SDLK_MENU = (SDL_SCANCODE_MENU | (1 << 30)),
    SDLK_SELECT = (SDL_SCANCODE_SELECT | (1 << 30)),
    SDLK_STOP = (SDL_SCANCODE_STOP | (1 << 30)),
    SDLK_AGAIN = (SDL_SCANCODE_AGAIN | (1 << 30)),
    SDLK_UNDO = (SDL_SCANCODE_UNDO | (1 << 30)),
    SDLK_CUT = (SDL_SCANCODE_CUT | (1 << 30)),
    SDLK_COPY = (SDL_SCANCODE_COPY | (1 << 30)),
    SDLK_PASTE = (SDL_SCANCODE_PASTE | (1 << 30)),
    SDLK_FIND = (SDL_SCANCODE_FIND | (1 << 30)),
    SDLK_MUTE = (SDL_SCANCODE_MUTE | (1 << 30)),
    SDLK_VOLUMEUP = (SDL_SCANCODE_VOLUMEUP | (1 << 30)),
    SDLK_VOLUMEDOWN = (SDL_SCANCODE_VOLUMEDOWN | (1 << 30)),
    SDLK_KP_COMMA = (SDL_SCANCODE_KP_COMMA | (1 << 30)),
    SDLK_KP_EQUALSAS400 =
        (SDL_SCANCODE_KP_EQUALSAS400 | (1 << 30)),
    SDLK_ALTERASE = (SDL_SCANCODE_ALTERASE | (1 << 30)),
    SDLK_SYSREQ = (SDL_SCANCODE_SYSREQ | (1 << 30)),
    SDLK_CANCEL = (SDL_SCANCODE_CANCEL | (1 << 30)),
    SDLK_CLEAR = (SDL_SCANCODE_CLEAR | (1 << 30)),
    SDLK_PRIOR = (SDL_SCANCODE_PRIOR | (1 << 30)),
    SDLK_RETURN2 = (SDL_SCANCODE_RETURN2 | (1 << 30)),
    SDLK_SEPARATOR = (SDL_SCANCODE_SEPARATOR | (1 << 30)),
    SDLK_OUT = (SDL_SCANCODE_OUT | (1 << 30)),
    SDLK_OPER = (SDL_SCANCODE_OPER | (1 << 30)),
    SDLK_CLEARAGAIN = (SDL_SCANCODE_CLEARAGAIN | (1 << 30)),
    SDLK_CRSEL = (SDL_SCANCODE_CRSEL | (1 << 30)),
    SDLK_EXSEL = (SDL_SCANCODE_EXSEL | (1 << 30)),
    SDLK_KP_00 = (SDL_SCANCODE_KP_00 | (1 << 30)),
    SDLK_KP_000 = (SDL_SCANCODE_KP_000 | (1 << 30)),
    SDLK_THOUSANDSSEPARATOR =
        (SDL_SCANCODE_THOUSANDSSEPARATOR | (1 << 30)),
    SDLK_DECIMALSEPARATOR =
        (SDL_SCANCODE_DECIMALSEPARATOR | (1 << 30)),
    SDLK_CURRENCYUNIT = (SDL_SCANCODE_CURRENCYUNIT | (1 << 30)),
    SDLK_CURRENCYSUBUNIT =
        (SDL_SCANCODE_CURRENCYSUBUNIT | (1 << 30)),
    SDLK_KP_LEFTPAREN = (SDL_SCANCODE_KP_LEFTPAREN | (1 << 30)),
    SDLK_KP_RIGHTPAREN = (SDL_SCANCODE_KP_RIGHTPAREN | (1 << 30)),
    SDLK_KP_LEFTBRACE = (SDL_SCANCODE_KP_LEFTBRACE | (1 << 30)),
    SDLK_KP_RIGHTBRACE = (SDL_SCANCODE_KP_RIGHTBRACE | (1 << 30)),
    SDLK_KP_TAB = (SDL_SCANCODE_KP_TAB | (1 << 30)),
    SDLK_KP_BACKSPACE = (SDL_SCANCODE_KP_BACKSPACE | (1 << 30)),
    SDLK_KP_A = (SDL_SCANCODE_KP_A | (1 << 30)),
    SDLK_KP_B = (SDL_SCANCODE_KP_B | (1 << 30)),
    SDLK_KP_C = (SDL_SCANCODE_KP_C | (1 << 30)),
    SDLK_KP_D = (SDL_SCANCODE_KP_D | (1 << 30)),
    SDLK_KP_E = (SDL_SCANCODE_KP_E | (1 << 30)),
    SDLK_KP_F = (SDL_SCANCODE_KP_F | (1 << 30)),
    SDLK_KP_XOR = (SDL_SCANCODE_KP_XOR | (1 << 30)),
    SDLK_KP_POWER = (SDL_SCANCODE_KP_POWER | (1 << 30)),
    SDLK_KP_PERCENT = (SDL_SCANCODE_KP_PERCENT | (1 << 30)),
    SDLK_KP_LESS = (SDL_SCANCODE_KP_LESS | (1 << 30)),
    SDLK_KP_GREATER = (SDL_SCANCODE_KP_GREATER | (1 << 30)),
    SDLK_KP_AMPERSAND = (SDL_SCANCODE_KP_AMPERSAND | (1 << 30)),
    SDLK_KP_DBLAMPERSAND =
        (SDL_SCANCODE_KP_DBLAMPERSAND | (1 << 30)),
    SDLK_KP_VERTICALBAR =
        (SDL_SCANCODE_KP_VERTICALBAR | (1 << 30)),
    SDLK_KP_DBLVERTICALBAR =
        (SDL_SCANCODE_KP_DBLVERTICALBAR | (1 << 30)),
    SDLK_KP_COLON = (SDL_SCANCODE_KP_COLON | (1 << 30)),
    SDLK_KP_HASH = (SDL_SCANCODE_KP_HASH | (1 << 30)),
    SDLK_KP_SPACE = (SDL_SCANCODE_KP_SPACE | (1 << 30)),
    SDLK_KP_AT = (SDL_SCANCODE_KP_AT | (1 << 30)),
    SDLK_KP_EXCLAM = (SDL_SCANCODE_KP_EXCLAM | (1 << 30)),
    SDLK_KP_MEMSTORE = (SDL_SCANCODE_KP_MEMSTORE | (1 << 30)),
    SDLK_KP_MEMRECALL = (SDL_SCANCODE_KP_MEMRECALL | (1 << 30)),
    SDLK_KP_MEMCLEAR = (SDL_SCANCODE_KP_MEMCLEAR | (1 << 30)),
    SDLK_KP_MEMADD = (SDL_SCANCODE_KP_MEMADD | (1 << 30)),
    SDLK_KP_MEMSUBTRACT =
        (SDL_SCANCODE_KP_MEMSUBTRACT | (1 << 30)),
    SDLK_KP_MEMMULTIPLY =
        (SDL_SCANCODE_KP_MEMMULTIPLY | (1 << 30)),
    SDLK_KP_MEMDIVIDE = (SDL_SCANCODE_KP_MEMDIVIDE | (1 << 30)),
    SDLK_KP_PLUSMINUS = (SDL_SCANCODE_KP_PLUSMINUS | (1 << 30)),
    SDLK_KP_CLEAR = (SDL_SCANCODE_KP_CLEAR | (1 << 30)),
    SDLK_KP_CLEARENTRY = (SDL_SCANCODE_KP_CLEARENTRY | (1 << 30)),
    SDLK_KP_BINARY = (SDL_SCANCODE_KP_BINARY | (1 << 30)),
    SDLK_KP_OCTAL = (SDL_SCANCODE_KP_OCTAL | (1 << 30)),
    SDLK_KP_DECIMAL = (SDL_SCANCODE_KP_DECIMAL | (1 << 30)),
    SDLK_KP_HEXADECIMAL =
        (SDL_SCANCODE_KP_HEXADECIMAL | (1 << 30)),
    SDLK_LCTRL = (SDL_SCANCODE_LCTRL | (1 << 30)),
    SDLK_LSHIFT = (SDL_SCANCODE_LSHIFT | (1 << 30)),
    SDLK_LALT = (SDL_SCANCODE_LALT | (1 << 30)),
    SDLK_LGUI = (SDL_SCANCODE_LGUI | (1 << 30)),
    SDLK_RCTRL = (SDL_SCANCODE_RCTRL | (1 << 30)),
    SDLK_RSHIFT = (SDL_SCANCODE_RSHIFT | (1 << 30)),
    SDLK_RALT = (SDL_SCANCODE_RALT | (1 << 30)),
    SDLK_RGUI = (SDL_SCANCODE_RGUI | (1 << 30)),
    SDLK_MODE = (SDL_SCANCODE_MODE | (1 << 30)),
    SDLK_AUDIONEXT = (SDL_SCANCODE_AUDIONEXT | (1 << 30)),
    SDLK_AUDIOPREV = (SDL_SCANCODE_AUDIOPREV | (1 << 30)),
    SDLK_AUDIOSTOP = (SDL_SCANCODE_AUDIOSTOP | (1 << 30)),
    SDLK_AUDIOPLAY = (SDL_SCANCODE_AUDIOPLAY | (1 << 30)),
    SDLK_AUDIOMUTE = (SDL_SCANCODE_AUDIOMUTE | (1 << 30)),
    SDLK_MEDIASELECT = (SDL_SCANCODE_MEDIASELECT | (1 << 30)),
    SDLK_WWW = (SDL_SCANCODE_WWW | (1 << 30)),
    SDLK_MAIL = (SDL_SCANCODE_MAIL | (1 << 30)),
    SDLK_CALCULATOR = (SDL_SCANCODE_CALCULATOR | (1 << 30)),
    SDLK_COMPUTER = (SDL_SCANCODE_COMPUTER | (1 << 30)),
    SDLK_AC_SEARCH = (SDL_SCANCODE_AC_SEARCH | (1 << 30)),
    SDLK_AC_HOME = (SDL_SCANCODE_AC_HOME | (1 << 30)),
    SDLK_AC_BACK = (SDL_SCANCODE_AC_BACK | (1 << 30)),
    SDLK_AC_FORWARD = (SDL_SCANCODE_AC_FORWARD | (1 << 30)),
    SDLK_AC_STOP = (SDL_SCANCODE_AC_STOP | (1 << 30)),
    SDLK_AC_REFRESH = (SDL_SCANCODE_AC_REFRESH | (1 << 30)),
    SDLK_AC_BOOKMARKS = (SDL_SCANCODE_AC_BOOKMARKS | (1 << 30)),
    SDLK_BRIGHTNESSDOWN =
        (SDL_SCANCODE_BRIGHTNESSDOWN | (1 << 30)),
    SDLK_BRIGHTNESSUP = (SDL_SCANCODE_BRIGHTNESSUP | (1 << 30)),
    SDLK_DISPLAYSWITCH = (SDL_SCANCODE_DISPLAYSWITCH | (1 << 30)),
    SDLK_KBDILLUMTOGGLE =
        (SDL_SCANCODE_KBDILLUMTOGGLE | (1 << 30)),
    SDLK_KBDILLUMDOWN = (SDL_SCANCODE_KBDILLUMDOWN | (1 << 30)),
    SDLK_KBDILLUMUP = (SDL_SCANCODE_KBDILLUMUP | (1 << 30)),
    SDLK_EJECT = (SDL_SCANCODE_EJECT | (1 << 30)),
    SDLK_SLEEP = (SDL_SCANCODE_SLEEP | (1 << 30)),
    SDLK_APP1 = (SDL_SCANCODE_APP1 | (1 << 30)),
    SDLK_APP2 = (SDL_SCANCODE_APP2 | (1 << 30)),
    SDLK_AUDIOREWIND = (SDL_SCANCODE_AUDIOREWIND | (1 << 30)),
    SDLK_AUDIOFASTFORWARD = (SDL_SCANCODE_AUDIOFASTFORWARD | (1 << 30))
} SDL_KeyCode;

typedef enum
{
    KMOD_NONE = 0x0000,
    KMOD_LSHIFT = 0x0001,
    KMOD_RSHIFT = 0x0002,
    KMOD_LCTRL = 0x0040,
    KMOD_RCTRL = 0x0080,
    KMOD_LALT = 0x0100,
    KMOD_RALT = 0x0200,
    KMOD_LGUI = 0x0400,
    KMOD_RGUI = 0x0800,
    KMOD_NUM = 0x1000,
    KMOD_CAPS = 0x2000,
    KMOD_MODE = 0x4000,
    KMOD_RESERVED = 0x8000
} SDL_Keymod;
#define KMOD_CTRL (KMOD_LCTRL | KMOD_RCTRL)
#define KMOD_SHIFT (KMOD_LSHIFT | KMOD_RSHIFT)
#define KMOD_ALT (KMOD_LALT | KMOD_RALT)
#define KMOD_GUI (KMOD_LGUI | KMOD_RGUI)

typedef struct SDL_Keysym
{
    SDL_Scancode scancode;
    SDL_Keycode sym;
    Uint16 mod;
    uint32_t unused;
} SDL_Keysym;

extern SDL_Window *SDL_GetKeyboardFocus(void);
extern const Uint8 *SDL_GetKeyboardState(int *numkeys);

extern SDL_Keymod SDL_GetModState(void);

extern void SDL_SetModState(SDL_Keymod modstate);

extern SDL_Keycode SDL_GetKeyFromScancode(SDL_Scancode scancode);

extern SDL_Scancode SDL_GetScancodeFromKey(SDL_Keycode key);

extern const char *SDL_GetScancodeName(SDL_Scancode scancode);

extern SDL_Scancode SDL_GetScancodeFromName(const char *name);

extern const char *SDL_GetKeyName(SDL_Keycode key);

extern SDL_Keycode SDL_GetKeyFromName(const char *name);

extern void SDL_StartTextInput(void);

extern SDL_bool SDL_IsTextInputActive(void);

extern void SDL_StopTextInput(void);

extern void SDL_SetTextInputRect(SDL_Rect *rect);

extern SDL_bool SDL_HasScreenKeyboardSupport(void);

extern SDL_bool SDL_IsScreenKeyboardShown(SDL_Window *window);

typedef struct SDL_Cursor SDL_Cursor;

typedef enum
{
    SDL_SYSTEM_CURSOR_ARROW,
    SDL_SYSTEM_CURSOR_IBEAM,
    SDL_SYSTEM_CURSOR_WAIT,
    SDL_SYSTEM_CURSOR_CROSSHAIR,
    SDL_SYSTEM_CURSOR_WAITARROW,
    SDL_SYSTEM_CURSOR_SIZENWSE,
    SDL_SYSTEM_CURSOR_SIZENESW,
    SDL_SYSTEM_CURSOR_SIZEWE,
    SDL_SYSTEM_CURSOR_SIZENS,
    SDL_SYSTEM_CURSOR_SIZEALL,
    SDL_SYSTEM_CURSOR_NO,
    SDL_SYSTEM_CURSOR_HAND,
    SDL_NUM_SYSTEM_CURSORS
} SDL_SystemCursor;

typedef enum
{
    SDL_MOUSEWHEEL_NORMAL,
    SDL_MOUSEWHEEL_FLIPPED
} SDL_MouseWheelDirection;

extern SDL_Window *SDL_GetMouseFocus(void);

extern uint32_t SDL_GetMouseState(int *x, int *y);
extern uint32_t SDL_GetGlobalMouseState(int *x, int *y);

extern uint32_t SDL_GetRelativeMouseState(int *x, int *y);

extern void SDL_WarpMouseInWindow(SDL_Window *window,
                                  int x, int y);

extern int SDL_WarpMouseGlobal(int x, int y);
extern int SDL_SetRelativeMouseMode(SDL_bool enabled);
extern int SDL_CaptureMouse(SDL_bool enabled);

extern SDL_bool SDL_GetRelativeMouseMode(void);
extern SDL_Cursor *SDL_CreateCursor(const Uint8 *data,
                                    const Uint8 *mask,
                                    int w, int h, int hot_x,
                                    int hot_y);

extern SDL_Cursor *SDL_CreateColorCursor(SDL_Surface *surface,
                                         int hot_x,
                                         int hot_y);

extern SDL_Cursor *SDL_CreateSystemCursor(SDL_SystemCursor id);

extern void SDL_SetCursor(SDL_Cursor *cursor);

extern SDL_Cursor *SDL_GetCursor(void);

extern SDL_Cursor *SDL_GetDefaultCursor(void);

extern void SDL_FreeCursor(SDL_Cursor *cursor);

extern int SDL_ShowCursor(int toggle);
#define SDL_BUTTON(X) (1 << ((X)-1))
#define SDL_BUTTON_LEFT 1
#define SDL_BUTTON_MIDDLE 2
#define SDL_BUTTON_RIGHT 3
#define SDL_BUTTON_X1 4
#define SDL_BUTTON_X2 5
#define SDL_BUTTON_LMASK SDL_BUTTON(SDL_BUTTON_LEFT)
#define SDL_BUTTON_MMASK SDL_BUTTON(SDL_BUTTON_MIDDLE)
#define SDL_BUTTON_RMASK SDL_BUTTON(SDL_BUTTON_RIGHT)
#define SDL_BUTTON_X1MASK SDL_BUTTON(SDL_BUTTON_X1)
#define SDL_BUTTON_X2MASK SDL_BUTTON(SDL_BUTTON_X2)

struct _SDL_Joystick;
typedef struct _SDL_Joystick SDL_Joystick;

typedef struct
{
    Uint8 data[16];
} SDL_JoystickGUID;

typedef Sint32 SDL_JoystickID;

typedef enum
{
    SDL_JOYSTICK_TYPE_UNKNOWN,
    SDL_JOYSTICK_TYPE_GAMECONTROLLER,
    SDL_JOYSTICK_TYPE_WHEEL,
    SDL_JOYSTICK_TYPE_ARCADE_STICK,
    SDL_JOYSTICK_TYPE_FLIGHT_STICK,
    SDL_JOYSTICK_TYPE_DANCE_PAD,
    SDL_JOYSTICK_TYPE_GUITAR,
    SDL_JOYSTICK_TYPE_DRUM_KIT,
    SDL_JOYSTICK_TYPE_ARCADE_PAD,
    SDL_JOYSTICK_TYPE_THROTTLE
} SDL_JoystickType;

typedef enum
{
    SDL_JOYSTICK_POWER_UNKNOWN = -1,
    SDL_JOYSTICK_POWER_EMPTY,
    SDL_JOYSTICK_POWER_LOW,
    SDL_JOYSTICK_POWER_MEDIUM,
    SDL_JOYSTICK_POWER_FULL,
    SDL_JOYSTICK_POWER_WIRED,
    SDL_JOYSTICK_POWER_MAX
} SDL_JoystickPowerLevel;

extern void SDL_LockJoysticks(void);
extern void SDL_UnlockJoysticks(void);

extern int SDL_NumJoysticks(void);

extern const char *SDL_JoystickNameForIndex(int device_index);

extern int SDL_JoystickGetDevicePlayerIndex(int device_index);

extern SDL_JoystickGUID SDL_JoystickGetDeviceGUID(int device_index);

extern Uint16 SDL_JoystickGetDeviceVendor(int device_index);

extern Uint16 SDL_JoystickGetDeviceProduct(int device_index);

extern Uint16 SDL_JoystickGetDeviceProductVersion(int device_index);

extern SDL_JoystickType SDL_JoystickGetDeviceType(int device_index);

extern SDL_JoystickID SDL_JoystickGetDeviceInstanceID(int device_index);

extern SDL_Joystick *SDL_JoystickOpen(int device_index);

extern SDL_Joystick *SDL_JoystickFromInstanceID(SDL_JoystickID instance_id);

extern SDL_Joystick *SDL_JoystickFromPlayerIndex(int player_index);

extern const char *SDL_JoystickName(SDL_Joystick *joystick);

extern int SDL_JoystickGetPlayerIndex(SDL_Joystick *joystick);

extern void SDL_JoystickSetPlayerIndex(SDL_Joystick *joystick, int player_index);

extern SDL_JoystickGUID SDL_JoystickGetGUID(SDL_Joystick *joystick);

extern Uint16 SDL_JoystickGetVendor(SDL_Joystick *joystick);

extern Uint16 SDL_JoystickGetProduct(SDL_Joystick *joystick);

extern Uint16 SDL_JoystickGetProductVersion(SDL_Joystick *joystick);

extern SDL_JoystickType SDL_JoystickGetType(SDL_Joystick *joystick);

extern void SDL_JoystickGetGUIDString(SDL_JoystickGUID guid, char *pszGUID, int cbGUID);

extern SDL_JoystickGUID SDL_JoystickGetGUIDFromString(const char *pchGUID);

extern SDL_bool SDL_JoystickGetAttached(SDL_Joystick *joystick);

extern SDL_JoystickID SDL_JoystickInstanceID(SDL_Joystick *joystick);

extern int SDL_JoystickNumAxes(SDL_Joystick *joystick);

extern int SDL_JoystickNumBalls(SDL_Joystick *joystick);

extern int SDL_JoystickNumHats(SDL_Joystick *joystick);

extern int SDL_JoystickNumButtons(SDL_Joystick *joystick);

extern void SDL_JoystickUpdate(void);

extern int SDL_JoystickEventState(int state);
#define SDL_JOYSTICK_AXIS_MAX 32767
#define SDL_JOYSTICK_AXIS_MIN -32768

extern Sint16 SDL_JoystickGetAxis(SDL_Joystick *joystick,
                                  int axis);

extern SDL_bool SDL_JoystickGetAxisInitialState(SDL_Joystick *joystick,
                                                int axis, Sint16 *state);
#define SDL_HAT_CENTERED 0x00
#define SDL_HAT_UP 0x01
#define SDL_HAT_RIGHT 0x02
#define SDL_HAT_DOWN 0x04
#define SDL_HAT_LEFT 0x08
#define SDL_HAT_RIGHTUP (SDL_HAT_RIGHT | SDL_HAT_UP)
#define SDL_HAT_RIGHTDOWN (SDL_HAT_RIGHT | SDL_HAT_DOWN)
#define SDL_HAT_LEFTUP (SDL_HAT_LEFT | SDL_HAT_UP)
#define SDL_HAT_LEFTDOWN (SDL_HAT_LEFT | SDL_HAT_DOWN)
extern Uint8 SDL_JoystickGetHat(SDL_Joystick *joystick,
                                int hat);

extern int SDL_JoystickGetBall(SDL_Joystick *joystick,
                               int ball, int *dx, int *dy);

extern Uint8 SDL_JoystickGetButton(SDL_Joystick *joystick,
                                   int button);

extern int SDL_JoystickRumble(SDL_Joystick *joystick, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, uint32_t duration_ms);

extern void SDL_JoystickClose(SDL_Joystick *joystick);

extern SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel(SDL_Joystick *joystick);
#define SDL_gamecontroller_h_

struct _SDL_GameController;
typedef struct _SDL_GameController SDL_GameController;

typedef enum
{
    SDL_CONTROLLER_TYPE_UNKNOWN = 0,
    SDL_CONTROLLER_TYPE_XBOX360,
    SDL_CONTROLLER_TYPE_XBOXONE,
    SDL_CONTROLLER_TYPE_PS3,
    SDL_CONTROLLER_TYPE_PS4,
    SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO
} SDL_GameControllerType;

typedef enum
{
    SDL_CONTROLLER_BINDTYPE_NONE = 0,
    SDL_CONTROLLER_BINDTYPE_BUTTON,
    SDL_CONTROLLER_BINDTYPE_AXIS,
    SDL_CONTROLLER_BINDTYPE_HAT
} SDL_GameControllerBindType;

typedef struct SDL_GameControllerButtonBind
{
    SDL_GameControllerBindType bindType;
    union
    {
        int button;
        int axis;
        struct
        {
            int hat;
            int hat_mask;
        } hat;
    } value;
} SDL_GameControllerButtonBind;

extern int SDL_GameControllerAddMappingsFromRW(SDL_RWops *rw, int freerw);
#define SDL_GameControllerAddMappingsFromFile(file) SDL_GameControllerAddMappingsFromRW(SDL_RWFromFile(file, "rb"), 1)

extern int SDL_GameControllerAddMapping(const char *mappingString);

extern int SDL_GameControllerNumMappings(void);

extern char *SDL_GameControllerMappingForIndex(int mapping_index);

extern char *SDL_GameControllerMappingForGUID(SDL_JoystickGUID guid);

extern char *SDL_GameControllerMapping(SDL_GameController *gamecontroller);

extern SDL_bool SDL_IsGameController(int joystick_index);

extern const char *SDL_GameControllerNameForIndex(int joystick_index);

extern SDL_GameControllerType SDL_GameControllerTypeForIndex(int joystick_index);

extern char *SDL_GameControllerMappingForDeviceIndex(int joystick_index);

extern SDL_GameController *SDL_GameControllerOpen(int joystick_index);

extern SDL_GameController *SDL_GameControllerFromInstanceID(SDL_JoystickID joyid);

extern SDL_GameController *SDL_GameControllerFromPlayerIndex(int player_index);

extern const char *SDL_GameControllerName(SDL_GameController *gamecontroller);

extern SDL_GameControllerType SDL_GameControllerGetType(SDL_GameController *gamecontroller);

extern int SDL_GameControllerGetPlayerIndex(SDL_GameController *gamecontroller);

extern void SDL_GameControllerSetPlayerIndex(SDL_GameController *gamecontroller, int player_index);

extern Uint16 SDL_GameControllerGetVendor(SDL_GameController *gamecontroller);

extern Uint16 SDL_GameControllerGetProduct(SDL_GameController *gamecontroller);

extern Uint16 SDL_GameControllerGetProductVersion(SDL_GameController *gamecontroller);

extern SDL_bool SDL_GameControllerGetAttached(SDL_GameController *gamecontroller);

extern SDL_Joystick *SDL_GameControllerGetJoystick(SDL_GameController *gamecontroller);

extern int SDL_GameControllerEventState(int state);

extern void SDL_GameControllerUpdate(void);

typedef enum
{
    SDL_CONTROLLER_AXIS_INVALID = -1,
    SDL_CONTROLLER_AXIS_LEFTX,
    SDL_CONTROLLER_AXIS_LEFTY,
    SDL_CONTROLLER_AXIS_RIGHTX,
    SDL_CONTROLLER_AXIS_RIGHTY,
    SDL_CONTROLLER_AXIS_TRIGGERLEFT,
    SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
    SDL_CONTROLLER_AXIS_MAX
} SDL_GameControllerAxis;

extern SDL_GameControllerAxis SDL_GameControllerGetAxisFromString(const char *pchString);

extern const char *SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis axis);

extern SDL_GameControllerButtonBind
SDL_GameControllerGetBindForAxis(SDL_GameController *gamecontroller,
                                 SDL_GameControllerAxis axis);

extern Sint16
SDL_GameControllerGetAxis(SDL_GameController *gamecontroller,
                          SDL_GameControllerAxis axis);

typedef enum
{
    SDL_CONTROLLER_BUTTON_INVALID = -1,
    SDL_CONTROLLER_BUTTON_A,
    SDL_CONTROLLER_BUTTON_B,
    SDL_CONTROLLER_BUTTON_X,
    SDL_CONTROLLER_BUTTON_Y,
    SDL_CONTROLLER_BUTTON_BACK,
    SDL_CONTROLLER_BUTTON_GUIDE,
    SDL_CONTROLLER_BUTTON_START,
    SDL_CONTROLLER_BUTTON_LEFTSTICK,
    SDL_CONTROLLER_BUTTON_RIGHTSTICK,
    SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
    SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
    SDL_CONTROLLER_BUTTON_DPAD_UP,
    SDL_CONTROLLER_BUTTON_DPAD_DOWN,
    SDL_CONTROLLER_BUTTON_DPAD_LEFT,
    SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
    SDL_CONTROLLER_BUTTON_MAX
} SDL_GameControllerButton;

extern SDL_GameControllerButton SDL_GameControllerGetButtonFromString(const char *pchString);

extern const char *SDL_GameControllerGetStringForButton(SDL_GameControllerButton button);

extern SDL_GameControllerButtonBind
SDL_GameControllerGetBindForButton(SDL_GameController *gamecontroller,
                                   SDL_GameControllerButton button);

extern Uint8 SDL_GameControllerGetButton(SDL_GameController *gamecontroller,
                                         SDL_GameControllerButton button);

extern int SDL_GameControllerRumble(SDL_GameController *gamecontroller, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, uint32_t duration_ms);

extern void SDL_GameControllerClose(SDL_GameController *gamecontroller);
#define SDL_QuitRequested() (SDL_PumpEvents(), (SDL_PeepEvents(NULL, 0, SDL_PEEKEVENT, SDL_QUIT, SDL_QUIT) > 0))

typedef Sint64 SDL_TouchID;
typedef Sint64 SDL_FingerID;

typedef enum
{
    SDL_TOUCH_DEVICE_INVALID = -1,
    SDL_TOUCH_DEVICE_DIRECT,
    SDL_TOUCH_DEVICE_INDIRECT_ABSOLUTE,
    SDL_TOUCH_DEVICE_INDIRECT_RELATIVE
} SDL_TouchDeviceType;

typedef struct SDL_Finger
{
    SDL_FingerID id;
    float x;
    float y;
    float pressure;
} SDL_Finger;
#define SDL_TOUCH_MOUSEID ((uint32_t)-1)
#define SDL_MOUSE_TOUCHID ((Sint64)-1)

extern int SDL_GetNumTouchDevices(void);

extern SDL_TouchID SDL_GetTouchDevice(int index);

extern SDL_TouchDeviceType SDL_GetTouchDeviceType(SDL_TouchID touchID);

extern int SDL_GetNumTouchFingers(SDL_TouchID touchID);

extern SDL_Finger *SDL_GetTouchFinger(SDL_TouchID touchID, int index);

typedef Sint64 SDL_GestureID;

extern int SDL_RecordGesture(SDL_TouchID touchId);

extern int SDL_SaveAllDollarTemplates(SDL_RWops *dst);

extern int SDL_SaveDollarTemplate(SDL_GestureID gestureId, SDL_RWops *dst);

extern int SDL_LoadDollarTemplates(SDL_TouchID touchId, SDL_RWops *src);
#define SDL_RELEASED 0
#define SDL_PRESSED 1

typedef enum
{
    SDL_FIRSTEVENT = 0,
    SDL_QUIT = 0x100,
    SDL_APP_TERMINATING,
    SDL_APP_LOWMEMORY,
    SDL_APP_WILLENTERBACKGROUND,
    SDL_APP_DIDENTERBACKGROUND,
    SDL_APP_WILLENTERFOREGROUND,
    SDL_APP_DIDENTERFOREGROUND,
    SDL_DISPLAYEVENT = 0x150,
    SDL_WINDOWEVENT = 0x200,
    SDL_SYSWMEVENT,
    SDL_KEYDOWN = 0x300,
    SDL_KEYUP,
    SDL_TEXTEDITING,
    SDL_TEXTINPUT,
    SDL_KEYMAPCHANGED,
    SDL_MOUSEMOTION = 0x400,
    SDL_MOUSEBUTTONDOWN,
    SDL_MOUSEBUTTONUP,
    SDL_MOUSEWHEEL,
    SDL_JOYAXISMOTION = 0x600,
    SDL_JOYBALLMOTION,
    SDL_JOYHATMOTION,
    SDL_JOYBUTTONDOWN,
    SDL_JOYBUTTONUP,
    SDL_JOYDEVICEADDED,
    SDL_JOYDEVICEREMOVED,
    SDL_CONTROLLERAXISMOTION = 0x650,
    SDL_CONTROLLERBUTTONDOWN,
    SDL_CONTROLLERBUTTONUP,
    SDL_CONTROLLERDEVICEADDED,
    SDL_CONTROLLERDEVICEREMOVED,
    SDL_CONTROLLERDEVICEREMAPPED,
    SDL_FINGERDOWN = 0x700,
    SDL_FINGERUP,
    SDL_FINGERMOTION,
    SDL_DOLLARGESTURE = 0x800,
    SDL_DOLLARRECORD,
    SDL_MULTIGESTURE,
    SDL_CLIPBOARDUPDATE = 0x900,
    SDL_DROPFILE = 0x1000,
    SDL_DROPTEXT,
    SDL_DROPBEGIN,
    SDL_DROPCOMPLETE,
    SDL_AUDIODEVICEADDED = 0x1100,
    SDL_AUDIODEVICEREMOVED,
    SDL_SENSORUPDATE = 0x1200,
    SDL_RENDER_TARGETS_RESET = 0x2000,
    SDL_RENDER_DEVICE_RESET,
    SDL_USEREVENT = 0x8000,
    SDL_LASTEVENT = 0xFFFF
} SDL_EventType;

typedef struct SDL_CommonEvent
{
    uint32_t type;
    uint32_t timestamp;
} SDL_CommonEvent;

typedef struct SDL_DisplayEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t display;
    Uint8 event;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint32 data1;
} SDL_DisplayEvent;

typedef struct SDL_WindowEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    Uint8 event;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint32 data1;
    Sint32 data2;
} SDL_WindowEvent;

typedef struct SDL_KeyboardEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    Uint8 state;
    Uint8 repeat;
    Uint8 padding2;
    Uint8 padding3;
    SDL_Keysym keysym;
} SDL_KeyboardEvent;
#define SDL_TEXTEDITINGEVENT_TEXT_SIZE (32)

typedef struct SDL_TextEditingEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    char text[(32)];
    Sint32 start;
    Sint32 length;
} SDL_TextEditingEvent;
#define SDL_TEXTINPUTEVENT_TEXT_SIZE (32)

typedef struct SDL_TextInputEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    char text[(32)];
} SDL_TextInputEvent;

typedef struct SDL_MouseMotionEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    uint32_t which;
    uint32_t state;
    Sint32 x;
    Sint32 y;
    Sint32 xrel;
    Sint32 yrel;
} SDL_MouseMotionEvent;

typedef struct SDL_MouseButtonEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    uint32_t which;
    Uint8 button;
    Uint8 state;
    Uint8 clicks;
    Uint8 padding1;
    Sint32 x;
    Sint32 y;
} SDL_MouseButtonEvent;

typedef struct SDL_MouseWheelEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    uint32_t which;
    Sint32 x;
    Sint32 y;
    uint32_t direction;
} SDL_MouseWheelEvent;

typedef struct SDL_JoyAxisEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_JoystickID which;
    Uint8 axis;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint16 value;
    Uint16 padding4;
} SDL_JoyAxisEvent;

typedef struct SDL_JoyBallEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_JoystickID which;
    Uint8 ball;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint16 xrel;
    Sint16 yrel;
} SDL_JoyBallEvent;

typedef struct SDL_JoyHatEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_JoystickID which;
    Uint8 hat;
    Uint8 value;
    Uint8 padding1;
    Uint8 padding2;
} SDL_JoyHatEvent;

typedef struct SDL_JoyButtonEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_JoystickID which;
    Uint8 button;
    Uint8 state;
    Uint8 padding1;
    Uint8 padding2;
} SDL_JoyButtonEvent;

typedef struct SDL_JoyDeviceEvent
{
    uint32_t type;
    uint32_t timestamp;
    Sint32 which;
} SDL_JoyDeviceEvent;

typedef struct SDL_ControllerAxisEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_JoystickID which;
    Uint8 axis;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint16 value;
    Uint16 padding4;
} SDL_ControllerAxisEvent;

typedef struct SDL_ControllerButtonEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_JoystickID which;
    Uint8 button;
    Uint8 state;
    Uint8 padding1;
    Uint8 padding2;
} SDL_ControllerButtonEvent;

typedef struct SDL_ControllerDeviceEvent
{
    uint32_t type;
    uint32_t timestamp;
    Sint32 which;
} SDL_ControllerDeviceEvent;

typedef struct SDL_AudioDeviceEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t which;
    Uint8 iscapture;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
} SDL_AudioDeviceEvent;

typedef struct SDL_TouchFingerEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_TouchID touchId;
    SDL_FingerID fingerId;
    float x;
    float y;
    float dx;
    float dy;
    float pressure;
    uint32_t windowID;
} SDL_TouchFingerEvent;

typedef struct SDL_MultiGestureEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_TouchID touchId;
    float dTheta;
    float dDist;
    float x;
    float y;
    Uint16 numFingers;
    Uint16 padding;
} SDL_MultiGestureEvent;

typedef struct SDL_DollarGestureEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_TouchID touchId;
    SDL_GestureID gestureId;
    uint32_t numFingers;
    float error;
    float x;
    float y;
} SDL_DollarGestureEvent;

typedef struct SDL_DropEvent
{
    uint32_t type;
    uint32_t timestamp;
    char *file;
    uint32_t windowID;
} SDL_DropEvent;

typedef struct SDL_SensorEvent
{
    uint32_t type;
    uint32_t timestamp;
    Sint32 which;
    float data[6];
} SDL_SensorEvent;

typedef struct SDL_QuitEvent
{
    uint32_t type;
    uint32_t timestamp;
} SDL_QuitEvent;

typedef struct SDL_OSEvent
{
    uint32_t type;
    uint32_t timestamp;
} SDL_OSEvent;

typedef struct SDL_UserEvent
{
    uint32_t type;
    uint32_t timestamp;
    uint32_t windowID;
    Sint32 code;
    void *data1;
    void *data2;
} SDL_UserEvent;

struct SDL_SysWMmsg;
typedef struct SDL_SysWMmsg SDL_SysWMmsg;

typedef struct SDL_SysWMEvent
{
    uint32_t type;
    uint32_t timestamp;
    SDL_SysWMmsg *msg;
} SDL_SysWMEvent;

typedef union SDL_Event
{
    uint32_t type;
    SDL_CommonEvent common;
    SDL_DisplayEvent display;
    SDL_WindowEvent window;
    SDL_KeyboardEvent key;
    SDL_TextEditingEvent edit;
    SDL_TextInputEvent text;
    SDL_MouseMotionEvent motion;
    SDL_MouseButtonEvent button;
    SDL_MouseWheelEvent wheel;
    SDL_JoyAxisEvent jaxis;
    SDL_JoyBallEvent jball;
    SDL_JoyHatEvent jhat;
    SDL_JoyButtonEvent jbutton;
    SDL_JoyDeviceEvent jdevice;
    SDL_ControllerAxisEvent caxis;
    SDL_ControllerButtonEvent cbutton;
    SDL_ControllerDeviceEvent cdevice;
    SDL_AudioDeviceEvent adevice;
    SDL_SensorEvent sensor;
    SDL_QuitEvent quit;
    SDL_UserEvent user;
    SDL_SysWMEvent syswm;
    SDL_TouchFingerEvent tfinger;
    SDL_MultiGestureEvent mgesture;
    SDL_DollarGestureEvent dgesture;
    SDL_DropEvent drop;
    Uint8 padding[56];
} SDL_Event;

typedef int SDL_compile_time_assert_SDL_Event[(sizeof(SDL_Event) == 56) * 2 - 1];

extern void SDL_PumpEvents(void);

typedef enum
{
    SDL_ADDEVENT,
    SDL_PEEKEVENT,
    SDL_GETEVENT
} SDL_eventaction;
extern int SDL_PeepEvents(SDL_Event *events, int numevents,
                          SDL_eventaction action,
                          uint32_t minType, uint32_t maxType);

extern SDL_bool SDL_HasEvent(uint32_t type);
extern SDL_bool SDL_HasEvents(uint32_t minType, uint32_t maxType);

extern void SDL_FlushEvent(uint32_t type);
extern void SDL_FlushEvents(uint32_t minType, uint32_t maxType);

extern int SDL_PollEvent(SDL_Event *event);

extern int SDL_WaitEvent(SDL_Event *event);

extern int SDL_WaitEventTimeout(SDL_Event *event,
                                int timeout);

extern int SDL_PushEvent(SDL_Event *event);

typedef int (*SDL_EventFilter)(void *userdata, SDL_Event *event);
extern void SDL_SetEventFilter(SDL_EventFilter filter,
                               void *userdata);

extern SDL_bool SDL_GetEventFilter(SDL_EventFilter *filter,
                                   void **userdata);

extern void SDL_AddEventWatch(SDL_EventFilter filter,
                              void *userdata);

extern void SDL_DelEventWatch(SDL_EventFilter filter,
                              void *userdata);

extern void SDL_FilterEvents(SDL_EventFilter filter,
                             void *userdata);
#define SDL_QUERY -1
#define SDL_IGNORE 0
#define SDL_DISABLE 0
#define SDL_ENABLE 1

extern Uint8 SDL_EventState(uint32_t type, int state);
#define SDL_GetEventState(type) SDL_EventState(type, SDL_QUERY)

extern uint32_t SDL_RegisterEvents(int numevents);

extern char *SDL_GetBasePath(void);
extern char *SDL_GetPrefPath(const char *org, const char *app);

struct _SDL_Haptic;
typedef struct _SDL_Haptic SDL_Haptic;
#define SDL_HAPTIC_CONSTANT (1u << 0)
#define SDL_HAPTIC_SINE (1u << 1)
#define SDL_HAPTIC_LEFTRIGHT (1u << 2)
#define SDL_HAPTIC_TRIANGLE (1u << 3)
#define SDL_HAPTIC_SAWTOOTHUP (1u << 4)
#define SDL_HAPTIC_SAWTOOTHDOWN (1u << 5)
#define SDL_HAPTIC_RAMP (1u << 6)
#define SDL_HAPTIC_SPRING (1u << 7)
#define SDL_HAPTIC_DAMPER (1u << 8)
#define SDL_HAPTIC_INERTIA (1u << 9)
#define SDL_HAPTIC_FRICTION (1u << 10)
#define SDL_HAPTIC_CUSTOM (1u << 11)
#define SDL_HAPTIC_GAIN (1u << 12)
#define SDL_HAPTIC_AUTOCENTER (1u << 13)
#define SDL_HAPTIC_STATUS (1u << 14)
#define SDL_HAPTIC_PAUSE (1u << 15)
#define SDL_HAPTIC_POLAR 0
#define SDL_HAPTIC_CARTESIAN 1
#define SDL_HAPTIC_SPHERICAL 2
#define SDL_HAPTIC_INFINITY 4294967295U

typedef struct SDL_HapticDirection
{
    Uint8 type;
    Sint32 dir[3];
} SDL_HapticDirection;

typedef struct SDL_HapticConstant
{
    Uint16 type;
    SDL_HapticDirection direction;
    uint32_t length;
    Uint16 delay;
    Uint16 button;
    Uint16 interval;
    Sint16 level;
    Uint16 attack_length;
    Uint16 attack_level;
    Uint16 fade_length;
    Uint16 fade_level;
} SDL_HapticConstant;

typedef struct SDL_HapticPeriodic
{
    Uint16 type;
    SDL_HapticDirection direction;
    uint32_t length;
    Uint16 delay;
    Uint16 button;
    Uint16 interval;
    Uint16 period;
    Sint16 magnitude;
    Sint16 offset;
    Uint16 phase;
    Uint16 attack_length;
    Uint16 attack_level;
    Uint16 fade_length;
    Uint16 fade_level;
} SDL_HapticPeriodic;
typedef struct SDL_HapticCondition
{
    Uint16 type;
    SDL_HapticDirection direction;
    uint32_t length;
    Uint16 delay;
    Uint16 button;
    Uint16 interval;
    Uint16 right_sat[3];
    Uint16 left_sat[3];
    Sint16 right_coeff[3];
    Sint16 left_coeff[3];
    Uint16 deadband[3];
    Sint16 center[3];
} SDL_HapticCondition;
typedef struct SDL_HapticRamp
{
    Uint16 type;
    SDL_HapticDirection direction;
    uint32_t length;
    Uint16 delay;
    Uint16 button;
    Uint16 interval;
    Sint16 start;
    Sint16 end;
    Uint16 attack_length;
    Uint16 attack_level;
    Uint16 fade_length;
    Uint16 fade_level;
} SDL_HapticRamp;
typedef struct SDL_HapticLeftRight
{
    Uint16 type;
    uint32_t length;
    Uint16 large_magnitude;
    Uint16 small_magnitude;
} SDL_HapticLeftRight;
typedef struct SDL_HapticCustom
{
    Uint16 type;
    SDL_HapticDirection direction;
    uint32_t length;
    Uint16 delay;
    Uint16 button;
    Uint16 interval;
    Uint8 channels;
    Uint16 period;
    Uint16 samples;
    Uint16 *data;
    Uint16 attack_length;
    Uint16 attack_level;
    Uint16 fade_length;
    Uint16 fade_level;
} SDL_HapticCustom;

typedef union SDL_HapticEffect
{
    Uint16 type;
    SDL_HapticConstant constant;
    SDL_HapticPeriodic periodic;
    SDL_HapticCondition condition;
    SDL_HapticRamp ramp;
    SDL_HapticLeftRight leftright;
    SDL_HapticCustom custom;
} SDL_HapticEffect;

extern int SDL_NumHaptics(void);

extern const char *SDL_HapticName(int device_index);
extern SDL_Haptic *SDL_HapticOpen(int device_index);

extern int SDL_HapticOpened(int device_index);

extern int SDL_HapticIndex(SDL_Haptic *haptic);

extern int SDL_MouseIsHaptic(void);

extern SDL_Haptic *SDL_HapticOpenFromMouse(void);

extern int SDL_JoystickIsHaptic(SDL_Joystick *joystick);
extern SDL_Haptic *SDL_HapticOpenFromJoystick(SDL_Joystick *
                                                  joystick);

extern void SDL_HapticClose(SDL_Haptic *haptic);
extern int SDL_HapticNumEffects(SDL_Haptic *haptic);
extern int SDL_HapticNumEffectsPlaying(SDL_Haptic *haptic);
extern unsigned int SDL_HapticQuery(SDL_Haptic *haptic);

extern int SDL_HapticNumAxes(SDL_Haptic *haptic);

extern int SDL_HapticEffectSupported(SDL_Haptic *haptic,
                                     SDL_HapticEffect *
                                         effect);

extern int SDL_HapticNewEffect(SDL_Haptic *haptic,
                               SDL_HapticEffect *effect);
extern int SDL_HapticUpdateEffect(SDL_Haptic *haptic,
                                  int effect,
                                  SDL_HapticEffect *data);
extern int SDL_HapticRunEffect(SDL_Haptic *haptic,
                               int effect,
                               uint32_t iterations);

extern int SDL_HapticStopEffect(SDL_Haptic *haptic,
                                int effect);

extern void SDL_HapticDestroyEffect(SDL_Haptic *haptic,
                                    int effect);
extern int SDL_HapticGetEffectStatus(SDL_Haptic *haptic,
                                     int effect);
extern int SDL_HapticSetGain(SDL_Haptic *haptic, int gain);
extern int SDL_HapticSetAutocenter(SDL_Haptic *haptic,
                                   int autocenter);
extern int SDL_HapticPause(SDL_Haptic *haptic);

extern int SDL_HapticUnpause(SDL_Haptic *haptic);

extern int SDL_HapticStopAll(SDL_Haptic *haptic);

extern int SDL_HapticRumbleSupported(SDL_Haptic *haptic);

extern int SDL_HapticRumbleInit(SDL_Haptic *haptic);
extern int SDL_HapticRumblePlay(SDL_Haptic *haptic, float strength, uint32_t length);

extern int SDL_HapticRumbleStop(SDL_Haptic *haptic);
#define SDL_HINT_FRAMEBUFFER_ACCELERATION "SDL_FRAMEBUFFER_ACCELERATION"
#define SDL_HINT_RENDER_DRIVER "SDL_RENDER_DRIVER"
#define SDL_HINT_RENDER_OPENGL_SHADERS "SDL_RENDER_OPENGL_SHADERS"
#define SDL_HINT_RENDER_DIRECT3D_THREADSAFE "SDL_RENDER_DIRECT3D_THREADSAFE"
#define SDL_HINT_RENDER_DIRECT3D11_DEBUG "SDL_RENDER_DIRECT3D11_DEBUG"
#define SDL_HINT_RENDER_LOGICAL_SIZE_MODE "SDL_RENDER_LOGICAL_SIZE_MODE"
#define SDL_HINT_RENDER_SCALE_QUALITY "SDL_RENDER_SCALE_QUALITY"
#define SDL_HINT_RENDER_VSYNC "SDL_RENDER_VSYNC"
#define SDL_HINT_VIDEO_ALLOW_SCREENSAVER "SDL_VIDEO_ALLOW_SCREENSAVER"
#define SDL_HINT_VIDEO_EXTERNAL_CONTEXT "SDL_VIDEO_EXTERNAL_CONTEXT"
#define SDL_HINT_VIDEO_X11_XVIDMODE "SDL_VIDEO_X11_XVIDMODE"
#define SDL_HINT_VIDEO_X11_XINERAMA "SDL_VIDEO_X11_XINERAMA"
#define SDL_HINT_VIDEO_X11_XRANDR "SDL_VIDEO_X11_XRANDR"
#define SDL_HINT_VIDEO_X11_WINDOW_VISUALID "SDL_VIDEO_X11_WINDOW_VISUALID"
#define SDL_HINT_VIDEO_X11_NET_WM_PING "SDL_VIDEO_X11_NET_WM_PING"
#define SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR "SDL_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR"
#define SDL_HINT_VIDEO_X11_FORCE_EGL "SDL_VIDEO_X11_FORCE_EGL"
#define SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN "SDL_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN"
#define SDL_HINT_WINDOWS_INTRESOURCE_ICON "SDL_WINDOWS_INTRESOURCE_ICON"
#define SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL "SDL_WINDOWS_INTRESOURCE_ICON_SMALL"
#define SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP "SDL_WINDOWS_ENABLE_MESSAGELOOP"
#define SDL_HINT_GRAB_KEYBOARD "SDL_GRAB_KEYBOARD"
#define SDL_HINT_MOUSE_DOUBLE_CLICK_TIME "SDL_MOUSE_DOUBLE_CLICK_TIME"
#define SDL_HINT_MOUSE_DOUBLE_CLICK_RADIUS "SDL_MOUSE_DOUBLE_CLICK_RADIUS"
#define SDL_HINT_MOUSE_NORMAL_SPEED_SCALE "SDL_MOUSE_NORMAL_SPEED_SCALE"
#define SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE "SDL_MOUSE_RELATIVE_SPEED_SCALE"
#define SDL_HINT_MOUSE_RELATIVE_MODE_WARP "SDL_MOUSE_RELATIVE_MODE_WARP"
#define SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH "SDL_MOUSE_FOCUS_CLICKTHROUGH"
#define SDL_HINT_TOUCH_MOUSE_EVENTS "SDL_TOUCH_MOUSE_EVENTS"
#define SDL_HINT_MOUSE_TOUCH_EVENTS "SDL_MOUSE_TOUCH_EVENTS"
#define SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS "SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS"
#define SDL_HINT_IDLE_TIMER_DISABLED "SDL_IOS_IDLE_TIMER_DISABLED"
#define SDL_HINT_ORIENTATIONS "SDL_IOS_ORIENTATIONS"
#define SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS "SDL_APPLE_TV_CONTROLLER_UI_EVENTS"
#define SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION "SDL_APPLE_TV_REMOTE_ALLOW_ROTATION"
#define SDL_HINT_IOS_HIDE_HOME_INDICATOR "SDL_IOS_HIDE_HOME_INDICATOR"
#define SDL_HINT_ACCELEROMETER_AS_JOYSTICK "SDL_ACCELEROMETER_AS_JOYSTICK"
#define SDL_HINT_TV_REMOTE_AS_JOYSTICK "SDL_TV_REMOTE_AS_JOYSTICK"
#define SDL_HINT_XINPUT_ENABLED "SDL_XINPUT_ENABLED"
#define SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING "SDL_XINPUT_USE_OLD_JOYSTICK_MAPPING"
#define SDL_HINT_GAMECONTROLLERTYPE "SDL_GAMECONTROLLERTYPE"
#define SDL_HINT_GAMECONTROLLERCONFIG "SDL_GAMECONTROLLERCONFIG"
#define SDL_HINT_GAMECONTROLLERCONFIG_FILE "SDL_GAMECONTROLLERCONFIG_FILE"
#define SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES "SDL_GAMECONTROLLER_IGNORE_DEVICES"
#define SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT "SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT"
#define SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS "SDL_GAMECONTROLLER_USE_BUTTON_LABELS"
#define SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS "SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS"
#define SDL_HINT_JOYSTICK_HIDAPI "SDL_JOYSTICK_HIDAPI"
#define SDL_HINT_JOYSTICK_HIDAPI_PS4 "SDL_JOYSTICK_HIDAPI_PS4"
#define SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE "SDL_JOYSTICK_HIDAPI_PS4_RUMBLE"
#define SDL_HINT_JOYSTICK_HIDAPI_STEAM "SDL_JOYSTICK_HIDAPI_STEAM"
#define SDL_HINT_JOYSTICK_HIDAPI_SWITCH "SDL_JOYSTICK_HIDAPI_SWITCH"
#define SDL_HINT_JOYSTICK_HIDAPI_XBOX "SDL_JOYSTICK_HIDAPI_XBOX"
#define SDL_HINT_JOYSTICK_HIDAPI_GAMECUBE "SDL_JOYSTICK_HIDAPI_GAMECUBE"
#define SDL_HINT_ENABLE_STEAM_CONTROLLERS "SDL_ENABLE_STEAM_CONTROLLERS"
#define SDL_HINT_ALLOW_TOPMOST "SDL_ALLOW_TOPMOST"
#define SDL_HINT_TIMER_RESOLUTION "SDL_TIMER_RESOLUTION"
#define SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION "SDL_QTWAYLAND_CONTENT_ORIENTATION"
#define SDL_HINT_QTWAYLAND_WINDOW_FLAGS "SDL_QTWAYLAND_WINDOW_FLAGS"
#define SDL_HINT_THREAD_STACK_SIZE "SDL_THREAD_STACK_SIZE"
#define SDL_HINT_VIDEO_HIGHDPI_DISABLED "SDL_VIDEO_HIGHDPI_DISABLED"
#define SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK "SDL_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK"
#define SDL_HINT_VIDEO_WIN_D3DCOMPILER "SDL_VIDEO_WIN_D3DCOMPILER"
#define SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT "SDL_VIDEO_WINDOW_SHARE_PIXEL_FORMAT"
#define SDL_HINT_WINRT_PRIVACY_POLICY_URL "SDL_WINRT_PRIVACY_POLICY_URL"
#define SDL_HINT_WINRT_PRIVACY_POLICY_LABEL "SDL_WINRT_PRIVACY_POLICY_LABEL"
#define SDL_HINT_WINRT_HANDLE_BACK_BUTTON "SDL_WINRT_HANDLE_BACK_BUTTON"
#define SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES "SDL_VIDEO_MAC_FULLSCREEN_SPACES"
#define SDL_HINT_MAC_BACKGROUND_APP "SDL_MAC_BACKGROUND_APP"
#define SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION "SDL_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION"
#define SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION "SDL_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION"
#define SDL_HINT_IME_INTERNAL_EDITING "SDL_IME_INTERNAL_EDITING"
#define SDL_HINT_ANDROID_TRAP_BACK_BUTTON "SDL_ANDROID_TRAP_BACK_BUTTON"
#define SDL_HINT_ANDROID_BLOCK_ON_PAUSE "SDL_ANDROID_BLOCK_ON_PAUSE"
#define SDL_HINT_RETURN_KEY_HIDES_IME "SDL_RETURN_KEY_HIDES_IME"
#define SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT "SDL_EMSCRIPTEN_KEYBOARD_ELEMENT"
#define SDL_HINT_NO_SIGNAL_HANDLERS "SDL_NO_SIGNAL_HANDLERS"
#define SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4 "SDL_WINDOWS_NO_CLOSE_ON_ALT_F4"
#define SDL_HINT_BMP_SAVE_LEGACY_FORMAT "SDL_BMP_SAVE_LEGACY_FORMAT"
#define SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING "SDL_WINDOWS_DISABLE_THREAD_NAMING"
#define SDL_HINT_RPI_VIDEO_LAYER "SDL_RPI_VIDEO_LAYER"
#define SDL_HINT_VIDEO_DOUBLE_BUFFER "SDL_VIDEO_DOUBLE_BUFFER"
#define SDL_HINT_OPENGL_ES_DRIVER "SDL_OPENGL_ES_DRIVER"
#define SDL_HINT_AUDIO_RESAMPLING_MODE "SDL_AUDIO_RESAMPLING_MODE"
#define SDL_HINT_AUDIO_CATEGORY "SDL_AUDIO_CATEGORY"
#define SDL_HINT_RENDER_BATCHING "SDL_RENDER_BATCHING"
#define SDL_HINT_EVENT_LOGGING "SDL_EVENT_LOGGING"
#define SDL_HINT_WAVE_RIFF_CHUNK_SIZE "SDL_WAVE_RIFF_CHUNK_SIZE"
#define SDL_HINT_WAVE_TRUNCATION "SDL_WAVE_TRUNCATION"
#define SDL_HINT_WAVE_FACT_CHUNK "SDL_WAVE_FACT_CHUNK"
#define SDL_HINT_DISPLAY_USABLE_BOUNDS "SDL_DISPLAY_USABLE_BOUNDS"
#define SDL_STANDARD_GRAVITY 9.80665f
#define SDL_NONSHAPEABLE_WINDOW -1
#define SDL_INVALID_SHAPE_ARGUMENT -2
#define SDL_WINDOW_LACKS_SHAPE -3
#define SDL_SHAPEMODEALPHA(mode) (mode == ShapeModeDefault || mode == ShapeModeBinarizeAlpha || mode == ShapeModeReverseBinarizeAlpha)
#define SDL_TICKS_PASSED(A, B) ((Sint32)((B) - (A)) <= 0)
#define SDL_MAJOR_VERSION 2
#define SDL_MINOR_VERSION 0
#define SDL_PATCHLEVEL 12
#define SDL_VERSION(x)                  \
    {                                   \
        (x)->major = SDL_MAJOR_VERSION; \
        (x)->minor = SDL_MINOR_VERSION; \
        (x)->patch = SDL_PATCHLEVEL;    \
    }
#define SDL_VERSIONNUM(X, Y, Z) ((X)*1000 + (Y)*100 + (Z))
#define SDL_COMPILEDVERSION SDL_VERSIONNUM(SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL)
#define SDL_VERSION_ATLEAST(X, Y, Z) (SDL_COMPILEDVERSION >= SDL_VERSIONNUM(X, Y, Z))

#define SDL_INIT_TIMER 0x00000001u
#define SDL_INIT_AUDIO 0x00000010u
#define SDL_INIT_VIDEO 0x00000020u
#define SDL_INIT_JOYSTICK 0x00000200u
#define SDL_INIT_HAPTIC 0x00001000u
#define SDL_INIT_GAMECONTROLLER 0x00002000u
#define SDL_INIT_EVENTS 0x00004000u
#define SDL_INIT_SENSOR 0x00008000u
#define SDL_INIT_NOPARACHUTE 0x00100000u
#define SDL_INIT_EVERYTHING (SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR)
#define HAS_ARG 0x0001
#define OPT_BOOL 0x0002
#define OPT_EXPERT 0x0004
#define OPT_STRING 0x0008
#define OPT_VIDEO 0x0010
#define OPT_AUDIO 0x0020
#define OPT_INT 0x0080
#define OPT_FLOAT 0x0100
#define OPT_SUBTITLE 0x0200
#define OPT_INT64 0x0400
#define OPT_EXIT 0x0800
#define OPT_DATA 0x1000
#define OPT_PERFILE 0x2000
#define OPT_OFFSET 0x4000
#define OPT_SPEC 0x8000
#define OPT_TIME 0x10000
#define OPT_DOUBLE 0x20000
#define OPT_INPUT 0x40000
#define OPT_OUTPUT 0x80000
typedef enum
{
    SDL_HINT_DEFAULT,
    SDL_HINT_NORMAL,
    SDL_HINT_OVERRIDE
} SDL_HintPriority;

extern SDL_bool SDL_SetHintWithPriority(const char *name,
                                        const char *value,
                                        SDL_HintPriority priority);

extern SDL_bool SDL_SetHint(const char *name,
                            const char *value);

extern const char *SDL_GetHint(const char *name);

extern SDL_bool SDL_GetHintBoolean(const char *name, SDL_bool default_value);

typedef void (*SDL_HintCallback)(void *userdata, const char *name, const char *oldValue, const char *newValue);

extern void SDL_AddHintCallback(const char *name,
                                SDL_HintCallback callback,
                                void *userdata);

extern void SDL_DelHintCallback(const char *name,
                                SDL_HintCallback callback,
                                void *userdata);

extern void SDL_ClearHints(void);

extern void *SDL_LoadObject(const char *sofile);

extern void *SDL_LoadFunction(void *handle,
                              const char *name);

extern void SDL_UnloadObject(void *handle);
#define SDL_MAX_LOG_MESSAGE 4096

typedef enum
{
    SDL_LOG_CATEGORY_APPLICATION,
    SDL_LOG_CATEGORY_ERROR,
    SDL_LOG_CATEGORY_ASSERT,
    SDL_LOG_CATEGORY_SYSTEM,
    SDL_LOG_CATEGORY_AUDIO,
    SDL_LOG_CATEGORY_VIDEO,
    SDL_LOG_CATEGORY_RENDER,
    SDL_LOG_CATEGORY_INPUT,
    SDL_LOG_CATEGORY_TEST,
    SDL_LOG_CATEGORY_RESERVED1,
    SDL_LOG_CATEGORY_RESERVED2,
    SDL_LOG_CATEGORY_RESERVED3,
    SDL_LOG_CATEGORY_RESERVED4,
    SDL_LOG_CATEGORY_RESERVED5,
    SDL_LOG_CATEGORY_RESERVED6,
    SDL_LOG_CATEGORY_RESERVED7,
    SDL_LOG_CATEGORY_RESERVED8,
    SDL_LOG_CATEGORY_RESERVED9,
    SDL_LOG_CATEGORY_RESERVED10,
    SDL_LOG_CATEGORY_CUSTOM
} SDL_LogCategory;

typedef enum
{
    SDL_LOG_PRIORITY_VERBOSE = 1,
    SDL_LOG_PRIORITY_DEBUG,
    SDL_LOG_PRIORITY_INFO,
    SDL_LOG_PRIORITY_WARN,
    SDL_LOG_PRIORITY_ERROR,
    SDL_LOG_PRIORITY_CRITICAL,
    SDL_NUM_LOG_PRIORITIES
} SDL_LogPriority;

extern void SDL_LogSetAllPriority(SDL_LogPriority priority);

extern void SDL_LogSetPriority(int category,
                               SDL_LogPriority priority);

extern SDL_LogPriority SDL_LogGetPriority(int category);

extern void SDL_LogResetPriorities(void);

extern void SDL_Log(const char *fmt, ...);

extern void SDL_LogVerbose(int category, const char *fmt, ...);

extern void SDL_LogDebug(int category, const char *fmt, ...);

extern void SDL_LogInfo(int category, const char *fmt, ...);

extern void SDL_LogWarn(int category, const char *fmt, ...);

extern void SDL_LogError(int category, const char *fmt, ...);

extern void SDL_LogCritical(int category, const char *fmt, ...);

extern void SDL_LogMessage(int category,
                           SDL_LogPriority priority,
                           const char *fmt, ...);

extern void SDL_LogMessageV(int category,
                            SDL_LogPriority priority,
                            const char *fmt, va_list ap);

typedef void (*SDL_LogOutputFunction)(void *userdata, int category, SDL_LogPriority priority, const char *message);

extern void SDL_LogGetOutputFunction(SDL_LogOutputFunction *callback, void **userdata);

extern void SDL_LogSetOutputFunction(SDL_LogOutputFunction callback, void *userdata);

typedef enum
{
    SDL_MESSAGEBOX_ERROR = 0x00000010,
    SDL_MESSAGEBOX_WARNING = 0x00000020,
    SDL_MESSAGEBOX_INFORMATION = 0x00000040,
    SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT = 0x00000080,
    SDL_MESSAGEBOX_BUTTONS_RIGHT_TO_LEFT = 0x00000100
} SDL_MessageBoxFlags;

typedef enum
{
    SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT = 0x00000001,
    SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT = 0x00000002
} SDL_MessageBoxButtonFlags;

typedef struct
{
    uint32_t flags;
    int buttonid;
    const char *text;
} SDL_MessageBoxButtonData;

typedef struct
{
    Uint8 r, g, b;
} SDL_MessageBoxColor;

typedef enum
{
    SDL_MESSAGEBOX_COLOR_BACKGROUND,
    SDL_MESSAGEBOX_COLOR_TEXT,
    SDL_MESSAGEBOX_COLOR_BUTTON_BORDER,
    SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND,
    SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED,
    SDL_MESSAGEBOX_COLOR_MAX
} SDL_MessageBoxColorType;

typedef struct
{
    SDL_MessageBoxColor colors[SDL_MESSAGEBOX_COLOR_MAX];
} SDL_MessageBoxColorScheme;

typedef struct
{
    uint32_t flags;
    SDL_Window *window;
    const char *title;
    const char *message;
    int numbuttons;
    const SDL_MessageBoxButtonData *buttons;
    const SDL_MessageBoxColorScheme *colorScheme;
} SDL_MessageBoxData;
extern int SDL_ShowMessageBox(const SDL_MessageBoxData *messageboxdata, int *buttonid);
extern int SDL_ShowSimpleMessageBox(uint32_t flags, const char *title, const char *message, SDL_Window *window);

typedef void *SDL_MetalView;

extern SDL_MetalView SDL_Metal_CreateView(SDL_Window *window);

extern void SDL_Metal_DestroyView(SDL_MetalView view);

struct SDL_Renderer;
typedef struct SDL_Renderer SDL_Renderer;



extern int SDL_GetNumRenderDrivers(void);

extern int SDL_GetRenderDriverInfo(int index,
                                   SDL_RendererInfo *info);

extern int SDL_CreateWindowAndRenderer(
    int width, int height, uint32_t window_flags,
    SDL_Window **window, SDL_Renderer **renderer);

extern SDL_Renderer *SDL_CreateRenderer(SDL_Window *window,
                                        int index, uint32_t flags);

extern SDL_Renderer *SDL_CreateSoftwareRenderer(SDL_Surface *surface);

extern SDL_Renderer *SDL_GetRenderer(SDL_Window *window);

extern int SDL_GetRendererInfo(SDL_Renderer *renderer,
                               SDL_RendererInfo *info);

extern int SDL_GetRendererOutputSize(SDL_Renderer *renderer,
                                     int *w, int *h);

extern SDL_Texture *SDL_CreateTexture(SDL_Renderer *renderer,
                                      uint32_t format,
                                      int access, int w,
                                      int h);

extern SDL_Texture *SDL_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);

extern int SDL_QueryTexture(SDL_Texture *texture,
                            uint32_t *format, int *access,
                            int *w, int *h);
extern int SDL_SetTextureColorMod(SDL_Texture *texture,
                                  Uint8 r, Uint8 g, Uint8 b);
extern int SDL_GetTextureColorMod(SDL_Texture *texture,
                                  Uint8 *r, Uint8 *g,
                                  Uint8 *b);

extern int SDL_SetTextureAlphaMod(SDL_Texture *texture,
                                  Uint8 alpha);

extern int SDL_GetTextureAlphaMod(SDL_Texture *texture,
                                  Uint8 *alpha);
extern int SDL_SetTextureBlendMode(SDL_Texture *texture,
                                   SDL_BlendMode blendMode);

extern int SDL_GetTextureBlendMode(SDL_Texture *texture,
                                   SDL_BlendMode *blendMode);
extern int SDL_SetTextureScaleMode(SDL_Texture *texture,
                                   SDL_ScaleMode scaleMode);

extern int SDL_GetTextureScaleMode(SDL_Texture *texture,
                                   SDL_ScaleMode *scaleMode);
extern int SDL_UpdateTexture(SDL_Texture *texture,
                             const SDL_Rect *rect,
                             const void *pixels, int pitch);
extern int SDL_UpdateYUVTexture(SDL_Texture *texture,
                                const SDL_Rect *rect,
                                const Uint8 *Yplane, int Ypitch,
                                const Uint8 *Uplane, int Upitch,
                                const Uint8 *Vplane, int Vpitch);
extern int SDL_LockTexture(SDL_Texture *texture,
                           const SDL_Rect *rect,
                           void **pixels, int *pitch);
extern int SDL_LockTextureToSurface(SDL_Texture *texture,
                                    const SDL_Rect *rect,
                                    SDL_Surface **surface);

extern void SDL_UnlockTexture(SDL_Texture *texture);

extern SDL_bool SDL_RenderTargetSupported(SDL_Renderer *renderer);

extern int SDL_SetRenderTarget(SDL_Renderer *renderer,
                               SDL_Texture *texture);

extern SDL_Texture *SDL_GetRenderTarget(SDL_Renderer *renderer);
extern int SDL_RenderSetLogicalSize(SDL_Renderer *renderer, int w, int h);

extern void SDL_RenderGetLogicalSize(SDL_Renderer *renderer, int *w, int *h);
extern int SDL_RenderSetIntegerScale(SDL_Renderer *renderer,
                                     SDL_bool enable);

extern SDL_bool SDL_RenderGetIntegerScale(SDL_Renderer *renderer);
extern int SDL_RenderSetViewport(SDL_Renderer *renderer,
                                 const SDL_Rect *rect);

extern void SDL_RenderGetViewport(SDL_Renderer *renderer,
                                  SDL_Rect *rect);

extern int SDL_RenderSetClipRect(SDL_Renderer *renderer,
                                 const SDL_Rect *rect);

extern void SDL_RenderGetClipRect(SDL_Renderer *renderer,
                                  SDL_Rect *rect);

extern SDL_bool SDL_RenderIsClipEnabled(SDL_Renderer *renderer);
extern int SDL_RenderSetScale(SDL_Renderer *renderer,
                              float scaleX, float scaleY);

extern void SDL_RenderGetScale(SDL_Renderer *renderer,
                               float *scaleX, float *scaleY);
extern int SDL_SetRenderDrawColor(SDL_Renderer *renderer,
                                  Uint8 r, Uint8 g, Uint8 b,
                                  Uint8 a);
extern int SDL_GetRenderDrawColor(SDL_Renderer *renderer,
                                  Uint8 *r, Uint8 *g, Uint8 *b,
                                  Uint8 *a);
extern int SDL_SetRenderDrawBlendMode(SDL_Renderer *renderer,
                                      SDL_BlendMode blendMode);

extern int SDL_GetRenderDrawBlendMode(SDL_Renderer *renderer,
                                      SDL_BlendMode *blendMode);

extern int SDL_RenderClear(SDL_Renderer *renderer);

extern int SDL_RenderDrawPoint(SDL_Renderer *renderer,
                               int x, int y);

extern int SDL_RenderDrawPoints(SDL_Renderer *renderer,
                                const SDL_Point *points,
                                int count);

extern int SDL_RenderDrawLine(SDL_Renderer *renderer,
                              int x1, int y1, int x2, int y2);

extern int SDL_RenderDrawLines(SDL_Renderer *renderer,
                               const SDL_Point *points,
                               int count);

extern int SDL_RenderDrawRect(SDL_Renderer *renderer,
                              const SDL_Rect *rect);

extern int SDL_RenderDrawRects(SDL_Renderer *renderer,
                               const SDL_Rect *rects,
                               int count);

extern int SDL_RenderFillRect(SDL_Renderer *renderer,
                              const SDL_Rect *rect);

extern int SDL_RenderFillRects(SDL_Renderer *renderer,
                               const SDL_Rect *rects,
                               int count);
extern int SDL_RenderCopy(SDL_Renderer *renderer,
                          SDL_Texture *texture,
                          const SDL_Rect *srcrect,
                          const SDL_Rect *dstrect);
extern int SDL_RenderCopyEx(SDL_Renderer *renderer,
                            SDL_Texture *texture,
                            const SDL_Rect *srcrect,
                            const SDL_Rect *dstrect,
                            const double angle,
                            const SDL_Point *center,
                            const SDL_RendererFlip flip);

extern int SDL_RenderDrawPointF(SDL_Renderer *renderer,
                                float x, float y);

extern int SDL_RenderDrawPointsF(SDL_Renderer *renderer,
                                 const SDL_FPoint *points,
                                 int count);

extern int SDL_RenderDrawLineF(SDL_Renderer *renderer,
                               float x1, float y1, float x2, float y2);

extern int SDL_RenderDrawLinesF(SDL_Renderer *renderer,
                                const SDL_FPoint *points,
                                int count);

extern int SDL_RenderDrawRectF(SDL_Renderer *renderer,
                               const SDL_FRect *rect);

extern int SDL_RenderDrawRectsF(SDL_Renderer *renderer,
                                const SDL_FRect *rects,
                                int count);

extern int SDL_RenderFillRectF(SDL_Renderer *renderer,
                               const SDL_FRect *rect);

extern int SDL_RenderFillRectsF(SDL_Renderer *renderer,
                                const SDL_FRect *rects,
                                int count);
extern int SDL_RenderCopyF(SDL_Renderer *renderer,
                           SDL_Texture *texture,
                           const SDL_Rect *srcrect,
                           const SDL_FRect *dstrect);
extern int SDL_RenderCopyExF(SDL_Renderer *renderer,
                             SDL_Texture *texture,
                             const SDL_Rect *srcrect,
                             const SDL_FRect *dstrect,
                             const double angle,
                             const SDL_FPoint *center,
                             const SDL_RendererFlip flip);
extern int SDL_RenderReadPixels(SDL_Renderer *renderer,
                                const SDL_Rect *rect,
                                uint32_t format,
                                void *pixels, int pitch);

extern void SDL_RenderPresent(SDL_Renderer *renderer);

extern void SDL_DestroyTexture(SDL_Texture *texture);

extern void SDL_DestroyRenderer(SDL_Renderer *renderer);
extern int SDL_RenderFlush(SDL_Renderer *renderer);

extern int SDL_GL_BindTexture(SDL_Texture *texture, float *texw, float *texh);

extern int SDL_GL_UnbindTexture(SDL_Texture *texture);

extern void *SDL_RenderGetMetalLayer(SDL_Renderer *renderer);

extern void *SDL_RenderGetMetalCommandEncoder(SDL_Renderer *renderer);

struct _SDL_Sensor;
typedef struct _SDL_Sensor SDL_Sensor;

typedef Sint32 SDL_SensorID;
typedef enum
{
    SDL_SENSOR_INVALID = -1,
    SDL_SENSOR_UNKNOWN,
    SDL_SENSOR_ACCEL,
    SDL_SENSOR_GYRO
} SDL_SensorType;

extern int SDL_NumSensors(void);
extern const char *SDL_SensorGetDeviceName(int device_index);
extern SDL_SensorType SDL_SensorGetDeviceType(int device_index);
extern int SDL_SensorGetDeviceNonPortableType(int device_index);
extern SDL_SensorID SDL_SensorGetDeviceInstanceID(int device_index);
extern SDL_Sensor *SDL_SensorOpen(int device_index);
extern SDL_Sensor *SDL_SensorFromInstanceID(SDL_SensorID instance_id);
extern const char *SDL_SensorGetName(SDL_Sensor *sensor);
extern SDL_SensorType SDL_SensorGetType(SDL_Sensor *sensor);
extern int SDL_SensorGetNonPortableType(SDL_Sensor *sensor);
extern SDL_SensorID SDL_SensorGetInstanceID(SDL_Sensor *sensor);
extern int SDL_SensorGetData(SDL_Sensor *sensor, float *data, int num_values);
extern void SDL_SensorClose(SDL_Sensor *sensor);
extern void SDL_SensorUpdate(void);
extern int SDL_SetWindowShape(SDL_Window *window, SDL_Surface *shape, SDL_WindowShapeMode *shape_mode);
extern int SDL_GetShapedWindowMode(SDL_Window *window, SDL_WindowShapeMode *shape_mode);
typedef void (*SDL_WindowsMessageHook)(void *userdata, void *hWnd, unsigned int message, Uint64 wParam, Sint64 lParam);
extern void SDL_SetWindowsMessageHook(SDL_WindowsMessageHook callback, void *userdata);
extern int SDL_Direct3D9GetAdapterIndex(int displayIndex);
extern IDirect3DDevice9 *SDL_RenderGetD3D9Device(SDL_Renderer *renderer);
extern SDL_bool SDL_DXGIGetOutputInfo(int displayIndex, int *adapterIndex, int *outputIndex);
extern SDL_bool SDL_IsTablet(void);
extern void SDL_OnApplicationWillTerminate(void);
extern void SDL_OnApplicationDidReceiveMemoryWarning(void);
extern void SDL_OnApplicationWillResignActive(void);
extern void SDL_OnApplicationDidEnterBackground(void);
extern void SDL_OnApplicationWillEnterForeground(void);
extern void SDL_OnApplicationDidBecomeActive(void);
extern uint32_t SDL_GetTicks(void);
extern Uint64 SDL_GetPerformanceCounter(void);
extern Uint64 SDL_GetPerformanceFrequency(void);
extern void SDL_Delay(uint32_t ms);
typedef uint32_t (*SDL_TimerCallback)(uint32_t interval, void *param);
typedef int SDL_TimerID;
extern SDL_TimerID SDL_AddTimer(uint32_t interval,SDL_TimerCallback callback,void *param);
extern SDL_bool SDL_RemoveTimer(SDL_TimerID id);
extern void SDL_GetVersion(SDL_version *ver);
extern const char *SDL_GetRevision(void);
extern int SDL_GetRevisionNumber(void);
extern SDL_Window *SDL_CreateShapedWindow(const char *title, unsigned int x, unsigned int y, unsigned int w, unsigned int h, uint32_t flags);
extern SDL_bool SDL_IsShapedWindow(const SDL_Window *window);
extern int SDL_Init(uint32_t flags);

extern int SDL_InitSubSystem(uint32_t flags);

extern void SDL_QuitSubSystem(uint32_t flags);

extern uint32_t SDL_WasInit(uint32_t flags);

extern void SDL_Quit(void);

#define CMDUTILS_COMMON_OPTIONS_AVDEVICE {"sources", OPT_EXIT | HAS_ARG, {.func_arg = show_sources}, "list sources of the input device", "device"}, {"sinks", OPT_EXIT | HAS_ARG, {.func_arg = show_sinks}, "list sinks of the output device", "device"},
#define CMDUTILS_COMMON_OPTIONS {"L", OPT_EXIT, {.func_arg = show_license}, "show license"}, {"h", OPT_EXIT, {.func_arg = show_help}, "show help", "topic"}, {"?", OPT_EXIT, {.func_arg = show_help}, "show help", "topic"}, {"help", OPT_EXIT, {.func_arg = show_help}, "show help", "topic"}, {"-help", OPT_EXIT, {.func_arg = show_help}, "show help", "topic"}, {"version", OPT_EXIT, {.func_arg = show_version}, "show version"}, {"buildconf", OPT_EXIT, {.func_arg = show_buildconf}, "show build configuration"}, {"formats", OPT_EXIT, {.func_arg = show_formats}, "show available formats"}, {"muxers", OPT_EXIT, {.func_arg = show_muxers}, "show available muxers"}, {"demuxers", OPT_EXIT, {.func_arg = show_demuxers}, "show available demuxers"}, {"devices", OPT_EXIT, {.func_arg = show_devices}, "show available devices"}, {"codecs", OPT_EXIT, {.func_arg = show_codecs}, "show available codecs"}, {"decoders", OPT_EXIT, {.func_arg = show_decoders}, "show available decoders"}, {"encoders", OPT_EXIT, {.func_arg = show_encoders}, "show available encoders"}, {"bsfs", OPT_EXIT, {.func_arg = show_bsfs}, "show available bit stream filters"}, {"protocols", OPT_EXIT, {.func_arg = show_protocols}, "show available protocols"}, {"filters", OPT_EXIT, {.func_arg = show_filters}, "show available filters"}, {"pix_fmts", OPT_EXIT, {.func_arg = show_pix_fmts}, "show available pixel formats"}, {"layouts", OPT_EXIT, {.func_arg = show_layouts}, "show standard channel layouts"}, {"sample_fmts", OPT_EXIT, {.func_arg = show_sample_fmts}, "show available audio sample formats"}, {"colors", OPT_EXIT, {.func_arg = show_colors}, "show available color names"}, {"loglevel", HAS_ARG, {.func_arg = opt_loglevel}, "set logging level", "loglevel"}, {"v", HAS_ARG, {.func_arg = opt_loglevel}, "set logging level", "loglevel"}, {"report", 0, {.func_arg = opt_report}, "generate a report"}, {"max_alloc", HAS_ARG, {.func_arg = opt_max_alloc}, "set maximum size of a single allocated block", "bytes"}, {"cpuflags", HAS_ARG | OPT_EXPERT, {.func_arg = opt_cpuflags}, "force specific cpu flags", "flags"}, {"hide_banner", OPT_BOOL | OPT_EXPERT, {&hide_banner}, "do not show program banner", "hide_banner"}, CMDUTILS_COMMON_OPTIONS_AVDEVICE


extern const char program_name[];

extern const int program_birth_year;

extern AVCodecContext *avcodec_opts[AVMEDIA_TYPE_NB];
AVDictionary *sws_dict;
AVDictionary *swr_opts;
AVDictionary *format_opts, *codec_opts, *resample_opts;

static FILE *report_file;
static int report_file_level = AV_LOG_DEBUG;
int hide_banner = 0;


#define CONV_FP(x) ((double) (x)) / (1 << 16)

// double to fixed point
#define CONV_DB(x) (int32_t) ((x) * (1 << 16))


double av_display_rotation_get(const int32_t matrix[9])
{
    double rotation, scale[2];

    scale[0] = hypot(CONV_FP(matrix[0]), CONV_FP(matrix[3]));
    scale[1] = hypot(CONV_FP(matrix[1]), CONV_FP(matrix[4]));

    if (scale[0] == 0.0 || scale[1] == 0.0)
        return NAN;

    rotation = atan2(CONV_FP(matrix[1]) / scale[1],
                     CONV_FP(matrix[0]) / scale[0]) * 180 / M_PI;

    return -rotation;
}

// #include "cmdutils.c"

#define media_type_string av_get_media_type_string
#define GET_PIX_FMT_NAME(pix_fmt) const char *name = av_get_pix_fmt_name(pix_fmt);
#define GET_CODEC_NAME(id) const char *name = avcodec_descriptor_get(id)->name;
#define GET_SAMPLE_FMT_NAME(sample_fmt) const char *name = av_get_sample_fmt_name(sample_fmt)
#define GET_SAMPLE_RATE_NAME(rate) \
    char name[16];                 \
    snprintf(name, sizeof(name), "%d", rate);

#define GET_CH_LAYOUT_DESC(ch_layout) \
    char name[128];                   \
    av_get_channel_layout_string(name, sizeof(name), 0, ch_layout);

double get_rotation(AVStream *st);

const char program_name[] = "ffplay";
const int program_birth_year = 2003;
#define MAX_QUEUE_SIZE (15 * 1024 * 1024)
#define MIN_FRAMES 25
#define EXTERNAL_CLOCK_MIN_FRAMES 2
#define EXTERNAL_CLOCK_MAX_FRAMES 10
#define SDL_AUDIO_MIN_BUFFER_SIZE 512
#define SDL_AUDIO_MAX_CALLBACKS_PER_SEC 30
#define SDL_VOLUME_STEP (0.75)
#define AV_SYNC_THRESHOLD_MIN 0.04
#define AV_SYNC_THRESHOLD_MAX 0.1
#define AV_SYNC_FRAMEDUP_THRESHOLD 0.1
#define AV_NOSYNC_THRESHOLD 10.0
#define SAMPLE_CORRECTION_PERCENT_MAX 10
#define EXTERNAL_CLOCK_SPEED_MIN 0.900
#define EXTERNAL_CLOCK_SPEED_MAX 1.010
#define EXTERNAL_CLOCK_SPEED_STEP 0.001
#define AUDIO_DIFF_AVG_NB 20
#define REFRESH_RATE 0.01
#define SAMPLE_ARRAY_SIZE (8 * 65536)
#define CURSOR_HIDE_DELAY 1000000
#define USE_ONEPASS_SUBTITLE_RENDER 1

static unsigned sws_flags = 4;


static AVInputFormat *file_iformat;
static const char *input_filename;
static const char *window_title;
static int default_width = 640;
static int default_height = 480;
static int screen_width = 0;
static int screen_height = 0;
static int screen_left = (0x2FFF0000u | (0));
static int screen_top = (0x2FFF0000u | (0));
static int audio_disable;
static int video_disable;
static int subtitle_disable;
static const char *wanted_stream_spec[AVMEDIA_TYPE_NB] = {0};
static int seek_by_bytes = -1;
static float seek_interval = 10;
static int display_disable;
static int borderless;
static int alwaysontop;
static int startup_volume = 100;
static int show_status = -1;
static int av_sync_type = AV_SYNC_AUDIO_MASTER;
static int64_t start_time = 0;
static int64_t duration = 0;
static int fast = 0;
static int genpts = 0;
static int lowres = 0;
static int decoder_reorder_pts = -1;
static int autoexit;
static int exit_on_keydown;
static int exit_on_mousedown;
static int loop = 1;
static int framedrop = -1;
static int infinite_buffer = -1;
static enum ShowMode show_mode = SHOW_MODE_NONE;
static const char *audio_codec_name;
static const char *subtitle_codec_name;
static const char *video_codec_name;
double rdftspeed = 0.02;
static int64_t cursor_last_shown;
static int cursor_hidden = 0;

static const char **vfilters_list =
    NULL;
static int nb_vfilters = 0;
static char *afilters =
    NULL;

static int autorotate = 1;
static int find_stream_info = 1;
static int filter_nbthreads = 0;

static int is_full_screen;
static int64_t audio_callback_time;

static AVPacket flush_pkt;
#define FF_QUIT_EVENT (SDL_USEREVENT + 2)

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_RendererInfo renderer_info = {0};
static SDL_AudioDeviceID audio_dev;


static const struct TextureFormatEntry sdl_texture_format_map[] = {
    {AV_PIX_FMT_RGB8, SDL_PIXELFORMAT_RGB332},
    {AV_PIX_FMT_RGB444LE, SDL_PIXELFORMAT_RGB444},
    {AV_PIX_FMT_RGB555LE, SDL_PIXELFORMAT_RGB555},
    {AV_PIX_FMT_BGR555LE, SDL_PIXELFORMAT_BGR555},
    {AV_PIX_FMT_RGB565LE, SDL_PIXELFORMAT_RGB565},
    {AV_PIX_FMT_BGR565LE, SDL_PIXELFORMAT_BGR565},
    {AV_PIX_FMT_RGB24, SDL_PIXELFORMAT_RGB24},
    {AV_PIX_FMT_BGR24, SDL_PIXELFORMAT_BGR24},
    {AV_PIX_FMT_BGR0, SDL_PIXELFORMAT_RGB888},
    {AV_PIX_FMT_RGB0, SDL_PIXELFORMAT_BGR888},
    {AV_PIX_FMT_0BGR, SDL_PIXELFORMAT_RGBX8888},
    {AV_PIX_FMT_0RGB, SDL_PIXELFORMAT_BGRX8888},
    {AV_PIX_FMT_BGRA, SDL_PIXELFORMAT_ARGB8888},
    {AV_PIX_FMT_ABGR, SDL_PIXELFORMAT_RGBA8888},
    {AV_PIX_FMT_RGBA, SDL_PIXELFORMAT_ABGR8888},
    {AV_PIX_FMT_ARGB, SDL_PIXELFORMAT_BGRA8888},
    {AV_PIX_FMT_YUV420P, SDL_PIXELFORMAT_IYUV},
    {AV_PIX_FMT_YUYV422, SDL_PIXELFORMAT_YUY2},
    {AV_PIX_FMT_UYVY422, SDL_PIXELFORMAT_UYVY},
    {AV_PIX_FMT_NONE, SDL_PIXELFORMAT_UNKNOWN},
};

static int opt_add_vfilter(void *optctx, const char *opt, const char *arg)
{
    vfilters_list = grow_array(vfilters_list, sizeof(*vfilters_list), &nb_vfilters, nb_vfilters + 1);
    vfilters_list[nb_vfilters - 1] = arg;
    return 0;
}

static inline int cmp_audio_fmts(enum AVSampleFormat fmt1, int64_t channel_count1,
                                 enum AVSampleFormat fmt2, int64_t channel_count2)
{
    if (channel_count1 == 1 && channel_count2 == 1)
        return av_get_packed_sample_fmt(fmt1) != av_get_packed_sample_fmt(fmt2);
    else
        return channel_count1 != channel_count2 || fmt1 != fmt2;
}

static inline int64_t get_valid_channel_layout(int64_t channel_layout, int channels)
{
    if (channel_layout && av_get_channel_layout_nb_channels(channel_layout) == channels)
        return channel_layout;
    else
        return 0;
}

static int packet_queue_put_private(PacketQueue *q, AVPacket *pkt)
{
    MyAVPacketList *pkt1;
    if (q->abort_request)
        return -1;
    pkt1 = av_malloc(sizeof(MyAVPacketList));
    if (pkt1 == NULL)
        return -1;
    pkt1->pkt = *pkt;
    pkt1->next = NULL;
    if (pkt == &flush_pkt)
        q->serial++;
    pkt1->serial = q->serial;
    if (q->last_pkt == NULL)
        q->first_pkt = pkt1;
    else
        q->last_pkt->next = pkt1;
    q->last_pkt = pkt1;
    q->nb_packets++;
    q->size += pkt1->pkt.size + sizeof(*pkt1);
    q->duration += pkt1->pkt.duration;
    SDL_CondSignal(q->cond);
    return 0;
}

static int packet_queue_put(PacketQueue *q, AVPacket *pkt)
{
    int ret;
    SDL_LockMutex(q->mutex);
    ret = packet_queue_put_private(q, pkt);
    SDL_UnlockMutex(q->mutex);
    if (pkt != &flush_pkt && ret < 0)
        av_packet_unref(pkt);
    return ret;
}

static int packet_queue_put_nullpacket(PacketQueue *q, int stream_index)
{
    AVPacket pkt1, *pkt = &pkt1;
    av_init_packet(pkt);
    pkt->data =
        NULL;
    pkt->size = 0;
    pkt->stream_index = stream_index;
    return packet_queue_put(q, pkt);
}

static int packet_queue_init(PacketQueue *q)
{
    memset(q, 0, sizeof(PacketQueue));
    q->mutex = SDL_CreateMutex();
    if (!q->mutex)
    {
        av_log(
            NULL, 8, "SDL_CreateMutex(): %s\n", SDL_GetError());
        return (-(
            12));
    }
    q->cond = SDL_CreateCond();
    if (!q->cond)
    {
        av_log(
            NULL, 8, "SDL_CreateCond(): %s\n", SDL_GetError());
        return (-(
            12));
    }
    q->abort_request = 1;
    return 0;
}

static void packet_queue_flush(PacketQueue *q)
{
    MyAVPacketList *pkt, *pkt1;
    SDL_LockMutex(q->mutex);
    for (pkt = q->first_pkt; pkt; pkt = pkt1)
    {
        pkt1 = pkt->next;
        av_packet_unref(&pkt->pkt);
        av_freep(&pkt);
    }
    q->last_pkt =
        NULL;
    q->first_pkt =
        NULL;
    q->nb_packets = 0;
    q->size = 0;
    q->duration = 0;
    SDL_UnlockMutex(q->mutex);
}

static void packet_queue_destroy(PacketQueue *q)
{
    packet_queue_flush(q);
    SDL_DestroyMutex(q->mutex);
    SDL_DestroyCond(q->cond);
}

static void packet_queue_abort(PacketQueue *q)
{
    SDL_LockMutex(q->mutex);
    q->abort_request = 1;
    SDL_CondSignal(q->cond);
    SDL_UnlockMutex(q->mutex);
}

static void packet_queue_start(PacketQueue *q)
{
    SDL_LockMutex(q->mutex);
    q->abort_request = 0;
    packet_queue_put_private(q, &flush_pkt);
    SDL_UnlockMutex(q->mutex);
}

static int packet_queue_get(PacketQueue *q, AVPacket *pkt, int block, int *serial)
{
    MyAVPacketList *pkt1;
    int ret;
    SDL_LockMutex(q->mutex);
    for (;;)
    {
        if (q->abort_request)
        {
            ret = -1;
            break;
        }
        pkt1 = q->first_pkt;
        if (pkt1)
        {
            q->first_pkt = pkt1->next;
            if (!q->first_pkt)
                q->last_pkt =
                    NULL;
            q->nb_packets--;
            q->size -= pkt1->pkt.size + sizeof(*pkt1);
            q->duration -= pkt1->pkt.duration;
            *pkt = pkt1->pkt;
            if (serial)
                *serial = pkt1->serial;
            av_free(pkt1);
            ret = 1;
            break;
        }
        else if (!block)
        {
            ret = 0;
            break;
        }
        else
        {
            SDL_CondWait(q->cond, q->mutex);
        }
    }
    SDL_UnlockMutex(q->mutex);
    return ret;
}

static void decoder_init(Decoder *d, AVCodecContext *avctx, PacketQueue *queue, SDL_cond *empty_queue_cond)
{
    memset(d, 0, sizeof(Decoder));
    d->avctx = avctx;
    d->queue = queue;
    d->empty_queue_cond = empty_queue_cond;
    d->start_pts = 0;
    d->pkt_serial = -1;
}

static int decoder_decode_frame(Decoder *d, AVFrame *frame, AVSubtitle *sub)
{
    int ret = (-(11));
    for (;;)
    {
        AVPacket pkt;
        if (d->queue->serial == d->pkt_serial)
        {
            do
            {
                if (d->queue->abort_request != 0)
                    return -1;
                switch (d->avctx->codec_type)
                {
                case AVMEDIA_TYPE_VIDEO:
                    ret = avcodec_receive_frame(d->avctx, frame);
                    if (ret >= 0)
                    {
                        if (decoder_reorder_pts == -1)
                        {
                            frame->pts = frame->best_effort_timestamp;
                        }
                        else if (!decoder_reorder_pts)
                        {
                            frame->pts = frame->pkt_dts;
                        }
                    }
                    break;
                case AVMEDIA_TYPE_AUDIO:
                    ret = avcodec_receive_frame(d->avctx, frame);
                    if (ret >= 0)
                    {
                        AVRational tb = (AVRational){1, frame->sample_rate};
                        if (frame->pts != 0)
                            frame->pts = av_rescale_q(frame->pts, d->avctx->pkt_timebase, tb);
                        else if (d->next_pts != 0)
                            frame->pts = av_rescale_q(d->next_pts, d->next_pts_tb, tb);
                        if (frame->pts != 0)
                        {
                            d->next_pts = frame->pts + frame->nb_samples;
                            d->next_pts_tb = tb;
                        }
                    }
                    break;
                }
                if (ret == (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24))))
                {
                    d->finished = d->pkt_serial;
                    avcodec_flush_buffers(d->avctx);
                    return 0;
                }
                if (ret >= 0)
                    return 1;
            } while (ret != (-(11)));
        }
        do
        {
            if (d->queue->nb_packets == 0)
                SDL_CondSignal(d->empty_queue_cond);
            if (d->packet_pending)
            {
                av_packet_move_ref(&pkt, &d->pkt);
                d->packet_pending = 0;
            }
            else
            {
                if (packet_queue_get(d->queue, &pkt, 1, &d->pkt_serial) < 0)
                    return -1;
            }
            if (d->queue->serial == d->pkt_serial)
                break;
            av_packet_unref(&pkt);
        } while (1);
        if (pkt.data == flush_pkt.data)
        {
            avcodec_flush_buffers(d->avctx);
            d->finished = 0;
            d->next_pts = d->start_pts;
            d->next_pts_tb = d->start_pts_tb;
        }
        else
        {
            if (d->avctx->codec_type == AVMEDIA_TYPE_SUBTITLE)
            {
                int got_frame = 0;
                ret = avcodec_decode_subtitle2(d->avctx, sub, &got_frame, &pkt);
                if (ret < 0)
                {
                    ret = (-(11));
                }
                else
                {
                    if (got_frame && !pkt.data)
                    {
                        d->packet_pending = 1;
                        av_packet_move_ref(&d->pkt, &pkt);
                    }
                    ret = got_frame ? 0 : (pkt.data ? (-(11)) : (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24))));
                }
            }
            else
            {
                if (avcodec_send_packet(d->avctx, &pkt) == (-(
                                                               11)))
                {
                    av_log(d->avctx, 16, "Receive_frame and send_packet both returned EAGAIN, which is an API violation.\n");
                    d->packet_pending = 1;
                    av_packet_move_ref(&d->pkt, &pkt);
                }
            }
            av_packet_unref(&pkt);
        }
    }
}

static void decoder_destroy(Decoder *d)
{
    av_packet_unref(&d->pkt);
    avcodec_free_context(&d->avctx);
}

static void frame_queue_unref_item(Frame *vp)
{
    av_frame_unref(vp->frame);
    avsubtitle_free(&vp->sub);
}

static int frame_queue_init(FrameQueue *f, PacketQueue *pktq, int max_size, int keep_last)
{
    int i;
    memset(f, 0, sizeof(FrameQueue));
    if (!(f->mutex = SDL_CreateMutex()))
    {
        av_log(NULL, 8, "SDL_CreateMutex(): %s\n", SDL_GetError());
        return (-(12));
    }
    if (!(f->cond = SDL_CreateCond()))
    {
        av_log(NULL, 8, "SDL_CreateCond(): %s\n", SDL_GetError());
        return (-(12));
    }
    f->pktq = pktq;
    f->max_size = (max_size > 16 ? 16 : max_size);
    f->keep_last = !!keep_last;
    for (i = 0; i < f->max_size; i++)
        if (!(f->queue[i].frame = av_frame_alloc()))
            return (-(12));
    return 0;
}

static void frame_queue_destory(FrameQueue *f)
{
    int i;
    for (i = 0; i < f->max_size; i++)
    {
        Frame *vp = &f->queue[i];
        frame_queue_unref_item(vp);
        av_frame_free(&vp->frame);
    }
    SDL_DestroyMutex(f->mutex);
    SDL_DestroyCond(f->cond);
}

static void frame_queue_signal(FrameQueue *f)
{
    SDL_LockMutex(f->mutex);
    SDL_CondSignal(f->cond);
    SDL_UnlockMutex(f->mutex);
}

static Frame *frame_queue_peek(FrameQueue *f)
{
    return &f->queue[(f->rindex + f->rindex_shown) % f->max_size];
}

static Frame *frame_queue_peek_next(FrameQueue *f)
{
    return &f->queue[(f->rindex + f->rindex_shown + 1) % f->max_size];
}

static Frame *frame_queue_peek_last(FrameQueue *f)
{
    return &f->queue[f->rindex];
}

static Frame *frame_queue_peek_writable(FrameQueue *f)
{
    SDL_LockMutex(f->mutex);
    while (f->size >= f->max_size &&
           !f->pktq->abort_request)
    {
        SDL_CondWait(f->cond, f->mutex);
    }
    SDL_UnlockMutex(f->mutex);
    if (f->pktq->abort_request)
        return NULL;
    return &f->queue[f->windex];
}

static Frame *frame_queue_peek_readable(FrameQueue *f)
{
    SDL_LockMutex(f->mutex);
    while (f->size - f->rindex_shown <= 0 &&
           !f->pktq->abort_request)
    {
        SDL_CondWait(f->cond, f->mutex);
    }
    SDL_UnlockMutex(f->mutex);
    if (f->pktq->abort_request)
        return NULL;
    return &f->queue[(f->rindex + f->rindex_shown) % f->max_size];
}

static void frame_queue_push(FrameQueue *f)
{
    if (++f->windex == f->max_size)
        f->windex = 0;
    SDL_LockMutex(f->mutex);
    f->size++;
    SDL_CondSignal(f->cond);
    SDL_UnlockMutex(f->mutex);
}

static void frame_queue_next(FrameQueue *f)
{
    if (f->keep_last && !f->rindex_shown)
    {
        f->rindex_shown = 1;
        return;
    }
    frame_queue_unref_item(&f->queue[f->rindex]);
    if (++f->rindex == f->max_size)
        f->rindex = 0;
    SDL_LockMutex(f->mutex);
    f->size--;
    SDL_CondSignal(f->cond);
    SDL_UnlockMutex(f->mutex);
}

static int frame_queue_nb_remaining(FrameQueue *f)
{
    return f->size - f->rindex_shown;
}

static int64_t frame_queue_last_pos(FrameQueue *f)
{
    Frame *fp = &f->queue[f->rindex];
    if (f->rindex_shown && fp->serial == f->pktq->serial)
        return fp->pos;
    else
        return -1;
}

static void decoder_abort(Decoder *d, FrameQueue *fq)
{
    packet_queue_abort(d->queue);
    frame_queue_signal(fq);
    SDL_WaitThread(d->decoder_tid,NULL);
    d->decoder_tid = NULL;
    packet_queue_flush(d->queue);
}

static inline void fill_rectangle(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    if (w && h)
        SDL_RenderFillRect(renderer, &rect);
}

static int realloc_texture(SDL_Texture **texture, uint32_t new_format, int new_width, int new_height, SDL_BlendMode blendmode, int init_texture)
{
    uint32_t format;
    int access, w, h;
    if (!*texture || SDL_QueryTexture(*texture, &format, &access, &w, &h) < 0 || new_width != w || new_height != h || new_format != format)
    {
        void *pixels;
        int pitch;
        if (*texture)
            SDL_DestroyTexture(*texture);
        if (!(*texture = SDL_CreateTexture(renderer, new_format, SDL_TEXTUREACCESS_STREAMING, new_width, new_height)))
            return -1;
        if (SDL_SetTextureBlendMode(*texture, blendmode) < 0)
            return -1;
        if (init_texture)
        {
            if (SDL_LockTexture(*texture, NULL, &pixels, &pitch) < 0)
                return -1;
            memset(pixels, 0, pitch * new_height);
            SDL_UnlockTexture(*texture);
        }
        av_log(NULL, 40, "Created %dx%d texture with %s.\n", new_width, new_height, SDL_GetPixelFormatName(new_format));
    }
    return 0;
}

static void calculate_display_rect(SDL_Rect *rect,
                                   int scr_xleft, int scr_ytop, int scr_width, int scr_height,
                                   int pic_width, int pic_height, AVRational pic_sar)
{
    AVRational aspect_ratio = pic_sar;
    int64_t width, height, x, y;
    if (av_cmp_q(aspect_ratio, av_make_q(0, 1)) <= 0)
        aspect_ratio = av_make_q(1, 1);
    aspect_ratio = av_mul_q(aspect_ratio, av_make_q(pic_width, pic_height));
    height = scr_height;
    width = av_rescale(height, aspect_ratio.num, aspect_ratio.den) & ~1;
    if (width > scr_width)
    {
        width = scr_width;
        height = av_rescale(width, aspect_ratio.den, aspect_ratio.num) & ~1;
    }
    x = (scr_width - width) / 2;
    y = (scr_height - height) / 2;
    rect->x = scr_xleft + x;
    rect->y = scr_ytop + y;
    rect->w = (((int)width) > (1) ? ((int)width) : (1));
    rect->h = (((int)height) > (1) ? ((int)height) : (1));
}

static void get_sdl_pix_fmt_and_blendmode(int format, uint32_t *sdl_pix_fmt, SDL_BlendMode *sdl_blendmode)
{
    int i;
    *sdl_blendmode = SDL_BLENDMODE_NONE;
    *sdl_pix_fmt = SDL_PIXELFORMAT_UNKNOWN;
    if (format == AV_PIX_FMT_BGRA ||
        format == AV_PIX_FMT_ABGR ||
        format == AV_PIX_FMT_RGBA ||
        format == AV_PIX_FMT_ARGB)
        *sdl_blendmode = SDL_BLENDMODE_BLEND;
    for (i = 0; i < (sizeof(sdl_texture_format_map) / sizeof((sdl_texture_format_map)[0])) - 1; i++)
    {
        if (format == sdl_texture_format_map[i].format)
        {
            *sdl_pix_fmt = sdl_texture_format_map[i].texture_fmt;
            return;
        }
    }
}

static int upload_texture(SDL_Texture **tex, AVFrame *frame, struct SwsContext **img_convert_ctx)
{
    int ret = 0;
    uint32_t sdl_pix_fmt;
    SDL_BlendMode sdl_blendmode;
    get_sdl_pix_fmt_and_blendmode(frame->format, &sdl_pix_fmt, &sdl_blendmode);
    if (realloc_texture(tex, sdl_pix_fmt == SDL_PIXELFORMAT_UNKNOWN ? SDL_PIXELFORMAT_ARGB8888 : sdl_pix_fmt, frame->width, frame->height, sdl_blendmode, 0) < 0)
        return -1;
    switch (sdl_pix_fmt)
    {
    case SDL_PIXELFORMAT_UNKNOWN:
        *img_convert_ctx = sws_getCachedContext(*img_convert_ctx,
                                                frame->width, frame->height, frame->format, frame->width, frame->height,
                                                AV_PIX_FMT_BGRA, sws_flags,
                                                NULL,
                                                NULL,
                                                NULL);
        if (*img_convert_ctx != NULL)
        {
            uint8_t *pixels[4];
            int pitch[4];
            if (!SDL_LockTexture(*tex,NULL, (void **)pixels, pitch))
            {
                sws_scale(*img_convert_ctx, (const uint8_t *const *)frame->data, frame->linesize,
                          0, frame->height, pixels, pitch);
                SDL_UnlockTexture(*tex);
            }
        }
        else
        {
            av_log(NULL, 8, "Cannot initialize the conversion context\n");
            ret = -1;
        }
        break;
    case SDL_PIXELFORMAT_IYUV:
        if (frame->linesize[0] > 0 && frame->linesize[1] > 0 && frame->linesize[2] > 0)
        {
            ret = SDL_UpdateYUVTexture(*tex,
                                       NULL, frame->data[0], frame->linesize[0],
                                       frame->data[1], frame->linesize[1],
                                       frame->data[2], frame->linesize[2]);
        }
        else if (frame->linesize[0] < 0 && frame->linesize[1] < 0 && frame->linesize[2] < 0)
        {
            ret = SDL_UpdateYUVTexture(*tex,
                                       NULL, frame->data[0] + frame->linesize[0] * (frame->height - 1), -frame->linesize[0],
                                       frame->data[1] + frame->linesize[1] * (AV_CEIL_RSHIFT(frame->height, 1) - 1), -frame->linesize[1],
                                       frame->data[2] + frame->linesize[2] * (AV_CEIL_RSHIFT(frame->height, 1) - 1), -frame->linesize[2]);
        }
        else
        {
            av_log(
                NULL, 16, "Mixed negative and positive linesizes are not supported.\n");
            return -1;
        }
        break;
    default:
        if (frame->linesize[0] < 0)
        {
            ret = SDL_UpdateTexture(*tex,NULL, frame->data[0] + frame->linesize[0] * (frame->height - 1), -frame->linesize[0]);
        }
        else
        {
            ret = SDL_UpdateTexture(*tex,NULL, frame->data[0], frame->linesize[0]);
        }
        break;
    }
    return ret;
}

static void set_sdl_yuv_conversion_mode(AVFrame *frame)
{
    SDL_YUV_CONVERSION_MODE mode = SDL_YUV_CONVERSION_AUTOMATIC;
    if (frame && (frame->format == AV_PIX_FMT_YUV420P || frame->format == AV_PIX_FMT_YUYV422 || frame->format == AV_PIX_FMT_UYVY422))
    {
        if (frame->color_range == AVCOL_RANGE_JPEG)
            mode = SDL_YUV_CONVERSION_JPEG;
        else if (frame->colorspace == AVCOL_SPC_BT709)
            mode = SDL_YUV_CONVERSION_BT709;
        else if (frame->colorspace == AVCOL_SPC_BT470BG || frame->colorspace == AVCOL_SPC_SMPTE170M || frame->colorspace == AVCOL_SPC_SMPTE240M)
            mode = SDL_YUV_CONVERSION_BT601;
    }
    SDL_SetYUVConversionMode(mode);
}

static void video_image_display(VideoState *is)
{
    Frame *vp;
    Frame *sp = NULL;
    SDL_Rect rect;
    vp = frame_queue_peek_last(&is->pictq);
    if (is->subtitle_st)
    {
        if (frame_queue_nb_remaining(&is->subpq) > 0)
        {
            sp = frame_queue_peek(&is->subpq);
            if (vp->pts >= sp->pts + ((float)sp->sub.start_display_time / 1000))
            {
                if (!sp->uploaded)
                {
                    uint8_t *pixels[4];
                    int pitch[4];
                    int i;
                    if (!sp->width || !sp->height)
                    {
                        sp->width = vp->width;
                        sp->height = vp->height;
                    }
                    if (realloc_texture(&is->sub_texture, SDL_PIXELFORMAT_ARGB8888, sp->width, sp->height, SDL_BLENDMODE_BLEND, 1) < 0)
                        return;
                    for (i = 0; i < sp->sub.num_rects; i++)
                    {
                        AVSubtitleRect *sub_rect = sp->sub.rects[i];
                        sub_rect->x = av_clip_c(sub_rect->x, 0, sp->width);
                        sub_rect->y = av_clip_c(sub_rect->y, 0, sp->height);
                        sub_rect->w = av_clip_c(sub_rect->w, 0, sp->width - sub_rect->x);
                        sub_rect->h = av_clip_c(sub_rect->h, 0, sp->height - sub_rect->y);
                        is->sub_convert_ctx = sws_getCachedContext(is->sub_convert_ctx,
                                                                   sub_rect->w, sub_rect->h, AV_PIX_FMT_PAL8,
                                                                   sub_rect->w, sub_rect->h, AV_PIX_FMT_BGRA,
                                                                   0,
                                                                   NULL,
                                                                   NULL,
                                                                   NULL);
                        if (!is->sub_convert_ctx)
                        {
                            av_log(NULL, 8, "Cannot initialize the conversion context\n");
                            return;
                        }
                        if (!SDL_LockTexture(is->sub_texture, (SDL_Rect *)sub_rect, (void **)pixels, pitch))
                        {
                            sws_scale(is->sub_convert_ctx, (const uint8_t *const *)sub_rect->data, sub_rect->linesize, 0, sub_rect->h, pixels, pitch);
                            SDL_UnlockTexture(is->sub_texture);
                        }
                    }
                    sp->uploaded = 1;
                }
            }
            else
                sp =
                    NULL;
        }
    }
    calculate_display_rect(&rect, is->xleft, is->ytop, is->width, is->height, vp->width, vp->height, vp->sar);
    if (!vp->uploaded)
    {
        if (upload_texture(&is->vid_texture, vp->frame, &is->img_convert_ctx) < 0)
            return;
        vp->uploaded = 1;
        vp->flip_v = vp->frame->linesize[0] < 0;
    }
    set_sdl_yuv_conversion_mode(vp->frame);
    SDL_RenderCopyEx(renderer, is->vid_texture,
                     NULL, &rect, 0,
                     NULL, vp->flip_v ? SDL_FLIP_VERTICAL : 0);
    set_sdl_yuv_conversion_mode(NULL);
    if (sp)
    {
        SDL_RenderCopy(renderer, is->sub_texture, NULL, &rect);
    }
}

static inline int compute_mod(int a, int b)
{
    return a < 0 ? a % b + b : a % b;
}

static void video_audio_display(VideoState *s)
{
    int i, i_start, x, y1, y, ys, delay, n, nb_display_channels;
    int ch, channels, h, h2;
    int64_t time_diff;
    int rdft_bits, nb_freq;
    for (rdft_bits = 1; (1 << rdft_bits) < 2 * s->height; rdft_bits++)
        ;
    nb_freq = 1 << (rdft_bits - 1);
    channels = s->audio_tgt.channels;
    nb_display_channels = channels;
    if (!s->paused)
    {
        int data_used = s->show_mode == SHOW_MODE_WAVES ? s->width : (2 * nb_freq);
        n = 2 * channels;
        delay = s->audio_write_buf_size;
        delay /= n;
        if (audio_callback_time)
        {
            time_diff = av_gettime_relative() - audio_callback_time;
            delay -= (time_diff * s->audio_tgt.freq) / 1000000;
        }
        delay += 2 * data_used;
        if (delay < data_used)
            delay = data_used;
        i_start = x = compute_mod(s->sample_array_index - delay * channels, (8 * 65536));
        if (s->show_mode == SHOW_MODE_WAVES)
        {
            h =
                (-0x7fffffff - 1);
            for (i = 0; i < 1000; i += channels)
            {
                int idx = ((8 * 65536) + x - i) % (8 * 65536);
                int a = s->sample_array[idx];
                int b = s->sample_array[(idx + 4 * channels) % (8 * 65536)];
                int c = s->sample_array[(idx + 5 * channels) % (8 * 65536)];
                int d = s->sample_array[(idx + 9 * channels) % (8 * 65536)];
                int score = a - d;
                if (h < score && (b ^ c) < 0)
                {
                    h = score;
                    i_start = idx;
                }
            }
        }
        s->last_i_start = i_start;
    }
    else
    {
        i_start = s->last_i_start;
    }
    if (s->show_mode == SHOW_MODE_WAVES)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        h = s->height / nb_display_channels;
        h2 = (h * 9) / 20;
        for (ch = 0; ch < nb_display_channels; ch++)
        {
            i = i_start + ch;
            y1 = s->ytop + ch * h + (h / 2);
            for (x = 0; x < s->width; x++)
            {
                y = (s->sample_array[i] * h2) >> 15;
                if (y < 0)
                {
                    y = -y;
                    ys = y1 - y;
                }
                else
                {
                    ys = y1;
                }
                fill_rectangle(s->xleft + x, ys, 1, y);
                i += channels;
                if (i >= (8 * 65536))
                    i -= (8 * 65536);
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        for (ch = 1; ch < nb_display_channels; ch++)
        {
            y = s->ytop + ch * h;
            fill_rectangle(s->xleft, y, s->width, 1);
        }
    }
    else
    {
        if (realloc_texture(&s->vis_texture, SDL_PIXELFORMAT_ARGB8888, s->width, s->height, SDL_BLENDMODE_NONE, 1) < 0)
            return;
        nb_display_channels = ((nb_display_channels) > (2) ? (2) : (nb_display_channels));
        if (rdft_bits != s->rdft_bits)
        {
            av_rdft_end(s->rdft);
            av_free(s->rdft_data);
            s->rdft = av_rdft_init(rdft_bits, DFT_R2C);
            s->rdft_bits = rdft_bits;
            s->rdft_data = av_malloc_array(nb_freq, 4 * sizeof(*s->rdft_data));
        }
        if (!s->rdft || !s->rdft_data)
        {
            av_log(
                NULL, 16, "Failed to allocate buffers for RDFT, switching to waves display\n");
            s->show_mode = SHOW_MODE_WAVES;
        }
        else
        {
            FFTSample *data[2];
            SDL_Rect rect = {.x = s->xpos, .y = 0, .w = 1, .h = s->height};
            uint32_t *pixels;
            int pitch;
            for (ch = 0; ch < nb_display_channels; ch++)
            {
                data[ch] = s->rdft_data + 2 * nb_freq * ch;
                i = i_start + ch;
                for (x = 0; x < 2 * nb_freq; x++)
                {
                    double w = (x - nb_freq) * (1.0 / nb_freq);
                    data[ch][x] = s->sample_array[i] * (1.0 - w * w);
                    i += channels;
                    if (i >= (8 * 65536))
                        i -= (8 * 65536);
                }
                av_rdft_calc(s->rdft, data[ch]);
            }
            if (!SDL_LockTexture(s->vis_texture, &rect, (void **)&pixels, &pitch))
            {
                pitch >>= 2;
                pixels += pitch * s->height;
                for (y = 0; y < s->height; y++)
                {
                    double w = 1 / sqrt(nb_freq);
                    int a = sqrt(w * sqrt(data[0][2 * y + 0] * data[0][2 * y + 0] + data[0][2 * y + 1] * data[0][2 * y + 1]));
                    int b = (nb_display_channels == 2) ? sqrt(w * hypot(data[1][2 * y + 0], data[1][2 * y + 1]))
                                                       : a;
                    a = ((a) > (255) ? (255) : (a));
                    b = ((b) > (255) ? (255) : (b));
                    pixels -= pitch;
                    *pixels = (a << 16) + (b << 8) + ((a + b) >> 1);
                }
                SDL_UnlockTexture(s->vis_texture);
            }
            SDL_RenderCopy(renderer, s->vis_texture,
                           NULL,
                           NULL);
        }
        if (!s->paused)
            s->xpos++;
        if (s->xpos >= s->width)
            s->xpos = s->xleft;
    }
}

static void stream_component_close(VideoState *is, int stream_index)
{
    AVFormatContext *ic = is->ic;
    AVCodecParameters *codecpar;
    if (stream_index < 0 || stream_index >= ic->nb_streams)
        return;
    codecpar = ic->streams[stream_index]->codecpar;
    switch (codecpar->codec_type)
    {
    case AVMEDIA_TYPE_AUDIO:
        decoder_abort(&is->auddec, &is->sampq);
        SDL_CloseAudioDevice(audio_dev);
        decoder_destroy(&is->auddec);
        swr_free(&is->swr_ctx);
        av_freep(&is->audio_buf1);
        is->audio_buf1_size = 0;
        is->audio_buf = NULL;
        if (is->rdft)
        {
            av_rdft_end(is->rdft);
            av_freep(&is->rdft_data);
            is->rdft = NULL;
            is->rdft_bits = 0;
        }
        break;
    case AVMEDIA_TYPE_VIDEO:
        decoder_abort(&is->viddec, &is->pictq);
        decoder_destroy(&is->viddec);
        break;
    case AVMEDIA_TYPE_SUBTITLE:
        decoder_abort(&is->subdec, &is->subpq);
        decoder_destroy(&is->subdec);
        break;
    default:
        break;
    }
    ic->streams[stream_index]->discard = AVDISCARD_ALL;
    switch (codecpar->codec_type)
    {
    case AVMEDIA_TYPE_AUDIO:
        is->audio_st = NULL;
        is->audio_stream = -1;
        break;
    case AVMEDIA_TYPE_VIDEO:
        is->video_st = NULL;
        is->video_stream = -1;
        break;
    case AVMEDIA_TYPE_SUBTITLE:
        is->subtitle_st = NULL;
        is->subtitle_stream = -1;
        break;
    default:
        break;
    }
}

static void stream_close(VideoState *is)
{
    is->abort_request = 1;
    SDL_WaitThread(is->read_tid,
                   NULL);
    if (is->audio_stream >= 0)
        stream_component_close(is, is->audio_stream);
    if (is->video_stream >= 0)
        stream_component_close(is, is->video_stream);
    if (is->subtitle_stream >= 0)
        stream_component_close(is, is->subtitle_stream);
    avformat_close_input(&is->ic);
    packet_queue_destroy(&is->videoq);
    packet_queue_destroy(&is->audioq);
    packet_queue_destroy(&is->subtitleq);
    frame_queue_destory(&is->pictq);
    frame_queue_destory(&is->sampq);
    frame_queue_destory(&is->subpq);
    SDL_DestroyCond(is->continue_read_thread);
    sws_freeContext(is->img_convert_ctx);
    sws_freeContext(is->sub_convert_ctx);
    av_free(is->filename);
    if (is->vis_texture)
        SDL_DestroyTexture(is->vis_texture);
    if (is->vid_texture)
        SDL_DestroyTexture(is->vid_texture);
    if (is->sub_texture)
        SDL_DestroyTexture(is->sub_texture);
    av_free(is);
}

static void do_exit(VideoState *is)
{
    if (is != NULL)
    {
        stream_close(is);
    }
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    // uninit_opts();
    av_freep(&vfilters_list);
    avformat_network_deinit();
    if (show_status)
        printf("\n");
    SDL_Quit();
    av_log(
        NULL, -8, "%s", "");
    exit(0);
}

static void sigterm_handler(int sig)
{
    exit(123);
}

static void set_default_window_size(int width, int height, AVRational sar)
{
    SDL_Rect rect;
    int max_width = screen_width ? screen_width : 0x7fffffff;
    int max_height = screen_height ? screen_height : 0x7fffffff;
    if (max_width == 0x7fffffff && max_height == 0x7fffffff)
        max_height = height;
    calculate_display_rect(&rect, 0, 0, max_width, max_height, width, height, sar);
    default_width = rect.w;
    default_height = rect.h;
}

static int video_open(VideoState *is)
{
    int w, h;
    w = screen_width ? screen_width : default_width;
    h = screen_height ? screen_height : default_height;
    if (window_title == NULL)
        window_title = input_filename;
    SDL_SetWindowTitle(window, window_title);
    SDL_SetWindowSize(window, w, h);
    SDL_SetWindowPosition(window, screen_left, screen_top);
    if (is_full_screen != 0)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_ShowWindow(window);
    is->width = w;
    is->height = h;
    return 0;
}

static void video_display(VideoState *is)
{
    if (!is->width)
        video_open(is);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (is->audio_st && is->show_mode != SHOW_MODE_VIDEO)
        video_audio_display(is);
    else if (is->video_st)
        video_image_display(is);
    SDL_RenderPresent(renderer);
}

static double get_clock(Clock *c)
{
    if (*c->queue_serial != c->serial)
        return NAN;
    if (c->paused)
    {
        return c->pts;
    }
    else
    {
        double time = av_gettime_relative() / 1000000.0;
        return c->pts_drift + time - (time - c->last_updated) * (1.0 - c->speed);
    }
}

static void set_clock_at(Clock *c, double pts, int serial, double time)
{
    c->pts = pts;
    c->last_updated = time;
    c->pts_drift = c->pts - time;
    c->serial = serial;
}

static void set_clock(Clock *c, double pts, int serial)
{
    double time = av_gettime_relative() / 1000000.0;
    set_clock_at(c, pts, serial, time);
}

static void set_clock_speed(Clock *c, double speed)
{
    set_clock(c, get_clock(c), c->serial);
    c->speed = speed;
}

static void init_clock(Clock *c, int *queue_serial)
{
    c->speed = 1.0;
    c->paused = 0;
    c->queue_serial = queue_serial;
    set_clock(c,
              NAN, -1);
}

static void sync_clock_to_slave(Clock *c, Clock *slave)
{
    double clock = get_clock(c);
    double slave_clock = get_clock(slave);
    if (!isnan(slave_clock) && (isnan(clock) || fabs(clock - slave_clock) > AV_NOSYNC_THRESHOLD))
        set_clock(c, slave_clock, slave->serial);
}

static int get_master_sync_type(VideoState *is)
{
    if (is->av_sync_type == AV_SYNC_VIDEO_MASTER)
    {
        if (is->video_st)
            return AV_SYNC_VIDEO_MASTER;
        else
            return AV_SYNC_AUDIO_MASTER;
    }
    else if (is->av_sync_type == AV_SYNC_AUDIO_MASTER)
    {
        if (is->audio_st)
            return AV_SYNC_AUDIO_MASTER;
        else
            return AV_SYNC_EXTERNAL_CLOCK;
    }
    else
    {
        return AV_SYNC_EXTERNAL_CLOCK;
    }
}

static double get_master_clock(VideoState *is)
{
    double val;
    switch (get_master_sync_type(is))
    {
    case AV_SYNC_VIDEO_MASTER:
        val = get_clock(&is->vidclk);
        break;
    case AV_SYNC_AUDIO_MASTER:
        val = get_clock(&is->audclk);
        break;
    default:
        val = get_clock(&is->extclk);
        break;
    }
    return val;
}

static void check_external_clock_speed(VideoState *is)
{
    if (is->video_stream >= 0 && is->videoq.nb_packets <= 2 ||
        is->audio_stream >= 0 && is->audioq.nb_packets <= 2)
    {
        set_clock_speed(&is->extclk, ((0.900) > (is->extclk.speed - 0.001) ? (0.900) : (is->extclk.speed - 0.001)));
    }
    else if ((is->video_stream < 0 || is->videoq.nb_packets > 10) &&
             (is->audio_stream < 0 || is->audioq.nb_packets > 10))
    {
        set_clock_speed(&is->extclk, ((1.010) > (is->extclk.speed + 0.001) ? (is->extclk.speed + 0.001) : (1.010)));
    }
    else
    {
        double speed = is->extclk.speed;
        if (speed != 1.0)
            set_clock_speed(&is->extclk, speed + 0.001 * (1.0 - speed) / fabs(1.0 - speed));
    }
}

static void stream_seek(VideoState *is, int64_t pos, int64_t rel, int seek_by_bytes)
{
    if (!is->seek_req)
    {
        is->seek_pos = pos;
        is->seek_rel = rel;
        is->seek_flags &= ~2;
        if (seek_by_bytes)
            is->seek_flags |= 2;
        is->seek_req = 1;
        SDL_CondSignal(is->continue_read_thread);
    }
}

static void stream_toggle_pause(VideoState *is)
{
    if (is->paused)
    {
        is->frame_timer += av_gettime_relative() / 1000000.0 - is->vidclk.last_updated;
        if (is->read_pause_return != (-(
                                         40)))
        {
            is->vidclk.paused = 0;
        }
        set_clock(&is->vidclk, get_clock(&is->vidclk), is->vidclk.serial);
    }
    set_clock(&is->extclk, get_clock(&is->extclk), is->extclk.serial);
    is->paused = is->audclk.paused = is->vidclk.paused = is->extclk.paused = !is->paused;
}

static void toggle_pause(VideoState *is)
{
    stream_toggle_pause(is);
    is->step = 0;
}

static void toggle_mute(VideoState *is)
{
    is->muted = !is->muted;
}

static void update_volume(VideoState *is, int sign, double step)
{
    double volume_level = is->audio_volume ? (20 * log(is->audio_volume / (double)128) / log(10)) : -1000.0;
    int new_volume = lrint(128 * pow(10.0, (volume_level + sign * step) / 20.0));
    is->audio_volume = av_clip_c(is->audio_volume == new_volume ? (is->audio_volume + sign) : new_volume, 0, 128);
}

static void step_to_next_frame(VideoState *is)
{
    if (is->paused)
        stream_toggle_pause(is);
    is->step = 1;
}

static double compute_target_delay(double delay, VideoState *is)
{
    double sync_threshold, diff = 0;
    if (get_master_sync_type(is) != AV_SYNC_VIDEO_MASTER)
    {
        diff = get_clock(&is->vidclk) - get_master_clock(is);
        sync_threshold = ((0.04) > (((0.1) > (delay) ? (delay) : (0.1))) ? (0.04) : (((0.1) > (delay) ? (delay) : (0.1))));
        if (!isnan(diff) && fabs(diff) < is->max_frame_duration)
        {
            if (diff <= -sync_threshold)
                delay = ((0) > (delay + diff) ? (0) : (delay + diff));
            else if (diff >= sync_threshold && delay > 0.1)
                delay = delay + diff;
            else if (diff >= sync_threshold)
                delay = 2 * delay;
        }
    }
    av_log(NULL, 56, "video: delay=%0.3f A-V=%f\n",delay, -diff);
    return delay;
}

static double vp_duration(VideoState *is, Frame *vp, Frame *nextvp)
{
    if (vp->serial == nextvp->serial)
    {
        double duration = nextvp->pts - vp->pts;
        if (isnan(duration) || duration <= 0 || duration > is->max_frame_duration)
            return vp->duration;
        else
            return duration;
    }
    else
    {
        return 0.0;
    }
}

static void update_video_pts(VideoState *is, double pts, int64_t pos, int serial)
{
    set_clock(&is->vidclk, pts, serial);
    sync_clock_to_slave(&is->extclk, &is->vidclk);
}

static void video_refresh(void *opaque, double *remaining_time)
{
    VideoState *is = opaque;
    double time;
    Frame *sp, *sp2;
    if (!is->paused && get_master_sync_type(is) == AV_SYNC_EXTERNAL_CLOCK && is->realtime)
        check_external_clock_speed(is);
    if (!display_disable && is->show_mode != SHOW_MODE_VIDEO && is->audio_st)
    {
        time = av_gettime_relative() / 1000000.0;
        if (is->force_refresh || is->last_vis_time + rdftspeed < time)
        {
            video_display(is);
            is->last_vis_time = time;
        }
        *remaining_time = ((*remaining_time) > (is->last_vis_time + rdftspeed - time) ? (is->last_vis_time + rdftspeed - time) : (*remaining_time));
    }
    if (is->video_st)
    {
    retry:
        if (frame_queue_nb_remaining(&is->pictq) == 0)
        {
            // nothing to do, no picture to display in the queue
        }
        else
        {
            double last_duration, duration, delay;
            Frame *vp, *lastvp;
            lastvp = frame_queue_peek_last(&is->pictq);
            vp = frame_queue_peek(&is->pictq);
            if (vp->serial != is->videoq.serial)
            {
                frame_queue_next(&is->pictq);
                goto retry;
            }
            if (lastvp->serial != vp->serial)
                is->frame_timer = av_gettime_relative() / 1000000.0;
            if (is->paused)
                goto display;
            last_duration = vp_duration(is, lastvp, vp);
            delay = compute_target_delay(last_duration, is);
            time = av_gettime_relative() / 1000000.0;
            if (time < is->frame_timer + delay)
            {
                *remaining_time = ((is->frame_timer + delay - time) > (*remaining_time) ? (*remaining_time) : (is->frame_timer + delay - time));
                goto display;
            }
            is->frame_timer += delay;
            if (delay > 0 && time - is->frame_timer > 0.1)
                is->frame_timer = time;
            SDL_LockMutex(is->pictq.mutex);
            if (!isnan(vp->pts))
                update_video_pts(is, vp->pts, vp->pos, vp->serial);
            SDL_UnlockMutex(is->pictq.mutex);
            if (frame_queue_nb_remaining(&is->pictq) > 1)
            {
                Frame *nextvp = frame_queue_peek_next(&is->pictq);
                duration = vp_duration(is, vp, nextvp);
                if (!is->step && (framedrop > 0 || (framedrop && get_master_sync_type(is) != AV_SYNC_VIDEO_MASTER)) && time > is->frame_timer + duration)
                {
                    is->frame_drops_late++;
                    frame_queue_next(&is->pictq);
                    goto retry;
                }
            }
            if (is->subtitle_st)
            {
                while (frame_queue_nb_remaining(&is->subpq) > 0)
                {
                    sp = frame_queue_peek(&is->subpq);
                    if (frame_queue_nb_remaining(&is->subpq) > 1)
                        sp2 = frame_queue_peek_next(&is->subpq);
                    else
                        sp2 =
                            NULL;
                    if (sp->serial != is->subtitleq.serial || (is->vidclk.pts > (sp->pts + ((float)sp->sub.end_display_time / 1000))) || (sp2 && is->vidclk.pts > (sp2->pts + ((float)sp2->sub.start_display_time / 1000))))
                    {
                        if (sp->uploaded)
                        {
                            int i;
                            for (i = 0; i < sp->sub.num_rects; i++)
                            {
                                AVSubtitleRect *sub_rect = sp->sub.rects[i];
                                uint8_t *pixels;
                                int pitch, j;
                                if (!SDL_LockTexture(is->sub_texture, (SDL_Rect *)sub_rect, (void **)&pixels, &pitch))
                                {
                                    for (j = 0; j < sub_rect->h; j++, pixels += pitch)
                                        memset(pixels, 0, sub_rect->w << 2);
                                    SDL_UnlockTexture(is->sub_texture);
                                }
                            }
                        }
                        frame_queue_next(&is->subpq);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            frame_queue_next(&is->pictq);
            is->force_refresh = 1;
            if (is->step && !is->paused)
                stream_toggle_pause(is);
        }
    display:
        if (!display_disable && is->force_refresh && is->show_mode == SHOW_MODE_VIDEO && is->pictq.rindex_shown)
            video_display(is);
    }
    is->force_refresh = 0;
    if (show_status)
    {
        AVBPrint buf;
        static int64_t last_time;
        int64_t cur_time;
        int aqsize, vqsize, sqsize;
        double av_diff;
        cur_time = av_gettime_relative();
        if (!last_time || (cur_time - last_time) >= 30000)
        {
            aqsize = 0;
            vqsize = 0;
            sqsize = 0;
            if (is->audio_st)
                aqsize = is->audioq.size;
            if (is->video_st)
                vqsize = is->videoq.size;
            if (is->subtitle_st)
                sqsize = is->subtitleq.size;
            av_diff = 0;
            if (is->audio_st && is->video_st)
                av_diff = get_clock(&is->audclk) - get_clock(&is->vidclk);
            else if (is->video_st)
                av_diff = get_master_clock(is) - get_clock(&is->vidclk);
            else if (is->audio_st)
                av_diff = get_master_clock(is) - get_clock(&is->audclk);
            av_bprint_init(&buf, 0, 1);
            av_bprintf(&buf,
                       "%7.2f %s:%7.3f fd=%4d aq=%5dKB vq=%5dKB sq=%5dB f=%"
                       "I64d"
                       "/%"
                       "I64d"
                       "   \r",
                       get_master_clock(is),
                       (is->audio_st && is->video_st) ? "A-V" : (is->video_st ? "M-V" : (is->audio_st ? "M-A" : "   ")),
                       av_diff,
                       is->frame_drops_early + is->frame_drops_late,
                       aqsize / 1024,
                       vqsize / 1024,
                       sqsize,
                       is->video_st ? is->viddec.avctx->pts_correction_num_faulty_dts : 0,
                       is->video_st ? is->viddec.avctx->pts_correction_num_faulty_pts : 0);
            if (show_status == 1 && 32 > av_log_get_level())
                fprintf(
                    (&__iob_func()[2]), "%s", buf.str);
            else
                av_log(
                    NULL, 32, "%s", buf.str);
            fflush(
                (&__iob_func()[2]));
            av_bprint_finalize(&buf,
                               NULL);
            last_time = cur_time;
        }
    }
}

static int queue_picture(VideoState *is, AVFrame *src_frame, double pts, double duration, int64_t pos, int serial)
{
    Frame *vp;
    if (!(vp = frame_queue_peek_writable(&is->pictq)))
        return -1;
    vp->sar = src_frame->sample_aspect_ratio;
    vp->uploaded = 0;
    vp->width = src_frame->width;
    vp->height = src_frame->height;
    vp->format = src_frame->format;
    vp->pts = pts;
    vp->duration = duration;
    vp->pos = pos;
    vp->serial = serial;
    set_default_window_size(vp->width, vp->height, vp->sar);
    av_frame_move_ref(vp->frame, src_frame);
    frame_queue_push(&is->pictq);
    return 0;
}

static int get_video_frame(VideoState *is, AVFrame *frame)
{
    int got_picture;
    if ((got_picture = decoder_decode_frame(&is->viddec, frame,NULL)) < 0)
        return -1;
    if (got_picture != 0)
    {
        double dpts = NAN;
        if (frame->pts != 0)
            dpts = av_q2d(is->video_st->time_base) * frame->pts;
        frame->sample_aspect_ratio = av_guess_sample_aspect_ratio(is->ic, is->video_st, frame);
        if (framedrop > 0 || (framedrop && get_master_sync_type(is) != AV_SYNC_VIDEO_MASTER))
        {
            if (frame->pts != 0)
            {
                double diff = dpts - get_master_clock(is);
                if (!isnan(diff) && fabs(diff) < AV_NOSYNC_THRESHOLD && diff - is->frame_last_filter_delay < 0 && is->viddec.pkt_serial == is->vidclk.serial && is->videoq.nb_packets) {
                    is->frame_drops_early++;
                    av_frame_unref(frame);
                    got_picture = 0;
                }
            }
        }
    }
    return got_picture;
}

static int configure_filtergraph(AVFilterGraph *graph, const char *filtergraph,
                                 AVFilterContext *source_ctx, AVFilterContext *sink_ctx)
{
    int ret, i;
    int nb_filters = graph->nb_filters;
    AVFilterInOut *outputs = NULL,
                  *inputs = NULL;
    if (filtergraph)
    {
        outputs = avfilter_inout_alloc();
        inputs = avfilter_inout_alloc();
        if (!outputs || !inputs)
        {
            ret = (-12);
            goto fail;
        }
        outputs->name = av_strdup("in");
        outputs->filter_ctx = source_ctx;
        outputs->pad_idx = 0;
        outputs->next = NULL;
        inputs->name = av_strdup("out");
        inputs->filter_ctx = sink_ctx;
        inputs->pad_idx = 0;
        inputs->next =
            NULL;
        if ((ret = avfilter_graph_parse_ptr(graph, filtergraph, &inputs, &outputs, NULL)) < 0)
            goto fail;
    }
    else
    {
        if ((ret = avfilter_link(source_ctx, 0, sink_ctx, 0)) < 0)
            goto fail;
    }
    for (i = 0; i < graph->nb_filters - nb_filters; i++)
        do
        {
            AVFilterContext *SWAP_tmp = graph->filters[i + nb_filters];
            graph->filters[i + nb_filters] = graph->filters[i];
            graph->filters[i] = SWAP_tmp;
        } while (0);
    ret = avfilter_graph_config(graph,
                                NULL);
fail:
    avfilter_inout_free(&outputs);
    avfilter_inout_free(&inputs);
    return ret;
}
#define INSERT_FILT(name, arg)                                                                                       \
    do                                                                                                               \
    {                                                                                                                \
        AVFilterContext *filt_ctx;                                                                                   \
        ret = avfilter_graph_create_filter(&filt_ctx, avfilter_get_by_name(name), "ffplay_" name, arg, NULL, graph); \
        if (ret < 0)                                                                                                 \
            goto fail;                                                                                               \
        ret = avfilter_link(filt_ctx, 0, last_filter, 0);                                                            \
        if (ret < 0)                                                                                                 \
            goto fail;                                                                                               \
        last_filter = filt_ctx;                                                                                      \
    } while (0)

static int configure_video_filters(AVFilterGraph *graph, VideoState *is, const char *vfilters, AVFrame *frame)
{
    enum AVPixelFormat pix_fmts[(sizeof(sdl_texture_format_map) / sizeof((sdl_texture_format_map)[0]))];
    char sws_flags_str[512] = "";
    char buffersrc_args[256];
    int ret;
    AVFilterContext *filt_src = NULL,
                    *filt_out = NULL,
                    *last_filter = NULL;
    AVCodecParameters *codecpar = is->video_st->codecpar;
    AVRational fr = av_guess_frame_rate(is->ic, is->video_st, NULL);
    AVDictionaryEntry *e = NULL;
    int nb_pix_fmts = 0;
    int i, j;
    for (i = 0; i < renderer_info.num_texture_formats; i++)
    {
        for (j = 0; j < (sizeof(sdl_texture_format_map) / sizeof((sdl_texture_format_map)[0])) - 1; j++)
        {
            if (renderer_info.texture_formats[i] == sdl_texture_format_map[j].texture_fmt)
            {
                pix_fmts[nb_pix_fmts++] = sdl_texture_format_map[j].format;
                break;
            }
        }
    }
    pix_fmts[nb_pix_fmts] = AV_PIX_FMT_NONE;
    while ((e = av_dict_get(sws_dict, "", e, 2)))
    {
        if (!strcmp(e->key, "sws_flags"))
        {
            av_strlcatf(sws_flags_str, sizeof(sws_flags_str), "%s=%s:", "flags", e->value);
        }
        else
            av_strlcatf(sws_flags_str, sizeof(sws_flags_str), "%s=%s:", e->key, e->value);
    }
    if (strlen(sws_flags_str))
        sws_flags_str[strlen(sws_flags_str) - 1] = '\0';
    graph->scale_sws_opts = av_strdup(sws_flags_str);
    snprintf(buffersrc_args, sizeof(buffersrc_args),
             "video_size=%dx%d:pix_fmt=%d:time_base=%d/%d:pixel_aspect=%d/%d",
             frame->width, frame->height, frame->format,
             is->video_st->time_base.num, is->video_st->time_base.den,
             codecpar->sample_aspect_ratio.num, ((codecpar->sample_aspect_ratio.den) > (1) ? (codecpar->sample_aspect_ratio.den) : (1)));
    if (fr.num && fr.den)
        av_strlcatf(buffersrc_args, sizeof(buffersrc_args), ":frame_rate=%d/%d", fr.num, fr.den);
    if ((ret = avfilter_graph_create_filter(&filt_src,
                                            avfilter_get_by_name("buffer"),
                                            "ffplay_buffer", buffersrc_args,
                                            NULL,
                                            graph)) < 0)
        goto fail;
    ret = avfilter_graph_create_filter(&filt_out,
                                       avfilter_get_by_name("buffersink"),
                                       "ffplay_buffersink",
                                       NULL,
                                       NULL, graph);
    if (ret < 0)
        goto fail;
    if ((ret = (av_int_list_length_for_size(sizeof(*(pix_fmts)), pix_fmts, AV_PIX_FMT_NONE) > 0x7fffffff / sizeof(*(pix_fmts)) ? (-22)
                                                                                                                               : av_opt_set_bin(filt_out, "pix_fmts", (const uint8_t *)(pix_fmts), av_int_list_length_for_size(sizeof(*(pix_fmts)), pix_fmts, AV_PIX_FMT_NONE) * sizeof(*(pix_fmts)), (1 << 0)))) < 0)
        goto fail;
    last_filter = filt_out;
    if (autorotate)
    {
        double theta = get_rotation(is->video_st);
        if (fabs(theta - 90) < 1.0)
        {
            
                AVFilterContext *filt_ctx;
                ret = avfilter_graph_create_filter(&filt_ctx, avfilter_get_by_name("transpose"), "ffplay_transpose","clock",NULL, graph);
                if (ret < 0)
                    goto fail;
                ret = avfilter_link(filt_ctx, 0, last_filter, 0);
                if (ret < 0)
                    goto fail;
                last_filter = filt_ctx;
        }
        else if (fabs(theta - 180) < 1.0)
        {
            
                AVFilterContext *filt_ctx;
                ret = avfilter_graph_create_filter(&filt_ctx, avfilter_get_by_name("hflip"), "ffplay_hflip",NULL,NULL, graph);
                if (ret < 0)
                    goto fail;
                ret = avfilter_link(filt_ctx, 0, last_filter, 0);
                if (ret < 0)
                    goto fail;
                last_filter = filt_ctx;
          
                ret = avfilter_graph_create_filter(&filt_ctx, avfilter_get_by_name("vflip"), "ffplay_vflip",NULL,NULL, graph);
                if (ret < 0)
                    goto fail;
                ret = avfilter_link(filt_ctx, 0, last_filter, 0);
                if (ret < 0)
                    goto fail;
                last_filter = filt_ctx;
        }
        else if (fabs(theta - 270) < 1.0)
        {
      
                AVFilterContext *filt_ctx;
                ret = avfilter_graph_create_filter(&filt_ctx, avfilter_get_by_name("transpose"), "ffplay_transpose","cclock",NULL, graph);
                if (ret < 0)
                    goto fail;
                ret = avfilter_link(filt_ctx, 0, last_filter, 0);
                if (ret < 0)
                    goto fail;
                last_filter = filt_ctx;
        }
        else if (fabs(theta) > 1.0)
        {
            char rotate_buf[64];
            snprintf(rotate_buf, sizeof(rotate_buf), "%f*PI/180", theta);
     
                AVFilterContext *filt_ctx;
                ret = avfilter_graph_create_filter(&filt_ctx, avfilter_get_by_name("rotate"), "ffplay_rotate",rotate_buf,NULL, graph);
                if (ret < 0)
                    goto fail;
                ret = avfilter_link(filt_ctx, 0, last_filter, 0);
                if (ret < 0)
                    goto fail;
                last_filter = filt_ctx;
        }
    }
    if ((ret = configure_filtergraph(graph, vfilters, filt_src, last_filter)) < 0)
        goto fail;
    is->in_video_filter = filt_src;
    is->out_video_filter = filt_out;

fail:
    return ret;
}

static int configure_audio_filters(VideoState *is, const char *afilters, int force_output_format)
{
    static const enum AVSampleFormat sample_fmts[] = {AV_SAMPLE_FMT_S16, AV_SAMPLE_FMT_NONE};
    int sample_rates[2] = {0, -1};
    int64_t channel_layouts[2] = {0, -1};
    int channels[2] = {0, -1};
    AVFilterContext *filt_asrc =
                        NULL,
                    *filt_asink =
                        NULL;
    char aresample_swr_opts[512] = "";
    AVDictionaryEntry *e =
        NULL;
    char asrc_args[256];
    int ret;
    avfilter_graph_free(&is->agraph);
    if (!(is->agraph = avfilter_graph_alloc()))
        return (-(12));
    is->agraph->nb_threads = filter_nbthreads;
    while ((e = av_dict_get(swr_opts, "", e, 2)))
        av_strlcatf(aresample_swr_opts, sizeof(aresample_swr_opts), "%s=%s:", e->key, e->value);
    if (strlen(aresample_swr_opts))
        aresample_swr_opts[strlen(aresample_swr_opts) - 1] = '\0';
    av_opt_set(is->agraph, "aresample_swr_opts", aresample_swr_opts, 0);
    ret = snprintf(asrc_args, sizeof(asrc_args),
                   "sample_rate=%d:sample_fmt=%s:channels=%d:time_base=%d/%d",
                   is->audio_filter_src.freq, av_get_sample_fmt_name(is->audio_filter_src.fmt),
                   is->audio_filter_src.channels,
                   1, is->audio_filter_src.freq);
    if (is->audio_filter_src.channel_layout)
        snprintf(asrc_args + ret, sizeof(asrc_args) - ret,
                 ":channel_layout=0x%"
                 "I64x",
                 is->audio_filter_src.channel_layout);
    ret = avfilter_graph_create_filter(&filt_asrc,
                                       avfilter_get_by_name("abuffer"), "ffplay_abuffer",
                                       asrc_args,
                                       NULL, is->agraph);
    if (ret < 0)
        goto end;
    ret = avfilter_graph_create_filter(&filt_asink,
                                       avfilter_get_by_name("abuffersink"), "ffplay_abuffersink",
                                       NULL,
                                       NULL, is->agraph);
    if (ret < 0)
        goto end;
    if ((ret = (av_int_list_length_for_size(sizeof(*(sample_fmts)), sample_fmts, AV_SAMPLE_FMT_NONE) > 0x7fffffff / sizeof(*(sample_fmts)) ? (-(22))
                                                                                                                                           : av_opt_set_bin(filt_asink, "sample_fmts", (const uint8_t *)(sample_fmts), av_int_list_length_for_size(sizeof(*(sample_fmts)), sample_fmts, AV_SAMPLE_FMT_NONE) * sizeof(*(sample_fmts)), (1 << 0)
                                                                                                                                                                ))) < 0)
        goto end;
    if ((ret = av_opt_set_int(filt_asink, "all_channel_counts", 1, (1 << 0))) < 0)
        goto end;
    if (force_output_format)
    {
        channel_layouts[0] = is->audio_tgt.channel_layout;
        channels[0] = is->audio_tgt.channel_layout ? -1 : is->audio_tgt.channels;
        sample_rates[0] = is->audio_tgt.freq;
        if ((ret = av_opt_set_int(filt_asink, "all_channel_counts", 0, (1 << 0))) < 0)
            goto end;
        if ((ret = (av_int_list_length_for_size(sizeof(*(channel_layouts)), channel_layouts, -1) > 0x7fffffff / sizeof(*(channel_layouts)) ? (-(
                                                                                                                                                 22))
                                                                                                                                           : av_opt_set_bin(filt_asink, "channel_layouts", (const uint8_t *)(channel_layouts), av_int_list_length_for_size(sizeof(*(channel_layouts)), channel_layouts, -1) * sizeof(*(channel_layouts)), (1 << 0)
                                                                                                                                                                ))) < 0)
            goto end;
        if ((ret = (av_int_list_length_for_size(sizeof(*(channels)), channels, -1) > 0x7fffffff / sizeof(*(channels)) ? (-(
                                                                                                                            22))
                                                                                                                      : av_opt_set_bin(filt_asink, "channel_counts", (const uint8_t *)(channels), av_int_list_length_for_size(sizeof(*(channels)), channels, -1) * sizeof(*(channels)), (1 << 0)
                                                                                                                                           ))) < 0)
            goto end;
        if ((ret = (av_int_list_length_for_size(sizeof(*(sample_rates)), sample_rates, -1) > 0x7fffffff / sizeof(*(sample_rates)) ? (-(
                                                                                                                                        22))
                                                                                                                                  : av_opt_set_bin(filt_asink, "sample_rates", (const uint8_t *)(sample_rates), av_int_list_length_for_size(sizeof(*(sample_rates)), sample_rates, -1) * sizeof(*(sample_rates)), (1 << 0)
                                                                                                                                                       ))) < 0)
            goto end;
    }
    if ((ret = configure_filtergraph(is->agraph, afilters, filt_asrc, filt_asink)) < 0)
        goto end;
    is->in_audio_filter = filt_asrc;
    is->out_audio_filter = filt_asink;

end:
    if (ret < 0)
        avfilter_graph_free(&is->agraph);
    return ret;
}

static int audio_thread(void *arg)
{
    VideoState *is = arg;
    AVFrame *frame = av_frame_alloc();
    Frame *af;
    int last_serial = -1;
    int64_t dec_channel_layout;
    int reconfigure;
    int got_frame = 0;
    AVRational tb;
    int ret = 0;

    do
    {
        if ((got_frame = decoder_decode_frame(&is->auddec, frame,NULL)) < 0)
            goto the_end;
        if (got_frame)
        {
            tb = (AVRational){1, frame->sample_rate};
            dec_channel_layout = get_valid_channel_layout(frame->channel_layout, frame->channels);
            reconfigure =
                cmp_audio_fmts(is->audio_filter_src.fmt, is->audio_filter_src.channels,frame->format, frame->channels) ||
                is->audio_filter_src.channel_layout != dec_channel_layout ||
                is->audio_filter_src.freq != frame->sample_rate ||
                is->auddec.pkt_serial != last_serial;
            if (reconfigure)
            {
                char buf1[1024], buf2[1024];
                av_get_channel_layout_string(buf1, sizeof(buf1), -1, is->audio_filter_src.channel_layout);
                av_get_channel_layout_string(buf2, sizeof(buf2), -1, dec_channel_layout);
                av_log(
                    NULL, 48,
                    "Audio frame changed from rate:%d ch:%d fmt:%s layout:%s serial:%d to rate:%d ch:%d fmt:%s layout:%s serial:%d\n",
                    is->audio_filter_src.freq, is->audio_filter_src.channels, av_get_sample_fmt_name(is->audio_filter_src.fmt), buf1, last_serial,
                    frame->sample_rate, frame->channels, av_get_sample_fmt_name(frame->format), buf2, is->auddec.pkt_serial);
                is->audio_filter_src.fmt = frame->format;
                is->audio_filter_src.channels = frame->channels;
                is->audio_filter_src.channel_layout = dec_channel_layout;
                is->audio_filter_src.freq = frame->sample_rate;
                last_serial = is->auddec.pkt_serial;
                if ((ret = configure_audio_filters(is, afilters, 1)) < 0)
                    goto the_end;
            }
            if ((ret = av_buffersrc_add_frame(is->in_audio_filter, frame)) < 0)
                goto the_end;
            while ((ret = av_buffersink_get_frame_flags(is->out_audio_filter, frame, 0)) >= 0)
            {
                tb = av_buffersink_get_time_base(is->out_audio_filter);
                if (!(af = frame_queue_peek_writable(&is->sampq)))
                    goto the_end;
                af->pts = (frame->pts == 0) ? NAN : frame->pts * av_q2d(tb);
                af->pos = frame->pkt_pos;
                af->serial = is->auddec.pkt_serial;
                af->duration = av_q2d((AVRational){frame->nb_samples, frame->sample_rate});
                av_frame_move_ref(af->frame, frame);
                frame_queue_push(&is->sampq);
                if (is->audioq.serial != is->auddec.pkt_serial)
                    break;
            }
            if (ret == (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24))))
                is->auddec.finished = is->auddec.pkt_serial;
        }
    } while (ret >= 0 || ret == (-(11)) || ret == (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24))));
the_end:
    avfilter_graph_free(&is->agraph);
    av_frame_free(&frame);
    return ret;
}

static int decoder_start(Decoder *d, int (*fn)(void *), const char *thread_name, void *arg)
{
    packet_queue_start(d->queue);
    d->decoder_tid = SDL_CreateThread(fn, thread_name, arg);
    if (!d->decoder_tid)
    {
        av_log(NULL, 16, "SDL_CreateThread(): %s\n", SDL_GetError());
        return (-(
            12));
    }
    return 0;
}

static int video_thread(void *arg)
{
    VideoState *is = arg;
    AVFrame *frame = av_frame_alloc();
    double pts;
    double duration;
    int ret;
    AVRational tb = is->video_st->time_base;
    AVRational frame_rate = av_guess_frame_rate(is->ic, is->video_st, NULL);
    AVFilterGraph *graph = NULL;
    AVFilterContext *filt_out = NULL, *filt_in = NULL;
    int last_w = 0;
    int last_h = 0;
    enum AVPixelFormat last_format = -2;
    int last_serial = -1;
    int last_vfilter_idx = 0;
    if (!frame)
        return (-(12));
    for (;;)
    {
        ret = get_video_frame(is, frame);
        if (ret < 0)
            goto the_end;
        if (!ret)
            continue;
        if (last_w != frame->width || last_h != frame->height || last_format != frame->format || last_serial != is->viddec.pkt_serial || last_vfilter_idx != is->vfilter_idx)
        {
            av_log(
                NULL, 48,
                "Video frame changed from size:%dx%d format:%s serial:%d to size:%dx%d format:%s serial:%d\n",
                last_w, last_h,
                (const char *)av_x_if_null(av_get_pix_fmt_name(last_format), "none"), last_serial,
                frame->width, frame->height,
                (const char *)av_x_if_null(av_get_pix_fmt_name(frame->format), "none"), is->viddec.pkt_serial);
            avfilter_graph_free(&graph);
            graph = avfilter_graph_alloc();
            if (!graph)
            {
                ret = (-(
                    12));
                goto the_end;
            }
            graph->nb_threads = filter_nbthreads;
            if ((ret = configure_video_filters(graph, is, vfilters_list ? vfilters_list[is->vfilter_idx] : NULL, frame)) < 0)
            {
                SDL_Event event;
                event.type = (SDL_USEREVENT + 2);
                event.user.data1 = is;
                SDL_PushEvent(&event);
                goto the_end;
            }
            filt_in = is->in_video_filter;
            filt_out = is->out_video_filter;
            last_w = frame->width;
            last_h = frame->height;
            last_format = frame->format;
            last_serial = is->viddec.pkt_serial;
            last_vfilter_idx = is->vfilter_idx;
            frame_rate = av_buffersink_get_frame_rate(filt_out);
        }
        ret = av_buffersrc_add_frame(filt_in, frame);
        if (ret < 0)
            goto the_end;
        while (ret >= 0)
        {
            is->frame_last_returned_time = av_gettime_relative() / 1000000.0;
            ret = av_buffersink_get_frame_flags(filt_out, frame, 0);
            if (ret < 0)
            {
                if (ret == (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24))))
                    is->viddec.finished = is->viddec.pkt_serial;
                ret = 0;
                break;
            }
            is->frame_last_filter_delay = av_gettime_relative() / 1000000.0 - is->frame_last_returned_time;
            if (fabs(is->frame_last_filter_delay) > 10.0 / 10.0)
                is->frame_last_filter_delay = 0;
            tb = av_buffersink_get_time_base(filt_out);
            duration = (frame_rate.num && frame_rate.den ? av_q2d((AVRational){frame_rate.den, frame_rate.num}) : 0);
            pts = (frame->pts == 0) ? NAN
                                                                   : frame->pts * av_q2d(tb);
            ret = queue_picture(is, frame, pts, duration, frame->pkt_pos, is->viddec.pkt_serial);
            av_frame_unref(frame);
            if (is->videoq.serial != is->viddec.pkt_serial)
                break;
        }
        if (ret < 0)
            goto the_end;
    }
the_end:
    avfilter_graph_free(&graph);
    av_frame_free(&frame);
    return 0;
}

static int subtitle_thread(void *arg)
{
    VideoState *is = arg;
    Frame *sp;
    int got_subtitle;
    double pts;
    for (;;)
    {
        if (!(sp = frame_queue_peek_writable(&is->subpq)))
            return 0;
        if ((got_subtitle = decoder_decode_frame(&is->subdec,
                                                 NULL, &sp->sub)) < 0)
            break;
        pts = 0;
        if (got_subtitle && sp->sub.format == 0)
        {
            if (sp->sub.pts != 0)
                pts = sp->sub.pts / (double)1000000;
            sp->pts = pts;
            sp->serial = is->subdec.pkt_serial;
            sp->width = is->subdec.avctx->width;
            sp->height = is->subdec.avctx->height;
            sp->uploaded = 0;
            frame_queue_push(&is->subpq);
        }
        else if (got_subtitle)
        {
            avsubtitle_free(&sp->sub);
        }
    }
    return 0;
}

static void update_sample_display(VideoState *is, short *samples, int samples_size)
{
    int size, len;
    size = samples_size / sizeof(short);
    while (size > 0)
    {
        len = (8 * 65536) - is->sample_array_index;
        if (len > size)
            len = size;
        memcpy(is->sample_array + is->sample_array_index, samples, len * sizeof(short));
        samples += len;
        is->sample_array_index += len;
        if (is->sample_array_index >= (8 * 65536))
            is->sample_array_index = 0;
        size -= len;
    }
}

static int synchronize_audio(VideoState *is, int nb_samples)
{
    int wanted_nb_samples = nb_samples;
    if (get_master_sync_type(is) != AV_SYNC_AUDIO_MASTER)
    {
        double diff, avg_diff;
        int min_nb_samples, max_nb_samples;
        diff = get_clock(&is->audclk) - get_master_clock(is);
        if (!isnan(diff) && fabs(diff) < 10.0)
        {
            is->audio_diff_cum = diff + is->audio_diff_avg_coef * is->audio_diff_cum;
            if (is->audio_diff_avg_count < 20)
            {
                is->audio_diff_avg_count++;
            }
            else
            {
                avg_diff = is->audio_diff_cum * (1.0 - is->audio_diff_avg_coef);
                if (fabs(avg_diff) >= is->audio_diff_threshold)
                {
                    wanted_nb_samples = nb_samples + (int)(diff * is->audio_src.freq);
                    min_nb_samples = ((nb_samples * (100 - 10) / 100));
                    max_nb_samples = ((nb_samples * (100 + 10) / 100));
                    wanted_nb_samples = av_clip_c(wanted_nb_samples, min_nb_samples, max_nb_samples);
                }
                av_log(
                    NULL, 56, "diff=%f adiff=%f sample_diff=%d apts=%0.3f %f\n",
                    diff, avg_diff, wanted_nb_samples - nb_samples,
                    is->audio_clock, is->audio_diff_threshold);
            }
        }
        else
        {
            is->audio_diff_avg_count = 0;
            is->audio_diff_cum = 0;
        }
    }
    return wanted_nb_samples;
}

static int audio_decode_frame(VideoState *is)
{
    int data_size, resampled_data_size;
    int64_t dec_channel_layout;
    double audio_clock0;
    int wanted_nb_samples;
    Frame *af;
    if (is->paused)
        return -1;
    do
    {
        while (frame_queue_nb_remaining(&is->sampq) == 0)
        {
            if ((av_gettime_relative() - audio_callback_time) > 1000000LL * is->audio_hw_buf_size / is->audio_tgt.bytes_per_sec / 2)
                return -1;
            av_usleep(1000);
        }
        if (!(af = frame_queue_peek_readable(&is->sampq)))
            return -1;
        frame_queue_next(&is->sampq);
    } while (af->serial != is->audioq.serial);
    data_size = av_samples_get_buffer_size(
        NULL, af->frame->channels,
        af->frame->nb_samples,
        af->frame->format, 1);
    dec_channel_layout =
        (af->frame->channel_layout && af->frame->channels == av_get_channel_layout_nb_channels(af->frame->channel_layout)) ? af->frame->channel_layout : av_get_default_channel_layout(af->frame->channels);
    wanted_nb_samples = synchronize_audio(is, af->frame->nb_samples);
    if (af->frame->format != is->audio_src.fmt ||
        dec_channel_layout != is->audio_src.channel_layout ||
        af->frame->sample_rate != is->audio_src.freq ||
        (wanted_nb_samples != af->frame->nb_samples && !is->swr_ctx))
    {
        swr_free(&is->swr_ctx);
        is->swr_ctx = swr_alloc_set_opts(
            NULL,
            is->audio_tgt.channel_layout, is->audio_tgt.fmt, is->audio_tgt.freq,
            dec_channel_layout, af->frame->format, af->frame->sample_rate,
            0,
            NULL);
        if (!is->swr_ctx || swr_init(is->swr_ctx) < 0)
        {
            av_log(
                NULL, 16,
                "Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!\n",
                af->frame->sample_rate, av_get_sample_fmt_name(af->frame->format), af->frame->channels,
                is->audio_tgt.freq, av_get_sample_fmt_name(is->audio_tgt.fmt), is->audio_tgt.channels);
            swr_free(&is->swr_ctx);
            return -1;
        }
        is->audio_src.channel_layout = dec_channel_layout;
        is->audio_src.channels = af->frame->channels;
        is->audio_src.freq = af->frame->sample_rate;
        is->audio_src.fmt = af->frame->format;
    }
    if (is->swr_ctx)
    {
        const uint8_t **in = (const uint8_t **)af->frame->extended_data;
        uint8_t **out = &is->audio_buf1;
        int out_count = (int64_t)wanted_nb_samples * is->audio_tgt.freq / af->frame->sample_rate + 256;
        int out_size = av_samples_get_buffer_size(
            NULL, is->audio_tgt.channels, out_count, is->audio_tgt.fmt, 0);
        int len2;
        if (out_size < 0)
        {
            av_log(
                NULL, 16, "av_samples_get_buffer_size() failed\n");
            return -1;
        }
        if (wanted_nb_samples != af->frame->nb_samples)
        {
            if (swr_set_compensation(is->swr_ctx, (wanted_nb_samples - af->frame->nb_samples) * is->audio_tgt.freq / af->frame->sample_rate,
                                     wanted_nb_samples * is->audio_tgt.freq / af->frame->sample_rate) < 0)
            {
                av_log(
                    NULL, 16, "swr_set_compensation() failed\n");
                return -1;
            }
        }
        av_fast_malloc(&is->audio_buf1, &is->audio_buf1_size, out_size);
        if (!is->audio_buf1)
            return (-(
                12));
        len2 = swr_convert(is->swr_ctx, out, out_count, in, af->frame->nb_samples);
        if (len2 < 0)
        {
            av_log(
                NULL, 16, "swr_convert() failed\n");
            return -1;
        }
        if (len2 == out_count)
        {
            av_log(
                NULL, 24, "audio buffer is probably too small\n");
            if (swr_init(is->swr_ctx) < 0)
                swr_free(&is->swr_ctx);
        }
        is->audio_buf = is->audio_buf1;
        resampled_data_size = len2 * is->audio_tgt.channels * av_get_bytes_per_sample(is->audio_tgt.fmt);
    }
    else
    {
        is->audio_buf = af->frame->data[0];
        resampled_data_size = data_size;
    }
    audio_clock0 = is->audio_clock;
    if (!isnan(af->pts))
        is->audio_clock = af->pts + (double)af->frame->nb_samples / af->frame->sample_rate;
    else
        is->audio_clock = NAN;
    is->audio_clock_serial = af->serial;
    return resampled_data_size;
}

static void sdl_audio_callback(void *opaque, Uint8 *stream, int len)
{
    VideoState *is = opaque;
    int audio_size, len1;
    audio_callback_time = av_gettime_relative();
    while (len > 0)
    {
        if (is->audio_buf_index >= is->audio_buf_size)
        {
            audio_size = audio_decode_frame(is);
            if (audio_size < 0)
            {
                is->audio_buf =
                    NULL;
                is->audio_buf_size = 512 / is->audio_tgt.frame_size * is->audio_tgt.frame_size;
            }
            else
            {
                if (is->show_mode != SHOW_MODE_VIDEO)
                    update_sample_display(is, (int16_t *)is->audio_buf, audio_size);
                is->audio_buf_size = audio_size;
            }
            is->audio_buf_index = 0;
        }
        len1 = is->audio_buf_size - is->audio_buf_index;
        if (len1 > len)
            len1 = len;
        if (!is->muted && is->audio_buf && is->audio_volume == 128)
            memcpy(stream, (uint8_t *)is->audio_buf + is->audio_buf_index, len1);
        else
        {
            memset(stream, 0, len1);
            if (!is->muted && is->audio_buf)
                SDL_MixAudioFormat(stream, (uint8_t *)is->audio_buf + is->audio_buf_index, 0x8010, len1, is->audio_volume);
        }
        len -= len1;
        stream += len1;
        is->audio_buf_index += len1;
    }
    is->audio_write_buf_size = is->audio_buf_size - is->audio_buf_index;
    if (!isnan(is->audio_clock))
    {
        set_clock_at(&is->audclk, is->audio_clock - (double)(2 * is->audio_hw_buf_size + is->audio_write_buf_size) / is->audio_tgt.bytes_per_sec, is->audio_clock_serial, audio_callback_time / 1000000.0);
        sync_clock_to_slave(&is->extclk, &is->audclk);
    }
}

static int audio_open(void *opaque, int64_t wanted_channel_layout, int wanted_nb_channels, int wanted_sample_rate, struct AudioParams *audio_hw_params)
{
    SDL_AudioSpec wanted_spec, spec;
    const char *env;
    static const int next_nb_channels[] = {0, 0, 1, 6, 2, 6, 4, 6};
    static const int next_sample_rates[] = {0, 44100, 48000, 96000, 192000};
    int next_sample_rate_idx = (sizeof(next_sample_rates) / sizeof((next_sample_rates)[0])) - 1;
    env = SDL_getenv("SDL_AUDIO_CHANNELS");
    if (env)
    {
        wanted_nb_channels = atoi(env);
        wanted_channel_layout = av_get_default_channel_layout(wanted_nb_channels);
    }
    if (!wanted_channel_layout || wanted_nb_channels != av_get_channel_layout_nb_channels(wanted_channel_layout))
    {
        wanted_channel_layout = av_get_default_channel_layout(wanted_nb_channels);
        wanted_channel_layout &= ~(0x20000000 | 0x40000000);
    }
    wanted_nb_channels = av_get_channel_layout_nb_channels(wanted_channel_layout);
    wanted_spec.channels = wanted_nb_channels;
    wanted_spec.freq = wanted_sample_rate;
    if (wanted_spec.freq <= 0 || wanted_spec.channels <= 0)
    {
        av_log(
            NULL, 16, "Invalid sample rate or channel count!\n");
        return -1;
    }
    while (next_sample_rate_idx && next_sample_rates[next_sample_rate_idx] >= wanted_spec.freq)
        next_sample_rate_idx--;
    wanted_spec.format = 0x8010;
    wanted_spec.silence = 0;
    wanted_spec.samples = ((512) > (2 << av_log2(wanted_spec.freq / 30)) ? (512) : (2 << av_log2(wanted_spec.freq / 30)));
    wanted_spec.callback = sdl_audio_callback;
    wanted_spec.userdata = opaque;
    while (!(audio_dev = SDL_OpenAudioDevice(
                 NULL, 0, &wanted_spec, &spec, 0x00000001 | 0x00000004)))
    {
        av_log(
            NULL, 24, "SDL_OpenAudio (%d channels, %d Hz): %s\n",
            wanted_spec.channels, wanted_spec.freq, SDL_GetError());
        wanted_spec.channels = next_nb_channels[((7) > (wanted_spec.channels) ? (wanted_spec.channels) : (7))];
        if (!wanted_spec.channels)
        {
            wanted_spec.freq = next_sample_rates[next_sample_rate_idx--];
            wanted_spec.channels = wanted_nb_channels;
            if (!wanted_spec.freq)
            {
                av_log(
                    NULL, 16,
                    "No more combinations to try, audio open failed\n");
                return -1;
            }
        }
        wanted_channel_layout = av_get_default_channel_layout(wanted_spec.channels);
    }
    if (spec.format != 0x8010)
    {
        av_log(
            NULL, 16,
            "SDL advised audio format %d is not supported!\n", spec.format);
        return -1;
    }
    if (spec.channels != wanted_spec.channels)
    {
        wanted_channel_layout = av_get_default_channel_layout(spec.channels);
        if (!wanted_channel_layout)
        {
            av_log(
                NULL, 16,
                "SDL advised channel count %d is not supported!\n", spec.channels);
            return -1;
        }
    }
    audio_hw_params->fmt = AV_SAMPLE_FMT_S16;
    audio_hw_params->freq = spec.freq;
    audio_hw_params->channel_layout = wanted_channel_layout;
    audio_hw_params->channels = spec.channels;
    audio_hw_params->frame_size = av_samples_get_buffer_size(
        NULL, audio_hw_params->channels, 1, audio_hw_params->fmt, 1);
    audio_hw_params->bytes_per_sec = av_samples_get_buffer_size(
        NULL, audio_hw_params->channels, audio_hw_params->freq, audio_hw_params->fmt, 1);
    if (audio_hw_params->bytes_per_sec <= 0 || audio_hw_params->frame_size <= 0)
    {
        av_log(NULL, 16, "av_samples_get_buffer_size failed\n");
        return -1;
    }
    return spec.size;
}
AVDictionary *filter_codec_opts(AVDictionary *opts, enum AVCodecID codec_id,
                                AVFormatContext *s, AVStream *st, AVCodec *codec);
static int stream_component_open(VideoState *is, int stream_index)
{
    AVFormatContext *ic = is->ic;
    AVCodecContext *avctx;
    AVCodec *codec;
    const char *forced_codec_name = NULL;
    AVDictionary *opts = NULL;
    AVDictionaryEntry *t = NULL;
    int sample_rate, nb_channels;
    int64_t channel_layout;
    int ret = 0;
    int stream_lowres = lowres;
    if (stream_index < 0 || stream_index >= ic->nb_streams)
        return -1;
    avctx = avcodec_alloc_context3(NULL);
    if (avctx == NULL)
        return (-(12));
    ret = avcodec_parameters_to_context(avctx, ic->streams[stream_index]->codecpar);
    if (ret < 0)
        goto fail;
    avctx->pkt_timebase = ic->streams[stream_index]->time_base;
    codec = avcodec_find_decoder(avctx->codec_id);
    switch (avctx->codec_type)
    {
    case AVMEDIA_TYPE_AUDIO:
        is->last_audio_stream = stream_index;
        forced_codec_name = audio_codec_name;
        break;
    case AVMEDIA_TYPE_SUBTITLE:
        is->last_subtitle_stream = stream_index;
        forced_codec_name = subtitle_codec_name;
        break;
    case AVMEDIA_TYPE_VIDEO:
        is->last_video_stream = stream_index;
        forced_codec_name = video_codec_name;
        break;
    }
    if (forced_codec_name)
        codec = avcodec_find_decoder_by_name(forced_codec_name);
    if (codec == NULL)
    {
        if (forced_codec_name != NULL)
            av_log(NULL, 24,"No codec could be found with name '%s'\n", forced_codec_name);
        else
            av_log(NULL, 24,"No decoder could be found for codec %s\n", avcodec_get_name(avctx->codec_id));
        ret = (-(22));
        goto fail;
    }
    avctx->codec_id = codec->id;
    if (stream_lowres > codec->max_lowres)
    {
        av_log(avctx, 24, "The maximum value for lowres supported by the decoder is %d\n",codec->max_lowres);
        stream_lowres = codec->max_lowres;
    }
    avctx->lowres = stream_lowres;
    if (fast != 0)
        avctx->flags2 |= (1 << 0);
    opts = filter_codec_opts(codec_opts, avctx->codec_id, ic, ic->streams[stream_index], codec);
    t = av_dict_get(opts, "threads",NULL, 0);
    if (t == NULL)
        av_dict_set(&opts, "threads", "auto", 0);
    if (stream_lowres != 0)
        av_dict_set_int(&opts, "lowres", stream_lowres, 0);
    if (avctx->codec_type == AVMEDIA_TYPE_VIDEO || avctx->codec_type == AVMEDIA_TYPE_AUDIO)
        av_dict_set(&opts, "refcounted_frames", "1", 0);
    ret = avcodec_open2(avctx, codec, &opts);
    if ( ret< 0)
    {
        goto fail;
    }
    t = av_dict_get(opts, "",NULL, 2);
    if (t != NULL)
    {
        av_log(NULL, 16, "Option %s not found.\n", t->key);
        ret = (-(int)((0xF8) | (('O') << 8) | (('P') << 16) | ((unsigned)('T') << 24)));
        goto fail;
    }
    is->eof = 0;
    ic->streams[stream_index]->discard = AVDISCARD_DEFAULT;
    switch (avctx->codec_type)
    {
    case AVMEDIA_TYPE_AUDIO:
    {
        AVFilterContext *sink;
        is->audio_filter_src.freq = avctx->sample_rate;
        is->audio_filter_src.channels = avctx->channels;
        is->audio_filter_src.channel_layout = get_valid_channel_layout(avctx->channel_layout, avctx->channels);
        is->audio_filter_src.fmt = avctx->sample_fmt;
        ret = configure_audio_filters(is, afilters, 0);
        if (ret < 0)
            goto fail;
        sink = is->out_audio_filter;
        sample_rate = av_buffersink_get_sample_rate(sink);
        nb_channels = av_buffersink_get_channels(sink);
        channel_layout = av_buffersink_get_channel_layout(sink);
    }
    ret = audio_open(is, channel_layout, nb_channels, sample_rate, &is->audio_tgt);
        if (ret < 0)
            goto fail;
        is->audio_hw_buf_size = ret;
        is->audio_src = is->audio_tgt;
        is->audio_buf_size = 0;
        is->audio_buf_index = 0;
        is->audio_diff_avg_coef = exp(log(0.01) / 20);
        is->audio_diff_avg_count = 0;
        is->audio_diff_threshold = (double)(is->audio_hw_buf_size) / is->audio_tgt.bytes_per_sec;
        is->audio_stream = stream_index;
        is->audio_st = ic->streams[stream_index];
        decoder_init(&is->auddec, avctx, &is->audioq, is->continue_read_thread);
        if ((is->ic->iformat->flags & (0x2000 | 0x4000 | 0x8000)) && is->ic->iformat->read_seek == NULL)
        {
            is->auddec.start_pts = is->audio_st->start_time;
            is->auddec.start_pts_tb = is->audio_st->time_base;
        }
        ret = decoder_start(&is->auddec, audio_thread, "audio_decoder", is);
        if ( ret < 0)
            goto out;
        SDL_PauseAudioDevice(audio_dev, 0);
        break;
    case AVMEDIA_TYPE_VIDEO:
        is->video_stream = stream_index;
        is->video_st = ic->streams[stream_index];
        decoder_init(&is->viddec, avctx, &is->videoq, is->continue_read_thread);
        ret = decoder_start(&is->viddec, video_thread, "video_decoder", is);
        if (ret < 0)
            goto out;
        is->queue_attachments_req = 1;
        break;
    case AVMEDIA_TYPE_SUBTITLE:
        is->subtitle_stream = stream_index;
        is->subtitle_st = ic->streams[stream_index];
        decoder_init(&is->subdec, avctx, &is->subtitleq, is->continue_read_thread);
        ret = decoder_start(&is->subdec, subtitle_thread, "subtitle_decoder", is);
        if (ret < 0)
            goto out;
        break;
    default:
        break;
    }
    goto out;

fail:
    avcodec_free_context(&avctx);
out:
    av_dict_free(&opts);
    return ret;
}

static int decode_interrupt_cb(void *ctx)
{
    VideoState *is = ctx;
    return is->abort_request;
}

static int stream_has_enough_packets(AVStream *st, int stream_id, PacketQueue *queue)
{
    return stream_id < 0 ||
           queue->abort_request ||
           (st->disposition & 0x0400) ||
           queue->nb_packets > 25 && (!queue->duration || av_q2d(st->time_base) * queue->duration > 1.0);
}

static int is_realtime(AVFormatContext *s)
{
    if (!strcmp(s->iformat->name, "rtp") || !strcmp(s->iformat->name, "rtsp") || !strcmp(s->iformat->name, "sdp"))
        return 1;
    if (s->pb && (!strncmp(s->url, "rtp:", 4) || !strncmp(s->url, "udp:", 4)))
        return 1;
    return 0;
}


int ff_id3v2_match(const uint8_t *buf, const char *magic)
{
    return  buf[0]         == magic[0] &&
            buf[1]         == magic[1] &&
            buf[2]         == magic[2] &&
            buf[3]         != 0xff     &&
            buf[4]         != 0xff     &&
           (buf[6] & 0x80) == 0        &&
           (buf[7] & 0x80) == 0        &&
           (buf[8] & 0x80) == 0        &&
           (buf[9] & 0x80) == 0;
}
int ff_id3v2_tag_len(const uint8_t *buf)
{
    int len = ((buf[6] & 0x7f) << 21) +
              ((buf[7] & 0x7f) << 14) +
              ((buf[8] & 0x7f) << 7) +
              (buf[9] & 0x7f) +
              ID3v2_HEADER_SIZE;
    if (buf[5] & 0x10)
        len += ID3v2_HEADER_SIZE;
    return len;
}

int av_match_ext(const char *filename, const char *extensions)
{
    const char *ext;
    if (filename == NULL)
        return 0;
    ext = strrchr(filename, '.');
    if (ext)
        return av_match_name(ext + 1, extensions);
    return 0;
}
ff_const59 AVInputFormat *av_probe_input_format3(ff_const59 AVProbeData *pd, int is_opened,int *score_ret)
{
    AVProbeData lpd = *pd;
    const AVInputFormat *fmt1 = NULL;
    ff_const59 AVInputFormat *fmt = NULL;
    int score, score_max = 0;
    void *i = 0;
    const static uint8_t zerobuffer[AVPROBE_PADDING_SIZE];
    enum nodat {
        NO_ID3,
        ID3_ALMOST_GREATER_PROBE,
        ID3_GREATER_PROBE,
        ID3_GREATER_MAX_PROBE,
    } nodat = NO_ID3;
    if (lpd.buf == NULL)
        lpd.buf = (unsigned char *) zerobuffer;
    if (lpd.buf_size > 10 && ff_id3v2_match(lpd.buf, ID3v2_DEFAULT_MAGIC)) {
        int id3len = ff_id3v2_tag_len(lpd.buf);
        if (lpd.buf_size > id3len + 16) {
            if (lpd.buf_size < 2LL*id3len + 16)
                nodat = ID3_ALMOST_GREATER_PROBE;
            lpd.buf      += id3len;
            lpd.buf_size -= id3len;
        } else if (id3len >= PROBE_BUF_MAX) {
            nodat = ID3_GREATER_MAX_PROBE;
        } else
            nodat = ID3_GREATER_PROBE;
    }
    // while ((fmt1 = av_demuxer_iterate(&i))) {
    while (fmt1) {
        if (!is_opened == !(fmt1->flags & AVFMT_NOFILE) && strcmp(fmt1->name, "image2"))
            continue;
        score = 0;
        if (fmt1->read_probe) {
            score = fmt1->read_probe(&lpd);
            if (score != 0)
                av_log(NULL, AV_LOG_TRACE, "Probing %s score:%d size:%d\n", fmt1->name, score, lpd.buf_size);
            if (fmt1->extensions && av_match_ext(lpd.filename, fmt1->extensions)) {
                switch (nodat) {
                case NO_ID3:
                    score = FFMAX(score, 1);
                    break;
                case ID3_GREATER_PROBE:
                case ID3_ALMOST_GREATER_PROBE:
                    score = FFMAX(score, AVPROBE_SCORE_EXTENSION / 2 - 1);
                    break;
                case ID3_GREATER_MAX_PROBE:
                    score = FFMAX(score, AVPROBE_SCORE_EXTENSION);
                    break;
                }
            }
        } else if (fmt1->extensions) {
            if (av_match_ext(lpd.filename, fmt1->extensions))
                score = AVPROBE_SCORE_EXTENSION;
        }
        if (av_match_name(lpd.mime_type, fmt1->mime_type)) {
            if (AVPROBE_SCORE_MIME > score) {
                av_log(NULL, AV_LOG_DEBUG, "Probing %s score:%d increased to %d due to MIME type\n", fmt1->name, score, AVPROBE_SCORE_MIME);
                score = AVPROBE_SCORE_MIME;
            }
        }
        if (score > score_max) {
            score_max = score;
            fmt       = (AVInputFormat*)fmt1;
        } else if (score == score_max)
            fmt = NULL;
    }
    if (nodat == ID3_GREATER_PROBE)
        score_max = FFMIN(AVPROBE_SCORE_EXTENSION / 2 - 1, score_max);
    *score_ret = score_max;
    return fmt;
}
ff_const59 AVInputFormat *av_probe_input_format2(ff_const59 AVProbeData *pd, int is_opened, int *score_max)
{
    int score_ret;
    ff_const59 AVInputFormat *fmt = av_probe_input_format3(pd, is_opened, &score_ret);
    if (score_ret > *score_max) {
        *score_max = score_ret;
        return fmt;
    } else
        return NULL;
}
int ffio_rewind_with_probe_data(AVIOContext *s, unsigned char **bufp, int buf_size)
{
    int64_t buffer_start;
    int buffer_size;
    int overlap, new_size, alloc_size;
    uint8_t *buf = *bufp;
    if (s->write_flag) {
        av_freep(bufp);
        return AVERROR(EINVAL);
    }
    buffer_size = s->buf_end - s->buffer;
    if ((buffer_start = s->pos - buffer_size) > buf_size) {
        av_freep(bufp);
        return AVERROR(EINVAL);
    }
    overlap = buf_size - buffer_start;
    new_size = buf_size + buffer_size - overlap;
    alloc_size = FFMAX(s->buffer_size, new_size);
    if (alloc_size > buf_size)
        if (!(buf = (*bufp) = av_realloc_f(buf, 1, alloc_size)))
            return AVERROR(ENOMEM);
    if (new_size > buf_size) {
        memcpy(buf + buf_size, s->buffer + overlap, buffer_size - overlap);
        buf_size = new_size;
    }
    av_free(s->buffer);
    s->buf_ptr = s->buffer = buf;
    s->buffer_size = alloc_size;
    s->pos = buf_size;
    s->buf_end = s->buf_ptr + buf_size;
    s->eof_reached = 0;
    return 0;
}
static int read_packet_wrapper(AVIOContext *s, uint8_t *buf, int size)
{
    int ret;
    if (!s->read_packet)
        return AVERROR(EINVAL);
    ret = s->read_packet(s->opaque, buf, size);
#if FF_API_OLD_AVIO_EOF_0
    if (!ret && !s->max_packet_size) {
        av_log(NULL, AV_LOG_WARNING, "Invalid return value 0 for stream protocol\n");
        ret = AVERROR_EOF;
    }
#else
    av_assert2(ret || s->max_packet_size);
#endif
    return ret;
}
static int url_resetbuf(AVIOContext *s, int flags)
{
    av_assert1(flags == AVIO_FLAG_WRITE || flags == AVIO_FLAG_READ);
    if (flags & AVIO_FLAG_WRITE) {
        s->buf_end = s->buffer + s->buffer_size;
        s->write_flag = 1;
    } else {
        s->buf_end = s->buffer;
        s->write_flag = 0;
    }
    return 0;
}
#define IO_BUFFER_SIZE 32768
int ffio_set_buf_size(AVIOContext *s, int buf_size)
{
    uint8_t *buffer;
    buffer = av_malloc(buf_size);
    if (!buffer)
        return AVERROR(ENOMEM);
    av_free(s->buffer);
    s->buffer = buffer;
    s->orig_buffer_size =
    s->buffer_size = buf_size;
    s->buf_ptr = s->buf_ptr_max = buffer;
    url_resetbuf(s, s->write_flag ? AVIO_FLAG_WRITE : AVIO_FLAG_READ);
    return 0;
}
static void fill_buffer(AVIOContext *s)
{
    int max_buffer_size = s->max_packet_size ?
                          s->max_packet_size : IO_BUFFER_SIZE;
    uint8_t *dst        = s->buf_end - s->buffer + max_buffer_size <= s->buffer_size ?
                          s->buf_end : s->buffer;
    int len             = s->buffer_size - (dst - s->buffer);
    
    if (!s->read_packet && s->buf_ptr >= s->buf_end)
        s->eof_reached = 1;
    
    if (s->eof_reached)
        return;
    if (s->update_checksum && dst == s->buffer) {
        if (s->buf_end > s->checksum_ptr)
            s->checksum = s->update_checksum(s->checksum, s->checksum_ptr,
                                             s->buf_end - s->checksum_ptr);
        s->checksum_ptr = s->buffer;
    }
    
    if (s->read_packet && s->orig_buffer_size && s->buffer_size > s->orig_buffer_size && len >= s->orig_buffer_size) {
        if (dst == s->buffer && s->buf_ptr != dst) {
            int ret = ffio_set_buf_size(s, s->orig_buffer_size);
            if (ret < 0)
                av_log(s, AV_LOG_WARNING, "Failed to decrease buffer size\n");
            s->checksum_ptr = dst = s->buffer;
        }
        len = s->orig_buffer_size;
    }
    len = read_packet_wrapper(s, dst, len);
    if (len == AVERROR_EOF) {
        
        s->eof_reached = 1;
    } else if (len < 0) {
        s->eof_reached = 1;
        s->error= len;
    } else {
        s->pos += len;
        s->buf_ptr = dst;
        s->buf_end = dst + len;
        s->bytes_read += len;
    }
}
int avio_feof(AVIOContext *s)
{
    if(!s)
        return 0;
    if(s->eof_reached){
        s->eof_reached=0;
        fill_buffer(s);
    }
    return s->eof_reached;
}
int avio_read(AVIOContext *s, unsigned char *buf, int size)
{
    int len, size1;
    size1 = size;
    while (size > 0) {
        len = FFMIN(s->buf_end - s->buf_ptr, size);
        if (len == 0 || s->write_flag) {
            if((s->direct || size > s->buffer_size) && !s->update_checksum) {
                len = read_packet_wrapper(s, buf, size);
                if (len == AVERROR_EOF) {
                    
                    s->eof_reached = 1;
                    break;
                } else if (len < 0) {
                    s->eof_reached = 1;
                    s->error= len;
                    break;
                } else {
                    s->pos += len;
                    s->bytes_read += len;
                    size -= len;
                    buf += len;
                    s->buf_ptr = s->buffer;
                    s->buf_end = s->buffer;
                }
            } else {
                fill_buffer(s);
                len = s->buf_end - s->buf_ptr;
                if (len == 0)
                    break;
            }
        } else {
            memcpy(buf, s->buf_ptr, len);
            buf += len;
            s->buf_ptr += len;
            size -= len;
        }
    }
    if (size1 == size) {
        if (s->error)      return s->error;
        if (avio_feof(s))  return AVERROR_EOF;
    }
    return size1 - size;
}
int av_probe_input_buffer2(AVIOContext *pb, ff_const59 AVInputFormat **fmt, const char *filename, void *logctx, unsigned int offset, unsigned int max_probe_size)
{
    AVProbeData pd = { filename ? filename : "" };
    uint8_t *buf = NULL;
    int ret = 0, probe_size, buf_offset = 0;
    int score = 0;
    int ret2;
    if (!max_probe_size)
        max_probe_size = PROBE_BUF_MAX;
    else if (max_probe_size < PROBE_BUF_MIN) {
        av_log(logctx, AV_LOG_ERROR, "Specified probe size value %u cannot be < %u\n", max_probe_size, PROBE_BUF_MIN);
        return AVERROR(EINVAL);
    }
    if (offset >= max_probe_size)
        return AVERROR(EINVAL);
    if (pb->av_class) {
        uint8_t *mime_type_opt = NULL;
        char *semi;
        av_opt_get(pb, "mime_type", AV_OPT_SEARCH_CHILDREN, &mime_type_opt);
        pd.mime_type = (const char *)mime_type_opt;
        semi = pd.mime_type ? strchr(pd.mime_type, ';') : NULL;
        if (semi != NULL) {
            *semi = '\0';
        }
    }
    for (probe_size = PROBE_BUF_MIN; probe_size <= max_probe_size && !*fmt; probe_size = FFMIN(probe_size << 1, FFMAX(max_probe_size, probe_size + 1))) {
        score = probe_size < max_probe_size ? AVPROBE_SCORE_RETRY : 0;
        ret = av_reallocp(&buf, probe_size + AVPROBE_PADDING_SIZE);
        if (ret < 0)
            goto fail;
        ret = avio_read(pb, buf + buf_offset, probe_size - buf_offset);
        if (ret < 0) {
            if (ret != AVERROR_EOF)
                goto fail;
            score = 0;
            ret   = 0;          
        }
        buf_offset += ret;
        if (buf_offset < offset)
            continue;
        pd.buf_size = buf_offset - offset;
        pd.buf = &buf[offset];
        memset(pd.buf + pd.buf_size, 0, AVPROBE_PADDING_SIZE);
        
        *fmt = av_probe_input_format2(&pd, 1, &score);
        if (*fmt != NULL) {
            if (score <= AVPROBE_SCORE_RETRY) {
                av_log(logctx, AV_LOG_WARNING, "Format %s detected only with low score of %d, " "misdetection possible!\n", (*fmt)->name, score);
            } else
                av_log(logctx, AV_LOG_DEBUG, "Format %s probed with size=%d and score=%d\n", (*fmt)->name, probe_size, score);
        }
    }
    if ( *fmt == NULL)
        ret = AVERROR_INVALIDDATA;

fail:
    
    ret2 = ffio_rewind_with_probe_data(pb, &buf, buf_offset);
    if (ret >= 0)
        ret = ret2;
    av_freep(&pd.mime_type);
    return ret < 0 ? ret : score;
}
static int init_input(AVFormatContext *s, const char *filename, AVDictionary **options)
{
    int ret;
    AVProbeData pd = { filename, NULL, 0 };
    int score = AVPROBE_SCORE_RETRY;
    if (s->pb) {
        s->flags |= AVFMT_FLAG_CUSTOM_IO;
        if (!s->iformat)
            return av_probe_input_buffer2(s->pb, &s->iformat, filename,s, 0, s->format_probesize);
        else if (s->iformat->flags & AVFMT_NOFILE)
            av_log(s, AV_LOG_WARNING, "Custom AVIOContext makes no sense and ""will be ignored with AVFMT_NOFILE format.\n");
        return 0;
    }
    if ((s->iformat && s->iformat->flags & AVFMT_NOFILE) ||
        (!s->iformat && (s->iformat = av_probe_input_format2(&pd, 0, &score))))
        return score;
    ret = s->io_open(s, &s->pb, filename, AVIO_FLAG_READ | s->avio_flags, options);
    if (ret < 0)
        return ret;
    if (s->iformat)
        return 0;
    return av_probe_input_buffer2(s->pb, &s->iformat, filename,s, 0, s->format_probesize);
}
#define IO_BUFFER_SIZE 32768

static void update_checksum(AVIOContext *s)
{
    if (s->update_checksum && s->buf_ptr > s->checksum_ptr) {
        s->checksum = s->update_checksum(s->checksum, s->checksum_ptr,s->buf_ptr - s->checksum_ptr);
    }
}
int ffio_ensure_seekback(AVIOContext *s, int64_t buf_size)
{
    uint8_t *buffer;
    int max_buffer_size = s->max_packet_size ?
                          s->max_packet_size : IO_BUFFER_SIZE;
    ptrdiff_t filled = s->buf_end - s->buf_ptr;
    if (buf_size <= s->buf_end - s->buf_ptr)
        return 0;
    buf_size += max_buffer_size - 1;
    if (buf_size + s->buf_ptr - s->buffer <= s->buffer_size || s->seekable || !s->read_packet)
        return 0;
    av_assert0(!s->write_flag);
    if (buf_size <= s->buffer_size) {
        update_checksum(s);
        memmove(s->buffer, s->buf_ptr, filled);
    } else {
        buffer = av_malloc(buf_size);
        if (!buffer)
            return AVERROR(ENOMEM);
        update_checksum(s);
        memcpy(buffer, s->buf_ptr, filled);
        av_free(s->buffer);
        s->buffer = buffer;
        s->buffer_size = buf_size;
    }
    s->buf_ptr = s->buffer;
    s->buf_end = s->buffer + filled;
    s->checksum_ptr = s->buffer;
    return 0;
}
unsigned int avio_rl24(AVIOContext *s)
{
    unsigned int val;
    val = avio_rl16(s);
    val |= avio_r8(s) << 16;
    return val;
}
static void writeout(AVIOContext *s, const uint8_t *data, int len)
{
    if (!s->error) {
        int ret = 0;
        if (s->write_data_type)
            ret = s->write_data_type(s->opaque, (uint8_t *)data,
                                     len,
                                     s->current_type,
                                     s->last_time);
        else if (s->write_packet)
            ret = s->write_packet(s->opaque, (uint8_t *)data, len);
        if (ret < 0) {
            s->error = ret;
        } else {
            if (s->pos + len > s->written)
                s->written = s->pos + len;
        }
    }
    if (s->current_type == AVIO_DATA_MARKER_SYNC_POINT ||
        s->current_type == AVIO_DATA_MARKER_BOUNDARY_POINT) {
        s->current_type = AVIO_DATA_MARKER_UNKNOWN;
    }
    s->last_time = AV_NOPTS_VALUE;
    s->writeout_count ++;
    s->pos += len;
}
static void flush_buffer(AVIOContext *s)
{
    s->buf_ptr_max = FFMAX(s->buf_ptr, s->buf_ptr_max);
    if (s->write_flag && s->buf_ptr_max > s->buffer) {
        writeout(s, s->buffer, s->buf_ptr_max - s->buffer);
        if (s->update_checksum) {
            s->checksum     = s->update_checksum(s->checksum, s->checksum_ptr,
                                                 s->buf_ptr_max - s->checksum_ptr);
            s->checksum_ptr = s->buffer;
        }
    }
    s->buf_ptr = s->buf_ptr_max = s->buffer;
    if (!s->write_flag)
        s->buf_end = s->buffer;
}
void avio_write(AVIOContext *s, const unsigned char *buf, int size)
{
    if (s->direct && !s->update_checksum) {
        avio_flush(s);
        writeout(s, buf, size);
        return;
    }
    while (size > 0) {
        int len = FFMIN(s->buf_end - s->buf_ptr, size);
        memcpy(s->buf_ptr, buf, len);
        s->buf_ptr += len;
        if (s->buf_ptr >= s->buf_end)
            flush_buffer(s);
        buf += len;
        size -= len;
    }
}
typedef struct DynBuffer
{
    int pos, size, allocated_size;
    uint8_t *buffer;
    int io_buffer_size;
    uint8_t io_buffer[1];
} DynBuffer;
int avio_close_dyn_buf(AVIOContext *s, uint8_t **pbuffer)
{
    DynBuffer *d;
    int size;
    static const char padbuf[AV_INPUT_BUFFER_PADDING_SIZE] = {0};
    int padding = 0;
    if (!s) {
        *pbuffer = NULL;
        return 0;
    }
    
    if (!s->max_packet_size) {
        avio_write(s, padbuf, sizeof(padbuf));
        padding = AV_INPUT_BUFFER_PADDING_SIZE;
    }
    avio_flush(s);
    d = s->opaque;
    *pbuffer = d->buffer;
    size = d->size;
    av_free(d);
    avio_context_free(&s);
    return size - padding;
}

#define PUT_UTF8(val, tmp, PUT_BYTE)                      \
    {                                                     \
        int bytes, shift;                                 \
        uint32_t in = val;                                \
        if (in < 0x80)                                    \
        {                                                 \
            tmp = in;                                     \
            PUT_BYTE                                      \
        }                                                 \
        else                                              \
        {                                                 \
            bytes = (av_log2(in) + 4) / 5;                \
            shift = (bytes - 1) * 6;                      \
            tmp = (256 - (256 >> bytes)) | (in >> shift); \
            PUT_BYTE                                      \
            while (shift >= 6)                            \
            {                                             \
                shift -= 6;                               \
                tmp = 0x80 | ((in >> shift) & 0x3f);      \
                PUT_BYTE                                  \
            }                                             \
        }                                                 \
    }
    void ffio_free_dyn_buf(AVIOContext **s)
{
    DynBuffer *d;
    if (!*s)
        return;
    d = (*s)->opaque;
    av_free(d->buffer);
    av_free(d);
    avio_context_free(s);
}
#define GET_UTF16(val, GET_16BIT, ERROR)     \
    val = (GET_16BIT);                       \
    {                                        \
        unsigned int hi = val - 0xD800;      \
        if (hi < 0x800)                      \
        {                                    \
            val = (GET_16BIT)-0xDC00;        \
            if (val > 0x3FFU || hi > 0x3FFU) \
            {                                \
                ERROR                        \
            }                                \
            val += (hi << 10) + 0x10000;     \
        }                                    \
    }

static int decode_str(AVFormatContext *s, AVIOContext *pb, int encoding,
                      uint8_t **dst, int *maxread)
{
    int ret;
    uint8_t tmp;
    uint32_t ch = 1;
    int left = *maxread;
    unsigned int (*get)(AVIOContext*) = avio_rb16;
    AVIOContext *dynbuf;
    if ((ret = avio_open_dyn_buf(&dynbuf)) < 0) {
        av_log(s, AV_LOG_ERROR, "Error opening memory stream\n");
        return ret;
    }
    switch (encoding) {
    case ID3v2_ENCODING_ISO8859:
        while (left && ch) {
            ch = avio_r8(pb);
            PUT_UTF8(ch, tmp, avio_w8(dynbuf, tmp);)
            left--;
        }
        break;
    case ID3v2_ENCODING_UTF16BOM:
        if ((left -= 2) < 0) {
            av_log(s, AV_LOG_ERROR, "Cannot read BOM value, input too short\n");
            ffio_free_dyn_buf(&dynbuf);
            *dst = NULL;
            return AVERROR_INVALIDDATA;
        }
        switch (avio_rb16(pb)) {
        case 0xfffe:
            get = avio_rl16;
        case 0xfeff:
            break;
        default:
            av_log(s, AV_LOG_ERROR, "Incorrect BOM value\n");
            ffio_free_dyn_buf(&dynbuf);
            *dst = NULL;
            *maxread = left;
            return AVERROR_INVALIDDATA;
        }
    case ID3v2_ENCODING_UTF16BE:
        while ((left > 1) && ch) {
            GET_UTF16(ch, ((left -= 2) >= 0 ? get(pb) : 0), break;)
            PUT_UTF8(ch, tmp, avio_w8(dynbuf, tmp);)
        }
        if (left < 0)
            left += 2;  
        break;
    case ID3v2_ENCODING_UTF8:
        while (left && ch) {
            ch = avio_r8(pb);
            avio_w8(dynbuf, ch);
            left--;
        }
        break;
    default:
        av_log(s, AV_LOG_WARNING, "Unknown encoding\n");
    }
    if (ch)
        avio_w8(dynbuf, 0);
    avio_close_dyn_buf(dynbuf, dst);
    *maxread = left;
    return 0;
}
static void read_comment(AVFormatContext *s, AVIOContext *pb, int taglen,
                      AVDictionary **metadata)
{
    const char *key = "comment";
    uint8_t *dst;
    int encoding, dict_flags = AV_DICT_DONT_OVERWRITE | AV_DICT_DONT_STRDUP_VAL;
    av_unused int language;
    if (taglen < 4)
        return;
    encoding = avio_r8(pb);
    language = avio_rl24(pb);
    taglen -= 4;
    if (decode_str(s, pb, encoding, &dst, &taglen) < 0) {
        av_log(s, AV_LOG_ERROR, "Error reading comment frame, skipped\n");
        return;
    }
    if (dst && !*dst)
        av_freep(&dst);
    if (dst) {
        key = (const char *) dst;
        dict_flags |= AV_DICT_DONT_STRDUP_KEY;
    }
    if (decode_str(s, pb, encoding, &dst, &taglen) < 0) {
        av_log(s, AV_LOG_ERROR, "Error reading comment frame, skipped\n");
        if (dict_flags & AV_DICT_DONT_STRDUP_KEY)
            av_freep((void*)&key);
        return;
    }
    if (dst)
        av_dict_set(metadata, key, (const char *) dst, dict_flags);
}

static unsigned int get_size(AVIOContext *s, int len)
{
    int v = 0;
    while (len--)
        v = (v << 7) + (avio_r8(s) & 0x7F);
    return v;
}


static int is_tag(const char *buf, unsigned int len)
{
    if (!len)
        return 0;
    while (len--)
        if ((buf[len] < 'A' ||
             buf[len] > 'Z') &&
            (buf[len] < '0' ||
             buf[len] > '9'))
            return 0;
    return 1;
}
static int check_tag(AVIOContext *s, int offset, unsigned int len)
{
    char tag[4];
    if (len > 4 ||
        avio_seek(s, offset, SEEK_SET) < 0 ||
        avio_read(s, tag, len) < (int)len)
        return -1;
    else if (!AV_RB32(tag) || is_tag(tag, len))
        return 1;
    return 0;
}
static unsigned int size_to_syncsafe(unsigned int size)
{
    return (((size) & (0x7f <<  0)) >> 0) +
           (((size) & (0x7f <<  8)) >> 1) +
           (((size) & (0x7f << 16)) >> 2) +
           (((size) & (0x7f << 24)) >> 3);
}

void ff_metadata_conv(AVDictionary **pm, const AVMetadataConv *d_conv,const AVMetadataConv *s_conv)
{
    
    const AVMetadataConv *sc, *dc;
    AVDictionaryEntry *mtag = NULL;
    AVDictionary *dst = NULL;
    const char *key;
    if (d_conv == s_conv || !pm)
        return;
    while ((mtag = av_dict_get(*pm, "", mtag, AV_DICT_IGNORE_SUFFIX))) {
        key = mtag->key;
        if (s_conv)
            for (sc=s_conv; sc->native; sc++)
                if (!av_strcasecmp(key, sc->native)) {
                    key = sc->generic;
                    break;
                }
        if (d_conv)
            for (dc=d_conv; dc->native; dc++)
                if (!av_strcasecmp(key, dc->generic)) {
                    key = dc->native;
                    break;
                }
        av_dict_set(&dst, key, mtag->value, 0);
    }
    av_dict_free(pm);
    *pm = dst;
}

static void read_ttag(AVFormatContext *s, AVIOContext *pb, int taglen,AVDictionary **metadata, const char *key)
{
    uint8_t *dst;
    int encoding, dict_flags = AV_DICT_DONT_OVERWRITE | AV_DICT_DONT_STRDUP_VAL;
    unsigned genre;
    if (taglen < 1)
        return;
    encoding = avio_r8(pb);
    taglen--; 
    if (decode_str(s, pb, encoding, &dst, &taglen) < 0) {
        av_log(s, AV_LOG_ERROR, "Error reading frame %s, skipped\n", key);
        return;
    }
    if (!(strcmp(key, "TCON") && strcmp(key, "TCO"))                         &&
        (sscanf(dst, "(%d)", &genre) == 1 || sscanf(dst, "%d", &genre) == 1) &&
        genre <= ID3v1_GENRE_MAX) {
        av_freep(&dst);
        dst = av_strdup(ff_id3v1_genre_str[genre]);
    } else if (!(strcmp(key, "TXXX") && strcmp(key, "TXX"))) {
        
        key = dst;
        if (decode_str(s, pb, encoding, &dst, &taglen) < 0) {
            av_log(s, AV_LOG_ERROR, "Error reading frame %s, skipped\n", key);
            av_freep(&key);
            return;
        }
        dict_flags |= AV_DICT_DONT_STRDUP_KEY;
    } else if (!*dst)
        av_freep(&dst);
    if (dst)
        av_dict_set(metadata, key, dst, dict_flags);
}
static void free_chapter(void *obj)
{
    ID3v2ExtraMetaCHAP *chap = obj;
    av_freep(&chap->element_id);
    av_dict_free(&chap->meta);
}
static void read_chapter(AVFormatContext *s, AVIOContext *pb, int len, const char *ttag, ID3v2ExtraMeta **extra_meta, int isv34)
{
    int taglen;
    char tag[5];
    ID3v2ExtraMeta *new_extra = NULL;
    ID3v2ExtraMetaCHAP *chap  = NULL;
    new_extra = av_mallocz(sizeof(*new_extra));
    if (!new_extra)
        return;
    chap = &new_extra->data.chap;
    if (decode_str(s, pb, 0, &chap->element_id, &len) < 0)
        goto fail;
    if (len < 16)
        goto fail;
    chap->start = avio_rb32(pb);
    chap->end   = avio_rb32(pb);
    avio_skip(pb, 8);
    len -= 16;
    while (len > 10) {
        if (avio_read(pb, tag, 4) < 4)
            goto fail;
        tag[4] = 0;
        taglen = avio_rb32(pb);
        avio_skip(pb, 2);
        len -= 10;
        if (taglen < 0 || taglen > len)
            goto fail;
        if (tag[0] == 'T')
            read_ttag(s, pb, taglen, &chap->meta, tag);
        else
            avio_skip(pb, taglen);
        len -= taglen;
    }
    ff_metadata_conv(&chap->meta, NULL, ff_id3v2_34_metadata_conv);
    ff_metadata_conv(&chap->meta, NULL, ff_id3v2_4_metadata_conv);
    new_extra->tag  = "CHAP";
    new_extra->next = *extra_meta;
    *extra_meta     = new_extra;
    return;

fail:
    free_chapter(chap);
    av_freep(&new_extra);
}

static void free_priv(void *obj)
{
    ID3v2ExtraMetaPRIV *priv = obj;
    av_freep(&priv->owner);
    av_freep(&priv->data);
}
static void read_priv(AVFormatContext *s, AVIOContext *pb, int taglen,
                      const char *tag, ID3v2ExtraMeta **extra_meta, int isv34)
{
    ID3v2ExtraMeta *meta;
    ID3v2ExtraMetaPRIV *priv;
    meta = av_mallocz(sizeof(*meta));
    if (!meta)
        return;
    priv = &meta->data.priv;
    if (decode_str(s, pb, ID3v2_ENCODING_ISO8859, &priv->owner, &taglen) < 0)
        goto fail;
    priv->data = av_malloc(taglen);
    if (!priv->data)
        goto fail;
    priv->datasize = taglen;
    if (avio_read(pb, priv->data, priv->datasize) != priv->datasize)
        goto fail;
    meta->tag   = "PRIV";
    meta->next  = *extra_meta;
    *extra_meta = meta;
    return;

fail:
    free_priv(priv);
    av_freep(&meta);
}
static void free_geobtag(void *obj)
{
    ID3v2ExtraMetaGEOB *geob = obj;
    av_freep(&geob->mime_type);
    av_freep(&geob->file_name);
    av_freep(&geob->description);
    av_freep(&geob->data);
}
#define SIZE_SPECIFIER "zu"
static void read_geobtag(AVFormatContext *s, AVIOContext *pb, int taglen,
                         const char *tag, ID3v2ExtraMeta **extra_meta,
                         int isv34)
{
    ID3v2ExtraMetaGEOB *geob_data = NULL;
    ID3v2ExtraMeta *new_extra     = NULL;
    char encoding;
    unsigned int len;
    if (taglen < 1)
        return;
    new_extra = av_mallocz(sizeof(ID3v2ExtraMeta));
    if (!new_extra) {
        av_log(s, AV_LOG_ERROR, "Failed to alloc %"SIZE_SPECIFIER" bytes\n",
               sizeof(ID3v2ExtraMeta));
        return;
    }
    geob_data = &new_extra->data.geob;
    
    encoding = avio_r8(pb);
    taglen--;
    
    if (decode_str(s, pb, ID3v2_ENCODING_ISO8859, &geob_data->mime_type,
                   &taglen) < 0 ||
        taglen <= 0)
        goto fail;
    
    if (decode_str(s, pb, encoding, &geob_data->file_name, &taglen) < 0 ||
        taglen <= 0)
        goto fail;
    
    if (decode_str(s, pb, encoding, &geob_data->description, &taglen) < 0 ||
        taglen < 0)
        goto fail;
    if (taglen) {
        
        geob_data->data = av_malloc(taglen);
        if (!geob_data->data) {
            av_log(s, AV_LOG_ERROR, "Failed to alloc %d bytes\n", taglen);
            goto fail;
        }
        if ((len = avio_read(pb, geob_data->data, taglen)) < taglen)
            av_log(s, AV_LOG_WARNING,
                   "Error reading GEOB frame, data truncated.\n");
        geob_data->datasize = len;
    } else {
        geob_data->data     = NULL;
        geob_data->datasize = 0;
    }
    
    new_extra->tag  = "GEOB";
    new_extra->next = *extra_meta;
    *extra_meta     = new_extra;
    return;

fail:
    av_log(s, AV_LOG_ERROR, "Error reading frame %s, skipped\n", tag);
    free_geobtag(geob_data);
    av_free(new_extra);
    return;
}

static void rstrip_spaces(char *buf)
{
    size_t len = strlen(buf);
    while (len > 0 && buf[len - 1] == ' ')
        buf[--len] = 0;
}
static void free_apic(void *obj)
{
    ID3v2ExtraMetaAPIC *apic = obj;
    av_buffer_unref(&apic->buf);
    av_freep(&apic->description);
}
static void read_apic(AVFormatContext *s, AVIOContext *pb, int taglen,const char *tag, ID3v2ExtraMeta **extra_meta,int isv34)
{
    int enc, pic_type;
    char mimetype[64] = {0};
    const CodecMime *mime     = ff_id3v2_mime_tags;
    enum AVCodecID id         = AV_CODEC_ID_NONE;
    ID3v2ExtraMetaAPIC *apic  = NULL;
    ID3v2ExtraMeta *new_extra = NULL;
    int64_t end               = avio_tell(pb) + taglen;
    if (taglen <= 4 || (!isv34 && taglen <= 6))
        goto fail;
    new_extra = av_mallocz(sizeof(*new_extra));
    if (!new_extra)
        goto fail;
    apic = &new_extra->data.apic;
    enc = avio_r8(pb);
    taglen--;
    
    if (isv34) {
        taglen -= avio_get_str(pb, taglen, mimetype, sizeof(mimetype));
    } else {
        if (avio_read(pb, mimetype, 3) < 0)
            goto fail;
        mimetype[3] = 0;
        taglen    -= 3;
    }
    while (mime->id != AV_CODEC_ID_NONE) {
        if (!av_strncasecmp(mime->str, mimetype, sizeof(mimetype))) {
            id = mime->id;
            break;
        }
        mime++;
    }
    if (id == AV_CODEC_ID_NONE) {
        av_log(s, AV_LOG_WARNING,
               "Unknown attached picture mimetype: %s, skipping.\n", mimetype);
        goto fail;
    }
    apic->id = id;
    
    pic_type = avio_r8(pb);
    taglen--;
    if (pic_type < 0 || pic_type >= FF_ARRAY_ELEMS(ff_id3v2_picture_types)) {
        av_log(s, AV_LOG_WARNING, "Unknown attached picture type %d.\n",
               pic_type);
        pic_type = 0;
    }
    apic->type = ff_id3v2_picture_types[pic_type];
    
    if (decode_str(s, pb, enc, &apic->description, &taglen) < 0) {
        av_log(s, AV_LOG_ERROR,
               "Error decoding attached picture description.\n");
        goto fail;
    }
    apic->buf = av_buffer_alloc(taglen + AV_INPUT_BUFFER_PADDING_SIZE);
    if (!apic->buf || !taglen || avio_read(pb, apic->buf->data, taglen) != taglen)
        goto fail;
    memset(apic->buf->data + taglen, 0, AV_INPUT_BUFFER_PADDING_SIZE);
    new_extra->tag  = "APIC";
    new_extra->next = *extra_meta;
    *extra_meta     = new_extra;
    rstrip_spaces(apic->description);
    return;

fail:
    if (apic)
        free_apic(apic);
    av_freep(&new_extra);
    avio_seek(pb, end, SEEK_SET);
}
static const ID3v2EMFunc id3v2_extra_meta_funcs[] = {
    { "GEO", "GEOB", read_geobtag, free_geobtag },
    { "PIC", "APIC", read_apic,    free_apic    },
    { "CHAP","CHAP", read_chapter, free_chapter },
    { "PRIV","PRIV", read_priv,    free_priv    },
    { NULL }
};
static const ID3v2EMFunc *get_extra_meta_func(const char *tag, int isv34)
{
    int i = 0;
    while (id3v2_extra_meta_funcs[i].tag3) {
        if (tag && !memcmp(tag,
                    (isv34 ? id3v2_extra_meta_funcs[i].tag4 :
                             id3v2_extra_meta_funcs[i].tag3),
                    (isv34 ? 4 : 3)))
            return &id3v2_extra_meta_funcs[i];
        i++;
    }
    return NULL;
}
#define SHORT_SEEK_THRESHOLD (256 * 1024)
int ffio_init_context(AVIOContext *s,
                  unsigned char *buffer,
                  int buffer_size,
                  int write_flag,
                  void *opaque,
                  int (*read_packet)(void *opaque, uint8_t *buf, int buf_size),
                  int (*write_packet)(void *opaque, uint8_t *buf, int buf_size),
                  int64_t (*seek)(void *opaque, int64_t offset, int whence))
{
    memset(s, 0, sizeof(AVIOContext));
    s->buffer      = buffer;
    s->orig_buffer_size =
    s->buffer_size = buffer_size;
    s->buf_ptr     = buffer;
    s->buf_ptr_max = buffer;
    s->opaque      = opaque;
    s->direct      = 0;
    url_resetbuf(s, write_flag ? AVIO_FLAG_WRITE : AVIO_FLAG_READ);
    s->write_packet    = write_packet;
    s->read_packet     = read_packet;
    s->seek            = seek;
    s->pos             = 0;
    s->eof_reached     = 0;
    s->error           = 0;
    s->seekable        = seek ? AVIO_SEEKABLE_NORMAL : 0;
    s->min_packet_size = 0;
    s->max_packet_size = 0;
    s->update_checksum = NULL;
    s->short_seek_threshold = SHORT_SEEK_THRESHOLD;
    if (!read_packet && !write_flag) {
        s->pos     = buffer_size;
        s->buf_end = s->buffer + buffer_size;
    }
    s->read_pause = NULL;
    s->read_seek  = NULL;
    s->write_data_type       = NULL;
    s->ignore_boundary_point = 0;
    s->current_type          = AVIO_DATA_MARKER_UNKNOWN;
    s->last_time             = AV_NOPTS_VALUE;
    s->short_seek_get        = NULL;
    s->written               = 0;
    return 0;
}
static void read_uslt(AVFormatContext *s, AVIOContext *pb, int taglen,
                      AVDictionary **metadata)
{
    uint8_t lang[4];
    uint8_t *descriptor = NULL; 
    uint8_t *text;
    char *key;
    int encoding;
    int ok = 0;
    if (taglen < 1)
        goto error;
    encoding = avio_r8(pb);
    taglen--;
    if (avio_read(pb, lang, 3) < 3)
        goto error;
    lang[3] = '\0';
    taglen -= 3;
    if (decode_str(s, pb, encoding, &descriptor, &taglen) < 0)
        goto error;
    if (decode_str(s, pb, encoding, &text, &taglen) < 0)
        goto error;
    key = av_asprintf("lyrics-%s%s%s", descriptor[0] ? (char *)descriptor : "",
                                       descriptor[0] ? "-" : "",
                                       lang);
    if (!key) {
        av_free(text);
        goto error;
    }
    av_dict_set(metadata, key, text,
                AV_DICT_DONT_STRDUP_KEY | AV_DICT_DONT_STRDUP_VAL);
    ok = 1;
error:
    if (!ok)
        av_log(s, AV_LOG_ERROR, "Error reading lyrics, skipped\n");
    av_free(descriptor);
}
static void id3v2_parse(AVIOContext *pb, AVDictionary **metadata,AVFormatContext *s, int len, uint8_t version,uint8_t flags, ID3v2ExtraMeta **extra_meta)
{
    int isv34, unsync;
    unsigned tlen;
    char tag[5];
    int64_t next, end = avio_tell(pb) + len;
    int taghdrlen;
    const char *reason = NULL;
    AVIOContext pb_local;
    AVIOContext *pbx;
    unsigned char *buffer = NULL;
    int buffer_size       = 0;
    const ID3v2EMFunc *extra_func = NULL;
    unsigned char *uncompressed_buffer = NULL;
    av_unused int uncompressed_buffer_size = 0;
    const char *comm_frame;
    av_log(s, AV_LOG_DEBUG, "id3v2 ver:%d flags:%02X len:%d\n", version, flags, len);
    switch (version) {
    case 2:
        if (flags & 0x40) {
            reason = "compression";
            goto error;
        }
        isv34     = 0;
        taghdrlen = 6;
        comm_frame = "COM";
        break;
    case 3:
    case 4:
        isv34     = 1;
        taghdrlen = 10;
        comm_frame = "COMM";
        break;
    default:
        reason = "version";
        goto error;
    }
    unsync = flags & 0x80;
    if (isv34 && flags & 0x40) { 
        int extlen = get_size(pb, 4);
        if (version == 4)
            
            extlen -= 4;
        if (extlen < 0) {
            reason = "invalid extended header length";
            goto error;
        }
        avio_skip(pb, extlen);
        len -= extlen + 4;
        if (len < 0) {
            reason = "extended header too long.";
            goto error;
        }
    }
    while (len >= taghdrlen) {
        unsigned int tflags = 0;
        int tunsync         = 0;
        int tcomp           = 0;
        int tencr           = 0;
        unsigned long av_unused dlen;
        if (isv34) {
            if (avio_read(pb, tag, 4) < 4)
                break;
            tag[4] = 0;
            if (version == 3) {
                tlen = avio_rb32(pb);
            } else {
                
                tlen = avio_rb32(pb);
                if (tlen > 0x7f) {
                    if (tlen < len) {
                        int64_t cur = avio_tell(pb);
                        if (ffio_ensure_seekback(pb, 2 ))
                            break;
                        if (check_tag(pb, cur + 2 + size_to_syncsafe(tlen), 4) == 1)
                            tlen = size_to_syncsafe(tlen);
                        else if (check_tag(pb, cur + 2 + tlen, 4) != 1)
                            break;
                        avio_seek(pb, cur, SEEK_SET);
                    } else
                        tlen = size_to_syncsafe(tlen);
                }
            }
            tflags  = avio_rb16(pb);
            tunsync = tflags & ID3v2_FLAG_UNSYNCH;
        } else {
            if (avio_read(pb, tag, 3) < 3)
                break;
            tag[3] = 0;
            tlen   = avio_rb24(pb);
        }
        if (tlen > (1<<28))
            break;
        len -= taghdrlen + tlen;
        if (len < 0)
            break;
        next = avio_tell(pb) + tlen;
        if (!tlen) {
            if (tag[0])
                av_log(s, AV_LOG_DEBUG, "Invalid empty frame %s, skipping.\n",
                       tag);
            continue;
        }
        if (tflags & ID3v2_FLAG_DATALEN) {
            if (tlen < 4)
                break;
            dlen = avio_rb32(pb);
            tlen -= 4;
        } else
            dlen = tlen;
        tcomp = tflags & ID3v2_FLAG_COMPRESSION;
        tencr = tflags & ID3v2_FLAG_ENCRYPTION;
        
        if (tencr || (!CONFIG_ZLIB && tcomp)) {
            const char *type;
            if (!tcomp)
                type = "encrypted";
            else if (!tencr)
                type = "compressed";
            else
                type = "encrypted and compressed";
            av_log(s, AV_LOG_WARNING, "Skipping %s ID3v2 frame %s.\n", type, tag);
            avio_skip(pb, tlen);
        
        } else if (tag[0] == 'T' ||
                   !memcmp(tag, "USLT", 4) ||
                   !strcmp(tag, comm_frame) ||
                   (extra_meta &&
                    (extra_func = get_extra_meta_func(tag, isv34)))) {
            pbx = pb;
            if (unsync || tunsync || tcomp) {
                av_fast_malloc(&buffer, &buffer_size, tlen);
                if (!buffer) {
                    av_log(s, AV_LOG_ERROR, "Failed to alloc %d bytes\n", tlen);
                    goto seek;
                }
            }
            if (unsync || tunsync) {
                uint8_t *b = buffer;
                uint8_t *t = buffer;
                uint8_t *end = t + tlen;
                if (avio_read(pb, buffer, tlen) != tlen) {
                    av_log(s, AV_LOG_ERROR, "Failed to read tag data\n");
                    goto seek;
                }
                while (t != end) {
                    *b++ = *t++;
                    if (t != end && t[-1] == 0xff && !t[0])
                        t++;
                }
                ffio_init_context(&pb_local, buffer, b - buffer, 0, NULL, NULL, NULL, NULL);
                tlen = b - buffer;
                pbx  = &pb_local; 
            }
#if CONFIG_ZLIB
                if (tcomp) {
                    int err;
                    av_log(s, AV_LOG_DEBUG, "Compresssed frame %s tlen=%d dlen=%ld\n", tag, tlen, dlen);
                    av_fast_malloc(&uncompressed_buffer, &uncompressed_buffer_size, dlen);
                    if (!uncompressed_buffer) {
                        av_log(s, AV_LOG_ERROR, "Failed to alloc %ld bytes\n", dlen);
                        goto seek;
                    }
                    if (!(unsync || tunsync)) {
                        err = avio_read(pb, buffer, tlen);
                        if (err < 0) {
                            av_log(s, AV_LOG_ERROR, "Failed to read compressed tag\n");
                            goto seek;
                        }
                        tlen = err;
                    }
                    err = uncompress(uncompressed_buffer, &dlen, buffer, tlen);
                    if (err != Z_OK) {
                        av_log(s, AV_LOG_ERROR, "Failed to uncompress tag: %d\n", err);
                        goto seek;
                    }
                    ffio_init_context(&pb_local, uncompressed_buffer, dlen, 0, NULL, NULL, NULL, NULL);
                    tlen = dlen;
                    pbx = &pb_local; 
                }
#endif
            if (tag[0] == 'T')
                
                read_ttag(s, pbx, tlen, metadata, tag);
            else if (!memcmp(tag, "USLT", 4))
                read_uslt(s, pbx, tlen, metadata);
            else if (!strcmp(tag, comm_frame))
                read_comment(s, pbx, tlen, metadata);
            else
                
                extra_func->read(s, pbx, tlen, tag, extra_meta, isv34);
        } else if (!tag[0]) {
            if (tag[1])
                av_log(s, AV_LOG_WARNING, "invalid frame id, assuming padding\n");
            avio_skip(pb, tlen);
            break;
        }
        
seek:
        avio_seek(pb, next, SEEK_SET);
    }
    
    if (version == 4 && flags & 0x10)
        end += 10;

error:
    if (reason)
        av_log(s, AV_LOG_INFO, "ID3v2.%d tag skipped, cannot handle %s\n",
               version, reason);
    avio_seek(pb, end, SEEK_SET);
    av_free(buffer);
    av_free(uncompressed_buffer);
    return;
}
static const AVMetadataConv id3v2_2_metadata_conv[] = {
    { "TAL", "album"        },
    { "TCO", "genre"        },
    { "TCP", "compilation"  },
    { "TT2", "title"        },
    { "TEN", "encoded_by"   },
    { "TP1", "artist"       },
    { "TP2", "album_artist" },
    { "TP3", "performer"    },
    { "TRK", "track"        },
    { 0 }
};
static int is_number(const char *str)
{
    while (*str >= '0' && *str <= '9')
        str++;
    return !*str;
}
static AVDictionaryEntry *get_date_tag(AVDictionary *m, const char *tag)
{
    AVDictionaryEntry *t;
    if ((t = av_dict_get(m, tag, NULL, AV_DICT_MATCH_CASE)) &&
        strlen(t->value) == 4 && is_number(t->value))
        return t;
    return NULL;
}
static void merge_date(AVDictionary **m)
{
    AVDictionaryEntry *t;
    char date[17] = { 0 };      
    if (!(t = get_date_tag(*m, "TYER")) &&
        !(t = get_date_tag(*m, "TYE")))
        return;
    av_strlcpy(date, t->value, 5);
    av_dict_set(m, "TYER", NULL, 0);
    av_dict_set(m, "TYE", NULL, 0);
    if (!(t = get_date_tag(*m, "TDAT")) &&
        !(t = get_date_tag(*m, "TDA")))
        goto finish;
    snprintf(date + 4, sizeof(date) - 4, "-%.2s-%.2s", t->value + 2, t->value);
    av_dict_set(m, "TDAT", NULL, 0);
    av_dict_set(m, "TDA", NULL, 0);
    if (!(t = get_date_tag(*m, "TIME")) &&
        !(t = get_date_tag(*m, "TIM")))
        goto finish;
    snprintf(date + 10, sizeof(date) - 10,
             " %.2s:%.2s", t->value, t->value + 2);
    av_dict_set(m, "TIME", NULL, 0);
    av_dict_set(m, "TIM", NULL, 0);

finish:
    if (date[0])
        av_dict_set(m, "date", date, 0);
}
static void id3v2_read_internal(AVIOContext *pb, AVDictionary **metadata,AVFormatContext *s, const char *magic,ID3v2ExtraMeta **extra_meta, int64_t max_search_size)
{
    int len, ret;
    uint8_t buf[ID3v2_HEADER_SIZE];
    int found_header;
    int64_t start, off;
    if (max_search_size && max_search_size < ID3v2_HEADER_SIZE)
        return;
    start = avio_tell(pb);
    do {
        
        off = avio_tell(pb);
        if (max_search_size && off - start >= max_search_size - ID3v2_HEADER_SIZE) {
            avio_seek(pb, off, SEEK_SET);
            break;
        }
        ret = ffio_ensure_seekback(pb, ID3v2_HEADER_SIZE);
        if (ret >= 0)
            ret = avio_read(pb, buf, ID3v2_HEADER_SIZE);
        if (ret != ID3v2_HEADER_SIZE) {
            avio_seek(pb, off, SEEK_SET);
            break;
        }
        found_header = ff_id3v2_match(buf, magic);
        if (found_header) {
            
            len = ((buf[6] & 0x7f) << 21) |
                  ((buf[7] & 0x7f) << 14) |
                  ((buf[8] & 0x7f) << 7) |
                   (buf[9] & 0x7f);
            id3v2_parse(pb, metadata, s, len, buf[3], buf[5], extra_meta);
        } else {
            avio_seek(pb, off, SEEK_SET);
        }
    } while (found_header);
    ff_metadata_conv(metadata, NULL, ff_id3v2_34_metadata_conv);
    ff_metadata_conv(metadata, NULL, id3v2_2_metadata_conv);
    ff_metadata_conv(metadata, NULL, ff_id3v2_4_metadata_conv);
    merge_date(metadata);
}

void ff_id3v2_read_dict(AVIOContext *pb, AVDictionary **metadata,
                        const char *magic, ID3v2ExtraMeta **extra_meta)
{
    id3v2_read_internal(pb, metadata, NULL, magic, extra_meta, 0);
}
#define AV_RB64(p) AV_RB(64, p)
#define PNGSIG 0x89504e470d0a1a0a
#define MNGSIG 0x8a4d4e470d0a1a0
int ff_id3v2_parse_apic(AVFormatContext *s, ID3v2ExtraMeta *extra_meta)
{
    ID3v2ExtraMeta *cur;
    for (cur = extra_meta; cur; cur = cur->next) {
        ID3v2ExtraMetaAPIC *apic;
        AVStream *st;
        if (strcmp(cur->tag, "APIC"))
            continue;
        apic = &cur->data.apic;
        if (!(st = avformat_new_stream(s, NULL)))
            return AVERROR(ENOMEM);
        st->disposition      |= AV_DISPOSITION_ATTACHED_PIC;
        st->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
        st->codecpar->codec_id   = apic->id;
        if (AV_RB64(apic->buf->data) == PNGSIG)
            st->codecpar->codec_id = AV_CODEC_ID_PNG;
        if (apic->description[0])
            av_dict_set(&st->metadata, "title", apic->description, 0);
        av_dict_set(&st->metadata, "comment", apic->type, 0);
        av_init_packet(&st->attached_pic);
        st->attached_pic.buf          = apic->buf;
        st->attached_pic.data         = apic->buf->data;
        st->attached_pic.size         = apic->buf->size - AV_INPUT_BUFFER_PADDING_SIZE;
        st->attached_pic.stream_index = st->index;
        st->attached_pic.flags       |= AV_PKT_FLAG_KEY;
        apic->buf = NULL;
    }
    return 0;
}
#ifdef __GNUC__
#define dynarray_add(tab, nb_ptr, elem)\
do {\
    __typeof__(tab) _tab = (tab);\
    __typeof__(elem) _elem = (elem);\
    (void)sizeof(**_tab == _elem); \
    av_dynarray_add(_tab, nb_ptr, _elem);\
} while(0)
#else
#define dynarray_add(tab, nb_ptr, elem)\
do {\
    av_dynarray_add((tab), nb_ptr, (elem));\
} while(0)
#endif
AVChapter *avpriv_new_chapter(AVFormatContext *s, int id, AVRational time_base,
                              int64_t start, int64_t end, const char *title)
{
    AVChapter *chapter = NULL;
    int i;
    if (end != AV_NOPTS_VALUE && start > end) {
        av_log(s, AV_LOG_ERROR, "Chapter end time %"PRId64" before start %"PRId64"\n", end, start);
        return NULL;
    }
    for (i = 0; i < s->nb_chapters; i++)
        if (s->chapters[i]->id == id)
            chapter = s->chapters[i];
    if (!chapter) {
        chapter = av_mallocz(sizeof(AVChapter));
        if (!chapter)
            return NULL;
        dynarray_add(&s->chapters, &s->nb_chapters, chapter);
    }
    av_dict_set(&chapter->metadata, "title", title, 0);
    chapter->id        = id;
    chapter->time_base = time_base;
    chapter->start     = start;
    chapter->end       = end;
    return chapter;
}
int ff_id3v2_parse_chapters(AVFormatContext *s, ID3v2ExtraMeta *extra_meta)
{
    int ret = 0;
    ID3v2ExtraMeta *cur;
    AVRational time_base = {1, 1000};
    ID3v2ExtraMetaCHAP **chapters = NULL;
    int num_chapters = 0;
    int i;
    for (cur = extra_meta; cur; cur = cur->next) {
        ID3v2ExtraMetaCHAP *chap;
        if (strcmp(cur->tag, "CHAP"))
            continue;
        chap = &cur->data.chap;
        if ((ret = av_dynarray_add_nofree(&chapters, &num_chapters, chap)) < 0)
            goto end;
    }
    for (i = 0; i < (num_chapters / 2); i++) {
        ID3v2ExtraMetaCHAP *right;
        int right_index;
        right_index = (num_chapters - 1) - i;
        right = chapters[right_index];
        chapters[right_index] = chapters[i];
        chapters[i] = right;
    }
    for (i = 0; i < num_chapters; i++) {
        ID3v2ExtraMetaCHAP *chap;
        AVChapter *chapter;
        chap = chapters[i];
        chapter = avpriv_new_chapter(s, i, time_base, chap->start, chap->end, chap->element_id);
        if (!chapter)
            continue;
        if ((ret = av_dict_copy(&chapter->metadata, chap->meta, 0)) < 0)
            goto end;
    }

end:
    av_freep(&chapters);
    return ret;
}
#define ID3v2_PRIV_METADATA_PREFIX "id3v2_priv."
int ff_id3v2_parse_priv_dict(AVDictionary **metadata, ID3v2ExtraMeta *extra_meta)
{
    ID3v2ExtraMeta *cur;
    int dict_flags = AV_DICT_DONT_OVERWRITE | AV_DICT_DONT_STRDUP_KEY | AV_DICT_DONT_STRDUP_VAL;
    for (cur = extra_meta; cur; cur = cur->next) {
        if (!strcmp(cur->tag, "PRIV")) {
            ID3v2ExtraMetaPRIV *priv = &cur->data.priv;
            AVBPrint bprint;
            char *escaped, *key;
            int i, ret;
            if ((key = av_asprintf(ID3v2_PRIV_METADATA_PREFIX "%s", priv->owner)) == NULL) {
                return AVERROR(ENOMEM);
            }
            av_bprint_init(&bprint, priv->datasize + 1, AV_BPRINT_SIZE_UNLIMITED);
            for (i = 0; i < priv->datasize; i++) {
                if (priv->data[i] < 32 || priv->data[i] > 126 || priv->data[i] == '\\') {
                    av_bprintf(&bprint, "\\x%02x", priv->data[i]);
                } else {
                    av_bprint_chars(&bprint, priv->data[i], 1);
                }
            }
            if ((ret = av_bprint_finalize(&bprint, &escaped)) < 0) {
                av_free(key);
                return ret;
            }
            if ((ret = av_dict_set(metadata, key, escaped, dict_flags)) < 0) {
                return ret;
            }
        }
    }
    return 0;
}
int ff_id3v2_parse_priv(AVFormatContext *s, ID3v2ExtraMeta *extra_meta)
{
    return ff_id3v2_parse_priv_dict(&s->metadata, extra_meta);
}
void ff_id3v2_free_extra_meta(ID3v2ExtraMeta **extra_meta)
{
    ID3v2ExtraMeta *current = *extra_meta, *next;
    const ID3v2EMFunc *extra_func;
    while (current) {
        if ((extra_func = get_extra_meta_func(current->tag, 1)))
            extra_func->free(&current->data);
        next = current->next;
        av_freep(&current);
        current = next;
    }
    *extra_meta = NULL;
}
static int update_stream_avctx(AVFormatContext *s)
{
    int i, ret;
    for (i = 0; i < s->nb_streams; i++) {
        AVStream *st = s->streams[i];
        if (!st->internal->need_context_update)
            continue;
        
        if (st->parser && st->internal->avctx->codec_id != st->codecpar->codec_id) {
            av_parser_close(st->parser);
            st->parser = NULL;
        }
        
        ret = avcodec_parameters_to_context(st->internal->avctx, st->codecpar);
        if (ret < 0)
            return ret;
#if FF_API_LAVF_AVCTX
        
        ret = avcodec_parameters_to_context(st->codec, st->codecpar);
        if (ret < 0)
            return ret;
#endif
        st->internal->need_context_update = 0;
    }
    return 0;
}
#define RAW_PACKET_BUFFER_SIZE 2500000
int avformat_open_input(AVFormatContext **ps, const char *filename,ff_const59 AVInputFormat *fmt, AVDictionary **options)
{
    AVFormatContext *s = *ps;
    int i, ret = 0;
    AVDictionary *tmp = NULL;
    ID3v2ExtraMeta *id3v2_extra_meta = NULL;

    if (s->av_class == NULL) {
        av_log(NULL, AV_LOG_ERROR, "Input context has not been properly allocated by avformat_alloc_context() and is not NULL either\n");
        return AVERROR(EINVAL);
    }
    if (fmt != NULL)
        s->iformat = fmt;
    if (options != NULL)
        av_dict_copy(&tmp, *options, 0);
    if (s->pb != NULL) 
        s->flags |= AVFMT_FLAG_CUSTOM_IO;
    ret = av_opt_set_dict(s, &tmp);
    if (ret < 0)
        goto fail;
    if (!(s->url = av_strdup(filename ? filename : ""))) {
        ret = AVERROR(ENOMEM);
        goto fail;
    }
#if FF_API_FORMAT_FILENAME
    av_strlcpy(s->filename, filename ? filename : "", sizeof(s->filename));
#endif
    ret = init_input(s, filename, &tmp);
    if (ret < 0)
        goto fail;
    s->probe_score = ret;
    if (!s->protocol_whitelist && s->pb && s->pb->protocol_whitelist) {
        s->protocol_whitelist = av_strdup(s->pb->protocol_whitelist);
        if (!s->protocol_whitelist) {
            ret = AVERROR(ENOMEM);
            goto fail;
        }
    }
    if (!s->protocol_blacklist && s->pb && s->pb->protocol_blacklist) {
        s->protocol_blacklist = av_strdup(s->pb->protocol_blacklist);
        if (!s->protocol_blacklist) {
            ret = AVERROR(ENOMEM);
            goto fail;
        }
    }
    if (s->format_whitelist && av_match_list(s->iformat->name, s->format_whitelist, ',') <= 0) {
        av_log(s, AV_LOG_ERROR, "Format not on whitelist \'%s\'\n", s->format_whitelist);
        ret = AVERROR(EINVAL);
        goto fail;
    }
    avio_skip(s->pb, s->skip_initial_bytes);
    
    if (s->iformat->flags & AVFMT_NEEDNUMBER) {
        if (!av_filename_number_test(filename)) {
            ret = AVERROR(EINVAL);
            goto fail;
        }
    }
    s->duration = s->start_time = AV_NOPTS_VALUE;
    
    if (s->iformat->priv_data_size > 0) {
        if (!(s->priv_data = av_mallocz(s->iformat->priv_data_size))) {
            ret = AVERROR(ENOMEM);
            goto fail;
        }
        if (s->iformat->priv_class) {
            *(const AVClass **) s->priv_data = s->iformat->priv_class;
            av_opt_set_defaults(s->priv_data);
            if ((ret = av_opt_set_dict(s->priv_data, &tmp)) < 0)
                goto fail;
        }
    }
    
    if (s->pb)
        ff_id3v2_read_dict(s->pb, &s->internal->id3v2_meta, ID3v2_DEFAULT_MAGIC, &id3v2_extra_meta);
    if (!(s->flags&AVFMT_FLAG_PRIV_OPT) && s->iformat->read_header)
        if ((ret = s->iformat->read_header(s)) < 0)
            goto fail;
    if (!s->metadata) {
        s->metadata = s->internal->id3v2_meta;
        s->internal->id3v2_meta = NULL;
    } else if (s->internal->id3v2_meta) {
        av_log(s, AV_LOG_WARNING, "Discarding ID3 tags because more suitable tags were found.\n");
        av_dict_free(&s->internal->id3v2_meta);
    }
    if (id3v2_extra_meta != NULL) {
        if (!strcmp(s->iformat->name, "mp3") || !strcmp(s->iformat->name, "aac") ||
            !strcmp(s->iformat->name, "tta") || !strcmp(s->iformat->name, "wav")) {
            ret = ff_id3v2_parse_apic(s, id3v2_extra_meta);
            if (ret < 0)
                goto close;
            ret = ff_id3v2_parse_chapters(s, id3v2_extra_meta);
            if (ret < 0)
                goto close;
            ret = ff_id3v2_parse_priv(s, id3v2_extra_meta);
            if ( ret< 0)
                goto close;
        } else
            av_log(s, AV_LOG_DEBUG, "demuxer does not support additional id3 data, skipping\n");
    }
    ff_id3v2_free_extra_meta(&id3v2_extra_meta);
    ret = avformat_queue_attached_pictures(s);
    if (ret < 0)
        goto close;
    if (!(s->flags&AVFMT_FLAG_PRIV_OPT) && s->pb && !s->internal->data_offset)
        s->internal->data_offset = avio_tell(s->pb);
    s->internal->raw_packet_buffer_remaining_size = RAW_PACKET_BUFFER_SIZE;
    update_stream_avctx(s);
    for (i = 0; i < s->nb_streams; i++)
        s->streams[i]->internal->orig_codec_id = s->streams[i]->codecpar->codec_id;
    if (options) {
        av_dict_free(options);
        *options = tmp;
    }
    *ps = s;
    return 0;

close:
    if (s->iformat->read_close)
        s->iformat->read_close(s);
fail:
    ff_id3v2_free_extra_meta(&id3v2_extra_meta);
    av_dict_free(&tmp);
    if (s->pb && !(s->flags & AVFMT_FLAG_CUSTOM_IO))
        avio_closep(&s->pb);
    avformat_free_context(s);
    *ps = NULL;
    return ret;
}

int ff_check_interrupt(AVIOInterruptCB *cb)
{
    if (cb && cb->callback)
        return cb->callback(cb->opaque);
    return 0;
}

static inline int retry_transfer_wrapper(URLContext *h, uint8_t *buf,int size, int size_min, int (*transfer_func)(URLContext *h,uint8_t *buf,int size))
{
    int ret, len;
    int fast_retries = 5;
    int64_t wait_since = 0;

    len = 0;
    while (len < size_min) {
        if (ff_check_interrupt(&h->interrupt_callback))
            return AVERROR_EXIT;
        ret = transfer_func(h, buf + len, size - len);
        if (ret == AVERROR(EINTR))
            continue;
        if (h->flags & AVIO_FLAG_NONBLOCK)
            return ret;
        if (ret == AVERROR(EAGAIN)) {
            ret = 0;
            if (fast_retries) {
                fast_retries--;
            } else {
                if (h->rw_timeout) {
                    if (!wait_since)
                        wait_since = av_gettime_relative();
                    else if (av_gettime_relative() > wait_since + h->rw_timeout)
                        return AVERROR(EIO);
                }
                av_usleep(1000);
            }
        } else if (ret == AVERROR_EOF)
            return (len > 0) ? len : AVERROR_EOF;
        else if (ret < 0)
            return ret;
        if (ret) {
            fast_retries = FFMAX(fast_retries, 2);
            wait_since = 0;
        }
        len += ret;
    }
    return len;
}
int ffurl_read(URLContext *h, unsigned char *buf, int size)
{
    if (!(h->flags & AVIO_FLAG_READ))
        return AVERROR(EIO);
    return retry_transfer_wrapper(h, buf, size, 1, h->prot->url_read);
}

int ffurl_write(URLContext *h, const unsigned char *buf, int size)
{
    if (!(h->flags & AVIO_FLAG_WRITE))
        return AVERROR(EIO);
    
    if (h->max_packet_size && size > h->max_packet_size)
        return AVERROR(EIO);

    return retry_transfer_wrapper(h, (unsigned char *)buf, size, size,
                                  (int (*)(struct URLContext *, uint8_t *, int))
                                  h->prot->url_write);
}
int64_t ffurl_seek(URLContext *h, int64_t pos, int whence)
{
    int64_t ret;

    if (!h->prot->url_seek)
        return AVERROR(ENOSYS);
    ret = h->prot->url_seek(h, pos, whence & ~AVSEEK_FORCE);
    return ret;
}

int ffurl_get_short_seek(URLContext *h)
{
    if (!h || !h->prot || !h->prot->url_get_short_seek)
        return AVERROR(ENOSYS);
    return h->prot->url_get_short_seek(h);
}

static void *ff_avio_child_next(void *obj, void *prev)
{
    AVIOContext *s = obj;
    return prev ? NULL : s->opaque;
}

static const char *urlcontext_to_name(void *ptr)
{
    URLContext *h = (URLContext *)ptr;
    if (h->prot)
        return h->prot->name;
    else
        return "NULL";
}
static void *urlcontext_child_next(void *obj, void *prev)
{
    URLContext *h = obj;
    if (prev == NULL && h->priv_data != NULL && h->prot->priv_data_class != NULL)
        return h->priv_data;
    return NULL;
}

#ifndef S_ISFIFO
#  ifdef S_IFIFO
#    define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#  else
#    define S_ISFIFO(m) 0
#  endif
#endif


#ifndef S_ISLNK
#  ifdef S_IFLNK
#    define S_ISLNK(m) (((m) & S_IFLNK) == S_IFLNK)
#  else
#    define S_ISLNK(m) 0
#  endif
#endif


#ifndef S_ISSOCK
#  ifdef S_IFSOCK
#    define S_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)
#  else
#    define S_ISSOCK(m) 0
#  endif
#endif



typedef struct FileContext {
    const AVClass *class;
    int fd;
    int trunc;
    int blocksize;
    int follow;
    int seekable;
// #if HAVE_DIRENT_H
//     DIR *dir;
// #endif
} FileContext;

static const AVOption file_options[] = {
    { "truncate", "truncate existing files on write", offsetof(FileContext, trunc), AV_OPT_TYPE_BOOL, { .i64 = 1 }, 0, 1, AV_OPT_FLAG_ENCODING_PARAM },
    { "blocksize", "set I/O operation maximum block size", offsetof(FileContext, blocksize), AV_OPT_TYPE_INT, { .i64 = INT_MAX }, 1, INT_MAX, AV_OPT_FLAG_ENCODING_PARAM },
    { "follow", "Follow a file as it is being written", offsetof(FileContext, follow), AV_OPT_TYPE_INT, { .i64 = 0 }, 0, 1, AV_OPT_FLAG_DECODING_PARAM },
    { "seekable", "Sets if the file is seekable", offsetof(FileContext, seekable), AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 0, AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_ENCODING_PARAM },
    { NULL }
};

static const AVOption pipe_options[] = {
    { "blocksize", "set I/O operation maximum block size", offsetof(FileContext, blocksize), AV_OPT_TYPE_INT, { .i64 = INT_MAX }, 1, INT_MAX, AV_OPT_FLAG_ENCODING_PARAM },
    { NULL }
};

static const AVClass file_class = {
    .class_name = "file",
    .item_name  = av_default_item_name,
    .option     = file_options,
    .version    = LIBAVUTIL_VERSION_INT,
};

static const AVClass pipe_class = {
    .class_name = "pipe",
    .item_name  = av_default_item_name,
    .option     = pipe_options,
    .version    = LIBAVUTIL_VERSION_INT,
};

static int file_read(URLContext *h, unsigned char *buf, int size)
{
    FileContext *c = h->priv_data;
    int ret;
    size = FFMIN(size, c->blocksize);
    ret = read(c->fd, buf, size);
    if (ret == 0 && c->follow)
        return AVERROR(EAGAIN);
    if (ret == 0)
        return AVERROR_EOF;
    return (ret == -1) ? AVERROR(errno) : ret;
}

static int file_write(URLContext *h, const unsigned char *buf, int size)
{
    FileContext *c = h->priv_data;
    int ret;
    size = FFMIN(size, c->blocksize);
    ret = write(c->fd, buf, size);
    return (ret == -1) ? AVERROR(errno) : ret;
}

static int file_get_handle(URLContext *h)
{
    FileContext *c = h->priv_data;
    return c->fd;
}

static int file_check(URLContext *h, int mask)
{
    int ret = 0;
    const char *filename = h->filename;
    av_strstart(filename, "file:", &filename);

    {
#if HAVE_ACCESS && defined(R_OK)
    if (access(filename, F_OK) < 0)
        return AVERROR(errno);
    if (mask&AVIO_FLAG_READ)
        if (access(filename, R_OK) >= 0)
            ret |= AVIO_FLAG_READ;
    if (mask&AVIO_FLAG_WRITE)
        if (access(filename, W_OK) >= 0)
            ret |= AVIO_FLAG_WRITE;
#else
    struct stat st;
#   ifndef _WIN32
    ret = stat(filename, &st);
#   else
    ret = win32_stat(filename, &st);
#   endif
    if (ret < 0)
        return AVERROR(errno);

    ret |= st.st_mode&S_IRUSR ? mask&AVIO_FLAG_READ  : 0;
    ret |= st.st_mode&S_IWUSR ? mask&AVIO_FLAG_WRITE : 0;
#endif
    }
    return ret;
}

static int file_delete(URLContext *h)
{
#if HAVE_UNISTD_H
    int ret;
    const char *filename = h->filename;
    av_strstart(filename, "file:", &filename);

    ret = rmdir(filename);
    if (ret < 0 && (errno == ENOTDIR
#   ifdef _WIN32
        || errno == EINVAL
#   endif
        ))
        ret = unlink(filename);
    if (ret < 0)
        return AVERROR(errno);

    return ret;
#else
    return AVERROR(ENOSYS);
#endif 
}

static int file_move(URLContext *h_src, URLContext *h_dst)
{
    const char *filename_src = h_src->filename;
    const char *filename_dst = h_dst->filename;
    av_strstart(filename_src, "file:", &filename_src);
    av_strstart(filename_dst, "file:", &filename_dst);

    if (rename(filename_src, filename_dst) < 0)
        return AVERROR(errno);

    return 0;
}

int avpriv_open(const char *filename, int flags, ...)
{
    int fd;
    unsigned int mode = 0;
    va_list ap;

    va_start(ap, flags);
    if (flags & O_CREAT)
        mode = va_arg(ap, unsigned int);
    va_end(ap);

#ifdef O_CLOEXEC
    flags |= O_CLOEXEC;
#endif
#ifdef O_NOINHERIT
    flags |= O_NOINHERIT;
#endif

    fd = open(filename, flags, mode);
#if HAVE_FCNTL
    if (fd != -1) {
        if (fcntl(fd, F_SETFD, FD_CLOEXEC) == -1)
            av_log(NULL, AV_LOG_DEBUG, "Failed to set close on exec\n");
    }
#endif

    return fd;
}

static int file_open(URLContext *h, const char *filename, int flags)
{
    FileContext *c = h->priv_data;
    int access;
    int fd;
    struct stat st;

    av_strstart(filename, "file:", &filename);

    if (flags & AVIO_FLAG_WRITE && flags & AVIO_FLAG_READ) {
        access = O_CREAT | O_RDWR;
        if (c->trunc)
            access |= O_TRUNC;
    } else if (flags & AVIO_FLAG_WRITE) {
        access = O_CREAT | O_WRONLY;
        if (c->trunc)
            access |= O_TRUNC;
    } else {
        access = O_RDONLY;
    }
#ifdef O_BINARY
    access |= O_BINARY;
#endif
    fd = avpriv_open(filename, access, 0666);
    if (fd == -1)
        return AVERROR(errno);
    c->fd = fd;

    h->is_streamed = !fstat(fd, &st) && S_ISFIFO(st.st_mode);

    
    if (!h->is_streamed && flags & AVIO_FLAG_WRITE)
        h->min_packet_size = h->max_packet_size = 262144;

    if (c->seekable >= 0)
        h->is_streamed = !c->seekable;

    return 0;
}


static int64_t file_seek(URLContext *h, int64_t pos, int whence)
{
    FileContext *c = h->priv_data;
    int64_t ret;

    if (whence == AVSEEK_SIZE) {
        struct stat st;
        ret = fstat(c->fd, &st);
        return ret < 0 ? AVERROR(errno) : (S_ISFIFO(st.st_mode) ? 0 : st.st_size);
    }

    ret = lseek(c->fd, pos, whence);

    return ret < 0 ? AVERROR(errno) : ret;
}

static int file_close(URLContext *h)
{
    FileContext *c = h->priv_data;
    return close(c->fd);
}

static int file_open_dir(URLContext *h)
{
#if HAVE_LSTAT
    FileContext *c = h->priv_data;

    c->dir = opendir(h->filename);
    if (!c->dir)
        return AVERROR(errno);

    return 0;
#else
    return AVERROR(ENOSYS);
#endif 
}

static int file_read_dir(URLContext *h, AVIODirEntry **next)
{
#if HAVE_LSTAT
    FileContext *c = h->priv_data;
    struct dirent *dir;
    char *fullpath = NULL;

    *next = ff_alloc_dir_entry();
    if (!*next)
        return AVERROR(ENOMEM);
    do {
        errno = 0;
        dir = readdir(c->dir);
        if (!dir) {
            av_freep(next);
            return AVERROR(errno);
        }
    } while (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."));

    fullpath = av_append_path_component(h->filename, dir->d_name);
    if (fullpath) {
        struct stat st;
        if (!lstat(fullpath, &st)) {
            if (S_ISDIR(st.st_mode))
                (*next)->type = AVIO_ENTRY_DIRECTORY;
            else if (S_ISFIFO(st.st_mode))
                (*next)->type = AVIO_ENTRY_NAMED_PIPE;
            else if (S_ISCHR(st.st_mode))
                (*next)->type = AVIO_ENTRY_CHARACTER_DEVICE;
            else if (S_ISBLK(st.st_mode))
                (*next)->type = AVIO_ENTRY_BLOCK_DEVICE;
            else if (S_ISLNK(st.st_mode))
                (*next)->type = AVIO_ENTRY_SYMBOLIC_LINK;
            else if (S_ISSOCK(st.st_mode))
                (*next)->type = AVIO_ENTRY_SOCKET;
            else if (S_ISREG(st.st_mode))
                (*next)->type = AVIO_ENTRY_FILE;
            else
                (*next)->type = AVIO_ENTRY_UNKNOWN;

            (*next)->group_id = st.st_gid;
            (*next)->user_id = st.st_uid;
            (*next)->size = st.st_size;
            (*next)->filemode = st.st_mode & 0777;
            (*next)->modification_timestamp = INT64_C(1000000) * st.st_mtime;
            (*next)->access_timestamp =  INT64_C(1000000) * st.st_atime;
            (*next)->status_change_timestamp = INT64_C(1000000) * st.st_ctime;
        }
        av_free(fullpath);
    }

    (*next)->name = av_strdup(dir->d_name);
    return 0;
#else
    return AVERROR(ENOSYS);
#endif 
}

static int file_close_dir(URLContext *h)
{
#if HAVE_LSTAT
    FileContext *c = h->priv_data;
    closedir(c->dir);
    return 0;
#else
    return AVERROR(ENOSYS);
#endif 
}
const URLProtocol ff_file_protocol = {
    .name                = "file",
    .url_open            = file_open,
    .url_read            = file_read,
    .url_write           = file_write,
    .url_seek            = file_seek,
    .url_close           = file_close,
    .url_get_file_handle = file_get_handle,
    .url_check           = file_check,
    .url_delete          = file_delete,
    .url_move            = file_move,
    .priv_data_size      = sizeof(FileContext),
    .priv_data_class     = &file_class,
    .url_open_dir        = file_open_dir,
    .url_read_dir        = file_read_dir,
    .url_close_dir       = file_close_dir,
    .default_whitelist   = "file,crypto,data"
};

#define URL_PROTOCOL_FLAG_NESTED_SCHEME 1 
#define URL_PROTOCOL_FLAG_NETWORK 2       

// #include "udp.c"
static const URLProtocol * const url_protocols[] = {
    // &ff_async_protocol,
    // &ff_bluray_protocol,
    // &ff_cache_protocol,
    // &ff_concat_protocol,
    // &ff_crypto_protocol,
    // &ff_data_protocol,
    // &ff_ffrtmphttp_protocol,
    &ff_file_protocol,
    // &ff_ftp_protocol,
    // &ff_gopher_protocol,
    // &ff_hls_protocol,
    // &ff_http_protocol,
    // &ff_httpproxy_protocol,
    // &ff_https_protocol,
    // &ff_icecast_protocol,
    // &ff_mmsh_protocol,
    // &ff_mmst_protocol,
    // &ff_md5_protocol,
    // &ff_pipe_protocol,
    // &ff_prompeg_protocol,
    // &ff_rtmp_protocol,
    // &ff_rtmps_protocol,
    // &ff_rtmpt_protocol,
    // &ff_rtmpts_protocol,
    // &ff_rtp_protocol,
    // &ff_srtp_protocol,
    // &ff_subfile_protocol,
    // &ff_tee_protocol,
    // &ff_tcp_protocol,
    // &ff_tls_protocol,
    // &ff_udp_protocol,
    // &ff_udplite_protocol,
    // &ff_libsrt_protocol,
    // &ff_libssh_protocol,
    // &ff_libzmq_protocol,
    NULL };

#if FF_API_CHILD_CLASS_NEXT
const AVClass *ff_urlcontext_child_class_next(const AVClass *prev)
{
    int i;
    for (i = 0; prev && url_protocols[i]; i++) {
        if (url_protocols[i]->priv_data_class == prev) {
            i++;
            break;
        }
    }
    for (; url_protocols[i]; i++)
        if (url_protocols[i]->priv_data_class)
            return url_protocols[i]->priv_data_class;
    return NULL;
}

const AVClass *ff_urlcontext_child_class_iterate(void **iter)
{
    const AVClass *ret = NULL;
    uintptr_t i;

    for (i = (uintptr_t)*iter; url_protocols[i]; i++) {
        ret = url_protocols[i]->priv_data_class;
        if (ret)
            break;
    }

    *iter = (void*)(uintptr_t)(url_protocols[i] ? i + 1 : i);
    return ret;
}
const AVClass ffurl_context_class = {
    .class_name       = "URLContext",
    .item_name        = urlcontext_to_name,
    .option           = (AVOption[]) {
    {"protocol_whitelist", "List of protocols that are allowed to be used", offsetof(URLContext,protocol_whitelist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
    {"protocol_blacklist", "List of protocols that are not allowed to be used", offsetof(URLContext,protocol_blacklist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
    {"rw_timeout", "Timeout for IO operations (in microseconds)", offsetof(URLContext, rw_timeout), AV_OPT_TYPE_INT64, { .i64 = 0 }, 0, INT64_MAX, AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_DECODING_PARAM },
    { NULL }
},
    .version          = LIBAVUTIL_VERSION_INT,
    .child_next       = urlcontext_child_next,
#if FF_API_CHILD_CLASS_NEXT
    .child_class_next = ff_urlcontext_child_class_next,
#endif
    .child_class_iterate = ff_urlcontext_child_class_iterate,
};

static const AVClass *ff_avio_child_class_next(const AVClass *prev)
{
    return prev ? NULL : &ffurl_context_class;
}
#endif
static const AVClass *child_class_iterate(void **iter)
{
    const AVClass *c = *iter ? NULL : &ffurl_context_class;
    *iter = (void*)(uintptr_t)c;
    return c;
}
static const AVOption ff_avio_options[] = {
    {"protocol_whitelist", "List of protocols that are allowed to be used", offsetof(AVIOContext,protocol_whitelist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
    { NULL },
};
const AVClass ff_avio_class = {
    .class_name = "AVIOContext",
    .item_name  = av_default_item_name,
    .version    = LIBAVUTIL_VERSION_INT,
    .option     = ff_avio_options,
    .child_next = ff_avio_child_next,
#if FF_API_CHILD_CLASS_NEXT
    .child_class_next = ff_avio_child_class_next,
#endif
    .child_class_iterate = child_class_iterate,
};
int ffio_fdopen(AVIOContext **s, URLContext *h)
{
    uint8_t *buffer = NULL;
    int buffer_size, max_packet_size;

    max_packet_size = h->max_packet_size;
    if (max_packet_size) {
        buffer_size = max_packet_size; 
    } else {
        buffer_size = IO_BUFFER_SIZE;
    }
    if (!(h->flags & AVIO_FLAG_WRITE) && h->is_streamed) {
        if (buffer_size > INT_MAX/2)
            return AVERROR(EINVAL);
        buffer_size *= 2;
    }
    buffer = av_malloc(buffer_size);
    if (!buffer)
        return AVERROR(ENOMEM);

    *s = avio_alloc_context(buffer, buffer_size, h->flags & AVIO_FLAG_WRITE, h,
                            (int (*)(void *, uint8_t *, int))  ffurl_read,
                            (int (*)(void *, uint8_t *, int))  ffurl_write,
                            (int64_t (*)(void *, int64_t, int))ffurl_seek);
    if (!*s)
        goto fail;

    (*s)->protocol_whitelist = av_strdup(h->protocol_whitelist);
    if (!(*s)->protocol_whitelist && h->protocol_whitelist) {
        avio_closep(s);
        goto fail;
    }
    (*s)->protocol_blacklist = av_strdup(h->protocol_blacklist);
    if (!(*s)->protocol_blacklist && h->protocol_blacklist) {
        avio_closep(s);
        goto fail;
    }
    (*s)->direct = h->flags & AVIO_FLAG_DIRECT;

    (*s)->seekable = h->is_streamed ? 0 : AVIO_SEEKABLE_NORMAL;
    (*s)->max_packet_size = max_packet_size;
    (*s)->min_packet_size = h->min_packet_size;
    if(h->prot) {
        (*s)->read_pause = (int (*)(void *, int))h->prot->url_read_pause;
        (*s)->read_seek  =
            (int64_t (*)(void *, int, int64_t, int))h->prot->url_read_seek;

        if (h->prot->url_read_seek)
            (*s)->seekable |= AVIO_SEEKABLE_TIME;
    }
    (*s)->short_seek_get = (int (*)(void *))ffurl_get_short_seek;
    (*s)->av_class = &ff_avio_class;
    return 0;
fail:
    av_freep(&buffer);
    return AVERROR(ENOMEM);
}
#define URL_SCHEME_CHARS         \
    "abcdefghijklmnopqrstuvwxyz" \
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
    "0123456789+-."
    static inline int is_dos_path(const char *path)
{
#if HAVE_DOS_PATHS
    if (path[0] && path[1] == ':')
        return 1;
#endif
    return 0;
}
const URLProtocol **ffurl_get_protocols(const char *whitelist,
                                        const char *blacklist)
{
    const URLProtocol **ret;
    int i, ret_idx = 0;

    ret = av_mallocz_array(FF_ARRAY_ELEMS(url_protocols), sizeof(*ret));
    if (!ret)
        return NULL;

    for (i = 0; url_protocols[i]; i++) {
        const URLProtocol *up = url_protocols[i];

        if (whitelist && *whitelist && !av_match_name(up->name, whitelist))
            continue;
        if (blacklist && *blacklist && av_match_name(up->name, blacklist))
            continue;

        ret[ret_idx++] = up;
    }

    return ret;
}

static const struct URLProtocol *url_find_protocol(const char *filename)
{
    const URLProtocol **protocols;
    char proto_str[128], proto_nested[128], *ptr;
    size_t proto_len = strspn(filename, URL_SCHEME_CHARS);
    int i;

    if (filename[proto_len] != ':' &&
        (strncmp(filename, "subfile,", 8) || !strchr(filename + proto_len + 1, ':')) || is_dos_path(filename))
        strcpy(proto_str, "file");
    else
        av_strlcpy(proto_str, filename, FFMIN(proto_len + 1, sizeof(proto_str)));

    av_strlcpy(proto_nested, proto_str, sizeof(proto_nested));
    ptr = strchr(proto_nested, '+');
    if (ptr != NULL)
        *ptr = '\0';

    protocols = ffurl_get_protocols(NULL, NULL);
    if (protocols == NULL)
        return NULL;
    av_log(NULL, AV_LOG_DEBUG, "%s\n", proto_str);

    for (i = 0; protocols[i]; i++) {
            const URLProtocol *up = protocols[i];

        if (!strcmp(proto_str, up->name)) {
            av_freep(&protocols);
            return up;
        }
        if (up->flags & URL_PROTOCOL_FLAG_NESTED_SCHEME && !strcmp(proto_nested, up->name)) {
            av_freep(&protocols);
            return up;
        }
    }
    av_freep(&protocols);
    if (av_strstart(filename, "https:", NULL) || av_strstart(filename, "tls:", NULL))
        av_log(NULL, AV_LOG_WARNING, "https protocol not found, recompile FFmpeg with openssl, gnutls or securetransport enabled.\n");

    return NULL;
}

int ff_network_init(void)
{
#if HAVE_WINSOCK2_H
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(1, 1), &wsaData))
        return 0;
#endif
    return 1;
}
void ff_network_close(void)
{
#if HAVE_WINSOCK2_H
    WSACleanup();
#endif
}
static int url_alloc_for_protocol(URLContext **puc, const URLProtocol *up,const char *filename, int flags,const AVIOInterruptCB *int_cb)
{
    URLContext *uc;
    int err;

#if CONFIG_NETWORK
    if (up->flags & URL_PROTOCOL_FLAG_NETWORK && !ff_network_init())
        return AVERROR(EIO);
#endif
    if ((flags & AVIO_FLAG_READ) && !up->url_read) {
        av_log(NULL, AV_LOG_ERROR,
               "Impossible to open the '%s' protocol for reading\n", up->name);
        return AVERROR(EIO);
    }
    if ((flags & AVIO_FLAG_WRITE) && !up->url_write) {
        av_log(NULL, AV_LOG_ERROR,
               "Impossible to open the '%s' protocol for writing\n", up->name);
        return AVERROR(EIO);
    }
    uc = av_mallocz(sizeof(URLContext) + strlen(filename) + 1);
    if (!uc) {
        err = AVERROR(ENOMEM);
        goto fail;
    }
    uc->av_class = &ffurl_context_class;
    uc->filename = (char *)&uc[1];
    strcpy(uc->filename, filename);
    uc->prot            = up;
    uc->flags           = flags;
    uc->is_streamed     = 0; 
    uc->max_packet_size = 0; 
    if (up->priv_data_size) {
        uc->priv_data = av_mallocz(up->priv_data_size);
        if (!uc->priv_data) {
            err = AVERROR(ENOMEM);
            goto fail;
        }
        if (up->priv_data_class) {
            int proto_len= strlen(up->name);
            char *start = strchr(uc->filename, ',');
            *(const AVClass **)uc->priv_data = up->priv_data_class;
            av_opt_set_defaults(uc->priv_data);
            if(!strncmp(up->name, uc->filename, proto_len) && uc->filename + proto_len == start){
                int ret= 0;
                char *p= start;
                char sep= *++p;
                char *key, *val;
                p++;

                if (strcmp(up->name, "subfile"))
                    ret = AVERROR(EINVAL);

                while(ret >= 0 && (key= strchr(p, sep)) && p<key && (val = strchr(key+1, sep))){
                    *val= *key= 0;
                    if (strcmp(p, "start") && strcmp(p, "end")) {
                        ret = AVERROR_OPTION_NOT_FOUND;
                    } else
                        ret= av_opt_set(uc->priv_data, p, key+1, 0);
                    if (ret == AVERROR_OPTION_NOT_FOUND)
                        av_log(uc, AV_LOG_ERROR, "Key '%s' not found.\n", p);
                    *val= *key= sep;
                    p= val+1;
                }
                if(ret<0 || p!=key){
                    av_log(uc, AV_LOG_ERROR, "Error parsing options string %s\n", start);
                    av_freep(&uc->priv_data);
                    av_freep(&uc);
                    err = AVERROR(EINVAL);
                    goto fail;
                }
                memmove(start, key+1, strlen(key));
            }
        }
    }
    if (int_cb)
        uc->interrupt_callback = *int_cb;

    *puc = uc;
    return 0;
fail:
    *puc = NULL;
    if (uc)
        av_freep(&uc->priv_data);
    av_freep(&uc);
#if CONFIG_NETWORK
    if (up->flags & URL_PROTOCOL_FLAG_NETWORK)
        ff_network_close();
#endif
    return err;
}
int ffurl_alloc(URLContext **puc, const char *filename, int flags,
                const AVIOInterruptCB *int_cb)
{
    const URLProtocol *p = NULL;

    p = url_find_protocol(filename);
    if (p != NULL)
       return url_alloc_for_protocol(puc, p, filename, flags, int_cb);

    *puc = NULL;
    return AVERROR_PROTOCOL_NOT_FOUND;
}

int ffurl_connect(URLContext *uc, AVDictionary **options)
{
    int err;
    AVDictionary *tmp_opts = NULL;
    AVDictionaryEntry *e;

    if (!options)
        options = &tmp_opts;

    av_assert0(!(e=av_dict_get(*options, "protocol_whitelist", NULL, 0)) ||
               (uc->protocol_whitelist && !strcmp(uc->protocol_whitelist, e->value)));
    av_assert0(!(e=av_dict_get(*options, "protocol_blacklist", NULL, 0)) ||
               (uc->protocol_blacklist && !strcmp(uc->protocol_blacklist, e->value)));

    if (uc->protocol_whitelist && av_match_list(uc->prot->name, uc->protocol_whitelist, ',') <= 0) {
        av_log(uc, AV_LOG_ERROR, "Protocol '%s' not on whitelist '%s'!\n", uc->prot->name, uc->protocol_whitelist);
        return AVERROR(EINVAL);
    }

    if (uc->protocol_blacklist && av_match_list(uc->prot->name, uc->protocol_blacklist, ',') > 0) {
        av_log(uc, AV_LOG_ERROR, "Protocol '%s' on blacklist '%s'!\n", uc->prot->name, uc->protocol_blacklist);
        return AVERROR(EINVAL);
    }

    if (!uc->protocol_whitelist && uc->prot->default_whitelist) {
        av_log(uc, AV_LOG_DEBUG, "Setting default whitelist '%s'\n", uc->prot->default_whitelist);
        uc->protocol_whitelist = av_strdup(uc->prot->default_whitelist);
        if (!uc->protocol_whitelist) {
            return AVERROR(ENOMEM);
        }
    } else if (!uc->protocol_whitelist)
        av_log(uc, AV_LOG_DEBUG, "No default whitelist set\n"); 

    if ((err = av_dict_set(options, "protocol_whitelist", uc->protocol_whitelist, 0)) < 0)
        return err;
    if ((err = av_dict_set(options, "protocol_blacklist", uc->protocol_blacklist, 0)) < 0)
        return err;

    err =
        uc->prot->url_open2 ? uc->prot->url_open2(uc,
                                                  uc->filename,
                                                  uc->flags,
                                                  options) :
        uc->prot->url_open(uc, uc->filename, uc->flags);

    av_dict_set(options, "protocol_whitelist", NULL, 0);
    av_dict_set(options, "protocol_blacklist", NULL, 0);

    if (err)
        return err;
    uc->is_connected = 1;
    
    if ((uc->flags & AVIO_FLAG_WRITE) || !strcmp(uc->prot->name, "file"))
        if (!uc->is_streamed && ffurl_seek(uc, 0, SEEK_SET) < 0)
            uc->is_streamed = 1;
    return 0;
}
int ffurl_closep(URLContext **hh)
{
    URLContext *h= *hh;
    int ret = 0;
    if (!h)
        return 0;     

    if (h->is_connected && h->prot->url_close)
        ret = h->prot->url_close(h);
#if CONFIG_NETWORK
    if (h->prot->flags & URL_PROTOCOL_FLAG_NETWORK)
        ff_network_close();
#endif
    if (h->prot->priv_data_size) {
        if (h->prot->priv_data_class)
            av_opt_free(h->priv_data);
        av_freep(&h->priv_data);
    }
    av_opt_free(h);
    av_freep(hh);
    return ret;
}
int ffurl_open_whitelist(URLContext **puc, const char *filename, int flags,const AVIOInterruptCB *int_cb, AVDictionary **options,const char *whitelist, const char* blacklist,URLContext *parent)
{
    AVDictionary *tmp_opts = NULL;
    AVDictionaryEntry *e;
    int ret = ffurl_alloc(puc, filename, flags, int_cb);
    if (ret < 0)
        return ret;
    if (parent)
        av_opt_copy(*puc, parent);
    if (options &&
        (ret = av_opt_set_dict(*puc, options)) < 0)
        goto fail;
    if (options && (*puc)->prot->priv_data_class &&
        (ret = av_opt_set_dict((*puc)->priv_data, options)) < 0)
        goto fail;

    if (!options)
        options = &tmp_opts;

    av_assert0(!whitelist ||
               !(e=av_dict_get(*options, "protocol_whitelist", NULL, 0)) ||
               !strcmp(whitelist, e->value));
    av_assert0(!blacklist ||
               !(e=av_dict_get(*options, "protocol_blacklist", NULL, 0)) ||
               !strcmp(blacklist, e->value));

    if ((ret = av_dict_set(options, "protocol_whitelist", whitelist, 0)) < 0)
        goto fail;

    if ((ret = av_dict_set(options, "protocol_blacklist", blacklist, 0)) < 0)
        goto fail;

    if ((ret = av_opt_set_dict(*puc, options)) < 0)
        goto fail;

    ret = ffurl_connect(*puc, options);

    if (!ret)
        return 0;
fail:
    ffurl_closep(puc);
    return ret;
}
int ffurl_close(URLContext *h)
{
    return ffurl_closep(&h);
}
int ffio_open_whitelist(AVIOContext **s, const char *filename, int flags, const AVIOInterruptCB *int_cb, AVDictionary **options,const char *whitelist, const char *blacklist)
{
    URLContext *h;
    int err;

    *s = NULL;

    err = ffurl_open_whitelist(&h, filename, flags, int_cb, options, whitelist, blacklist, NULL);
    if (err < 0)
        return err;
    err = ffio_fdopen(s, h);
    if (err < 0) {
        ffurl_close(h);
        return err;
    }
    return 0;
}

static int io_open_default(AVFormatContext *s, AVIOContext **pb,
                           const char *url, int flags, AVDictionary **options)
{
    int loglevel;

    if (!strcmp(url, s->url) ||
        s->iformat && !strcmp(s->iformat->name, "image2") ||
        s->oformat && !strcmp(s->oformat->name, "image2")
    ) {
        loglevel = AV_LOG_DEBUG;
    } else
        loglevel = AV_LOG_INFO;

    av_log(s, loglevel, "Opening \'%s\' for %s\n", url, flags & AVIO_FLAG_WRITE ? "writing" : "reading");

#if FF_API_OLD_OPEN_CALLBACKS
    if (s->open_cb)
        return s->open_cb(s, pb, url, flags, &s->interrupt_callback, options);
#endif

    return ffio_open_whitelist(pb, url, flags, &s->interrupt_callback, options, s->protocol_whitelist, s->protocol_blacklist);
}

static void io_close_default(AVFormatContext *s, AVIOContext *pb)
{
    avio_close(pb);
}
static const AVOption avformat_options[] = {
{"avioflags", NULL, offsetof(AVFormatContext,avio_flags), AV_OPT_TYPE_FLAGS, {.i64 = 0 }, INT_MIN, INT_MAX, 3, "avioflags"},
{"direct", "reduce buffering", 0, AV_OPT_TYPE_CONST, {.i64 = AVIO_FLAG_DIRECT }, INT_MIN, INT_MAX, 3, "avioflags"},
{"probesize", "set probing size", offsetof(AVFormatContext,probesize), AV_OPT_TYPE_INT64, {.i64 = 5000000 }, 32, INT64_MAX, 2},
{"formatprobesize", "number of bytes to probe file format", offsetof(AVFormatContext,format_probesize), AV_OPT_TYPE_INT, {.i64 = PROBE_BUF_MAX}, 0, INT_MAX-1, 2},
{"packetsize", "set packet size", offsetof(AVFormatContext,packet_size), AV_OPT_TYPE_INT, {.i64 = 0 }, 0, INT_MAX, 1},
{"fflags", NULL, offsetof(AVFormatContext,flags), AV_OPT_TYPE_FLAGS, {.i64 = AVFMT_FLAG_AUTO_BSF }, INT_MIN, INT_MAX, 3, "fflags"},
{"flush_packets", "reduce the latency by flushing out packets immediately", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_FLUSH_PACKETS }, INT_MIN, INT_MAX, 1, "fflags"},
{"ignidx", "ignore index", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_IGNIDX }, INT_MIN, INT_MAX, 2, "fflags"},
{"genpts", "generate pts", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_GENPTS }, INT_MIN, INT_MAX, 2, "fflags"},
{"nofillin", "do not fill in missing values that can be exactly calculated", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_NOFILLIN }, INT_MIN, INT_MAX, 2, "fflags"},
{"noparse", "disable AVParsers, this needs nofillin too", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_NOPARSE }, INT_MIN, INT_MAX, 2, "fflags"},
{"igndts", "ignore dts", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_IGNDTS }, INT_MIN, INT_MAX, 2, "fflags"},
{"discardcorrupt", "discard corrupted frames", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_DISCARD_CORRUPT }, INT_MIN, INT_MAX, 2, "fflags"},
{"sortdts", "try to interleave outputted packets by dts", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_SORT_DTS }, INT_MIN, INT_MAX, 2, "fflags"},
#if FF_API_LAVF_KEEPSIDE_FLAG
{"keepside", "deprecated, does nothing", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_KEEP_SIDE_DATA }, INT_MIN, INT_MAX, 2, "fflags"},
#endif
{"fastseek", "fast but inaccurate seeks", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_FAST_SEEK }, INT_MIN, INT_MAX, 2, "fflags"},
#if FF_API_LAVF_MP4A_LATM
{"latm", "deprecated, does nothing", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_MP4A_LATM }, INT_MIN, INT_MAX, 1, "fflags"},
#endif
{"nobuffer", "reduce the latency introduced by optional buffering", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_FLAG_NOBUFFER }, 0, INT_MAX, 2, "fflags"},
{"bitexact", "do not write random/volatile data", 0, AV_OPT_TYPE_CONST, { .i64 = AVFMT_FLAG_BITEXACT }, 0, 0, 1, "fflags" },
{"shortest", "stop muxing with the shortest stream", 0, AV_OPT_TYPE_CONST, { .i64 = AVFMT_FLAG_SHORTEST }, 0, 0, 1, "fflags" },
{"autobsf", "add needed bsfs automatically", 0, AV_OPT_TYPE_CONST, { .i64 = AVFMT_FLAG_AUTO_BSF }, 0, 0, 1, "fflags" },
{"seek2any", "allow seeking to non-keyframes on demuxer level when supported", offsetof(AVFormatContext,seek2any), AV_OPT_TYPE_BOOL, {.i64 = 0 }, 0, 1, 2},
{"analyzeduration", "specify how many microseconds are analyzed to probe the input", offsetof(AVFormatContext,max_analyze_duration), AV_OPT_TYPE_INT64, {.i64 = 0 }, 0, INT64_MAX, 2},
{"cryptokey", "decryption key", offsetof(AVFormatContext,key), AV_OPT_TYPE_BINARY, {.dbl = 0}, 0, 0, 2},
{"indexmem", "max memory used for timestamp index (per stream)", offsetof(AVFormatContext,max_index_size), AV_OPT_TYPE_INT, {.i64 = 1<<20 }, 0, INT_MAX, 2},
{"rtbufsize", "max memory used for buffering real-time frames", offsetof(AVFormatContext,max_picture_buffer), AV_OPT_TYPE_INT, {.i64 = 3041280 }, 0, INT_MAX, 2}, 
{"fdebug", "print specific debug info", offsetof(AVFormatContext,debug), AV_OPT_TYPE_FLAGS, {.i64 = 0 }, 0, INT_MAX, 3, "fdebug"},
{"ts", NULL, 0, AV_OPT_TYPE_CONST, {.i64 = FF_FDEBUG_TS }, INT_MIN, INT_MAX, 3, "fdebug"},
{"max_delay", "maximum muxing or demuxing delay in microseconds", offsetof(AVFormatContext,max_delay), AV_OPT_TYPE_INT, {.i64 = -1 }, -1, INT_MAX, 3},
{"start_time_realtime", "wall-clock time when stream begins (PTS==0)", offsetof(AVFormatContext,start_time_realtime), AV_OPT_TYPE_INT64, {.i64 = AV_NOPTS_VALUE}, INT64_MIN, INT64_MAX, 1},
{"fpsprobesize", "number of frames used to probe fps", offsetof(AVFormatContext,fps_probe_size), AV_OPT_TYPE_INT, {.i64 = -1}, -1, INT_MAX-1, 2},
{"audio_preload", "microseconds by which audio packets should be interleaved earlier", offsetof(AVFormatContext,audio_preload), AV_OPT_TYPE_INT, {.i64 = 0}, 0, INT_MAX-1, 1},
{"chunk_duration", "microseconds for each chunk", offsetof(AVFormatContext,max_chunk_duration), AV_OPT_TYPE_INT, {.i64 = 0}, 0, INT_MAX-1, 1},
{"chunk_size", "size in bytes for each chunk", offsetof(AVFormatContext,max_chunk_size), AV_OPT_TYPE_INT, {.i64 = 0}, 0, INT_MAX-1, 1},

{"f_err_detect", "set error detection flags (deprecated; use err_detect, save via avconv)", offsetof(AVFormatContext,error_recognition), AV_OPT_TYPE_FLAGS, {.i64 = AV_EF_CRCCHECK }, INT_MIN, INT_MAX, 2, "err_detect"},
{"err_detect", "set error detection flags", offsetof(AVFormatContext,error_recognition), AV_OPT_TYPE_FLAGS, {.i64 = AV_EF_CRCCHECK }, INT_MIN, INT_MAX, 2, "err_detect"},
{"crccheck", "verify embedded CRCs", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_CRCCHECK }, INT_MIN, INT_MAX, 2, "err_detect"},
{"bitstream", "detect bitstream specification deviations", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_BITSTREAM }, INT_MIN, INT_MAX, 2, "err_detect"},
{"buffer", "detect improper bitstream length", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_BUFFER }, INT_MIN, INT_MAX, 2, "err_detect"},
{"explode", "abort decoding on minor error detection", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_EXPLODE }, INT_MIN, INT_MAX, 2, "err_detect"},
{"ignore_err", "ignore errors", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_IGNORE_ERR }, INT_MIN, INT_MAX, 2, "err_detect"},
{"careful",    "consider things that violate the spec, are fast to check and have not been seen in the wild as errors", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_CAREFUL }, INT_MIN, INT_MAX, 2, "err_detect"},
{"compliant",  "consider all spec non compliancies as errors", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_COMPLIANT | AV_EF_CAREFUL }, INT_MIN, INT_MAX, 2, "err_detect"},
{"aggressive", "consider things that a sane encoder shouldn't do as an error", 0, AV_OPT_TYPE_CONST, {.i64 = AV_EF_AGGRESSIVE | AV_EF_COMPLIANT | AV_EF_CAREFUL}, INT_MIN, INT_MAX, 2, "err_detect"},
{"use_wallclock_as_timestamps", "use wallclock as timestamps", offsetof(AVFormatContext,use_wallclock_as_timestamps), AV_OPT_TYPE_BOOL, {.i64 = 0}, 0, 1, 2},
{"skip_initial_bytes", "set number of bytes to skip before reading header and frames", offsetof(AVFormatContext,skip_initial_bytes), AV_OPT_TYPE_INT64, {.i64 = 0}, 0, INT64_MAX-1, 2},
{"correct_ts_overflow", "correct single timestamp overflows", offsetof(AVFormatContext,correct_ts_overflow), AV_OPT_TYPE_BOOL, {.i64 = 1}, 0, 1, 2},
{"flush_packets", "enable flushing of the I/O context after each packet", offsetof(AVFormatContext,flush_packets), AV_OPT_TYPE_INT, {.i64 = -1}, -1, 1, 1},
{"metadata_header_padding", "set number of bytes to be written as padding in a metadata header", offsetof(AVFormatContext,metadata_header_padding), AV_OPT_TYPE_INT, {.i64 = -1}, -1, INT_MAX, 1},
{"output_ts_offset", "set output timestamp offset", offsetof(AVFormatContext,output_ts_offset), AV_OPT_TYPE_DURATION, {.i64 = 0}, -INT64_MAX, INT64_MAX, 1},
{"max_interleave_delta", "maximum buffering duration for interleaving", offsetof(AVFormatContext,max_interleave_delta), AV_OPT_TYPE_INT64, { .i64 = 10000000 }, 0, INT64_MAX, 1 },
{"f_strict", "how strictly to follow the standards (deprecated; use strict, save via avconv)", offsetof(AVFormatContext,strict_std_compliance), AV_OPT_TYPE_INT, {.i64 = 0 }, INT_MIN, INT_MAX, 3, "strict"},
{"strict", "how strictly to follow the standards", offsetof(AVFormatContext,strict_std_compliance), AV_OPT_TYPE_INT, {.i64 = 0 }, INT_MIN, INT_MAX, 3, "strict"},
{"very", "strictly conform to a older more strict version of the spec or reference software", 0, AV_OPT_TYPE_CONST, {.i64 = FF_COMPLIANCE_VERY_STRICT }, INT_MIN, INT_MAX, 3, "strict"},
{"strict", "strictly conform to all the things in the spec no matter what the consequences", 0, AV_OPT_TYPE_CONST, {.i64 = FF_COMPLIANCE_STRICT }, INT_MIN, INT_MAX, 3, "strict"},
{"normal", NULL, 0, AV_OPT_TYPE_CONST, {.i64 = FF_COMPLIANCE_NORMAL }, INT_MIN, INT_MAX, 3, "strict"},
{"unofficial", "allow unofficial extensions", 0, AV_OPT_TYPE_CONST, {.i64 = FF_COMPLIANCE_UNOFFICIAL }, INT_MIN, INT_MAX, 3, "strict"},
{"experimental", "allow non-standardized experimental variants", 0, AV_OPT_TYPE_CONST, {.i64 = FF_COMPLIANCE_EXPERIMENTAL }, INT_MIN, INT_MAX, 3, "strict"},
{"max_ts_probe", "maximum number of packets to read while waiting for the first timestamp", offsetof(AVFormatContext,max_ts_probe), AV_OPT_TYPE_INT, { .i64 = 50 }, 0, INT_MAX, 2 },
{"avoid_negative_ts", "shift timestamps so they start at 0", offsetof(AVFormatContext,avoid_negative_ts), AV_OPT_TYPE_INT, {.i64 = -1}, -1, 2, 1, "avoid_negative_ts"},
{"auto",              "enabled when required by target format",    0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_AVOID_NEG_TS_AUTO },              INT_MIN, INT_MAX, 1, "avoid_negative_ts"},
{"disabled",          "do not change timestamps",                  0, AV_OPT_TYPE_CONST, {.i64 = 0 },                                    INT_MIN, INT_MAX, 1, "avoid_negative_ts"},
{"make_non_negative", "shift timestamps so they are non negative", 0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_AVOID_NEG_TS_MAKE_NON_NEGATIVE }, INT_MIN, INT_MAX, 1, "avoid_negative_ts"},
{"make_zero",         "shift timestamps so they start at 0",       0, AV_OPT_TYPE_CONST, {.i64 = AVFMT_AVOID_NEG_TS_MAKE_ZERO },         INT_MIN, INT_MAX, 1, "avoid_negative_ts"},
{"dump_separator", "set information dump field separator", offsetof(AVFormatContext,dump_separator), AV_OPT_TYPE_STRING, {.str = ", "}, 0, 0, 3},
{"codec_whitelist", "List of decoders that are allowed to be used", offsetof(AVFormatContext,codec_whitelist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
{"format_whitelist", "List of demuxers that are allowed to be used", offsetof(AVFormatContext,format_whitelist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
{"protocol_whitelist", "List of protocols that are allowed to be used", offsetof(AVFormatContext,protocol_whitelist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
{"protocol_blacklist", "List of protocols that are not allowed to be used", offsetof(AVFormatContext,protocol_blacklist), AV_OPT_TYPE_STRING, { .str = NULL },  0, 0, 2 },
{"max_streams", "maximum number of streams", offsetof(AVFormatContext,max_streams), AV_OPT_TYPE_INT, { .i64 = 1000 }, 0, INT_MAX, 2 },
{"skip_estimate_duration_from_pts", "skip duration calculation in estimate_timings_from_pts", offsetof(AVFormatContext,skip_estimate_duration_from_pts), AV_OPT_TYPE_BOOL, {.i64 = 0}, 0, 1, 2},
{"max_probe_packets", "Maximum number of packets to probe a codec", offsetof(AVFormatContext,max_probe_packets), AV_OPT_TYPE_INT, { .i64 = 2500 }, 0, INT_MAX, 2 },
{NULL},
};

#define ITER_STATE_SHIFT 16

static const AVClass *format_child_class_iterate(void **iter)
{

    void *val = (void*)(((uintptr_t)*iter) & ((1 << ITER_STATE_SHIFT) - 1));
    unsigned int state = ((uintptr_t)*iter) >> ITER_STATE_SHIFT;
    const AVClass *ret = NULL;

    if (state == CHILD_CLASS_ITER_AVIO) {
        ret = &ff_avio_class;
        state++;
        goto finish;
    }

    if (state == CHILD_CLASS_ITER_MUX) {
        const AVOutputFormat *ofmt;

        // while ((ofmt = av_muxer_iterate(&val))) {
        while ((ofmt )) {
            ret = ofmt->priv_class;
            if (ret)
                goto finish;
        }

        val = NULL;
        state++;
    }

    if (state == CHILD_CLASS_ITER_DEMUX) {
        const AVInputFormat *ifmt;

        // while ((ifmt = av_demuxer_iterate(&val))) {
        while (ifmt ) {
            ret = ifmt->priv_class;
            if (ret)
                goto finish;
        }
        val = NULL;
        state++;
    }
finish:
    av_assert0(!((uintptr_t)val >> ITER_STATE_SHIFT));
    *iter = (void*)((uintptr_t)val | (state << ITER_STATE_SHIFT));
    return ret;
}
static void *format_child_next(void *obj, void *prev)
{
    AVFormatContext *s = obj;
    if (!prev && s->priv_data &&
        ((s->iformat && s->iformat->priv_class) ||
          s->oformat && s->oformat->priv_class))
        return s->priv_data;
    if (s->pb && s->pb->av_class && prev != s->pb)
        return s->pb;
    return NULL;
}
static const char* format_to_name(void* ptr)
{
    AVFormatContext* fc = (AVFormatContext*) ptr;
    if(fc->iformat) return fc->iformat->name;
    else if(fc->oformat) return fc->oformat->name;
    else return "NULL";
}
static AVClassCategory AVClass_get_category(void *ptr)
{
    AVCodecContext* avctx = ptr;
    if(avctx->codec && avctx->codec->decode) return AV_CLASS_CATEGORY_DECODER;
    else                                     return AV_CLASS_CATEGORY_ENCODER;
}
static const AVClass av_format_context_class = {
    .class_name     = "AVFormatContext",
    .item_name      = format_to_name,
    .option         = avformat_options,
    .version        = LIBAVUTIL_VERSION_INT,
    .child_next     = format_child_next,
    .child_class_iterate = format_child_class_iterate,
    .category       = AV_CLASS_CATEGORY_MUXER,
    .get_category   = AVClass_get_category,
};
static void avformat_get_context_defaults(AVFormatContext *s)
{
    memset(s, 0, sizeof(AVFormatContext));
    s->av_class = &av_format_context_class;
    s->io_open  = io_open_default;
    s->io_close = io_close_default;
    av_opt_set_defaults(s);
}
AVFormatContext *avformat_alloc_context(void)
{
    AVFormatContext *ic;
    AVFormatInternal *internal;
    ic = av_malloc(sizeof(AVFormatContext));
    if (!ic) return ic;

    internal = av_mallocz(sizeof(*internal));
    if (!internal) {
        av_free(ic);
        return NULL;
    }
    avformat_get_context_defaults(ic);
    ic->internal = internal;
    ic->internal->offset = AV_NOPTS_VALUE;
    ic->internal->raw_packet_buffer_remaining_size = RAW_PACKET_BUFFER_SIZE;
    ic->internal->shortest_end = AV_NOPTS_VALUE;
    return ic;
}
AVDictionary **setup_find_stream_info_opts(AVFormatContext *s,
                                           AVDictionary *codec_opts);
void print_error(const char *filename, int err)
{
    char errbuf[128];
    const char *errbuf_ptr = errbuf;

    if (av_strerror(err, errbuf, sizeof(errbuf)) < 0)
        errbuf_ptr = strerror(AVUNERROR(err));
    av_log(NULL, AV_LOG_ERROR, "%s: %s\n", filename, errbuf_ptr);
}
static int read_thread(void *arg)
{
    VideoState *is = arg;
    AVFormatContext *ic = NULL;
    int err, i, ret;
    int st_index[AVMEDIA_TYPE_NB];
    AVPacket pkt1, *pkt = &pkt1;
    int64_t stream_start_time;
    int pkt_in_play_range = 0;
    AVDictionaryEntry *t;
    SDL_mutex *wait_mutex = SDL_CreateMutex();
    int scan_all_pmts_set = 0;
    int64_t pkt_ts;
    if (wait_mutex == NULL)
    {
        av_log(NULL, 8, "SDL_CreateMutex(): %s\n", SDL_GetError());
        ret = (-(12));
        goto fail;
    }
    memset(st_index, -1, sizeof(st_index));
    is->eof = 0;
    ic = avformat_alloc_context();
    if (ic == NULL)
    {
        av_log(NULL, 8, "Could not allocate context.\n");
        ret = (-(12));
        goto fail;
    }
    ic->interrupt_callback.callback = decode_interrupt_cb;
    ic->interrupt_callback.opaque = is;
    t = av_dict_get(format_opts, "scan_all_pmts", NULL, 1);
    if (t == NULL)
    {
        av_dict_set(&format_opts, "scan_all_pmts", "1", 16);
        scan_all_pmts_set = 1;
    }
    err = avformat_open_input(&ic, is->filename, is->iformat, &format_opts);
    if (err < 0)
    {
        print_error(is->filename, err);
        ret = -1;
        goto fail;
    }
    if (scan_all_pmts_set != 0)
        av_dict_set(&format_opts, "scan_all_pmts",NULL, 1);
    t = av_dict_get(format_opts, "", NULL, 2);
    if (t != NULL)
    {
        av_log(NULL, 16, "Option %s not found.\n", t->key);
        ret = (-(int)(0xF8 | ('O' << 8) | ('P' << 16) | (unsigned)('T') << 24));
        goto fail;
    }
    is->ic = ic;
    if (genpts != 0)
        ic->flags |= 0x0001;
    av_format_inject_global_side_data(ic);
    if (find_stream_info != 0)
    {
        AVDictionary **opts = setup_find_stream_info_opts(ic, codec_opts);
        int orig_nb_streams = ic->nb_streams;
        err = avformat_find_stream_info(ic, opts);
        for (i = 0; i < orig_nb_streams; i++)
            av_dict_free(&opts[i]);
        av_freep(&opts);
        if (err < 0)
        {
            av_log(NULL, 24,"%s: could not find codec parameters\n", is->filename);
            ret = -1;
            goto fail;
        }
    }
    if (ic->pb)
        ic->pb->eof_reached = 0; // FIXME hack, ffplay maybe should not use avio_feof() to test for the end
    if (seek_by_bytes < 0)
        seek_by_bytes = !!(ic->iformat->flags & AVFMT_TS_DISCONT) && strcmp("ogg", ic->iformat->name);
    is->max_frame_duration = (ic->iformat->flags & AVFMT_TS_DISCONT) ? 10.0 : 3600.0;
    if (!window_title && (t = av_dict_get(ic->metadata, "title", NULL, 0)))
        window_title = av_asprintf("%s - %s", t->value, input_filename);
    if (start_time != 0)
    {
        int64_t timestamp;
        timestamp = start_time;
        if (ic->start_time != 0)
            timestamp += ic->start_time;
        ret = avformat_seek_file(ic, -1, (-9223372036854775807LL - 1), timestamp, 9223372036854775807LL, 0);
        if (ret < 0)
        {
            av_log(NULL, 24, "%s: could not seek to position %0.3f\n", is->filename, (double)timestamp / 1000000);
        }
    }
    is->realtime = is_realtime(ic);
    if (show_status)
        av_dump_format(ic, 0, is->filename, 0);
    for (i = 0; i < ic->nb_streams; i++)
    {
        AVStream *st = ic->streams[i];
        enum AVMediaType type = st->codecpar->codec_type;
        st->discard = AVDISCARD_ALL;
        if (type >= 0 && wanted_stream_spec[type] && st_index[type] == -1)
            if (avformat_match_stream_specifier(ic, st, wanted_stream_spec[type]) > 0)
                st_index[type] = i;
    }
    for (i = 0; i < AVMEDIA_TYPE_NB; i++)
    {
        if (wanted_stream_spec[i] && st_index[i] == -1)
        {
            av_log(NULL, 16, "Stream specifier %s does not match any %s stream\n", wanted_stream_spec[i], av_get_media_type_string(i));
            st_index[i] = 0x7fffffff;
        }
    }
    if (video_disable == 0)
        st_index[AVMEDIA_TYPE_VIDEO] =
            av_find_best_stream(ic, AVMEDIA_TYPE_VIDEO, st_index[AVMEDIA_TYPE_VIDEO], -1, NULL, 0);
    if (audio_disable == 0)
        st_index[AVMEDIA_TYPE_AUDIO] = av_find_best_stream(ic, AVMEDIA_TYPE_AUDIO, st_index[AVMEDIA_TYPE_AUDIO], st_index[AVMEDIA_TYPE_VIDEO], NULL, 0);
    if (video_disable == 0 && subtitle_disable == 0)
        st_index[AVMEDIA_TYPE_SUBTITLE] = av_find_best_stream(ic, AVMEDIA_TYPE_SUBTITLE, st_index[AVMEDIA_TYPE_SUBTITLE], (st_index[AVMEDIA_TYPE_AUDIO] >= 0 ? st_index[AVMEDIA_TYPE_AUDIO] : st_index[AVMEDIA_TYPE_VIDEO]),NULL, 0);
    is->show_mode = show_mode;
    if (st_index[AVMEDIA_TYPE_VIDEO] >= 0)
    {
        AVStream *st = ic->streams[st_index[AVMEDIA_TYPE_VIDEO]];
        AVCodecParameters *codecpar = st->codecpar;
        AVRational sar = av_guess_sample_aspect_ratio(ic, st, NULL);
        if (codecpar->width)
            set_default_window_size(codecpar->width, codecpar->height, sar);
    }
    if (st_index[AVMEDIA_TYPE_AUDIO] >= 0)
    {
        stream_component_open(is, st_index[AVMEDIA_TYPE_AUDIO]);
    }
    ret = -1;
    if (st_index[AVMEDIA_TYPE_VIDEO] >= 0)
    {
        ret = stream_component_open(is, st_index[AVMEDIA_TYPE_VIDEO]);
    }
    if (is->show_mode == SHOW_MODE_NONE)
        is->show_mode = ret >= 0 ? SHOW_MODE_VIDEO : SHOW_MODE_RDFT;
    if (st_index[AVMEDIA_TYPE_SUBTITLE] >= 0)
    {
        stream_component_open(is, st_index[AVMEDIA_TYPE_SUBTITLE]);
    }
    if (is->video_stream < 0 && is->audio_stream < 0)
    {
        av_log(NULL, 8, "Failed to open file '%s' or configure filtergraph\n", is->filename);
        ret = -1;
        goto fail;
    }
    if (infinite_buffer < 0 && is->realtime)
        infinite_buffer = 1;
    for (;;)
    {
        if (is->abort_request)
            break;
        if (is->paused != is->last_paused)
        {
            is->last_paused = is->paused;
            if (is->paused)
                is->read_pause_return = av_read_pause(ic);
            else
                av_read_play(ic);
        }
        if (is->paused && (!strcmp(ic->iformat->name, "rtsp") || (ic->pb && !strncmp(input_filename, "mmsh:", 5))))
        {
            SDL_Delay(10);
            continue;
        }
        if (is->seek_req)
        {
            int64_t seek_target = is->seek_pos;
            int64_t seek_min = is->seek_rel > 0 ? seek_target - is->seek_rel + 2 : (-9223372036854775807LL - 1);
            int64_t seek_max = is->seek_rel < 0 ? seek_target - is->seek_rel - 2 : 9223372036854775807LL;
            // FIXME the +-2 is due to rounding being not done in the correct direction in generation of the seek_pos/seek_rel variables
            ret = avformat_seek_file(is->ic, -1, seek_min, seek_target, seek_max, is->seek_flags);
            if (ret < 0)
            {
                av_log(NULL, 16,"%s: error while seeking\n", is->ic->url);
            }
            else
            {
                if (is->audio_stream >= 0)
                {
                    packet_queue_flush(&is->audioq);
                    packet_queue_put(&is->audioq, &flush_pkt);
                }
                if (is->subtitle_stream >= 0)
                {
                    packet_queue_flush(&is->subtitleq);
                    packet_queue_put(&is->subtitleq, &flush_pkt);
                }
                if (is->video_stream >= 0)
                {
                    packet_queue_flush(&is->videoq);
                    packet_queue_put(&is->videoq, &flush_pkt);
                }
                if (is->seek_flags & 2)
                {
                    set_clock(&is->extclk, NAN, 0);
                }
                else
                {
                    set_clock(&is->extclk, seek_target / (double)1000000, 0);
                }
            }
            is->seek_req = 0;
            is->queue_attachments_req = 1;
            is->eof = 0;
            if (is->paused)
                step_to_next_frame(is);
        }
        if (is->queue_attachments_req)
        {
            if (is->video_st && is->video_st->disposition & 0x0400)
            {
                AVPacket copy;
                if ((ret = av_packet_ref(&copy, &is->video_st->attached_pic)) < 0)
                    goto fail;
                packet_queue_put(&is->videoq, &copy);
                packet_queue_put_nullpacket(&is->videoq, is->video_stream);
            }
            is->queue_attachments_req = 0;
        }
        if (infinite_buffer < 1 &&
            (is->audioq.size + is->videoq.size + is->subtitleq.size > (15 * 1024 * 1024) || (stream_has_enough_packets(is->audio_st, is->audio_stream, &is->audioq) &&
                                                                                             stream_has_enough_packets(is->video_st, is->video_stream, &is->videoq) &&
                                                                                             stream_has_enough_packets(is->subtitle_st, is->subtitle_stream, &is->subtitleq))))
        {
            SDL_LockMutex(wait_mutex);
            SDL_CondWaitTimeout(is->continue_read_thread, wait_mutex, 10);
            SDL_UnlockMutex(wait_mutex);
            continue;
        }
        if (!is->paused &&
            (!is->audio_st || (is->auddec.finished == is->audioq.serial && frame_queue_nb_remaining(&is->sampq) == 0)) &&
            (!is->video_st || (is->viddec.finished == is->videoq.serial && frame_queue_nb_remaining(&is->pictq) == 0)))
        {
            if (loop != 1 && (!loop || --loop))
            {
                stream_seek(is, start_time != 0 ? start_time : 0, 0, 0);
            }
            else if (autoexit)
            {
                ret = (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24)));
                goto fail;
            }
        }
        ret = av_read_frame(ic, pkt);
        if (ret < 0)
        {
            if ((ret == (-(int)(('1') | (('O') << 8) | (('F') << 16) | ((unsigned)(' ') << 24))) || avio_feof(ic->pb)) && !is->eof)
            {
                if (is->video_stream >= 0)
                    packet_queue_put_nullpacket(&is->videoq, is->video_stream);
                if (is->audio_stream >= 0)
                    packet_queue_put_nullpacket(&is->audioq, is->audio_stream);
                if (is->subtitle_stream >= 0)
                    packet_queue_put_nullpacket(&is->subtitleq, is->subtitle_stream);
                is->eof = 1;
            }
            if (ic->pb && ic->pb->error)
            {
                if (autoexit)
                    goto fail;
                else
                    break;
            }
            SDL_LockMutex(wait_mutex);
            SDL_CondWaitTimeout(is->continue_read_thread, wait_mutex, 10);
            SDL_UnlockMutex(wait_mutex);
            continue;
        }
        else
        {
            is->eof = 0;
        }
        stream_start_time = ic->streams[pkt->stream_index]->start_time;
        pkt_ts = pkt->pts == 0 ? pkt->dts : pkt->pts;
        pkt_in_play_range = duration == 0 ||
                            (pkt_ts - (stream_start_time != 0 ? stream_start_time : 0)) * av_q2d(ic->streams[pkt->stream_index]->time_base) - (double)(start_time != 0 ? start_time : 0) / 1000000 <= ((double)duration / 1000000);
        if (pkt->stream_index == is->audio_stream && pkt_in_play_range)
        {
            packet_queue_put(&is->audioq, pkt);
        }
        else if (pkt->stream_index == is->video_stream && pkt_in_play_range && !(is->video_st->disposition & 0x0400))
        {
            packet_queue_put(&is->videoq, pkt);
        }
        else if (pkt->stream_index == is->subtitle_stream && pkt_in_play_range)
        {
            packet_queue_put(&is->subtitleq, pkt);
        }
        else
        {
            av_packet_unref(pkt);
        }
    }
    ret = 0;
fail:
    if (ic && !is->ic)
        avformat_close_input(&ic);
    if (ret != 0)
    {
        SDL_Event event;
        event.type = (SDL_USEREVENT + 2);
        event.user.data1 = is;
        SDL_PushEvent(&event);
    }
    SDL_DestroyMutex(wait_mutex);
    return 0;
}

static VideoState *stream_open(const char *filename, AVInputFormat *iformat)
{
    VideoState *is;
    is = av_mallocz(sizeof(VideoState));
    if (!is)
        return NULL;
    is->last_video_stream = is->video_stream = -1;
    is->last_audio_stream = is->audio_stream = -1;
    is->last_subtitle_stream = is->subtitle_stream = -1;
    is->filename = av_strdup(filename);
    if (!is->filename)
        goto fail;
    is->iformat = iformat;
    is->ytop = 0;
    is->xleft = 0;
    if (frame_queue_init(&is->pictq, &is->videoq, 3, 1) < 0)
        goto fail;
    if (frame_queue_init(&is->subpq, &is->subtitleq, 16, 0) < 0)
        goto fail;
    if (frame_queue_init(&is->sampq, &is->audioq, 9, 1) < 0)
        goto fail;
    if (packet_queue_init(&is->videoq) < 0 ||
        packet_queue_init(&is->audioq) < 0 ||
        packet_queue_init(&is->subtitleq) < 0)
        goto fail;
    if (!(is->continue_read_thread = SDL_CreateCond()))
    {
        av_log(NULL, 8, "SDL_CreateCond(): %s\n", SDL_GetError());
        goto fail;
    }
    init_clock(&is->vidclk, &is->videoq.serial);
    init_clock(&is->audclk, &is->audioq.serial);
    init_clock(&is->extclk, &is->extclk.serial);
    is->audio_clock_serial = -1;
    if (startup_volume < 0)
        av_log(NULL, 24, "-volume=%d < 0, setting to 0\n", startup_volume);
    if (startup_volume > 100)
        av_log(NULL, 24, "-volume=%d > 100, setting to 100\n", startup_volume);
    startup_volume = av_clip_c(startup_volume, 0, 100);
    startup_volume = av_clip_c(128 * startup_volume / 100, 0, 128);
    is->audio_volume = startup_volume;
    is->muted = 0;
    is->av_sync_type = av_sync_type;
    is->read_tid = SDL_CreateThread(read_thread, "read_thread", is);
    if (!is->read_tid)
    {
        av_log(NULL, 8, "SDL_CreateThread(): %s\n", SDL_GetError());
    fail:
        stream_close(is);
        return NULL;
    }
    return is;
}

static void stream_cycle_channel(VideoState *is, int codec_type)
{
    AVFormatContext *ic = is->ic;
    int start_index, stream_index;
    int old_index;
    AVStream *st;
    AVProgram *p = NULL;
    int nb_streams = is->ic->nb_streams;
    if (codec_type == AVMEDIA_TYPE_VIDEO)
    {
        start_index = is->last_video_stream;
        old_index = is->video_stream;
    }
    else if (codec_type == AVMEDIA_TYPE_AUDIO)
    {
        start_index = is->last_audio_stream;
        old_index = is->audio_stream;
    }
    else
    {
        start_index = is->last_subtitle_stream;
        old_index = is->subtitle_stream;
    }
    stream_index = start_index;
    if (codec_type != AVMEDIA_TYPE_VIDEO && is->video_stream != -1)
    {
        p = av_find_program_from_stream(ic,
                                        NULL, is->video_stream);
        if (p)
        {
            nb_streams = p->nb_stream_indexes;
            for (start_index = 0; start_index < nb_streams; start_index++)
                if (p->stream_index[start_index] == stream_index)
                    break;
            if (start_index == nb_streams)
                start_index = -1;
            stream_index = start_index;
        }
    }
    for (;;)
    {
        if (++stream_index >= nb_streams)
        {
            if (codec_type == AVMEDIA_TYPE_SUBTITLE)
            {
                stream_index = -1;
                is->last_subtitle_stream = -1;
                goto the_end;
            }
            if (start_index == -1)
                return;
            stream_index = 0;
        }
        if (stream_index == start_index)
            return;
        st = is->ic->streams[p ? p->stream_index[stream_index] : stream_index];
        if (st->codecpar->codec_type == codec_type)
        {
            switch (codec_type)
            {
            case AVMEDIA_TYPE_AUDIO:
                if (st->codecpar->sample_rate != 0 &&
                    st->codecpar->channels != 0)
                    goto the_end;
                break;
            case AVMEDIA_TYPE_VIDEO:
            case AVMEDIA_TYPE_SUBTITLE:
                goto the_end;
            default:
                break;
            }
        }
    }
the_end:
    if (p && stream_index != -1)
        stream_index = p->stream_index[stream_index];
    av_log(NULL, 32, "Switch %s stream from #%d to #%d\n",
        av_get_media_type_string(codec_type),
        old_index,
        stream_index);
    stream_component_close(is, old_index);
    stream_component_open(is, stream_index);
}

static void toggle_full_screen(VideoState *is)
{
    is_full_screen = !is_full_screen;
    SDL_SetWindowFullscreen(window, is_full_screen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

static void toggle_audio_display(VideoState *is)
{
    int next = is->show_mode;
    do
    {
        next = (next + 1) % SHOW_MODE_NB;
    } while (next != is->show_mode && (next == SHOW_MODE_VIDEO && !is->video_st || next != SHOW_MODE_VIDEO && !is->audio_st));
    if (is->show_mode != next)
    {
        is->force_refresh = 1;
        is->show_mode = next;
    }
}

static void refresh_loop_wait_event(VideoState *is, SDL_Event *event)
{
    double remaining_time = 0.0;
    SDL_PumpEvents();
    while (!SDL_PeepEvents(event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT))
    {
        if (!cursor_hidden && av_gettime_relative() - cursor_last_shown > 1000000)
        {
            SDL_ShowCursor(0);
            cursor_hidden = 1;
        }
        if (remaining_time > 0.0)
            av_usleep((int64_t)(remaining_time * 1000000.0));
        remaining_time = 0.01;
        if (is->show_mode != SHOW_MODE_NONE && (!is->paused || is->force_refresh))
            video_refresh(is, &remaining_time);
        SDL_PumpEvents();
    }
}

static void seek_chapter(VideoState *is, int incr)
{
    int64_t pos = get_master_clock(is) * 1000000;
    int i;
    if (!is->ic->nb_chapters)
        return;
    for (i = 0; i < is->ic->nb_chapters; i++)
    {
        AVChapter *ch = is->ic->chapters[i];
        if (av_compare_ts(pos, (AVRational){1, 1000000}, ch->start, ch->time_base) < 0)
        {
            i--;
            break;
        }
    }
    i += incr;
    i = (i > 0 ? i : 0);
    if (i >= is->ic->nb_chapters)
        return;
    av_log(NULL, 40, "Seeking to chapter %d.\n", i);
    stream_seek(is, av_rescale_q(is->ic->chapters[i]->start, is->ic->chapters[i]->time_base, (AVRational){1, 1000000}), 0, 0);
}

static void event_loop(VideoState *cur_stream)
{
    SDL_Event event;
    double incr, pos, frac;
    for (;;)
    {
        double x;
        refresh_loop_wait_event(cur_stream, &event);
        switch (event.type)
        {
        case SDL_KEYDOWN:
            if (exit_on_keydown || event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q)
            {
                do_exit(cur_stream);
                break;
            }
            // If we don't yet have a window, skip all key events, because read_thread might still be initializing...
            if (!cur_stream->width)
                continue;
            switch (event.key.keysym.sym)
            {
            case SDLK_f:
                toggle_full_screen(cur_stream);
                cur_stream->force_refresh = 1;
                break;
            case SDLK_p:
            case SDLK_SPACE:
                toggle_pause(cur_stream);
                break;
            case SDLK_m:
                toggle_mute(cur_stream);
                break;
            case SDLK_KP_MULTIPLY:
            case SDLK_0:
                update_volume(cur_stream, 1, (0.75));
                break;
            case SDLK_KP_DIVIDE:
            case SDLK_9:
                update_volume(cur_stream, -1, (0.75));
                break;
            case SDLK_s: // S: Step to next frame
                step_to_next_frame(cur_stream);
                break;
            case SDLK_a:
                stream_cycle_channel(cur_stream, AVMEDIA_TYPE_AUDIO);
                break;
            case SDLK_v:
                stream_cycle_channel(cur_stream, AVMEDIA_TYPE_VIDEO);
                break;
            case SDLK_c:
                stream_cycle_channel(cur_stream, AVMEDIA_TYPE_VIDEO);
                stream_cycle_channel(cur_stream, AVMEDIA_TYPE_AUDIO);
                stream_cycle_channel(cur_stream, AVMEDIA_TYPE_SUBTITLE);
                break;
            case SDLK_t:
                stream_cycle_channel(cur_stream, AVMEDIA_TYPE_SUBTITLE);
                break;
            case SDLK_w:
                if (cur_stream->show_mode == SHOW_MODE_VIDEO && cur_stream->vfilter_idx < nb_vfilters - 1)
                {
                    if (++cur_stream->vfilter_idx >= nb_vfilters)
                        cur_stream->vfilter_idx = 0;
                }
                else
                {
                    cur_stream->vfilter_idx = 0;
                    toggle_audio_display(cur_stream);
                }
                break;
            case SDLK_PAGEUP:
                if (cur_stream->ic->nb_chapters <= 1)
                {
                    incr = 600.0;
                    goto do_seek;
                }
                seek_chapter(cur_stream, 1);
                break;
            case SDLK_PAGEDOWN:
                if (cur_stream->ic->nb_chapters <= 1)
                {
                    incr = -600.0;
                    goto do_seek;
                }
                seek_chapter(cur_stream, -1);
                break;
            case SDLK_LEFT:
                incr = seek_interval ? -seek_interval : -10.0;
                goto do_seek;
            case SDLK_RIGHT:
                incr = seek_interval ? seek_interval : 10.0;
                goto do_seek;
            case SDLK_UP:
                incr = 60.0;
                goto do_seek;
            case SDLK_DOWN:
                incr = -60.0;
            do_seek:
                if (seek_by_bytes)
                {
                    pos = -1;
                    if (pos < 0 && cur_stream->video_stream >= 0)
                        pos = frame_queue_last_pos(&cur_stream->pictq);
                    if (pos < 0 && cur_stream->audio_stream >= 0)
                        pos = frame_queue_last_pos(&cur_stream->sampq);
                    if (pos < 0)
                        pos = avio_tell(cur_stream->ic->pb);
                    if (cur_stream->ic->bit_rate)
                        incr *= cur_stream->ic->bit_rate / 8.0;
                    else
                        incr *= 180000.0;
                    pos += incr;
                    stream_seek(cur_stream, pos, incr, 1);
                }
                else
                {
                    pos = get_master_clock(cur_stream);
                    if (isnan(pos))
                        pos = (double)cur_stream->seek_pos / 1000000;
                    pos += incr;
                    if (cur_stream->ic->start_time != 0 && pos < cur_stream->ic->start_time / (double)1000000)
                        pos = cur_stream->ic->start_time / (double)1000000;
                    stream_seek(cur_stream, (int64_t)(pos * 1000000), (int64_t)(incr * 1000000), 0);
                }
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (exit_on_mousedown)
            {
                do_exit(cur_stream);
                break;
            }
            if (event.button.button == 1)
            {
                static int64_t last_mouse_left_click = 0;
                if (av_gettime_relative() - last_mouse_left_click <= 500000)
                {
                    toggle_full_screen(cur_stream);
                    cur_stream->force_refresh = 1;
                    last_mouse_left_click = 0;
                }
                else
                {
                    last_mouse_left_click = av_gettime_relative();
                }
            }
        case SDL_MOUSEMOTION:
            if (cursor_hidden)
            {
                SDL_ShowCursor(1);
                cursor_hidden = 0;
            }
            cursor_last_shown = av_gettime_relative();
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button != 3)
                    break;
                x = event.button.x;
            }
            else
            {
                if (!(event.motion.state & (1 << ((3) - 1))))
                    break;
                x = event.motion.x;
            }
            if (seek_by_bytes || cur_stream->ic->duration <= 0)
            {
                uint64_t size = avio_size(cur_stream->ic->pb);
                stream_seek(cur_stream, size * x / cur_stream->width, 0, 1);
            }
            else
            {
                int64_t ts;
                int ns, hh, mm, ss;
                int tns, thh, tmm, tss;
                tns = cur_stream->ic->duration / 1000000LL;
                thh = tns / 3600;
                tmm = (tns % 3600) / 60;
                tss = (tns % 60);
                frac = x / cur_stream->width;
                ns = frac * tns;
                hh = ns / 3600;
                mm = (ns % 3600) / 60;
                ss = (ns % 60);
                av_log(NULL, 32,"Seek to %2.0f%% (%2d:%02d:%02d) of total duration (%2d:%02d:%02d)       \n", frac * 100,hh, mm, ss, thh, tmm, tss);
                ts = frac * cur_stream->ic->duration;
                if (cur_stream->ic->start_time != 0)
                    ts += cur_stream->ic->start_time;
                stream_seek(cur_stream, ts, 0, 0);
            }
            break;
        case SDL_WINDOWEVENT:
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                screen_width = cur_stream->width = event.window.data1;
                screen_height = cur_stream->height = event.window.data2;
                if (cur_stream->vis_texture)
                {
                    SDL_DestroyTexture(cur_stream->vis_texture);
                    cur_stream->vis_texture =
                        NULL;
                }
            case SDL_WINDOWEVENT_EXPOSED:
                cur_stream->force_refresh = 1;
            }
            break;
        case SDL_QUIT:
        case (SDL_USEREVENT + 2):
            do_exit(cur_stream);
            break;
        default:
            break;
        }
    }
}
int opt_default(void *optctx, const char *opt, const char *arg);
static int opt_frame_size(void *optctx, const char *opt, const char *arg)
{
    av_log(NULL, 24, "Option -s is deprecated, use -video_size.\n");
    return opt_default(NULL, "video_size", arg);
}
double parse_number_or_die(const char *context, const char *numstr, int type,
                           double min, double max);
static int opt_width(void *optctx, const char *opt, const char *arg)
{
    screen_width = parse_number_or_die(opt, arg, 0x0400, 1, 0x7fffffff);
    return 0;
}

static int opt_height(void *optctx, const char *opt, const char *arg)
{
    screen_height = parse_number_or_die(opt, arg, 0x0400, 1, 0x7fffffff);
    return 0;
}

static int opt_format(void *optctx, const char *opt, const char *arg)
{
    file_iformat = av_find_input_format(arg);
    if (!file_iformat)
    {
        av_log(NULL, 8, "Unknown input format: %s\n", arg);
        return (-(
            22));
    }
    return 0;
}

static int opt_frame_pix_fmt(void *optctx, const char *opt, const char *arg)
{
    av_log(NULL, 24, "Option -pix_fmt is deprecated, use -pixel_format.\n");
    return opt_default(
        NULL, "pixel_format", arg);
}

static int opt_sync(void *optctx, const char *opt, const char *arg)
{
    if (!strcmp(arg, "audio"))
        av_sync_type = AV_SYNC_AUDIO_MASTER;
    else if (!strcmp(arg, "video"))
        av_sync_type = AV_SYNC_VIDEO_MASTER;
    else if (!strcmp(arg, "ext"))
        av_sync_type = AV_SYNC_EXTERNAL_CLOCK;
    else
    {
        av_log(NULL, 16, "Unknown value for %s: %s\n", opt, arg);
        exit(1);
    }
    return 0;
}

static void (*program_exit)(int ret);

void exit_program(int ret)
{
    if (program_exit)
        program_exit(ret);

    exit(ret);
}

int64_t parse_time_or_die(const char *context, const char *timestr,
                          int is_duration)
{
    int64_t us;
    if (av_parse_time(&us, timestr, is_duration) < 0)
    {
        av_log(NULL, AV_LOG_FATAL, "Invalid %s specification for %s: %s\n",
               is_duration ? "duration" : "date", context, timestr);
        exit_program(1);
    }
    return us;
}

static int opt_seek(void *optctx, const char *opt, const char *arg)
{
    start_time = parse_time_or_die(opt, arg, 1);
    return 0;
}

static int opt_duration(void *optctx, const char *opt, const char *arg)
{
    duration = parse_time_or_die(opt, arg, 1);
    return 0;
}

static int opt_show_mode(void *optctx, const char *opt, const char *arg)
{
    show_mode = !strcmp(arg, "video") ? SHOW_MODE_VIDEO : !strcmp(arg, "waves") ? SHOW_MODE_WAVES : !strcmp(arg, "rdft") ? SHOW_MODE_RDFT : parse_number_or_die(opt, arg, 0x0080, 0, SHOW_MODE_NB - 1);
    return 0;
}

static void opt_input_file(void *optctx, const char *filename)
{
    if (input_filename)
    {
        av_log(NULL, 8,"Argument '%s' provided as input filename, but '%s' was already specified.\n",filename, input_filename);
        exit(1);
    }
    if (!strcmp(filename, "-"))
        filename = "pipe:";
    input_filename = filename;
}

static int opt_codec(void *optctx, const char *opt, const char *arg)
{
    const char *spec = strchr(opt, ':');
    if (!spec)
    {
        av_log(NULL, 16,
            "No media specifier was specified in '%s' in option '%s'\n",
            arg, opt);
        return (-(22));
    }
    spec++;
    switch (spec[0])
    {
    case 'a':
        audio_codec_name = arg;
        break;
    case 's':
        subtitle_codec_name = arg;
        break;
    case 'v':
        video_codec_name = arg;
        break;
    default:
        av_log(NULL, 16,"Invalid media specifier '%s' in option '%s'\n", spec, opt);
        return (-(22));
    }
    return 0;
}

static int dummy;


void *grow_array(void *array, int elem_size, int *size, int new_size)
{
    if (new_size >= INT_MAX / elem_size) {
        av_log(NULL, AV_LOG_ERROR, "Array too big.\n");
        exit_program(1);
    }
    if (*size < new_size) {
        uint8_t *tmp = av_realloc_array(array, new_size, elem_size);
        if (!tmp) {
            av_log(NULL, AV_LOG_ERROR, "Could not alloc buffer.\n");
            exit_program(1);
        }
        memset(tmp + *size*elem_size, 0, (new_size-*size) * elem_size);
        *size = new_size;
        return tmp;
    }
    return array;
}

void uninit_opts(void)
{
    av_dict_free(&swr_opts);
    av_dict_free(&sws_dict);
    av_dict_free(&format_opts);
    av_dict_free(&codec_opts);
    av_dict_free(&resample_opts);
}

double get_rotation(AVStream *st)
{
    uint8_t *displaymatrix = av_stream_get_side_data(st,
                                                     AV_PKT_DATA_DISPLAYMATRIX, NULL);
    double theta = 0;
    if (displaymatrix)
        theta = -av_display_rotation_get((int32_t *)displaymatrix);

    theta -= 360 * floor(theta / 360 + 0.9 / 360);

    if (fabs(theta - 90 * round(theta / 90)) > 2)
        av_log(NULL, AV_LOG_WARNING, "Odd rotation angle.\n"
                                     "If you want to help, upload a sample "
                                     "of this file to https:"
                                     "and contact the ffmpeg-devel mailing list. (ffmpeg-devel@ffmpeg.org)");

    return theta;
}

char *av_strndup(const char *s, size_t len)
{
    char *ret = NULL, *end;

    if (!s)
        return NULL;

    end = memchr(s, 0, len);
    if (end)
        len = end - s;

    ret = av_realloc(NULL, len + 1);
    if (!ret)
        return NULL;

    memcpy(ret, s, len);
    ret[len] = 0;
    return ret;
}
static int match_stream_specifier(AVFormatContext *s, AVStream *st,
                                  const char *spec, const char **indexptr, AVProgram **p)
{
    int match = 1; 
    while (*spec)
    {
        if (*spec <= '9' && *spec >= '0')
        { 
            if (indexptr)
                *indexptr = spec;
            return match;
        }
        else if (*spec == 'v' || *spec == 'a' || *spec == 's' || *spec == 'd' ||
                 *spec == 't' || *spec == 'V')
        { 
            enum AVMediaType type;
            int nopic = 0;

            switch (*spec++)
            {
            case 'v':
                type = AVMEDIA_TYPE_VIDEO;
                break;
            case 'a':
                type = AVMEDIA_TYPE_AUDIO;
                break;
            case 's':
                type = AVMEDIA_TYPE_SUBTITLE;
                break;
            case 'd':
                type = AVMEDIA_TYPE_DATA;
                break;
            case 't':
                type = AVMEDIA_TYPE_ATTACHMENT;
                break;
            case 'V':
                type = AVMEDIA_TYPE_VIDEO;
                nopic = 1;
                break;
            default:
                av_assert0(0);
            }
            if (*spec && *spec++ != ':') 
                return AVERROR(EINVAL);

#if FF_API_LAVF_AVCTX
            
            if (type != st->codecpar->codec_type && (st->codecpar->codec_type != AVMEDIA_TYPE_UNKNOWN || st->codec->codec_type != type))
                match = 0;
            
#else
            if (type != st->codecpar->codec_type)
                match = 0;
#endif
            if (nopic && (st->disposition & AV_DISPOSITION_ATTACHED_PIC))
                match = 0;
        }
        else if (*spec == 'p' && *(spec + 1) == ':')
        {
            int prog_id, i, j;
            int found = 0;
            char *endptr;
            spec += 2;
            prog_id = strtol(spec, &endptr, 0);
            
            if (spec == endptr || (*endptr && *endptr++ != ':'))
                return AVERROR(EINVAL);
            spec = endptr;
            if (match)
            {
                for (i = 0; i < s->nb_programs; i++)
                {
                    if (s->programs[i]->id != prog_id)
                        continue;

                    for (j = 0; j < s->programs[i]->nb_stream_indexes; j++)
                    {
                        if (st->index == s->programs[i]->stream_index[j])
                        {
                            found = 1;
                            if (p)
                                *p = s->programs[i];
                            i = s->nb_programs;
                            break;
                        }
                    }
                }
            }
            if (!found)
                match = 0;
        }
        else if (*spec == '#' ||
                 (*spec == 'i' && *(spec + 1) == ':'))
        {
            int stream_id;
            char *endptr;
            spec += 1 + (*spec == 'i');
            stream_id = strtol(spec, &endptr, 0);
            if (spec == endptr || *endptr) 
                return AVERROR(EINVAL);
            return match && (stream_id == st->id);
        }
        else if (*spec == 'm' && *(spec + 1) == ':')
        {
            AVDictionaryEntry *tag;
            char *key, *val;
            int ret;

            if (match)
            {
                spec += 2;
                val = strchr(spec, ':');

                key = val ? av_strndup(spec, val - spec) : av_strdup(spec);
                if (!key)
                    return AVERROR(ENOMEM);

                tag = av_dict_get(st->metadata, key, NULL, 0);
                if (tag)
                {
                    if (!val || !strcmp(tag->value, val + 1))
                        ret = 1;
                    else
                        ret = 0;
                }
                else
                    ret = 0;

                av_freep(&key);
            }
            return match && ret;
        }
        else if (*spec == 'u' && *(spec + 1) == '\0')
        {
            AVCodecParameters *par = st->codecpar;
#if FF_API_LAVF_AVCTX
            
            AVCodecContext *codec = st->codec;
            
#endif
            int val;
            switch (par->codec_type)
            {
            case AVMEDIA_TYPE_AUDIO:
                val = par->sample_rate && par->channels;
#if FF_API_LAVF_AVCTX
                val = val || (codec->sample_rate && codec->channels);
#endif
                if (par->format == AV_SAMPLE_FMT_NONE
#if FF_API_LAVF_AVCTX
                    && codec->sample_fmt == AV_SAMPLE_FMT_NONE
#endif
                )
                    return 0;
                break;
            case AVMEDIA_TYPE_VIDEO:
                val = par->width && par->height;
#if FF_API_LAVF_AVCTX
                val = val || (codec->width && codec->height);
#endif
                if (par->format == AV_PIX_FMT_NONE
#if FF_API_LAVF_AVCTX
                    && codec->pix_fmt == AV_PIX_FMT_NONE
#endif
                )
                    return 0;
                break;
            case AVMEDIA_TYPE_UNKNOWN:
                val = 0;
                break;
            default:
                val = 1;
                break;
            }
#if FF_API_LAVF_AVCTX
            return match && ((par->codec_id != AV_CODEC_ID_NONE || codec->codec_id != AV_CODEC_ID_NONE) && val != 0);
#else
            return match && (par->codec_id != AV_CODEC_ID_NONE && val != 0);
#endif
        }
        else
        {
            return AVERROR(EINVAL);
        }
    }

    return match;
}
int avformat_match_stream_specifier(AVFormatContext *s, AVStream *st,
                                    const char *spec)
{
    int ret, index;
    char *endptr;
    const char *indexptr = NULL;
    AVProgram *p = NULL;
    int nb_streams;

    ret = match_stream_specifier(s, st, spec, &indexptr, &p);
    if (ret < 0)
        goto error;

    if (!indexptr)
        return ret;

    index = strtol(indexptr, &endptr, 0);
    if (*endptr)
    { 
        ret = AVERROR(EINVAL);
        goto error;
    }

    
    if (spec == indexptr)
        return (index == st->index);

    
    nb_streams = p ? p->nb_stream_indexes : s->nb_streams;
    for (int i = 0; i < nb_streams && index >= 0; i++)
    {
        AVStream *candidate = p ? s->streams[p->stream_index[i]] : s->streams[i];
        ret = match_stream_specifier(s, candidate, spec, NULL, NULL);
        if (ret < 0)
            goto error;
        if (ret > 0 && index-- == 0 && st == candidate)
            return 1;
    }
    return 0;

error:
    if (ret == AVERROR(EINVAL))
        av_log(s, AV_LOG_ERROR, "Invalid stream specifier: %s.\n", spec);
    return ret;
}

int check_stream_specifier(AVFormatContext *s, AVStream *st, const char *spec)
{
    int ret = avformat_match_stream_specifier(s, st, spec);
    if (ret < 0)
        av_log(s, AV_LOG_ERROR, "Invalid stream specifier: %s.\n", spec);
    return ret;
}
AVDictionary *filter_codec_opts(AVDictionary *opts, enum AVCodecID codec_id,
                                AVFormatContext *s, AVStream *st, AVCodec *codec)
{
    AVDictionary *ret = NULL;
    AVDictionaryEntry *t = NULL;
    int flags = s->oformat ? AV_OPT_FLAG_ENCODING_PARAM
                           : AV_OPT_FLAG_DECODING_PARAM;
    char prefix = 0;
    const AVClass *cc = avcodec_get_class();

    if (!codec)
        codec = s->oformat ? avcodec_find_encoder(codec_id)
                           : avcodec_find_decoder(codec_id);

    switch (st->codecpar->codec_type)
    {
    case AVMEDIA_TYPE_VIDEO:
        prefix = 'v';
        flags |= AV_OPT_FLAG_VIDEO_PARAM;
        break;
    case AVMEDIA_TYPE_AUDIO:
        prefix = 'a';
        flags |= AV_OPT_FLAG_AUDIO_PARAM;
        break;
    case AVMEDIA_TYPE_SUBTITLE:
        prefix = 's';
        flags |= AV_OPT_FLAG_SUBTITLE_PARAM;
        break;
    }

    while (t = av_dict_get(opts, "", t, AV_DICT_IGNORE_SUFFIX))
    {
        char *p = strchr(t->key, ':');

        
        if (p)
            switch (check_stream_specifier(s, st, p + 1))
            {
            case 1:
                *p = 0;
                break;
            case 0:
                continue;
            // default:
                exit_program(1);
            }

        if (av_opt_find(&cc, t->key, NULL, flags, AV_OPT_SEARCH_FAKE_OBJ) ||
            !codec ||
            (codec->priv_class &&
             av_opt_find(&codec->priv_class, t->key, NULL, flags,
                         AV_OPT_SEARCH_FAKE_OBJ)))
            av_dict_set(&ret, t->key, t->value, 0);
        else if (t->key[0] == prefix &&
                 av_opt_find(&cc, t->key + 1, NULL, flags,
                             AV_OPT_SEARCH_FAKE_OBJ))
            av_dict_set(&ret, t->key + 1, t->value, 0);

        if (p)
            *p = ':';
    }
    return ret;
}


AVDictionary **setup_find_stream_info_opts(AVFormatContext *s,
                                           AVDictionary *codec_opts)
{
    int i;
    AVDictionary **opts;

    if (!s->nb_streams)
        return NULL;
    opts = av_mallocz_array(s->nb_streams, sizeof(*opts));
    if (!opts)
    {
        av_log(NULL, AV_LOG_ERROR,
               "Could not alloc memory for stream options.\n");
        return NULL;
    }
    for (i = 0; i < s->nb_streams; i++)
        opts[i] = filter_codec_opts(codec_opts, s->streams[i]->codecpar->codec_id,
                                    s, s->streams[i], NULL);
    return opts;
}

static const AVOption *opt_find(void *obj, const char *name, const char *unit,
                                int opt_flags, int search_flags)
{
    const AVOption *o = av_opt_find(obj, name, unit, opt_flags, search_flags);
    if (o && !o->flags)
        return NULL;
    return o;
}

#define FLAGS (o->type == AV_OPT_TYPE_FLAGS && (arg[0]=='-' || arg[0]=='+')) ? AV_DICT_APPEND : 0
int opt_default(void *optctx, const char *opt, const char *arg)
{
    const AVOption *o;
    int consumed = 0;
    char opt_stripped[128];
    const char *p;
    const AVClass *cc = avcodec_get_class(), *fc = avformat_get_class();
#if CONFIG_AVRESAMPLE
    const AVClass *rc = avresample_get_class();
#endif
#if CONFIG_SWSCALE
    const AVClass *sc = sws_get_class();
#endif
#if CONFIG_SWRESAMPLE
    const AVClass *swr_class = swr_get_class();
#endif

    if (!strcmp(opt, "debug") || !strcmp(opt, "fdebug"))
        av_log_set_level(AV_LOG_DEBUG);

    if (!(p = strchr(opt, ':')))
        p = opt + strlen(opt);
    av_strlcpy(opt_stripped, opt, FFMIN(sizeof(opt_stripped), p - opt + 1));

    if ((o = opt_find(&cc, opt_stripped, NULL, 0,
                      AV_OPT_SEARCH_CHILDREN | AV_OPT_SEARCH_FAKE_OBJ)) ||
        ((opt[0] == 'v' || opt[0] == 'a' || opt[0] == 's') &&
         (o = opt_find(&cc, opt + 1, NULL, 0, AV_OPT_SEARCH_FAKE_OBJ))))
    {
        av_dict_set(&codec_opts, opt, arg, FLAGS);
        consumed = 1;
    }
    if ((o = opt_find(&fc, opt, NULL, 0,
                      AV_OPT_SEARCH_CHILDREN | AV_OPT_SEARCH_FAKE_OBJ)))
    {
        av_dict_set(&format_opts, opt, arg, FLAGS);
        if (consumed)
            av_log(NULL, AV_LOG_VERBOSE, "Routing option %s to both codec and muxer layer\n", opt);
        consumed = 1;
    }
#if CONFIG_SWSCALE
    if (!consumed && (o = opt_find(&sc, opt, NULL, 0,
                                   AV_OPT_SEARCH_CHILDREN | AV_OPT_SEARCH_FAKE_OBJ)))
    {
        struct SwsContext *sws = sws_alloc_context();
        int ret = av_opt_set(sws, opt, arg, 0);
        sws_freeContext(sws);
        if (!strcmp(opt, "srcw") || !strcmp(opt, "srch") ||
            !strcmp(opt, "dstw") || !strcmp(opt, "dsth") ||
            !strcmp(opt, "src_format") || !strcmp(opt, "dst_format"))
        {
            av_log(NULL, AV_LOG_ERROR, "Directly using swscale dimensions/format options is not supported, please use the -s or -pix_fmt options\n");
            return AVERROR(EINVAL);
        }
        if (ret < 0)
        {
            av_log(NULL, AV_LOG_ERROR, "Error setting option %s.\n", opt);
            return ret;
        }

        av_dict_set(&sws_dict, opt, arg, FLAGS);

        consumed = 1;
    }
#else
    if (!consumed && !strcmp(opt, "sws_flags"))
    {
        av_log(NULL, AV_LOG_WARNING, "Ignoring %s %s, due to disabled swscale\n", opt, arg);
        consumed = 1;
    }
#endif
#if CONFIG_SWRESAMPLE
    if (!consumed && (o = opt_find(&swr_class, opt, NULL, 0,
                                   AV_OPT_SEARCH_CHILDREN | AV_OPT_SEARCH_FAKE_OBJ)))
    {
        struct SwrContext *swr = swr_alloc();
        int ret = av_opt_set(swr, opt, arg, 0);
        swr_free(&swr);
        if (ret < 0)
        {
            av_log(NULL, AV_LOG_ERROR, "Error setting option %s.\n", opt);
            return ret;
        }
        av_dict_set(&swr_opts, opt, arg, FLAGS);
        consumed = 1;
    }
#endif
#if CONFIG_AVRESAMPLE
    if ((o = opt_find(&rc, opt, NULL, 0,
                      AV_OPT_SEARCH_CHILDREN | AV_OPT_SEARCH_FAKE_OBJ)))
    {
        av_dict_set(&resample_opts, opt, arg, FLAGS);
        consumed = 1;
    }
#endif

    if (consumed)
        return 0;
    return AVERROR_OPTION_NOT_FOUND;
}

double parse_number_or_die(const char *context, const char *numstr, int type,
                           double min, double max)
{
    char *tail;
    const char *error;
    double d = av_strtod(numstr, &tail);
    if (*tail)
        error = "Expected number for %s but found: %s\n";
    else if (d < min || d > max)
        error = "The value for %s was %s which is not within %f - %f\n";
    else if (type == OPT_INT64 && (int64_t)d != d)
        error = "Expected int64 for %s but found %s\n";
    else if (type == OPT_INT && (int)d != d)
        error = "Expected int for %s but found %s\n";
    else
        return d;
    av_log(NULL, AV_LOG_FATAL, error, context, numstr, min, max);
    exit_program(1);
    return 0;
}



void init_dynload(void)
{
#if HAVE_SETDLLDIRECTORY && defined(_WIN32)
    SetDllDirectory("");
#endif
}
void init_opts(void)
{
    av_dict_set(&sws_dict, "flags", "bicubic", 0);
}

static void show_usage(void)
{
    av_log(NULL, 32, "Simple media player\n");
    av_log(NULL, 32, "usage: %s [options] input_file\n", program_name);
    av_log(NULL, 32, "\n");
}

static int write_option(void *optctx, const OptionDef *po, const char *opt,
                        const char *arg)
{
    void *dst = po->flags & (OPT_OFFSET | OPT_SPEC) ? (uint8_t *)optctx + po->u.off : po->u.dst_ptr;
    int *dstcount;

    if (po->flags & OPT_SPEC)
    {
        SpecifierOpt **so = dst;
        char *p = strchr(opt, ':');
        char *str;

        dstcount = (int *)(so + 1);
        *so = grow_array(*so, sizeof(**so), dstcount, *dstcount + 1);
        str = av_strdup(p ? p + 1 : "");
        if (!str)
            return AVERROR(ENOMEM);
        (*so)[*dstcount - 1].specifier = str;
        dst = &(*so)[*dstcount - 1].u;
    }

    if (po->flags & OPT_STRING)
    {
        char *str;
        str = av_strdup(arg);
        av_freep(dst);
        if (!str)
            return AVERROR(ENOMEM);
        *(char **)dst = str;
    }
    else if (po->flags & OPT_BOOL || po->flags & OPT_INT)
    {
        *(int *)dst = parse_number_or_die(opt, arg, OPT_INT64, INT_MIN, INT_MAX);
    }
    else if (po->flags & OPT_INT64)
    {
        *(int64_t *)dst = parse_number_or_die(opt, arg, OPT_INT64, INT64_MIN, INT64_MAX);
    }
    else if (po->flags & OPT_TIME)
    {
        *(int64_t *)dst = parse_time_or_die(opt, arg, 1);
    }
    else if (po->flags & OPT_FLOAT)
    {
        *(float *)dst = parse_number_or_die(opt, arg, OPT_FLOAT, -INFINITY, INFINITY);
    }
    else if (po->flags & OPT_DOUBLE)
    {
        *(double *)dst = parse_number_or_die(opt, arg, OPT_DOUBLE, -INFINITY, INFINITY);
    }
    else if (po->u.func_arg)
    {
        int ret = po->u.func_arg(optctx, opt, arg);
        if (ret < 0)
        {
            av_log(NULL, AV_LOG_ERROR,
                   "Failed to set value '%s' for option '%s': %s\n",
                   arg, opt, av_err2str(ret));
            return ret;
        }
    }
    if (po->flags & OPT_EXIT)
        exit_program(0);

    return 0;
}
static const OptionDef *find_option(const OptionDef *po, const char *name)
{
    const char *p = strchr(name, ':');
    int len = p ? p - name : strlen(name);

    while (po->name) {
        if (!strncmp(name, po->name, len) && strlen(po->name) == len)
            break;
        po++;
    }
    return po;
}
int parse_option(void *optctx, const char *opt, const char *arg,
                 const OptionDef *options)
{
    const OptionDef *po;
    int ret;

    po = find_option(options, opt);
    if (!po->name && opt[0] == 'n' && opt[1] == 'o')
    {
        
        po = find_option(options, opt + 2);
        if ((po->name && (po->flags & OPT_BOOL)))
            arg = "0";
    }
    else if (po->flags & OPT_BOOL)
        arg = "1";

    if (!po->name)
        po = find_option(options, "default");
    if (!po->name)
    {
        av_log(NULL, AV_LOG_ERROR, "Unrecognized option '%s'\n", opt);
        return AVERROR(EINVAL);
    }
    if (po->flags & HAS_ARG && !arg)
    {
        av_log(NULL, AV_LOG_ERROR, "Missing argument for option '%s'\n", opt);
        return AVERROR(EINVAL);
    }

    ret = write_option(optctx, po, opt, arg);
    if (ret < 0)
        return ret;

    return !!(po->flags & HAS_ARG);
}
#if HAVE_COMMANDLINETOARGVW && defined(_WIN32)
#include <shellapi.h>
static char **win32_argv_utf8 = NULL;
static int win32_argc = 0;

static void prepare_app_arguments(int *argc_ptr, char ***argv_ptr)
{
    char *argstr_flat;
    wchar_t **argv_w;
    int i, buffsize = 0, offset = 0;

    if (win32_argv_utf8)
    {
        *argc_ptr = win32_argc;
        *argv_ptr = win32_argv_utf8;
        return;
    }

    win32_argc = 0;
    argv_w = CommandLineToArgvW(GetCommandLineW(), &win32_argc);
    if (win32_argc <= 0 || !argv_w)
        return;

    
    for (i = 0; i < win32_argc; i++)
        buffsize += WideCharToMultiByte(CP_UTF8, 0, argv_w[i], -1,
                                        NULL, 0, NULL, NULL);

    win32_argv_utf8 = av_mallocz(sizeof(char *) * (win32_argc + 1) + buffsize);
    argstr_flat = (char *)win32_argv_utf8 + sizeof(char *) * (win32_argc + 1);
    if (!win32_argv_utf8)
    {
        LocalFree(argv_w);
        return;
    }

    for (i = 0; i < win32_argc; i++)
    {
        win32_argv_utf8[i] = &argstr_flat[offset];
        offset += WideCharToMultiByte(CP_UTF8, 0, argv_w[i], -1,
                                      &argstr_flat[offset],
                                      buffsize - offset, NULL, NULL);
    }
    win32_argv_utf8[i] = NULL;
    LocalFree(argv_w);

    *argc_ptr = win32_argc;
    *argv_ptr = win32_argv_utf8;
}
#else
static inline void prepare_app_arguments(int *argc_ptr, char ***argv_ptr)
{
    
}
#endif 
void parse_options(void *optctx, int argc, char **argv, const OptionDef *options,void (*parse_arg_function)(void *, const char *))
{
    const char *opt;
    int optindex, handleoptions = 1, ret;
    prepare_app_arguments(&argc, &argv);
    optindex = 1;
    while (optindex < argc)
    {
        opt = argv[optindex++];

        if (handleoptions && opt[0] == '-' && opt[1] != '\0')
        {
            if (opt[1] == '-' && opt[2] == '\0')
            {
                handleoptions = 0;
                continue;
            }
            opt++;

            if ((ret = parse_option(optctx, opt, argv[optindex], options)) < 0)
                exit_program(1);
            optindex += ret;
        }
        else
        {
            if (parse_arg_function)
                parse_arg_function(optctx, opt);
        }
    }
}
void av_log_format_line(void *ptr, int level, const char *fmt, va_list vl,
                        char *line, int line_size, int *print_prefix)
{
    av_log_format_line2(ptr, level, fmt, vl, line, line_size, print_prefix);
}
static void log_callback_report(void *ptr, int level, const char *fmt, va_list vl)
{
    va_list vl2;
    char line[1024];
    static int print_prefix = 1;

    va_copy(vl2, vl);
    av_log_default_callback(ptr, level, fmt, vl);
    av_log_format_line(ptr, level, fmt, vl2, line, sizeof(line), &print_prefix);
    va_end(vl2);
    if (report_file_level >= level)
    {
        fputs(line, report_file);
        fflush(report_file);
    }
}
static void expand_filename_template(AVBPrint *bp, const char *template,
                                     struct tm *tm)
{
    int c;

    while ((c = *(template ++)))
    {
        if (c == '%')
        {
            if (!(c = *(template ++)))
                break;
            switch (c)
            {
            case 'p':
                av_bprintf(bp, "%s", program_name);
                break;
            case 't':
                av_bprintf(bp, "%04d%02d%02d-%02d%02d%02d",
                           tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
                           tm->tm_hour, tm->tm_min, tm->tm_sec);
                break;
            case '%':
                av_bprint_chars(bp, c, 1);
                break;
            }
        }
        else
        {
            av_bprint_chars(bp, c, 1);
        }
    }
}
static int init_report(const char *env)
{
    char *filename_template = NULL;
    char *key, *val;
    int ret, count = 0;
    int prog_loglevel, envlevel = 0;
    time_t now;
    struct tm *tm;
    AVBPrint filename;

    if (report_file) 
        return 0;
    time(&now);
    tm = localtime(&now);

    while (env && *env)
    {
        if ((ret = av_opt_get_key_value(&env, "=", ":", 0, &key, &val)) < 0)
        {
            if (count)
                av_log(NULL, AV_LOG_ERROR,
                       "Failed to parse FFREPORT environment variable: %s\n",
                       av_err2str(ret));
            break;
        }
        if (*env)
            env++;
        count++;
        if (!strcmp(key, "file"))
        {
            av_free(filename_template);
            filename_template = val;
            val = NULL;
        }
        else if (!strcmp(key, "level"))
        {
            char *tail;
            report_file_level = strtol(val, &tail, 10);
            if (*tail)
            {
                av_log(NULL, AV_LOG_FATAL, "Invalid report file level\n");
                exit_program(1);
            }
            envlevel = 1;
        }
        else
        {
            av_log(NULL, AV_LOG_ERROR, "Unknown key '%s' in FFREPORT\n", key);
        }
        av_free(val);
        av_free(key);
    }

    av_bprint_init(&filename, 0, AV_BPRINT_SIZE_AUTOMATIC);
    expand_filename_template(&filename,
                             av_x_if_null(filename_template, "%p-%t.log"), tm);
    av_free(filename_template);
    if (!av_bprint_is_complete(&filename))
    {
        av_log(NULL, AV_LOG_ERROR, "Out of memory building report file name\n");
        return AVERROR(ENOMEM);
    }

    prog_loglevel = av_log_get_level();
    if (!envlevel)
        report_file_level = FFMAX(report_file_level, prog_loglevel);

    report_file = fopen(filename.str, "w");
    if (!report_file)
    {
        int ret = AVERROR(errno);
        av_log(NULL, AV_LOG_ERROR, "Failed to open report \"%s\": %s\n",
               filename.str, strerror(errno));
        return ret;
    }
    av_log_set_callback(log_callback_report);
    av_log(NULL, AV_LOG_INFO,
           "%s started on %04d-%02d-%02d at %02d:%02d:%02d\n"
           "Report written to \"%s\"\n"
           "Log level: %d\n",
           program_name,
           tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
           tm->tm_hour, tm->tm_min, tm->tm_sec,
           filename.str, report_file_level);
    av_bprint_finalize(&filename, NULL);
    return 0;
}
int opt_report(void *optctx, const char *opt, const char *arg)
{
    return init_report(NULL);
}
static const OptionDef helpoptions[] = {
    { "x", HAS_ARG, { .func_arg = opt_width }, "force displayed width", "width" },
    { "y", HAS_ARG, { .func_arg = opt_height }, "force displayed height", "height" },
    { "s", HAS_ARG | OPT_VIDEO, { .func_arg = opt_frame_size }, "set frame size (WxH or abbreviation)", "size" },
    { "fs", OPT_BOOL, { &is_full_screen }, "force full screen" },
    { "an", OPT_BOOL, { &audio_disable }, "disable audio" },
    { "vn", OPT_BOOL, { &video_disable }, "disable video" },
    { "sn", OPT_BOOL, { &subtitle_disable }, "disable subtitling" },
    { "ast", OPT_STRING | HAS_ARG | OPT_EXPERT, { &wanted_stream_spec[AVMEDIA_TYPE_AUDIO] }, "select desired audio stream", "stream_specifier" },
    { "vst", OPT_STRING | HAS_ARG | OPT_EXPERT, { &wanted_stream_spec[AVMEDIA_TYPE_VIDEO] }, "select desired video stream", "stream_specifier" },
    { "sst", OPT_STRING | HAS_ARG | OPT_EXPERT, { &wanted_stream_spec[AVMEDIA_TYPE_SUBTITLE] }, "select desired subtitle stream", "stream_specifier" },
    { "ss", HAS_ARG, { .func_arg = opt_seek }, "seek to a given position in seconds", "pos" },
    { "t", HAS_ARG, { .func_arg = opt_duration }, "play  \"duration\" seconds of audio/video", "duration" },
    { "bytes", OPT_INT | HAS_ARG, { &seek_by_bytes }, "seek by bytes 0=off 1=on -1=auto", "val" },
    { "seek_interval", OPT_FLOAT | HAS_ARG, { &seek_interval }, "set seek interval for left/right keys, in seconds", "seconds" },
    { "nodisp", OPT_BOOL, { &display_disable }, "disable graphical display" },
    { "noborder", OPT_BOOL, { &borderless }, "borderless window" },
    { "alwaysontop", OPT_BOOL, { &alwaysontop }, "window always on top" },
    { "volume", OPT_INT | HAS_ARG, { &startup_volume}, "set startup volume 0=min 100=max", "volume" },
    { "f", HAS_ARG, { .func_arg = opt_format }, "force format", "fmt" },
    { "pix_fmt", HAS_ARG | OPT_EXPERT | OPT_VIDEO, { .func_arg = opt_frame_pix_fmt }, "set pixel format", "format" },
    { "stats", OPT_BOOL | OPT_EXPERT, { &show_status }, "show status", "" },
    { "fast", OPT_BOOL | OPT_EXPERT, { &fast }, "non spec compliant optimizations", "" },
    { "genpts", OPT_BOOL | OPT_EXPERT, { &genpts }, "generate pts", "" },
    { "drp", OPT_INT | HAS_ARG | OPT_EXPERT, { &decoder_reorder_pts }, "let decoder reorder pts 0=off 1=on -1=auto", ""},
    { "lowres", OPT_INT | HAS_ARG | OPT_EXPERT, { &lowres }, "", "" },
    { "sync", HAS_ARG | OPT_EXPERT, { .func_arg = opt_sync }, "set audio-video sync. type (type=audio/video/ext)", "type" },
    { "autoexit", OPT_BOOL | OPT_EXPERT, { &autoexit }, "exit at the end", "" },
    { "exitonkeydown", OPT_BOOL | OPT_EXPERT, { &exit_on_keydown }, "exit on key down", "" },
    { "exitonmousedown", OPT_BOOL | OPT_EXPERT, { &exit_on_mousedown }, "exit on mouse down", "" },
    { "loop", OPT_INT | HAS_ARG | OPT_EXPERT, { &loop }, "set number of times the playback shall be looped", "loop count" },
    { "framedrop", OPT_BOOL | OPT_EXPERT, { &framedrop }, "drop frames when cpu is too slow", "" },
    { "infbuf", OPT_BOOL | OPT_EXPERT, { &infinite_buffer }, "don't limit the input buffer size (useful with realtime streams)", "" },
    { "window_title", OPT_STRING | HAS_ARG, { &window_title }, "set window title", "window title" },
    { "left", OPT_INT | HAS_ARG | OPT_EXPERT, { &screen_left }, "set the x position for the left of the window", "x pos" },
    { "top", OPT_INT | HAS_ARG | OPT_EXPERT, { &screen_top }, "set the y position for the top of the window", "y pos" },
    { "default", HAS_ARG | OPT_AUDIO | OPT_VIDEO | OPT_EXPERT, { .func_arg = opt_default }, "generic catch all option", "" },
    { "codec", HAS_ARG, { .func_arg = opt_codec}, "force decoder", "decoder_name" },
    { "acodec", HAS_ARG | OPT_STRING | OPT_EXPERT, {    &audio_codec_name }, "force audio decoder",    "decoder_name" },
    { "scodec", HAS_ARG | OPT_STRING | OPT_EXPERT, { &subtitle_codec_name }, "force subtitle decoder", "decoder_name" },
    { "vcodec", HAS_ARG | OPT_STRING | OPT_EXPERT, {    &video_codec_name }, "force video decoder",    "decoder_name" },
    { "autorotate", OPT_BOOL, { &autorotate }, "automatically rotate video", "" },
    { "find_stream_info", OPT_BOOL | OPT_INPUT | OPT_EXPERT, { &find_stream_info },
        "read and decode the streams to fill missing information with heuristics" },
    { "filter_threads", HAS_ARG | OPT_INT | OPT_EXPERT, { &filter_nbthreads }, "number of filter threads per graph" },
    { NULL, },
};

// #include "common.cpp"

int main(int argc, char **argv)
{
    int flags;
    VideoState *is;
    init_dynload();
    av_log_set_flags(1);
    // parse_loglevel(argc, argv, help_options);
    avdevice_register_all();
    avformat_network_init();
    init_opts();
    signal(2, sigterm_handler);
    signal(15, sigterm_handler);
    // input_filename = argv[1];
    // show_banner(argc, argv, help_options);
    parse_options(NULL, argc, argv, helpoptions, opt_input_file);
    if (!input_filename)
    {
        show_usage();
        av_log(NULL, 8, "An input file must be specified\n");
        av_log(NULL, 8,"Use -h to get full help or, even better, run 'man %s'\n", program_name);
        exit(1);
    }
    if (display_disable)
    {
        video_disable = 1;
    }
    flags = 0x00000020u | 0x00000010u | 0x00000001u;
    if (audio_disable)
        flags &= ~0x00000010u;
    else
    {
        if (!SDL_getenv("SDL_AUDIO_ALSA_SET_BUFFER_SIZE"))
            SDL_setenv("SDL_AUDIO_ALSA_SET_BUFFER_SIZE", "1", 1);
    }
    if (display_disable)
        flags &= ~0x00000020u;
    if (SDL_Init(flags))
    {
        av_log(NULL, 8, "Could not initialize SDL - %s\n", SDL_GetError());
        av_log(NULL, 8, "(Did you set the DISPLAY variable?)\n");
        exit(1);
    }
    SDL_EventState(SDL_SYSWMEVENT, 0);
    SDL_EventState(SDL_USEREVENT, 0);
    av_init_packet(&flush_pkt);
    flush_pkt.data = (uint8_t *)&flush_pkt;
    if (!display_disable)
    {
        int flags = SDL_WINDOW_HIDDEN;
        if (alwaysontop)
            flags |= SDL_WINDOW_ALWAYS_ON_TOP;
        if (borderless)
            flags |= SDL_WINDOW_BORDERLESS;
        else
            flags |= SDL_WINDOW_RESIZABLE;
        window = SDL_CreateWindow(program_name, (0x1FFF0000u | (0)), (0x1FFF0000u | (0)), default_width, default_height, flags);
        SDL_SetHint("SDL_RENDER_SCALE_QUALITY", "linear");
        if (window)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (!renderer)
            {
                av_log(NULL, 24, "Failed to initialize a hardware accelerated renderer: %s\n", SDL_GetError());
                renderer = SDL_CreateRenderer(window, -1, 0);
            }
            if (renderer)
            {
                if (!SDL_GetRendererInfo(renderer, &renderer_info))
                    av_log(
                        NULL, 40, "Initialized %s renderer.\n", renderer_info.name);
            }
        }
        if (!window || !renderer || !renderer_info.num_texture_formats)
        {
            av_log(NULL, 8, "Failed to create window or renderer: %s", SDL_GetError());
            do_exit(NULL);
        }
    }
    is = stream_open(input_filename, file_iformat);
    if (!is)
    {
        av_log(NULL, 8, "Failed to initialize VideoState!\n");
        do_exit(NULL);
    }
    event_loop(is);
    return 0;
}
