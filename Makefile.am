SUBDIRS = src tests doc

PROJECT = cgraph
export PROJECT

# project directories
src_dir     = $(top_srcdir)/src
include_dir = $(top_srcdir)/include
tests_dir   = $(top_srcdir)/tests
tools_dir   = $(top_srcdir)/tools
doc_dir     = $(top_srcdir)/doc

# install directories
includedir = $(prefix)/include
libdir     = $(prefix)/lib
testsdir   = $(prefix)/tests
docdir     = $(prefix)/doc

if ENABLE_DEBUG
COMPILE_FLAGS = -DDEBUG -g
else
COMPILE_FLAGS =
endif
COMPILE_FLAGS += $(STDC) -Wall -pedantic -pedantic-errors
export COMPILE_FLAGS

pkgconfigdir = @libdir@/pkgconfig
pkgconfig_DATA = $(PROJECT).pc

EXTRA_DIST = autogen.sh $(PROJECT).pc Doxyfile README.md

DISTCLEANFILES = aclocal.m4 ar-lib autoscan.log config.* configure $(PROJECT).pc Doxyfile depcomp gtk-doc.m4 gtk-doc.make install-sh libtool ltmain.sh Makefile.in Makefile missing test-driver

if BUILD_IN_GIT_REPO
BUILT_SOURCES = $(include_dir)/cgraph_template_off.h $(include_dir)/cgraph_template_check.h $(include_dir)/cgraph_stdchk.h $(src_dir)/version.c

$(include_dir)/cgraph_template_off.h: $(include_dir)/cgraph_template_off.h.in $(tools_dir)/template_off.macro
	-python3 $(tools_dir)/macro.py $< -o $@ -t $(tools_dir)/template_off.macro -c "end of cgraph_template_off" --nodoc

$(include_dir)/cgraph_template_check.h: $(include_dir)/cgraph_template_check.h.in $(tools_dir)/template_check.macro
	-python3 $(tools_dir)/macro.py $< -o $@ -t $(tools_dir)/template_check.macro -c "end of cgraph_template_check" --nodoc

$(include_dir)/cgraph_stdchk.h: $(include_dir)/cgraph_stdchk.h.in $(tools_dir)/stdchk.macro
	-python3 $(tools_dir)/macro.py $< -o $@ -t $(tools_dir)/stdchk.macro -c "" --nodoc

$(src_dir)/version.c: $(include_dir)/cgraph_config.h
	-python3 $(tools_dir)/enum2array.py $< -e cgraph_type_t -s $@ -a __cgraph_types__ -o $@
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
	cloc $(include_dir) $(src_dir) $(tests_dir) $(tools_dir) --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=in,md --not-match-f="Makefile$$"

update:
if BUILD_IN_GIT_REPO
	echo update source files to a latest version with a git repo
	git clean -xf
	git pull --quiet
else
	echo update nothing without a git repo
endif
	chmod +x $(top_srcdir)/autogen.sh

upgrade:
if BUILD_IN_GIT_REPO
	echo update source files to a latest version with a git repo
	git fetch --all
	git reset --hard origin/master
	git pull
else
	echo update nothing without a git repo
endif
