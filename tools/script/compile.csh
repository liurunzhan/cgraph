#!/usr/bin/csh -f

set PRO="cgraph"
set DIR="."
set INC=${DIR}/"include"
set SRC=${DIR}/"src"
set TST=${DIR}/"test"
set LIB=${DIR}/"lib"

set CC="cc"
set CFLAGS="-std=c89 -Wall -pedantic"
set CSFLAGS="-shared"

if ( $CC != "tcc" ) then
  set CFLAGS="${CFLAGS} -pedantic-errors"
endif
set CFLAGS="${CFLAGS} -fPIC"

set MODE="debug"
if ( $MODE == "debug" ) then
  set CFLAGS="${CFLAGS} -g -DDEBUG"
else if ( $MODE == "release" ) then
  set CFLAGS="${CFLAGS} -static -O2"
endif

# package shared library
set AR="ar"
set ARFLAGS="-rcs"

# source files
set CFILES=`ls ${SRC}/*.c`
echo ${CFILES}

# target files
set LIBSHARED=${LIB}/lib${PRO}.so
set LIBSTATIC=${LIB}/lib${PRO}.a
# test files
set TSTFILE=${TST}/${PRO}.c
set TSTTARGET=${TST}/${PRO}

if ( $#argv == 0 ) then
  foreach file ($CFILES)
    regsub {.c$} $file .o obj
    regsub {.c$} $file .d dep
    echo "compile ${file} to ${obj}"
    ${CC} ${CFLAGS} -I${INC} -c ${file} -o ${obj} -MD -MF ${dep}
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
