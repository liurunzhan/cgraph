DIR=.
INC=$(DIR)/../include
LIB=$(DIR)/../lib

SOURCE = cgraph.c
TARGET = cgraph

.PHONY: all test clean

all:

test:
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET) $(SOURCE) -L$(LIB) -static -l$(TARGET) -lm
	./$(TARGET) ./elements.csv

clean:
	$(RM) $(RMFLAGS) $(TARGET)

distclean:
	$(RM) $(RMFLAGS) $(TARGET)