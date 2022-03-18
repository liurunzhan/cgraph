/**
 * @file cgraph_platform.h
 * @brief the configuration in different platforms
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
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
#define USE_XOPEN
#endif

typedef enum {
  CGRAPH_PLAT_CYGWIN = 0,  /**< TYPE 0 : CGRAPH_PLAT_CYGWIN */
  CGRAPH_PLAT_MSYS = 0,    /**< TYPE 0 : CGRAPH_PLAT_MSYS */
  CGRAPH_PLAT_MSYS2 = 0,   /**< TYPE 0 : CGRAPH_PLAT_MSYS2 */
  CGRAPH_PLAT_WINDOWS = 1, /**< TYPE 1 : CGRAPH_PLAT_WINDOWS */
  CGRAPH_PLAT_MACOS = 2,   /**< TYPE 2 : CGRAPH_PLAT_MACOS */
  CGRAPH_PLAT_LINUX = 3,   /**< TYPE 3 : CGRAPH_PLAT_LINUX */
  CGRAPH_PLAT_UNIX = 4,    /**< TYPE 4 : CGRAPH_PLAT_UNIX */
  CGRAPH_PLAT_STDC = 5     /**< TYPE 5 : CGRAPH_PLAT_STDC */
} cgraph_plat_t;

/**< TYPE 0 : '\n' */
#define __PLAT_LEND_UNIX (0)
/**< TYPE 1 : '\r' */
#define __PLAT_LEND_MACOS (1)
/**< TYPE 2 : '\r\n' */
#define __PLAT_LEND_WIN (2)

#define __PLAT_LEND_TYPE0 '\n'
#define __PLAT_LEND_TYPE1 '\r'

/** Self-defined features in different platforms */
#if defined(__CYGWIN__)
#define __PLAT_NAME "cygwin"
#define __PLAT_MODE CGRAPH_PLAT_CYGWIN
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_LEND "\n"
#define __PLAT_LEND_SIZE (1)
#define __PLAT_LEND_C __PLAT_LEND_TYPE0
#define __PLAT_LEND_TYPE __PLAT_LEND_UNIX
#elif (defined(_WIN32) || defined(_WIN64))
#define __PLAT_NAME "windows"
#define __PLAT_MODE CGRAPH_PLAT_WINDOWS
#define __PLAT_PSPLIT "\\"
#define __PLAT_PSPLIT_C '\\'
#define __PLAT_LEND "\r\n"
#define __PLAT_LEND_SIZE (2)
#define __PLAT_LEND_C __PLAT_LEND_TYPE0
#define __PLAT_LEND_C0 __PLAT_LEND_TYPE1
#define __PLAT_LEND_C1 __PLAT_LEND_TYPE0
#define __PLAT_WINDOWS
#define __PLAT_LEND_TYPE __PLAT_LEND_WIN
#elif defined(__APPLE__)
#define __PLAT_NAME "macos"
#define __PLAT_MODE CGRAPH_PLAT_MACOS
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_LEND "\r"
#define __PLAT_LEND_C __PLAT_LEND_TYPE1
#define __PLAT_LEND_TYPE __PLAT_LEND_MACOS
#else
#if defined(__linux__)
#define __PLAT_NAME "linux"
#define __PLAT_MODE CGRAPH_PLAT_LINUX
#elif defined(Unix__)
#define __PLAT_NAME "unix"
#define __PLAT_MODE CGRAPH_PLAT_UNIX
#else
#define __PLAT_NAME "none"
#define __PLAT_MODE CGRAPH_PLAT_STDC
#endif
#define __PLAT_PSPLIT "/"
#define __PLAT_PSPLIT_C '/'
#define __PLAT_LEND_SIZE (1)
#define __PLAT_LEND "\n"
#define __PLAT_LEND_C __PLAT_LEND_TYPE0
#define __PLAT_LEND_TYPE __PLAT_LEND_UNIX
#endif

/** Self-defined features in different structures */
#define __PLAT_ENDIAN_BIG (0)
#define __PLAT_ENDIAN_LITTLE (1)
#define __PLAT_ENDIAN_NONE (2)
#if defined(__BIG_ENDIAN__) || defined(__BIG_ENDIAN) ||                        \
    defined(__WORDS_BIGENDIAN) /** Big-Endian architecture */
