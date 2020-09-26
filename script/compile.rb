#!/usr/bin/ruby -w

$PRO = "cgraph"
$DIR = "."
$INC = File.join($DIR, "include")
$SRC = File.join($DIR, "src")
$TST = File.join($DIR, "test")
$LIB = File.join($DIR, "lib")

$CC = "cc"
$CFLAGS = "-pedantic -Wall -fpic -std=c89"
$CSFLAGS = "-shared"

$MODE = "debug"
if $MODE == "debug" then
  $CFLAGS = "#{$CFLAGS} -g -DDEBUG"
elsif $MODE == "release" then
  $CFLAGS = "#{$CFLAGS} -static -O2"
end

# package shared library
$AR = "ar"
$ARFLAGS = "-rcs"

if RbConfig::CONFIG["host_os"] == "mswin" || RbConfig::CONFIG["host_os"] == "mingw"
  # target files
  $LIBSHARED = File.join($LIB, "lib#{$PRO}.dll")
  $LIBSTATIC = File.join($LIB, "lib#{$PRO}.a")
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

$CFILES = []
Dir.foreach($SRC) do |file|
  if File.extname(file) =~ /.c$/
    $CFILES << File.join($SRC, file)
  end
end

$args = ARGV
if $args.size == 0
  if not File.directory?($LIB)
    Dir::mkdir($LIB)
  end
  $OFILES = []
  for $file in $CFILES do
    $obj = $file.sub(".c", ".o")
    puts("compile #{$file} to #{$obj}")
    system("#{$CC} #{$CFLAGS} -I#{$INC} -c #{$file} -o #{$obj}")
    $OFILES << $obj
  end
  puts("compile #{$LIBSHARED}")
  system("#{$CC} #{$CSFLAGS} -o #{$LIBSHARED} #{$OFILES.join(" ")}")
  puts("compile #{$LIBSTATIC}")
  system("#{$AR} #{$ARFLAGS} #{$LIBSTATIC} #{$OFILES.join(" ")}")
elsif $args[0] == "test"
  puts("compile #{$TSTFILE} to #{$TSTTARGET}")
  system("#{$CC} #{$CFLAGS} -I#{$INC} -o #{$TSTTARGET} #{$TSTFILE} -L#{$LIB} -static -l#{$PRO} -lm")
  puts("test #{$TSTTARGET} with #{File.join($TST, "elements.csv")}")
  system("#{$TSTTARGET} #{File.join($TST, "elements.csv")}")
elsif $args[0] == "clean"
  for $file in $CFILES do
    $obj = $file.sub(".c", ".o")
    if File::exist?($obj)
      puts("clean #{$obj}")
      File::delete($obj)
    end
  end
  if File::exist?($LIBSTATIC)
    puts("clean #{$LIBSTATIC}")
    File::delete($LIBSTATIC)
  end
  if File::exist?($LIBSHARED)
    puts("clean #{$LIBSHARED}")
    File::delete($LIBSHARED)
  end
  if File::exist?($TSTTARGET)
    puts("clean #{$TSTTARGET}")
    File::delete($TSTTARGET)
  end
elsif $args[0] == "distclean"
  for $file in $CFILES do
    $obj = $file.sub(".c", ".o")
    if File::exist?($obj)
      puts("clean #{$obj}")
      File::delete($obj)
    end
  end
  if File::exist?($LIBSTATIC)
    puts("clean #{$LIBSTATIC}")
    File::delete($LIBSTATIC)
  end
  if File::exist?($LIBSHARED)
    puts("clean #{$LIBSHARED}")
    File::delete($LIBSHARED)
  end
  if Dir::exist?($LIB)
    puts("clean #{$LIB}")
    Dir::rmdir($LIB)
  end
  if File::exist?($TSTTARGET)
    puts("clean #{$TSTTARGET}")
    File::delete($TSTTARGET)
  end
elsif $args[0] == "help"
  puts("#{__FILE__} <target>")
  puts("<target>: ")
  puts("                    compile cgraph")
  puts("          test      test cgraph\n")
  puts("          clean     clean all the generated files")
  puts("          distclean clean all the generated files and directories")
  puts("          help      commands to this program")
else
  puts("#{$args[0]} is an unsupported command")
  puts("use \"#{__FILE__} help\" to know all supported commands")
end