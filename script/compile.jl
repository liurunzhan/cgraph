#!/usr/bin/julia

PRO = "cgraph"
DIR = "."
INC = joinpath(DIR, "include")
SRC = joinpath(DIR, "src")
TST = joinpath(DIR, "test")
LIB = joinpath(DIR, "lib")

CC = "cc"
CFLAGS = ["-pedantic", "-Wall", "-fpic", "-std=c89"]
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug"
  push!(CFLAGS, "-g")
  push!(CFLAGS, "-DDEBUG")
elseif MODE == "release"
  push!(CFLAGS, "-static")
  push!(CFLAGS, "-O2")
end

# package shared library
AR = "ar"
ARFLAGS = "-rcs"

if Sys.iswindows()
  # target files
  LIBSHARED = joinpath(LIB, "lib$PRO.dll")
  LIBSTATIC = joinpath(LIB, "lib$PRO.a")
  # test files
  TSTFILE = joinpath(TST, "$PRO.c")
  TSTTARGET = joinpath(TST, "$PRO.exe")
else
  # target files
  LIBSHARED = joinpath(LIB, "lib$PRO.so")
  LIBSTATIC = joinpath(LIB, "lib$PRO.a")
  # test files
  TSTFILE = joinpath(TST, "$PRO.c")
  TSTTARGET = joinpath(TST, PRO)
end

CFILES = []
for file in readdir(SRC)
  if nothing != match(r".c$", file)
    push!(CFILES, file)
  end
end

args = ARGS
if length(args) == 0
  mkpath("$LIB")
  OFILES = []
  for file in CFILES
    obj = replace(file, r".c$"=>".o")
    src_path = joinpath(SRC, file)
    obj_path = joinpath(SRC, obj)
    push!(OFILES, obj_path)
    println("compile $src_path to $obj_path")
    run(`$CC $CFLAGS -I$INC -c $src_path -o $obj_path`)
  end
  println("compile $LIBSHARED")
  run(`$CC $CSFLAGS -o $LIBSHARED $OFILES`)
  println("compile $LIBSTATIC");
  run(`$AR $ARFLAGS $LIBSTATIC $OFILES`)
elseif 1 == length(args)
  if args[1] == "test"
    println("compile $TSTFILE to $TSTTARGET")
    run(`$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm`)
    tst_path = joinpath(TST, "elements.csv")
    println("test $TSTTARGET with $tst_path")
    run(`$TSTTARGET $tst_path`)
  elseif args[1] == "clean"
    for file in CFILES
      obj = replace(file, r".c$"=>".o")
      println("clean ", joinpath(SRC, obj))
      rm(joinpath(SRC, obj), force=true)
    end
    println("clean $LIBSTATIC")
    rm("$LIBSTATIC", force=true)
    println("clean $LIBSHARED")
    rm("$LIBSHARED", force=true)
    println("clean $TSTTARGET")
    rm("$TSTTARGET", force=true)
  elseif args[1] == "distclean"
    for file in CFILES
      obj = replace(file, r".c$"=>".o")
      println("clean ", joinpath(SRC, obj))
      rm(joinpath(SRC, obj), force=true)
    end
    println("clean $LIBSTATIC")
    rm("$LIBSTATIC", force=true)
    println("clean $LIBSHARED")
    rm("$LIBSHARED", force=true)
    println("clean $LIB")
    rm("$LIB", force=true)
    println("clean $TSTTARGET")
    rm("$TSTTARGET", force=true)
  elseif args[1] == "help"
    println(PROGRAM_FILE, "    <target>")
    println("<target>: ")
    println("                    compile cgraph")
    println("          test      test cgraph")
    println("          clean     clean all the generated files")
    println("          distclean clean all the generated files and directories")
    println("          help      commands to this program")
  else
    println(args[1], " is an unsupported command")
    println("use \"", PROGRAM_FILE, " help\" to know all supported commands")
  end
else
  println(args[1], " is an unsupported command")
  println("use \"", PROGRAM_FILE, " help\" to know all supported commands")
end