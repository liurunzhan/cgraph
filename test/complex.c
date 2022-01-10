#include "cgraph_complex.h"

int main(int argc, char *argv[]) {
  TYPE complex1 = FUNCTION(NAME, initri)(1.0, 2.0);
  TYPE complex2 = FUNCTION(NAME, ones)();
  TYPE complex3 = FUNCTION(NAME, rand)();
  FUNCTION(NAME, fprintln)(stdout, complex1);
  FUNCTION(NAME, fprintln)(stdout, complex2);
  FUNCTION(NAME, fprintln)(stdout, FUNCTION(NAME, add)(complex1, complex2));
  FUNCTION(NAME, fprintln)(stdout, FUNCTION(NAME, sub)(complex1, complex2));
  FUNCTION(NAME, fprintln)(stdout, FUNCTION(NAME, mul)(complex1, complex2));
  FUNCTION(NAME, fprintln)(stdout, FUNCTION(NAME, div)(complex1, complex2));
  FUNCTION(NAME, fprintln)(stdout, FUNCTION(NAME, sqrt)(complex1));

  return 0;
}