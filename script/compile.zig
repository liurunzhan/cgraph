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
  var CFLAGS = "-pedantic -Wall -fPIC -std=c89";
  const CSFLAGS = "-shared";

  const MODE = "debug"
  if (MODE == "debug") {
    CLFLAGS += " -g -DDEBUG";
  } else if (MODE == "release") {
    CFLAGS += " -static -O2";
  }

  // package shared library
  AR = "ar";
  ARFLAGS = "-rcs";

  if (builtin.os.tag == "windows") {
    // target files
    const libshared = std.fs.path.join(lib, "lib{}.dll", .{pro});
    const libstatic = std.fs.path.join(lib, "lib{}.a", .{pro});
    // test files
    const tstfile = std.fs.path.join(tst, "{}.c", .{pro});
    const tsttarget = std.fs.path.join(tst, "{}.exe", .{pro});
  } else {
    // target files
    const libshared = std.fs.path.join(lib, "lib{}.so", .{pro});
    const libstatic = std.fs.path.join(lib, "lib{}.a", .{pro});
    // test files
    const tstfile = std.fs.path.join(tst, "{}.c", .{pro});
    const tsttarget = std.fs.path.join(tst, "{}", .{pro});
  }


  std.os.mkdir(LIB);

}