/**
 * @file cgraph_config.h
 * @brief the configuration of cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
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

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#include "cgraph_platform.h"

/**
 * @typedef cgraph_char_t
 * @brief 8-bit ASCII character data type, used in c-type string
 * @def CGRAPH_CHAR_MAX CHAR_MAX
 * @def CGRAPH_CHAR_MIN CHAR_MIN
 * @def CGRAPH_CHAR_EPS (0xFF)
 * @def CGRAPH_CHAR_BITS (8)
 */
typedef char cgraph_char_t;
#define CGRAPH_CHAR_MAX CHAR_MAX
#define CGRAPH_CHAR_MIN CHAR_MIN
#define CGRAPH_CHAR_EPS (0xFFU)
#define CGRAPH_CHAR_BITS (8 * sizeof(cgraph_char_t))

/**
 * @typedef cgraph_bool_t
 * @brief 1-bit integer number data type
 * @def CGRAPH_BOOL_MAX CGRAPH_TRUE  (1)
 * @def CGRAPH_BOOL_MIN CGRAPH_FALSE (0)
 * @def CGRAPH_BOOL_EPS (0x01U)
 * @def CGRAPH_BOOL_BITS (1)
 */
#define CGRAPH_FALSE (0)
#define CGRAPH_TRUE (1)
typedef signed int cgraph_bool_t;
#define CGRAPH_BOOL_MAX CGRAPH_TRUE
#define CGRAPH_BOOL_MIN CGRAPH_FALSE
#define CGRAPH_BOOL_EPS (0x01U)
#define CGRAPH_BOOL_BITS (1)

#define CGRAPH_BOOL_TRUE "true"
#define CGRAPH_BOOL_TRUE_LEN (4)
#define CGRAPH_BOOL_FALSE "false"
#define CGRAPH_BOOL_FALSE_LEN (5)

/**
 * @typedef cgraph_logic_t
 * @brief 2-bit integer number data type, equals to logic in system verilog with
 * 4 states---0, 1, Z and X
 * @def CGRAPH_LOGIC_MAX CGRAPH_LX  (3)
 * @def CGRAPH_LOGIC_MIN CGRAPH_L0 (0)
 * @def CGRAPH_LOGIC_EPS (0x03U)
 * @def CGRAPH_LOGIC_BITS (2)
 */
#define CGRAPH_L0 (0)
#define CGRAPH_L1 (1)
#define CGRAPH_LZ (2)
#define CGRAPH_LX (3)
typedef signed int cgraph_logic_t;
#define CGRAPH_LOGIC_MAX CGRAPH_LX
#define CGRAPH_LOGIC_MIN CGRAPH_L0
#define CGRAPH_LOGIC_EPS (0x03U)
#define CGRAPH_LOGIC_BITS (2)

#define CGRAPH_LOGIC_L0 "0"
#define CGRAPH_LOGIC_L0_LEN (1)
#define CGRAPH_LOGIC_L1 "1"
#define CGRAPH_LOGIC_L1_LEN (1)
#define CGRAPH_LOGIC_LZ "Z"
#define CGRAPH_LOGIC_LZ_LEN (1)
#define CGRAPH_LOGIC_LX "X"
#define CGRAPH_LOGIC_LX_LEN (1)

/**
 * @typedef cgraph_int_t
 * @brief 32-bit integer number data type
 * @def CGRAPH_INT_MAX INT_MAX
 * @def CGRAPH_INT_MIN INT_MIN
 * @def CGRAPH_INT_EPS (0xFFFFFFFFU)
 * @def CGRAPH_INT_BITS (32)
 */
typedef signed int cgraph_int_t;
#define CGRAPH_INT_MAX INT_MAX
#define CGRAPH_INT_MIN INT_MIN
#define CGRAPH_INT_EPS (0xFFFFFFFFU)
#define CGRAPH_INT_BITS (8 * sizeof(cgraph_int_t))

/**
 * @typedef cgraph_uint_t
 * @brief 32-bit unsigned integer number data type
 * @def CGRAPH_UINT_MAX UINT_MAX
 * @def CGRAPH_UINT_MIN UINT_MIN
 * @def CGRAPH_UINT_EPS (0xFFFFFFFFU)
 * @def CGRAPH_UINT_BITS (32)
 */
