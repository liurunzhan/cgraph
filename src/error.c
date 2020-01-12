#include <stdio.h>
#include "cgraph_error.h"

void cgraph_error(cgraph_char_t *reason, const cgraph_size_t line, cgraph_char_t *file)
{
  fprintf(stderr, "%s happens in Line %ld of File %s\n", reason, line, file);
  fflush(stderr);
}