#!/usr/bin/julia

PRO = "cgraph"
DIR = "."
SRC = joinpath(DIR, "src")
INC = joinpath(DIR, "include")
TST = joinpath(DIR, "test")
LIB = joinpath(DIR, "lib")

CC = "cc"
CFLAGS = "-ansi -pedantic -pedantic-errors -Wall -fPIC"
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug"
  CFLAGS = CFLAGS * " -g -DDEBUG"
elseif MODE == "release"
  CFLAGS = CFLAGS * " -static -O2"
end

# package shared library
AR = "ar"
ARFLAGS = "-rcs"

if Sys.iswindows()
  # target files
  LIBSHARED = joinpath(LIB, "lib$PRO.dll")
  LIBSTATIC = joinpath(LIB, "lib$PRO.a")
  # test files
  TSTFILE = joinpath(TST, "$PRO.c")
  TSTTARGET = joinpath(TST, "$PRO.exe")
else
  # target files
  LIBSHARED = joinpath(LIB, "lib$PRO.so")
  LIBSTATIC = joinpath(LIB, "lib$PRO.a")
  # test files
  TSTFILE = joinpath(TST, "$PRO.c")
  TSTTARGET = joinpath(TST, PRO)
end

CFILES = []
for file in readdir(SRC)
  if nothing != match(r".c$", file)
    push!(CFILES, file)
  end
end

args = ARGS
if 0 == length(args)

elseif 1 == length(args)
  if args[1] == "test"

  elseif args[1] == "clean"
    print(args)
  elseif args[1] == "distclean"

  elseif args[1] == "help"

  else

  end
else

end