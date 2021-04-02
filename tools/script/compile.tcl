#!/usr/bin/tclsh -f

set PRO "cgraph"
set DIR "."
set INC [file join ${DIR} "include"]
set SRC [file join ${DIR} "src"]
set TST [file join ${DIR} "test"]
set LIB [file join ${DIR} "lib"]

set CC "cc"
set CFLAGS "-std=c89 -Wall -pedantic"
set CSFLAGS "-shared"

if { [ $CC != "tcc" ] } {
  append CFLAGS " -pedantic-errors"
}
append CFLAGS " -fPIC"

set MODE "debug"
if { [ string compare $MODE "debug" ] } {
  append CFLAGS " -g -DDEBUG"
} elseif { [ string compare $MODE "release" ] } {
  append CFLAGS " -static -O2"
}

# package shared library
set AR ar
set ARFLAGS "-rcs"

# source files
set CFILES [glob ${SRC}/*.c]
# target files
set LIBSHARED ${LIB}/lib${PRO}.so
set LIBSTATIC ${LIB}/lib${PRO}.a
# test files
set TSTFILE ${TST}/${PRO}.c
set TSTTARGET ${TST}/${PRO}

if { [ $argc == 0 ] } {
  foreach file $CFILES {
    regsub {.c$} $file .o obj
    puts "compile ${file} to ${obj}"
    exec sh -c "${CC} ${CFLAGS} -I${INC} -c ${file} -o ${obj}"
  }
  puts "compile ${LIBSHARED}"
  exec sh -c "${CC} ${CSFLAGS} -o ${LIBSHARED} ${SRC}/*.o"
  puts "compile ${LIBSTATIC}"
  exec sh -c "${AR} ${ARFLAGS} ${LIBSTATIC} ${SRC}/*.o"
} elseif { [ lindex $argv 0 ] == "test" } {
  puts "compile ${TSTFILE} to ${TSTTARGET}"
  exec sh -c "${CC} ${CFLAGS} -I${INC} -o ${TSTTARGET} ${TSTFILE} -L${LIB} -static -l${PRO} -lm"
  puts "test ${TSTTARGET} with ${TST}/elements.csv"
  exec sh -c "${TSTTARGET} ${TST}/elements.csv"
} elseif { [ lindex $argv 0 ] == "clean" } {
  foreach file $CFILES {
    regsub {.c$} $file .o obj
    puts "clean ${obj}"
    exec sh -c "${CC} ${CFLAGS} -I${INC} -c ${file} -o ${obj}"
  }
  puts "clean ${LIBSHARED}"
  exec sh -c "${RM} ${RMFLAGS} ${LIBSHARED}"
  puts "clean ${LIBSTATIC}"
  exec sh -c "${RM} ${RMFLAGS} ${LIBSTATIC}"
  puts "clean ${TSTTARGET}"
  exec sh -c "${RM} ${RMFLAGS} ${TSTTARGET}"
} elseif { [ lindex $argv 0 ] == "distclean" } {
  foreach file $CFILES {
    regsub {.c$} $file .o obj
    puts "clean ${obj}"
    exec sh -c "${RM} ${RMFL} ${obj}"
  }
  puts "clean ${LIBSHARED}"
  exec sh -c "${RM} ${RMFLAGS} ${LIBSHARED}"
  puts "clean ${LIBSTATIC}"
  exec sh -c "${RM} ${RMFLAGS} ${LIBSTATIC}"
  puts "clean ${LIB}"
  exec sh -c "${RMDIR} ${RMDIRFLAGS} ${LIB}"
  puts "clean ${TSTTARGET}"
  exec sh -c "${RM} ${RMFLAGS} ${TSTTARGET}"
} elseif { [ lindex $argv 0 ] == "help" } {
  puts "$argv0 <target>"
  puts "<target>: "
  puts "                    compile cgraph"
  puts "          test      test cgraph"
  puts "          clean     clean all the generated files"
  puts "          distclean clean all the generated files and directories"
  puts "          help      commands to this program"
} else {
  puts "[ lindex $argv 0 ] is an unsupported command"
  puts "use \"$argv0 help\" to know all supported commands"
}