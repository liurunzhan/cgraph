#!/usr/bin/perl6

use v6;

my $PRO = "cgraph";
my $DIR = ".";
my $SRC = $DIR.IO.add("src");
my $INC = $DIR.IO.add("include");
my $TST = $DIR.IO.add("test");
my $LIB = $DIR.IO.add("lib");

my $CC = "cc";
my $CFLAGS = "-pedantic -Wall -fpic -std=c89";
my $CSFLAGS = "-shared";

my $MODE = "debug";
if ($MODE eq "debug")
{
  $CFLAGS = "$CFLAGS -g -DDEBUG";
}
elsif ($MODE eq "release")
{
  $CFLAGS = "$CFLAGS -static -O2";
}

# package shared library
my $AR = "ar";
my $ARFLAGS = "-rcs";

# source files
my @CFILES;
for (dir $SRC) -> $file
{
  if ($file ~~ /\.c$/)
  {
    @CFILES.push($file);
  }
}
my $LIBSHARED;
my $LIBSTATIC;
my $TSTFILE;
my $TSTTARGET;

if (VM.osname eq "MSWin32")
{
  # target files
  $LIBSHARED = $LIB.IO.add("lib$PRO.dll");
  $LIBSTATIC = $LIB.IO.add("lib$PRO.a");
  # test files
  $TSTFILE = $TST.IO.add("$PRO.c");
  $TSTTARGET = $TST.IO.add("$PRO.exe");
}
else
{
  # target files
  $LIBSHARED = $LIB.IO.add("lib$PRO.so");
  $LIBSTATIC = $LIB.IO.add("lib$PRO.a");
  # test files
  $TSTFILE = $TST.IO.add("$PRO.c");
  $TSTTARGET = $TST.IO.add("$PRO");
}

my @args = @*ARGS;
if (@args.elems eq 0)
{
  mkdir $LIB;
  for @CFILES -> $file
  {
    my $obj = S/\.c$/\.o/ given $file;
    say("compile $file to $obj");
    shell("$CC $CFLAGS -I$INC -c $file -o $obj");
  }
  say("compile $LIBSHARED");
  shell("$CC $CSFLAGS -o $LIBSHARED $SRC/*.o");
  say("compile $LIBSTATIC");
  shell("$AR $ARFLAGS $LIBSTATIC $SRC/*.o");
}
elsif (@args[0] eq "test")
{
  say("compile $TSTFILE to $TSTTARGET");
  shell("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
  say("test $TSTTARGET with $TST.IO.add("elements.csv")");
  shell("$TSTTARGET $TST.IO.add("elements.csv")");
}
elsif (@args[0] eq "clean")
{
  for @CFILES -> $file
  {
    my $obj = S/\.c$/\.o/ given $file;
    say("clean $obj");
    unlink "$obj";
  }
  say("clean $LIBSTATIC");
  unlink "$LIBSTATIC";
  say("clean $LIBSHARED");
  unlink "$LIBSHARED";
  say("clean $TSTTARGET");
  unlink "$TSTTARGET";
}
elsif (@args[0] eq "distclean")
{
  for @CFILES -> $file
  {
    my $obj = S/\.c$/\.o/ given $file;
    say("clean $obj");
    unlink "$obj";
  }
  say("clean $LIBSTATIC");
  unlink "$LIBSTATIC";
  say("clean $LIBSHARED");
  unlink "$LIBSHARED";
  say("clean $LIB");
  rmdir $LIB;
  say("clean $TSTTARGET");
  unlink "$TSTTARGET";
}
elsif (@args[0] eq "help")
{
  say("$0 <target>\n");
  say("<target>: \n");
  say("                    compile cgraph");
  say("          test      test cgraph");
  say("          clean     clean all the generated files");
  say("          distclean clean all the generated files and directories");
  say("          help      commands to this program");
}
else
{
  say("@args[0] is an unsupported command");
  say("use \"$0 help\" to know all supported commands");
}