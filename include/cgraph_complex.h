/**
 * @file cgraph_complex.h
 * @brief the apis of DATA TYPE cgraph_complex_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
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

#define NAME complex
#define TYPE TYPE_T(NAME)
#define ID ID_T(COMPLEX)
#define BITS (sizeof(TYPE))
#define OUT_FMT "%g+i%g"
#define ZERO                                                                   \
  {                                                                            \
    { 0.0, 0.0 }                                                               \
  }
#define ONE                                                                    \
  {                                                                            \
    { 1.0, 0.0 }                                                               \
  }
#define ONES                                                                   \
  {                                                                            \
    { 1.0, 1.0 }                                                               \
  }
#define MIN                                                                    \
  {                                                                            \
    { CGRAPH_FLOAT64_MIN, CGRAPH_FLOAT64_MIN }                                 \
  }
#define MAX                                                                    \
  {                                                                            \
    { CGRAPH_FLOAT64_MAX, CGRAPH_FLOAT64_MAX }                                 \
  }
#define DATA_NAME float64
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_ID ID_T(FLOAT64)
#define DATA_BITS CGRAPH_FLOAT64_BITS
#define DATA_ZERO (0.0)
#define DATA_ONE (1.0)
#define DATA_ONES (1.0)
#define DATA_MIN CGRAPH_FLOAT64_MIN
#define DATA_MAX CGRAPH_FLOAT64_MAX
#define DATA_EPS CGRAPH_FLOAT64_EPS
#define DATA_EPS_LEN CGRAPH_FLOAT64_BITS

/**
 * @struct cgraph_complex_t
 * @brief the object of complex number
 */
typedef struct {
  DATA_TYPE data[2];
} cgraph_complex_t;

#define COMPLEX_REAL(x) ((x).data[0])
#define COMPLEX_IMAG(x) ((x).data[1])
#define COMPLEX_MAG2(x)                                                        \
  (COMPLEX_REAL(x) * COMPLEX_REAL(x) + COMPLEX_IMAG(x) * COMPLEX_IMAG(x))

/** template module */
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
extern DATA_TYPE FUNCTION(NAME, real)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, imag)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, mag)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, mag_inv)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, angle)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, dist)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, std)(const TYPE x);
extern TYPE FUNCTION(NAME, conj)(const TYPE x);
extern TYPE FUNCTION(NAME, opp)(const TYPE x);
extern TYPE FUNCTION(NAME, inv)(const TYPE x);
extern TYPE FUNCTION(NAME, mul1i)(const TYPE x);
extern TYPE FUNCTION(NAME, mul2i)(const TYPE x);
extern TYPE FUNCTION(NAME, mul3i)(const TYPE x);
extern TYPE FUNCTION(NAME, mul4i)(const TYPE x);
extern TYPE FUNCTION(NAME, dot_inv)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, dot)(const TYPE x, const TYPE y);

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
extern TYPE FUNCTION(NAME, powr)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, powi)(const TYPE x, const DATA_TYPE y);

extern TYPE *FUNCTION(NAME, fft)(TYPE *cthis, const cgraph_size_t len);
extern TYPE *FUNCTION(NAME, ifft)(TYPE *cthis, const cgraph_size_t len);

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_COMPLEX_H__ */
