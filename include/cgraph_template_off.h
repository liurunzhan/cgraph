/**
 * @file cgraph_template_off.h
 * @brief undefine the common-defined macros
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

/**
 * Description of the file's generator:
 * Update the cgraph_template_off.h.in
 * Macros in this file is generated by tool/macro.py with following documents.
 * Users can call this script by running ./tools/run.sh in root of project.
 * This script supports groups and macros, where dumplex values are supported.
 * 1) if you want to add a new macro in existed group, just add it after the
 * corresponding line of "MACRO GROUP : GROUP DESCRIPITION"
 * 2) if you want to add a new group, add it with the template
 * MACRO GROUP : GROUP DESCRIPITION
 * MACRO1 MACRO2 MACRO3 ... MACRO4
 * where a) "GROUP DESCRIPTION" is insert into a C-type document before the
 * macro group, and b) MACROx is generated into a C-type code as
 * #ifdef MACROx
 * #undef MACROx
 * #endif
 */

/*******************************************************************************
 * MACRO GROUP : BASE
 * CONCAT1V CONCAT1
 * CONCAT2V CONCAT2
 * CONCAT3V CONCAT3
 * CONCAT4V CONCAT4
 * TYPE_T ID_T STRUCT STRING FUNCTION
 * MACRO GROUP : DATA TYPE
 * TYPE_OBJECT TYPE_HOBJECT TYPE_GOBJECT TYPE_MOBJECT TYPE_M3OBJECT TYPE_POBJECT
 * TYPE_FLOAT8 TYPE_FLOAT16 TYPE_FLOAT32 TYPE_FLOAT64 TYPE_FLOAT128
 * TYPE_FLOAT128_SIZE64 TYPE_FLOAT128_SIZE80 TYPE_FLOAT128_SIZE128
 * TYPE_BOOL TYPE_LOGIC TYPE_INT TYPE_LONG TYPE_LONG_SIZE32 TYPE_LONG_SIZE64
 * TYPE_INT8 TYPE_INT16 TYPE_INT32 TYPE_INT64 TYPE_INT128 TYPE_INT128_SIZE64
 * TYPE_INT128_SIZE128
 * TYPE_TIME TYPE_COMPLEX TYPE_QUAT TYPE_FRACTION TYPE_POINT2D TYPE_POINT3D
 * TYPE_BIGINT TYPE_BIGNUM TYPE_STRING TYPE_BITSET
 * MACRO GROUP : STRUCTURE TYPE
 * TYPE_VECTOR
 * TYPE_MATRIX TYPE_BIGMAT TYPE_SPAMAT
 * TYPE_MATRIX3D TYPE_BIGMAT3D TYPE_SPAMAT3D
 * TYPE_DFRAME TYPE_LIST TYPE_TREE TYPE_SET TYPE_DICT TYPE_QUEUE
 * MACRO GROUP : DATA TYPE ELEMENT
 * TYPE_WITH_DATA
 * DATA_TYPE DATA_ID DATA_NAME DATA_UNAME DATA_INAME
 * DATA_BITS DATA_BYTES DATA_L2BITS DATA_L2BITS_EPSILON
 * DATA_UTYPE DATA_END
 * DATA_ZERO DATA_ONE DATA_ONES
 * DATA_MAX DATA_MIN DATA_BIAS
 * DATA_MAX1 DATA_MIN1 DATA_BIAS1
 * DATA_NAN DATA_INF DATA_PINF DATA_NINF
 * DATA_LSB DATA_MSB DATA_MASK DATA_EPSILON DATA_EPSILON_LEN
 * DATA_EQ DATA_NE DATA_GT DATA_GE DATA_LT DATA_LE
 * DATA_TEST DATA_FUNC DATA_CFUNC
 * DATA_TOBOOL DATA_TOLOGIC
 * DATA_ISBOOL DATA_ISLOGIC
 * DATA_ISNAN DATA_ISPINF DATA_ISNINF DATA_ISINF
 * DATA_ISPOS DATA_ISNEG
 * MACRO GROUP : ELEMENT BASE
 * ARG TYPE TYPE_PTR
 * NAME ID BITS L2BITS
 * UNAME UTYPE UID IN_FMT IN_FMT_IMAG OUT_FMT OUT_FMT_REAL OUT_FMT_IMAG
 * OUT_FMT_NUM
 * ZERO0 ONE0 ONES0
 * ZERO1 ONE1 ONES1
 * ZERO ONE ONES
 * MIN MAX NAN INF PINF NINF
 * LSB MSB SIGNBIT MASK EPSILON EPSILON_LEN DATA_INUM
 * HASH_OFFSET
 * FRAC_BITS FRAC_MASK FRAC_OFFSET
 * FLOAT_SOFT_TOFRAC FLOAT_SOFT_FRAC_FMT FLOAT_SOFT_FRAC FLOAT_SOFT_FRAC_CLR
 * FLOAT_SOFT_FRAC_SET
 * EXP_BITS EXP_MASK EXP_OFFSET EXP_BIAS
 * FLOAT_SOFT
 * FLOAT_SOFT_TOEXP FLOAT_SOFT_EXP FLOAT_SOFT_EXP_CLR FLOAT_SOFT_EXP_SET
 * SIG_BITS SIG_MASK SIG_OFFSET
 * FLOAT_SOFT_TOSIG FLOAT_SOFT_SIG FLOAT_SOFT_SIG_CLR FLOAT_SOFT_SIG_SET
 * MASK1 MASK2 MASK4 MASK8 MASK16 MASK32 MASK64
 * MACRO GROUP : COPYED MEMORY SIZE WITHOUT SELF-DEFINED MEMORY POINTER SIZE
 * COPY_SIZE
 * MACRO GROUP : OBJECT TYPE
 * OBJECT
 * CGRAPH_OBJECT_BASE CGRAPH_OBJECT_ROOT
 * CGRAPH_OBJECT_DATA_START
 * MACRO GROUP : BASIC FUNCTIONS
 * CGRAPH_BASE CGRAPH_SIZE CGRAPH_LEN
 * CGRAPH_DATA CGRAPH_DATA_START CGRAPH_DATA_END CGRAPH_DATA_ROOT
 * CGRAPH_ISNULL CGRAPH_HASMEM CGRAPH_ISEMPTY CGRAPH_HASDATA
 * CGRAPH_DATA_BITS_CHECKER CGRAPH_DATA_BYTES_CHECKER
 * MACRO GROUP : STRUCTURE TYPE ELEMENT
 * CGRAPH_STRUCTURE_BASE
 * CGRAPH_STRUCTURE_PTR1 CGRAPH_STRUCTURE_PTR2
 * CGRAPH_STRUCTURE_ROOT
 * MACRO GROUP : 2D AND 3D MATRIX
 * CGRAPH_MATRIX_INDEXES MATRIX_ROW MATRIX_COLUMN MATRIX_SIZE MATRIX_INDEX
 * CGRAPH_MATRIX_ROW CGRAPH_MATRIX_COLUMN CGRAPH_MATRIX_SIZE
 * CGRAPH_MATRIX3D_INDEXES MATRIX3D_INDEX_I MATRIX3D_INDEX_J MATRIX3D_INDEX_K
 * MATRIX3D_SIZE_IJ MATRIX3D_SIZE_IK MATRIX3D_SIZE_JK MATRIX3D_SIZE
 * MATRIX3D_INDEX
 * CGRAPH_MATRIX3D_INDEX_I CGRAPH_MATRIX3D_INDEX_J CGRAPH_MATRIX3D_INDEX_K
 * CGRAPH_MATRIX3D_SIZE_IJ CGRAPH_MATRIX3D_SIZE_IK MATRIX3D_SIZE_JK
 * CGRAPH_MATRIX3D_SIZE
 * MACRO GROUP : DATA TYPE MATHEMATICAL FUNCTIONS, CHECKED BY "template_check.h"
 * ASSIGN ADD SUB MUL DIV DIVF INT FEXP FREXP FMOD MODF MOD
 * BOOLEAN_EQ BOOLEAN_NE BOOLEAN_GT BOOLEAN_GE BOOLEAN_LT BOOLEAN_LE
 * BOOLEAN_AND BOOLEAN_NAND BOOLEAN_ANDN BOOLEAN_OR BOOLEAN_NOR BOOLEAN_ORN
 * BOOLEAN_ABS BOOLEAN_NOT BOOLEAN_XOR BOOLEAN_XNOR
 * EQ NE GT GE LT LE
 * AND NAND ANDN OR NOR ORN NOT XOR XNOR
 * CEIL FLOOR POW ABS SIN COS TAN ASIN ACOS ATAN SINH COSH TANH
 * LOG LOG2 LOG10 EXP SQRT CUBE
 * SWAP ROL3 ROR3 ROL4 ROR4
 * DATA_SWAP MACRO GROUP : DEFINED C-TYPE BUFFER
 * CGRAPH_CBUF_SIZE CGRAPH_CBUF_PTR CGRAPH_CBUF_LEN
 ******************************************************************************/

