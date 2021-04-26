/**
 * @file cgraph_math.h
 * @brief the basic mathematical functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_MATH_H__
#define __CGRAPH_MATH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

#include "cgraph_config.h"

/**                const numbers defined and used in this library */
#define MATH_ERROR (-1) /**MATH ERROR */
#if defined(M_PI)
#define MATH_CONST_PI (M_PI)
#else
#define MATH_CONST_PI (3.14159265358979323846)
#endif /** MATH_CONST_PI pi */

#define MATH_CONST_2PI (6.28318530717958647693) /** MATH_CONST_2PI : 2*pi */

#if defined(M_PI_2)
#define MATH_CONST_PI_2 (M_PI_2)
#else
#define MATH_CONST_PI_2 (1.57079632679489661923)
#endif /** MATH_CONST_PI_2 : pi/2 */

#if defined(M_2_PI)
#define MATH_CONST_2_PI (M_PI_2)
#else
#define MATH_CONST_2_PI (1.57079632679489661923)
#endif /** MATH_CONST_2_PI : 2/pi */

#if defined(M_E)
#define MATH_CONST_E (M_E)
#else
#define MATH_CONST_E (2.71828182845904523536)
#endif /** MATH_CONST_E : e */

#define MATH_CONST_PHI                                                         \
  (0.61803398874989484820) /** MATH_CONST_PHI : (sqrt(5)-1)/2 */

#if defined(M_LN2)
#define MATH_CONST_LOG2 (M_LN2)
#else
#define MATH_CONST_LOG2 (0.69314718055994530942)
#endif /** MATH_CONST_LOG2 : log_e 2 */

#if defined(M_LN10)
#define MATH_CONST_LOG10 (M_LN10)
#else
#define MATH_CONST_LOG10 (2.30258509299404568402)
#endif /** MATH_CONST_LOG10 : log_e 10 */

/* package of functions in <ctype.h> */
extern cgraph_bool_t cgraph_math_isalnum(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isalpha(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isblank(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnumst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_islower(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isprint(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isspace(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isupper(const cgraph_char_t data);
extern cgraph_char_t cgraph_math_toupper(const cgraph_char_t data);
extern cgraph_char_t cgraph_math_tolower(const cgraph_char_t data);

extern cgraph_bool_t cgraph_math_ispsplit(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnline(const cgraph_char_t data);

extern cgraph_size_t cgraph_math_lenofname(const cgraph_char_t *data,
                                           cgraph_bool_t *flag);
extern cgraph_bool_t cgraph_math_isname(const cgraph_char_t *data);

extern cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data);
extern cgraph_int_t cgraph_math_hex2dec(cgraph_char_t data,
                                        cgraph_bool_t *error);
extern cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data,
                                          cgraph_bool_t *error);
extern cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data,
                                          cgraph_bool_t *error);
extern cgraph_size_t cgraph_math_lenofdec(const cgraph_char_t *data,
                                          cgraph_char_t **res);
extern cgraph_size_t cgraph_math_lenofbase(const cgraph_int_t data,
                                           const cgraph_int_t base);
extern cgraph_int_t
cgraph_math_chgbase(cgraph_int_t *old, const cgraph_size_t old_len,
                    cgraph_int_t old_base, cgraph_int_t *new,
                    const cgraph_size_t new_len, cgraph_int_t new_base);

extern cgraph_uint64_t cgraph_math_crc(const cgraph_uint64_t predata,
                                       const cgraph_uint64_t data,
                                       const cgraph_uint64_t poly);

extern cgraph_bool_t cgraph_math_prime(const cgraph_int_t data);
extern cgraph_size_t cgraph_math_primes(cgraph_int_t *primes,
                                        cgraph_int_t *isprime,
                                        const cgraph_int_t data);

#define MATH_CONST_RANDOM32_MAX CGRAPH_INT32_MAX
typedef cgraph_int32_t (*cgraph_random32_intptr_t)(void);
extern void cgraph_random32_intptr(cgraph_random32_intptr_t ptr);
extern void cgraph_random32_seed(const cgraph_int32_t seed);
extern cgraph_int32_t cgraph_random32(void);
extern cgraph_int32_t cgraph_random32_mt19937(void);
extern cgraph_int32_t cgraph_random32_uniform(const cgraph_int32_t min,
                                              const cgraph_int32_t max);

#define MATH_CONST_RANDOM64_MAX CGRAPH_INT64_MAX
typedef cgraph_int64_t (*cgraph_random64_intptr_t)(void);
extern void cgraph_random64_intptr(cgraph_random64_intptr_t ptr);
extern void cgraph_random64_seed(const cgraph_int64_t seed);
extern cgraph_int64_t cgraph_random64(void);
extern cgraph_int64_t cgraph_random64_mt19937(void);
extern cgraph_int64_t cgraph_random64_uniform(const cgraph_int64_t min,
                                              const cgraph_int64_t max);

extern cgraph_float64_t cgraph_random64_normal(const cgraph_float64_t mu,
                                               const cgraph_float64_t sigma);

extern cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                         const cgraph_float64_t x);
extern cgraph_int_t cgraph_math_pow2(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_log2(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_mod2(const cgraph_int_t x);
extern cgraph_int_t cgraph_math_mod2n(const cgraph_int_t x,
                                      const cgraph_int_t n);
extern cgraph_int_t cgraph_math_bin2gray(const cgraph_int_t data);
extern cgraph_int_t cgraph_math_gray2bin(const cgraph_int_t data);

extern cgraph_int_t cgraph_math_pow(const cgraph_int_t x, const cgraph_int_t n);
extern cgraph_int_t cgraph_math_pow_mod(const cgraph_int_t x,
                                        const cgraph_int_t n,
                                        const cgraph_int_t mod);
extern cgraph_int_t cgraph_math_mul(const cgraph_int_t x, const cgraph_int_t y);
extern cgraph_int_t cgraph_math_mul_mod(const cgraph_int_t x,
                                        const cgraph_int_t y,
                                        const cgraph_int_t mod);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MATH_H__ */
