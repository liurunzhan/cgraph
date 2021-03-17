#ifndef _CGRAPH_DICT_H_
#define _CGRAPH_DICT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_DICT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_ROOT
} cgraph_dict_t;

#include "cgraph_template_struct.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_DICT_H_ */
