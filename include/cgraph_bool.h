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

#ifndef __CGRAPH_BOOL_H__
#define __CGRAPH_BOOL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define BOOL_AND(x, y) ((x) & (y))
#define BOOL_OR(x, y) ((x) | (y))
#define BOOL_NOT(x) ((x) ^ 0x01)
#define BOOL_XOR(x, y) ((x) ^ (y))
#define BOOL_XNOR(x, y) (~BOOL_XOR(x, y))

#define TYPE_BOOL
#include "cgraph_template.h"

/** template module */
#include "cgraph_template_int.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BOOL_H__ */