/** BASE */
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

#ifdef TYPE_T
#undef TYPE_T
#endif

#ifdef ID_T
#undef ID_T
#endif

#ifdef STRUCT
#undef STRUCT
#endif

#ifdef STRING
#undef STRING
#endif

#ifdef FUNCTION
#undef FUNCTION
#endif

/** DATA TYPE */
#ifdef TYPE_OBJECT
#undef TYPE_OBJECT
#endif

#ifdef TYPE_HOBJECT
#undef TYPE_HOBJECT
#endif

#ifdef TYPE_GOBJECT
#undef TYPE_GOBJECT
#endif

#ifdef TYPE_MOBJECT
#undef TYPE_MOBJECT
#endif

#ifdef TYPE_M3OBJECT
#undef TYPE_M3OBJECT
#endif

#ifdef TYPE_POBJECT
#undef TYPE_POBJECT
#endif

#ifdef TYPE_FLOAT8
#undef TYPE_FLOAT8
#endif

#ifdef TYPE_FLOAT16
#undef TYPE_FLOAT16
#endif

#ifdef TYPE_FLOAT32
#undef TYPE_FLOAT32
#endif

#ifdef TYPE_FLOAT64
#undef TYPE_FLOAT64
#endif

#ifdef TYPE_FLOAT128
#undef TYPE_FLOAT128
#endif

