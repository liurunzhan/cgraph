SUBDIRS = src test doc

PROJECT = cgraph
export PROJECT

# project directories
src_dir     = $(top_srcdir)/src
include_dir = $(top_srcdir)/include
test_dir    = $(top_srcdir)/test
tools_dir   = $(top_srcdir)/tools
doc_dir     = $(top_srcdir)/doc

# install directories
includedir = $(prefix)/include
libdir     = $(prefix)/lib
testdir    = $(prefix)/test
docdir     = $(prefix)/doc

if DEBUG
MODE_FLAGS    =-DDEBUG
else
MODE_FLAGS    =
endif
COMPILE_FLAGS = -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
export COMPILE_FLAGS

pkgconfigdir = @libdir@/pkgconfig
pkgconfig_DATA = $(PROJECT).pc

EXTRA_DIST = autogen.sh $(PROJECT).pc Doxyfile README.md

DISTCLEANFILES = aclocal.m4 ar-lib autoscan.log config.* configure $(PROJECT).pc Doxyfile depcomp gtk-doc.m4 gtk-doc.make install-sh libtool ltmain.sh Makefile.in Makefile missing test-driver

if BUILT_IN_GIT_REPO
BUILT_SOURCES = $(include_dir)/cgraph_template_off.h $(include_dir)/cgraph_template_check.h

$(include_dir)/cgraph_template_off.h: $(include_dir)/cgraph_template_off.h.in $(tools_dir)/template_off.macro
	-python3 $(tools_dir)/macro.py $< -o $@ -t $(tools_dir)/template_off.macro -c "end of cgraph_template_off"

$(include_dir)/cgraph_template_check.h: $(include_dir)/cgraph_template_check.h.in $(tools_dir)/template_check.macro
	-python3 $(tools_dir)/macro.py $< -o $@ -t $(tools_dir)/template_check.macro -c "end of cgraph_template_check"
endif

distclean-local:
	-rm -rf $(top_srcdir)/autom4te.cache

.PHONY: doc doxygen cloc cloc-all update branch

doc:
if ENABLE_GTK_DOC
	$(MAKE) -C $(doc_dir)
else
	$(MAKE) doxygen
endif

doxygen:
	doxygen -u
	doxygen

cloc:
	cloc $(include_dir) $(src_dir) --force-lang=C,ct --force-lang="C/C++ Header",ht --include-ext=c,ct,h,ht

cloc-all: clean
	cloc $(include_dir) $(src_dir) $(test_dir) $(tools_dir) --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=in,md --not-match-f="Makefile$$"

update:
	git clean -xf
	git pull --quiet
	chmod +x $(top_srcdir)/autogen.sh

upgrade:
	git fetch --all
	git reset --hard origin/master
	git pull