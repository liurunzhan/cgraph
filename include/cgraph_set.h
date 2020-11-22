#ifndef _CGRAPH_SET_H_
#define _CGRAPH_SET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_SET
#include "templete.h"

typedef struct
{
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_ROOT
}cgraph_set_t;

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_SET_H_ */
