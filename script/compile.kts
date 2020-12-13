#!/usr/bin/env kotlinc -script

import java.io.File;

fun main(args: Array<String>) {
  val PRO = "cgraph"
  val DIR = "."
  val INC = DIR + File.separator + "include"
  val SRC = DIR + File.separator + "src"
  val TST = DIR + File.separator + "test"
  val LIB = DIR + File.separator + "lib"
  
  val CC = "cc"
  var CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
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
  
  val SCRIPT_NAME = (new File(getClass()).protectionDomain.codeSource.location.path).name
  if (args.length == 0) {

  } else if(args[0] == "test") {

  } else if(args[0] == "clean") {

  } else if(args[0] == "distclean") {

  } else if(args[0] == "help") {

  } else {
    println("${args[0]} is an unsupported command")
    println("use \"${SCRIPT_NAME} help \" to know all supported commands")
  }
}