#define __PLAT_ENDIAN __PLAT_ENDIAN_BIG
#elif defined(__LITTLE_ENDIAN__) || defined(__LITTLE_ENDIAN) ||                \
    defined(__WORDS_LITTLEENDIAN) /** Little-endian architecture */
#define __PLAT_ENDIAN __PLAT_ENDIAN_LITTLE
#else /** Undefined architecture */
#define __PLAT_ENDIAN __PLAT_ENDIAN_LITTLE
#endif

#ifndef __WORDSIZE
#if defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64) ||                 \
    defined(_M_IA64) || defined(_M_IX64) || defined(__x86_64__) ||             \
    defined(__x86_64) || defined(__aarch64__) || defined(__ARM_64BIT_STATE)
#define __WORDSIZE (64)
#elif defined(_WIN32) || defined(_M_IX86) || defined(I386) ||                  \
    defined(I386__) || defined(I486__) || defined(I686__) ||                   \
    defined(__ARM_32BIT_STATE)
#define __WORDSIZE (32)
#else
#define __WORDSIZE (32)
#endif
#endif

#if __WORDSIZE == 64
#define __WORDSIZE_LOG2 (6)
#else
#define __WORDSIZE_LOG2 (5)
#endif

/** C Standard */
#ifndef __STDC__
#error Only standard c is suppoted!!
#endif

#ifndef __STDC_VERSION__
#define __STDC_VERSION__ (198901L)
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
#elif defined(INTEL_COMPILER)
#define __INLINE inline
/** Digital Mars C Compiler */
#elif defined(__DMC__)
#define __INLINE inline
/** Watcom C Compiler */
#elif defined(__WATCOMC__)
#define __INLINE inline
/** ARM C Compiler */
#elif defined(__CC_ARM)
#define __INLINE Inline
/** IAR C Compiler */
#elif defined(ICCARM__)
#define __INLINE inline
/** TASKING C Compiler */
#elif defined(__TASKING__)
#define __INLINE inline
#else
#define __INLINE
#endif
#endif

#ifndef __EXTENSION__
#if (__STDC_VERSION__ < 199901L) && (defined(__GNUC__) || defined(__clang__))
#define __EXTENSION__ __extension__
#else
#define __EXTENSION__
#endif
#endif

/** int types in different platforms */
#if __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#include <stdint.h>
#elif defined(HAVE_CONFIG_H)
#include "cgraph_stdint.h"
#endif

#ifndef INT8_MAX
typedef signed char int8_t;
#define INT8_MAX (127L)
#define INT8_MIN (-128L)
typedef unsigned char uint8_t;
#define UINT8_MAX (255U)
#endif
#define UINT8_MIN (0U)

#ifndef INT16_MAX
typedef signed short int16_t;
#define INT16_MAX (32767L)
#define INT16_MIN (-32768L)
typedef unsigned short uint16_t;
#define UINT16_MAX (65535U)
#endif
#define UINT16_MIN (0U)

#ifndef INT32_MAX
typedef signed int int32_t;
#define INT32_MAX (2147483647L)
#define INT32_MIN (-2147483648L)
typedef unsigned int uint32_t;
#define UINT32_MAX (4294967295U)
#endif
#define UINT32_MIN (0U)

#if (__STDC_VERSION__ < 199901L) && (!defined(HAVE_LONG_LONG))
#if defined(__GNUC__) || defined(__clang__)
__EXTENSION__ typedef signed long long int64_t;
__EXTENSION__ typedef unsigned long long uint64_t;
#elif defined(_MSC_VER)
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else /**   */
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
#endif
#endif

#define INT8_MASK INT8_MIN
#define INT8_EPSILON (1)
#define INT8_BITS (8)
#define INT8_BITS_LOG2 (3)

#define UINT8_MASK UINT8_MAX
#define UINT8_EPSILON (1U)
#define UINT8_BITS INT8_BITS
#define UINT8_BITS_LOG2 INT8_BITS_LOG2

#define INT16_MASK INT16_MIN
#define INT16_EPSILON (1)
#define INT16_BITS (16)
#define INT16_BITS_LOG2 (4)

#define UINT16_MASK UINT16_MAX
#define UINT16_EPSILON (1U)
#define UINT16_BITS INT16_BITS
#define UINT16_BITS_LOG2 INT16_BITS_LOG2

