ROOT= .
SCR= $(ROOT)/script
TOOLS= make cmake xmake \
			 sh zsh fish cmd powershell \
	     perl perl6 ruby python lua r julia \
	     java scala kotlin clojure groovy

TOOL= make
CMD=
COMPILE= make -f
SCRIPT= compile.mk

$(TOOLS):
	-rm -f compile.* xmake.lua CMakeLists.txt
	-cp $(SCR)/$(SCRIPT) .
	$(COMPILE) $(SCRIPT) $(CMD)
	-rm compile.* xmake.lua CMakeLists.txt
	
.PHONY: all test clean distclean help $(TOOLS)

all: CMD=

test: CMD= test

clean: CMD= clean

distclean: CMD= distclean

help: CMD= help

make: SCRIPT= compile.mk
make: COMPILE=	make -f
make: TOOL= make

cmake: SCRIPT= CMakeLists.txt
cmake: COMPILE= -mkdir build; cd build; rm -f CMakeCache.txt; cmake .. ; make
cmake: TOOL= cmake

xmake: SCRIPT= xmake.lua
xmake: COMPILE= xmake

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
