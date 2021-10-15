#!/usr/bin/tclsh

set PRO "cgraph"
set DIR "."
set INC [file join ${DIR} "include"]
set SRC [file join ${DIR} "src"]
set TST [file join ${DIR} "test"]
set LIB [file join ${DIR} "lib"]

set CC "cc"
set CFLAGS "-std=c89 -Wall -pedantic -fPIC"
set CSFLAGS "-shared"

if { $CC != "tcc" } {
  append CFLAGS " -pedantic-errors"
}

set MODE "debug"
if { [ string compare $MODE "debug" ] } {
  append CFLAGS " -g -DDEBUG"
} elseif { [ string compare $MODE "release" ] } {
  append CFLAGS " -static -O2"
}

# build and clean directories and files
set MKDIR "mkdir"
set RM "rm"
set RMFLAGS "-rf"

set RMDIR "rm"
set RMDIRFLAGS "-rf"

# package shared library
set AR "ar"
set ARFLAGS "-rcs"

# target files
set LIBSHARED ${LIB}/lib${PRO}.so
set LIBSTATIC ${LIB}/lib${PRO}.a
# test files
set TSTFILE ${TST}/${PRO}.c
set TSTTARGET ${TST}/${PRO}

if { $argc == 0 } {
  exec sh -c "mkdir -p ${LIB}"
	set OFILES ""
	foreach file [ glob -nocomplain ${SRC}/*.c ] {
    regsub {.c$} ${file} .o obj
		regsub {.c$} ${file} .d dep
    puts "compile ${file} to ${obj}"
		catch { exec sh -c "${CC} ${CFLAGS} -I${INC} -c ${file} -o ${obj} -MD -MF ${dep}" } message
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
	foreach file [ glob -nocomplain ${SRC}/*.c ] {
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
  puts "clean ${TSTTARGET}"
  catch { exec sh -c "${RM} ${RMFLAGS} ${TSTTARGET}" }
} elseif { [ lindex $argv 0 ] == "distclean" } {
	foreach file [ glob -nocomplain ${SRC}/*.c ] {
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
