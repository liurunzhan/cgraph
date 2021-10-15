HEADERS_PUBLIC = ../include/cgraph.h ../include/cgraph_base.h ../include/cgraph_bigint.h ../include/cgraph_bigmat.h ../include/cgraph_bigmat3d.h ../include/cgraph_bignum.h ../include/cgraph_bitset.h ../include/cgraph_bool.h ../include/cgraph_cmdarg.h ../include/cgraph_complex.h ../include/cgraph_config.h ../include/cgraph_data.h ../include/cgraph_dframe.h ../include/cgraph_dict.h ../include/cgraph_error.h ../include/cgraph_file.h ../include/cgraph_float128.h ../include/cgraph_float16.h ../include/cgraph_float32.h ../include/cgraph_float64.h ../include/cgraph_float8.h ../include/cgraph_fraction.h ../include/cgraph_gobject.h ../include/cgraph_graph.h ../include/cgraph_hobject.h ../include/cgraph_int.h ../include/cgraph_int128.h ../include/cgraph_int16.h ../include/cgraph_int32.h ../include/cgraph_int64.h ../include/cgraph_int8.h ../include/cgraph_list.h ../include/cgraph_logic.h ../include/cgraph_long.h ../include/cgraph_m3object.h ../include/cgraph_math.h ../include/cgraph_matrix.h ../include/cgraph_matrix3d.h ../include/cgraph_memory.h ../include/cgraph_mobject.h ../include/cgraph_object.h ../include/cgraph_object_base.h ../include/cgraph_platform.h ../include/cgraph_queue.h ../include/cgraph_set.h ../include/cgraph_snode.h ../include/cgraph_spamat.h ../include/cgraph_spamat3d.h ../include/cgraph_stack.h ../include/cgraph_stdchk.h ../include/cgraph_stdchk.h.in ../include/cgraph_stdint.h ../include/cgraph_string.h ../include/cgraph_struct.h ../include/cgraph_template.h ../include/cgraph_template.ht ../include/cgraph_template_cbuffer.ht ../include/cgraph_template_check.h ../include/cgraph_template_data.ht ../include/cgraph_template_float.ht ../include/cgraph_template_float_soft.ht ../include/cgraph_template_int.ht ../include/cgraph_template_int_soft.ht ../include/cgraph_template_matrix.ht ../include/cgraph_template_matrix3d.ht ../include/cgraph_template_object.ht ../include/cgraph_template_off.h ../include/cgraph_template_struct.ht ../include/cgraph_time.h ../include/cgraph_tree.h ../include/cgraph_vector.h ../include/cgraph_verilog.h ../include/cgraph_version.h

BASE_SOURCES = template_base.ct

DATA_BASE_SOURCES = template_data.ct template_cbuffer.ct

INT_BASE_SOURCES = template_int.ct template_int_soft.ct

INT_SOURCES = $(INT_BASE_SOURCES) bool.c logic.c int.c long.c int8.c int16.c int32.c int64.c int128.c bigint.c bitset.c time.c

FLOAT_BASE_SOURCES = template_float.ct template_float_soft.ct

FLOAT_SOURCES = $(FLOAT_BASE_SOURCES) float8.c float16.c float32.c float64.c float128.c bignum.c complex.c fraction.c

STRING_SOURCES = string.c

DATA_SOURCES = $(DATA_BASE_SOURCES) $(INT_SOURCES) $(FLOAT_SOURCES) $(STRING_SOURCES) data.c

OBJECT_BASE_SOURCES = template_object.ct

OBJECT_SOURCES = $(OBJECT_BASE_SOURCES) gobject.c hobject.c m3object.c mobject.c object.c snode.c

STRUCTURE_BASE_SOURCES = template_struct.ct

MATRIX_BASE_SOURCES = template_matrix.ct template_matrix3d.ct

MATRIX_SOURCES = $(MATRIX_BASE_SOURCES) vector.c matrix.c matrix3d.c bigmat.c bigmat3d.c spamat.c spamat3d.c

STRUCTURE_SOURCES = $(STRUCTURE_BASE_SOURCES) $(MATRIX_SOURCES) dframe.c dict.c list.c queue.c tree.c

ALGORITHM_SOURCES = cmdarg.c error.c file.c math.c memory.c verilog.c version.c

SOURCES = $(BASE_SOURCES) $(DATA_SOURCES) $(OBJECT_SOURCES) $(STRUCTURE_SOURCES) $(ALGORITHM_SOURCES)

if DEBUG
MODE_FLAGS            = -DDEBUG
else
MODE_FLAGS            = 
endif
FLAGS                 = -I$(top_srcdir)/include -Wall -pedantic -pedantic-errors $(MODE_FLAGS)
lib_LTLIBRARIES       = libcgraph.la
libcgraph_la_CFLAGS   = $(FLAGS)
libcgraph_la_CXXFLAGS = $(FLAGS)
libcgraph_la_LDFLAGS  = -lm -no-undefined
libcgraph_la_SOURCES  = $(SOURCES)

includedir            = $(prefix)/include/cgraph
include_HEADERS       = $(HEADERS_PUBLIC)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
