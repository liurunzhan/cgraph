#!/usr/bin/fish

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

# project
set PRO cgraph

# directory tree
set DIR `pwd`
set INC ${DIR}/include
set SRC ${DIR}/src
set SRC_TYPE ${SRC}/type
set TST ${DIR}/tests
set LIB ${DIR}/lib

# compiler configuration
set CC cc
set CFLAGS "-std=c89 -Wall -pedantic -fPIC"
set CSFLAGS "-shared"

if $CC != "tcc"
  set CFLAGS "${CFLAGS} -pedantic-errors"
end

# debug or release mode
set MODE "debug"
if $MODE = "debug"
  set CFLAGS "${CFLAGS} -g -DDEBUG"
else if $MODE = "release"
  set CFLAGS "${CFLAGS} -static -O2"
end

# build and clean directories and files
set MKDIR mkdir
set RM rm
set RMFLAGS "-rf"

set RMDIR rm
set RMDIRFLAGS "-rf"

# package shared library
set AR ar
set ARFLAGS "-rcs"

# source files
set CFILES `find ${SRC} -regex "^[^\.]*\.c$"`
# target files
set LIBSHARED ${LIB}/lib${PRO}.so
set LIBSTATIC ${LIB}/lib${PRO}.a
# test files
set TSTFILE ${TST}/${PRO}.c
set TSTTARGET ${TST}/${PRO}

# commands to $0
set OPT $1

if -z $1
  ${MKDIR} ${LIB} 
  for file in ${CFILES}
    obj=`echo ${file} | sed "s/\.c$/\.o/g"`
    dep=`echo ${file} | sed "s/\.c$/\.d/g"`
    echo "compile ${file} to ${obj}"
    ${CC} ${CFLAGS} -I${INC} -I${SRC_TYPE} -c ${file} -o ${obj} -MD -MF ${dep}
  end
  echo "compile ${LIBSHARED}"
  ${CC} ${CSFLAGS} -o ${LIBSHARED} ${SRC}/*.o
  echo "compile ${LIBSTATIC}"
  ${AR} ${ARFLAGS} ${LIBSTATIC} ${SRC}/*.o
else if $1 = "test"
  echo "compile ${TSTFILE} to ${TSTTARGET}"
  ${CC} ${CFLAGS} -I${INC} -o ${TSTTARGET} ${TSTFILE} -L${LIB} -static -l${PRO} -lm
  echo "test ${TSTTARGET} with ${TST}/elements.csv"
  ${TSTTARGET} ${TST}/elements.csv
else if $1 = "clean"
  for file in ${CFILES}
    obj=`echo ${file} | sed "s/\.c$/\.o/g"`
    echo "clean ${obj}"
    ${RM} ${RMFLAGS} ${obj}
    dep=`echo ${file} | sed "s/\.c$/\.d/g"`
    echo "clean ${dep}"
    ${RM} ${RMFLAGS} ${dep}
  end
  echo "clean ${LIBSHARED}"
  ${RM} ${RMFLAGS} ${LIBSHARED}
  echo "clean ${LIBSTATIC}"
  ${RM} ${RMFLAGS} ${LIBSTATIC}
  echo "clean ${TSTTARGET}"
  ${RM} ${RMFLAGS} ${TSTTARGET}
else if $1 = "distclean"
  for file in ${CFILES}
    obj=`echo ${file} | sed "s/\.c$/\.o/g"`
    echo "clean ${obj}"
    ${RM} ${RMFLAGS} ${obj}
    dep=`echo ${file} | sed "s/\.c$/\.d/g"`
    echo "clean ${dep}"
    ${RM} ${RMFLAGS} ${dep}
  end
  echo "clean ${LIBSHARED}"
  ${RM} ${RMFLAGS} ${LIBSHARED}
  echo "clean ${LIBSTATIC}"
  ${RM} ${RMFLAGS} ${LIBSTATIC}
  echo "clean ${LIB}"
  ${RMDIR} ${RMDIRFLAGS} ${LIB}
  echo "clean ${TSTTARGET}"
  ${RM} ${RMFLAGS} ${TSTTARGET}
else if $1 = "help"
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
end
