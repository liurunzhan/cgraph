#include <stdlib.h>
#include <string.h>
#include "cgraph_platform.h"
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

cgraph_bool_t cgraph_file_fclose(FILE *fp)
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

cgraph_bool_t cgraph_file_fgets(cgraph_string_t *buffer, FILE *fp)
{
  cgraph_bool_t error = CGRAPH_FALSE;
  if((NULL != buffer) && (NULL != fp) && (0 == ferror(fp)))
  {
    char *data;
    fpos_t fp_init;
    fgetpos(fp, &fp_init);
    while((NULL != (data = fgets(buffer->data, buffer->size+1, fp))) && (buffer->data[buffer->size-1] != '\0') && (buffer->data[buffer->size-1] != '\n') && (buffer->data[buffer->size-1] != '\r'))
    {
      buffer = cgraph_string_realloc(buffer, CGRAPH_STRING_T, buffer->size, 2*buffer->size, &error);
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

cgraph_string_t *cgraph_file_header(FILE *fp, cgraph_string_t *buffer, cgraph_bool_t *error)
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
  cgraph_int_t error = 0;
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

cgraph_bool_t cgraph_file_line(cgraph_string_t *buffer, FILE *fp, const cgraph_size_t line)
{
  cgraph_size_t i;
  cgraph_bool_t flag = CGRAPH_FALSE;
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


static const cgraph_char_t *_platform = CGRAPH_PLAT_MODE;
static const cgraph_char_t *_path_split = CGRAPH_PLAT_PSPLIT;
static const cgraph_char_t *_file_end = CGRAPH_PLAT_FEND;

const static union cgraph_endian_t 
{
  cgraph_int32_t num;
  cgraph_int8_t byte[4];
} cgraph_file_endian = {1};

void cgraph_file_os(cgraph_char_t **os, cgraph_char_t **sep, cgraph_char_t **end, cgraph_bool_t *isbigendian)
{
  *os = (cgraph_char_t *)_platform;
  *sep = (cgraph_char_t *)_path_split;
  *end = (cgraph_char_t *)_file_end;
  if(NULL != isbigendian)
  { *isbigendian = (cgraph_file_endian.byte[3] ? CGRAPH_FALSE : CGRAPH_TRUE); }
}