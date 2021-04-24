#if defined(TYPE)
#error before <cgraph_template.h> is included, no other <cgraph_template.h> is included without <cgraph_template_off.h> included
#endif

#define CONCAT1V(a) #a
#define CONCAT1(a) CONCAT1V(a)
#define CONCAT2V(a, b) a##_##b
#define CONCAT2(a, b) CONCAT2V(a, b)
#define CONCAT3V(a, b, c) a##_##b##_##c
#define CONCAT3(a, b, c) CONCAT3V(a, b, c)
#define CONCAT4V(a, b, c, d) a##_##b##_##c##_##d
#define CONCAT4(a, b, c, d) CONCAT4V(a, b, c, d)

#define STRUCT(a) CONCAT3(_cgraph, a, struct_)
#define STRING(a) CONCAT1(a)
#define FUNCPTR(a, b) CONCAT4(cgraph, a, b, t)
#define FUNCTION(a, b) CONCAT3(cgraph, a, b)

/**
 * @brief DATA AND STRUCTURE TYPE TEMPLATE :
 * @def TYPE
 * @def ID
 * @def NAME
 * @def OUT_FORMAT
 * @def UTYPE
 * @def ZERO
 * @def ONE
 * @def ONES
 * @def BITS
 * @def MIN
 * @def MAX
 * @def EPSILON
 * @def EPSILON_LEN
 *
 * @def DATA_TYPE
 * @def DATA_ID
 * @def DATA_NAME
 * @def DATA_UTYPE
 * @def DATA_ZERO
 * @def DATA_ONE
 * @def DATA_ONES
 * @def DATA_BITS
 * @def DATA_MIN
 * @def DATA_MAX
 * @def DATA_EPSILON
 * @def DATA_EPSILON_LEN
 */

#if defined(TYPE_OBJECT)
#define TYPE cgraph_object_t
#define ID CGRAPH_OBJECT_T
#define NAME object
#define OUT_FORMAT "ld"
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)

#elif defined(TYPE_HOBJECT)
#define TYPE cgraph_hobject_t
#define ID CGRAPH_HOBJECT_T
#define NAME hobject
#define OUT_FORMAT "ld"
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define OBJECT(type, opt) CGRAPH_HOBJECT(type, opt)

#elif defined(TYPE_GOBJECT)
#define TYPE cgraph_gobject_t
#define ID CGRAPH_GOBJECT_T
#define NAME gobject
#define OUT_FORMAT "ld"
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define OBJECT(type, opt) CGRAPH_GOBJECT(type, opt)

#elif defined(TYPE_M3OBJECT)
#define TYPE cgraph_m3object_t
#define ID CGRAPH_M3OBJECT_T
#define NAME m3object
#define OUT_FORMAT "ld"
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define OBJECT(type, opt) CGRAPH_M3OBJECT(type, opt)

#elif defined(TYPE_MOBJECT)
#define TYPE cgraph_mobject_t
#define ID CGRAPH_MOBJECT_T
#define NAME mobject
#define OUT_FORMAT "ld"
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#define OBJECT(type, opt) CGRAPH_MOBJECT(type, opt)

#elif defined(TYPE_BOOL)
#define ARG cgraph_long_t
#define TYPE cgraph_bool_t
#define ID CGRAPH_BOOL_T
#define NAME bool
#define IN_FORMAT "%s"
#define OUT_FORMAT "%s"
#define UTYPE cgraph_bool_t
#define ZERO CGRAPH_FALSE
#define ONE CGRAPH_TRUE
#define ONES CGRAPH_TRUE
#define BITS CGRAPH_BOOL_BITS
#define MIN CGRAPH_BOOL_MIN
#define MAX CGRAPH_BOOL_MAX
#define MSB (ONE)
#define LSB (ONE)
#define EPSILON CGRAPH_BOOL_EPS
#define EPSILON_LEN CGRAPH_BOOL_BITS

#elif defined(TYPE_LOGIC)
#define ARG cgraph_long_t
#define TYPE cgraph_logic_t
#define ID CGRAPH_LOGIC_T
#define NAME logic
#define IN_FORMAT "%s"
#define OUT_FORMAT "%s"
#define UTYPE cgraph_logic_t
#define ZERO CGRAPH_L0
#define ONE CGRAPH_L1
#define ONES CGRAPH_L1
#define BITS CGRAPH_LOGIC_BITS
#define MIN CGRAPH_LOGIC_MIN
#define MAX CGRAPH_LOGIC_MAX
#define MSB CGRAPH_L1
#define LSB CGRAPH_LZ
#define EPSILON CGRAPH_LOGIC_EPS
#define EPSILON_LEN CGRAPH_LOGIC_BITS

#elif defined(TYPE_INT)
#define ARG cgraph_long_t
#define TYPE cgraph_int_t
#define ID CGRAPH_INT_T
#define NAME int
#define IN_FORMAT "%d"
#define OUT_FORMAT "%d"
#define UTYPE cgraph_uint_t
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT_MIN
#define BITS CGRAPH_INT_BITS
#define MIN CGRAPH_INT_MIN
#define MAX CGRAPH_INT_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPSILON CGRAPH_INT_EPS
#define EPSILON_LEN CGRAPH_INT_BITS
#define EPSILON1 (0xAAAAAAAAU)
#define EPSILON2 (0xCCCCCCCCU)
#define EPSILON4 (0xF0F0F0F0U)
#define EPSILON8 (0xFF00FF00U)
#define EPSILON16 (0xFFFF0000U)

#elif defined(TYPE_LONG)
#define ARG cgraph_long_t
#define TYPE cgraph_long_t
#define ID CGRAPH_LONG_T
#define NAME long
#define IN_FORMAT "%ld"
#define OUT_FORMAT "%ld"
#define UTYPE cgraph_ulong_t
#define ZERO (0L)
#define ONE (1L)
#define ONES CGRAPH_LONG_MIN
#define BITS CGRAPH_LONG_BITS
#define MIN CGRAPH_LONG_MIN
#define MAX CGRAPH_LONG_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPSILON CGRAPH_LONG_EPS
#define EPSILON_LEN CGRAPH_LONG_BITS
#define EPSILON1 CGRAPH_LONG_EPSILON1
#define EPSILON2 CGRAPH_LONG_EPSILON2
#define EPSILON4 CGRAPH_LONG_EPSILON4
#define EPSILON8 CGRAPH_LONG_EPSILON8
#define EPSILON16 CGRAPH_LONG_EPSILON16
#define EPSILON32 CGRAPH_LONG_EPSILON32

#elif defined(TYPE_INT8)
#define ARG cgraph_long_t
#define TYPE cgraph_int8_t
#define ID CGRAPH_INT8_T
#define NAME int8
#define IN_FORMAT CGRAPH_INT8_IN_FORMAT
#define OUT_FORMAT CGRAPH_INT8_OUT_FORMAT
#define UTYPE cgraph_uint8_t
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT8_MIN
#define BITS CGRAPH_INT8_BITS
#define BITS_LOG2 CGRAPH_INT8_BITS_LOG2
#define MIN CGRAPH_INT8_MIN
#define MAX CGRAPH_INT8_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPSILON CGRAPH_INT8_EPS
#define EPSILON_LEN CGRAPH_INT8_BITS
#define EPSILON1 (0xAAU)
#define EPSILON2 (0xCCU)
#define EPSILON4 (0xF0U)

