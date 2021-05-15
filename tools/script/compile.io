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

LIBSHARED := nil
LIBSTATIC := nil
TSTFILE := nil
TSTTARGET := nil
if(System platform == "windows") then(
  # target files
  LIBSHARED := File clone setPath("#{LIB}/lib#{PRO}.dll" interpolate)
  LIBSTATIC := File clone setPath("#{LIB}/lib#{PRO}.lib" interpolate)
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
  LIB create
  OFILES := List clone
  CFILES foreach(file,
    file := file path 
    obj := file asMutable replaceSeq(".c", ".o")
    OFILES append(obj)
    "compile #{file} to #{obj}" interpolate println
    System system("#{CC} #{CFLAGS} -I#{INC path} -c #{file} -o #{obj}" interpolate )
  )
  OFILES := OFILES join(" ")
  "compile #{LIBSHARED name}" interpolate println
  System system("#{CC} #{CSFLAGS} -o #{LIBSHARED name} #{OFILES}" interpolate)
  "compile #{LIBSTATIC name}" interpolate println
  System system("#{AR} #{ARFLAGS} #{LIBSTATIC name} #{OFILES}" interpolate)
) elseif(args at(1) == "test") then(
  "compile #{TSTFILE name} to #{TSTTARGET name}" interpolate println
  System system("#{CC} #{CFLAGS} -I#{INC path} -o #{TSTTARGET name} #{TSTFILE name} -L#{LIB path} -static -l#{PRO} -lm" interpolate)
  tst_path := File clone setPath("#{TST}/elements.csv" interpolate)
  "test #{TSTTARGET name} with #{tst_path name}" interpolate println
  System system("#{TSTTARGET name} #{tst_path name}" interpolate)
) elseif(args at(1) == "clean") then(
  CFILES foreach(file,
    file := file path 
    obj := file asMutable replaceSeq(".c", ".o")
    "clean #{obj}" interpolate println
    if(obj asFile exists) then(
      obj asFile remove
    )
  )
  "clean #{LIBSTATIC name}" interpolate println
  if(LIBSTATIC exists) then(
    LIBSTATIC remove
  )
  "clean #{LIBSHARED name}" interpolate println
  if(LIBSHARED exists) then(
    LIBSHARED remove
  )
  "clean #{TSTTARGET name}" interpolate println
  if(TSTTARGET exists) then(
    TSTTARGET remove
  )
) elseif(args at(1) == "distclean") then(
  CFILES foreach(file,
    file := file path 
    obj := file asMutable replaceSeq(".c", ".o")
    "clean #{obj}" interpolate println
    if(obj asFile exists) then(
      obj asFile remove
    )
  )
  "clean #{LIBSTATIC name}" interpolate println
  if(LIBSTATIC exists) then(
    LIBSTATIC remove
  )
  "clean #{LIBSHARED name}" interpolate println
  if(LIBSHARED exists) then(
    LIBSHARED remove
  )
  "clean #{LIB path}" interpolate println
  if(LIB exists) then(
    LIB remove
  )
  "clean #{TSTTARGET name}" interpolate println
  if(TSTTARGET exists) then(
    TSTTARGET remove
  )
) elseif(args at(1) == "help") then(
  "#{args at(0)}    <target>" interpolate println
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