DIR = ..$(SEPARATOR)..$(SEPARATOR)
INC = $(DIR)$(SEPARATOR)..$(SEPARATOR)include
LIB = $(DIR)$(SEPARATOR)..$(SEPARATOR)lib

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

.PHONY: all clean distclean

all: $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ -MD -MF $*.d

-include $(DEPEND)

clean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)

distclean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)
