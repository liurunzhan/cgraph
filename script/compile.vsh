#!/usr/local/bin/v run

import os

fn main() {
  pro := "cgraph"
  dir := "."
  inc := os.join_path(dir, "include")
  src := os.join_path(dir, "src")
  tst := os.join_path(dir, "test")
  lib := os.join_path(dir, "lib")

  cc := "cc"
  mut cflags := "-pedantic -Wall -fPIC -std=c89"
  csflags := "-shared"

  mode := "debug"
  if mode == "debug" {
    cflags += " -g -DDEBUG"
  } else if mode == "release" {
    cflags += " -static -O2"
  }

  // package shared library
  ar := "ar"
  arflags := "-rcs"

  cfiles := os.walk_ext(src, ".c")
  
  $if windows {
    // target files
    libshared := os.join_path(lib, "lib${pro}.dll")
    libstatic := os.join_path(lib, "lib${pro}.a")
    // test files
    tstfile := os.join_path(tst, "${pro}.c")
    tsttarget := os.join_path(tst, "${pro}.exe")
  } $else {
    // target files
    libshared := os.join_path(lib, "lib${pro}.so")
    libstatic := os.join_path(lib, "lib${pro}.a")
    // test files
    tstfile := os.join_path(tst, "${pro}.c")
    tsttarget := os.join_path(tst, "${pro}")
  }


  os.mkdir(lib) 
}
