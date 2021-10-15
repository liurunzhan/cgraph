#!/usr/bin/lua

require("package")
require('string')
require('os')
require('table')
require('lfs') -- luafilesystem, installed by "luarocks install luafilesystem"

SEPARATOR = string.sub(package.config, 0, 1)

PRO = "cgraph"
DIR = "."
INC = DIR .. SEPARATOR .. "include"
SRC = DIR .. SEPARATOR .. "src"
TST = DIR .. SEPARATOR .. "test"
LIB = DIR .. SEPARATOR .. "lib"

CC = "cc"
CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
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

if SEPARATOR == "\\" then
  LIBSHARED = LIB .. SEPARATOR .. "lib" .. PRO .. ".dll"
  LIBSTATIC = LIB .. SEPARATOR .. "lib" .. PRO .. ".lib"
  TSTFILE   = TST .. SEPARATOR .. PRO .. ".c"
  TSTTARGET = TST .. SEPARATOR .. PRO .. ".exe"
else
  LIBSHARED = LIB .. SEPARATOR .. "lib" .. PRO .. ".so"
  LIBSTATIC = LIB .. SEPARATOR .. "lib" .. PRO .. ".a"
  TSTFILE   = TST .. SEPARATOR .. PRO .. ".c"
  TSTTARGET = TST .. SEPARATOR .. PRO
end

CFILES = {}
for file in lfs.dir(SRC) do
  if string.match(file, ".c$") then
    table.insert(CFILES, SRC .. SEPARATOR .. file)
  end
end

if not arg[1] then
  lfs.mkdir(LIB)
  OFILES = {}
  for index, file in pairs(CFILES) do
    obj = string.gsub(file, ".c$", ".o")
    dep = string.gsub(file, ".c$", ".d")
    print(string.format("compile file to %s", obj))
    os.execute(string.format("%s %s -I%s -c %s -o %s -MD -MF %s", CC, CFLAGS, INC, file, obj, dep))
    table.insert(OFILES, obj)
  end
  print(string.format("compile %s", LIBSHARED))
  os.execute(string.format("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, table.concat(OFILES, " ")))
  print(string.format("compile %s", LIBSTATIC))
  os.execute(string.format("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, table.concat(OFILES, " ")))
elseif arg[1] == "test" then
	print(string.format("compile %s to %s", TSTFILE, TSTTARGET))
	os.execute(string.format("%s %s -I%s -o %s $ -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
	print(string.format("test %s with %s", TSTTARGET, TST .. SEPARATOR .. "elements.csv"))
	os.execute(string.format("%s %s", TSTTARGET, TST .. SEPARATOR .. "elements.csv"))
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