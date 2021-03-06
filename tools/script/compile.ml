#!/usr/bin/ocaml

let _PRO = "cgraph";;
let _DIR = ".";;
let _SEP = if Sys.win32 then "\\" else "/";;
let _INC = String.concat _SEP [ _DIR; "include" ];;
let _SRC = String.concat _SEP [ _DIR; "src" ];;
let _TST = String.concat _SEP [ _DIR; "test" ];;
let _LIB = String.concat _SEP [ _DIR; "lib" ];;

let _CC = "cc";;
let _CFLAGS = "-std=c89 -Wall -pedantic -fPIC";;
let _CSFLAGS = "-shared";;

let _MODE = "debug";;
let _CFLAGS = if String.equal _MODE "debug" then
    _CFLAGS ^ " -g -DDEBUG"
  else begin 
    if String.equal _MODE "release" then
      _CFLAGS ^ " -static -O2"
  end

(* package shared library *)
let _AR = "ar";;
let _ARFLAGS = "-rcs";;

if Sys.win32 then
  _LIBSHARED = String.concat _SEP [ _LIB; "lib" ^ PRO ^ ".dll" ];;
  _LIBSTATIC = String.concat _SEP [ _LIB; "lib" ^ PRO ^ ".lib" ];;
  _TSTFILE   = String.concat _SEP [ _TST; PRO ^ ".c" ];;
  _TSTTARGET = String.concat _SEP [ _TST; PRO ^ ".exe" ];;
else
  _LIBSHARED = String.concat _SEP [ _LIB; "lib" ^ PRO ^ ".so" ];;
  _LIBSTATIC = String.concat _SEP [ _LIB; "lib" ^ PRO ^ ".a" ];;
  _TSTFILE   = String.concat _SEP [ _TST; PRO ^ ".c" ];;
  _TSTTARGET = String.concat _SEP [ _TST; PRO ];;
end

let args = Sys.argv;;

if Array.length args == 0 then begin
  Format.print_string "hello";
end
else begin
  if String.equal args.(1) "test" then begin

  end
  else begin
    if String.equal args.(1) "clean" then begin

    end
    else begin
      if String.equal args.(1) "distclean" then begin

      end
      else begin
        if String.equal args.(1) "help" then begin
          Format.print_string args.(0); Format.print_string "    <target>"; Format.print_newline ();
          Format.print_string "<target>: "; Format.print_newline ();
          Format.print_string "                    compile cgraph"; Format.print_newline ();
          Format.print_string "          test      test cgraph"; Format.print_newline ();
          Format.print_string "          clean     clean all the generated files"; Format.print_newline ();
          Format.print_string "          distclean clean all the generated files and directories"; Format.print_newline ();
          Format.print_string "          help      commands to this program"; Format.print_newline ();
        end
        else begin
          Format.print_string args.(1); Format.print_string " is an unsupported command"; Format.print_newline ();
          Format.print_string "use \""; Format.print_string args.(0); Format.print_string " help\" to know all supported commands"; Format.print_newline ();
        end
      end
    end
  end
end