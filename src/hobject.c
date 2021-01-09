#include "cgraph_data.h"
#include "cgraph_error.h"
#include "cgraph_hobject.h"
#include "cgraph_memory.h"
#include "cgraph_struct.h"

#define TYPE_HOBJECT
#include "template.h"

/**/
#include "object_base.ct"

/**key data of hobject */
void *FUNCTION(NAME, kaccessible)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_KACCESSIABLE(_cthis) = CGRAPH_TRUE;
    }

    return _cthis;
}

void *FUNCTION(NAME, kunaccessible)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_KACCESSIABLE(_cthis) = CGRAPH_FALSE;
    }

    return _cthis;
}

void *FUNCTION(NAME, khashed)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_KHASHED(_cthis) = CGRAPH_TRUE;
    }

    return _cthis;
}

void *FUNCTION(NAME, kunhashed)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_KHASHED(_cthis) = CGRAPH_FALSE;
    }

    return _cthis;
}

/**value data of hobject */
void *FUNCTION(NAME, vaccessible)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_VACCESSIABLE(_cthis) = CGRAPH_TRUE;
    }

    return _cthis;
}

void *FUNCTION(NAME, vunaccessible)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_VACCESSIABLE(_cthis) = CGRAPH_FALSE;
    }

    return _cthis;
}

void *FUNCTION(NAME, vhashed)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_VHASHED(_cthis) = CGRAPH_TRUE;
    }

    return _cthis;
}

void *FUNCTION(NAME, vunhashed)(void *cthis)
{
    TYPE *_cthis = (TYPE *)cthis;
    if (NULL != _cthis) {
        CGRAPH_DTYPE_VHASHED(_cthis) = CGRAPH_FALSE;
    }

    return _cthis;
}

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "template_off.h"
