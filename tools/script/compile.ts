#!/usr/bin/env ts-node

let path = require("path");
let fs = require("fs");

const sep: string = path.sep;

let PRO: string = "cgraph";
let DIR: string = ".";
let INC: string = DIR + sep + "include";
let SRC: string = DIR + sep + "src";
let SRC_TYPE: string = SRC + sep + "type";
let TST: string = DIR + sep + "tests";
let LIB: string = DIR + sep + "lib";

let CC: string = "cc";
let CFLAGS: string = "-std=c89 -Wall -pedantic -fPIC";
let CSFLAGS: string = "-shared";

let MODE: string = "debug";
if (MODE == "debug") {
  CFLAGS.concat(" -g -DDEBUG");
} else if (MODE == "release") {
  CFLAGS.concat(" -static -O2");
}

// build and clean directories and files
let MKDIR: string = "mkdir";
let RM: string = "rm";
let RMFLAGS: string = "-rf";

let RMDIR: string = "rm";
let RMDIRFLAGS: string = "-rf";

let AR: string = "ar";
let ARFLAGS: string = "-rcs";

function getsubdirs(path: string, dirs: string[]) {
  const files: string[] = fs.readdirSync(path);
  for (let i: any = 0; i < files.length; i++) {
    let subpath: string  = path + sep + files[i];
    let stats: any = fs.lstatSync(subpath);
    if (stats.isDirectory() && !files[i].startsWith(".")) {
      dirs.push(subpath);
      getsubdirs(subpath, dirs);
    }
  }
}

let SRCS: string[] = [];
getsubdirs(SRC, SRCS);

let CFILES: string[] = [];
for (let i: any = 0; i < SRCS.length; i++) {
  const files: string[] = fs.readdirSync(SRCS[i]);
  for (let j: any = 0; j < files.length; j++) {
    let file: string = SRCS[i] + sep + files[j];
    let stats: any = fs.lstatSync(file);
    if (stats.isFile() && !files[j].startsWith(".") && files[j].endsWith(".c")) {
      CFILES.push(file);
    }
  }
}
console.log(CFILES);

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
