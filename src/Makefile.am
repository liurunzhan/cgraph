HEADERS_PUBLIC        = ../include/cgraph.h ../include/cgraph_bigint.h ../include/cgraph_bigmat.h ../include/cgraph_bigmat3d.h ../include/cgraph_bignum.h ../include/cgraph_bitset.h ../include/cgraph_bool.h ../include/cgraph_complex.h ../include/cgraph_config.h ../include/cgraph_data.h ../include/cgraph_dframe.h ../include/cgraph_dict.h ../include/cgraph_error.h ../include/cgraph_file.h ../include/cgraph_float128.h ../include/cgraph_float32.h ../include/cgraph_float64.h ../include/cgraph_fraction.h ../include/cgraph_gobject.h ../include/cgraph_graph.h ../include/cgraph_hobject.h ../include/cgraph_int.h ../include/cgraph_int16.h ../include/cgraph_int32.h ../include/cgraph_int64.h ../include/cgraph_int8.h ../include/cgraph_list.h ../include/cgraph_long.h ../include/cgraph_m3object.h ../include/cgraph_math.h ../include/cgraph_matrix.h ../include/cgraph_matrix3d.h ../include/cgraph_memory.h ../include/cgraph_mobject.h ../include/cgraph_object.h ../include/cgraph_platform.h ../include/cgraph_pobject.h ../include/cgraph_queue.h ../include/cgraph_set.h ../include/cgraph_spamat.h ../include/cgraph_spamat3d.h ../include/cgraph_stack.h ../include/cgraph_string.h ../include/cgraph_struct.h ../include/cgraph_time.h ../include/cgraph_tree.h ../include/cgraph_vector.h ../include/cgraph_verilog.h ../include/cgraph_version.h ../include/data_base.ht ../include/float_base.ht ../include/int_base.ht ../include/matrix3d_base.ht ../include/matrix_base.ht ../include/object_base.ht ../include/struct_base.ht ../include/template.h ../include/template_base.ht ../include/template_check.h ../include/template_off.h

SOURCES               = bigint.c bigmat.c bigmat3d.c bignum.c bitset.c bool.c complex.c data.c data_base.ct dframe.c dict.c error.c file.c float32.c float64.c float_base.ct fraction.c gobject.c hobject.c int.c int16.c int32.c int64.c int8.c int_base.ct list.c long.c m3object.c math.c matrix.c matrix3d.c matrix3d_base.ct matrix_base.ct memory.c mobject.c object.c object_base.ct pobject.c spamat.c spamat3d.c string.c struct_base.ct template_base.ct time.c vector.c verilog.c version.c

FLAGS                 = -I$(top_srcdir)/include -I$(top_builddir)/include -Wall
lib_LTLIBRARIES       = libcgraph.la
libcgraph_la_CFLAGS   = $(FLAGS)
libcgraph_la_CXXFLAGS = $(FLAGS)
libcgraph_la_LDFLAGS  = -lm -shared -fPIC
libcgraph_la_SOURCES  = $(SOURCES)

includedir            = $(prefix)/include/cgraph
include_HEADERS       = $(HEADERS_PUBLIC)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f .deps/*

distclean-local:
	-rm -rf .deps
