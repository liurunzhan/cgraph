#include "cgraph_data.h"
#include "cgraph_error.h"
#include "cgraph_m3object.h"
#include "cgraph_memory.h"
#include "cgraph_struct.h"

#define TYPE_M3OBJECT
#include "cgraph_template.h"

/** template module */
#include "template_object.ct"

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, index_i)(const TYPE *cthis) {
  return MATRIX3D_INDEX_I(cthis);
}

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, index_j)(const TYPE *cthis) {
  return MATRIX3D_INDEX_J(cthis);
}

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, index_k)(const TYPE *cthis) {
  return MATRIX3D_INDEX_K(cthis);
}

#include "cgraph_template_off.h"
