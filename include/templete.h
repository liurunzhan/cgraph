#if defined(TYPE)
	#error before <templete.h> is included, no other <templete.h> is included without <templete_off.h>
#endif

#define CONCAT1V(a) # a
#define CONCAT1(a) CONCAT1V(a)
#define CONCAT2V(a,b) a ## _ ## b 
#define CONCAT2(a,b) CONCAT2V(a,b)
#define CONCAT3V(a,b,c) a ## _ ## b ## _ ## c
#define CONCAT3(a,b,c) CONCAT3V(a,b,c)
#define CONCAT4V(a,b,c,d) a ## _ ## b ## _ ## c ## _ ## d
#define CONCAT4(a,b,c,d) CONCAT4V(a,b,c,d)

#define STRING(a) CONCAT1(a)
#define FUNCTION(a, b) CONCAT3(cgraph, a, b)
#define STRUCT(a) CONCAT3(_cgraph, a, struct_)

/*
DATA AND STRUCTURE TYPE TEMPLETE : 

#define TYPE
#define ID
#define NAME
#define OUT_FORMAT
#define UTYPE
#define ZERO
#define ONE
#define ONES
#define BITS
#define MIN
#define MAX
#define EPSILON
#define EPSILON_LEN

#define DATA_TYPE
#define DATA_ID
#define DATA_UTYPE
#define DATA_ZERO
#define DATA_ONE
#define DATA_ONES
#define DATA_BITS
#define DATA_MIN
#define DATA_MAX
#define DATA_EPSILON
#define DATA_EPSILON_LEN
*/

#if defined(TYPE_OBJECT)
  #define TYPE cgraph_object_t
  #define ID CGRAPH_OBJECT_T
  #define NAME object
  #define OUT_FORMAT "ld"
  #define ZERO NULL
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_stl_t

  #define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)
  
#elif defined(TYPE_HOBJECT)
  #define TYPE cgraph_hobject_t
  #define ID CGRAPH_HOBJECT_T
  #define NAME hobject
  #define OUT_FORMAT "ld"
  #define ZERO NULL
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_stl_t
  
  #define OBJECT(type, opt) CGRAPH_HOBJECT(type, opt)
  
#elif defined(TYPE_POBJECT)
  #define TYPE cgraph_pobject_t
  #define ID CGRAPH_POBJECT_T
  #define NAME pobject
  #define OUT_FORMAT "ld"
  #define ZERO NULL
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_stl_t
  
  #define OBJECT(type, opt) CGRAPH_POBJECT(type, opt)

#elif defined(TYPE_SOBJECT)
  #define TYPE cgraph_sobject_t
  #define ID CGRAPH_SOBJECT_T
  #define NAME sobject
  #define OUT_FORMAT "ld"
  #define ZERO NULL
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_stl_t
  
  #define OBJECT(type, opt) CGRAPH_SOBJECT(type, opt)
  
#elif defined(TYPE_BOOL)
  #define ARG cgraph_long_t
  #define TYPE cgraph_bool_t
  #define ID CGRAPH_BOOL_T
  #define NAME bool
  #define OUT_FORMAT "%d"
  #define UTYPE cgraph_bool_t
  #define ZERO CGRAPH_FALSE
  #define ONE CGRAPH_TRUE
  #define ONES CGRAPH_TRUE
  #define BITS CGRAPH_BOOL_BIT
  #define MIN CGRAPH_FALSE
  #define MAX CGRAPH_TRUE
  #define MSB (ONE)
  #define LSB (ONE)
  #define EPSILON CGRAPH_BOOL_EPS
  #define EPSILON_LEN CGRAPH_BOOL_BIT

#elif defined(TYPE_INT)
  #define ARG cgraph_long_t
  #define TYPE cgraph_int_t
  #define ID CGRAPH_INT_T
  #define NAME int
  #define OUT_FORMAT "%d"
  #define UTYPE cgraph_uint_t
  #define ZERO (0)
  #define ONE (1)
  #define ONES CGRAPH_INT_MIN
  #define BITS CGRAPH_INT_BIT
  #define MIN CGRAPH_INT_MIN
  #define MAX CGRAPH_INT_MAX
  #define MSB (ONE << (BITS-1))
  #define LSB (ONE)
  #define EPSILON CGRAPH_INT_EPS
  #define EPSILON_LEN CGRAPH_INT_BIT

