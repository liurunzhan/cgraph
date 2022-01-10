/**
 * @file cgraph_fraction.h
 * @brief the apis of DATA TYPE cgraph_fraction_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_FRACTION_H__
#define __CGRAPH_FRACTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_FRACTION
#include "cgraph_template.h"

#define NAME fraction
#define TYPE TYPE_T(NAME)
#define ID ID_T(FRACTION)
#define BITS (8 * sizeof(TYPE))
#define IN_FMT "%d/%d"
#define OUT_FMT "%d/%d"
#define OUT_FMT_NUM "%d"
#define ZERO ((TYPE){{0, 1}})
#define ONE ((TYPE){{1, 1}})
#define ONES ((TYPE){{CGRAPH_INT_MIN, 1}})
#define MIN ((TYPE){{CGRAPH_INT_MIN, 1}})
#define MAX ((TYPE){{CGRAPH_INT_MAX, 1}})
#define NAN ((TYPE){{0, 0}})
#define INF ((TYPE){{1, 0}})
#define PINF ((TYPE){{1, 0}})
#define NINF ((TYPE){{-1, 0}})
#define EPS ((TYPE){{-1, CGRAPH_INT_MIN}})
#define EPS_LEN (8 * sizeof(TYPE))
#define DATA_NAME int
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(INT)
#define DATA_BITS CGRAPH_INT_BITS
#define DATA_ZERO (0)
#define DATA_ONE (1)
#define DATA_ONES CGRAPH_INT_MIN
#define DATA_MIN CGRAPH_INT_MIN
#define DATA_MAX CGRAPH_INT_MAX
#define DATA_MSB (DATA_ONE << (DATA_BITS - 1))
#define DATA_LSB (DATA_ONE)
#define DATA_EPS CGRAPH_INT_EPS

/**
 * @struct cgraph_fraction_t
 * @brief the object of fraction number
 */
typedef struct {
  DATA_TYPE data[2];
} cgraph_fraction_t;

#define FRACTION_NUM(x) ((x).data[0])
#define FRACTION_DEN(x) ((x).data[1])
#define FRACTION_VALUE(x) (1.0 * FRACTION_NUM(x) / FRACTION_DEN(x))

/** template module */
#define CGRAPH_FRACTION_CBUF_SIZE CGRAPH_CBUF_SIZE0
#include "cgraph_template_cbuf.ht"
#include "cgraph_template_data.ht"

/** initial functions */
extern TYPE FUNCTION(NAME, initnd)(const DATA_TYPE num, const DATA_TYPE den);
extern TYPE FUNCTION(NAME, initn)(const DATA_TYPE num);
extern TYPE FUNCTION(NAME, initd)(const DATA_TYPE den);

extern TYPE FUNCTION(NAME, addn)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subn)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muln)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divn)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, pown)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, addd)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subd)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muld)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divd)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, powd)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, opp)(const TYPE x);
extern TYPE FUNCTION(NAME, abs)(const TYPE x);
extern TYPE FUNCTION(NAME, mod)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, unit)(const DATA_TYPE x);
extern TYPE FUNCTION(NAME, unit_inv)(const DATA_TYPE x);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FRACTION_H__ */
