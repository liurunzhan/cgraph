/**
 * @file cgraph_point3d.h
 * @brief the apis of DATA TYPE cgraph_pont3d_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_POINT3D_H__
#define __CGRAPH_POINT3D_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_POINT3D
#include "cgraph_template.h"

/** data details: if needs another data memory, define Macro TYPE_WITH_DATA */
#define DATA_INUM (3)
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

/** type details: */
#define NAME point3d
#define TYPE TYPE_T(NAME)
#define ID ID_T(POINT3D)
#define BITS (sizeof(TYPE))
#define IN_FMT "(%lf,%lf,%lf)"
#define OUT_FMT "(%g,%g,%g)"
#if __STDC_VERSION__ >= 199901L
#define ZERO ((TYPE){{DATA_ZERO, DATA_ZERO, DATA_ZERO}})
#define ONE ((TYPE){{DATA_ONE, DATA_ZERO, DATA_ZERO}})
#define ONES ((TYPE){{DATA_ONE, DATA_ONE, DATA_ONE}})
#define MIN ((TYPE){{DATA_MIN, DATA_MIN, DATA_MIN}})
#define MAX ((TYPE){{DATA_MAX, DATA_MAX, DATA_MAX}})
#define NAN ((TYPE){{DATA_NAN, DATA_NAN, DATA_NAN}})
#define INF ((TYPE){{DATA_INF, DATA_INF, DATA_INF}})
#define PINF ((TYPE){{DATA_PINF, DATA_PINF, DATA_PINF}})
#define NINF ((TYPE){{DATA_NINF, DATA_NINF, DATA_NINF}})
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
 * @struct cgraph_point3d_t
 * @brief the object of 3-d point
 */
typedef struct {
  DATA_TYPE data[DATA_INUM];
} cgraph_point3d_t;

#if DATA_INUM != 3
#error DATA_INUM must be defined as 3, or will throw a compilation error
#endif

#define POINT3D_X(x) ((x).data[0])
#define POINT3D_Y(x) ((x).data[1])
#define POINT3D_Z(x) ((x).data[2])
#define POINT3D_MAG2(x)                                                        \
  ((POINT3D_X(x) * POINT3D_X(x)) + (POINT3D_Y(x) * POINT3D_Y(x)) +             \
   (POINT3D_Z(x) * POINT3D_Z(x)))

/** template module */
#include "cgraph_template_data.ht"

#include "cgraph_template_point.ht"

extern TYPE FUNCTION(NAME, mixed)(const TYPE x, const TYPE y, const TYPE z);
extern DATA_TYPE FUNCTION(NAME, fmixed)(const TYPE x, const TYPE y,
                                        const TYPE z);
extern TYPE FUNCTION(NAME, triple)(const TYPE x, const TYPE y, const TYPE z);
extern DATA_TYPE FUNCTION(NAME, det)(const TYPE x, const TYPE y, const TYPE z);

extern TYPE FUNCTION(NAME, rev2)(const TYPE x);

extern TYPE FUNCTION(NAME, xrotl)(const TYPE x, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, xrotr)(const TYPE x, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, yrotl)(const TYPE x, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, yrotr)(const TYPE x, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, zrotl)(const TYPE x, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, zrotr)(const TYPE x, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, arol)(const TYPE x, const TYPE r,
                                 const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, aror)(const TYPE x, const TYPE r,
                                 const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, arol_inv)(const TYPE x, const TYPE r,
                                     const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, aror_inv)(const TYPE x, const TYPE r,
                                     const DATA_TYPE angle);

extern TYPE FUNCTION(NAME, scale)(const TYPE x, const TYPE rate);
extern TYPE FUNCTION(NAME, lookat)(const TYPE x, const TYPE r, const TYPE u,
                                   const TYPE d, const TYPE p);
extern TYPE FUNCTION(NAME, glfrustum)(const TYPE x, const TYPE min,
                                      const TYPE max);
extern TYPE FUNCTION(NAME, glvolume)(const TYPE x, const TYPE min,
                                     const TYPE max);

extern TYPE FUNCTION(NAME, line)(const TYPE x, const TYPE y, TYPE *p);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_POINT3D_H__ */
