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
#define TYPE_C(x) ((x)&CGRAPH_LOGIC_MASK)
#define ID ID_T(LOGIC)
#define BITS CGRAPH_LOGIC_BITS
#define L2BITS CGRAPH_LOGIC_L2BITS
#define IN_FMT "%s"
#define OUT_FMT "%s"
#define UTYPE TYPE_T(NAME)
#define UTYPE_C(x) TYPE_C(x)
#define UID ID_T(LOGIC)
#define ZERO CGRAPH_L0
#define ONE CGRAPH_L1
#define ONES CGRAPH_L1
#define MIN CGRAPH_LOGIC_MIN
#define MAX CGRAPH_LOGIC_MAX
#define MASK CGRAPH_LOGIC_MASK
#define EPSILON CGRAPH_L1
#define NAN CGRAPH_LX
#define MSB CGRAPH_L1
#define LSB CGRAPH_LZ

/** template module */
#include "cgraph_template_int.ht"

extern cgraph_bool_t FUNCTION(NAME, leq)(const TYPE x, const TYPE y);
extern cgraph_bool_t FUNCTION(NAME, lne)(const TYPE x, const TYPE y);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_LOGIC_H__ */
