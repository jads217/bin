#The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#Find the sum of all the primes below two million.
use strict;

#we initialize with 2 as the first prime number
my $sum = 2;
my $limit = 2000000;
my @primeArray = [2];

for (my $i = 3; $i < $limit; ($i=$i+2)) {
    #check if number is prime by dividing it against all previously discovered primes
    my $isPrime = 1; #start with assumption that number is prime
    my $arrayIndex = 0;
    while (($primeArray[$arrayIndex]) && ($isPrime == 1)) {
	if ($i % $primeArray[$arrayIndex]) {
	    #does not divide evenly try the next prime
	    $arrayIndex++;
	} else {
	    #divides evenly. not a prime number
	    $isPrime = 0;
	}
    }
    if ($isPrime == 1) {
	#new prime number discovered
	$primeArray[$arrayIndex] = $i;
	$sum = $sum + $i;
	print "$i is $arrayIndex prime, sum is $sum,\n";
    }
}
print "Sum of all primes below $limit is $sum\n";
