SOURCES = dy_graph.c st_graph.c

noinst_LTLIBRARIES    = libgraph.la
libgraph_la_CFLAGS    = -I$(top_srcdir)/include $(COMPILE_FLAGS)
libgraph_la_LDFLAGS   = -lm -no-undefined
libgraph_la_SOURCES   = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps