#!/usr/bin/env groovy

import java.io.File;
import groovy.io.FileType;

def PRO = "cgraph"
def DIR = "."
def SRC = DIR + File.separator + "src"
def INC = DIR + File.separator + "include"
def TST = DIR + File.separator + "test"
def LIB = DIR + File.separator + "lib"

def CC = "cc"
def CFLAGS = "-pedantic -Wall -fpic -std=c89"
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
  LIBSTATIC = LIB + File.separator + "lib" + PRO + ".a"
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
  lib.mkdir()
  def OFILES = []
  for (file in CFILES) {
    def obj = file.getPath().replace(".c", ".o")
    def cmd = sprintf("%s %s -I%s -c %s -o %s", CC, CFLAGS, INC, file, obj)
    println(sprintf("compile %s to %s", file, obj))
    cmd.execute()
    OFILES.add(obj)
  }
} else if (args[0] == "test") {

} else if (args[0] == "clean") {

} else if (args[0] == "distclean") {

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