#!/usr/bin/crystal

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

PRO = "cgraph"
DIR = "."
INC = File.join(DIR, "include")
SRC = File.join(DIR, "src")
SRC_TYPE = File.join(SRC, "type")
TST = File.join(DIR, "test")
LIB = File.join(DIR, "lib")

CC = "cc"
_CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
CSFLAGS = "-shared"

MODE = "debug"
if MODE == "debug"
  _CFLAGS = "#{_CFLAGS} -g -DDEBUG"
elsif MODE == "release"
  _CFLAGS = "#{_CFLAGS} -static -O2"
end

# package shared library
AR = "ar"
ARFLAGS = "-rcs"

# source files
# get all subdirectories
def getsubdirs(path, dirs)
  Dir.each(path) do |item|
    subpath = File.join(path, item)
    if File.directory?(subpath) && !(File.basename(item) =~ /^\./)
      dirs << subpath
      getsubdirs(subpath, dirs)
    end
  end
end

SRCS = [] of String
getsubdirs(SRC, SRCS)

# get all source files from subdirectories
CFILES = [] of String
SRCS.each do |dir|
  Dir.each(dir) do |item|
    subpath = File.join(dir, item)
    if File.file?(subpath) && File.basename(item) =~ /^((?!\.).)*\.c$/
      CFILES << subpath
    end
  end
end

# target files
LIBSHARED = File.join(LIB, "lib#{PRO}.so")
LIBSTATIC = File.join(LIB, "lib#{PRO}.a")
# test files
_TSTFILE = File.join(TST, "#{PRO}.c")
_TSTTARGET = File.join(TST, PRO)

args = ARGV
if args.size == 0
  if !File.directory?(LIB)
    Dir.mkdir(LIB)
  end
  _OFILES = [] of String
  CFILES.each do |file|
    obj = file.sub("\.c", ".o")
    dep = file.sub("\.c", ".d")
    puts("compile #{file} to #{obj}")
    `#{CC} #{_CFLAGS} -I#{INC} -I#{SRC_TYPE} -c #{file} -o #{obj} -MD -MF #{dep}`
    _OFILES << obj
  end
  puts("compile #{LIBSHARED}")
  `#{CC} #{CSFLAGS} -o #{LIBSHARED} #{_OFILES.join(" ")}`
  puts("compile #{LIBSTATIC}")
  `#{AR} #{ARFLAGS} #{LIBSTATIC} #{_OFILES.join(" ")}`
elsif args[0] == "test"
  puts("compile #{_TSTFILE} to #{_TSTTARGET}")
  `#{CC} #{_CFLAGS} -I#{INC} -o #{_TSTTARGET} #{_TSTFILE} -L#{LIB} -static -l#{PRO} -lm`
  puts("test #{_TSTTARGET} with #{File.join(TST, "elements.csv")}")
  `#{_TSTTARGET} #{File.join(TST, "elements.csv")}`
elsif args[0] == "clean"
  CFILES.each do |file|
    obj = file.sub("\.c", ".o")
    puts("clean #{obj}")
    if File.exists?(obj)
      File.delete(obj)
    end
    dep = file.sub("\.c", ".d")
    puts("clean #{dep}")
    if File.exists?(dep)
      File.delete(dep)
    end
  end
  puts("clean #{LIBSTATIC}")
  if File.exists?(LIBSTATIC)
    File.delete(LIBSTATIC)
  end
  puts("clean #{LIBSHARED}")
  if File.exists?(LIBSHARED)
    File.delete(LIBSHARED)
  end
  puts("clean #{_TSTTARGET}")
  if File.exists?(_TSTTARGET)
    File.delete(_TSTTARGET)
  end
elsif args[0] == "distclean"
  CFILES.each do |file|
    obj = file.sub("\.c", ".o")
    puts("clean #{obj}")
    if File.exists?(obj)
      File.delete(obj)
    end
    dep = file.sub("\.c", ".d")
    puts("clean #{dep}")
    if File.exists?(dep)
      File.delete(dep)
    end
  end
  puts("clean #{LIBSTATIC}")
  if File.exists?(LIBSTATIC)
    File.delete(LIBSTATIC)
  end
  puts("clean #{LIBSHARED}")
  if File.exists?(LIBSHARED)
    File.delete(LIBSHARED)
  end
  puts("clean #{LIB}")
  if Dir.exists?(LIB)
    Dir.delete(LIB)
  end
  puts("clean #{_TSTTARGET}")
  if File.exists?(_TSTTARGET)
    File.delete(_TSTTARGET)
  end
elsif args[0] == "help"
  puts("#{__FILE__} <target>")
  puts("<target>: ")
  puts("                    compile cgraph")
  puts("          test      test cgraph\n")
  puts("          clean     clean all the generated files")
  puts("          distclean clean all the generated files and directories")
  puts("          help      commands to this program")
else
  puts("#{args[0]} is an unsupported command")
  puts("use \"#{__FILE__} help\" to know all supported commands")
end