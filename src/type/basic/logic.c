#include "cgraph_base.h"

/***/
#include "cgraph_logic.h"

/** template module */
#include "template_int.ct"

static const cgraph_char_t *__cgraph_L0__ = CGRAPH_LOGIC_L0;
static const cgraph_char_t *__cgraph_L1__ = CGRAPH_LOGIC_L1;
static const cgraph_char_t *__cgraph_LZ__ = CGRAPH_LOGIC_LZ;
static const cgraph_char_t *__cgraph_LX__ = CGRAPH_LOGIC_LX;

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE x) {
  cgraph_char_t *res = NULL;
  switch (x) {
  case CGRAPH_L0: {
    res = (cgraph_char_t *)__cgraph_L0__;
    break;
  }
  case CGRAPH_L1: {
    res = (cgraph_char_t *)__cgraph_L1__;
    break;
  }
  case CGRAPH_LZ: {
    res = (cgraph_char_t *)__cgraph_LZ__;
    break;
  }
  case CGRAPH_LX: {
    res = (cgraph_char_t *)__cgraph_LX__;
    break;
  }
  default: {
#ifdef DEBUG

#endif
    break;
  }
  }

  return res;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res = CGRAPH_LX;
  if (NULL != error) {
    *error = CGRAPH_FALSE;
  }
  if ((NULL != cstr) && (1 == len)) {
    if ('0' == cstr[0]) {
      res = CGRAPH_L0;
    } else if ('1' == cstr[0]) {
      res = CGRAPH_L1;
    } else if (('Z' == cstr[0]) || ('z' == cstr[0])) {
      res = CGRAPH_LZ;
    } else if (('X' == cstr[0]) || ('x' == cstr[0])) {
      res = CGRAPH_LX;
    } else if (NULL != error) {
      *error = CGRAPH_TRUE;
    }
  }

  return res;
}