#ifdef TYPE_FLOAT128_SIZE64
#undef TYPE_FLOAT128_SIZE64
#endif

#ifdef TYPE_FLOAT128_SIZE80
#undef TYPE_FLOAT128_SIZE80
#endif

#ifdef TYPE_FLOAT128_SIZE128
#undef TYPE_FLOAT128_SIZE128
#endif

#ifdef TYPE_BOOL
#undef TYPE_BOOL
#endif

#ifdef TYPE_LOGIC
#undef TYPE_LOGIC
#endif

#ifdef TYPE_INT
#undef TYPE_INT
#endif

#ifdef TYPE_LONG
#undef TYPE_LONG
#endif

#ifdef TYPE_LONG_SIZE32
#undef TYPE_LONG_SIZE32
#endif

#ifdef TYPE_LONG_SIZE64
#undef TYPE_LONG_SIZE64
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

#ifdef TYPE_INT128
#undef TYPE_INT128
#endif

#ifdef TYPE_INT128_SIZE64
#undef TYPE_INT128_SIZE64
#endif

#ifdef TYPE_INT128_SIZE128
#undef TYPE_INT128_SIZE128
#endif

#ifdef TYPE_TIME
#undef TYPE_TIME
#endif

#ifdef TYPE_COMPLEX
#undef TYPE_COMPLEX
#endif

#ifdef TYPE_QUAT
#undef TYPE_QUAT
#endif

#ifdef TYPE_FRACTION
#undef TYPE_FRACTION
#endif

#ifdef TYPE_POINT2D
#undef TYPE_POINT2D
#endif

#ifdef TYPE_POINT3D
#undef TYPE_POINT3D
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

#ifdef TYPE_SPAMAT
#undef TYPE_SPAMAT
#endif

#ifdef TYPE_MATRIX3D
#undef TYPE_MATRIX3D
#endif

#ifdef TYPE_BIGMAT3D
#undef TYPE_BIGMAT3D
#endif

#ifdef TYPE_SPAMAT3D
#undef TYPE_SPAMAT3D
#endif

#ifdef TYPE_DFRAME
#undef TYPE_DFRAME
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

/** DATA TYPE ELEMENT */
#ifdef TYPE_WITH_DATA
#undef TYPE_WITH_DATA
#endif

#ifdef DATA_TYPE
#undef DATA_TYPE
#endif

