#The prime factors of 13195 are 5, 7, 13 and 29.
#What is the largest prime factor of the number 600851475143 ?
use strict;

my $num = 600851475143;
#my $num = 5289978;
my $lastFactor;
my $factor;

if (!($num % 2)) {
    $num = $num / 2;
    $lastFactor = 2;
    while (!($num % 2)) {
	$num = $num / 2;
    }
} else {
    $lastFactor = 1;
}
$factor = 3;
while ($num > 1) {
    if (!($num % $factor)) {
	print "factor is $factor, num is $num\n";
	$num = $num / $factor;
	$lastFactor = $factor;
	while (!($num % $factor)) {
	    $num = $num / $factor;
	}
    }
    $factor = $factor + 2;
}
print "Largest prime factor is $lastFactor\n";
