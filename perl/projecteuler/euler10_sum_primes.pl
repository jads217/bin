#The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#Find the sum of all the primes below two million.
use strict;

#we initialize with 2 as the first prime number
my $sum = 2;
my $limit = 2000000;

#inefficient method storing array of prime numbers
#my @primeArray = [2];

#for (my $i = 3; $i < $limit; ($i=$i+2)) {
    #check if number is prime by dividing it against all previously discovered primes
#    my $isPrime = 1; #start with assumption that number is prime
#    my $arrayIndex = 0;
#    while (($primeArray[$arrayIndex]) && ($isPrime == 1)) {
#	if ($i % $primeArray[$arrayIndex]) {
#	    #does not divide evenly try the next prime
#	    $arrayIndex++;
#	} else {
#	    #divides evenly. not a prime number
#	    $isPrime = 0;
#	}
 #   }
#    if ($isPrime == 1) {
#	#new prime number discovered
#	$primeArray[$arrayIndex] = $i;
#	$sum = $sum + $i;
#	print "$i is $arrayIndex prime, sum is $sum,\n";
 #   }
#}
#print "Sum of all primes below $limit is $sum\n";

#efficient method using Sieve of Erasthemes
my $sievebound = ($limit-1) / 2; #last index of sieve
my @sieve = (0) x $sievebound; #initialized false
my $crosslimit = int((int(sqrt($limit))-1) / 2);
print "sievebound is $sievebound, crosslimit is $crosslimit\n";
for (my $i = 1; $i < $crosslimit; $i++) {
    if (!$sieve[$i]) {
	# 2*i+1 is prime, mark multiples
	for (my $j = 2*$i*($i+1); $j < $sievebound; $j= $j + 2*$i+1) {
	    $sieve[$j] = 1;
	}
    }
}
for (my $i = 1; $i < $sievebound; $i++) {
    if (!$sieve[$i]) {
	$sum = $sum + (2*$i+1);
    }
}
print "Sum of all primes below $limit is $sum\n";
