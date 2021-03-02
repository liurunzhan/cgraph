#ifndef _CGRAPH_STRING_H_
#define _CGRAPH_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_STRING
#include "template.h"

typedef struct {
  CGRAPH_DATA_BASE
  CGRAPH_DATA_ROOT
} cgraph_string_t;

#include "data_base.ht"

/**                          string hash functions */
extern cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis);
extern TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format,
                                   ...);

extern cgraph_bool_t FUNCTION(NAME, ispsplit)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isnewline)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isspace)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isblankspace)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, muli)(const TYPE *x, const cgraph_int_t y, TYPE *z);

#include "template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_STRING_H_ */
