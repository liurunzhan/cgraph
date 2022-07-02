@echo off
setlocal enabledelayedexpansion

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
set CSFLAGS=-shared

if CC != tcc (
  set CFLAGS+=" -pedantic-errors"
)

if CC != clang (
  set CFLAGS+=" -fPIC"
)

rem debug or release mode
set MODE=debug
if MODE == "debug" (
  set CFLAGS+=" -g -DDEBUG"
) else if MODE == "release" (
  set CFLAGS+=" -static -O2"
)

rem build and clean directories and files
set MKDIR=mkdir
set RM=del
set RMFLAGS=/Q /F
set RMDIR=rd
set RMDIRFLAGS=/Q

rem package shared library
set AR=ar
set ARFLAGS=-rcs

rem target files
set LIBSHARED=%LIB%\lib%PRO%.dll
set LIBSTATIC=%LIB%\lib%PRO%.lib
rem test files
set TSTFILE=%TST%\%PRO%.c
set TSTTARGET=%TST%\%PRO%.exe

set PAR="%~1"

if %PAR% == "" (
  %MKDIR% %LIB%
  for /d %SRC% %%F in (*.c) do (
    set file=%%F
    set obj=!file:.c=.o!
		set dep=!file:.c=.d!
    echo compile !file! to !obj!
    %CC% %CFLAGS% -I%INC% -I%SRC_TYPE% -c !file! -o !obj! -MD -MF !dep!
  )
  echo compile %LIBSHARED%
  %CC% %CSFLAGS% -o %LIBSHARED% %SRC%\*.o
  echo compile %LIBSTATIC%
  %AR% %ARFLAGS% %LIBSTATIC% %SRC%\*.o
) else if %PAR% == "test" (
  echo compile %TSTFILE% to %TSTTARGET%
  %CC% %CFLAGS% -I%INC% -o %TSTTARGET% %TSTFILE% -L%LIB% -static -l%PRO% -lm
  echo test %TSTTARGET% with %TST%\elements.csv
  %TSTTARGET% %TST%\elements.csv
) else if %PAR% == "clean" (
  for /d %SRC% %%F in (*.c) do (
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
  for /d %SRC% %%F in (*.c) do (
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
