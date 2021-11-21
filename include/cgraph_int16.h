/**
 * @file cgraph_int16.h
 * @brief the apis of DATA TYPE cgraph_int16_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_INT16_H__
#define __CGRAPH_INT16_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT16
#include "cgraph_template.h"

#define ARG cgraph_long_t
#define NAME int16
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT16)
#define BITS CGRAPH_INT16_BITS
#define BITS_LOG2 CGRAPH_INT16_BITS_LOG2
#define IN_FMT CGRAPH_INT16_IN_FMT
#define OUT_FMT CGRAPH_INT16_OUT_FMT
#define UNAME uint16
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT16)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT16_MIN
#define MIN CGRAPH_INT16_MIN
#define MAX CGRAPH_INT16_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPS CGRAPH_INT16_EPS
#define EPS_LEN CGRAPH_INT16_BITS
#define EPS1 (0xAAAAU)
#define EPS2 (0xCCCCU)
#define EPS4 (0xF0F0U)
#define EPS8 (0xFF00U)

/** template module */
#include "cgraph_template_int.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT16_H__ */
