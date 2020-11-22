#!/usr/bin/tclsh

set PRO "cgraph"
set DIR "."
set INC [file join ${DIR} "include"]
set SRC [file join ${DIR} "src"]
set TST [file join ${DIR} "test"]
set LIB [file join ${DIR} "lib"]

set CC "cc"
set CFLAGS "-pedantic -Wall -fPIC -std=c89"
set CSFLAGS "-shared"

set MODE "debug"
if {[string compare $MODE "debug"]} {
  append CFLAGS " -g -DDEBUG"
} elseif {[string compare $MODE "release"]} {
  append CFLAGS " -static -O2"
}

# package shared library
set AR "ar"
set ARFLAGS "-rcs"

set CFILES [glob ${SRC}/*.c]
puts $CFILES
for { set i 0 } { $i < [llength $CFILES] } { incr i } {
  set OBJ [string map {\.c$} $CFILES($i)]
  puts "$CFILES($i)"
}