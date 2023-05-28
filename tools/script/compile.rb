#!/usr/bin/ruby -w

# Date : 2022-07-01
# A script to compile Library cgraph in Unix-like and Windows Platforms
# gets source files iteratively from Directory src

$PRO = "cgraph"
$DIR = "."
$INC = File.join($DIR, "include")
$SRC = File.join($DIR, "src")
$SRC_TYPE = File.join($SRC, "type")
$TST = File.join($DIR, "tests")
$LIB = File.join($DIR, "lib")

$CC = "cc"
$CFLAGS = "-std=c89 -Wall -pedantic -fPIC"
$CSFLAGS = "-shared"

$MODE = "debug"
if $MODE == "debug" then
  $CFLAGS = "#{$CFLAGS} -g -DDEBUG -O0"
elsif $MODE == "release" then
  $CFLAGS = "#{$CFLAGS} -O2"
end

# package shared library
$AR = "ar"
$ARFLAGS = "-rcs"

# source files
# get all subdirectories
def getsubdirs(path, dirs)
  Dir.foreach(path) do |item|
    subpath = File.join(path, item)
    if File::directory?(subpath) && !(File::basename(item) =~ /^\./)
      dirs << subpath
      getsubdirs(subpath, dirs)
    end
  end
end

$SRCS = []
getsubdirs($SRC, $SRCS)

# get all source files from subdirectories
$CFILES = []
for dir in $SRCS do
  Dir.foreach(dir) do |item|
    subpath = File.join(dir, item)
    if File::file?(subpath) && (File.basename(item) =~ /^((?!\.).)*\.c$/)
      $CFILES << subpath
    end
  end
end

if RbConfig::CONFIG["host_os"] == "mswin" || RbConfig::CONFIG["host_os"] == "mingw"
  # target files
  $LIBSHARED = File.join($LIB, "lib#{$PRO}.dll")
  $LIBSTATIC = File.join($LIB, "lib#{$PRO}.lib")
  # test files
  $TSTFILE = File.join($TST, "#{$PRO}.c")
  $TSTTARGET = File.join($TST, "#{$PRO}.exe")
else
  # target files
  $LIBSHARED = File.join($LIB, "lib#{$PRO}.so")
  $LIBSTATIC = File.join($LIB, "lib#{$PRO}.a")
  # test files
  $TSTFILE = File.join($TST, "#{$PRO}.c")
  $TSTTARGET = File.join($TST, $PRO)
end

args = ARGV
if args.size == 0
  if not File.directory?($LIB)
    Dir::mkdir($LIB)
  end
  $OFILES = []
  for file in $CFILES do
    obj = file.sub(/\.c$/, ".o")
    dep = file.sub(/\.c$/, ".d")
    puts("compile #{file} to #{obj}")
    system("#{$CC} #{$CFLAGS} -I#{$INC} -I#{$SRC_TYPE} -c #{file} -o #{obj} -MD -MF #{dep}")
    $OFILES << obj
  end
  puts("compile #{$LIBSHARED}")
  system("#{$CC} #{$CSFLAGS} -o #{$LIBSHARED} #{$OFILES.join(" ")}")
  puts("compile #{$LIBSTATIC}")
  system("#{$AR} #{$ARFLAGS} #{$LIBSTATIC} #{$OFILES.join(" ")}")
elsif args[0] == "test"
  puts("compile #{$TSTFILE} to #{$TSTTARGET}")
  system("#{$CC} #{$CFLAGS} -I#{$INC} -o #{$TSTTARGET} #{$TSTFILE} -L#{$LIB} -static -l#{$PRO} -lm")
  puts("test #{$TSTTARGET} with #{File.join($TST, "elements.csv")}")
  system("#{$TSTTARGET} #{File.join($TST, "elements.csv")}")
elsif args[0] == "clean"
  for file in $CFILES do
    obj = file.sub(/\.c$/, ".o")
    puts("clean #{obj}")
    if File::exist?(obj)
      File::delete(obj)
    end
    dep = file.sub(/\.c$/, ".d")
    puts("clean #{dep}")
    if File::exist?(dep)
      File::delete(dep)
    end
  end
  puts("clean #{$LIBSTATIC}")
  if File::exist?($LIBSTATIC)
    File::delete($LIBSTATIC)
  end
  puts("clean #{$LIBSHARED}")
  if File::exist?($LIBSHARED)
    File::delete($LIBSHARED)
  end
  puts("clean #{$TSTTARGET}")
  if File::exist?($TSTTARGET)
    File::delete($TSTTARGET)
  end
elsif args[0] == "distclean"
  for file in $CFILES do
    obj = $file.sub(/\.c$/, ".o")
    puts("clean #{obj}")
    if File::exist?(obj)
      File::delete(obj)
    end
    dep = $file.sub(/\.c$/, ".d")
    puts("clean #{dep}")
    if File::exist?(dep)
      File::delete(dep)
    end
  end
  puts("clean #{$LIBSTATIC}")
  if File::exist?($LIBSTATIC)
    File::delete($LIBSTATIC)
  end
  puts("clean #{$LIBSHARED}")
  if File::exist?($LIBSHARED)
    File::delete($LIBSHARED)
  end
  puts("clean #{$LIB}")
  if Dir::exist?($LIB)
    Dir::rmdir($LIB)
  end
  puts("clean #{$TSTTARGET}")
  if File::exist?($TSTTARGET)
    File::delete($TSTTARGET)
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
