#ifndef _CGRAPH_VERSION_H_
#define _CGRAPH_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifdef VERSION
#define CGRAPH_VERSION VERSION
#else
#define CGRAPH_VERSION "0.0.0"
#endif

extern void cgraph_version(cgraph_char_t **version, cgraph_int_t *major,
                           cgraph_int_t *minor, cgraph_int_t *subminor);
extern void cgraph_version_print(void);
extern void cgraph_version_fprintf(FILE *fp);

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_VERSION_H_ */
