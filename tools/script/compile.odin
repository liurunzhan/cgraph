#!/usr/bin/env -S odin run

package main

import "core:os"
import "core:path/filepath"
import "core:os"
import "core:fmt"
import "core:strings"

main :: proc() {
	PRO : string = "cgraph";
	DIR : string = ".";
	INC : string = filepath.join(PRO, "include");
	SRC : string = filepath.join(PRO, "src");
	TST : string = filepath.join(PRO, "test");
	LIB : string = filepath.join(PRO, "lib");

	CC : string = "cc";
	CFLAGS : string = "-std=c89 -Wall -pedantic -fPIC";
	CSFLAGS : string = "-shared";

	MODE : string = "debug";
	if MODE == "debug" {
		CFLAGS = strings.join(CFLAGS, " -g -DDEBUG");
	} else if MODE == "release" {
		CFLAGS = strings.join(CFLAGS, " -static -O2");
	}

	//package shared library
	AR : string = "ar";
	ARFLAGS : string = "-rcs";

	LIBSHARED : string;
	LIBSTATIC : string;
	TSTFILE : string;
	TSTTARGET : string;
	if ODIN_OS == "windows" {
		// target files
		LIBSHARED = filepath.join(LIB, fmt.aprintf("lib%s.dll", PRO));
		LIBSTATIC = filepath.join(LIB, fmt.aprintf("lib%s.lib", PRO));
		// test files
		TSTFILE = filepath.join(TST, fmt.aprintf("%s.c", PRO));
		TSTTARGET = filepath.join(TST, fmt.aprintf("%s.exe", PRO));
	} else {
		// target files
		LIBSHARED = filepath.join(LIB, fmt.aprintf("lib%s.so", PRO));
		LIBSTATIC = filepath.join(LIB, fmt.aprintf("lib%s.a", PRO));
		// test files
		TSTFILE = filepath.join(TST, fmt.aprintf("%s.c", PRO));
		TSTTARGET = filepath.join(TST, PRO);
	}

	CFILES := make([dynamic]string);
	os.read_dir(SRC, &CFILES);

	args := os.args;
	if len(args) == 1 {
		if !os2.exists(LIB) {
			os2.mkdir(LIB, 777);
		}

		OFILES := make([dynamic]string);
		delete(OFILES);
	} else if args[1] == "test" {
	} else if args[1] == "clean" {
	} else if args[1] == "distclean" {
		fmt.println("clean ", LIBSTATIC);
  	if os2.exists(LIBSTATIC) {
    	os2.remove_all(LIBSTATIC);
		}
  	fmt.println("clean ", LIBSHARED);
  	if os2.exists(LIBSHARED) {
			os2.remove_all(LIBSHARED);
		}
		fmt.println("clean ", LIB);
		if os2.exists(LIB) {
			os2.remove_all(LIB);
		}
  	fmt.println("clean ", TSTTARGET);
  	if(os2.exists(TSTTARGET)) {
			os2.remove_all(TSTTARGET);
		}
	} else if args[1] == "help" {
  	fmt.println(args[0], "    <target>");
  	fmt.println("<target>: ");
  	fmt.println("                    compile cgraph");
  	fmt.println("          test      test cgraph");
  	fmt.println("          clean     clean all the generated files");
  	fmt.println("          distclean clean all the generated files and directories");
  	fmt.println("          help      commands to this program");
	}	else {
  	fmt.println(args[0], " is an unsupported command");
  	fmt.println("use \"", args[1], " help\" to know all supported commands");
	}
	delete(CFILES);
}