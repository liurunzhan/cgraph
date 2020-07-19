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
if(MODE == "debug") {
  CFLAGS <- paste(CFLAGS, "-g -DDEBUG", sep=" ")
} else if(MODE == "release") {
  CFLAGS <- paste(CFLAGS, "-static -O2", sep=" ")
}

# package shared library
AR <- "ar"
ARFLAGS <- "-rcs"

if(.Platform$OS.type == "windows") {
  # target files
  LIBSHARED <- file.path(LIB, paste("lib", PRO, ".dll", sep=""), fsep=.Platform$file.sep)
  LIBSTATIC <- file.path(LIB, paste("lib", PRO, ".a", sep=""), fsep=.Platform$file.sep)
  # test files
  TSTFILE <- file.path(TST, paste(PRO, ".c", sep=""), fsep=.Platform$file.sep)
  TSTTARGET <- file.path(TST, paste(PRO, ".exe", sep=""), fsep=.Platform$file.sep)
} else {
  # target files
  LIBSHARED <- file.path(LIB, paste("lib", PRO, ".so", sep=""), fsep=.Platform$file.sep)
  LIBSTATIC <- file.path(LIB, paste("lib", PRO, ".a", sep=""), fsep=.Platform$file.sep)
  # test files
  TSTFILE <- file.path(TST, paste(PRO, ".c", sep=""), fsep=.Platform$file.sep)
  TSTTARGET <- file.path(TST, PRO, fsep=.Platform$file.sep)
}

CFILES <- list.files(SRC, pattern=".c$")

args <- commandArgs(trailingOnly = TRUE)
script_name <- unlist(strsplit(commandArgs()[4], split="="))[2]
if (length(args) == 0) {
  dir.create(LIB)
  for(file in CFILES) {
    obj <- gsub(".c$", ".o", file)
    print(sprintf("compile %s to %s", file.path(SRC, file, fsep=.Platform$file.sep), file.path(SRC, obj, fsep=.Platform$file.sep)))
    system(sprintf("%s %s -I%s -c %s -o %s", CC, CFLAGS, INC, file.path(SRC, file, fsep=.Platform$file.sep), file.path(SRC, obj, fsep=.Platform$file.sep)))
  }
  print(sprintf("compile %s", LIBSHARED))
  system(sprintf("%s %s -o %s %s/*.o", CC, CSFLAGS, LIBSHARED, SRC))
  print(sprintf("compile %s", LIBSTATIC))
  system(sprintf("%s %s %s %s/*.o", AR, ARFLAGS, LIBSTATIC, SRC))
} else if (args[1] == "test") {
  print(sprintf("compile %s to %s", TSTFILE, TSTTARGET))
  system(sprintf("%s %s -I%s -o %s %s -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
  print(sprintf("test %s with %s", TSTTARGET, file.path(TST, "elements.csv", fsep=.Platform$file.sep)))
  system(sprintf("%s %s", TSTTARGET, file.path(TST, "elements.csv", fsep=.Platform$file.sep)))
} else if (args[1] == "clean") {
  for(file in CFILES) {
    obj <- gsub(".c$", ".o", file)
    print(sprintf("clean %s", obj))
    unlink(file.path(SRC, obj, fsep=.Platform$file.sep), force=TRUE)
  }
  print(sprintf("clean %s", LIBSTATIC))
  unlink(LIBSTATIC, force=TRUE)
  print(sprintf("clean %s", LIBSHARED))
  unlink(LIBSHARED, force=TRUE)
  print(sprintf("clean %s", TSTTARGET))
  unlink(TSTTARGET, force=TRUE)
} else if (args[1] == "distclean") {
  for(file in CFILES) {
    obj <- gsub(".c$", ".o", file)
    print(sprintf("clean %s", obj))
    unlink(file.path(SRC, obj, fsep=.Platform$file.sep), force=TRUE)
  }
  print(sprintf("clean %s", LIBSTATIC))
  unlink(LIBSTATIC, force=TRUE)
  print(sprintf("clean %s", LIBSHARED))
  unlink(LIBSHARED, force=TRUE)
  print(sprintf("clean %s", LIB))
  unlink(LIB, force=TRUE)
  print(sprintf("clean %s", TSTTARGET))
  unlink(TSTTARGET, force=TRUE)
} else if (args[1] == "help") {
  print(sprintf("%s <target>", script_name))
  print("<target>: ")
  print("                    compile cgraph")
  print("          test      test cgraph")
  print("          clean     clean all the generated files")
  print("          distclean clean all the generated files and directories")
  print("          help      commands to this program")
} else {
  print(sprintf("%s is an unsupported command", args[1]))
  print(sprintf("use \"%s help\" to know all supported commands", script_name))
}