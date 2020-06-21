#include <stdio.h>
#include <stdlib.h>
#include "cgraph.h"

int main(int argc, char *argv[])
{
  cgraph_char_t buffer[100];
  cgraph_fraction_t fraction = {-1, INT_MAX};
  cgraph_integer_t integer = 123;
  cgraph_float_t real = 123.0, number = 0.1;
  cgraph_size_t i = 0;
  cgraph_bignum_t *bignum = cgraph_bignum_calloc(1, 100);
  cgraph_string_t *string = cgraph_string_calloc(1, 100);
  fprintf(stdout, "start simulation\n");
  fprintf(stdout, "%d %d\n", FRACTION_NUM(fraction), FRACTION_DEN(fraction));
  cgraph_string_initd(string, "abcd", 4);
  cgraph_bignum_initd(bignum, "123.123.123", strlen("123.123.123"));
  fprintf(stdout, "%s %d\n", bignum->data, cgraph_bignum_test(bignum));
  fprintf(stdout, "%s\n", string->data);
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
  fprintf(stdout, "%d %x\n", 3, cgraph_integer_bits(3, 1, 3));
  fprintf(stdout, "%d %x\n", 0, cgraph_integer_sets(0, 1, 3));
  fprintf(stdout, "%d %x\n", 127, cgraph_integer_clrs(127, 0, 3));
  fprintf(stdout, "%d %ld\n", 128, cgraph_integer_zeros(128));
  fprintf(stdout, "%d %ld\n", integer, cgraph_integer_hash(&integer));
  for(i = 0; i<6; i++)
  {
    cgraph_float_t data = real + number;
    cgraph_float_hash(&data);
    number = number / 10.0;
  }
  
  cgraph_file_fgets(NULL, NULL);
  
  cgraph_error_log_buffer(stdout, __FILE__, __LINE__, buffer, 100, "%s %d %d", "hello", 1 , 2);
  cgraph_error_log(stdout, __FILE__, __LINE__, "%s %d", "hello", 1);
  cgraph_error_log(stdout, __FILE__, __LINE__, "%d", cgraph_fraction_ismin(fraction));
  cgraph_string_free(string);
  cgraph_bignum_free(bignum);

  return 0;
}
