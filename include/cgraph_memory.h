#ifndef _CGRAPH_MEMORY_H_
#define _CGRAPH_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/***************************** memory management ******************************/
void *cgraph_calloc(const cgraph_size_t len, const cgraph_size_t data_size);
void *cgraph_realloc(void *cthis, const cgraph_size_t old_len, const cgraph_size_t new_len, const cgraph_size_t data_size, cgraph_boolean_t *error);
void *cgraph_memcpy(void *new_cthis, const void *cthis, const cgraph_size_t len, const cgraph_size_t data_size);
void cgraph_free(void *cthis);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MEMORY_H_ */