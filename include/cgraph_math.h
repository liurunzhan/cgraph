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

extern cgraph_integer_t cgraph_math_hex2dec(cgraph_char_t data);
extern cgraph_char_t cgraph_math_dec2hex(const cgraph_integer_t data);
extern cgraph_char_t cgraph_math_toupper(cgraph_char_t data);
extern cgraph_char_t cgraph_math_tolower(cgraph_char_t data);
extern cgraph_size_t cgraph_math_baseoflen(const cgraph_integer_t data, const cgraph_integer_t base);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MATH_H_ */