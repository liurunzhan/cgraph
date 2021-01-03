#ifdef CONCAT1V
  #undef CONCAT1V
#endif

#ifdef CONCAT1
  #undef CONCAT1
#endif

#ifdef CONCAT2V
  #undef CONCAT2V
#endif

#ifdef CONCAT2
  #undef CONCAT2
#endif

#ifdef CONCAT3V
  #undef CONCAT3V
#endif

#ifdef CONCAT3
  #undef CONCAT3
#endif

#ifdef CONCAT4V
  #undef CONCAT4V
#endif

#ifdef CONCAT4
  #undef CONCAT4
#endif

#ifdef STRING
  #undef STRING
#endif

#ifdef FUNCTION
  #undef FUNCTION
#endif

#ifdef STRUCT
  #undef STRUCT
#endif

/**DATA TYPE */

#ifdef TYPE_OBJECT
  #undef TYPE_OBJECT
#endif

#ifdef TYPE_HOBJECT
  #undef TYPE_HOBJECT
#endif

#ifdef TYPE_POBJECT
  #undef TYPE_POBJECT
#endif

#ifdef TYPE_SOBJECT
  #undef TYPE_SOBJECT
#endif

#ifdef TYPE_INT
  #undef TYPE_INT
#endif

#ifdef TYPE_FLOAT64
  #undef TYPE_FLOAT64
#endif

#ifdef TYPE_BOOL
  #undef TYPE_BOOL
#endif

#ifdef TYPE_FLOAT32
  #undef TYPE_FLOAT32
#endif

#ifdef TYPE_LONG
  #undef TYPE_LONG
#endif

#ifdef TYPE_INT8
  #undef TYPE_INT8
#endif

#ifdef TYPE_INT16
  #undef TYPE_INT16
#endif

#ifdef TYPE_INT32
  #undef TYPE_INT32
#endif

#ifdef TYPE_INT64
  #undef TYPE_INT64
#endif

#ifdef TYPE_TIME
  #undef TYPE_TIME
#endif

#ifdef TYPE_COMPLEX
  #undef TYPE_COMPLEX
#endif

#ifdef TYPE_FRACTION
  #undef TYPE_FRACTION
#endif

#ifdef TYPE_BIGINT
  #undef TYPE_BIGINT
#endif

#ifdef TYPE_BIGNUM
  #undef TYPE_BIGNUM
#endif

#ifdef TYPE_STRING
  #undef TYPE_STRING
#endif

#ifdef TYPE_BITSET
  #undef TYPE_BITSET
#endif

/** STRUCTURE TYPE */

#ifdef TYPE_VECTOR
  #undef TYPE_VECTOR
#endif

#ifdef TYPE_MATRIX
  #undef TYPE_MATRIX
#endif

#ifdef TYPE_BIGMAT
  #undef TYPE_BIGMAT
#endif

#ifdef TYPE_DFRAME
  #undef TYPE_DFRAME
#endif

#ifdef TYPE_DICT
  #undef TYPE_DICT
#endif

#ifdef TYPE_LIST
  #undef TYPE_LIST
#endif

#ifdef TYPE_TREE
  #undef TYPE_TREE
#endif

#ifdef TYPE_SET
  #undef TYPE_SET
#endif

#ifdef TYPE_DICT
  #undef TYPE_DICT
#endif

#ifdef TYPE_QUEUE
  #undef TYPE_QUEUE
#endif

/**TYPE PROPERTY */

#ifdef ARG
  #undef ARG
#endif

#ifdef TYPE
  #undef TYPE
#endif

#ifdef ID
  #undef ID
#endif

#ifdef UTYPE
  #undef UTYPE
#endif

#ifdef NAME
  #undef NAME
#endif

#ifdef OUT_FORMAT
  #undef OUT_FORMAT
#endif

#ifdef ZERO
  #undef ZERO
#endif

#ifdef ONE
  #undef ONE
#endif

#ifdef ONES
  #undef ONES
#endif

#ifdef BITS
  #undef BITS
#endif

#ifdef MIN
  #undef MIN
#endif

#ifdef MAX
  #undef MAX
#endif

#ifdef MSB
  #undef MSB
#endif

#ifdef LSB
  #undef LSB
#endif

