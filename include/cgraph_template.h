/**
 * @file cgraph_template.h
 * @brief define the common-defined macros
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
 * @url https://github.com/liurunzhan/cgraph
 */

/*
```mermaid
    cgraph_template.h[cgraph_template] --data-based-->
cgraph_template_data.ht(cgraph_template_data)
    cgraph_template_data.ht(cgraph_template_data) --"object-based"-->
cgraph_template_object.ht([cgraph_template_object])
    cgraph_template_data.ht(cgraph_template_data) --int-based-->
template_int.ht([cgraph_template_int])
    cgraph_template_data.ht(cgraph_template_data) --float-based-->
template_float.ht([cgraph_template_float])
    cgraph_template_data.ct(cgraph_template_data) --point-based-->
template_point.ht([cgraph_template_point])
    template_base.ht[template_base] --structure based-->
cgraph_template_struct.ht(cgraph_template_struct)
    cgraph_template_struct.ht(template_struct) --matrix-based-->
template_matrix.ht([cgraph_template_matrix])
    cgraph_template_struct.ht(cgraph_template_struct)
--3d-matrix-based--> cgraph_template_matrix3d.ht([cgraph_template_matrix3d])
 ```
 */

#define CONCAT1V(a) #a
#define CONCAT1(a) CONCAT1V(a)
#define CONCAT2V(a, b) a##_##b
#define CONCAT2(a, b) CONCAT2V(a, b)
#define CONCAT3V(a, b, c) a##_##b##_##c
#define CONCAT3(a, b, c) CONCAT3V(a, b, c)
#define CONCAT4V(a, b, c, d) a##_##b##_##c##_##d
#define CONCAT4(a, b, c, d) CONCAT4V(a, b, c, d)

#define TYPE_T(a) CONCAT3(cgraph, a, t)
#define ID_T(a) CONCAT3(CGRAPH, a, T)
#define STRUCT(a) CONCAT3(__cgraph, a, vfptr)
#define SFLOAT(a) CONCAT3(__cgraph, a, t)
#define STRING(a) CONCAT1(a)
#define FUNCTION(a, b) CONCAT3(cgraph, a, b)

/** property inheritance of data and structure types */
#define CGRAPH_BASE cgraph_size_t size, len;
#define CGRAPH_SIZE(x) ((NULL != (x)) ? (x)->size : SIZE_C(0))
#define CGRAPH_LEN(x) ((NULL != (x)) ? (x)->len : SIZE_C(0))
#define CGRAPH_LENEQ2V(x, y)                                                   \
  ((NULL != (x)) && (NULL != (y)) && ((x)->len == (y)->len))
#define CGRAPH_ISNULL(x) ((NULL == (x)) || (SIZE_C(0) >= (x)->size))
#define CGRAPH_HASMEM(x) ((NULL != (x)) && (SIZE_C(0) < (x)->size))
#define CGRAPH_ISEMPTY(x) ((NULL == (x)) || (SIZE_C(0) >= (x)->len))
#define CGRAPH_HASDATA(x) ((NULL != (x)) && (SIZE_C(0) < (x)->len))
#define CGRAPH_DATA_BITCHK(x, bits)                                            \
  ((NULL != (x)) && ((bits >> DATA_L2BITS) <= (x)->len))
#define CGRAPH_DATA_BYTECHK(x, bits)                                           \
  ((NULL != (x)) && ((bits >> (3 * DATA_L2BITS)) <= (x)->len))

/** property inheritance of object types */
#define CGRAPH_OBJECT_BASE cgraph_element_t element;

#define CGRAPH_OBJECT_ROOT DATA_TYPE data;

#if (__STDC_VERSION__ >= 199901L)
#define CGRAPH_DATA_ROOT DATA_TYPE *data, root[];
#else
#define CGRAPH_DATA_ROOT DATA_TYPE *data, *root;
#endif /** __STDC_VERSION__ */

/** get the value of given index in data of an object */
#define CGRAPH_DATA(x, idx) ((x)->data[(idx)])
/** get the address of given index in data of an object */
#define CGRAPH_DATA_ADDR(x, idx) (&CGRAPH_DATA(x, idx))
/** get the header address in data of an object */
#define CGRAPH_DATA_HADDR(x) CGRAPH_DATA_ADDR(x, 0)
/** get the tail address in data of an object */
#define CGRAPH_DATA_TADDR(x) CGRAPH_DATA_ADDR(x, (x)->len - 1)

