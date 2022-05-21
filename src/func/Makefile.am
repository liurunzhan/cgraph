SOURCES = error.c file.c memory.c math.c rand.c

noinst_LTLIBRARIES    = libfunc.la
libfunc_la_CFLAGS     = -I$(top_srcdir)/include $(COMPILE_FLAGS)
libfunc_la_LDFLAGS    = -lm -no-undefined
libfunc_la_SOURCES    = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
