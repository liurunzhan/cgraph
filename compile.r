#!/usr/bin/Rscript

PRO <- "cgraph"
DIR <- "."
SRC <- file.path(DIR, "src", fsep=.Platform$file.sep)
INC <- file.path(DIR, "include", fsep=.Platform$file.sep)
TST <- file.path(DIR, "test", fsep=.Platform$file.sep)
LIB <- file.path(DIR, "lib", fsep=.Platform$file.sep)

CC <- "cc"
CFLAGS <- "-pedantic -Wall -fpic -std=c89"
CSFLAGS <- "-shared"

MODE <- "debug"
if(MODE == "debug")
{
  CFLAGS <- paste(CFLAGS, "-g -DDEBUG", sep=" ")
} else if(MODE == "release")
{
  CFLAGS <- paste(CFLAGS, "-static -O2", sep=" ")
}

# package shared library
AR <- "ar"
ARFLAGS <- "-rcs"

if(.Platform$OS.type == "windows")
{
  # target files
  LIBSHARED <- file.path(LIB, paste("lib", PRO, ".dll", sep=""), fsep=.Platform$file.sep)
  LIBSTATIC <- file.path(LIB, paste("lib", PRO, ".a", sep=""), fsep=.Platform$file.sep)
  # test files
  TSTFILE <- file.path(TST, paste(PRO, ".c", sep=""), fsep=.Platform$file.sep)
  TSTTARGET <- file.path(TST, paste(PRO, ".exe", sep=""), fsep=.Platform$file.sep)
} else
{
  # target files
  LIBSHARED <- file.path(LIB, paste("lib", PRO, ".so", sep=""), fsep=.Platform$file.sep)
  LIBSTATIC <- file.path(LIB, paste("lib", PRO, ".a", sep=""), fsep=.Platform$file.sep)
  # test files
  TSTFILE <- file.path(TST, paste(PRO, ".c", sep=""), fsep=.Platform$file.sep)
  TSTTARGET <- file.path(TST, PRO, fsep=.Platform$file.sep)
}

CFILES <- list.files(SRC, pattern=".c$")
print(CFILES)