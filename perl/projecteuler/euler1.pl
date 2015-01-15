#!/usr/bin/env perl
#script that provides the sum of all natural numbers that are multiples of 3 or 5 between 0 and 1000
use strict;

my $limit = 999;
#iterative method
my $sum = 0;
for (my $i = 1; $i <= $limit; $i++) {
    if (!($i % 3) | !($i % 5)) {
	$sum = $sum + $i;
    }
}
print "Final sum is $sum\n";
#more efficient solution
$sum = 0;
my $n;
my $p;
sub SumDivisibleBy {
    $n = @_[0];
    print "n is $n\n";
    $p = int ($limit / $n);
    return ($n * ($p*($p+1)/2));
}
$sum = SumDivisibleBy(3) + SumDivisibleBy(5) - SumDivisibleBy(15);
print "Final sum is $sum\n";
