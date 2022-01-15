/**
 * @file cgraph_float128.h
 * @brief the apis of DATA TYPE cgraph_float128_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_FLOAT128_H__
#define __CGRAPH_FLOAT128_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_FLOAT128
#include "cgraph_template.h"

#ifdef __WITH_INT128_SIZE128
#define TYPE_FLOAT128_SIZE128
#elif defined(__WITH_INT128_SIZE80)
#define TYPE_FLOAT128_SIZE80
#else
#define TYPE_FLOAT128_SIZE64
#endif

#define ARG cgraph_float128_t
#define NAME float128
#define TYPE TYPE_T(NAME)
#define ID ID_T(FLOAT128)
#define BITS CGRAPH_FLOAT128_BITS
#define IN_FMT CGRAPH_FLOAT128_IN_FMT
#define OUT_FMT CGRAPH_FLOAT128_OUT_FMT
#define ZERO (0.0)
#define ONE (1.0)
#define ONES (1.0)
#define MIN CGRAPH_FLOAT128_MIN
#define MAX CGRAPH_FLOAT128_MAX
#define NAN CGRAPH_FLOAT128_NAN
#define INF CGRAPH_FLOAT128_INF
#define PINF CGRAPH_FLOAT128_PINF
#define NINF CGRAPH_FLOAT128_NINF
#define EPS CGRAPH_FLOAT128_EPS
#define EPS_LEN CGRAPH_FLOAT128_DIG
#define HASH_OFS CGRAPH_FLOAT128_HASH_OFS
#define FRAC_BITS CGRAPH_FLOAT128_FRAC_BITS
#define EXP_BITS CGRAPH_FLOAT128_EXP_BITS
#define DATA_NAME int128
#define DATA_ID ID_T(INT128)

/** template module */
#include "cgraph_template_float.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT128_H__ */
