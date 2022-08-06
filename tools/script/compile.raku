#!/usr/bin/perl6

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

use v6;

my $PRO = "cgraph";
my $DIR = ".";
my $INC = $DIR.IO.add("include");
my $SRC = $DIR.IO.add("src");
my $SRC_TYPE = $SRC.IO.add("type");
my $TST = $DIR.IO.add("tests");
my $LIB = $DIR.IO.add("lib");

my $CC = "cc";
my $CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
my $CSFLAGS = "-shared";

my $MODE = "debug";
if ($MODE eq "debug") {
  $CFLAGS = "$CFLAGS -g -DDEBUG";
} elsif ($MODE eq "release") {
  $CFLAGS = "$CFLAGS -static -O2";
}

# package shared library
my $AR = "ar";
my $ARFLAGS = "-rcs";

# source files
# get all subdirectories
sub getsubdirs ($path, $dirs) {
  for dir($path) -> $item {
    if ($item.basename !~~ /^\./) {
      if ($item.IO ~~ :d) {
        $dirs.push($item);
        getsubdirs($item, $dirs);
      }
    }
  }
}

my @SRCS = ();
getsubdirs($SRC, @SRCS);

# get all source files from subdirectories
my @CFILES;
for (@SRCS) -> $dir {
  for dir($dir) -> $file {
    if ($file ~~ /\.c$/) {
      @CFILES.push($file);
    }
  }
}

my $LIBSHARED;
my $LIBSTATIC;
my $TSTFILE;
my $TSTTARGET;

if (VM.osname eq "MSWin32") {
  # target files
  $LIBSHARED = $LIB.IO.add("lib$PRO.dll");
  $LIBSTATIC = $LIB.IO.add("lib$PRO.lib");
  # test files
  $TSTFILE = $TST.IO.add("$PRO.c");
  $TSTTARGET = $TST.IO.add("$PRO.exe");
} else {
  # target files
  $LIBSHARED = $LIB.IO.add("lib$PRO.so");
  $LIBSTATIC = $LIB.IO.add("lib$PRO.a");
  # test files
  $TSTFILE = $TST.IO.add("$PRO.c");
  $TSTTARGET = $TST.IO.add("$PRO");
}

my @args = @*ARGS;
if (@args.elems eq 0) {
  mkdir $LIB;
  my @OFILES;
  for @CFILES -> $file {
    my $obj = S/\.c$/\.o/ given $file;
    my $dep = S/\.c$/\.d/ given $file;
    say("compile $file to $obj");
    shell("$CC $CFLAGS -I$INC -I$SRC_TYPE -c $file -o $obj -MD -MF $dep");
    @OFILES.push($obj);
  }
  say("compile $LIBSHARED");
  shell("$CC $CSFLAGS -o $LIBSHARED " ~ join " ", @OFILES);
  say("compile $LIBSTATIC");
  shell("$AR $ARFLAGS $LIBSTATIC " ~ join " ", @OFILES);
} elsif (@args[0] eq "test") {
  say("compile $TSTFILE to $TSTTARGET");
  shell("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
  say("test $TSTTARGET with $TST.IO.add("elements.csv")");
  shell("$TSTTARGET $TST.IO.add("elements.csv")");
} elsif (@args[0] eq "clean") {
  for @CFILES -> $file {
    my $obj = S/\.c$/\.o/ given $file;
    say("clean $obj");
    unlink "$obj";
    my $dep = S/\.c$/\.d/ given $file;
    say("clean $dep");
    unlink "$dep";
  }
  say("clean $LIBSTATIC");
  unlink "$LIBSTATIC";
  say("clean $LIBSHARED");
  unlink "$LIBSHARED";
  say("clean $TSTTARGET");
  unlink "$TSTTARGET";
} elsif (@args[0] eq "distclean") {
  for @CFILES -> $file {
    my $obj = S/\.c$/\.o/ given $file;
    say("clean $obj");
    unlink "$obj";
    my $dep = S/\.c$/\.d/ given $file;
    say("clean $dep");
    unlink "$dep";
  }
  say("clean $LIBSTATIC");
  unlink "$LIBSTATIC";
  say("clean $LIBSHARED");
  unlink "$LIBSHARED";
  say("clean $LIB");
  rmdir $LIB;
  say("clean $TSTTARGET");
  unlink "$TSTTARGET";
} elsif (@args[0] eq "help") {
  say("$*PROGRAM-NAME <target>");
  say("<target>: ");
  say("                    compile cgraph");
  say("          test      test cgraph");
  say("          clean     clean all the generated files");
  say("          distclean clean all the generated files and directories");
  say("          help      commands to this program");
} else {
  say("@args[0] is an unsupported command");
  say("use \"$*PROGRAM-NAME help\" to know all supported commands");
}
