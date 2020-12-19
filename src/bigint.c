#include "cgraph_memory.h"
#include "cgraph_math.h"
#include "cgraph_bigint.h"

#define TYPE_BIGINT
#include "templete.h"
#include "data_base.ct"

/**
  @brief BKDR Hash Algorithm
  hash = (hash * 31) + cthis->data[i]
*/
cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0;
  if(NULL != _cthis)
  {
    cgraph_size_t i;
    hash = _cthis->postive;
    for(i=0; i<_cthis->len; i++)
    { hash = hash * 31 + _cthis->data[i]; }
  }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != _cthis)
  {
    cgraph_size_t i;
    flag = CGRAPH_TRUE;
    for(i=0; i<_cthis->len; i++)
    {
      if((_cthis->data[i] > 10) || (_cthis->data[i] < 0))
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
    cgraph_size_t len = cthis->postive ? cthis->len : (cthis->len+1);
    str = cgraph_string_calloc(1, len+1);
    if(NULL != str)
    {
      cgraph_size_t i = 0;
      if(cthis->postive == CGRAPH_FALSE)
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

cgraph_bool_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;

  return EQ(_x, _y);
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if(NULL != cthis)
  { cthis->postive = CGRAPH_TRUE; }
  
  return cthis;
}

cgraph_bool_t FUNCTION(NAME, ispos)(const TYPE *cthis)
{
  return cthis->postive;
}

cgraph_bool_t FUNCTION(NAME, isneg)(const TYPE *cthis)
{
  return CGRAPH_TEST((!cthis->postive));
}

TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z)
{
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len) + 1;
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if(CGRAPH_FALSE == error)
  {
    cgraph_size_t i;
    DATA_TYPE *xd = &(x->data[x->len-1]), *yd = &(y->data[y->len-1]), *zd = &(z->data[z->len-1]);
    for(i=1; i<len; i++, xd--, yd--, zd--)
    { *zd = *xd + *yd; }
    z->postive = x->postive;
  }

  return z;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z)
{
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len) + 1;
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if(CGRAPH_FALSE == error)
  {
    cgraph_size_t i;
    DATA_TYPE *xd = &(x->data[x->len-1]), *yd = &(y->data[y->len-1]), *zd = &(z->data[z->len-1]);
    for(i=1; i<len; i++, xd--, yd--, zd--)
    {
      *zd = *xd - *yd;
    }
    z->postive = x->postive;
  }

  return z;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z)
{
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len) + 1;
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if(CGRAPH_FALSE == error)
  {
    cgraph_size_t i;
    DATA_TYPE *xd = &(x->data[x->len-1]), *yd = &(y->data[y->len-1]), *zd = &(z->data[z->len-1]);
    for(i=1; i<len; i++, xd--, yd--, zd--)
    {
      *zd = (*xd) * (*yd);
    }
    z->postive = x->postive;
  }

  return z;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z)
{
  cgraph_size_t len = CGRAPH_MAX(x->len, y->len) + 1;
  cgraph_bool_t error = CGRAPH_FALSE;
  z = FUNCTION(NAME, realloc)(z, DATA_ID, 0, len, &error);
  if(CGRAPH_FALSE == error)
  {
    if(x->postive == y->postive)
    {
      cgraph_size_t i;
      DATA_TYPE *xd = &(x->data[x->len-1]), *yd = &(y->data[y->len-1]), *zd = &(z->data[z->len-1]);
      for(i=1; i<len; i++, xd--, yd--, zd--)
      { z->data[z->len-i] = x->data[x->len-i] + y->data[y->len-i]; }
      z->postive = x->postive;
    }
  }

  return z;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y) && (x->postive == y->postive))
  {
    cgraph_size_t i, min = CGRAPH_MIN(x->len, y->len);
    DATA_TYPE *xd = &(x->data[x->len-1]), *yd = &(y->data[y->len-1]);
    for(i=0; i<min; i++, xd--, yd--)
    {
      if(*xd != *yd)
      { break; }
    }
    if(i >= min)
    {
      for(i=min; i<x->len; i++, xd--)
      {
        if(0 != *xd)
        { break; }
      }
      for(i=min; i<y->len; i++, yd--)
      {
        if(0 != *yd)
        { break; }
      }
      if((i >= x->len) && (i >= y->len))
      { flag = CGRAPH_TRUE; }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y)
{
  return CGRAPH_FALSE == FUNCTION(NAME, eq)(x, y);
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->postive == y->postive)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->postive)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] <= y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->postive)
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
    else if(CGRAPH_TRUE == x->postive && CGRAPH_FALSE == y->postive)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->postive == y->postive)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->postive)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] < y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->postive)
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
    else if(CGRAPH_TRUE == x->postive && CGRAPH_FALSE == y->postive)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->postive == y->postive)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->postive)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] >= y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->postive)
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
    else if(CGRAPH_FALSE == x->postive && CGRAPH_TRUE == y->postive)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->postive == y->postive)
    {
      cgraph_size_t i, len = CGRAPH_MIN(x->len, y->len);
      if(CGRAPH_TRUE == x->postive)
      {
        for(i=len-1; i>=0; i--)
        {
          if(x->data[i] > y->data[i])
          { break; }
        }
      }
      else if(CGRAPH_FALSE == x->postive)
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
    else if(CGRAPH_FALSE == x->postive && CGRAPH_TRUE == y->postive)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

TYPE *FUNCTION(NAME, fromstr)(const cgraph_string_t *cthis)
{
  cgraph_size_t len = '-' == cthis->data[0] ? (cthis->len-1) : cthis->len;
  TYPE *object = FUNCTION(NAME, calloc)(1, len);
  if(NULL != object)
  {
    cgraph_size_t i = 0;
    if('-' == cthis->data[i])
    {
      object->postive = CGRAPH_FALSE;
      i++;
    }
    for(; i<len; i++)
    { object->data[i] = cthis->data[i] - '0'; }
  }

  return object;
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
