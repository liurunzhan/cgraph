#ifndef _CGRAPH_COMPLEX_H_
#define _CGRAPH_COMPLEX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_COMPLEX
#include "templete.h"

typedef struct 
{
  DATA_TYPE data[2];
}cgraph_complex_t;

#define COMPLEX_REAL(x) ((x).data[0])
#define COMPLEX_IMAG(x) ((x).data[1])
#define COMPLEX_MOD2(x) (COMPLEX_REAL(x) * COMPLEX_REAL(x) + COMPLEX_IMAG(x) * COMPLEX_IMAG(x))

#include "data_templete.h"

/*                   complex number mathematical functions                    */
extern cgraph_real_t FUNCTION(NAME, mod)(const TYPE x);
extern cgraph_real_t FUNCTION(NAME, arg)(const TYPE x);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_COMPLEX_H_ */