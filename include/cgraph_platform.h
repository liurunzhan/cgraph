/**
 * @file cgraph_platform.h
 * @brief the configuration in different platforms and compilers
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
#elif (defined(_WIN32) || defined(_WIN64)) || defined(WINVER)
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
#if defined(__linux) || defined(__linux__)
#define __PLAT_NAME "linux"
#define __PLAT_MODE CGRAPH_PLAT_LINUX
#elif defined(__unix) || defined(__unix__) || defined(unix)
#define __PLAT_NAME "unix"
#define __PLAT_MODE CGRAPH_PLAT_UNIX
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#define __PLAT_NAME "bsd"
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
#define __PLAT_ENDIAN_LITTLE (0)
#define __PLAT_ENDIAN_BIG (1)
#define __PLAT_ENDIAN_NONE (2)
#if defined(__LITTLE_ENDIAN__) || defined(__LITTLE_ENDIAN) ||                  \
    defined(__WORDS_LITTLEENDIAN)
/** Little-endian architecture */
#define __PLAT_ENDIAN __PLAT_ENDIAN_LITTLE
#elif defined(__BIG_ENDIAN__) || defined(__BIG_ENDIAN) ||                      \
    defined(__WORDS_BIGENDIAN)
/** Big-Endian architecture */
#define __PLAT_ENDIAN __PLAT_ENDIAN_BIG
#else
/** Undefined architecture */
#define __PLAT_ENDIAN __PLAT_ENDIAN_NONE
#endif

#if (__PLAT_ENDIAN < __PLAT_ENDIAN_LITTLE) ||                                  \
    (__PLAT_ENDIAN > __PLAT_ENDIAN_NONE)
#error __PLAT_ENDIAN must be defined as one of <__PLAT_ENDIAN_LITTLE(0), __PLAT_ENDIAN_BIG(1) or __PLAT_ENDIAN_NONE(2)>
#endif

#ifndef __WORDSIZE
#if defined(_WIN64) || defined(__CYGWIN64__) || defined(_M_X64) ||             \
    defined(_M_AMD64) || defined(_M_IA64) || defined(_M_IX64) ||               \
    defined(__x86_64__) || defined(__x86_64) || defined(__aarch64__) ||        \
    defined(__ARM_64BIT_STATE)
#define __WORDSIZE (64)
#elif defined(_WIN32) || defined(__CYGWIN32__) || defined(_M_IX86) ||          \
    defined(I386) || defined(I386__) || defined(I486__) || defined(I686__) ||  \
    defined(__ARM_32BIT_STATE)
#define __WORDSIZE (32)
#else
#define __WORDSIZE (32)
#endif
#endif

#if !defined(__WORDSIZE)
#error __WORDSIZE must be defined in this library
#elif (__WORDSIZE != 32) && (__WORDSIZE != 64)
#error __WORDSIZE must be defined as one of <32, 64>
#endif

#if __WORDSIZE == 64
#define __WORDSIZE_LOG2 (6)
#else
#define __WORDSIZE_LOG2 (5)
#endif

/** C Standard */
#ifndef __STDC__
#error Only "Standard C" is suppoted!!
#endif

#ifndef __STDC_VERSION__
#define __STDC_VERSION__ (198901L)
#endif

#ifndef __STDC_VERSION__
#error __STDC_VERSION__ must be defined in this library
#endif

#if defined(__GNUC__) || defined(__clang__)
/** a macro value defined to judge the features of gnuc more than stdc */
#ifndef __GNUC_MTSTDC
#define __GNUC_MTSTDC
#endif
#endif

/** Self-defined features in different compilers */
/** @{ */
/**
 * extension features to cross C standards with compilers, such as integer
 * definitions with different cpu bits in C89 environment, only defined and used
 * in this header file
 */
#ifndef __EXTENSION__
#if __STDC_VERSION__ >= 199901L
#define __EXTENSION__
#elif defined(__MINGW_EXTENSION)
/** for mingw gcc/clang compilers */
#define __EXTENSION__ __MINGW_EXTENSION
#elif defined(__GNUC_MTSTDC)
/** for gcc/clang Compilers */
#define __EXTENSION__ __extension__
#else
#define __EXTENSION__
#endif
#endif

#ifndef __EXTENSION__
#error __EXTENSION__ must be defined in this library even if empty
#endif
/** @} */

/** inline function definitions to cross compilers */
/** @{ */
#ifndef __INLINE__
#if __STDC_VERSION__ >= 199901L
#define __INLINE__ inline
#elif defined(__GNUC_MTSTDC)
/** GNU C Compiler or Clang C Compiler */
#define __INLINE__ __EXTENSION__ __inline__
#elif defined(_MSC_VER)
/** Microsoft C Compiler */
#define __INLINE__ _inline
#elif defined(INTEL_COMPILER) || defined(__DMC__) || defined(__WATCOMC__) ||   \
    defined(ICCARM__) || defined(__TASKING__)
/**
 * Macro value defined in different compilers:
 * | Compiler | Macro | keyword |
 * | :-: | :-: | :-: |
 * | Intel C | INTEL_COMPILER | inline |
 * | Digital Mars C | __DMC__ | inline |
 * | Watcom C | __WATCOMC__ | inline |
 * | IAR C | ICCARM__ | inline |
 * | TASKING C | __TASKING__ | inline |
 */
#define __INLINE__ inline
#elif defined(__CC_ARM)
/** ARM C Compiler */
#define __INLINE__ Inline
#elif defined(__inline)
#define __INLINE__ __inline
#elif defined(__inline__)
#define __INLINE__ __inline__
#else
#define __INLINE__
#endif
#endif

#ifndef __INLINE__
#error __INLINE__ must be defined in this library even if it is empty
#endif
/** @} */

/** int types in different platforms */
#if __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#include <stdint.h>
#elif defined(HAVE_CONFIG_H)
#include "cgraph_stdint.h"
#else
#include <limits.h>
#include <stddef.h>
#endif

/** */
/** @{ */
#ifndef INT8_C
#define INT8_C(x) (x)
#define UINT8_C(x) (x##U)
#endif

#ifndef INT16_C
#define INT16_C(x) (x)
#define UINT16_C(x) (x##U)
#endif

#ifndef INT32_C
#define INT32_C(x) (x)
#define UINT32_C(x) (x##U)
#endif

#ifndef INT_C
#define INT_C(x) (x)
#define UINT_C(x) (x##U)
#endif
/** @} */

#ifndef INT8_MAX
typedef signed char int8_t;
#define INT8_MAX INT8_C(127)
#define INT8_MIN INT8_C(-128)
typedef unsigned char uint8_t;
#define UINT8_MAX UINT8_C(255)
#endif
#define UINT8_MIN UINT8_C(0)

#ifndef INT16_MAX
typedef signed short int16_t;
#define INT16_MAX INT16_C(32767)
#define INT16_MIN INT16_C(-32768)
typedef unsigned short uint16_t;
#define UINT16_MAX UINT8_C(65535)
#endif
#define UINT16_MIN UINT8_C(0)

#ifndef INT32_MAX
typedef signed int int32_t;
#define INT32_MAX INT32_C(2147483647)
#define INT32_MIN INT32_C(-2147483648)
typedef unsigned int uint32_t;
#define UINT32_MAX UINT32_C(4294967295)
#endif
#define UINT32_MIN UINT32_C(0)

/** */
/** @{ */
#define INT8_MASK INT8_MIN
#define INT8_MASK1 UINT8_C(0xAA)
#define INT8_MASK2 UINT8_C(0xCC)
#define INT8_MASK4 UINT8_C(0xF0)
#define INT8_EPSILON INT8_C(1)
#define INT8_BITS (8)
#define INT8_L2BITS (3)
#define INT8_LSB UINT8_C(0x01)
#define INT8_MSB (INT8_LSB << (INT8_BITS - 1))

#define UINT8_MASK UINT8_MAX
#define UINT8_MASK1 UINT8_C(0xAA)
#define UINT8_MASK2 UINT8_C(0xCC)
#define UINT8_MASK4 UINT8_C(0xF0)
#define UINT8_EPSILON UINT8_C(1)
#define UINT8_BITS INT8_BITS
#define UINT8_L2BITS INT8_L2BITS
#define UINT8_LSB UINT8_C(0x01)
#define UINT8_MSB (UINT8_LSB << (UINT8_BITS - 1))

