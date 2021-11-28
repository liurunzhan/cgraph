#include "cgraph_object_base.h"

/***/
#include "cgraph_mobject.h"

/** template module */
#include "template_object.ct"

__INLINE cgraph_size_t FUNCTION(NAME, row)(const TYPE *cthis) {
  return CGRAPH_MATRIX_ROW(cthis);
}

__INLINE cgraph_size_t FUNCTION(NAME, column)(const TYPE *cthis) {
  return CGRAPH_MATRIX_COLUMN(cthis);
}