#elif defined(TYPE_INT16)
#define ARG cgraph_long_t
#define TYPE cgraph_int16_t
#define ID CGRAPH_INT16_T
#define NAME int16
#define IN_FORMAT CGRAPH_INT16_IN_FORMAT
#define OUT_FORMAT CGRAPH_INT16_OUT_FORMAT
#define UTYPE cgraph_uint16_t
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT16_MIN
#define BITS CGRAPH_INT16_BITS
#define BITS_LOG2 CGRAPH_INT16_BITS_LOG2
#define MIN CGRAPH_INT16_MIN
#define MAX CGRAPH_INT16_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPSILON CGRAPH_INT16_EPS
#define EPSILON_LEN CGRAPH_INT16_BITS
#define EPSILON1 (0xAAAAU)
#define EPSILON2 (0xCCCCU)
#define EPSILON4 (0xF0F0U)
#define EPSILON8 (0xFF00U)

#elif defined(TYPE_INT32)
#define ARG cgraph_long_t
#define TYPE cgraph_int32_t
#define ID CGRAPH_INT32_T
#define NAME int32
#define IN_FORMAT CGRAPH_INT32_IN_FORMAT
#define OUT_FORMAT CGRAPH_INT32_OUT_FORMAT
#define UTYPE cgraph_uint32_t
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT32_MIN
#define BITS CGRAPH_INT32_BITS
#define BITS_LOG2 CGRAPH_INT32_BITS_LOG2
#define MIN CGRAPH_INT32_MIN
#define MAX CGRAPH_INT32_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPSILON CGRAPH_INT32_EPS
#define EPSILON_LEN CGRAPH_INT32_BITS
#define HASH_OFFSET (4)
#define EPSILON1 (0xAAAAAAAAU)
#define EPSILON2 (0xCCCCCCCCU)
#define EPSILON4 (0xF0F0F0F0U)
#define EPSILON8 (0xFF00FF00U)
#define EPSILON16 (0xFFFF0000U)

#elif defined(TYPE_INT64)
#define ARG cgraph_long_t
#define TYPE cgraph_int64_t
#define ID CGRAPH_INT64_T
#define NAME int64
#define IN_FORMAT CGRAPH_INT64_IN_FORMAT
#define OUT_FORMAT CGRAPH_INT64_OUT_FORMAT
#define UTYPE cgraph_uint64_t
#define ZERO (0)
#define ONE (1)
#define ONES CGRAPH_INT64_MIN
#define BITS CGRAPH_INT64_BITS
#define BITS_LOG2 CGRAPH_INT64_BITS_LOG2
#define MIN CGRAPH_INT64_MIN
#define MAX CGRAPH_INT64_MAX
#define MSB (ONE << (BITS - 1))
#define LSB (ONE)
#define EPSILON CGRAPH_INT64_EPS
#define EPSILON_LEN CGRAPH_INT64_BITS
#define HASH_OFFSET (8)
#define EPSILON1 CGRAPH_INT64_EPSILON1
#define EPSILON2 CGRAPH_INT64_EPSILON2
#define EPSILON4 CGRAPH_INT64_EPSILON4
#define EPSILON8 CGRAPH_INT64_EPSILON8
#define EPSILON16 CGRAPH_INT64_EPSILON16
#define EPSILON32 CGRAPH_INT64_EPSILON32

#elif defined(TYPE_FLOAT32)
#define ARG cgraph_float64_t
#define TYPE cgraph_float32_t
#define ID CGRAPH_FLOAT32_T
#define NAME float32
#define IN_FORMAT "%g"
#define OUT_FORMAT "%g"
#define ZERO (0.0)
#define ONE (1.0)
#define ONES (1.0)
#define BITS CGRAPH_FLOAT32_BITS
#define MIN CGRAPH_FLOAT32_MIN
#define MAX CGRAPH_FLOAT32_MAX
#define EPSILON CGRAPH_FLOAT32_EPS
#define EPSILON_LEN CGRAPH_FLOAT32_DIG
#define HASH_OFFSET (4)

#elif defined(TYPE_FLOAT64)
#define ARG cgraph_float64_t
#define TYPE cgraph_float64_t
#define ID CGRAPH_FLOAT64_T
#define NAME float64
#define IN_FORMAT "%g"
#define OUT_FORMAT "%g"
#define ZERO (0.0)
#define ONE (1.0)
#define ONES (1.0)
#define BITS CGRAPH_FLOAT64_BITS
#define MIN CGRAPH_FLOAT64_MIN
#define MAX CGRAPH_FLOAT64_MAX
#define EPSILON CGRAPH_FLOAT64_EPS
#define EPSILON_LEN CGRAPH_FLOAT64_DIG
#define HASH_OFFSET (8)

#elif defined(TYPE_FLOAT128)
#define ARG cgraph_float128_t
#define TYPE cgraph_float128_t
#define ID CGRAPH_FLOAT128_T
#define NAME float128
#define IN_FORMAT CGRAPH_FLOAT128_IN_FORMAT
#define OUT_FORMAT CGRAPH_FLOAT128_OUT_FORMAT
#define ZERO (0.0)
#define ONE (1.0)
#define ONES (1.0)
#define BITS CGRAPH_FLOAT128_BITS
#define MIN CGRAPH_FLOAT128_MIN
#define MAX CGRAPH_FLOAT128_MAX
#define EPSILON CGRAPH_FLOAT128_EPS
#define EPSILON_LEN CGRAPH_FLOAT128_DIG
#define HASH_OFFSET CGRAPH_FLOAT128_HASH_OFFSET

#elif defined(TYPE_TIME)
#define TYPE cgraph_time_t
#define ID CGRAPH_TIME_T
#define NAME time
#define OUT_FORMAT0 "%d%d"
#define ZERO0                                                                  \
  {                                                                            \
    0, {                                                                       \
      { 0, 0 }                                                                 \
    }                                                                          \
  }
#define ONE0                                                                   \
  {                                                                            \
    0, {                                                                       \
      { 0, 1 }                                                                 \
    }                                                                          \
  }
#define ONES0                                                                  \
  {                                                                            \
    1, {                                                                       \
      { 1, 1 }                                                                 \
    }                                                                          \
  }
#define OUT_FORMAT1 "%d-%d-%d %d-%d-%d"
#define ZERO1                                                                  \
  {                                                                            \
    0, {                                                                       \
      { 0, 0, 0, 0, 0, 0 }                                                     \
    }                                                                          \
  }
#define ONE1                                                                   \
  {                                                                            \
    0, {                                                                       \
      { 0, 0, 0, 0, 0, 1 }                                                     \
    }                                                                          \
  }
#define ONES1                                                                  \
  {                                                                            \
    1, {                                                                       \
      { 1, 1, 1, 1, 1, 1 }                                                     \
    }                                                                          \
  }
