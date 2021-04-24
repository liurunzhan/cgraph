#include "cgraph_base.h"
#include "cgraph_object.h"
#include "cgraph_queue.h"

#define TYPE_QUEUE
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

TYPE *FUNCTION(NAME, pop)(TYPE *cthis, const void *x) {
  if ((NULL != cthis) && (NULL != x)) {
  }

  return cthis;
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

#include "cgraph_template_off.h"