typedef unsigned int cgraph_uint_t;
#define CGRAPH_UINT_MAX UINT_MAX
#define CGRAPH_UINT_MIN UINT_MIN
#define CGRAPH_UINT_EPS (0xFFFFFFFFU)
#define CGRAPH_UINT_BITS (8 * sizeof(cgraph_uint_t))

/**
 * @typedef cgraph_long_t
 * @brief 32-bit/64-bit integer number data type in 32-bit/64-bit system
 * @def CGRAPH_LONG_MAX LONG_MAX
 * @def CGRAPH_LONG_MIN LONG_MIN
 * @def CGRAPH_LONG_EPS (0xFFFFFFFFU)/(0xFFFFFFFFFFFFFFFFULL)
 * @def CGRAPH_LONG_BITS (32)/(64)
 */
typedef signed long cgraph_long_t;
#define CGRAPH_LONG_MAX LONG_MAX
#define CGRAPH_LONG_MIN LONG_MIN
#define CGRAPH_LONG_EPS __CGRAPH_LONG_EPS
#define CGRAPH_LONG_BITS CGRAPH_WORDSIZE
#define CGRAPH_LONG_EPSILON1 __CGRAPH_LONG_EPSILON1
#define CGRAPH_LONG_EPSILON2 __CGRAPH_LONG_EPSILON2
#define CGRAPH_LONG_EPSILON4 __CGRAPH_LONG_EPSILON4
#define CGRAPH_LONG_EPSILON8 __CGRAPH_LONG_EPSILON8
#define CGRAPH_LONG_EPSILON16 __CGRAPH_LONG_EPSILON16
#define CGRAPH_LONG_EPSILON32 __CGRAPH_LONG_EPSILON32

/**
 * @typedef cgraph_ulong_t
 * @brief 32-bit/64-bit unsigned integer number data type in 32-bit/64-bit
 * system
 * @def CGRAPH_ULONG_MAX ULONG_MAX
 * @def CGRAPH_ULONG_MIN ULONG_MIN
 * @def CGRAPH_ULONG_EPS (0xFFFFFFFF)/(0xFFFFFFFFFFFFFFFF)
 * @def CGRAPH_ULONG_BITS (32)/(64)
 */
typedef unsigned long cgraph_ulong_t;
#define CGRAPH_ULONG_MAX ULONG_MAX
#define CGRAPH_ULONG_MIN ULONG_MIN
#define CGRAPH_ULONG_EPS __CGRAPH_ULONG_EPS
#define CGRAPH_ULONG_BITS CGRAPH_WORDSIZE
#define CGRAPH_ULONG_EPSILON1 __CGRAPH_ULONG_EPSILON1
#define CGRAPH_ULONG_EPSILON2 __CGRAPH_ULONG_EPSILON2
#define CGRAPH_ULONG_EPSILON4 __CGRAPH_ULONG_EPSILON4
#define CGRAPH_ULONG_EPSILON8 __CGRAPH_ULONG_EPSILON8
#define CGRAPH_ULONG_EPSILON16 __CGRAPH_ULONG_EPSILON16
#define CGRAPH_ULONG_EPSILON32 __CGRAPH_ULONG_EPSILON32

/**
 * @typedef cgraph_size_t
 * @brief 32-bit/64-bit integer number data type in 32-bit/64-bit system
 * @def CGRAPH_SIZE_MAX LONG_MAX
 * @def CGRAPH_SIZE_MIN LONG_MIN
 * @def CGRAPH_SIZE_EPS (0xFFFFFFFF)/(0xFFFFFFFFFFFFFFFF)
 * @def CGRAPH_SIZE_BITS (32)/(64)
 */
typedef cgraph_long_t cgraph_size_t;
#define CGRAPH_SIZE_MAX CGRAPH_LONG_MAX
#define CGRAPH_SIZE_MIN CGRAPH_LONG_MIN
#define CGRAPH_SIZE_EPS CGRAPH_LONG_EPS
#define CGRAPH_SIZE_BITS CGRAPH_LONG_BITS
#define CGRAPH_SIZE_OUT_FORMAT "%ld"

/**
 * @typedef cgraph_int8_t
 * @brief 8-bit integer number
 * @def CGRAPH_INT8_MIN
 */
