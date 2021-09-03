DIR = .
INC = $(DIR)$(SEPARATOR)..$(SEPARATOR)include
LIB = $(DIR)$(SEPARATOR)..$(SEPARATOR)lib

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(SEPARATOR)$(LIBSTATIC)
LIBSHARED_TARGET = $(LIB)$(SEPARATOR)$(LIBSHARED)

.PHONY: all clean distclean

all: $(LIBSHARED_TARGET) $(LIBSTATIC_TARGET)

$(LIBSHARED_TARGET): $(OBJECT)
	$(CC) $(CSFLAGS) -o $(LIBSHARED_TARGET) $(OBJECT)

$(LIBSTATIC_TARGET): $(OBJECT)
	$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ -MD -MF $*.d

-include $(DEPEND)

clean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)

distclean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)