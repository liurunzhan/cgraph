#include "cgraph_object_base.h"

#include "cgraph_mobject.h"

#define TYPE_MOBJECT
#include "cgraph_template.h"

/** template module */
#include "template_object.ct"

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, row)(const TYPE *cthis) {
  return MATRIX_ROW(cthis);
}

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, column)(const TYPE *cthis) {
  return MATRIX_COLUMN(cthis);
}

#include "cgraph_template_off.h"
