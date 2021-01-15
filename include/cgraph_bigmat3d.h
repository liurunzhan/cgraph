#ifndef _CGRAPH_BIGMAT3D_H_
#define _CGRAPH_BIGMAT3D_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGMAT3D
#include "template.h"

typedef struct {
    CGRAPH_STRUCTURE_BASE
    CGRAPH_MATRIX3D_INDEXES
    CGRAPH_STRUCTURE_ROOT
} cgraph_bigmat3d_t;
#include "matrix3d_base.ht"
#include "struct_base.ht"
#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGMAT3D_H_ */
