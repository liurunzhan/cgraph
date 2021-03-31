/**
 * @file cgraph_bool.h
 * @brief the apis of DATA TYPE cgraph_bool_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_BOOL_H_
#define _CGRAPH_BOOL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define BOOL_AND(x, y)                                                         \
  (((x == CGRAPH_FALSE) || (y == CGRAPH_FALSE)) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define BOOL_OR(x, y)                                                          \
  (((x == CGRAPH_TRUE) || (y == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define BOOL_NOT(x) ((x == CGRAPH_TRUE) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define BOOL_XOR(x, y) ((x != y) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define BOOL_XNOR(x, y) ((x == y) ? CGRAPH_TRUE : CGRAPH_FALSE)

#define TYPE_BOOL
#include "cgraph_template.h"

/* */

#include "cgraph_template_int.ht"

extern cgraph_char_t *FUNCTION(NAME, bool2str)(const TYPE x);
extern TYPE FUNCTION(NAME, str2bool)(const cgraph_char_t *x,
                                     const cgraph_size_t len);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BOOL_H_ */