#ifdef DATA_ID
#undef DATA_ID
#endif

#ifdef DATA_NAME
#undef DATA_NAME
#endif

#ifdef DATA_UNAME
#undef DATA_UNAME
#endif

#ifdef DATA_INAME
#undef DATA_INAME
#endif

#ifdef DATA_BITS
#undef DATA_BITS
#endif

#ifdef DATA_BYTES
#undef DATA_BYTES
#endif

#ifdef DATA_L2BITS
#undef DATA_L2BITS
#endif

#ifdef DATA_L2BITS_EPSILON
#undef DATA_L2BITS_EPSILON
#endif

#ifdef DATA_UTYPE
#undef DATA_UTYPE
#endif

#ifdef DATA_END
#undef DATA_END
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

#ifdef DATA_MAX
#undef DATA_MAX
#endif

#ifdef DATA_MIN
#undef DATA_MIN
#endif

#ifdef DATA_BIAS
#undef DATA_BIAS
#endif

#ifdef DATA_MAX1
#undef DATA_MAX1
#endif

#ifdef DATA_MIN1
#undef DATA_MIN1
#endif

#ifdef DATA_BIAS1
#undef DATA_BIAS1
#endif

#ifdef DATA_NAN
#undef DATA_NAN
#endif

#ifdef DATA_INF
#undef DATA_INF
#endif

#ifdef DATA_PINF
#undef DATA_PINF
#endif

#ifdef DATA_NINF
#undef DATA_NINF
#endif

#ifdef DATA_LSB
#undef DATA_LSB
#endif

#ifdef DATA_MSB
#undef DATA_MSB
#endif

#ifdef DATA_MASK
#undef DATA_MASK
#endif

#ifdef DATA_EPSILON
#undef DATA_EPSILON
#endif

#ifdef DATA_EPSILON_LEN
#undef DATA_EPSILON_LEN
#endif

#ifdef DATA_EQ
#undef DATA_EQ
#endif

#ifdef DATA_NE
#undef DATA_NE
#endif

#ifdef DATA_GT
#undef DATA_GT
#endif

#ifdef DATA_GE
#undef DATA_GE
#endif

#ifdef DATA_LT
#undef DATA_LT
#endif

#ifdef DATA_LE
#undef DATA_LE
#endif

#ifdef DATA_TEST
#undef DATA_TEST
#endif

#ifdef DATA_FUNC
#undef DATA_FUNC
#endif

#ifdef DATA_CFUNC
#undef DATA_CFUNC
#endif

#ifdef DATA_TOBOOL
#undef DATA_TOBOOL
#endif

#ifdef DATA_TOLOGIC
#undef DATA_TOLOGIC
#endif

#ifdef DATA_ISBOOL
#undef DATA_ISBOOL
#endif

#ifdef DATA_ISLOGIC
#undef DATA_ISLOGIC
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

/** ELEMENT BASE */
#ifdef ARG
#undef ARG
#endif

#ifdef TYPE
#undef TYPE
#endif

#ifdef TYPE_PTR
#undef TYPE_PTR
#endif

#ifdef NAME
#undef NAME
#endif

#ifdef ID
#undef ID
#endif

#ifdef BITS
#undef BITS
#endif

#ifdef L2BITS
#undef L2BITS
#endif

#ifdef UNAME
#undef UNAME
#endif

#ifdef UTYPE
#undef UTYPE
#endif

#ifdef UID
#undef UID
#endif

#ifdef IN_FMT
#undef IN_FMT
#endif

#ifdef IN_FMT_IMAG
#undef IN_FMT_IMAG
#endif

#ifdef OUT_FMT
#undef OUT_FMT
#endif

#ifdef OUT_FMT_REAL
#undef OUT_FMT_REAL
#endif

#ifdef OUT_FMT_IMAG
#undef OUT_FMT_IMAG
#endif

#ifdef OUT_FMT_NUM
#undef OUT_FMT_NUM
#endif

#ifdef ZERO0
#undef ZERO0
#endif

#ifdef ONE0
#undef ONE0
#endif

#ifdef ONES0
#undef ONES0
#endif

#ifdef ZERO1
#undef ZERO1
#endif

#ifdef ONE1
#undef ONE1
#endif

