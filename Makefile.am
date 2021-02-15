SUBDIRS=src test doc

EXTRA_DIST = autogen.sh Doxyfile.base README.md

DISTCLEANFILES = autoscan.log aclocal.m4 config.* configure install-sh libtool ltmain.sh gtk-doc.m4 gtk-doc.make Makefile.in Makefile

distclean-local:
	-rm -rf $(top_srcdir)/autom4te.cache
	-rm -rf $(top_srcdir)/m4
	-rm -rf $(top_srcdir)/po

.PHONY: gtkdoc doxygen cloc update branch

gtkdoc:
	$(MAKE) -C $(top_srcdir)/doc

doxygen:
	-cp -f Doxyfile.base Doxyfile
	doxygen -u
	doxygen

cloc:
	cloc include src script test --force-lang=C,ct --force-lang="C/C++ Header",ht --force-lang=make,mk --exclude-ext=d,o,in

update:
	git clean -xf
	git pull --quiet

define push-branch
	@echo push branch master to branch $(1)
	-git checkout $(1)
	-git rebase master
	-git push --force origin $(1)
endef

branch:
	$(call push-branch, dist)
	$(call push-branch, julia)
	$(call push-branch, perl)
	$(call call push-branch, python)
	$(call push-branch, r)