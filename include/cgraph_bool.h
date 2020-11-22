#ifndef _CGRAPH_BOOL_H_
#define _CGRAPH_BOOL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define BOOL_AND(x, y) (((x == CGRAPH_FALSE) || (y == CGRAPH_FALSE)) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define BOOL_OR(x, y) (((x == CGRAPH_TRUE) || (y == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define BOOL_NOT(x) ((x == CGRAPH_TRUE) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define BOOL_XOR(x, y) ((x != y) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define BOOL_XNOR(x, y) ((x == y) ? CGRAPH_TRUE : CGRAPH_FALSE)

#define TYPE_BOOL
#include "templete.h"
#include "data_base.ht"

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BOOL_H_ */
