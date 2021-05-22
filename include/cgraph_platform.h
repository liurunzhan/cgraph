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

#ifndef __CGRAPH_PLATFORM_H__
#define __CGRAPH_PLATFORM_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "cgraph_stdchk.h"
#endif

#ifdef __HAVE_LIBM
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

/**< TYPE 0 : '\n' */
#define __PLAT_NLINE_UNIX (0)
/**< TYPE 1 : '\r' */
#define __PLAT_NLINE_MACOS (1)
/**< TYPE 2 : '\r\n' */
#define __PLAT_NLINE_WIN (2)

#define __PLAT_NLINE_TYPE0 '\n'
#define __PLAT_NLINE_TYPE1 '\r'

/** Self-defined features in different platforms */
#if defined(__CYGWIN__)
#define __PLAT_NAME "cygwin"
#define __PLAT_MODE CGRAPH_PLAT_CYGWIN
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_NLINE "\n"
#define __PLAT_NLINE_C __PLAT_NLINE_TYPE0
#define __PLAT_NLINE_TYPE __PLAT_NLINE_UNIX
#elif (defined(_WIN32) || defined(_WIN64))
#define __PLAT_NAME "windows"
#define __PLAT_MODE CGRAPH_PLAT_WINDOWS
#define __PLAT_PSPLIT "\\"
#define __PLAT_PSPLIT_C '\\'
#define __PLAT_NLINE "\r\n"
#define __PLAT_NLINE_C __PLAT_NLINE_TYPE0
#define __PLAT_NLINE_C0 __PLAT_NLINE_TYPE1
#define __PLAT_NLINE_C1 __PLAT_NLINE_TYPE0
#define __PLAT_WINDOWS
#define __PLAT_NLINE_TYPE __PLAT_NLINE_WIN
#elif defined(__APPLE__)
#define __PLAT_NAME "macos"
#define __PLAT_MODE CGRAPH_PLAT_MACOS
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_NLINE "\r"
#define __PLAT_NLINE_C __PLAT_NLINE_TYPE1
#define __PLAT_NLINE_TYPE __PLAT_NLINE_MACOS
#elif defined(__linux__)
#define __PLAT_NAME "linux"
#define __PLAT_MODE CGRAPH_PLAT_LINUX
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_NLINE "\n"
#define __PLAT_NLINE_C __PLAT_NLINE_TYPE0
#define __PLAT_NLINE_TYPE __PLAT_NLINE_UNIX
#elif defined(__unix__)
#define __PLAT_NAME "unix"
#define __PLAT_MODE CGRAPH_PLAT_UNIX
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_NLINE "\n"
#define __PLAT_NLINE_C __PLAT_NLINE_TYPE0
#define __PLAT_NLINE_TYPE __PLAT_NLINE_UNIX
#else
#define __PLAT_NAME "undefined"
#define __PLAT_MODE CGRAPH_PLAT_UNDEFINED
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_NLINE "\n"
#define __PLAT_NLINE_C __PLAT_NLINE_TYPE0
#define __PLAT_NLINE_TYPE __PLAT_NLINE_UNIX
#endif

/** Self-defined features in different structures */
#if defined(__BIG_ENDIAN__) || defined(__WORDS_BIGENDIAN)
#define __PLAT_ENDIAN 1
#else /* defined __LITTLE_ENDIAN__ or not */
#define __PLAT_ENDIAN 0
#endif

#ifndef __WORDSIZE
#if defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64) ||                 \
    defined(_M_IA64) || defined(__x86_64__) || defined(__x86_64) ||            \
    defined(__aarch64__) || defined(__ARM_64BIT_STATE)
#define __WORDSIZE 64
#elif defined(_WIN32) || defined(_M_IX86) || defined(__i386) ||                \
    defined(__i386__) || defined(__i486__) || defined(__i686__) ||             \
    defined(__ARM_32BIT_STATE)
#define __WORDSIZE 32
#endif
#endif

#if __WORDSIZE == 64
#define __WORDSIZE_LOG2 6
#elif __WORDSIZE == 32
#define __WORDSIZE_LOG2 5
#endif

