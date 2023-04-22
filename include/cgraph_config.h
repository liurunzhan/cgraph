/**
 * @file cgraph_config.h
 * @brief the configuration of cgraph
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

#ifndef __CGRAPH_CONFIG_H__
#define __CGRAPH_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief basic c-type definitions:
 * support for C89/C90 and higher
 * integer number types : char int long int8_t int16_t int32_t int64_t
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
 */
typedef char cgraph_char_t;
/** \defgroup group_char cgraph_char_t */
/** @{ */
#define CGRAPH_CHAR_MAX CHAR_MAX
#define CGRAPH_CHAR_MIN CHAR_MIN
#define CGRAPH_CHAR_MASK UINT8_C(0xFF)
#define CGRAPH_CHAR_EPSILON INT8_C(0x01)
#define CGRAPH_CHAR_BITS (8 * sizeof(cgraph_char_t))
/** @} */

/**
 * @typedef cgraph_uchar_t
 * @brief 8-bit ASCII character data type, used in c-type string
 */
typedef unsigned char cgraph_uchar_t;
/** \defgroup group_uchar cgraph_uchar_t */
/** @{ */
#define CGRAPH_UCHAR_MAX UCHAR_MAX
#define CGRAPH_UCHAR_MIN UCHAR_MIN
#define CGRAPH_UCHAR_MASK UINT8_C(0xFF)
#define CGRAPH_UCHAR_EPSILON UINT8_C(0x01)
#define CGRAPH_UCHAR_BITS (8 * sizeof(cgraph_uchar_t))
/** @} */

/**
 * @typedef cgraph_bool_t
 * @brief 1-bit integer number data type
 */
#define CGRAPH_FALSE INT_C(0)
#define CGRAPH_TRUE INT_C(1)
typedef signed int cgraph_bool_t;
/** \defgroup group_bool cgraph_bool_t */
/** @{ */
#define CGRAPH_BOOL_MAX CGRAPH_TRUE
#define CGRAPH_BOOL_MIN CGRAPH_FALSE
#define CGRAPH_BOOL_MASK UINT_C(0x01)
#define CGRAPH_BOOL_EPSILON INT_C(0x01)
#define CGRAPH_BOOL_BITS (1)
#define CGRAPH_BOOL_L2BITS (0)

/* C-type string boolean definition */
#define CGRAPH_BOOL_STRUE "true"
#define CGRAPH_BOOL_STRUE_LEN (4)
#define CGRAPH_BOOL_SFALSE "false"
#define CGRAPH_BOOL_SFALSE_LEN (5)
/** @} */

/**
 * @typedef cgraph_logic_t
 * @brief 2-bit integer number data type, equals to logic in system verilog with
 * 4 states---0, 1, Z and X
 */
#define CGRAPH_L0 (0)
#define CGRAPH_L1 (1)
#define CGRAPH_LZ (2)
#define CGRAPH_LX (3)
typedef signed int cgraph_logic_t;
/** \defgroup group_logic cgraph_logic_t */
/** @{ */
#define CGRAPH_LOGIC_MAX CGRAPH_LX
#define CGRAPH_LOGIC_MIN CGRAPH_L0
#define CGRAPH_LOGIC_MASK UINT_C(0x03)
#define CGRAPH_LOGIC_EPSILON INT_C(0x01)
#define CGRAPH_LOGIC_BITS (2)
#define CGRAPH_LOGIC_L2BITS (1)

#define CGRAPH_LOGIC_L0 "0"
#define CGRAPH_LOGIC_L0_LEN (1)
#define CGRAPH_LOGIC_L1 "1"
#define CGRAPH_LOGIC_L1_LEN (1)
#define CGRAPH_LOGIC_LZ "Z"
#define CGRAPH_LOGIC_LZ_LEN (1)
#define CGRAPH_LOGIC_LX "X"
#define CGRAPH_LOGIC_LX_LEN (1)
/** @} */

/**
 * @typedef cgraph_int_t
 * @brief 32-bit integer number data type
 */
typedef signed int cgraph_int_t;
/** \defgroup group_int cgraph_int_t */
/** @{ */
#define CGRAPH_INT_MAX INT_MAX
#define CGRAPH_INT_MIN INT_MIN
#define CGRAPH_INT_MASK INT_MASK
#define CGRAPH_INT_MASK1 INT_MASK1
#define CGRAPH_INT_MASK2 INT_MASK2
#define CGRAPH_INT_MASK4 INT_MASK4
#define CGRAPH_INT_MASK8 INT_MASK8
#define CGRAPH_INT_MASK16 INT_MASK16
#define CGRAPH_INT_LSB INT_LSB
#define CGRAPH_INT_MSB INT_MSB
#define CGRAPH_INT_EPSILON UINT_C(0x01)
#define CGRAPH_INT_BITS INT_BITS
#define CGRAPH_INT_L2BITS INT_BITS
/** @} */

/**
 * @typedef cgraph_uint_t
 * @brief 32-bit unsigned integer number data type
 */
typedef unsigned int cgraph_uint_t;
/** \defgroup group_uint cgraph_uint_t */
/** @{ */
#define CGRAPH_UINT_MAX UINT_MAX
#define CGRAPH_UINT_MIN UINT_MIN
#define CGRAPH_UINT_MASK UINT_MASK
#define CGRAPH_UINT_MASK1 UINT_MASK1
#define CGRAPH_UINT_MASK2 UINT_MASK2
#define CGRAPH_UINT_MASK4 UINT_MASK4
#define CGRAPH_UINT_MASK8 UINT_MASK8
#define CGRAPH_UINT_MASK16 UINT_MASK16
#define CGRAPH_UINT_LSB UINT_LSB
#define CGRAPH_UINT_MSB UINT_MSB
#define CGRAPH_UINT_EPSILON UINT_C(0x01)
#define CGRAPH_UINT_BITS (32)
#define CGRAPH_UINT_L2BITS (5)
/** @} */

/**
 * @typedef cgraph_long_t
 * @brief 32-bit/64-bit integer number data type in 32-bit/64-bit system
 */
typedef signed long cgraph_long_t;
/** \defgroup group_long cgraph_long_t */
/** @{ */
#define CGRAPH_LONG_ZERO LONG_C(0)
#define CGRAPH_LONG_ONE LONG_C(1)
#define CGRAPH_LONG_MAX LONG_MAX
#define CGRAPH_LONG_MIN LONG_MIN
#define CGRAPH_LONG_MASK LONG_MASK
#define CGRAPH_LONG_LSB LONG_LSB
#define CGRAPH_LONG_MSB LONG_MSB
#define CGRAPH_LONG_EPSILON LONG_EPSILON
#define CGRAPH_LONG_BITS LONG_BITS
#define CGRAPH_LONG_L2BITS LONG_L2BITS
#define CGRAPH_LONG_MASK1 LONG_MASK1
#define CGRAPH_LONG_MASK2 LONG_MASK2
#define CGRAPH_LONG_MASK4 LONG_MASK4
#define CGRAPH_LONG_MASK8 LONG_MASK8
#define CGRAPH_LONG_MASK16 LONG_MASK16
#define CGRAPH_LONG_MASK32 LONG_MASK32
#define CGRAPH_LONG_MASK64 LONG_MASK64
#define CGRAPH_LONG_IN_FMT "%" SCNdl
#define CGRAPH_LONG_OUT_FMT "%" PRIdl
/** @} */

