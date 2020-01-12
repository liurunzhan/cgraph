#include <stdio.h>
#include "cgraph_version.h"

static cgraph_char_t *cgraph_version_string = CGRAPH_VERSION;

cgraph_boolean_t cgraph_version(cgraph_char_t **version, cgraph_integer_t *major, cgraph_integer_t *minor, cgraph_integer_t *subminor)
{
  if(NULL == *version || NULL == major || NULL == minor || NULL == subminor)
  {
    return CGRAPH_FALSE;
  }
  *version = cgraph_version_string;
  sscanf(CGRAPH_VERSION, "%d.%d.%d", major, minor, subminor);
  return CGRAPH_TRUE;
}