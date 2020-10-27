/**
* @file  cgraph_bigint.h  
* @brief  
* @author       Liurunzhan
* @date     2015-5-24 
* @version  0.0.0 
* @copyright Vincent                                                    
*/

#ifndef _CGRAPH_BIGINT_H_
#define _CGRAPH_BIGINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"
#include "cgraph_string.h"
#include "cgraph_bignum.h"

#define TYPE_BIGINT
#include "templete.h"

typedef struct 
{
  cgraph_boolean_t postive;
  CGRAPH_DATA_BASE
}cgraph_bigint_t;

#include "data_base.ht"

extern TYPE *FUNCTION(NAME, abs)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, tonum)(const cgraph_string_t *cthis);
extern TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y, TYPE *z);
extern TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y, TYPE *z);

extern cgraph_boolean_t FUNCTION(NAME, eq)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, ne)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, gr)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, ge)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, ls)(const TYPE *x, const TYPE *y);
extern cgraph_boolean_t FUNCTION(NAME, le)(const TYPE *x, const TYPE *y);
extern cgraph_string_t *FUNCTION(NAME, tostr)(const TYPE *cthis);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_BIGINT_H_ */