#ifdef ONES1
#undef ONES1
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

#ifdef MIN
#undef MIN
#endif

#ifdef MAX
#undef MAX
#endif

#ifdef NAN
#undef NAN
#endif

#ifdef INF
#undef INF
#endif

#ifdef PINF
#undef PINF
#endif

#ifdef NINF
#undef NINF
#endif

#ifdef LSB
#undef LSB
#endif

#ifdef MSB
#undef MSB
#endif

#ifdef SIGNBIT
#undef SIGNBIT
#endif

#ifdef MASK
#undef MASK
#endif

#ifdef EPSILON
#undef EPSILON
#endif

#ifdef EPSILON_LEN
#undef EPSILON_LEN
#endif

#ifdef DATA_INUM
#undef DATA_INUM
#endif

#ifdef HASH_OFFSET
#undef HASH_OFFSET
#endif

#ifdef FRAC_BITS
#undef FRAC_BITS
#endif

#ifdef FRAC_MASK
#undef FRAC_MASK
#endif

#ifdef FRAC_OFFSET
#undef FRAC_OFFSET
#endif

#ifdef FLOAT_SOFT_TOFRAC
#undef FLOAT_SOFT_TOFRAC
#endif

#ifdef FLOAT_SOFT_FRAC_FMT
#undef FLOAT_SOFT_FRAC_FMT
#endif

#ifdef FLOAT_SOFT_FRAC
#undef FLOAT_SOFT_FRAC
#endif

#ifdef FLOAT_SOFT_FRAC_CLR
#undef FLOAT_SOFT_FRAC_CLR
#endif

#ifdef FLOAT_SOFT_FRAC_SET
#undef FLOAT_SOFT_FRAC_SET
#endif

#ifdef EXP_BITS
#undef EXP_BITS
#endif

#ifdef EXP_MASK
#undef EXP_MASK
#endif

#ifdef EXP_OFFSET
#undef EXP_OFFSET
#endif

#ifdef EXP_BIAS
#undef EXP_BIAS
#endif

#ifdef FLOAT_SOFT
#undef FLOAT_SOFT
#endif

#ifdef FLOAT_SOFT_TOEXP
#undef FLOAT_SOFT_TOEXP
#endif

#ifdef FLOAT_SOFT_EXP
#undef FLOAT_SOFT_EXP
#endif

#ifdef FLOAT_SOFT_EXP_CLR
#undef FLOAT_SOFT_EXP_CLR
#endif

#ifdef FLOAT_SOFT_EXP_SET
#undef FLOAT_SOFT_EXP_SET
#endif

#ifdef SIG_BITS
#undef SIG_BITS
#endif

#ifdef SIG_MASK
#undef SIG_MASK
#endif

#ifdef SIG_OFFSET
#undef SIG_OFFSET
#endif

#ifdef FLOAT_SOFT_TOSIG
#undef FLOAT_SOFT_TOSIG
#endif

#ifdef FLOAT_SOFT_SIG
#undef FLOAT_SOFT_SIG
#endif

#ifdef FLOAT_SOFT_SIG_CLR
#undef FLOAT_SOFT_SIG_CLR
#endif

#ifdef FLOAT_SOFT_SIG_SET
#undef FLOAT_SOFT_SIG_SET
#endif

#ifdef MASK1
#undef MASK1
#endif

#ifdef MASK2
#undef MASK2
#endif

#ifdef MASK4
#undef MASK4
#endif

#ifdef MASK8
#undef MASK8
#endif

#ifdef MASK16
#undef MASK16
#endif

#ifdef MASK32
#undef MASK32
#endif

#ifdef MASK64
#undef MASK64
#endif

/** COPYED MEMORY SIZE WITHOUT SELF-DEFINED MEMORY POINTER SIZE */
#ifdef COPY_SIZE
#undef COPY_SIZE
#endif

/** OBJECT TYPE */
#ifdef OBJECT
#undef OBJECT
#endif

#ifdef CGRAPH_OBJECT_BASE
#undef CGRAPH_OBJECT_BASE
#endif

#ifdef CGRAPH_OBJECT_ROOT
#undef CGRAPH_OBJECT_ROOT
#endif

#ifdef CGRAPH_OBJECT_DATA_START
#undef CGRAPH_OBJECT_DATA_START
#endif

