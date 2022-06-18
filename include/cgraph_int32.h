/**
 * @file cgraph_int32.h
 * @brief the apis of DATA TYPE cgraph_int32_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_INT32_H__
#define __CGRAPH_INT32_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT32
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int32
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT32)
#define BITS CGRAPH_INT32_BITS
#define L2BITS CGRAPH_INT32_L2BITS
#define IN_FMT CGRAPH_INT32_IN_FMT
#define OUT_FMT CGRAPH_INT32_OUT_FMT
#define UNAME uint32
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT32)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT32_MAX
#define MIN CGRAPH_INT32_MIN
#define MAX CGRAPH_INT32_MAX
#define MASK CGRAPH_INT32_MASK
#define EPSILON CGRAPH_INT32_EPSILON
#define NAN ZERO
#define LSB CGRAPH_INT32_LSB
#define MSB CGRAPH_INT32_MSB
#define HASH_OFFSET (4)
#define MASK1 CGRAPH_INT32_MASK1
#define MASK2 CGRAPH_INT32_MASK2
#define MASK4 CGRAPH_INT32_MASK4
#define MASK8 CGRAPH_INT32_MASK8
#define MASK16 CGRAPH_INT32_MASK16

/** template module */
#include "cgraph_template_int.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT32_H__ */
