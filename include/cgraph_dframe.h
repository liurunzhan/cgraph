#ifndef _CGRAPH_DFRAME_H_
#define _CGRAPH_DFRAME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_DFRAME
#include "cgraph_template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  cgraph_size_t row, column;
  CGRAPH_STRUCTURE_ROOT
} cgraph_dframe_t;

#include "cgraph_template_struct.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_DFRAME_H_ */
