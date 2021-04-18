#include "cgraph_base.h"
#include "cgraph_logic.h"

#define TYPE_LOGIC
#include "cgraph_template.h"

/** template module */
#include "template_int.ct"

static const cgraph_char_t *__cgraph_L0__ = CGRAPH_LOGIC_L0;
static const cgraph_char_t *__cgraph_L1__ = CGRAPH_LOGIC_L1;
static const cgraph_char_t *__cgraph_LZ__ = CGRAPH_LOGIC_LZ;
static const cgraph_char_t *__cgraph_LX__ = CGRAPH_LOGIC_LX;

cgraph_char_t *FUNCTION(NAME, logic2str)(const TYPE x) {
  cgraph_char_t *res = (cgraph_char_t *)__cgraph_LX__;
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
  }

  return res;
}

TYPE FUNCTION(NAME, str2logic)(const cgraph_char_t *str,
                               const cgraph_size_t len) {
  TYPE res = CGRAPH_LX;
  if ((NULL != str) && (1 == len)) {
    switch (str[0]) {
    case '0': {
      res = CGRAPH_L0;
      break;
    }
    case '1': {
      res = CGRAPH_L1;
      break;
    }
    case 'Z': {
      res = CGRAPH_LZ;
      break;
    }
    }
  }

  return res;
}

#include "cgraph_template_off.h"
