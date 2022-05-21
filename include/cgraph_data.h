/**
 * @file cgraph_data.h
 * @brief the apis of data types in cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
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
#include "cgraph_point2d.h"
#include "cgraph_point3d.h"
#include "cgraph_string.h"
#include "cgraph_time.h"

/** used to clear command macro variables */
#include "cgraph_template_off.h"

extern cgraph_point3d_t cgraph_point2d_xmul(const cgraph_point2d_t x,
                                            const cgraph_point2d_t y);

extern cgraph_logic_t cgraph_bool_to_logic(const cgraph_bool_t x);
extern cgraph_bool_t cgraph_logic_to_bool(const cgraph_logic_t x);

extern cgraph_string_t *cgraph_bool_to_string(const cgraph_bool_t x);
extern cgraph_bool_t cgraph_string_to_bool(const cgraph_string_t *cthis);

extern cgraph_string_t *cgraph_bigint_to_string(const cgraph_bigint_t *cthis);
extern cgraph_bigint_t *cgraph_string_to_bigint(const cgraph_string_t *cthis);

extern cgraph_bignum_t *cgraph_bigint_to_bignum(const cgraph_bigint_t *cthis);
extern cgraph_bigint_t *cgraph_bignum_to_bigint(const cgraph_bignum_t *cthis);

extern cgraph_bitset_t *cgraph_bigint_to_bitset(const cgraph_bigint_t *cthis);
extern cgraph_bigint_t *cgraph_bitset_to_bigint(const cgraph_bitset_t *cthis);

extern cgraph_float16_t cgraph_float8_to_float16(const cgraph_float8_t x);
extern cgraph_float32_t cgraph_float8_to_float32(const cgraph_float8_t x);
extern cgraph_float64_t cgraph_float8_to_float64(const cgraph_float8_t x);
extern cgraph_float128_t cgraph_float8_to_float128(const cgraph_float8_t x);

extern cgraph_float8_t cgraph_float16_to_float8(const cgraph_float16_t x);
extern cgraph_float32_t cgraph_float16_to_float32(const cgraph_float16_t x);
extern cgraph_float64_t cgraph_float16_to_float64(const cgraph_float16_t x);
extern cgraph_float128_t cgraph_float16_to_float128(const cgraph_float16_t x);

extern cgraph_float8_t cgraph_float32_to_float8(const cgraph_float32_t x);
extern cgraph_float16_t cgraph_float32_to_float16(const cgraph_float32_t x);
extern cgraph_float64_t cgraph_float32_to_float64(const cgraph_float32_t x);
extern cgraph_float128_t cgraph_float32_to_float128(const cgraph_float32_t x);

extern cgraph_float8_t cgraph_float64_to_float8(const cgraph_float64_t x);
extern cgraph_float16_t cgraph_float64_to_float16(const cgraph_float64_t x);
extern cgraph_float32_t cgraph_float64_to_float32(const cgraph_float64_t x);
extern cgraph_float128_t cgraph_float64_to_float128(const cgraph_float64_t x);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_DATA_H__ */
