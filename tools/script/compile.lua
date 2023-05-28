#!/usr/bin/lua

-- Date : 2022-07-01
-- A script to compile Library cgraph in Unix-like and Windows Platforms
-- gets source files iteratively from Directory src

require("package")
require('string')
require('os')
require('table')

-- Needs a third party library---luafilesystem, installed by "luarocks install luafilesystem"
require('lfs')

PSEP = string.sub(package.config, 0, 1)

PRO = "cgraph"
DIR = "."
INC = DIR .. PSEP .. "include"
SRC = DIR .. PSEP .. "src"
SRC_TYPE = SRC .. PSEP .. "type"
TST = DIR .. PSEP .. "tests"
LIB = DIR .. PSEP .. "lib"

CC = "cc"
CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug" then
  CFLAGS = CFLAGS .. " -g -DDEBUG -O0"
elseif MODE == "release" then
  CFLAGS = CFLAGS .. " -O2"
end

-- package shared library
AR = "ar"
ARFLAGS = "-rcs"

if PSEP == "\\" then
  LIBSHARED = LIB .. PSEP .. "lib" .. PRO .. ".dll"
  LIBSTATIC = LIB .. PSEP .. "lib" .. PRO .. ".lib"
  TSTFILE   = TST .. PSEP .. PRO .. ".c"
  TSTTARGET = TST .. PSEP .. PRO .. ".exe"
else
  LIBSHARED = LIB .. PSEP .. "lib" .. PRO .. ".so"
  LIBSTATIC = LIB .. PSEP .. "lib" .. PRO .. ".a"
  TSTFILE   = TST .. PSEP .. PRO .. ".c"
  TSTTARGET = TST .. PSEP .. PRO
end

-- source files
-- get all subdirectories
function getsubdirs(path, dirs)
  for item in lfs.dir(path) do
    if not string.match(item, "^%.") then
      subpath = path .. PSEP .. item
      attr = lfs.attributes(subpath)
      if attr.mode == "directory" then
        table.insert(dirs, subpath)
        getsubdirs(subpath, dirs)
      end
    end
  end
end

SRCS = {}
getsubdirs(SRC, SRCS)

-- get all source files from subdirectories
CFILES = {}
for index, dir in pairs(SRCS) do
  for file in lfs.dir(dir) do
    if string.match(file, "^[^%.].-%.c$") then
      table.insert(CFILES, dir .. PSEP .. file)
    end
  end
end

if not arg[1] then
  lfs.mkdir(LIB)
  OFILES = {}
  for index, file in pairs(CFILES) do
    obj = string.gsub(file, ".c$", ".o")
    dep = string.gsub(file, ".c$", ".d")
    print(string.format("compile file to %s", obj))
    os.execute(string.format("%s %s -I%s -I%s -c %s -o %s -MD -MF %s", CC, CFLAGS, INC, SRC_TYPE, file, obj, dep))
    table.insert(OFILES, obj)
  end
  print(string.format("compile %s", LIBSHARED))
  os.execute(string.format("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, table.concat(OFILES, " ")))
  print(string.format("compile %s", LIBSTATIC))
  os.execute(string.format("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, table.concat(OFILES, " ")))
elseif arg[1] == "test" then
  print(string.format("compile %s to %s", TSTFILE, TSTTARGET))
  os.execute(string.format("%s %s -I%s -o %s $ -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
  print(string.format("test %s with %s", TSTTARGET, TST .. PSEP .. "elements.csv"))
  os.execute(string.format("%s %s", TSTTARGET, TST .. PSEP .. "elements.csv"))
elseif arg[1] == "clean" then
  for index, file in pairs(CFILES) do
    obj = string.gsub(file, ".c$", ".o")
    print(string.format("clean %s", obj))
    os.remove(obj)
    dep = string.gsub(file, ".c$", ".d")
    print(string.format("clean %s", dep))
    os.remove(dep)
  end
  print(string.format("clean %s", LIBSTATIC))
  os.remove(LIBSTATIC)
  print(string.format("clean %s", LIBSHARED))
  os.remove(LIBSHARED)
  print(string.format("clean %s", TSTTARGET))
  os.remove(TSTTARGET)
elseif arg[1] == "distclean" then
  for file in CFILES do
    obj = string.gsub(file, ".c$", ".o")
    print(string.format("clean %s", obj))
    os.remove(obj)
    dep = string.gsub(file, ".c$", ".d")
    print(string.format("clean %s", dep))
    os.remove(dep)
  end
  print(string.format("clean %s", LIBSTATIC))
  os.remove(LIBSTATIC)
  print(string.format("clean %s", LIBSHARED))
  os.remove(LIBSHARED)
  print(string.format("clean %s", LIB))
  os.remove(LIB)
  print(string.format("clean %s", TSTTARGET))
  os.remove(TSTTARGET)
elseif arg[1] == "help" then
  print(arg[0] .. "    <target>")
  print("<target>: ")
  print("                    compile cgraph")
  print("          test      test cgraph")
  print("          clean     clean all the generated files")
  print("          distclean clean all the generated files and directories")
  print("          help      commands to this program")
else
  print(arg[1] .. " is an unsupported command")
  print("use \"" .. arg[0] .. " help\" to know all supported commands")
end
