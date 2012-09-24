#!/usr/bin/perl -w

use v5.12;

use strict;
use Data::Dumper;

my @a=(1,2,3);
my @a2=(4,5,6);

my @b = (@a, @a2);
my @b2 = ([@a], [@a2]);

@a2 = ('a','b','c');

say @b;
say Dumper @b;
say Dumper @b2;
