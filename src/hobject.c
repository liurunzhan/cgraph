#include "cgraph_object_base.h"

#include "cgraph_hobject.h"

#define TYPE_HOBJECT
#include "cgraph_template.h"

/** template module */
#include "template_object.ct"

__INLINE TYPE *FUNCTION(NAME, ksetaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KACCESS(cthis) = CGRAPH_TRUE;
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unksetaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KACCESS(cthis) = CGRAPH_FALSE;
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, khashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KHASHED(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unkhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KHASHED(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, vsetaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unvsetaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, vhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VHASHED(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unvhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VHASHED(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

#include "cgraph_template_off.h"
