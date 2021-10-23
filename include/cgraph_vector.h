/**
 * @file cgraph_vector.h
 * @brief the apis of STRUCTURE TYPE cgraph_vector_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef __CGRAPH_VECTOR_H__
#define __CGRAPH_VECTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_VECTOR
#include "cgraph_template.h"

/**
 * @struct cgraph_vector_t
 * @brief the object of vector
 */
typedef struct {
  CGRAPH_STRUCTURE_BASE
  CGRAPH_STRUCTURE_ROOT
} cgraph_vector_t;

/** template module */
#include "cgraph_template_struct.ht"

extern cgraph_vector_t *FUNCTION(NAME, primes)(const cgraph_int_t data);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_VECTOR_H__ */
