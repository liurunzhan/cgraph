#!/usr/bin/env zig run

const std = @import("std");
const builtin = @import("builtin");

pub fn main() void {
  const PRO = "cgraph";
  const DIR = ".";
  const INC = std.fs.path.join(DIR, "include");
  const SRC = std.fs.path.join(DIR, "src");
  const TST = std.fs.path.join(DIR, "test");
  const LIB = std.fs.path.join(DIR, "lib");

  const CC = "cc";
  var CFLAGS = "-pedantic -Wall -fpic -std=c89";
  const CSFLAGS = "-shared";

  const MODE = "debug"
  if (MODE == "debug") {
    CLFLAGS += " -g -DDEBUG"
  } else if (MODE == "release") {
    CFLAGS += " -static -O2"
  }

  // package shared library
  ar := "ar"
  arflags := "-rcs"

  if (builtin.os.tag == "windows") {

  } else {

  }


  std.os.mkdir(LIB);

}