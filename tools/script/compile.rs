#!/usr/bin/env rustx

use std::fs;
use std::env;
use std::path;
use std::process::Command;

fn main() {
  let PRO = "cgraph";
  let DIR = path::Path::new(".");
  let INC = DIR.join("include");
  let SRC = DIR.join("src");
  let SRC_TYPE = SRC.join("type");
  let TST = DIR.join("tests");
  let LIB = DIR.join("lib");

  let CC = "cc";
  let mut CFLAGS = "-std=c89 -Wall -pedantic -fPIC".to_string();
  let CSFLAGS = "-shared";
  
  let MODE = "debug";
  if MODE == "debug" {
    CFLAGS.push_str(" -g -DDEBUG");
  } else if MODE == "release" {
    CFLAGS.push_str(" -static -O2");
  }
  
  //  package shared library
  let AR = "ar";
  let ARFLAGS = "-rcs";

	let mut LIBSHARED: _;
	let mut LIBSTATIC: _;
	let mut TSTFILE: _;
	let mut TSTTARGET: _;
  if env::consts::OS == "windows" {
    //  target files
    LIBSHARED = LIB.join(format!("lib{}.dll", PRO));
    LIBSTATIC = LIB.join(format!("lib{}.lib", PRO));
    //  test files
    TSTFILE = TST.join(format!("{}.c", PRO));
    TSTTARGET = TST.join(format!("{}.exe", PRO));
  } else {
    //  target files
    LIBSHARED = LIB.join(format!("lib{}.so", PRO));
    LIBSTATIC = LIB.join(format!("lib{}.a", PRO));
    //  test files
    TSTFILE = TST.join(format!("{}.c", PRO));
    TSTTARGET = TST.join(format!("{}", PRO));
  }
  
  let mut CFILES: Vec<path::PathBuf> = Vec::new();
  for file in SRC.read_dir().expect("read_dir call failed") {
    if let Ok(file) = file {
      let path = file.path();
      if path.is_file() && path.extension() != None && "c" == path.extension().unwrap() && path.file_name().unwrap().to_str().unwrap().starts_with(".") {
        let path = file.path();
        CFILES.push(path);
      }
    }
  }

  let args: Vec<String> = env::args().collect();
  if args.len() == 1 {
    if !LIB.exists() {
      fs::create_dir(LIB).unwrap();
    }
    for file in CFILES {
      let obj = file.with_extension("o");
      let dep = file.with_extension("d");
      println!("compile {} to {}", file.display(), obj.display());
      if env::consts::OS == "windows" {
        Command::new("cmd")
                .args(&["/C", CC]);
      } else {
        Command::new("sh")
                .args(&["-c", CC]);
      }
    }

  } else if args[1] == "test" {

  } else if args[1] == "clean" {
    for file in CFILES {
      let obj = file.with_extension("o");
      let dep = file.with_extension("d");
      println!("clean {}", obj.display());
      if obj.exists() {
        fs::remove_file(obj);
      }
      println!("clean {}", dep.display());
      if dep.exists() {
        fs::remove_file(dep);
      }
    }
    println!("clean {}", LIBSHARED.display());
    if LIBSHARED.exists() {
      fs::remove_file(LIBSHARED);
    }
    println!("clean {}", LIBSTATIC.display());
    if LIBSTATIC.exists() {
      fs::remove_file(LIBSTATIC);
    }
  } else if args[1] == "distclean" {
    for file in CFILES {
      let obj = file.with_extension("o");
      let dep = file.with_extension("d");
      println!("clean {}", obj.display());
      if obj.exists() {
        fs::remove_file(obj);
      }
      println!("clean {}", dep.display());
      if dep.exists() {
        fs::remove_file(dep);
      }
    }
    println!("clean {}", LIBSHARED.display());
    if LIBSHARED.exists() {
      fs::remove_file(LIBSHARED);
    }
    println!("clean {}", LIBSTATIC.display());
    if LIBSTATIC.exists() {
      fs::remove_file(LIBSTATIC);
    }
    println!("clean {}", LIB.display());
    if LIB.exists() {
      fs::remove_file(LIB);
    }
  } else if args[1] == "help" {
    println!("{} <target>", file!());
    println!("<target>: ");
    println!("                    compile cgraph");
    println!("          test      test cgraph\n");
    println!("          clean     clean all the generated files");
    println!("          distclean clean all the generated files and directories");
    println!("          help      commands to this PROgram");
  } else {
    println!("{} is an unsupported command", args[1]);
    println!("use \"{} help\" to know all supported commands", file!());
  }
}