/**
 * @typedef cgraph_ulong_t
 * @brief 32-bit/64-bit unsigned integer number data type in 32-bit/64-bit
 * system
 */
typedef unsigned long cgraph_ulong_t;
/** \defgroup group_ulong cgraph_ulong_t */
/** @{ */
#define CGRAPH_ULONG_ZERO ULONG_C(0)
#define CGRAPH_ULONG_ONE ULONG_C(1)
#define CGRAPH_ULONG_MAX ULONG_MAX
#define CGRAPH_ULONG_MIN ULONG_MIN
#define CGRAPH_ULONG_MASK ULONG_MASK
#define CGRAPH_ULONG_LSB ULONG_LSB
#define CGRAPH_ULONG_MSB ULONG_MSB
#define CGRAPH_ULONG_EPSILON ULONG_EPSILON
#define CGRAPH_ULONG_BITS ULONG_BITS
#define CGRAPH_ULONG_L2BITS ULONG_L2BITS
#define CGRAPH_ULONG_MASK1 ULONG_MASK1
#define CGRAPH_ULONG_MASK2 ULONG_MASK2
#define CGRAPH_ULONG_MASK4 ULONG_MASK4
#define CGRAPH_ULONG_MASK8 ULONG_MASK8
#define CGRAPH_ULONG_MASK16 ULONG_MASK16
#define CGRAPH_ULONG_MASK32 ULONG_MASK32
#define CGRAPH_ULONG_MASK64 ULONG_MASK64
#define CGRAPH_ULONG_IN_FMT "%" SCNul
#define CGRAPH_ULONG_OUT_FMT "%" PRIul
/** @} */

/**
 * @typedef cgraph_size_t
 * @brief 32-bit/64-bit integer number data type in 32-bit/64-bit system
 */
typedef cgraph_long_t cgraph_size_t;
/** \defgroup group_size cgraph_size_t */
/** @{ */
#define CGRAPH_SIZE_ZERO CGRAPH_LONG_ZERO
#define CGRAPH_SIZE_ONE CGRAPH_LONG_ONE
#define CGRAPH_SIZE_MAX CGRAPH_LONG_MAX
#define CGRAPH_SIZE_MIN CGRAPH_LONG_MIN
#define CGRAPH_SIZE_MASK CGRAPH_LONG_MASK
#define CGRAPH_SIZE_EPSILON CGRAPH_LONG_EPSILON
#define CGRAPH_SIZE_BITS CGRAPH_LONG_BITS
#define CGRAPH_SIZE_L2BITS CGRAPH_LONG_L2BITS
#define CGRAPH_SIZE_IN_FMT "%" SCNdl
#define CGRAPH_SIZE_OUT_FMT "%" PRIdl
/** @} */

/**
 * @typedef cgraph_usize_t
 * @brief 32-bit/64-bit unsigned integer number data type in 32-bit/64-bit
 * system
 */
typedef cgraph_ulong_t cgraph_usize_t;
/** \defgroup group_usize cgraph_usize_t */
/** @{ */
#define CGRAPH_USIZE_ZERO CGRAPH_ULONG_ZERO
#define CGRAPH_USIZE_ONE CGRAPH_ULONG_ONE
#define CGRAPH_USIZE_MAX CGRAPH_ULONG_MAX
#define CGRAPH_USIZE_MIN CGRAPH_ULONG_MIN
#define CGRAPH_USIZE_MASK CGRAPH_ULONG_MASK
#define CGRAPH_USIZE_EPSILON CGRAPH_ULONG_EPSILON
#define CGRAPH_USIZE_BITS CGRAPH_ULONG_BITS
#define CGRAPH_USIZE_L2BITS CGRAPH_ULONG_L2BITS
#define CGRAPH_USIZE_IN_FMT "%" SCNul
#define CGRAPH_USIZE_OUT_FMT "%" PRIul
/** @} */

/**
 * @typedef cgraph_int8_t
 * @brief 8-bit integer number
 */
typedef int8_t cgraph_int8_t;
/** \defgroup group_int8 cgraph_int8_t */
/** @{ */
#define CGRAPH_INT8_MAX INT8_MAX
#define CGRAPH_INT8_MIN INT8_MIN
#define CGRAPH_INT8_MASK INT8_MASK
#define CGRAPH_INT8_MASK1 INT8_MASK1
#define CGRAPH_INT8_MASK2 INT8_MASK2
#define CGRAPH_INT8_MASK4 INT8_MASK4
#define CGRAPH_INT8_LSB INT8_LSB
#define CGRAPH_INT8_MSB INT8_MSB
#define CGRAPH_INT8_EPSILON INT8_EPSILON
#define CGRAPH_INT8_BITS INT8_BITS
#define CGRAPH_INT8_L2BITS INT8_L2BITS
#define CGRAPH_INT8_IN_FMT "%" SCNd8
#define CGRAPH_INT8_OUT_FMT "%" PRId8
/** @} */

/**
 * @typedef cgraph_uint8_t
 * @brief 8-bit unsigned integer number
 */
typedef uint8_t cgraph_uint8_t;
/** \defgroup group_uint8 cgraph_uint8_t */
/** @{ */
#define CGRAPH_UINT8_MAX UINT8_MAX
#define CGRAPH_UINT8_MIN UINT8_MIN
#define CGRAPH_UINT8_MASK UINT8_MASK
#define CGRAPH_UINT8_MASK1 UINT8_MASK1
#define CGRAPH_UINT8_MASK2 UINT8_MASK2
#define CGRAPH_UINT8_MASK4 UINT8_MASK4
#define CGRAPH_UINT8_LSB UINT8_LSB
#define CGRAPH_UINT8_MSB UINT8_MSB
#define CGRAPH_UINT8_EPSILON UINT8_EPSILON
#define CGRAPH_UINT8_BITS UINT8_BITS
#define CGRAPH_UINT8_L2BITS UINT8_L2BITS
#define CGRAPH_UINT8_IN_FMT "%" SCNu8
#define CGRAPH_UINT8_OUT_FMT "%" PRIu8
/** @} */

/**
 * @typedef cgraph_int16_t
 * @brief 16-bit integer number
 */
