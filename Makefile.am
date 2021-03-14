SUBDIRS=src test doc

# install directories
includedir = $(prefix)/include
libdir     = $(prefix)/lib
testdir    = $(prefix)/test

pkgconfigdir = @libdir@/pkgconfig
pkgconfig_DATA = cgraph.pc

EXTRA_DIST = autogen.sh cgraph.pc Doxyfile.base README.md

DISTCLEANFILES = autoscan.log aclocal.m4 config.* configure install-sh libtool ltmain.sh gtk-doc.m4 gtk-doc.make Makefile.in Makefile Doxyfile

distclean-local:
	-rm -rf $(top_srcdir)/autom4te.cache

.PHONY: gtkdoc doxygen cloc update branch

gtkdoc:
	$(MAKE) -C $(top_srcdir)/doc

doxygen:
	-cp -f Doxyfile.base Doxyfile
	doxygen -u
	doxygen

cloc:
	cloc include src script test --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=d,o,Po,in,md --not-match-f="/Makefile$$/"

update:
	git clean -xf
	git pull --quiet