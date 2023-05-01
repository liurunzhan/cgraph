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
 * mem management functions:
 * 1) is packaged with standard library functions
 * 2) with error information added
 * 3) except for cgraph_calloc and cgraph_realloc, the operated mem length
 * can be a postive or negative number, where a postive number means forward
 * operation and a negative number means reverse operation
 */
extern void *cgraph_calloc(const cgraph_size_t size);
extern void *cgraph_realloc(void *mem, const cgraph_size_t size1,
                            const cgraph_size_t size2, cgraph_bool_t *error);
extern void *cgraph_memset(void *mem, cgraph_uint_t ch, cgraph_size_t n);
extern void *cgraph_memcpy(void *dest, const void *src, const cgraph_size_t n);
extern void *cgraph_memscpy(void *dest, const void *src, const cgraph_size_t dn,
                            const cgraph_size_t sn);
extern cgraph_size_t cgraph_memlen(const void *mem, const cgraph_uint_t end);
extern void *cgraph_memend(const void *mem, const cgraph_uint_t end);
extern cgraph_bool_t cgraph_memcmp(const void *mem1, const void *mem2,
                                   const cgraph_size_t n);
extern void *cgraph_memrev(void *mem, cgraph_size_t n);
extern void *cgraph_memchr(const void *mem, cgraph_int_t ch,
                           const cgraph_size_t n);
extern void *cgraph_memrchr(const void *mem, cgraph_int_t ch,
                            const cgraph_size_t n);
extern void cgraph_free(void *mem);

extern cgraph_size_t cgraph_abitlen(const void *mem, const cgraph_size_t n);
extern cgraph_size_t cgraph_adatlen(const void *mem, const cgraph_size_t n,
                                    const cgraph_size_t datsize,
                                    cgraph_bool_t (*func)(const void *data));
extern cgraph_bool_t
cgraph_datcmp(const void *dest, const void *src, const cgraph_size_t n,
              const cgraph_size_t datsize,
              cgraph_bool_t (*func)(const void *x, const void *y));

/*
 * c-type string management functions:
 * 1) is packaged with standard library functions
 * 2) with error information added
 */
extern cgraph_size_t cgraph_strlen(const cgraph_char_t *str);
extern cgraph_char_t *cgraph_strend(const cgraph_char_t *str);
extern cgraph_char_t *cgraph_strcpy(cgraph_char_t *dest,
                                    const cgraph_char_t *str);
extern cgraph_char_t *cgraph_strncpy(cgraph_char_t *dest,
                                     const cgraph_char_t *str,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strscpy(cgraph_char_t *dest,
                                     const cgraph_char_t *str,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strcat(cgraph_char_t *dest,
                                    const cgraph_char_t *str);
extern cgraph_char_t *cgraph_strncat(cgraph_char_t *dest,
                                     const cgraph_char_t *str,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strscat(cgraph_char_t *dest,
                                     const cgraph_char_t *str,
                                     const cgraph_size_t n);
extern cgraph_bool_t cgraph_strcmp(const cgraph_char_t *str1,
                                   const cgraph_char_t *str2);
extern cgraph_bool_t cgraph_strcasecmp(const cgraph_char_t *str1,
                                       const cgraph_char_t *str2);
extern cgraph_bool_t cgraph_strncmp(const cgraph_char_t *str1,
                                    const cgraph_char_t *str2,
                                    const cgraph_size_t n);
extern cgraph_bool_t cgraph_strncasecmp(const cgraph_char_t *str1,
                                        const cgraph_char_t *str2,
                                        const cgraph_size_t n);
extern cgraph_char_t *cgraph_strrev(cgraph_char_t *str);
extern cgraph_char_t *cgraph_strnrev(cgraph_char_t *str, const cgraph_size_t n);
extern cgraph_char_t *cgraph_strtok(cgraph_char_t *str,
                                    const cgraph_char_t *sep);
extern cgraph_char_t *cgraph_strntok(cgraph_char_t *str,
                                     const cgraph_char_t *sep,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strstok(cgraph_char_t *str,
                                     const cgraph_char_t *sep,
                                     cgraph_char_t **cbuf);
extern cgraph_char_t *cgraph_strchr(const cgraph_char_t *str, cgraph_int_t ch);
extern cgraph_char_t *cgraph_strnchr(const cgraph_char_t *str, cgraph_int_t ch,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strchrn(const cgraph_char_t *str, cgraph_int_t ch,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strrchr(const cgraph_char_t *str, cgraph_int_t ch);
extern cgraph_char_t *cgraph_strnrchr(const cgraph_char_t *str, cgraph_int_t ch,
                                      const cgraph_size_t n);
extern cgraph_char_t *cgraph_strrchrn(const cgraph_char_t *str, cgraph_int_t ch,
                                      const cgraph_size_t n);
extern cgraph_char_t *cgraph_strstr(const cgraph_char_t *str,
                                    cgraph_char_t *dest);
extern cgraph_char_t *cgraph_strnstr(const cgraph_char_t *str,
                                     cgraph_char_t *dest,
                                     const cgraph_size_t n);
extern cgraph_char_t *cgraph_strstrn(const cgraph_char_t *str,
                                     cgraph_char_t *dest,
                                     const cgraph_size_t n);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MEMORY_H__ */