#define ZERO ZERO0
#define ONE ONE0
#define ONES ONE0
#define BITS (8 * sizeof(TYPE) - 1)
#define MIN (0)
#define MAX (1)
#define DATA_TYPE cgraph_int32_t
#define DATA_ID CGRAPH_INT32_T
#define DATA_NAME int32
#define DATA_UTYPE cgraph_uint32_t
#define DATA_ZERO (0)
#define DATA_ONE (1)
#define DATA_ONES (1)
#define DATA_BITS (8 * sizeof(DATA_TYPE))
#define DATA_MIN CGRAPH_INT32_MIN
#define DATA_MAX CGRAPH_INT32_MAX
#define DATA_MIN1 CGRAPH_INT32_MAX
#define DATA_MAX1 (CGRAPH_INT32_MIN & 0x3FFFFFFFU)
#define DATA_MSB (DATA_ONE << (DATA_BITS - 1))
#define DATA_LSB (DATA_ONE)
#define DATA_EPSILON CGRAPH_INT32_EPS

#elif defined(TYPE_COMPLEX)
#define TYPE cgraph_complex_t
#define ID CGRAPH_COMPLEX_T
#define NAME complex
#define OUT_FORMAT "%g+i%g"
#define ZERO                                                                   \
  {                                                                            \
    { 0.0, 0.0 }                                                               \
  }
#define ONE                                                                    \
  {                                                                            \
    { 1.0, 0.0 }                                                               \
  }
#define ONES                                                                   \
  {                                                                            \
    { 1.0, 1.0 }                                                               \
  }
#define BITS (CGRAPH_FLOAT64_BITS * 2)
#define MIN                                                                    \
  {                                                                            \
    { CGRAPH_FLOAT64_MIN, CGRAPH_FLOAT64_MIN }                                 \
  }
#define MAX                                                                    \
  {                                                                            \
    { CGRAPH_FLOAT64_MAX, CGRAPH_FLOAT64_MAX }                                 \
  }
#define DATA_TYPE cgraph_float64_t
#define DATA_ID CGRAPH_FLOAT64_T
#define DATA_NAME float64
#define DATA_ZERO 0.0
#define DATA_ONE 1.0
#define DATA_ONES 1.0
#define DATA_BITS CGRAPH_FLOAT64_BITS
#define DATA_MIN CGRAPH_FLOAT64_MIN
#define DATA_MAX CGRAPH_FLOAT64_MAX
#define DATA_EPSILON CGRAPH_FLOAT64_EPS
#define DATA_EPSILON_LEN CGRAPH_FLOAT64_BITS

#elif defined(TYPE_FRACTION)
#define TYPE cgraph_fraction_t
#define ID CGRAPH_FRACTION_T
#define NAME fraction
#define OUT_FORMAT "%d/%d"
#define ZERO                                                                   \
  {                                                                            \
    { 0, 1 }                                                                   \
  }
#define ONE                                                                    \
  {                                                                            \
    { 1, 1 }                                                                   \
  }
#define ONES                                                                   \
  {                                                                            \
    { CGRAPH_INT_MIN, 1 }                                                      \
  }
#define BITS (8 * sizeof(TYPE))
#define MIN                                                                    \
  {                                                                            \
    { CGRAPH_INT_MIN, 1 }                                                      \
  }
#define MAX                                                                    \
  {                                                                            \
    { CGRAPH_INT_MAX, 1 }                                                      \
  }
#define EPSILON                                                                \
  {                                                                            \
    { 1, CGRAPH_INT_MAX }                                                      \
  }
#define EPSILON_LEN (8 * sizeof(TYPE))
#define DATA_TYPE cgraph_int_t
#define DATA_ID CGRAPH_INT_T
#define DATA_NAME int
#define DATA_ZERO 0
#define DATA_ONE 1
#define DATA_ONES CGRAPH_INT_MIN
#define DATA_BITS (8 * sizeof(DATA_TYPE))
#define DATA_MIN CGRAPH_INT_MIN
#define DATA_MAX CGRAPH_INT_MAX
#define DATA_MSB (DATA_ONE << (DATA_BITS - 1))
#define DATA_LSB (DATA_ONE)
#define DATA_EPSILON CGRAPH_INT_EPS

#elif defined(TYPE_BIGINT)
#define TYPE cgraph_bigint_t
#define ID CGRAPH_BIGINT_T
#define NAME bigint
#define OUT_FORMAT "%u"
#define ZERO(x) FUNCTION(NAME, zero)((x), 0)
#define ONE(x) FUNCTION(NAME, one)((x), 0)
#define ONES(x) FUNCTION(NAME, ones)((x), 0)
#define MIN(x) FUNCTION(NAME, min)((x)), 0)
#define MAX(x) FUNCTION(NAME, max)((x), 0)
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_uint8_t
#define DATA_ID CGRAPH_UINT8_T
#define DATA_UTYPE cgraph_uint8_t
#define DATA_ZERO (0)
#define DATA_ONE (1)
#define DATA_ONES CGRAPH_UINT8_MAX
#define DATA_BITS CGRAPH_UINT8_BITS
#define DATA_BITS_LOG2 CGRAPH_UINT8_BITS_LOG2
#define DATA_MIN CGRAPH_UINT8_MIN
#define DATA_MAX CGRAPH_UINT8_MAX
#define DATA_MSB (1)
#define DATA_LSB (1 << (CGRAPH_UINT8_BITS - 1))
#define DATA_EPSILON CGRAPH_UINT8_EPS

#elif defined(TYPE_BIGNUM)
#define TYPE cgraph_bignum_t
#define ID CGRAPH_BIGNUM_T
#define NAME bignum
#define OUT_FORMAT "%c"
#define ZERO(x) FUNCTION(NAME, zero)((x), 0)
#define ONE(x) FUNCTION(NAME, one)((x), 0)
#define ONES(x) FUNCTION(NAME, ones)((x), 0)
#define BITS (8 * sizeof(TYPE))
#define MIN FUNCTION(NAME, min)((x), 0)
#define MAX FUNCTION(NAME, max)((x), 0)
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_char_t
#define DATA_ID CGRAPH_CHAR_T
#define DATA_BITS (8 * sizeof(DATA_TYPE))
#define DATA_ZERO ('0')
#define DATA_ONE ('1')
#define DATA_ONES ('1')
#define DATA_MIN ('0')
#define DATA_MAX ('9')

#elif defined(TYPE_STRING)
#define TYPE cgraph_string_t
#define ID CGRAPH_STRING_T
#define NAME string
#define OUT_FORMAT "%s"
#define ZERO(x) FUNCTION(NAME, zero)((x), 0)
#define ONE(x) FUNCTION(NAME, one)((x), 0)
#define ONES(x) FUNCTION(NAME, ones)((x), 0)
#define BITS (8 * sizeof(TYPE))
#define MIN CGRAPH_CHAR_MIN
#define MAX CGRAPH_CHAR_MAX
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_char_t
#define DATA_ID CGRAPH_CHAR_T
#define DATA_ZERO ('0')
#define DATA_ONE ('1')
#define DATA_ONES ('1')
#define DATA_MIN (' ')
#define DATA_MAX ('~')
#define DATA_BITS (8 * sizeof(DATA_TYPE))

