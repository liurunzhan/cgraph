#!/usr/bin/lua

require("package")
require('string')
require('os')
require('lfs')

SEPARATOR = string.sub(package.config, 0, 1)

PRO = "cgraph"
DIR = "."
SRC = DIR .. SEPARATOR .. "src"
INC = DIR .. SEPARATOR .. "include"
TST = DIR .. SEPARATOR .. "test"
LIB = DIR .. SEPARATOR .. "lib"

CC = "cc"
CFLAGS = "-pedantic -Wall -fpic -std=c89"
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug" then
  CFLAGS = CFLAGS .. " -g -DDEBUG"
elseif MODE == "release" then
  CFLAGS = CFLAGS .. " -static -O2"
end

-- package shared library
AR = "ar"
ARFLAGS = "-rcs"

CFILES = {}
for file in lfs.dir(SRC) do
  if string(file, ".c$") then
    CFILES.append(SRC .. SEPARATOR .. file)
  end
end

args = ARGS
if 0 == length(args) then
  mkpath("$LIB")
  for file in CFILES do
    obj = string.gsub(file, ".c$", ".o")
    print("compile $file to $obj")
    os.execute("$CC $CFLAGS -I$INC -c $file -o $obj")
  end
  print("compile $LIBSHARED")
  os.execute("$CC $CSFLAGS -o $LIBSHARED $SRC/*.o")
  print("compile $LIBSTATIC");
  os.execute("$AR $ARFLAGS $LIBSTATIC $SRC/*.o")
elseif 1 == length(args) then
  if args[1] == "test" then
  print("compile $TSTFILE to $TSTTARGET")
    os.execute("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm")
    tst_path = path.join(TST, "elements.csv")
    print("test $TSTTARGET with $tst_path")
    os.execute("$TSTTARGET $tst_path")
  elseif args[1] == "clean" then
    for file in CFILES do
      obj = string.gsub(file, ".c$", ".o")
      print("clean ", SRC .. SEPARATOR .. obj)
      os.remove(SRC .. SEPARATOR .. obj)
    end
    print("clean $LIBSTATIC")
    os.remove("$LIBSTATIC")
    print("clean $LIBSHARED")
    os.remove("$LIBSHARED")
    print("clean $TSTTARGET")
    os.remove("$TSTTARGET")
  elseif args[1] == "distclean" then
    for file in CFILES do
      obj = string.gsub(file, ".c$", ".o")
      print("clean $obj")
      os.remove("$obj")
    end
    print("clean $LIBSTATIC")
    os.remove("$LIBSTATIC")
    print("clean $LIBSHARED")
    os.remove("$LIBSHARED")
    print("clean $LIB")
    os.remove("$LIB")
    print("clean $TSTTARGET")
    os.remove("$TSTTARGET")
  elseif args[1] == "help" then
    print(PROGRAM_FILE, "    <target>")
    print("<target>: ")
    print("                    compile cgraph")
    print("          test      test cgraph")
    print("          clean     clean all the generated files")
    print("          distclean clean all the generated files and directories")
    print("          help      commands to this program")
  else
    print(args[1], " is an unsupported command")
    print("use \"", PROGRAM_FILE, " help\" to know all supported commands")
  end
else
  print(args[1], " is an unsupported command")
  print("use \"", PROGRAM_FILE, " help\" to know all supported commands")
end