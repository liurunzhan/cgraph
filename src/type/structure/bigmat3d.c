#include "cgraph_base.h"
#include "cgraph_object.h"

/***/
#include "cgraph_bigmat3d.h"

/** template module */
#include "template_matrix3d.ct"

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;
  if ((NULL != x) && (NULL != y)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(x);
    cgraph_size_t len = x->len;
    if ((type == CGRAPH_DTYPE_TYPE(y)) && (len == y->len)) {
      OBJECT(type, cmp)
      (x->data, y->data, &flag, len, OBJECT(type, eq));
    }
  } else if ((NULL == x) && (NULL == y)) {
    flag = CGRAPH_TRUE;
  }

  return flag;
}
