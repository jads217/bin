#The sum of the squares of the first ten natural numbers is,
#1^2 + 2^2 + ... + 10^2 = 385
#The square of the sum of the first ten natural numbers is,
#(1 + 2 + ... + 10)^2 = 552 = 3025
#Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
#Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
use strict;

my $sumSquares = 0;
my $simpleSum = 0;
my $squareSum = 0;
my $difference = 0;

for (my $i = 1; $i <= 100; $i++) {
    $simpleSum = $simpleSum + $i;
    $sumSquares = $sumSquares + ($i * $i);
}
$squareSum = $simpleSum * $simpleSum;
$difference = $squareSum - $sumSquares;
print "The sum of squares is $sumSquares, the square of sums is $squareSum, the difference is $difference\n";

#simple arithmetic solution
my $limit = 100;
my $sum = $limit * ($limit + 1) / 2;
my $sum_sq = (2* $limit + 1) * ($limit + 1) * $limit / 6;
$difference = ($sum * $sum) - $sum_sq;
print "The difference is $difference\n";
