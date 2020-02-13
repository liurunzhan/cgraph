#ifndef _CGRAPH_OBJECT_H_
#define _CGRAPH_OBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

typedef struct {
  cgraph_type_t type;
  cgraph_size_t hcode;
  void *data;
}cgraph_object_t;

#define CGRAPH_OBJECT(type) (_cgraph_objects_[type])

#define TYPE_OBJECT

#include "templete.h"
#include "data_templete.h"


void *FUNCTION(NAME, data)(void *cthis);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_OBJECT_H_ */