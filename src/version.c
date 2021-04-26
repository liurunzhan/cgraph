#include "cgraph_file.h"
#include "cgraph_version.h"

static const cgraph_char_t *cgraph_version_string = CGRAPH_VERSION;

void cgraph_version_parse(cgraph_char_t **version, cgraph_int_t *major,
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

cgraph_size_t cgraph_version_fprint(FILE *fp) {
  return fprintf(fp, "Version of Library CGRAPH is %s", cgraph_version_string);
}

cgraph_size_t cgraph_version_print(void) {
  return cgraph_version_fprint(stdout);
}

cgraph_size_t cgraph_version_fprintln(FILE *fp) {
  cgraph_size_t len =
      fprintf(fp, "Version of Library CGRAPH is %s", cgraph_version_string);
  if (0 < len) {
    len += cgraph_file_printnl();
  }

  return len;
}

cgraph_size_t cgraph_version_println(void) {
  return cgraph_version_fprintln(stdout);
}