#elif defined(TYPE_LONG)
  #define ARG cgraph_long_t
  #define TYPE cgraph_long_t
  #define ID CGRAPH_LONG_T
  #define NAME long
  #define OUT_FORMAT "%ld"
  #define UTYPE cgraph_ulong_t
  #define ZERO (0L)
  #define ONE (1L)
  #define ONES CGRAPH_LONG_MIN
  #define BITS CGRAPH_LONG_BIT
  #define MIN CGRAPH_LONG_MIN
  #define MAX CGRAPH_LONG_MAX
  #define MSB (ONE << (BITS-1))
  #define LSB (ONE)
  #define EPSILON CGRAPH_LONG_EPS
  #define EPSILON_LEN CGRAPH_LONG_BIT
  
#elif defined(TYPE_INT8)
  #define ARG cgraph_long_t
  #define TYPE cgraph_int8_t
  #define ID CGRAPH_INT8_T
  #define NAME int8
  #define OUT_FORMAT "%d"
  #define UTYPE cgraph_uint8_t
  #define ZERO (0)
  #define ONE (1)
  #define ONES CGRAPH_INT8_MIN
  #define BITS CGRAPH_INT8_BIT
  #define MIN CGRAPH_INT8_MIN
  #define MAX CGRAPH_INT8_MAX
  #define MSB (ONE << (BITS-1))
  #define LSB (ONE)
  #define EPSILON CGRAPH_INT8_EPS
  #define EPSILON_LEN CGRAPH_INT8_BIT
  
#elif defined(TYPE_INT16)
  #define ARG cgraph_long_t
  #define TYPE cgraph_int16_t
  #define ID CGRAPH_INT16_T
  #define NAME int16
  #define OUT_FORMAT "%d"
  #define UTYPE cgraph_uint16_t
  #define ZERO (0)
  #define ONE (1)
  #define ONES CGRAPH_INT16_MIN
  #define BITS CGRAPH_INT16_BIT
  #define MIN CGRAPH_INT16_MIN
  #define MAX CGRAPH_INT16_MAX
  #define MSB (ONE << (BITS-1))
  #define LSB (ONE)
  #define EPSILON CGRAPH_INT16_EPS
  #define EPSILON_LEN CGRAPH_INT16_BIT
  
#elif defined(TYPE_INT32)
  #define ARG cgraph_long_t
  #define TYPE cgraph_int32_t
  #define ID CGRAPH_INT32_T
  #define NAME int32
  #define OUT_FORMAT "%d"
  #define UTYPE cgraph_uint32_t
  #define ZERO (0)
  #define ONE (1)
  #define ONES CGRAPH_INT32_MIN
  #define BITS CGRAPH_INT32_BIT
  #define MIN CGRAPH_INT32_MIN
  #define MAX CGRAPH_INT32_MAX
  #define MSB (ONE << (BITS-1))
  #define LSB (ONE)
  #define EPSILON CGRAPH_INT32_EPS
  #define EPSILON_LEN CGRAPH_INT32_BIT
  
#elif defined(TYPE_INT64)
  #define ARG cgraph_long_t
  #define TYPE cgraph_int64_t
  #define ID CGRAPH_INT64_T
  #define NAME int64
  #define OUT_FORMAT "%lld"
  #define UTYPE cgraph_uint64_t
  #define ZERO (0LL)
  #define ONE (1LL)
  #define ONES CGRAPH_INT64_MIN
  #define BITS CGRAPH_INT64_BIT
  #define MIN CGRAPH_INT64_MIN
  #define MAX CGRAPH_INT64_MAX
  #define MSB (ONE << (BITS-1))
  #define LSB (ONE)
  #define EPSILON CGRAPH_INT64_EPS
  #define EPSILON_LEN CGRAPH_INT64_BIT

#elif defined(TYPE_FLOAT32)
  #define ARG cgraph_float64_t
  #define TYPE cgraph_float32_t
  #define ID CGRAPH_FLOAT32_T
  #define NAME float32
  #define OUT_FORMAT "%f"
  #define ZERO (0.0)
  #define ONE (1.0)
  #define ONES (1.0)
  #define BITS CGRAPH_FLOAT32_BIT
  #define MIN CGRAPH_FLOAT32_MIN
  #define MAX CGRAPH_FLOAT32_MAX
  #define EPSILON CGRAPH_FLOAT32_EPS
  #define EPSILON_LEN CGRAPH_FLOAT32_BIT