#define INT32_MASK INT32_MIN
#define INT32_EPSILON (1)
#define INT32_BITS (32)
#define INT32_BITS_LOG2 (5)

#define UINT32_MASK UINT32_MASK
#define UINT32_EPSILON (1U)
#define UINT32_BITS INT32_BITS
#define UINT32_BITS_LOG2 INT32_BITS_LOG2

#ifndef SCNd8

#define SCNd8 "d"
#define PRId8 "d"

#define SCNu8 "u"
#define PRIu8 "u"

#define SCNd16 "d"
#define PRId16 "d"

#define SCNu16 "u"
#define PRIu16 "u"

#define SCNd32 "d"
#define PRId32 "d"

#define SCNu32 "u"
#define PRIu32 "u"

#endif

#if __STDC_VERSION__ >= 199901L
#define SCNptr "z"
#define PRIptr "z"
#elif defined(HAVE_CONFIG_H)
#define SCNptr PRI_SIZE_T_MODIFIER
#define PRIptr PRI_SIZE_T_MODIFIER
#else
#define SCNptr "ld"
#define PRIptr "ld"
#endif

#ifndef INT64_MAX
#define INT64_MAX __EXTENSION__(9223372036854775807LL)
#define INT64_MIN __EXTENSION__(-9223372036854775808LL)
#define UINT64_MAX __EXTENSION__(18446744073709551615ULL)
#endif
#define UINT64_MIN __EXTENSION__(0LL)

#define INT64_BITS (64)
#define INT64_BITS_LOG2 (6)
#define INT64_MASK INT64_MIN
#define INT64_MASK1 __EXTENSION__(0xAAAAAAAAAAAAAAAAULL)
#define INT64_MASK2 __EXTENSION__(0xCCCCCCCCCCCCCCCCULL)
#define INT64_MASK4 __EXTENSION__(0xF0F0F0F0F0F0F0F0ULL)
#define INT64_MASK8 __EXTENSION__(0xFF00FF00FF00FF00ULL)
#define INT64_MASK16 __EXTENSION__(0xFFFF0000FFFF0000ULL)
#define INT64_MASK32 __EXTENSION__(0xFFFFFFFF00000000ULL)
#define INT64_MASK64 __EXTENSION__(0xFFFFFFFFFFFFFFFFULL)
#define INT64_EPSILON __EXTENSION__(1LL)

#define UINT64_BITS INT64_BITS
#define UINT64_BITS_LOG INT64_BITS_LOG2
#define UINT64_MASK UINT64_MAX
#define UINT64_MASK1 __EXTENSION__(0xAAAAAAAAAAAAAAAAULL)
#define UINT64_MASK2 __EXTENSION__(0xCCCCCCCCCCCCCCCCULL)
#define UINT64_MASK4 __EXTENSION__(0xF0F0F0F0F0F0F0F0ULL)
#define UINT64_MASK8 __EXTENSION__(0xFF00FF00FF00FF00ULL)
#define UINT64_MASK16 __EXTENSION__(0xFFFF0000FFFF0000ULL)
#define UINT64_MASK32 __EXTENSION__(0xFFFFFFFF00000000ULL)
#define UINT64_MASK64 __EXTENSION__(0xFFFFFFFFFFFFFFFFULL)
#define UINT64_EPSILON __EXTENSION__(1ULL)

/** integer type input and output style */
#ifndef SCNd64
#if defined(__GNUC__) || defined(__clang__)
#ifdef __PLAT_WINDOWS
#define SCNd64 "I64d"
#define PRId64 "I64d"
#define SCNu64 "I64u"
#define PRIu64 "I64u"
#else
#define SCNd64 "lld"
#define PRId64 "lld"
#define SCNu64 "llu"
#define PRIu64 "llu"
#endif
#elif defined(_MSC_VER)
#define SCNd64 "I64d"
#define PRId64 "I64d"
#define SCNu64 "I64u"
#define PRIu64 "I64u"
#else /**   */
#ifdef __PLAT_WINDOWS
#define SCNd64 "I64d"
#define PRId64 "I64d"
#define SCNu64 "I64u"
#define PRIu64 "I64u"
#else
#define SCNd64 "lld"
#define PRId64 "lld"
#define SCNu64 "llu"
#define PRIu64 "llu"
#endif
#endif
#endif

