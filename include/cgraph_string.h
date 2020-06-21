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
  cgraph_size_t size, len;
  DATA_TYPE *root, *data;
}cgraph_string_t;

#include "data_templete.h"

/*                         string operation function                          */

/*                       string mathematical functions                        */

/*                           string hash functions                            */
extern cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis);
extern TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format, ...);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_STRING_H_ */
