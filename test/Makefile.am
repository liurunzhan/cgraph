
DISTCLEANFILES = Makefile.in Makefile

if DEBUG
MODE_FLAGS  = -DDEBUG
else
MODE_FLAGS  = 
endif
FLAGS       = -I$(top_srcdir)/include -Wall $(MODE_FLAGS)

AM_LDFLAGS  = -L$(top_srcdir)/src -lcgraph
AM_CFLAGS   = $(FLAGS)
AM_CPPFLAGS = $(FLAGS)

TESTS = bigint cgraph float32 float64 float128 spamat spamat3d string time vector verilog version

noinst_PROGRAMS = $(TESTS)

bigint_SOURCES    = bigint.c
cgraph_SOURCES    = cgraph.c
float32_SOURCES   = float32.c
float64_SOURCES   = float64.c
float128_SOURCES  = float128.c
spamat_SOURCES    = spamat.c
spamat3d_SOURCES  = spamat3d.c
string_SOURCES    = string.c
time_SOURCES      = time.c
vector_SOURCES    = vector.c 
verilog_SOURCES   = verilog.c
version_SOURCES   = version.c

clean-local:
	-rm -f .deps/*

distclean-local:
	-rm -rf .deps