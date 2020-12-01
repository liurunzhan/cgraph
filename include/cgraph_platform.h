#ifndef _CGRAPH_PLATFORM_H_
#define _CGRAPH_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif

/* supported platform types */
#if (defined(_WIN32) || defined(_WIN64))
  #if defined(__CYGWIN__)
    #define CGRAPH_PLAT_MODE "cygwin/msys/msys2"
    #define CGRAPH_PLAT_PSPLIT "/"
    #define CGRAPH_PLAT_FEND "\n"
  #else
    #define CGRAPH_PLAT_MODE "windows"
    #define CGRAPH_PLAT_PSPLIT "\\"
    #define CGRAPH_PLAT_FEND "\r\n"
  #endif
#elif defined(__APPLE__)
  #define CGRAPH_PLAT_MODE "macos"
  #define CGRAPH_PLAT_PSPLIT "/"
  #define CGRAPH_PLAT_FEND "\r"
#elif defined(__linux__)
  #define CGRAPH_PLAT_MODE "linux"
  #define CGRAPH_PLAT_PSPLIT "/"
  #define CGRAPH_PLAT_FEND "\n"
#elif defined(__unix__)
  #define CGRAPH_PLAT_MODE "unix"
  #define CGRAPH_PLAT_PSPLIT "/"
  #define CGRAPH_PLAT_FEND "\n"
#else
 #error unsupported platforms!!
#endif

#if defined(__LITTLE_ENDIAN__)
  #define CGRAPH_PLAT_ENDIAN 0
#elif defined(__BIG_ENDIAN__)
  #define CGRAPH_PLAT_ENDIAN 1
#else
  #define CGRAPH_PLAT_ENDIAN 2
#endif

#if (__WORDSIZE == 64) || defined(_WIN64) || defined(_M_X64) || defined(__x86_64__)
  #define CGRAPH_WORDSIZE 64
#elif (__WORDSIZE == 32) || defined(_WIN32) || defined(_M_IX86) || defined(__i386__)
  #define CGRAPH_WORDSIZE 32
#else
  #error only 32-bit and 64-bit system are supported!!
#endif

#if defined(__STDC__)
  #if defined(__STDC_VERSION__)
    #define CGRAPH_STDC_VERSION __STDC_VERSION__
  #else
    #define CGRAPH_STDC_VERSION 1989L
  #endif
#else
  #error only standard c is suppoted!!
#endif

#if CGRAPH_STDC_VERSION >= 199901L
  #define CGRAPH_INLINE inline
#else
  #define CGRAPH_INLINE
#endif

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_PLATFORM_H_ */