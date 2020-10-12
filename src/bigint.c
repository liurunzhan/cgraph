#include "cgraph_bigint.h"
#include "cgraph_memory.h"
#include "cgraph_math.h"

#define TYPE_BIGINT
#include "templete.h"
#include "data_base.ct"

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

cgraph_boolean_t FUNCTION(NAME, check)(const void *cthis)
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

cgraph_string_t *FUNCTION(NAME, tostr)(const TYPE *cthis)
{
  cgraph_string_t *str = NULL;
  if(NULL != cthis)
  {
    cgraph_size_t len = cthis->pos ? cthis->len : (cthis->len+1);
    str = cgraph_string_calloc(1, len+1);
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
  }

  return str;
}

cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y;

  return EQ(object_x, object_y);
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if(NULL != cthis)
  { cthis->pos = CGRAPH_TRUE; }
  
  return cthis;
}

cgraph_boolean_t FUNCTION(NAME, ispos)(const TYPE *cthis)
{
  return cthis->pos;
}

cgraph_boolean_t FUNCTION(NAME, isneg)(const TYPE *cthis)
{
  return CGRAPH_TEST((!cthis->pos));
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z)
{
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len);
  TYPE *res = FUNCTION(NAME, calloc)(CGRAPH_INTEGER_T, len+1);
  if(NULL != res)
  {
    if(x->pos == y->pos)
    {
      cgraph_size_t i;
      for(i=1; i<len; i++)
      { res->data[res->len-i] = x->data[x->len-i] + y->data[y->len-i]; }
      res->pos = x->pos;
    }
  }

  return res;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y, *res = NULL;
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

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z)
{
  TYPE *object_x = (TYPE *)x, *object_y = (TYPE *)y, *res = NULL;
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

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z)
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

cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if((x->len == y->len) && (x->pos == y->pos))
    {
      cgraph_size_t i;
      for(i=x->len-1; i>=0; i--)
      {
        if(x->data[i] != y->data[i])
        { break; }
      }
      if(i < 0)
      { flag = CGRAPH_TRUE; }
    }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if((x->len == y->len) && (x->pos == y->pos))
    {
      cgraph_size_t i;
      for(i=x->len-1; i>=0; i--)
      {
        if(x->data[i] == y->data[i])
        { break; }
      }
      if(i < 0)
      { flag = CGRAPH_TRUE; }
    }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->pos == y->pos)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] <= y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] >= y->data[i])
          { break; }
        }
      }
      if(i < 0)
      { flag = CGRAPH_TRUE; }
    }
    else if(CGRAPH_TRUE == x->pos && CGRAPH_FALSE == y->pos)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->pos == y->pos)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] < y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] > y->data[i])
          { break; }
        }
      }
      if(i < 0)
      { flag = CGRAPH_TRUE; }
    }
    else if(CGRAPH_TRUE == x->pos && CGRAPH_FALSE == y->pos)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->pos == y->pos)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] >= y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] <= y->data[i])
          { break; }
        }
      }
      if(i < 0)
      { flag = CGRAPH_TRUE; }
    }
    else if(CGRAPH_FALSE == x->pos && CGRAPH_TRUE == y->pos)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_boolean_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->pos == y->pos)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] > y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->pos)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] < y->data[i])
          { break; }
        }
      }
      if(i < 0)
      { flag = CGRAPH_TRUE; }
    }
    else if(CGRAPH_FALSE == x->pos && CGRAPH_TRUE == y->pos)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

TYPE *FUNCTION(NAME, tonum)(const cgraph_string_t *cthis)
{
  cgraph_size_t len = '-' == cthis->data[0] ? (cthis->len-1) : cthis->len;
  TYPE *num = FUNCTION(NAME, calloc)(1, len);
  if(NULL != num)
  {
    cgraph_size_t i = 0;
    if('-' == cthis->data[0])
    {
      num->pos = CGRAPH_FALSE;
      i++;
    }
    for(; i<len; i++)
    { num->data[i] = cthis->data[i] - '0'; }
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

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"
