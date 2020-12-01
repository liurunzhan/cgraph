/**
 * @file cgraph_config.h
 * @author liurunzhan (liurunzhan@sina.com)
 * @brief common definitions in cgraph
 * @version 0.0.0
 * @date 2020-11-18
 * @copyright Copyright (c) 2020
 */
#ifndef _CGRAPH_CONFIG_H_
#define _CGRAPH_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 
 * basic c-type definitions:
 * integer number types : char int long int8_t int16_t int32_t
 * float number types   : float double
 * c-type string type   : char *
*/

#include "cgraph_platform.h"

#include <stddef.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>

/** 
 * @typedef cgraph_char_t
 * @brief 8-bit ASCII character data type, used in c-type string
 * @def CGRAPH_CHAR_MAX CHAR_MAX
 * @def CGRAPH_CHAR_MIN CHAR_MIN
 * @def CGRAPH_CHAR_EPS (0xFF)
 * @def CGRAPH_CHAR_BIT (8)
 */
typedef char            cgraph_char_t;
#define CGRAPH_CHAR_MAX CHAR_MAX
#define CGRAPH_CHAR_MIN CHAR_MIN
#define CGRAPH_CHAR_EPS (0xFF)
#define CGRAPH_CHAR_BIT (8)

/** 
 * @typedef cgraph_bool_t
 * @brief 1-bit integer number data type
 * @def CGRAPH_BOOL_MAX CGRAPH_TRUE  (1)
 * @def CGRAPH_BOOL_MIN CGRAPH_FALSE (0)
 * @def CGRAPH_BOOL_EPS (0x01)
 * @def CGRAPH_BOOL_BIT (1)
 */
typedef signed int      cgraph_bool_t;
#define CGRAPH_TRUE (1)
#define CGRAPH_FALSE (0)
#define CGRAPH_BOOL_MAX CGRAPH_TRUE
#define CGRAPH_BOOL_MIN CGRAPH_FALSE
#define CGRAPH_BOOL_EPS (0x01)
#define CGRAPH_BOOL_BIT (1)

/** 
 * @typedef cgraph_int_t
 * @brief 32-bit integer number data type
 * @def CGRAPH_INT_MAX INT_MAX
 * @def CGRAPH_INT_MIN INT_MIN
 * @def CGRAPH_INT_EPS (0xFFFFFFFF)
 * @def CGRAPH_INT_BIT (32)
 */
typedef signed int      cgraph_int_t;
typedef unsigned int    cgraph_uint_t;
#define CGRAPH_INT_MAX  INT_MAX
#define CGRAPH_INT_MIN  INT_MIN
#define CGRAPH_INT_EPS  (0xFFFFFFFF)
#define CGRAPH_INT_BIT  (32)

/** 
 * @typedef cgraph_uint_t
 * @brief 32-bit unsigned integer number data type
 * @def CGRAPH_UINT_MAX UINT_MAX
 * @def CGRAPH_UINT_MIN UINT_MIN
 * @def CGRAPH_UINT_EPS (0xFFFFFFFF)
 * @def CGRAPH_UINT_BIT (32)
 */
#define CGRAPH_UINT_MAX  UINT_MAX
#define CGRAPH_UINT_MIN  UINT_MIN
#define CGRAPH_UINT_EPS  (0xFFFFFFFF)
#define CGRAPH_UINT_BIT  (32)

/** 
 * @typedef cgraph_long_t 
 * @brief 32-bit/64-bit integer number data type in 32-bit/64-bit system
 * @def CGRAPH_BOOL_MAX LONG_MAX
 * @def CGRAPH_BOOL_MIN LONG_MIN
 * @def CGRAPH_BOOL_EPS (0xFFFFFFFF)/(0xFFFFFFFFFFFFFFFF)
 * @def CGRAPH_BOOL_BIT (32)/(64)
 */
