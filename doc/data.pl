#!/usr/bin/perl -w

use strict;
use warnings;
use File::Spec;

my $root = "..";
my $include = File::Spec->catfile($root, "include");

opendir (my $din, $include) or die "$include cannot be read";
my @files = readdir($din);
closedir($din);

foreach my $file (@files) 
{
  my $path = File::Spec->catfile($include, $file);
  if((-f $path) && ($file !~ /^\./))
  {  print($path); }
}