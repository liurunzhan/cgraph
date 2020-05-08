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
  cgraph_size_t hash = object->pos, i;
  for(i=0; i<object->len; i++)
  { hash = hash * 31 + object->data[i]; }

  return hash;
}

void *FUNCTION(NAME, abs)(void *cthis)
{
  TYPE *object = (TYPE *)(cthis);
  object->pos = ((object->pos == CGRAPH_FALSE) ? CGRAPH_TRUE : CGRAPH_TRUE);
  
  return object;
}

cgraph_boolean_t FUNCTION(NAME, eq)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_size_t i, len = CGRAPH_MIN(object_x->len, object_y->len);
  cgraph_boolean_t flag = CGRAPH_TRUE;
  for(i=0; i<len; i++)
  {
    if(object_x->data[object_x->len-i] != object_y->data[object_y->len-i])
    {
      flag = CGRAPH_FALSE;
      break;
    }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_boolean_t flag = CGRAPH_TRUE;
  cgraph_size_t i;
  for(i=0; i<object->len; i++)
  {
    if((object->data[i] > 10) || (object->data[i] < 0))
    {
      flag = CGRAPH_FALSE;
      break;
    }
  }

  return flag;
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

cgraph_string_t *FUNCTION(NAME, tostr)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t len = object->pos ? object->len : (object->len+1);
  cgraph_string_t *str = cgraph_string_calloc(1, len);
  if(NULL != str)
  {
    cgraph_size_t i = 0;
    if(object->pos == CGRAPH_FALSE)
    {
      str->data[i] = '-';
      i++;
    }
    for(; i<len; i++)
    { str->data[i] = object->data[i] + '0'; }
    str->data[i] = '\0';
  }

  return str;
}

cgraph_bignum_t *FUNCTION(NAME, tonum)(const void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  cgraph_size_t len = object->pos ? object->len : (object->len+1);
  cgraph_bignum_t *num = cgraph_bignum_calloc(1, len);
  if(NULL != num)
  {
    cgraph_size_t i = 0;
    if(!object->pos)
    {
      num->data[i] = '-';
      i++;
    }
    for(; i<len; i++)
    { num->data[i] = object->data[i] + '0'; }
  }

  return num;
}

#include "templete_off.h"