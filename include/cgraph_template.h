/**
 * @file cgraph_template.h
 * @brief define the common defined macros
 * @author liurunzhan
 * @email liurunzhan@sina.com
 * @package cgraph
 * @version 0.0.0
 * @date 2021-03-31
 * @lisence GPL-3.0
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
#define STRUCT(a) CONCAT3(_cgraph, a, struct_)
#define STRING(a) CONCAT1(a)
#define FUNCPTR(a, b) CONCAT4(cgraph, a, b, t)
#define FUNCTION(a, b) CONCAT3(cgraph, a, b)

/**property inheritance of object types */
#define CGRAPH_OBJECT_BASE cgraph_element_t element;

#define CGRAPH_OBJECT_ROOT DATA_TYPE data;
#define CGRAPH_OBJECT_DATA_START(a) (&((a)->data[0]))

/**property inheritance of data and structure types */
#define CGRAPH_BASE cgraph_size_t size, len;
#define CGRAPH_SIZE(x) ((NULL != (x)) ? (x)->size : 0)
#define CGRAPH_LEN(x) ((NULL != (x)) ? (x)->len : 0)
#define CGRAPH_DATA_START(a) (&((a)->data[0]))
#define CGRAPH_DATA_END(a) (&((a)->data[(a)->len - 1]))
#define CGRAPH_ISNULL(x) ((NULL == (x)) || (0 >= (x)->size))
#define CGRAPH_HASMEM(x) ((NULL != (x)) && (0 < (x)->size))
#define CGRAPH_ISEMPTY(x) ((NULL == (x)) || (0 >= (x)->len))
#define CGRAPH_HASDATA(x) ((NULL != (x)) && (0 < (x)->len))
#define CGRAPH_DATA_BITS_CHECKER(x, bits)                                      \
  ((NULL != (x)) && ((bits / DATA_BITS) <= (x)->len))
#define CGRAPH_DATA_BYTES_CHECKER(x, bits)                                     \
  ((NULL != (x)) && ((bits / DATA_BYTES) <= (x)->len))

#if (__STDC_VERSION__ >= 199901L)
#define CGRAPH_DATA_ROOT DATA_TYPE *data, root[];
#else
#define CGRAPH_DATA_ROOT DATA_TYPE *data, *root;
#endif /**__STDC_VERSION__ */

#define CGRAPH_STRUCTURE_BASE                                                  \
  CGRAPH_BASE                                                                  \
  CGRAPH_OBJECT_BASE

#define CGRAPH_STRUCTURE_PTR1 cgraph_snode1_t *header, *tail;
#define CGRAPH_STRUCTURE_PTR2 cgraph_snode2_t *header, *tail;

#define CGRAPH_STRUCTURE_ROOT DATA_TYPE data, root;

#define CGRAPH_MATRIX_INDEXES cgraph_size_t row, column;

#define CGRAPH_MATRIX_ROW(x) ((NULL != (x)) ? (x)->row : 0)
#define CGRAPH_MATRIX_COLUMN(x) ((NULL != (x)) ? (x)->column : 0)
#define CGRAPH_MATRIX3D_INDEXES cgraph_size_t index_i, index_j, index_k;

#define CGRAPH_MATRIX3D_INDEX_I(x) ((NULL != (x)) ? (x)->index_i : 0)
#define CGRAPH_MATRIX3D_INDEX_J(x) ((NULL != (x)) ? (x)->index_j : 0)
#define CGRAPH_MATRIX3D_INDEX_K(x) ((NULL != (x)) ? (x)->index_k : 0)
