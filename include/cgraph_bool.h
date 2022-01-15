/**
 * @file cgraph_bool.h
 * @brief the apis of DATA TYPE cgraph_bool_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
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

#include "cgraph_template_off.h"
#define TYPE_BOOL
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME bool
#define TYPE TYPE_T(NAME)
#define ID ID_T(BOOL)
#define BITS CGRAPH_BOOL_BITS
#define BITS_LOG2 CGRAPH_BOOL_BITS_LOG2
#define IN_FMT "%s"
#define OUT_FMT "%s"
#define UTYPE TYPE_T(NAME)
#define UID ID_T(BOOL)
#define ZERO CGRAPH_FALSE
#define ONE CGRAPH_TRUE
#define ONES CGRAPH_TRUE
#define MIN CGRAPH_BOOL_MIN
#define MAX CGRAPH_BOOL_MAX
#define MSB (ONE)
#define LSB (ONE)
#define EPS CGRAPH_BOOL_EPS
#define EPS_LEN CGRAPH_BOOL_BITS

/** template module */
#include "cgraph_template_int.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_BOOL_H__ */
