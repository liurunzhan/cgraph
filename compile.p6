#!/usr/bin/env/perl6

use v6;

my $PRO = "cgraph";
my $DIR = ".";
my $SRC = "$DIR/src";
my $INC = "$DIR/include";
my $TST = "$DIR/test";
my $LIB = "$DIR/lib";

my $CC = "cc";
my $CFLAGS = "-ansi -pedantic -pedantic-errors -Wall -fPIC -g";
my $CSFLAGS = "-shared";

# package shared library
my $AR = "ar";
my $ARFLAGS = "-rcs";

# source files
opendir(my $fin, $SRC) or die "cannot open directory $SRC";
my @CFILES = readdir($fin);
closedir($fin);
my $LIBSHARED;
my $LIBSTATIC;
my $TSTFILE;
my $TSTTARGET;
if($^O eq "MSWin32")
{
  # target files
  $LIBSHARED = "$LIB/lib$PRO.dll";
  $LIBSTATIC = "$LIB/lib$PRO.a";
  # test files
  $TSTFILE = "$TST/$PRO.c";
  $TSTTARGET = "$TST/$PRO.exe";
}
else
{
  # target files
  $LIBSHARED = "$LIB/lib$PRO.so";
  $LIBSTATIC = "$LIB/lib$PRO.a";
  # test files
  $TSTFILE = "$TST/$PRO.c";
  $TSTTARGET = "$TST/$PRO";
}

my @args = @*ARGS;

if($args[0] eq "")
{
  mkdir $LIB;
  foreach my $file (@CFILES)
  {
    if($file =~ /\.c/)
    {
      my $obj = ($file =~ s/\.c/\.o/r);
      print("compile $SRC/$file to $SRC/$obj\n");
      system("$CC $CFLAGS -I$INC -c $SRC/$file -o $SRC/$obj");
    }
  }
  print("compile $LIBSHARED\n");
  system("$CC $CSFLAGS -o $LIBSHARED $SRC/*.o");
  print("compile $LIBSTATIC\n");
  system("$AR $ARFLAGS $LIBSTATIC $SRC/*.o");
}
elsif($args[0] eq "test")
{
  print("compile $TSTFILE to $TSTTARGET\n");
  system("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
  print("test $TSTTARGET with ${TST}/elements.csv\n");
  system("$TSTTARGET $TST/elements.csv");
}
elsif($args[0] eq "clean")
{
  foreach my $file (@CFILES)
  {
    if($file =~ /\.c/)
    {
      my $obj = ($file =~ s/\.c/\.o/r);
      print("clean $obj\n");
      unlink "$SRC/$obj";
    }
  }
  print("clean $LIBSTATIC\n");
  unlink "$LIBSTATIC";
  print("clean $LIBSHARED\n");
  unlink "$LIBSHARED";
  print("clean $TSTTARGET\n");
  unlink "$TSTTARGET";
}
elsif($args[0] eq "distclean")
{
  foreach my $file (@CFILES)
  {
    if($file =~ /\.c/)
    {
      my $obj = ($file =~ s/\.c/\.o/r);
      print("clean $obj\n");
      unlink "$SRC/$obj";
    }
  }
  print("clean $LIBSTATIC\n");
  unlink "$LIBSTATIC";
  print("clean $LIBSHARED\n");
  unlink "$LIBSHARED";
  print("clean $LIB\n");
  rmdir $LIB;
  print("clean $TSTTARGET\n");
  unlink "$TSTTARGET";
}
elsif($args[0] eq "help")
{
  print("$0 <target>\n");
  print("<target>: \n");
  print("                    compile cgraph\n");
  print("          test      test cgraph\n");
  print("          clean     clean all the generated files\n");
  print("          distclean clean all the generated files and directories\n");
  print("          help      commands to this program\n");
}
else
{
  print("$args[0] is an unsupported command\n");
  print("use \"$0 help\" to know all supported commands\n");
}