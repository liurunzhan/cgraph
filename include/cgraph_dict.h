#ifndef _CGRAPH_DICT_H_
#define _CGRAPH_DICT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_DICT
#include "templete.h"

typedef struct 
{
  CGRAPH_STRUCTURE_BASE
}cgraph_dict_t;

#include "struct_base.ht"
#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_DICT_H_ */
