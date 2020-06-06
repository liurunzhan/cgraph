#!/usr/bin/ruby -w

PRO = "cgraph"
DIR = "."
SRC = "#{DIR}/src"
INC = "#{DIR}/include"
TST = "#{DIR}/test"
LIB = "#{DIR}/lib"

CC = "cc"
cflags = "-ansi -pedantic -pedantic-errors -Wall -fPIC"
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug" then
  CFLAGS = "#{cflags} -g -DDEBUG"
elsif MODE == "release" then
  CFLAGS = "#{cflags} -static -O2"
end

# package shared library
AR = "ar"
ARFLAGS = "-rcs"
