#include "cgraph_memory.h"
#include "cgraph_bool.h"

#define TYPE_BOOL
#include "templete.h"
#include "data_base.ct"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE _cthis = *(TYPE *)cthis;
  cgraph_size_t hash = _cthis == CGRAPH_FALSE ? 0 : (_cthis == CGRAPH_TRUE ? 1 : 2);
  return hash;
}

cgraph_bool_t FUNCTION(NAME, check)(const void *cthis)
{
  cgraph_bool_t flag = CGRAPH_FALSE;
  if(NULL != cthis)
  {
    TYPE _cthis = *(TYPE *)cthis;
    if(CGRAPH_TRUE == _cthis || CGRAPH_FALSE == _cthis)
    { flag = CGRAPH_TRUE; }
  }

  return flag;
}

static const cgraph_char_t *__cgraph_true__ = "true";
static const cgraph_size_t __cgraph_true_len__ = 4;
static const cgraph_size_t __cgraph_true_size__ = 5;
static const cgraph_char_t *__cgraph_false__ = "false";
static const cgraph_size_t __cgraph_false_len__ = 5;
static const cgraph_size_t __cgraph_false_size__ = 6;

cgraph_char_t *FUNCTION(NAME, tostr)(const void *cthis, cgraph_size_t *len)
{
  cgraph_char_t *str = NULL;
  if(NULL != cthis && NULL != len)
  {
    TYPE _cthis = *(TYPE *)cthis;
    cgraph_char_t *_str;
    cgraph_size_t _size, _len;
    if(CGRAPH_TRUE == _cthis)
    {
      _str = (cgraph_char_t *)__cgraph_true__;
      _size = __cgraph_true_size__;
      _len = __cgraph_true_len__;
    }
    else if(CGRAPH_FALSE == _cthis)
    {
      _str = (cgraph_char_t *)__cgraph_false__;
      _size = __cgraph_false_size__;
      _len = __cgraph_false_len__;
    }
    else
    {
      _str = NULL;
      _size = 0;
      _len = 0;
    }
    if(NULL != _str)
    {
      str = cgraph_calloc(_size, sizeof(cgraph_char_t));
      if(NULL != str)
      {
        cgraph_strcpy(str, _str);
        *len = _len;
      }
      else
      { *len = 0; }
    }
    else
    {  *len = _len; }
  }

  return str;
}

#include "templete_off.h"