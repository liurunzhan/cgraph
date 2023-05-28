#!/usr/bin/tclsh

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

set PRO "cgraph"
set DIR "."
set INC [file join ${DIR} "include"]
set SRC [file join ${DIR} "src"]
set SRC_TYPE [file join ${SRC} "type"]
set TST [file join ${DIR} "tests"]
set LIB [file join ${DIR} "lib"]

set CC "cc"
set CFLAGS "-std=c89 -Wall -pedantic -fPIC"
set CSFLAGS "-shared"

if { $CC != "tcc" } {
  append CFLAGS " -pedantic-errors"
}

set MODE "debug"
if { [ string compare $MODE "debug" ] } {
  append CFLAGS " -g -DDEBUG -O0"
} elseif { [ string compare $MODE "release" ] } {
  append CFLAGS " -O2"
}

# build and clean directories and files
set MKDIR "mkdir"
set MKDIRFLAGS "-p"
set RM "rm"
set RMFLAGS "-f"

set RMDIR "rm"
set RMDIRFLAGS "-rf"

# package shared library
set AR "ar"
set ARFLAGS "-rcs"

# source files
proc getsubdirs {path} {
  global SRCS
  foreach dir [glob -nocomplain -type d [file join ${path} *]] {
    set len [array size SRCS]
    set SRCS(${len}) ${dir}
    getsubdirs ${dir}
  }
}

array set SRCS ""
getsubdirs $SRC

array set CFILES ""
foreach index [ array names SRCS ] {
  set dir $SRCS(${index})
  foreach file [ glob -nocomplain ${dir}/*.c ] {
    set basename [ glob -nocomplain -path $file -tails * ]
    if { 0 == [string match "." $basename ] } {
      set len [array size CFILES]
      set CFILES($len) $file
    }
  }
}

# target files
set LIBSHARED [ file join ${LIB} "lib${PRO}.so" ]
set LIBSTATIC [ file join ${LIB} lib${PRO}.a ]
# test files
set TSTFILE [ file join ${TST} ${PRO}.c ]
set TSTTARGET [ file join ${TST} ${PRO} ]

if { $argc == 0 } {
  exec sh -c "${MKDIR} ${MKDIRFLAGS} ${LIB}"
  set OFILES ""
  foreach index [ array names CFILES ] {
    set file $CFILES($index)
    regsub {\.c$} ${file} .o obj
    regsub {\.c$} ${file} .d dep
    puts "compile ${file} to ${obj}"
    catch { exec sh -c "${CC} ${CFLAGS} -I${INC} -I${SRC_TYPE} -c ${file} -o ${obj} -MD -MF ${dep}" } message
    if { [ string length $message ] != 0 } {
      puts $message
    }
    append OFILES " " $obj
  }
  puts "compile ${LIBSHARED}"
  catch { exec sh -c "${CC} ${CSFLAGS} -o ${LIBSHARED} ${OFILES}" } message
  if { [ string length $message ] != 0 } {
    puts $message
  }
  puts "compile ${LIBSTATIC}"
  catch { exec sh -c "${AR} ${ARFLAGS} ${LIBSTATIC} ${OFILES}" } message
  if { [ string length $message ] != 0 } {
    puts $message
  }
} elseif { [ lindex $argv 0 ] == "test" } {
  puts "compile ${TSTFILE} to ${TSTTARGET}"
  catch { exec sh -c "${CC} ${CFLAGS} -I${INC} -o ${TSTTARGET} ${TSTFILE} -L${LIB} -static -l${PRO} -lm" } message
  if { [ string length $message ] != 0 } {
    puts $message
  }
  puts "test ${TSTTARGET} with ${TST}/elements.csv"
  catch { exec sh -c "${TSTTARGET} ${TST}/elements.csv" } message
  if { [ string length $message ] != 0 } {
    puts $message
  }
} elseif { [ lindex $argv 0 ] == "clean" } {
  foreach index [ array names CFILES ] {
    set file $CFILES(${index})
    regsub {\.c$} ${file} .o obj
    puts "clean ${obj}"
    catch { exec sh -c "${RM} ${RMFLAGS} ${obj}" }
    regsub {\.c$} ${file} .d dep
    puts "clean ${dep}"
    catch { exec sh -c "${RM} ${RMFLAGS} ${dep}" }
  }
  puts "clean ${LIBSHARED}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${LIBSHARED}" }
  puts "clean ${LIBSTATIC}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${LIBSTATIC}" }
  puts "clean ${TSTTARGET}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${TSTTARGET}" }
} elseif { [ lindex $argv 0 ] == "distclean" } {
  foreach index [ array names CFILES ] {
    set file $CFILES(${index})
    regsub {.c$} ${file} .o obj
    puts "clean ${obj}"
    catch { exec sh -c "${RM} ${RMFLAGS} ${obj}" }
    regsub {.c$} ${file} .d dep
    puts "clean ${dep}"
    catch { exec sh -c "${RM} ${RMFLAGS} ${dep}" }
  }
  puts "clean ${LIBSHARED}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${LIBSHARED}" }
  puts "clean ${LIBSTATIC}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${LIBSTATIC}" }
  puts "clean ${LIB}"
  catch { exec sh -c "${RMDIR} ${RMDIRFLAGS} ${LIB}" }
  puts "clean ${TSTTARGET}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${TSTTARGET}" }
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
