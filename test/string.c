#include "cgraph.h"
#include <stdio.h>
#include <string.h>

#define TYPE_STRING
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  TYPE *string = FUNCTION(NAME, calloc)(ID, 10000);
  char *str = "hello world!";
  cgraph_size_t i = 2;
  fprintf(stdout, "test %s\n", STRING(NAME));
  if (NULL != string) {
    cgraph_bool_t error = CGRAPH_FALSE;
    fprintf(stdout, "%s\n", str);
    string = FUNCTION(NAME, initd)(string, str, strlen(str));
    fprintf(stdout, "data %s\n", string->data);
    fprintf(stdout,
            "test base " CGRAPH_PTRADDR_OUT_FORMAT
            " start " CGRAPH_PTRADDR_OUT_FORMAT
            " end " CGRAPH_PTRADDR_OUT_FORMAT "\n",
            CGRAPH_PTRADDR(string), CGRAPH_PTRADDR(string->data),
            CGRAPH_PTRADDR(string->data + 10000));
    for (i = 1; i <= 200; i++) {
      string =
          FUNCTION(NAME, realloc)(string, DATA_ID, 10000, 10000 * i, &error);
      if (error == CGRAPH_FALSE) {
        fprintf(stdout, "address : " CGRAPH_PTRADDR_OUT_FORMAT "\n",
                CGRAPH_PTRADDR(string));
        fprintf(stdout, "length  : " CGRAPH_SIZE_OUT_FORMAT "\n", string->len);
        fprintf(stdout, "size    : " CGRAPH_SIZE_OUT_FORMAT "\n", string->size);
        fprintf(stdout, "data    : " OUT_FORMAT "\n", string->data);
      }
    }
  }
  FUNCTION(NAME, free)
  (string);

  return 0;
}

#include "cgraph_template_off.h"
