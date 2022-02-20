#include "cgraph_base.h"

/***/
#include "cgraph_logic.h"

/** template module */
#include "template_int.ct"

static const cgraph_char_t *__cgraph_L0__ = CGRAPH_LOGIC_L0;
static const cgraph_char_t *__cgraph_L1__ = CGRAPH_LOGIC_L1;
static const cgraph_char_t *__cgraph_LZ__ = CGRAPH_LOGIC_LZ;
static const cgraph_char_t *__cgraph_LX__ = CGRAPH_LOGIC_LX;

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis) {
  cgraph_char_t *res = NULL;
  switch (cthis) {
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
    cgraph_file_fprintf(stderr, "undefined logic value");
    break;
  }
  }

  return res;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr, const cgraph_size_t len,
                            cgraph_bool_t *error) {
  TYPE res = CGRAPH_LX;
  cgraph_bool_t _error = CGRAPH_TRUE;
  if (NULL != cstr) {
    _error = CGRAPH_FALSE;
    switch (cstr[0]) {
    case '0': {
      res = CGRAPH_L0;
      break;
    }
    case '1': {
      res = CGRAPH_L1;
      break;
    }
    case 'Z':
    case 'z': {
      res = CGRAPH_LZ;
      break;
    }
    case 'X':
    case 'x': {
      res = CGRAPH_LX;
      break;
    }
    default: {
      cgraph_file_fprintf(stderr, "undefined logic value %c", cstr[0]);
      _error = CGRAPH_TRUE;
      break;
    }
    }
  }
  if (NULL != error) {
    *error = _error;
  }

  return res;
}

TYPE *FUNCTION(NAME, decodes)(const cgraph_char_t *cstr,
                              const cgraph_size_t len, cgraph_bool_t *error,
                              TYPE *cthis) {
  cgraph_bool_t _error = CGRAPH_TRUE;
  if (NULL != cstr) {
    _error = CGRAPH_FALSE;
    CGRAPH_LOOP(i, 0, len)
    switch (cstr[i]) {
    case '0': {
      cthis[i] = CGRAPH_L0;
      break;
    }
    case '1': {
      cthis[i] = CGRAPH_L1;
      break;
    }
    case 'Z':
    case 'z': {
      cthis[i] = CGRAPH_LZ;
      break;
    }
    case 'X':
    case 'x': {
      cthis[i] = CGRAPH_LX;
      break;
    }
    default: {
      cgraph_file_fprintf(stderr, "undefined logic value %c at %ld", cstr[i],
                          i);
      _error = CGRAPH_TRUE;
      break;
    }
    }
    CGRAPH_LOOP_END
  }
  if (NULL != error) {
    *error = _error;
  }

  return cthis;
}

cgraph_bool_t FUNCTION(NAME, leq)(const TYPE x, const TYPE y) {
  return CGRAPH_TEST(DATA_EQ(x, y));
}

cgraph_bool_t FUNCTION(NAME, lne)(const TYPE x, const TYPE y) {
  return CGRAPH_TEST(DATA_NE(x, y));
}
