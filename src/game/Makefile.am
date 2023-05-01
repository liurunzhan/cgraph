SOURCES = sudoku.c cmdarg.c verilog.c

noinst_LTLIBRARIES = libgame.la
libgame_la_CFLAGS  = -I$(top_srcdir)/include $(COMPILE_FLAGS)
libgame_la_LDFLAGS = -lm -no-undefined
libgame_la_SOURCES = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
