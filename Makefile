ROOT= .
SCR= $(ROOT)/script
TOOLS= make cmake xmake\
			 sh zsh fish tsh vsh cmd powershell \
			 tcc go rust haskell zig \
	     perl perl6 ruby python lua r julia lisp typescript \
	     java scala kotlin clojure groovy

MAKE= make

.PHONY: all test clean distclean doc cloc help $(TOOLS)

all: CMD=

test: CMD= test

clean: CMD= clean
clean: all

distclean: CMD= distclean

doc:
	doxygen

cloc:
	cloc include src test script

help: CMD= help

make:
	$(MAKE) -f Makefile.sub make TOOL=make CMD=$(CMD)