#include <stdio.h>
#include "cgraph_version.h"

static const cgraph_char_t *cgraph_version_string = CGRAPH_VERSION;

void cgraph_version(const cgraph_char_t **version, cgraph_int_t *major, cgraph_int_t *minor, cgraph_int_t *subminor)
{
  cgraph_int_t cgraph_major, cgraph_minor, cgraph_subminor;
  sscanf(cgraph_version_string, "%d.%d.%d", &cgraph_major, &cgraph_minor, &cgraph_subminor);
  *version = (cgraph_char_t *)cgraph_version_string;
  if(NULL != major)
  { *major = cgraph_major; }
  if(NULL != minor)
  { *minor = cgraph_minor; }
  if(NULL != subminor)
  { *subminor = cgraph_subminor; }
}

void cgraph_version_print(void)
{ fprintf(stdout, "Version of Library CGRAPH is %s\n", cgraph_version_string); }

void cgraph_version_fprintf(void *fp)
{ fprintf((FILE *)fp, "Version of Library CGRAPH is %s\n", cgraph_version_string); }

void cgraph_version_test(void)
{
#ifdef DEBUG
  cgraph_char_t *version;
  cgraph_int_t major, minor, subminor;
  cgraph_version_print();
  cgraph_version_fprintf(stdout);
  cgraph_version(&version, &major, &minor, &subminor);
  fprintf(stdout, "CGRAPH : %s\nMajor version : %d\nMinor version : %d\nSubminor version : %d\n", version, major, minor, subminor);
#endif
}
