#!/usr/bin/env gorun

package main

import (
	"fmt"
	"os"
	"path"
	"runtime"
)

func main() {
	var PRO string = "cgraph"
	var DIR string = "."
	var INC string = path.Join(PRO, "include")
	var SRC string = path.Join(PRO, "src")
	var TST string = path.Join(PRO, "test")
	var LIB string = path.Join(PRO, "lib")

  var CC string = "cc"
  var CFLAGS string = "-pedantic -Wall -fPIC -std=c89"
  var CSFLAGS string = "-shared"

  var MODE string = "debug"
  if MODE == "debug" {
    CFLAGS = CFLAGS + " -g -DDEBUG"
  } else if MODE == "release" {
    CFLAGS = CFLAGS + " -static -O2"
  }

	var AR = "ar"
	var ARFLAGS = "-rcs"

	if runtime.GOOS == "windows" {
    var LIBSHARED = path.Join(LIB, "lib" + PRO + ".dll")
    var LIBSTATIC = path.Join(LIB, "lib" + PRO + ".a")
    var TSTFILE   = path.Join(TST, PRO + ".c")
    var TSTTARGET = path.Join(TST, POR + ".exe")
	} else {
    var LIBSHARED = path.Join(LIB, "lib" + PRO + ".so")
    var LIBSTATIC = path.Join(LIB, "lib" + PRO + ".a")
    var TSTFILE   = path.Join(TST, PRO + ".c")
    var TSTTARGET = path.Join(TST, PRO)
	}

	var args []string = os.Args
	if len(args) == 1 {
	
	} else if args[1] == "test" {

	} else if args[1] == "clean" {

	} else if args[1] == "distclean" {

	} else if args[1] == "help" {
    fmt.Printf("%s    <target>\n", args[0])
    fmt.Printf("<target>: \n")
    fmt.Printf("                    compile cgraph\n")
    fmt.Printf("          test      test cgraph\n")
    fmt.Printf("          clean     clean all the generated files\n")
    fmt.Printf("          distclean clean all the generated files and directories\n")
    fmt.Printf("          help      commands to this program\n")
	} else {
		fmt.Printf("%s is an unsupported command\n", args[1])
		fmt.Printf("use \"%s help\" to know all supported commands\n", args[0])
	}
}
