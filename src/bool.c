#include "cgraph_bool.h"
#include "cgraph_memory.h"

#define TYPE_BOOL
#include "template.h"

/*template module*/
#include "int_base.ct"

static const cgraph_char_t *__cgraph_true__ = "true";
static const cgraph_size_t __cgraph_true_len__ = 4;
static const cgraph_size_t __cgraph_true_size__ = 5;
static const cgraph_char_t *__cgraph_false__ = "false";
static const cgraph_size_t __cgraph_false_len__ = 5;
static const cgraph_size_t __cgraph_false_size__ = 6;

cgraph_char_t *FUNCTION(NAME, tostr)(const void *cthis, cgraph_size_t *len) {
  cgraph_char_t *str = NULL;
  if (NULL != cthis && NULL != len) {
    TYPE _cthis = *(TYPE *)cthis;
    cgraph_char_t *_str;
    cgraph_size_t _size, _len;
    if (CGRAPH_TRUE == _cthis) {
      _str = (cgraph_char_t *)__cgraph_true__;
      _size = __cgraph_true_size__;
      _len = __cgraph_true_len__;
    } else if (CGRAPH_FALSE == _cthis) {
      _str = (cgraph_char_t *)__cgraph_false__;
      _size = __cgraph_false_size__;
      _len = __cgraph_false_len__;
    } else {
      _str = NULL;
      _size = 0;
      _len = 0;
    }
    if (NULL != _str) {
      str = cgraph_calloc(_size);
      if (NULL != str) {
        cgraph_strcpy(str, _str);
        *len = _len;
      } else {
        *len = 0;
      }
    } else {
      *len = _len;
    }
  }

  return str;
}

#include "template_off.h"
