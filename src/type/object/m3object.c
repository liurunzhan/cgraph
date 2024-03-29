#include "cgraph_object_base.h"

/** object cgraph_m3object_t header */
#include "cgraph_m3object.h"

/** template module */
#include "template_object.ct"

__INLINE__ cgraph_size_t FUNCTION(NAME, index_i)(const TYPE *cthis) {
  return CGRAPH_MATRIX3D_INDEX_I(cthis);
}

__INLINE__ cgraph_size_t FUNCTION(NAME, index_j)(const TYPE *cthis) {
  return CGRAPH_MATRIX3D_INDEX_J(cthis);
}

__INLINE__ cgraph_size_t FUNCTION(NAME, index_k)(const TYPE *cthis) {
  return CGRAPH_MATRIX3D_INDEX_K(cthis);
}
