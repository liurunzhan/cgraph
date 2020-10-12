#ifndef _CGRAPH_BOOLEAN_H_
#define _CGRAPH_BOOLEAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define BOOLEAN_AND(x, y) (((x == CGRAPH_FALSE) || (y == CGRAPH_FALSE)) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define BOOLEAN_OR(x, y) (((x == CGRAPH_TRUE) || (y == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define BOOLEAN_NOT(x) ((x == CGRAPH_TRUE) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define BOOLEAN_XOR(x, y) ((x != y) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define BOOLEAN_XNOR(x, y) ((x == y) ? CGRAPH_TRUE : CGRAPH_FALSE)

#define TYPE_BOOLEAN
#include "templete.h"
#include "data_base.th"

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BOOLEAN_H_ */
