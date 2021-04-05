#include "cgraph.h"
#include <stdio.h>
#include <string.h>

#define TYPE_BIGNUM
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  cgraph_char_t *num = "-0000230.01";
  cgraph_char_t *num2 = "-230.0";
  TYPE *bignum1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum3 = FUNCTION(NAME, calloc)(DATA_ID, 20);

  FUNCTION(NAME, initc)(bignum1, num, strlen(num));
  FUNCTION(NAME, initc)(bignum3, num2, strlen(num2));
  FUNCTION(NAME, fprintf)(stdout, bignum1);
  fprintf(stdout, "\n");
  FUNCTION(NAME, ceil)(bignum1, bignum2);
  FUNCTION(NAME, fprintf)(stdout, bignum2);
  fprintf(stdout, "\n");
  fprintf(stdout, "compare : %d\n", FUNCTION(NAME, eq)(bignum2, bignum3));
  FUNCTION(NAME, floor)(bignum1, bignum2);
  FUNCTION(NAME, fprintf)(stdout, bignum2);
  fprintf(stdout, "\n");
  FUNCTION(NAME, initf64)(bignum1, 0.234567890);
  FUNCTION(NAME, fprintf)(stdout, bignum1);
  fprintf(stdout, "\n");
  FUNCTION(NAME, initf32)(bignum1, 0.234567);
  FUNCTION(NAME, fprintf)(stdout, bignum1);
  fprintf(stdout, "\n");

  FUNCTION(NAME, free)(bignum1);
  FUNCTION(NAME, free)(bignum2);
  FUNCTION(NAME, free)(bignum3);

  return 0;
}