typedef __cgraph_int8 cgraph_int8_t;
#define CGRAPH_INT8_MAX __CGRAPH_INT8_MAX
#define CGRAPH_INT8_MIN __CGRAPH_INT8_MIN
#define CGRAPH_INT8_EPS __CGRAPH_INT8_EPS
#define CGRAPH_INT8_BITS __CGRAPH_INT8_BITS
#define CGRAPH_INT8_IN_FORMAT __CGRAPH_INT8_IN_FORMAT
#define CGRAPH_INT8_OUT_FORMAT __CGRAPH_INT8_OUT_FORMAT

/**
 * @typedef cgraph_uint8_t
 * @brief 8-bit unsigned integer number
 * @def CGRAPH_UINT8_MIN
 */
typedef __cgraph_uint8 cgraph_uint8_t;
#define CGRAPH_UINT8_MAX __CGRAPH_UINT8_MAX
#define CGRAPH_UINT8_MIN __CGRAPH_UINT8_MIN
#define CGRAPH_UINT8_EPS __CGRAPH_UINT8_EPS
#define CGRAPH_UINT8_BITS __CGRAPH_UINT8_BITS
#define CGRAPH_UINT8_IN_FORMAT __CGRAPH_UINT8_IN_FORMAT
#define CGRAPH_UINT8_OUT_FORMAT __CGRAPH_UINT8_OUT_FORMAT

/**
 * @typedef cgraph_int16_t
 * @brief 16-bit integer number
 * @def CGRAPH_INT16_MIN
 */
typedef __cgraph_int16 cgraph_int16_t;
#define CGRAPH_INT16_MIN __CGRAPH_INT16_MIN
#define CGRAPH_INT16_MAX __CGRAPH_INT16_MAX
#define CGRAPH_INT16_EPS __CGRAPH_INT16_EPS
#define CGRAPH_INT16_BITS __CGRAPH_INT16_BITS
#define CGRAPH_INT16_IN_FORMAT __CGRAPH_INT16_IN_FORMAT
#define CGRAPH_INT16_OUT_FORMAT __CGRAPH_INT16_OUT_FORMAT

/**
 * @typedef cgraph_uint16_t
 * @brief 16-bit unsigned integer number
 * @def CGRAPH_UINT16_MIN
 */
typedef __cgraph_uint16 cgraph_uint16_t;
#define CGRAPH_UINT16_MIN __CGRAPH_UINT16_MIN
#define CGRAPH_UINT16_MAX __CGRAPH_UINT16_MAX
#define CGRAPH_UINT16_EPS __CGRAPH_UINT16_EPS
#define CGRAPH_UINT16_BITS __CGRAPH_UINT16_BITS
#define CGRAPH_UINT16_IN_FORMAT __CGRAPH_UINT16_IN_FORMAT
#define CGRAPH_UINT16_OUT_FORMAT __CGRAPH_UINT16_OUT_FORMAT

/**
 * @typedef cgraph_int32_t
 * @brief 32-bit integer number
 * @def CGRAPH_INT32_MIN
 */
typedef __cgraph_int32 cgraph_int32_t;
#define CGRAPH_INT32_MIN __CGRAPH_INT32_MIN
#define CGRAPH_INT32_MAX __CGRAPH_INT32_MAX
#define CGRAPH_INT32_EPS __CGRAPH_INT32_EPS
#define CGRAPH_INT32_BITS __CGRAPH_INT32_BITS
#define CGRAPH_INT32_IN_FORMAT __CGRAPH_INT32_IN_FORMAT
#define CGRAPH_INT32_OUT_FORMAT __CGRAPH_INT32_OUT_FORMAT

/**
 * @typedef cgraph_uint32_t
 * @brief 32-bit unsigned integer number
 * @def CGRAPH_UINT32_MIN
 */
typedef __cgraph_uint32 cgraph_uint32_t;
#define CGRAPH_UINT32_MIN __CGRAPH_UINT32_MIN
#define CGRAPH_UINT32_MAX __CGRAPH_UINT32_MAX
#define CGRAPH_UINT32_EPS __CGRAPH_UINT32_EPS
#define CGRAPH_UINT32_BITS __CGRAPH_UINT32_BITS
#define CGRAPH_UINT32_IN_FORMAT __CGRAPH_UINT32_IN_FORMAT
#define CGRAPH_UINT32_OUT_FORMAT __CGRAPH_UINT32_OUT_FORMAT

/**
 * @typedef cgraph_int64_t
 * @brief 64-bit integer number
 * @def CGRAPH_INT64_MIN
 */
