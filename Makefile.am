SUBDIRS=src

.PHONY: allclean doc cloc

allclean: distclean
	-rm -f autoscan.log aclocal.m4 config.* configure install-sh ltmain.sh $(top_srcdir)/doc/Makefile.in $(top_srcdir)/src/Makefile.in $(top_srcdir)/test/Makefile.in $(top_srcdir)/Makefile.in
	-rm -rf $(top_srcdir)/autom4teautom4te.cache

doc:
	doxygen -u
	doxygen

cloc:
	cloc include src script --force-lang=C,ct --force-lang="C/C++ Header",ht --exclude-ext=d,o