#elif defined(TYPE_BITSET)
#define TYPE cgraph_bitset_t
#define ID CGRAPH_BITSET_T
#define NAME bitset
#define OUT_FORMAT "%02x"
#define ZERO(x) FUNCTION(NAME, zero)((x), 0)
#define ONE(x) FUNCTION(NAME, one)((x), 0)
#define ONES(x) FUNCTION(NAME, ones)((x), 0)
#define BITS CGRAPH_UINT8_MIN
#define MIN (0)
#define MAX CGRAPH_UINT8_MIN
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_uint8_t
#define DATA_UTYPE cgraph_uint8_t
#define DATA_ID CGRAPH_UINT8_T
#define DATA_ZERO 0
#define DATA_ONE 1
#define DATA_ONES CGRAPH_UINT8_MAX
#define DATA_BITS (8 * sizeof(DATA_TYPE))
#define DATA_BITS_LOG2 CGRAPH_UINT8_BITS_LOG2
#define DATA_MIN CGRAPH_UINT8_MIN
#define DATA_MAX CGRAPH_UINT8_MAX
#define DATA_EPSILON CGRAPH_UINT8_EPS

#elif defined(TYPE_VECTOR)
#define TYPE cgraph_vector_t
#define ID CGRAPH_VECTOR_T
#define NAME vector
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_MATRIX)
#define TYPE cgraph_matrix_t
#define ID CGRAPH_MATRIX_T
#define NAME matrix
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_MATRIX3D)
#define TYPE cgraph_matrix3d_t
#define ID CGRAPH_MATRIX3D_T
#define NAME matrix3d
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_BIGMAT)
#define TYPE cgraph_bigmat_t
#define ID CGRAPH_BIGMAT_T
#define NAME bigmat
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_BIGMAT3D)
#define TYPE cgraph_bigmat3d_t
#define ID CGRAPH_BIGMAT3D_T
#define NAME bigmat3d
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_SPAMAT)
#define TYPE cgraph_spamat_t
#define ID CGRAPH_SPAMAT_T
#define NAME spamat
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_SPAMAT3D)
#define TYPE cgraph_spamat3d_t
#define ID CGRAPH_SPAMAT3D_T
#define NAME spamat3d
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_DFRAME)
#define TYPE cgraph_dframe_t
#define ID CGRAPH_DFRAME_T
#define NAME dframe
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_DICT)
#define TYPE cgraph_dict_t
#define ID CGRAPH_DICT_T
#define NAME dict
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_SET)
#define TYPE cgraph_set_t
#define ID CGRAPH_SET_T
#define NAME tree
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_LIST)
#define TYPE cgraph_list_t
#define ID CGRAPH_LIST_T
#define NAME list
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_TREE)
#define TYPE cgraph_tree_t
#define ID CGRAPH_TREE_T
#define NAME tree
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_QUEUE)
#define TYPE cgraph_queue_t
#define ID CGRAPH_QUEUE_T
#define NAME tree
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#elif defined(TYPE_STACK)
#define TYPE cgraph_stack_t
#define ID CGRAPH_STACK_T
#define NAME tree
#define ZERO NULL
#define TYPE_WITH_DATA
#define DATA_TYPE cgraph_stl_t

#else
#error <cgraph_template.h> can not be included directly without supported macro TYPE_* defined
#endif

/**property inheritance of object types */
#define CGRAPH_OBJECT_BASE cgraph_element_t element;

#define CGRAPH_OBJECT_ROOT DATA_TYPE data;

/**property inheritance of data and structure types */
#define CGRAPH_DATA_BASE cgraph_size_t size, len;
#define CGRAPH_SIZE(x) ((NULL != (x)) ? (x)->size : 0)
#define CGRAPH_LEN(x) ((NULL != (x)) ? (x)->len : 0)

#if (CGRAPH_STDC_VERSION >= 199901L)
#define CGRAPH_DATA_ROOT DATA_TYPE *data, root[];
#else
#define CGRAPH_DATA_ROOT DATA_TYPE *data, *root;
#endif /**CGRAPH_STDC_VERSION */

#define CGRAPH_STRUCTURE_BASE                                                  \
  CGRAPH_DATA_BASE                                                             \
  cgraph_element_t element;

#define CGRAPH_STRUCTURE_ROOT DATA_TYPE data, root;

#if defined(TYPE_MATRIX) || defined(TYPE_BIGMAT) || defined(TYPE_MOBJECT) ||   \
    defined(TYPE_SPAMAT)
#define CGRAPH_MATRIX_INDEXES cgraph_size_t row, column;

#define MATRIX_ROW(x) ((NULL != (x)) ? (x)->row : 0)
#define MATRIX_COLUMN(x) ((NULL != (x)) ? (x)->column : 0)
#elif defined(TYPE_MATRIX3D) || defined(TYPE_BIGMAT3D) ||                      \
    defined(TYPE_M3OBJECT) || defined(TYPE_SPAMAT3D)
#define CGRAPH_MATRIX3D_INDEXES cgraph_size_t index_i, index_j, index_k;

#define MATRIX3D_INDEX_I(x) ((NULL != (x)) ? (x)->index_i : 0)
#define MATRIX3D_INDEX_J(x) ((NULL != (x)) ? (x)->index_j : 0)
#define MATRIX3D_INDEX_K(x) ((NULL != (x)) ? (x)->index_k : 0)
#endif

/**copyed memory size without pointer memory size */
#ifndef TYPE_WITH_DATA
#define COPY_SIZE (sizeof(TYPE))
#elif defined(TYPE_OBJECT) || defined(TYPE_HOBJECT) ||                         \
    defined(TYPE_GOBJECT) || defined(TYPE_MOBJECT) || defined(TYPE_M3OBJECT)
#define COPY_SIZE (sizeof(TYPE) - sizeof(DATA_TYPE *))
#elif ID <= CGRAPH_DTYPE_PTR_MAX
#define COPY_SIZE (sizeof(TYPE) - __CGRAPH_TYPE_PTRSIZE * sizeof(DATA_TYPE *))
#else
#define COPY_SIZE (sizeof(TYPE) - 2 * sizeof(DATA_TYPE *))
#endif

#if defined(TYPE_OBJECT) || defined(TYPE_HOBJECT) || defined(TYPE_GOBJECT) ||  \
    defined(TYPE_MOBJECT) || defined(TYPE_M3OBJECT)

#define ADD(a, b, c) __CGRAPH_UNDEFINED
#define SUB(a, b, c) __CGRAPH_UNDEFINED
#define MUL(a, b, c) __CGRAPH_UNDEFINED
#define DIV(a, b, c) __CGRAPH_UNDEFINED
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define EQ(a, b) __CGRAPH_UNDEFINED
#define NE(a, b) __CGRAPH_UNDEFINED
#define GR(a, b) __CGRAPH_UNDEFINED
#define GE(a, b) __CGRAPH_UNDEFINED
#define LS(a, b) __CGRAPH_UNDEFINED
#define LE(a, b) __CGRAPH_UNDEFINED

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_BOOL)
#define DATA_TEST(a) (!((~EPSILON) & (a)))
#define DATA_TOBOOL(a) ((a)&CGRAPH_BOOL_EPS)
#define DATA_TOLOGIC(a) ((a)&CGRAPH_LOGIC_EPS)
#define DATA_ISBOOL(a) (!((~CGRAPH_BOOL_EPS) & (a)))
#define DATA_ISLOGIC(a) (!((~CGRAPH_LOGIC_EPS) & (a)))

#define ADD(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) || ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define SUB(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_FALSE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define MUL(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define DIV(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define DIVF(a, b, c)                                                          \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define INT(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define MOD(a, b, c) (SUB((a), INT(a, b)))