typedef __cgraph_int64 cgraph_int64_t;
#define CGRAPH_INT64_MAX __CGRAPH_INT64_MAX
#define CGRAPH_INT64_MIN __CGRAPH_INT64_MIN
#define CGRAPH_INT64_EPS __CGRAPH_INT64_EPS
#define CGRAPH_INT64_BITS __CGRAPH_INT64_BITS
#define CGRAPH_INT64_IN_FORMAT __CGRAPH_INT64_IN_FORMAT
#define CGRAPH_INT64_OUT_FORMAT __CGRAPH_INT64_OUT_FORMAT
#define CGRAPH_INT64_EPSILON1 __CGRAPH_INT64_EPSILON1
#define CGRAPH_INT64_EPSILON2 __CGRAPH_INT64_EPSILON2
#define CGRAPH_INT64_EPSILON4 __CGRAPH_INT64_EPSILON4
#define CGRAPH_INT64_EPSILON8 __CGRAPH_INT64_EPSILON8
#define CGRAPH_INT64_EPSILON16 __CGRAPH_INT64_EPSILON16
#define CGRAPH_INT64_EPSILON32 __CGRAPH_INT64_EPSILON32

/**
 * @typedef cgraph_uint64_t
 * @brief 64-bit unsigned integer number
 * @def CGRAPH_UINT64_MIN
 */
typedef __cgraph_uint64 cgraph_uint64_t;
#define CGRAPH_UINT64_MAX __CGRAPH_UINT64_MAX
#define CGRAPH_UINT64_MIN __CGRAPH_UINT64_MIN
#define CGRAPH_UINT64_EPS __CGRAPH_UINT64_EPS
#define CGRAPH_UINT64_BITS __CGRAPH_UINT64_BITS
#define CGRAPH_UINT64_IN_FORMAT __CGRAPH_UINT64_IN_FORMAT
#define CGRAPH_UINT64_OUT_FORMAT __CGRAPH_UINT64_OUT_FORMAT
#define CGRAPH_UINT64_EPSILON1 __CGRAPH_INT64_EPSILON1
#define CGRAPH_UINT64_EPSILON2 __CGRAPH_INT64_EPSILON2
#define CGRAPH_UINT64_EPSILON4 __CGRAPH_INT64_EPSILON4
#define CGRAPH_UINT64_EPSILON8 __CGRAPH_INT64_EPSILON8
#define CGRAPH_UINT64_EPSILON16 __CGRAPH_INT64_EPSILON16
#define CGRAPH_UINT64_EPSILON32 __CGRAPH_INT64_EPSILON32

/**
 * @typedef cgraph_float32_t
 * @brief 32-bit floating point number data type
 * @def CGRAPH_FLOAT32_MAX FLT_MAX
 * @def CGRAPH_FLOAT32_MIN FLT_MIN
 * @def CGRAPH_FLOAT32_EPS FLT_EPSILON
 * @def CGRAPH_FLOAT32_BITS FLT_DIG
 */
typedef float cgraph_float32_t;
#define CGRAPH_FLOAT32_MAX FLT_MAX
#define CGRAPH_FLOAT32_MIN FLT_MIN
#define CGRAPH_FLOAT32_EPS FLT_EPSILON
#define CGRAPH_FLOAT32_DIG FLT_DIG
#define CGRAPH_FLOAT32_BITS (32)

/**
 * @typedef cgraph_float64_t
 * @brief 64-bit floating point number data type
 * @def CGRAPH_FLOAT64_MAX DBL_MAX
 * @def CGRAPH_FLOAT64_MIN DBL_MIN
 * @def CGRAPH_FLOAT64_EPS DBL_EPSILON
 * @def CGRAPH_FLOAT64_BITS DBL_DIG
 */
typedef double cgraph_float64_t;
#define CGRAPH_FLOAT64_MAX DBL_MAX
#define CGRAPH_FLOAT64_MIN DBL_MIN
#define CGRAPH_FLOAT64_EPS DBL_EPSILON
#define CGRAPH_FLOAT64_DIG DBL_DIG
#define CGRAPH_FLOAT64_BITS (64)

