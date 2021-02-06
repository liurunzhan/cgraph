#ifndef _CGRAPH_PLATFORM_H_
#define _CGRAPH_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_LIBM
#define __USE_XOPEN
#endif

typedef enum {
    CGRAPH_PLAT_CYGWIN = 0,   /**< TYPE 0 : CGRAPH_PLAT_CYGWIN   */
    CGRAPH_PLAT_MSYS = 0,     /**< TYPE 0 : CGRAPH_PLAT_MSYS   */
    CGRAPH_PLAT_MSYS2 = 0,    /**< TYPE 0 : CGRAPH_PLAT_MSYS2   */
    CGRAPH_PLAT_WINDOWS = 1,  /**< TYPE 1 : CGRAPH_PLAT_WINDOWS   */
    CGRAPH_PLAT_MACOS = 2,    /**< TYPE 2 : CGRAPH_PLAT_MACOS   */
    CGRAPH_PLAT_LINUX = 3,    /**< TYPE 3 : CGRAPH_PLAT_LINUX   */
    CGRAPH_PLAT_UNIX = 4,     /**< TYPE 4 : CGRAPH_PLAT_UNIX */
    CGRAPH_PLAT_UNDEFINED = 5 /**< TYPE 5 : CGRAPH_PLAT_UNDEFINED */
} cgraph_plat_t;

/**Self-defined features in different platforms */
#if defined(__CYGWIN__)
#define CGRAPH_PLAT_NAME   "cygwin"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_CYGWIN
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\n"
#define CGRAPH_PLAT_WINDOWS
#elif (defined(_WIN32) || defined(_WIN64))
#define CGRAPH_PLAT_NAME   "windows"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_WINDOWS
#define CGRAPH_PLAT_PSPLIT "\\"
#define CGRAPH_PLAT_FEND   "\r\n"
#define CGRAPH_PLAT_WINDOWS
#elif defined(__APPLE__)
#define CGRAPH_PLAT_NAME   "macos"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_MACOS
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\r"
#define CGRAPH_PLAT_UNIX
#elif defined(__linux__)
#define CGRAPH_PLAT_NAME   "linux"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_LINUX
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\n"
#define CGRAPH_PLAT_UNIX
#elif defined(__unix__)
#define CGRAPH_PLAT_NAME   "unix"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_UNIX
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\n"
#define CGRAPH_PLAT_UNIX
#else
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_UNDEFINED
#error unsupported platforms!!
#endif

/**Self-defined features in different structures */
#if defined(__LITTLE_ENDIAN__)
#define CGRAPH_PLAT_ENDIAN 0
#elif defined(__BIG_ENDIAN__)
#define CGRAPH_PLAT_ENDIAN 1
#else
#define CGRAPH_PLAT_ENDIAN 2
#endif

#if (__WORDSIZE == 64) || defined(_WIN64) || defined(_M_X64) ||                \
    defined(__x86_64__) || defined(__x86_64)
#define CGRAPH_WORDSIZE 64
#elif (__WORDSIZE == 32) || defined(_WIN32) || defined(_M_IX86) ||             \
    defined(__i386__) || defined(__i486__)
#define CGRAPH_WORDSIZE 32
#else
#error only 32-bit and 64-bit system are supported!!
#endif

/**C standard */
#if defined(__STDC__)
#if defined(__STDC_VERSION__)
#define CGRAPH_STDC_VERSION __STDC_VERSION__
#else
#define CGRAPH_STDC_VERSION 198901L
#endif
#else
#error only standard c is suppoted!!
#endif

/**Self-defined features in different compilers */
#if CGRAPH_STDC_VERSION >= 199901L

#define CGRAPH_INLINE inline
#define __cgraph_vsnprintf(buffer, size, format, args)                         \
    vsnprintf(buffer, size, format, args)

