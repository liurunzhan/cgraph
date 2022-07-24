#include "cgraph_base.h"

/** object cgraph_bool_t header */
#include "cgraph_bool.h"

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Notice the initialization order difference of static global variables among
  various compilers and their versions, which depends on their implementations.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_STRUE;
static const cgraph_size_t __cgraph_true_len__ = CGRAPH_BOOL_STRUE_LEN;
static const cgraph_size_t __cgraph_true_size__ = (CGRAPH_BOOL_STRUE_LEN + 1);
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_SFALSE;
static const cgraph_size_t __cgraph_false_len__ = CGRAPH_BOOL_SFALSE_LEN;
static const cgraph_size_t __cgraph_false_size__ = (CGRAPH_BOOL_SFALSE_LEN + 1);

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  return (CGRAPH_FALSE == cthis) ? (cgraph_char_t *)__cgraph_false__
                                 : (cgraph_char_t *)__cgraph_true__;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res = CGRAPH_FALSE;
  cgraph_bool_t _error = CGRAPH_TRUE;
  if ((NULL != cstr) && (0 < len)) {
    if (__cgraph_true_len__ == len) {
      _error = cgraph_memcmp(cstr, __cgraph_true__, __cgraph_true_len__);
      if (CGRAPH_TRUE == _error) {
        res = CGRAPH_TRUE;
      } else {
        _error = CGRAPH_TRUE;
      }
    } else if (__cgraph_false_len__ == len) {
      _error = cgraph_memcmp(cstr, __cgraph_false__, __cgraph_false_len__);
      if (CGRAPH_FALSE == _error) {
        _error = CGRAPH_TRUE;
      }
    }
  }
  if (NULL != error) {
    *error = _error;
  }

  return res;
}

/** template module */
#include "template_int.ct"