#define EQ(a, b) ((a) == (b))
#define NE(a, b) ((a) != (b))
#define GR(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))
#define LS(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))

#define CEIL(a, b) ceil((a))
#define FLOOR(a, b) floor((a))
#define POW(a, b) (((b) == CGRAPH_FALSE) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define ABS(a, b) ((a))
#define SIN(a, b) sin((a))
#define COS(a, b) cos((a))
#define TAN(a, b) tan((a))
#define ASIN(a, b) asin((a))
#define ACOS(a, b) acos((a))
#define ATAN(a, b) atan2((a))
#define SINH(a, b) sinh((a))
#define COSH(a, b) cosh((a))
#define TANH(a, b) tanh((a))
#define LOG(a, b) log((a))
#define LOG2(a, b) (log((a)) / log(2.0))
#define LOG10(a, b) log10((a))
#define EXP(a, b) exp((a))
#define SQRT(a, b) sqrt((a))

#elif defined(TYPE_LOGIC)
#define DATA_TEST(a) (!((~EPSILON) & (a)))
#define DATA_TOBOOL(a) ((a)&CGRAPH_BOOL_EPS)
#define DATA_TOLOGIC(a) ((a)&CGRAPH_LOGIC_EPS)
#define DATA_ISBOOL(a) (!((~CGRAPH_BOOL_EPS) & (a)))
#define DATA_ISLOGIC(a) (!((~CGRAPH_LOGIC_EPS) & (a)))

#define ADD(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) || ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define SUB(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_FALSE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define MUL(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define DIV(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define DIVF(a, b, c)                                                          \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define INT(a, b, c)                                                           \
  ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define MOD(a, b, c) (SUB((a), INT(a, b)))

#define EQ(a, b) ((DATA_ISBOOL(a) && DATA_ISBOOL(b)) ? (a) == (b) : CGRAPH_LX)
#define NE(a, b) ((DATA_ISBOOL(a) && DATA_ISBOOL(b)) ? (a) != (b) : CGRAPH_LX)
#define GR(a, b) ((DATA_ISBOOL(a) && DATA_ISBOOL(b)) ? (a) > (b) : CGRAPH_LX)
#define GE(a, b) ((DATA_ISBOOL(a) && DATA_ISBOOL(b)) ? (a) >= (b) : CGRAPH_LX)
#define LS(a, b) ((DATA_ISBOOL(a) && DATA_ISBOOL(b)) ? (a) < (b) : CGRAPH_LX)
#define LE(a, b) ((DATA_ISBOOL(a) && DATA_ISBOOL(b)) ? (a) <= (b) : CGRAPH_LX)

#define CEIL(a, b) ceil((a))
#define FLOOR(a, b) floor((a))
#define POW(a, b) (((b) == CGRAPH_FALSE) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define ABS(a, b) ((a))
#define SIN(a, b) sin((a))
#define COS(a, b) cos((a))
#define TAN(a, b) tan((a))
#define ASIN(a, b) asin((a))
#define ACOS(a, b) acos((a))
#define ATAN(a, b) atan2((a))
#define SINH(a, b) sinh((a))
#define COSH(a, b) cosh((a))
#define TANH(a, b) tanh((a))
#define LOG(a, b) log((a))
#define LOG2(a, b) (log((a)) / log(2.0))
#define LOG10(a, b) log10((a))
#define EXP(a, b) exp((a))
#define SQRT(a, b) sqrt((a))

#elif defined(TYPE_INT) || defined(TYPE_LONG) || defined(TYPE_INT8) ||         \
    defined(TYPE_INT16) || defined(TYPE_INT32) || defined(TYPE_INT64)
#define DATA_TEST(a) ((DATA_MIN != (a)) && (DATA_MAX != (a)))
#define DATA_TOBOOL(a) ((a)&CGRAPH_BOOL_EPS)
#define DATA_TOLOGIC(a) ((a)&CGRAPH_LOGIC_EPS)
#define DATA_ISBOOL(a) (!((~CGRAPH_BOOL_EPS) & (a)))
#define DATA_ISLOGIC(a) (!((~CGRAPH_LOGIC_EPS) & (a)))

#define ADD(a, b, c) ((a) + (b))
#define SUB(a, b, c) ((a) - (b))
#define MUL(a, b, c) ((a) * (b))
#define DIV(a, b, c) ((a) / (b))
#define DIVF(a, b, c) (1.0 * (a) / (b))
#define INT(a, b, c) ((a) / (b))
#define MOD(a, b, c) ((a) % (b))

#define EQ(a, b) ((a) == (b))
#define NE(a, b) ((a) != (b))
#define GR(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))
#define LS(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))

#define CEIL(a) (a)
#define FLOOR(a) (a)
#define POW(a, b) pow((a), (b))
#define ABS(a) CGRAPH_ABS((a))
#define SIN(a) sin((a))
#define COS(a) cos((a))
#define TAN(a) tan((a))
#define ASIN(a) asin((a))
#define ACOS(a) acos((a))
#define ATAN(a) atan2((a))
#define SINH(a) sinh((a))
#define COSH(a) cosh((a))
#define TANH(a) tanh((a))
#define LOG(a) log((a))
#define LOG2(a) (log((a)) / log(2.0))
#define LOG10(a) log10((a))
#define EXP(a) exp((a))
#define SQRT(a) sqrt((a))

#elif defined(TYPE_FLOAT32) || defined(TYPE_FLOAT64) || defined(TYPE_FLOAT128)
#if (CGRAPH_STDC_VERSION >= 199901L) && defined(_MATH_H_)
#define DATA_TEST(a) isnormal((a))
#define DATA_ISNAN(a) isnan((a))
#define DATA_ISPINF(a) (isinf((a)) > 0)
#define DATA_ISNINF(a) (isinf((a)) < 0)
#define DATA_ISINF(a) isinf((a))
#define DATA_ISPOS(a) signbit((a))
#define DATA_ISNEG(a) (!signbit((a)))
#else
#define DATA_TEST(a) ((MIN < (a)) && (MAX > (a)))
#define DATA_ISNAN(a) ((a) != (a))
#define DATA_ISPINF(a) (MAX < (a))
#define DATA_ISNINF(a) (MIN > (a))
#define DATA_ISINF(a) (DATA_ISPINF(a) || DATA_ISNINF(a))
#define DATA_ISPOS(a) (!FUNCTION(NAME, signbit)((a)))
#define DATA_ISNEG(a) FUNCTION(NAME, signbit)((a))
#endif /**CGRAPH_STDC_VERSION */

#define ADD(a, b, c) ((a) + (b))
#define SUB(a, b, c) ((a) - (b))
#define MUL(a, b, c) ((a) * (b))
#define DIV(a, b, c) ((a) / (b))
#define DIVF(a, b, c) ((a) / (b))
#define INT(a, b, c) FUNCTION(NAME, int)((a), (b))
#define FEXP(a) FUNCTION(NAME, fexp)((a))

#if defined(TYPE_FLOAT32) && (CGRAPH_STDC_VERSION >= 199901L)
#define TYPE_PTR TYPE
#define FREXP(a, b, c) frexpf((a), (b))
#define FMOD(a, b, c) fmodf((a), (b))
#define MODF(a, b, c) modff((a), (b))
#define MOD(a, b, c) fmodf((a), (b))