typedef signed long     cgraph_long_t;
typedef unsigned long   cgraph_ulong_t;
#define CGRAPH_LONG_MAX LONG_MAX
#define CGRAPH_LONG_MIN LONG_MIN
#if CGRAPH_WORDSIZE == 64
  #define CGRAPH_LONG_EPS (0xFFFFFFFFFFFFFFFF)
  #define CGRAPH_LONG_BIT (64)
#elif CGRAPH_WORDSIZE == 32
  #define CGRAPH_LONG_EPS (0xFFFFFFFF)
  #define CGRAPH_LONG_BIT (32)
#endif

/** 
 * @typedef cgraph_ulong_t  
 * @brief 32-bit/64-bit unsigned integer number data type in 32-bit/64-bit system
 * @def CGRAPH_ULONG_MAX ULONG_MAX
 * @def CGRAPH_ULONG_MIN ULONG_MIN
 * @def CGRAPH_ULONG_EPS (0xFFFFFFFF)/(0xFFFFFFFFFFFFFFFF)
 * @def CGRAPH_ULONG_BIT (32)/(64)
 */
#define CGRAPH_ULONG_MAX ULONG_MAX
#define CGRAPH_ULONG_MIN ULONG_MIN
#if CGRAPH_WORDSIZE == 64
  #define CGRAPH_ULONG_EPS (0xFFFFFFFFFFFFFFFF)
  #define CGRAPH_ULONG_BIT (64)
#elif CGRAPH_WORDSIZE == 32
  #define CGRAPH_ULONG_EPS (0xFFFFFFFF)
  #define CGRAPH_ULONG_BIT (32)
#endif

/** 
 * @typedef cgraph_size_t
 * @brief 32-bit/64-bit integer number data type in 32-bit/64-bit system
 * @def CGRAPH_SIZE_MAX LONG_MAX
 * @def CGRAPH_SIZE_MIN LONG_MIN
 * @def CGRAPH_SIZE_EPS (0xFFFFFFFF)/(0xFFFFFFFFFFFFFFFF)
 * @def CGRAPH_SIZE_BIT (32)/(64)
 */
typedef signed long     cgraph_size_t;
#define CGRAPH_SIZE_MAX CGRAPH_LONG_MAX
#define CGRAPH_SIZE_MIN CGRAPH_LONG_MIN
#define CGRAPH_SIZE_EPS CGRAPH_LONG_EPS
#define CGRAPH_SIZE_BIT CGRAPH_LONG_BIT


#if (CGRAPH_STDC_VERSION >= 199901L) /**< C99 OR HIGHER SUPPORTED! */
  #include <stdint.h>
  /**< 8-bit integer number */
  #define CGRAPH_INT8_MIN INT8_MIN
  #define CGRAPH_INT8_MAX INT8_MIN
  #define CGRAPH_INT8_EPS (0xFF)
  #define CGRAPH_INT8_BIT (8)
  #define CGRAPH_UINT8_MIN UINT8_MIN
  #define CGRAPH_UINT8_MAX UINT8_MIN
  #define CGRAPH_UINT8_EPS (0xFF)
  #define CGRAPH_UINT8_BIT (8)
  typedef int8_t cgraph_int8_t;
  typedef uint8_t cgraph_uint8_t;
  /**< 16-bit integer number */
  #define CGRAPH_INT16_MIN INT16_MIN
  #define CGRAPH_INT16_MAX INT16_MIN
  #define CGRAPH_INT16_EPS (0xFFFF)
  #define CGRAPH_INT16_BIT (16)
  #define CGRAPH_UINT16_MIN UINT16_MIN
  #define CGRAPH_UINT16_MAX UINT16_MIN
  #define CGRAPH_INT16_EPS (0xFFFF)
  #define CGRAPH_INT16_BIT (16)
  typedef int16_t cgraph_int16_t;
  typedef uint16_t cgraph_uint16_t;
  /**< 32-bit integer number */
  #define CGRAPH_INT32_MIN INT32_MIN
  #define CGRAPH_INT32_MAX INT32_MIN
  #define CGRAPH_INT32_EPS (0xFFFFFFFF)
  #define CGRAPH_INT32_BIT (32)
  #define CGRAPH_UINT32_MIN UINT32_MIN
  #define CGRAPH_UINT32_MAX UINT32_MIN
  #define CGRAPH_UINT32_EPS (0xFFFFFFFF)
  #define CGRAPH_UINT32_BIT (32)
  typedef int32_t cgraph_int32_t;
  typedef uint32_t cgraph_uint32_t;
  /**< 64-bit integer number */
  #define CGRAPH_INT64_MIN INT64_MIN
  #define CGRAPH_INT64_MAX INT64_MIN
  #define CGRAPH_INT64_EPS (0xFFFFFFFFFFFFFFFF)
  #define CGRAPH_INT64_BIT (64)
  #define CGRAPH_UINT64_MIN UINT64_MIN
  #define CGRAPH_UINT64_MAX UINT64_MIN
  #define CGRAPH_UINT64_EPS (0xFFFFFFFFFFFFFFFF)
  #define CGRAPH_UINT64_BIT (64)
  typedef int64_t cgraph_int64_t;
  typedef uint64_t cgraph_uint64_t;
