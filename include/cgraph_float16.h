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

#define DATA_NAME int16
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(INT16)
#define DATA_UNAME uint16
#define DATA_UTYPE TYPE_T(DATA_UNAME)

#define ARG cgraph_float64_t
#define NAME float16
#define TYPE TYPE_T(NAME)
#define ID ID_T(FLOAT16)
#define BITS CGRAPH_FLOAT16_BITS
#define IN_FMT CGRAPH_FLOAT16_IN_FMT
#define OUT_FMT CGRAPH_FLOAT16_OUT_FMT
#define ZERO FUNCTION(NAME, zero)()
#define ONE FUNCTION(NAME, one)()
#define ONES ONE
#define MIN CGRAPH_FLOAT16_MIN
#define MAX CGRAPH_FLOAT16_MAX
#define NAN CGRAPH_FLOAT16_NAN
#define INF CGRAPH_FLOAT16_INF
#define PINF CGRAPH_FLOAT16_PINF
#define NINF CGRAPH_FLOAT16_NINF
#define EPSILON CGRAPH_FLOAT16_EPSILON
#define EPSILON_LEN CGRAPH_FLOAT16_DIG
#define HASH_OFFSET (2)
#define FRAC_BITS CGRAPH_FLOAT16_FRAC_BITS
#define FRAC_OFFSET CGRAPH_FLOAT16_FRAC_OFFSET
#define FRAC_MASK CGRAPH_FLOAT16_FRAC_MASK
#define EXP_BITS CGRAPH_FLOAT16_EXP_BITS
#define EXP_OFFSET CGRAPH_FLOAT16_EXP_OFFSET
#define EXP_MASK CGRAPH_FLOAT16_EXP_MASK
#define EXP_BIAS CGRAPH_FLOAT16_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT16_SIG_BITS
#define SIG_OFFSET CGRAPH_FLOAT16_SIG_OFFSET
#define SIG_MASK CGRAPH_FLOAT16_SIG_MASK

/** template module */
#include "cgraph_template_float_soft.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT16_H__ */
