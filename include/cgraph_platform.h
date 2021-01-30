#ifndef _CGRAPH_PLATFORM_H_
#define _CGRAPH_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
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
#define CGRAPH_PLAT_NAME   "cgywin"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_CYGWIN
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\n"
#elif (defined(_WIN32) || defined(_WIN64))
#define CGRAPH_PLAT_NAME   "windows"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_WINDOWS
#define CGRAPH_PLAT_PSPLIT "\\"
#define CGRAPH_PLAT_FEND   "\r\n"
#elif defined(__APPLE__)
#define CGRAPH_PLAT_NAME   "macos"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_MACOS
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\r"
#elif defined(__linux__)
#define CGRAPH_PLAT_NAME   "linux"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_LINUX
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\n"
#elif defined(__unix__)
#define CGRAPH_PLAT_NAME   "unix"
#define CGRAPH_PLAT_MODE   CGRAPH_PLAT_UNIX
#define CGRAPH_PLAT_PSPLIT "/"
#define CGRAPH_PLAT_FEND   "\n"
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
#define CGRAPH_INLINE              inline
#define __cgraph_int64             signed long long
#define __CGRAPH_INT64_MIN         (-9223372036854775808LL)
#define __CGRAPH_INT64_MAX         (9223372036854775807LL)
#define __CGRAPH_INT64_EPS         (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_INT64_OUT_FORMAT  "%lld"
#define __cgraph_uint64            unsigned long long
#define __CGRAPH_UINT64_MIN        (0LL)
#define __CGRAPH_UINT64_MAX        (1844674407370955161ULL)
#define __CGRAPH_UINT64_EPS        (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_UINT64_OUT_FORMAT "%llu"
#define CGRAPH_WITH_FLOAT128
#define __CGRAPH_FLOAT128     signed long double
#define __CGRAPH_FLOAT128_MIN LDBL_MIN
#define __CGRAPH_FLOAT128_MAX LDBL_MAX
#define __CGRAPH_FLOAT128_EPS LDBL_EPSILON
#define __CGRAPH_FLOAT128_BIT LDBL_DIG
#define __cgraph_vsnprintf(buffer, size, format, args)                         \
    vsnprintf(buffer, size, format, args)
#else
#if defined(__GNUC__) || defined(__clang__)
#define CGRAPH_INLINE       __extension__ __inline__
__extension__ typedef signed long long __cgraph_int64;
#define __CGRAPH_INT64_MIN  __extension__(-9223372036854775808LL)
#define __CGRAPH_INT64_MAX  __extension__(9223372036854775807LL)
#define __CGRAPH_INT64_EPS  __extension__(0xFFFFFFFFFFFFFFFFLL)
__extension__ typedef unsigned long long __cgraph_uint64;
#define __CGRAPH_UINT64_MIN __extension__(0LL)
#define __CGRAPH_UINT64_MAX __extension__(1844674407370955161ULL)
#define __CGRAPH_UINT64_EPS __extension__(0xFFFFFFFFFFFFFFFFLL)
#if CGRAPH_PLAT_MODE != CGRAPH_PLAT_WINDOWS
#define __CGRAPH_INT64_OUT_FORMAT  "%lld"
#define __CGRAPH_UINT64_OUT_FORMAT "%llu"
#else
#define __CGRAPH_INT64_OUT_FORMAT  "%I64d"
#define __CGRAPH_UINT64_OUT_FORMAT "%I64u"
#endif
#elif defined(_MSC_VER)
#define CGRAPH_INLINE              __inline
typedef signed __int64 __cgraph_int64;
#define __CGRAPH_INT64_MIN         (-9223372036854775808LL)
#define __CGRAPH_INT64_MAX         (9223372036854775807LL)
#define __CGRAPH_INT64_EPS         (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_INT64_OUT_FORMAT  "%I64d"
typedef unsigned __int64 __cgraph_uint64;
#define __CGRAPH_UINT64_MIN        (0LL)
#define __CGRAPH_UINT64_MAX        (1844674407370955161ULL)
#define __CGRAPH_UINT64_EPS        (0xFFFFFFFFFFFFFFFFLL)
#define __CGRAPH_UINT64_OUT_FORMAT "%I64u"
#else
#error unsupported C compiler in 32-bit system
#endif
#define __cgraph_vsnprintf(buffer, size, format, args)                         \
    vsprintf(buffer, format, args)
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
