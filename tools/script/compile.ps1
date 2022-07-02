#!/bin/powershell

# project
$PRO="cgraph"

# directory tree
$DIR=Resolve-Path "."
$INC=Join-Path $DIR "include"
$SRC=Join-Path $DIR "src"
$SRC_TYPE=Join-Path $SRC "type"
$TST=Join-Path $DIR "tests"
$LIB=Join-Path $DIR "lib"

# compiler configuration
$CFLAGS="-std=c89 -Wall -pedantic -fPIC"
$CSFLAGS="-shared".Split()

$MODE="debug"
if($MODE -ceq "debug") {
  $CFLAGS="$CFLAGS -g -DDEBUG"
} elseif($MODE -ceq "release") {
  $CFLAGS="$CFLAGS -static -O2"
}
$CFLAGS=$CFLAGS.Split()

# source files
$CFILES=@(Get-ChildItem -Path $SRC -File -Recurse -Include *.c)

if($IsWindows) {
	# target files
	$LIBSHARED=Join-Path $LIB "lib$PRO.dll"
	$LIBSTATIC=Join-Path $LIB "lib$PRO.lib"
	# test files
	$TSTFILE=Join-Path $TST "$PRO.c"
	$TSTTARGET=Join-Path $TST "$PRO.exe"
} else {
	# target files
	$LIBSHARED=Join-Path $LIB "lib$PRO.so"
	$LIBSTATIC=Join-Path $LIB "lib$PRO.a"
	# test files
	$TSTFILE=Join-Path $TST "$PRO.c"
	$TSTTARGET=Join-Path $TST "$PRO"
}

$TSTCSV=Join-Path $TST "elements.csv"

# commands to $0
$OPT=$args

if($OPT.Count -eq 0) {
  mkdir -Path $LIB -Force
  foreach($file in $CFILES) {
    $obj=$file -replace "\.c", ".o"
		$dep=$file -replace "\.c", ".d"
		echo "compile $file to $obj"
    & cc $CFLAGS -Iinclude -Isrc/type -c $file -o $obj -MD -MF $dep
  }
  echo "compile $LIBSHARED"
  cc -shared -o $LIBSHARED $SRC\*.o
  echo "compile $LIBSTATIC"
  ar -rcs $LIBSTATIC $SRC\*.o
} elseif($OPT[0] -ceq "test") {
  echo "compile $TSTFILE to $TSTTARGET"
  & cc $CFLAGS -Iinclude -o $TSTTARGET $TSTFILE -Llib -static -l$PRO -lm
  echo "test $TSTTARGET with $TSTCSV"
  & $TSTTARGET $TSTCSV
} elseif($OPT[0] -ceq "clean") {
  foreach($file in $CFILES) {
    $obj=$file -replace "\.c", ".o"
    echo "clean $obj"
    rm -Force $obj
    $dep=$file -replace "\.c", ".d"
    echo "clean $dep"
    rm -Force $dep
  }
  echo "clean $LIBSHARED"
  rm -Force $LIBSHARED
  echo "clean $LIBSTATIC"
  rm -Force $LIBSTATIC
  echo "clean $TSTTARGET"
  rm -Force $TSTTARGET
} elseif($OPT[0] -ceq "distclean") {
  foreach($file in $CFILES) {
    $obj=$file -replace "\.c", ".o"
    echo "clean $obj"
    rm -Force $obj
    $dep=$file -replace "\.c", ".d"
    echo "clean $dep"
    rm -Force $dep
  }
  echo "clean $LIBSHARED"
  rm -Force $LIBSHARED
  echo "clean $LIBSTATIC"
  rm -Force $LIBSTATIC
  echo "clean $LIB"
  rmdir -Force -Recurse -Path $LIB
  echo "clean $TSTTARGET"
  rm -Force $TSTTARGET
} elseif($OPT[0] -ceq "help") {
  echo "$TSTTARGET"
  echo "<target>: "
  echo "                    compile cgraph"
  echo "          test      test cgraph"
  echo "          clean     clean all the generated files"
  echo "          distclean clean all the generated files and directories"
  echo "          help      commands to this program"
} else {
  echo "$OPT[0] is an unsupported command"
  echo "use \" help\" to know all supported commands"
}