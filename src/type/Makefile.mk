DIR = .
INC = $(DIR)$(SEPARATOR)..$(SEPARATOR)include
LIB = $(DIR)$(SEPARATOR)..$(SEPARATOR)lib

BASIC      = basic
DATA       = data
OBJECT_DIR = object
STRUCTURE  = structure

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(SEPARATOR)$(LIBSTATIC)
LIBSHARED_TARGET = $(LIB)$(SEPARATOR)$(LIBSHARED)

.PHONY: all clean distclean

all: $(OBJECT)
	$(MAKE) -C $(BASIC) -f Makefile.mk
	$(MAKE) -C $(DATA) -f Makefile.mk
	$(MAKE) -C $(OBJECT_DIR) -f Makefile.mk
	$(MAKE) -C $(STRUCTURE) -f Makefile.mk

$(LIBSHARED_TARGET): $(OBJECT)
	$(CC) $(CSFLAGS) -o $(LIBSHARED_TARGET) $(OBJECT)

$(LIBSTATIC_TARGET): $(OBJECT)
	$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ -MD -MF $*.d

-include $(DEPEND)

clean:
	$(MAKE) -C $(BASIC) -f Makefile.mk
	$(MAKE) -C $(DATA) -f Makefile.mk
	$(MAKE) -C $(OBJECT_DIR) -f Makefile.mk
	$(MAKE) -C $(STRUCTURE) -f Makefile.mk
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)

distclean:
	$(MAKE) -C $(BASIC) -f Makefile.mk
	$(MAKE) -C $(DATA) -f Makefile.mk
	$(MAKE) -C $(OBJECT_DIR) -f Makefile.mk
	$(MAKE) -C $(STRUCTURE) -f Makefile.mk
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)