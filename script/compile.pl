#!/usr/bin/perl -w

use strict;
use warnings;
use File::Spec;

my $PRO = "cgraph";
my $DIR = ".";
my $INC = File::Spec->catdir($DIR, "include");
my $SRC = File::Spec->catdir($DIR, "src");
my $TST = File::Spec->catdir($DIR, "test");
my $LIB = File::Spec->catdir($DIR, "lib");

my $CC = "cc";
my $CFLAGS = "-pedantic -Wall -fPIC -std=c89";
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
my @CFILES = ();
opendir(my $fin, $SRC) or die "cannot open directory $SRC";
foreach my $file (readdir($fin))
{
  if($file =~ /\.c$/)
  {
    push(@CFILES, File::Spec->catfile($SRC, $file));
  }
}
closedir($fin);
my $LIBSHARED;
my $LIBSTATIC;
my $TSTFILE;
my $TSTTARGET;
if ($^O eq "MSWin32")
{
  # target files
  $LIBSHARED = File::Spec->catfile($LIB, "lib$PRO.dll");
  $LIBSTATIC = File::Spec->catfile($LIB, "lib$PRO.a");
  # test files
  $TSTFILE = File::Spec->catfile($TST, "$PRO.c");
  $TSTTARGET = File::Spec->catfile($TST, "$PRO.exe");
}
else
{
  # target files
  $LIBSHARED = File::Spec->catfile($LIB, "lib$PRO.so");
  $LIBSTATIC = File::Spec->catfile($LIB, "lib$PRO.a");
  # test files
  $TSTFILE = File::Spec->catfile($TST, "$PRO.c");
  $TSTTARGET = File::Spec->catfile($TST, "$PRO");
}

my @args = @ARGV;
if ($#args == -1)
{
  mkdir $LIB;
  my @OFILES = ();
  foreach my $file (@CFILES)
  {
    my $obj = ($file =~ s/\.c$/\.o/r);
    printf("compile %s to %s\n", $file, $obj);
    system(sprintf("$CC $CFLAGS -I$INC -c %s -o %s", $file, $obj));
    push(@OFILES, $obj);
  }
  print("compile $LIBSHARED\n");
  system(sprintf("$CC $CSFLAGS -o $LIBSHARED %s", join(" ", @OFILES)));
  print("compile $LIBSTATIC\n");
  system(sprintf("$AR $ARFLAGS $LIBSTATIC %s", join(" ", @OFILES)));
}
elsif ($args[0] eq "test")
{
  print("compile $TSTFILE to $TSTTARGET\n");
  system("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
  printf("test $TSTTARGET with %s\n", File::Spec->catfile($TST, "elements.csv"));
  system(sprintf("$TSTTARGET %s", File::Spec->catfile($TST, "elements.csv")));
}
elsif ($args[0] eq "clean")
{
  foreach my $file (@CFILES)
  {
    my $obj = ($file =~ s/\.c$/\.o/r);
    print("clean $obj\n");
    unlink $obj;
  }
  print("clean $LIBSTATIC\n");
  unlink $LIBSTATIC;
  print("clean $LIBSHARED\n");
  unlink $LIBSHARED;
  print("clean $TSTTARGET\n");
  unlink $TSTTARGET;
}
elsif ($args[0] eq "distclean")
{
  foreach my $file (@CFILES)
  {
    my $obj = ($file =~ s/\.c$/\.o/r);
    print("clean $obj\n");
    unlink $obj;
  }
  print("clean $LIBSTATIC\n");
  unlink $LIBSTATIC;
  print("clean $LIBSHARED\n");
  unlink $LIBSHARED;
  print("clean $LIB\n");
  rmdir $LIB;
  print("clean $TSTTARGET\n");
  unlink $TSTTARGET;
}
elsif ($args[0] eq "help")
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