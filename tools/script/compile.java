//!/usr/bin/java --source 11

import java.util.List;
import java.util.ArrayList;
import java.io.File;
import java.lang.Runtime;

public class Compile {
  public static void main(String[] args) {
    String PRO = new String("cgraph");
    String DIR = new String(".");
    String INC = new String(DIR + File.separator + "include");
    String SRC = new String(DIR + File.separator + "src");
    String TST = new String(DIR + File.separator + "test");
    String LIB = new String(DIR + File.separator + "lib");

    String CC = new String("cc");
    StringBuffer CFLAGS = new StringBuffer("-std=c89 -Wall -pedantic -fPIC");
    String CSFLAGS = new String("-shared");

    String MODE = new String("debug");
    if (MODE.equals("debug")) {
      CFLAGS.append(" -g -DDEBUG");
    } else if (MODE.equals("release")) {
      CFLAGS.append(" -static -O2");
    }

    // package shared library
    String AR = new String("ar");
    String ARFLAGS = new String("-rcs");
    
    String OS = System.getProperty("os.name");
    String LIBSHARED, LIBSTATIC, TSTFILE, TSTTARGET;
    if(OS.matches("^[Ww]in")) {
      // target files
      LIBSHARED = new String(LIB + File.separator + "lib" + PRO + ".dll");
      LIBSTATIC = new String(LIB + File.separator + "lib" + PRO + ".lib");
      // test files
      TSTFILE = new String(TST + File.separator + PRO + ".c");
      TSTTARGET = new String(TST + File.separator + PRO + ".exe");
    } else {
      // target files
      LIBSHARED = new String(LIB + File.separator + "lib" + PRO + ".so");
      LIBSTATIC = new String(LIB + File.separator + "lib" + PRO + ".a");
      // test files
      TSTFILE = new String(TST + File.separator + PRO + ".c");
      TSTTARGET = new String(TST + File.separator + PRO);
    }
    
    List<File> CFILES = new ArrayList<File>();
    File[] FILES = new File(SRC).listFiles();
    for(File file : FILES) {
      if(file.isFile() && file.getName().endsWith(".c")) {
        CFILES.add(file);
      }
    }

    String SCRIPT_NAME = Thread.currentThread().getStackTrace()[1].getFileName();
    if (args.length == 0) {
      if(!(new File(LIB).exists())) {
        new File(LIB).mkdir();
      }
      List<String> OFILES = new ArrayList<String>();
      for(File file : CFILES) {
        try {
          String obj = file.getPath().replace(".c", ".o");
          String dep = file.getPath().replace(".c", ".d");
          String cmd = String.format("%s %s -I%s -c %s -o %s -MD -MF %s", CC, CFLAGS, INC, file, obj, dep);
          System.out.println(String.format("compile %s to %s", file, obj));
          Process program = Runtime.getRuntime().exec(cmd);
          OFILES.add(obj);
        } catch (Exception e) {
          String obj = file.getPath().replace(".c", ".o");
          System.out.println(String.format("compile %s to %s error!", file, obj));
        }
      }
      try {
        String cmd = String.format("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, String.join(" ", OFILES));
        System.out.println(String.format("compile %s", LIBSHARED));
        Process program = Runtime.getRuntime().exec(cmd);
      } catch (Exception e) {
        System.out.println(String.format("compile *.o to %s error!", LIBSHARED));
      }
      try {
        String cmd = String.format("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, String.join(" ", OFILES));
        System.out.println(String.format("compile %s", LIBSTATIC));
        Process program = Runtime.getRuntime().exec(cmd);
      } catch (Exception e) {
        System.out.println(String.format("compile *.o to %s error!", LIBSTATIC));
      }
    } else if (args[0].equals("test")) {
      try {
        String cmd = String.format("%s %s -I%s -o %s %s -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO);
        System.out.println(String.format("compile %s to %s", TSTFILE, TSTTARGET));
        Process program = Runtime.getRuntime().exec(cmd);
      } catch (Exception e) {
        System.out.println(String.format("compile %s to %s error!", TSTFILE, TSTTARGET));
      }
      try {
        String cmd = String.format("%s %s", TSTTARGET, TST + File.separator + "elements.csv");
        System.out.println(String.format("test %s with %s", TSTTARGET, TST + File.separator + "elements.csv"));
        Process program = Runtime.getRuntime().exec(cmd);
      } catch (Exception e) {
        System.out.println(String.format("test %s with %s error!", TSTTARGET, TST + File.separator + "elements.csv"));
      }
    } else if (args[0].equals("clean")) {
      for(File file : CFILES) {
        File obj = new File(file.getPath().replace(".c", ".o"));
        System.out.println(String.format("clean %s", obj));
        obj.delete();
        File dep = new File(file.getPath().replace(".c", ".d"));
        System.out.println(String.format("clean %s", dep));
        dep.delete();
      }
      System.out.println(String.format("clean %s", LIBSTATIC));
      File libstatic = new File(LIBSTATIC);
      libstatic.delete();
      System.out.println(String.format("clean %s", LIBSHARED));
      File libshared = new File(LIBSHARED);
      libshared.delete();
      System.out.println(String.format("clean %s", TSTTARGET));
      File tsttarget = new File(TSTTARGET);
      tsttarget.delete();
    } else if (args[0].equals("distclean")) {
      for(File file : CFILES) {
        File obj = new File(file.getPath().replace(".c", ".o"));
        System.out.println(String.format("clean %s", obj));
        obj.delete();
        File dep = new File(file.getPath().replace(".c", ".d"));
        System.out.println(String.format("clean %s", dep));
        dep.delete();
      }
      System.out.println(String.format("clean %s", LIBSTATIC));
      File libstatic = new File(LIBSTATIC);
      libstatic.delete();
      System.out.println(String.format("clean %s", LIBSHARED));
      File libshared = new File(LIBSHARED);
      libshared.delete();
      System.out.println(String.format("clean %s", LIB));
      File lib = new File(LIB);
      lib.delete();
      System.out.println(String.format("clean %s", TSTTARGET));
      File tsttarget = new File(TSTTARGET);
      tsttarget.delete();
    } else if (args[0].equals("help")) {
      System.out.println(SCRIPT_NAME +" <target>");
      System.out.println("<target>: ");
      System.out.println("                    compile cgraph");
      System.out.println("          test      test cgraph");
      System.out.println("          clean     clean all the generated files");
      System.out.println("          distclean clean all the generated files and directories");
      System.out.println("          help      commands to this program");
    } else {
      System.out.println(args[0] + " is an unsupported command");
      System.out.println("use \"" + SCRIPT_NAME + " help\" to know all supported commands");
    }
  }
}