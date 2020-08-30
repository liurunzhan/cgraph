#!/usr/bin/env groovy

def PRO = "cgraph"
def DIR = "."
def SRC = "$DIR/src"
def INC = "$DIR/include"
def TST = "$DIR/test"
def LIB = "$DIR/lib"

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