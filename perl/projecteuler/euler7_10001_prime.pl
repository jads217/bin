#By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
#What is the 10 001st prime number?
use strict;

#we know that 2 is prime and no other even number will be prime so we start at 3 with a count of 1 and increment by 2
my $num = 1;
my $count = 1;
my $limit = 10001;

while ($count < $limit) {
    $num = $num + 2;
    if (is_prime($num)) {
        $count = $count + 1;
	print "$num is $count prime\n";
    }
}
print "The $limit prime number is $num\n";

#use definitions of prime number to quickly find out if given number is prime
sub is_prime {
    if ($num == 1) {
	return 0; #1 is not prime
    } elsif ($num < 4) {
	return 1; #2 and 3 are prime
    } elsif (!($num % 2)) {
	return 0; #divisible by 2, not prime
    } elsif ($num < 9) {
	return 1; #5, 7 are prime
    } elsif (!($num % 3)) {
	return 0; #divisible by 3, not prime
    } else {
	my $bound = int(sqrt($num)); #factor must be less than sqrt(num)
	my $prime_div = 5;
	my $test = 1;
	while (($prime_div <= $bound) && ($test == 1)) {
	    if (!($num % $prime_div) || !($num % ($prime_div+2))) {
		$test = 0;
		return 0;
	    }
	    $prime_div = $prime_div + 6;
	}
	return 1;
    }
}
