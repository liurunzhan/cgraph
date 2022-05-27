#include "cgraph_file.h"
#include "cgraph_version.h"

static const cgraph_char_t *cgraph_version_string = CGRAPH_VERSION;

void cgraph_version_parse(cgraph_char_t **version, cgraph_int_t *major,
                          cgraph_int_t *minor, cgraph_int_t *subminor) {
  cgraph_int_t cgraph_major, cgraph_minor, cgraph_subminor;
  sscanf(cgraph_version_string, "%d.%d.%d", &cgraph_major, &cgraph_minor,
         &cgraph_subminor);
  if (NULL != version) {
    *version = (cgraph_char_t *)cgraph_version_string;
  }
  if (NULL != major) {
    *major = cgraph_major;
  }
  if (NULL != minor) {
    *minor = cgraph_minor;
  }
  if (NULL != subminor) {
    *subminor = cgraph_subminor;
  }
}

cgraph_size_t cgraph_version_fprint(FILE *fp) {
  return cgraph_file_fprintf(fp, "Version of Library CGRAPH is %s",
                             cgraph_version_string);
}

cgraph_size_t cgraph_version_print(void) {
  return cgraph_version_fprint(stdout);
}

cgraph_size_t cgraph_version_fprintln(FILE *fp) {
  cgraph_size_t len =
      fprintf(fp, "Version of Library CGRAPH is %s", cgraph_version_string);
  if (0 < len) {
    len += cgraph_file_println();
  }

  return len;
}

cgraph_size_t cgraph_version_println(void) {
  return cgraph_version_fprintln(stdout);
}

