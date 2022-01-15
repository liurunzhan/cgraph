/**
 * @file cgraph_float16.h
 * @brief the apis of DATA TYPE cgraph_float16_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_FLOAT16_H__
#define __CGRAPH_FLOAT16_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_FLOAT16
#include "cgraph_template.h"

#define ARG cgraph_int_t
#define NAME float16
#define TYPE TYPE_T(NAME)
#define ID ID_T(FLOAT16)
#define BITS CGRAPH_FLOAT16_BITS
#define IN_FMT "%g"
#define OUT_FMT "%g"
#define ZERO (0)
#define ONE (CGRAPH_FLOAT16_EXP_BIAS << CGRAPH_FLOAT16_EXP_OFS)
#define ONES ONE
#define MIN CGRAPH_FLOAT16_MIN
#define MAX CGRAPH_FLOAT16_MAX
#define NAN CGRAPH_FLOAT16_NAN
#define INF CGRAPH_FLOAT16_INF
#define PINF CGRAPH_FLOAT16_PINF
#define NINF CGRAPH_FLOAT16_NINF
#define EPS CGRAPH_FLOAT16_EPS
#define EPS_LEN CGRAPH_FLOAT16_DIG
#define HASH_OFS (2)
#define FRAC_BITS CGRAPH_FLOAT16_FRAC_BITS
#define FRAC_OFS CGRAPH_FLOAT16_FRAC_OFS
#define FRAC_EPS CGRAPH_FLOAT16_FRAC_EPS
#define EXP_BITS CGRAPH_FLOAT16_EXP_BITS
#define EXP_OFS CGRAPH_FLOAT16_EXP_OFS
#define EXP_EPS CGRAPH_FLOAT16_EXP_EPS
#define EXP_BIAS CGRAPH_FLOAT16_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT16_SIG_BITS
#define SIG_OFS CGRAPH_FLOAT16_SIG_OFS
#define SIG_EPS CGRAPH_FLOAT16_SIG_EPS
#define DATA_NAME int16
#define DATA_ID ID_T(INT16)

/** template module */
#include "cgraph_template_float_soft.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT16_H__ */
