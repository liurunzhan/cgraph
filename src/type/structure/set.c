#include "cgraph_base.h"
#include "cgraph_hobject.h"

/** object cgraph_set_t header */
#include "cgraph_set.h"

/** template module */
#include "template_struct.ct"

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {

  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}
