/**
 * @file cgraph_float32.h
 * @brief the apis of DATA TYPE cgraph_float32_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
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

#define DATA_NAME int32
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(INT32)
#define DATA_UNAME uint8
#define DATA_UTYPE TYPE_T(DATA_UNAME)

#define ARG cgraph_float64_t
#define NAME float32
#define TYPE TYPE_T(NAME)
#define TYPE_C(x) FLT_C(x)
#define ID ID_T(FLOAT32)
#define BITS CGRAPH_FLOAT32_BITS
#define IN_FMT "%g"
#define OUT_FMT "%g"
#define ZERO (0.0f)
#define ONE (1.0f)
#define ONES (1.0f)
#define MIN CGRAPH_FLOAT32_MIN
#define MAX CGRAPH_FLOAT32_MAX
#define NAN CGRAPH_FLOAT32_NAN
#define INF CGRAPH_FLOAT32_INF
#define PINF CGRAPH_FLOAT32_PINF
#define NINF CGRAPH_FLOAT32_NINF
#define EPSILON CGRAPH_FLOAT32_EPSILON
#define EPSILON_LEN CGRAPH_FLOAT32_DIG
#define HASH_OFFSET (4)
#define FRAC_BITS CGRAPH_FLOAT32_FRAC_BITS
#define FRAC_OFFSET CGRAPH_FLOAT32_FRAC_OFFSET
#define FRAC_MASK CGRAPH_FLOAT32_FRAC_MASK
#define EXP_BITS CGRAPH_FLOAT32_EXP_BITS
#define EXP_OFFSET CGRAPH_FLOAT32_EXP_OFFSET
#define EXP_MASK CGRAPH_FLOAT32_EXP_MASK
#define EXP_BIAS CGRAPH_FLOAT32_EXP_BIAS
#define SIG_BITS CGRAPH_FLOAT32_SIG_BITS
#define SIG_OFFSET CGRAPH_FLOAT32_SIG_OFFSET
#define SIG_MASK CGRAPH_FLOAT32_SIG_MASK

/** template module */
#include "cgraph_template_float.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT32_H__ */
