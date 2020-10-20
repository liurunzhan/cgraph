#ifndef _CGRAPH_CONFIG_H_
#define _CGRAPH_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* 
  basic c-type definitions:
  integer number types : char int long
  float number types   : float double
  c-type string type   : char
*/

#include <stddef.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>

typedef signed int cgraph_integer_t;
typedef double cgraph_real_t;
typedef signed int cgraph_boolean_t;
typedef signed long cgraph_long_t;
typedef signed long cgraph_size_t;

typedef char cgraph_char_t;
typedef float cgraph_float_t;

typedef unsigned int cgraph_uinteger_t;
typedef unsigned long cgraph_ulong_t;

#define CGRAPH_BOOLEAN_MAX CGRAPH_TRUE
#define CGRAPH_BOOLEAN_MIN CGRAPH_FALSE

#define CGRAPH_INTEGER_MAX INT_MAX
#define CGRAPH_INTEGER_MIN INT_MIN
#define CGRAPH_LONG_MAX LONG_MAX
#define CGRAPH_LONG_MIN LONG_MIN

#if __WORDSIZE == 64 || defined(_WIN64)
#define CGRAPH_LONG_EPSILON (0xFFFFFFFFFFFFFFFF)
#define CGRAPH_LONG_EPSILON_LEN (64)
#elif __WORDSIZE == 32 || defined(_WIN32)
#define CGRAPH_LONG_EPSILON (0xFFFFFFFF)
#define CGRAPH_LONG_EPSILON_LEN (32)
#else
#error only 64-bit and 32-bit system are supported!!
#endif

#define CGRAPH_REAL_MAX DBL_MAX
#define CGRAPH_REAL_MIN DBL_MIN
#define CGRAPH_REAL_EPSILON DBL_EPSILON
#define CGRAPH_REAL_EPSILON_LEN DBL_DIG

#define CGRAPH_FLOAT_MAX FLT_MAX
#define CGRAPH_FLOAT_MIN FLT_MIN
#define CGRAPH_FLOAT_EPSILON FLT_EPSILON
#define CGRAPH_FLOAT_EPSILON_LEN FLT_DIG

#if defined(__STDC__)
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) /* C99 OR HIGHER SUPPORTED! */
#include <stdint.h>
/* 8-bit integer number */
#define CGRAPH_INT8_MIN INT8_MIN
#define CGRAPH_INT8_MAX INT8_MIN
typedef int8_t cgraph_int8_t;
typedef uint8_t cgraph_uint8_t;
/* 16-bit integer number */
#define CGRAPH_INT16_MIN INT16_MIN
#define CGRAPH_INT16_MAX INT16_MIN
typedef int16_t cgraph_int16_t;
typedef uint16_t cgraph_uint16_t;
/* 32-bit integer number */
#define CGRAPH_INT32_MIN INT32_MIN
#define CGRAPH_INT32_MAX INT32_MIN
typedef int32_t cgraph_int32_t;
typedef uint32_t cgraph_uint32_t;
/* 64-bit integer number */
#define CGRAPH_INT64_MIN INT64_MIN
#define CGRAPH_INT64_MAX INT64_MIN
typedef int64_t cgraph_int64_t;
typedef uint64_t cgraph_uint64_t;
#else /* C89 OR C90 OR C95 */
/* 8-bit integer number */
#define CGRAPH_INT8_MIN (-128)
#define CGRAPH_INT8_MAX (127)
typedef signed char cgraph_int8_t;
#define CGRAPH_UINT8_MIN (0)
#define CGRAPH_UINT8_MAX (255)
typedef unsigned char cgraph_uint8_t;
/* 16-bit integer number */
#define CGRAPH_INT16_MIN (-32768)
#define CGRAPH_INT16_MAX (32767)
typedef signed short cgraph_int16_t;
#define CGRAPH_UINT16_MIN (0)
#define CGRAPH_UINT16_MAX (65535)
typedef unsigned short cgraph_uint16_t;
/* 32-bit integer number */
#define CGRAPH_INT32_MIN (-2147483648L)
#define CGRAPH_INT32_MAX (2147483647L)
typedef signed int cgraph_int32_t;
#define CGRAPH_UINT32_MIN (0L)
#define CGRAPH_UINT32_MAX (4294967295L)
typedef unsigned int cgraph_uint32_t;
/* 64-bit integer number */
#if __WORDSIZE == 64 || defined(_WIN64)
#define CGRAPH_INT64_MIN (-9223372036854775808LL)
#define CGRAPH_INT64_MAX (9223372036854775807LL)
#define CGRAPH_INT64_EPS (0xFFFFFFFFFFFFFFFF)
#define CGRAPH_INT64_EPS_LEN (64)
typedef signed long cgraph_int64_t;
#define CGRAPH_UINT64_MIN (0LL)
#define CGRAPH_UINT64_MAX (1844674407370955161LL)
typedef unsigned long cgraph_uint64_t;
#elif __WORDSIZE == 32 || defined(_WIN32)
#define CGRAPH_INT64_MIN (-9223372036854775808LL)
#define CGRAPH_INT64_MAX (9223372036854775807LL)
#define CGRAPH_INT64_EPS (0xFFFFFFFFFFFFFFFF)
#define CGRAPH_INT64_EPS_LEN (64)
__extension__
typedef signed long long cgraph_int64_t;
#define CGRAPH_UINT64_MIN (0LL)
#define CGRAPH_UINT64_MAX (1844674407370955161LL)
__extension__
typedef unsigned long long cgraph_uint64_t;
#else
#error only 32-bit and 64-bit system are supported!!
#endif /* __WORDSIZE */
#endif /* __STDC_VERSION__ */
#else
#error only standard c is suppoted!
#endif /* __STDC__ */

