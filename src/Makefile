ROOT=..
INC=$(ROOT)/include
LIB=$(ROOT)/lib

DIR=.

SOURCE=$(wildcard *.c)
OBJECT=$(SOURCE:.c=.o)

LIBSTATIC_TARGET=$(LIB)/$(LIBSTATIC)
LIBSHARE_TARGET=$(LIB)/$(LIBSHARE)

.PHONY: all clean

all: $(LIBSTATIC_TARGET) $(LIBSHARE_TARGET)

$(LIBSTATIC_TARGET): $(OBJECT)
	@echo *** START the compilation of $(LIBSTATIC) ***
	@$(AR) $(ARFLAGS) $(LIBSTATIC_TARGET) -I$(INC) $(OBJECT)
	@echo *** END the compilation of $(LIBSTATIC) ***

$(LIBSHARE_TARGET): $(OBJECT)
	@echo *** START the compilation of $(LIBSHARE) ***
	@$(CC) $(CFLAGS) $(CSFLAGS) -I$(INC) -o $(LIBSHARE_TARGET) $(SOURCE)
	@echo *** END the compilation of $(LIBSHARE) ***

$(OBJECT): %.o: %.c
	@echo *** START the compilation of $< to $@ ***
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@echo *** END the compilation of $< to $@ ***

clean:
	@-$(RM) $(RMFLAGS) $(OBJECT)

distclean:
	@-$(RM) $(RMFLAGS) $(OBJECT)