/**
 * @file cgraph_long.h
 * @brief the apis of DATA TYPE cgraph_long_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_LONG_H__
#define __CGRAPH_LONG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_LONG
#include "cgraph_template.h"

#if __WORDSIZE == 64
#define TYPE_LONG_SIZE64
#else
#define TYPE_LONG_SIZE32
#endif

#define ARG cgraph_long_t
#define NAME long
#define TYPE TYPE_T(NAME)
#define ID ID_T(LONG)
#define BITS CGRAPH_LONG_BITS
#define L2BITS CGRAPH_LONG_L2BITS
#define IN_FMT "%ld"
#define OUT_FMT "%ld"
#define UNAME ulong
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(ULONG)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_LONG_MAX
#define MIN CGRAPH_LONG_MIN
#define MAX CGRAPH_LONG_MAX
#define MASK CGRAPH_LONG_MASK
#define EPSILON CGRAPH_LONG_EPSILON
#define NAN ZERO
#define LSB CGRAPH_LONG_LSB
#define MSB CGRAPH_LONG_MSB
#define MASK1 CGRAPH_LONG_MASK1
#define MASK2 CGRAPH_LONG_MASK2
#define MASK4 CGRAPH_LONG_MASK4
#define MASK8 CGRAPH_LONG_MASK8
#define MASK16 CGRAPH_LONG_MASK16
#define MASK32 CGRAPH_LONG_MASK32
#define MASK64 CGRAPH_LONG_MASK64

/** template module */
#include "cgraph_template_int.ht"

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_LONG_H__ */
