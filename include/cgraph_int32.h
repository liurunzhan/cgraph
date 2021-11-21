/**
 * @file cgraph_int32.h
 * @brief the apis of DATA TYPE cgraph_int32_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_INT32_H__
#define __CGRAPH_INT32_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT32
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int32
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT32)
#define BITS CGRAPH_INT32_BITS
#define BITS_LOG2 CGRAPH_INT32_BITS_LOG2
#define IN_FMT CGRAPH_INT32_IN_FMT
#define OUT_FMT CGRAPH_INT32_OUT_FMT
#define UNAME uint32
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT32)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT32_MIN
#define MIN CGRAPH_INT32_MIN
#define MAX CGRAPH_INT32_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPS CGRAPH_INT32_EPS
#define EPS_LEN CGRAPH_INT32_BITS
#define HASH_OFS (4)
#define EPS1 (0xAAAAAAAAU)
#define EPS2 (0xCCCCCCCCU)
#define EPS4 (0xF0F0F0F0U)
#define EPS8 (0xFF00FF00U)
#define EPS16 (0xFFFF0000U)

/** template module */
#include "cgraph_template_int.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT32_H__ */
