#!/usr/bin/env node

// Date : 2022-07-01
// A script to compile Library cgraph in Unix-like and Windows Platforms
// gets source files iteratively from Directory src

const syspath = require("path");
const fs = require("fs");
const os = require("os");
const child_process = require("child_process");

var PRO = "cgraph";
var DIR = ".";
var INC = syspath.join(DIR, "include");
var SRC = syspath.join(DIR, "src");
var SRC_TYPE = syspath.join(SRC, "type");
var TST = syspath.join(DIR, "tests");
var LIB = syspath.join(DIR, "lib");

var CC = "cc";
var CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
var CSFLAGS = "-shared";

var MODE = "debug";
if (MODE == "debug") {
  CFLAGS.concat(" -g -DDEBUG -O0");
} else if (MODE == "release") {
  CFLAGS.concat(" -O2");
}

// package shared library
var AR = "ar";
var ARFLAGS = "-rcs";

// source files
// get all subdirectories
function getsubdirs(path, dirs) {
  const files = fs.readdirSync(path);
  for (var i = 0; i < files.length; i++) {
    var subpath = syspath.join(path, files[i]);
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
    var file = syspath.join(SRCS[i], files[j]);
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
  LIBSHARED = syspath.join(LIB, `lib${PRO}.dll`);
  LIBSTATIC = syspath.join(LIB, `lib${PRO}.lib`);
  // test files
  TSTSUFFIX = ".exe";
} else {
  // target files
  LIBSHARED = syspath.join(LIB, `lib${PRO}.so`);
  LIBSTATIC = syspath.join(LIB, `lib${PRO}.a`);
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
    child_process.exec(`${CC} ${CFLAGS} -I${INC} -I${SRC_TYPE} -c ${CFILES[i]} -o ${obj} -MD -MF ${dep}`);
    OFILES.push(obj);
  }
  console.log(`compile ${LIBSHARED}`);
  child_process.exec(`${CC} ${CSFLAGS} -o ${LIBSHARED} ${OFILES.join(" ")}`);
  console.log(`compile ${LIBSTATIC}`);
  child_process.exec(`${AR} ${ARFLAGS} ${LIBSTATIC} ${OFILES.join(" ")}`);
} else if (process.argv[2] == "test") {
  const files = fs.readdirSync(TST);
  for (var i = 0; i < files.length; i++) {
    var file = syspath.join(TST, files[i]);
    var stats = fs.lstatSync(file);
    if (stats.isFile() && /^((?!\.).)*\.c$/.test(files[i])) {
      var target = file.replace(/\.c$/, TSTSUFFIX);
      console.log(`compile ${file} to ${target}`);
      child_process.exec(`${CC} ${CFLAGS} -I${INC} -o ${target} ${file} -L${LIB} -static -l${PRO} -lm`);
      console.log(`test ${target}`);
      child_process.exec(target);
    }
  }
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