#else /**< C89 OR C90 OR C95 */
  /**< 8-bit integer number */
  #define CGRAPH_INT8_MIN (-128)
  #define CGRAPH_INT8_MAX (127)
  #define CGRAPH_INT8_EPS (0xFF)
  #define CGRAPH_INT8_BIT (8)
  #define CGRAPH_UINT8_MIN (0)
  #define CGRAPH_UINT8_MAX (255)
  #define CGRAPH_UINT8_EPS (0xFF)
  #define CGRAPH_UINT8_BIT (8)
  typedef signed char cgraph_int8_t;
  typedef unsigned char cgraph_uint8_t;
  /**< 16-bit integer number */
  #define CGRAPH_INT16_MIN (-32768)
  #define CGRAPH_INT16_MAX (32767)
  #define CGRAPH_INT16_EPS (0xFFFF)
  #define CGRAPH_INT16_BIT (16)
  #define CGRAPH_UINT16_MIN (0)
  #define CGRAPH_UINT16_MAX (65535)
  #define CGRAPH_UINT16_EPS (0xFFFF)
  #define CGRAPH_UINT16_BIT (16)
  typedef signed short cgraph_int16_t;
  typedef unsigned short cgraph_uint16_t;
  /**< 32-bit integer number */
  #define CGRAPH_INT32_MIN (-2147483648L)
  #define CGRAPH_INT32_MAX (2147483647L)
  #define CGRAPH_INT32_EPS (0xFFFFFFFF)
  #define CGRAPH_INT32_BIT (32)
  #define CGRAPH_UINT32_MIN (0L)
  #define CGRAPH_UINT32_MAX (4294967295L)
  #define CGRAPH_UINT32_EPS (0xFFFFFFFF)
  #define CGRAPH_UINT32_BIT (32)
  typedef signed int cgraph_int32_t;
  typedef unsigned int cgraph_uint32_t;
  /**< 64-bit integer number */
  #define CGRAPH_INT64_MIN (-9223372036854775808LL)
  #define CGRAPH_INT64_MAX (9223372036854775807LL)
  #define CGRAPH_INT64_EPS (0xFFFFFFFFFFFFFFFF)
  #define CGRAPH_INT64_BIT (64)
  #define CGRAPH_UINT64_MIN (0LL)
  #define CGRAPH_UINT64_MAX (1844674407370955161ULL)
  #define CGRAPH_UINT64_EPS (0xFFFFFFFFFFFFFFFF)
  #define CGRAPH_UINT64_BIT (64)
  #if CGRAPH_WORDSIZE == 64
    typedef signed long cgraph_int64_t;
    typedef unsigned long cgraph_uint64_t;
  #elif CGRAPH_WORDSIZE == 32
    #if defined(__GNUC__) || defined(__clang__)
      __extension__
      typedef signed long long cgraph_int64_t;
      __extension__
      typedef unsigned long long cgraph_uint64_t;
    #elif defined(_MSC_VER)
      typedef signed __int64 cgraph_int64_t;
      typedef unsigned __int64 cgraph_uint64_t;
    #else
      #error unsupported C compiler in 32-bit system
    #endif
  #endif /* CGRAPH_WORDSIZE */