#elif defined(TYPE_FLOAT64)
  #define ARG cgraph_float64_t
  #define TYPE cgraph_float64_t
  #define ID CGRAPH_FLOAT64_T
  #define NAME float64
  #define OUT_FORMAT "%g"
  #define ZERO (0.0)
  #define ONE (1.0)
  #define ONES (1.0)
  #define BITS CGRAPH_FLOAT64_BIT
  #define MIN CGRAPH_FLOAT64_MIN
  #define MAX CGRAPH_FLOAT64_MAX
  #define EPSILON CGRAPH_FLOAT64_EPS
  #define EPSILON_LEN CGRAPH_FLOAT64_BIT

#elif defined(TYPE_TIME)
  #define TYPE cgraph_time_t
  #define ID CGRAPH_TIME_T
  #define NAME time
  #define OUT_FORMAT "%d"
  #define ZERO (0)
  #define ONE (1)
  #define ONES {{ 1 << 26 | 1 << 22 |  1 << 17 || 1 << 12 | 1 << 6 | 1}}
  #define BITS (8*sizeof(TYPE)-1)
  #define MIN (0)
  #define MAX (1)
  #define DATA_TYPE cgraph_int32_t
  #define DATA_ID CGRAPH_INT32_T
  #define DATA_UTYPE cgraph_uint32_t
  #define DATA_ZERO (0)
  #define DATA_ONE (1)
  #define DATA_ONES (1)
  #define DATA_BITS (8*sizeof(DATA_TYPE))
  #define DATA_MIN (CGRAPH_INT32_MIN >> 1)
  #define DATA_MAX (CGRAPH_INT32_MAX >> 1)
  #define DATA_MSB (DATA_ONE << (DATA_BITS-1))
  #define DATA_LSB (DATA_ONE)
	
#elif defined(TYPE_COMPLEX)
  #define TYPE cgraph_complex_t
  #define ID CGRAPH_COMPLEX_T
  #define NAME complex
  #define OUT_FORMAT "%g"
  #define ZERO {{0.0, 0.0}}
  #define ONE {{0.0, 1.0}}
  #define ONES {{1.0, 1.0}}
  #define BITS (CGRAPH_FLOAT64_BIT*2)
  #define MIN {{CGRAPH_FLOAT64_MIN, CGRAPH_FLOAT64_MIN}}
  #define MAX {{CGRAPH_FLOAT64_MAX, CGRAPH_FLOAT64_MAX}}
  #define DATA_TYPE cgraph_float64_t
  #define DATA_ID CGRAPH_FLOAT64_T
  #define DATA_ZERO 0.0
  #define DATA_ONE 1.0
  #define DATA_ONES 1.0
  #define DATA_BITS CGRAPH_FLOAT64_BIT
  #define DATA_MIN CGRAPH_FLOAT64_MIN
  #define DATA_MAX CGRAPH_FLOAT64_MAX
  #define DATA_EPSILON CGRAPH_FLOAT64_EPS
  #define DATA_EPSILON_LEN CGRAPH_FLOAT64_BIT
  
#elif defined(TYPE_FRACTION)
  #define TYPE cgraph_fraction_t
  #define ID CGRAPH_FRACTION_T
  #define NAME fraction
  #define OUT_FORMAT "%d"
  #define ZERO {{0, 1}}
  #define ONE {{1, 1}}
  #define ONES {{CGRAPH_INT_MIN, 1}}
  #define BITS (8*sizeof(TYPE))
  #define MIN {{CGRAPH_INT_MIN, 1}}
  #define MAX {{CGRAPH_INT_MAX, 1}}
  #define EPSILON {{1, CGRAPH_INT_MAX}}
  #define EPSILON_LEN (8*sizeof(TYPE))
  #define DATA_TYPE cgraph_int_t
  #define DATA_ID CGRAPH_INT_T
  #define DATA_ZERO 0
  #define DATA_ONE 1
  #define DATA_ONES CGRAPH_INT_MIN
  #define DATA_BITS (8*sizeof(DATA_TYPE))
  #define DATA_MIN CGRAPH_INT_MIN
  #define DATA_MAX CGRAPH_INT_MAX
  #define DATA_MSB (DATA_ONE << (DATA_BITS-1))
  #define DATA_LSB (DATA_ONE)
  
