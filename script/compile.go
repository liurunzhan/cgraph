#!/usr/bin/env gorun

package main

import (
	"fmt"
	"os"
)

func main() {

	args = os.Args()
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
