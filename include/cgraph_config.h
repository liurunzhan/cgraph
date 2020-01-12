#ifndef _CGRAPH_CONFIG_H_
#define _CGRAPH_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef int cgraph_integer_t;
typedef double cgraph_real_t;
typedef int cgraph_boolean_t;
typedef long cgraph_size_t;

typedef const char cgraph_char_t;
typedef float cgraph_float_t;

typedef char cgraph_int8_t;
typedef short cgraph_int16_t;
typedef int cgraph_int32_t;
typedef long cgraph_int64_t;
typedef long cgraph_long_t;

#define CGRAPH_TRUE (1)
#define CGRAPH_FALSE (0)
#define CGRAPH_TEST(x) ((x) ? CGRAPH_TRUE : CGRAPH_FALSE)

/* 
  the boundary between data objects and data structural objects 
  if type is greater than CGRAPH_NODE_T, this object is a data object;
  otherwise, this object is a data structural object.
*/
typedef enum {
  /* data objects */
  CGRAPH_OBJECT_T   =  0,
  CGRAPH_INTEGER_T  =  1,
  CGRAPH_REAL_T     =  2,
  CGRAPH_BOOLEAN_T  =  3,
  CGRAPH_FLOAT_T    =  4,
  CGRAPH_LONG_T     =  5,
  CGRAPH_INT8_T     =  6,
  CGRAPH_INT16_T    =  7,
  CGRAPH_INT32_T    =  8,
  CGRAPH_INT64_T    =  9,
  CGRAPH_COMPLEX_T  = 10,
  CGRAPH_FRACTION_T = 11,
  CGRAPH_BIGINT_T   = 12,
  CGRAPH_BIGNUM_T   = 13,
  CGRAPH_STRING_T   = 14,
  /* data structural objects */
  CGRAPH_VECTOR_T   = 15,
  CGRAPH_MATRIX_T   = 16,
  CGRAPH_BIGMAT_T   = 17,
  CGRAPH_DFRAME_T   = 18,
  CGRAPH_HTABLE_T   = 19,
  CGRAPH_LIST_T     = 20
}cgraph_type_t;

typedef struct
{
/*private:*/
  cgraph_integer_t __type__;
  cgraph_size_t __size__;
  cgraph_size_t __msize__;
  cgraph_char_t *__name__;

/*public:*/
  cgraph_type_t (*type)(void);
  cgraph_size_t (*size)(void);
  cgraph_size_t (*msize)(void);
  cgraph_char_t *(*name)(void);
  void *(*calloc)(const cgraph_type_t type, const cgraph_size_t size);
  void (*free)(void *gthis);
  void *(*copy)(const void *cthis, const cgraph_size_t size);
  cgraph_size_t (*dsize)(const void *cthis);
  cgraph_size_t (*hash)(const void *cthis);
  void (*none)(void);
}CGVTable;

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_CONFIG_H_ */