#define CGRAPH_STRUCTURE_BASE                                                  \
  CGRAPH_BASE                                                                  \
  CGRAPH_OBJECT_BASE

#define CGRAPH_STRUCTURE_PTR1 cgraph_snode1_t *header, *tail;
#define CGRAPH_STRUCTURE_PTR2 cgraph_snode2_t *header, *tail;

#define CGRAPH_STRUCTURE_ROOT DATA_TYPE data, root;

/** 2D MATRIX */
#define CGRAPH_MATRIX_INDEXES cgraph_size_t row, column;
#define MATRIX_ROW(x) ((x)->row)
#define MATRIX_COLUMN(x) ((x)->column)
#define MATRIX_SET_INDEX(x, row, column)                                       \
  do {                                                                         \
    MATRIX_ROW(x) = (row);                                                     \
    MATRIX_COLUMN(x) = (column);                                               \
  } while (0)

#define MATRIX_SIZE(x) (MATRIX_ROW(x) * MATRIX_COLUMN(x))

#define CGRAPH_MATRIX_ROW(x) ((NULL != (x)) ? MATRIX_ROW(x) : SIZE_C(0))
#define CGRAPH_MATRIX_COLUMN(x) ((NULL != (x)) ? MATRIX_COLUMN(x) : SIZE_C(0))
#define CGRAPH_MATRIX_SIZE(x) ((NULL != (x)) ? MATRIX_SIZE(x) : SIZE_C(0))

/** 3D MATRIX */
#define CGRAPH_MATRIX3D_INDEXES cgraph_size_t index_i, index_j, index_k;
#define MATRIX3D_INDEX_I(x) ((x)->index_i)
#define MATRIX3D_INDEX_J(x) ((x)->index_j)
#define MATRIX3D_INDEX_K(x) ((x)->index_k)
#define MATRIX3D_INDEX_SET(x, index_i, index_j, index_k)                       \
  do {                                                                         \
    MATRIX3D_INDEX_I(x) = (index_i);                                           \
    MATRIX3D_INDEX_J(x) = (index_j);                                           \
    MATRIX3D_INDEX_K(x) = (index_k);                                           \
  } while (0)

#define MATRIX3D_SIZE_IJ(x) (MATRIX3D_INDEX_I(x) * MATRIX3D_INDEX_J(x))
#define MATRIX3D_SIZE_IK(x) (MATRIX3D_INDEX_I(x) * MATRIX3D_INDEX_K(x))
#define MATRIX3D_SIZE_JK(x) (MATRIX3D_INDEX_J(x) * MATRIX3D_INDEX_K(x))
#define MATRIX3D_SIZE(x)                                                       \
  (MATRIX3D_INDEX_I(x) * MATRIX3D_INDEX_J(x) * MATRIX3D_INDEX_K(x))

#define CGRAPH_MATRIX3D_INDEX_I(x)                                             \
  ((NULL != (x)) ? MATRIX3D_INDEX_I(x) : SIZE_C(0))
#define CGRAPH_MATRIX3D_INDEX_J(x)                                             \
  ((NULL != (x)) ? MATRIX3D_INDEX_J(x) : SIZE_C(0))
#define CGRAPH_MATRIX3D_INDEX_K(x)                                             \
  ((NULL != (x)) ? MATRIX3D_INDEX_K(x) : SIZE_C(0))
#define CGRAPH_MATRIX3D_SIZE_IJ(x)                                             \
  ((NULL != (x)) ? MATRIX3D_SIZE_IJ(x) : SIZE_C(0))
#define CGRAPH_MATRIX3D_SIZE_IK(x)                                             \
  ((NULL != (x)) ? MATRIX3D_SIZE_IK(x) : SIZE_C(0))
#define CGRAPH_MATRIX3D_SIZE_JK(x)                                             \
  ((NULL != (x)) ? MATRIX3D_SIZE_JK(x) : SIZE_C(0))
#define CGRAPH_MATRIX3D_SIZE(x) ((NULL != (x)) ? MATRIX3D_SIZE(x) : SIZE_C(0))
