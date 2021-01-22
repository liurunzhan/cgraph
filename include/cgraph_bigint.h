/**
 * @file  cgraph_bigint.h
 * @brief
 * @author       Liurunzhan
 * @date     2015-5-24
 * @version  0.0.0
 * @copyright Vincent
 */

#ifndef _CGRAPH_BIGINT_H_
#define _CGRAPH_BIGINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_BIGINT
#include "template.h"

typedef struct {
    CGRAPH_DATA_BASE
    cgraph_bool_t postive;
    CGRAPH_DATA_ROOT
} cgraph_bigint_t;

#include "data_base.ht"

extern TYPE *FUNCTION(NAME, unit)(const cgraph_size_t size);
extern TYPE *FUNCTION(NAME, unit_inv)(const cgraph_size_t size);
extern TYPE *FUNCTION(NAME, zero)(const cgraph_size_t size);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_BIGINT_H_ */
