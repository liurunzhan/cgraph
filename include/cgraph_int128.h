/**
 * @file cgraph_int128.h
 * @brief the apis of DATA TYPE cgraph_int128_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_INT128_H__
#define __CGRAPH_INT128_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_INT128
#include "cgraph_template.h"

#define DATA_TYPE __INT128_DTYPE

#define ARG cgraph_long_t
#define NAME int128
#define TYPE TYPE_T(NAME)
#define ID ID_T(INT128)
#define BITS CGRAPH_INT128_BITS
#define BITS_LOG2 CGRAPH_INT128_BITS_LOG2
#define IN_FMT CGRAPH_INT128_IN_FMT
#define OUT_FMT CGRAPH_INT128_OUT_FMT
#define UNAME uint128
#define UTYPE TYPE_T(UNAME)
#define UID ID_T(UINT128)
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT128_MAX
#define MIN CGRAPH_INT128_MIN
#define MAX CGRAPH_INT128_MAX
#define NAN ZERO
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPS CGRAPH_INT128_EPS
#define EPS_LEN CGRAPH_INT128_BITS
#define HASH_OFS (8)
#define EPS1 CGRAPH_INT128_EPS1
#define EPS2 CGRAPH_INT128_EPS2
#define EPS4 CGRAPH_INT128_EPS4
#define EPS8 CGRAPH_INT128_EPS8
#define EPS16 CGRAPH_INT128_EPS16
#define EPS32 CGRAPH_INT128_EPS32
#define EPS64 CGRAPH_INT128_EPS64

/** template module */
#define CGRAPH_INT128_CBUF_SIZE CGRAPH_CBUF_SIZE0
#include "cgraph_template_cbuf.ht"
#include "cgraph_template_int.ht"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_INT128_H__ */
