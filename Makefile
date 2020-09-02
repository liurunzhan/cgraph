ROOT=.
SCR=$(ROOT)/script
TOOL=make
TOOLS=make cmake xmake sh zsh fish cmd powershell perl perl6 ruby python lua r julia java scala kotlin clojure groovy

$(TOOLS) test clean distclean help:
	@cp $(SCR)/$(SCRIPT) .
	
.PHONY: all $(TOOLS) test clean distclean help

all: $(TOOL)

test:
CMD := test

clean:
CMD := clean

distclean:
CMD := distclean

help:
CMD := help

make: 
SCRIPT := compile.mk
COMPILE :=	make -f

cmake: 
SCRIPT := CMakeLists.txt
COMPILE := cmake

xmake:
SCRIPT := xmake.lua
COMPILE := xmake

sh:
SCRIPT := compile.sh
COMPILE := sh

zsh:
SCRIPT := compile.zsh
COMPILE := zsh

fish:
SCRIPT := compile.fish
COMPILE := fish

cmd:
SCRIPT := compile.bat
COMPILE := cmd

powershell:
SCRIPT := compile.ps1
COMPILE := powershell

perl:
SCRIPT := compile.pl
COMPILE := perl

perl6:
SCRIPT := compile.pl6
COMPILE := perl6

ruby:
SCRIPT := compile.rb
COMPILE := ruby

python:
SCRIPT := compile.py
COMPILE := python

lua:
SCRIPT := compile.lua
COMPILE := lua

r:
SCRIPT := compile.r
COMPILE := Rscript

julia:
SCRIPT := compile.jl
COMPILE := julia

java:
SCRIPT := compile.java
COMPILE := java --source 11

scala:
SCRIPT := compile.scala
COMPILE := scala

kotlin:
SCRIPT := compile.kts
COMPILE := kotlin

clojure:
SCRIPT := compile.clj
COMPILE := lein-exec

groovy:
SCRIPT := compile.groovy
COMPILE := groovy
