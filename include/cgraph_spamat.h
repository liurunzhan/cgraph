#ifndef _CGRAPH_SPAMAT_H_
#define _CGRAPH_SPAMAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_mobject.h"

#define TYPE_SPAMAT
#include "template.h"

typedef struct {
    CGRAPH_STRUCTURE_BASE
    CGRAPH_MATRIX_INDEXES
    CGRAPH_STRUCTURE_ROOT
} cgraph_spamat_t;
#include "matrix_base.ht"
#include "struct_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_SPAMAT_H_ */
