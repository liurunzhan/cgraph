#!/usr/bin/env groovy

import java.io.File;
import groovy.io.FileType;

def PRO = "cgraph"
def DIR = "."
def INC = DIR + File.separator + "include"
def SRC = DIR + File.separator + "src"
def TST = DIR + File.separator + "test"
def LIB = DIR + File.separator + "lib"

def CC = "cc"
def CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
def CSFLAGS = "-shared"

def MODE = "debug"
if (MODE == "debug") {
  CFLAGS = CFLAGS + " -g -DDEBUG"
} else if (MODE == "release") {
  CFLAGS = CFLAGS + " -static -O2"
}

def AR = "ar"
def ARFLAGS = "-rcs"

def CFILES = []
def FILES = new File(SRC)
FILES.eachFileMatch(~/.*\.c$/) {
  File file -> CFILES.add(file)
}

def OS = System.getProperty("os.name")
def LIBSHARED, LIBSTATIC, TSTFILE, TSTTARGET
if(OS.matches("^[Ww]in")) {
  // target files
  LIBSHARED = LIB + File.separator + "lib" + PRO + ".dll"
  LIBSTATIC = LIB + File.separator + "lib" + PRO + ".lib"
  // test files
  TSTFILE = TST + File.separator + PRO + ".c"
  TSTTARGET = TST + File.separator + PRO + ".exe"
} else {
  // target files
  LIBSHARED = LIB + File.separator + "lib" + PRO + ".so"
  LIBSTATIC = LIB + File.separator + "lib" + PRO + ".a"
  // test files
  TSTFILE = TST + File.separator + PRO + ".c"
  TSTTARGET = TST + File.separator + PRO
}

def SCRIPT_NAME = new File(getClass().protectionDomain.codeSource.location.path).name
def args = this.args
if (args.size() == 0) {
  def lib = new File(LIB)
  if (!lib.exists()) {
    lib.mkdir()
  }
  def OFILES = []
  for (file in CFILES) {
    def obj = file.getPath().replace(".c", ".o")
    def dep = file.getPath().replace(".c", ".d")
    def cmd = sprintf("%s %s -I%s -c %s -o %s -MD -MF %s", CC, CFLAGS, INC, file, obj, dep)
    println(sprintf("compile %s to %s", file, obj))
    cmd.execute()
    OFILES.add(obj)
  }
  def cmd = sprintf("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, OFILES.join(" "))
  println(sprintf("compile %s", LIBSHARED))
  cmd.execute()
  cmd = sprintf("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, OFILES.join(" "))
  println(sprintf("compile %s", LIBSTATIC))
  cmd.execute()
} else if (args[0] == "test") {
  def cmd = sprintf("%s %s -I%s -o %s %s -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO)
  println(sprintf("compile %s to %s", TSTFILE, TSTTARGET))
  cmd.execute()
} else if (args[0] == "clean") {
  for (file in CFILES) {
    def obj = new File(file.getPath().replace(".c", ".o"))
    println(sprintf("clean %s", obj))
    obj.delete()
    def dep = new File(file.getPath().replace(".c", ".d"))
    println(sprintf("clean %s", dep))
    dep.delete()
  }
  println(sprintf("clean %s", LIBSTATIC))
  def libstatic = new File(LIBSTATIC)
  libstatic.delete()
  println(sprintf("clean %s", LIBSHARED))
  def libshared = new File(LIBSHARED)
  libshared.delete()
  println(sprintf("clean %s", TSTTARGET))
  def tsttarget = new File(TSTTARGET)
  tsttarget.delete()
} else if (args[0] == "distclean") {
  for (file in CFILES) {
    def obj = new File(file.getPath().replace(".c", ".o"))
    println(sprintf("clean %s", obj))
    obj.delete()
    def dep = new File(file.getPath().replace(".c", ".d"))
    println(sprintf("clean %s", dep))
    dep.delete()
  }
  println(sprintf("clean %s", LIBSTATIC))
  def libstatic = new File(LIBSTATIC)
  libstatic.delete()
  println(sprintf("clean %s", LIBSHARED))
  def libshared = new File(LIBSHARED)
  libshared.delete()
  println(sprintf("clean %s", LIB))
  def lib = new File(LIB)
  lib.delete()
  println(sprintf("clean %s", TSTTARGET))
  def tsttarget = new File(TSTTARGET)
  tsttarget.delete()
} else if (args[0] == "help") {
  println("${SCRIPT_NAME} <target>")
  println("<target>: ")
  println("                    compile cgraph")
  println("          test      test cgraph")
  println("          clean     clean all the generated files")
  println("          distclean clean all the generated files and directories")
  println("          help      commands to this program")
} else {
  println("${args[0]} is an unsupported command")
  println("use \"${SCRIPT_NAME} help\" to know all supported commands")
}