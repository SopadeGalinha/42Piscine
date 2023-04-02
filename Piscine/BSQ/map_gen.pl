#!/usr/bin/perl
use warnings;
use strict;
die "program y density" unless (scalar(@ARGV) == 2);
my ($y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $y; $j++) {
if (int(rand($y) * 2) < $density) {
    print "o";
}
else {
print "."; }
}
print "\n"; }