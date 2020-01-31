#ifndef _CGRAPH_VERSION_H_
#define _CGRAPH_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define CGRAPH_VERSION "0.0.0"

cgraph_boolean_t cgraph_version(cgraph_char_t **version, cgraph_integer_t *major, cgraph_integer_t *minor, cgraph_integer_t *subminor);
void cgraph_version_print(void);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_VERSION_H_ */