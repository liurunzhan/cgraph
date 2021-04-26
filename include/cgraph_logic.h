/**
 * @file cgraph_logic.h
 * @brief the apis of DATA TYPE cgraph_logic_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_LOGIC_H__
#define __CGRAPH_LOGIC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_LOGIC
#include "cgraph_template.h"

/** template module */
#include "cgraph_template_int.ht"

#define LOGIC_AND(x, y) FUNCTION(NAME, and)((x), (y))
#define LOGIC_OR(x, y) FUNCTION(NAME, or)((x), (y))
#define LOGIC_NOT(x) FUNCTION(NAME, not )((x))
#define LOGIC_XOR(x, y) FUNCTION(NAME, xor)((x), (y))
#define LOGIC_XNOR(x, y) FUNCTION(NAME, xnor)((x), (y))

extern cgraph_char_t *FUNCTION(NAME, logic2str)(const TYPE str);
extern TYPE FUNCTION(NAME, str2logic)(const cgraph_char_t *str,
                                      const cgraph_size_t len);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_LOGIC_H__ */
