# a simple Makefile to compile cgraph and generate static and shared library, 
# which crosses the platforms of windows and linux.

export CC = cc
export CFLAGS = -ansi -pedantic -pedantic-errors -Wall -fPIC
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
	@echo "compile cgraph in Platform $(MY_OS)"
	$(MKDIR) $(LIB)
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