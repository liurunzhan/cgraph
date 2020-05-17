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

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != object_x) && (NULL != object_y))
  {
    if((object_x->len == object_y->len) && (object_x->pos == object_y->pos) && (CGRAPH_TRUE == cgraph_memcmp(object_x->data, object_y->data, object_x->len, FUNCTION(NAME, dsize)())))
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if(CGRAPH_FALSE == cthis->pos)
  { cthis->pos = CGRAPH_TRUE; }
  
  return cthis;
}

cgraph_boolean_t FUNCTION(NAME, test)(const TYPE *cthis)
{
  cgraph_boolean_t flag = CGRAPH_TRUE;
  cgraph_size_t i;
  for(i=0; i<cthis->len; i++)
  {
    if((cthis->data[i] > 10) || (cthis->data[i] < 0))
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

cgraph_string_t *FUNCTION(NAME, tostr)(const TYPE *cthis)
{
  cgraph_size_t len = cthis->pos ? cthis->len : (cthis->len+1);
  cgraph_string_t *str = cgraph_string_calloc(1, len);
  if(NULL != str)
  {
    cgraph_size_t i = 0;
    if(cthis->pos == CGRAPH_FALSE)
    {
      str->data[i] = '-';
      i++;
    }
    for(; i<len; i++)
    { str->data[i] = cthis->data[i] + '0'; }
    str->data[i] = '\0';
  }

  return str;
}

TYPE *FUNCTION(NAME, tonum)(const cgraph_string_t *cthis)
{
  cgraph_size_t len = cthis->data[0] == '-' ? (cthis->len-1) : cthis->len;
  TYPE *num = cgraph_bignum_calloc(1, len);
  if(NULL != num)
  {
    cgraph_size_t i = 0;
    if('-' != cthis->data[0])
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
  cgraph_size_t i= 0;
  while((0 == cthis->data[i]) && (i < cthis->len))
  { i++; }
  cthis->data = &(cthis->data[i]);
  cthis->len -= i;

  return cthis;
}

#include "templete_off.h"