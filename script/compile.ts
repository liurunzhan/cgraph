#!/usr/bin/tsc 

let path = require('path');

let PRO : string = "cgraph";
let DIR : string = ".";
let INC : string = DIR + path.sep + "include";
let SRC : string = DIR + path.sep + "src";
let TST : string = DIR + path.sep + "test";
let LIB : string = DIR + path.sep + "lib";

let CC : string = "cc";
let CFLAGS : string = "-pedantic -Wall -fPIC -std=c89";
let CSFLAGS : string = "-shared";

let MODE : string = "debug";
if (MODE == "debug") {
  CFLAGS.concat(" -g -DDEBUG");
} else if (MODE == "release") {
  CFLAGS.concat(" -static -O2");
}

let AR : string = "ar";
let ARFLAGS : string = "-rcs";