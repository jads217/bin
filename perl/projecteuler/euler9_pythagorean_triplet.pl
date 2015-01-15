#A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
#a2 + b2 = c2
#
#For example, 32 + 42 = 9 + 16 = 25 = 52.
#
#There exists exactly one Pythagorean triplet for which a + b + c = 1000.
#Find the product abc.

use strict;

for (my $a = 1; $a < 333; $a++) {
    for (my $b = $a+1; $b < (1000-$a-$b); $b++) {
	my $c = 1000 - $a - $b;
	if (($a*$a+$b*$b) == $c*$c) {
	    my $sum = $a * $b * $c;
	    print "a = $a, b = $b, c = $c, sum = $sum\n";
	}
    }
}
