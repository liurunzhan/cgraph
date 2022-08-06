#!/usr/bin/nim

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

import os, strutils, strformat

var PRO: string = "cgraph"
var DIR: string = "."
var INC: string = joinPath(DIR, "include")
var SRC: string = joinPath(DIR, "src")
var SRC_TYPE: string = joinPath(SRC, "type")
var TST: string = joinPath(DIR, "tests")
var LIB: string = joinPath(DIR, "lib")

var CC: string = "cc"
var CFLAGS: string = "-std=c89 -Wall -pedantic -fPIC"
var CSFLAGS: string = "-shared"

var MODE: string = "debug"
if(MODE == "debug"):
  CFLAGS.add(" -g -DDEBUG")
elif(MODE == "release"):
  CFLAGS.add(" -static -O2")

# package shared library
var AR: string = "ar"
var ARFLAGS: string = "-rcs"

var LIBSHARED: string
var LIBSTATIC: string
var TSTFILE: string
var TSTTARGET: string

if defined(windows):
  # target files
  LIBSHARED = joinPath(LIB, fmt"lib{PRO}.dll")
  LIBSTATIC = joinPath(LIB, fmt"lib{PRO}.lib")
  # test files
  TSTFILE = joinPath(TST, fmt"{PRO}.c")
  TSTTARGET = joinPath(TST, fmt"{PRO}.exe")
else:
  # target files
  LIBSHARED = joinPath(LIB, fmt"lib{PRO}.so")
  LIBSTATIC = joinPath(LIB, fmt"lib{PRO}.a")
  # test files
  TSTFILE = joinPath(TST, fmt"{PRO}.c")
  TSTTARGET = joinPath(TST, PRO)

var CFILES: seq[string]
for path in walkDirRec(SRC):
  var file_name = extractFilename(path)
  if(fileExists(path) and endsWith(file_name, ".c") and (not startsWith(file_name, "."))):
    add(CFILES, path)

if(paramCount() == 1):
  if(not dirExists(LIB)):
    mkDir(LIB)
  var OFILES: seq[string]
  for file in CFILES:
    var obj = file
    obj[^1] = 'o'
    var dep = file
    dep[^1] = 'd'
    echo(fmt"compile {file} to {obj}")
    exec(fmt"{CC} {CFLAGS} -I{INC} -I{SRC_TYPE} -c {file} -o {obj} -MD -MF {dep}")
    add(OFILES, obj)
  echo(fmt"compile {LIBSHARED}")
  var objects = join(OFILES, " ")
  exec(fmt"{CC} {CSFLAGS} -o {LIBSHARED} {objects}")
  echo(fmt"compile {LIBSTATIC}");
  exec(fmt"{AR} {ARFLAGS} {LIBSTATIC} {objects}")
elif(paramStr(2) == "test"):
  echo(fmt"compile {TSTFILE} to {TSTTARGET}")
  exec(fmt"{CC} {CFLAGS} -I{INC} -o {TSTTARGET} {TSTFILE} -L{LIB} -static -l{PRO} -lm")
  var tst_path = joinPath(TST, "elements.csv")
  echo(fmt"test {TSTTARGET} with {tst_path}")
  exec(fmt"{TSTTARGET} {tst_path}")
elif(paramStr(2) == "clean"):
  for file in CFILES:
    var obj = file
    obj[^1] = 'o'
    echo("clean ", obj)
    if(fileExists(obj)):
      rmFile(obj)
    var dep = file
    dep[^1] = 'd'
    echo("clean ", dep)
    if(fileExists(dep)):
      rmFile(dep)
  echo(fmt"clean {LIBSTATIC}")
  if(fileExists(LIBSTATIC)):
    rmFile(LIBSTATIC)
  echo(fmt"clean {LIBSHARED}")
  if(fileExists(LIBSHARED)):
    rmFile(LIBSHARED)
  echo(fmt"clean {TSTTARGET}")
  if(fileExists(TSTTARGET)):
    rmFile(TSTTARGET)
elif(paramStr(2) == "distclean"):
  for file in CFILES:
    var obj = file
    obj[^1] = 'o'
    echo(fmt"clean {obj}")
    rmFile(obj)
    var dep = file
    dep[^1] = 'd'
    echo("clean ", dep)
    if(fileExists(dep)):
      rmFile(dep)
  echo(fmt"clean {LIBSTATIC}")
  if(fileExists(LIBSTATIC)):
    rmFile(LIBSTATIC)
  echo(fmt"clean {LIBSHARED}")
  if(fileExists(LIBSHARED)):
    rmFile(LIBSHARED)
  echo(fmt"clean {LIB}")
  if(dirExists(LIB)):
    rmDir(LIB)
  echo(fmt"clean {TSTTARGET}")
  if(fileExists(TSTTARGET)):
    rmFile(TSTTARGET)
elif(paramStr(2) == "help"):
  echo(fmt"{paramStr(1)}    <target>")
  echo("<target>: ")
  echo("                    compile cgraph")
  echo("          test      test cgraph")
  echo("          clean     clean all the generated files")
  echo("          distclean clean all the generated files and directories")
  echo("          help      commands to this program")
else:
  echo(fmt"{paramStr(2)} is an unsupported command")
  echo("""use "{paramStr(1)} help" to know all supported commands""")
