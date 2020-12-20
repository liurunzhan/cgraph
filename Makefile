ROOT = .
export TOOLS = make cmake xmake\
			 sh zsh fish tsh vsh cmd powershell \
			 tcc go rust haskell zig \
	     perl perl6 ruby python lua r julia lisp typescript \
	     java scala kotlin clojure groovy

MAKE ?= make

.PHONY: all test clean distclean doc cloc help $(TOOLS)

all: CMD =

test: CMD = test

clean: CMD = clean

distclean: CMD = distclean

test: CMD = test

help: CMD= help

doc:
	doxygen -u
	doxygen

cloc:
	cloc include src script --force-lang=C,ct --force-lang="C/C++ Header",ht --exclude-ext=d,o

$(TOOLS):
	$(MAKE) -f Makefile.sub $@ TOOL=$@ CMD=$(CMD)