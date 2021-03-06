#include "cgraph.h"
#include <stdio.h>
#include <string.h>

#define TYPE_BIGNUM
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  cgraph_char_t *num = "-0.9", *num2 = "-230.0", *num3 = "-0.1", *num4 = "0.09",
                *num5 = "0.2", *num6 = "-0.21", *num7 = "-0.00009340000";
  cgraph_float64_t float64 = 0.123456;
  cgraph_float32_t float32 = 0.123456;
  TYPE *bignum1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum3 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum4 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum5 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum6 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum7 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum8 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum9 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum10 = FUNCTION(NAME, calloc)(DATA_ID, 20);

  FUNCTION(NAME, initc)(bignum6, num3, strlen(num3));
  FUNCTION(NAME, initc)(bignum7, num4, strlen(num4));
  FUNCTION(NAME, initc)(bignum8, num5, strlen(num5));
  FUNCTION(NAME, initc)(bignum9, num6, strlen(num6));

  FUNCTION(NAME, initc)(bignum10, num7, strlen(num7));
  FUNCTION(NAME, fprintln)(stdout, bignum10);
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, initc)(bignum10, &num7[1], strlen(num7) - 1);
  FUNCTION(NAME, fprintln)(stdout, bignum10);
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, fprintln)
  (stdout, (bignum10 = FUNCTION(NAME, mul10)(bignum10, 10)));
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, fprintln)
  (stdout, (bignum10 = FUNCTION(NAME, div10)(bignum10, 10)));
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, fprintln)
  (stdout, (bignum10 = FUNCTION(NAME, div10)(bignum10, 30)));
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, fprintln)
  (stdout, (bignum10 = FUNCTION(NAME, mul10)(bignum10, 30)));
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, fprintln)
  (stdout, (bignum10 = FUNCTION(NAME, mul10)(bignum10, 30)));
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);
  FUNCTION(NAME, fprintln)
  (stdout, (bignum10 = FUNCTION(NAME, mul10)(bignum10, 30)));
  FUNCTION(NAME, dat_fprintln)(stdout, bignum10);

  FUNCTION(NAME, fprint)(stdout, bignum6);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum7);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum6, bignum7));
  FUNCTION(NAME, fprint)(stdout, bignum6);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum8);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum6, bignum8));
  FUNCTION(NAME, fprint)(stdout, bignum6);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum6, bignum9));
  FUNCTION(NAME, fprint)(stdout, bignum7);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum8);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum7, bignum8));
  FUNCTION(NAME, fprint)(stdout, bignum7);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum7, bignum9));
  FUNCTION(NAME, fprint)(stdout, bignum8);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum8, bignum9));
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum9, bignum9));

  FUNCTION(NAME, fprint)(stdout, bignum6);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum7);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum6, bignum7));
  FUNCTION(NAME, fprint)(stdout, bignum6);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum8);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum6, bignum8));
  FUNCTION(NAME, fprint)(stdout, bignum6);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum6, bignum9));
  FUNCTION(NAME, fprint)(stdout, bignum7);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum8);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum7, bignum8));
  FUNCTION(NAME, fprint)(stdout, bignum7);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum7, bignum9));
  FUNCTION(NAME, fprint)(stdout, bignum8);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum8, bignum9));
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum9);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum9, bignum9));

  FUNCTION(NAME, initc)(bignum1, num, strlen(num));
  FUNCTION(NAME, fprintln)(stdout, bignum1);
  FUNCTION(NAME, initc)(bignum3, num2, strlen(num2));
  FUNCTION(NAME, fprintln)(stdout, bignum3);
  FUNCTION(NAME, ceil)(bignum1, bignum2);
  FUNCTION(NAME, fprintln)(stdout, bignum2);
  FUNCTION(NAME, fprint)(stdout, bignum2);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum3);
  fprintf(stdout, " EQ compare : %d\n", FUNCTION(NAME, eq)(bignum2, bignum3));
  FUNCTION(NAME, fprint)(stdout, bignum2);
  fprintf(stdout, " and ");
  FUNCTION(NAME, fprint)(stdout, bignum3);
  fprintf(stdout, " GR compare : %d\n", FUNCTION(NAME, gr)(bignum2, bignum3));
  FUNCTION(NAME, floor)(bignum1, bignum2);
  FUNCTION(NAME, fprintln)(stdout, bignum2);
  FUNCTION(NAME, initf64)(bignum1, float64);
  FUNCTION(NAME, fprintln)(stdout, bignum1);
  if (bignum1->postive) {
    fprintf(stdout, "bignum1 is postive!\n");
  }
  FUNCTION(NAME, initf32)(bignum2, float32);
  FUNCTION(NAME, fprintln)(stdout, bignum1);
  FUNCTION(NAME, fprintln)(stdout, bignum2);
  FUNCTION(NAME, add)(bignum1, bignum2, bignum4);
  FUNCTION(NAME, fprintln)(stdout, bignum4);
  FUNCTION(NAME, opp)(bignum1);
  FUNCTION(NAME, fprintln)(stdout, bignum1);
  FUNCTION(NAME, fprintln)(stdout, bignum2);
  FUNCTION(NAME, add)(bignum1, bignum2, bignum5);
  FUNCTION(NAME, fprintln)(stdout, bignum5);

  FUNCTION(NAME, free)(bignum1);
  FUNCTION(NAME, free)(bignum2);
  FUNCTION(NAME, free)(bignum3);
  FUNCTION(NAME, free)(bignum4);
  FUNCTION(NAME, free)(bignum5);
  FUNCTION(NAME, free)(bignum6);
  FUNCTION(NAME, free)(bignum7);
  FUNCTION(NAME, free)(bignum8);
  FUNCTION(NAME, free)(bignum9);
  FUNCTION(NAME, free)(bignum10);

  return 0;
}