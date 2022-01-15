#!/usr/bin/perl

use strict;
use warnings;

my @args = @ARGV;

my $plat = "none";
my $cc   = "cc";
my $std  = "c89";
my $mode = "debug";

my %plats = ("none" => "all", "linux" => "all", "wsl" => "all", "cygwin" => "cygwin", "msys" => "msys", "msys2" => "msys2", "mingw" => "mingw32", "windows" => 7);
my %ccs   = (
  "all" => {"cc" => 0, "gcc" => 1, "clang" => 2, "tcc" => 3}, 
  "mingw32" => {"mingw32-gcc" => 4}, 
  "msys2" => {"mingw-w64-i686-gcc" => 5, "mingw-w64-x86_64-gcc" => 6, "mingw-w64-cross-gcc" => 7}, 
  "cygwin" => {"cygwin32-gcc" => 8, "cygwin64-gcc" => 9, "mingw64-i686-gcc" => 10, "mingw64-x86_64-gcc" => 11}
);
my %stdcs = (
	"c89" => 1989,
	"c90" => 1990,
	"c99" => 1999,
	"c11" => 2011,
	"c17" => 2017
);
my %gnucs = (
	"gnu89" => 1989,
	"gnu90" => 1990,
	"gnu99" => 1999,
	"gnu11" => 2011,
	"gnu17" => 2017
);

if($#args == -1) {
  print("none command line arguments are input!\n");
  print("use following command to get help and all supported commands!\n");
  print("$0 --help\n");
  exit(1);
}

my $i = 0;
while($i <= $#args) {
  if($args[$i] eq "--plat") {
    if($i >= $#args) {
			print("do not give platform after $args[$i]!\n");
			exit(-1);
		}
		$i += 1;
		if(exists($plats{$args[$i]})) {
			$plat = $args[$i];
		} elsif($args[$i] eq "--help") {
      print("argument $args[$i] supports:\n");
      foreach my $key (sort{$plats{$a} <=> $plats{$b}} keys %plats) {
				print("    $key\n");
			}
      exit(0);
    } else {
			print("set unsupported platform -- $args[$i]!\n");
			print("please use $args[$i] --help to get all supported platforms\n");
			exit(-1);
		}
  } elsif($args[$i] eq "--cc") {
    if($i >= $#args) {
			print("do not give c compiler after $args[$i]!\n");
			exit(-1);
		}
		$i += 1;``
		if(exists($ccs{$plats{$plat}}{$args[$i]})) {
			$cc = $args[$i];
		} elsif($args[$i] eq "--help") {
      print("argument --cc supports:\n");
      foreach my $plat (sort{$ccs{$a} <=> $ccs{$b}} keys %ccs) {
        foreach my $cc (sort{$ccs{$plat}{$a} <=> $ccs{$plat}{$b}} keys %{$ccs{$plat}}) {
					print "    $plat => $cc\n";
				}
      }
      exit(0);
    } else {
 			print("set unsupported c compiler -- $args[$i]!\n");
			print("please use --cc --help to get all supported c compilers\n");
			exit(-1);
		}
  } elsif($args[$i] eq "--std") {
    if($i >= $#args) {
			print("do not give c standard after $args[$i]!\n");
			exit(-1);
		}
    $i += 1;
		if(exists($stdcs{$args[$i]})) {
			$std = $args[$i];
		} elsif(exists($gnucs{$args[$i]})) {
			$std = $args[$i];
		} elsif($args[$i] eq "--help") {
      print("argument --std supports:\n");
      foreach my $key (sort{$stdcs{$a} <=> $stdcs{$b}} keys %stdcs) {
				print("$key\n");
			}
      foreach my $key (sort{$gnucs{$a} <=> $gnucs{$b}} keys %gnucs) {
				print("$key\n");
			}
      exit(0);
    } else {
			print("set unsupported c standard with given compiler -- $args[$i] in $cc!\n");
			print("please use --std --help to get all supported standards\n");
			exit(-1);
		}
  } elsif($args[$i] eq "--mode") {
		if($i >= $#args) {
			print("do not give compilation mode after $args[$i]!\n");
			exit(-1);
		}
		$i += 1;
		if(($args[$i] eq "debug") || ($args[$i] eq "release")) {
			$mode = $args[$i];
		} elsif($args[$i] eq "--help") {
      print("argument --mode supports:\ndebug\nrelease\n");
      exit(0);
    } else {
			print("set unsupported compilation mode -- $args[$i]!\n");
			print("please use --mode --help to get all supported compilation modes\n");
			exit(-1);
		}
  } elsif($args[$i] eq "--help") {
    $i += 1;
    print("$args[0] supports following commands:\n");
		print("    --plat platform ()\n");
		print("    --cc   c compiler (gcc/clang/tcc)\n");
		print("    --std  c standard (c/gnu+89/90/99/11/17)\n");
		print("    --mode compilation mode (debug/release)\n");
    exit(0);
  } else {
    print("unsupported command line arguments are input!\n");
    print("use following command to get help and all supported commands!\n");
    print("$0 --help\n");
    exit(1);
  }
	$i += 1;
}

sub get_scripts {
  my ($Makefile) = @_;
  my %scripts = ();
  if(-e $Makefile) {
    open my $fin, "<", $Makefile or die "$Makefile is read error";
    while(<$fin>) {
      $_ =~ s/\r?\n//g;
      if($_ =~ /^SCRIPT/) {

			} elsif($_ =~ /^TOOL/) {

			}
    }
    close($fin);
  }

  return \%scripts;
}

sub replace_arguments {
  my ($script, $plat, $cc, $std, $mode) = @_;
  
}
