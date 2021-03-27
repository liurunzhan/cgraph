#!/usr/bin/rdmd

import std.algorithm;
import std.array;
import std.file;
import std.format;
import std.path;
import std.process;
import std.stdio;

int main(string[] args) {
	string PRO = "cgraph";
	string DIR = ".";
	string INC = buildPath(DIR, "include");
	string SRC = buildPath(DIR, "src");
	string TST = buildPath(DIR, "test");
	string LIB = buildPath(DIR, "lib");

	string CC = "cc";
	string CFLAGS = "-std=c89 -Wall -pedantic -fPIC";
	string CSFLAGS = "-shared";

	string MODE = "debug";
	if (MODE == "debug") {
		CFLAGS ~= " -g -DDEBUG";
	} else if (MODE == "release") {
		CFLAGS ~= " -static -O2";
	}

  // package shared library
	string AR = "ar";
	string ARFLAGS = "-rcs";

	version(Windows) {
		// target files
		string LIBSHARED = buildPath(LIB, "lib" ~ PRO ~ ".dll");
		string LIBSTATIC = buildPath(LIB, "lib" ~ PRO ~ ".a");
		// test files
		string TSTFILE = buildPath(TST, PRO ~ ".c");
		string TSTTARGET = buildPath(TST, PRO ~ ".exe");
	} else {
		// target files
		string LIBSHARED = buildPath(LIB, "lib" ~ PRO ~ ".so");
		string LIBSTATIC = buildPath(LIB, "lib" ~ PRO ~ ".a");
		// test files
		string TSTFILE = buildPath(TST, PRO ~ ".c");
		string TSTTARGET = buildPath(TST, PRO);
	}

	string[] CFILES = dirEntries(SRC, SpanMode.shallow).filter!(a => a.isFile).filter!(a => ".c" == a.extension).map!(a => a.name).array;

	if(1 == args.length) {
		LIB.mkdirRecurse;
		string[] OFILES;
		foreach (file; CFILES) {
			string obj = file.setExtension("o");
			writeln(format("compile %s to %s", file, obj));
			executeShell(format("%s %s -I%s -c %s -o %s", CC, CFLAGS, INC, file, obj));
			OFILES ~= [obj];
		}
  	writeln(format("compile %s", LIBSHARED));
  	executeShell(format("%s %s -o %s %s", CC, CSFLAGS, LIBSHARED, join(OFILES, " ")));
  	writeln(format("compile %s", LIBSTATIC));
  	executeShell(format("%s %s %s %s", AR, ARFLAGS, LIBSTATIC, join(OFILES, " ")));
	} else if("test" == args[1]) {
		writeln(format("compile %s to %s", TSTFILE, TSTTARGET));
		executeShell(format("%s %s -I%s -o %s %s -L%s -static -l%s -lm", CC, CFLAGS, INC, TSTTARGET, TSTFILE, LIB, PRO));
		writeln(format("test %s with %s", TSTTARGET, buildPath(TST, "elements.csv")));
		executeShell(format("%s %s", TSTTARGET, buildPath(TST, "elements.csv")));
	} else if("clean" == args[1]) {
		foreach (file; CFILES) {
			string obj = file.setExtension("o");
			writeln(format("clean %s", obj));
			if(obj.exists) {
				obj.remove;
			}
		}
		writeln(format("clean %s", LIBSTATIC));
		if(LIBSTATIC.exists) {
			LIBSTATIC.remove;
		}
		writeln(format("clean %s", LIBSHARED));
		if(LIBSHARED.exists) {
			LIBSHARED.remove;
		}
		writeln(format("clean %s", TSTTARGET));
		if(TSTTARGET.exists) {
			TSTTARGET.remove;
		}
	} else if("distclean" == args[1]) {
		foreach (file; CFILES) {
			string obj = file.setExtension("o");
			writeln(format("clean %s", obj));
			if(obj.exists) {
				obj.remove;
			}
		}
		writeln(format("clean %s", LIBSTATIC));
		if(LIBSTATIC.exists) {
			LIBSTATIC.remove;
		}
		writeln(format("clean %s", LIBSHARED));
		if(LIBSHARED.exists) {
			LIBSHARED.remove;
		}
		writeln(format("clean %s", LIB));
		if(LIB.exists) {
			LIB.rmdir;
		}
		writeln(format("clean %s", TSTTARGET));
		if(TSTTARGET.exists) {
			TSTTARGET.remove;
		}
	} else if("help" == args[1]) {
		writeln(format("%s <target>", args[0]));
		writeln("<target>: ");
		writeln("                    compile cgraph");
		writeln("          test      test cgraph");
		writeln("          clean     clean all the generated files");
		writeln("          distclean clean all the generated files and directories");
		writeln("          help      commands to this program");
	} else {
		writeln(format("%s is an unsupported command", args[1]));
		writeln(format("use \"%s help\" to know all supported commands", args[0]));
	}

	return 0;
}