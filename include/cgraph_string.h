/**
 * @file cgraph_string.h
 * @brief the apis of DATA TYPE cgraph_string_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 */

#ifndef _CGRAPH_STRING_H_
#define _CGRAPH_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#define TYPE_STRING
#include "cgraph_template.h"

typedef struct {
  CGRAPH_DATA_BASE
  CGRAPH_DATA_ROOT
} cgraph_string_t;

#include "cgraph_template_data.ht"

/**                          string hash functions */
extern cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis);
extern TYPE *FUNCTION(NAME, initf)(TYPE *cthis, const cgraph_char_t *format,
                                   ...);

extern cgraph_bool_t FUNCTION(NAME, isalnum)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isalpha)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isblank)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isdigit)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, islower)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isprint)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isspace)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isupper)(const TYPE *cthis);

extern cgraph_bool_t FUNCTION(NAME, ispsplit)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isnline)(const TYPE *cthis);

extern TYPE *FUNCTION(NAME, muli)(const TYPE *x, const cgraph_size_t y,
                                  TYPE *z);

#include "cgraph_template_off.h"

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_STRING_H_ */
