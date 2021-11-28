# project directories
include_dir   = $(top_srcdir)/include
src_dir       = $(top_srcdir)/src
type_dir      = $(src_dir)/type

SOURCES = bigint.c bignum.c bitset.c string.c

if DEBUG
MODE_FLAGS            = -DDEBUG
else
MODE_FLAGS            =
endif
FLAGS                 = -I$(include_dir) -I$(type_dir) -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
noinst_LTLIBRARIES    = libdata.la
libdata_la_CFLAGS     = $(FLAGS)
libdata_la_LDFLAGS    = -lm -no-undefined
libdata_la_SOURCES    = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps