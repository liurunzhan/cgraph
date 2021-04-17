#include "cgraph_base.h"
#include "cgraph_bool.h"

#define TYPE_BOOL
#include "cgraph_template.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;

cgraph_char_t *FUNCTION(NAME, bool2str)(const TYPE x) {
  return (CGRAPH_FALSE == x) ? (cgraph_char_t *)__cgraph_false__
                             : (cgraph_char_t *)__cgraph_true__;
}

TYPE FUNCTION(NAME, str2bool)(const cgraph_char_t *str,
                              const cgraph_size_t len) {
  TYPE res = CGRAPH_FALSE;
  if ((NULL != str) && (4 == len)) {
    if (('T' == str[0]) || ('t' == str[0])) {
      if (('R' == str[1]) || ('r' == str[1])) {
        if (('U' == str[2]) || ('u' == str[2])) {
          if (('E' == str[3]) || ('e' == str[3])) {
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
