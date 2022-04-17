#include "cgraph_base.h"
#include "cgraph_object.h"

/** object cgraph_dframe_t header */
#include "cgraph_dframe.h"

/** template module */
#include "template_struct.ct"

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t len = x->len;
    if ((type == CGRAPH_DTYPE_TYPE(y)) && (len == y->len)) {
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}
