SOURCES = dy_graph.c st_graph.c

if DEBUG
MODE_FLAGS            = -DDEBUG
else
MODE_FLAGS            = 
endif
FLAGS                 = -I$(top_srcdir)/include -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
noinst_LTLIBRARIES    = libgraph.la
libgraph_la_CFLAGS    = $(FLAGS)
libgraph_la_LDFLAGS   = -lm -no-undefined
libgraph_la_SOURCES   = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps