#include "cgraph_file.h"
#include "cgraph_int.h"

#include "cgraph_fraction.h"

int main(int argc, char *argv[]) {
  TYPE fraction1 = FUNCTION(NAME, initnd)(1, 2);
  TYPE fraction2 = FUNCTION(NAME, ones)();
  TYPE fraction3 = FUNCTION(NAME, rand)();
  TYPE fraction_min = FUNCTION(NAME, min)();
  TYPE fraction_max = FUNCTION(NAME, max)();
  FUNCTION(NAME, fprintln)(stdout, fraction1);
  FUNCTION(NAME, fprintln)(stdout, fraction2);
  FUNCTION(NAME, fprintln)(stdout, fraction3);
  FUNCTION(NAME, fprintln)(stdout, fraction_min);
  FUNCTION(NAME, fprintln)(stdout, fraction_max);
  FUNCTION(NAME, fprintln)
  (stdout, FUNCTION(NAME, add)(fraction1, fraction2));
  FUNCTION(NAME, fprintln)
  (stdout, FUNCTION(NAME, sub)(fraction1, fraction2));
  FUNCTION(NAME, fprintln)
  (stdout, FUNCTION(NAME, mul)(fraction1, fraction2));
  FUNCTION(NAME, fprintln)
  (stdout, FUNCTION(NAME, div)(fraction1, fraction2));
  FUNCTION(NAME, fprintln)(stdout, FUNCTION(NAME, sqrt)(fraction1));

  return 0;
}