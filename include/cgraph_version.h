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

extern void cgraph_version(cgraph_char_t **version, cgraph_int_t *major,
                           cgraph_int_t *minor, cgraph_int_t *subminor);
extern void cgraph_version_print(void);
extern void cgraph_version_fprintf(FILE *fp);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_VERSION_H__ */