typedef int16_t cgraph_int16_t;
/** \defgroup group_int16 cgraph_int16_t */
/** @{ */
#define CGRAPH_INT16_MIN INT16_MIN
#define CGRAPH_INT16_MAX INT16_MAX
#define CGRAPH_INT16_MASK INT16_MASK
#define CGRAPH_INT16_MASK1 INT16_MASK1
#define CGRAPH_INT16_MASK2 INT16_MASK2
#define CGRAPH_INT16_MASK4 INT16_MASK4
#define CGRAPH_INT16_MASK8 INT16_MASK8
#define CGRAPH_INT16_LSB INT16_LSB
#define CGRAPH_INT16_MSB INT16_MSB
#define CGRAPH_INT16_EPSILON INT16_EPSILON
#define CGRAPH_INT16_BITS INT16_BITS
#define CGRAPH_INT16_L2BITS INT16_L2BITS
#define CGRAPH_INT16_IN_FMT "%" SCNd16
#define CGRAPH_INT16_OUT_FMT "%" PRId16
/** @} */

/**
 * @typedef cgraph_uint16_t
 * @brief 16-bit unsigned integer number
 */
typedef uint16_t cgraph_uint16_t;
/** \defgroup group_uint16 cgraph_uint16_t */
/** @{ */
#define CGRAPH_UINT16_MIN UINT16_MIN
#define CGRAPH_UINT16_MAX UINT16_MAX
#define CGRAPH_UINT16_MASK UINT16_MASK
#define CGRAPH_UINT16_MASK1 UINT16_MASK1
#define CGRAPH_UINT16_MASK2 UINT16_MASK2
#define CGRAPH_UINT16_MASK4 UINT16_MASK4
#define CGRAPH_UINT16_MASK8 UINT16_MASK8
#define CGRAPH_UINT16_LSB UINT16_LSB
#define CGRAPH_UINT16_MSB UINT16_MSB
#define CGRAPH_UINT16_EPSILON UINT16_EPSILON
#define CGRAPH_UINT16_BITS UINT16_BITS
#define CGRAPH_UINT16_L2BITS UINT16_L2BITS
#define CGRAPH_UINT16_IN_FMT "%" SCNu16
#define CGRAPH_UINT16_OUT_FMT "%" PRIu16
/** @} */

/**
 * @typedef cgraph_int32_t
 * @brief 32-bit integer number
 */
typedef int32_t cgraph_int32_t;
/** \defgroup group_int32 cgraph_int32_t */
/** @{ */
#define CGRAPH_INT32_MIN INT32_MIN
#define CGRAPH_INT32_MAX INT32_MAX
#define CGRAPH_INT32_MASK INT32_MASK
#define CGRAPH_INT32_MASK1 INT32_MASK1
#define CGRAPH_INT32_MASK2 INT32_MASK2
#define CGRAPH_INT32_MASK4 INT32_MASK4
#define CGRAPH_INT32_MASK8 INT32_MASK8
#define CGRAPH_INT32_MASK16 INT32_MASK16
#define CGRAPH_INT32_LSB INT32_LSB
#define CGRAPH_INT32_MSB INT32_MSB
#define CGRAPH_INT32_EPSILON INT32_EPSILON
#define CGRAPH_INT32_BITS INT32_BITS
#define CGRAPH_INT32_L2BITS INT32_L2BITS
#define CGRAPH_INT32_IN_FMT "%" SCNd32
#define CGRAPH_INT32_OUT_FMT "%" PRId32
/** @} */

/**
 * @typedef cgraph_uint32_t
 * @brief 32-bit unsigned integer number
 */
typedef uint32_t cgraph_uint32_t;
/** \defgroup group_uint32 cgraph_uint32_t */
/** @{ */
#define CGRAPH_UINT32_MIN UINT32_MIN
#define CGRAPH_UINT32_MAX UINT32_MAX
#define CGRAPH_UINT32_MASK UINT32_MASK
#define CGRAPH_UINT32_MASK1 UINT32_MASK1
#define CGRAPH_UINT32_MASK2 UINT32_MASK2
#define CGRAPH_UINT32_MASK4 UINT32_MASK4
#define CGRAPH_UINT32_MASK8 UINT32_MASK8
#define CGRAPH_UINT32_MASK16 UINT32_MASK16
#define CGRAPH_UINT32_LSB UINT32_LSB
#define CGRAPH_UINT32_MSB UINT32_MSB
#define CGRAPH_UINT32_EPSILON UINT32_EPSILON
#define CGRAPH_UINT32_BITS UINT32_BITS
#define CGRAPH_UINT32_L2BITS UINT32_L2BITS
#define CGRAPH_UINT32_IN_FMT "%" SCNu32
#define CGRAPH_UINT32_OUT_FMT "%" PRIu32
/** @} */

/**
 * @typedef cgraph_int64_t
 * @brief 64-bit integer number
 */
typedef int64_t cgraph_int64_t;
/** \defgroup group_int64 cgraph_int64_t */
/** @{ */
#define CGRAPH_INT64_MAX INT64_MAX
#define CGRAPH_INT64_MIN INT64_MIN
#define CGRAPH_INT64_MASK INT64_MASK
#define CGRAPH_INT64_LSB INT64_LSB
#define CGRAPH_INT64_MSB INT64_MSB
#define CGRAPH_INT64_EPSILON INT64_EPSILON
#define CGRAPH_INT64_BITS INT64_BITS
#define CGRAPH_INT64_L2BITS INT64_L2BITS
#define CGRAPH_INT64_IN_FMT "%" SCNd64
#define CGRAPH_INT64_OUT_FMT "%" PRId64
#define CGRAPH_INT64_MASK1 INT64_MASK1
#define CGRAPH_INT64_MASK2 INT64_MASK2
#define CGRAPH_INT64_MASK4 INT64_MASK4
#define CGRAPH_INT64_MASK8 INT64_MASK8
#define CGRAPH_INT64_MASK16 INT64_MASK16
#define CGRAPH_INT64_MASK32 INT64_MASK32
#define CGRAPH_INT64_MASK64 INT64_MASK64
/** @} */

/**
 * @typedef cgraph_uint64_t
 * @brief 64-bit unsigned integer number
 */
typedef uint64_t cgraph_uint64_t;
/** \defgroup group_uint64 cgraph_uint64_t */
/** @{ */
#define CGRAPH_UINT64_MAX UINT64_MAX
#define CGRAPH_UINT64_MIN UINT64_MIN
#define CGRAPH_UINT64_MASK UINT64_MASK
#define CGRAPH_UINT64_LSB UINT64_LSB
#define CGRAPH_UINT64_MSB UINT64_MSB
#define CGRAPH_UINT64_BITS UINT64_BITS
#define CGRAPH_UINT64_EPSILON UINT64_EPSILON
#define CGRAPH_UINT64_L2BITS UINT64_L2BITS
#define CGRAPH_UINT64_IN_FMT "%" SCNu64
#define CGRAPH_UINT64_OUT_FMT "%" PRIu64
#define CGRAPH_UINT64_MASK1 UINT64_MASK1
#define CGRAPH_UINT64_MASK2 UINT64_MASK2
#define CGRAPH_UINT64_MASK4 UINT64_MASK4
#define CGRAPH_UINT64_MASK8 UINT64_MASK8
#define CGRAPH_UINT64_MASK16 UINT64_MASK16
#define CGRAPH_UINT64_MASK32 UINT64_MASK32
#define CGRAPH_UINT64_MASK64 UINT64_MASK64
/** @} */