#define EQ(a, b) (fabsf((a) - (b)) < EPSILON)
#define NE(a, b) (fabsf((a) - (b)) > EPSILON)
#define GR(a, b) (((a) - (b)) > EPSILON)
#define GE(a, b) (((a) - (b)) > (-EPSILON))
#define LS(a, b) (((a) - (b)) < (-EPSILON))
#define LE(a, b) (((a) - (b)) < EPSILON)

#define CEIL(a) ceilf((a))
#define FLOOR(a) floorf((a))
#define POW(a, b) powf((a), (b))
#define ABS(a) fabsf((a))
#define SIN(a) sinf((a))
#define COS(a) cosf((a))
#define TAN(a) tanf((a))
#define ASIN(a) asinf((a))
#define ACOS(a) acosf((a))
#define ATAN(a) atan2f((a))
#define SINH(a) sinhf((a))
#define COSH(a) coshf((a))
#define TANH(a) tanhf((a))
#define LOG(a) logf((a))
#define LOG2(a) (logf((a)) / logf(2.0))
#define LOG10(a) log10f((a))
#define EXP(a) expf((a))
#define SQRT(a) sqrtf((a))
#elif defined(TYPE_FLOAT128) && defined(CGRAPH_WITH_FLOAT128)
#define TYPE_PTR TYPE
#define FREXP(a, b, c) frexpl((a), (b))
#define FMOD(a, b, c) fmodl((a), (b))
#define MODF(a, b, c) modfl((a), (b))
#define MOD(a, b, c) fmodl((a), (b))

#define EQ(a, b) (fabsl((a) - (b)) < EPSILON)
#define NE(a, b) (fabsl((a) - (b)) > EPSILON)
#define GR(a, b) (((a) - (b)) > EPSILON)
#define GE(a, b) (((a) - (b)) > (-EPSILON))
#define LS(a, b) (((a) - (b)) < (-EPSILON))
#define LE(a, b) (((a) - (b)) < EPSILON)

#define CEIL(a) ceill((a))
#define FLOOR(a) floorl((a))
#define POW(a, b) powl((a), (b))
#define ABS(a) fabsl((a))
#define SIN(a) sinl((a))
#define COS(a) cosl((a))
#define TAN(a) tanl((a))
#define ASIN(a) asinl((a))
#define ACOS(a) acosl((a))
#define ATAN(a) atan2l((a))
#define SINH(a) sinhl((a))
#define COSH(a) coshl((a))
#define TANH(a) tanhl((a))
#define LOG(a) logl((a))
#define LOG2(a) (logl((a)) / logl(2.0))
#define LOG10(a) log10l((a))
#define EXP(a) expl((a))
#define SQRT(a) sqrtl((a))
#else
#define TYPE_PTR ARG
#define FREXP(a, b, c) frexp((a), (b))
#define FMOD(a, b, c) fmod((a), (b))
#define MODF(a, b, c) modf((a), (b))
#define MOD(a, b, c) fmod((a), (b))

#define EQ(a, b) (fabs((a) - (b)) < EPSILON)
#define NE(a, b) (fabs((a) - (b)) > EPSILON)
#define GR(a, b) (((a) - (b)) > EPSILON)
#define GE(a, b) (((a) - (b)) > (-EPSILON))
#define LS(a, b) (((a) - (b)) < (-EPSILON))
#define LE(a, b) (((a) - (b)) < EPSILON)

#define CEIL(a) ceil((a))
#define FLOOR(a) floor((a))
#define POW(a, b) pow((a), (b))
#define ABS(a) fabs((a))
#define SIN(a) sin((a))
#define COS(a) cos((a))
#define TAN(a) tan((a))
#define ASIN(a) asin((a))
#define ACOS(a) acos((a))
#define ATAN(a) atan2((a))
#define SINH(a) sinh((a))
#define COSH(a) cosh((a))
#define TANH(a) tanh((a))
#define LOG(a) log((a))
#define LOG2(a) (log((a)) / log(2.0))
#define LOG10(a) log10((a))
#define EXP(a) exp((a))
#define SQRT(a) sqrt((a))
#endif

#elif defined(TYPE_TIME)

#define EQ(a, b)                                                               \
  FUNCTION(NAME, eq)                                                           \
  ((a), (b))
#define NE(a, b)                                                               \
  FUNCTION(NAME, ne)                                                           \
  ((a), (b))
#define GR(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((a), (b))
#define GE(a, b)                                                               \
  FUNCTION(NAME, ge)                                                           \
  ((a), (b))
#define LS(a, b)                                                               \
  FUNCTION(NAME, ls)                                                           \
  ((a), (b))
#define LE(a, b)                                                               \
  FUNCTION(NAME, le)                                                           \
  ((a), (b))

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add1)                                                         \
  ((a), (b))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub1)                                                         \
  ((a), (b))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul1)                                                         \
  ((a), (b))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div1)                                                         \
  ((a), (b))
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_COMPLEX)
#define DATA_EQ(a, b) (fabs((a) - (b)) < DATA_EPSILON)
#define DATA_NE(a, b) (fabs((a) - (b)) > DATA_EPSILON)
#define DATA_GR(a, b) (((a) - (b)) > DATA_EPSILON)
#define DATA_GE(a, b) (DATA_GR(a, b) || DATA_EQ(a, b))
#define DATA_LS(a, b) (((b) - (a)) > DATA_EPSILON)
#define DATA_LE(a, b) (DATA_LS(a, b) || DATA_EQ(a, b))

#if (CGRAPH_STDC_VERSION >= 199901L) && defined(_MATH_H_)
#define DATA_TEST(a) (isnormal(COMPLEX_REAL(a)) && isnormal(COMPLEX_IMAG(a)))
#define DATA_ISNAN(a) (isnan(COMPLEX_REAL(a)) || isnan(COMPLEX_IMAG(a)))
#define DATA_ISPINF(a)                                                         \
  ((0 < isinf(COMPLEX_REAL(a))) || (0 < isinf(COMPLEX_IMAG(a))))
#define DATA_ISNINF(a)                                                         \
  ((0 > isinf(COMPLEX_REAL(a))) || (0 > isinf(COMPLEX_IMAG(a))))
#define DATA_ISINF(a) ((!isinf(COMPLEX_REAL(a))) || (!isinf(COMPLEX_IMAG(a))))
#define DATA_ISPOS(a) (signbit(COMPLEX_REAL(a)) && signbit(COMPLEX_IMAG(a)))
#define DATA_ISNEG(a)                                                          \
  ((!signbit(COMPLEX_REAL(a))) && (!signbit(COMPLEX_IMAG(a))))
#else
#define DATA_TEST(a)                                                           \
  ((DATA_MIN < COMPLEX_REAL(a)) && (DATA_MAX > COMPLEX_REAL(a)) &&             \
   (DATA_MIN < COMPLEX_IMAG(a)) && (DATA_MAX > COMPLEX_IMAG(a)))
#define DATA_ISNAN(a)                                                          \
  ((COMPLEX_REAL(a) != COMPLEX_REAL(a)) || (COMPLEX_IMAG(a) != COMPLEX_IMAG(a)))