#define INT16_MASK INT16_MIN
#define INT16_MASK1 UINT16_C(0xAAAA)
#define INT16_MASK2 UINT16_C(0xCCCC)
#define INT16_MASK4 UINT16_C(0xF0F0)
#define INT16_MASK8 UINT16_C(0xFF00)
#define INT16_EPSILON INT16_C(1)
#define INT16_BITS (16)
#define INT16_L2BITS (4)
#define INT16_LSB UINT16_C(0x01)
#define INT16_MSB (INT16_LSB << (INT16_BITS - 1))

#define UINT16_MASK UINT16_MAX
#define UINT16_MASK1 UINT16_C(0xAAAA)
#define UINT16_MASK2 UINT16_C(0xCCCC)
#define UINT16_MASK4 UINT16_C(0xF0F0)
#define UINT16_MASK8 UINT16_C(0xFF00)
#define UINT16_EPSILON UINT16_C(1)
#define UINT16_BITS INT16_BITS
#define UINT16_L2BITS INT16_L2BITS
#define UINT16_LSB UINT16_C(0x01)
#define UINT16_MSB (UINT16_LSB << (UINT16_BITS - 1))

#define INT32_MASK INT32_MIN
#define INT32_MASK1 UINT32_C(0xAAAAAAAA)
#define INT32_MASK2 UINT32_C(0xCCCCCCCC)
#define INT32_MASK4 UINT32_C(0xF0F0F0F0)
#define INT32_MASK8 UINT32_C(0xFF00FF00)
#define INT32_MASK16 UINT32_C(0xFFFF0000)
#define INT32_EPSILON INT32_C(1)
#define INT32_BITS (32)
#define INT32_L2BITS (5)
#define INT32_LSB UINT32_C(0x01)
#define INT32_MSB (INT32_LSB << (INT32_BITS - 1))

#define UINT32_MASK UINT32_MAX
#define UINT32_MASK1 UINT32_C(0xAAAAAAAA)
#define UINT32_MASK2 UINT32_C(0xCCCCCCCC)
#define UINT32_MASK4 UINT32_C(0xF0F0F0F0)
#define UINT32_MASK8 UINT32_C(0xFF00FF00)
#define UINT32_MASK16 UINT32_C(0xFFFF0000)
#define UINT32_EPSILON UINT32_C(1)
#define UINT32_BITS INT32_BITS
#define UINT32_L2BITS INT32_L2BITS
#define UINT32_LSB UINT32_C(0x01)
#define UINT32_MSB (UINT32_LSB << (UINT32_BITS - 1))

#define INT_MASK INT_MIN
#define INT_MASK1 UINT_C(0xAAAAAAAA)
#define INT_MASK2 UINT_C(0xCCCCCCCC)
#define INT_MASK4 UINT_C(0xF0F0F0F0)
#define INT_MASK8 UINT_C(0xFF00FF00)
#define INT_MASK16 UINT_C(0xFFFF0000)
#define INT_EPSILON UINT_C(1)
#define INT_BITS (32)
#define INT_L2BITS (5)
#define INT_LSB UINT_C(0x01)
#define INT_MSB (INT_LSB << (INT_BITS - 1))

#define UINT_MASK UINT_MAX
#define UINT_MASK1 UINT_C(0xAAAAAAAA)
#define UINT_MASK2 UINT_C(0xCCCCCCCC)
#define UINT_MASK4 UINT_C(0xF0F0F0F0)
#define UINT_MASK8 UINT_C(0xFF00FF00)
#define UINT_MASK16 UINT_C(0xFFFF0000)
#define UINT_EPSILON UINT_C(1)
#define UINT_BITS INT_BITS
#define UINT_L2BITS INT_L2BITS
#define UINT_LSB UINT_C(0x01)
#define UINT_MSB (UINT_LSB << (UINT_BITS - 1))
/** @} */

/** */
/** @{ */
#ifndef SCNd8
#define SCNd8 "d"
#define PRId8 "d"

#define SCNu8 "u"
#define PRIu8 "u"
#endif

#ifndef SCNd16
#define SCNd16 "d"
#define PRId16 "d"

#define SCNu16 "u"
#define PRIu16 "u"
#endif

#ifndef SCNd32
#define SCNd32 "d"
#define PRId32 "d"

#define SCNu32 "u"
#define PRIu32 "u"
#endif
/** @} */

/** */
/** @{ */
#ifndef SCNptr
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
#endif
/** @} */

#if (__STDC_VERSION__ < 199901L)
/** if TYPE long supports 64-bit or bigger */
#if defined(ULONG_MAX) && ((ULONG_MAX >> 31 >> 31) >= 3)
typedef signed long int64_t;
typedef unsigned long uint64_t;

#ifndef INT64_C
#define INT64_C(x) (x##L)
#define UINT64_C(x) (x##UL)
#endif
#elif defined(_MSC_VER) || defined(__int64) ||                                 \
    (defined(__PLAT_WINDOWS) && defined(__GNUC_MTSTDC))
/** if used in VC/VC++ Compilers or GCC/Clang in Windows Platform */
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;

#ifndef INT64_C
#define INT64_C(x) __EXTENSION__((int64_t)x)
#define UINT64_C(x) __EXTENSION__((uint64_t)x)
#endif
/** TYPE long long int is defined as int64_t */
#else
__EXTENSION__ typedef signed long long int64_t;
__EXTENSION__ typedef unsigned long long uint64_t;

#ifndef INT64_C
#define INT64_C(x) __EXTENSION__(x##LL)
#define UINT64_C(x) __EXTENSION__(x##ULL)
#endif
#endif
#endif

#define INT64_LSB UINT64_C(0x01)
#define INT64_MSB (INT64_LSB << (INT64_BITS - 1))
#define UINT64_LSB UINT64_C(0x01)
#define UINT64_MSB (UINT64_LSB << (UINT64_BITS - 1))

/** */
/** @{ */
#ifndef INT64_MAX
#define INT64_MAX INT64_C(9223372036854775807)
#define INT64_MIN INT64_C(-9223372036854775808)
#define UINT64_MAX UINT64_C(18446744073709551615)
#endif
#define UINT64_MIN UINT64_C(0)

#define INT64_BITS (64)
#define INT64_L2BITS (6)
#define INT64_MASK INT64_MIN
#define INT64_MASK1 UINT64_C(0xAAAAAAAAAAAAAAAA)
#define INT64_MASK2 UINT64_C(0xCCCCCCCCCCCCCCCC)
#define INT64_MASK4 UINT64_C(0xF0F0F0F0F0F0F0F0)
#define INT64_MASK8 UINT64_C(0xFF00FF00FF00FF00)
#define INT64_MASK16 UINT64_C(0xFFFF0000FFFF0000)
#define INT64_MASK32 UINT64_C(0xFFFFFFFF00000000)
#define INT64_MASK64 UINT64_C(0xFFFFFFFFFFFFFFFF)
#define INT64_EPSILON INT64_C(1)

#define UINT64_BITS INT64_BITS
#define UINT64_L2BITS INT64_L2BITS
#define UINT64_MASK UINT64_MAX
#define UINT64_MASK1 UINT64_C(0xAAAAAAAAAAAAAAAA)
#define UINT64_MASK2 UINT64_C(0xCCCCCCCCCCCCCCCC)
#define UINT64_MASK4 UINT64_C(0xF0F0F0F0F0F0F0F0)
#define UINT64_MASK8 UINT64_C(0xFF00FF00FF00FF00)
#define UINT64_MASK16 UINT64_C(0xFFFF0000FFFF0000)
#define UINT64_MASK32 UINT64_C(0xFFFFFFFF00000000)
#define UINT64_MASK64 UINT64_C(0xFFFFFFFFFFFFFFFF)
#define UINT64_EPSILON UINT64_C(1)
/** @} */

/** integer type input and output style */
/** @{ */
#ifndef SCNd64
#if defined(_MSC_VER) || defined(__int64) ||                                   \
    (defined(__PLAT_WINDOWS) && defined(__GNUC_MTSTDC))
/** if used in VC/VC++ Compilers or GCC/Clang in Windows Platform */
#define SCNd64 "I64d"
#define PRId64 "I64d"
#define SCNu64 "I64u"
#define PRIu64 "I64u"
#elif defined(ULONG_MAX) && ((ULONG_MAX >> 31 >> 31) >= 3)
/** if TYPE long supports 64-bit or bigger */
#define SCNd64 "ld"
#define PRId64 "ld"
#define SCNu64 "lu"
#define PRIu64 "lu"
#else
/** TYPE long long int is defined as int64_t */
#define SCNd64 "lld"
#define PRId64 "lld"
#define SCNu64 "llu"
#define PRIu64 "llu"
#endif
#endif
/** @} */