#elif defined(TYPE_BIGINT)
  #define TYPE cgraph_bigint_t
  #define ID CGRAPH_BIGINT_T
  #define NAME bigint
  #define OUT_FORMAT "%u"
  #define ZERO (0)
  #define ONE (1)
  #define ONES (1)
  #define MIN (0)
  #define MAX (9)
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_uint8_t
  #define DATA_ID CGRAPH_UINT8_T
  #define DATA_UTYPE cgraph_uint8_t
  #define DATA_ZERO (0)
  #define DATA_ONE (1)
  #define DATA_ONES (1)
  #define DATA_BITS (4)
  #define DATA_MIN (0)
  #define DATA_MAX (9)
  #define DATA_MSB (1)
  #define DATA_LSB (1)
  
#elif defined(TYPE_BIGNUM)
  #define TYPE cgraph_bignum_t
  #define ID CGRAPH_BIGNUM_T
  #define NAME bignum
  #define OUT_FORMAT "%s"
  #define ZERO ("0.0")
  #define ONE ("1.0")
  #define ONES ("1")
  #define BITS (8*sizeof(TYPE))
  #define MIN ("-inf")
  #define MAX ("+inf")
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_char_t
  #define DATA_ID CGRAPH_CHAR_T
  #define DATA_BITS (8*sizeof(DATA_TYPE))
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
  #define ZERO (0)
  #define ONE (1)
  #define ONES CGRAPH_CHAR_MIN
  #define BITS (8*sizeof(TYPE))
  #define MIN CGRAPH_CHAR_MIN
  #define MAX CGRAPH_CHAR_MAX
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_char_t
  #define DATA_ID CGRAPH_CHAR_T
  #define DATA_MIN CGRAPH_CHAR_MIN
  #define DATA_MAX CGRAPH_CHAR_MAX
  #define DATA_BITS (8*sizeof(DATA_TYPE))
  #define DATA_ONES ('1')
  
#elif defined(TYPE_BITSET)
  #define TYPE cgraph_bitset_t
  #define ID CGRAPH_BITSET_T
  #define NAME bitset
  #define OUT_FORMAT "%x"
  #define ZERO (0)
  #define ONE (1)
  #define ONES (1)
  #define BITS CGRAPH_UINT8_MIN
  #define MIN  (0)
  #define MAX CGRAPH_UINT8_MIN
  #define CGRAPH_WITH_DATA
  #define DATA_TYPE cgraph_uint8_t
  #define DATA_UTYPE cgraph_uint8_t
  #define DATA_ID CGRAPH_UINT8_T
  #define DATA_ZERO 0
  #define DATA_ONE 1
  #define DATA_ONES CGRAPH_UINT8_MAX
  #define DATA_BITS (8*sizeof(DATA_TYPE))
  #define DATA_MIN CGRAPH_UINT8_MIN
  #define DATA_MAX CGRAPH_UINT8_MAX
  
#elif defined(TYPE_VECTOR)
  #define TYPE cgraph_vector_t
  #define ID CGRAPH_VECTOR_T
  #define NAME vector
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t
  
  #if defined(CGRAPH_OBJECT)
    #define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)
  #endif

#elif defined(TYPE_MATRIX)
  #define TYPE cgraph_matrix_t
  #define ID CGRAPH_MATRIX_T
  #define NAME matrix
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t
  
  #if defined(CGRAPH_OBJECT)
    #define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)
  #endif

#elif defined(TYPE_BIGMAT)
  #define TYPE cgraph_bigmat_t
  #define ID CGRAPH_BIGMAT_T
  #define NAME bigmat
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_OBJECT)
    #define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)
  #endif
  
#elif defined(TYPE_DFRAME)
  #define TYPE cgraph_dframe_t
  #define ID CGRAPH_DFRAME_T
  #define NAME dframe
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_OBJECT)
    #define OBJECT(type, opt) CGRAPH_OBJECT(type, opt)
  #endif

