#ifndef _CGRAPH_STRING_H_
#define _CGRAPH_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_STRING
#include "templete.h"

typedef struct 
{
  cgraph_size_t len, size;
  DATA_TYPE *data;
}cgraph_string_t;

#include "data_templete.h"

/*                       string mathematical functions                        */

/*                           string hash functions                            */
extern cgraph_size_t FUNCTION(NAME, jshash)(cgraph_string_t *str);
extern cgraph_size_t FUNCTION(NAME, sdbmhash)(cgraph_string_t *str);
extern cgraph_size_t FUNCTION(NAME, rshash)(cgraph_string_t *str);
extern cgraph_size_t FUNCTION(NAME, elfhash)(cgraph_string_t *str);
extern cgraph_size_t FUNCTION(NAME, bkdrhash)(cgraph_string_t *str);

#include "templete_off.h"



#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_STRING_H_ */