/** C Standard */
#ifndef __STDC__
#error only standard c is suppoted!!
#endif
#ifndef __STDC_VERSION__
#define __STDC_VERSION__ 198901L
#endif

/** Self-defined features in different compilers */
#ifndef __INLINE
#if __STDC_VERSION__ >= 199901L
#define __INLINE inline
/** GNU C Compiler or Clang C Compiler */
#elif defined(__GNUC__) || defined(__clang__)
#define __INLINE __extension__ __inline__
/** Microsoft C Compiler */
#elif defined(_MSC_VER)
#define __INLINE _inline
/** Intel C Compiler */
#elif defined(__INTEL_COMPILER)
#define __INLINE inline
/** Digital Mars C Compiler */
#elif defined(__DMC__)
#define __INLINE inline
/** Watcom C Compiler */
#elif defined(__WATCOMC__)
#define __INLINE inline
/** ARM C Compiler */
#elif defined(__CC_ARM)
#define __INLINE __inline
/** IAR C Compiler */
#elif defined(__ICCARM__)
#define __INLINE inline
/** TASKING C Compiler */
#elif defined(__TASKING__)
#define __INLINE inline
#else
#define __INLINE
#endif
#endif

/** int types in different platforms */
#if __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#include <stdint.h>
#define __SIZE_IN_FORMAT "%z"
#define __SIZE_OUT_FORMAT "%z"
#define __INT8_MAX INT8_MAX
#define __INT8_MIN INT8_MIN
#define __INT8_IN_FORMAT "%" SCNd8
#define __INT8_OUT_FORMAT "%" PRId8
typedef int8_t __cgraph_int8;
#define __UINT8_MAX UINT8_MAX
#define __UINT8_MIN (0U)
#define __UINT8_IN_FORMAT "%" SCNu8
#define __UINT8_OUT_FORMAT "%" PRIu8
typedef uint8_t __cgraph_uint8;
#define __INT16_MAX INT16_MAX
#define __INT16_MIN INT16_MIN
#define __INT16_IN_FORMAT "%" SCNd16
#define __INT16_OUT_FORMAT "%" PRId16
typedef int16_t __cgraph_int16;
#define __UINT16_MAX UINT16_MAX
#define __UINT16_MIN (0U)
#define __UINT16_IN_FORMAT "%" SCNu16
#define __UINT16_OUT_FORMAT "%" PRIu16
typedef uint16_t __cgraph_uint16;
#define __INT32_MAX INT32_MAX
#define __INT32_MIN INT32_MIN
#define __INT32_IN_FORMAT "%" SCNd32
#define __INT32_OUT_FORMAT "%" PRId32
typedef int32_t __cgraph_int32;
#define __UINT32_MAX UINT32_MAX
#define __UINT32_MIN (0U)
#define __UINT32_IN_FORMAT "%" SCNu32
#define __UINT32_OUT_FORMAT "%" PRIu32
typedef uint32_t __cgraph_uint32;
#define __INT64_MAX INT64_MAX
#define __INT64_MIN INT64_MIN
#define __INT64_IN_FORMAT "%" SCNd64
#define __INT64_OUT_FORMAT "%" PRId64
#define __INT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __INT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __INT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __INT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __INT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __INT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef int64_t __cgraph_int64;
#define __UINT64_MAX UINT64_MAX
#define __UINT64_MIN (0ULL)
#define __UINT64_IN_FORMAT "%" SCNu64
#define __UINT64_OUT_FORMAT "%" PRIu64
#define __UINT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __UINT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __UINT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __UINT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __UINT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __UINT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef uint64_t __cgraph_uint64;
#define __RANDOM64_A (6364136223846793005ULL)
#define __RANDOM64_B (1442695040888963407ULL)
#define __RANDOM64_M (18446744073709551615ULL)
#else
#ifdef HAVE_CONFIG_H
#include "cgraph_stdint.h"
#define __SIZE_IN_FORMAT "%" PRI_SIZE_T_MODIFIER
#define __SIZE_OUT_FORMAT "%" PRI_SIZE_T_MODIFIER
#define __INT8_MAX INT8_MAX
#define __INT8_MIN INT8_MIN
typedef int8_t __cgraph_int8;
#define __UINT8_MAX UINT8_MAX
#define __UINT8_MIN (0U)
typedef uint8_t __cgraph_uint8;
#define __INT16_MAX INT16_MAX
#define __INT16_MIN INT16_MIN
typedef int16_t __cgraph_int16;
#define __UINT16_MAX UINT16_MAX
#define __UINT16_MIN (0U)
typedef uint16_t __cgraph_uint16;
#define __INT32_MAX INT32_MAX
#define __INT32_MIN INT32_MIN
typedef int32_t __cgraph_int32;
#define __UINT32_MAX UINT32_MAX
#define __UINT32_MIN (0U)
typedef uint32_t __cgraph_uint32;
#define __INT64_MAX INT64_MAX
#define __INT64_MIN INT64_MIN
typedef int64_t __cgraph_int64;
#define __UINT64_MAX UINT64_MAX
#define __UINT64_MIN (0ULL)
typedef uint64_t __cgraph_uint64;
#else
#define __SIZE_IN_FORMAT "%ld"
#define __SIZE_OUT_FORMAT "%ld"
#define __INT8_MAX (127L)
#define __INT8_MIN (-128L)
typedef signed char __cgraph_int8;
#define __UINT8_MAX (255U)
#define __UINT8_MIN (0U)
typedef unsigned char __cgraph_uint8;
#define __INT16_MAX (32767L)
#define __INT16_MIN (-32768L)
typedef signed short __cgraph_int16;
#define __UINT16_MAX (65535U)
#define __UINT16_MIN (0U)
typedef unsigned short __cgraph_uint16;
#define __INT32_MAX (2147483647L)
#define __INT32_MIN (-2147483648L)
typedef signed int __cgraph_int32;
#define __UINT32_MAX (4294967295U)
#define __UINT32_MIN (0U)
typedef unsigned int __cgraph_uint32;
#if defined(__GNUC__) || defined(__clang__) || defined(__HAVE_LONG_LONG)
#define __INT64_MAX __extension__(9223372036854775807LL)
#define __INT64_MIN __extension__(-9223372036854775808LL)
#define __INT64_EPSILON1 __extension__(0xAAAAAAAAAAAAAAAAULL)
#define __INT64_EPSILON2 __extension__(0xCCCCCCCCCCCCCCCCULL)
#define __INT64_EPSILON4 __extension__(0xF0F0F0F0F0F0F0F0ULL)
#define __INT64_EPSILON8 __extension__(0xFF00FF00FF00FF00ULL)
#define __INT64_EPSILON16 __extension__(0xFFFF0000FFFF0000ULL)
#define __INT64_EPSILON32 __extension__(0xFFFFFFFF00000000ULL)
__extension__ typedef signed long long __cgraph_int64;
#define __UINT64_MAX __extension__(18446744073709551615ULL)
#define __UINT64_MIN __extension__(0LL)
#define __UINT64_EPSILON1 __extension__(0xAAAAAAAAAAAAAAAAULL)
#define __UINT64_EPSILON2 __extension__(0xCCCCCCCCCCCCCCCCULL)
#define __UINT64_EPSILON4 __extension__(0xF0F0F0F0F0F0F0F0ULL)
#define __UINT64_EPSILON8 __extension__(0xFF00FF00FF00FF00ULL)
#define __UINT64_EPSILON16 __extension__(0xFFFF0000FFFF0000ULL)
#define __UINT64_EPSILON32 __extension__(0xFFFFFFFF00000000ULL)
__extension__ typedef unsigned long long __cgraph_uint64;
#define __RANDOM64_A __extension__(6364136223846793005ULL)
#define __RANDOM64_B __extension__(1442695040888963407ULL)
#define __RANDOM64_M __extension__(18446744073709551615ULL)
#elif defined(_MSC_VER)
#define __INT64_MAX (9223372036854775807LL)
#define __INT64_MIN (-9223372036854775808LL)
#define __INT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __INT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __INT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __INT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __INT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __INT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef signed __int64 __cgraph_int64;
#define __UINT64_MIN (0LL)
#define __UINT64_MAX (18446744073709551615ULL)
#define __UINT64_EPSILON1 (0xAAAAAAAAAAAAAAAAULL)
#define __UINT64_EPSILON2 (0xCCCCCCCCCCCCCCCCULL)
#define __UINT64_EPSILON4 (0xF0F0F0F0F0F0F0F0ULL)
#define __UINT64_EPSILON8 (0xFF00FF00FF00FF00ULL)
#define __UINT64_EPSILON16 (0xFFFF0000FFFF0000ULL)
#define __UINT64_EPSILON32 (0xFFFFFFFF00000000ULL)
typedef unsigned __int64 __cgraph_uint64;
#define __RANDOM64_A (6364136223846793005ULL)
#define __RANDOM64_B (1442695040888963407ULL)
#define __RANDOM64_M (18446744073709551615ULL)
#else
#error unsupported C compiler in 32-bit/64-bit system
#endif
#endif
#define __INT8_IN_FORMAT "%d"
#define __INT8_OUT_FORMAT "%d"
#define __UINT8_IN_FORMAT "%u"
#define __UINT8_OUT_FORMAT "%u"
#define __INT16_IN_FORMAT "%d"
#define __INT16_OUT_FORMAT "%d"
#define __UINT16_IN_FORMAT "%u"
#define __UINT16_OUT_FORMAT "%u"
#define __INT32_IN_FORMAT "%d"
#define __INT32_OUT_FORMAT "%d"
#define __UINT32_IN_FORMAT "%u"
#define __UINT32_OUT_FORMAT "%u"
#if defined(__GNUC__) || defined(__clang__)
#ifdef __PLAT_WINDOWS
#define __INT64_IN_FORMAT "%I64d"
#define __INT64_OUT_FORMAT "%I64d"
#define __UINT64_IN_FORMAT "%I64u"
#define __UINT64_OUT_FORMAT "%I64u"
#else
#define __INT64_IN_FORMAT "%lld"
#define __INT64_OUT_FORMAT "%lld"
#define __UINT64_IN_FORMAT "%llu"
#define __UINT64_OUT_FORMAT "%llu"
#endif
#elif defined(_MSC_VER)
#define __INT64_IN_FORMAT "%I64d"
#define __INT64_OUT_FORMAT "%I64d"
#define __UINT64_IN_FORMAT "%I64u"
#define __UINT64_OUT_FORMAT "%I64u"
#else
#error unsupported C compiler in 32-bit/64-bit system
#endif
#endif