#elif defined(TYPE_DICT)
  #define TYPE cgraph_dict_t
  #define ID CGRAPH_DICT_T
  #define NAME dict
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t
  
  #if defined(CGRAPH_HOBJECT)
    #define OBJECT(type, opt) CGRAPH_HOBJECT(type, opt)
  #endif

#elif defined(TYPE_LIST)
  #define TYPE cgraph_list_t
  #define ID CGRAPH_LIST_T
  #define NAME list
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_POBJECT)
    #define OBJECT(type, opt) CGRAPH_POBJECT(type, opt)
  #endif
  
#elif defined(TYPE_TREE)
  #define TYPE cgraph_tree_t
  #define ID CGRAPH_TREE_T
  #define NAME tree
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_POBJECT)
    #define OBJECT(type, opt) CGRAPH_POBJECT(type, opt)
  #endif
  
#elif defined(TYPE_SET)
  #define TYPE cgraph_set_t
  #define ID CGRAPH_SET_T
  #define NAME tree
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_HOBJECT)
    #define OBJECT(type, opt) CGRAPH_HOBJECT(type, opt)
  #endif
  
#elif defined(TYPE_QUEUE)
  #define TYPE cgraph_queue_t
  #define ID CGRAPH_QUEUE_T
  #define NAME tree
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_POBJECT)
    #define OBJECT(type, opt) CGRAPH_POBJECT(type, opt)
  #endif

#elif defined(TYPE_STACK)
  #define TYPE cgraph_stack_t
  #define ID CGRAPH_STACK_T
  #define NAME tree
  #define ZERO NULL
  #define DATA_TYPE cgraph_stl_t

  #if defined(CGRAPH_POBJECT)
    #define OBJECT(type, opt) CGRAPH_POBJECT(type, opt)
  #endif
  
#else
  #error !!! UNSUPPORTED DATA TYPE !!!
#endif

/* property inheritance of object types  */
#define CGRAPH_OBJECT_BASE \
  cgraph_element_t element; \
  cgraph_size_t hash;

#define CGRAPH_OBJECT_ROOT \
  DATA_TYPE data;

/* property inheritance of data and structure types */
#define CGRAPH_DATA_BASE \
  cgraph_size_t size, len; \

#if (CGRAPH_STDC_VERSION >= 199901L)
	#define CGRAPH_DATA_ROOT \
  DATA_TYPE *data, root[];
#else
  #define CGRAPH_DATA_ROOT \
  DATA_TYPE *data, *root;
#endif /* CGRAPH_STDC_VERSION */

#define CGRAPH_STRUCTURE_BASE \
  CGRAPH_DATA_BASE \
  cgraph_size_t msize; \
	cgraph_element_t element; \

#define CGRAPH_STRUCTURE_ROOT \
  DATA_TYPE data, root;

#if defined(TYPE_OBJECT) || defined(TYPE_HOBJECT) || defined(TYPE_POBJECT) || defined(TYPE_SOBJECT)

#elif defined(TYPE_BOOL)
  #define DATA_TEST(a) (((a) == CGRAPH_TRUE) || ((a) == CGRAPH_FALSE))
  
  #define ADD(a, b, c) ((((a) == CGRAPH_TRUE) || ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
  #define SUB(a, b, c) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_FALSE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
  #define	MUL(a, b, c) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
  #define DIV(a, b, c) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
  #define INT(a, b, c) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
  #define MOD(a, b, c) (SUB((a), INT(a, b)))
  
  #define EQ(a, b) ((a) == (b))
  #define NE(a, b) ((a) != (b))
  #define GR(a, b) ((a) > (b))
  #define GE(a, b) ((a) >= (b))
  #define LS(a, b) ((a) < (b))
  #define LE(a, b) ((a) <= (b))
  
  #define POW(a, b) (((a) == CGRAPH_TRUE) ? CGRAPH_TRUE : CGRAPH_FALSE)
  #define ABS(a) ((a))
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
  
  #define EXCHNAGE(a, b) do{ TYPE tmp = (a); (a) = (b); (b) = tmp; } while(0)
  
