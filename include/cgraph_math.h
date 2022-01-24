/**
 * @file cgraph_math.h
 * @brief the basic mathematical functions
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
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

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
#define MATH_CONST_PI (M_PI) /** MATH_CONST_PI pi */

#define M_2PI (6.28318530717958647693)
#define MATH_CONST_2PI (M_2PI) /** MATH_CONST_2PI : 2*pi */

#ifndef M_PI_2
#define M_PI_2 (1.57079632679489661923)
#endif
#define MATH_CONST_PI_2 (M_PI_2) /** MATH_CONST_PI_2 : pi/2 */

#ifndef M_2_PI
#define M_2_PI (1.57079632679489661923)
#endif
#define MATH_CONST_2_PI (M_PI_2) /** MATH_CONST_2_PI : 2/pi */

#ifndef M_E
#define M_E (2.71828182845904523536)
#endif
#define MATH_CONST_E (M_E) /** MATH_CONST_E : e */

#define M_PHI (0.61803398874989484820)
#define MATH_CONST_PHI (M_PHI) /** MATH_CONST_PHI : (sqrt(5)-1)/2 */

#ifndef M_LN2
#define M_LN2 (0.69314718055994530942)
#endif
#define MATH_CONST_LOG2 (M_LN2) /** MATH_CONST_LOG2 : log_e(2) */

#ifndef M_LN10
#define M_LN10 (2.30258509299404568402)
#endif
#define MATH_CONST_LOG10 (M_LN10) /** MATH_CONST_LOG10 : log_e(10) */

#define MATH_CONST_LOG10_INV (1.0 / M_LN10)

#ifndef NAN
#define NAN (0.0 / 0.0)
#endif
#define MATH_CONST_NAN (NAN) /** MATH_CONST_NAN : nan */

#ifndef INFINITY
#define INFINITY (1.0 / 0.0)
#endif
#define MATH_CONST_INFINITY (INFINITY) /** MATH_CONST_INFINITY : infinity */

extern cgraph_size_t cgraph_math_subc(cgraph_char_t *x, const cgraph_size_t len,
                                      const cgraph_char_t ch);
extern cgraph_size_t *cgraph_math_kmpnext(const cgraph_char_t *y,
                                          cgraph_size_t *next,
                                          const cgraph_size_t len);
extern cgraph_size_t cgraph_math_kmpcnt(const cgraph_char_t *x,
                                        const cgraph_size_t size,
                                        const cgraph_char_t *y,
                                        const cgraph_size_t *next,
                                        const cgraph_size_t len);
extern cgraph_size_t
cgraph_math_kmpsub(const cgraph_char_t *x, cgraph_char_t *z,
                   const cgraph_size_t size, const cgraph_char_t *y,
                   const cgraph_size_t *next, const cgraph_size_t len);

