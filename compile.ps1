#!/bin/powershell

# project
$PRO="cgraph"

# directory tree
$DIR=Split-Path -Parent $MyInvocation.MyCommand.Definition
$INC=Join-Path $DIR "include"
$SRC=Join-Path $DIR "src"
$TST=Join-Path $DIR "test"
$LIB=Join-Path $DIR "lib"

# compiler configuration
# $CFLAGS=-ansi -pedantic -pedantic-errors -Wall -fPIC
# $CSFLAGS=-shared

# source files
$CFILES=ls $SRC\*.c
# target files
$LIBSHARED=Join-Path $LIB "lib$PRO.so"
$LIBSTATIC=Join-Path $LIB "lib$PRO.a"
# test files
$TSTFILE=Join-Path $TST "$PRO.c"
$TSTTARGET=Join-Path $TST $PRO

# commands to $0
$OPT=$args

if($OPT.Count -eq 0)
{
  mkdir -Path $LIB -Force
  foreach($file in $CFILES)
  {
    $obj=$file -replace "\.c", ".o"
    # echo "compile $file to $obj"
    cc -ansi -pedantic -pedantic-errors -Wall -fPIC -I$INC -c $file -o $obj
  }
  echo "compile $LIBSHARED"
  cc -shared -o $LIBSHARED $SRC\*.o
  echo "compile $LIBSTATIC"
  ar -rcs $LIBSTATIC $SRC\*.o
}
elseif($OPT.CompareTo("test"))
{
  echo "compile $TSTFILE to $TSTTARGET"
  & $CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm
  echo "test $TSTTARGET with $TST/elements.csv"
  & $TSTTARGET "$TST/elements.csv"
}
elseif($OPT.CompareTo("clean"))
{
  foreach($file in $CFILES)
  {
    $obj=$file -replace ".c", ".o"
    echo "clean $obj"
    & $RM $RMFLAGS $obj
  }
  echo "clean $LIBSHARED"
  & $RM $RMFLAGS $LIBSHARED
  echo "clean $LIBSTATIC"
  & $RM $RMFLAGS $LIBSTATIC
  echo "clean $TSTTARGET"
  & $RM $RMFLAGS $TSTTARGET
}
elseif($OPT.CompareTo("distclean"))
{
  foreach($file in $CFILES)
  {
    $obj=$file -replace ".c", ".o"
    echo "clean $obj"
    & $RM $RMFLAGS $obj
  }
  echo "clean $LIBSHARED"
  & $RM $RMFLAGS $LIBSHARED
  echo "clean $LIBSTATIC"
  & $RM $RMFLAGS $LIBSTATIC
  echo "clean $LIB"
  & $RM $RMFLAGS $LIB
  echo "clean $TSTTARGET"
  & $RM $RMFLAGS $TSTTARGET
}
elseif($OPT.CompareTo("help"))
{
  echo " <target>"
  echo "<target>: "
  echo "                    compile cgraph"
  echo "          test      test cgraph"
  echo "          clean     clean all the generated files"
  echo "          distclean clean all the generated files and directories"
  echo "          help      commands to this program"
}
else
{
  echo "$OPT[0] is an unsupported command"
  echo "use \" help\" to know all supported commands"
}