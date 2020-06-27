#ifndef _CGRAPH_FRACTION_H_
#define _CGRAPH_FRACTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_FRACTION
#include "templete.h"

typedef struct 
{
  DATA_TYPE data[2];
}cgraph_fraction_t;

#define FRACTION_NUM(x) ((x).data[0])
#define FRACTION_DEN(x) ((x).data[1])
#define FRACTION_VALUE(x) (1.0 * FRACTION_NUM(x) / FRACTION_DEN(x))

#include "data_templete.h"

/*                                public apis                                 */
extern cgraph_size_t FUNCTION(NAME, hash)(const void *cthis);
extern cgraph_boolean_t FUNCTION(NAME, test)(const void *cthis);
extern cgraph_boolean_t FUNCTION(NAME, equal)(const void *x, const void *y);

/*                               private apis                                 */
extern cgraph_boolean_t FUNCTION(NAME, isnan)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, isinf)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ispinf)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, isninf)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, iszero)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ispos)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, isneg)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ismin)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ismax)(const TYPE x);

extern TYPE FUNCTION(NAME, addi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, subi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, muli)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, divi)(const TYPE x, const DATA_TYPE y);
extern TYPE FUNCTION(NAME, powi)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, addf)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, subf)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mulf)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, divf)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, powf)(const TYPE x, const TYPE y);

extern TYPE FUNCTION(NAME, abs)(const TYPE x);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_FRACTION_H_ */