#elif defined(TYPE_INT) || defined(TYPE_LONG) || defined(TYPE_INT8) || defined(TYPE_INT16) || defined(TYPE_INT32) || defined(TYPE_INT64)
  #define DATA_TEST(a) ((DATA_MIN != (a)) && (DATA_MAX != (a)))
  
  #define ADD(a, b, c) ((a) + (b))
  #define SUB(a, b, c) ((a) - (b))
  #define MUL(a, b, c) ((a) * (b))
  #define DIV(a, b, c) ((a) / (b))
  #define INT(a, b, c) ((a) / (b))
  #define MOD(a, b, c) ((a) % (b))
  
  #define EQ(a, b) ((a) == (b))
  #define NE(a, b) ((a) != (b))
  #define GR(a, b) ((a) > (b))
  #define GE(a, b) ((a) >= (b))
  #define LS(a, b) ((a) < (b))
  #define LE(a, b) ((a) <= (b))
  
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
  
  #define EXCHANGE(a, b) do{ TYPE tmp = (a); (a) = (b); (b) = tmp; } while(0)
  
#elif defined(TYPE_FLOAT32) || defined(TYPE_FLOAT64)
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
    #define DATA_ISPOS(a) GR((a), 0.0)
    #define DATA_ISNEG(a) LS((a), 0.0)
  #endif /* CGRAPH_STDC_VERSION */
  
  #define ADD(a, b, c) ((a) + (b))
  #define SUB(a, b, c) ((a) - (b))
  #define MUL(a, b, c) ((a) * (b))
  #define DIV(a, b, c) ((a) / (b))
  #define INT(a, b, c) (floor(DIV((a), (b), (0))))
  #define MOD(a, b, c) (fmod((a), (b)))
  
  #define EQ(a, b) (fabs((a) - (b)) < EPSILON)
  #define NE(a, b) (fabs((a) - (b)) > EPSILON)
  #define GR(a, b) (((a) - (b)) > EPSILON)
  #define GE(a, b) (((a) - (b)) > (-EPSILON))
  #define LS(a, b) (((a) - (b)) < (-EPSILON))
  #define LE(a, b) (((a) - (b)) < EPSILON)
  
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
  
  #define EXCHANGE(a, b) do{ TYPE tmp = (a); (a) = (b); (b) = tmp; }while(0)
  
#elif defined(TYPE_TIME)
  
  #define EQ(a, b) FUNCTION(NAME, eq)((a), (b))
  #define NE(a, b) FUNCTION(NAME, ne)((a), (b))
  #define GR(a, b) FUNCTION(NAME, gr)((a), (b))
  #define GE(a, b) FUNCTION(NAME, ge)((a), (b))
  #define LS(a, b) FUNCTION(NAME, ls)((a), (b))
  #define LE(a, b) FUNCTION(NAME, le)((a), (b))
  
  #define ADD(a, b, c) FUNCTION(NAME, add1t)((a), (b))
  #define SUB(a, b, c) FUNCTION(NAME, sub1t)((a), (b))
  #define MUL(a, b, c) FUNCTION(NAME, mul1t)((a), (b))
  #define DIV(a, b, c) FUNCTION(NAME, div1t)((a), (b))
  
