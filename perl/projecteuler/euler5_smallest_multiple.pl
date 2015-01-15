#!/usr/bin/env perl
#2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
#What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
use strict;

#really slow method
my $number;
#for ($number = 20; $number > 0; $number = $number + 2) {
#    my $remainder = 0;
#    my $divisor = 2;
#    while ($remainder == 0 && $divisor < 21) {
#	$remainder = ($number % $divisor);
#	$divisor++;
#    }
#    if ($remainder == 0) {
#	print "The smallest multiple is $number\n";
#	$number = -1;
#	exit;
#    }
#    elsif ($divisor > 15) {
#	print "Number = $number Divisor = $divisor Remainder = $remainder\n";
#    }
#}

#efficient method
my @p = (1, 2, 3, 5, 7, 11, 13, 17, 19, 23); #array of primes required
my @a;
my $k = 20;
my $N = 1;
my $i = 1;
my $check = 1;
my $limit = sqrt($k);
while ($p[$i] <= $k) {
    $a[$i] = 1;
    if ($check == 1) {
	if ($p[$i] <= $limit) {
	    $a[$i] = int(log($k)/log($p[$i]));
	} else {
	    $check = 0;
	}
    }
    print "N= $N, p of $i = $p[$i], a of $i = $a[$i]\n";
    $N = $N * (($p[$i])**($a[$i]));
    $i++;
}
print "The smallest multiple is $N\n";
