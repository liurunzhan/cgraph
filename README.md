# cgraph

A C LIBRARY FOR GRAPH ANALYSIS

## Compilation

This library supports mingw32-make, make, cmake and xmake to compile this library with the version of debug (addtion c flags of "-g -DDEBUG") and release (addtion c flags of "-static -O2"), cross different platforms of mingw, msys, msys2, cgywin, wsl and linux.

This library also provides shell script [compile.sh](./compile.sh), z shell script [compile.zsh](./compile.zsh) and fish script [compile.fish](./compile.fish) in msys, msys2, cgywin, wsl and linux, batch script [compile.bat](./compile.bat) and powershell script [compile.ps1](./compile.ps1) in mingw to directly compile this library by C compiler without make tools. All the compile scripts provide the same command-line arguments, without any argument or with the arguments of test, clean, distclean and help.

What's more, this library provides perl script [compile.pl](./compile.pl), perl6 script [compile.p6](./compile.p6), ruby script [compile.rb](./compile.rb), python script [compile.py](./compile.py) to compile this library. Makes and shells are good enough to do some things well, but perl, perl6 and python can do the same as well.

Any compiler who supports ANSI C can compile this library well, such as mingw32-gcc, mingw-w64-i686-gcc, mingw-w64-x86_64-gcc, tcc, gcc and clang.

| tool | flags | |
| :-: | :-: | :-: |
| mingw32-gcc, mingw-w64-i686-gcc, mingw-w64-x86_64-gcc, tcc, gcc | -pedantic -Wall -fpic -std=c89 | -anis -pedantic -pedantic-errors -Wall -fpic |
| clang |  -pedantic -Wall -std=c89 | |

## Overview

Do what you want to do, and be what you want to be!

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

| TYPE | ID | C TYPE |
| :-: | :-: | :-: |
|  |  |  |  |



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