#define __INT8_EPS __INT8_MIN
#define __INT8_BITS (8)
#define __INT8_BITS_LOG2 (3)
#define __UINT8_EPS __UINT8_MAX
#define __UINT8_BITS (8)
#define __UINT8_BITS_LOG2 (3)
#define __INT16_EPS __INT16_MIN
#define __INT16_BITS (16)
#define __INT16_BITS_LOG2 (4)
#define __UINT16_EPS __UINT16_MAX
#define __UINT16_BITS (16)
#define __UINT16_BITS_LOG2 (4)
#define __INT32_EPS __INT32_MIN
#define __INT32_BITS (32)
#define __INT32_BITS_LOG2 (5)
#define __UINT32_EPS __UINT32_MAX
#define __UINT32_BITS (32)
#define __UINT32_BITS_LOG2 (5)
#define __INT64_EPS __INT64_MIN
#define __INT64_BITS (64)
#define __INT64_BITS_LOG2 (6)
#define __UINT64_EPS __UINT64_MAX
#define __UINT64_BITS (64)
#define __UINT64_BITS_LOG (6)

/**< 128-bit float number details */
#if __STDC_VERSION__ >= 199901L || defined(__HAVE_LONG_DOUBLE)
#define __WITH_FLOAT128
#define __FLOAT128 long double
#define __FLOAT128_MIN LDBL_MIN
#define __FLOAT128_MAX LDBL_MAX
#define __FLOAT128_EPS LDBL_EPSILON
#define __FLOAT128_DIG LDBL_DIG
#define __FLOAT128_BITS (8 * sizeof(__FLOAT128))
#define __FLOAT128_IN_FORMAT "%Lg"
#define __FLOAT128_OUT_FORMAT "%Lg"
#define __FLOAT128_HASH_OFFSET (12)
#define __FLOAT128_FRA_BITS (15)
#define __FLOAT128_FRA_OFFSET (0)
#define __FLOAT128_FRA_EPSILON (0x7FFF)
#define __FLOAT128_EXP_BITS (64)
#define __FLOAT128_EXP_OFFSET __FLOAT128_FRA_BITS
#define __FLOAT128_EXP_EPSILON __UINT64_EPS
#else
#define __FLOAT128 double
#define __FLOAT128_MIN DBL_MIN
#define __FLOAT128_MAX DBL_MAX
#define __FLOAT128_EPS DBL_EPSILON
#define __FLOAT128_DIG DBL_DIG
#define __FLOAT128_BITS (8 * sizeof(__FLOAT128))
#define __FLOAT128_IN_FORMAT "%g"
#define __FLOAT128_OUT_FORMAT "%g"
#define __FLOAT128_HASH_OFFSET (8)
#define __FLOAT128_FRA_BITS (11)
#define __FLOAT128_FRA_OFFSET (0)
#define __FLOAT128_FRA_EPSILON (0x7FFF)
#define __FLOAT128_EXP_BITS (52)
#define __FLOAT128_EXP_OFFSET __FLOAT128_FRA_BITS
#define __FLOAT128_EXP_EPSILON (0xFFFFFFFFFFFFF)
#endif

