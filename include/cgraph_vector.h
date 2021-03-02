#ifndef _CGRAPH_VECTOR_H_
#define _CGRAPH_VECTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_VECTOR
#include "template.h"

typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_ROOT
} cgraph_vector_t;

#include "struct_base.ht"

extern cgraph_vector_t *FUNCTION(NAME, primes)(const cgraph_int_t data);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_VECTOR_H_ */
