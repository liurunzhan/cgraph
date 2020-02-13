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
export LIBSHARE = $(LIBTARGET).dll

DIR = .
INC = $(DIR)\include
SRC = $(DIR)\src
TST = $(DIR)\test
LIB = $(DIR)\lib
BIN = $(DIR)\bin
PATH_LIBSHARE = $(LIB)\$(LIBSHARE)
PATH_LIBSTATIC = $(LIB)\$(LIBSTATIC)

else
export RM = -rm
export RMFLAGS = -f
export MKDIR = -mkdir -p
export RMDIR = -rm
export RMDIRFLAGS = -rf
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARE = $(LIBTARGET).so

DIR = .
INC = $(DIR)/include
SRC = $(DIR)/src
TST = $(DIR)/test
LIB = $(DIR)/lib
BIN = $(DIR)/bin
PATH_LIBSHARE = $(LIB)/$(LIBSHARE)
PATH_LIBSTATIC = $(LIB)/$(LIBSTATIC)

endif

.PHONY: all test clean distclean

all:
	$(MKDIR) $(LIB)
	$(MKDIR) $(BIN)
	$(MAKE) -C $(SRC)

test:
	$(MAKE) -C $(TST) test

clean:
	$(MAKE) -C $(SRC) clean
	$(MAKE) -C $(TST) clean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARE)

distclean:
	$(MAKE) -C $(SRC) clean
	$(MAKE) -C $(TST) clean
	$(RMDIR) $(RMDIRFLAGS) $(LIB)
	$(RMDIR) $(RMDIRFLAGS) $(BIN)