/**
 * @typedef cgraph_int128_t
 * @brief 128-bit integer number
 */
typedef int128_t cgraph_int128_t;
/** \defgroup group_int128 cgraph_int128_t */
/** @{ */
#define CGRAPH_INT128_MAX INT128_MAX
#define CGRAPH_INT128_MIN INT128_MIN
#define CGRAPH_INT128_MASK INT128_MASK
#define CGRAPH_INT128_EPSILON INT128_EPSILON
#define CGRAPH_INT128_BITS INT128_BITS
#define CGRAPH_INT128_L2BITS INT128_L2BITS
#define CGRAPH_INT128_IN_FMT "%" SCNd128
#define CGRAPH_INT128_OUT_FMT "%" PRId128
#define CGRAPH_INT128_MASK1 INT128_MASK1
#define CGRAPH_INT128_MASK2 INT128_MASK2
#define CGRAPH_INT128_MASK4 INT128_MASK4
#define CGRAPH_INT128_MASK8 INT128_MASK8
#define CGRAPH_INT128_MASK16 INT128_MASK16
#define CGRAPH_INT128_MASK32 INT128_MASK32
#define CGRAPH_INT128_MASK64 INT128_MASK64
#define CGRAPH_INT128_MASK128 INT128_MASK128
/** @} */

/**
 * @typedef cgraph_uint128_t
 * @brief 128-bit unsigned integer number
 */
typedef uint128_t cgraph_uint128_t;
/** \defgroup group_uint128 cgraph_uint128_t */
/** @{ */
#define CGRAPH_UINT128_MAX UINT128_MAX
#define CGRAPH_UINT128_MIN UINT128_MIN
#define CGRAPH_UINT128_MASK UINT128_MASK
#define CGRAPH_UINT128_EPSILON UINT128_EPSILON
#define CGRAPH_UINT128_BITS UINT128_BITS
#define CGRAPH_UINT128_L2BITS UINT128_L2BITS
#define CGRAPH_UINT128_IN_FMT "%" SCNd128
#define CGRAPH_UINT128_OUT_FMT "%" PRId128
#define CGRAPH_UINT128_MASK1 UINT128_MASK1
#define CGRAPH_UINT128_MASK2 UINT128_MASK2
#define CGRAPH_UINT128_MASK4 UINT128_MASK4
#define CGRAPH_UINT128_MASK8 UINT128_MASK8
#define CGRAPH_UINT128_MASK16 UINT128_MASK16
#define CGRAPH_UINT128_MASK32 UINT128_MASK32
#define CGRAPH_UINT128_MASK64 UINT128_MASK64
#define CGRAPH_UINT128_MASK128 UINT128_MASK128
/** @} */

/**
 * @typedef cgraph_float8_t
 * @brief 8-bit floating point number data type
 */
typedef float8_t cgraph_float8_t;
/** \defgroup group_float8 cgraph_float8_t */
/** @{ */
#define CGRAPH_FLOAT8_MAX FLT8_MAX
#define CGRAPH_FLOAT8_MIN FLT8_MIN
#define CGRAPH_FLOAT8_NAN FLT8_NAN
#define CGRAPH_FLOAT8_INF FLT8_INF
#define CGRAPH_FLOAT8_PINF FLT8_PINF
#define CGRAPH_FLOAT8_NINF FLT8_NINF
#define CGRAPH_FLOAT8_EPSILON FLT8_EPSILON
#define CGRAPH_FLOAT8_DIG FLT8_DIG
#define CGRAPH_FLOAT8_BITS FLT8_BITS
#define CGRAPH_FLOAT8_FRAC_BITS FLT8_FRAC_BITS
#define CGRAPH_FLOAT8_IN_FMT "%s"
#define CGRAPH_FLOAT8_OUT_FMT "%s"
#define CGRAPH_FLOAT8_FRAC_OFFSET FLT8_FRAC_OFFSET
#define CGRAPH_FLOAT8_FRAC_MASK FLT8_FRAC_MASK
#define CGRAPH_FLOAT8_EXP_BITS FLT8_EXP_BITS
#define CGRAPH_FLOAT8_EXP_OFFSET FLT8_EXP_OFFSET
#define CGRAPH_FLOAT8_EXP_MASK FLT8_EXP_MASK
#define CGRAPH_FLOAT8_EXP_BIAS FLT8_EXP_BIAS
#define CGRAPH_FLOAT8_SIG_BITS FLT8_SIG_BITS
#define CGRAPH_FLOAT8_SIG_OFFSET                                               \
  (CGRAPH_FLOAT8_EXP_BITS + CGRAPH_FLOAT8_FRAC_BITS)
#define CGRAPH_FLOAT8_SIG_MASK FLT8_SIG_MASK
/** @} */

/**
 * @typedef cgraph_float16_t
 * @brief 16-bit floating point number data type
 */
typedef float16_t cgraph_float16_t;
/** \defgroup group_float16 cgraph_float16_t */
/** @{ */
#define CGRAPH_FLOAT16_MAX FLT16_MAX
#define CGRAPH_FLOAT16_MIN FLT16_MIN
#define CGRAPH_FLOAT16_NAN FLT16_NAN
#define CGRAPH_FLOAT16_INF FLT16_INF
#define CGRAPH_FLOAT16_PINF FLT16_PINF
#define CGRAPH_FLOAT16_NINF FLT16_NINF
#define CGRAPH_FLOAT16_EPSILON FLT16_EPSILON
#define CGRAPH_FLOAT16_DIG FLT16_DIG
#define CGRAPH_FLOAT16_BITS FLT16_BITS
#define CGRAPH_FLOAT16_IN_FMT "%s"
#define CGRAPH_FLOAT16_OUT_FMT "%s"
#define CGRAPH_FLOAT16_FRAC_BITS FLT16_FRAC_BITS
#define CGRAPH_FLOAT16_FRAC_OFFSET FLT16_FRAC_OFFSET
#define CGRAPH_FLOAT16_FRAC_MASK FLT16_FRAC_MASK
#define CGRAPH_FLOAT16_EXP_BITS FLT16_EXP_BITS
#define CGRAPH_FLOAT16_EXP_OFFSET FLT16_EXP_OFFSET
#define CGRAPH_FLOAT16_EXP_MASK FLT16_EXP_MASK
#define CGRAPH_FLOAT16_EXP_BIAS FLT16_EXP_BIAS
#define CGRAPH_FLOAT16_SIG_BITS FLT16_SIG_BITS
#define CGRAPH_FLOAT16_SIG_OFFSET                                              \
  (CGRAPH_FLOAT16_EXP_BITS + CGRAPH_FLOAT16_FRAC_BITS)
