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
  var CFLAGS string = "-std=c89 -Wall -pedantic -fPIC"
  var CSFLAGS string = "-shared"

  var MODE string = "debug"
  if MODE == "debug" {
    CFLAGS = CFLAGS + " -g -DDEBUG"
  } else if MODE == "release" {
    CFLAGS = CFLAGS + " -static -O2"
  }

	var AR string = "ar"
	var ARFLAGS string = "-rcs"

	var LIBSHARED string 
	var LIBSTATIC string 
	var TSTFILE string 
	var TSTTARGET string
	
	if runtime.GOOS == "windows" {
    LIBSHARED = path.Join(LIB, "lib" + PRO + ".dll")
    LIBSTATIC = path.Join(LIB, "lib" + PRO + ".a")
    TSTFILE   = path.Join(TST, PRO + ".c")
    TSTTARGET = path.Join(TST, PRO + ".exe")
	} else {
    LIBSHARED = path.Join(LIB, "lib" + PRO + ".so")
    LIBSTATIC = path.Join(LIB, "lib" + PRO + ".a")
    TSTFILE   = path.Join(TST, PRO + ".c")
    TSTTARGET = path.Join(TST, PRO)
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
