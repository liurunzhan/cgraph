# project directories
include_dir   = $(top_srcdir)/include
src_dir       = $(top_srcdir)/src
type_dir      = $(src_dir)/type

MATRIX_SOURCES = vector.c matrix.c matrix3d.c bigmat.c bigmat3d.c spamat.c spamat3d.c

STRUCTURE_SOURCES = dframe.c dict.c list.c queue.c tree.c

SOURCES = $(MATRIX_SOURCES) $(STRUCTURE_SOURCES)

noinst_LTLIBRARIES      = libstructure.la
libstructure_la_CFLAGS  = -I$(include_dir) -I$(type_dir) $(COMPILE_FLAGS)
libstructure_la_LDFLAGS = -lm -no-undefined
libstructure_la_SOURCES = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