#define CGRAPH_FLOAT16_SIG_MASK FLT16_SIG_MASK
/** @} */

/**
 * @typedef cgraph_float32_t
 * @brief 32-bit floating point number data type
 */
typedef float cgraph_float32_t;
/** \defgroup group_float32 cgraph_float32_t */
/** @{ */
#define CGRAPH_FLOAT32_MAX FLT_MAX
#define CGRAPH_FLOAT32_MIN FLT_MIN
#define CGRAPH_FLOAT32_NAN FLT_NAN
#define CGRAPH_FLOAT32_INF FLT_INF
#define CGRAPH_FLOAT32_PINF FLT_PINF
#define CGRAPH_FLOAT32_NINF FLT_NINF
#define CGRAPH_FLOAT32_EPSILON FLT_EPSILON
#define CGRAPH_FLOAT32_DIG FLT_DIG
#define CGRAPH_FLOAT32_BITS (32)
#define CGRAPH_FLOAT32_IN_FMT "%f"
#define CGRAPH_FLOAT32_OUT_FMT "%g"
#define CGRAPH_FLOAT32_FRAC_BITS (23)
#define CGRAPH_FLOAT32_FRAC_OFFSET (0)
#define CGRAPH_FLOAT32_FRAC_MASK (0x7FFFFFU)
#define CGRAPH_FLOAT32_EXP_BITS (8)
#define CGRAPH_FLOAT32_EXP_OFFSET CGRAPH_FLOAT32_FRAC_BITS
#define CGRAPH_FLOAT32_EXP_MASK (0xFFU)
#define CGRAPH_FLOAT32_EXP_BIAS (0x7FU)
#define CGRAPH_FLOAT32_SIG_BITS (1)
#define CGRAPH_FLOAT32_SIG_OFFSET                                              \
  (CGRAPH_FLOAT32_EXP_BITS + CGRAPH_FLOAT32_FRAC_BITS)
#define CGRAPH_FLOAT32_SIG_MASK (0x80000000U)
/** @} */

/**
 * @typedef cgraph_float64_t
 * @brief 64-bit floating point number data type
 */
typedef double cgraph_float64_t;
/** \defgroup group_float64 cgraph_float64_t */
/** @{ */
#define CGRAPH_FLOAT64_MAX DBL_MAX
#define CGRAPH_FLOAT64_MIN DBL_MIN
#define CGRAPH_FLOAT64_NAN DBL_NAN
#define CGRAPH_FLOAT64_INF DBL_INF
#define CGRAPH_FLOAT64_PINF DBL_PINF
#define CGRAPH_FLOAT64_NINF DBL_NINF
#define CGRAPH_FLOAT64_EPSILON DBL_EPSILON
#define CGRAPH_FLOAT64_DIG DBL_DIG
#define CGRAPH_FLOAT64_BITS (64)
#define CGRAPH_FLOAT64_IN_FMT "%lf"
#define CGRAPH_FLOAT64_OUT_FMT "%g"
#define CGRAPH_FLOAT64_FRAC_BITS (52)
#define CGRAPH_FLOAT64_FRAC_OFFSET (0)
#define CGRAPH_FLOAT64_FRAC_MASK (0)
#define CGRAPH_FLOAT64_EXP_BITS (11)
#define CGRAPH_FLOAT64_EXP_OFFSET CGRAPH_FLOAT64_FRAC_BITS
#define CGRAPH_FLOAT64_EXP_MASK (0x3FFU)
#define CGRAPH_FLOAT64_EXP_BIAS (0x2FFU)
#define CGRAPH_FLOAT64_SIG_BITS (1)
#define CGRAPH_FLOAT64_SIG_OFFSET                                              \
  (CGRAPH_FLOAT64_EXP_BITS + CGRAPH_FLOAT64_FRAC_BITS)
#define CGRAPH_FLOAT64_SIG_MASK (0)
/** @} */

/**
 * @typedef cgraph_float128_t
 * @brief 128-bit floating point number data type
 */
typedef FLT128 cgraph_float128_t;
/** \defgroup group_float128 cgraph_float128_t */
/** @{ */
#define CGRAPH_FLOAT128_MAX FLT128_MIN
#define CGRAPH_FLOAT128_MIN FLT128_MAX
#define CGRAPH_FLOAT128_NAN FLT128_NAN
#define CGRAPH_FLOAT128_INF FLT128_INF
#define CGRAPH_FLOAT128_PINF FLT128_PINF
#define CGRAPH_FLOAT128_NINF FLT128_NINF
#define CGRAPH_FLOAT128_EPSILON FLT128_EPSILON
#define CGRAPH_FLOAT128_DIG FLT128_DIG
#define CGRAPH_FLOAT128_BITS FLT128_BITS
#define CGRAPH_FLOAT128_IN_FMT "%" FLT128_IN_FMT
#define CGRAPH_FLOAT128_OUT_FMT "%" FLT128_OUT_FMT
#define CGRAPH_FLOAT128_HASH_OFFSET FLT128_HASH_OFFSET
#define CGRAPH_FLOAT128_FRAC_BITS FLT128_FRAC_BITS
#define CGRAPH_FLOAT128_FRAC_OFFSET FLT128_FRAC_OFFSET
#define CGRAPH_FLOAT128_FRAC_MASK FLT128_FRAC_MASK
#define CGRAPH_FLOAT128_EXP_BITS FLT128_EXP_BITS
#define CGRAPH_FLOAT128_EXP_OFFSET FLT128_EXP_OFFSET
#define CGRAPH_FLOAT128_EXP_MASK FLT128_EXP_MASK
/** @} */

/**
 * the hash values of some special float point numbers:
 * nan/+inf/-inf
 */
#define CGRAPH_FLOAT_NAN_HASH USIZE_C(3141592653)
#define CGRAPH_FLOAT_PINF_HASH USIZE_C(1234567891)
#define CGRAPH_FLOAT_NINF_HASH USIZE_C(1987654321)

#define CGRAPH_MEMORY_HEADER_SIZE (2UL)
#define CGRAPH_MEMORY_FREED_SIZE (2UL * CGRAPH_MEMORY_HEADER_SIZE)

typedef void *cgraph_stl_t;
typedef cgraph_uint8_t *cgraph_addr_t;

#define CGRAPH_VARADDR_OUT_FMT "%p"
#define CGRAPH_VARADDR(x) (&(x))
#define CGRAPH_VARADDR1V(x) ((cgraph_addr_t)CGRAPH_VARADDR(x))
#define CGRAPH_VARADDR2V(x, y) (CGRAPH_VARADDR1V(x) + (y))

