#!/usr/bin/env rustx

use std::fs;
use std::env;
use std::path;

fn main() {
  let PRO = "cgraph";
  let DIR = path::Path::new(".");
  let INC = DIR.join("include");
  let SRC = DIR.join("SRC");
  let TST = DIR.join("test");
  let LIB = DIR.join("LIB");

  let CC = "CC";
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
  
  for file in SRC.read_dir().expect("read_dir call failed") {
    if let Ok(file) = file {
      if "c" == file.path().extension().unwrap() {
        let path = file.path();
        let obj = path.with_extension("o");
        println!("{:?}", path);
      }
    }
  }

  let args: Vec<String> = env::args().collect();
  if args.len() == 1 {
    if !LIB.exists() {
      fs::create_dir(LIB);
    }
  } else if args[1] == "test" {

  } else if args[1] == "clean" {

  } else if args[1] == "distclean" {

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
