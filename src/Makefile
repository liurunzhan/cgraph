ROOT=..
INC=$(ROOT)/include
LIB=$(ROOT)/lib

DIR=.

SOURCE=$(wildcard *.c)
OBJECT=$(SOURCE:.c=.o)

.PHONY: all clean

all: $(OBJECT)

$(OBJECT): %.o: %.c
	@echo *** START the compilation of $< to $@ ***
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@echo *** END the compilation of $< to $@ ***

clean:
	@-$(RM) $(RMFLAGS) $(OBJECT)

distclean:
	@-$(RM) $(RMFLAGS) $(OBJECT)