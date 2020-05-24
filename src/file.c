#include <stdlib.h>
#include <string.h>
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
    fprintf(stderr, "FILE %s of LINE %d : %s in style %s is opened error!\n", __FILE__, __LINE__, file, mode);
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
    fprintf(stderr, "FILE %s of LINE %d : file handle is error before closed!\n", __FILE__, __LINE__);
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
      fprintf(stderr, "FILE %s of LINE %d : read a whole line in the file error\n", __FILE__, __LINE__);
      fflush(stderr);
    #endif
      error = CGRAPH_TRUE;
    }
    if((NULL == fp) || (0 != ferror(fp)))
    {
    #ifdef DEBUG
      fflush(stdout);
      fprintf(stderr, "FILE %s of LINE %d : file handle is error!\n", __FILE__, __LINE__);
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
    { fprintf(stderr, "FILE %s of LINE %d : file buffer is empty!\n", __FILE__, __LINE__); }
    if((NULL == fp) || (0 != ferror(fp)))
    { fprintf(stderr, "FILE %s of LINE %d : file handle is error!\n", __FILE__, __LINE__); }
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
    { fprintf(stderr, "FILE %s of LINE %d : file buffer is empty!\n", __FILE__, __LINE__); }
    if((NULL == fp) || (0 != ferror(fp)))
    { fprintf(stderr, "FILE %s of LINE %d : file handle is error!\n", __FILE__, __LINE__); }
    if(NULL == error)
    { fprintf(stderr, "FILE %s of LINE %d : error flag is empty!\n", __FILE__, __LINE__); }
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
        fprintf(stderr, "FILE %s of LINE %d : read %ld line error!\n", __FILE__, __LINE__, i);
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
    { fprintf(stderr, "FILE %s of LINE %d : file handle is error!\n", __FILE__, __LINE__); }
    if(NULL == buffer)
    { fprintf(stderr, "FILE %s of LINE %d : file buffer is empty!\n", __FILE__, __LINE__); }
    if(line < 0)
    { fprintf(stderr, "FILE %s of LINE %d : line number %ld is a negative number!\n", __FILE__, __LINE__, line); }
    fflush(stderr);
  }
#endif

  return flag;
}