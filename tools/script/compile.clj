#!/usr/bin/env lein-exec

(import '(java.io File))

(def PRO "cgraph")
(def DIR ".")
(def INC (str DIR File/separator "include"))
(def SRC (str DIR File/separator "src"))
(def SRC_TYPE (str SRC File/separator "type"))
(def TST (str DIR File/separator "tests"))
(def LIB (str DIR File/separator "lib"))

(def CC "cc")
(def CFLAGS "-std=c89 -Wall -pedantic -fPIC")
(def CSFLAGS "-shared")

(def CFLAGS (if (not (compare CC "tcc")) (str CFLAGS " -pedantic-errors")))

(def MODE "debug")
(def CFLAGS (if (compare MODE "debug") (str CFLAGS " -g -DDEBUG -O0") (if (compare MODE "release") (str CFLAGS " -O2"))))

(def AR "ar")
(def ARFLAGS "-rcs")

(def FILES (file-seq (clojure.java.io/file SRC)))
(def CFILES (filter FILES #(.isFile %)))
