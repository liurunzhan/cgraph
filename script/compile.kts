#!/usr/bin/env kotlinc -script

import java.io.File;

val PRO = "cgraph"
val DIR = "."
val SRC = DIR + File.separator + "src"
val INC = DIR + File.separator + "include"
val TST = DIR + File.separator + "test"
val LIB = DIR + File.separator + "lib"

val CC = "cc"
var CFLAGS = "-pedantic -Wall -fpic -std=c89"
val CSFLAGS = "-shared"

val MODE = "debug"
if (MODE == "debug") {
  CFLAGS = CFLAGS + " -g -DDEBUG"
} else if (MODE == "release") {
  CFLAGS = CFLAGS + " -static -O2"
}

val AR = "ar"
val ARFLAGS = "-rcs"

val FILES = File(SRC).walk()
val CFILES : MutableList<String> = mutableListOf()
FILES.maxDepth(1).filter{it.isFile}.filter{it.extension == "c"}.forEach{CFILES.add(SRC + File.separator + it.name)}

print(CFILES)