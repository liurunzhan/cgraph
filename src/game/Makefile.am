SOURCES = sudoku.c cmdarg.c verilog.c

if DEBUG
MODE_FLAGS            = -DDEBUG
else
MODE_FLAGS            = 
endif
FLAGS                 = -I$(top_srcdir)/include -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
noinst_LTLIBRARIES    = libgame.la
libgame_la_CFLAGS     = $(FLAGS)
libgame_la_LDFLAGS    = -lm -no-undefined
libgame_la_SOURCES    = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
