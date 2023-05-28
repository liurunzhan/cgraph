#!/usr/bin/ocaml

let _PRO = "cgraph";;
let _DIR = ".";;
let _SEP = if Sys.win32 then "\\" else "/";;
let _INC = String.concat _SEP [ _DIR; "include" ];;
let _SRC = String.concat _SEP [ _DIR; "src" ];;
let _TST = String.concat _SEP [ _DIR; "tests" ];;
let _LIB = String.concat _SEP [ _DIR; "lib" ];;

let _CC = "cc";;
let _CFLAGS = "-std=c89 -Wall -pedantic -fPIC";;
let _CSFLAGS = "-shared";;

let _MODE = "debug";;
let _CFLAGS = match _MODE with
  | "debug" -> _CFLAGS ^ " -g -DDEBUG -O0"
  | "release" -> _CFLAGS ^ " -O2"
	| _ -> assert false;;

(* package shared library *)
let _AR = "ar";;
let _ARFLAGS = "-rcs";;

(* target files *)
let _LIBSHARED = if Sys.win32 then String.concat _SEP [ _LIB; "lib" ^ _PRO ^ ".dll" ] else String.concat _SEP [ _LIB; "lib" ^ _PRO ^ ".so" ];;
let _LIBSTATIC = if Sys.win32 then String.concat _SEP [ _LIB; "lib" ^ _PRO ^ ".lib" ] else String.concat _SEP [ _LIB; "lib" ^ _PRO ^ ".a" ];;
(* test files *)
let _TSTFILE   = if Sys.win32 then String.concat _SEP [ _TST; _PRO ^ ".c" ] else String.concat _SEP [ _TST; _PRO ^ ".c" ];;
let _TSTTARGET = if Sys.win32 then String.concat _SEP [ _TST; _PRO ^ ".exe" ] else String.concat _SEP [ _TST; _PRO ];;

(* source files *)
(* get all subdirectories *)


let args = Sys.argv;;

match args.(1) with
  | exception index_out_of_bounds -> begin
    Format.print_string "hello";
  end
  | "test" -> begin
  end
  | "clean" -> begin
  end
  | "distclean" -> begin
  end
  | "help" -> begin
    Format.print_string args.(0); Format.print_string "    <target>"; Format.print_newline ();
    Format.print_string "<target>: "; Format.print_newline ();
    Format.print_string "                    compile cgraph"; Format.print_newline ();
    Format.print_string "          test      test cgraph"; Format.print_newline ();
    Format.print_string "          clean     clean all the generated files"; Format.print_newline ();
    Format.print_string "          distclean clean all the generated files and directories"; Format.print_newline ();
    Format.print_string "          help      commands to this program"; Format.print_newline ();
  end
  | _ -> begin
    Format.print_string args.(1); Format.print_string " is an unsupported command"; Format.print_newline ();
    Format.print_string "use \""; Format.print_string args.(0); Format.print_string " help\" to know all supported commands"; Format.print_newline ();
  end
