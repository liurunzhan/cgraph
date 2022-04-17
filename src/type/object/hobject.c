#include "cgraph_object_base.h"

/** object cgraph_hobject_t header */
#include "cgraph_hobject.h"

/** template module */
#include "template_object.ct"

__INLINE cgraph_type_t FUNCTION(NAME, ktype)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KTYPE(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, iskaccess)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KACCESS(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, iskconst)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KCONST(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, iskhash)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_KHASH(cthis) : CGRAPH_FALSE;
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

__INLINE TYPE *FUNCTION(NAME, setkconst)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KACCESS(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetkconst)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KACCESS(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, setkhash)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KHASH(cthis) = CGRAPH_TRUE;
    CGRAPH_DTYPE_VHASH(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetkhash)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_KHASH(cthis) = CGRAPH_FALSE;
    CGRAPH_DTYPE_VHASH(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE cgraph_type_t FUNCTION(NAME, vtype)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VTYPE(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, isvaccess)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VACCESS(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, isvconst)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VCONST(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, isvhash)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_DTYPE_VHASH(cthis) : CGRAPH_FALSE;
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

__INLINE TYPE *FUNCTION(NAME, setvconst)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetvconst)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VACCESS(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, setvhash)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VHASH(cthis) = CGRAPH_TRUE;
  }

  return cthis;
}

__INLINE TYPE *FUNCTION(NAME, unsetvhash)(TYPE *cthis) {
  if (NULL != cthis) {
    CGRAPH_DTYPE_VHASH(cthis) = CGRAPH_FALSE;
  }

  return cthis;
}
