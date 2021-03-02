#include "cgraph.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  cgraph_char_t *version;
  cgraph_int_t major, minor, subminor;
  cgraph_version_print();
  cgraph_version_fprintf(stdout);
  cgraph_version(&version, &major, &minor, &subminor);
  fprintf(stdout,
          "CGRAPH : %s\nMajor version : %d\nMinor version : %d\nSubminor "
          "version : %d\n",
          version, major, minor, subminor);

  return 0;
}