typedef __CGRAPH_FLOAT128 cgraph_float128_t;
#define CGRAPH_FLOAT128_MAX __CGRAPH_FLOAT128_MIN
#define CGRAPH_FLOAT128_MIN __CGRAPH_FLOAT128_MAX
#define CGRAPH_FLOAT128_EPS __CGRAPH_FLOAT128_EPS
#define CGRAPH_FLOAT128_DIG __CGRAPH_FLOAT128_DIG
#define CGRAPH_FLOAT128_BITS __CGRAPH_FLOAT128_BITS
#define CGRAPH_FLOAT128_IN_FORMAT __CGRAPH_FLOAT128_IN_FORMAT
#define CGRAPH_FLOAT128_OUT_FORMAT __CGRAPH_FLOAT128_OUT_FORMAT
#define CGRAPH_FLOAT128_HASH_OFFSET __CGRAPH_FLOAT128_HASH_OFFSET

#define CGRAPH_FLOAT_NAN_HASH (3141592653UL)
#define CGRAPH_FLOAT_PINF_HASH (1234567891UL)
#define CGRAPH_FLOAT_NINF_HASH (1987654321UL)

#define CGRAPH_MEMORY_HEADER_SIZE (2)
#define CGRAPH_MEMORY_FREED_SIZE (2 * CGRAPH_MEMORY_HEADER_SIZE)

#if CGRAPH_MEMORY_FREED_SIZE <= CGRAPH_MEMORY_HEADER_SIZE
#error CGRAPH_MEMORY_FREED_SIZE must be greater than CGRAPH_MEMORY_HEADER_SIZE
#endif

typedef void *cgraph_stl_t;
typedef cgraph_uint8_t *cgraph_addr_t;

#define CGRAPH_VARADDR(x) (&(x))
#define CGRAPH_VARADDR1V(x) ((cgraph_addr_t)(&(x)))
#define CGRAPH_VARADDR2V(x, y) ((cgraph_addr_t)(&(x)) + (y))

#define CGRAPH_PTRADDR_OUT_FORMAT "%p"
#define CGRAPH_PTRADDR(x) ((void *)(x))
#define CGRAPH_PTRADDR1V(x) ((cgraph_addr_t)(x))
#define CGRAPH_PTRADDR2V(x, y) ((cgraph_addr_t)(x) + (y))

#define CGRAPH_TEST(x) ((x) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define CGRAPH_NTEST(x) ((x) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define CGRAPH_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define CGRAPH_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define CGRAPH_ABS(x) (((x) < 0) ? (-(x)) : (x))
#define CGRAPH_AND(x, y) ((x) & (y))
#define CGRAPH_OR(x, y) ((x) | (y))
#define CGRAPH_XOR(x, y) ((x) ^ (y))
#define CGRAPH_NOT(x) (~(x))
#define CGRAPH_XNOR(x, y) CGRAPH_NOT(CGRAPH_XOR(x, y))
#define CGRAPH_BIT(x, pos) (((x) >> (pos)) & 1)
#define CGRAPH_BSET(x, pos) ((x) | (1 << (pos)))
#define CGRAPH_BCLR(x, pos) ((x) & (~(1 << (pos))))
#define CGRAPH_BITS(x, from, to)                                               \
  (((x) >> (from)) & (~(ONES << ((to) - (from)))))
#define CGRAPH_BSETS(x, from, to)                                              \
  ((x) | ((~(ONES << ((to) - (from)))) << (from)))
#define CGRAPH_BCLRS(x, from, to) ((x) & ((ONES << (to)) | (~(ONES << (from)))))

/**
 * @enum cgraph_type_t
 * @brief the type enumerate structure, storing all object, data and structure
 * types defined in this library
 * @details CGRAPH_OBJECT_T, CGRAPH_HOBJECT_T, CGRAPH_POBJECT_T and
 * CGRAPH_SOBJECT_T share the same value, for the case that object types are
 * defined to be used in structure types and it is useless to use them
 * separately without structure type used and use two or more object types in
 * the same structure module. Users can use them separately with <cgraph.h>
 * included.
 */
