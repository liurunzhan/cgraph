#!/usr/local/bin/v run

fn main() {
  PRO := "cgraph"
  DIR := "."
  SRC := File::Spec->catdir($DIR, "src")
  INC := File::Spec->catdir($DIR, "include")
  TST := File::Spec->catdir($DIR, "test")
  LIB := File::Spec->catdir($DIR, "lib")

  CC := "cc"
  mut CFLAGS := "-pedantic -Wall -fpic -std=c89"
  CSFLAGS := "-shared"

  MODE := "debug"
  if MODE == "debug" {
    CFLAGS += " -g -DDEBUG"
  } else if MODE == "release" {
    CFLAGS += " -static -O2"
  }

  // package shared library
  AR := "ar"
  ARFLAGS := "-rcs"

  $if windows {
    // target files
    LIBSHARED := File::Spec->catfile($LIB, "lib$PRO.dll")
    LIBSTATIC := File::Spec->catfile($LIB, "lib$PRO.a")
    // test files
    $TSTFILE = File::Spec->catfile($TST, "$PRO.c")
    $TSTTARGET = File::Spec->catfile($TST, "$PRO.exe")
  } else {
    // target files
    LIBSHARED := File::Spec->catfile($LIB, "lib$PRO.so")
    LIBSTATIC := File::Spec->catfile($LIB, "lib$PRO.a")
    // test files
    TSTFILE := File::Spec->catfile($TST, "$PRO.c")
    TSTTARGET := File::Spec->catfile($TST, "$PRO")
  }


}
