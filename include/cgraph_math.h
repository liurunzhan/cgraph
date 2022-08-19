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

#ifndef M_E
#define M_E (2.7182818284590452354)
#endif /** M_E : e */

#ifndef M_1_E
#define M_1_E (0.367879441171442321596)
#endif /** M_E : 1/e */

#ifndef M_LOG2E
#define M_LOG2E (1.4426950408889634074)
#endif /** M_LOG2E : log_2(e) */

#ifndef M_LOG10E
#define M_LOG10E (0.43429448190325182765)
#endif /** M_LOG10E : log_10(e) */

#ifndef M_LN2
#define M_LN2 (0.693147180559945309417)
#endif /** M_LN2 : log_e(2) */

#ifndef M_1_LN2
#define M_1_LN2 (1.44269504088896340736)
#endif /** M_LN2 : 1/log_e(2) */

#ifndef M_LN10
#define M_LN10 (2.30258509299404568402)
#endif /** M_LN10 : log_e(10) */

#ifndef M_1_LN10
#define M_1_LN10 (0.43429448190325182765)
#endif /** M_1_LN10 : 1/log_e(10) */

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif /** M_PI pi */

#ifndef M_2PI
#define M_2PI (6.28318530717958647693)
#endif /** M_2PI : 2*pi */

#ifndef M_PI_2
#define M_PI_2 (1.57079632679489661923)
#endif /** M_PI_2 : pi/2 */

#ifndef M_PI_2
#define M_PI_4 (0.78539816339744830962)
#endif /** M_PI_4 : pi/4 */

#ifndef M_1_PI
#define M_1_PI (0.31830988618379067154)
#endif /** M_1_PI : 1/pi */

#ifndef M_2_PI
#define M_2_PI (0.63661977236758134308)
#endif /** M_2_PI : 2/pi */

#ifndef M_2_SQRTPI
#define M_2_SQRTPI (1.12837916709551257390)
#endif /** M_2_SQRTPI : 2/sqrt(pi) */

#ifndef M_SQRT2
#define M_SQRT2 (1.41421356237309504880)
#endif /** M_SQRT2 : sqrt(2) */

#ifndef M_SQRT1_2
#define M_SQRT1_2 (0.70710678118654752440)
#endif /** M_SQRT1_2 : sqrt(1/2) */

#ifndef M_SQRT3
#define M_SQRT3 (1.73205080756887729353)
#endif /** M_SQRT3 : sqrt(3) */

#ifndef M_SQRT1_3
#define M_SQRT1_3 (0.57735026918962576451)
#endif /** M_SQRT1_3 : sqrt(1/3) */

#ifndef M_PHI
#define M_PHI (0.61803398874989484820)
#endif /** M_PHI : (sqrt(5)-1)/2 */

#ifndef M_1_PHI
#define M_1_PHI (1.61803398874989484820)
#endif /** M_1_PHI : (sqrt(5)+1)/2 */

#ifndef NAN
#define NAN (0.0 / 0.0)
#endif /** NAN : nan */

#ifndef INFINITY
#define INFINITY (1.0 / 0.0)
#endif /** INFINITY : infinity */

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
extern cgraph_int_t cgraph_math_isnline(const cgraph_char_t datax,
                                        const cgraph_char_t datay);
extern cgraph_int_t cgraph_math_isnliney(const cgraph_char_t datax,
                                         const cgraph_char_t datay);