#if __WORDSIZE == 64
#define __LONG_EPS __UINT64_MAX
#define __LONG_EPSILON1 __UINT64_EPSILON1
#define __LONG_EPSILON2 __UINT64_EPSILON2
#define __LONG_EPSILON4 __UINT64_EPSILON4
#define __LONG_EPSILON8 __UINT64_EPSILON8
#define __LONG_EPSILON16 __UINT64_EPSILON16
#define __LONG_EPSILON32 __UINT64_EPSILON32
#define __ULONG_EPS __UINT64_MAX
#define __ULONG_EPSILON1 __UINT64_EPSILON1
#define __ULONG_EPSILON2 __UINT64_EPSILON2
#define __ULONG_EPSILON4 __UINT64_EPSILON4
#define __ULONG_EPSILON8 __UINT64_EPSILON8
#define __ULONG_EPSILON16 __UINT64_EPSILON16
#define __ULONG_EPSILON32 __UINT64_EPSILON32
#elif __WORDSIZE == 32
#define __LONG_EPS __UINT32_MAX
#define __LONG_EPSILON1 (0xAAAAAAAAUL)
#define __LONG_EPSILON2 (0xCCCCCCCCUL)
#define __LONG_EPSILON4 (0xF0F0F0F0U)
#define __LONG_EPSILON8 (0xFF00FF00U)
#define __LONG_EPSILON16 (0xFFFF0000U)
#define __LONG_EPSILON32 (0xFFFFFFFFU)
#define __ULONG_EPS __UINT32_MAX
#define __ULONG_EPSILON1 (0xAAAAAAAAUL)
#define __ULONG_EPSILON2 (0xCCCCCCCCUL)
#define __ULONG_EPSILON4 (0xF0F0F0F0U)
#define __ULONG_EPSILON8 (0xFF00FF00U)
#define __ULONG_EPSILON16 (0xFFFF0000U)
#define __ULONG_EPSILON32 (0xFFFFFFFFU)
#endif

#if (__STDC_VERSION__ >= 201112L)
#define __TYPE_BEGIN(name)
#define __TYPE_END(name)
#define __TYPE_ELEMENT(type, element) ((type))
#else
#define __TYPE_BEGIN(name) name
#define __TYPE_END(name) name
#define __TYPE_ELEMENT(type, element) ((type).element)
#endif

#if (__STDC_VERSION__ >= 199901L) || defined(__HAVE_FUNC) || defined(__func__)
#define __FUNCTION __func__
#elif defined(__FUNCTION__)
#define __FUNCTION __FUNCTION__
#elif defined(__function__)
#define __FUNCTION __function__
#else
#define __FUNCTION NULL
#endif

#if __STDC_VERSION__ >= 199901L
#define __TYPE_PTRSIZE (1)
#else
#define __TYPE_PTRSIZE (2)
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_PLATFORM_H__ */