#elif defined(TYPE_COMPLEX)
  #if (CGRAPH_STDC_VERSION >= 199901L) && defined(_MATH_H_)
    #define DATA_TEST(a) isnormal((a))
    #define DATA_ISNAN(a) isnan((a))
    #define DATA_ISPINF(a) (isinf((a)) > 0)
    #define DATA_ISNINF(a) (isinf((a)) < 0)
    #define DATA_ISINF(a) isinf((a))
    #define DATA_ISPOS(a) signbit((a))
    #define DATA_ISNEG(a) (!signbit((a)))
  #else
    #define DATA_TEST(a) ((DATA_MIN < (a)) && (DATA_MAX > (a)))
    #define DATA_ISNAN(a) ((a) != (a))
    #define DATA_ISPINF(a) (DATA_MAX < (a))
    #define DATA_ISNINF(a) (DATA_MIN > (a))
    #define DATA_ISINF(a) (DATA_ISPINF(a) || DATA_ISNINF(a))
    #define DATA_ISPOS(a) GR((a), 0.0)
    #define DATA_ISNEG(a) LS((a), 0.0)
  #endif /* CGRAPH_STDC_VERSION */
  
  #define ADD(a, b, c) FUNCTION(NAME, addc)((a), (b))
  #define SUB(a, b, c) FUNCTION(NAME, subc)((a), (b))
  #define MUL(a, b, c) FUNCTION(NAME, mulc)((a), (b))
  #define DIV(a, b, c) FUNCTION(NAME, divc)((a), (b))
  
  #define EQ(a, b) ((fabs(COMPLEX_REAL(a) - COMPLEX_REAL(b)) < DATA_EPSILON) && (fabs(COMPLEX_IMAG(a) - COMPLEX_IMAG(b)) < DATA_EPSILON))
  #define NE(a, b) ((fabs(COMPLEX_REAL(a) - COMPLEX_REAL(b)) > DATA_EPSILON) || (fabs(COMPLEX_IMAG(a) - COMPLEX_IMAG(b)) > DATA_EPSILON))
  #define GR(a, b) ((COMPLEX_MOD2(a) - COMPLEX_MOD2(b)) > DATA_EPSILON)
  #define GE(a, b) ((COMPLEX_MOD2(a) - COMPLEX_MOD2(b)) > (-DATA_EPSILON))
  #define LS(a, b) ((COMPLEX_MOD2(a) - COMPLEX_MOD2(b)) < (-DATA_EPSILON))
  #define LE(a, b) ((COMPLEX_MOD2(a) - COMPLEX_MOD2(b)) < DATA_EPSILON)
  
  #define EXCHANGE(a, b) do{ TYPE tmp; \
   	COMPLEX_REAL(tmp) = COMPLEX_REAL(a);   COMPLEX_IMAG(tmp) = COMPLEX_IMAG(a); \
   	COMPLEX_REAL(a)   = COMPLEX_REAL(b);   COMPLEX_IMAG(a)   = COMPLEX_IMAG(b); \
    COMPLEX_REAL(b)   = COMPLEX_REAL(tmp); COMPLEX_IMAG(b)   = COMPLEX_IMAG(tmp); }while(0)
  
#elif defined(TYPE_FRACTION)
  #define DATA_TEST(a) (0 == (a))
  
  #define ADD(a, b, c) FUNCTION(NAME, addf)((a), (b))
  #define SUB(a, b, c) FUNCTION(NAME, subf)((a), (b))
  #define MUL(a, b, c) FUNCTION(NAME, mulf)((a), (b))
  #define DIV(a, b, c) FUNCTION(NAME, divf)((a), (b))
  
  #define EQ(a, b) ((FRACTION_NUM(a) == FRACTION_NUM(b)) && (FRACTION_DEN(a) == FRACTION_DEN(b)))
  #define NE(a, b) ((FRACTION_NUM(a) != FRACTION_NUM(b)) || (FRACTION_DEN(a) != FRACTION_DEN(b)))
  #define GR(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) > (FRACTION_NUM(b) * FRACTION_DEN(a)))
  #define GE(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) >= (FRACTION_NUM(b) * FRACTION_DEN(a)))
  #define LS(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) < (FRACTION_NUM(b) * FRACTION_DEN(a)))
  #define LE(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) <= (FRACTION_NUM(b) * FRACTION_DEN(a)))
  
  #define EXCHANGE(a, b) do{ TYPE tmp; \
   FRACTION_NUM(tmp) = FRACTION_NUM(a);   FRACTION_DEN(tmp) = FRACTION_DEN(a); \
   FRACTION_NUM(a)   = FRACTION_NUM(b);   FRACTION_DEN(a)   = FRACTION_DEN(b); \
   FRACTION_NUM(b)   = FRACTION_NUM(tmp); FRACTION_DEN(b)   = FRACTION_DEN(tmp); }while(0)
  