#if __WORDSIZE == 64
#define LONG_MASK UINT64_MAX
#define LONG_MASK1 UINT64_MASK1
#define LONG_MASK2 UINT64_MASK2
#define LONG_MASK4 UINT64_MASK4
#define LONG_MASK8 UINT64_MASK8
#define LONG_MASK16 UINT64_MASK16
#define LONG_MASK32 UINT64_MASK32
#define LONG_BITS UINT64_BITS

#define ULONG_MASK UINT64_MAX
#define ULONG_MASK1 UINT64_MASK1
#define ULONG_MASK2 UINT64_MASK2
#define ULONG_MASK4 UINT64_MASK4
#define ULONG_MASK8 UINT64_MASK8
#define ULONG_MASK16 UINT64_MASK16
#define ULONG_MASK32 UINT64_MASK32
#define ULONG_BITS UINT64_BITS
#elif __WORDSIZE == 32
#define LONG_MASK UINT32_MAX
#define LONG_MASK1 (0xAAAAAAAAUL)
#define LONG_MASK2 (0xCCCCCCCCUL)
#define LONG_MASK4 (0xF0F0F0F0U)
#define LONG_MASK8 (0xFF00FF00U)
#define LONG_MASK16 (0xFFFF0000U)
#define LONG_MASK32 (0xFFFFFFFFU)
#define LONG_BITS UINT32_BITS

#define ULONG_MASK UINT32_MAX
#define ULONG_MASK1 (0xAAAAAAAAUL)
#define ULONG_MASK2 (0xCCCCCCCCUL)
#define ULONG_MASK4 (0xF0F0F0F0U)
#define ULONG_MASK8 (0xFF00FF00U)
#define ULONG_MASK16 (0xFFFF0000U)
#define ULONG_MASK32 (0xFFFFFFFFU)
#define ULONG_BITS UINT32_BITS
#endif

#define SCNdlg "ld"
#define PRIdlg "ld"
#define SCNulg "lu"
#define PRIulg "lu"

/**< 128-bit float number details */
#if __STDC_VERSION__ >= 199901L && defined(__SIZEOF_INT128__)
#define __WITH_INT128_SIZE128
typedef int64_t int128_t;
#define INT128_MIN (-1)
#define INT128_MAX (0)
#define INT128_MASK INT64_MASK
#define INT128_EPSILON (1)
#define INT128_DIG (128)
#define INT128_BITS (128)
#define INT128_BITS_LOG2 (7)
#define INT128_IN_FMT "s"
#define INT128_OUT_FMT "s"

#define INT128_MASK1 INT64_MASK1
#define INT128_MASK2 INT64_MASK2
#define INT128_MASK4 INT64_MASK4
#define INT128_MASK8 INT64_MASK8
#define INT128_MASK16 INT64_MASK16
#define INT128_MASK32 INT64_MASK32
#define INT128_MASK64 INT64_MASK64
#define INT128_DTYPE __int128

typedef uint64_t uint128_t;
#define UINT128_MIN (0)
#define UINT128_MAX (1)
#define UINT128_MASK UINT64_MASK
#define UINT128_EPSILON (1)
#define UINT128_DIG UINT64_DIG
#define UINT128_BITS UINT64_BITS
#define UINT128_BITS_LOG2 (7)
#define SCNd128 "s"
#define PRId128 "s"
#define UINT128_MASK1 UINT64_MASK1
#define UINT128_MASK2 UINT64_MASK2
#define UINT128_MASK4 UINT64_MASK4
#define UINT128_MASK8 UINT64_MASK8
#define UINT128_MASK16 UINT64_MASK16
#define UINT128_MASK32 UINT64_MASK32
#define UINT128_MASK64 UINT64_MASK64
#define UINT128_DTYPE uint128_t

#else
#define __WITH_INT128_SIZE64
typedef int64_t int128_t;
#define INT128_MIN INT64_MIN
#define INT128_MAX INT64_MAX
#define INT128_MASK INT64_MASK
#define INT128_EPSILON INT64_EPSILON
#define INT128_DIG INT64_DIG
#define INT128_BITS (8 * sizeof(int128_t))
#define INT128_BITS_LOG2 INT64_BITS_LOG2
#define SCNd128 "s"
#define PRId128 "s"
#define INT128_MASK1 INT64_MASK1
#define INT128_MASK2 INT64_MASK2
#define INT128_MASK4 INT64_MASK4
#define INT128_MASK8 INT64_MASK8
#define INT128_MASK16 INT64_MASK16
#define INT128_MASK32 INT64_MASK32
#define INT128_MASK64 INT64_MASK64
#define INT128_DTYPE int128_t

