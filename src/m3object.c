#include "cgraph_object_base.h"

#include "cgraph_m3object.h"

#define TYPE_M3OBJECT
#include "cgraph_template.h"

/** template module */
#include "template_object.ct"

__INLINE cgraph_size_t FUNCTION(NAME, index_i)(const TYPE *cthis) {
  return MATRIX3D_INDEX_I(cthis);
}

__INLINE cgraph_size_t FUNCTION(NAME, index_j)(const TYPE *cthis) {
  return MATRIX3D_INDEX_J(cthis);
}

__INLINE cgraph_size_t FUNCTION(NAME, index_k)(const TYPE *cthis) {
  return MATRIX3D_INDEX_K(cthis);
}

#include "cgraph_template_off.h"
