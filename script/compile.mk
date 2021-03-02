# a simple Makefile to compile cgraph and generate static and shared library, 
# which crosses the platforms of windows and linux.

export CC = cc
export CFLAGS = -std=c89 -Wall -pedantic
export MAKE ?= make
export AR = ar
export ARFLAGS = -rcs
export CSFLAGS = -shared
export TARGET = cgraph
export LIBTARGET = lib$(TARGET)
export MODE = debug

ifneq ($(CC), tcc)
CFLAGS += -pedantic-errors
endif

ifeq ($(MODE), debug)
CFLAGS += -g -DDEBUG
else ifeq ($(MODE), release)
CFLAGS += -static -O2
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
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARED = $(LIBTARGET).dll
export SEPARATOR = \\
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
export LIBSTATIC = $(LIBTARGET).a
export LIBSHARED = $(LIBTARGET).so
export SEPARATOR = /
export SPLIT = ;
endif

DIR = .
INC = $(DIR)$(SEPARATOR)include
SRC = $(DIR)$(SEPARATOR)src
TST = $(DIR)$(SEPARATOR)test
LIB = $(DIR)$(SEPARATOR)lib
PATH_LIBSHARED = $(LIB)$(SEPARATOR)$(LIBSHARED)
PATH_LIBSTATIC = $(LIB)$(SEPARATOR)$(LIBSTATIC)
DOC = $(DIR)$(SEPARATOR)doc

.PHONY: all test memchk gtkdoc doxygen format clean distclean update help

all:
	@echo "compile cgraph in Platform $(MY_OS)"
	$(MKDIR) $(MKDIRFLAGS) $(LIB)
	$(MAKE) -C $(SRC) -f Makefile.mk
	$(MAKE) -C $(TST) -f Makefile.mk

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
	$(CP) $(CPFLAGS) Doxyfile.base Doxyfile
	doxygen -u
	doxygen

format:
	astyle --style=kr $(INC)$(SEPARATOR)*.h $(INC)$(SEPARATOR)*.ht $(SRC)$(SEPARATOR)*.c $(SRC)$(SEPARATOR)*.ct $(TST)$(SEPARATOR)*.c

clean:
	@echo "clean cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(SRC) -f Makefile.mk clean
	$(MAKE) -C $(TST) -f Makefile.mk clean
	$(MAKE) -C $(DOC) -f Makefile.mk clean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARED)

distclean:
	@echo "distclean cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(SRC) -f Makefile.mk distclean
	$(MAKE) -C $(TST) -f Makefile.mk distclean
	$(MAKE) -C $(DOC) -f Makefile.mk distclean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARED)
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