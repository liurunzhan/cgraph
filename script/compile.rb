#!/usr/bin/ruby -w

$PRO = "cgraph"
$DIR = "."
$SRC = File.join($DIR, "src")
$INC = File.join($DIR, "include")
$TST = File.join($DIR, "test")
$LIB = File.join($DIR, "lib")

$CC = "cc"
$CFLAGS = "-pedantic -Wall -fpic -std=c89"
$CSFLAGS = "-shared"

$MODE = "debug"
if $MODE == "debug" then
  $CFLAGS = "$CFLAGS -g -DDEBUG"
elsif $MODE == "release" then
  $CFLAGS = "$CFLAGS -static -O2"
end

# package shared library
$AR = "ar"
$ARFLAGS = "-rcs"

$CFILES = Dir["*.c"]
print()

$args = ARGV
if $args.size == 0
  if not File.directory?($LIB)
    Dir::mkdir($LIB)
  end
  for $file in $CFILES do
    $obj = $file.sub!(".c$", ".o")
    puts("compile %s to %s", File.join($SRC, $file), File.join($SRC, $obj))
    system(puts("$CC $CFLAGS -I$INC -c %s -o %s", File.join($SRC, $file), File.join($SRC, $obj)))
  end
  puts("compile $LIBSHARED")
  system(sprintf("$CC $CSFLAGS -o $LIBSHARED %s/*.o", $SRC))
  puts("compile $LIBSTATIC")
  system(sprintf("$AR $ARFLAGS $LIBSTATIC %s/*.o", $SRC))
elsif $args[0] == "test"
  puts("compile $TSTFILE to $TSTTARGET")
  system("$CC $CFLAGS -I$INC -o $TSTTARGET $TSTFILE -L$LIB -static -l$PRO -lm")
  printf("test $TSTTARGET with %s", File.join($TST, "elements.csv"))
  system(sprintf("$TSTTARGET %s", File.join($TST, "elements.csv")))
elsif $args[0] == "clean"
  for $file in $CFILES do
    $obj = $file.sub!(".c$", ".o")
    puts("clean $obj")
    File::delete(File.join($SRC, $obj))
  end
  puts("clean $LIBSTATIC")
  File::delete($LIBSTATIC)
  puts("clean $LIBSHARED")
  File::delete($LIBSHARED)
  puts("clean $TSTTARGET")
  File::delete($TSTTARGET)
elsif $args[0] == "distclean"
  for $file in $CFILES do
    my $obj = $file.sub!(".c$", ".o")
    puts("clean $obj")
    File::delete(File.join($SRC, $obj))
  end
  puts("clean $LIBSTATIC")
  File::delete($LIBSTATIC)
  puts("clean $LIBSHARED")
  File::delete($LIBSHARED)
  puts("clean $LIB")
  Dir::rmdir($LIB)
  puts("clean $TSTTARGET")
  File::delete($TSTTARGET)
elsif $args[0] == "help"
  puts("__FILE__ <target>")
  puts("<target>: ")
  puts("                    compile cgraph")
  puts("          test      test cgraph\n")
  puts("          clean     clean all the generated files")
  puts("          distclean clean all the generated files and directories")
  puts("          help      commands to this program")
else
  puts("$args[0] is an unsupported command")
  printf("use \"%s help\" to know all supported commands", __FILE__)
end