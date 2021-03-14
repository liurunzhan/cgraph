#include "cgraph_bool.h"
#include "cgraph_file.h"
#include "cgraph_memory.h"

#define TYPE_BOOL
#include "template.h"

static const cgraph_char_t *__cgraph_true__ = CGRAPH_BOOL_TRUE;
static const cgraph_char_t *__cgraph_false__ = CGRAPH_BOOL_FALSE;

/*template module*/
cgraph_char_t *FUNCTION(NAME, bool2str)(const TYPE x) {
  return (CGRAPH_FALSE == x) ? (cgraph_char_t *)__cgraph_false__
                             : (cgraph_char_t *)__cgraph_true__;
}

TYPE FUNCTION(NAME, str2bool)(const cgraph_char_t *x) {
  TYPE res = CGRAPH_FALSE;
  if ('T' == x[0] || 't' == x[0]) {
    if (('R' == x[1] || 'r' == x[1]) && ('\0' != x[1])) {
      if (('U' == x[2] || 'u' == x[2]) && ('\0' != x[2])) {
        if (('E' == x[3] || 'e' == x[3]) && ('\0' != x[3])) {
          if ('\0' == x[4]) {
            res = CGRAPH_TRUE;
          }
        }
      }
    }
  }

  return res;
}

#include "int_base.ct"
#include "template_off.h"
