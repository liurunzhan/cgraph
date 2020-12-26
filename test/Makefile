DIR = .
INC = $(DIR)$(SEPARATOR)..$(SEPARATOR)include
LIB = $(DIR)$(SEPARATOR)..$(SEPARATOR)lib

SOURCE = cgraph.c

ifndef TARGET
TARGET = cgraph
endif

ifeq ($(MY_OS), Windows)
TARGET_TEST = $(TARGET).exe
MEMTOOL = drmemory.exe
MEMFLAGS = 
else
TARGET_TEST = $(TARGET)
MEMTOOL = valgrind
MEMFLAGS = --tool=memcheck --leak-check=full --show-reachable=yes
endif

.PHONY: all test clean memchk

all:

compile:
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET) $(SOURCE) -L$(LIB) -static -l$(TARGET) -lm

test: compile
	.$(SEPARATOR)$(TARGET_TEST) .$(SEPARATOR)elements.csv

memchk: compile
	$(MEMTOOL) $(MEMFLAGS) .$(SEPARATOR)$(TARGET_TEST) .$(SEPARATOR)elements.csv

clean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)

distclean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)