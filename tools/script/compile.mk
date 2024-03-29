# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src
# designed to cross the platforms of windows and linux.

export PRO = cgraph

export CC = cc
export CFLAGS = -std=c89 -Wall -pedantic -fPIC
export MAKE ?= make
export AR = ar
export ARFLAGS = -rcs
export CSFLAGS = -shared
export TARGET = $(PRO)
export LIBTARGET = lib$(TARGET)
export MODE = debug

ifneq ($(CC), tcc)
CFLAGS += -pedantic-errors
endif

ifeq ($(MODE), debug)
CFLAGS += -g -DDEBUG -O0
else ifeq ($(MODE), release)
CFLAGS += -O2
endif

# cross platforms
# mingw
# msys
# msys2
# cygwin
# wsl
# linux
# referred by http://www.imooc.com/wenda/detail/584860
ifeq ("$(findstring ;,$(PATH))", ";")
OS := Windows
else
OS := $(shell uname 2>/dev/null || echo Unknown)
OS := $(patsubst CYGWIN%,Cygwin,$(OS))
OS := $(patsubst MSYS%,MSYS,$(OS))
OS := $(patsubst MINGW%,MSYS,$(OS))
endif

export MY_OS = $(OS)

ifneq ($(CC)_$(OS), clang_Windows)
CFLAGS += -fPIC
endif

# Windows cmd is available or not
ifeq ($(shell echo "windows cmd available"), "windows cmd available")
CMD_AVAI := TRUE
else
CMD_AVAI := FALSE
endif

ifeq ($(CMD_AVAI), TRUE)
export RM = -del
export RMFLAGS = /Q /F
export MKDIR = -mkdir
export MKDIRFLAGS =
export RMDIR = -rd
export RMDIRFLAGS = /Q
export CP = -copy
export CPFLAGS = /Y
export LIBSTATIC_SUFFIX = .lib
export LIBSHARED_SUFFIX = .dll
export PSEP = \\
export SPLIT = &
else
export RM = -rm
export RMFLAGS = -f
export MKDIR = -mkdir
export MKDIRFLAGS = -p
export RMDIR = -rm
export RMDIRFLAGS = -rf
export CP = -cp
export CPFLAGS =
export LIBSTATIC_SUFFIX = .a
export LIBSHARED_SUFFIX = .so
export PSEP = /
export SPLIT = ;
endif

DIR = .
INC = $(DIR)$(PSEP)include
SRC = $(DIR)$(PSEP)src
TST = $(DIR)$(PSEP)tests
TOL = $(DIR)$(PSEP)tool
LIB = $(DIR)$(PSEP)lib
DOC = $(DIR)$(PSEP)doc

.PHONY: all test memchk gtkdoc doxygen format clean distclean update help

all:
	@echo "compile cgraph in Platform $(MY_OS)"
	$(MKDIR) $(MKDIRFLAGS) $(LIB)
	$(MAKE) -C $(SRC) -f Makefile.mk all
	$(MAKE) -C $(TST) -f Makefile.mk all

test:
	@echo "test cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(TST) -f Makefile.mk test

memchk:
	@echo "do memory check by valgrind"
	$(MAKE) -C $(TST) -f Makefile.mk memchk

gtkdoc:
	@echo "generate documentation of cgraph in Platform $(MY_OS) with gtk-doc"
	$(MAKE) -C $(DOC) -f Makefile.mk doc

doxygen:
ifneq (Doxyfile, $(wildcard Doxyfile))
	$(CP) $(CPFLAGS) Doxyfile.base Doxyfile
endif
	doxygen -u
	doxygen

format:
	astyle --style=kr $(INC)$(PSEP)*.h $(INC)$(PSEP)*.ht $(SRC)$(PSEP)*.c $(SRC)$(PSEP)*.ct $(TST)$(PSEP)*.c

clean:
	@echo "clean cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(SRC) -f Makefile.mk clean
	$(MAKE) -C $(TST) -f Makefile.mk clean
	$(MAKE) -C $(DOC) -f Makefile.mk clean

distclean:
	@echo "distclean cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(SRC) -f Makefile.mk distclean
	$(MAKE) -C $(TST) -f Makefile.mk distclean
	$(MAKE) -C $(DOC) -f Makefile.mk distclean
	$(RMDIR) $(RMDIRFLAGS) $(LIB)

update:
	git clean -xf
	git pull --quiet

help:
	@echo "build cgraph in Platform $(MY_OS)"
	@echo "$(MAKE) <target>"
	@echo "<target>: "
	@echo "                    build cgraph"
	@echo "          test      test cgraph"
	@echo "          clean     clean all the generated files"
	@echo "          distclean clean all the generated files and directories"
	@echo "          help      commands to this program"
