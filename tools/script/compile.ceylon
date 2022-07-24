#!/bin/sh
exec ceylon run "$0" "$@"
!#

String PRO = "cgraph";
String DIR = ".";
String INC = File.join(DIR, "include");
String SRC = File.join(DIR, "src");
String SRC_TYPE = File.join(SRC, "type");
String TST = File.join(DIR, "tests");
String LIB = File.join(DIR, "lib");