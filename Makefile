PLATFORM = windows

export CC = cc
export CFLAGS = -ansi -pedantic -pedantic-errors -Wall
export MAKE = make
export AR = ar
export ARFLAG = -r

ifeq ($(PLATFORM), windows)
export RM = del
export RMFLAGS = /S /Q /F
export MKDIR = mkdir
export RMDIR = rd
export RMDIRFLAGS = /S /Q
else
export RM = rm
export RMFLAGS = -f
export MKDIR = mkdir
export RMDIR = rm
export RMDIRFLAGS = -rf
endif

export TARGET = cgraph

ROOT = .
INC = $(ROOT)/include
SRC = $(ROOT)/src
TST = $(ROOT)/test
LIB = $(ROOT)/lib
BIN = $(ROOT)/bin
DIR = $(ROOT)

.PHONY: all test clean distclean

all:
	-$(MKDIR) lib
	-$(MKDIR) bin
	@echo *** START the compilation of cgraph ***
	$(MAKE) -C $(SRC)
	@echo *** END the compilation of cgraph ***

test:$(TARGET)
	@echo *** START the test of cgraph ***
	$(MAKE) -C $(TST) test
	@echo *** END the test of cgraph ***

clean:
	@echo *** START the cleaning of cgraph ***
	$(MAKE) -C $(SRC) clean
	@echo *** END the cleaning of cgraph ***

distclean:
	@echo *** START all cleaning of cgraph ***
	$(MAKE) -C $(SRC) distclean
	-$(RMDIR) $(RMDIRFLAG) lib
	-$(RMDIR) $(RMDIRFLAG) bin
	@echo *** END all cleaning of cgraph ***