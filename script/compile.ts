#!/usr/bin/tsc 

let path = require('path');

let PRO : string = "cgraph";
let DIR : string = ".";
let INC : string = DIR + path.sep + "include";
let SRC : string = DIR + path.sep + "src";
let TST : string = DIR + path.sep + "test";
let LIB : string = DIR + path.sep + "lib";

let CC : string = "cc";
let CFLAGS : string = "-std=c89 -Wall -pedantic -fPIC";
let CSFLAGS : string = "-shared";

let MODE : string = "debug";
if (MODE == "debug") {
  CFLAGS.concat(" -g -DDEBUG");
} else if (MODE == "release") {
  CFLAGS.concat(" -static -O2");
}

// build and clean directories and files
let MKDIR : string = "mkdir";
let RM : string = "rm";
let RMFLAGS : string = "-rf";

let RMDIR : string = "rm";
let RMDIRFLAGS : string = "-rf";

let AR : string = "ar";
let ARFLAGS : string = "-rcs";

