# project directories
include_dir   = $(top_srcdir)/include
src_dir       = $(top_srcdir)/src
type_dir      = $(src_dir)/type

INT_SOURCES = bool.c logic.c int.c long.c int8.c int16.c int32.c int64.c int128.c

FLOAT_SOURCES = float8.c float16.c float32.c float64.c float128.c fraction.c

COMPLEX_SOURCES = complex.c

TIME_SOURCES = time.c

POINT_SOURCES = point2d.c point3d.c

SOURCES = $(INT_SOURCES) $(FLOAT_SOURCES) $(COMPLEX_SOURCES) $(TIME_SOURCES) $(POINT_SOURCES)

noinst_LTLIBRARIES    = libbasic.la
libbasic_la_CFLAGS    = -I$(include_dir) -I$(type_dir) $(COMPILE_FLAGS)
libbasic_la_LDFLAGS   = -lm -no-undefined
libbasic_la_SOURCES   = $(SOURCES)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps