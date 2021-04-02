#include "cgraph.h"
#include <stdio.h>
#include <string.h>

#define TYPE_BIGNUM
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  cgraph_char_t *num = "-0000234.00";
  TYPE *bignum1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bignum2 = FUNCTION(NAME, calloc)(DATA_ID, 20);

  FUNCTION(NAME, initc)(bignum1, num, strlen(num));
  FUNCTION(NAME, fprintf)(stdout, bignum1);
  fprintf(stdout, "\n");
  FUNCTION(NAME, initc)(bignum2, num, strlen(num));
  FUNCTION(NAME, fprintf)(stdout, bignum2);
  fprintf(stdout, "\n");

  FUNCTION(NAME, free)(bignum1);
  FUNCTION(NAME, free)(bignum2);

  return 0;
}