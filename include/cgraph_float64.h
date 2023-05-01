/**
 * @file cgraph_float64.h
 * @brief the apis of DATA TYPE cgraph_float64_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_FLOAT64_H__
#define __CGRAPH_FLOAT64_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_FLOAT64
#include "cgraph_template.h"

#define DATA_NAME int64
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(INT64)
#define DATA_UNAME uint64
#define DATA_UTYPE TYPE_T(DATA_UNAME)

#define ARG cgraph_float64_t
#define NAME float64
#define TYPE TYPE_T(NAME)
#define TYPE_C(x) DBL_C(x)
#define ID ID_T(FLOAT64)
#define BITS CGRAPH_FLOAT64_BITS
#define IN_FMT "%g"
#define OUT_FMT "%g"
#define ZERO (0.0)
#define ONE (1.0)
#define ONES (1.0)
#define MIN CGRAPH_FLOAT64_MIN
#define MAX CGRAPH_FLOAT64_MAX
#define NAN CGRAPH_FLOAT64_NAN
#define INF CGRAPH_FLOAT64_INF
#define PINF CGRAPH_FLOAT64_PINF
#define NINF CGRAPH_FLOAT64_NINF
#define EPSILON CGRAPH_FLOAT64_EPSILON
#define EPSILON_LEN CGRAPH_FLOAT64_DIG
#define HASH_OFFSET (8)
#define FRAC_BITS CGRAPH_FLOAT64_FRAC_BITS
#define FRAC_OFFSET CGRAPH_FLOAT64_FRAC_OFFSET
#define FRAC_MASK CGRAPH_FLOAT64_FRAC_MASK
#define EXP_BITS CGRAPH_FLOAT64_EXP_BITS
#define EXP_OFFSET CGRAPH_FLOAT64_EXP_OFFSET
#define EXP_MASK CGRAPH_FLOAT64_EXP_MASK
#define EXP_BIAS CGRAPH_FLOAT64_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT64_SIG_BITS
#define SIG_OFFSET CGRAPH_FLOAT64_SIG_OFFSET
#define SIG_MASK CGRAPH_FLOAT64_SIG_MASK

/** template module */
#include "cgraph_template_float.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT64_H__ */