#elif defined(TYPE_BIGINT)
  
  #define ADD(a, b, c) FUNCTION(NAME, add)((a), (b), (c))
  #define SUB(a, b, c) FUNCTION(NAME, sub)((a), (b), (c))
  #define MUL(a, b, c) FUNCTION(NAME, mul)((a), (b), (c))
  #define DIV(a, b, c) FUNCTION(NAME, div)((a), (b), (c))
  
  #define EQ(a, b) FUNCTION(NAME, eq)((a), (b))
  #define NE(a, b) FUNCTION(NAME, ne)((a), (b))
  #define GR(a, b) FUNCTION(NAME, gr)((a), (b))
  #define GE(a, b) FUNCTION(NAME, ge)((a), (b))
  #define LS(a, b) FUNCTION(NAME, ls)((a), (b))
  #define LE(a, b) FUNCTION(NAME, le)((a), (b))
  
  #define ABS(a) FUNCTION(NAME, abs)((a))
  #define EXCHANGE(a, b) do{ TYPE *tmp; tmp = (a); (a) = (b); (b) = tmp; }while(0)
  
#elif defined(TYPE_BIGNUM)
  
  #define ADD(a, b, c) FUNCTION(NAME, add)((a), (b), (c))
  #define SUB(a, b, c) FUNCTION(NAME, sub)((a), (b), (c))
  #define MUL(a, b, c) FUNCTION(NAME, mul)((a), (b), (c))
  #define DIV(a, b, c) FUNCTION(NAME, div)((a), (b), (c))
  
  #define EQ(a, b) FUNCTION(NAME, eq)((a), (b))
  #define NE(a, b) FUNCTION(NAME, ne)((a), (b))
  #define GR(a, b) FUNCTION(NAME, gr)((a), (b))
  #define GE(a, b) FUNCTION(NAME, ge)((a), (b))
  #define LS(a, b) FUNCTION(NAME, ls)((a), (b))
  #define LE(a, b) FUNCTION(NAME, le)((a), (b))
  
  #define ABS(a) FUNCTION(NAME, abs)((a))
  #define EXCHANGE(a, b) do{ TYPE *tmp; tmp = (a); (a) = (b); (b) = tmp; }while(0)
  
#elif defined(TYPE_STRING)
  
  #define ADD(a, b, c) FUNCTION(NAME, add)((a), (b), (c))
  #define SUB(a, b, c) FUNCTION(NAME, sub)((a), (b), (c))
  #define MUL(a, b, c) FUNCTION(NAME, mul)((a), (b), (c))
  #define DIV(a, b, c) FUNCTION(NAME, div)((a), (b), (c))
  
  #define EQ(a, b) FUNCTION(NAME, eq)((a), (b))
  #define NE(a, b) FUNCTION(NAME, ne)((a), (b))
  #define GR(a, b) FUNCTION(NAME, gr)((a), (b))
  #define GE(a, b) FUNCTION(NAME, ge)((a), (b))
  #define LS(a, b) FUNCTION(NAME, ls)((a), (b))
  #define LE(a, b) FUNCTION(NAME, le)((a), (b))
  
  #define ABS(a) ((a))
  #define EXCHANGE(a, b) do{ TYPE *tmp; tmp = (a); (a) = (b); (b) = tmp; }while(0)
  
#elif defined(TYPE_BITSET)
  
  #define ADD(a, b, c) FUNCTION(NAME, add)((a), (b), (c))
  #define SUB(a, b, c) FUNCTION(NAME, sub)((a), (b), (c))
  #define MUL(a, b, c) FUNCTION(NAME, mul)((a), (b), (c))
  #define DIV(a, b, c) FUNCTION(NAME, div)((a), (b), (c))
  
  #define EQ(a, b) FUNCTION(NAME, eq)((a), (b))
  #define NE(a, b) FUNCTION(NAME, ne)((a), (b))
  #define GR(a, b) FUNCTION(NAME, gr)((a), (b))
  #define GE(a, b) FUNCTION(NAME, ge)((a), (b))
  #define LS(a, b) FUNCTION(NAME, ls)((a), (b))
  #define LE(a, b) FUNCTION(NAME, le)((a), (b))
  
#elif defined(TYPE_VECTOR) || defined(TYPE_MATRIX) || defined(TYPE_BIGMAT) || defined(TYPE_DFRAME) || defined(TYPE_DICT) || defined(TYPE_LIST) || defined(TYPE_TREE) || defined(TYPE_SET) || defined(TYPE_QUEUE) || defined(TYPE_STACK)

  #define EXCHANGE(a, b) do{ TYPE *tmp; tmp = (a); (a) = (b); (b) = tmp; }while(0)

#else
  #error !!! UNSUPPORTED DATA TYPE !!!
#endif
