/**
 * @file cgraph_float16.h
 * @brief the apis of DATA TYPE cgraph_float16_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_FLOAT16_H__
#define __CGRAPH_FLOAT16_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_FLOAT16
#include "cgraph_template.h"

/** template module */
#include "cgraph_template_float_soft.ht"

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_FLOAT16_H__ */
