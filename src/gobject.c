#include "cgraph_data.h"
#include "cgraph_error.h"
#include "cgraph_gobject.h"
#include "cgraph_memory.h"
#include "cgraph_struct.h"

#define TYPE_GOBJECT
#include "template.h"

/**/
#include "object_base.ct"

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, keyisid)(const TYPE *cthis)
{
    return (NULL != cthis) ? CGRAPH_GTYPE_GKEYISID(cthis) : CGRAPH_FALSE;
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, directed)(const TYPE *cthis)
{
    return (NULL != cthis) ? CGRAPH_GTYPE_GDIRECTED(cthis) : CGRAPH_FALSE;
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, weighted)(const TYPE *cthis)
{
    return (NULL != cthis) ? CGRAPH_GTYPE_GWEIGHTED(cthis) : CGRAPH_FALSE;
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, multiple)(const TYPE *cthis)
{
    return (NULL != cthis) ? CGRAPH_GTYPE_GMULTIPLE(cthis) : CGRAPH_FALSE;
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, hyper)(const TYPE *cthis)
{
    return (NULL != cthis) ? CGRAPH_GTYPE_GHYPER(cthis) : CGRAPH_FALSE;
}

CGRAPH_INLINE cgraph_bool_t FUNCTION(NAME, dynamic)(const TYPE *cthis)
{
    return (NULL != cthis) ? CGRAPH_GTYPE_GDYNAMIC(cthis) : CGRAPH_FALSE;
}

#include "template_off.h"
