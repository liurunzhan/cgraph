#!/usr/bin/Rscript

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

PRO <- "cgraph"
DIR <- "."
INC <- file.path(DIR, "include", fsep=.Platform$file.sep)
SRC <- file.path(DIR, "src", fsep=.Platform$file.sep)
SRC_TYPE <- file.path(SRC, "type", fsep=.Platform$file.sep)
TST <- file.path(DIR, "tests", fsep=.Platform$file.sep)
LIB <- file.path(DIR, "lib", fsep=.Platform$file.sep)

CC <- "cc"
CFLAGS <- "-std=c89 -Wall -pedantic -fPIC"
CSFLAGS <- "-shared"

MODE <- "debug"
if (MODE == "debug") {
  CFLAGS <- paste(CFLAGS, "-g -DDEBUG", sep=" ")
} else if (MODE == "release") {
  CFLAGS <- paste(CFLAGS, "-static -O2", sep=" ")
}

# package shared library
AR <- "ar"
ARFLAGS <- "-rcs"

# get all source files from subdirectories
CFILES <- lapply(list.files(SRC, pattern="^[^\\.].*?\\.c$", recursive=TRUE), function(x) { file.path(SRC, x, fsep=.Platform$file.sep)})

TEST_FILES <- lapply(list.files(TST, pattern="*\\.c$"), function(x) { file.path(TST, x, fsep=.Platform$file.sep)})

if (.Platform$OS.type == "windows") {
  # target files
  LIBSHARED <- file.path(LIB, paste("lib", PRO, ".dll", sep=""), fsep=.Platform$file.sep)
  LIBSTATIC <- file.path(LIB, paste("lib", PRO, ".lib", sep=""), fsep=.Platform$file.sep)
  # test files
  TSTSUFFIX <- ".exe"
} else {
  # target files
  LIBSHARED <- file.path(LIB, paste("lib", PRO, ".so", sep=""), fsep=.Platform$file.sep)
  LIBSTATIC <- file.path(LIB, paste("lib", PRO, ".a", sep=""), fsep=.Platform$file.sep)
  # test files
  TSTSUFFIX <- ""
}

args <- commandArgs(trailingOnly = TRUE)
script_name <- unlist(strsplit(commandArgs()[4], split="="))[2]
if (length(args) == 0) {
  if (!file.exists(LIB)) {
    dir.create(LIB)
  }
  OFILES <- character()
  for (file in CFILES) {
    obj <- gsub("\\.c$", ".o", file)
		dep <- gsub("\\.c$", ".d", file)
    print(sprintf("compile %s to %s", file, obj))
    system(sprintf("%s %s -I%s -I%s -c %s -o %s -MD -MF %s", CC, CFLAGS, INC, SRC_TYPE, file, obj, dep))
    OFILES <- append(OFILES, obj, after=length(OFILES))
  }
  print(sprintf("compile %s", LIBSHARED))
  system(sprintf("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, paste(OFILES, collapse=" ")))
  print(sprintf("compile %s", LIBSTATIC))
  system(sprintf("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, paste(OFILES, collapse=" ")))
} else if (args[1] == "test") {
	for (file in TEST_FILES) {
		TSTFILE <- file
		TSTTARGET <- gsub("\\.c$", TSTSUFFIX, TSTFILE)
  	print(sprintf("compile %s to %s", TSTFILE, TSTTARGET))
  	system(sprintf("%s %s -I%s -o %s %s -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO))
  	print(sprintf("test %s", TSTTARGET))
	  system(TSTTARGET)
	}
} else if (args[1] == "clean") {
  for (file in CFILES) {
    obj <- gsub("\\.c$", ".o", file)
    print(sprintf("clean %s", obj))
    unlink(file.path(SRC, obj, fsep=.Platform$file.sep), force=TRUE)
    dep <- gsub("\\.c$", ".d", file)
    print(sprintf("clean %s", dep))
    unlink(file.path(SRC, dep, fsep=.Platform$file.sep), force=TRUE)
  }
  print(sprintf("clean %s", LIBSTATIC))
  unlink(LIBSTATIC, force=TRUE)
  print(sprintf("clean %s", LIBSHARED))
  unlink(LIBSHARED, force=TRUE)
	for (file in TEST_FILES) {
		TSTFILE <- file
		TSTTARGET <- gsub("\\.c$", TSTSUFFIX, TSTFILE)
  	print(sprintf("clean %s", TSTTARGET))
  	unlink(TSTTARGET, force=TRUE)
	}
} else if (args[1] == "distclean") {
  for (file in CFILES) {
    obj <- gsub("\\.c$", ".o", file)
    print(sprintf("clean %s", obj))
    unlink(file.path(SRC, obj, fsep=.Platform$file.sep), force=TRUE)
    dep <- gsub("\\.c$", ".d", file)
    print(sprintf("clean %s", dep))
    unlink(file.path(SRC, dep, fsep=.Platform$file.sep), force=TRUE)
  }
  print(sprintf("clean %s", LIBSTATIC))
  unlink(LIBSTATIC, force=TRUE)
  print(sprintf("clean %s", LIBSHARED))
  unlink(LIBSHARED, force=TRUE)
  print(sprintf("clean %s", LIB))
  unlink(LIB, force=TRUE)
	for (file in TEST_FILES) {
		TSTFILE <- file
		TSTTARGET <- gsub("\\.c$", TSTSUFFIX, TSTFILE)
  	print(sprintf("clean %s", TSTTARGET))
  	unlink(TSTTARGET, force=TRUE)
	}
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