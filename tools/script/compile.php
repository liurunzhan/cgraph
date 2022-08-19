#!/usr/bin/env -S php -f
<?php

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

declare(strict_types=1);

$PRO = "cgraph";
$DIR = ".";
$INC = File::Spec->catdir($DIR, "include");
$SRC = File::Spec->catdir($DIR, "src");
$SRC_TYPE = File::Spec->catdir($SRC, "type");
$TST = File::Spec->catdir($DIR, "tests");
$LIB = File::Spec->catdir($DIR, "lib");

$CC = "cc";
$CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
$CSFLAGS = "-shared";

$MODE = "debug";
if ($MODE == "debug") {
  $CFLAGS .= " -g -DDEBUG";
} elseif ($MODE == "release") {
  $CFLAGS .= " -static -O2";
}

# package shared library
$AR = "ar";
$ARFLAGS = "-rcs";

$LIBSHARED;
$LIBSTATIC;
$TSTSUFFIX;
if ($PHP_OS == "WIN32" || $PHP_OS == "winnt" || $PHP_OS == "Windows") {
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

$args = $ARGV;
if (count($args) == 0) {
  mkdir($LIB);
  $OFILES = array();
  for($i=0;$i<count($CFILES);$i++) {
		$file = $CFILES[$i];
    $obj = preg_replace("/\.c$/", ".o", $file);
    $dep = preg_replace("/\.c$/", ".d", $file);
    echo(sprintf("compile %s to %s\n", $file, $obj));
    system(sprintf("$CC $CFLAGS -I$INC -I$SRC_TYPE -c %s -o %s -MD -MF %s", $file, $obj, $dep));
    push($OFILES, $obj);
  }
  echo("compile $LIBSHARED\n");
  system(sprintf("$CC $CSFLAGS -o $LIBSHARED %s", join(" ", $OFILES)));
  echo("compile $LIBSTATIC\n");
  system(sprintf("$AR $ARFLAGS $LIBSTATIC %s", join(" ", $OFILES)));
} elseif ($args[0] == "test") {
  opendir($din, $TST) or die "cannot open directory $TST";
  foreach $file (readdir($din)) {
    if ($file =~ /^((?!\.).)*\.c$/) {
      $TSTFILE = File::Spec->catfile($TST, $file); 
      $TSTTARGET = ($TSTFILE =~ s/\.c$/$TSTSUFFIX/r);
      echo("compile $TSTFILE to $TSTTARGET\n");
      system("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
      echo("test $TSTTARGET\n");
      system($TSTTARGET);
    }
  }
  closedir($din);
} elseif ($args[0] == "clean") {
  for($i=0;$i<count($CFILES);$i++) {
		$file = $CFILES[$i];
    $obj = preg_replace("/\.c$/", ".o", $file);
    echo("clean $obj\n");
    unlink $obj;
    $dep = preg_replace("/\.c$/", ".d", $file);
    echo("clean $dep\n");
    unlink $dep;
  }
  echo("clean $LIBSTATIC\n");
  unlink $LIBSTATIC;
  echo("clean $LIBSHARED\n");
  unlink $LIBSHARED;
  opendir($din, $TST) or die "cannot open directory $TST";
  foreach $file (readdir($din)) {
    if ($file =~ /^((?!\.).)*\.c$/) {
      $TSTFILE = File::Spec->catfile($TST, $file); 
      $TSTTARGET = ($TSTFILE =~ s/\.c$/$TSTSUFFIX/r);
      echo("clean $TSTTARGET\n");
      unlink $TSTTARGET;
    }
  }
  closedir($din);
} elseif ($args[0] == "distclean") {
  for($i=0;$i<count($CFILES);$i++) {
		$file = $CFILES[$i];
    $obj = preg_replace("/\.c$/", ".o", $file);
    echo("clean $obj\n");
    unlink $obj;
    $dep = preg_replace("/\.c$/", ".d", $file);
    echo("clean $dep\n");
    unlink $dep;
  }
  echo("clean $LIBSTATIC\n");
  unlink $LIBSTATIC;
  echo("clean $LIBSHARED\n");
  unlink $LIBSHARED;
  echo("clean $LIB\n");
  rmdir $LIB;
  opendir($din, $TST) or die "cannot open directory $TST";
  foreach $file (readdir($din)) {
    if ($file =~ /^((?!\.).)*\.c$/) {
      $TSTFILE = File::Spec->catfile($TST, $file); 
      $TSTTARGET = ($TSTFILE =~ s/\.c$/$TSTSUFFIX/r);
      echo("clean $TSTTARGET\n");
      unlink $TSTTARGET;
    }
  }
  closedir($din);
} elseif ($args[0] == "help") {
  echo($_SERVER['SCRIPT_NAME'] . " <target>\n");
  echo("<target>: \n");
  echo("                    compile cgraph\n");
  echo("          test      test cgraph\n");
  echo("          clean     clean all the generated files\n");
  echo("          distclean clean all the generated files and directories\n");
  echo("          help      commands to this program\n");
} else {
  echo("$args[0] is an unsupported command\n");
  echo("use \"$0 help\" to know all supported commands\n");
}

?>