/**
 * @file cgraph_int16.h
 * @brief the apis of DATA TYPE cgraph_int16_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_INT16_H__
#define __CGRAPH_INT16_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT16
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int16
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT16)
#define BITS CGRAPH_INT16_BITS
#define L2BITS CGRAPH_INT16_L2BITS
#define IN_FMT CGRAPH_INT16_IN_FMT
#define OUT_FMT CGRAPH_INT16_OUT_FMT
#define UNAME uint16
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT16)
#define ZERO INT16_C(0)
#define ONE INT16_C(1)
#define ONES CGRAPH_INT16_MAX
#define MIN CGRAPH_INT16_MIN
#define MAX CGRAPH_INT16_MAX
#define MASK CGRAPH_INT16_MASK
#define EPSILON CGRAPH_INT16_EPSILON
#define NAN ZERO
#define LSB CGRAPH_INT16_LSB
#define MSB CGRAPH_INT16_MSB
#define MASK1 CGRAPH_INT16_MASK1
#define MASK2 CGRAPH_INT16_MASK2
#define MASK4 CGRAPH_INT16_MASK4
#define MASK8 CGRAPH_INT16_MASK8

/** template module */
#include "cgraph_template_int.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT16_H__ */
