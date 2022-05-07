/**
 * @file cgraph_point2d.h
 * @brief the apis of DATA TYPE cgraph_point2d_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_POINT2D_H__
#define __CGRAPH_POINT2D_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_POINT2D
#include "cgraph_template.h"

#define DATA_NAME float64
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(FLOAT64)
#define DATA_BITS CGRAPH_FLOAT64_BITS
#define DATA_ZERO (0.0)
#define DATA_ONE (1.0)
#define DATA_ONES (1.0)
#define DATA_MIN CGRAPH_FLOAT64_MIN
#define DATA_MAX CGRAPH_FLOAT64_MAX
#define DATA_NAN CGRAPH_FLOAT64_NAN
#define DATA_INF CGRAPH_FLOAT64_INF
#define DATA_PINF CGRAPH_FLOAT64_PINF
#define DATA_NINF CGRAPH_FLOAT64_NINF
#define DATA_EPSILON CGRAPH_FLOAT64_EPSILON
#define DATA_EPSILON_LEN CGRAPH_FLOAT64_BITS

#define NAME point2d
#define TYPE TYPE_T(NAME)
#define ID ID_T(POINT2D)
#define BITS (sizeof(TYPE))
#define IN_FMT "(%lf,%lf)"
#define OUT_FMT "(%g,%g)"
#if __STDC_VERSION__ >= 199901L
#define ZERO ((TYPE){{DATA_ZERO, DATA_ZERO}})
#define ONE ((TYPE){{DATA_ONE, DATA_ZERO}})
#define ONES ((TYPE){{DATA_ONE, DATA_ONE}})
#define MIN ((TYPE){{DATA_MIN, DATA_MIN}})
#define MAX ((TYPE){{DATA_MAX, DATA_MAX}})
#define NAN ((TYPE){{DATA_NAN, DATA_NAN}})
#define INF ((TYPE){{DATA_INF, DATA_INF}})
#define PINF ((TYPE){{DATA_PINF, DATA_PINF}})
#define NINF ((TYPE){{DATA_NINF, DATA_NINF}})
#else
#define ZERO FUNCTION(NAME, zero)()
#define ONE FUNCTION(NAME, one)()
#define ONES FUNCTION(NAME, ones)()
#define MIN FUNCTION(NAME, min)()
#define MAX FUNCTION(NAME, max)()
#define NAN FUNCTION(NAME, nan)()
#define INF FUNCTION(NAME, inf)()
#define PINF FUNCTION(NAME, pinf)()
#define NINF FUNCTION(NAME, ninf)()
#endif

/**
 * @struct cgraph_point2d_t
 * @brief the object of 2-d point
 */
typedef struct {
  DATA_TYPE data[2];
} cgraph_point2d_t;

#define POINT2D_X(x) ((x).data[0])
#define POINT2D_Y(x) ((x).data[1])
#define POINT2D_MAG2(x)                                                        \
  ((POINT2D_X(x) * POINT2D_X(x)) + (POINT2D_Y(x) * POINT2D_Y(x)))

/** template module */
#include "cgraph_template_data.ht"

#include "cgraph_template_point.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_POINT2D_H__ */
