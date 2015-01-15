#By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
#What is the 10 001st prime number?
use strict;

#we know that 2 is prime and no other even number will be prime so we start at 3 with a count of 1 and increment by 2
my $num = 3;
my $count = 1;
my $limit = 10001;

while ($count < $limit) {
    if (is_prime($num)) {
        $count = $count + 1;
#        print "$num is prime. Count is $count\n";
		}
		if ($count == $limit) {
				print "The $limit prime number is $num\n";
		}
		$num = $num + 2;
}

#check that given number is a prime number by dividing it by every possible divisor
sub is_prime {
		my $prime_div;
		my $prime_factor;
		for ($prime_div = 2; $prime_div < ((int $num / 2) + 1); $prime_div++) {
				if (!($num % $prime_div)) {
						$prime_factor = $num / $prime_div;
#						print "$num has at least one factor, e.g. $prime_factor\n";
						return 0;
				}
		}
#		print "$num is prime.\n";
		return 1;
}
