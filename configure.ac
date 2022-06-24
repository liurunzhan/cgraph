#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cgraph], [0.0.0], [liurunzhan@sina.com], [cgraph], [https://github.com/liurunzhan/cgraph])
AC_SUBST([PACKAGE_AUTHOR], [liurunzhan])
AC_SUBST([PACKAGE_LISENCE], [GPL-3.0])
AC_SUBST([PACKAGE_BRIEF], ["A C Library for Graph And Mathematical Analysis"])
AC_CONFIG_SRCDIR([include/cgraph.h])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])
PKG_PROG_PKG_CONFIG

# cite from autoconf-archive : 
# https://www.gnu.org/software/autoconf-archive/The-Macros.html
m4_include([m4/ax_c_long_long.m4])
m4_include([m4/ax_c_var_func.m4])
m4_include([m4/ax_cache_size.m4])
m4_include([m4/ax_compile_check_sizeof.m4])
m4_include([m4/ax_create_stdint_h.m4])
m4_include([m4/ax_valgrind_check.m4])
m4_include([m4/m4_ax_c___attribute__.m4])
m4_include([m4/m4_ax_c_compile_value.m4])
m4_include([m4/m4_ax_c_var_func.m4])
m4_include([m4/m4_ax_printf_size_t.m4])
m4_include([m4/m4_ax_prog_cc_for_build.m4])
m4_include([m4/m4_ax_prog_cxx_for_build.m4])

# Checks for programs.
AC_DEFINE([cgraph_test], ["Hello, World\n"],
  [Greetings string.])
AC_LANG(C)
AC_LANG_CONFTEST(
[AC_LANG_PROGRAM([[const char hw[] = "Hello, World\n";]],
                 [[fputs (hw, stdout);]])])
AC_LANG(C++)
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
AX_VALGRIND_DFLT([memcheck], [on])
AX_VALGRIND_CHECK

# Checks for gtk-doc.
# check for gtk-doc
GTK_DOC_CHECK([1.14], [--flavour no-tmpl])

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [fabs pow sqrt log sin cos tan atan2])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_TIME
AC_CHECK_HEADERS([stdio.h stdlib.h string.h math.h float.h limits.h stdarg.h inttypes.h stddef.h stdint.h unistd.h sys/stat.h dirent.h io.h windows.h])
AX_CREATE_STDINT_H(include/cgraph_stdint.h)

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AX_C_LONG_LONG
AC_CHECK_TYPES(long double)

AC_STRUCT_TM
AX_PRINTF_SIZE_T
AX_C_REFERENCEABLE_PASSED_VA_LIST
AX_PROG_CC_FOR_BUILD
AX_PROG_CXX_FOR_BUILD

AC_C_CONST
AC_C_INLINE
AX_C_VAR_FUNC
AC_C_BIGENDIAN

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MEMCMP
AC_FUNC_MKTIME
AC_FUNC_REALLOC
AC_CHECK_FUNCS([alloc calloc realloc memset memcpy strcpy srand rand])

# Checks for DEBUG or RELEASE mode
AC_ARG_ENABLE(debug, AS_HELP_STRING([--enable-debug], [turn on debugging]),
[case "${enableval}" in
  yes) debug=true ;;
  no)  debug=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
esac], [debug=false])
AM_CONDITIONAL(enable_debug, test x$debug = xtrue)

AC_ARG_WITH(stdc, AS_HELP_STRING([--with-stdc], [set C standard with given compiler]), AC_SUBST(enable_stdc, true), AC_SUBST(enable_stdc, false))
AC_SUBST(stdc, $stdc)

# Checks for building in a git repo or not
AC_CHECK_FILES([include/cgraph_template_off.h.in tools/template_off.macro include/cgraph_template_check.h.in tools/template_check.macro include/cgraph_stdchk.h.in tools/stdchk.macro tools/macro.py tools/enum2array.py], AC_SUBST(in_git_repo, true), AC_SUBST(in_git_repo, false))
AM_CONDITIONAL(built_in_git_repo, test x$in_git_repo = xtrue)

AC_CONFIG_FILES([Makefile
                 cgraph.pc
								 Doxyfile
                 doc/Makefile
                 src/Makefile
								 src/func/Makefile
								 src/game/Makefile
								 src/graph/Makefile
								 src/type/Makefile
								 src/type/basic/Makefile
								 src/type/data/Makefile
								 src/type/object/Makefile
								 src/type/structure/Makefile
                 test/Makefile
								 tools/cgraph.json])
AC_OUTPUT
