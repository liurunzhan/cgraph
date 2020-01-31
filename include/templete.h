#define COMBINE1x(a) # a
#define COMBINE1(a) COMBINE1x(a)
#define COMBINE2x(a,b) a ## _ ## b 
#define COMBINE2(a,b) COMBINE2x(a,b)
#define COMBINE3x(a,b,c) a ## _ ## b ## _ ## c
#define COMBINE3(a,b,c) COMBINE3x(a,b,c)
#define COMBINE4x(a,b,c,d) a ## _ ## b ## _ ## c ## _ ## d
#define COMBINE4(a,b,c,d) COMBINE4x(a,b,c,d)

#define STRING(a) COMBINE1(a)
#define FUNCTION(a, b) COMBINE3(cgraph, a, b)
#define STRUCT(a) COMBINE3(_cgraph, a, struct_)

#if defined(TYPE_OBJECT)
#define TYPE cgraph_object_t
#define ID CGRAPH_OBJECT_T
#define NAME object
#define OUT_FORMAT "ld"
#define ZERO NULL

#elif defined(TYPE_INTEGER)
#define TYPE cgraph_integer_t
#define ID CGRAPH_INTEGER_T
#define NAME integer
#define OUT_FORMAT "%d"
#define ZERO 0
#define DATA_MIN CGRAPH_INTEGER_MAX
#define DATA_MAX CGRAPH_INTEGER_MIN

#elif defined(TYPE_REAL)
#define TYPE cgraph_real_t
#define ID CGRAPH_REAL_T
#define NAME real
#define OUT_FORMAT "%G"
#define DATA_EPSILON DBL_EPSILON
#define ZERO 0.0
#define DATA_MAX CGRAPH_REAL_MAX
#define DATA_MIN CGRAPH_REAL_MIN

#elif defined(TYPE_BOOLEAN)
#define TYPE cgraph_boolean_t
#define ID CGRAPH_BOOLEAN_T
#define NAME boolean
#define OUT_FORMAT "%d"
#define ZERO 0
#define DATA_MAX CGRAPH_BOOLEAN_MAX
#define DATA_MIN CGRAPH_BOOLEAN_MIN

#elif defined(TYPE_FLOAT)
#define TYPE cgraph_float_t
#define ID CGRAPH_FLOAT_T
#define NAME float
#define OUT_FORMAT "%f"
#define DATA_EPSILON FLT_EPSILON
#define ZERO 0.0
#define DATA_MAX CGRAPH_FLOAT_MAX
#define DATA_MIN CGRAPH_FLOAT_MIN

#elif defined(TYPE_LONG)
#define TYPE cgraph_long_t
#define ID CGRAPH_LONG_T
#define NAME long
#define OUT_FORMAT "%ld"
#define ZERO 0
#define DATA_MAX CGRAPH_LONG_MAX
#define DATA_MIN CGRAPH_LONG_MIN

#elif defined(TYPE_INT8)
#define TYPE cgraph_int8_t
#define ID CGRAPH_INT8_T
#define NAME int8
#define OUT_FORMAT "%d"
#define ZERO 0
#define DATA_MAX CGRAPH_INT8_MAX
#define DATA_MIN CGRAPH_INT8_MIN

#elif defined(TYPE_INT16)
#define TYPE cgraph_int16_t
#define ID CGRAPH_INT16_T
#define NAME int16
#define OUT_FORMAT "%d"
#define ZERO 0
#define DATA_MAX CGRAPH_INT16_MAX
#define DATA_MIN CGRAPH_INT16_MIN

#elif defined(TYPE_INT32)
#define TYPE cgraph_int32_t
#define ID CGRAPH_INT32_T
#define NAME int32
#define OUT_FORMAT "%d"
#define ZERO 0
#define DATA_MAX CGRAPH_INT32_MAX
#define DATA_MIN CGRAPH_INT32_MIN

#elif defined(TYPE_INT64)
#define TYPE cgraph_int64_t
#define ID CGRAPH_INT64_T
#define NAME int64
#define OUT_FORMAT "%ld"
#define ZERO 0
#define DATA_MAX CGRAPH_INT64_MAX
#define DATA_MIN CGRAPH_INT64_MIN

#elif defined(TYPE_COMPLEX)
#define TYPE cgraph_complex_t
#define ID CGRAPH_COMPLEX_T
#define NAME complex
#define OUT_FORMAT "%g"
#define DATA_TYPE double
#define DATA_EPSILON DBL_EPSILON
#define ZERO {0.0, 0.0}

