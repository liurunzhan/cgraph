#ifndef _CGRAPH_MATH_H_
#define _CGRAPH_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define MATH_ERROR -1

extern cgraph_integer_t cgraph_math_hex2dec(cgraph_char_t data);
extern cgraph_char_t cgraph_math_dec2hex(const cgraph_integer_t data);
extern cgraph_char_t cgraph_math_toupper(cgraph_char_t data);
extern cgraph_char_t cgraph_math_tolower(cgraph_char_t data);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_MATH_H_ */