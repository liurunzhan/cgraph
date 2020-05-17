#include <stdio.h>
#include <stdlib.h>
#include "cgraph.h"

int main(int argc, char *argv[])
{
  fprintf(stdout, "start simulation\n");
  /*
  if(argc == 2)
  {
    cgraph_string_t *buffer = cgraph_string_calloc(CGRAPH_STRING_T, 1000);
    char *file = argv[1];
    FILE *fp = cgraph_file_fopen(file, "r");
    cgraph_size_t row = cgraph_file_rows(fp);
    cgraph_size_t column = cgraph_file_columns(fp, ",", buffer);
    cgraph_object_t *abc;
    cgraph_integer_t i;
    fprintf(stdout, "row: %ld column : %ld\n", row, column);
    cgraph_file_fclose(fp);
    cgraph_string_free(buffer);
    for(i=CGRAPH_INTEGER_T; i<CGRAPH_FRACTION_T; i++)
    {
      abc = cgraph_object_calloc(i, 100);
      cgraph_object_free(abc);
    }
    do
    {
      cgraph_bigint_t *big = cgraph_bigint_calloc(CGRAPH_INTEGER_T, 2);
      cgraph_integer_t data[2] = {1,1};
      cgraph_string_t *buffer;
      cgraph_bigint_initd(big, data, 2);
      buffer = cgraph_bigint_tostr(big);
      fprintf(stdout, "%s\n", buffer->data);
      cgraph_string_free(buffer);
      cgraph_bigint_free(big);
    } while (0);
  }
  else
  {
    fprintf(stdout, "%d arguments input error!\n", argc);
  }
  fprintf(stdout, "end simulation\n");
  */
  fprintf(stdout, "%d %o\n", 3, cgraph_integer_bits(3, 1, 3));
  fprintf(stdout, "%d %o\n", 1, cgraph_integer_sets(1, 1, 3));
  fprintf(stdout, "%d %d\n", 127, cgraph_integer_clrs(127, 0, 3));
  fprintf(stdout, "%d %ld\n", 128, cgraph_integer_zeros(128));

  return 0;
}