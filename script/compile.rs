#!/usr/bin/env rustx

use std::env;

fn main() {
  let PRO = "cgraph";
  let DIR = ".";
  let INC = "include";
  let SRC = "src";
  let TST = "test"；
  let LIB = "lib";

  let args: Vec<_> = env::args().collect();
  if args.len() == 0 {

  } else if args[0] == "test" {

  } else if args[0] == "clean" {

  } else if args[0] == "distclean" {

  } else if args[0] == "help" {
    println!("{} <target>", );
    println!("<target>: ");
    println!("                    compile cgraph");
    println!("          test      test cgraph\n");
    println!("          clean     clean all the generated files");
    println!("          distclean clean all the generated files and directories");
    println!("          help      commands to this program");
  } else {
    println!("{} is an unsupported command", args[0]);
    println!("use \"{} help\" to know all supported commands");
  }
}
