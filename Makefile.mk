# using subscript Makefile.sub to choose which self-defined script is used to compile library cgraph
# using make -f Makefile.self ? CMD=? TARGET=?

ROOT = .
export TOOLS = make cmake xmake\
			 sh zsh fish tsh vsh cmd powershell \
			 tcc go rust haskell zig \
	     perl perl6 ruby python lua r julia lisp typescript \
	     java scala kotlin clojure groovy

MAKE ?= make

.PHONY: all test clean distclean gtkdoc doxygen update cloc help $(TOOLS) memchk

all: CMD =

test: CMD = test

clean: CMD = clean

distclean: CMD = distclean

gtkdoc: CMD=gtkdoc

doxygen: CMD=doxygen

help: CMD= help

update:
	git clean -xf
	git pull --quiet

cloc:
	cloc include src script test --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=d,o,in

$(TOOLS):
	$(MAKE) -f Makefile.sub $@ TOOL=$@ CMD=$(CMD)