typedef enum {
  CGRAPH_OBJECT_T = 0,    /**< TYPE  0 : CGRAPH_OBJECT_T */
  CGRAPH_HOBJECT_T = 0,   /**< TYPE  0 : CGRAPH_HOBJECT_T */
  CGRAPH_GOBJECT_T = 0,   /**< TYPE  0 : CGRAPH_GOBJECT_T */
  CGRAPH_M3OBJECT_T = 0,  /**< TYPE  0 : CGRAPH_M3OBJECT_T */
  CGRAPH_MOBJECT_T = 0,   /**< TYPE  0 : CGRAPH_MOBJECT_T */
  CGRAPH_POBJECT_T = 0,   /**< TYPE  0 : CGRAPH_POBJECT_T */
  CGRAPH_BOOL_T = 1,      /**< TYPE  1 : CGRAPH_BOOL_T */
  CGRAPH_LOGIC_T = 2,     /**< TYPE  2 : CGRAPH_LOGIC_T */
  CGRAPH_INT_T = 3,       /**< TYPE  3 : CGRAPH_INT_T */
  CGRAPH_LONG_T = 4,      /**< TYPE  4 : CGRAPH_LONG_T */
  CGRAPH_INT8_T = 5,      /**< TYPE  5 : CGRAPH_INT8_T */
  CGRAPH_UINT8_T = 5,     /**< TYPE  5 : CGRAPH_UINT8_T */
  CGRAPH_CHAR_T = 5,      /**< TYPE  5 : CGRAPH_CHAR_T */
  CGRAPH_INT16_T = 6,     /**< TYPE  6 : CGRAPH_INT16_T */
  CGRAPH_INT32_T = 7,     /**< TYPE  7 : CGRAPH_INT32_T */
  CGRAPH_INT64_T = 8,     /**< TYPE  8 : CGRAPH_INT64_T */
  CGRAPH_FLOAT32_T = 9,   /**< TYPE  9 : CGRAPH_FLOAT32_T */
  CGRAPH_FLOAT64_T = 10,  /**< TYPE 10 : CGRAPH_FLOAT64_T */
  CGRAPH_FLOAT128_T = 11, /**< TYPE 11 : CGRAPH_FLOAT128_T */
  CGRAPH_TIME_T = 12,     /**< TYPE 12 : CGRAPH_TIME_T */
  CGRAPH_COMPLEX_T = 13,  /**< TYPE 13 : CGRAPH_COMPLEX_T */
  CGRAPH_FRACTION_T = 14, /**< TYPE 14 : CGRAPH_FRACTION_T */
  CGRAPH_BITSET_T = 15,   /**< TYPE 15 : CGRAPH_BITSET_T */
  CGRAPH_BIGINT_T = 16,   /**< TYPE 16 : CGRAPH_BIGINT_T */
  CGRAPH_BIGNUM_T = 17,   /**< TYPE 17 : CGRAPH_BIGNUM_T */
  CGRAPH_STRING_T = 18,   /**< TYPE 18 : CGRAPH_STRING_T */
  CGRAPH_VECTOR_T = 19,   /**< TYPE 19 : CGRAPH_VECTOR_T */
  CGRAPH_MATRIX_T = 20,   /**< TYPE 20 : CGRAPH_MATRIX_T */
  CGRAPH_MATRIX3D_T = 21, /**< TYPE 21 : CGRAPH_MATRIX3D_T */
  CGRAPH_BIGMAT_T = 22,   /**< TYPE 22 : CGRAPH_BIGMAT_T */
  CGRAPH_BIGMAT3D_T = 23, /**< TYPE 23 : CGRAPH_BIGMAT3D_T */
  CGRAPH_SPAMAT_T = 24,   /**< TYPE 24 : CGRAPH_SPAMAT_T */
  CGRAPH_SPAMAT3D_T = 25, /**< TYPE 25 : CGRAPH_SPAMAT3D_T */
  CGRAPH_DFRAME_T = 26,   /**< TYPE 26 : CGRAPH_DFRAME_T */
  CGRAPH_DICT_T = 27,     /**< TYPE 27 : CGRAPH_DICT_T */
  CGRAPH_SET_T = 28,      /**< TYPE 28 : CGRAPH_SET_T */
  CGRAPH_LIST_T = 29,     /**< TYPE 29 : CGRAPH_LIST_T */
  CGRAPH_TREE_T = 30,     /**< TYPE 30 : CGRAPH_TREE_T */
  CGRAPH_NULL_T = 31      /**< TYPE 31 : CGRAPH_NULL_T */
} cgraph_type_t;

