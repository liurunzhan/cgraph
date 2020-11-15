#ifndef _CGRAPH_PLATFORM_H_
#define _CGRAPH_PLATFORM_H_

#ifdef __cplusplus
extern "C" {
#endif


#ifdef PLAT_MODE 
  #undef PLAT_MODE
#endif

#ifdef PLAT_PSPLIT
  #undef PLAT_PSPLIT
#endif

#ifdef PLAT_FEND
  #undef PLAT_FEND
#endif

#ifdef PLAT_BITS
  #undef PLAT_BITS
#endif

#ifdef PLAT_ENDIAN
  #undef PLAT_ENDIAN
#endif

/* supported platform types */
#if (defined(_WIN32) || defined(_WIN64))
  #if defined(__CYGWIN__)
    #define PLAT_MODE "cygwin/msys/msys2"
    #define PLAT_PSPLIT "/"
    #define PLAT_FEND "\n"
  #else
    #define PLAT_MODE "windows"
    #define PLAT_PSPLIT "\\"
    #define PLAT_FEND "\r\n"
  #endif
#elif defined(__APPLE__)
  #define PLAT_MODE "macos"
  #define PLAT_PSPLIT "/"
  #define PLAT_FEND "\r"
#elif defined(__linux__)
  #define PLAT_MODE "linux"
  #define PLAT_PSPLIT "/"
  #define PLAT_FEND "\n"
#elif defined(__unix__)
  #define PLAT_MODE "unix"
  #define PLAT_PSPLIT "/"
  #define PLAT_FEND "\n"
#else
 #error unsupported platforms!!
#endif

/* supported cpu bits */
#if defined(_WIN64)
  #define PLAT_BITS 64
#elif defined(_WIN32)
  #define PLAT_BITS 32
#elif defined(_M_IX86) || defined(__i386__)
  #define PLAT_BITS 32
#elif defined(_M_X64) || defined(__x86_64__)
  #define PLAT_BITS 64
#else
  #error only supported 32-bit or 64-bit cpu
#endif

#if defined(__LITTLE_ENDIAN__)
  #define PLAT_ENDIAN 0
#elif defined(__BIG_ENDIAN__)
  #define PLAT_ENDIAN 1
#else
  #define PLAT_ENDIAN 2
  #if defined(__GNUC__)
    #warning no endian type is defined!
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_PLATFORM_H_ */