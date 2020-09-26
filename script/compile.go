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
  var CFLAGS string = "-pedantic -Wall -fpic -std=c89"
  var CSFLAGS string = "-shared"

  var MODE string = "debug"
  if MODE == "debug" {
    CFLAGS = CFLAGS + " -g -DDEBUG"
  } else if MODE == "release" {
    CFLAGS = CFLAGS + " -static -O2"
  }

	if runtime.GOOS == "windows" {

	} else {

	}

	var args []string = os.Args
	if len(args) == 1 {
	
	} else if args[1] == "test" {

	} else if args[1] == "clean" {

	} else if args[1] == "distclean" {

	} else if args[1] == "help" {

	} else {
		fmt.Printf("%s is an unsupported command\n", args[1])
		fmt.Printf("use \"%s help\" to know all supported commands\n", args[0])
	}
}
