#include "cgraph_cmdarg.h"

int cgraph_cmdarg_lenofargs(int argc) { return argc - 1; }

char *cgraph_cmdarg_nameofpro(char *argv[]) { return argv[0]; }