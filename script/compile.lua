#!/usr/bin/lua

require("package")
require('string')
require('os')
require('table')
require('lfs')

SEPARATOR = string.sub(package.config, 0, 1)

PRO = "cgraph"
DIR = "."
INC = DIR .. SEPARATOR .. "include"
SRC = DIR .. SEPARATOR .. "src"
TST = DIR .. SEPARATOR .. "test"
LIB = DIR .. SEPARATOR .. "lib"

CC = "cc"
CFLAGS = "-pedantic -Wall -fPIC -std=c89"
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
  if string.match(file, ".c$") then
    CFILES.append(SRC .. SEPARATOR .. file)
  end
end

args = ARGS
if length(args) == 0 then
  lfs.mkdir(LIB)
  OFILES = {}
  for file in CFILES do
    obj = string.gsub(file, ".c$", ".o")
    OFILES.append(obj)
    print(string.format("compile file to %s", obj))
    os.execute(string.format("%s %s -I%s -c %s -o %s", CC, CFLAGS, INC, file, obj))
  end
  print(string.format("compile %s", LIBSHARED))
  os.execute(string.format("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, table.concat(OFILES, " ")))
  print(string.format("compile %s", LIBSTATIC))
  os.execute(string.format("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, table.concat(OFILES, " ")))
elseif 1 == length(args) then
  if args[1] == "test" then
    print(string.format("compile %s to %s", TSTFILE, TSTTARGET))
    os.execute(string.format("%s %s -I%s -o %s $ -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
    print(string.format("test %s with %s", TSTTARGET, TST .. SEPARATOR .. "elements.csv"))
    os.execute(string.format("%s %s", TSTTARGET, TST .. SEPARATOR .. "elements.csv"))
  elseif args[1] == "clean" then
    for file in CFILES do
      obj = string.gsub(file, ".c$", ".o")
      print(string.format("clean %s", obj))
      os.remove(obj)
    end
    print(string.format("clean %s", LIBSTATIC))
    os.remove(LIBSTATIC)
    print(string.format("clean %s", LIBSHARED))
    os.remove(LIBSHARED)
    print(string.format("clean %s", TSTTARGET))
    os.remove(TSTTARGET)
  elseif args[1] == "distclean" then
    for file in CFILES do
      obj = string.gsub(file, ".c$", ".o")
      print(string.format("clean %s", obj))
      os.remove(obj)
    end
    print(string.format("clean %s", LIBSTATIC))
    os.remove(LIBSTATIC)
    print(string.format("clean %s", LIBSHARED))
    os.remove(LIBSHARED)
    print(string.format("clean %s", LIB))
    os.remove(LIB)
    print(string.format("clean %s", TSTTARGET))
    os.remove(TSTTARGET)
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