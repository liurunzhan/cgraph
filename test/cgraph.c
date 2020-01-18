#include <stdio.h>
#include <stdlib.h>
#include "cgraph.h"

int main(int argc, char *argv[])
{
  fprintf(stdout, "start simulation\n");
  if(argc == 2)
  {
    cgraph_string_t *buffer = cgraph_string_calloc(1, 1000);
    char *file = argv[1];
    fprintf(stdout, "FILE %s\n", file);
    FILE *fp = cgraph_file_fopen(file, "r");
    cgraph_size_t row = cgraph_file_rows(fp);
    cgraph_size_t column = cgraph_file_columns(fp, ",", buffer);
    fprintf(stdout, "row: %ld column : %ld\n", row, column);
    cgraph_file_fclose(fp);
    cgraph_string_free(buffer);
    cgraph_string_t *abc = cgraph_string_calloc(CGRAPH_STRING_T, 10000);
    cgraph_string_free(abc);
  }
  else
  {
    fprintf(stdout, "%d arguments input error!\n", argc);
  }
  fprintf(stdout, "end simulation\n");

  return 0;
}