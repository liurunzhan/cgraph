#!/usr/bin/env lein-exec

(import '(java.io File))

(def PRO "cgraph")
(def DIR ".")
(def INC (str DIR File/separator "include"))
(def SRC (str DIR File/separator "src"))
(def TST (str DIR File/separator "test"))
(def LIB (str DIR File/separator "lib"))

(def CC "cc")
(def CFLAGS "-std=c89 -Wall -pedantic")
(def CSFLAGS "-shared")

(def CFLAGS (if (not (compare CC "tcc")) (str CFLAGS " -pedantic-errors")))

(def CFLAGS (str CFLAGS " -fPIC"))

(def MODE "debug")
(def CFLAGS (if (compare MODE "debug") (str CFLAGS " -g -DDEBUG") (if (compare MODE "release") (str CFLAGS " -static -O2"))))

(def AR "ar")
(def ARFLAGS "-rcs")

(def FILES (file-seq (clojure.java.io/file SRC)))
(def CFILES (filter FILES #(.isFile %)))