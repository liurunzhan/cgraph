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

/*                              initial function                              */
extern TYPE FUNCTION(NAME, initma)(const DATA_TYPE mod, const DATA_TYPE arg);
extern TYPE FUNCTION(NAME, initri)(const DATA_TYPE real, const DATA_TYPE imag);

/*                   complex number mathematical functions                    */
extern DATA_TYPE FUNCTION(NAME, mod)(const TYPE x);
extern DATA_TYPE FUNCTION(NAME, arg)(const TYPE x);

extern TYPE FUNCTION(NAME, conj)(const TYPE x);

extern TYPE FUNCTION(NAME, muli)(const TYPE x);
extern TYPE FUNCTION(NAME, muli2)(const TYPE x);
extern TYPE FUNCTION(NAME, muli3)(const TYPE x);
extern TYPE FUNCTION(NAME, muli4)(const TYPE x);

extern TYPE FUNCTION(NAME, addr)(const TYPE x, const cgraph_real_t y);
extern TYPE FUNCTION(NAME, subr)(const TYPE x, const cgraph_real_t y);
extern TYPE FUNCTION(NAME, mulr)(const TYPE x, const cgraph_real_t y);
extern TYPE FUNCTION(NAME, divr)(const TYPE x, const cgraph_real_t y);
extern TYPE FUNCTION(NAME, powr)(const TYPE x, const cgraph_real_t y);

extern TYPE FUNCTION(NAME, addc)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, subc)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mulc)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, divc)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, powc)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, opp)(const TYPE x);
extern TYPE FUNCTION(NAME, abs)(const TYPE x);
extern TYPE FUNCTION(NAME, sin)(const TYPE x);
extern TYPE FUNCTION(NAME, cos)(const TYPE x);
extern TYPE FUNCTION(NAME, tan)(const TYPE x);

extern TYPE FUNCTION(NAME, log)(const TYPE x);
extern TYPE FUNCTION(NAME, log2)(const TYPE x);
extern TYPE FUNCTION(NAME, log10)(const TYPE x);
extern TYPE FUNCTION(NAME, exp)(const TYPE x);
extern TYPE FUNCTION(NAME, sqrt)(const TYPE x);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_COMPLEX_H_ */