#define CGRAPH_PTRADDR_OUT_FMT "%p"
#define CGRAPH_PTRADDR(x) ((void *)(x))
#define CGRAPH_PTRADDR1V(x) ((cgraph_addr_t)CGRAPH_PTRADDR(x))
#define CGRAPH_PTRADDR2V(x, y) (CGRAPH_PTRADDR1V(x) + (y))

#define CGRAPH_ISFILE(x) ((NULL != (x)) && (0 == ferror((x))))
#define CGRAPH_ISNFILE(x) ((NULL == (x)) || (0 != ferror((x))))
#define CGRAPH_ISSTR(x) ((NULL != (x)) && ('\0' != *(x)))
#define CGRAPH_ISNSTR(x) ((NULL == (x)) || ('\0' == *(x)))
#define CGRAPH_ISSTR2V(x, y)                                                   \
  (CGRAPH_ISSTR(x) && CGRAPH_ISSTR(y) && ((x) != (y)))
#define CGRAPH_ISNSTR2V(x, y)                                                  \
  (CGRAPH_ISNSTR(x) || CGRAPH_ISNSTR(y) || ((x) == (y)))
#define CGRAPH_ISBUF(x, len) ((NULL != (x)) && (0 < (len)))
#define CGRAPH_ISNBUF(x, len) ((NULL == (x)) || (0 >= (len)))
#define CGRAPH_TEST(x) ((x) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define CGRAPH_NTEST(x) ((x) ? CGRAPH_FALSE : CGRAPH_TRUE)
#define CGRAPH_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define CGRAPH_MAX(x, y) (((x) > (y)) ? (x) : (y))
#define CGRAPH_MIN3V(x, y, z)                                                  \
  (((x) > (y)) ? CGRAPH_MAX(x, z) : CGRAPH_MAX(y, z))
#define CGRAPH_MAX3V(x, y, z)                                                  \
  (((x) < (y)) ? CGRAPH_MIN(x, z) : CGRAPH_MIN(y, z))
#define CGRAPH_ABS(x) ((0 > (x)) ? (-(x)) : (x))
#define CGRAPH_POS(x, bits) ((0 <= (x)) ? (x) : ((x) + (bits)))
#define CGRAPH_AND(x, y) ((x) & (y))
#define CGRAPH_OR(x, y) ((x) | (y))
#define CGRAPH_XOR(x, y) ((x) ^ (y))
#define CGRAPH_NOT(x) (~(x))
#define CGRAPH_XNOR(x, y) CGRAPH_NOT(CGRAPH_XOR(x, y))
#define CGRAPH_ROTL(x, BITS, bits) (((x) << (bits)) | ((x) >> (BITS - (bits))))
#define CGRAPH_ROTR(x, BITS, bits) (((x) >> (bits)) | ((x) << (BITS - (bits))))
#define CGRAPH_BIT(x, pos) (((x) >> (pos)) & CGRAPH_BOOL_MASK)
#define CGRAPH_BFLAG(x, bits) (x | (x >> ((bits)-1)))
#define CGRAPH_BSET(x, pos) ((x) | (CGRAPH_BOOL_MASK << (pos)))
#define CGRAPH_BCLR(x, pos) ((x) & (~(CGRAPH_BOOL_MASK << (pos))))
#define CGRAPH_BITS(x, from, to)                                               \
  (((x) >> (from)) & (~(ONES << ((to) - (from)))))
#define CGRAPH_BSETS(x, from, to)                                              \
  ((x) | ((~(ONES << ((to) - (from)))) << (from)))
#define CGRAPH_BCLRS(x, from, to) ((x) & ((ONES << (to)) | (~(ONES << (from)))))