typedef uint64_t uint128_t;
#define UINT128_MIN UINT64_MIN
#define UINT128_MAX UINT64_MAX
#define UINT128_MASK UINT64_MASK
#define UINT128_EPSILON UINT64_EPSILON
#define UINT128_DIG UINT64_DIG
#define UINT128_BITS (8 * sizeof(uint128_t))
#define UINT128_BITS_LOG2 UINT64_BITS_LOG2
#define UINT128_IN_FMT "s"
#define UINT128_OUT_FMT "s"
#define UINT128_MASK1 UINT64_MASK1
#define UINT128_MASK2 UINT64_MASK2
#define UINT128_MASK4 UINT64_MASK4
#define UINT128_MASK8 UINT64_MASK8
#define UINT128_MASK16 UINT64_MASK16
#define UINT128_MASK32 UINT64_MASK32
#define UINT128_MASK64 UINT64_MASK64
#define UINT128_DTYPE uint128_t
#endif

/**< float number details */
#ifndef CONST_NAN
#define CONST_NAN (0.0 / 0.0)
#endif

#ifndef CONST_INFINITY
#define CONST_INFINITY (1.0 / 0.0)
#endif

/**
 * 8-bit float point number
 * sign bit 1
 * exp bit 3 (bias=5)
 * fra bit 4
 * value(sign, exp, bias, fra) = sign * fra * 2^(exp + bias)
 */
/** @{ */
#define FLT8_MIN (0xEFU)
#define FLT8_MAX (0x6FU)
#define FLT8_NAN (0x7FU)
#define FLT8_INF (0x70U)
#define FLT8_PINF FLT8_INF
#define FLT8_NINF (0xF0U)
#define FLT8_EPSILON (0x10U)
#define FLT8_DIG UINT8_EPSILON
#define FLT8_MASK UINT8_MASK
#define FLT8_EXP_DIG (3)
#define FLT8_EXP_BIAS (0)
#define FLT8_EXP_BITS FLT8_EXP_DIG
#define FLT8_EXP_MASK (0x07U)
#define FLT8_EXP_OFFSET (0)
#define FLT8_FRAC_DIG (4)
#define FLT8_FRAC_BIAS FLT8_EXP_BITS
#define FLT8_FRAC_BITS FLT8_FRAC_DIG
#define FLT8_FRAC_MASK (0x0FU)
#define FLT8_FRAC_OFFSET (0)
#define FLT8_SIG_DIG (0)
#define FLT8_SIG_MASK (0)
/** @} */

/**
 * 16-bit float point number
 * sign bit 1
 * exp bit 5 (bias=15)
 * fra bit 10
 * value(sign, exp, bias, fra) = sign * fra * 2^(exp + bias)
 */
/** @{ */
#define FLT16_MIN (0xFEFFU)
#define FLT16_MAX (0x7EFFU)
#define FLT16_NAN (0x7FFFU)
#define FLT16_INF (0x7C00U)
#define FLT16_PINF FLT16_INF
#define FLT16_NINF (0xFC00U)
#define FLT16_EPSILON (0x0100U)
#define FLT16_DIG (0)
#define FLT16_MASK UINT16_MASK
#define FLT16_EXP_DIG (5)
#define FLT16_EXP_BIAS (0)
#define FLT16_EXP_BITS FLT16_EXP_DIG
#define FLT16_EXP_MASK (0x1FU)
#define FLT16_EXP_OFFSET (0)
#define FLT16_FRAC_DIG (10)
#define FLT16_FRAC_BIAS (0)
#define FLT16_FRAC_BITS FLT16_FRAC_DIG
#define FLT16_FRAC_MASK (0x3FFU)
#define FLT16_FRAC_OFFSET (0)
#define FLT16_SIG_DIG (0)
#define FLT16_SIG_MASK (0)
/** @} */

/** 32-bit float point number */
/** @{ */
#define FLT_NAN CONST_NAN
#define FLT_INF CONST_INFINITY
#define FLT_PINF CONST_INFINITY
#define FLT_NINF (-CONST_INFINITY)
/** @} */

