/**
 * @file cgraph_version.h
 * @brief the version solution of cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_VERSION_H__
#define __CGRAPH_VERSION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifdef __VERSION
#define CGRAPH_VERSION __VERSION
#else
#define CGRAPH_VERSION "0.0.0"
#endif

extern void cgraph_version_parse(cgraph_char_t **version, cgraph_int_t *major,
                                 cgraph_int_t *minor, cgraph_int_t *subminor);
extern cgraph_size_t cgraph_version_fprint(FILE *fp);
extern cgraph_size_t cgraph_version_print(void);
extern cgraph_size_t cgraph_version_fprintln(FILE *fp);
extern cgraph_size_t cgraph_version_println(void);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_VERSION_H__ */
