DIR = .
INC = $(DIR)$(PSEP)..$(PSEP)include
LIB = $(DIR)$(PSEP)..$(PSEP)lib
TOL = $(DIR)$(PSEP)..$(PSEP)tools
FUNC  = func
TYPE  = type
GRAPH = graph
GAME  = game

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(PSEP)lib$(PRO)$(LIBSTATIC_SUFFIX)
LIBSHARED_TARGET = $(LIB)$(PSEP)lib$(PRO)$(LIBSHARED_SUFFIX)

FUNC_DIR        = $(DIR)$(PSEP)$(FUNC)$(PSEP)
TYPE_DIR        = $(DIR)$(PSEP)$(TYPE)$(PSEP)
GRAPH_DIR       = $(DIR)$(PSEP)$(GRAPH)$(PSEP)
GAME_DIR        = $(DIR)$(PSEP)$(GAME)$(PSEP)

LIBSTATIC_FUNC  = lib$(FUNC)$(LIBSTATIC_SUFFIX)
LIBSTATIC_TYPE  = lib$(TYPE)$(LIBSTATIC_SUFFIX)
LIBSTATIC_GRAPH = lib$(GRAPH)$(LIBSTATIC_SUFFIX)
LIBSTATIC_GAME  = lib$(GAME)$(LIBSTATIC_SUFFIX)

LIBSHARED_FUNC  = lib$(FUNC)$(LIBSHARED_SUFFIX)
LIBSHARED_TYPE  = lib$(TYPE)$(LIBSHARED_SUFFIX)
LIBSHARED_GRAPH = lib$(GRAPH)$(LIBSHARED_SUFFIX)
LIBSHARED_GAME  = lib$(GAME)$(LIBSHARED_SUFFIX)

.PHONY: all clean distclean

all: compile $(LIBSHARED_TARGET) $(LIBSTATIC_TARGET)

PREDEPS_FILES = $(INC)$(PSEP)cgraph_template_off.h.in $(TOL)$(PSEP)template_off.macro $(INC)$(PSEP)cgraph_template_check.h.in $(TOL)$(PSEP)template_check.macro $(INC)$(PSEP)cgraph_stdchk.h.in $(TOL)$(PSEP)stdchk.macro $(TOL)$(PSEP)macro.py
PREDEPS_EXIST_FILES = $(wildcard $(PREDEPS_FILES))

$(warning expecting PREDEPS is $(PREDEPS_FILES))
$(warning existing  PREDEPS is $(PREDEPS_EXIST_FILES))

ifeq ($(PREDEPS_FILES), $(PREDEPS_EXIST_FILES))
PREDEPS = $(INC)$(PSEP)cgraph_template_off.h $(INC)$(PSEP)cgraph_template_check.h $(INC)$(PSEP)cgraph_stdchk.h

$(INC)$(PSEP)cgraph_template_off.h: $(INC)$(PSEP)cgraph_template_off.h.in $(TOL)$(PSEP)template_off.macro
	-python3 $(TOL)$(PSEP)macro.py $< -o $@ -t $(TOL)$(PSEP)template_off.macro -c "end of cgraph_template_off"

$(INC)$(PSEP)cgraph_template_check.h: $(INC)$(PSEP)cgraph_template_check.h.in $(TOL)$(PSEP)template_check.macro
	-python3 $(TOL)$(PSEP)macro.py $< -o $@ -t $(TOL)$(PSEP)template_check.macro -c "end of cgraph_template_check"
$(INC)$(PSEP)cgraph_stdchk.h: $(INC)$(PSEP)cgraph_stdchk.h.in $(TOL)$(PSEP)stdchk.macro
	-python3 $(TOL)$(PSEP)macro.py $< -o $@ -t $(TOL)$(PSEP)stdchk.macro -c "" --novar
else
PREDEPS = 
endif

compile: $(PREDEPS)
	$(MAKE) -C $(FUNC) -f Makefile.mk all
	$(MAKE) -C $(TYPE) -f Makefile.mk all
	$(MAKE) -C $(GRAPH) -f Makefile.mk all
	$(MAKE) -C $(GAME) -f Makefile.mk all

$(LIBSHARED_TARGET): $(OBJECT)
	$(CC) $(CSFLAGS) -o $(LIBSHARED_TARGET) $(OBJECT) $(FUNC_DIR)$(LIBSHARED_FUNC) $(TYPE_DIR)$(LIBSHARED_TYPE) $(GRAPH_DIR)$(LIBSHARED_GRAPH) $(GAME_DIR)$(LIBSHARED_GAME)

$(LIBSTATIC_TARGET): $(OBJECT)
	$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) $(OBJECT) $(FUNC_DIR)$(LIBSTATIC_FUNC) $(TYPE_DIR)$(LIBSTATIC_TYPE) $(GRAPH_DIR)$(LIBSTATIC_GRAPH) $(GAME_DIR)$(LIBSTATIC_GAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ -MD -MF $*.d

-include $(DEPEND)

clean:
	$(MAKE) -C $(FUNC) -f Makefile.mk clean
	$(MAKE) -C $(TYPE) -f Makefile.mk clean
	$(MAKE) -C $(GRAPH) -f Makefile.mk clean
	$(MAKE) -C $(GAME) -f Makefile.mk clean
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND) $(LIBSTATIC_TARGET) $(LIBSHARED_TARGET)

distclean:
	$(MAKE) -C $(FUNC) -f Makefile.mk distclean
	$(MAKE) -C $(TYPE) -f Makefile.mk distclean
	$(MAKE) -C $(GRAPH) -f Makefile.mk distclean
	$(MAKE) -C $(GAME) -f Makefile.mk distclean
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND) $(LIBSTATIC_TARGET) $(LIBSHARED_TARGET)
	$(RMDIR) $(RMDIRFLAGS) $(LIB)