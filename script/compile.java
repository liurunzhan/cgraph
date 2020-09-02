//!/usr/bin/java --source 11

import java.util.*;
import java.io.*;

public class Compile {
  public static void main(String[] args) {
    String PRO = new String("cgraph");
    String DIR = new String(".");
    String SRC = new String(DIR + File.separator + "src");
    String INC = new String(DIR + File.separator + "include");
    String TST = new String(DIR + File.separator + "test");
    String LIB = new String(DIR + File.separator + "lib");

    String CC = new String("cc");
    StringBuffer CFLAGS = new StringBuffer("-pedantic -Wall -fpic -std=c89");
    String CSFLAGS = new String("-shared");

    String MODE = new String("debug");
    if (MODE.equals("debug")) {
      CFLAGS.append(" -g -DDEBUG");
    }
    else if (MODE.equals("release")) {
      CFLAGS.append(" -static -O2");
    }

    // package shared library
    String AR = new String("ar");
    String ARFLAGS = new String("-rcs");

    List<File> CFILES = new ArrayList<File>();
    File[] FILES = new File(SRC).listFiles();
    for(File file : FILES) {
      if(file.isFile() && file.getName().endsWith(".c")) {
        CFILES.add(file);
      }
    }
  }
}