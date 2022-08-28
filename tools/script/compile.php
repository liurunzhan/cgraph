#!/usr/bin/env -S php -f
<?php

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

declare(strict_types=1);

$PRO = "cgraph";
$DIR = ".";
$INC = $DIR . DIRECTORY_SEPARATOR . "include";
$SRC = $DIR . DIRECTORY_SEPARATOR . "src";
$SRC_TYPE = $SRC . DIRECTORY_SEPARATOR . "type";
$TST = $DIR . DIRECTORY_SEPARATOR . "tests";
$LIB = $DIR . DIRECTORY_SEPARATOR . "lib";

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

# source files
# get all subdirectories
function getsubdirs($path, &$dirs) {
  $din = opendir($path);
  while(false !== ($item=readdir($din))) {
    $subpath = $path . DIRECTORY_SEPARATOR . $item;
    if (is_dir($subpath) && !preg_match("/^\./", $item)) {
      array_push($dirs, $subpath);
      getsubdirs($subpath, $dirs);
    }
  }
  closedir($din);
}

# get all source files from subdirectories
$SRCS = array();
getsubdirs($SRC, $SRCS);

$CFILES = array();
for($i=0;$i<count($SRCS);$i++) {
  $dir = $SRCS[$i];
  $din = opendir($dir);
  while(false !== ($item=readdir($din))) {
    $subpath = $dir . DIRECTORY_SEPARATOR . $item;
    if (is_file($subpath) && preg_match("/^((?!\.).)*\.c$/", $item)) {
      array_push($CFILES, $subpath);
    }
  }
  closedir($din);
}

$LIBSHARED;
$LIBSTATIC;
$TSTSUFFIX;
if (PHP_OS == "WIN32" || PHP_OS == "winnt" || PHP_OS == "Windows") {
  # target files
  $LIBSHARED = $LIB . DIRECTORY_SEPARATOR .  "lib{$PRO}.dll";
  $LIBSTATIC = $LIB . DIRECTORY_SEPARATOR .  "lib{$PRO}.lib";
  # test files
  $TSTSUFFIX = ".exe";
} else {
  # target files
  $LIBSHARED = $LIB . DIRECTORY_SEPARATOR .  "lib{$PRO}.so";
  $LIBSTATIC = $LIB . DIRECTORY_SEPARATOR .  "lib{$PRO}.a";
  # test files
  $TSTSUFFIX = "";
}

$args = $argv;
if ($argc == 1) {
  if(!is_dir($LIB)) {
    mkdir($LIB);
  }
  $OFILES = array();
  for($i=0;$i<count($CFILES);$i++) {
    $file = $CFILES[$i];
    $obj = preg_replace("/\.c$/", ".o", $file);
    $dep = preg_replace("/\.c$/", ".d", $file);
    echo("compile {$file} to {$obj}\n");
    system("{$CC} {$CFLAGS} -I{$INC} -I{$SRC_TYPE} -c {$file} -o {$obj} -MD -MF {$dep}");
    array_push($OFILES, $obj);
  }
  echo("compile $LIBSHARED\n");
  system(sprintf("{$CC} {$CSFLAGS} -o {$LIBSHARED} %s", join(" ", $OFILES)));
  echo("compile $LIBSTATIC\n");
  system(sprintf("{$AR} {$ARFLAGS} {$LIBSTATIC} %s", join(" ", $OFILES)));
} elseif ($args[1] == "test") {
  $din = opendir($TST);
  while(false !== ($file=readdir($din))) {
    if (preg_match("/^((?!\.).)*\.c$/", $file)) {
      $TSTFILE = $TST . DIRECTORY_SEPARATOR . $file;
      $TSTTARGET = preg_replace("/\.c$/", $TSTSUFFIX, $TSTFILE);
      echo("compile $TSTFILE to $TSTTARGET\n");
      system("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm");
      echo("test $TSTTARGET\n");
      system($TSTTARGET);
    }
  }
  closedir($din);
} elseif ($args[1] == "clean") {
  for($i=0;$i<count($CFILES);$i++) {
    $file = $CFILES[$i];
    $obj = preg_replace("/\.c$/", ".o", $file);
    echo("clean {$obj}\n");
    unlink($obj);
    $dep = preg_replace("/\.c$/", ".d", $file);
    echo("clean {$dep}\n");
    unlink($dep);
  }
  echo("clean $LIBSTATIC\n");
  unlink($LIBSTATIC);
  echo("clean $LIBSHARED\n");
  unlink($LIBSHARED);
  $din = opendir($TST);
  while(false !== ($file=readdir($din))) {
    if (preg_match("/^((?!\.).)*\.c$/", $file)) {
      $TSTFILE = $TST . DIRECTORY_SEPARATOR . $file;
      $TSTTARGET = preg_replace("/\.c$/", $TSTSUFFIX, $TSTFILE);
      echo("clean {$TSTTARGET}\n");
      unlink($TSTTARGET);
    }
  }
  closedir($din);
} elseif ($args[1] == "distclean") {
  for($i=0;$i<count($CFILES);$i++) {
    $file = $CFILES[$i];
    $obj = preg_replace("/\.c$/", ".o", $file);
    echo("clean {$obj}\n");
    unlink($obj);
    $dep = preg_replace("/\.c$/", ".d", $file);
    echo("clean {$dep}\n");
    unlink($dep);
  }
  echo("clean {$LIBSTATIC}\n");
  unlink($LIBSTATIC);
  echo("clean {$LIBSHARED}\n");
  unlink($LIBSHARED);
  echo("clean {$LIB}\n");
  rmdir($LIB);
  $din = opendir($TST);
  while(false !== ($file=readdir($din))) {
    if (preg_match("/^((?!\.).)*\.c$/", $file)) {
       $TSTFILE = $TST . DIRECTORY_SEPARATOR . $file;
      $TSTTARGET = preg_replace("/\.c$/", $TSTSUFFIX, $TSTFILE);
      echo("clean {$TSTTARGET}\n");
      unlink($TSTTARGET);
    }
  }
  closedir($din);
} elseif ($args[1] == "help") {
  echo("{$_SERVER['SCRIPT_NAME']} <target>\n");
  echo("<target>: \n");
  echo("                    compile cgraph\n");
  echo("          test      test cgraph\n");
  echo("          clean     clean all the generated files\n");
  echo("          distclean clean all the generated files and directories\n");
  echo("          help      commands to this program\n");
} else {
  echo("{$args[1]} is an unsupported command\n");
  echo("use \"{$_SERVER['SCRIPT_NAME']} help\" to know all supported commands\n");
}

?>