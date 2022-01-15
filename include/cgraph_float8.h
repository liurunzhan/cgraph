/**
 * @file cgraph_float8.h
 * @brief the apis of DATA TYPE cgraph_float8_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_FLOAT8_H__
#define __CGRAPH_FLOAT8_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_FLOAT8
#include "cgraph_template.h"

#define ARG cgraph_int_t
#define NAME float8
#define TYPE TYPE_T(NAME)
#define ID ID_T(FLOAT8)
#define BITS CGRAPH_FLOAT8_BITS
#define IN_FMT "%g"
#define OUT_FMT "%g"
#define ZERO (0)
#define ONE (CGRAPH_FLOAT8_EXP_BIAS << CGRAPH_FLOAT8_EXP_OFS)
#define ONES ONE
#define MIN CGRAPH_FLOAT8_MIN
#define MAX CGRAPH_FLOAT8_MAX
#define NAN CGRAPH_FLOAT8_NAN
#define INF CGRAPH_FLOAT8_INF
#define PINF CGRAPH_FLOAT8_PINF
#define NINF CGRAPH_FLOAT8_NINF
#define EPS CGRAPH_FLOAT8_EPS
#define EPS_LEN CGRAPH_FLOAT8_DIG
#define HASH_OFS (1)
#define FRAC_BITS CGRAPH_FLOAT8_FRAC_BITS
#define FRAC_OFS CGRAPH_FLOAT8_FRAC_OFS
#define FRAC_EPS CGRAPH_FLOAT8_FRAC_EPS
#define EXP_BITS CGRAPH_FLOAT8_EXP_BITS
#define EXP_OFS CGRAPH_FLOAT8_EXP_OFS
#define EXP_EPS CGRAPH_FLOAT8_EXP_EPS
#define EXP_BIAS CGRAPH_FLOAT8_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT8_SIG_BITS
#define SIG_OFS CGRAPH_FLOAT8_SIG_OFS
#define SIG_EPS CGRAPH_FLOAT8_SIG_EPS
#define DATA_NAME int8
#define DATA_ID ID_T(INT8)

/** template module */
#include "cgraph_template_float_soft.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT8_H__ */
