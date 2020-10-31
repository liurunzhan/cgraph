DIR= .
INC= $(DIR)$(SEPARATOR)..$(SEPARATOR)include
LIB= $(DIR)$(SEPARATOR)..$(SEPARATOR)lib

SOURCE= cgraph.c
ifndef TARGET
TARGET= cgraph
endif
ifeq ($(MY_OS), Windows)
TARGET_TEST= $(TARGET).exe
else
TARGET_TEST= $(TARGET)
endif

.PHONY: all test clean

all:

test:
	$(CC) $(CFLAGS) -I$(INC) -o $(TARGET) $(SOURCE) -L$(LIB) -l$(TARGET) -lm
	.$(SEPARATOR)$(TARGET_TEST) .$(SEPARATOR)elements.csv

clean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)

distclean:
	$(RM) $(RMFLAGS) $(TARGET_TEST)