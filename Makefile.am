SUBDIRS=src

.PHONY: allclean doc cloc update

allclean: distclean
	-rm -f autoscan.log aclocal.m4 config.* configure install-sh ltmain.sh
	-rm -f $(top_srcdir)/doc/Makefile.in
	-rm -f $(top_srcdir)/src/Makefile.in 
	-rm -f $(top_srcdir)/test/Makefile.in
	-rm -f $(top_srcdir)/Makefile.in
	-rm -f gtk-doc.m4 gtk-doc.make
	-rm -rf $(top_srcdir)/autom4te.cache
	-rm -rf $(top_srcdir)/m4

doc:
	make -C $(top_srcdir)/doc

cloc:
	cloc include src script test --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=d,o,in

update:
	git clean -xf
	git pull --quiet