#define DATA_ISPINF(a)                                                         \
  ((DATA_MAX < COMPLEX_REAL(a)) || (DATA_MAX < COMPLEX_IMAG(a)))
#define DATA_ISNINF(a)                                                         \
  ((DATA_MIN > COMPLEX_REAL(a)) || (DATA_MIN > COMPLEX_IMAG(a)))
#define DATA_ISINF(a) (DATA_ISPINF(a) || DATA_ISNINF(a))
#define DATA_ISPOS(a)                                                          \
  (DATA_GR(COMPLEX_REAL(a), 0.0) && DATA_GR(COMPLEX_IMAG(a), 0.0))
#define DATA_ISNEG(a)                                                          \
  (DATA_LS(COMPLEX_REAL(a), 0.0) && DATA_LS(COMPLEX_IMAG(a), 0.0))
#endif

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add)                                                          \
  ((a), (b))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub)                                                          \
  ((a), (b))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul)                                                          \
  ((a), (b))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, mod)                                                          \
  ((a), (b))
#define DIVF(a, b, c)                                                          \
  FUNCTION(NAME, div)                                                          \
  ((a), (b))
#define INT(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b))
#define MOD(a, b, c)                                                           \
  FUNCTION(NAME, mod)                                                          \
  ((a), (b))

#define EQ(a, b)                                                               \
  (DATA_EQ(COMPLEX_REAL(a), COMPLEX_REAL(b)) &&                                \
   DATA_EQ(COMPLEX_IMAG(a), COMPLEX_IMAG(b)))
#define NE(a, b)                                                               \
  (DATA_NE(COMPLEX_REAL(a), COMPLEX_REAL(b)) ||                                \
   DATA_NE(COMPLEX_IMAG(a), COMPLEX_IMAG(b)))
#define GR(a, b) DATA_GR(COMPLEX_MAG2(a), COMPLEX_MAG2(b))
#define GE(a, b) DATA_GE(COMPLEX_MAG2(a), COMPLEX_MAG2(b))
#define LS(a, b) DATA_LS(COMPLEX_MAG2(a), COMPLEX_MAG2(b))
#define LE(a, b) DATA_LE(COMPLEX_MAG2(a), COMPLEX_MAG2(b))

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_FRACTION)
#define DATA_TEST(a) ((0 != FRACTION_DEN(a)))
#define DATA_ISNAN(a) ((0 == FRACTION_DEN(a)) && (0 == FRACTION_NUM(a)))
#define DATA_ISPINF(a) ((0 == FRACTION_DEN(a)) && (0 < FRACTION_NUM(a)))
#define DATA_ISNINF(a) ((0 == FRACTION_DEN(a)) && (0 > FRACTION_NUM(a)))
#define DATA_ISINF(a) (0 == FRACTION_DEN(a))
#define DATA_ISPOS(a)                                                          \
  (((0 < FRACTION_DEN(a)) && (0 < FRACTION_NUM(a))) ||                         \
   ((0 > FRACTION_DEN(a)) && (0 > FRACTION_NUM(a))))
#define DATA_ISNEG(a)                                                          \
  (((0 < FRACTION_DEN(a)) && (0 > FRACTION_NUM(a))) ||                         \
   ((0 > FRACTION_DEN(a)) && (0 < FRACTION_NUM(a))))

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add)                                                          \
  ((a), (b))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub)                                                          \
  ((a), (b))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul)                                                          \
  ((a), (b))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b))
#define DIVF(a, b, c)                                                          \
  FUNCTION(NAME, div)                                                          \
  ((a), (b))
#define INT(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b))
#define MOD(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b))

#define EQ(a, b)                                                               \
  ((FRACTION_NUM(a) == FRACTION_NUM(b)) && (FRACTION_DEN(a) == FRACTION_DEN(b)))
#define NE(a, b)                                                               \
  ((FRACTION_NUM(a) != FRACTION_NUM(b)) || (FRACTION_DEN(a) != FRACTION_DEN(b)))
#define GR(a, b)                                                               \
  ((FRACTION_NUM(a) * FRACTION_DEN(b)) > (FRACTION_NUM(b) * FRACTION_DEN(a)))
#define GE(a, b)                                                               \
  ((FRACTION_NUM(a) * FRACTION_DEN(b)) >= (FRACTION_NUM(b) * FRACTION_DEN(a)))
#define LS(a, b)                                                               \
  ((FRACTION_NUM(a) * FRACTION_DEN(b)) < (FRACTION_NUM(b) * FRACTION_DEN(a)))
#define LE(a, b)                                                               \
  ((FRACTION_NUM(a) * FRACTION_DEN(b)) <= (FRACTION_NUM(b) * FRACTION_DEN(a)))

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_BIGINT)

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add)                                                          \
  ((a), (b), (c))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub)                                                          \
  ((a), (b), (c))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul)                                                          \
  ((a), (b), (c))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b), (c))
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define EQ(a, b)                                                               \
  FUNCTION(NAME, eq)                                                           \
  ((a), (b))
#define NE(a, b)                                                               \
  FUNCTION(NAME, ne)                                                           \
  ((a), (b))
#define GR(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((a), (b))
#define GE(a, b)                                                               \
  FUNCTION(NAME, ge)                                                           \
  ((a), (b))
#define LS(a, b)                                                               \
  FUNCTION(NAME, ls)                                                           \
  ((a), (b))
#define LE(a, b)                                                               \
  FUNCTION(NAME, le)                                                           \
  ((a), (b))

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_BIGNUM)

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add)                                                          \
  ((a), (b), (c))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub)                                                          \
  ((a), (b), (c))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul)                                                          \
  ((a), (b), (c))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b), (c))
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define EQ(a, b)                                                               \
  FUNCTION(NAME, eq)                                                           \
  ((a), (b))
#define NE(a, b)                                                               \
  FUNCTION(NAME, ne)                                                           \
  ((a), (b))
#define GR(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((a), (b))
#define GE(a, b)                                                               \
  FUNCTION(NAME, ge)                                                           \
  ((a), (b))
#define LS(a, b)                                                               \
  FUNCTION(NAME, ls)                                                           \
  ((a), (b))
#define LE(a, b)                                                               \
  FUNCTION(NAME, le)                                                           \
  ((a), (b))

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_STRING)

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add)                                                          \
  ((a), (b), (c))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub)                                                          \
  ((a), (b), (c))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul)                                                          \
  ((a), (b), (c))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b), (c))
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define EQ(a, b)                                                               \
  FUNCTION(NAME, eq)                                                           \
  ((a), (b))
#define NE(a, b)                                                               \
  FUNCTION(NAME, ne)                                                           \
  ((a), (b))
#define GR(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((a), (b))
#define GE(a, b)                                                               \
  FUNCTION(NAME, ge)                                                           \
  ((a), (b))
#define LS(a, b)                                                               \
  FUNCTION(NAME, ls)                                                           \
  ((a), (b))
#define LE(a, b)                                                               \
  FUNCTION(NAME, le)                                                           \
  ((a), (b))

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_BITSET)

#define ADD(a, b, c)                                                           \
  FUNCTION(NAME, add)                                                          \
  ((a), (b), (c))
#define SUB(a, b, c)                                                           \
  FUNCTION(NAME, sub)                                                          \
  ((a), (b), (c))
