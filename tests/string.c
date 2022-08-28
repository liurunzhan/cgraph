#include "cgraph_base.h"

#include "cgraph_string.h"

int main(int argc, char *argv[]) {
  TYPE *string = FUNCTION(NAME, calloc)(ID, 10000);
  TYPE *string1 = FUNCTION(NAME, calloc)(ID, 10000);
  TYPE *string2 = FUNCTION(NAME, calloc)(ID, 10000);
  char *cstr = "hello world world wORLD !world !hello_Wor2lD", *str1 = "world";
  char *cstr2 = "hello world!" __PLAT_LEND;
  cgraph_size_t i = 2;
  cgraph_file_fprintfln(stdout, "test %s", STRING(NAME));
  if (NULL != string) {
    cgraph_bool_t error = CGRAPH_FALSE;
    cgraph_file_fprintfln(stdout, "%s", cstr);
    string = FUNCTION(NAME, initdt)(string, cstr, cgraph_strlen(cstr));
    cgraph_file_fprintfln(stdout, "data %s", string->data);
    cgraph_string_title(string);
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
        cgraph_file_fprintfln(stdout, "address : " CGRAPH_PTRADDR_OUT_FMT,
                              CGRAPH_PTRADDR(string));
        cgraph_file_fprintfln(stdout, "length  : %ld", string->len);
        cgraph_file_fprintfln(stdout, "size    : %ld", string->size);
        cgraph_file_fprintfln(stdout, "data    : %s", string->data);
      }
    }
  }
  string1 = FUNCTION(NAME, initc)(string1, cstr, cgraph_strlen(cstr));
  string2 = FUNCTION(NAME, initc)(string2, str1, cgraph_strlen(str1));
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

  cgraph_file_fprintfln(stdout, "test chomp");
  string1 = FUNCTION(NAME, initc)(string1, cstr2, cgraph_strlen(cstr2));
  cgraph_file_fprintf(stdout, "%s", string1->data);
  string1 = FUNCTION(NAME, chomp)(string1);
  cgraph_file_fprintfln(stdout, "%ld : %s", string1->len, string1->data);
  string1 = FUNCTION(NAME, rol)(string1, 2);
  cgraph_file_fprintfln(stdout, "ROL %ld : %s", string1->len, string1->data);
  string1 = FUNCTION(NAME, ror)(string1, 2);
  cgraph_file_fprintfln(stdout, "ROR %ld : %s", string1->len, string1->data);
  string1 = FUNCTION(NAME, shl)(string1, 2);
  cgraph_file_fprintfln(stdout, "SHL %ld : %s", string1->len, string1->data);
  string1 = FUNCTION(NAME, shr)(string1, 2);
  cgraph_file_fprintfln(stdout, "SHR %ld : %s", string1->len, string1->data);

  FUNCTION(NAME, free)(string);
  FUNCTION(NAME, free)
  (string1);
  FUNCTION(NAME, free)
  (string2);

  return 0;
}
