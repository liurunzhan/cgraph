PRO = "cgraph"
project(PRO, "c")
library(PRO)

incdir = include_directories('include')

CC = "cc" 
CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
CSFLAGS = "-shared"

if get_option("debug").enabled()
CFLAGS += " -g -DDEBUG"
elif get_option("release").enabled()
CFLAGS += " -static -O2"
endif

AR = "ar"
ARFLAGS = "-rcs"