#define MUL(a, b, c)                                                           \
  FUNCTION(NAME, mul)                                                          \
  ((a), (b), (c))
#define DIV(a, b, c)                                                           \
  FUNCTION(NAME, div)                                                          \
  ((a), (b), (c))
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define EQ(a, b)                                                               \
  FUNCTION(NAME, eq)                                                           \
  ((a), (b))
#define NE(a, b)                                                               \
  FUNCTION(NAME, ne)                                                           \
  ((a), (b))
#define GR(a, b)                                                               \
  FUNCTION(NAME, gr)                                                           \
  ((a), (b))
#define GE(a, b)                                                               \
  FUNCTION(NAME, ge)                                                           \
  ((a), (b))
#define LS(a, b)                                                               \
  FUNCTION(NAME, ls)                                                           \
  ((a), (b))
#define LE(a, b)                                                               \
  FUNCTION(NAME, le)                                                           \
  ((a), (b))

#define ABS(a) FUNCTION(NAME, abs)((a))
#define CEIL(a, b) FUNCTION(NAME, ceil)((a), (b))
#define FLOOR(a, b) FUNCTION(NAME, floor)((a), (b))
#define POW(a, b) FUNCTION(NAME, pow)((a), (b))
#define SIN(a, b) FUNCTION(NAME, sin)((a), (b))
#define COS(a, b) FUNCTION(NAME, cos)((a), (b))
#define TAN(a, b) FUNCTION(NAME, tan)((a), (b))
#define ASIN(a, b) FUNCTION(NAME, asin)((a), (b))
#define ACOS(a, b) FUNCTION(NAME, acos)((a), (b))
#define ATAN(a, b) FUNCTION(NAME, atan)((a), (b))
#define SINH(a, b) FUNCTION(NAME, sinh)((a), (b))
#define COSH(a, b) FUNCTION(NAME, cosh)((a), (b))
#define TANH(a, b) FUNCTION(NAME, tanh)((a), (b))
#define LOG(a, b) FUNCTION(NAME, log)((a), (b))
#define LOG2(a, b) FUNCTION(NAME, log2)((a), (b))
#define LOG10(a, b) FUNCTION(NAME, log10)((a), (b))
#define EXP(a, b) FUNCTION(NAME, exp)((a), (b))
#define SQRT(a, b) FUNCTION(NAME, sqrt)((a), (b))

#elif defined(TYPE_VECTOR) || defined(TYPE_MATRIX) || defined(TYPE_BIGMAT) ||  \
    defined(TYPE_SPAMAT) || defined(TYPE_MATRIX3D) ||                          \
    defined(TYPE_BIGMAT3D) || defined(TYPE_SPAMAT3D) ||                        \
    defined(TYPE_DFRAME) || defined(TYPE_DICT) || defined(TYPE_SET) ||         \
    defined(TYPE_LIST) || defined(TYPE_TREE) || defined(TYPE_QUEUE) ||         \
    defined(TYPE_STACK)

#if defined(CGRAPH_OBJECT)
#define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)
#elif defined(CGRAPH_HOBJECT)
#define OBJECT(type, opt) CGRAPH_HOBJECT(type, opt)
#elif defined(CGRAPH_MOBJECT)
#define OBJECT(type, opt) CGRAPH_MOBJECT(type, opt)
#elif defined(CGRAPH_M3OBJECT)
#define OBJECT(type, opt) CGRAPH_M3OBJECT(type, opt)
#endif

#define ADD(a, b, c) __CGRAPH_UNDEFINED
#define SUB(a, b, c) __CGRAPH_UNDEFINED
#define MUL(a, b, c) __CGRAPH_UNDEFINED
#define DIV(a, b, c) __CGRAPH_UNDEFINED
#define DIVF(a, b, c) __CGRAPH_UNDEFINED
#define INT(a, b, c) __CGRAPH_UNDEFINED
#define MOD(a, b, c) __CGRAPH_UNDEFINED

#define EQ(a, b) __CGRAPH_UNDEFINED
#define NE(a, b) __CGRAPH_UNDEFINED
#define GR(a, b) __CGRAPH_UNDEFINED
#define GE(a, b) __CGRAPH_UNDEFINED
#define LS(a, b) __CGRAPH_UNDEFINED
#define LE(a, b) __CGRAPH_UNDEFINED
#endif

#ifdef TYPE_WITH_DATA

#define ASSIGN(a, b)                                                           \
  FUNCTION(NAME, init)                                                         \
  ((a), (b), -1)

#define SWAP(a, b)                                                             \
  do {                                                                         \
    TYPE *tmp = (a);                                                           \
    (a) = (b);                                                                 \
    (b) = tmp;                                                                 \
  } while (0)
#define ROL3(a, b, c)                                                          \
  do {                                                                         \
    TYPE *tmp = (a);                                                           \
    (a) = (b);                                                                 \
    (b) = (c);                                                                 \
    (c) = tmp;                                                                 \
  } while (0)
#define ROR3(a, b, c)                                                          \
  do {                                                                         \
    TYPE *tmp = (c);                                                           \
    (c) = (b);                                                                 \
    (b) = (a);                                                                 \
    (a) = tmp;                                                                 \
  } while (0)
#define ROL4(a, b, c, d)                                                       \
  do {                                                                         \
    TYPE *tmp = (a);                                                           \
    (a) = (b);                                                                 \
    (b) = (c);                                                                 \
    (c) = (d);                                                                 \
    (d) = tmp;                                                                 \
  } while (0)
#define ROR4(a, b, c, d)                                                       \
  do {                                                                         \
    TYPE *tmp = (d);                                                           \
    (d) = (c);                                                                 \
    (c) = (b);                                                                 \
    (b) = (a);                                                                 \
    (a) = tmp;                                                                 \
  } while (0)

#define DATA_SWAP(a, b)                                                        \
  do {                                                                         \
    DATA_TYPE tmp = (a);                                                       \
    (a) = (b);                                                                 \
    (b) = tmp;                                                                 \
  } while (0)

#else

#define ASSIGN(a, b) (b)

#define SWAP(a, b)                                                             \
  do {                                                                         \
    TYPE tmp = a;                                                              \
    a = b;                                                                     \
    b = tmp;                                                                   \
  } while (0)
#define ROL3(a, b, c)                                                          \
  do {                                                                         \
    TYPE tmp = (a);                                                            \
    (a) = (b);                                                                 \
    (b) = (c);                                                                 \
    (c) = tmp;                                                                 \
  } while (0)
#define ROR3(a, b, c)                                                          \
  do {                                                                         \
    TYPE tmp = (c);                                                            \
    (c) = (b);                                                                 \
    (b) = (a);                                                                 \
    (a) = tmp;                                                                 \
  } while (0)
#define ROL4(a, b, c, d)                                                       \
  do {                                                                         \
    TYPE tmp = (a);                                                            \
    (a) = (b);                                                                 \
    (b) = (c);                                                                 \
    (c) = (d);                                                                 \
    (d) = tmp;                                                                 \
  } while (0)
#define ROR4(a, b, c, d)                                                       \
  do {                                                                         \
    TYPE tmp = (d);                                                            \
    (d) = (c);                                                                 \
    (c) = (b);                                                                 \
    (b) = (a);                                                                 \
    (a) = tmp;                                                                 \
  } while (0)

#endif