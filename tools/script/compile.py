#!/usr/bin/python

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src
# needs Python-2.7, Python3.4 or higher
# TODO: A multiple definition issue while compiling shared library

import os
import sys
import platform
import shutil
import subprocess

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
SRC_TYPE = os.path.join(SRC, "type")
TST = os.path.join(DIR, "tests")
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

# source files
# get all subdirectories
def getsubdirs(path, dirs):
  for root, subdirs, files in os.walk(path):
    for dir in subdirs:
      if not dir.startswith("."):
        subpath = os.path.join(root, dir)
        dirs.append(subpath)
        getsubdirs(subpath, dirs)

SRCS = []
getsubdirs(SRC, SRCS)

# get all source files from subdirectories
CFILES = []
for dir in SRCS:
  for root, subdirs, files in os.walk(dir):
    for file in files:
      if not file.startswith(".") and file.endswith(".c"):
        CFILES.append(os.path.join(root, file))

LIBSHARED = None
LIBSTATIC = None
TSTFILE = None
TSTTARGET = None
if platform.system() == "Windows":
  # target files
  LIBSHARED = os.path.join(LIB, "lib{PRO}.dll".format(PRO=PRO))
  LIBSTATIC = os.path.join(LIB, "lib{PRO}.lib".format(PRO=PRO))
  # test files
  TSTSUFFIX = ".exe"
else:
  # target files
  LIBSHARED = os.path.join(LIB, "lib{PRO}.so".format(PRO=PRO))
  LIBSTATIC = os.path.join(LIB, "lib{PRO}.a".format(PRO=PRO))
  # test files
  TSTSUFFIX = ""

if __name__ == "__main__":
  args = sys.argv
  if len(args) == 1 :
    if not pathlib.Path(LIB).exists():
      os.mkdir(LIB)
    OFILES = []
    for file in CFILES:
      obj = file.replace(".c", ".o")
      dep = file.replace(".c", ".d")
      print("compile {file} to {obj}".format(file=file, obj=obj))
      subprocess.run("{CC} {CFLAGS} -I{INC} -I{SRC_TYPE} -c {file} -o {obj} -MD -MF {dep}".format(CC=CC, CFLAGS=CFLAGS, INC=INC, SRC_TYPE=SRC_TYPE, file=file, obj=obj, dep=dep), shell=True)
      OFILES.append(obj)
    print("compile {LIBSHARED}".format(LIBSHARED=LIBSHARED))
    subprocess.run("{CC} {CSFLAGS} -o {LIBSHARED} {OFILES}".format(CC=CC, CSFLAGS=CSFLAGS, LIBSHARED=LIBSHARED, OFILES=" ".join(OFILES)), shell=True)
    print("compile {LIBSTATIC}".format(LIBSTATIC=LIBSTATIC))
    subprocess.run("{AR} {ARFLAGS} {LIBSTATIC} {OFILES}".format(AR=AR, ARFLAGS=ARFLAGS, LIBSTATIC=LIBSTATIC, OFILES=" ".join(OFILES)), shell=True)
  elif args[1] == "test":
    for file in os.listdir(TST):
      if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
        TSTFILE = os.path.join(TST, file)
        TSTTARGET = TSTFILE.replace(".c", TSTSUFFIX)
        print("compile {TSTFILE} to {TSTTARGET}".format(TSTFILE=TSTFILE, TSTTARGET=TSTTARGET))
        subprocess.run("{CC} {CFLAGS} -I{INC} -o {TSTTARGET} {TSTFILE} -L{LIB} -static -l{PRO} -lm".format(CC=CC, CFLAGS=CFLAGS, INC=INC, TSTTARGET=TSTTARGET, TSTFILE=TSTFILE, LIB=LIB, PRO=PRO), shell=True)
        print("test {TSTTARGET}".format(TSTTARGET=TSTTARGET))
        subprocess.run(TSTTARGET, shell=True)
  elif args[1] == "clean":
    for file in CFILES:
      obj = file.replace(".c", ".o")
      print("clean {obj}".format(obj=obj))
      if pathlib.Path(obj).exists():
        os.remove(obj)
      dep = file.replace(".c", ".d")
      print("clean {dep}".format(dep=dep))
      if pathlib.Path(dep).exists():
        os.remove(dep)
    print("clean {LIBSTATIC}".format(LIBSTATIC=LIBSTATIC))
    if pathlib.Path(LIBSTATIC).exists():
      os.remove(LIBSTATIC)
    print("clean {LIBSHARED}".format(LIBSHARED=LIBSHARED))
    if pathlib.Path(LIBSHARED).exists():
      os.remove(LIBSHARED)
    for file in os.listdir(TST):
      if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
        TSTFILE = os.path.join(TST, file)
        TSTTARGET = TSTFILE.replace(".c", TSTSUFFIX)
        print("clean {TSTTARGET}".format(TSTTARGET=TSTTARGET))
        if pathlib.Path(TSTTARGET).exists():
          os.remove(TSTTARGET)
  elif args[1] == "distclean":
    for file in CFILES:
      obj = file.replace(".c", ".o")
      print("clean {obj}".format(obj=obj))
      if pathlib.Path(obj).exists():
        os.remove(obj)
      dep = file.replace(".c", ".d")
      print("clean {dep}".format(dep=dep))
      if pathlib.Path(dep).exists():
        os.remove(dep)
    print("clean {LIBSTATIC}".format(LIBSTATIC=LIBSTATIC))
    if pathlib.Path(LIBSTATIC).exists():
      os.remove(LIBSTATIC)
    print("clean {LIBSHARED}".format(LIBSHARED=LIBSHARED))
    if pathlib.Path(LIBSHARED).exists():
      os.remove(LIBSHARED)
    print("clean {LIB}".format(LIB=LIB))
    if pathlib.Path(LIB).exists():
      shutil.rmtree(LIB)
    for file in os.listdir(TST):
      if not file.startswith(".") and os.path.splitext(file)[1] == ".c":
        TSTFILE = os.path.join(TST, file)
        TSTTARGET = TSTFILE.replace(".c", TSTSUFFIX)
        print("clean {TSTTARGET}".format(TSTTARGET=TSTTARGET))
        if pathlib.Path(TSTTARGET).exists():
          os.remove(TSTTARGET)
  elif args[1] == "help":
    print("{script} <target>".format(script=args[0]))
    print("<target>: ")
    print("                    compile cgraph")
    print("          test      test cgraph")
    print("          clean     clean all the generated files")
    print("          distclean clean all the generated files and directories")
    print("          help      commands to this program")
  else:
    print("{script} is an unsupported command".format(script=args[0]))
    print("use \"{script} help\" to know all supported commands".format(script=args[0]))