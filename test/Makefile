DIR=.
INC=$(DIR)/../include
LIB=$(DIR)/../lib

SOURCE = cgraph.c
ifndef TARGET
TARGET = cgraph
endif
ifeq ($(OS), Windows_NT)
TARGET_TEST = $(TARGET).exe
else
TARGET_TEST = $(TARGET)
endif

.PHONY: all test clean

all:

test:
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET) $(SOURCE) -L$(LIB) -static -l$(TARGET) -lm
	./$(TARGET_TEST) ./elements.csv

clean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)

distclean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)