/** \defgroup group_cstr cgraph_cstr_const  */
/** @{ */
#define CGRAPH_CSTR_NAN "nan"
#define CGRAPH_CSTR_NAN_SIZE (3)
#define CGRAPH_CSTR_INF "inf"
#define CGRAPH_CSTR_INF_SIZE (3)
#define CGRAPH_CSTR_INFR "fni"
#define CGRAPH_CSTR_INFR_SIZE (3)
#define CGRAPH_CSTR_PINF "+inf"
#define CGRAPH_CSTR_PINFR "fni+"
#define CGRAPH_CSTR_PINF_SIZE (4)
#define CGRAPH_CSTR_NINF "-inf"
#define CGRAPH_CSTR_NINFR "fni-"
#define CGRAPH_CSTR_NINF_SIZE (4)
/** @} */

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
/** @defgroup group_type cgraph_type_t */
/** @{ */
typedef enum {
  CGRAPH_MIN_T = 0,       /**< TYPE MN : CGRAPH_MIN_T */
  CGRAPH_OBJECT_T = 0,    /**< TYPE  0 : CGRAPH_OBJECT_T */
  CGRAPH_HOBJECT_T = 0,   /**< TYPE  0 : CGRAPH_HOBJECT_T */
  CGRAPH_GOBJECT_T = 0,   /**< TYPE  0 : CGRAPH_GOBJECT_T */
  CGRAPH_M3OBJECT_T = 0,  /**< TYPE  0 : CGRAPH_M3OBJECT_T */
  CGRAPH_MOBJECT_T = 0,   /**< TYPE  0 : CGRAPH_MOBJECT_T */
  CGRAPH_POBJECT_T = 0,   /**< TYPE  0 : CGRAPH_POBJECT_T */
  CGRAPH_BOOL_T = 1,      /**< TYPE  1 : CGRAPH_BOOL_T */
  CGRAPH_LOGIC_T = 2,     /**< TYPE  2 : CGRAPH_LOGIC_T */
  CGRAPH_INT_T = 3,       /**< TYPE  3 : CGRAPH_INT_T */
  CGRAPH_UINT_T = 3,      /**< TYPE  3 : CGRAPH_UINT_T */
  CGRAPH_LONG_T = 4,      /**< TYPE  4 : CGRAPH_LONG_T */
  CGRAPH_ULONG_T = 4,     /**< TYPE  4 : CGRAPH_ULONG_T */
  CGRAPH_SIZE_T = 4,      /**< TYPE  4 : CGRAPH_SIZE_T */
  CGRAPH_USIZE_T = 4,     /**< TYPE  4 : CGRAPH_USIZE_T */
  CGRAPH_INT8_T = 5,      /**< TYPE  5 : CGRAPH_INT8_T */
  CGRAPH_UINT8_T = 5,     /**< TYPE  5 : CGRAPH_UINT8_T */
  CGRAPH_CHAR_T = 5,      /**< TYPE  5 : CGRAPH_CHAR_T */
  CGRAPH_UCHAR_T = 5,     /**< TYPE  5 : CGRAPH_UCHAR_T */
  CGRAPH_INT16_T = 6,     /**< TYPE  6 : CGRAPH_INT16_T */
  CGRAPH_UINT16_T = 6,    /**< TYPE  6 : CGRAPH_UINT16_T */
  CGRAPH_INT32_T = 7,     /**< TYPE  7 : CGRAPH_INT32_T */
  CGRAPH_UINT32_T = 7,    /**< TYPE  7 : CGRAPH_UINT32_T */
  CGRAPH_INT64_T = 8,     /**< TYPE  8 : CGRAPH_INT64_T */
  CGRAPH_UINT64_T = 8,    /**< TYPE  8 : CGRAPH_UINT64_T */
  CGRAPH_INT128_T = 9,    /**< TYPE  9 : CGRAPH_INT128_T */
  CGRAPH_UINT128_T = 9,   /**< TYPE  9 : CGRAPH_UINT128_T */
  CGRAPH_FLOAT8_T = 10,   /**< TYPE 10 : CGRAPH_FLOAT8_T */
  CGRAPH_FLOAT16_T = 11,  /**< TYPE 11 : CGRAPH_FLOAT16_T */
  CGRAPH_FLOAT32_T = 12,  /**< TYPE 12 : CGRAPH_FLOAT32_T */
  CGRAPH_FLOAT64_T = 13,  /**< TYPE 13 : CGRAPH_FLOAT64_T */
  CGRAPH_FLOAT128_T = 14, /**< TYPE 14 : CGRAPH_FLOAT128_T */
  CGRAPH_TIME_T = 15,     /**< TYPE 15 : CGRAPH_TIME_T */
  CGRAPH_COMPLEX_T = 16,  /**< TYPE 16 : CGRAPH_COMPLEX_T */
  CGRAPH_FRACTION_T = 17, /**< TYPE 17 : CGRAPH_FRACTION_T */
  CGRAPH_POINT2D_T = 18,  /**< TYPE 18 : CGRAPH_POINT2D_T */
  CGRAPH_POINT3D_T = 19,  /**< TYPE 19 : CGRAPH_POINT3D_T */
  CGRAPH_BITSET_T = 20,   /**< TYPE 20 : CGRAPH_BITSET_T */
  CGRAPH_BIGINT_T = 21,   /**< TYPE 21 : CGRAPH_BIGINT_T */
  CGRAPH_BIGNUM_T = 22,   /**< TYPE 22 : CGRAPH_BIGNUM_T */
  CGRAPH_STRING_T = 23,   /**< TYPE 23 : CGRAPH_STRING_T */
  CGRAPH_VECTOR_T = 24,   /**< TYPE 24 : CGRAPH_VECTOR_T */
  CGRAPH_MATRIX_T = 25,   /**< TYPE 25 : CGRAPH_MATRIX_T */
  CGRAPH_MATRIX3D_T = 26, /**< TYPE 26 : CGRAPH_MATRIX3D_T */
  CGRAPH_BIGMAT_T = 27,   /**< TYPE 27 : CGRAPH_BIGMAT_T */
  CGRAPH_BIGMAT3D_T = 28, /**< TYPE 28 : CGRAPH_BIGMAT3D_T */
  CGRAPH_SPAMAT_T = 29,   /**< TYPE 29 : CGRAPH_SPAMAT_T */
  CGRAPH_SPAMAT3D_T = 30, /**< TYPE 30 : CGRAPH_SPAMAT3D_T */
  CGRAPH_DFRAME_T = 31,   /**< TYPE 31 : CGRAPH_DFRAME_T */
  CGRAPH_DICT_T = 32,     /**< TYPE 32 : CGRAPH_DICT_T */
  CGRAPH_SET_T = 33,      /**< TYPE 33 : CGRAPH_SET_T */
  CGRAPH_LIST_T = 34,     /**< TYPE 34 : CGRAPH_LIST_T */
  CGRAPH_QUEUE_T = 35,    /**< TYPE 35 : CGRAPH_QUEUE_T */
  CGRAPH_TREE_T = 36,     /**< TYPE 36 : CGRAPH_TREE_T */
  CGRAPH_MAX_T = 36       /**< TYPE MX : CGRAPH_MAX_T */
} cgraph_type_t;

/**
 * @details the boundary between data objects and data structural objects
 * if type is greater than CGRAPH_NODE_T, this object is a data object;
 * otherwise, this object is a data structural object
 */
#define CGRAPH_DTYPE_NPTR_MIN CGRAPH_BOOL_T
#define CGRAPH_DTYPE_NPTR_MAX CGRAPH_POINT3D_T
#define CGRAPH_DTYPE_PTR_MIN CGRAPH_BITSET_T
#define CGRAPH_DTYPE_PTR_MAX CGRAPH_STRING_T
#define CGRAPH_TYPE_MIN CGRAPH_VECTOR_T
#define CGRAPH_TYPE_MAX CGRAPH_MAX_T
/** @} */

/**
 * @struct cgraph_element_t
 * @brief data and structure tyep id
 */
/** \defgroup group_element cgraph_element_t */
/** @{ */
#pragma pack(1)
typedef struct {
  /**  key data type */
  cgraph_uint_t k_type : 6;
  cgraph_uint_t k_access : 1;
  cgraph_uint_t k_const : 1;
  cgraph_uint_t k_hash : 1;
  cgraph_uint_t : 3;
  /**  value data type */
  cgraph_uint_t v_type : 6;
  cgraph_uint_t v_access : 1;
  cgraph_uint_t v_const : 1;
  cgraph_uint_t v_hash : 1;
  cgraph_uint_t : 3;
  /**  graph type */
  cgraph_uint_t g_keyisid : 1;
  cgraph_uint_t g_directed : 1;
  cgraph_uint_t g_weighted : 1;
  cgraph_uint_t g_multiple : 1;
  cgraph_uint_t g_hyper : 1;
  cgraph_uint_t g_dynamic : 1;
  cgraph_uint_t : 2;
} cgraph_element_t;
#pragma pack()

#define CGRAPH_DTYPE_KTYPE(a) ((a)->element.k_type)
#define CGRAPH_DTYPE_KACCESS(a) ((a)->element.k_access)
#define CGRAPH_DTYPE_KCONST(a) ((a)->element.k_const)
#define CGRAPH_DTYPE_KHASH(a) ((a)->element.k_hash)

#define CGRAPH_DTYPE_VTYPE(a) ((a)->element.v_type)
#define CGRAPH_DTYPE_VACCESS(a) ((a)->element.v_access)
#define CGRAPH_DTYPE_VCONST(a) ((a)->element.v_const)
#define CGRAPH_DTYPE_VHASH(a) ((a)->element.v_hash)

#define CGRAPH_DTYPE_TYPE(a) CGRAPH_DTYPE_KTYPE(a)
#define CGRAPH_DTYPE_ACCESS(a) CGRAPH_DTYPE_KACCESS(a)
#define CGRAPH_DTYPE_CONST(a) CGRAPH_DTYPE_KCONST(a)
#define CGRAPH_DTYPE_HASH(a) CGRAPH_DTYPE_KHASH(a)

#define CGRAPH_GTYPE_GKEYISID(a) ((a)->element.g_keyisid)
#define CGRAPH_GTYPE_GDIRECTED(a) ((a)->element.g_directed)
#define CGRAPH_GTYPE_GWEIGHTED(a) ((a)->element.g_weighted)
#define CGRAPH_GTYPE_GMULTIPLE(a) ((a)->element.g_multiple)
#define CGRAPH_GTYPE_GHYPER(a) ((a)->element.g_hyper)
#define CGRAPH_GTYPE_GDYNAMIC(a) ((a)->element.g_dynamic)
/** @} */

/**
 * @struct cgraph_vtable_t
 * @brief virtual table of each type
 */
typedef const struct {
  /**< private: */
  const cgraph_type_t t_id;          /**< type id */
  const cgraph_char_t *const t_name; /**< type name */
  const cgraph_size_t t_size;        /**< type size */
  const cgraph_size_t t_ptrsize;     /**< pointer size of type */
  const cgraph_size_t t_cpysize; /**< memory size of type used in copy memory
size, excludes data pointer size */
  const cgraph_size_t
      t_strusize; /**< memory size of type used in structure types */
  const cgraph_size_t t_bmatsize; /**< memory size of type used in big matrix */
  const cgraph_size_t
      t_bmat3dsize; /**< memory size of type used in big matrix 3d */
  const cgraph_size_t t_datsize; /**< data size of type */

  /**< public: */
  cgraph_type_t (*const tid)(void);
  cgraph_char_t *(*const tname)(void);
  cgraph_size_t (*const tsize)(void);
  cgraph_size_t (*const tptrsize)(void);
  cgraph_size_t (*const tcpycsize)(void);
  cgraph_size_t (*const tstrusize)(void);
  cgraph_size_t (*const tbmatsize)(void);
  cgraph_size_t (*const tbmat3dsize)(void);
  cgraph_size_t (*const datsize)(void);
  cgraph_bool_t (*const hasdata)(void);
  void *(*data)(const void *cthis);
  cgraph_size_t (*const len)(const void *cthis);
  cgraph_size_t (*const size)(const void *cthis);
  cgraph_size_t (*const msize)(const cgraph_type_t type,
                               const cgraph_size_t size);
  void *(*const update)(void *cthis, const cgraph_type_t type,
                        const cgraph_size_t len, const cgraph_size_t size);
  void *(*const calloc)(const cgraph_type_t type, const cgraph_size_t size);
  void *(*const realloc)(void *cthis, const cgraph_type_t type,
                         const cgraph_size_t old_size,
                         const cgraph_size_t new_size, cgraph_bool_t *error);
  void *(*const copy)(const void *cthis, const cgraph_size_t size);
  void (*const free)(void *cthis);
  void *(*const memcpy)(void *x, const void *y, const cgraph_size_t size);
  void (*const check)(const void *x, void *y);
  void (*const hash)(const void *x, void *y);
  void (*const equal)(const void *x, const void *y, void *z);
  void *(*const datindex)(void *cthis, const cgraph_size_t datindex);
  void *(*const index)(void *cthis, const cgraph_size_t len,
                       const cgraph_size_t index);
  void (*const add)(void *x, void *y, void *z);
  void (*const sub)(void *x, void *y, void *z);
  void (*const mul)(void *x, void *y, void *z);
  void (*const div)(void *x, void *y, void *z);
  void (*const divi)(void *x, void *y, void *z);
  void (*const divf)(void *x, void *y, void *z);
  void (*const mod)(void *x, void *y, void *z);
  void (*const eq)(void *x, void *y, void *z);
  void (*const ne)(void *x, void *y, void *z);
  void (*const gt)(void *x, void *y, void *z);
  void (*const ge)(void *x, void *y, void *z);
  void (*const lt)(void *x, void *y, void *z);
  void (*const le)(void *x, void *y, void *z);
  void (*const sin)(void *x, void *y);
  void (*const cos)(void *x, void *y);
  void (*const tan)(void *x, void *y);
  void (*const asin)(void *x, void *y);
  void (*const acos)(void *x, void *y);
  void (*const atan)(void *x, void *y);
  void (*const sinh)(void *x, void *y);
  void (*const cosh)(void *x, void *y);
  void (*const tanh)(void *x, void *y);
  void (*const log)(void *x, void *y);
  void (*const log2)(void *x, void *y);
  void (*const log10)(void *x, void *y);
  void (*const exp)(void *x, void *y);
  void (*const sqrt)(void *x, void *y);
  void *(*const cmp)(void *x, void *y, void *z, const cgraph_size_t len,
                     void (*func)(void *x, void *y, void *res));
  void *(*const for1v)(void *x, const cgraph_size_t len, void (*func)(void *x));
  void *(*const for2v)(void *x, void *y, const cgraph_size_t len,
                       void (*func)(void *x, void *y));
  void *(*const for2vc)(void *x, void *y, const cgraph_size_t len,
                        void (*func)(void *x, void *y));
  void *(*const for3v)(void *x, void *y, void *z, const cgraph_size_t len,
                       void (*func)(void *x, void *y, void *res));
  void *(*const for3vvc)(void *x, void *y, void *z, const cgraph_size_t len,
                         void (*func)(void *x, void *y, void *res));
  void *(*const for3vcv)(void *x, void *y, void *z, const cgraph_size_t len,
                         void (*func)(void *x, void *y, void *res));
  void *(*const for3cvc)(void *x, void *y, void *z, const cgraph_size_t len,
                         void (*func)(void *x, void *y, void *res));
  void (*const tend)(void);
} cgraph_vtable_t;

#define __CGRAPH_OBJECTS_NAME(NAME) (_cgraph_##NAME##_s_)
#define CGRAPH_OBJECTS_NAME(NAME) __CGRAPH_OBJECTS_NAME(NAME)

#define __UNDEFINED NULL

/** @brief buffer size level */
/** \defgroup group_cbufsize cgraph c-type buffer size */
/** @{ */
#define CGRAPH_CBUF_SIZE0 (128L)
#define CGRAPH_CBUF_SIZE1 (256L)
#define CGRAPH_CBUF_SIZE2 (512L)
#define CGRAPH_CBUF_SIZE3 (1024L)
#define CGRAPH_CBUF_SIZE4 (2048L)

#ifndef BUFSIZ
#define BUFSIZ (8192L)
#endif
#define CGRAPH_CBUF_SIZE5 BUFSIZ
/** @} */

/** @details data lazy size level */
/** \defgroup group_cdatsize cgraph data size */
/** @{ */
#define CGRAPH_DATA_SIZE0 (2L)
#define CGRAPH_DATA_SIZE1 (4L)
#define CGRAPH_DATA_SIZE2 (8L)
/** @} */

#define CGRAPH_TIME_FMT "%Y-%m-%d %H:%M:%S"

#ifdef __cplusplus
}
#endif

#endif /** __CGRAPH_CONFIG_H__ */
