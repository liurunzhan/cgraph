[TOC]

# cgraph

## Overview

## Data Types

## Structural Types

## APIs

## Data Types

### Data Type List

| TYPE | ID | NAME | MACRO | DESCRIPTION |
| :-: | :-: | :-: | :-: | :-: |
| cgraph_object_t | CGRAPH_OBJECT_T | object | TYPE_OBJECT |  |
| cgraph_integer_t | CGRAPH_INTEGER_T | integer | TYPE_INTEGER | |
| cgraph_real_t | CGRAPH_REAL_T | real | TYPE_REAL | |
| cgraph_boolean_t | CGRAPH_BOOLEAN_T | boolean | TYPE_REAL |
| cgraph_float_t | CGRAPH_FLOAT_T | float | TYPE_FLOAT | |
| cgraph_long_t | CGRAPH_LONG_T | long | TYPE_LONG | |
| cgraph_int8_t | CGRAPH_INT8_T | int8 | TYPE_INT8 | |
| cgraph_int16_t | CGRAPH_INT16_T | int16 | TYPE_INT16 | |
| cgraph_int32_t | CGRAPH_INT32_T | int32 | TYPE_INT32 | |
| cgraph_int64_t | CGRAPH_INT64_T | int64 | TYPE_INT64 | |
| cgraph_complex_t | CGRAPH_COMPLEX_T | complex | TYPE_COMPLEX | |
| cgraph_fraction_t | CGRAPH_FRACTION_T | fraction | TYPE_FRACTION | |
| cgraph_bigint_t | CGRAPH_BIGINT_T | bigint | TYPE_BIGINT | |
| cgraph_bignum_t | CGRAPH_BIGNUM_T | bignum | TYPE_BIGNUM | |
| cgraph_string_t | CGRAPH_STRING_T | string | TYPE_STRING | |
| cgraph_bitset_t | CGRAPH_BITSET_T | bitset | TYPE_BITSET | |

### basic types

All basic data types in this library are the package of C-type data types, which makes it easy to cross 32-bit and 64-bit platforms.

| TYPE | ID | C TYPE |
| :-: | :-: | :-: |
| cgraph_integer_t | CGRAPH_INTEGER_T | int |
| cgraph_real_t | CGRAPH_REAL_T | double |
| cgraph_boolean_t | CGRAPH_BOOLEAN_T | int |
| cgraph_float_t | CGRAPH_FLOAT_T | float |
| cgraph_long_t | CGRAPH_LONG_T | long |
| cgraph_int8_t | CGRAPH_INT8_T | int8 |
| cgraph_int16_t | CGRAPH_INT16_T | int16 |
| cgraph_int32_t | CGRAPH_INT32_T | int32 |
| cgraph_int64_t | CGRAPH_INT64_T | int64 |



### cgraph_object_t

``` c
typedef struct 
{
  cgraph_type_t type;
  cgraph_size_t hash;
  void *data;
}cgraph_object_t;
```

### cgraph_complex_t

``` c
typedef struct 
{
  DATA_TYPE data[2];
}cgraph_complex_t;
```

### cgraph_fraction_t

``` c
typedef struct 
{
  DATA_TYPE data[2];
}cgraph_fraction_t;
```

### cgraph_bigint_t

``` c
typedef struct 
{
  cgraph_size_t len, size;
  cgraph_boolean_t pos;
  DATA_TYPE *root, *data;
}cgraph_bigint_t;
```

### cgraph_bignum_t

``` c
typedef struct 
{
  cgraph_size_t len, size, point;
  DATA_TYPE *root, *data;
}cgraph_bignum_t;
```

### cgraph_string_t

``` c
typedef struct 
{
  cgraph_size_t len, size;
  DATA_TYPE *root, *data;
}cgraph_string_t;
```

### cgraph_bitset_t


``` c
typedef struct 
{
  cgraph_size_t len, size;
  DATA_TYPE *root, *data;
}cgraph_bitset_t;
```

## Data Structures

### Data Structure List

| TYPE | ID | NAME | MACRO | FUNCTION |
| :-: | :-: | :-: | :-: | :-: |
| cgraph_vector_t | CGRAPH_VECTOR_T | vector | TYPE_VECTOR |  |
| cgraph_matrix_t | CGRAPH_MATRIX_T | matrix | TYPE_MATRIX |  |
| cgraph_bigmat_t | CGRAPH_BIGMAT_T | bigmat | TYPE_BIGMAT |  |
| cgraph_list_t | CGRAPH_LIST_T | list | TYPE_LIST |  |
| cgraph_htable_t | CGRAPH_HTABLE_T | htable | TYPE_HTABLE |  |
| cgraph_dframe_t | CGRAPH_DFRAME_T | dframe | TYPE_DFRAME |  |
| cgraph_graph_t | CGRAPH_GRAPH_T | graph | TYPE_GRAPH |  |

## Header Independence

![avatar](./headers.png)

![avatar](./sources.png)