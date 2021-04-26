/**
 * @file cgraph_cmdarg.h
 * @brief the command line arguments
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

typedef struct {
  cgraph_size_t len;
  cgraph_string_t *name;
  cgraph_string_t **args;
} cgraph_cmdarg_t;

int cgraph_cmdarg_lenofargs(int argc);
char *cgraph_cmdarg_nameofpro(char *argv[]);
cgraph_cmdarg_t *cgraph_cmdarg_calloc(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_CMDARG_H__ */
