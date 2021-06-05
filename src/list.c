#include "cgraph_base.h"
#include "cgraph_list.h"
#include "cgraph_object.h"

#define TYPE_LIST
#include "cgraph_template.h"

/** template module */
#include "template_struct.ct"

cgraph_bool_t FUNCTION(NAME, find)(const TYPE *cthis, const void *x) {
  cgraph_bool_t res = CGRAPH_FALSE;
  if ((NULL != cthis) && (NULL != x)) {
  }

  return res;
}

TYPE *FUNCTION(NAME, push)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
  }

  return cthis;
}

void *FUNCTION(NAME, pop)(TYPE *cthis) {
  void *res = NULL;
  if (NULL != cthis) {
  }

  return res;
}

TYPE *FUNCTION(NAME, disable)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
  }

  return cthis;
}

TYPE *FUNCTION(NAME, delete)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
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
