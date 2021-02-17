
DISTCLEANFILES = Makefile.in Makefile

AM_LDFLAGS  = -L$(top_srcdir)/src -lcgraph
AM_CFLAGS   = -I$(top_srcdir)/include
AM_CPPFLAGS = -I$(top_srcdir)/include

TESTS = bigint cgraph 

noinst_PROGRAMS = bigint cgraph
bigint_SOURCES  = bigint.c
cgraph_SOURCES  = cgraph.c

# spamat_SOURCES = spamat.c
# spatmat3d_SOURCES = spatmat3d.c
# string_SOURCES = string.c
# time_SOURCES = time.c
# vector_SOURCES = vector.c 
# verilog_SOURCES = verilog.c
# version_SOURCES = version.c