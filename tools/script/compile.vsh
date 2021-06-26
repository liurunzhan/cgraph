#!/usr/bin/env -S v run

import os

fn main() {
  pro := "cgraph"
  dir := "."
  inc := os.join_path(dir, "include")
  src := os.join_path(dir, "src")
  tst := os.join_path(dir, "test")
  lib := os.join_path(dir, "lib")

  cc := "cc"
  mut cflags := "-std=c89 -Wall -pedantic"
  csflags := "-shared"

  if cc != "tcc" {
    cflags += " -pedantic-errors"
  }
  cflags += " -fPIC"

  mode := "debug"
  if mode == "debug" {
    cflags += " -g -DDEBUG"
  } else if mode == "release" {
    cflags += " -static -O2"
  }

  // package shared library
  ar := "ar"
  arflags := "-rcs"
  
  mut libshared := ""
  mut libstatic := ""
  mut tstfile := ""
  mut tsttarget := ""
  $if windows {
    // target files
    libshared += os.join_path(lib, "lib${pro}.dll")
    libstatic += os.join_path(lib, "lib${pro}.lib")
    // test files
    tstfile += os.join_path(tst, "${pro}.c")
    tsttarget += os.join_path(tst, "${pro}.exe")
  } $else {
    // target files
    libshared += os.join_path(lib, "lib${pro}.so")
    libstatic += os.join_path(lib, "lib${pro}.a")
    // test files
    tstfile += os.join_path(tst, "${pro}.c")
    tsttarget += os.join_path(tst, "${pro}")
  }

  cfiles := os.walk_ext(src, ".c")

  if os.args.len == 1 {
    if !os.is_dir(lib) {
      os.mkdir(lib) ?
    }
    mut ofiles := []string{}
    for file in cfiles {
      obj := file.replace(".c", ".o")
      dep := file.replace(".c", ".d")
      println("compile ${file} to ${obj}")
      os.system("${cc} ${cflags} -I${inc} -c ${file} -o ${obj} -MD -MF ${dep}")
      ofiles << obj
    }
    println("compile ${libshared}")
    os.system("${cc} ${csflags} -o ${libshared} ${ofiles.join(" ")}")
    println("compile ${libstatic}")
    os.system("${ar} ${arflags} ${libstatic} ${ofiles.join(" ")}")
  } else if os.args[1] == "test" {
    println("compile ${tstfile} to ${tsttarget}")
    os.system("${cc} ${cflags} -I${inc} -o ${tsttarget} ${tstfile} -L${lib} -static -l${pro} -lm")
    println("test ${tsttarget} with ${os.join_path(tst, "elements.csv")}")
    os.system("${tsttarget} ${os.join_path(tst, "elements.csv")}")
  } else if os.args[1] == "clean" {
    for file in cfiles {
      obj := file.replace(".c", ".o")
      println("clean ${obj}")
      if os.exists(obj) {
        os.rm(obj) ?
      }
      dep := file.replace(".c", ".d")
      println("clean ${dep}")
      if os.exists(dep) {
        os.rm(dep) ?
      }
    }
    println("clean ${libstatic}")
    if os.exists(libstatic) {
      os.rm(libstatic) ?
    }
    println("clean ${libshared}")
    if os.exists(libshared) {
      os.rm(libshared) ?
    }
    println("clean ${tsttarget}")
    if os.exists(tsttarget) {
      os.rm(tsttarget) ?
    }
  } else if os.args[1] == "distclean" {
    for file in cfiles {
      obj := file.replace(".c", ".o")
      println("clean ${obj}")
      if os.exists(obj) {
        os.rm(obj) ?
      }
      dep := file.replace(".c", ".d")
      println("clean ${dep}")
      if os.exists(dep) {
        os.rm(dep) ?
      }
    }
    println("clean ${libstatic}")
    if os.exists(libstatic) {
      os.rm(libstatic) ?
    }
    println("clean ${libshared}")
    if os.exists(libshared) {
      os.rm(libshared) ?
    }
    println("clean ${lib}")
    if os.is_dir(lib) {
      os.rmdir(lib) ?
    }
    println("clean ${tsttarget}")
    if os.exists(tsttarget) {
      os.rm(tsttarget) ?
    }
  } else if os.args[1] == "help" {
    println("${os.args[0]}    <target>")
    println("<target>: ")
    println("                    compile cgraph")
    println("          test      test cgraph")
    println("          clean     clean all the generated files")
    println("          distclean clean all the generated files and directories")
    println("          help      commands to this program")
  } else {
    println("${os.args[1]} is an unsupported command")
    println("use \"${os.args[0]} help\" to know all supported commands")
  }
}
