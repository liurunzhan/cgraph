/**
 * @file cgraph_template_check.h
 * @brief the checker of common defined macros
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
 * Update the cgraph_template_check.h.in
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
 * MACRO GROUP : DATA TYPE MATHEMATICAL FUNCTIONS
 * ASSIGN ADD SUB MUL DIV DIVF INT
 * MODF MOD EQ NE GT GE LT LE CEIL FLOOR POW ABS
 * SIN COS TAN ASIN ACOS ATAN
 * SINH COSH TANH
 * LOG LOG2 LOG10
 * EXP SQRT SWAP
 * ROL3 ROR3 ROL4 ROR4
 * DATA_SWAP
 ******************************************************************************/

/*
  defined macro variables:
  #define ASSIGN
  #define ADD
  #define SUB
  #define MUL
  #define DIV
  #define DIVF
  #define INT
  #define MODF
  #define MOD
  #define EQ
  #define NE
  #define GT
  #define GE
  #define LT
  #define LE
  #define CEIL
  #define FLOOR
  #define POW
  #define ABS
  #define SIN
  #define COS
  #define TAN
  #define ASIN
  #define ACOS
  #define ATAN
  #define SINH
  #define COSH
  #define TANH
  #define LOG
  #define LOG2
  #define LOG10
  #define EXP
  #define SQRT
  #define SWAP
  #define ROL3
  #define ROR3
  #define ROL4
  #define ROR4
  #define DATA_SWAP
*/

/** DATA TYPE MATHEMATICAL FUNCTIONS */
#ifndef ASSIGN
#error undefined needed macro ASSIGN
#endif

#ifndef ADD
#error undefined needed macro ADD
#endif

#ifndef SUB
#error undefined needed macro SUB
#endif

#ifndef MUL
#error undefined needed macro MUL
#endif

#ifndef DIV
#error undefined needed macro DIV
#endif

#ifndef DIVF
#error undefined needed macro DIVF
#endif

#ifndef INT
#error undefined needed macro INT
#endif

#ifndef MODF
#error undefined needed macro MODF
#endif

#ifndef MOD
#error undefined needed macro MOD
#endif

#ifndef EQ
#error undefined needed macro EQ
#endif

#ifndef NE
#error undefined needed macro NE
#endif

#ifndef GT
#error undefined needed macro GT
#endif

#ifndef GE
#error undefined needed macro GE
#endif

#ifndef LT
#error undefined needed macro LT
#endif

#ifndef LE
#error undefined needed macro LE
#endif

#ifndef CEIL
#error undefined needed macro CEIL
#endif

#ifndef FLOOR
#error undefined needed macro FLOOR
#endif

#ifndef POW
#error undefined needed macro POW
#endif

#ifndef ABS
#error undefined needed macro ABS
#endif

#ifndef SIN
#error undefined needed macro SIN
#endif

#ifndef COS
#error undefined needed macro COS
#endif

#ifndef TAN
#error undefined needed macro TAN
#endif

#ifndef ASIN
#error undefined needed macro ASIN
#endif

#ifndef ACOS
#error undefined needed macro ACOS
#endif

#ifndef ATAN
#error undefined needed macro ATAN
#endif

#ifndef SINH
#error undefined needed macro SINH
#endif

#ifndef COSH
#error undefined needed macro COSH
#endif

#ifndef TANH
#error undefined needed macro TANH
#endif

#ifndef LOG
#error undefined needed macro LOG
#endif

#ifndef LOG2
#error undefined needed macro LOG2
#endif

#ifndef LOG10
#error undefined needed macro LOG10
#endif

#ifndef EXP
#error undefined needed macro EXP
#endif

#ifndef SQRT
#error undefined needed macro SQRT
#endif

#ifndef SWAP
#error undefined needed macro SWAP
#endif

#ifndef ROL3
#error undefined needed macro ROL3
#endif

#ifndef ROR3
#error undefined needed macro ROR3
#endif

#ifndef ROL4
#error undefined needed macro ROL4
#endif

#ifndef ROR4
#error undefined needed macro ROR4
#endif

#ifndef DATA_SWAP
#error undefined needed macro DATA_SWAP
#endif

/** end of cgraph_template_check */