/**
 * @def CGRAPH_DTYPE_NPTR_MIN CGRAPH_BOOL_T
 * @def CGRAPH_DTYPE_NPTR_MAX CGRAPH_FRACTION_T
 * @def CGRAPH_DTYPE_PTR_MIN CGRAPH_BITSET_T
 * @def CGRAPH_DTYPE_PTR_MAX CGRAPH_STRING_T
 * @def CGRAPH_TYPE_MIN CGRAPH_VECTOR_T
 * @def CGRAPH_TYPE_MAX CGRAPH_NULL_T
 * @brief the boundary between data objects and data structural objects
 * if type is greater than CGRAPH_NODE_T, this object is a data object;
 * otherwise, this object is a data structural object.
 */
#define CGRAPH_DTYPE_NPTR_MIN CGRAPH_BOOL_T
#define CGRAPH_DTYPE_NPTR_MAX CGRAPH_FRACTION_T
#define CGRAPH_DTYPE_PTR_MIN CGRAPH_BITSET_T
#define CGRAPH_DTYPE_PTR_MAX CGRAPH_STRING_T
#define CGRAPH_TYPE_MIN CGRAPH_VECTOR_T
#define CGRAPH_TYPE_MAX CGRAPH_NULL_T

/**
 * @brief data and structure tyep id
 * @struct cgraph_element_t
 */
typedef struct {
  /**  key data type */
  cgraph_uint_t k_type : 6;
  cgraph_uint_t k_access : 1;
  cgraph_uint_t k_hash : 1;
  /**  value data type */
  cgraph_uint_t v_type : 6;
  cgraph_uint_t v_access : 1;
  cgraph_uint_t v_hash : 1;
  /** unused space for extertions */
  cgraph_uint_t : 8;
  /**  graph type */
  cgraph_uint_t g_keyisid : 1;
  cgraph_uint_t g_directed : 1;
  cgraph_uint_t g_weighted : 1;
  cgraph_uint_t g_multiple : 1;
  cgraph_uint_t g_hyper : 1;
  cgraph_uint_t g_dynamic : 1;
  cgraph_uint_t : 2;
} cgraph_element_t;

#define CGRAPH_DTYPE_KTYPE(a) ((a)->element.k_type)
#define CGRAPH_DTYPE_KACCESS(a) ((a)->element.k_access)
#define CGRAPH_DTYPE_KHASHED(a) ((a)->element.k_hash)

#define CGRAPH_DTYPE_VTYPE(a) ((a)->element.v_type)
#define CGRAPH_DTYPE_VACCESS(a) ((a)->element.v_access)
#define CGRAPH_DTYPE_VHASHED(a) ((a)->element.v_hash)

#define CGRAPH_DTYPE_TYPE(a) CGRAPH_DTYPE_KTYPE(a)
#define CGRAPH_DTYPE_ACCESS(a) CGRAPH_DTYPE_KACCESS(a)
#define CGRAPH_DTYPE_HASHED(a) CGRAPH_DTYPE_KHASHED(a)

#define CGRAPH_GTYPE_GKEYISID(a) ((a)->element.g_keyisid)
#define CGRAPH_GTYPE_GDIRECTED(a) ((a)->element.g_directed)
#define CGRAPH_GTYPE_GWEIGHTED(a) ((a)->element.g_weighted)
#define CGRAPH_GTYPE_GMULTIPLE(a) ((a)->element.g_multiple)
#define CGRAPH_GTYPE_GHYPER(a) ((a)->element.g_hyper)
#define CGRAPH_GTYPE_GDYNAMIC(a) ((a)->element.g_dynamic)

typedef void (*cgraph_pfunc1_t)(void *x);
typedef void (*cgraph_pfunc2_t)(void *x, void *y);
typedef void (*cgraph_pfunc3_t)(void *x, void *y, void *res);

