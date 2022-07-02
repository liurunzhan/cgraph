#!/usr/bin/env -S kotlinc -script

import java.io.File
import java.lang.*

fun main(args: Array<String>) {
	val PRO = "cgraph"
	val DIR = "."
	val INC = DIR + File.separator + "include"
	val SRC = DIR + File.separator + "src"
	val SRC_TYPE = SRC + File.separator + "type"
	val TST = DIR + File.separator + "tests"
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

	var CFILES : MutableList<String> = mutableListOf()
	File(SRC).walk().maxDepth(1).filter{it.isFile}.filter{it.extension == "c"}.forEach{CFILES.add(SRC + File.separator + it.name)}

	// val SCRIPT_NAME = (File(Object.getClass()).protectionDomain.codeSource.location.path).name
	// println(SCRIPT_NAME)
	println(args)
	if (args.size == 0) {
		var OFILES : MutableList<String> = mutableListOf()
		for (file in CFILES) {
			val obj : String = file.replace(Regex(".c$"), ".o")
			val dep : String = file.replace(Regex(".c$"), ".d")
			OFILES.add(obj)
		}
	} else if(args[0] == "test") {

	} else if(args[0] == "clean") {
		for (file in CFILES) {
			val obj : String = file.replace(Regex(".c$"), ".o")
			val dep : String = file.replace(Regex(".c$"), ".d")
		}
	} else if(args[0] == "distclean") {
		for (file in CFILES) {
			val obj : String = file.replace(Regex(".c$"), ".o")
			val dep : String = file.replace(Regex(".c$"), ".d")
		}
	} else if(args[0] == "help") {
		// println("${SCRIPT_NAME}    <target>")
		println("<target>: ")
		println("                    compile cgraph")
		println("          test      test cgraph")
		println("          clean     clean all the generated files")
		println("          distclean clean all the generated files and directories")
		println("          help      commands to this program")
	} else {
		println("${args[0]} is an unsupported command")
		// println("use \"${SCRIPT_NAME} help \" to know all supported commands")
	}
}