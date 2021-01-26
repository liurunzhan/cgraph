#ifndef _CGRAPH_MATH_H_
#define _CGRAPH_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

#include "cgraph_config.h"

/**                const numbers defined and used in this library             */
#define MATH_ERROR (-1) /**MATH ERROR    */
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

extern cgraph_uint_t cgraph_math_crc(const cgraph_uint_t predata,
                                     const cgraph_uint_t data,
                                     const cgraph_uint_t poly);
extern cgraph_int_t cgraph_math_hex2dec(cgraph_char_t data,
                                        cgraph_bool_t *error);
extern cgraph_char_t cgraph_math_dec2uhex(const cgraph_int_t data,
                                          cgraph_bool_t *error);
extern cgraph_char_t cgraph_math_dec2lhex(const cgraph_int_t data,
                                          cgraph_bool_t *error);
extern cgraph_char_t cgraph_math_toupper(cgraph_char_t data);
extern cgraph_char_t cgraph_math_tolower(cgraph_char_t data);
extern cgraph_size_t cgraph_math_baseoflen(const cgraph_int_t data,
                                           const cgraph_int_t base);

extern cgraph_bool_t cgraph_math_prime(const cgraph_int_t data);
extern cgraph_size_t cgraph_math_primes(cgraph_int_t *primes,
                                        cgraph_int_t *isprime,
                                        const cgraph_int_t data);

#define CGRAPH_RANDOM_MAX 2147483647

extern cgraph_int_t cgraph_random(void);
extern cgraph_int_t cgraph_random_uniform(const cgraph_int_t min,
                                          const cgraph_int_t max);
extern cgraph_float64_t cgraph_random_normal(const cgraph_float64_t mu,
                                             const cgraph_float64_t sigma);

extern cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                         const cgraph_float64_t x);
extern cgraph_int_t cgraph_math_pow2(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_log2(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_mod2(const cgraph_int_t n);
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

#endif /** _CGRAPH_MATH_H_ */
