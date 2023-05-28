#!/bin/zsh

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

# project
PRO=cgraph

# directory tree
DIR=`pwd`
INC=${DIR}/include
SRC=${DIR}/src
SRC_TYPE=${SRC}/type
TST=${DIR}/tests
LIB=${DIR}/lib

# compiler configuration
CC=cc
CFLAGS=(-std=c89 -Wall -pedantic -fPIC)
CSFLAGS=(-shared)

if [[ ${CC} != "tcc" ]] {
  CFLAGS+=(-pedantic-errors)
}

# debug or release mode
MODE="debug"
if [[ ${MODE} == "debug" ]] {
  CFLAGS+=(-g -DDEBUG)
} elif [[ ${MODE} == "release" ]] {
  CFLAGS+=(-O2)
}

# build and clean directories and files
MKDIR=mkdir
MKDIRFLAGS=(-p)
RM=rm
RMFLAGS=(-f)

RMDIR=rm
RMDIRFLAGS=(-rf)

# package shared library
AR=ar
ARFLAGS=(-rcs)

# source files
CFILES=(`find $SRC -type f -name '*.c' -not -name '.*'`)
# target files
LIBSHARED=$LIB/lib$PRO.so
LIBSTATIC=$LIB/lib$PRO.a
# test files
TSTFILE=$TST/$PRO.c
TSTTARGET=$TST/$PRO

if (( $# == 0 )) {
  $MKDIR $MKDIRFLAGS $LIB
  OFILES=""
  for file ($CFILES) {
    obj=`echo $file | sed 's/\.c$/\.o/g'`
    dep=`echo $file | sed 's/\.c$/\.d/g'`
    echo "compile $file to $obj"
    OFILES="$OFILES $obj"
    $CC $CFLAGS -I$INC -I$SRC_TYPE -c $file -o $obj -MD -MF $dep
  }
  echo "compile $LIBSHARED"
  $CC $CSFLAGS -o $LIBSHARED $OFILES
  echo "compile $LIBSTATIC"
  $AR $ARFLAGS $LIBSTATIC $OFILES
} elif [[ $1 == "test" ]] {
  echo "compile $TSTFILE to $TSTTARGET"
  $CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm
  echo "test $TSTTARGET with $TST/elements.csv"
  $TSTTARGET $TST/elements.csv
} elif [[ $1 == "clean" ]] {
  for file ($CFILES) {
    obj=`echo $file | sed 's/\.c$/\.o/g'`
    echo "clean $obj"
    $RM $RMFLAGS $obj
    dep=`echo $file | sed 's/\.c$/\.d/g'`
    echo "clean $dep"
    $RM $RMFLAGS $dep
  }
  echo "clean $LIBSHARED"
  $RM $RMFLAGS $LIBSHARED
  echo "clean $LIBSTATIC"
  $RM $RMFLAGS $LIBSTATIC
  echo "clean $TSTTARGET"
  $RM $RMFLAGS $TSTTARGET
} elif [[ $1 == "distclean" ]] {
  for file ($CFILES) {
    obj=`echo $file | sed 's/\.c$/\.o/g'`
    echo "clean $obj"
    $RM $RMFLAGS $obj
    dep=`echo $file | sed 's/\.c$/\.d/g'`
    echo "clean $dep"
    $RM $RMFLAGS $dep
  }
  echo "clean $LIBSHARED"
  $RM $RMFLAGS $LIBSHARED
  echo "clean $LIBSTATIC"
  $RM $RMFLAGS $LIBSTATIC
  echo "clean $LIB"
  $RMDIR $RMDIRFLAGS $LIB
  echo "clean $TSTTARGET"
  $RM $RMFLAGS $TSTTARGET
} elif [[ $1 == "help" ]] {
  echo "$0 <target>"
  echo "<target>: "
  echo "                    compile cgraph"
  echo "          test      test cgraph"
  echo "          clean     clean all the generated files"
  echo "          distclean clean all the generated files and directories"
  echo "          help      commands to this program"
} else {
  echo "$1 is an unsupported command"
  echo "use \"$0 help\" to know all supported commands"
}
