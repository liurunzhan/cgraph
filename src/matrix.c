#include "cgraph_matrix.h"
#include "cgraph_memory.h"
#include "cgraph_object.h"

#define TYPE_MATRIX
#include "template.h"

/**/
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
