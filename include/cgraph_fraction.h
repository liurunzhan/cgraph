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
extern cgraph_boolean_t FUNCTION(NAME, isnan)(const void *cthis);

/*                               private apis                                 */
extern TYPE FUNCTION(NAME, add)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, sub)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, mul)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, div)(const TYPE x, const TYPE y);
extern TYPE FUNCTION(NAME, pow)(const TYPE x, const DATA_TYPE y);

extern TYPE FUNCTION(NAME, abs)(const TYPE x);

extern cgraph_boolean_t FUNCTION(NAME, iszero)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, ispos)(const TYPE x);
extern cgraph_boolean_t FUNCTION(NAME, isneg)(const TYPE x);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_FRACTION_H_ */