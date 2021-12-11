DIR = ..$(PSEP)..
INC = $(DIR)$(PSEP)..$(PSEP)include
LIB = .

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(PSEP)libdata$(LIBSTATIC_SUFFIX)
LIBSHARED_TARGET = $(LIB)$(PSEP)libdata$(LIBSHARED_SUFFIX)

.PHONY: all clean distclean

all: $(LIBSHARED_TARGET) $(LIBSTATIC_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -I.. -c $< -o $@ -MD -MF $*.d

$(LIBSHARED_TARGET): $(OBJECT)
	$(CC) $(CSFLAGS) -o $(LIBSHARED_TARGET) $(OBJECT)

$(LIBSTATIC_TARGET): $(OBJECT)
	$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) $(OBJECT)

-include $(DEPEND)

clean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND) $(LIBSTATIC_TARGET) $(LIBSTATIC_TARGET)

distclean:
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND) $(LIBSTATIC_TARGET) $(LIBSTATIC_TARGET)
