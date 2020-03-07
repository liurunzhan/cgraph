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
$CFLAGS="-ansi -pedantic -pedantic-errors -Wall -fPIC -g".Split()
$CSFLAGS="-shared".Split()

# source files
$CFILES=ls $SRC\*.c
# target files
$LIBSHARED=Join-Path $LIB "lib$PRO.dll"
$LIBSTATIC=Join-Path $LIB "lib$PRO.a"
# test files
$TSTFILE=Join-Path $TST "$PRO.c"
$TSTTARGET=Join-Path $TST "$PRO.exe"
$TSTCSV=Join-Path $TST "elements.csv"

# commands to $0
$OPT=$args
echo "$OPT"

if($OPT.Count -eq 0)
{
  mkdir -Path $LIB -Force
  foreach($file in $CFILES)
  {
    $obj=$file -replace "\.c", ".o"
    # echo "compile $file to $obj"
    & cc $CFLAGS -I./include -c $file -o $obj
  }
  echo "compile $LIBSHARED"
  cc -shared -o $LIBSHARED $SRC\*.o
  echo "compile $LIBSTATIC"
  ar -rcs $LIBSTATIC $SRC\*.o
}
elseif($OPT[0] -ceq "test")
{
  echo "compile $TSTFILE to $TSTTARGET"
  & cc $CFLAGS -I./include -o $TSTTARGET $TSTFILE -L./lib -static -lcgraph -lm
  echo "test $TSTTARGET with $TSTCSV"
  & $TSTTARGET $TSTCSV
}
elseif($OPT[0] -ceq "clean")
{
  foreach($file in $CFILES)
  {
    $obj=$file -replace "\.c", ".o"
    echo "clean $obj"
    rm $obj
  }
  echo "clean $LIBSHARED"
  rm $LIBSHARED
  echo "clean $LIBSTATIC"
  rm $LIBSTATIC
  echo "clean $TSTTARGET"
  rm $TSTTARGET
}
elseif($OPT[0] -ceq "distclean")
{
  foreach($file in $CFILES)
  {
    $obj=$file -replace "\.c", ".o"
    echo "clean $obj"
    rm $obj
  }
  echo "clean $LIBSHARED"
  rm $LIBSHARED
  echo "clean $LIBSTATIC"
  rm $LIBSTATIC
  echo "clean $LIB"
  rmdir $LIB
  echo "clean $TSTTARGET"
  rm $TSTTARGET
}
elseif($OPT[0] -ceq "help")
{
  echo "$TSTTARGET"
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