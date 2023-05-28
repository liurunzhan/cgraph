@echo off
setlocal enableextensions
setlocal enabledelayedexpansion

rem Date : 2022-07-01
rem A script to compile Library cgraph in Unix-like and Windows Platforms
rem gets source files iteratively from Directory src

rem project
set PRO=cgraph

rem directory tree
rem set DIR=%~dp0
set DIR=.
set INC=%DIR%\include
set SRC=%DIR%\src
set SRC_TYPE=%SRC%\type
set TST=%DIR%\tests
set LIB=%DIR%\lib

rem compiler configuration
set CC=cc
set CFLAGS=-std=c89 -Wall -pedantic

set TARBITS=32
if TARBITS == "32" (
  set "CFLAGS=%CFLAGS% -m32"
) else if TARBITS == "64" (
  set "CFLAGS=%CFLAGS% -m64"
)

set SHARED=true
set CSFLAGS=-shared
if SHARED == "false" (
	set CSFLAGS=-static
)

if not CC == tcc (
  set "CFLAGS=%CFLAGS% -pedantic-errors"
)

if not CC == clang (
  set "CFLAGS=%CFLAGS% -fPIC"
)

rem debug or release mode
set MODE=debug
if MODE == "debug" (
  set "CFLAGS=%CFLAGS% -g -DDEBUG -O0"
) else if MODE == "release" (
  set "CFLAGS=%CFLAGS% -O2"
)

rem build and clean directories and files
set MKDIR=mkdir
set MKDIRFLAGS=
set RM=del
set RMFLAGS=/Q /F
set RMDIR=rd
set RMDIRFLAGS=/Q

rem package shared library
set AR=ar
set ARFLAGS=-rcs

if TARBITS == "32" (
  set "ARFLAGS=%ARFLAGS% -X32"
) else if TARBITS == "64" (
  set "ARFLAGS=%ARFLAGS% -X64"
) else if TARBITS == "32_64" (
  set "ARFLAGS=%ARFLAGS% -X32_64"
)

rem target files
set LIBSHARED=%LIB%\lib%PRO%.dll
set LIBSTATIC=%LIB%\lib%PRO%.lib
rem test files
set TSTFILE=%TST%\%PRO%.c
set TSTTARGET=%TST%\%PRO%.exe

set PAR="%~1"

if %PAR% == "" (
  %MKDIR% %MKDIRFLAGS% %LIB%
  set OFILES=""
  for /R %SRC% %%F in (*.c) do (
    set file=%%F
    set obj=!file:.c=.o!
    set dep=!file:.c=.d!
    echo compile !file! to !obj!
    %CC% %CFLAGS% -I%INC% -I%SRC_TYPE% -c !file! -o !obj! -MD -MF !dep!
    set "OFILES=!OFILES!!obj! "
  )
  set OFILES=!OFILES:~2,-1!
  echo compile %LIBSHARED%
  %CC% %CSFLAGS% -o %LIBSHARED% !OFILES!
  echo compile %LIBSTATIC%
  %AR% %ARFLAGS% %LIBSTATIC% !OFILES!
) else if %PAR% == "test" (
  echo compile %TSTFILE% to %TSTTARGET%
  %CC% %CFLAGS% -I%INC% -o %TSTTARGET% %TSTFILE% -L%LIB% %CSFLAGS% -l%PRO% -lm
  echo test %TSTTARGET% with %TST%\elements.csv
  %TSTTARGET% %TST%\elements.csv
) else if %PAR% == "clean" (
  for /R %SRC% %%F in (*.c) do (
    set file=%%F
    set obj=!file:.c=.o!
    echo clean !obj!
    %RM% %RMFLAGS% !obj!
    set dep=!file:.c=.d!
    echo clean !dep!
    %RM% %RMFLAGS% !dep!
  )
  %RM% %RMFLAGS% %LIBSHARED%
  %RM% %RMFLAGS% %LIBSTATIC%
  %RM% %RMFLAGS% %TSTTARGET%
) else if %PAR% == "distclean" (
  for /R %SRC% %%F in (*.c) do (
    set file=%%F
    set obj=!file:.c=.o!
    echo clean !obj!
    %RM% %RMFLAGS% !obj!
    set dep=!file:.c=.d!
    echo clean !dep!
    %RM% %RMFLAGS% !dep!
  )
  %RM% %RMFLAGS% %LIBSHARED%
  %RM% %RMFLAGS% %LIBSTATIC%
  %RM% %RMFLAGS% %TSTTARGET%
  %RMDIR% %RMDIRFLAGS% %LIB%
) else if %PAR% == "help" (
  echo "%0 <target>"
  echo "<target>: "
  echo "                    compile cgraph"
  echo "          test      test cgraph"
  echo "          clean     clean all the generated files"
  echo "          distclean clean all the generated files and directories"
  echo "          help      commands to this program"
) else (
  echo %1 is an unsupported command
  echo use "%0 help" to know all supported commands
)
