SUBDIRS=src test doc

# install directories
includedir = $(prefix)/include
libdir     = $(prefix)/lib
testdir    = $(prefix)/test
docdir     = $(prefix)/doc

pkgconfigdir = @libdir@/pkgconfig
pkgconfig_DATA = cgraph.pc

EXTRA_DIST = autogen.sh cgraph.pc Doxyfile README.md

DISTCLEANFILES = aclocal.m4 ar-lib autoscan.log config.* configure cgraph.pc Doxyfile depcomp gtk-doc.m4 gtk-doc.make install-sh libtool ltmain.sh Makefile.in Makefile missing test-driver

distclean-local:
	-rm -rf $(top_srcdir)/autom4te.cache

.PHONY: doc doxygen cloc cloc-all update branch

doc:
if ENABLE_GTK_DOC
	$(MAKE) -C $(top_srcdir)/doc
else
	$(MAKE) doxygen
endif

doxygen:
	doxygen -u
	doxygen

cloc:
	cloc include src/*.c* --force-lang=C,ct --force-lang="C/C++ Header",ht --exclude-ext=in

cloc-all: clean
	cloc include src test tools --force-lang=C,ct --force-lang="C/C++ Header",ht --exclude-ext=in,md --not-match-f="Makefile$$"

update:
	git clean -xf
	git pull --quiet
	chmod +x ./autogen.sh

upgrade:
	git fetch --all
	git reset --hard origin/master
	git pull