/**
 * @file cgraph_version.h
 * @brief the version functions of cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_VERSION_H__
#define __CGRAPH_VERSION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "0.0.0"
#endif

extern void cgraph_version_parse(cgraph_char_t **version, cgraph_int_t *major,
                                 cgraph_int_t *minor, cgraph_int_t *subminor);
extern cgraph_size_t cgraph_version_fprint(FILE *fp);
extern cgraph_size_t cgraph_version_print(void);
extern cgraph_size_t cgraph_version_fprintln(FILE *fp);
extern cgraph_size_t cgraph_version_println(void);
extern const cgraph_char_t **cgraph_version_types(void);
extern const cgraph_char_t *cgraph_version_tname(const cgraph_size_t type);
extern cgraph_size_t cgraph_version_tprintln(const cgraph_char_t *sep);
extern cgraph_size_t cgraph_version_tfprintln(FILE *fp,
                                              const cgraph_char_t *sep);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_VERSION_H__ */
