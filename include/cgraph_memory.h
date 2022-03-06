/**
 * @file cgraph_memory.h
 * @brief the apis of memory management
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_MEMORY_H__
#define __CGRAPH_MEMORY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/*
 * memory management functions:
 * 1) is packaged with standard library functions
 * 2) with error information added
 * 3) except for cgraph_calloc and cgraph_realloc, the operated memory length
 * can be a postive or negative number, where a postive number means forward
 * operation and a negative number means reverse operation
 */
extern void *cgraph_calloc(const cgraph_size_t size);
extern void *cgraph_realloc(void *memory, const cgraph_size_t old_size,
                            const cgraph_size_t new_size, cgraph_bool_t *error);
extern void *cgraph_memset(void *memory, cgraph_uint_t data, cgraph_size_t len);
extern void *cgraph_memcpy(void *trg_mem, const void *src_mem,
                           const cgraph_size_t len);
extern void *cgraph_memscpy(void *trg_mem, const void *src_mem,
                            const cgraph_size_t trg_size,
                            const cgraph_size_t src_len);
extern cgraph_size_t cgraph_memlen(const void *memory,
                                   const cgraph_uint8_t end);
extern void *cgraph_memend(const void *memory, const cgraph_uint8_t end);
extern cgraph_bool_t cgraph_memcmp(const void *x_mem, const void *y_mem,
                                   const cgraph_size_t len);
extern void *cgraph_memrev(void *memory, cgraph_size_t len);
extern void *cgraph_memchr(const void *memory, cgraph_int_t ch,
                           const cgraph_size_t len);
extern void *cgraph_memrchr(const void *memory, cgraph_int_t ch,
                            const cgraph_size_t len);
extern void cgraph_free(void *memory);

extern cgraph_size_t cgraph_bitlen(const void *memory, const cgraph_size_t len);

typedef cgraph_bool_t (*cgraph_memeq0_func_t)(const void *data);
extern cgraph_size_t cgraph_datlen(const void *memory, const cgraph_size_t len,
                                   const cgraph_size_t datsize,
                                   cgraph_memeq0_func_t func);

typedef cgraph_bool_t (*cgraph_memeq_func_t)(const void *x, const void *y);
extern cgraph_bool_t cgraph_datcmp(const void *trg_mem, const void *src_mem,
                                   const cgraph_size_t len,
                                   const cgraph_size_t datsize,
                                   cgraph_memeq_func_t func);

/*
 * c-type string management functions:
 * 1) is packaged with standard library functions
 * 2) with error information added
 */
extern cgraph_size_t cgraph_strlen(const cgraph_char_t *string);
extern cgraph_char_t *cgraph_strend(const cgraph_char_t *string);
extern cgraph_char_t *cgraph_strcpy(cgraph_char_t *trg_str,
                                    const cgraph_char_t *src_str);
extern cgraph_char_t *cgraph_strncpy(cgraph_char_t *trg_str,
                                     const cgraph_char_t *src_str,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strscpy(cgraph_char_t *trg_str,
                                     const cgraph_char_t *src_str,
                                     const cgraph_size_t trg_size);
extern cgraph_char_t *cgraph_strcat(cgraph_char_t *trg_str,
                                    const cgraph_char_t *src_str);
extern cgraph_char_t *cgraph_strncat(cgraph_char_t *trg_str,
                                     const cgraph_char_t *src_str,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strscat(cgraph_char_t *trg_str,
                                     const cgraph_char_t *src_str,
                                     const cgraph_size_t trg_size);
extern cgraph_bool_t cgraph_strcmp(const cgraph_char_t *x_str,
                                   const cgraph_char_t *y_str);
extern cgraph_char_t *cgraph_strrev(cgraph_char_t *string);
extern cgraph_char_t *cgraph_strnrev(cgraph_char_t *string,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strtok(cgraph_char_t *string,
                                    const cgraph_char_t *sep);
extern cgraph_char_t *cgraph_strntok(cgraph_char_t *string,
                                     const cgraph_char_t *sep,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strstok(cgraph_char_t *string,
                                     const cgraph_char_t *sep,
                                     cgraph_char_t **cbuf);
extern cgraph_char_t *cgraph_strchr(const cgraph_char_t *string,
                                    cgraph_int_t ch);
extern cgraph_char_t *cgraph_strnchr(const cgraph_char_t *string,
                                     cgraph_int_t ch, const cgraph_size_t len);
extern cgraph_char_t *cgraph_strchrn(const cgraph_char_t *string,
                                     cgraph_int_t ch, const cgraph_size_t num);
extern cgraph_char_t *cgraph_strrchr(const cgraph_char_t *string,
                                     cgraph_int_t ch);
extern cgraph_char_t *cgraph_strnrchr(const cgraph_char_t *string,
                                      cgraph_int_t ch, const cgraph_size_t len);
extern cgraph_char_t *cgraph_strrchrn(const cgraph_char_t *string,
                                      cgraph_int_t ch, const cgraph_size_t num);
extern cgraph_char_t *cgraph_strstr(const cgraph_char_t *src_str,
                                    cgraph_char_t *trg_str);
extern cgraph_char_t *cgraph_strnstr(const cgraph_char_t *src_str,
                                     cgraph_char_t *trg_str,
                                     const cgraph_size_t len);
extern cgraph_char_t *cgraph_strstrn(const cgraph_char_t *src_str,
                                     cgraph_char_t *trg_str,
                                     const cgraph_size_t num);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MEMORY_H__ */