#include <inttypes.h>
#include <stdint.h>
/**< 8-bit integer number */
#define __CGRAPH_INT8_MAX        INT8_MAX
#define __CGRAPH_INT8_MIN        INT8_MIN
#define __CGRAPH_INT8_EPS        (0xFF)
#define __CGRAPH_INT8_BIT        (8)
#define __CGRAPH_INT8_IN_FORMAT  SCNd8
#define __CGRAPH_INT8_OUT_FORMAT PRId8
typedef int8_t __cgraph_int8;
/**< 8-bit unsigned integer number */
#define __CGRAPH_UINT8_MAX        UINT8_MAX
#define __CGRAPH_UINT8_MIN        UINT8_MIN
#define __CGRAPH_UINT8_EPS        (0xFF)
#define __CGRAPH_UINT8_BIT        (8)
#define __CGRAPH_UINT8_IN_FORMAT  SCNu8
#define __CGRAPH_UINT8_OUT_FORMAT PRIu8
typedef uint8_t __cgraph_uint8;
/**< 16-bit integer number */
#define __CGRAPH_INT16_MAX        INT16_MAX
#define __CGRAPH_INT16_MIN        INT16_MIN
#define __CGRAPH_INT16_EPS        (0xFFFF)
#define __CGRAPH_INT16_BIT        (16)
#define __CGRAPH_INT16_IN_FORMAT  SCNd16
#define __CGRAPH_INT16_OUT_FORMAT PRId16
typedef int16_t __cgraph_int16;
/**< 16-bit unsigned integer number */
#define __CGRAPH_UINT16_MAX        UINT16_MAX
#define __CGRAPH_UINT16_MIN        UINT16_MIN
#define __CGRAPH_UINT16_EPS        (0xFFFF)
#define __CGRAPH_UINT16_BIT        (16)
#define __CGRAPH_UINT16_IN_FORMAT  SCNu16
#define __CGRAPH_UINT16_OUT_FORMAT PRIu16
typedef uint16_t __cgraph_uint16;
/**< 32-bit integer number */
#define __CGRAPH_INT32_MAX        INT32_MAX
#define __CGRAPH_INT32_MIN        INT32_MIN
#define __CGRAPH_INT32_EPS        (0xFFFFFFFF)
#define __CGRAPH_INT32_BIT        (32)
#define __CGRAPH_INT32_IN_FORMAT  SCNd32
#define __CGRAPH_INT32_OUT_FORMAT PRId32
typedef int32_t __cgraph_int32;
/**< 32-bit unsigned integer number */
#define __CGRAPH_UINT32_MAX        UINT32_MAX
#define __CGRAPH_UINT32_MIN        UINT32_MIN
#define __CGRAPH_UINT32_EPS        (0xFFFFFFFF)
#define __CGRAPH_UINT32_BIT        (32)
#define __CGRAPH_UINT32_IN_FORMAT  SCNu32
#define __CGRAPH_UINT32_OUT_FORMAT PRIu32
typedef uint32_t __cgraph_uint32;
/**< 64-bit integer number */
#define __CGRAPH_INT64_MAX        INT64_MAX
#define __CGRAPH_INT64_MIN        INT64_MIN
#define __CGRAPH_INT64_EPS        (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_INT64_BIT        (64)
#define __CGRAPH_INT64_IN_FORMAT  SCNd64
#define __CGRAPH_INT64_OUT_FORMAT PRId64
typedef int64_t __cgraph_int64;
/**< 64-bit unsigned integer number */
#define __CGRAPH_UINT64_MAX        UINT64_MAX
#define __CGRAPH_UINT64_MIN        UINT64_MIN
#define __CGRAPH_UINT64_EPS        (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_UINT64_BIT        (64)
#define __CGRAPH_UINT64_IN_FORMAT  SCNu64
#define __CGRAPH_UINT64_OUT_FORMAT PRIu64
typedef uint64_t __cgraph_uint64;
/**< 128-bit float number */
#define CGRAPH_WITH_FLOAT128
#define __CGRAPH_FLOAT128     signed long double
#define __CGRAPH_FLOAT128_MIN LDBL_MIN
#define __CGRAPH_FLOAT128_MAX LDBL_MAX
#define __CGRAPH_FLOAT128_EPS LDBL_EPSILON
#define __CGRAPH_FLOAT128_BIT LDBL_DIG

#else

/**< 8-bit integer number */
#define __CGRAPH_INT8_MAX          (127)
#define __CGRAPH_INT8_MIN          (-128)
#define __CGRAPH_INT8_EPS          (0xFF)
#define __CGRAPH_INT8_BIT          (8)
#define __CGRAPH_INT8_IN_FORMAT    "%d"
#define __CGRAPH_INT8_OUT_FORMAT   "%d"
typedef signed char __cgraph_int8;
/**< 8-bit unsigned integer number */
#define __CGRAPH_UINT8_MAX         (255)
#define __CGRAPH_UINT8_MIN         (0)
#define __CGRAPH_UINT8_EPS         (0xFF)
#define __CGRAPH_UINT8_BIT         (8)
#define __CGRAPH_UINT8_IN_FORMAT   "%u"
#define __CGRAPH_UINT8_OUT_FORMAT  "%u"
typedef unsigned char __cgraph_uint8;
/**< 16-bit integer number */
#define __CGRAPH_INT16_MAX         (32767)
#define __CGRAPH_INT16_MIN         (-32768)
#define __CGRAPH_INT16_EPS         (0xFFFF)
#define __CGRAPH_INT16_BIT         (16)
#define __CGRAPH_INT16_IN_FORMAT   "%d"
#define __CGRAPH_INT16_OUT_FORMAT  "%d"
typedef signed short __cgraph_int16;
/**< 16-bit unsigned integer number */
#define __CGRAPH_UINT16_MAX        (65535)
#define __CGRAPH_UINT16_MIN        (0)
#define __CGRAPH_UINT16_EPS        (0xFFFF)
#define __CGRAPH_UINT16_BIT        (16)
#define __CGRAPH_UINT16_IN_FORMAT  "%u"
#define __CGRAPH_UINT16_OUT_FORMAT "%u"
typedef unsigned short __cgraph_uint16;
/**< 32-bit integer number */
#define __CGRAPH_INT32_MAX         (2147483647)
#define __CGRAPH_INT32_MIN         (-2147483648)
#define __CGRAPH_INT32_EPS         (0xFFFFFFFF)
#define __CGRAPH_INT32_BIT         (32)
#define __CGRAPH_INT32_IN_FORMAT   "%d"
#define __CGRAPH_INT32_OUT_FORMAT  "%d"
typedef signed int __cgraph_int32;
/**< 32-bit unsigned integer number */
#define __CGRAPH_UINT32_MAX        (4294967295)
#define __CGRAPH_UINT32_MIN        (0)
#define __CGRAPH_UINT32_EPS        (0xFFFFFFFF)
#define __CGRAPH_UINT32_BIT        (32)
#define __CGRAPH_UINT32_IN_FORMAT  "%u"
#define __CGRAPH_UINT32_OUT_FORMAT "%u"
typedef unsigned int __cgraph_uint32;

