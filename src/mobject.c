#include "cgraph_data.h"
#include "cgraph_error.h"
#include "cgraph_memory.h"
#include "cgraph_mobject.h"
#include "cgraph_struct.h"

#define TYPE_MOBJECT
#include "template.h"

/**/
#include "object_base.ct"

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, row)(const TYPE *cthis)
{
    return (NULL != cthis ? MATRIX_ROW(cthis) : 0);
}

CGRAPH_INLINE cgraph_size_t FUNCTION(NAME, column)(const TYPE *cthis)
{
    return (NULL != cthis ? MATRIX_COLUMN(cthis) : 0);
}

#include "template_off.h"
