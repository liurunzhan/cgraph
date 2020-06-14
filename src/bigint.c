#include "cgraph_bigint.h"
#include "cgraph_memory.h"
#include "cgraph_math.h"

#define TYPE_BIGINT
#include "templete.h"
#include "data.templete"

/*
  BKDR Hash Algorithm
  hash = (hash * 31) + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != object)
  {
    cgraph_size_t i;
    hash = object->pos;
    for(i=0; i<object->len; i++)
    { hash = hash * 31 + object->data[i]; }
  }

  return CGRAPH_ABS(hash);
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(NULL != object)
  {
    cgraph_size_t i;
    flag = CGRAPH_TRUE;
    for(i=0; i<object->len; i++)
    {
      if((object->data[i] > 10) || (object->data[i] < 0))
      {
        flag = CGRAPH_FALSE;
        break;
      }
    }
  }

  return flag;
}

cgraph_char_t *FUNCTION(NAME, tostr)(const void *cthis, cgraph_size_t *len)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_char_t *str = NULL;
  if(NULL != object && NULL != len)
  {
    *len = object->pos ? object->len : (object->len+1);
    str = cgraph_calloc(*len+1, sizeof(cgraph_char_t));
    if(NULL != str)
    {
      cgraph_size_t i = 0;
      if(object->pos == CGRAPH_FALSE)
      {
        str[i] = '-';
        i++;
      }
      for(; i<*len; i++)
      { str[i] = object->data[i] + '0'; }
      str[i] = '\0';
    }
    else
    { *len = 0; } 
  }

  return str;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != object_x) && (NULL != object_y))
  {
    if((object_x->len == object_y->len) && (object_x->pos == object_y->pos))
    {
      flag = cgraph_memcmp(object_x->data, object_y->data, object_x->len, FUNCTION(NAME, dsize)());
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if((NULL != cthis) && (CGRAPH_FALSE == cthis->pos))
  { cthis->pos = CGRAPH_TRUE; }
  
  return cthis;
}

cgraph_boolean_t FUNCTION(NAME, ispos)(const TYPE *cthis)
{
  return CGRAPH_TEST((cthis->pos == CGRAPH_TRUE));
}

cgraph_boolean_t FUNCTION(NAME, isneg)(const TYPE *cthis)
{
  return CGRAPH_TEST((cthis->pos == CGRAPH_FALSE));
}

void *FUNCTION(NAME, add)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y, *res;
  cgraph_size_t len = CGRAPH_MAX(object_x->len, object_y->len);
  res = FUNCTION(NAME, calloc)(CGRAPH_INTEGER_T, len+1);
  if(NULL != res)
  {
    if(object_x->pos == object_y->pos)
    {
      cgraph_size_t i;
      for(i=1; i<len; i++)
      { res->data[res->len-i] = object_x->data[object_x->len-i] + object_y->data[object_y->len-i]; }
      res->pos = object_x->pos;
    }
  }

  return res;
}

TYPE *FUNCTION(NAME, tonum)(const cgraph_string_t *cthis)
{
  cgraph_size_t len = '-' == cthis->data[0] ? (cthis->len-1) : cthis->len;
  TYPE *num = cgraph_bignum_calloc(1, len);
  if(NULL != num)
  {
    cgraph_size_t i = 0;
    if('-' == cthis->data[0])
    {
      num->data[i] = '-';
      i++;
    }
    for(; i<len; i++)
    { num->data[i] = cthis->data[i]; }
  }

  return num;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis)
{
  if(NULL != cthis)
  {
    DATA_TYPE *data = cthis->data;
    while((0 == *data) && (0 < cthis->len))
    {
      cthis->len -= 1;
      data++;
    }
    cthis->data = data;
  }

  return cthis;
}

#include "templete_off.h"