#if defined(__GNUC__) || defined(__clang__)

#define CGRAPH_INLINE __extension__ __inline__
#define __cgraph_vsnprintf(buffer, size, format, args)                         \
    __extension__ vsprintf(buffer, format, args)

/**< 64-bit integer number */
#define __CGRAPH_INT64_MAX  __extension__(9223372036854775807LL)
#define __CGRAPH_INT64_MIN  __extension__(-9223372036854775808LL)
#define __CGRAPH_INT64_EPS  __extension__(0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_INT64_BIT  (64)
__extension__ typedef signed long long __cgraph_int64;

/**< 64-bit unsigned integer number */
#define __CGRAPH_UINT64_MAX __extension__(1844674407370955161ULL)
#define __CGRAPH_UINT64_MIN __extension__(0LL)
#define __CGRAPH_UINT64_EPS __extension__(0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_UINT64_BIT (64)
__extension__ typedef unsigned long long __cgraph_uint64;

#ifdef CGRAPH_PLAT_WINDOWS

#define __CGRAPH_INT64_IN_FORMAT  "%I64d"
#define __CGRAPH_INT64_OUT_FORMAT "%I64d"

#define __CGRAPH_UINT64_IN_FORMAT  "%I64u"
#define __CGRAPH_UINT64_OUT_FORMAT "%I64u"

#else

#define __CGRAPH_INT64_IN_FORMAT  "%lld"
#define __CGRAPH_INT64_OUT_FORMAT "%lld"

#define __CGRAPH_UINT64_IN_FORMAT  "%llu"
#define __CGRAPH_UINT64_OUT_FORMAT "%llu"

#endif

#elif defined(_MSC_VER)

#define CGRAPH_INLINE __inline
#define __cgraph_vsnprintf(buffer, size, format, args)                         \
    vsprintf(buffer, format, args)

/**< 64-bit integer number */
#define __CGRAPH_INT64_MAX         (9223372036854775807LL)
#define __CGRAPH_INT64_MIN         (-9223372036854775808LL)
#define __CGRAPH_INT64_EPS         (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_INT64_BIT         (64)
#define __CGRAPH_INT64_IN_FORMAT   "%I64d"
#define __CGRAPH_INT64_OUT_FORMAT  "%I64d"
typedef signed __int64 __cgraph_int64;
/**< 64-bit unsigned integer number */
#define __CGRAPH_UINT64_MIN        (0LL)
#define __CGRAPH_UINT64_MAX        (1844674407370955161ULL)
#define __CGRAPH_UINT64_EPS        (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_UINT64_BIT        (64)
#define __CGRAPH_UINT64_IN_FORMAT  "%I64u"
#define __CGRAPH_UINT64_OUT_FORMAT "%I64u"
typedef unsigned __int64 __cgraph_uint64;

#else
#error unsupported C compiler in 32-bit system
#endif

#endif

#if (CGRAPH_STDC_VERSION >= 201112L)
#define __CGRAPH_TYPE_BEGIN(name)
#define __CGRAPH_TYPE_END(name)
#define __CGRAPH_TYPE_ELEMENT(type, element) ((type))
#else
#define __CGRAPH_TYPE_BEGIN(name)            name
#define __CGRAPH_TYPE_END(name)              name
#define __CGRAPH_TYPE_ELEMENT(type, element) ((type).element)
#endif

#if (CGRAPH_STDC_VERSION >= 199901L) || defined(__func__)
#define __CGRAPH_FUNCTION __func__
#elif defined(__FUNCTION__)
#define __CGRAPH_FUNCTION __FUNCTION__
#elif defined(__function__)
#define __CGRAPH_FUNCTION __function__
#else
#define __CGRAPH_FUNCTION NULL
#endif

#if CGRAPH_STDC_VERSION >= 199901L
#define __CGRAPH_TYPE_PTRSIZE (1)
#else
#define __CGRAPH_TYPE_PTRSIZE (2)
#endif

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_PLATFORM_H_ */
