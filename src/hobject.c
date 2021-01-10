#include "cgraph_data.h"
#include "cgraph_error.h"
#include "cgraph_hobject.h"
#include "cgraph_memory.h"
#include "cgraph_struct.h"

#define TYPE_HOBJECT
#include "template.h"

/**/
#include "object_base.ct"

CGRAPH_INLINE TYPE *FUNCTION(NAME, kaccessible)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_KACCESSIABLE(cthis) = CGRAPH_TRUE;
        CGRAPH_DTYPE_VACCESSIABLE(cthis) = CGRAPH_TRUE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, unkaccessible)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_KACCESSIABLE(cthis) = CGRAPH_FALSE;
        CGRAPH_DTYPE_VACCESSIABLE(cthis) = CGRAPH_FALSE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, khashed)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_KHASHED(cthis) = CGRAPH_TRUE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, unkhashed)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_KHASHED(cthis) = CGRAPH_FALSE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, vaccessible)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_VACCESSIABLE(cthis) = CGRAPH_TRUE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, unvaccessible)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_VACCESSIABLE(cthis) = CGRAPH_FALSE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, vhashed)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_VHASHED(cthis) = CGRAPH_TRUE;
    }

    return cthis;
}

CGRAPH_INLINE TYPE *FUNCTION(NAME, unvhashed)(TYPE *cthis)
{
    if(NULL != cthis)
    {
        CGRAPH_DTYPE_VHASHED(cthis) = CGRAPH_FALSE;
    }

    return cthis;
}

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "template_off.h"
