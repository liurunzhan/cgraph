
DISTCLEANFILES = Makefile.in Makefile

if DEBUG
MODE_FLAGS  = -DDEBUG
else
MODE_FLAGS  = 
endif
FLAGS       = -I$(top_srcdir)/include -Wall -pedantic -pedantic-errors $(MODE_FLAGS)

AM_LDFLAGS  = -L$(top_srcdir)/src -lcgraph
AM_CFLAGS   = $(FLAGS)
AM_CPPFLAGS = $(FLAGS)

TESTS = bigint bigmat bigmat3d bignum bitset cgraph float8 float16 float32 float64 float128 bool logic int int8 int16 int32 int64 int128 long time matrix matrix3d spamat spamat3d string vector verilog version game

noinst_PROGRAMS = $(TESTS)

bigint_SOURCES    = bigint.c
bigmat_SOURCES    = bigmat.c
bigmat3d_SOURCES  = bigmat3d.c
bignum_SOURCES    = bignum.c
bitset_SOURCES    = bitset.c
cgraph_SOURCES    = cgraph.c
float8_SOURCES    = float8.c
float16_SOURCES   = float16.c
float32_SOURCES   = float32.c
float64_SOURCES   = float64.c
float128_SOURCES  = float128.c
bool_SOURCES      = bool.c
logic_SOURCES     = logic.c
int_SOURCE        = int.c
int8_SOURCE       = int8.c
int16_SOURCE      = int16.c
int32_SOURCE      = int32.c
int64_SOURCE      = int64.c
int128_SOURCE     = int128.c
long_SOURCE       = long.c
matrix_SOURCES    = matrix.c
matrix3d_SOURCES  = matrix3d.c
spamat_SOURCES    = spamat.c
spamat3d_SOURCES  = spamat3d.c
string_SOURCES    = string.c
time_SOURCES      = time.c
vector_SOURCES    = vector.c 
verilog_SOURCES   = verilog.c
version_SOURCES   = version.c
game_SOURCES      = game.c

clean-local:
	-rm -f .deps/*

distclean-local:
	-rm -rf .deps

@VALGRIND_CHECK_RULES@
VALGRIND_SUPPRESSIONS_FILES = my-project.supp
EXTRA_DIST = my-project.supp
