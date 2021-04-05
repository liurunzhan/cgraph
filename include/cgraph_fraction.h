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

#ifndef _CGRAPH_FRACTION_H_
#define _CGRAPH_FRACTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_FRACTION
#include "cgraph_template.h"

typedef struct {
  DATA_TYPE data[2];
} cgraph_fraction_t;

#define FRACTION_NUM(x) ((x).data[0])
#define FRACTION_DEN(x) ((x).data[1])
#define FRACTION_VALUE(x) (1.0 * FRACTION_NUM(x) / FRACTION_DEN(x))

#include "cgraph_template_data.ht"

/**                            initial functions */
extern TYPE FUNCTION(NAME, initf32)(const cgraph_float32_t data);
extern TYPE FUNCTION(NAME, initf64)(const cgraph_float64_t data);
extern TYPE FUNCTION(NAME, initwnd)(const DATA_TYPE num, const DATA_TYPE den);
extern TYPE FUNCTION(NAME, initwn)(const DATA_TYPE num);
extern TYPE FUNCTION(NAME, initwd)(const DATA_TYPE den);

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

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_FRACTION_H_ */
