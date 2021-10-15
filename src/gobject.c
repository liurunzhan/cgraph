#include "cgraph_object_base.h"

#include "cgraph_gobject.h"

#define TYPE_GOBJECT
#include "cgraph_template.h"

/** template module */
#include "template_object.ct"

__INLINE cgraph_bool_t FUNCTION(NAME, keyisid)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_GTYPE_GKEYISID(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, directed)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_GTYPE_GDIRECTED(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, weighted)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_GTYPE_GWEIGHTED(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, multiple)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_GTYPE_GMULTIPLE(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, hyper)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_GTYPE_GHYPER(cthis) : CGRAPH_FALSE;
}

__INLINE cgraph_bool_t FUNCTION(NAME, dynamic)(const TYPE *cthis) {
  return (NULL != cthis) ? CGRAPH_GTYPE_GDYNAMIC(cthis) : CGRAPH_FALSE;
}

#include "cgraph_template_off.h"
