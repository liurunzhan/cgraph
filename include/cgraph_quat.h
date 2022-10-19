/**
 * @file cgraph_quat.h
 * @brief the apis of DATA TYPE cgraph_quat_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_QUAT_H__
#define __CGRAPH_QUAT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_QUAT
#include "cgraph_template.h"

#define DATA_INUM (4)

#define DATA_TYPE cgraph_float64_t

#if DATA_INUM != 4
#error DATA_INUM must be defined as 4, or will throw a compilation error
#endif

/**
 * @struct cgraph_quat_t
 * @brief the object of quaternion number
 */
typedef struct {
  DATA_TYPE data[DATA_INUM];
} cgraph_quat_t;

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_QUAT_H__ */
