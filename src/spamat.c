#include "cgraph_memory.h"
#include "cgraph_mobject.h"
#include "cgraph_spamat.h"

#define TYPE_SPAMAT
#include "template.h"

/**/
#include "matrix_base.ct"
#include "struct_base.ct"

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis) {
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

#include "template_off.h"
