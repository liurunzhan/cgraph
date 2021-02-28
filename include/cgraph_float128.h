#ifndef _CGRAPH_FLOAT128_H_
#define _CGRAPH_FLOAT128_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifdef CGRAPH_WITH_FLOAT128

#define TYPE_FLOAT128
#include "template.h"

/* */

#include "float_base.ht"
#include "template_off.h"

#endif

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_FLOAT128_H_ */
