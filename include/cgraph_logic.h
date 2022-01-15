/**
 * @file cgraph_logic.h
 * @brief the apis of DATA TYPE cgraph_logic_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_LOGIC_H__
#define __CGRAPH_LOGIC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_LOGIC
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME logic
#define TYPE TYPE_T(NAME)
#define ID ID_T(LOGIC)
#define BITS CGRAPH_LOGIC_BITS
#define BITS_LOG2 CGRAPH_LOGIC_BITS_LOG2
#define IN_FMT "%s"
#define OUT_FMT "%s"
#define UTYPE TYPE_T(NAME)
#define UID ID_T(LOGIC)
#define ZERO CGRAPH_L0
#define ONE CGRAPH_L1
#define ONES CGRAPH_L1
#define MIN CGRAPH_LOGIC_MIN
#define MAX CGRAPH_LOGIC_MAX
#define MSB CGRAPH_L1
#define LSB CGRAPH_LZ
#define EPS CGRAPH_LOGIC_EPS
#define EPS_LEN CGRAPH_LOGIC_BITS

/** template module */
#include "cgraph_template_int.ht"

#define LOGIC_AND(x, y) FUNCTION(NAME, and)((x), (y))
#define LOGIC_OR(x, y) FUNCTION(NAME, or)((x), (y))
#define LOGIC_NOT(x) FUNCTION(NAME, not )((x))
#define LOGIC_XOR(x, y) FUNCTION(NAME, xor)((x), (y))
#define LOGIC_XNOR(x, y) FUNCTION(NAME, xnor)((x), (y))

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_LOGIC_H__ */
