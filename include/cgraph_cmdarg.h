/**
 * @file cgraph_cmdarg.h
 * @brief the apis of the command line arguments
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_CMDARG_H__
#define __CGRAPH_CMDARG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_string.h"

/**
 * @struct cgraph_cmdarg_t
 * @brief the object of command line argument
 */
typedef struct {
  cgraph_size_t len;
  cgraph_char_t *name;
  cgraph_char_t **args;
  cgraph_char_t *data;
} cgraph_cmdarg_t;

extern cgraph_cmdarg_t *cgraph_cmdarg_calloc(int argc, char *argv[]);
extern void cgraph_cmdarg_free(cgraph_cmdarg_t *cthis);

extern cgraph_char_t *cgraph_cmdarg_nam(const cgraph_cmdarg_t *cthis);
extern cgraph_size_t cgraph_cmdarg_namlen(const cgraph_cmdarg_t *cthis);
extern cgraph_bool_t cgraph_cmdarg_isarg(const cgraph_cmdarg_t *cthis,
                                         const cgraph_char_t *arg);
extern cgraph_size_t cgraph_cmdarg_argnum(const cgraph_cmdarg_t *cthis,
                                          const cgraph_char_t *arg);
extern cgraph_char_t *cgraph_cmdarg_argnam(const cgraph_cmdarg_t *cthis,
                                           const cgraph_size_t argnum);
extern cgraph_size_t cgraph_cmdarg_arglen(const cgraph_cmdarg_t *cthis,
                                          const cgraph_size_t argnum);
extern cgraph_size_t cgraph_cmdarg_fprintln(FILE *fp,
                                            const cgraph_cmdarg_t *cthis);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_CMDARG_H__ */
