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

#include "data_templete.h"

/*                      fraction mathematical functions                       */

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_FRACTION_H_ */