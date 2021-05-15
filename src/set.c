#include "cgraph_base.h"
#include "cgraph_hobject.h"
#include "cgraph_set.h"

#define TYPE_SET
#include "cgraph_template.h"

/** template module */
#include "template_struct.ct"

cgraph_bool_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

#include "cgraph_template_off.h"
