#include "cgraph_bigmat3d.h"
#include "cgraph_memory.h"
#include "cgraph_object.h"

#define TYPE_BIGMAT3D
#include "template.h"

/*template module*/
#include "matrix3d_base.ct"
#include "struct_base.ct"

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis)
{
    cgraph_bool_t flag = CGRAPH_FALSE;

    return flag;
}

#include "template_off.h"
