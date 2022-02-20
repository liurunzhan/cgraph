SUBDIRS = func type graph game

# project directories
include_dir = $(top_srcdir)/include
src_dir     = $(top_srcdir)/src

# dependence
libfunc_la  = $(src_dir)/func/libfunc.la
libtype_la  = $(src_dir)/type/libtype.la
libgraph_la = $(src_dir)/graph/libgraph.la
libgame_la  = $(src_dir)/game/libgame.la

SOURCES = version.c

lib_LTLIBRARIES       = libcgraph.la
libcgraph_la_CFLAGS   = -I$(include_dir) $(COMPILE_FLAGS)
libcgraph_la_LDFLAGS  = -lm -no-undefined
libcgraph_la_SOURCES  = $(SOURCES)
libcgraph_la_LIBADD   = $(libfunc_la) $(libtype_la) $(libgraph_la) $(libgame_la)

HEADERS_PUBLIC = $(include_dir)/cgraph.h $(include_dir)/cgraph_base.h $(include_dir)/cgraph_bigint.h $(include_dir)/cgraph_bigmat.h $(include_dir)/cgraph_bigmat3d.h $(include_dir)/cgraph_bignum.h $(include_dir)/cgraph_bitset.h $(include_dir)/cgraph_bool.h $(include_dir)/cgraph_cmdarg.h $(include_dir)/cgraph_complex.h $(include_dir)/cgraph_config.h $(include_dir)/cgraph_data.h $(include_dir)/cgraph_dframe.h $(include_dir)/cgraph_dict.h $(include_dir)/cgraph_error.h $(include_dir)/cgraph_file.h $(include_dir)/cgraph_float128.h $(include_dir)/cgraph_float16.h $(include_dir)/cgraph_float32.h $(include_dir)/cgraph_float64.h $(include_dir)/cgraph_float8.h $(include_dir)/cgraph_fraction.h $(include_dir)/cgraph_game.h $(include_dir)/cgraph_gobject.h $(include_dir)/cgraph_graph.h $(include_dir)/cgraph_hobject.h $(include_dir)/cgraph_int.h $(include_dir)/cgraph_int128.h $(include_dir)/cgraph_int16.h $(include_dir)/cgraph_int32.h $(include_dir)/cgraph_int64.h $(include_dir)/cgraph_int8.h $(include_dir)/cgraph_list.h $(include_dir)/cgraph_logic.h $(include_dir)/cgraph_long.h $(include_dir)/cgraph_m3object.h $(include_dir)/cgraph_math.h $(include_dir)/cgraph_matrix.h $(include_dir)/cgraph_matrix3d.h $(include_dir)/cgraph_memory.h $(include_dir)/cgraph_mobject.h $(include_dir)/cgraph_object.h $(include_dir)/cgraph_object_base.h $(include_dir)/cgraph_platform.h $(include_dir)/cgraph_queue.h $(include_dir)/cgraph_set.h $(include_dir)/cgraph_snode.h $(include_dir)/cgraph_spamat.h $(include_dir)/cgraph_spamat3d.h $(include_dir)/cgraph_stack.h $(include_dir)/cgraph_stdchk.h $(include_dir)/cgraph_stdchk.h.in $(include_dir)/cgraph_stdint.h $(include_dir)/cgraph_string.h $(include_dir)/cgraph_struct.h $(include_dir)/cgraph_template.h $(include_dir)/cgraph_template.ht $(include_dir)/cgraph_template_cbuf.ht $(include_dir)/cgraph_template_check.h $(include_dir)/cgraph_template_data.ht $(include_dir)/cgraph_template_float.ht $(include_dir)/cgraph_template_float_soft.ht $(include_dir)/cgraph_template_int.ht $(include_dir)/cgraph_template_int_soft.ht $(include_dir)/cgraph_template_matrix.ht $(include_dir)/cgraph_template_matrix3d.ht $(include_dir)/cgraph_template_object.ht $(include_dir)/cgraph_template_off.h $(include_dir)/cgraph_template_struct.ht $(include_dir)/cgraph_time.h $(include_dir)/cgraph_tree.h $(include_dir)/cgraph_vector.h $(include_dir)/cgraph_verilog.h $(include_dir)/cgraph_version.h

include_HEADERS       = $(HEADERS_PUBLIC)

DISTCLEANFILES        = Makefile.in Makefile

clean-local:
	-rm -f *.d *.o
	-rm -f .deps/*

distclean-local:
	-rm -f *.d *.o
	-rm -rf .deps