#ifdef EPSILON
  #undef EPSILON
#endif

#ifdef EPSILON_LEN
  #undef EPSILON_LEN
#endif

/**DATA TYPE AND PROPERTY IN DATA TYPE */

#ifdef CGRAPH_WITH_DATA
  #undef CGRAPH_WITH_DATA
#endif

#ifdef DATA_TYPE
  #undef DATA_TYPE
#endif

#ifdef DATA_ID
  #undef DATA_ID
#endif

#ifdef DATA_UTYPE
  #undef DATA_UTYPE
#endif

#ifdef DATA_ZERO
  #undef DATA_ZERO
#endif

#ifdef DATA_ONE
  #undef DATA_ONE
#endif

#ifdef DATA_ONES
  #undef DATA_ONES
#endif

#ifdef DATA_BITS
  #undef DATA_BITS
#endif

#ifdef DATA_MAX
  #undef DATA_MAX
#endif

#ifdef DATA_MIN
  #undef DATA_MIN
#endif

#ifdef DATA_MSB
  #undef DATA_MSB
#endif

#ifdef DATA_LSB
  #undef DATA_LSB
#endif

#ifdef DATA_EPSILON
  #undef DATA_EPSILON
#endif

#ifdef DATA_EPSILON_LEN
  #undef DATA_EPSILON_LEN
#endif

#ifdef DATA_TEST
  #undef DATA_TEST
#endif

#ifdef DATA_ISNAN
  #undef DATA_ISNAN
#endif

#ifdef DATA_ISPINF
  #undef DATA_ISPINF
#endif

#ifdef DATA_ISNINF
  #undef DATA_ISNINF
#endif

#ifdef DATA_ISINF
  #undef DATA_ISINF
#endif

#ifdef DATA_ISPOS
  #undef DATA_ISPOS
#endif

#ifdef DATA_ISNEG
  #undef DATA_ISNEG
#endif

/** POINTER TYPE OF TYPE VECTOR */
#ifdef TYPE_VPTR
  #undef TYPE_VPTR
#endif

#ifdef TYPE_CPTR
  #undef TYPE_CPTR
#endif

#ifdef TYPE_SPTR
  #undef TYPE_SPTR
#endif

/** COPYED MEMORY SIZE WITHOUT POINTER MEMORY SIZE */
#ifdef COPY_SIZE
  #undef COPY_SIZE
#endif

/**OBJECT TYPE */
#ifdef OBJECT
  #undef OBJECT
#endif

/**DATA AND STRUCTURE INIT */
#ifdef CGRAPH_DATA_BASE
  #undef CGRAPH_DATA_BASE
#endif

#ifdef CGRAPH_STRUCTURE_BASE
  #undef CGRAPH_STRUCTURE_BASE
#endif

/**
 * DATA TYPE MATHEMATICAL FUNCTIONS
 * ALL TYPES MUST DEFINED FOLLOWING FUNCTIONS
 * CHECKED BY TEMPLATE_CHECK.H
 */
#ifdef ADD
  #undef ADD
#endif

#ifdef SUB
  #undef SUB
#endif

#ifdef MUL
  #undef MUL
#endif

#ifdef DIV
  #undef DIV
#endif

#ifdef DIVF
  #undef DIVF
#endif

#ifdef INT
  #undef INT
#endif

#ifdef MOD
  #undef MOD
#endif

#ifdef EQ
  #undef EQ
#endif

#ifdef NE
  #undef NE
#endif

#ifdef GR
  #undef GR
#endif

#ifdef GE
  #undef GE
#endif

#ifdef LS
  #undef LS
#endif

#ifdef LE
  #undef LE
#endif

#ifdef CEIL
  #undef CEIL
#endif

#ifdef FLOOR
  #undef FLOOR
#endif

#ifdef POW
  #undef POW
#endif

#ifdef ABS
  #undef ABS
#endif

#ifdef SIN
  #undef SIN
#endif

#ifdef COS
  #undef COS
#endif

#ifdef TAN
  #undef TAN
#endif

#ifdef ASIN
  #undef ASIN
#endif

#ifdef ACOS
  #undef ACOS
#endif

#ifdef ATAN
  #undef ATAN
#endif

#ifdef EXCHANGE
  #undef EXCHANGE
#endif
