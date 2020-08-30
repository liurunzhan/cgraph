#!/bin/sh
exec scala "$0" "$@"
!#

import scala.reflect.io.Directory

object Compile {
  def main(args: Array[String]): Unit = {
    // project
    val PRO : String = "cgraph"

    // directory tree
    val DIR : String = "."
    val INC : String = "$DIR/include"
    val SRC : String = "$DIR/src"
    val TST : String = "$DIR/test"
    val LIB : String = "$DIR/lib"

    val CC : String = "cc"
    var CFLAGS : String = "-pedantic -Wall -fpic -std=c89"
    val CSFLAGS : String = "-shared"

    val MODE : String = "debug"
    if (MODE.equals("debug"))
    {
      CFLAGS += " -g -DDEBUG"
    }
    else if (MODE.equals("release"))
    {
      CFLAGS += " -static -O2"
    }

    val AR : String = "ar"
    val ARFLAGS : String = "-rcs"
  }
}