#include "cgraph.h"
#include <stdio.h>
#include <string.h>

#define TYPE_STRING
#include "cgraph_template.h"

int main(int argc, char *argv[]) {
  TYPE *string = FUNCTION(NAME, calloc)(ID, 10000);
  char *str = "hello world!";
  cgraph_size_t i = 2;
  cgraph_file_fprintfln(stdout, "test %s", STRING(NAME));
  if (NULL != string) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_file_fprintfln(stdout, "%s", str);
    string = FUNCTION(NAME, initd)(string, str, strlen(str));
    cgraph_file_fprintfln(stdout, "data %s", string->data);
    cgraph_file_fprintfln(stdout,
                          "test base " CGRAPH_PTRADDR_OUT_FORMAT
                          " start " CGRAPH_PTRADDR_OUT_FORMAT
                          " end " CGRAPH_PTRADDR_OUT_FORMAT,
                          CGRAPH_PTRADDR(string), CGRAPH_PTRADDR(string->data),
                          CGRAPH_PTRADDR(string->data + 10000));
    for (i = 1; i <= 200; i++) {
      string =
          FUNCTION(NAME, realloc)(string, DATA_ID, 10000, 10000 * i, &error);
      if (error == CGRAPH_FALSE) {
        cgraph_file_fprintfln(stdout, "address : " CGRAPH_PTRADDR_OUT_FORMAT,
                              CGRAPH_PTRADDR(string));
        cgraph_file_fprintfln(stdout, "length  : " CGRAPH_SIZE_OUT_FORMAT,
                              string->len);
        cgraph_file_fprintfln(stdout, "size    : " CGRAPH_SIZE_OUT_FORMAT,
                              string->size);
        cgraph_file_fprintfln(stdout, "data    : " OUT_FORMAT, string->data);
      }
    }
  }
  FUNCTION(NAME, free)
  (string);

  return 0;
}

#include "cgraph_template_off.h"
