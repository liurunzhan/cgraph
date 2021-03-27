#!/bin/sh
exec scala "$0" "$@"
!#

import java.io.File
import scala.reflect.io.Directory
import scala.collection.mutable.ArrayBuffer
import sys.process._

object Compile {
  def main(args: Array[String]): Unit = {
    // project
    val PRO : String = "cgraph"

    // directory tree
    val DIR : String = "."
    val INC : String = DIR + File.separator + "include"
    val SRC : String = DIR + File.separator + "src"
    val TST : String = DIR + File.separator + "test"
    val LIB : String = DIR + File.separator + "lib"

    val CC : String = "cc"
    var CFLAGS : String = "-std=c89 -Wall -pedantic -fPIC"
    val CSFLAGS : String = "-shared"

    val MODE : String = "debug"
    if (MODE.equals("debug")) {
      CFLAGS += " -g -DDEBUG"
    } else if (MODE.equals("release")) {
      CFLAGS += " -static -O2"
    }

    val AR : String = "ar"
    val ARFLAGS : String = "-rcs"



    val CFILES : Array[File] = (new File(SRC)).listFiles().filter(_.isFile).filter(_.toString.endsWith(".c"))

    val SCRIPT_NAME = (new File(getClass()).protectionDomain.codeSource.location.path).name
    if (args.length == 0) {
      if (!obj.exists()) {
        (new File(LIB)).mkdir()
      }
      val OFILES = ArrayBuffer[String]()
      for(file <- CFILES) {
        val patten = "\.c$"r
        val obj : String = pattern.replaceAll(file, ".o")
        println("compile ${file} to ${obj}")
        "${CC} ${CFLAGS} -I${INC} -c ${file} -o ${obj}" !
        OFILES += obj
      }
    } else if (args(0) == "test") {

    } else if (args(0) == "clean") {
      for(file <- CFILES) {
        val patten = "\.c$"r
        val obj : String = pattern.replaceAll(file ".o")
        println("clean ${obj}")
        if (obj.exists()) {
          obj.delete()
        }
      }
    } else if (args(0) == "distclean") {
      for(file <- CFILES) {
        val patten = "\.c$"r
        val obj : String = pattern.replaceAll(file, ".o")
        println("clean ${obj}")
        if (obj.exists()) {
          obj.delete()
        }
      }

      println("clean ${LIB}")
      if (LIB.exists()) {
        LIB.delete()
      }
    } else if (args(0) == "help") {
      println("${SCRIPT_NAME} <target>")
      println("<target>: ")
      println("                    compile cgraph")
      println("          test      test cgraph\n")
      println("          clean     clean all the generated files")
      println("          distclean clean all the generated files and directories")
      println("          help      commands to this PROgram")
    } else {
      println("${args(0)} is an unsupported command")
      println("use \"${SCRIPT_NAME} help\" to know all supported commands")
    }
  }
}