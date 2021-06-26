#!/bin/sh

# project
PRO=cgraph

# directory tree
DIR=`pwd`
INC=${DIR}/include
SRC=${DIR}/src
TST=${DIR}/test
LIB=${DIR}/lib

# compiler configuration
CC=cc
CFLAGS="-std=c89 -Wall -pedantic"
CSFLAGS="-shared"

if [ $CC != "tcc" ]; then
  CFLAGS="${CFLAGS} -pedantic-errors"
fi
CFLAGS="${CFLAGS} -fPIC"

# debug or release mode
MODE="debug"
if [ $MODE = "debug" ]; then
CFLAGS="${CFLAGS} -g -DDEBUG"
elif [ $MODE = "release"]; then
CFLAGS="${CFLAGS} -static -O2"
fi

# build and clean directories and files
MKDIR=mkdir
RM=rm
RMFLAGS="-rf"

RMDIR=rm
RMDIRFLAGS="-rf"

# package shared library
AR=ar
ARFLAGS="-rcs"

# source files
CFILES=`ls ${SRC}/*.c`
# target files
LIBSHARED=${LIB}/lib${PRO}.so
LIBSTATIC=${LIB}/lib${PRO}.a
# test files
TSTFILE=${TST}/${PRO}.c
TSTTARGET=${TST}/${PRO}

# commands to $0
OPT=$1

if [ -z $1 ]; then
  ${MKDIR} ${LIB} 
  for file in ${CFILES}; do
    obj=`echo ${file} | sed "s/\.c$/\.o/g"`
    dep=`echo ${file} | sed "s/\.c$/\.d/g"`
    echo "compile ${file} to ${obj}"
    ${CC} ${CFLAGS} -I${INC} -c ${file} -o ${obj} -MD -MF ${dep}
  done
  echo "compile ${LIBSHARED}"
  ${CC} ${CSFLAGS} -o ${LIBSHARED} ${SRC}/*.o
  echo "compile ${LIBSTATIC}"
  ${AR} ${ARFLAGS} ${LIBSTATIC} ${SRC}/*.o
elif [ $1 = "test" ]; then
  echo "compile ${TSTFILE} to ${TSTTARGET}"
  ${CC} ${CFLAGS} -I${INC} -o ${TSTTARGET} ${TSTFILE} -L${LIB} -static -l${PRO} -lm
  echo "test ${TSTTARGET} with ${TST}/elements.csv"
  ${TSTTARGET} ${TST}/elements.csv
elif [ $1 = "clean" ]; then
  for file in ${CFILES}; do
    obj=`echo ${file} | sed "s/\.c$/\.o/g"`
    echo "clean ${obj}"
    ${RM} ${RMFLAGS} ${obj}
    dep=`echo ${file} | sed "s/\.c$/\.d/g"`
    echo "clean ${dep}"
    ${RM} ${RMFLAGS} ${dep}
  done
  echo "clean ${LIBSHARED}"
  ${RM} ${RMFLAGS} ${LIBSHARED}
  echo "clean ${LIBSTATIC}"
  ${RM} ${RMFLAGS} ${LIBSTATIC}
  echo "clean ${TSTTARGET}"
  ${RM} ${RMFLAGS} ${TSTTARGET}
elif [ $1 = "distclean" ]; then
  for file in ${CFILES}; do
    obj=`echo ${file} | sed "s/\.c$/\.o/g"`
    echo "clean ${obj}"
    ${RM} ${RMFLAGS} ${obj}
    dep=`echo ${file} | sed "s/\.c$/\.d/g"`
    echo "clean ${dep}"
    ${RM} ${RMFLAGS} ${dep}
  done
  echo "clean ${LIBSHARED}"
  ${RM} ${RMFLAGS} ${LIBSHARED}
  echo "clean ${LIBSTATIC}"
  ${RM} ${RMFLAGS} ${LIBSTATIC}
  echo "clean ${LIB}"
  ${RMDIR} ${RMDIRFLAGS} ${LIB}
  echo "clean ${TSTTARGET}"
  ${RM} ${RMFLAGS} ${TSTTARGET}
elif [ $1 = "help" ]; then
  echo "$0 <target>"
  echo "<target>: "
  echo "                    compile cgraph"
  echo "          test      test cgraph"
  echo "          clean     clean all the generated files"
  echo "          distclean clean all the generated files and directories"
  echo "          help      commands to this program"
else
  echo "$1 is an unsupported command"
  echo "use \"$0 help\" to know all supported commands"
fi