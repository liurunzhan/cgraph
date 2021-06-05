/**
 * @file cgraph_int64.h
 * @brief the apis of DATA TYPE cgraph_int64_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_INT128_H__
#define __CGRAPH_INT128_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#ifndef CGRAPH_INT128_BUFFER_SIZE
#define CGRAPH_INT128_BUFFER_SIZE 40
#endif

#define TYPE_INT128
#include "cgraph_template.h"

/** template module */
#include "cgraph_template_int.ht"

extern cgraph_char_t *FUNCTION(NAME, encode)(const TYPE cthis);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT128_H__ */