#define CGRAPH_TRUE (1)
#define CGRAPH_FALSE (0)
#define CGRAPH_TEST(x) ((x) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define CGRAPH_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define CGRAPH_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define CGRAPH_ABS(x) (((x) < 0) ? (-(x)) : (x))

#define CGRAPH_FLOAT_NAN_HASH (3141592653UL)
#define CGRAPH_FLOAT_PINF_HASH (1234567891UL)
#define CGRAPH_FLOAT_NINF_HASH (1987654321UL)

/* 
  the boundary between data objects and data structural objects 
  if type is greater than CGRAPH_NODE_T, this object is a data object;
  otherwise, this object is a data structural object.
*/
  
  /* data objects */
typedef enum
{ 
  CGRAPH_OBJECT_T    =  0,
  CGRAPH_INTEGER_T   =  1,
  CGRAPH_REAL_T      =  2,
  CGRAPH_BOOLEAN_T   =  3,
  CGRAPH_FLOAT_T     =  4,
  CGRAPH_LONG_T      =  5,
  CGRAPH_INT8_T      =  6,
  CGRAPH_UINT8_T     =  6,
  CGRAPH_INT16_T     =  7,
  CGRAPH_INT32_T     =  8,
  CGRAPH_INT64_T     =  9,
  CGRAPH_TIME_T      = 10,
  CGRAPH_COMPLEX_T   = 11,
  CGRAPH_FRACTION_T  = 12,
  CGRAPH_BIGINT_T    = 13,
  CGRAPH_BIGNUM_T    = 14,
  CGRAPH_STRING_T    = 15,
  CGRAPH_BITSET_T    = 16,
 /* data structural objects */
  CGRAPH_VECTOR_T    = 17,
  CGRAPH_MATRIX_T    = 18,
  CGRAPH_BIGMAT_T    = 19,
  CGRAPH_DFRAME_T    = 20,
  CGRAPH_DICT_T      = 21,
  CGRAPH_LIST_T      = 22,
  CGRAPH_TREE_T      = 23,
  CGRAPH_NULL_T      = 24
} cgraph_type_t;