#endif /* CGRAPH_STDC_VERSION */

/** 
 * @typedef cgraph_float32_t
 * @brief 32-bit floating point number data type
 * @def CGRAPH_FLOAT32_MAX FLT_MAX
 * @def CGRAPH_FLOAT32_MIN FLT_MIN
 * @def CGRAPH_FLOAT32_EPS FLT_EPSILON
 * @def CGRAPH_FLOAT32_BIT FLT_DIG
 */
typedef float              cgraph_float32_t;
#define CGRAPH_FLOAT32_MAX FLT_MAX
#define CGRAPH_FLOAT32_MIN FLT_MIN
#define CGRAPH_FLOAT32_EPS FLT_EPSILON
#define CGRAPH_FLOAT32_BIT FLT_DIG

/** 
 * @typedef cgraph_float64_t
 * @brief 64-bit floating point number data type
 * @def CGRAPH_FLOAT64_MAX DBL_MAX
 * @def CGRAPH_FLOAT64_MIN DBL_MIN
 * @def CGRAPH_FLOAT64_EPS DBL_EPSILON
 * @def CGRAPH_FLOAT64_BIT DBL_DIG
 */
typedef double             cgraph_float64_t;
#define CGRAPH_FLOAT64_MAX DBL_MAX
#define CGRAPH_FLOAT64_MIN DBL_MIN
#define CGRAPH_FLOAT64_EPS DBL_EPSILON
#define CGRAPH_FLOAT64_BIT DBL_DIG

#define CGRAPH_FLOAT_NAN_HASH (3141592653UL)
#define CGRAPH_FLOAT_PINF_HASH (1234567891UL)
#define CGRAPH_FLOAT_NINF_HASH (1987654321UL)

#define CGRAPH_MEMORY_FREED_SIZE (2)
typedef void *         cgraph_stl_t;
typedef cgraph_uint8_t cgraph_addr8_t;

#define CGRAPH_TEST(x) ((x) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define CGRAPH_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define CGRAPH_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define CGRAPH_ABS(x) (((x) < 0) ? (-(x)) : (x))

/**
 * @def CGRAPH_DTYPE_MAX
 * @def CGRAPH_TYPE_MAX
 * @brief the boundary between data objects and data structural objects 
 * if type is greater than CGRAPH_NODE_T, this object is a data object; 
 * otherwise, this object is a data structural object.
*/
#define CGRAPH_DTYPE_MAX CGRAPH_VECTOR_T
#define CGRAPH_TYPE_MAX  CGRAPH_NULL_T

/** 
 * @enum cgraph_type_t
 * @brief the type enumerate structure, storing all object, data and structure types defined in this library
 * @details CGRAPH_OBJECT_T, CGRAPH_HOBJECT_T, CGRAPH_POBJECT_T and CGRAPH_SOBJECT_T share the same value, for the case that object types are defined to be used in structure types and it is useless to use them separately without structure type used and use two or more object types in the same structure module. Users can use them separately with <cgraph.h> included.
 */
