#include "cgraph.h"

int main(int argc, char *argv[]) {
  cgraph_char_t *version = NULL;
  cgraph_int_t major, minor, subminor;
  cgraph_version_println();
  cgraph_version_fprintln(stdout);
  cgraph_version_parse(&version, &major, &minor, &subminor);
  cgraph_file_fprintfln(stdout,
                        "CGRAPH : %s" __PLAT_LEND
                        "Major version : %d" __PLAT_LEND
                        "Minor version : %d" __PLAT_LEND "Subminor "
                        "version : %d",
                        version, major, minor, subminor);

  return 0;
}