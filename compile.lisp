#!/usr/bin/clisp

(setq PRO "cgraph")
(setq DIR (pathname-directory "."))
(setq SRC (merge-pathnames "src" DIR))
(setq INC (merge-pathnames "include" DIR))
(setq TST (merge-pathnames "test" DIR))
(setq LIB (merge-pathnames "lib" DIR))

(setq CC "cc")
(setq CFLAGS "-pedantic -Wall -fpic -std=c89")
(setq CSFLAGS "-shared")

(setq MODE "debug")
(if (equal MODE "debug") (setq CFLAGS (concatenate 'string CFLAGS " -g -DDEBUG")) (if (equal MODE "release") (setq CFLAGS (concatenate 'string CFLAGS " -static -O2"))))
