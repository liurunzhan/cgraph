export CC = cc
export CFLAGS = -ansi -pedantic -pedantic-errors -Wall
export MAKE = make
export AR = ar
export ARFLAGS = -rcs
export CSFLAGS = -shared
export TARGET = cgraph
export LIBTARGET = lib$(TARGET)

ifeq ($(OS), Windows_NT)
export RM = -del
export RMFLAGS = /S /Q /F
export MKDIR = -mkdir
export RMDIR = -rd
export RMDIRFLAGS = /S /Q
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARED = $(LIBTARGET).dll

DIR = .
INC = $(DIR)\include
SRC = $(DIR)\src
TST = $(DIR)\test
LIB = $(DIR)\lib
PATH_LIBSHARED = $(LIB)\$(LIBSHARED)
PATH_LIBSTATIC = $(LIB)\$(LIBSTATIC)

else
export RM = -rm
export RMFLAGS = -f
export MKDIR = -mkdir -p
export RMDIR = -rm
export RMDIRFLAGS = -rf
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARED = $(LIBTARGET).so

DIR = .
INC = $(DIR)/include
SRC = $(DIR)/src
TST = $(DIR)/test
LIB = $(DIR)/lib
PATH_LIBSHARED = $(LIB)/$(LIBSHARED)
PATH_LIBSTATIC = $(LIB)/$(LIBSTATIC)

endif

.PHONY: all test clean distclean help

all:
	$(MKDIR) $(LIB)
	$(MAKE) -C $(SRC)
	$(MAKE) -C $(TST)

test:
	$(MAKE) -C $(TST) test

clean:
	$(MAKE) -C $(SRC) clean
	$(MAKE) -C $(TST) clean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARED)

distclean:
	$(MAKE) -C $(SRC) distclean
	$(MAKE) -C $(TST) distclean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARED)
	$(RMDIR) $(RMDIRFLAGS) $(LIB)

help:
	@echo "$(MAKE) <target>"
	@echo "<target>: "
	@echo "                    build cgraph"
	@echo "          test      test cgraph"
	@echo "          clean     clean all the generated files"
	@echo "          distclean clean all the generated files and directories"
	@echo "          help      commands to this program"