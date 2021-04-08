/**
 * @file cgraph_float128.h
 * @brief the apis of DATA TYPE cgraph_float128_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_FLOAT128_H_
#define _CGRAPH_FLOAT128_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_FLOAT128
#include "cgraph_template.h"

/** template module */
#include "cgraph_template_float.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_FLOAT128_H_ */
