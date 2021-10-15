#include "cgraph_base.h"
#include "cgraph_bool.h"

#define TYPE_BOOL
#include "cgraph_template.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;

cgraph_char_t *FUNCTION(NAME, encode)(const TYPE x) {
  return (CGRAPH_FALSE == x) ? (cgraph_char_t *)__cgraph_false__
                             : (cgraph_char_t *)__cgraph_true__;
}

TYPE FUNCTION(NAME, decode)(const cgraph_char_t *cstr,
                            const cgraph_size_t len) {
  TYPE res = CGRAPH_FALSE;
  if ((NULL != cstr) && (4 == len)) {
    if (('T' == cstr[0]) || ('t' == cstr[0])) {
      if (('R' == cstr[1]) || ('r' == cstr[1])) {
        if (('U' == cstr[2]) || ('u' == cstr[2])) {
          if (('E' == cstr[3]) || ('e' == cstr[3])) {
            res = CGRAPH_TRUE;
          }
        }
      }
    }
  }

  return res;
}

/** template module */
#include "template_int.ct"

#include "cgraph_template_off.h"