typedef enum
{
  CGRAPH_OBJECT_T    =  0,  /**< TYPE  0 : CGRAPH_OBJECT_T   */
  CGRAPH_HOBJECT_T   =  0,  /**< TYPE  0 : CGRAPH_HOBJECT_T  */
  CGRAPH_POBJECT_T   =  0,  /**< TYPE  0 : CGRAPH_POBJECT_T  */
  CGRAPH_SOBJECT_T   =  0,  /**< TYPE  0 : CGRAPH_SOBJECT_T  */
  CGRAPH_BOOL_T      =  1,  /**< TYPE  1 : CGRAPH_BOOL_T     */
  CGRAPH_INT_T       =  2,  /**< TYPE  2 : CGRAPH_INT_T      */
  CGRAPH_LONG_T      =  3,  /**< TYPE  3 : CGRAPH_LONG_T     */
  CGRAPH_INT8_T      =  4,  /**< TYPE  4 : CGRAPH_INT8_T     */
  CGRAPH_UINT8_T     =  4,  /**< TYPE  4 : CGRAPH_UINT8_T    */
  CGRAPH_INT16_T     =  5,  /**< TYPE  5 : CGRAPH_INT16_T    */
  CGRAPH_INT32_T     =  6,  /**< TYPE  6 : CGRAPH_INT32_T    */
  CGRAPH_INT64_T     =  7,  /**< TYPE  7 : CGRAPH_INT64_T    */
  CGRAPH_FLOAT32_T   =  8,  /**< TYPE  8 : CGRAPH_FLOAT32_T  */
  CGRAPH_FLOAT64_T   =  9,  /**< TYPE  9 : CGRAPH_FLOAT64_T  */
  CGRAPH_TIME_T      = 10,  /**< TYPE 10 : CGRAPH_TIME_T     */
  CGRAPH_COMPLEX_T   = 11,  /**< TYPE 11 : CGRAPH_COMPLEX_T  */
  CGRAPH_FRACTION_T  = 12,  /**< TYPE 12 : CGRAPH_FRACTION_T */
  CGRAPH_BITSET_T    = 13,  /**< TYPE 13 : CGRAPH_BITSET_T   */
  CGRAPH_BIGINT_T    = 14,  /**< TYPE 14 : CGRAPH_BIGINT_T   */
  CGRAPH_BIGNUM_T    = 15,  /**< TYPE 15 : CGRAPH_BIGNUM_T   */
  CGRAPH_STRING_T    = 16,  /**< TYPE 16 : CGRAPH_STRING_T   */
  CGRAPH_VECTOR_T    = 17,  /**< TYPE 17 : CGRAPH_VECTOR_T   */
  CGRAPH_MATRIX_T    = 18,  /**< TYPE 18 : CGRAPH_MATRIX_T   */
  CGRAPH_BIGMAT_T    = 19,  /**< TYPE 19 : CGRAPH_BIGMAT_T   */
  CGRAPH_DFRAME_T    = 20,  /**< TYPE 20 : CGRAPH_DFRAME_T   */
  CGRAPH_DICT_T      = 21,  /**< TYPE 21 : CGRAPH_DICT_T     */
  CGRAPH_LIST_T      = 22,  /**< TYPE 22 : CGRAPH_LIST_T     */
  CGRAPH_TREE_T      = 23,  /**< TYPE 23 : CGRAPH_TREE_T     */
  CGRAPH_SET_T       = 24,  /**< TYPE 24 : CGRAPH_SET_T      */
  CGRAPH_NULL_T      = 25   /**< TYPE 25 : CGRAPH_NULL_T     */
}cgraph_type_t;

/**
 * @brief 
 * @struct cgraph_element_t
 */
typedef struct
{
  /* key data type */
  cgraph_uint_t ktype       : 6;
  cgraph_uint_t kaccessible : 1;
  cgraph_uint_t khashed     : 1;
  /* value data type */
  cgraph_uint_t vtype       : 6;
  cgraph_uint_t vaccessible : 1;
  cgraph_uint_t vhashed     : 1;
  /* unused space for extertions */
  cgraph_uint_t             : 8;
  /* graph type */
  cgraph_uint_t gdirected   : 1;
  cgraph_uint_t gweighted   : 1;
  cgraph_uint_t ghyper      : 1;
  cgraph_uint_t gmultiple   : 1;
  cgraph_uint_t gdynamic    : 1;
  cgraph_uint_t gkeyisid    : 1;
  cgraph_uint_t gstruct     : 2;
}cgraph_element_t;

