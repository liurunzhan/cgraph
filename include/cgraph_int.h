/**
 * @file cgraph_int.h
 * @brief the apis of DATA TYPE cgraph_int_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_INT_H__
#define __CGRAPH_INT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT)
#define BITS CGRAPH_INT_BITS
#define BITS_LOG2 CGRAPH_INT_BITS_LOG2
#define IN_FMT "%d"
#define OUT_FMT "%d"
#define UNAME uint
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT_MAX
#define MIN CGRAPH_INT_MIN
#define MAX CGRAPH_INT_MAX
#define MASK CGRAPH_INT_MASK
#define EPSILON CGRAPH_INT_EPSILON
#define NAN ZERO
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define MASK1 (0xAAAAAAAAU)
#define MASK2 (0xCCCCCCCCU)
#define MASK4 (0xF0F0F0F0U)
#define MASK8 (0xFF00FF00U)
#define MASK16 (0xFFFF0000U)

/** template module */
#include "cgraph_template_int.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT_H__ */
