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
  CGRAPH_DATA_BASE
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

extern TYPE *FUNCTION(NAME, add)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, sub)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, mul)(const TYPE *x, const TYPE *y);
extern TYPE *FUNCTION(NAME, div)(const TYPE *x, const TYPE *y);

#include "templete_off.h"

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_STRING_H_ */
