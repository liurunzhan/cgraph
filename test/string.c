#include <string.h>

#include "cgraph_file.h"

#include "cgraph_string.h"

int main(int argc, char *argv[]) {
  TYPE *string = FUNCTION(NAME, calloc)(ID, 10000);
  TYPE *string1 = FUNCTION(NAME, calloc)(ID, 10000);
  TYPE *string2 = FUNCTION(NAME, calloc)(ID, 10000);
  char *cstr = "hello world world world !world", *str1 = "world";
  cgraph_size_t i = 2;
  cgraph_file_fprintfln(stdout, "test %s", STRING(NAME));
  if (NULL != string) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_file_fprintfln(stdout, "%s", cstr);
    string = FUNCTION(NAME, initd)(string, cstr, strlen(cstr));
    cgraph_file_fprintfln(stdout, "data %s", string->data);
    cgraph_file_fprintfln(stdout,
                          "test base " CGRAPH_PTRADDR_OUT_FMT
                          " start " CGRAPH_PTRADDR_OUT_FMT
                          " end " CGRAPH_PTRADDR_OUT_FMT,
                          CGRAPH_PTRADDR(string), CGRAPH_PTRADDR(string->data),
                          CGRAPH_PTRADDR(string->data + 10000));
    for (i = 1; i <= 200; i++) {
      string =
          FUNCTION(NAME, realloc)(string, DATA_ID, 10000, 10000 * i, &error);
      if (CGRAPH_FALSE == error) {
        cgraph_file_fprintfln(stdout, "address : %p", CGRAPH_PTRADDR(string));
        cgraph_file_fprintfln(stdout, "length  : %ld", string->len);
        cgraph_file_fprintfln(stdout, "size    : %ld", string->size);
        cgraph_file_fprintfln(stdout, "data    : %s", string->data);
      }
    }
  }
  string1 = FUNCTION(NAME, initc)(string1, cstr, strlen(cstr));
  string2 = FUNCTION(NAME, initc)(string2, str1, strlen(str1));
  cgraph_file_fprintfln(stdout, "%s", string1->data);
  cgraph_file_fprintfln(stdout, "%s", string2->data);
  string = FUNCTION(NAME, sub)(string1, string2, string);
  cgraph_file_fprintfln(stdout, "%s", string->data);
  cgraph_file_fprintfln(stdout, "%s", string1->data);
  cgraph_file_fprintfln(stdout, "%s", string2->data);
  string = FUNCTION(NAME, mod)(string1, string2, string);
  cgraph_file_fprintfln(stdout, "%s", string->data);
  string1 = FUNCTION(NAME, initf)(string1, "%ld", 99);
  cgraph_file_fprintfln(stdout, "%s", string1->data);
  string2 = FUNCTION(NAME, initf)(string2, "%ld", 99);
  cgraph_file_fprintfln(stdout, "%s", string2->data);
  string = FUNCTION(NAME, mul)(string1, string2, string);
  cgraph_file_fprintfln(stdout, "%s", string->data);

  FUNCTION(NAME, free)(string);
  FUNCTION(NAME, free)
  (string1);
  FUNCTION(NAME, free)
  (string2);

  return 0;
}
