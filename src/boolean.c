#include "cgraph_boolean.h"
#include "cgraph_memory.h"

#define TYPE_BOOLEAN
#include "templete.h"
#include "data.templete"

cgraph_size_t FUNCTION(NAME, hash)(const void *cthis)
{
  TYPE object = *(TYPE *)cthis;
  cgraph_size_t hash = object == CGRAPH_FALSE ? 0 : (object == CGRAPH_TRUE ? 1 : 2);
  return hash;
}

cgraph_boolean_t FUNCTION(NAME, check)(const void *cthis)
{
  cgraph_boolean_t flag = CGRAPH_FALSE;
  if(NULL != cthis)
  {
    TYPE object = *(TYPE *)cthis;
    if(CGRAPH_TRUE == object || CGRAPH_FALSE == object)
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
    TYPE object = *(TYPE *)cthis;
    cgraph_char_t *object_str;
    cgraph_size_t object_size, object_len;
    if(CGRAPH_TRUE == object)
    {
      object_str = (cgraph_char_t *)__cgraph_true__;
      object_size = __cgraph_true_size__;
      object_len = __cgraph_true_len__;
    }
    else if(CGRAPH_FALSE == object)
    {
      object_str = (cgraph_char_t *)__cgraph_false__;
      object_size = __cgraph_false_size__;
      object_len = __cgraph_false_len__;
    }
    else
    {
      object_str = NULL;
      object_size = 0;
      object_len = 0;
    }
    if(NULL != object_str)
    {
      str = cgraph_calloc(object_size, sizeof(cgraph_char_t));
      if(NULL != str)
      {
        cgraph_strcpy(str, object_str);
        *len = object_len;
      }
      else
      { *len = 0; }
    }
    else
    {  *len = object_len; }
  }

  return str;
}

#include "templete_off.h"
