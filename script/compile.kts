#!/usr/bin/env kotlinc -script

val PRO = "cgraph"
val DIR = "."
val SRC = DIR + "/src"
val INC = DIR + "/include"
val TST = DIR + "/test"
val LIB = DIR + "/lib"

val CC = "cc"
var CFLAGS = "-pedantic -Wall -fpic -std=c89"
val CSFLAGS = "-shared"

val MODE = "debug"
if (MODE == "debug")
{
  CFLAGS = CFLAGS + " -g -DDEBUG"
}
else if (MODE == "release")
{
  CFLAGS = CFLAGS + " -static -O2"
}

val AR = "ar"
val ARFLAGS = "-rcs"