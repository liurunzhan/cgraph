#include "cgraph.h"
#include <stdio.h>

#define TYPE_BIGINT
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  TYPE *bigint1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint3 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint4 = NULL;
  TYPE *bigint5 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint6 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint7 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  cgraph_char_t *data = "001234567890";
  cgraph_char_t *data6 = "254";
  cgraph_char_t *data7 = "-255";

  bigint1->postive = CGRAPH_TRUE;
  bigint1->data[0] = 255;
  bigint1->data[1] = 255;
  bigint1->data[2] = 255;
  bigint1->len = 3;
  bigint2->postive = CGRAPH_FALSE;
  bigint2->data[0] = 255;
  bigint2->data[1] = 255;
  bigint2->data[2] = 254;
  bigint2->data[3] = 254;
  bigint2->len = 4;

  bigint6->postive = CGRAPH_TRUE;
  bigint6->data[0] = 254;
  bigint6->data[1] = 255;
  bigint6->data[2] = 255;
  bigint6->len = 3;
  bigint7->postive = CGRAPH_FALSE;
  bigint7->data[0] = 255;
  bigint7->data[1] = 255;
  bigint7->data[2] = 255;
  bigint7->len = 3;

  FUNCTION(NAME, fprintln)(stdout, bigint6);
  FUNCTION(NAME, fprintln)(stdout, bigint7);
  FUNCTION(NAME, fprintln)(stdout, bigint3);
  FUNCTION(NAME, add)(bigint6, bigint7, bigint3);
  FUNCTION(NAME, fprintln)(stdout, bigint6);
  FUNCTION(NAME, fprintln)(stdout, bigint7);
  FUNCTION(NAME, fprintln)(stdout, bigint3);
  bigint4 = FUNCTION(NAME, atoi)(data);
  FUNCTION(NAME, fprintln)(stdout, bigint4);
  FUNCTION(NAME, fprintln)(stdout, bigint1);
  FUNCTION(NAME, fprintln)(stdout, bigint2);
  FUNCTION(NAME, mul)(bigint1, bigint2, bigint5);
  FUNCTION(NAME, fprintln)(stdout, bigint5);
  FUNCTION(NAME, fprintln)(stdout, bigint2);
  FUNCTION(NAME, fprintln)(stdout, bigint1);
  FUNCTION(NAME, div)(bigint5, bigint2, bigint1);
  FUNCTION(NAME, fprintln)(stdout, bigint5);
  FUNCTION(NAME, fprintln)(stdout, bigint2);
  FUNCTION(NAME, fprintln)(stdout, bigint1);
  FUNCTION(NAME, mod)(bigint5, bigint2, bigint1);
  FUNCTION(NAME, fprintln)(stdout, bigint5);
  FUNCTION(NAME, fprintln)(stdout, bigint2);
  FUNCTION(NAME, fprintln)(stdout, bigint1);

  FUNCTION(NAME, free)(bigint1);
  FUNCTION(NAME, free)(bigint2);
  FUNCTION(NAME, free)(bigint3);
  FUNCTION(NAME, free)(bigint4);
  FUNCTION(NAME, free)(bigint5);
  FUNCTION(NAME, free)(bigint6);
  FUNCTION(NAME, free)(bigint7);

  return 0;
}

#include "cgraph_template_off.h"
