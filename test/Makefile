ROOT=..
INC=$(ROOT)/include
LIB=$(ROOT)/lib

DIR=.

SOURCE = cgraph.c
TARGET = cgraph

.PHONY: all test clean

all: 

test: $(TARGET)

$(TARGET):
	@echo *** START the compilation of $< to $@ ***
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIB)/libcgraph.a -o $(TARGET) $(SOURCE)
	@echo *** END the compilation of $< to $@ ***

clean:
	@-$(RM) $(RMFLAGS) $(OBJECT)

distclean:
	@-$(RM) $(RMFLAGS) $(OBJECT)