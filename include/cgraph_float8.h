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

#define DATA_NAME int8
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(INT8)
#define DATA_UNAME uint8
#define DATA_UTYPE TYPE_T(DATA_UNAME)

#define ARG cgraph_float64_t
#define NAME float8
#define TYPE TYPE_T(NAME)
#define ID ID_T(FLOAT8)
#define BITS CGRAPH_FLOAT8_BITS
#define IN_FMT CGRAPH_FLOAT8_IN_FMT
#define OUT_FMT CGRAPH_FLOAT8_OUT_FMT
#define ZERO FUNCTION(NAME, zero)()
#define ONE FUNCTION(NAME, one)()
#define ONES ONE
#define MIN CGRAPH_FLOAT8_MIN
#define MAX CGRAPH_FLOAT8_MAX
#define NAN CGRAPH_FLOAT8_NAN
#define INF CGRAPH_FLOAT8_INF
#define PINF CGRAPH_FLOAT8_PINF
#define NINF CGRAPH_FLOAT8_NINF
#define EPSILON CGRAPH_FLOAT8_EPSILON
#define EPSILON_LEN CGRAPH_FLOAT8_DIG
#define HASH_OFFSET (1)
#define FRAC_BITS CGRAPH_FLOAT8_FRAC_BITS
#define FRAC_OFFSET CGRAPH_FLOAT8_FRAC_OFFSET
#define FRAC_MASK CGRAPH_FLOAT8_FRAC_MASK
#define EXP_BITS CGRAPH_FLOAT8_EXP_BITS
#define EXP_OFFSET CGRAPH_FLOAT8_EXP_OFFSET
#define EXP_MASK CGRAPH_FLOAT8_EXP_MASK
#define EXP_BIAS CGRAPH_FLOAT8_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT8_SIG_BITS
#define SIG_OFFSET CGRAPH_FLOAT8_SIG_OFFSET
#define SIG_MASK CGRAPH_FLOAT8_SIG_MASK

/** template module */
#include "cgraph_template_float_soft.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT8_H__ */
