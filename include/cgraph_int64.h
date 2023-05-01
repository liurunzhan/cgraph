/**
 * @file cgraph_int64.h
 * @brief the apis of DATA TYPE cgraph_int64_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_INT64_H__
#define __CGRAPH_INT64_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT64
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int64
#define TYPE TYPE_T(NAME)
#define TYPE_C(x) INT64_C(x)
#define ID ID_T(INT64)
#define BITS CGRAPH_INT64_BITS
#define L2BITS CGRAPH_INT64_L2BITS
#define IN_FMT CGRAPH_INT64_IN_FMT
#define OUT_FMT CGRAPH_INT64_OUT_FMT
#define UNAME uint64
#define UTYPE TYPE_T(UNAME)
#define UTYPE_C(x) UINT64_C(x)
#define UID ID_T(UINT64)
#define ZERO TYPE_C(0)
#define ONE TYPE_C(1)
#define ONES CGRAPH_INT64_MAX
#define MIN CGRAPH_INT64_MIN
#define MAX CGRAPH_INT64_MAX
#define MASK CGRAPH_INT64_MASK
#define EPSILON CGRAPH_INT64_EPSILON
#define NAN ZERO
#define LSB CGRAPH_INT64_LSB
#define MSB CGRAPH_INT64_MSB
#define HASH_OFFSET (8)
#define MASK1 CGRAPH_INT64_MASK1
#define MASK2 CGRAPH_INT64_MASK2
#define MASK4 CGRAPH_INT64_MASK4
#define MASK8 CGRAPH_INT64_MASK8
#define MASK16 CGRAPH_INT64_MASK16
#define MASK32 CGRAPH_INT64_MASK32

/** template module */
#include "cgraph_template_int.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT64_H__ */
