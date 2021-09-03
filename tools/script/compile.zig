///!/usr/bin/env -S zig run

const std = @import("std");
const builtin = @import("builtin");
const Allocator = std.mem.Allocator;

pub fn main() void {
  const PRO : []const u8 = "cgraph";
  const DIR : []const u8 = ".";
  const SRC = std.fs.path.join(DIR, "src");
  const INC = std.fs.path.join(DIR, "include");
  const TST = std.fs.path.join(DIR, "test");
  const LIB = std.fs.path.join(DIR, "lib");

  const CC = "cc";
  var CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
  const CSFLAGS = "-shared";

  const MODE = "debug";
  if (MODE == "debug") {
    CLFLAGS += " -g -DDEBUG";
  } else if (MODE == "release") {
    CFLAGS += " -static -O2";
  }

  // package shared library
  AR = "ar";
  ARFLAGS = "-rcs";

  if (builtin.os == builtin.Os.windows) {
    // target files
    const LIBSHARED = std.fs.path.join(lib, "lib{}.dll", .{pro});
    const LIBSTATIC = std.fs.path.join(lib, "lib{}.lib", .{pro});
    // test files
    const TSTFILE = std.fs.path.join(tst, "{}.c", .{pro});
    const TSTTARGET = std.fs.path.join(tst, "{}.exe", .{pro});
  } else {
    // target files
    const LIBSHARED = std.fs.path.join(lib, "lib{}.so", .{pro});
    const LIBSTATIC = std.fs.path.join(lib, "lib{}.a", .{pro});
    // test files
    const TSTFILE = std.fs.path.join(tst, "{}.c", .{pro});
    const TSTTARGET = std.fs.path.join(tst, "{}", .{pro});
  }

  var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
  const gpa = &general_purpose_allocator.allocator;
  const args = try std.process.argsAlloc(gpa);
  defer std.process.argsFree(gpa, args);
  
  if (args.len == 1) {
    std.os.mkdir(LIB);
  } else if (args[1] == "test") {
    std.debug.print("hello world");
  } else if (args[1] == "clean") {
    std.debug.print("hello world");
  } else if (args[1] == "distclean") {
    std.debug.print("hello world");
  } else if (args[1] == "help") {
    std.debug.print("{}    <target>", .{args[0]});
    std.debug.print("<target>: ");
    std.debug.print("                    compile cgraph");
    std.debug.print("          test      test cgraph");
    std.debug.print("          clean     clean all the generated files");
    std.debug.print("          distclean clean all the generated files and directories");
    std.debug.print("          help      commands to this program");
  } else {
    std.debug.print("{} is an unsupported command", .{args[1]});
    std.debug.print("use \"{} help\" to know all supported commands", .{args[0]});
  }
}