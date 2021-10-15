#include "cgraph.h"

#define TYPE_INT128
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  FUNCTION(NAME, fprintln)(stdout, -120);
  FUNCTION(NAME, fprintln)(stdout, 120);

  return 0;
}

#include "cgraph_template_off.h"