# a simple Makefile to compile cgraph and generate static and shared library, 
# which crosses the platforms of windows and linux.

export CC = cc
export CFLAGS = -pedantic -Wall -fpic -std=c89
export MAKE = make
export AR = ar
export ARFLAGS = -rcs
export CSFLAGS = -shared
export TARGET = cgraph
export LIBTARGET = lib$(TARGET)
export MODE = debug

ifeq ($(MODE), debug)
CFLAGS += -g -DDEBUG
else ifeq ($(MODE), release)
CFLAGS += -static -O2
endif

# cross platforms
# mingw
# msys
# msys2
# cgywin
# wsl
# linux
# referred by http://www.imooc.com/wenda/detail/584860
ifeq ("$(findstring ;,$(PATH))", ";")
DETECTED_OS := Windows
else
DETECTED_OS := $(shell uname 2>/dev/null || echo Unknown)
DETECTED_OS := $(patsubst CYGWIN%,Cygwin,$(DETECTED_OS))
DETECTED_OS := $(patsubst MSYS%,MSYS,$(DETECTED_OS))
DETECTED_OS := $(patsubst MINGW%,MSYS,$(DETECTED_OS))
endif

export MY_OS = $(DETECTED_OS)

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
endif

DIR = .
INC = $(DIR)$(SEPARATOR)include
SRC = $(DIR)$(SEPARATOR)src
TST = $(DIR)$(SEPARATOR)test
LIB = $(DIR)$(SEPARATOR)lib
PATH_LIBSHARED = $(LIB)$(SEPARATOR)$(LIBSHARED)
PATH_LIBSTATIC = $(LIB)$(SEPARATOR)$(LIBSTATIC)

.PHONY: all test clean distclean help

all:
	@echo "compile cgraph in Platform $(MY_OS)"
	$(MKDIR) $(MKDIRFLAGS) $(LIB)
	$(MAKE) -C $(SRC)
	$(MAKE) -C $(TST)

test:
	@echo "test cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(TST) test

clean:
	@echo "clean cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(SRC) clean
	$(MAKE) -C $(TST) clean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARED)

distclean:
	@echo "distclean cgraph in Platform $(MY_OS)"
	$(MAKE) -C $(SRC) distclean
	$(MAKE) -C $(TST) distclean
	$(RM) $(RMFLAGS) $(PATH_LIBSTATIC)
	$(RM) $(RMFLAGS) $(PATH_LIBSHARED)
	$(RMDIR) $(RMDIRFLAGS) $(LIB)

help:
	@echo "build cgraph in Platform $(MY_OS)"
	@echo "$(MAKE) <target>"
	@echo "<target>: "
	@echo "                    build cgraph"
	@echo "          test      test cgraph"
	@echo "          clean     clean all the generated files"
	@echo "          distclean clean all the generated files and directories"
	@echo "          help      commands to this program"