static const cgraph_char_t *__cgraph_types__[] = {
    "CGRAPH_OBJECT_T/CGRAPH_HOBJECT_T/CGRAPH_GOBJECT_T/"
    "CGRAPH_M3OBJECT_T/CGRAPH_MOBJECT_T/CGRAPH_POBJECT_T", /**< TYPE  0 :
          CGRAPH_OBJECT_T/CGRAPH_HOBJECT_T/CGRAPH_GOBJECT_T/CGRAPH_M3OBJECT_T/CGRAPH_MOBJECT_T/CGRAPH_POBJECT_T
        */
    "CGRAPH_BOOL_T",              /**< TYPE  1 : CGRAPH_BOOL_T */
    "CGRAPH_LOGIC_T",             /**< TYPE  2 : CGRAPH_LOGIC_T */
    "CGRAPH_INT_T/CGRAPH_UINT_T", /**< TYPE  3 : CGRAPH_INT_T/CGRAPH_UINT_T */
    "CGRAPH_LONG_T/CGRAPH_ULONG_T/CGRAPH_SIZE_T/CGRAPH_USIZE_T", /**< TYPE  4 :
                                                                  * CGRAPH_LONG_T
                                                                /CGRAPH_ULONG_T/CGRAPH_SIZE_T/CGRAPH_USIZE_T
                                                              */
    "CGRAPH_INT8_T/CGRAPH_UINT8_T/CGRAPH_CHAR_T/CGRAPH_UCHAR_T", /**< TYPE  5 :
                                                                  * CGRAPH_INT8_T/CGRAPH_UINT8_T/CGRAPH_CHAR_T/CGRAPH_UCHAR_T
                                                                  */
    "CGRAPH_INT16_T/CGRAPH_UINT16_T",                            /**< TYPE  6 :
                                                                                              CGRAPH_INT16_T/CGRAPH_UINT16_T
                                                                  */
    "CGRAPH_INT32_T / CGRAPH_UINT32_T",                          /**< TYPE  7 :
                                                                    CGRAPH_INT32_T/CGRAPH_UINT32_T */
    "CGRAPH_INT64_T/CGRAPH_UINT64_T",                            /**< TYPE  8 :
                                                                    CGRAPH_INT64_T/CGRAPH_UINT64_T */
    "CGRAPH_INT128_T/CGRAPH_UINT128_T",                          /**< TYPE  9 :
                                                                    CGRAPH_INT128_T/CGRAPH_UINT128_T */
    "CGRAPH_FLOAT8_T",   /**< TYPE 10 : CGRAPH_FLOAT8_T */
    "CGRAPH_FLOAT16_T",  /**< TYPE 11 : CGRAPH_FLOAT16_T */
    "CGRAPH_FLOAT32_T",  /**< TYPE 12 : CGRAPH_FLOAT32_T */
    "CGRAPH_FLOAT64_T",  /**< TYPE 13 : CGRAPH_FLOAT64_T */
    "CGRAPH_FLOAT128_T", /**< TYPE 14 : CGRAPH_FLOAT128_T */
    "CGRAPH_TIME_T",     /**< TYPE 15 : CGRAPH_TIME_T */
    "CGRAPH_COMPLEX_T",  /**< TYPE 16 : CGRAPH_COMPLEX_T */
    "CGRAPH_FRACTION_T", /**< TYPE 17 : CGRAPH_FRACTION_T */
    "CGRAPH_BITSET_T",   /**< TYPE 18 : CGRAPH_BITSET_T */
    "CGRAPH_BIGINT_T",   /**< TYPE 19 : CGRAPH_BIGINT_T */
    "CGRAPH_BIGNUM_T",   /**< TYPE 20 : CGRAPH_BIGNUM_T */
    "CGRAPH_STRING_T",   /**< TYPE 21 : CGRAPH_STRING_T */
    "CGRAPH_VECTOR_T",   /**< TYPE 22 : CGRAPH_VECTOR_T */
    "CGRAPH_MATRIX_T",   /**< TYPE 23 : CGRAPH_MATRIX_T */
    "CGRAPH_MATRIX3D_T", /**< TYPE 24 : CGRAPH_MATRIX3D_T */
    "CGRAPH_BIGMAT_T",   /**< TYPE 25 : CGRAPH_BIGMAT_T */
    "CGRAPH_BIGMAT3D_T", /**< TYPE 26 : CGRAPH_BIGMAT3D_T */
    "CGRAPH_SPAMAT_T",   /**< TYPE 27 : CGRAPH_SPAMAT_T */
    "CGRAPH_SPAMAT3D_T", /**< TYPE 28 : CGRAPH_SPAMAT3D_T */
    "CGRAPH_DFRAME_T",   /**< TYPE 29 : CGRAPH_DFRAME_T */
    "CGRAPH_DICT_T",     /**< TYPE 30 : CGRAPH_DICT_T */
    "CGRAPH_SET_T",      /**< TYPE 31 : CGRAPH_SET_T */
    "CGRAPH_LIST_T",     /**< TYPE 32 : CGRAPH_LIST_T */
    "CGRAPH_QUEUE_T",    /**< TYPE 33 : CGRAPH_QUEUE_T */
    "CGRAPH_TREE_T",     /**< TYPE 34 : CGRAPH_TREE_T */
    NULL                 /**< TYPE 35 : CGRAPH_MAX_T */
};

const cgraph_char_t **cgraph_version_types(void) { return __cgraph_types__; }

const cgraph_char_t *cgraph_version_tname(const cgraph_size_t type) {
  return ((CGRAPH_OBJECT_T <= type) && (CGRAPH_MAX_T > type))
             ? __cgraph_types__[type]
             : NULL;
}

cgraph_size_t cgraph_version_tprintln(const cgraph_char_t *sep) {
  cgraph_size_t len = 0;
  CGRAPH_LOOP(i, CGRAPH_OBJECT_T, CGRAPH_MAX_T)
  len += cgraph_file_fprintfln(stdout, "%d%s%s", i, sep, __cgraph_types__[i]);
  CGRAPH_LOOP_END

  return len;
}

cgraph_size_t cgraph_version_tfprintln(FILE *fp, const cgraph_char_t *sep) {
  cgraph_size_t len = 0;
  CGRAPH_LOOP(i, CGRAPH_OBJECT_T, CGRAPH_MAX_T)
  len += cgraph_file_fprintfln(fp, "%d%s%s", i, sep, __cgraph_types__[i]);
  CGRAPH_LOOP_END

  return len;
}
