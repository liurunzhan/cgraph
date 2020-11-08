#!/usr/bin/perl

use strict;
use warnings;

my @args = @ARGV;

my $plat = "none";
my $cc   = "cc";
my $std  = "c89";
my $mode = "debug";

my %plats = ("none" => 0, "linux" => 1, "wsl" => 2, "cgywin" => 3, "msys" => 4, "msys2" => 5, "windows" => 6);
my %ccs   = (
  {"all" => {"cc" => 0, "gcc" => 1, "clang" => 2, "tcc" => 3}}, 
  {"mingw32" => {"mingw32-gcc" => 4}}, 
  {"msys2" => {"mingw-w64-i686-gcc" => 5, "mingw-w64-x86_64-gcc" => 6, "mingw-w64-cross-gcc" => 7}}, 
  {"cygwin" => {"cygwin32-gcc" => 8, "cygwin64-gcc" => 9, "mingw64-i686-gcc" => 10, "mingw64-x86_64-gcc" => 11}}
);
my %stdcs = ("c89" => 1989, "c90" => 1990, "c99" => 1999, "c11" => 2011);
my %gnucs = ("gnu89" => 1989, "gnu90" => 1990, "gnu99" => 1999, "gnu11" => 2011);

if($#args == -1)
{
  print("none command line arguments are input!\n");
  print("use following command to get help and all supported commands!\n");
  print("$0 --help\n");
  exit(1);
}

my $i = 0;
while($i <= $#args)
{
  if($args[$i] eq "--plat")
  {
    $i += 1;
    if(exists($plats{$args[$i]}))
    { $plat = $args[$i]; }
    elsif($args[$i] eq "--help")
    {
      exit(0);
    }
    else
    { print("set platform as default one, none!\n"); }
  }
  elsif($args[$i] eq "--cc")
  {
    $i += 1;
    if(exists($ccs{$args[$i]}))
    { $cc = $args[$i]; }
    elsif($args[$i] eq "--help")
    {
      exit(0);
    }
    else
    { print("set c compiler as default one, cc!\n"); }
  }
  if($args[$i] eq "--std")
  {
    $i += 1;
    if(exists($stdcs{$args[$i]}))
    { $std = $args[$i]; }
    elsif(exists($gnucs{$args[$i]}))
    { $std = $args[$i]; }
    elsif($args[$i] eq "--help")
    {
      print("argument --std supports:\n");
      foreach my $key (sort{$stdcs{$a} <=> $stdcs{$b}} keys %stdcs)
      { print("$key\n"); }
      foreach my $key (sort{$gnucs{$a} <=> $gnucs{$b}} keys %gnucs)
      { print("$key\n"); }
      exit(0);
    }
    else
    { print("set C standard as default one, c89!\n"); }
  }
  elsif($args[$i] eq "--mode")
  {
    $i += 1;
    if(($args[$i] eq "debug") || ($args[$i] eq "release"))
    { $mode = $args[$i]; }
    elsif($args[$i] eq "--help")
    {
      print("argument --mode supports:\ndebug\nrelease\n");
      exit(0);
    }
    else
    { print("set compilation mode as default one, debug!\n"); }
  }
  elsif($args[$i] eq "--help")
  {
    $i += 1;

    exit(0);
  }
  else
  {
    print("unsupported command line arguments are input!\n");
    print("use following command to get help and all supported commands!\n");
    print("$0 --help\n");
    exit(1);
  }
}

sub get_scripts
{
  my ($Makefile) = @_;
  my %scripts = ();
  if(-e $Makefile)
  {
    open my $fin, "<", $Makefile or die "$Makefile is read error!";
    while(<$fin>)
    {
      $_ =~ s/\r?\n//g;
      if($_ =~ /^SCRIPT/)
      { }
      elsif($_ =~ /^TOOL/)
      { }
    }
    close($fin);
  }

  return \%scripts;
}

sub replace_arguments
{
  my ($script, $plat, $cc, $std, $mode) = @_;
  
}