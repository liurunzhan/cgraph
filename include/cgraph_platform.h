/**
 * @file cgraph_platform.h
 * @brief the configuration in different platforms
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_PLATFORM_H_
#define _CGRAPH_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "cgraph_stdchk.h"
#endif

#ifdef __CGRAPH_HAVE_LIBM
#define __USE_XOPEN
#endif

typedef enum {
  CGRAPH_PLAT_CYGWIN = 0,   /**< TYPE 0 : CGRAPH_PLAT_CYGWIN */
  CGRAPH_PLAT_MSYS = 0,     /**< TYPE 0 : CGRAPH_PLAT_MSYS */
  CGRAPH_PLAT_MSYS2 = 0,    /**< TYPE 0 : CGRAPH_PLAT_MSYS2 */
  CGRAPH_PLAT_WINDOWS = 1,  /**< TYPE 1 : CGRAPH_PLAT_WINDOWS */
  CGRAPH_PLAT_MACOS = 2,    /**< TYPE 2 : CGRAPH_PLAT_MACOS */
  CGRAPH_PLAT_LINUX = 3,    /**< TYPE 3 : CGRAPH_PLAT_LINUX */
  CGRAPH_PLAT_UNIX = 4,     /**< TYPE 4 : CGRAPH_PLAT_UNIX */
  CGRAPH_PLAT_UNDEFINED = 5 /**< TYPE 5 : CGRAPH_PLAT_UNDEFINED */
} cgraph_plat_t;

typedef enum {
  CGRAPH_PLAT_FEND_UNIX = 0,  /**< TYPE 0 : '\n' */
  CGRAPH_PLAT_FEND_MACOS = 1, /**< TYPE 1 : '\r' */
  CGRAPH_PLAT_FEND_WIN = 2    /**< TYPE 2 : '\r\n' */
} cgraph_plat_fend_t;

#define CGRAPH_PLAT_FEND_TYPE0 '\n'
#define CGRAPH_PLAT_FEND_TYPE1 '\r'

/** Self-defined features in different platforms */
#if defined(__CYGWIN__)
#define CGRAPH_PLAT_NAME "cygwin"
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_CYGWIN
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_PSPLIT_C '/'
#define CGRAPH_PLAT_NLINE "\n"
#define CGRAPH_PLAT_NLINE_C CGRAPH_PLAT_FEND_TYPE0
#define CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND_UNIX
#elif (defined(_WIN32) || defined(_WIN64))
#define CGRAPH_PLAT_NAME "windows"
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_WINDOWS
#define CGRAPH_PLAT_PSPLIT "\\"
#define CGRAPH_PLAT_PSPLIT_C '\\'
#define CGRAPH_PLAT_NLINE "\r\n"
#define CGRAPH_PLAT_NLINE_C CGRAPH_PLAT_FEND_TYPE0
#define __CGRAPH_PLAT_WINDOWS
#define CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND_WIN
#elif defined(__APPLE__)
#define CGRAPH_PLAT_NAME "macos"
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_MACOS
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_PSPLIT_C '/'
#define CGRAPH_PLAT_NLINE "\r"
#define CGRAPH_PLAT_NLINE_C CGRAPH_PLAT_FEND_TYPE1
#define CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND_MACOS
#elif defined(__linux__)
#define CGRAPH_PLAT_NAME "linux"
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_LINUX
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_PSPLIT_C '/'
#define CGRAPH_PLAT_NLINE "\n"
#define CGRAPH_PLAT_NLINE_C CGRAPH_PLAT_FEND_TYPE0
#define CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND_UNIX
#elif defined(__unix__)
#define CGRAPH_PLAT_NAME "unix"
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_UNIX
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_PSPLIT_C '/'
#define CGRAPH_PLAT_NLINE "\n"
#define CGRAPH_PLAT_NLINE_C CGRAPH_PLAT_FEND_TYPE0
#define CGRAPH_PLAT_FEND CGRAPH_PLAT_FEND_UNIX
#else
#define CGRAPH_PLAT_MODE CGRAPH_PLAT_UNDEFINED
#error unsupported platforms!!
#endif

/** Self-defined features in different structures */
#if defined(__BIG_ENDIAN__) || defined(__CGRAPH_WORDS_BIGENDIAN)
#define CGRAPH_PLAT_ENDIAN 1
#else /* defined __LITTLE_ENDIAN__ or not */
#define CGRAPH_PLAT_ENDIAN 0
#endif

#if (__WORDSIZE == 64) || defined(_WIN64) || defined(_M_X64) ||                \
    defined(__x86_64__) || defined(__x86_64) || defined(__aarch64__)
#define CGRAPH_WORDSIZE 64
#elif (__WORDSIZE == 32) || defined(_WIN32) || defined(_M_IX86) ||             \
    defined(__i386__) || defined(__i486__) || defined(__ARM_32BIT_STATE)
#define CGRAPH_WORDSIZE 32
#else
#error only 32-bit and 64-bit system are supported!!
#endif

/** C standard */
#if defined(__STDC__)
#if defined(__STDC_VERSION__)
#define CGRAPH_STDC_VERSION __STDC_VERSION__
#else
#define CGRAPH_STDC_VERSION 198901L
#endif
#else
#error only standard c is suppoted!!
#endif

/** Self-defined features in different compilers */
#if CGRAPH_STDC_VERSION >= 199901L
#define CGRAPH_INLINE inline
#elif defined(__GNUC__) || defined(__clang__)
#define CGRAPH_INLINE __extension__ __inline__
#elif defined(_MSC_VER)
#define CGRAPH_INLINE __inline
#else
#error unsupported C compiler in 32-bit/64-bit system
#endif

/** int types in different platforms */
#if CGRAPH_STDC_VERSION >= 199901L
#include <inttypes.h>
#include <stdint.h>
#define __CGRAPH_INT8_MAX INT8_MAX
#define __CGRAPH_INT8_MIN INT8_MIN
#define __CGRAPH_INT8_IN_FORMAT "%" SCNd8
#define __CGRAPH_INT8_OUT_FORMAT "%" PRId8
typedef int8_t __cgraph_int8;
#define __CGRAPH_UINT8_MAX UINT8_MAX
#define __CGRAPH_UINT8_MIN (0U)
#define __CGRAPH_UINT8_IN_FORMAT "%" SCNu8
#define __CGRAPH_UINT8_OUT_FORMAT "%" PRIu8
typedef uint8_t __cgraph_uint8;
#define __CGRAPH_INT16_MAX INT16_MAX
#define __CGRAPH_INT16_MIN INT16_MIN
#define __CGRAPH_INT16_IN_FORMAT "%" SCNd16
#define __CGRAPH_INT16_OUT_FORMAT "%" PRId16
typedef int16_t __cgraph_int16;
#define __CGRAPH_UINT16_MAX UINT16_MAX
#define __CGRAPH_UINT16_MIN (0U)
#define __CGRAPH_UINT16_IN_FORMAT "%" SCNu16
#define __CGRAPH_UINT16_OUT_FORMAT "%" PRIu16
typedef uint16_t __cgraph_uint16;
#define __CGRAPH_INT32_MAX INT32_MAX
#define __CGRAPH_INT32_MIN INT32_MIN
#define __CGRAPH_INT32_IN_FORMAT "%" SCNd32
#define __CGRAPH_INT32_OUT_FORMAT "%" PRId32
typedef int32_t __cgraph_int32;
#define __CGRAPH_UINT32_MAX UINT32_MAX
#define __CGRAPH_UINT32_MIN (0U)
#define __CGRAPH_UINT32_IN_FORMAT "%" SCNu32
#define __CGRAPH_UINT32_OUT_FORMAT "%" PRIu32
typedef uint32_t __cgraph_uint32;
#define __CGRAPH_INT64_MAX INT64_MAX
#define __CGRAPH_INT64_MIN INT64_MIN
#define __CGRAPH_INT64_IN_FORMAT "%" SCNd64
#define __CGRAPH_INT64_OUT_FORMAT "%" PRId64
#define __CGRAPH_INT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __CGRAPH_INT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __CGRAPH_INT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __CGRAPH_INT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __CGRAPH_INT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __CGRAPH_INT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef int64_t __cgraph_int64;
#define __CGRAPH_UINT64_MAX UINT64_MAX
#define __CGRAPH_UINT64_MIN (0ULL)
#define __CGRAPH_UINT64_IN_FORMAT "%" SCNu64
#define __CGRAPH_UINT64_OUT_FORMAT "%" PRIu64
#define __CGRAPH_UINT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __CGRAPH_UINT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __CGRAPH_UINT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __CGRAPH_UINT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __CGRAPH_UINT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __CGRAPH_UINT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef uint64_t __cgraph_uint64;
#define __CGRAPH_RANDOM64_A (6364136223846793005ULL)
#define __CGRAPH_RANDOM64_B (1442695040888963407ULL)
#define __CGRAPH_RANDOM64_M (18446744073709551615ULL)
#else
#ifdef HAVE_CONFIG_H
#include "cgraph_stdint.h"
#define __CGRAPH_INT8_MAX INT8_MAX
#define __CGRAPH_INT8_MIN INT8_MIN
typedef int8_t __cgraph_int8;
#define __CGRAPH_UINT8_MAX UINT8_MAX
#define __CGRAPH_UINT8_MIN (0U)
typedef uint8_t __cgraph_uint8;
#define __CGRAPH_INT16_MAX INT16_MAX
#define __CGRAPH_INT16_MIN INT16_MIN
typedef int16_t __cgraph_int16;
#define __CGRAPH_UINT16_MAX UINT16_MAX
#define __CGRAPH_UINT16_MIN (0U)
typedef uint16_t __cgraph_uint16;
#define __CGRAPH_INT32_MAX INT32_MAX
#define __CGRAPH_INT32_MIN INT32_MIN
typedef int32_t __cgraph_int32;
#define __CGRAPH_UINT32_MAX UINT32_MAX
#define __CGRAPH_UINT32_MIN (0U)
typedef uint32_t __cgraph_uint32;
#define __CGRAPH_INT64_MAX INT64_MAX
#define __CGRAPH_INT64_MIN INT64_MIN
typedef int64_t __cgraph_int64;
#define __CGRAPH_UINT64_MAX UINT64_MAX
#define __CGRAPH_UINT64_MIN (0ULL)
typedef uint64_t __cgraph_uint64;
#else
#define __CGRAPH_INT8_MAX (127)
#define __CGRAPH_INT8_MIN (-128)
typedef signed char __cgraph_int8;
#define __CGRAPH_UINT8_MAX (255U)
#define __CGRAPH_UINT8_MIN (0U)
typedef unsigned char __cgraph_uint8;
#define __CGRAPH_INT16_MAX (32767)
#define __CGRAPH_INT16_MIN (-32768)
typedef signed short __cgraph_int16;
#define __CGRAPH_UINT16_MAX (65535U)
#define __CGRAPH_UINT16_MIN (0U)
typedef unsigned short __cgraph_uint16;
#define __CGRAPH_INT32_MAX (2147483647)
#define __CGRAPH_INT32_MIN (-2147483648)
typedef signed int __cgraph_int32;
#define __CGRAPH_UINT32_MAX (4294967295U)
#define __CGRAPH_UINT32_MIN (0U)
typedef unsigned int __cgraph_uint32;
#if defined(__GNUC__) || defined(__clang__) || defined(__CGRAPH_HAVE_LONG_LONG)
#define __CGRAPH_INT64_MAX __extension__(9223372036854775807LL)
#define __CGRAPH_INT64_MIN __extension__(-9223372036854775808LL)
#define __CGRAPH_INT64_EPSILON1 __extension__(0xAAAAAAAAAAAAAAAAULL)
#define __CGRAPH_INT64_EPSILON2 __extension__(0xCCCCCCCCCCCCCCCCULL)
#define __CGRAPH_INT64_EPSILON4 __extension__(0xF0F0F0F0F0F0F0F0ULL)
#define __CGRAPH_INT64_EPSILON8 __extension__(0xFF00FF00FF00FF00ULL)
#define __CGRAPH_INT64_EPSILON16 __extension__(0xFFFF0000FFFF0000ULL)
#define __CGRAPH_INT64_EPSILON32 __extension__(0xFFFFFFFF00000000ULL)
__extension__ typedef signed long long __cgraph_int64;
#define __CGRAPH_UINT64_MAX __extension__(18446744073709551615ULL)
#define __CGRAPH_UINT64_MIN __extension__(0LL)
#define __CGRAPH_UINT64_EPSILON1 __extension__(0xAAAAAAAAAAAAAAAAULL)
#define __CGRAPH_UINT64_EPSILON2 __extension__(0xCCCCCCCCCCCCCCCCULL)
#define __CGRAPH_UINT64_EPSILON4 __extension__(0xF0F0F0F0F0F0F0F0ULL)
#define __CGRAPH_UINT64_EPSILON8 __extension__(0xFF00FF00FF00FF00ULL)
#define __CGRAPH_UINT64_EPSILON16 __extension__(0xFFFF0000FFFF0000ULL)
#define __CGRAPH_UINT64_EPSILON32 __extension__(0xFFFFFFFF00000000ULL)
__extension__ typedef unsigned long long __cgraph_uint64;
#define __CGRAPH_RANDOM64_A __extension__(6364136223846793005ULL)
#define __CGRAPH_RANDOM64_B __extension__(1442695040888963407ULL)
#define __CGRAPH_RANDOM64_M __extension__(18446744073709551615ULL)
#elif defined(_MSC_VER)
#define __CGRAPH_INT64_MAX (9223372036854775807LL)
#define __CGRAPH_INT64_MIN (-9223372036854775808LL)
#define __CGRAPH_INT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __CGRAPH_INT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __CGRAPH_INT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __CGRAPH_INT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __CGRAPH_INT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __CGRAPH_INT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef signed __int64 __cgraph_int64;
#define __CGRAPH_UINT64_MIN (0LL)
#define __CGRAPH_UINT64_MAX (18446744073709551615ULL)
#define __CGRAPH_UINT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __CGRAPH_UINT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __CGRAPH_UINT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __CGRAPH_UINT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __CGRAPH_UINT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __CGRAPH_UINT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef unsigned __int64 __cgraph_uint64;
#define __CGRAPH_RANDOM64_A (6364136223846793005ULL)
#define __CGRAPH_RANDOM64_B (1442695040888963407ULL)
#define __CGRAPH_RANDOM64_M (18446744073709551615ULL)
#else
#error unsupported C compiler in 32-bit/64-bit system
#endif
#endif
#define __CGRAPH_INT8_IN_FORMAT "%d"
#define __CGRAPH_INT8_OUT_FORMAT "%d"
#define __CGRAPH_UINT8_IN_FORMAT "%u"
#define __CGRAPH_UINT8_OUT_FORMAT "%u"
#define __CGRAPH_INT16_IN_FORMAT "%d"
#define __CGRAPH_INT16_OUT_FORMAT "%d"
#define __CGRAPH_UINT16_IN_FORMAT "%u"
#define __CGRAPH_UINT16_OUT_FORMAT "%u"
#define __CGRAPH_INT32_IN_FORMAT "%d"
#define __CGRAPH_INT32_OUT_FORMAT "%d"
#define __CGRAPH_UINT32_IN_FORMAT "%u"
#define __CGRAPH_UINT32_OUT_FORMAT "%u"
#if defined(__GNUC__) || defined(__clang__)
#ifdef __CGRAPH_PLAT_WINDOWS
#define __CGRAPH_INT64_IN_FORMAT "%I64d"
#define __CGRAPH_INT64_OUT_FORMAT "%I64d"
#define __CGRAPH_UINT64_IN_FORMAT "%I64u"
#define __CGRAPH_UINT64_OUT_FORMAT "%I64u"
#else
#define __CGRAPH_INT64_IN_FORMAT "%lld"
#define __CGRAPH_INT64_OUT_FORMAT "%lld"
#define __CGRAPH_UINT64_IN_FORMAT "%llu"
#define __CGRAPH_UINT64_OUT_FORMAT "%llu"
#endif
#elif defined(_MSC_VER)
#define __CGRAPH_INT64_IN_FORMAT "%I64d"
#define __CGRAPH_INT64_OUT_FORMAT "%I64d"
#define __CGRAPH_UINT64_IN_FORMAT "%I64u"
#define __CGRAPH_UINT64_OUT_FORMAT "%I64u"
#else
#error unsupported C compiler in 32-bit/64-bit system
#endif
#endif

#define __CGRAPH_INT8_EPS __CGRAPH_INT8_MIN
#define __CGRAPH_INT8_BITS (8)
#define __CGRAPH_UINT8_EPS __CGRAPH_UINT8_MAX
#define __CGRAPH_UINT8_BITS (8)
#define __CGRAPH_INT16_EPS __CGRAPH_INT16_MIN
#define __CGRAPH_INT16_BITS (16)
#define __CGRAPH_UINT16_EPS __CGRAPH_UINT16_MAX
#define __CGRAPH_UINT16_BITS (16)
#define __CGRAPH_INT32_EPS __CGRAPH_INT32_MIN
#define __CGRAPH_INT32_BITS (32)
#define __CGRAPH_UINT32_EPS __CGRAPH_UINT32_MAX
#define __CGRAPH_UINT32_BITS (32)
#define __CGRAPH_INT64_EPS __CGRAPH_INT64_MIN
#define __CGRAPH_INT64_BITS (64)
#define __CGRAPH_UINT64_EPS __CGRAPH_UINT64_MAX
#define __CGRAPH_UINT64_BITS (64)

/**< 128-bit float number details */
#if CGRAPH_STDC_VERSION >= 199901L || defined(__CGRAPH_HAVE_LONG_DOUBLE)
#define CGRAPH_WITH_FLOAT128
#define __CGRAPH_FLOAT128 long double
#define __CGRAPH_FLOAT128_MIN LDBL_MIN
#define __CGRAPH_FLOAT128_MAX LDBL_MAX
#define __CGRAPH_FLOAT128_EPS LDBL_EPSILON
#define __CGRAPH_FLOAT128_DIG LDBL_DIG
#define __CGRAPH_FLOAT128_BITS (8 * sizeof(__CGRAPH_FLOAT128))
#define __CGRAPH_FLOAT128_IN_FORMAT "%Lg"
#define __CGRAPH_FLOAT128_OUT_FORMAT "%Lg"
#define __CGRAPH_FLOAT128_HASH_OFFSET (12)
#else
#define __CGRAPH_FLOAT128 double
#define __CGRAPH_FLOAT128_MIN DBL_MIN
#define __CGRAPH_FLOAT128_MAX DBL_MAX
#define __CGRAPH_FLOAT128_EPS DBL_EPSILON
#define __CGRAPH_FLOAT128_DIG DBL_DIG
#define __CGRAPH_FLOAT128_BITS (8 * sizeof(__CGRAPH_FLOAT128))
#define __CGRAPH_FLOAT128_IN_FORMAT "%g"
#define __CGRAPH_FLOAT128_OUT_FORMAT "%g"
#define __CGRAPH_FLOAT128_HASH_OFFSET (8)
#endif

#if CGRAPH_WORDSIZE == 64
#define __CGRAPH_LONG_EPS __CGRAPH_UINT64_MAX
#define __CGRAPH_LONG_EPSILON1 __CGRAPH_UINT64_EPSILON1
#define __CGRAPH_LONG_EPSILON2 __CGRAPH_UINT64_EPSILON2
#define __CGRAPH_LONG_EPSILON4 __CGRAPH_UINT64_EPSILON4
#define __CGRAPH_LONG_EPSILON8 __CGRAPH_UINT64_EPSILON8
#define __CGRAPH_LONG_EPSILON16 __CGRAPH_UINT64_EPSILON16
#define __CGRAPH_LONG_EPSILON32 __CGRAPH_UINT64_EPSILON32
#define __CGRAPH_ULONG_EPS __CGRAPH_UINT64_MAX
#define __CGRAPH_ULONG_EPSILON1 __CGRAPH_UINT64_EPSILON1
#define __CGRAPH_ULONG_EPSILON2 __CGRAPH_UINT64_EPSILON2
#define __CGRAPH_ULONG_EPSILON4 __CGRAPH_UINT64_EPSILON4
#define __CGRAPH_ULONG_EPSILON8 __CGRAPH_UINT64_EPSILON8
#define __CGRAPH_ULONG_EPSILON16 __CGRAPH_UINT64_EPSILON16
#define __CGRAPH_ULONG_EPSILON32 __CGRAPH_UINT64_EPSILON32
#elif CGRAPH_WORDSIZE == 32
#define __CGRAPH_LONG_EPS __CGRAPH_UINT32_MAX
#define __CGRAPH_LONG_EPSILON1 (0xAAAAAAAAUL)
#define __CGRAPH_LONG_EPSILON2 (0xCCCCCCCCUL)
#define __CGRAPH_LONG_EPSILON4 (0xF0F0F0F0U)
#define __CGRAPH_LONG_EPSILON8 (0xFF00FF00U)
#define __CGRAPH_LONG_EPSILON16 (0xFFFF0000U)
#define __CGRAPH_LONG_EPSILON32 (0xFFFFFFFFU)
#define __CGRAPH_ULONG_EPS __CGRAPH_UINT32_MAX
#define __CGRAPH_ULONG_EPSILON1 (0xAAAAAAAAUL)
#define __CGRAPH_ULONG_EPSILON2 (0xCCCCCCCCUL)
#define __CGRAPH_ULONG_EPSILON4 (0xF0F0F0F0U)
#define __CGRAPH_ULONG_EPSILON8 (0xFF00FF00U)
#define __CGRAPH_ULONG_EPSILON16 (0xFFFF0000U)
#define __CGRAPH_ULONG_EPSILON32 (0xFFFFFFFFU)
#endif

#if (CGRAPH_STDC_VERSION >= 201112L)
#define __CGRAPH_TYPE_BEGIN(name)
#define __CGRAPH_TYPE_END(name)
#define __CGRAPH_TYPE_ELEMENT(type, element) ((type))
#else
#define __CGRAPH_TYPE_BEGIN(name) name
#define __CGRAPH_TYPE_END(name) name
#define __CGRAPH_TYPE_ELEMENT(type, element) ((type).element)
#endif

#if (CGRAPH_STDC_VERSION >= 199901L) || defined(__CGRAPH_HAVE_FUNC) ||         \
    defined(__func__)
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
