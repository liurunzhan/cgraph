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
TST = os.path.join(DIR, "test")
LIB = os.path.join(DIR, "lib")

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
  TSTFILE = os.path.join(TST, "%s.c" % PRO)
  TSTTARGET = os.path.join(TST, "%s.exe" % PRO)
else:
  # target files
  LIBSHARED = os.path.join(LIB, "lib%s.so" % PRO)
  LIBSTATIC = os.path.join(LIB, "lib%s.a" % PRO)
  # test files
  TSTFILE = os.path.join(TST, "%s.c" % PRO)
  TSTTARGET = os.path.join(TST, PRO)

CFILES = []
for file in os.listdir(SRC):
  if os.path.splitext(file)[1] == ".c":
    CFILES.append(os.path.join(SRC, file))

args = sys.argv
if len(args) == 1 :
  if not pathlib.Path(LIB).exists():
    os.mkdir(LIB)
  OFILES = []
  for file in CFILES:
    obj = file.replace(".c", ".o")
		dep = file.replace(".c", ".d")
    print("compile %s to %s" % (file, obj))
    os.system("%s %s -I%s -c %s -o %s -MD -MF %s" % (CC, CFLAGS, INC, file, obj, dep))
    OFILES.append(obj)
  print("compile %s" % LIBSHARED)
  os.system("%s %s -o %s %s" % (CC, CSFLAGS, LIBSHARED, " ".join(OFILES)))
  print("compile %s" % LIBSTATIC)
  os.system("%s %s %s %s" % (AR, ARFLAGS, LIBSTATIC, " ".join(OFILES)))
elif args[1] == "test":
  print("compile %s to %s" % (os.path.join(TST, TSTFILE), os.path.join(TST, TSTTARGET)))
  os.system("%s %s -I%s -o %s %s -L%s -static -l%s -lm" % (CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
  print("test %s with %s" % (TSTTARGET, os.path.join(TST, "elements.csv")))
  os.system("%s %s" % (TSTTARGET, os.path.join(TST, "elements.csv")))
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