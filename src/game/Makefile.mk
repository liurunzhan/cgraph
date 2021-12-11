DIR = ..
INC = $(DIR)$(PSEP)..$(PSEP)include
LIB = .

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(PSEP)libgame$(LIBSTATIC_SUFFIX)
LIBSHARED_TARGET = $(LIB)$(PSEP)libgame$(LIBSHARED_SUFFIX)

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
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND) $(LIBSTATIC_TARGET) $(LIBSTATIC_TARGET)

distclean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND) $(LIBSTATIC_TARGET) $(LIBSTATIC_TARGET)