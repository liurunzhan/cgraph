#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgraph_memory.h"
#include "cgraph_string.h"
#include "cgraph_file.h"

FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode)
{
  FILE *fp;
  if(NULL == (fp = fopen(file, mode)))
  {
    fprintf(stderr, "%s in style %s is opened error!\n", file, mode);
    fflush(stderr);
    abort();
  }

  return fp;
}

cgraph_boolean_t cgraph_file_fclose(FILE *fp)
{
  if(0 != ferror(fp))
  {
    fprintf(stderr, "The file handle is error before closed!\n");
    fflush(stderr);
    clearerr(fp);
  }

  return CGRAPH_TEST(fclose(fp) == 0);
}

cgraph_size_t cgraph_file_rows(FILE *fp)
{
  cgraph_size_t rows = 0;
  if(0 == ferror(fp))
  {
    char ch;
    rewind(fp);
    while(!feof(fp))
    {
      if(ch=fgetc(fp) == '\n')
        rows += 1;
    }
    rewind(fp);
  }

  return rows;
}

cgraph_string_t *cgraph_file_getheader(FILE *fp, cgraph_string_t *buffer, cgraph_boolean_t *error)
{
  if(0 == ferror(fp))
  {
    rewind(fp);
    while(NULL != fgets(buffer->data, buffer->size+1, fp) && buffer->data[buffer->size-1] != '\0' && buffer->data[buffer->size-1] != '\n')
    {
      buffer->data = cgraph_realloc(buffer->data, buffer->size, 2*buffer->size, sizeof(char), error);
      if(*error == 0)
      {
        buffer->size *= 2;
      }
      rewind(fp);
    }
  }

  return buffer;
}

cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep, cgraph_string_t *buffer)
{
  cgraph_size_t columns = 0;
  cgraph_integer_t error = 0;
  char *str = NULL;
  buffer = cgraph_file_getheader(fp, buffer, &error);
  str = strtok(buffer->data, sep);
  while(NULL != str)
  {
    columns += 1;
    str = strtok(NULL, sep);
  }

  return columns;
}

void *cgraph_file_fread(void *gthis, FILE *fp, cgraph_string_t *buffer)
{
  

  return gthis;
}