#ifndef LONG_C
#define LONG_C(x) (x##L)
#define ULONG_C(x) (x##UL)
#endif

#define SIZE_C(x) LONG_C(x)
#define USIZE_C(x) ULONG_C(x)

/** */
/** @{ */
#if __WORDSIZE == 64
#define LONG_MASK UINT64_MAX
#define LONG_MASK1 UINT64_MASK1
#define LONG_MASK2 UINT64_MASK2
#define LONG_MASK4 UINT64_MASK4
#define LONG_MASK8 UINT64_MASK8
#define LONG_MASK16 UINT64_MASK16
#define LONG_MASK32 UINT64_MASK32
#define LONG_BITS UINT64_BITS
#define LONG_L2BITS UINT64_L2BITS

#define ULONG_MASK UINT64_MAX
#define ULONG_MASK1 UINT64_MASK1
#define ULONG_MASK2 UINT64_MASK2
#define ULONG_MASK4 UINT64_MASK4
#define ULONG_MASK8 UINT64_MASK8
#define ULONG_MASK16 UINT64_MASK16
#define ULONG_MASK32 UINT64_MASK32
#define ULONG_BITS UINT64_BITS
#define ULONG_L2BITS UINT64_L2BITS
#elif __WORDSIZE == 32
#define LONG_MASK UINT32_MAX
#define LONG_MASK1 ULONG_C(0xAAAAAAAA)
#define LONG_MASK2 ULONG_C(0xCCCCCCCC)
#define LONG_MASK4 ULONG_C(0xF0F0F0F0)
#define LONG_MASK8 ULONG_C(0xFF00FF00)
#define LONG_MASK16 ULONG_C(0xFFFF0000)
#define LONG_MASK32 ULONG_C(0xFFFFFFFF)
#define LONG_BITS UINT32_BITS
#define LONG_L2BITS INT32_L2BITS

#define ULONG_MASK UINT32_MAX
#define ULONG_MASK1 ULONG_C(0xAAAAAAAA)
#define ULONG_MASK2 ULONG_C(0xCCCCCCCC)
#define ULONG_MASK4 ULONG_C(0xF0F0F0F0)
#define ULONG_MASK8 ULONG_C(0xFF00FF00)
#define ULONG_MASK16 ULONG_C(0xFFFF0000)
#define ULONG_MASK32 ULONG_C(0xFFFFFFFF)
#define ULONG_BITS UINT32_BITS
#define ULONG_L2BITS UINT32_L2BITS
#endif

#define LONG_LSB ULONG_C(0x01)
#define LONG_MSB (LONG_LSB << (LONG_BITS - 1))
#define ULONG_LSB ULONG_C(0x01)
#define ULONG_MSB (ULONG_LSB << (ULONG_BITS - 1))

#define SCNdl "ld"
#define PRIdl "ld"
#define SCNul "lu"
#define PRIul "lu"

/** @} */

/**< 128-bit float number details */
#if __STDC_VERSION__ >= 199901L && defined(__SIZEOF_INT128__)
#define __WITH_INT128_SIZE128
typedef int64_t int128_t;
#define INT128_MIN (-1)
#define INT128_MAX (0)
#define INT128_MASK INT64_MASK
#define INT128_EPSILON (1)
#define INT128_BITS (128)
#define INT128_L2BITS (7)
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
#define UINT128_BITS UINT64_BITS
#define UINT128_L2BITS (7)
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
#define INT128_BITS (64)
#define INT128_L2BITS INT64_L2BITS
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
#define UINT128_BITS (64)
#define UINT128_L2BITS UINT64_L2BITS
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

/**
 * 8-bit float point number
 * sign bit 1
 * exp bit 3 (bias=5)
 * fra bit 4
 * value(sign, exp, bias, fra) = sign * fra * 2^(exp + bias)
 */
