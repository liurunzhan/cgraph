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
#define L2BITS CGRAPH_INT_L2BITS
#define IN_FMT "%d"
#define OUT_FMT "%d"
#define UNAME uint
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT)
#define ZERO INT_C(0)
#define ONE INT_C(1)
#define ONES CGRAPH_INT_MAX
#define MIN CGRAPH_INT_MIN
#define MAX CGRAPH_INT_MAX
#define MASK CGRAPH_INT_MASK
#define EPSILON CGRAPH_INT_EPSILON
#define NAN ZERO
#define LSB CGRAPH_INT_LSB
#define MSB CGRAPH_INT_MSB
#define MASK1 CGRAPH_INT_MASK1
#define MASK2 CGRAPH_INT_MASK2
#define MASK4 CGRAPH_INT_MASK4
#define MASK8 CGRAPH_INT_MASK8
#define MASK16 CGRAPH_INT_MASK16

/** template module */
#include "cgraph_template_int.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT_H__ */
