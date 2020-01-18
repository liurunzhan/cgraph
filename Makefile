PLATFORM = $(OS)

export CC = cc
export CFLAGS = -ansi -pedantic -pedantic-errors -Wall
export MAKE = make
export AR = ar
export ARFLAGS = -cr
export CSFLAGS = -shared -fPIC
export TARGET = cgraph
export LIBTARGET = lib$(TARGET)

ifeq ($(PLATFORM), Windows_NT)
export RM = -del
export RMFLAGS = /S /Q /F
export MKDIR = -mkdir
export RMDIR = -rd
export RMDIRFLAGS = /S /Q
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARE = $(LIBTARGET).dll
else
export RM = -rm
export RMFLAGS = -f
export MKDIR = -mkdir
export RMDIR = -rm
export RMDIRFLAGS = -rf
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARE = $(LIBTARGET).so
endif

ROOT = .
INC = $(ROOT)/include
SRC = $(ROOT)/src
TST = $(ROOT)/test
LIB = $(ROOT)/lib
BIN = $(ROOT)/bin
DIR = $(ROOT)

.PHONY: all test clean distclean

all:
	@$(MKDIR) $(LIB)
	@$(MKDIR) $(BIN)
	@echo *** START the compilation of cgraph ***
	@$(MAKE) -C $(SRC)
	@echo *** END the compilation of cgraph ***

test:$(TARGET)
	@echo *** START the test of cgraph ***
	@$(MAKE) -C $(TST) test
	@echo *** END the test of cgraph ***

clean:
	@echo *** START the cleaning of cgraph ***
	@$(MAKE) -C $(SRC) clean
	@$(RM) $(RMFLAGS) $(LIB)/$(LIBSTATIC)
	@$(RM) $(RMFLAGS) $(LIB)/$(LIBSHARE)
	@echo *** END the cleaning of cgraph ***


distclean:
	@echo *** START all cleaning of cgraph ***
	@$(MAKE) -C $(SRC) distclean
	@$(RMDIR) $(RMDIRFLAGS) $(LIB)
	@$(RMDIR) $(RMDIRFLAGS) $(BIN)
	@echo *** END all cleaning of cgraph ***