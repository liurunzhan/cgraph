#include <stdlib.h>
#include <string.h>
#include "cgraph_error.h"
#include "cgraph_memory.h"
#include "cgraph_string.h"
#include "cgraph_file.h"

FILE *cgraph_file_fopen(cgraph_char_t *file, cgraph_char_t *mode)
{
  FILE *fp = fopen(file, mode);
  if(NULL == fp)
  {
  #ifdef DEBUG
    fflush(stdout);
    cgraph_error_log(stderr, __FILE__, __LINE__, "%s in style %s is opened error", file, mode);
    fflush(stderr);
  #endif
    abort();
  }

  return fp;
}

cgraph_boolean_t cgraph_file_fclose(FILE *fp)
{
  if((NULL == fp) || (0 != ferror(fp)))
  {
  #ifdef DEBUG
    fflush(stdout);
    cgraph_error_log(stderr, __FILE__, __LINE__, "file handle is error before closed");
    fflush(stderr);
  #endif
    clearerr(fp);
    abort();
  }

  return CGRAPH_TEST(0 == fclose(fp));
}

cgraph_boolean_t cgraph_file_fgets(cgraph_string_t *buffer, FILE *fp)
{
  cgraph_boolean_t error = CGRAPH_FALSE;
  if((NULL != buffer) && (NULL != fp) && (0 == ferror(fp)))
  {
    char *data;
    fpos_t fp_init;
    fgetpos(fp, &fp_init);
    while((NULL != (data = fgets(buffer->data, buffer->size+1, fp))) && (buffer->data[buffer->size-1] != '\0') && (buffer->data[buffer->size-1] != '\n') && (buffer->data[buffer->size-1] != '\r'))
    {
      cgraph_string_realloc(buffer, buffer->size, 2*buffer->size, &error);
      fsetpos(fp, &fp_init);
      if(CGRAPH_TRUE == error)
      { break; }
    }
    if(NULL == data)
    {
    #ifdef DEBUG
      fflush(stdout);
      cgraph_error_log(stderr, __FILE__, __LINE__, "read a whole line in the file error");
      fflush(stderr);
    #endif
      error = CGRAPH_TRUE;
    }
    if((NULL == fp) || (0 != ferror(fp)))
    {
    #ifdef DEBUG
      fflush(stdout);
      cgraph_error_log(stderr, __FILE__, __LINE__, "file handle is error");
      fflush(stderr);
    #endif
      error = CGRAPH_TRUE;
    }
  }
  else
  {
  #ifdef DEBUG
    fflush(stdout);
    if(NULL == buffer)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "file buffer is empty"); }
    if((NULL == fp) || (0 != ferror(fp)))
    { cgraph_error_log(stderr, __FILE__, __LINE__, "file handle is error"); }
    fflush(stderr);
  #endif
    error = CGRAPH_TRUE;
  }

  return error;
}

cgraph_string_t *cgraph_file_header(FILE *fp, cgraph_string_t *buffer, cgraph_boolean_t *error)
{
  if((NULL != fp) && (0 == ferror(fp)) && (NULL != buffer) && (NULL != error))
  {
    rewind(fp);
    *error = cgraph_file_fgets(buffer, fp);
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if(NULL != buffer)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "file buffer is empty"); }
    if((NULL == fp) || (0 != ferror(fp)))
    { cgraph_error_log(stderr, __FILE__, __LINE__, "file handle is error"); }
    if(NULL == error)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "error flag is empty"); }
    fflush(stderr);
  }
#endif
  
  return buffer;
}

cgraph_size_t cgraph_file_rows(FILE *fp)
{
  cgraph_size_t rows = 0;
  if(0 == ferror(fp))
  {
    char ch;
    rewind(fp);
    while(0 != feof(fp))
    {
      if('\n' == (ch=fgetc(fp)))
      { rows += 1; }
    }
    rewind(fp);
  }

  return rows;
}

cgraph_size_t cgraph_file_columns(FILE *fp, cgraph_char_t *sep, cgraph_string_t *buffer)
{
  cgraph_size_t columns = 0;
  cgraph_integer_t error = 0;
  char *str = NULL;
  buffer = cgraph_file_header(fp, buffer, &error);
  str = strtok(buffer->data, sep);
  while(NULL != str)
  {
    columns += 1;
    str = strtok(NULL, sep);
  }

  return columns;
}

cgraph_boolean_t cgraph_file_line(cgraph_string_t *buffer, FILE *fp, const cgraph_size_t line)
{
  cgraph_size_t i;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != fp) && (0 == ferror(fp)) && (NULL != buffer) && (0 <= line))
  {
    for(i=0; i<line; i++)
    {
      flag = cgraph_file_fgets(buffer, fp);
      if(CGRAPH_TRUE == flag)
      {
      #ifdef DEBUG
        fflush(stdout);
        cgraph_error_log(stderr, __FILE__, __LINE__, "read %ld line error", i);
        fflush(stderr);
      #endif
        break;
      }
    }
  }
#ifdef DEBUG
  else
  {
    fflush(stdout);
    if((NULL == fp) || (0 != ferror(fp)))
    { cgraph_error_log(stderr, __FILE__, __LINE__, "file handle is error"); }
    if(NULL == buffer)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "file buffer is empty"); }
    if(line < 0)
    { cgraph_error_log(stderr, __FILE__, __LINE__, "line number %ld is a negative number", line); }
    fflush(stderr);
  }
#endif

  return flag;
}
