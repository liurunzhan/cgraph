#!/usr/bin/env ts-node

// Date : 2022-07-01
// A script to compile Library cgraph in Unix-like and Windows Platforms
// gets source files iteratively from Directory src

const syspath = require("path");
const fs = require("fs");
const os = require("os");
const child_process = require("child_process");

let PRO: string = "cgraph";
let DIR: string = ".";
let INC: string = syspath.join(DIR, "include");
let SRC: string = syspath.join(DIR, "src");
let SRC_TYPE: string = syspath.join(SRC, "type");
let TST: string = syspath.join(DIR, "tests");
let LIB: string = syspath.join(DIR, "lib");

let CC: string = "cc";
let CFLAGS: string = "-std=c89 -Wall -pedantic -fPIC";
let CSFLAGS: string = "-shared";

let MODE: string = "debug";
if (MODE == "debug") {
  CFLAGS.concat(" -g -DDEBUG");
} else if (MODE == "release") {
  CFLAGS.concat(" -static -O2");
}

// package shared library
let AR: string = "ar";
let ARFLAGS: string = "-rcs";

// source files
// get all subdirectories
function getsubdirs(path: string, dirs: string[]) {
  const files: string[] = fs.readdirSync(path);
  for (let i: number = 0; i < files.length; i++) {
    let subpath: string  = syspath.join(path, files[i]);
    let stats: any = fs.lstatSync(subpath);
    if (stats.isDirectory() && !files[i].startsWith(".")) {
      dirs.push(subpath);
      getsubdirs(subpath, dirs);
    }
  }
}

// get all source files from subdirectories
let SRCS: string[] = [];
getsubdirs(SRC, SRCS);

let CFILES: string[] = [];
for (let i: number = 0; i < SRCS.length; i++) {
  const files: string[] = fs.readdirSync(SRCS[i]);
  for (let j: number = 0; j < files.length; j++) {
    let file: string = syspath.join(SRCS[i], files[j]);
    let stats: any = fs.lstatSync(file);
    if (stats.isFile() && /^((?!\.).)*\.c$/.test(files[j])) {
      CFILES.push(file);
    }
  }
}

let LIBSHARED: string;
let LIBSTATIC: string;
let TSTSUFFIX: string;
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
  let OFILES = [];
  for (let i: number = 0; i < CFILES.length; i++) {
    let obj: string = CFILES[i].replace(/\.c$/, ".o");
    let dep: string = CFILES[i].replace(/\.c$/, ".d");
    console.log(`compile ${CFILES[i]} to ${obj}`);
    child_process.exec(`${CC} ${CFLAGS} -I${INC} -I${SRC_TYPE} -c ${CFILES[i]} -o ${obj} -MD -MF ${dep}`);
    OFILES.push(obj);
  }
  console.log(`compile ${LIBSHARED}`);
  child_process.exec(`${CC} ${CSFLAGS} -o ${LIBSHARED} ${OFILES.join(" ")}`);
  console.log(`compile ${LIBSTATIC}`);
  child_process.exec(`${AR} ${ARFLAGS} ${LIBSTATIC} ${OFILES.join(" ")}`);
} else if (process.argv[2] == "test") {
  const files: string[] = fs.readdirSync(TST);
  for (let i: number = 0; i < files.length; i++) {
    let file: string = syspath.join(TST, files[i]);
    let stats: any = fs.lstatSync(file);
    if (stats.isFile() && /^((?!\.).)*\.c$/.test(files[i])) {
      let target: string = file.replace(/\.c$/, TSTSUFFIX);
      console.log(`compile ${file} to ${target}`);
      child_process.exec(`${CC} ${CFLAGS} -I${INC} -o ${target} ${file} -L${LIB} -static -l${PRO} -lm`);
      console.log(`test ${target}`);
      child_process.exec(target);
    }
  }
} else if (process.argv[2] == "clean") {
  for (let i: number = 0; i < CFILES.length; i++) {
    let obj: string = CFILES[i].replace(/\.c$/, ".o");
    console.log(`clean ${obj}`);
    if (fs.existsSync(obj)) {
      fs.unlink(obj);
    }
    let dep: string = CFILES[i].replace(/\.c$/, ".d");
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
  for (let i: number = 0; i < CFILES.length; i++) {
    let obj: string = CFILES[i].replace(/\.c$/, ".o");
    console.log(`clean ${obj}`);
    if (fs.existsSync(obj)) {
      fs.unlink(obj);
    }
    let dep: string = CFILES[i].replace(/\.c$/, ".d");
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