#elif defined(TYPE_FRACTION)
#define TYPE cgraph_fraction_t
#define ID CGRAPH_FRACTION_T
#define NAME fraction
#define OUT_FORMAT "%d"
#define DATA_TYPE int
#define ZERO {0, 1}

#elif defined(TYPE_BIGINT)
#define TYPE cgraph_bigint_t
#define ID CGRAPH_BIGINT_T
#define NAME bigint
#define OUT_FORMAT "%d"
#define DATA_TYPE cgraph_integer_t
#define DATA_WITH_POINTER
#define ZERO 0

#elif defined(TYPE_BIGNUM)
#define TYPE cgraph_bignum_t
#define ID CGRAPH_BIGNUM_T
#define NAME bignum
#define OUT_FORMAT "%s"
#define DATA_TYPE char
#define DATA_WITH_POINTER
#define ZERO "0.0"

#elif defined(TYPE_STRING)
#define TYPE cgraph_string_t
#define ID CGRAPH_STRING_T
#define NAME string
#define OUT_FORMAT "%s"
#define DATA_TYPE char
#define DATA_WITH_POINTER
#define ZERO ""

#elif defined(TYPE_VECTOR)
#define TYPE cgraph_vector_t
#define ID CGRAPH_VECTOR_T
#define NAME vector
#define ZERO NULL

#elif defined(TYPE_MATRIX)
#define TYPE cgraph_matrix_t
#define ID CGRAPH_MATRIX_T
#define NAME matrix
#define ZERO NULL

#elif defined(TYPE_BIGMAT)
#define TYPE cgraph_bigmat_t
#define ID CGRAPH_BIGMAT_T
#define NAME bigmat
#define ZERO NULL

#elif defined(TYPE_DFRAME)
#define TYPE cgraph_dframe_t
#define ID CGRAPH_DFRAME_T
#define NAME dframe
#define ZERO NULL

#elif defined(TYPE_HTABLE)
#define TYPE cgraph_htable_t
#define ID CGRAPH_HTABLE_T
#define NAME htable
#define ZERO NULL

#elif defined(TYPE_LIST)
#define TYPE cgraph_list_t
#define ID CGRAPH_LIST_T
#define NAME list
#define ZERO NULL

#else
#error !!! UNSUPPORTED DATA TYPE !!!
#endif

#if defined(TYPE_OBJECT)

#elif defined(TYPE_BOOLEAN)
#define ADD(a, b) ((((a) == CGRAPH_TRUE) || ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define SUB(a, b) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_FALSE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define	MUL(a, b) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CGRAPH_TRUE : CGRAPH_FALSE)
#define DIV(a, b) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CHRAPH_TRUE : CGRAPH_FALSE)
#define INT(a, b) ((((a) == CGRAPH_TRUE) && ((b) == CGRAPH_TRUE)) ? CHRAPH_TRUE : CGRAPH_FALSE)
#define MOD(a, b) (SUB((a), INT(a, b)))

#define EQ(a, b) ((a) == (b))
#define GR(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))
#define LS(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))
#define POW(a, b) ((a) == CGRAPH_TRUE ? CGRAPH_TRUE : CGRAPH_FALSE)

#define ABS(a) ((a))

#elif defined(TYPE_INTEGER) || defined(TYPE_LONG) \
	|| defined(TYPE_INT8) || defined(TYPE_INT16) || defined(TYPE_INT32) \
	|| defined(TYPE_INT64)
#define ADD(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))
#define DIV(a, b) ((a) / (b))
#define INT(a, b) ((a) / (b))
#define MOD(a, b) ((a) % (b))

#define EQ(a, b) ((a) == (b))
#define GR(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))
#define LS(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))
#define POW(a, b) pow((a), (b))

#define ABS(a) ((a) > 0 ? (a) : (-(a)))
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

#elif defined(TYPE_REAL) || defined(TYPE_FLOAT)
#define ADD(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))
#define DIV(a, b) ((a) / (b))
#define INT(a, b) (floor((a), (b)))
#define MOD(a, b) (fmod((a), (b)))

#define EQ(a, b) (fabs((a) - (b)) < DATA_EPSILON)
#define GR(a, b) (((a) > (b)) && (fabs((a) - (b)) >= DATA_EPSILON))
#define GE(a, b) (GR(a, b) || EQ(a, b))
#define LS(a, b) (((a) < (b)) && (fabs((a) - (b)) >= DATA_EPSILON))
#define LE(a, b) (LS(a, b) || EQ(a, b))
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

