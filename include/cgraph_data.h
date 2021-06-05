/**
 * @file cgraph_data.h
 * @brief the apis of data types in cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_DATA_H__
#define __CGRAPH_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_bigint.h"
#include "cgraph_bignum.h"
#include "cgraph_bitset.h"
#include "cgraph_bool.h"
#include "cgraph_complex.h"
#include "cgraph_float128.h"
#include "cgraph_float16.h"
#include "cgraph_float32.h"
#include "cgraph_float64.h"
#include "cgraph_float8.h"
#include "cgraph_fraction.h"
#include "cgraph_int.h"
#include "cgraph_int128.h"
#include "cgraph_int16.h"
#include "cgraph_int32.h"
#include "cgraph_int64.h"
#include "cgraph_int8.h"
#include "cgraph_logic.h"
#include "cgraph_long.h"
#include "cgraph_string.h"
#include "cgraph_time.h"

extern cgraph_string_t *cgraph_bool_to_string(const cgraph_bool_t x);
extern cgraph_string_t *cgraph_bigint_to_string(const cgraph_bigint_t *cthis);
extern cgraph_bigint_t *cgraph_string_to_bigint(const cgraph_string_t *cthis);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_DATA_H__ */
