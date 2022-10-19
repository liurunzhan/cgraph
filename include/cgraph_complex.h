/**
 * @file cgraph_complex.h
 * @brief the apis of DATA TYPE cgraph_complex_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_COMPLEX_H__
#define __CGRAPH_COMPLEX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_template_off.h"
#define TYPE_COMPLEX
#include "cgraph_template.h"

#define DATA_INUM (2)
#define DATA_NAME float64
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(FLOAT64)
#define DATA_BITS CGRAPH_FLOAT64_BITS
#define DATA_ZERO DBL_C(0.0)
#define DATA_ONE DBL_C(1.0)
#define DATA_ONES DBL_C(1.0)
#define DATA_MIN CGRAPH_FLOAT64_MIN
#define DATA_MAX CGRAPH_FLOAT64_MAX
#define DATA_NAN CGRAPH_FLOAT64_NAN
#define DATA_INF CGRAPH_FLOAT64_INF
#define DATA_PINF CGRAPH_FLOAT64_PINF
#define DATA_NINF CGRAPH_FLOAT64_NINF
#define DATA_EPSILON CGRAPH_FLOAT64_EPSILON
#define DATA_EPSILON_LEN CGRAPH_FLOAT64_BITS

#define NAME complex
#define TYPE TYPE_T(NAME)
#define ID ID_T(COMPLEX)
#define BITS (sizeof(TYPE))
#define IN_FMT "%lf+i%lf"
#define IN_FMT_IMAG "i%lf"
#define OUT_FMT "%g+i%g"
#define OUT_FMT_REAL "%g"
#define OUT_FMT_IMAG "i%g"
#if __STDC_VERSION__ >= 199901L
#define ZERO ((TYPE){{DATA_ZERO, DATA_ZERO}})
#define ONE ((TYPE){{DATA_ONE, DATA_ZERO}})
#define ONES ((TYPE){{DATA_ONE, DATA_ONE}})
#define MIN ((TYPE){{DATA_MIN, DATA_MIN}})
#define MAX ((TYPE){{DATA_MAX, DATA_MAX}})
#define NAN ((TYPE){{DATA_NAN, DATA_NAN}})
#define INF ((TYPE){{DATA_INF, DATA_INF}})
#define PINF ((TYPE){{DATA_PINF, DATA_PINF}})
#define NINF ((TYPE){{DATA_NINF, DATA_NINF}})
#else
#define ZERO FUNCTION(NAME, zero)()
#define ONE FUNCTION(NAME, one)()
#define ONES FUNCTION(NAME, ones)()
#define MIN FUNCTION(NAME, min)()
#define MAX FUNCTION(NAME, max)()
#define NAN FUNCTION(NAME, nan)()
#define INF FUNCTION(NAME, inf)()
#define PINF FUNCTION(NAME, pinf)()
#define NINF FUNCTION(NAME, ninf)()
#endif

/**
 * @struct cgraph_complex_t
 * @brief the object of complex number
 */
typedef struct {
  DATA_TYPE data[DATA_INUM];
} cgraph_complex_t;

#if DATA_INUM != 2
#error DATA_INUM must be defined as 2, or will throw a compilation error
#endif

#define COMPLEX_REAL(x) ((x).data[0])
#define COMPLEX_IMAG(x) ((x).data[1])
#define COMPLEX_MAG2(x)                                                        \
  ((COMPLEX_REAL(x) * COMPLEX_REAL(x)) + (COMPLEX_IMAG(x) * COMPLEX_IMAG(x)))

/** template module */
#define CGRAPH_COMPLEX_CBUF_SIZE CGRAPH_CBUF_SIZE0
#include "cgraph_template_cbuf.ht"

#include "cgraph_template_data.ht"