#elif defined(TYPE_COMPLEX)
#define ADD(a, b) ({TYPE c; COMPLEX_REAL(c) = COMPLEX_REAL(a) + COMPLEX_REAL(b); COMPLEX_IMAG(c) = COMPLEX_IMAG(a) + COMPLEX_IMAG(b); c;})
#define SUB(a, b) ({TYPE c; COMPLEX_REAL(c) = COMPLEX_REAL(a) - COMPLEX_REAL(b);COMPLEX_IMAG(c) = COMPLEX_IMAG(a) - COMPLEX_IMAG(b); c;})
#define MUL(a, b) ({TYPE c; COMPLEX_REAL(c) = COMPLEX_REAL(a) * COMPLEX_REAL(b) - COMPLEX_IMAG(a) * COMPLEX_IMAG(b); COMPLEX_IMAG(c) = COMPLEX_REAL(a) * COMPLEX_IMAG(b) + COMPLEX_IMAG(a) * COMPLEX_REAL(b); c;})
#define DIV(a, b) ({TYPE c; DATA_TYPE mod = COMPLEX_MOD2(b); COMPLEX_REAL(c) = (COMPLEX_REAL(a) * COMPLEX_REAL(b) + COMPLEX_IMAG(a) * COMPLEX_IMAG(b)) / mod; COMPLEX_IMAG(c) = (COMPLEX_IMAG(a) * COMPLEX_REAL(b) - COMPLEX_REAL(a) * COMPLEX_IMAG(b)) / mod; c;})

#define EQ(a, b) ((fabs(COMPLEX_REAL(a) - COMPLEX_REAL(b)) < DATA_EPSILON) && (fabs(COMPLEX_IMAG(a) - COMPLEX_IMAG(b)) < DATA_EPSILON))
#define GR(a, b) (COMPLEX_MOD2(a) > COMPLEX_MOD2(b))
#define GE(a, b) (GR(a, b) || EQ(a, b))
#define LS(a, b) (COMPLEX_MOD2(a) < COMPLEX_MOD2(b))
#define LE(a, b) (LS(a, b) || EQ(a, b))

#define ABS(a) ({TYPE c; COMPLEX_REAL(c) = fabs(COMPLEX_REAL(a)); COMPLEX_IMAG(c) = fabs(COMPLEX_IMAG(a)); c;})

#elif defined(TYPE_FRACTION)
#define ADD(a, b) ({TYPE c; FRACTION_NUM(c) = FRACTION_NUM(a) * FRACTION_DEN(b) + FRACTION_DEN(a) * FRACTION_NUM(b); FRACTION_DEN(c) = FRACTION_DEN(a) * FRACTION_DEN(b); c;})
#define SUB(a, b) ({TYPE c; FRACTION_NUM(c) = FRACTION_NUM(a) * FRACTION_DEN(b) - FRACTION_DEN(a) * FRACTION_NUM(b); FRACTION_DEN(c) = FRACTION_DEN(a) * FRACTION_DEN(b); c;})
#define MUL(a, b) ({TYPE c; FRACTION_NUM(c) = FRACTION_NUM(a) * FRACTION_NUM(b); FRACTION_DEN(c) = FRACTION_DEN(a) * FRACTION_DEN(b); c;})
#define DIV(a, b) ({TYPE c; FRACTION_NUM(c) = FRACTION_NUM(a) * FRACTION_DEN(b); FRACTION_DEN(c) = FRACTION_DEN(a) * FRACTION_NUM(b); c;})

#define EQ(a, b) ((FRACTION_NUM(a) == FRACTION_NUM(b)) && (FRACTION_DEN(a) == FRACTION_DEN(b)))
#define GR(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) > (FRACTION_NUM(b) * FRACTION_DEN(a)))
#define GE(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) >= (FRACTION_NUM(b) * FRACTION_DEN(a)))
#define LS(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) < (FRACTION_NUM(b) * FRACTION_DEN(a)))
#define LE(a, b) ((FRACTION_NUM(a) * FRACTION_DEN(b)) <= (FRACTION_NUM(b) * FRACTION_DEN(a)))

#define ABS(a) ({TYPE c; FRACTION_NUM(c) = FRACTION_NUM(a); FRACTION_DEN(c) = FRACTION_DEN(a); c;})

#elif defined(TYPE_BIGINT) || defined(TYPE_BIGNUM) || defined(TYPE_STRING)

#elif defined(TYPE_VECTOR) || defined(TYPE_MATRIX) || defined(TYPE_BIGMAT) || defined(TYPE_DFRAME) || defined(TYPE_HTABLE) || defined(TYPE_LIST)

#else
#error !!! UNSUPPORTED DATA TYPE !!!
#endif