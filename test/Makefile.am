
DISTCLEANFILES = Makefile.in Makefile

AM_LDFLAGS  = -L$(top_srcdir)/src -lcgraph
AM_CFLAGS   = -I$(top_srcdir)/include
AM_CPPFLAGS = -I$(top_srcdir)/include

TESTS = bigint cgraph float32 float64 spamat spatmat3d string time vector verilog version

noinst_PROGRAMS = $(TESTS)

bigint_SOURCES    = bigint.c
cgraph_SOURCES    = cgraph.c
float32_SOURCES   = float32.c
float64_SOURCES   = float64.c
spamat_SOURCES    = spamat.c
spatmat3d_SOURCES = spatmat3d.c
string_SOURCES    = string.c
time_SOURCES      = time.c
vector_SOURCES    = vector.c 
verilog_SOURCES   = verilog.c
version_SOURCES   = version.c

clean-local:
	-rm -f .deps/*

distclean-local:
	-rm -rf .deps