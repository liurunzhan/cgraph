#!/usr/bin/env -S v run

// Date : 2022-07-01
// A script to compile Library cgraph in Unix-like and Windows Platforms
// gets source files iteratively from Directory src
// TODO : will check in the future

import os
import regex

fn getsubdirs(path, dirs) {
  items := os.walk(path)
  dir_mode := r"^[^\.]"
  mut match_mode := regex.regex_opt(dir_mode) or { panic(err) }
  for item in items {
    subpath := os.join_path(path, item)
    if os.is_dir(subpath) && match_mode.match_string(item) {
      dirs << subpath
      getsubdirs(subpath, dirs)
    }
  }
}

fn main() {
  pro := "cgraph"
  dir := "."
  inc := os.join_path(dir, "include")
  src := os.join_path(dir, "src")
  src_type := os.join_path(src, "type")
  tst := os.join_path(dir, "tests")
  lib := os.join_path(dir, "lib")

  cc := "cc"
  mut cflags := "-std=c89 -Wall -pedantic -fPIC"
  csflags := "-shared"

  if cc != "tcc" {
    cflags += " -pedantic-errors"
  }

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

  // source files
	// get all subdirectories
  mut srcs := []string{}
  getsubdirs(src, srcs)

  // get all source files from subdirectories
  mut cfiles := []string{}
  cfile_mode := r"^[^\.].*\.c$"
  mut match_mode := regex.regex_opt(cfile_mode) or { panic(err) }
  for dir in srcs {
    for item in os.walk_ext(dir, ".c") {
      subpath := os.join_path(dir, item)
      if os.is_dir(subpath) && match_mode.match_string(item) {
        dirs << subpath
        getsubdirs(subpath, dirs)
      }
    }
  }

  if os.args.len == 1 {
    if !os.is_dir(lib) {
      os.mkdir(lib) ?
    }
    mut ofiles := []string{}
    cfile_ext_mode := r"\.c$"
    mut match_mode := regex.regex_opt(cfile_ext_mode) or { panic(err) }
    for file in cfiles {
      obj := match_mode.replace(file, ".o")
      dep := match_mode.replace(file, ".d")
      println("compile ${file} to ${obj}")
      os.system("${cc} ${cflags} -I${inc} -I${src_type} -c ${file} -o ${obj} -MD -MF ${dep}")
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
    cfile_ext_mode := r"\.c$"
    mut match_mode := regex.regex_opt(cfile_ext_mode) or { panic(err) }
    for file in cfiles {
      obj := match_mode.replace(file, ".o")
      println("clean ${obj}")
      if os.exists(obj) {
        os.rm(obj) ?
      }
      dep := match_mode.replace(file, ".d")
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
    cfile_ext_mode := r"\.c$"
    mut match_mode := regex.regex_opt(cfile_ext_mode) or { panic(err) }
    for file in cfiles {
      obj := match_mode.replace(file, ".o")
      println("clean ${obj}")
      if os.exists(obj) {
        os.rm(obj) ?
      }
      dep := match_mode.replace(file, ".d")
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
