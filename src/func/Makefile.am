SOURCES = error.c file.c memory.c math.c

if DEBUG
MODE_FLAGS            = -DDEBUG
else
MODE_FLAGS            =
endif
FLAGS                 = -I$(top_srcdir)/include -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
noinst_LTLIBRARIES    = libfunc.la
libfunc_la_CFLAGS     = $(FLAGS)
libfunc_la_LDFLAGS    = -lm -no-undefined
libfunc_la_SOURCES    = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
