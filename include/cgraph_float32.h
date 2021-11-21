/**
 * @file cgraph_float32.h
 * @brief the apis of DATA TYPE cgraph_float32_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_FLOAT32_H__
#define __CGRAPH_FLOAT32_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_FLOAT32
#include "cgraph_template.h"

#define ARG cgraph_float64_t
#define NAME float32
#define TYPE TYPE_T(NAME)
#define ID ID_T(FLOAT32)
#define BITS CGRAPH_FLOAT32_BITS
#define IN_FMT "%g"
#define OUT_FMT "%g"
#define ZERO (0.0)
#define ONE (1.0)
#define ONES (1.0)
#define MIN CGRAPH_FLOAT32_MIN
#define MAX CGRAPH_FLOAT32_MAX
#define EPS CGRAPH_FLOAT32_EPS
#define EPS_LEN CGRAPH_FLOAT32_DIG
#define HASH_OFS (4)
#define FRAC_BITS CGRAPH_FLOAT32_FRAC_BITS
#define FRAC_OFS CGRAPH_FLOAT32_FRAC_OFS
#define FRAC_EPS CGRAPH_FLOAT32_FRAC_EPS
#define EXP_BITS CGRAPH_FLOAT32_EXP_BITS
#define EXP_OFS CGRAPH_FLOAT32_EXP_OFS
#define EXP_EPS CGRAPH_FLOAT32_EXP_EPS
#define EXP_BIAS CGRAPH_FLOAT32_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT32_SIG_BITS
#define SIG_OFS CGRAPH_FLOAT32_SIG_OFS
#define SIG_EPS CGRAPH_FLOAT32_SIG_EPS
#define DATA_NAME int32
#define DATA_ID ID_T(INT32)

/** template module */
#include "cgraph_template_float.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT32_H__ */
