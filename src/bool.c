#include "cgraph_base.h"
#include "cgraph_bool.h"

#define TYPE_BOOL
#include "cgraph_template.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;

/*template module*/
cgraph_char_t *FUNCTION(NAME, bool2str)(const TYPE x) {
  return (CGRAPH_FALSE == x) ? (cgraph_char_t *)__cgraph_false__
                             : (cgraph_char_t *)__cgraph_true__;
}

TYPE FUNCTION(NAME, str2bool)(const cgraph_char_t *x, const cgraph_size_t len) {
  TYPE res = CGRAPH_FALSE;
  if ((NULL != x) && (4 != len)) {
    if (('T' == x[0]) || ('t' == x[0])) {
      if (('R' == x[1]) || ('r' == x[1])) {
        if (('U' == x[2]) || ('u' == x[2])) {
          if (('E' == x[3]) || ('e' == x[3])) {
            res = CGRAPH_TRUE;
          }
        }
      }
    }
  }

  return res;
}

#include "template_int.ct"

#include "cgraph_template_off.h"