/** used to parse C-style codes to C-style objects */
extern cgraph_bool_t cgraph_math_isbin(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isoct(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isdec(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_ishex(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbinhd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbinst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbinmd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbined(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isbintl(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isocthd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isoctst(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isoctmd(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isocted(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_isocttl(const cgraph_char_t data);
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
extern cgraph_bool_t cgraph_math_iscopt(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_iscdoc(const cgraph_char_t datax,
                                        const cgraph_char_t datay);
extern cgraph_bool_t cgraph_math_isclpair(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_iscrpair(const cgraph_char_t data);
extern cgraph_bool_t cgraph_math_iscpair(const cgraph_char_t data);

/** translate C-style numbers by base */
extern cgraph_int_t cgraph_math_bin2dec(const cgraph_char_t data);
extern cgraph_char_t cgraph_math_dec2bin(const cgraph_int_t data);
extern cgraph_int_t cgraph_math_hex2dec(const cgraph_char_t data);
#ifndef cgraph_math_dec2hex
#define cgraph_math_dec2hex(data) cgraph_math_dec2uhex((data))
#endif
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

/** external mathematical functions */
extern cgraph_size_t cgraph_math_mod2(const cgraph_size_t x);
extern cgraph_size_t cgraph_math_mod3(const cgraph_size_t x);
extern cgraph_uint64_t cgraph_math_gcd(const cgraph_uint64_t x,
                                       const cgraph_uint64_t y);
extern cgraph_uint64_t cgraph_math_lcm(const cgraph_uint64_t x,
                                       const cgraph_uint64_t y);
extern cgraph_uint64_t cgraph_math_crc(const cgraph_uint64_t predata,
                                       const cgraph_uint64_t data,
                                       const cgraph_uint64_t poly);

extern cgraph_bool_t cgraph_math_isprime(const cgraph_int_t data);
extern cgraph_size_t cgraph_math_primes(cgraph_int_t *primes,
                                        cgraph_int_t *isprime,
                                        const cgraph_int_t data);

extern cgraph_float64_t cgraph_math_ang2rad(const cgraph_float64_t angle);
extern cgraph_float64_t cgraph_math_rad2ang(const cgraph_float64_t radian);

extern cgraph_float64_t cgraph_math_ceil(const cgraph_float64_t x);
extern cgraph_float64_t cgraph_math_floor(const cgraph_float64_t x);
extern cgraph_float64_t cgraph_math_log2(const cgraph_float64_t x);
extern cgraph_float64_t cgraph_math_logn(const cgraph_float64_t n,
                                         const cgraph_float64_t x);

extern cgraph_size_t cgraph_math_deccnt(const cgraph_int_t x,
                                        const cgraph_int_t n);
extern cgraph_size_t cgraph_math_rdeccnt(const cgraph_int_t x,
                                         const cgraph_int_t n);
extern cgraph_int_t cgraph_math_abitlen(const cgraph_uint_t data);
extern cgraph_int_t cgraph_math_pow2i(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_log2i(const cgraph_int_t n);
extern cgraph_int_t cgraph_math_mod2i(const cgraph_int_t x);
extern cgraph_int_t cgraph_math_rmod2i(const cgraph_int_t x,
                                       const cgraph_int_t n);
extern cgraph_uint_t cgraph_math_bin2gray(const cgraph_uint_t data);
extern cgraph_uint_t cgraph_math_gray2bin(const cgraph_uint_t data);

extern cgraph_int_t cgraph_math_ceili(const cgraph_int_t x,
                                      const cgraph_int_t y);
extern cgraph_int_t cgraph_math_floori(const cgraph_int_t x,
                                       const cgraph_int_t y);
extern cgraph_int_t cgraph_math_powi(const cgraph_int_t x,
                                     const cgraph_int_t n);
extern cgraph_int_t cgraph_math_powi_mod(const cgraph_int_t x,
                                         const cgraph_int_t n,
                                         const cgraph_int_t mod);
extern cgraph_int_t cgraph_math_muli(const cgraph_int_t x,
                                     const cgraph_int_t y);
extern cgraph_int_t cgraph_math_muli_mod(const cgraph_int_t x,
                                         const cgraph_int_t y,
                                         const cgraph_int_t mod);

/** Activation Functions defined in Neural Networks */
/** Function 1 : sigmoid */
extern cgraph_float64_t cgraph_math_sigmoid(const cgraph_float64_t x);
/** Function 2 : tanh */
extern cgraph_float64_t cgraph_math_tanh(const cgraph_float64_t x);
/** Function 3 : ReLU */
extern cgraph_float64_t cgraph_math_relu(const cgraph_float64_t x);
/** Function 4 : Leaky ReLU */
extern cgraph_float64_t cgraph_math_leaky_relu(const cgraph_float64_t x,
                                               const cgraph_float64_t a);
/** Function 5 : ELU  */
extern cgraph_float64_t cgraph_math_elu(const cgraph_float64_t x,
                                        const cgraph_float64_t a);
/** Function 6 : PReLU */
extern cgraph_float64_t cgraph_math_prelu(const cgraph_float64_t x,
                                          const cgraph_float64_t a);
/** Function 7 : Swish */
extern cgraph_float64_t cgraph_math_swish(const cgraph_float64_t x);
/** Function 8 : Softplus */
extern cgraph_float64_t cgraph_math_softplus(const cgraph_float64_t x);

/** RGB Color Generator */
extern cgraph_bool_t cgraph_math_colchk(const cgraph_uint32_t color);
extern cgraph_uint32_t cgraph_math_colfmt(const cgraph_uint32_t color);
extern cgraph_uint32_t cgraph_math_col2r(const cgraph_uint32_t color);
extern cgraph_uint32_t cgraph_math_col2g(const cgraph_uint32_t color);
extern cgraph_uint32_t cgraph_math_col2b(const cgraph_uint32_t color);
extern cgraph_char_t *cgraph_math_col2dec(const cgraph_uint32_t color,
                                          cgraph_char_t *cstr);
extern cgraph_char_t *cgraph_math_col2hex(const cgraph_uint32_t color,
                                          cgraph_char_t *cstr);
extern cgraph_uint32_t cgraph_math_dec2col(const cgraph_char_t *color);
extern cgraph_uint32_t cgraph_math_hex2col(const cgraph_char_t *color);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_MATH_H__ */
