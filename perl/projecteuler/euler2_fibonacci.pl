#!/usr/bin/env perl
#Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
#1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
#By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
use strict;

my $fib = 2;
my $prevFib = 1;
my $nextFib;
my $sum = 0;

while ($fib <= 4000000) {
    if (!($fib % 2)) {
	print "$fib is even\n";
	$sum = $sum + $fib;
    }
    $nextFib = $fib + $prevFib;
    $prevFib = $fib;
    $fib = $nextFib;
}
print "Final sum is $sum\n";
