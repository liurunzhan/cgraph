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

#define ARG cgraph_float64_t
#define NAME float64
#define TYPE TYPE_T(NAME)
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
#define EPS CGRAPH_FLOAT64_EPS
#define EPS_LEN CGRAPH_FLOAT64_DIG
#define HASH_OFS (8)
#define FRAC_BITS CGRAPH_FLOAT64_FRAC_BITS
#define FRAC_OFS CGRAPH_FLOAT64_FRAC_OFS
#define FRAC_EPS CGRAPH_FLOAT64_FRAC_EPS
#define EXP_BITS CGRAPH_FLOAT64_EXP_BITS
#define EXP_OFS CGRAPH_FLOAT64_EXP_OFS
#define EXP_EPS CGRAPH_FLOAT64_EXP_EPS
#define EXP_BIAS CGRAPH_FLOAT64_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT64_SIG_BITS
#define SIG_OFS CGRAPH_FLOAT64_SIG_OFS
#define SIG_EPS CGRAPH_FLOAT64_SIG_EPS
#define DATA_NAME int64
#define DATA_ID ID_T(INT64)

/** template module */
#include "cgraph_template_float.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT64_H__ */
