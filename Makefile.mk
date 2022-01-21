# using subscript Makefile.sub to choose which self-defined script is used to compile library cgraph
# using make -f Makefile.self ? CMD=? TARGET=?

ROOT = .
export TOOLS = make cmake xmake premake meson ninja\
			 sh csh zsh fish ksh vsh cmd powershell \
			 tcc haskell \
	     perl raku ruby python lua r go d julia tcl rust nims zig io lisp typescript \
	     java scala kotlin clojure groovy

MAKE ?= make

.PHONY: all test clean distclean help $(TOOLS) gtkdoc doxygen update branch cloc cloc-all format memchk

all: CMD =

test: CMD = test

clean: CMD = clean

distclean: CMD = distclean

help: CMD= help

gtkdoc: CMD=gtkdoc

doxygen: CMD=doxygen

$(TOOLS):
	$(MAKE) -f Makefile.sub $@ TOOL=$@ CMD=$(CMD)

cloc:
	cloc include src --force-lang=C,ct --force-lang="C/C++ Header",ht --include-ext=c,ct,h,ht

cloc-all:
	cloc include src test tools --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=in,md --not-match-f="Makefile$$"

update:
	git clean -xf
	git pull --quiet

upgrade:
	git fetch --all
	git reset --hard origin/master
	git pull

define push-branch
	@echo push branch master to branch $(1)
	git checkout $(1)
	git rebase master
	-git push --force origin $(1)
	git checkout master
endef

branch:
	$(call push-branch,dist)
	$(call push-branch,julia)
	$(call push-branch,perl)
	$(call push-branch,python)
	$(call push-branch,r)