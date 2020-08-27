#!/usr/bin/perl -w

use strict;
use warnings;
use File::Spec;

my $root = "..";
my $include = File::Spec->catfile($root, "include");

opendir (my $din, $include) or die "$include cannot be read!";
my @files = readdir($din);
closedir($din);

my %headers = ();

foreach my $file (@files) 
{
  my $path = File::Spec->catfile($include, $file);
  if((-f $path) && ($file !~ /^\./))
  {
    if(!exists($headers{$file}))
    { $headers{$file} = ""; }
    open my $fin, "<", $path or die "$path cannot be read";
    while(<$fin>)
    {
      $_ =~ s/\n$//g;
      $_ =~ s/\r$//g;
      $_ =~ s/^(\s+)//g;
      if($_ =~ /^#include(\s+)"(\S+)"/)
      { $headers{$file} = $headers{$file} . "$2,"; }
      elsif($_ =~ /^#include(\s+)\<(\S+)\>/)
      { $headers{$file} = $headers{$file} . "$2,"; }
    }
    close($fin);
    $headers{$file} =~ s/,$//g;
    print("$file,$headers{$file}\n");
  }
}