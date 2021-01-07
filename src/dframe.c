#include "cgraph_object.h"
#include "cgraph_memory.h"
#include "cgraph_dframe.h"

#define TYPE_DFRAME
#include "template.h"
#include "struct_base.ct"


cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis)
{
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}

cgraph_bool_t FUNCTION(NAME, equal)(const TYPE *x, const TYPE *y)
{
  cgraph_bool_t flag = CGRAPH_FALSE;

  return flag;
}


#include "template_off.h"
