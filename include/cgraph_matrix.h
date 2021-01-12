#ifndef _CGRAPH_MATRIX_H_
#define _CGRAPH_MATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_MATRIX
#include "template.h"
typedef struct {
    CGRAPH_STRUCTURE_BASE
    CGRAPH_MATRIX_INDEXES
    CGRAPH_STRUCTURE_ROOT
} cgraph_matrix_t;

#include "struct_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_MATRIX_H_ */
