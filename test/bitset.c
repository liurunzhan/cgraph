#include "cgraph.h"
#include <stdio.h>

#define TYPE_BITSET
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  TYPE *bitset1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bitset2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  cgraph_size_t i;

  bitset1->data[0] = 0xFF;
  bitset1->data[1] = 0xFF;
  bitset1->data[2] = 0xFF;
  bitset1->len = 3;
  bitset1->bits_num = 0;
  FUNCTION(NAME, fprintln)(stdout, bitset1);
  FUNCTION(NAME, fprintb)(stdout, bitset1);
  cgraph_file_fprintln(stdout);
  for (i = 7; i > 0; i--) {
    bitset1->bits_num = i;
    FUNCTION(NAME, fprintln)(stdout, bitset1);
    FUNCTION(NAME, fprintb)(stdout, bitset1);
    cgraph_file_fprintln(stdout);
  }

  FUNCTION(NAME, free)(bitset1);
  FUNCTION(NAME, free)(bitset2);

  return 0;
}