#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cgraph], [0.0.0], [liurunzhan@sina.com])
AC_CONFIG_SRCDIR([include/cgraph.h])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall])
AC_CONFIG_MACRO_DIR([m4])
PKG_PROG_PKG_CONFIG

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AM_PROG_AR
AC_PROG_LIBTOOL
AC_LIBTOOL_WIN32_DLL
LT_PREREQ([2.4.0])
LT_INIT

# Checks for gtk-doc.
GTK_DOC_CHECK([1.14], [--flavour no-tmpl])

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [pow])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([float.h limits.h stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MEMCMP
AC_FUNC_MKTIME
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset pow sqrt])

# Checks for DEBUG or RELEASE mode
AC_ARG_ENABLE(debug,
[  --enable-debug    Turn on debugging],
[case "${enableval}" in
  yes) debug=true ;;
  no)  debug=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
esac], [debug=false])
AM_CONDITIONAL(DEBUG, test x$debug = xtrue)

AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 src/Makefile
                 test/Makefile])
AC_OUTPUT