#define CGRAPH_DTYPE_KTYPE(a)        ((a)->element.ktype)
#define CGRAPH_DTYPE_KACCESSIABLE(a) ((a)->element.kaccessible)
#define CGRAPH_DTYPE_KHASHED(a)      ((a)->element.khashed)

#define CGRAPH_DTYPE_VTYPE(a)        ((a)->element.vtype)
#define CGRAPH_DTYPE_VACCESSIABLE(a) ((a)->element.vaccessible)
#define CGRAPH_DTYPE_VHASHED(a)      ((a)->element.vhashed)

#define CGRAPH_DTYPE_TYPE(a)         CGRAPH_DTYPE_KTYPE(a)
#define CGRAPH_DTYPE_ACCESSIABLE(a)  CGRAPH_DTYPE_KACCESSIABLE(a)
#define CGRAPH_DTYPE_HASHED(a)       CGRAPH_DTYPE_KHASHED(a)

#define CGRAPH_GTYPE_DIRECTED(a)  ((a)->element.gdirected)
#define CGRAPH_GTYPE_WEIGHTED(a)  ((a)->element.gweighted)
#define CGRAPH_GTYPE_GHYPER(a)    ((a)->element.ghyper)
#define CGRAPH_GTYPE_GMULTIPLE(a) ((a)->element.gmultiple)
#define CGRAPH_GTYPE_GDYNAMIC(a)  ((a)->element.gdynamic)
#define CGRAPH_GTYPE_GKEYISID(a)  ((a)->element.gkeyisid)
#define CGRAPH_GTYPE_GSTRUCT(a)   ((a)->element.gstruct)

typedef struct
{
/**< private: */
  cgraph_type_t _type;  /**< type id   */
  cgraph_char_t *_name; /**< type name */
  cgraph_size_t _size;  /**< type size */
  cgraph_size_t _psize; /**< pointer size of type */
  cgraph_size_t _msize; /**< memory size of type used in structure types */
  cgraph_size_t _dsize; /**< data size of type */

/**< public: */
  cgraph_type_t (*type)(void);
  cgraph_char_t *(*name)(void);
  cgraph_size_t (*size)(void);
  cgraph_size_t (*psize)(void);
  cgraph_size_t (*msize)(void);
  cgraph_size_t (*dsize)(void);
  cgraph_bool_t (*hasdata)(void);
  cgraph_size_t (*len)(const void *cthis);
  cgraph_size_t (*asize)(const void* cthis);
  cgraph_size_t (*csize)(const cgraph_type_t type, const cgraph_size_t size);
  void *(*update)(void *cthis, const cgraph_type_t type, const cgraph_size_t size);
  void *(*calloc)(const cgraph_type_t type, const cgraph_size_t size);
  void *(*realloc)(void *cthis, const cgraph_type_t type, const cgraph_size_t old_size, const cgraph_size_t new_size, cgraph_bool_t *error);
  void (*free)(void *gthis);
  void *(*copy)(const void *cthis, const cgraph_size_t size);
  cgraph_size_t (*hash)(const void *cthis);
  void (*add)(const void *x, const void *y, void *z);
  void (*sub)(const void *x, const void *y, void *z);
  void (*mul)(const void *x, const void *y, void *z);
  void (*div)(const void *x, const void *y, void *z);
  void (*none)(void);
}CGVTable;

#define _CGRAPH_OBJECTS_NAME(NAME) (_cgraph_ ## NAME ## s)
#define CGRAPH_OBJECTS_NAME(NAME) _CGRAPH_OBJECTS_NAME(NAME)

typedef void *(*cgraph_pfunc2_t)(const void *cthis, void *res);
typedef void *(*cgraph_pfunc3_t)(const void *x, const void *y, void *res);

#ifdef __cplusplus
}
#endif

#endif /* _CGRAPH_CONFIG_H_ */
