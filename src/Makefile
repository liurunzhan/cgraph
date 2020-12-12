ROOT = ..
INC = $(ROOT)$(SEPARATOR)include
LIB = $(ROOT)$(SEPARATOR)lib

DIR = .

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(SEPARATOR)$(LIBSTATIC)
LIBSHARED_TARGET = $(LIB)$(SEPARATOR)$(LIBSHARED)

.PHONY: all clean distclean

all: $(LIBSTATIC_TARGET) $(LIBSHARED_TARGET)

$(LIBSTATIC_TARGET): $(OBJECT)
	$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) $(OBJECT)

$(LIBSHARED_TARGET): $(OBJECT)
	$(CC) $(CSFLAGS) -o $(LIBSHARED_TARGET) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ -MD -MF $*.d

-include $(DEPEND)

clean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)

distclean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)