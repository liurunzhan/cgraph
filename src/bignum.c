#include <ctype.h>
#include "cgraph_memory.h"
#include "cgraph_bignum.h"

#define TYPE_BIGNUM
#include "templete.h"
#include "data_base.ct"

/*
  BKDR Hash Algorithm
  hash = (hash * 31) + (cthis->data[i] - '0')
*/
cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_size_t hash = 0, i;
  for(i=0; i<_cthis->len; i++)
  { hash = (hash * 31) + (_cthis->data[i] - '0'); }

  return CGRAPH_ABS(hash);
}

cgraph_bool_t FUNCTION(NAME, check)(const void *cthis)
{
  TYPE *_cthis = (TYPE *)cthis;
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != _cthis)
  {
    cgraph_size_t i = 0;
    flag = CGRAPH_TRUE;
    if(('+' == _cthis->data[i]) || ('-' == _cthis->data[i]))
    { i++; }
    else
    {
      cgraph_bool_t point_cnt = 0;
      for(; i<_cthis->len; i++)
      {
        if('0' > _cthis->data[i] || '9' < _cthis->data[i])
        {
          if('.' == _cthis->data[i])
          {  point_cnt++; }
          if(1 < point_cnt)
          {
            flag = CGRAPH_FALSE;
            break;
          }
        }
      }
    }
  }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, equal)(const void *x, const void *y)
{
  TYPE *_x = (TYPE *)x, *_y = (TYPE *)y;
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != _x) && (NULL != _y))
  {
    if(_x->len == _y->len)
    {
      flag = cgraph_memcmp(_x->data, _y->data, _x->len*FUNCTION(NAME, dsize)());
    }
  }

  return flag;
}

TYPE *FUNCTION(NAME, abs)(TYPE *cthis)
{
  if((NULL != cthis) && ('-' == cthis->data[0]))
  {
    cthis->data = &(cthis->data[1]);
    cthis->len -= 1;
  }

  return cthis;
}

TYPE *FUNCTION(NAME, format)(TYPE *cthis)
{
  if(NULL != cthis)
  {
    DATA_TYPE *data = cthis->data;
    while(((' ' == *data) || ('0' == *data)) && (0 < cthis->len))
    {
      cthis->len -= 1;
      data++;
    }
    cthis->data = data;
  }

  return cthis;
}


TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return NULL;
}

TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return NULL;
}

TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return NULL;
}

TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z)
{
  return NULL;
}

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if((x->len == y->len) && (x->point == y->point))
    {
      if(x->data[0] == y->data[0])
      {
        cgraph_size_t i;
        for(i=x->point-1; i>=0; i--)
        {
          if(x->data[i] != y->data[i])
          { break; }
        }
        if(i < 0)
        {
          for(i=x->point; i<x->len; i++)
          {
            if(x->data[i] != y->data[i])
            { break; }
          }
          if(i >= x->len)
          { flag = CGRAPH_TRUE; }
        }
      }
    }
  }
  else if((NULL == x) && (NULL == y))
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if((x->len == y->len) && (x->point == y->point))
    {
      if(x->data[0] == y->data[0])
      {
        cgraph_size_t i;
        for(i=x->point-1; i>=0; i--)
        {
          if(x->data[i] == y->data[i])
          { break; }
        }
        if(i < 0)
        {
          for(i=x->point; i<x->len; i++)
          {
            if(x->data[i] == y->data[i])
            { break; }
          }
          if(i >= x->len)
          { flag = CGRAPH_TRUE; }
        }
      }
    }
  }
  else if(NULL != x && NULL == y)
  { flag = CGRAPH_TRUE; }
  else if(NULL == x && NULL != y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->data[0] == y->data[0])
    {
      cgraph_size_t i, j;
      for(i=x->point-1, j=y->point-1; i>=0 && j >= 0; i--, j--)
      {
        if(x->data[i] <= y->data[j])
        { break; }
      }
      if(i < 0)
      {
        for(i=x->point, j=y->point; i<x->len && j<y->len; i++, j++)
        {
          if(x->data[i] <= y->data[j])
          { break; }
        }
        if(i >= x->len )
        { flag = CGRAPH_TRUE; }
      }
    }
    else if('-' == y->data[0])
    { flag = CGRAPH_TRUE; }
  }
  else if(NULL != x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->data[0] == y->data[0])
    {
      cgraph_size_t i, j;
      for(i=x->point-1, j=y->point-1; i>=0 && j >= 0; i--, j--)
      {
        if(x->data[i] < y->data[j])
        { break; }
      }
      if(i < 0)
      {
        for(i=x->point, j=y->point; i<x->len && j<y->len; i++, j++)
        {
          if(x->data[i] < y->data[j])
          { break; }
        }
        if(i >= x->len )
        { flag = CGRAPH_TRUE; }
      }
    }
    else if('-' == y->data[0])
    { flag = CGRAPH_TRUE; }
  }
  else if(NULL != x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->data[0] == y->data[0])
    {
      cgraph_size_t i, j;
      for(i=x->point-1, j=y->point-1; i>=0 && j >= 0; i--, j--)
      {
        if(x->data[i] <= y->data[j])
        { break; }
      }
      if(i < 0)
      {
        for(i=x->point, j=y->point; i<x->len && j<y->len; i++, j++)
        {
          if(x->data[i] <= y->data[j])
          { break; }
        }
        if(i >= x->len )
        { flag = CGRAPH_TRUE; }
      }
    }
    else if('-' == y->data[0])
    { flag = CGRAPH_TRUE; }
  }
  else if(NULL != x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

cgraph_bool_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if((NULL != x) && (NULL != y))
  {
    if(x->data[0] == y->data[0])
    {
      cgraph_size_t i, j;
      for(i=x->point-1, j=y->point-1; i>=0 && j >= 0; i--, j--)
      {
        if(x->data[i] <= y->data[j])
        { break; }
      }
      if(i < 0)
      {
        for(i=x->point, j=y->point; i<x->len && j<y->len; i++, j++)
        {
          if(x->data[i] <= y->data[j])
          { break; }
        }
        if(i >= x->len )
        { flag = CGRAPH_TRUE; }
      }
    }
    else if('-' == y->data[0])
    { flag = CGRAPH_TRUE; }
  }
  else if(NULL != x && NULL == y)
  { flag = CGRAPH_TRUE; }

  return flag;
}

#include "templete_off.h"
