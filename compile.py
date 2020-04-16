#!/usr/bin/python

import os
import sys
import pathlib
import platform
import shutil

PRO = "cgraph"
DIR = "."
SRC = os.path.join(DIR, "src")
INC = os.path.join(DIR, "include")
TST = os.path.join(DIR, "test")
LIB = os.path.join(DIR, "lib")

CC = "cc"
CFLAGS = "-ansi -pedantic -pedantic-errors -Wall -fPIC -g"
CSFLAGS = "-shared"

# package shared library
AR = "ar"
ARFLAGS = "-rcs"

plat = platform.system()
if plat == "Windows":
  # target files
  LIBSHARED = os.path.join(LIB, "lib%s.dll" % PRO)
  LIBSTATIC = os.path.join(LIB, "lib%s.a" % PRO)
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
    CFILES.append(file)

args = sys.argv
if len(args) == 1 :
  if not pathlib.Path(LIB).exists():
    os.mkdir(LIB)
  for file in CFILES:
    obj = os.path.splitext(file)[0] + ".o"
    file_path = os.path.join(SRC, file)
    obj_path = os.path.join(SRC, obj)
    print("compile %s to %s" % (file_path, obj_path))
    os.system("%s %s -I%s -c %s -o %s" % (CC, CFLAGS, INC, file_path, obj_path))
  print("compile %s" % LIBSHARED)
  os.system("%s %s -o %s %s/*.o" % (CC, CSFLAGS, LIBSHARED, SRC))
  print("compile %s" % LIBSTATIC)
  os.system("%s %s %s %s/*.o" % (AR, ARFLAGS, LIBSTATIC, SRC))
elif args[1] == "test":
  print("compile %s to %s" % (os.path.join(TST, TSTFILE), os.path.join(TST, TSTTARGET)))
  os.system("%s %s -I%s -o %s %s -L%s -static -l%s -lm" % (CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
  print("test %s with %s" % (TSTTARGET, os.path.join(TST, "elements.csv")))
  os.system("%s %s" % (TSTTARGET, os.path.join(TST, "elements.csv")))
elif args[1] == "clean":
  for file in CFILES:
    obj = os.path.splitext(file)[0] + ".o"
    file_path = os.path.join(SRC, file)
    obj_path = os.path.join(SRC, obj)
    print("clean %s" % obj_path)
    if pathlib.Path(obj_path).exists():
      os.remove(obj_path)
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
    obj = os.path.splitext(file)[0] + ".o"
    file_path = os.path.join(SRC, file)
    obj_path = os.path.join(SRC, obj)
    print("clean %s" % obj_path)
    if pathlib.Path(obj_path).exists():
      os.remove(obj_path)
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