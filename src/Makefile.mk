DIR = ..
INC = $(DIR)$(SEPARATOR)..$(SEPARATOR)include
LIB = $(DIR)$(SEPARATOR)..$(SEPARATOR)lib
FUNC  = func
TYPE  = type
GRAPH = graph
GAME  = game

SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
DEPEND = $(SOURCE:.c=.d)

LIBSTATIC_TARGET = $(LIB)$(SEPARATOR)$(LIBSTATIC)
LIBSHARED_TARGET = $(LIB)$(SEPARATOR)$(LIBSHARED)

.PHONY: all clean distclean

all: $(OBJECT)
	$(MAKE) -C $(FUNC) -f Makefile.mk
	$(MAKE) -C $(TYPE) -f Makefile.mk
	$(MAKE) -C $(GRAPH) -f Makefile.mk
	$(MAKE) -C $(GAME) -f Makefile.mk

$(LIBSHARED_TARGET): $(OBJECT)
	$(CC) $(CSFLAGS) -o $(LIBSHARED_TARGET) $(OBJECT)

$(LIBSTATIC_TARGET): $(OBJECT)
	$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ -MD -MF $*.d

-include $(DEPEND)

clean:
	$(MAKE) -C $(FUNC) -f Makefile.mk clean
	$(MAKE) -C $(TYPE) -f Makefile.mk clean
	$(MAKE) -C $(GRAPH) -f Makefile.mk clean
	$(MAKE) -C $(GAME) -f Makefile.mk clean
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)

distclean:
	$(MAKE) -C $(FUNC) -f Makefile.mk distclean
	$(MAKE) -C $(TYPE) -f Makefile.mk distclean
	$(MAKE) -C $(GRAPH) -f Makefile.mk distclean
	$(MAKE) -C $(GAME) -f Makefile.mk distclean
	$(RM) $(RMFLAGS) $(OBJECT) $(DEPEND)