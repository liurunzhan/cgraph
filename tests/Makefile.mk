DIR = .
INC = $(DIR)$(PSEP)..$(PSEP)include
LIB = $(DIR)$(PSEP)..$(PSEP)lib

TARGET = $(PRO)
SOURCE = $(TARGET).c

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

all: compile

compile:
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET_TEST) $(SOURCE) -L$(LIB) -shared -l$(PRO)

test: compile
	$(DIR)$(PSEP)$(TARGET_TEST)

memchk: compile
	$(MEMTOOL) $(MEMFLAGS) $(DIR)$(PSEP)$(TARGET_TEST)

clean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)

distclean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)
