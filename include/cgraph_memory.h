/**
 * @file cgraph_memory.h
 * @brief the apis of memory management
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_MEMORY_H__
#define __CGRAPH_MEMORY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/***************************** memory management
 * ******************************/
extern void *cgraph_calloc(const cgraph_size_t size);
extern void *cgraph_realloc(void *cthis, const cgraph_size_t old_size,
                            const cgraph_size_t new_size, cgraph_bool_t *error);
extern void *cgraph_memset(void *cthis, cgraph_size_t size, cgraph_uint_t data);
extern void *cgraph_memcpy(void *object, const void *cthis,
                           const cgraph_size_t size);
extern void *cgraph_memscpy(void *object, const cgraph_size_t size,
                            const cgraph_size_t old_len, const void *cthis,
                            const cgraph_size_t new_len);
extern cgraph_char_t *cgraph_strcpy(cgraph_char_t *object,
                                    const cgraph_char_t *cthis);
extern cgraph_char_t *cgraph_strncpy(cgraph_char_t *object,
                                     const cgraph_char_t *cthis,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strscpy(cgraph_char_t *object,
                                     const cgraph_size_t size,
                                     const cgraph_char_t *cthis);
extern cgraph_char_t *cgraph_strcat(cgraph_char_t *object,
                                    const cgraph_char_t *cthis);
extern cgraph_char_t *cgraph_strncat(cgraph_char_t *object,
                                     const cgraph_char_t *cthis,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strscat(cgraph_char_t *object,
                                     const cgraph_size_t size,
                                     const cgraph_char_t *cthis);
extern void cgraph_free(void *cthis);
extern cgraph_bool_t cgraph_memcmp(const void *x, const void *y,
                                   const cgraph_size_t size);
extern cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x,
                                   const cgraph_char_t *y);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MEMORY_H__ */
