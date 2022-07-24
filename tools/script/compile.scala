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
    val SRC_TYPE : String = SRC + File.separator + "type"
    val TST : String = DIR + File.separator + "tests"
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

    // target files
    val LIBSHARED : String = LIB + File.separator + "lib" + PRO + ".so"
    val LIBSTATIC : String = LIB + File.separator + "lib" + PRO + ".a"
    // test files
    val TSTFILE : String = TST + File.separator + PRO + ".c"
    val TSTTARGET : String = TST + File.separator + PRO

    val CFILES : Array[File] = (new File(SRC)).listFiles().filter(_.isFile).filter(_.toString.endsWith(".c"))

    val SCRIPT_NAME = (new File(getClass()).protectionDomain.codeSource.location.path).name
    if (args.length == 0) {
      if (!LIB.exists()) {
        (new File(LIB)).mkdir()
      }
      val OFILES = ArrayBuffer[String]()
      for (file <- CFILES) {
        val pattern = "\\.c$"r
        val obj : String = file.getPath().replaceAll(pattern, ".o")
        val dep : String = file.getPath().replaceAll(pattern, ".d")
        println("compile ${file} to ${obj}")
        "${CC} ${CFLAGS} -I${INC} -I{SRC_TYPE} -c ${file} -o ${obj} -MD -MF ${dep}" !
        OFILES.append(obj)
      }
      val OFILES_STRING : String = OFILES.mkString(" ")
      println("compile ${LIBSHARED}")
      "${CC} ${CSFLAGS} -o ${LIBSHARED} ${OFILES_STRING}" !
      println("compile ${LIBSTATIC}")
      "${AR} ${ARFLAGS} ${LIBSTATIC} ${OFILES_STRING}" !
    } else if (args(0) == "test") {
      println("compile ${TSTFILE} to ${TSTTARGET}")
      "${CC} ${CFLAGS} -I${INC} -o ${TSTTARGET} ${TSTFILE} -L${LIB} -static -l${PRO} -lm" !
      val TSTFILE_CSV : String = TST + File.separator + "elements.csv" 
      println("test ${TSTTARGET} with ${TSTFILE_CSV}")
      "${TSTTARGET} ${TSTFILE_CSV}" !
    } else if (args(0) == "clean") {
      for (file <- CFILES) {
        val pattern = "\\.c$"r
        val obj : String = file.getPath().replaceAll(pattern, ".o")
        println("clean ${obj}")
        if (obj.exists()) {
          obj.delete()
        }
        val dep : String = file.getPath().replaceAll(pattern, ".d")
        println("clean ${dep}")
        if (dep.exists()) {
          dep.delete()
        }
      }
      println("clean ${LIBSHARED}")
      if (LIBSHARED.exists()) {
        LIBSHARED.delete()
      }
      println("clean ${LIBSTATIC}")
      if (LIBSTATIC.exists()) {
        LIBSTATIC.delete()
      }
      println("clean ${TSTTARGET}")
      if (TSTTARGET.exists()) {
        TSTTARGET.delete()
      }
    } else if (args(0) == "distclean") {
      for (file <- CFILES) {
        val pattern = "\\.c$"r
        val obj : String = file.getPath().replaceAll(pattern, ".o")
        println("clean ${obj}")
        if (obj.exists()) {
          obj.delete()
        }
        val dep : String = file.getPath().replaceAll(pattern, ".d")
        println("clean ${dep}")
        if (dep.exists()) {
          dep.delete()
        }
      }
      println("clean ${LIBSHARED}")
      if (LIBSHARED.exists()) {
        LIBSHARED.delete()
      }
      println("clean ${LIBSTATIC}")
      if (LIBSTATIC.exists()) {
        LIBSTATIC.delete()
      }
      println("clean ${LIB}")
      if (LIB.exists()) {
        LIB.delete()
      }
      println("clean ${TSTTARGET}")
      if (TSTTARGET.exists()) {
        TSTTARGET.delete()
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