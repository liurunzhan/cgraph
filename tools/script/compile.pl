#!/usr/bin/perl -w

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

use strict;
use warnings;
use File::Spec;

my $PRO = "cgraph";
my $DIR = ".";
my $INC = File::Spec->catdir($DIR, "include");
my $SRC = File::Spec->catdir($DIR, "src");
my $SRC_TYPE = File::Spec->catdir($SRC, "type");
my $TST = File::Spec->catdir($DIR, "tests");
my $LIB = File::Spec->catdir($DIR, "lib");

my $CC = "cc";
my $CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
my $CSFLAGS = "-shared";

my $MODE = "debug";
if ($MODE eq "debug") {
  $CFLAGS = "$CFLAGS -g -DDEBUG -O0";
} elsif ($MODE eq "release") {
  $CFLAGS = "$CFLAGS -O2";
}

# package shared library
my $AR = "ar";
my $ARFLAGS = "-rcs";

# source files
# get all subdirectories
sub getsubdirs {
  my ($path, $dirs) = @_;
  opendir(my $din, $path) or die "cannot open directory $path";
  foreach my $item (readdir($din)) {
    my $subpath = File::Spec->catfile($path, $item);
    if ((-d $subpath) && ($item !~ /^\./)) {
      push(@{$dirs}, $subpath);
      getsubdirs($subpath, $dirs);
    }
  }
  closedir($din);
}

# get all source files from subdirectories
my @SRCS = ();
getsubdirs($SRC, \@SRCS);

my @CFILES = ();
foreach my $dir (@SRCS) {
  opendir(my $din, $dir) or die "cannot open directory $dir";
  foreach my $item (readdir($din)) {
    my $subpath = File::Spec->catfile($dir, $item);
    if ((-f $subpath) && ($item =~ /^((?!\.).)*\.c$/)) {
      push(@CFILES, $subpath);
    }
  }
  closedir($din);
}

my $LIBSHARED;
my $LIBSTATIC;
my $TSTSUFFIX;
if ($^O eq "MSWin32") {
  # target files
  $LIBSHARED = File::Spec->catfile($LIB, "lib$PRO.dll");
  $LIBSTATIC = File::Spec->catfile($LIB, "lib$PRO.lib");
  # test files
  $TSTSUFFIX = ".exe";
} else {
  # target files
  $LIBSHARED = File::Spec->catfile($LIB, "lib$PRO.so");
  $LIBSTATIC = File::Spec->catfile($LIB, "lib$PRO.a");
  # test files
  $TSTSUFFIX = "";
}

my @args = @ARGV;
if ($#args == -1) {
  mkdir $LIB;
  my @OFILES = ();
  foreach my $file (@CFILES) {
    my $obj = ($file =~ s/\.c$/\.o/r);
    my $dep = ($file =~ s/\.c$/\.d/r);
    printf("compile %s to %s\n", $file, $obj);
    system("$CC $CFLAGS -I$INC -I$SRC_TYPE -c $file -o $obj -MD -MF $dep");
    push(@OFILES, $obj);
  }
  print("compile $LIBSHARED\n");
  system(sprintf("$CC $CSFLAGS -o $LIBSHARED %s", join(" ", @OFILES)));
  print("compile $LIBSTATIC\n");
  system(sprintf("$AR $ARFLAGS $LIBSTATIC %s", join(" ", @OFILES)));
} elsif ($args[0] eq "test") {
  opendir(my $din, $TST) or die "cannot open directory $TST";
  foreach my $file (readdir($din)) {
    if ($file =~ /^((?!\.).)*\.c$/) {
      my $TSTFILE = File::Spec->catfile($TST, $file); 
      my $TSTTARGET = ($TSTFILE =~ s/\.c$/$TSTSUFFIX/r);
      print("compile $TSTFILE to $TSTTARGET\n");
      system("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
      printf("test $TSTTARGET\n");
      system($TSTTARGET);
    }
  }
  closedir($din);
} elsif ($args[0] eq "clean") {
  foreach my $file (@CFILES) {
    my $obj = ($file =~ s/\.c$/\.o/r);
    print("clean $obj\n");
    unlink $obj;
    my $dep = ($file =~ s/\.c$/\.d/r);
    print("clean $dep\n");
    unlink $dep;
  }
  print("clean $LIBSTATIC\n");
  unlink $LIBSTATIC;
  print("clean $LIBSHARED\n");
  unlink $LIBSHARED;
  opendir(my $din, $TST) or die "cannot open directory $TST";
  foreach my $file (readdir($din)) {
    if ($file =~ /^((?!\.).)*\.c$/) {
      my $TSTFILE = File::Spec->catfile($TST, $file); 
      my $TSTTARGET = ($TSTFILE =~ s/\.c$/$TSTSUFFIX/r);
      print("clean $TSTTARGET\n");
      unlink $TSTTARGET;
    }
  }
  closedir($din);
} elsif ($args[0] eq "distclean") {
  foreach my $file (@CFILES) {
    my $obj = ($file =~ s/\.c$/\.o/r);
    print("clean $obj\n");
    unlink $obj;
    my $dep = ($file =~ s/\.c$/\.d/r);
    print("clean $dep\n");
    unlink $dep;
  }
  print("clean $LIBSTATIC\n");
  unlink $LIBSTATIC;
  print("clean $LIBSHARED\n");
  unlink $LIBSHARED;
  print("clean $LIB\n");
  rmdir $LIB;
  opendir(my $din, $TST) or die "cannot open directory $TST";
  foreach my $file (readdir($din)) {
    if ($file =~ /^((?!\.).)*\.c$/) {
      my $TSTFILE = File::Spec->catfile($TST, $file); 
      my $TSTTARGET = ($TSTFILE =~ s/\.c$/$TSTSUFFIX/r);
      print("clean $TSTTARGET\n");
      unlink $TSTTARGET;
    }
  }
  closedir($din);
} elsif ($args[0] eq "help") {
  print("$0 <target>\n");
  print("<target>: \n");
  print("                    compile cgraph\n");
  print("          test      test cgraph\n");
  print("          clean     clean all the generated files\n");
  print("          distclean clean all the generated files and directories\n");
  print("          help      commands to this program\n");
} else {
  print("$args[0] is an unsupported command\n");
  print("use \"$0 help\" to know all supported commands\n");
}
