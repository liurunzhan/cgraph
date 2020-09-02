#!/usr/bin/env groovy

import java.io.*;
import groovy.io.FileType;

def PRO = "cgraph"
def DIR = "."
def SRC = DIR + File.separator + "src"
def INC = DIR + File.separator + "include"
def TST = DIR + File.separator + "test"
def LIB = DIR + File.separator + "lib"

def CC = "cc"
def CFLAGS = "-pedantic -Wall -fpic -std=c89"
def CSFLAGS = "-shared"

def MODE = "debug"
if (MODE == "debug")
{
  CFLAGS = CFLAGS + " -g -DDEBUG"
}
else if (MODE == "release")
{
  CFLAGS = CFLAGS + " -static -O2"
}

def AR = "ar"
def ARFLAGS = "-rcs"

def CFILES = []
def FILES = new File(SRC)
FILES.eachFileMatch(~/.*\.c$/) {
  File file -> CFILES.add(file)
}
