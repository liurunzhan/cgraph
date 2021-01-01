#!/usr/local/bin/io

PRO := "cgraph"
DIR := "."
INC := Directory clone setPath("#{DIR}/include" interpolate)
SRC := Directory clone setPath("#{DIR}/src" interpolate)
TST := Directory clone setPath("#{DIR}/test" interpolate)
LIB := Directory clone setPath("#{DIR}/lib" interpolate)

CC := "cc"
CFLAGS := "-std=c89 -Wall -pedantic -fPIC"
CSFLAGS := "-shared"

MODE := "debug"
if(MODE == "debug") then(
  CFLAGS := CFLAGS .. " -g -DDEBUG"
) elseif(MODE == "release") then(
  CFLAGS := CFLAGS .. "-static -O2"
)

# package shared library
AR := "ar"
ARFLAGS := "-rcs"

LIBSHARED := ""
LIBSTATIC := ""
TSTFILE := ""
TSTTARGET := ""
if(System platform == "windows") then(
  # target files
  LIBSHARED := File clone setPath("#{LIB}/lib#{PRO}.dll" interpolate)
  LIBSTATIC := File clone setPath("#{LIB}/lib#{PRO}.a" interpolate)
  # test files
  TSTFILE := File clone setPath("#{TST}/#{PRO}.c" interpolate)
  TSTTARGET := File clone setPath("#{TST}/#{PRO}.exe" interpolate)
) else(
  # target files
  LIBSHARED := File clone setPath("#{LIB}/lib#{PRO}.so" interpolate)
  LIBSTATIC := File clone setPath("#{LIB}/lib#{PRO}.a" interpolate)
  # test files
  TSTFILE := File clone setPath("#{TST}/#{PRO}.c" interpolate)
  TSTTARGET := File clone setPath("#{TST}/#{PRO}" interpolate)
)

CFILES := SRC filesWithExtension(".c")

args := System args

if(args size == 1) then(
  "haha" println
  LIB create
  OFILES := List clone
  CFILES foreach(file, 
    # obj = replace(file, r".c$"=>".o")
    # push!(OFILES, obj)
    "compile #{file} to #{obj}" interpolate println
    # run(`$CC $CFLAGS -I$INC -c $src_path -o $obj_path`)
  )
  "compile #{LIBSHARED}" interpolate println
  # run(`$CC $CSFLAGS -o $LIBSHARED $OFILES`)
  "compile #{LIBSTATIC}" interpolate println
  # run(`$AR $ARFLAGS $LIBSTATIC $OFILES`)
) elseif(args at(1) == "test") then(
  "compile #{TSTFILE name}" interpolate println
  "compile #{TSTFILE path} to #{TSTTARGET path}" interpolate println
  # run(`$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm`)
  tst_path := Directory clone setPath("#{TST}/elements.csv" interpolate)
  "test #{TSTTARGET} with #{tst_path}" interpolate println
  # run(`$TSTTARGET $tst_path`)
) elseif(args at(1) == "clean") then(
  # CFILES foreach(file,
  #   obj = replace(file, r".c$"=>".o")
  #   "clean #{obj}" interpolate println
  #   obj remove
  # )
  "clean #{LIBSTATIC}" interpolate println
  rm(LIBSTATIC, force=true)
  "clean #{LIBSHARED}" interpolate println
  rm(LIBSHARED, force=true)
  "clean #{TSTTARGET}" interpolate println
  rm(TSTTARGET, force=true)
) elseif(args at(1) == "distclean") then(
  # CFILES foreach(file,
  #   obj = replace(file, r".c$"=>".o")
  #   "clean #{obj}" interpolate println
  #   obj remove
  # )
  "clean #{LIBSTATIC}" interpolate println
  LIBSTATIC remove
  "clean #{LIBSHARED}" interpolate println
  LIBSHARED remove
  "clean #{LIB}" interpolate println
  LIB remove
  "clean #{TSTTARGET}" interpolate println
  TSTTARGET remove
) elseif(args at(1) == "help") then(
  "#{args[0]}    <target>" interpolate println
  "<target>: " println
  "                    compile cgraph" println
  "          test      test cgraph" println
  "          clean     clean all the generated files" println
  "          distclean clean all the generated files and directories" println
  "          help      commands to this program" println
) else(
  "#{args at(1)} is an unsupported command" interpolate println
  "use \"#{args at(0)} help\" to know all supported commands" interpolate println
)