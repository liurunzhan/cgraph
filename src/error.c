#include <stdio.h>
#include "cgraph_error.h"

static cgraph_char_t *__cgraph_error_strings__[] = 
{
  "NO ERROR",
  "ERROR",
  "OUT OF MEMORY",
  "OUT OF INDEX",
  "INFINITE",
  "NOT A NUMBER",
  "DIVISOR EQUAL TO ZERO",
  "MATH ERROR",
  NULL
};

#define CGRAPH_ERROR_STRING(reason) (__cgraph_error_strings__[reason])

void cgraph_error(cgraph_error_t reason, const cgraph_size_t line, cgraph_char_t *file)
{
  if(reason < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS)
  { fprintf(stderr, "%s happens in Line %ld of File %s\n", CGRAPH_ERROR_STRING(reason), line, file); }
  else
  { fprintf(stderr, "Undefined error %d happens in Line %ld of File %s\n", reason, line, file); }
  fflush(stderr);
}

cgraph_char_t *cgraph_error_reason(const cgraph_error_t reason)
{
  return (reason < CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS ? CGRAPH_ERROR_STRING(reason) : CGRAPH_ERROR_STRING(CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS));
}

void cgraph_error_details_md(FILE *fp)
{
  if(0 != feof(fp))
  {
    cgraph_integer_t i;
    fprintf(fp, "| ERROR TYPE | ERROR DETAIL |\n| :-: | :-: |\n");
    for(i=0; i<CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS; i++)
    { fprintf(fp, "| %d | %s |\n", i, CGRAPH_ERROR_STRING(i)); }
  }
}

void cgraph_error_details_csv(FILE *fp)
{
  if(0 != feof(fp))
  {
    cgraph_integer_t i;
    fprintf(fp, "ERROR TYPE,ERROR DETAIL\n");
    for(i=0; i<CGRAPH_ERROR_MAXIMUM_VALUE_OF_ERRORS; i++)
    { fprintf(fp, "%d,%s\n", i, CGRAPH_ERROR_STRING(i)); }
  }
}