/** BASIC FUNCTIONS */
#ifdef CGRAPH_BASE
#undef CGRAPH_BASE
#endif

#ifdef CGRAPH_SIZE
#undef CGRAPH_SIZE
#endif

#ifdef CGRAPH_LEN
#undef CGRAPH_LEN
#endif

#ifdef CGRAPH_DATA
#undef CGRAPH_DATA
#endif

#ifdef CGRAPH_DATA_START
#undef CGRAPH_DATA_START
#endif

#ifdef CGRAPH_DATA_END
#undef CGRAPH_DATA_END
#endif

#ifdef CGRAPH_DATA_ROOT
#undef CGRAPH_DATA_ROOT
#endif

#ifdef CGRAPH_ISNULL
#undef CGRAPH_ISNULL
#endif

#ifdef CGRAPH_HASMEM
#undef CGRAPH_HASMEM
#endif

#ifdef CGRAPH_ISEMPTY
#undef CGRAPH_ISEMPTY
#endif

#ifdef CGRAPH_HASDATA
#undef CGRAPH_HASDATA
#endif

#ifdef CGRAPH_DATA_BITS_CHECKER
#undef CGRAPH_DATA_BITS_CHECKER
#endif

#ifdef CGRAPH_DATA_BYTES_CHECKER
#undef CGRAPH_DATA_BYTES_CHECKER
#endif

/** STRUCTURE TYPE ELEMENT */
#ifdef CGRAPH_STRUCTURE_BASE
#undef CGRAPH_STRUCTURE_BASE
#endif

#ifdef CGRAPH_STRUCTURE_PTR1
#undef CGRAPH_STRUCTURE_PTR1
#endif

#ifdef CGRAPH_STRUCTURE_PTR2
#undef CGRAPH_STRUCTURE_PTR2
#endif

#ifdef CGRAPH_STRUCTURE_ROOT
#undef CGRAPH_STRUCTURE_ROOT
#endif

/** 2D AND 3D MATRIX */
#ifdef CGRAPH_MATRIX_INDEXES
#undef CGRAPH_MATRIX_INDEXES
#endif

#ifdef MATRIX_ROW
#undef MATRIX_ROW
#endif

#ifdef MATRIX_COLUMN
#undef MATRIX_COLUMN
#endif

#ifdef MATRIX_SIZE
#undef MATRIX_SIZE
#endif

#ifdef MATRIX_INDEX
#undef MATRIX_INDEX
#endif

#ifdef CGRAPH_MATRIX_ROW
#undef CGRAPH_MATRIX_ROW
#endif

#ifdef CGRAPH_MATRIX_COLUMN
#undef CGRAPH_MATRIX_COLUMN
#endif

#ifdef CGRAPH_MATRIX_SIZE
#undef CGRAPH_MATRIX_SIZE
#endif

#ifdef CGRAPH_MATRIX3D_INDEXES
#undef CGRAPH_MATRIX3D_INDEXES
#endif

#ifdef MATRIX3D_INDEX_I
#undef MATRIX3D_INDEX_I
#endif

#ifdef MATRIX3D_INDEX_J
#undef MATRIX3D_INDEX_J
#endif

#ifdef MATRIX3D_INDEX_K
#undef MATRIX3D_INDEX_K
#endif

#ifdef MATRIX3D_SIZE_IJ
#undef MATRIX3D_SIZE_IJ
#endif

#ifdef MATRIX3D_SIZE_IK
#undef MATRIX3D_SIZE_IK
#endif

#ifdef MATRIX3D_SIZE_JK
#undef MATRIX3D_SIZE_JK
#endif

#ifdef MATRIX3D_SIZE
#undef MATRIX3D_SIZE
#endif

#ifdef MATRIX3D_INDEX
#undef MATRIX3D_INDEX
#endif

#ifdef CGRAPH_MATRIX3D_INDEX_I
#undef CGRAPH_MATRIX3D_INDEX_I
#endif

#ifdef CGRAPH_MATRIX3D_INDEX_J
#undef CGRAPH_MATRIX3D_INDEX_J
#endif

#ifdef CGRAPH_MATRIX3D_INDEX_K
#undef CGRAPH_MATRIX3D_INDEX_K
#endif

