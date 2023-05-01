#include <stdio.h>

#include "cgraph_base.h"

#include "cgraph_bitset.h"

int main(int argc, char *argv[]) {
  TYPE *bitset1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bitset2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  cgraph_size_t i, start = 0, end = 8;

  bitset1->data[0] = 0xFF;
  bitset1->data[1] = 0xFF;
  bitset1->data[2] = 0xFF;
  bitset1->len = 3;
  FUNCTION(NAME, updatepos)(bitset1, 8);
  FUNCTION(NAME, fprintln)(stdout, bitset1);
  FUNCTION(NAME, fprintb)(stdout, bitset1);
  cgraph_file_fprintln(stdout);
  cgraph_file_fprintfln(stdout, "check clear and set operations");
  for (i = 0; i < bitset1->len * DATA_BITS; i++) {
    FUNCTION(NAME, clrs)(bitset1, start, i);
    FUNCTION(NAME, fprintln)(stdout, bitset1);
    FUNCTION(NAME, sets)(bitset1, start, i);
    FUNCTION(NAME, fprintln)(stdout, bitset1);
  }
  cgraph_file_fprintfln(stdout, "check clear and set operations done");
  bitset1->data[0] = 0xF0;
  bitset1->data[1] = 0x50;
  bitset1->data[2] = 0xC0;
  bitset1->len = 3;
  FUNCTION(NAME, updatepos)(bitset1, 8);
  FUNCTION(NAME, fprintln)(stdout, bitset1);
  FUNCTION(NAME, fprintb)(stdout, bitset1);
  cgraph_file_fprintln(stdout);
  for (i = 8; i > 0; i--) {
    /*FUNCTION(NAME, updatepos)(bitset1, i);*/
    FUNCTION(NAME, fprinth)(stdout, bitset1);
    cgraph_file_fprintln(stdout);
    FUNCTION(NAME, fprintb)(stdout, bitset1);
    cgraph_file_fprintln(stdout);
    bitset1 = FUNCTION(NAME, swapbit1)(bitset1);
  }

  FUNCTION(NAME, free)(bitset1);
  FUNCTION(NAME, free)(bitset2);

  return 0;
}