#ifndef _CGRAPH_BIGMAT_H_
#define _CGRAPH_BIGMAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGMAT
#include "template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_MATRIX_INDEXES
  CGRAPH_STRUCTURE_ROOT
} cgraph_bigmat_t;
#include "matrix_base.ht"
#include "struct_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGMAT_H_ */
