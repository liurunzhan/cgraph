#!/usr/bin/csh -f

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

set PRO="cgraph"
set DIR="."
set INC="${DIR}/include"
set SRC="${DIR}/src"
set SRC_TYPE="${SRC}/type"
set TST="${DIR}/tests"
set LIB="${DIR}/lib"

set CC="cc"
set CFLAGS="-std=c89 -Wall -pedantic -fPIC"
set CSFLAGS="-shared"

if ( $CC != "tcc" ) then
  set CFLAGS="${CFLAGS} -pedantic-errors"
endif

set MODE="debug"
if ( $MODE == "debug" ) then
  set CFLAGS="${CFLAGS} -g -DDEBUG"
else if ( $MODE == "release" ) then
  set CFLAGS="${CFLAGS} -static -O2"
endif

# build and clean directories and files
set MKDIR=mkdir
set MKDIRFLAGS="-p"
set RM=rm
set RMFLAGS="-f"

set RMDIR=rm
set RMDIRFLAGS="-rf"

# package shared library
set AR=ar
set ARFLAGS="-rcs"

# source files
set CFILES=`find ${SRC} -regex "^[^\.]*\.c$"`
echo ${CFILES}

# target files
set LIBSHARED="${LIB}/lib${PRO}.so"
set LIBSTATIC="${LIB}/lib${PRO}.a"
# test files
set TSTFILE="${TST}/${PRO}.c"
set TSTTARGET="${TST}/${PRO}"

if ( $#argv == 0 ) then
  ${MKDIR} ${MKDIRFLAGS} ${MKDIR} 
  foreach file ($CFILES)
    regsub {.c$} $file .o obj
    regsub {.c$} $file .d dep
    echo "compile ${file} to ${obj}"
    ${CC} ${CFLAGS} -I${INC} -I${SRC_TYPE} -c ${file} -o ${obj} -MD -MF ${dep}
  end
  echo "compile ${LIBSHARED}"
  ${CC} ${CSFLAGS} -o ${LIBSHARED} ${SRC}/*.o
  echo "compile ${LIBSTATIC}"
  ${AR} ${ARFLAGS} ${LIBSTATIC} ${SRC}/*.o
else if ( $argv[1] == "test" ) then
  echo "compile ${TSTFILE} to ${TSTTARGET}"
  ${CC} ${CFLAGS} -I${INC} -o ${TSTTARGET} ${TSTFILE} -L${LIB} -static -l${PRO} -lm
  echo "test ${TSTTARGET} with ${TST}/elements.csv"
  ${TSTTARGET} ${TST}/elements.csv
else if ( $argv[1] == "clean" ) then
  foreach file ($CFILES)
    regsub {.c$} $file .o obj
    echo "clean ${obj}"
    ${RM} ${RMFLAGS} ${obj}
    regsub {.c$} $file .d dep
    echo "clean ${dep}"
    ${RM} ${RMFLAGS} ${dep}
  end
  echo "clean ${LIBSHARED}"
  ${RM} ${RMFLAGS} ${LIBSHARED}
  echo "clean ${LIBSTATIC}"
  ${RM} ${RMFLAGS} ${LIBSTATIC}
  echo "clean ${TSTTARGET}"
  ${RM} ${RMFLAGS} ${TSTTARGET}
else if ( $argv[1] == "distclean" ) then
  foreach file ($CFILES)
    regsub {.c$} $file .o obj
    echo "clean ${obj}"
    ${RM} ${RMFLAGS} ${obj}
    regsub {.c$} $file .d dep
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
else if ( $argv[1] == "help" ) then
  echo "${argv[0]} <target>"
  echo "<target>: "
  echo "                    compile cgraph"
  echo "          test      test cgraph"
  echo "          clean     clean all the generated files"
  echo "          distclean clean all the generated files and directories"
  echo "          help      commands to this program"
else
  echo "${argv[1]} is an unsupported command"
  echo "use \"${argv[0]} help\" to know all supported commands"
endif
