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

  var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
  const gpa = &general_purpose_allocator.allocator;
  const args = try std.process.argsAlloc(gpa);
  defer std.process.argsFree(gpa, args);

  for (args) |arg, i| {
      std.debug.print("{}: {}\n", .{ i, arg });
  }
  std.debug.print(arg.len);

  std.os.mkdir(LIB);

}