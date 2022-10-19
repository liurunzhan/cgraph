#!/usr/bin/env -S odin run

package compile

import          "core:os"
import filepath "core:path/filepath"
import os2      "core:os/os2"
import          "core:fmt"
import          "core:strings"

main :: proc() {
  PRO : string = "cgraph";
  DIR : string = ".";
  INC : string = filepath.join([]string{DIR, "include"});
  SRC : string = filepath.join([]string{DIR, "src"});
  SRC_TYPE : string = filepath.join([]string{SRC, "type"});
  TST : string = filepath.join([]string{DIR, "tests"});
  LIB : string = filepath.join([]string{DIR, "lib"});

  CC : string = "cc";
  CFLAGS : string = "-std=c89 -Wall -pedantic -fPIC";
  CSFLAGS : string = "-shared";

  MODE : string = "debug";
  if MODE == "debug" {
    CFLAGS = strings.join([]string{CFLAGS}, " -g -DDEBUG");
  } else if MODE == "release" {
    CFLAGS = strings.join([]string{CFLAGS}, " -static -O2");
  }

  //package shared library
  AR : string = "ar";
  ARFLAGS : string = "-rcs";

  LIBSHARED : string;
  LIBSTATIC : string;
  TSTFILE : string;
  TSTTARGET : string;
  when ODIN_OS == .Windows {
    // target files
    LIBSHARED = filepath.join(LIB, fmt.aprintf("lib%s.dll", PRO));
    LIBSTATIC = filepath.join(LIB, fmt.aprintf("lib%s.lib", PRO));
    // test files
    TSTFILE = filepath.join(TST, fmt.aprintf("%s.c", PRO));
    TSTTARGET = filepath.join(TST, fmt.aprintf("%s.exe", PRO));
  } else {
    // target files
    LIBSHARED = filepath.join([]string{LIB, fmt.aprintf("lib%s.so", PRO)});
    LIBSTATIC = filepath.join([]string{LIB, fmt.aprintf("lib%s.a", PRO)});
    // test files
    TSTFILE = filepath.join([]string{TST, fmt.aprintf("%s.c", PRO)});
    TSTTARGET = filepath.join([]string{TST, PRO});
  }

  CFILES := make([dynamic]string);
  for file in filepath.walk(SRC) {
    if strings.has_suffix(file, ".c") {
      append(&CFILES, filepath.join([]string{SRC, file}));
    }
  }

  args := os.args;
  if len(args) == 1 {
    if !os2.exists(LIB) {
      os2.mkdir_all(LIB, 777);
    }
    OFILES := make([dynamic]string);
    for file in CFILES {
      obj : string = strings.replace(file, ".c", ".o", 1);
      dep : string = strings.replace(file, ".c", ".d", 1);
	    fmt.println("compile ", file, " to ", obj);
      // exec(fmt"{CC} {CFLAGS} -I{INC} -I{SRC_TYPE} -c {file} -o {obj} -MD -MF {dep}");
      append(&OFILES, obj);
    }
    delete(OFILES);
  } else if args[1] == "test" {
    fmt.println("compile ", TSTFILE, " to ", TSTTARGET);
    // exec(fmt"{CC} {CFLAGS} -I{INC} -o {TSTTARGET} {TSTFILE} -L{LIB} -static -l{PRO} -lm");
    tst_path : string = filepath.join([]string{TST, "elements.csv"});
    fmt.println("test ", TSTTARGET, " with ", tst_path);
    // exec(fmt"{TSTTARGET} {tst_path}");
  } else if args[1] == "clean" {
    for file in CFILES {
      obj : string = strings.replace(file, ".c", ".o", 1);
      fmt.println("clean ", obj);
      if os2.exists(obj) {
        os2.remove_all(obj);
      }
      dep : string = strings.replace(file, ".c", ".d", 1);
      fmt.println("clean ", dep);
      if os2.exists(dep) {
        os2.remove_all(dep);
      }
    }
    fmt.println("clean ", LIBSTATIC);
    if os2.exists(LIBSTATIC) {
      os2.remove_all(LIBSTATIC);
    }
    fmt.println("clean ", LIBSHARED);
    if os2.exists(LIBSHARED) {
      os2.remove_all(LIBSHARED);
    }
    fmt.println("clean ", TSTTARGET);
    if(os2.exists(TSTTARGET)) {
      os2.remove_all(TSTTARGET);
    }
  } else if args[1] == "distclean" {
    for file in CFILES {
      obj : string = strings.replace(file, ".c", ".o", 1);
      fmt.println("clean ", obj);
      if os2.exists(obj) {
        os2.remove_all(obj);
      }
      dep : string = strings.replace(file, ".c", ".d", 1);
      fmt.println("clean ", dep);
      if os2.exists(dep) {
        os2.remove_all(dep);
      }
    }
    fmt.println("clean ", LIBSTATIC);
    if os2.exists(LIBSTATIC) {
      os2.remove_all(LIBSTATIC);
    }
    fmt.println("clean ", LIBSHARED);
    if os2.exists(LIBSHARED) {
      os2.remove_all(LIBSHARED);
    }
    fmt.println("clean ", LIB);
    if os2.exists(LIB) {
      os2.remove_all(LIB);
    }
    fmt.println("clean ", TSTTARGET);
    if(os2.exists(TSTTARGET)) {
      os2.remove_all(TSTTARGET);
    }
  } else if args[1] == "help" {
    fmt.println(args[0], "    <target>");
    fmt.println("<target>: ");
    fmt.println("                    compile cgraph");
    fmt.println("          test      test cgraph");
    fmt.println("          clean     clean all the generated files");
    fmt.println("          distclean clean all the generated files and directories");
    fmt.println("          help      commands to this program");
  }  else {
    fmt.println(args[0], " is an unsupported command");
    fmt.println("use \"", args[1], " help\" to know all supported commands");
  }
  delete(CFILES);
}