#ifdef CGRAPH_MATRIX3D_SIZE_IJ
#undef CGRAPH_MATRIX3D_SIZE_IJ
#endif

#ifdef CGRAPH_MATRIX3D_SIZE_IK
#undef CGRAPH_MATRIX3D_SIZE_IK
#endif

#ifdef MATRIX3D_SIZE_JK
#undef MATRIX3D_SIZE_JK
#endif

#ifdef CGRAPH_MATRIX3D_SIZE
#undef CGRAPH_MATRIX3D_SIZE
#endif

/** DATA TYPE MATHEMATICAL FUNCTIONS, CHECKED BY "template_check.h" */
#ifdef ASSIGN
#undef ASSIGN
#endif

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

#ifdef FEXP
#undef FEXP
#endif

#ifdef FREXP
#undef FREXP
#endif

#ifdef FMOD
#undef FMOD
#endif

#ifdef MODF
#undef MODF
#endif

#ifdef MOD
#undef MOD
#endif

#ifdef BOOLEAN_EQ
#undef BOOLEAN_EQ
#endif

#ifdef BOOLEAN_NE
#undef BOOLEAN_NE
#endif

#ifdef BOOLEAN_GT
#undef BOOLEAN_GT
#endif

#ifdef BOOLEAN_GE
#undef BOOLEAN_GE
#endif

#ifdef BOOLEAN_LT
#undef BOOLEAN_LT
#endif

#ifdef BOOLEAN_LE
#undef BOOLEAN_LE
#endif

#ifdef BOOLEAN_AND
#undef BOOLEAN_AND
#endif

#ifdef BOOLEAN_NAND
#undef BOOLEAN_NAND
#endif

#ifdef BOOLEAN_ANDN
#undef BOOLEAN_ANDN
#endif

#ifdef BOOLEAN_OR
#undef BOOLEAN_OR
#endif

#ifdef BOOLEAN_NOR
#undef BOOLEAN_NOR
#endif

#ifdef BOOLEAN_ORN
#undef BOOLEAN_ORN
#endif

#ifdef BOOLEAN_ABS
#undef BOOLEAN_ABS
#endif

#ifdef BOOLEAN_NOT
#undef BOOLEAN_NOT
#endif

#ifdef BOOLEAN_XOR
#undef BOOLEAN_XOR
#endif

#ifdef BOOLEAN_XNOR
#undef BOOLEAN_XNOR
#endif

#ifdef EQ
#undef EQ
#endif

#ifdef NE
#undef NE
#endif

#ifdef GT
#undef GT
#endif

#ifdef GE
#undef GE
#endif

#ifdef LT
#undef LT
#endif

#ifdef LE
#undef LE
#endif

#ifdef AND
#undef AND
#endif

#ifdef NAND
#undef NAND
#endif

#ifdef ANDN
#undef ANDN
#endif

#ifdef OR
#undef OR
#endif

#ifdef NOR
#undef NOR
#endif

#ifdef ORN
#undef ORN
#endif

#ifdef NOT
#undef NOT
#endif

#ifdef XOR
#undef XOR
#endif

#ifdef XNOR
#undef XNOR
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

#ifdef SINH
#undef SINH
#endif

#ifdef COSH
#undef COSH
#endif

#ifdef TANH
#undef TANH
#endif

#ifdef LOG
#undef LOG
#endif

#ifdef LOG2
#undef LOG2
#endif

#ifdef LOG10
#undef LOG10
#endif

#ifdef EXP
#undef EXP
#endif

#ifdef SQRT
#undef SQRT
#endif

#ifdef CUBE
#undef CUBE
#endif

#ifdef SWAP
#undef SWAP
#endif

#ifdef ROL3
#undef ROL3
#endif

#ifdef ROR3
#undef ROR3
#endif

#ifdef ROL4
#undef ROL4
#endif

#ifdef ROR4
#undef ROR4
#endif

/** DEFINED C-TYPE BUFFER */
#ifdef CGRAPH_CBUF_SIZE
#undef CGRAPH_CBUF_SIZE
#endif

#ifdef CGRAPH_CBUF_PTR
#undef CGRAPH_CBUF_PTR
#endif

#ifdef CGRAPH_CBUF_LEN
#undef CGRAPH_CBUF_LEN
#endif

/** end of cgraph_template_off */
