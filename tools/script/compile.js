#!/usr/bin/env node

const path = require("path");
const fs = require("fs");

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

var SRCS = [];
getsubdirs(SRC, SRCS);

var CFILES = [];
for (var i = 0; i < SRCS.length; i++) {
  const files = fs.readdirSync(SRCS[i]);
  for (var j = 0; j < files.length; j++) {
    var file = SRCS[i] + sep + files[j];
    var stats = fs.lstatSync(file);
    if (stats.isFile() && !files[j].startsWith(".") && files[j].endsWith(".c")) {
      CFILES.push(file);
    }
  }
}

if (process.argv.length == 2) {
  
} else if (process.argv[2] == "test") {

} else if (process.argv[2] == "clean") {
  
} else if (process.argv[2] == "distclean") {
  
} else if (process.argv[2] == "help") {
  console.log(process.argv[1] + " <target>");
  console.log("<target>: ");
  console.log("                    compile cgraph");
  console.log("          test      test cgraph");
  console.log("          clean     clean all the generated files");
  console.log("          distclean clean all the generated files and directories");
  console.log("          help      commands to this program");
} else {
  console.log(process.argv[2] + " is an unsupported command");
  console.log("use \"" + process.argv[1] + " help\" to know all supported commands");
}
