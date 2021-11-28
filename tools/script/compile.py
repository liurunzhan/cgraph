#!/usr/bin/python

"""
  This script is used to compile library by Python-2.7 or higher
"""

import os
import sys
import platform
import shutil

try:
  import pathlib
except ImportError:
  from pip._internal import main
  main(["install", "pathlib"])
  import pathlib

PRO = "cgraph"
DIR = "."
INC = os.path.join(DIR, "include")
SRC = os.path.join(DIR, "src")
SRC_FUNC  = os.path.join(SRC, "func")
SRC_TYPE  = os.path.join(SRC, "type")
SRC_TYPE_BASIC     = os.path.join(SRC_TYPE, "basic")
SRC_TYPE_DATA      = os.path.join(SRC_TYPE, "data")
SRC_TYPE_OBJECT    = os.path.join(SRC_TYPE, "object")
SRC_TYPE_STRUCTURE = os.path.join(SRC_TYPE, "structure")
SRC_GRAPH = os.path.join(SRC, "graph")
SRC_GAME  = os.path.join(SRC, "game")
TST = os.path.join(DIR, "test")
LIB = os.path.join(DIR, "lib")

SRCS = [SRC, SRC_FUNC, SRC_TYPE, SRC_TYPE_BASIC, SRC_TYPE_DATA, SRC_TYPE_OBJECT, SRC_TYPE_STRUCTURE, SRC_GRAPH, SRC_GAME]

CC = "cc"
CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug":
  CFLAGS += " -g -DDEBUG"
elif MODE == "release":
  CFLAGS += " -static -O2"

# package shared library
AR = "ar"
ARFLAGS = "-rcs"

LIBSHARED = None
LIBSTATIC = None
TSTFILE = None
TSTTARGET = None
if platform.system() == "Windows":
  # target files
  LIBSHARED = os.path.join(LIB, "lib%s.dll" % PRO)
  LIBSTATIC = os.path.join(LIB, "lib%s.lib" % PRO)
  # test files
  TSTSUFFIX = ".exe"
else:
  # target files
  LIBSHARED = os.path.join(LIB, "lib%s.so" % PRO)
  LIBSTATIC = os.path.join(LIB, "lib%s.a" % PRO)
  # test files
  TSTSUFFIX = ""

CFILES = []
for dir in SRCS:
  for file in os.listdir(dir):
    if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
      CFILES.append(os.path.join(dir, file))

if __name__ == "__main__":
  args = sys.argv
  if len(args) == 1 :
    if not pathlib.Path(LIB).exists():
      os.mkdir(LIB)
    OFILES = []
    for file in CFILES:
      obj = file.replace(".c", ".o")
      dep = file.replace(".c", ".d")
      print("compile %s to %s" % (file, obj))
      os.system("%s %s -I%s -I%s -c %s -o %s -MD -MF %s" % (CC, CFLAGS, INC, SRC_TYPE, file, obj, dep))
      OFILES.append(obj)
    print("compile %s" % LIBSHARED)
    os.system("%s %s -o %s %s" % (CC, CSFLAGS, LIBSHARED, " ".join(OFILES)))
    print("compile %s" % LIBSTATIC)
    os.system("%s %s %s %s" % (AR, ARFLAGS, LIBSTATIC, " ".join(OFILES)))
  elif args[1] == "test":
    for file in os.listdir(TST):
      if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
        TSTFILE = os.path.join(TST, file)
        TSTTARGET = TSTFILE.replace(".c", TSTSUFFIX)
        print("compile %s to %s" % (TSTFILE, TSTTARGET))
        os.system("%s %s -I%s -o %s %s -L%s -static -l%s -lm" % (CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
        print("test %s" % TSTTARGET)
        os.system(TSTTARGET)
  elif args[1] == "clean":
    for file in CFILES:
      obj = file.replace(".c", ".o")
      print("clean %s" % obj)
      if pathlib.Path(obj).exists():
        os.remove(obj)
      dep = file.replace(".c", ".d")
      print("clean %s" % dep)
      if pathlib.Path(dep).exists():
        os.remove(dep)
    print("clean %s" % LIBSTATIC)
    if pathlib.Path(LIBSTATIC).exists():
      os.remove(LIBSTATIC)
    print("clean %s" % LIBSHARED)
    if pathlib.Path(LIBSHARED).exists():
      os.remove(LIBSHARED)
    for file in os.listdir(TST):
      if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
        TSTFILE = os.path.join(TST, file)
        TSTTARGET = TSTFILE.replace(".c", TSTSUFFIX)
        print("clean %s" % TSTTARGET)
        if pathlib.Path(TSTTARGET).exists():
          os.remove(TSTTARGET)
  elif args[1] == "distclean":
    for file in CFILES:
      obj = file.replace(".c", ".o")
      print("clean %s" % obj)
      if pathlib.Path(obj).exists():
        os.remove(obj)
      dep = file.replace(".c", ".d")
      print("clean %s" % dep)
      if pathlib.Path(dep).exists():
        os.remove(dep)
    print("clean %s" % LIBSTATIC)
    if pathlib.Path(LIBSTATIC).exists():
      os.remove(LIBSTATIC)
    print("clean %s" % LIBSHARED)
    if pathlib.Path(LIBSHARED).exists():
      os.remove(LIBSHARED)
    print("clean %s" % LIB)
    if pathlib.Path(LIB).exists():
      shutil.rmtree(LIB)
    for file in os.listdir(TST):
      if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
        TSTFILE = os.path.join(TST, file)
        TSTTARGET = TSTFILE.replace(".c", TSTSUFFIX)
        print("clean %s" % TSTTARGET)
        if pathlib.Path(TSTTARGET).exists():
          os.remove(TSTTARGET)
  elif args[1] == "help":
    print("%s <target>" % args[0])
    print("<target>: ")
    print("                    compile cgraph")
    print("          test      test cgraph")
    print("          clean     clean all the generated files")
    print("          distclean clean all the generated files and directories")
    print("          help      commands to this program")
  else:
    print("%s is an unsupported command" % args[0])
    print("use \"%s help\" to know all supported commands" % args[0])