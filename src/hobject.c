#include "cgraph_object_base.h"

#include "cgraph_hobject.h"

#define TYPE_HOBJECT
#include "cgraph_template.h"

/** template module */
#include "template_object.ct"

__INLINE cgraph_type_t FUNCTION(NAME, ktype)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KTYPE(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, kaccessiable)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KACCESS(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, khashed)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KHASHED(cthis) : CGRAPH_FALSE;
}

__INLINE TYPE *FUNCTION(NAME, setkaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KACCESS(cthis) = CGRAPH_TRUE;
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetkaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KACCESS(cthis) = CGRAPH_FALSE;
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, setkhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KHASHED(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetkhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KHASHED(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE cgraph_type_t FUNCTION(NAME, vtype)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VTYPE(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, vaccessiable)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VACCESS(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, vhashed)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VHASHED(cthis) : CGRAPH_FALSE;
}

__INLINE TYPE *FUNCTION(NAME, setvaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetvaccess)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, setvhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VHASHED(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetvhashed)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VHASHED(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

#include "cgraph_template_off.h"
