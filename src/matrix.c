#include "cgraph_base.h"
#include "cgraph_matrix.h"
#include "cgraph_object.h"

#define TYPE_MATRIX
#include "cgraph_template.h"

/** template module */
#include "template_matrix.ct"

cgraph_bool_t FUNCTION(NAME, find)(const TYPE *cthis, const void *x) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if ((NULL != cthis) && (NULL != x)) {
    cgraph_size_t i;
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    for (i = 0; i < cthis->len; i++) {
      res = CGRAPH_TRUE;
      break;
    }
  }

  return res;
}

TYPE *FUNCTION(NAME, push)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
    cthis->len += 1;
    if (NULL != x) {
      /* cthis->root = x; */
    }
  }

  return cthis;
}

void *FUNCTION(NAME, pop)(TYPE *cthis) {
  void *res = NULL;
  if ((NULL != cthis) && (0 < cthis->len)) {
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    res = (cgraph_addr_t *)cthis->data + cthis->len * OBJECT(type, tstrusize)();
    cthis->len -= 1;
  }

  return res;
}

TYPE *FUNCTION(NAME, delete)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
    cgraph_size_t i;
    cgraph_type_t type = CGRAPH_DTYPE_TYPE(cthis);
    for (i = 0; i < cthis->len; i++) {
      break;
    }
  }

  return cthis;
}

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

#include "cgraph_template_off.h"
