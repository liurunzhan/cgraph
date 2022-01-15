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
#define BITS_LOG2 CGRAPH_LONG_BITS_LOG2
#define IN_FMT "%ld"
#define OUT_FMT "%ld"
#define UNAME ulong
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(ULONG)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_LONG_MIN
#define MIN CGRAPH_LONG_MIN
#define MAX CGRAPH_LONG_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPS CGRAPH_LONG_EPS
#define EPS_LEN CGRAPH_LONG_BITS
#define EPS1 CGRAPH_LONG_EPS1
#define EPS2 CGRAPH_LONG_EPS2
#define EPS4 CGRAPH_LONG_EPS4
#define EPS8 CGRAPH_LONG_EPS8
#define EPS16 CGRAPH_LONG_EPS16
#define EPS32 CGRAPH_LONG_EPS32

/** template module */
#include "cgraph_template_int.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_LONG_H__ */