/* package of functions in <ctype.h> */
extern cgraph_bool_t cgraph_math_isnum(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isalnum(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isalpha(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isblank(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_islower(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isprint(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isspace(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isupper(const cgraph_char_t data);
extern cgraph_char_t cgraph_math_toupper(const cgraph_char_t data);
extern cgraph_char_t cgraph_math_tolower(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ispsplit(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnline(const cgraph_char_t datax,
                                         const cgraph_char_t datay);

extern cgraph_bool_t cgraph_math_isbin(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbinhd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbinst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbinmd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbined(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbintl(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdechd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdecst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdecmd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdeced(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdectl(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishexhd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishexst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishexmd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishexed(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishextl(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnumhd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnumst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnummd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnumed(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnumtl(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnamhd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnamst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnammd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnamed(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isnamtl(const cgraph_char_t data);

extern cgraph_int_t cgraph_math_bin2dec(const cgraph_char_t data);
extern cgraph_char_t cgraph_math_dec2bin(const cgraph_int_t data);
extern cgraph_int_t cgraph_math_hex2dec(const cgraph_char_t data);
#ifdef cgraph_math_dec2hex
#undef cgraph_math_dec2hex
#endif
#define cgraph_math_dec2hex(data) cgraph_math_dec2uhex((data))
extern cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data);
extern cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data);
extern cgraph_size_t cgraph_math_binlen(const cgraph_char_t *data,
                                        const cgraph_size_t len,
                                        cgraph_char_t **start);
extern cgraph_size_t cgraph_math_declen(const cgraph_char_t *data,
                                        const cgraph_size_t len,
                                        cgraph_char_t **start);
extern cgraph_size_t cgraph_math_hexlen(const cgraph_char_t *data,
                                        const cgraph_size_t len,
                                        cgraph_char_t **start);
extern cgraph_size_t cgraph_math_numlen(const cgraph_char_t *data,
                                        const cgraph_size_t len,
                                        cgraph_char_t **start);
extern cgraph_size_t cgraph_math_namlen(const cgraph_char_t *data,
                                        const cgraph_size_t len,
                                        cgraph_char_t **start);
extern cgraph_size_t cgraph_math_baslen(const cgraph_int_t data,
                                        const cgraph_int_t base);
extern cgraph_int_t cgraph_math_chbase(cgraph_int_t *old,
                                       const cgraph_size_t old_len,
                                       cgraph_int_t old_base, cgraph_int_t *new,
                                       const cgraph_size_t new_len,
                                       cgraph_int_t new_base);

extern cgraph_uint64_t cgraph_math_gcd(const cgraph_uint64_t x,
                                       const cgraph_uint64_t y);
extern cgraph_uint64_t cgraph_math_lcm(const cgraph_uint64_t x,
                                       const cgraph_uint64_t y);
extern cgraph_uint64_t cgraph_math_crc(const cgraph_uint64_t predata,
                                       const cgraph_uint64_t data,
                                       const cgraph_uint64_t poly);

extern cgraph_bool_t cgraph_math_prime(const cgraph_int_t data);
extern cgraph_size_t cgraph_math_primes(cgraph_int_t *primes,
                                        cgraph_int_t *isprime,
                                        const cgraph_int_t data);

/** 32-bit random number */
#ifdef MATH_CONST_RAND32_MAX
#undef MATH_CONST_RAND32_MAX
#endif

#define MATH_CONST_RAND32_MAX CGRAPH_INT32_MAX
typedef cgraph_int32_t (*cgraph_rand32_intptr_t)(void);
extern void cgraph_rand32_intptr(cgraph_rand32_intptr_t ptr);
extern void cgraph_rand32_seed(const cgraph_int32_t seed);
extern cgraph_int32_t cgraph_rand32(void);
extern cgraph_int32_t cgraph_rand32_miller(void);
extern cgraph_int32_t cgraph_rand32_mt19937(void);
extern cgraph_int32_t cgraph_rand32_uniform(const cgraph_int32_t min,
                                            const cgraph_int32_t max);
extern cgraph_float32_t cgraph_rand32_normal(const cgraph_float32_t mu,
                                             const cgraph_float32_t sigma);

/** 64-bit random number */
#ifdef MATH_CONST_RAND64_MAX
#undef MATH_CONST_RAND64_MAX
#endif

#define MATH_CONST_RAND64_MAX CGRAPH_INT64_MAX
typedef cgraph_int64_t (*cgraph_rand64_intptr_t)(void);
extern void cgraph_rand64_intptr(cgraph_rand64_intptr_t ptr);
extern void cgraph_rand64_seed(const cgraph_int64_t seed);
extern cgraph_int64_t cgraph_rand64(void);
extern cgraph_int64_t cgraph_rand64_mmix(void);
extern cgraph_int64_t cgraph_rand64_mt19937(void);
extern cgraph_int64_t cgraph_rand64_uniform(const cgraph_int64_t min,
                                            const cgraph_int64_t max);
extern cgraph_float64_t cgraph_rand64_normal(const cgraph_float64_t mu,
                                             const cgraph_float64_t sigma);

extern cgraph_bool_t cgraph_rand_bool(void);
extern cgraph_logic_t cgraph_rand_logic(void);

/** random size */
extern cgraph_size_t cgraph_rand_size(const cgraph_size_t size);

/** external mathematical functions */
extern cgraph_size_t cgraph_math_count(const cgraph_int_t x,
                                       const cgraph_int_t n);
extern cgraph_size_t cgraph_math_rngcnt(const cgraph_int_t x,
                                        const cgraph_int_t n);
extern cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                         const cgraph_float64_t x);
extern cgraph_int_t cgraph_math_ceil(const cgraph_int_t x,
                                     const cgraph_int_t y);
extern cgraph_int_t cgraph_math_floor(const cgraph_int_t x,
                                      const cgraph_int_t y);
extern cgraph_int_t cgraph_math_pow2(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_log2(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_mod2(const cgraph_int_t x);
extern cgraph_int_t cgraph_math_mod2n(const cgraph_int_t x,
                                      const cgraph_int_t n);
extern cgraph_uint_t cgraph_math_bin2gray(const cgraph_uint_t data);
extern cgraph_uint_t cgraph_math_gray2bin(const cgraph_uint_t data);

extern cgraph_int_t cgraph_math_pow(const cgraph_int_t x, const cgraph_int_t n);
extern cgraph_int_t cgraph_math_pow_mod(const cgraph_int_t x,
                                        const cgraph_int_t n,
                                        const cgraph_int_t mod);
extern cgraph_int_t cgraph_math_mul(const cgraph_int_t x, const cgraph_int_t y);
extern cgraph_int_t cgraph_math_mul_mod(const cgraph_int_t x,
                                        const cgraph_int_t y,
                                        const cgraph_int_t mod);

/** Function : sigmoid */
extern cgraph_float64_t cgraph_math_sigmoid(const cgraph_float64_t x);
/** Function : tanh */
extern cgraph_float64_t cgraph_math_tanh(const cgraph_float64_t x);
/** Function : ReLU */
extern cgraph_float64_t cgraph_math_relu(const cgraph_float64_t x);
/** Function : Leaky ReLU */
extern cgraph_float64_t cgraph_math_leaky_relu(const cgraph_float64_t x,
                                               const cgraph_float64_t a);
/** Function : ELU  */
extern cgraph_float64_t cgraph_math_elu(const cgraph_float64_t x,
                                        const cgraph_float64_t a);
/** Function : PReLU */
extern cgraph_float64_t cgraph_math_prelu(const cgraph_float64_t x,
                                          const cgraph_float64_t a);
/** Function : Swish */
extern cgraph_float64_t cgraph_math_swish(const cgraph_float64_t x);
/** Function : Softplus */
extern cgraph_float64_t cgraph_math_softplus(const cgraph_float64_t x);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MATH_H__ */
