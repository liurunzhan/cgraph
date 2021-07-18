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

/*
 * memory management functions:
 * except for cgraph_calloc and cgraph_realloc, the operated memory length can
 * be a postive or negative number, where
 * a postive number means forward operation
 * a negative number means reverse operation
 */
extern void *cgraph_calloc(const cgraph_size_t size);
extern void *cgraph_realloc(void *cthis, const cgraph_size_t old_size,
                            const cgraph_size_t new_size, cgraph_bool_t *error);
extern void *cgraph_memset(void *cthis, cgraph_uint_t data, cgraph_size_t size);
extern void *cgraph_memcpy(void *object, const void *cthis,
                           const cgraph_size_t size);
extern void *cgraph_memscpy(void *object, const cgraph_size_t size,
                            const void *cthis, const cgraph_size_t len);
extern cgraph_bool_t cgraph_memcmp(const void *x, const void *y,
                                   const cgraph_size_t size);
extern void cgraph_free(void *cthis);

/*
 * c-type string management functions
 */
extern cgraph_size_t cgraph_strlen(const cgraph_char_t *cthis);
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
extern cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x,
                                   const cgraph_char_t *y);
extern cgraph_char_t *cgraph_strrev(cgraph_char_t *object);
extern cgraph_char_t *cgraph_strnrev(cgraph_char_t *object,
                                     const cgraph_size_t size);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MEMORY_H__ */
