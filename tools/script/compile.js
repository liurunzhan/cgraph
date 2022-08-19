#!/usr/bin/env node

// Date : 2022-07-01
// A script to compile Library cgraph in Unix-like and Windows Platforms
// gets source files iteratively from Directory src

const path = require("path");
const fs = require("fs");
const os = require("os");

const sep = String(path.sep);

var PRO = "cgraph";
var DIR = ".";
var INC = DIR + sep + "include";
var SRC = DIR + sep + "src";
var SRC_TYPE = SRC + sep + "type";
var TST = DIR + sep + "tests";
var LIB = DIR + sep + "lib";

var CC = "cc";
var CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
var CSFLAGS = "-shared";

var MODE = "debug";
if (MODE == "debug") {
  CFLAGS.concat(" -g -DDEBUG");
} else if (MODE == "release") {
  CFLAGS.concat(" -static -O2");
}

// package shared library
var AR = "ar";
var ARFLAGS = "-rcs";

// source files
// get all subdirectories
function getsubdirs(path, dirs) {
  const files = fs.readdirSync(path);
  for (var i = 0; i < files.length; i++) {
    var subpath = path + sep + files[i];
    var stats = fs.lstatSync(subpath);
    if (stats.isDirectory() && !files[i].startsWith(".")) {
      dirs.push(subpath);
      getsubdirs(subpath, dirs);
    }
  }
}

// get all source files from subdirectories
var SRCS = [];
getsubdirs(SRC, SRCS);

var CFILES = [];
for (var i = 0; i < SRCS.length; i++) {
  const files = fs.readdirSync(SRCS[i]);
  for (var j = 0; j < files.length; j++) {
    var file = SRCS[i] + sep + files[j];
    var stats = fs.lstatSync(file);
    if (stats.isFile() && /^((?!\.).)*\.c$/.test(files[j])) {
      CFILES.push(file);
    }
  }
}

var LIBSHARED;
var LIBSTATIC;
var TSTSUFFIX;
if ("Windows_NT" == os.type()) {
  // target files
  LIBSHARED = `${LIB}${sep}lib${PRO}.dll`;
  LIBSTATIC = `${LIB}${sep}lib${PRO}.lib`;
  // test files
  TSTSUFFIX = ".exe";
} else {
  // target files
  LIBSHARED = `${LIB}${sep}lib${PRO}.so`;
  LIBSTATIC = `${LIB}${sep}lib${PRO}.a`;
  // test files
  TSTSUFFIX = "";
}

if (process.argv.length == 2) {
  if (!fs.existsSync(LIB)) {
    fs.mkdirSync(LIB);
  }
  var OFILES = [];
  for (var i = 0; i < CFILES.length; i++) {
    var obj = CFILES[i].replace(/\.c$/, ".o");
    var dep = CFILES[i].replace(/\.c$/, ".d");
    console.log(`compile ${CFILES[i]} to ${obj}`);
    OFILES.push(obj);
  }
} else if (process.argv[2] == "test") {

} else if (process.argv[2] == "clean") {
  for (var i = 0; i < CFILES.length; i++) {
    var obj = CFILES[i].replace(/\.c$/, ".o");
    console.log(`clean ${obj}`);
    if (fs.existsSync(obj)) {
      fs.unlink(obj);
    }
    var dep = CFILES[i].replace(/\.c$/, ".d");
    console.log(`clean ${dep}`);
    if (fs.existsSync(dep)) {
      fs.unlink(dep);
    }
  }
  console.log(`clean ${LIBSTATIC}`);
  if (fs.existsSync(LIBSTATIC)) {
    fs.unlink(LIBSTATIC);
  }
  console.log(`clean ${LIBSHARED}`);
  if (fs.existsSync(LIBSHARED)) {
    fs.unlink(LIBSHARED);
  }
} else if (process.argv[2] == "distclean") {
  for (var i = 0; i < CFILES.length; i++) {
    var obj = CFILES[i].replace(/\.c$/, ".o");
    console.log(`clean ${obj}`);
    if (fs.existsSync(obj)) {
      fs.unlink(obj);
    }
    var dep = CFILES[i].replace(/\.c$/, ".d");
    console.log(`clean ${dep}`);
    if (fs.existsSync(dep)) {
      fs.unlink(dep);
    }
  }
  console.log(`clean ${LIBSTATIC}`);
  if (fs.existsSync(LIBSTATIC)) {
    fs.unlink(LIBSTATIC);
  }
  console.log(`clean ${LIBSHARED}`);
  if (fs.existsSync(LIBSHARED)) {
    fs.unlink(LIBSHARED);
  }
  console.log(`clean ${LIB}`);
  if (fs.existsSync(LIB)) {
    fs.rmSync(LIB);
  }
} else if (process.argv[2] == "help") {
  console.log(`${process.argv[1]} <target>`);
  console.log("<target>: ");
  console.log("                    compile cgraph");
  console.log("          test      test cgraph");
  console.log("          clean     clean all the generated files");
  console.log("          distclean clean all the generated files and directories");
  console.log("          help      commands to this program");
} else {
  console.log(`${process.argv[2]} is an unsupported command`);
  console.log(`use \"${process.argv[1]} help\" to know all supported commands`);
}
