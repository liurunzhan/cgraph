#include "cgraph.h"
#include <stdio.h>

#define TYPE_FLOAT128
#include "template.h"

TYPE function_x(const TYPE x) { return x * x; }
TYPE function_x2(const TYPE x) { return 1 + x - x * x * x; }
TYPE function_xy(const TYPE x, const TYPE y) { return -1.0 * x * y * y; }

int main(int argc, char *argv[]) {
  cgraph_size_t i, j, k;
  TYPE data[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  TYPE xdata[6] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  TYPE ydata[3] = {1.0, 1.0, 1.0};
  TYPE zdata[8];
  TYPE tmp = ZERO;

  fprintf(stdout, OUT_FORMAT "\n", FUNCTION(NAME, sqrt)(2));
  fprintf(stdout, OUT_FORMAT "\n", FUNCTION(NAME, cube)(2));
  fprintf(
      stdout, OUT_FORMAT "\n",
      FUNCTION(NAME, intg_range_trapezoidal)(0.1, 0.2, 0.00001, &function_x));
  fprintf(
      stdout, OUT_FORMAT "\n",
      FUNCTION(NAME, intg_range_trapezoidal)(0.2, 0.1, 0.00001, &function_x));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, intg_range_simpson)(0.1, 0.2, 0.00001, &function_x));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, intg_range_simpson)(0.2, 0.1, 0.00001, &function_x));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, intg_range_simpson38)(0.1, 0.2, 0.00001, &function_x));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, intg_range_simpson38)(0.2, 0.1, 0.00001, &function_x));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, intg_range_cotes)(0.1, 0.2, 0.00001, &function_x));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, intg_range_cotes)(0.2, 0.1, 0.00001, &function_x));

  FUNCTION(NAME, trans)(data, 2, 2);
  FUNCTION(NAME, trans)(data, 1, 2);
  FUNCTION(NAME, subsym)(data, 2, 2);
  FUNCTION(NAME, subsym)(data, 1, 2);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      fprintf(stdout, OUT_FORMAT " ", data[i * 2 + j]);
    }
    fprintf(stdout, "\n");
  }
  FUNCTION(NAME, rot1I)(data, 2, 3);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      fprintf(stdout, OUT_FORMAT " ", data[i * 2 + j]);
    }
    fprintf(stdout, "\n");
  }
  FUNCTION(NAME, rot1I)(data, 1, 2);
  fprintf(stdout, OUT_FORMAT "\n", FUNCTION(NAME, exp)(1.0));
  fprintf(stdout, OUT_FORMAT "\n", FUNCTION(NAME, exp)(2.0));
  fprintf(stdout, OUT_FORMAT "\n", FUNCTION(NAME, exp)(3.0));
  fprintf(stdout, "pi = " OUT_FORMAT "\n", FUNCTION(NAME, pi)());
  FUNCTION(NAME, conv)
  (xdata, ydata, 6, 3, &tmp, zdata);
  for (k = 0; k < 8; k++) {
    fprintf(stdout, OUT_FORMAT "\n", zdata[k]);
  }
  fprintf(
      stdout, OUT_FORMAT "\n",
      FUNCTION(NAME, diff_runge_kutta_s4)(0.0, 5.0, 2.0, 0.25, function_xy));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, diff_kutta_s4)(0.0, 5.0, 2.0, 0.25, function_xy));
  fprintf(stdout, OUT_FORMAT "\n",
          FUNCTION(NAME, eqt_binary_search)(1.0, 2.0, function_x2));

  return 0;
}

#include "template_off.h"