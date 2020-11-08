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

#if defined(_WIN32) || defined(_WIN64)

#define PLAT_MODE "windows"
#define PLAT_PSPLIT "\\"
#define PLAT_FEND "\r\n"

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




#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_PLATFORM_H_ */