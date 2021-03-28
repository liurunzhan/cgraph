#include "cgraph_version.h"

static const cgraph_char_t *cgraph_version_string = CGRAPH_VERSION;

void cgraph_version(cgraph_char_t **version, cgraph_int_t *major,
                    cgraph_int_t *minor, cgraph_int_t *subminor) {
  cgraph_int_t cgraph_major, cgraph_minor, cgraph_subminor;
  sscanf(cgraph_version_string, "%d.%d.%d", &cgraph_major, &cgraph_minor,
         &cgraph_subminor);
  if (NULL != version) {
    *version = (cgraph_char_t *)cgraph_version_string;
  }
  if (NULL != major) {
    *major = cgraph_major;
  }
  if (NULL != minor) {
    *minor = cgraph_minor;
  }
  if (NULL != subminor) {
    *subminor = cgraph_subminor;
  }
}

void cgraph_version_print(void) {
  fprintf(stdout, "Version of Library CGRAPH is %s\n", cgraph_version_string);
}

void cgraph_version_fprintf(FILE *fp) {
  fprintf(fp, "Version of Library CGRAPH is %s\n", cgraph_version_string);
}
