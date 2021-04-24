#include "cgraph.h"
#include <stdio.h>

#define TYPE_BITSET
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  TYPE *bitset1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bitset2 = FUNCTION(NAME, calloc)(DATA_ID, 20);

  bitset1->data[0] = 0x20;
  bitset1->data[1] = 0x20;
  bitset1->data[2] = 0x20;
  bitset1->len = 3;
  FUNCTION(NAME, fprint)(stdout, bitset1);

  FUNCTION(NAME, free)(bitset1);
  FUNCTION(NAME, free)(bitset2);

  return 0;
}