/** initial function */
extern TYPE FUNCTION(NAME, initma)(const DATA_TYPE mag, const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, initm)(const DATA_TYPE mag);
extern TYPE FUNCTION(NAME, inita)(const DATA_TYPE angle);
extern TYPE FUNCTION(NAME, initri)(const DATA_TYPE real, const DATA_TYPE imag);
extern TYPE FUNCTION(NAME, initr)(const DATA_TYPE real);
extern TYPE FUNCTION(NAME, initi)(const DATA_TYPE imag);
extern TYPE FUNCTION(NAME, unit)(const cgraph_int_t n, const cgraph_int_t i);
extern TYPE FUNCTION(NAME, unit_inv)(const cgraph_int_t n,
                                     const cgraph_int_t i);

/** complex number mathematical functions */
extern cgraph_bool_t FUNCTION(NAME, isreal)(const TYPE x);
extern cgraph_bool_t FUNCTION(NAME, isimag)(const TYPE x);

extern DATA_TYPE FUNCTION(NAME, real)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, imag)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, mag2)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, mag2_inv)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, mag)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, mag_inv)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, angle)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, iangle)(const TYPE x, const TYPE y);
extern DATA_TYPE FUNCTION(NAME, dist)(const TYPE x, const TYPE y);
extern DATA_TYPE FUNCTION(NAME, fabs)(const TYPE x);

extern DATA_TYPE FUNCTION(NAME, dmin)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, dmax)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, dsum)(const TYPE x);

extern TYPE FUNCTION(NAME, std)(const TYPE x);
extern TYPE FUNCTION(NAME, conj)(const TYPE x);
extern TYPE FUNCTION(NAME, pow2)(const TYPE x);
extern TYPE FUNCTION(NAME, pow3)(const TYPE x);
extern TYPE FUNCTION(NAME, mul1i)(const TYPE x);
extern TYPE FUNCTION(NAME, mul2i)(const TYPE x);
extern TYPE FUNCTION(NAME, mul3i)(const TYPE x);
extern TYPE FUNCTION(NAME, mul4i)(const TYPE x);
extern TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, dot_conj)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, rdadd)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, rdsub)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, rdmul)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, rddiv)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, rdmod)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, rdpow)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, idadd)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, idsub)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, idmul)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, iddiv)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, idmod)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, idpow)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, log)(const TYPE x);
extern TYPE FUNCTION(NAME, log2)(const TYPE x);
extern TYPE FUNCTION(NAME, log10)(const TYPE x);
extern TYPE FUNCTION(NAME, exp)(const TYPE x);
extern TYPE FUNCTION(NAME, sqrt)(const TYPE x);
extern TYPE FUNCTION(NAME, pow)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mod)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, sin)(const TYPE x);
extern TYPE FUNCTION(NAME, cos)(const TYPE x);
extern TYPE FUNCTION(NAME, tan)(const TYPE x);
extern TYPE FUNCTION(NAME, cot)(const TYPE x);
extern TYPE FUNCTION(NAME, sec)(const TYPE x);
extern TYPE FUNCTION(NAME, csc)(const TYPE x);

extern TYPE FUNCTION(NAME, sinh)(const TYPE x);
extern TYPE FUNCTION(NAME, cosh)(const TYPE x);
extern TYPE FUNCTION(NAME, tanh)(const TYPE x);
extern TYPE FUNCTION(NAME, coth)(const TYPE x);
extern TYPE FUNCTION(NAME, sech)(const TYPE x);
extern TYPE FUNCTION(NAME, csch)(const TYPE x);

extern TYPE FUNCTION(NAME, asin)(const TYPE x);
extern TYPE FUNCTION(NAME, acos)(const TYPE x);
extern TYPE FUNCTION(NAME, atan)(const TYPE x);

extern TYPE FUNCTION(NAME, addr)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subr)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, mulr)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divr)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, modr)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, powr)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, modi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, powi)(const TYPE x, const DATA_TYPE y);

extern TYPE *FUNCTION(NAME, fft)(TYPE *cthis, const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, ifft)(TYPE *cthis, const cgraph_size_t len);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_COMPLEX_H__ */