/** @{ */
#define FLT8_BITS (8)
#define FLT8_EPSILON UINT8_C(0x10)
#define FLT8_DIG UINT8_EPSILON
#define FLT8_MASK UINT8_MASK
#define FLT8_EXP_DIG (3)
#define FLT8_EXP_BIAS (0)
#define FLT8_EXP_BITS FLT8_EXP_DIG
#define FLT8_EXP_MASK UINT8_C(0x07)
#define FLT8_EXP_OFFSET (0)
#define FLT8_FRAC_DIG (4)
#define FLT8_FRAC_BIAS FLT8_EXP_BITS
#define FLT8_FRAC_BITS FLT8_FRAC_DIG
#define FLT8_FRAC_MASK UINT8_C(0x0F)
#define FLT8_FRAC_OFFSET (0)
#define FLT8_SIG_DIG (0)
#define FLT8_SIG_BITS (1)
#define FLT8_SIG_MASK (0)

typedef union {
  struct {
    uint32_t sig : FLT8_SIG_BITS;
    uint32_t exp : FLT8_EXP_BITS;
    uint32_t frac : FLT8_FRAC_BITS;
  } sfloat;
  uint32_t data : FLT8_BITS;
} cgraph_sfloat8_t;

#define FLT8_MIN UINT8_C(0xEF)
#define FLT8_MAX UINT8_C(0x6F)
#define FLT8_NAN UINT8_C(0x7F)
#define FLT8_INF UINT8_C(0x70)
#define FLT8_PINF FLT8_INF
#define FLT8_NINF UINT8_C(0xF0)
/** @} */

/**
 * 16-bit float point number
 * sign bit 1
 * exp bit 5 (bias=15)
 * fra bit 10
 * value(sign, exp, bias, fra) = sign * fra * 2^(exp + bias)
 */
/** @{ */
#define FLT16_BITS (16)
#define FLT16_EPSILON UINT16_C(0x0100)
#define FLT16_DIG (0)
#define FLT16_MASK UINT16_MASK
#define FLT16_EXP_DIG (5)
#define FLT16_EXP_BIAS (0)
#define FLT16_EXP_BITS FLT16_EXP_DIG
#define FLT16_EXP_MASK UINT16_C(0x1F)
#define FLT16_EXP_OFFSET (0)
#define FLT16_FRAC_DIG (10)
#define FLT16_FRAC_BIAS (0)
#define FLT16_FRAC_BITS FLT16_FRAC_DIG
#define FLT16_FRAC_MASK UINT16_C(0x3FF)
#define FLT16_FRAC_OFFSET (0)
#define FLT16_SIG_DIG (0)
#define FLT16_SIG_BITS (1)
#define FLT16_SIG_MASK UINT16_C(0)

typedef union {
  struct {
    uint32_t sig : FLT16_SIG_BITS;
    uint32_t exp : FLT16_EXP_BITS;
    uint32_t frac : FLT16_FRAC_BITS;
  } sfloat;
  uint32_t data : FLT16_BITS;
} cgraph_sfloat16_t;

#define FLT16_MIN UINT16_C(0xFEFF)
#define FLT16_MAX UINT16_C(0x7EFF)
#define FLT16_NAN UINT16_C(0x7FFF)
#define FLT16_INF UINT16_C(0x7C00)
#define FLT16_PINF FLT16_INF
#define FLT16_NINF UINT16_C(0xFC00)
/** @} */

/** 32-bit float point number */
/** @{ */
#define FLT_C(x) (x##F)
#define FLT_NAN (FLT_C(0.0) / FLT_C(0.0))
#define FLT_INF (FLT_C(1.0) / FLT_C(0.0))
#define FLT_PINF FLT_INF
#define FLT_NINF (FLT_C(-1.0) / FLT_C(0.0))
/** @} */

/** 64-bit float point number */
/** @{ */
#define DBL_C(x) (x)
#define DBL_NAN (DBL_C(0.0) / DBL_C(0.0))
#define DBL_INF (DBL_C(1.0) / DBL_C(0.0))
#define DBL_PINF FLT_INF
#define DBL_NINF (DBL_C(-1.0) / DBL_C(0.0))
/** @} */

