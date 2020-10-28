#ifndef _CGRAPH_MATH_H_
#define _CGRAPH_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

/*                 const numbers defined and used in this library             */
#define MATH_ERROR       (-1)                     /* MATH ERROR    */
#if defined(_MATH_H_)
#define MATH_CONST_PI    (M_PI)                   /* pi            */
#define MATH_CONST_E     (M_E)                    /* e             */
#define MATH_CONST_PHI   (0.61803398874989484820) /* (sqrt(5)-1)/2 */
#define MATH_CONST_LOG2  (M_LN2)                  /* ln2           */
#define MATH_CONST_LOG10 (M_LN10)                 /* ln10          */
#else
#define MATH_CONST_PI    (3.14159265358979323846) /* pi            */
#define MATH_CONST_E     (2.71828182845904523536) /* e             */
#define MATH_CONST_PHI   (0.61803398874989484820) /* (sqrt(5)-1)/2 */
#define MATH_CONST_LOG2  (0.69314718055994530942) /* ln2           */
#define MATH_CONST_LOG10 (2.30258509299404568402) /* ln10          */
#endif

extern cgraph_uinteger_t cgraph_math_crc(const cgraph_uinteger_t predata, const cgraph_uinteger_t data, const cgraph_uinteger_t poly);
extern cgraph_integer_t cgraph_math_hex2dec(cgraph_char_t data, cgraph_boolean_t *error);
extern cgraph_char_t cgraph_math_dec2uhex(const cgraph_integer_t data, cgraph_boolean_t *error);
extern cgraph_char_t cgraph_math_dec2lhex(const cgraph_integer_t data, cgraph_boolean_t *error);
extern cgraph_char_t cgraph_math_toupper(cgraph_char_t data);
extern cgraph_char_t cgraph_math_tolower(cgraph_char_t data);
extern cgraph_size_t cgraph_math_baseoflen(const cgraph_integer_t data, const cgraph_integer_t base);

extern cgraph_boolean_t cgraph_math_prime(const cgraph_integer_t data);
extern cgraph_size_t cgraph_math_primes(cgraph_integer_t *primes, cgraph_integer_t *isprime, const cgraph_integer_t data);

#define	CGRAPH_RANDOM_MAX	2147483647

extern cgraph_integer_t cgraph_random(void);
extern cgraph_integer_t cgraph_random_uniform(const cgraph_integer_t min, const cgraph_integer_t max);
extern cgraph_real_t cgraph_random_normal(const cgraph_real_t mu, const cgraph_real_t sigma);

extern cgraph_real_t cgraph_math_logn(const cgraph_real_t n, const cgraph_real_t x);
extern cgraph_integer_t cgraph_math_pow2(const cgraph_integer_t n);
extern cgraph_integer_t cgraph_math_log2(const cgraph_integer_t n);
extern cgraph_integer_t cgraph_math_mod2(const cgraph_integer_t n);
extern cgraph_integer_t cgraph_math_bin2gray(const cgraph_integer_t data);
extern cgraph_integer_t cgraph_math_gray2bin(const cgraph_integer_t data);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MATH_H_ */
