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

#ifndef _CGRAPH_CMDARG_H_
#define _CGRAPH_CMDARG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct {
  cgraph_size_t len;
  cgraph_char_t *proname;
  cgraph_char_t arguments;
} cgraph_cmdarg_t;

int cgraph_cmdarg_lenofargs(int argc);
char *cgraph_cmdarg_nameofpro(char *argv[]);
cgraph_cmdarg_t cgraph_cmdarg_parser(int argc, char *args);

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_CMDARG_H_ */
