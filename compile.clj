#!/usr/bin/env lein-exec

(def PRO "cgraph")
(def DIR ".")
(def INC (str DIR "/" "include"))
(def SRC (str DIR "/" "src"))
(def TST (str DIR "/" "test"))
(def LIB (str DIR "/" "lib"))

(def CC "cc")
(def CFLAGS "-pedantic -Wall -fpic -std=c89")
(def CSFLAGS "-shared")

(def MODE "debug")
(def CFLAGS (if (compare MODE "debug") (str CFLAGS " -g -DDEBUG") (if (compare MODE "release") (str CFLAGS " -static -O2"))))

(def AR "ar")
(def ARFLAGS "-rcs")