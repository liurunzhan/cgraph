/**
 * @file cgraph_int8.h
 * @brief the apis of DATA TYPE cgraph_int8_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_INT8_H__
#define __CGRAPH_INT8_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT8
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int8
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT8)
#define BITS CGRAPH_INT8_BITS
#define L2BITS CGRAPH_INT8_L2BITS
#define IN_FMT CGRAPH_INT8_IN_FMT
#define OUT_FMT CGRAPH_INT8_OUT_FMT
#define UNAME uint8
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT8)
#define ZERO INT8_C(0)
#define ONE INT8_C(1)
#define ONES CGRAPH_INT8_MAX
#define MIN CGRAPH_INT8_MIN
#define MAX CGRAPH_INT8_MAX
#define MASK CGRAPH_INT8_MASK
#define EPSILON CGRAPH_INT8_EPSILON
#define NAN ZERO
#define LSB CGRAPH_INT8_LSB
#define MSB CGRAPH_INT8_MSB
#define MASK1 CGRAPH_INT8_MASK1
#define MASK2 CGRAPH_INT8_MASK2
#define MASK4 CGRAPH_INT8_MASK4

/** template module */
#include "cgraph_template_int.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT8_H__ */
