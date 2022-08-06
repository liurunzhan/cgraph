# project directories
include_dir   = $(top_srcdir)/include
src_dir       = $(top_srcdir)/src
type_dir      = $(src_dir)/type

OBJECT_SOURCES = gobject.c hobject.c m3object.c mobject.c object.c snode.c

SOURCES = $(OBJECT_SOURCES)

FLAGS                 = -I$(include_dir) -I$(type_dir) $(COMPILE_FLAGS)
noinst_LTLIBRARIES    = libobject.la
libobject_la_CFLAGS   = $(FLAGS)
libobject_la_LDFLAGS  = -lm -no-undefined
libobject_la_SOURCES  = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
