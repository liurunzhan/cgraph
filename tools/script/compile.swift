#!/usr/bin/env swift

import Foundation

let fileManager = FileManager.default

let PRO : String = "cgraph"
let DIR : String = "."
let INC : String = DIR + "/include"
let SRC : String = DIR + "/src"
let SRC_TYPE : String = SRC + "/type"
let TST : String = DIR + "/tests"
let LIB : String = DIR + "/lib"

let CC : String = "cc"
var CFLAGS : String = "-std=c89 -Wall -pedantic -fPIC"
let CSFLAGS : String = "-shared"

let MODE : String = "debug"
if MODE == "debug" {
  CFLAGS += " -g -DDEBUG -O0"
} else if MODE == "release" {
  CFLAGS += " -O2"
}

//  package shared library
let AR : String = "ar"
let ARFLAGS : String = "-rcs"

// source files
var CFILES = [String]()
for file in fileManager.subpaths(atPath: SRC)!{
  if(file.hasSuffix(".c")) {
    CFILES.append("\(SRC)/\(file)")
  }
}

// target files
let LIBSHARED : String = "\(LIB)/lib\(PRO).so"
let LIBSTATIC : String = "\(LIB)/lib\(PRO).a"
// test files
let TSTFILE : String = "\(TST)/\(PRO).c"
let TSTTARGET : String = "\(TST)/\(PRO)"

func runCommand(command: String, args: [String]) -> Void {
  let task = Process()
  task.executableURL = URL(fileURLWithPath: command)
  task.arguments = args
  print(args)
  try! task.run()
  task.waitUntilExit()
}

var args : [String] = CommandLine.arguments
if CommandLine.argc == 1 {
  if !fileManager.fileExists(atPath: LIB) {
    try! fileManager.createDirectory(atPath: LIB, withIntermediateDirectories: true, attributes: nil)
  }
  for file in CFILES {
    let obj : String = file.replacingOccurrences(of: ".c", with: ".o")
    let dep : String = file.replacingOccurrences(of: ".c", with: ".d")
    print("compile \(file) to \(obj)")
    runCommand(command: CC, args: [CFLAGS.components(separatedBy: " "), ["-I\(INC)", "-I\(SRC_TYPE)", "-c", file, "-o", obj, "-MD", "-MF", dep]].reduce([], +))
  }
  print("compile \(LIBSHARED)")

  print("compile \(LIBSTATIC)")

} else if args[1] == "test" {

} else if args[1] == "clean" {
  for file in CFILES {
    let OBJ : String = file.replacingOccurrences(of: ".c", with: ".o")
    print("clean \(OBJ)")
    if fileManager.fileExists(atPath: OBJ) {
      try! fileManager.removeItem(atPath: OBJ)
    }
    let DEP : String = file.replacingOccurrences(of: ".c", with: ".d")
    print("clean \(DEP)")
    if fileManager.fileExists(atPath: DEP) {
      try! fileManager.removeItem(atPath: DEP)
    }
  }
  print("clean \(LIBSHARED)")
  if fileManager.fileExists(atPath: LIBSHARED) {
    try! fileManager.removeItem(atPath: LIBSHARED)
  }
  print("clean \(LIBSTATIC)")
  if fileManager.fileExists(atPath: LIBSTATIC) {
    try! fileManager.removeItem(atPath: LIBSTATIC)
  }
  print("clean \(TSTTARGET)")
  if fileManager.fileExists(atPath: TSTTARGET) {
    try! fileManager.removeItem(atPath: TSTTARGET)
  }
} else if args[1] == "distclean" {
  for file in CFILES {
    let OBJ : String = file.replacingOccurrences(of: ".c", with: ".o")
    print("clean \(OBJ)")
    if fileManager.fileExists(atPath: OBJ) {
      try! fileManager.removeItem(atPath: OBJ)
    }
    let DEP : String = file.replacingOccurrences(of: ".c", with: ".d")
    print("clean \(DEP)")
    if fileManager.fileExists(atPath: DEP) {
      try! fileManager.removeItem(atPath: DEP)
    }
  }
  print("clean \(LIBSHARED)")
  if fileManager.fileExists(atPath: LIBSHARED) {
    try! fileManager.removeItem(atPath: LIBSHARED)
  }
  print("clean \(LIBSTATIC)")
  if fileManager.fileExists(atPath: LIBSTATIC) {
    try! fileManager.removeItem(atPath: LIBSTATIC)
  }
  print("clean \(LIB)")
  if fileManager.fileExists(atPath: LIB) {
    try! fileManager.removeItem(atPath: LIB)
  }
  print("clean \(TSTTARGET)")
  if fileManager.fileExists(atPath: TSTTARGET) {
    try! fileManager.removeItem(atPath: TSTTARGET)
  }
} else if args[1] == "help" {
  print("\(args[0]) <target>")
  print("<target>: ")
  print("                    compile cgraph")
  print("          test      test cgraph")
  print("          clean     clean all the generated files")
  print("          distclean clean all the generated files and directories")
  print("          help      commands to this program")
} else {
  print("\(args[1]) is an unsupported command");
  print("use \"\(args[0]) help\" to know all supported commands");
}
