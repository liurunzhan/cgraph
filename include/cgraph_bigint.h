/**
 * @file  cgraph_bigint.h
 * @brief
 * @author       Liurunzhan
 * @date     2021-02-06
 * @version  0.0.0
 * @copyright GPL 3.0
 */

#ifndef _CGRAPH_BIGINT_H_
#define _CGRAPH_BIGINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGINT
#include "cgraph_template.h"

typedef struct {
  CGRAPH_DATA_BASE
  cgraph_bool_t postive;
  CGRAPH_DATA_ROOT
} cgraph_bigint_t;

#include "cgraph_template_data.ht"

extern TYPE *FUNCTION(NAME, unit)(TYPE *cthis, const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, unit_inv)(TYPE *cthis, const cgraph_size_t len);
extern cgraph_size_t FUNCTION(NAME, cntones)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, cntzeros)(const TYPE *cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGINT_H_ */
