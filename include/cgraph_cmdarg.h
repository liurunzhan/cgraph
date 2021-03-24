#ifndef __CGRAPH_CMDARG_H__
#define __CGRAPH_CMDARG_H__

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

#endif /** __CGRAPH_CMDARG_H__ */
