/**
 * @file cgraph_string.h
 * @brief the apis of DATA TYPE cgraph_string_t
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_STRING_H__
#define __CGRAPH_STRING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "cgraph_config.h"

#include "cgraph_int8.h"

#include "cgraph_template_off.h"
#define TYPE_STRING
#include "cgraph_template.h"

#define TYPE_WITH_DATA
#define DATA_NAME char
#define DATA_UNAME uchar
#define DATA_INAME int8
#define DATA_TYPE TYPE_T(DATA_NAME)
#define DATA_UTYPE TYPE_T(DATA_UNAME)
#define DATA_ID ID_T(CHAR)
#define DATA_BITS (8 * sizeof(DATA_TYPE))
#define DATA_BYTES(x) FUNCTION(DATA_INAME, ubitceil)((x))
#define DATA_END ('\0')
#define DATA_ZERO ('0')
#define DATA_ONE ('1')
#define DATA_ONES ('1')
#define DATA_MIN (' ')
#define DATA_MAX ('~')

#define NAME string
#define TYPE TYPE_T(NAME)
#define ID ID_T(STRING)
#define BITS (8 * sizeof(TYPE))
#define OUT_FMT "%s"
#define ZERO(x) FUNCTION(NAME, zero)((x))
#define ONE(x) FUNCTION(NAME, one)((x))
#define ONES(x) FUNCTION(NAME, ones)((x))
#define MIN(x) FUNCTION(NAME, min)((x))
#define MAX(x) FUNCTION(NAME, max)((x))

/**
 * @struct cgraph_string_t
 * @brief the object of string
 */
typedef struct {
  CGRAPH_BASE
  CGRAPH_DATA_ROOT
} cgraph_string_t;

/** template module */
#include "cgraph_template_data.ht"

/** string hash functions */
extern cgraph_size_t FUNCTION(NAME, jshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, sdbmhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, rshash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, elfhash)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, bkdrhash)(const TYPE *cthis);
extern TYPE *FUNCTION(NAME, initc)(TYPE *cthis, const cgraph_char_t *data,
                                   const cgraph_size_t len);
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

extern TYPE *FUNCTION(NAME, lower)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, upper)(TYPE *cthis);

extern TYPE *FUNCTION(NAME, subc)(const TYPE *x, const DATA_TYPE y, TYPE *z);
extern TYPE *FUNCTION(NAME, muli)(const TYPE *x, const cgraph_size_t y,
                                  TYPE *z);
extern TYPE *FUNCTION(NAME, divc)(const TYPE *x, const DATA_TYPE y, TYPE *z);
extern TYPE *FUNCTION(NAME, modc)(const TYPE *x, const DATA_TYPE y, TYPE *z);

extern TYPE *FUNCTION(NAME, chomp)(TYPE *cthis);
extern TYPE *FUNCTION(NAME, strip)(TYPE *cthis, const cgraph_char_t *data);
extern TYPE *FUNCTION(NAME, lstrip)(TYPE *cthis, const cgraph_char_t *data);
extern TYPE *FUNCTION(NAME, rstrip)(TYPE *cthis, const cgraph_char_t *data);
extern TYPE *FUNCTION(NAME, stripc)(TYPE *cthis, const DATA_TYPE ch);
extern TYPE *FUNCTION(NAME, lstripc)(TYPE *cthis, const DATA_TYPE ch);
extern TYPE *FUNCTION(NAME, rstripc)(TYPE *cthis, const DATA_TYPE ch);
extern cgraph_bool_t FUNCTION(NAME, startswith)(const TYPE *cthis,
                                                const DATA_TYPE *cstr,
                                                const cgraph_size_t len);
extern cgraph_bool_t FUNCTION(NAME, endswith)(const TYPE *cthis,
                                              const DATA_TYPE *cstr,
                                              const cgraph_size_t len);

extern cgraph_bool_t FUNCTION(NAME, startswithc)(const TYPE *cthis,
                                                 const DATA_TYPE ch);
extern cgraph_bool_t FUNCTION(NAME, endswithc)(const TYPE *cthis,
                                               const DATA_TYPE ch);

extern cgraph_bool_t FUNCTION(NAME, isgb2312)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, len_gb2312)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isgbk)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, len_gbk)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isbig5)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, len_big5)(const TYPE *cthis);
extern cgraph_bool_t FUNCTION(NAME, isutf8)(const TYPE *cthis);
extern cgraph_size_t FUNCTION(NAME, len_utf8)(const TYPE *cthis);

/** used to clear common-defined macro variables, except included only */
#if defined(__CGRAPH_MACRO_CFLAG__)
#include "cgraph_template_off.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_STRING_H__ */