typedef struct
{
  /* key data type */
  cgraph_uinteger_t ktype     : 6;
  cgraph_uinteger_t kvisited  : 1;
  cgraph_uinteger_t khashed   : 1;
  /* value data type */
  cgraph_uinteger_t vtype     : 6;
  cgraph_uinteger_t vvisited  : 1;
  cgraph_uinteger_t vhashed   : 1;
  /* unused space for extertions */
  cgraph_uinteger_t unused    : 8;
  /* graph type */
  cgraph_uinteger_t gdirected : 1;
  cgraph_uinteger_t gweighted : 1;
  cgraph_uinteger_t ghyper    : 1;
  cgraph_uinteger_t gmultiple : 1;
  cgraph_uinteger_t gdynamic  : 1;
  cgraph_uinteger_t gkeyisid  : 1;
  cgraph_uinteger_t gstruct   : 2;
}cgraph_element_t;

#define CGRAPH_DTYPE_KTYPE(a)    ((a)->element.ktype)
#define CGRAPH_DTYPE_KVISITED(a) ((a)->element.kvisited)
#define CGRAPH_DTYPE_KHASHED(a)  ((a)->element.khashed)

#define CGRAPH_DTYPE_VTYPE(a)    ((a)->element.vtype)
#define CGRAPH_DTYPE_VVISITED(a) ((a)->element.vvisited)
#define CGRAPH_DTYPE_VHASHED(a)  ((a)->element.vhashed)

#define CGRAPH_DTYPE_TYPE(a)    CGRAPH_DTYPE_KTYPE(a)
#define CGRAPH_DTYPE_VISITED(a) CGRAPH_DTYPE_KVISITED(a)
#define CGRAPH_DTYPE_HASHED(a)  CGRAPH_DTYPE_KHASHED(a)

#define CGRAPH_GTYPE_DIRECTED(a)  ((a)->element.gdirected)
#define CGRAPH_GTYPE_WEIGHTED(a)  ((a)->element.gweighted)
#define CGRAPH_GTYPE_GHYPER(a)    ((a)->element.ghyper)
#define CGRAPH_GTYPE_GMULTIPLE(a) ((a)->element.gmultiple)
#define CGRAPH_GTYPE_GDYNAMIC(a)  ((a)->element.gdynamic)
#define CGRAPH_GTYPE_GKEYISID(a)  ((a)->element.gkeyisid)
#define CGRAPH_GTYPE_GSTRUCT(a)   ((a)->element.gstruct)

typedef struct
{
/*private:*/
  cgraph_type_t __type__;
  cgraph_size_t __size__;
  cgraph_size_t __psize__;
  cgraph_size_t __msize__;
  cgraph_size_t __dsize__;
  cgraph_char_t *__name__;

/*public:*/
  cgraph_type_t (*type)(void);
  cgraph_size_t (*size)(void);
  cgraph_size_t (*psize)(void);
  cgraph_size_t (*msize)(void);
  cgraph_size_t (*dsize)(void);
  cgraph_char_t *(*name)(void);
  cgraph_boolean_t (*hasdata)(void);
  void *(*calloc)(const cgraph_type_t type, const cgraph_size_t size);
  void *(*realloc)(void *cthis, const cgraph_size_t old_size, const cgraph_size_t new_size, cgraph_boolean_t *error);
  void (*free)(void *gthis);
  void *(*copy)(const void *cthis, const cgraph_size_t size);
  cgraph_size_t (*hash)(const void *cthis);
  void (*add)(const void *x, const void *y, void *z);
  void (*sub)(const void *x, const void *y, void *z);
  void (*mul)(const void *x, const void *y, void *z);
  void (*div)(const void *x, const void *y, void *z);
  void (*none)(void);
}CGVTable;

/*                          operations of data types                          */
extern CGVTable *_cgraph_objects_[];
#define CGRAPH_OBJECT(type, opt) ((_cgraph_objects_[type])->opt)

typedef void *(*cgraph_pfunc2_t)(const void *cthis, void *res);
typedef void *(*cgraph_pfunc3_t)(const void *x, const void *y, void *res);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_CONFIG_H_ */
