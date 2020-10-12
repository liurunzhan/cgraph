#ifndef _CGRAPH_VECTOR_H_
#define _CGRAPH_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_VECTOR
#include "templete.h"

typedef struct 
{
  CGRAPH_STRUCTURE_BASE
}cgraph_vector_t;

#include "struct_base.ht"

extern cgraph_vector_t *FUNCTION(NAME, primes)(const cgraph_integer_t data);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_VECTOR_H_ */
