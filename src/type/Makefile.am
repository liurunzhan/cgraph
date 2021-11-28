SUBDIRS = basic data object structure

# project directories
include_dir   = $(top_srcdir)/include
src_dir       = $(top_srcdir)/src
type_dir      = $(src_dir)/type
basic_dir     = $(type_dir)/basic
data_dir      = $(type_dir)/data
object_dir    = $(type_dir)/object
structure_dir = $(type_dir)/structure

# dependence
libbasic_la     = $(basic_dir)/libbasic.la
libdata_la      = $(data_dir)/libdata.la
libobject_la    = $(object_dir)/libobject.la
libstructure_la = $(structure_dir)/libstructure.la

BASE_SOURCES = template_base.ct

DATA_BASE_SOURCES = template_data.ct template_cbuf.ct

INT_BASE_SOURCES = template_int.ct cgraph_template_int_soft.ct

FLOAT_BASE_SOURCES = template_float.ct template_float_soft.ct

OBJECT_BASE_SOURCES = template_object.ct

STRUCTURE_BASE_SOURCES = template_struct.ct

MATRIX_BASE_SOURCES = template_matrix.ct template_matrix3d.ct

SOURCES = $(BASE_SOURCES) $(DATA_BASE_SOURCES) $(INT_BASE_SOURCES) $(FLOAT_BASE_SOURCES) $(OBJECT_BASE_SOURCES) $(STRUCTURE_BASE_SOURCES) $(MATRIX_BASE_SOURCES) data.c

if DEBUG
MODE_FLAGS            = -DDEBUG
else
MODE_FLAGS            =
endif
FLAGS                 = -I$(include_dir) -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
noinst_LTLIBRARIES    = libtype.la
libtype_la_CFLAGS     = $(FLAGS)
libtype_la_LDFLAGS    = -lm -no-undefined
libtype_la_SOURCES    = $(SOURCES)
libtype_la_LIBADD     = $(libbasic_la) $(libdata_la) $(libobject_la) $(libstructure_la)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps