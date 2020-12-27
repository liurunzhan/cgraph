#ifndef _CGRAPH_HOBJECT_H_
#define _CGRAPH_HOBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !(defined(_CGRAPH_H_) || defined(_CGRAPH_STRUCT_H_)) && (defined(_CGRAPH_OBJECT_H_) || defined(_CGRAPH_POBJECT_H_) || defined(_CGRAPH_SOBJECT_H_))
#error <cgraph_hobject.h> can not be included in the same file together with <cgraph_object.h>, <cgraph_pobject.h> or <cgraph_sobject.h> except in <cgraph.h> and <cgraph_struct.h>
#endif

#include "cgraph_config.h"

extern CGVTable *CGRAPH_OBJECTS_NAME(hobject)[];
#define CGRAPH_HOBJECT(type, opt) ((CGRAPH_OBJECTS_NAME(hobject)[type])->opt)

#define TYPE_HOBJECT
#include "template.h"

typedef struct 
{
  CGRAPH_OBJECT_BASE
  struct cgraph_hobject_t *next;
  DATA_TYPE *key;
  CGRAPH_OBJECT_ROOT
}cgraph_hobject_t;

#include "object_base.ht"

extern void *FUNCTION(NAME, kaccessible)(void *cthis);
extern void *FUNCTION(NAME, kunaccessible)(void *cthis);
extern void *FUNCTION(NAME, khashed)(void *cthis);
extern void *FUNCTION(NAME, kunhashed)(void *cthis);

extern void *FUNCTION(NAME, vaccessible)(void *cthis);
extern void *FUNCTION(NAME, vunaccessible)(void *cthis);
extern void *FUNCTION(NAME, vhashed)(void *cthis);
extern void *FUNCTION(NAME, vunhashed)(void *cthis);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_HOBJECT_H_ */
