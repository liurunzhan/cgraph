#ifndef _CGRAPH_VERSION_H_
#define _CGRAPH_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_VERSION "0.0.0"

extern void cgraph_version(const cgraph_char_t **version, cgraph_int_t *major, cgraph_int_t *minor, cgraph_int_t *subminor);
extern void cgraph_version_print(void);
extern void cgraph_version_fprintf(void *fp);

/* test function in DEBUG mode and do not use in RELEASE mode */
extern void cgraph_version_test(void);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_VERSION_H_ */
