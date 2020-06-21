#ifndef _CGRAPH_MEMORY_H_
#define _CGRAPH_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/***************************** memory management ******************************/
extern void *cgraph_calloc(const cgraph_size_t len, const cgraph_size_t data_size);
extern void *cgraph_realloc(void *cthis, const cgraph_size_t old_len, const cgraph_size_t new_len, const cgraph_size_t data_size, cgraph_boolean_t *error);
extern void *cgraph_memcpy(void *new_cthis, const void *cthis, const cgraph_size_t len, const cgraph_size_t data_size);
extern void *cgraph_strcpy(void *object, const void *cthis);
extern void cgraph_free(void *cthis);
extern cgraph_boolean_t cgraph_memcmp(const void *x, const void *y, const cgraph_size_t len, const cgraph_size_t data_size);
extern cgraph_boolean_t cgraph_strcmp(const char *x, const char *y);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MEMORY_H_ */
