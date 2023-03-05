#include "cgraph_base.h"

/** object cgraph_bool_t header */
#include "cgraph_bool.h"

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Notice the initialization order difference of static global variables among
  various compilers and their versions, which depends on their implementations.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
static const cgraph_char_t *__cgraph_strue__ = CGRAPH_BOOL_STRUE;
static const cgraph_size_t __cgraph_strue_len__ = CGRAPH_BOOL_STRUE_LEN;
static const cgraph_size_t __cgraph_strue_size__ = (CGRAPH_BOOL_STRUE_LEN + 1);
static const cgraph_char_t *__cgraph_sfalse__ = CGRAPH_BOOL_SFALSE;
static const cgraph_size_t __cgraph_sfalse_len__ = CGRAPH_BOOL_SFALSE_LEN;
static const cgraph_size_t __cgraph_sfalse_size__ =
    (CGRAPH_BOOL_SFALSE_LEN + 1);

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  return (CGRAPH_FALSE == cthis) ? (cgraph_char_t *)__cgraph_sfalse__
                                 : (cgraph_char_t *)__cgraph_strue__;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res = CGRAPH_FALSE;
  cgraph_bool_t _error = CGRAPH_TRUE;
  if ((NULL != cstr) && (0 < len)) {
    if (__cgraph_strue_len__ == len) {
      _error = cgraph_memcmp(cstr, __cgraph_strue__, __cgraph_strue_len__);
      if (CGRAPH_TRUE == _error) {
        res = CGRAPH_TRUE;
      } else {
        _error = CGRAPH_TRUE;
      }
    } else if (__cgraph_sfalse_len__ == len) {
      _error = cgraph_memcmp(cstr, __cgraph_sfalse__, __cgraph_sfalse_len__);
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

TYPE FUNCTION(NAME, decodenc)(const cgraph_char_t *cstr,
                              const cgraph_size_t len, cgraph_bool_t *error) {
  cgraph_char_t cstr_ic[CGRAPH_BOOL_SFALSE_LEN];
  if ((__cgraph_strue_len__ != len) && (__cgraph_sfalse_len__ != len)) {
    if (NULL != error) {
      *error = CGRAPH_TRUE;
    }
    return CGRAPH_FALSE;
  }
  CGRAPH_LOOP(i, 0, len)
  cstr_ic[i] = cgraph_math_tolower(cstr[i]);
  CGRAPH_LOOP_END

  return FUNCTION(NAME, decode)(cstr_ic, len, error);
}

/** template module */
#include "template_int.ct"