typedef struct {
  /**< private: */
  cgraph_type_t t_id;       /**< type id */
  cgraph_char_t *t_name;    /**< type name */
  cgraph_size_t t_size;     /**< type size */
  cgraph_size_t t_ptrsize;  /**< pointer size of type */
  cgraph_size_t t_cpysize;  /**< memory size of type used in copy memory size,
excludes data pointer size */
  cgraph_size_t t_strusize; /**< memory size of type used in structure types */
  cgraph_size_t t_bmatsize; /**< memory size of type used in big matrix */
  cgraph_size_t t_bmat3dsize; /**< memory size of type used in big matrix 3d */
  cgraph_size_t t_datsize;    /**< data size of type */

  /**< public: */
  cgraph_type_t (*tid)(void);
  cgraph_char_t *(*tname)(void);
  cgraph_size_t (*tsize)(void);
  cgraph_size_t (*tptrsize)(void);
  cgraph_size_t (*tcpycsize)(void);
  cgraph_size_t (*tstrusize)(void);
  cgraph_size_t (*tbmatsize)(void);
  cgraph_size_t (*tbmat3dsize)(void);
  cgraph_size_t (*datsize)(void);
  cgraph_bool_t (*hasdata)(void);
  void *(*data)(const void *cthis);
  cgraph_size_t (*len)(const void *cthis);
  cgraph_size_t (*size)(const void *cthis);
  cgraph_size_t (*msize)(const cgraph_type_t type, const cgraph_size_t size);
  void *(*update)(void *cthis, const cgraph_type_t type,
                  const cgraph_size_t len, const cgraph_size_t size);
  void *(*calloc)(const cgraph_type_t type, const cgraph_size_t size);
  void *(*realloc)(void *cthis, const cgraph_type_t type,
                   const cgraph_size_t old_size, const cgraph_size_t new_size,
                   cgraph_bool_t *error);
  void *(*copy)(const void *cthis, const cgraph_size_t size);
  void (*free)(void *cthis);
  void *(*memcpy)(void *x, const void *y, const cgraph_size_t size);
  void (*check)(const void *x, void *y);
  void (*hash)(const void *x, void *y);
  void (*equal)(const void *x, const void *y, void *z);
  void (*at)(void *x, const cgraph_size_t i);
  void (*add)(void *x, void *y, void *z);
  void (*sub)(void *x, void *y, void *z);
  void (*mul)(void *x, void *y, void *z);
  void (*div)(void *x, void *y, void *z);
  void (*divi)(void *x, void *y, void *z);
  void (*divf)(void *x, void *y, void *z);
  void (*mod)(void *x, void *y, void *z);
  void (*eq)(void *x, void *y, void *z);
  void (*ne)(void *x, void *y, void *z);
  void (*gr)(void *x, void *y, void *z);
  void (*ge)(void *x, void *y, void *z);
  void (*ls)(void *x, void *y, void *z);
  void (*le)(void *x, void *y, void *z);
  void (*sin)(void *x, void *y);
  void (*cos)(void *x, void *y);
  void (*tan)(void *x, void *y);
  void (*asin)(void *x, void *y);
  void (*acos)(void *x, void *y);
  void (*atan)(void *x, void *y);
  void (*sinh)(void *x, void *y);
  void (*cosh)(void *x, void *y);
  void (*tanh)(void *x, void *y);
  void (*log)(void *x, void *y);
  void (*log2)(void *x, void *y);
  void (*log10)(void *x, void *y);
  void (*exp)(void *x, void *y);
  void (*sqrt)(void *x, void *y);
  void *(*cmp)(void *x, void *y, void *z, const cgraph_size_t len,
               cgraph_pfunc3_t iter);
  void *(*iter1v)(void *x, const cgraph_size_t len, cgraph_pfunc1_t iter);
  void *(*iter2v)(void *x, void *y, const cgraph_size_t len,
                  cgraph_pfunc2_t iter);
  void *(*iter2vc)(void *x, void *y, const cgraph_size_t len,
                   cgraph_pfunc2_t iter);
  void *(*iter3v)(void *x, void *y, void *z, const cgraph_size_t len,
                  cgraph_pfunc3_t iter);
  void *(*iter3vvc)(void *x, void *y, void *z, const cgraph_size_t len,
                    cgraph_pfunc3_t iter);
  void *(*iter3vcv)(void *x, void *y, void *z, const cgraph_size_t len,
                    cgraph_pfunc3_t iter);
  void *(*iter3cvc)(void *x, void *y, void *z, const cgraph_size_t len,
                    cgraph_pfunc3_t iter);
  void (*tend)(void);
} CGVTable;

#define __CGRAPH_OBJECTS_NAME(NAME) (_cgraph_##NAME##s)
#define CGRAPH_OBJECTS_NAME(NAME) __CGRAPH_OBJECTS_NAME(NAME)

#define __CGRAPH_UNDEFINED NULL

#ifdef __cplusplus
}
#endif

#endif /** _CGRAPH_CONFIG_H_ */
