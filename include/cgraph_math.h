#ifndef _CGRAPH_MATH_H_
#define _CGRAPH_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define MATH_ERROR (-1)
#define MATH_CONST_PI  (3.14159265358979323846)
#define MATH_CONST_E   (2.71828182845904523536)
#define MATH_CONST_PHI (0.61803398874989484820)

extern cgraph_integer_t cgraph_math_crc(const cgraph_integer_t predata, const cgraph_integer_t data, const cgraph_integer_t polynomial);
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

extern cgraph_integer_t cgraph_math_pow2(const cgraph_integer_t len);
extern cgraph_integer_t cgraph_math_bin2gray(const cgraph_integer_t data);
extern cgraph_integer_t cgraph_math_gray2bin(const cgraph_integer_t data);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MATH_H_ */
