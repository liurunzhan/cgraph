#include "cgraph_m3object.h"
#include "cgraph_memory.h"
#include "cgraph_spamat3d.h"

#define TYPE_SPAMAT3D
#include "template.h"

/**/
#include "matrix3d_base.ct"
#include "struct_base.ct"

cgraph_bool_t FUNCTION(NAME, check)(const TYPE *cthis)
{
    cgraph_bool_t flag = CGRAPH_FALSE;

    return flag;
}

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "template_off.h"
