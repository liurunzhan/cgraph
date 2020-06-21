#!/usr/bin/lua

require('path')

PRO = "cgraph"
DIR = "."
SRC = path.join(DIR, "src")
INC = path.join(DIR, "include")
TST = path.join(DIR, "test")
LIB = path.join(DIR, "lib")

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
    CFILES.append(file)
  end
end

print(CFILES)