/** 64-bit float point number */
/** @{ */
#define DBL_NAN CONST_NAN
#define DBL_INF CONST_INFINITY
#define DBL_PINF CONST_INFINITY
#define DBL_NINF (-CONST_INFINITY)
/** @} */

/**< 128-bit float number */
#if __STDC_VERSION__ >= 199901L || defined(__HAVE_LONG_DOUBLE)
#define __WITH_FLOAT128_SIZE128
#define __FLOAT128 long double
#define __FLOAT128_MIN LDBL_MIN
#define __FLOAT128_MAX LDBL_MAX
#define __FLOAT128_NAN (0.0 / 0.0)
#define __FLOAT128_INF (1.0 / 0.0)
#define __FLOAT128_PINF (1.0 / 0.0)
#define __FLOAT128_NINF (-1.0 / 0.0)
#define __FLOAT128_EPSILON UINT128_MASK
#define __FLOAT128_DIG LDBL_DIG
#define __FLOAT128_BITS (8 * sizeof(__FLOAT128))
#define __FLOAT128_IN_FMT "Lg"
#define __FLOAT128_OUT_FMT "Lg"
#define __FLOAT128_HASH_OFFSET (12)
#define __FLOAT128_FRA_BITS (15)
#define __FLOAT128_FRA_OFFSET (0)
#define __FLOAT128_FRA_EPSILON (0x7FFF)
#define __FLOAT128_EXP_BITS (64)
#define __FLOAT128_EXP_OFFSET __FLOAT128_FRA_BITS
#define __FLOAT128_EXP_MASK UINT64_MASK
#else
#define __WITH_FLOAT128_SIZE64
#define __FLOAT128 double
#define __FLOAT128_MIN DBL_MIN
#define __FLOAT128_MAX DBL_MAX
#define __FLOAT128_NAN (0.0 / 0.0)
#define __FLOAT128_INF (1.0 / 0.0)
#define __FLOAT128_PINF (1.0 / 0.0)
#define __FLOAT128_NINF (-1.0 / 0.0)
#define __FLOAT128_EPSILON DBL_EPSILON
#define __FLOAT128_DIG DBL_DIG
#define __FLOAT128_BITS (8 * sizeof(__FLOAT128))
#define __FLOAT128_IN_FMT "g"
#define __FLOAT128_OUT_FMT "g"
#define __FLOAT128_HASH_OFFSET (8)
#define __FLOAT128_FRA_BITS (11)
#define __FLOAT128_FRA_OFFSET (0)
#define __FLOAT128_FRA_EPSILON (0x7FFFU)
#define __FLOAT128_EXP_BITS (52)
#define __FLOAT128_EXP_OFFSET __FLOAT128_FRA_BITS
#define __FLOAT128_EXP_MASK __extension__(0xFFFFFFFFFFFFFULL)
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

#ifndef __FUNCTION__
#if (__STDC_VERSION__ >= 199901L) || defined(__HAVE_FUNC) || defined(__func__)
#define __FUNCTION__ __func__
#elif defined(__function__)
#define __FUNCTION__ __function__
#else
#define __FUNCTION__ NULL
#endif
#endif

#if __STDC_VERSION__ >= 199901L
#define __TYPE_PTRSIZE (1)
#else
#define __TYPE_PTRSIZE (2)
#endif

/**
 * a simple way to use for-loop block locally, in c89/c90, c99 or higher
 * which will
 * 1) reduce the use of global variables
 * 2) be more easier to do ptimization
 */
#if __STDC_VERSION__ >= 199901L
#define CGRAPH_LOOP(i, start, end)                                             \
  for (cgraph_size_t i = (start); (i) < (end); (i)++) {

#define CGRAPH_RLOOP(i, start, end)                                            \
  for (cgraph_size_t i = (start); (i) >= (end); (i)--) {

#define CGRAPH_LOOP_END }
#else
#define CGRAPH_LOOP(i, start, end)                                             \
  do {                                                                         \
    cgraph_size_t i;                                                           \
    for ((i) = (start); (i) < (end); (i)++) {

#define CGRAPH_RLOOP(i, start, end)                                            \
  do {                                                                         \
    cgraph_size_t i;                                                           \
    for ((i) = (start); (i) >= (end); (i)--) {

#define CGRAPH_LOOP_END                                                        \
  }                                                                            \
  }                                                                            \
  while (0)                                                                    \
    ;
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_PLATFORM_H__ */
