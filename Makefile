ROOT= .
SCR= $(ROOT)/script
TOOLS= make cmake xmake\
			 sh zsh fish tsh vsh cmd powershell \
			 tcc go rust haskell zig \
	     perl perl6 ruby python lua r julia lisp typescript \
	     java scala kotlin clojure groovy

MAKE= make

TOOL=
CMD=
COMPILE=
SCRIPT=

# cross platforms
# mingw
# msys
# msys2
# cgywin
# wsl
# linux
# referred by http://www.imooc.com/wenda/detail/584860
ifeq ("$(findstring ;,$(PATH))", ";")
DETECTED_OS := Windows
else
DETECTED_OS := $(shell uname 2>/dev/null || echo Unknown)
DETECTED_OS := $(patsubst CYGWIN%,Cygwin,$(DETECTED_OS))
DETECTED_OS := $(patsubst MSYS%,MSYS,$(DETECTED_OS))
# DETECTED_OS := $(patsubst MINGW%,MSYS,$(DETECTED_OS))
endif

ifeq ($(DETECTED_OS), "Windows")
CMAKE_FLAGS= "NMake Makefiles"
else ifeq ($(DETECTED_OS), "CYGWIN")
CMAKE_FLAGS= "Unix Makefiles"
else ifeq ($(DETECTED_OS), "MSYS")
CMAKE_FLAGS= "MSYS Makefiles"
else ifeq ($(DETECTED_OS), "MINGW")
CMAKE_FLAGS= "MinGW Makefiles"
else
CMAKE_FLAGS= "Unix Makefiles"
endif

export MY_OS = $(DETECTED_OS)

# Windows cmd is available or not
ifeq ($(shell echo "windows cmd available"), "windows cmd available")
CMD_AVAI := TRUE
else
CMD_AVAI := FALSE
endif

ifeq ($(CMD_AVAI), TRUE)
export RM = del
export RMFLAGS = /Q /F
export MKDIR = mkdir
export MKDIRFLAGS =
export RMDIR = rd
export RMDIRFLAGS = /Q
export CP = copy
export CPFLAGS = /Y
export SEPARATOR = \\
export SPLIT = &
else
export RM = rm
export RMFLAGS = -f
export MKDIR = mkdir
export MKDIRFLAGS = -p
export RMDIR = rm
export RMDIRFLAGS = -rf
export CP = cp
export CPFLAGS =
export SEPARATOR = /
export SPLIT = ;
endif

$(TOOLS) test:
	$(RM) $(RMFLAGS) compile.* xmake.lua CMakeLists.txt
	$(CP) $(CPFLAGS) .$(SEPARATOR)script$(SEPARATOR)$(SCRIPT) .
	$(COMPILE) $(SCRIPT) $(CMD)
	
.PHONY: all test clean distclean doc help $(TOOLS)

all: CMD=

test: CMD= test

clean: CMD= clean

distclean: CMD= distclean

doc:
	doxygen

help: CMD= help

make: SCRIPT= compile.mk
make: COMPILE= $(MAKE) -f
make: TOOL= make

cmake: SCRIPT= CMakeLists.txt
cmake: COMPILE= $(MKDIR) $(MKDIRFLAGS) build; cd build; $(RM) $(RMFLAGS) *; cmake .. -G $(CMAKE_FLAGS); $(MAKE)
cmake: TOOL= cmake

xmake: SCRIPT= xmake.lua
xmake: COMPILE= xmake -F

sh: SCRIPT= compile.sh
sh: COMPILE= sh

zsh: SCRIPT= compile.zsh
zsh: COMPILE= zsh

fish: SCRIPT= compile.fish
fish: COMPILE= fish

cmd: SCRIPT= compile.bat
cmd: COMPILE= cmd

powershell: SCRIPT= compile.ps1
powershell: COMPILE= powershell

perl: SCRIPT= compile.pl
perl: COMPILE= perl

perl6: SCRIPT= compile.pl6
perl6: COMPILE= perl6

ruby: SCRIPT= compile.rb
ruby: COMPILE= ruby

python: SCRIPT= compile.py
python: COMPILE= python

lua: SCRIPT= compile.lua
lua: COMPILE= lua

r: SCRIPT= compile.r
r: COMPILE= Rscript

julia: SCRIPT= compile.jl
julia: COMPILE= julia

java: SCRIPT= compile.java
java: COMPILE= java --source 11

scala: SCRIPT= compile.scala
scala: COMPILE= scala

kotlin: SCRIPT= compile.kts
kotlin: COMPILE= kotlin

clojure: SCRIPT= compile.clj
clojure: COMPILE= lein-exec

groovy: SCRIPT= compile.groovy
groovy: COMPILE= groovy
