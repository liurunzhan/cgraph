#include "cgraph_data.h"
#include "cgraph_struct.h"
#include "cgraph_memory.h"
#include "cgraph_error.h"
#include "cgraph_hobject.h"

#define TYPE_HOBJECT
#include "templete.h"

#include "object_base.ct"

/* key data of hobject */
void *FUNCTION(NAME, kaccessible)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_KACCESSIABLE(object) = CGRAPH_TRUE; }

  return object;
}

void *FUNCTION(NAME, kunaccessible)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_KACCESSIABLE(object) = CGRAPH_FALSE; }
  
  return object;
}

void *FUNCTION(NAME, khashed)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_KHASHED(object) = CGRAPH_TRUE; }

  return object;
}

void *FUNCTION(NAME, kunhashed)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_KHASHED(object) = CGRAPH_FALSE; }

  return object;
}

/* value data of hobject */
void *FUNCTION(NAME, vaccessible)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_VACCESSIABLE(object) = CGRAPH_TRUE; }

  return object;
}

void *FUNCTION(NAME, vunaccessible)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_VACCESSIABLE(object) = CGRAPH_FALSE; }

  return object;
}

void *FUNCTION(NAME, vhashed)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_VHASHED(object) = CGRAPH_TRUE; }

  return object;
}

void *FUNCTION(NAME, vunhashed)(void *cthis)
{
  TYPE *object = (TYPE *)cthis;
  if(NULL != object)
  { CGRAPH_DTYPE_VHASHED(object) = CGRAPH_FALSE; }

  return object;
}

void FUNCTION(TYPE, test)(void)
{
#ifdef DEBUG

#endif
}

#include "templete_off.h"
