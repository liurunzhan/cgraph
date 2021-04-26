#include "cgraph.h"
#include <stdio.h>
#include <stdlib.h>

void printf_char(char data) {
  printf("debug %x %x\n", 0xFF & data, 0xFF & data);
}

#define CGRAPH_ZERO                                                            \
  {                                                                            \
    { 0.0, 0.0 }                                                               \
  }

cgraph_float64_t function_x(cgraph_float64_t x) { return x * x; }

int main(int argc, char *argv[]) {
  /*
  cgraph_char_t buffer[100];
  cgraph_fraction_t fraction = {-1, INT_MAX};
  cgraph_int_t integer = 123;
  cgraph_float32_t real = 123.0, number = 0.1;
  cgraph_size_t i = 0;
  cgraph_int8_t pre = 0xFF, data = 0x00, poly = 0x07;
  cgraph_bignum_t *bignum = cgraph_bignum_calloc(1, 100);
  cgraph_string_t *string = cgraph_string_calloc(1, 100);
  cgraph_int_t primes[100000];
  cgraph_int_t numbers[100000];
  fprintf(stdout, "start simulation\n");
  fprintf(stdout, "%d %d\n", FRACTION_NUM(fraction), FRACTION_DEN(fraction));
  cgraph_string_initd(string, "abcd", 4);
  cgraph_bignum_initd(bignum, "123.123.123", strlen("123.123.123"));
  fprintf(stdout, "%s %d\n", bignum->data, cgraph_bignum_check(bignum));
  fprintf(stdout, "%s\n", string->data);
  printf_char(pre);
  fprintf(stdout, "%x\n", cgraph_int8_ones(pre));
  cgraph_math_primes(primes, numbers, 10000);
  */
  /*
  if(argc == 2)
  {
  cgraph_string_t *buffer = cgraph_string_calloc(CGRAPH_STRING_T, 1000);
  char *file = argv[1];
  FILE *fp = cgraph_file_fopen(file, "r");
  cgraph_size_t row = cgraph_file_rows(fp);
  cgraph_size_t column = cgraph_file_columns(fp, ",", buffer);
  cgraph_object_t *abc;
  cgraph_int_t i;
  fprintf(stdout, "row: %ld column : %ld\n", row, column);
  cgraph_file_fclose(fp);
  cgraph_string_free(buffer);
  for(i=CGRAPH_INT_T; i<CGRAPH_FRACTION_T; i++)
  {
    abc = cgraph_object_calloc(i, 100);
    cgraph_object_free(abc);
  }
  do
  {
    cgraph_bigint_t *big = cgraph_bigint_calloc(CGRAPH_INT_T, 2);
    cgraph_int_t data[2] = {1,1};
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
  /*
  fprintf(stdout, "%d %x\n", 3, cgraph_integer_bits(3, 1, 3));
  fprintf(stdout, "%d %x\n", 0, cgraph_integer_sets(0, 1, 3));
  fprintf(stdout, "%d %x\n", 127, cgraph_integer_clrs(127, 0, 3));
  fprintf(stdout, "%d %ld\n", 128, cgraph_integer_zeros(128));
  fprintf(stdout, "%d %ld\n", integer, cgraph_integer_hash(&integer));
  fprintf(stdout, "crc32 : %02x\n",  cgraph_math_crc(pre, data, poly));
  for(i = 0; i<6; i++)
  {
  cgraph_float32_t data = real + number;
  cgraph_float_hash(&data);
  number = number / 10.0;
  }

  cgraph_file_fgets(NULL, NULL);

  cgraph_verilog_test();

  cgraph_error_log_buffer(stdout, buffer, 100, __FILE__, __LINE__,
  __FUNCTION, "%s %d %d", "hello", 1 , 2); cgraph_error_log(stdout,
  __FILE__, __LINE__, __FUNCTION, "%s %d", "hello", 1);
  cgraph_error_log(stdout, __FILE__, __LINE__, __FUNCTION, "%d",
  cgraph_fraction_ismin(fraction)); cgraph_string_free(string);
  cgraph_bignum_free(bignum);
  */
  /* cgraph_error_print(2);
     cgraph_string_test(); */
  /* cgraph_bigint_test(); */
  /*
  cgraph_version_test();
  cgraph_verilog_test();
  printf("%ld\n", cgraph_pobject_msize(CGRAPH_POBJECT_T, 10));
  */
  cgraph_complex_t x = CGRAPH_ZERO;
  cgraph_char_t *data = " abc[20] | _abc123", *name = &data[1];
  cgraph_bool_t flag;
  cgraph_int_t old[10], new[20], old_base = 10, new_base = 16;
  cgraph_size_t old_len = 10, new_len = 20, len;
  fprintf(stdout, "hello world!\n");
  fprintf(stdout, "%s %ld\n", name, cgraph_math_lenofname(name, &flag));
  old[0] = 1;
  old[1] = 1;
  old[2] = 2;
  fprintf(stdout, "old number : %d%d%d\n", old[0], old[1], old[2]);
  len = cgraph_math_chgbase(old, 3, old_base, new, new_len, new_base);
  fprintf(stdout, "new number %ld : %d%d\n", len, new[1], new[0]);

  return 0;
}
