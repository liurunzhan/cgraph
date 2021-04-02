#include "cgraph.h"
#include <stdio.h>

#define TYPE_BIGINT
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  TYPE *bigint1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint3 = FUNCTION(NAME, calloc)(DATA_ID, 20);
  TYPE *bigint4 = NULL;
  cgraph_char_t *data = "001234567890";

  bigint1->postive = CGRAPH_TRUE;
  bigint1->data[0] = 255;
  bigint1->data[1] = 255;
  bigint1->data[2] = 255;
  bigint1->len = 3;
  bigint2->postive = CGRAPH_FALSE;
  bigint2->data[0] = 255;
  bigint2->data[1] = 255;
  bigint2->data[2] = 254;
  bigint2->data[3] = 1;
  bigint2->len = 4;

  FUNCTION(NAME, fprintf)(stdout, bigint1);
  fprintf(stdout, "\n");
  FUNCTION(NAME, fprintf)(stdout, bigint2);
  fprintf(stdout, "\n");
  FUNCTION(NAME, fprintf)(stdout, bigint3);
  fprintf(stdout, "\n");
  FUNCTION(NAME, add)(bigint1, bigint2, bigint3);
  FUNCTION(NAME, fprintf)(stdout, bigint1);
  fprintf(stdout, "\n");
  FUNCTION(NAME, fprintf)(stdout, bigint2);
  fprintf(stdout, "\n");
  fprintf(stdout, "size : %ld\n", bigint3->len);
  FUNCTION(NAME, fprintf)(stdout, bigint3);
  fprintf(stdout, "\n");
  bigint4 = FUNCTION(NAME, atoi)(data);
  FUNCTION(NAME, fprintf)(stdout, bigint4);
  fprintf(stdout, "\n");

  FUNCTION(NAME, free)(bigint1);
  FUNCTION(NAME, free)(bigint2);
  FUNCTION(NAME, free)(bigint3);
  FUNCTION(NAME, free)(bigint4);

  return 0;
}

#include "cgraph_template_off.h"
