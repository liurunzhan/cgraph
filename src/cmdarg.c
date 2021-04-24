#include "cgraph_cmdarg.h"
#include "cgraph_memory.h"
#include <string.h>

int cgraph_cmdarg_lenofargs(int argc) { return argc - 1; }

char *cgraph_cmdarg_nameofpro(char *argv[]) { return argv[0]; }

cgraph_cmdarg_t *cgraph_cmdarg_calloc(int argc, char *argv[]) {
  cgraph_cmdarg_t *cmdarg = cgraph_calloc(sizeof(cgraph_cmdarg_t));
  if (NULL != cmdarg) {
    cgraph_size_t i;
    char *ptr = *argv;
    cmdarg->len = cgraph_cmdarg_lenofargs(argc);
    cmdarg->name = cgraph_string_calloc(CGRAPH_CHAR_T,
                                        strlen(cgraph_cmdarg_nameofpro(argv)));
    cmdarg->args = cgraph_calloc(sizeof(cgraph_string_t *));
    for (i = 0; '\0' != *ptr; ptr++, i++) {
      cmdarg->args[i] = cgraph_string_calloc(CGRAPH_CHAR_T, strlen(argv[i]));
    }
  }

  return cmdarg;
}

void cgraph_cmdarg_free(cgraph_cmdarg_t *cthis) {
  if (NULL != cthis) {
    cgraph_size_t i = 0;
    cgraph_string_free(cthis->name);
    for (i = 0; i < cthis->len; i++) {
      cgraph_string_free(cthis->args[i]);
    }
    cgraph_free(cthis->args);
    cgraph_free(cthis);
  }
}