/**< 128-bit float number */
/** @{ */
#if __STDC_VERSION__ >= 199901L || defined(__HAVE_LONG_DOUBLE)
#define LDBL_C(x) __EXTENSION__(x##L)
#define FLT128_C(x) LDBL_C(x)
#define FLT128_ZERO FLT128_C(0.0)
#define FLT128_ONE FLT128_C(1.0)
#define __WITH_FLOAT128_SIZE128
#define FLT128 long double
#define FLT128_MIN LDBL_MIN
#define FLT128_MAX LDBL_MAX
#define FLT128_EPSILON UINT128_MASK
#define FLT128_DIG LDBL_DIG
#define FLT128_BITS (8 * sizeof(FLT128))
#define FLT128_IN_FMT "Lg"
#define FLT128_OUT_FMT "Lg"
#define FLT128_HASH_OFFSET (12)
#define FLT128_FRA_BITS (15)
#define FLT128_FRA_OFFSET (0)
#define FLT128_FRA_EPSILON (0x7FFF)
#define FLT128_EXP_BITS (64)
#define FLT128_EXP_OFFSET FLT128_FRA_BITS
#define FLT128_EXP_MASK UINT64_MASK
#else
#define __WITH_FLOAT128_SIZE64
#define LDBL_C(x) __EXTENSION__(x)
#define FLT128_C(x) LDBL_C(x)
#define FLT128_ZERO FLT128_C(0.0)
#define FLT128_ONE FLT128_C(1.0)
#define FLT128 double
#define FLT128_MIN DBL_MIN
#define FLT128_MAX DBL_MAX
#define FLT128_EPSILON DBL_EPSILON
#define FLT128_DIG DBL_DIG
#define FLT128_BITS (8 * sizeof(FLT128))
#define FLT128_IN_FMT "g"
#define FLT128_OUT_FMT "g"
#define FLT128_HASH_OFFSET (8)
#define FLT128_FRA_BITS (11)
#define FLT128_FRA_OFFSET (0)
#define FLT128_FRA_EPSILON (0x7FFFU)
#define FLT128_EXP_BITS (52)
#define FLT128_EXP_OFFSET FLT128_FRA_BITS
#define FLT128_EXP_MASK UINT64_C(0xFFFFFFFFFFFFF)
#endif
#define FLT128_NAN (FLT128_ZERO / FLT128_ZERO)
#define FLT128_INF (FLT128_ONE / FLT128_ZERO)
#define FLT128_PINF (FLT128_ONE / FLT128_ZERO)
#define FLT128_NINF (-FLT128_ONE / FLT128_ZERO)
/** @} */

#if (__STDC_VERSION__ >= 201112L) || defined(__GNUC_MTSTDC)
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
#elif defined(__FUNC__)
#define __FUNCTION__ __FUNC__
#else
#define __FUNCTION__ NULL
#endif
#endif

/**
 * @details the moemory size to allocate objects
 */
/** @{ */
#if __STDC_VERSION__ >= 199901L
#define __TYPE_PTRSIZE (1)
#else
#define __TYPE_PTRSIZE (2)
#endif

/** @} */

/**
 * A simple way to use for-loop block locally, in C89/C90, C99, C11 or higher,
 * which will
 * 1) limit the variable scope, and reduce variable misusage
 * 2) avoid the location limitation of variable declearation in C89/C90.
 * 3) be more easier to do optimization
 */
#if __STDC_VERSION__ >= 199901L
#define CGRAPH_BEGIN {
#define CGRAPH_END }

#define CGRAPH_LOOP(itr, start, end)                                           \
  for (cgraph_size_t itr = (start); (itr) < (end); (itr)++) {
#define CGRAPH_RLOOP(itr, start, end)                                          \
  for (cgraph_size_t itr = (start); (itr) > (end); (itr)--) {
#define CGRAPH_LOOP_END }
#else
#define CGRAPH_BEGIN do {
#define CGRAPH_END                                                             \
  }                                                                            \
  while (0)                                                                    \
    ;

#define CGRAPH_LOOP(itr, start, end)                                           \
  do {                                                                         \
    cgraph_size_t itr;                                                         \
    for ((itr) = (start); (itr) < (end); (itr)++) {

#define CGRAPH_RLOOP(itr, start, end)                                          \
  do {                                                                         \
    cgraph_size_t itr;                                                         \
    for ((itr) = (start); (itr) > (end); (itr)--) {

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
