# you can use print for debugging purposes, e.g.
# print "this is a debug message\n";
use strict;

my @A;
my @B;
$A[0] = 2;
$A[1] = 2;
$A[2] = 1;
$A[3] = 0;
$A[4] = 1;
$A[5] = 10;
$A[6] = 2;
$A[7] = 3;
$A[8] = 10;

my $cover = 0;
my $i = 0;
my $N = @A;
while ($i <= $N) {
    if (!$B[$A[$i]]) {
        print "$A[$i] has not been seen yet. updating cover to $i\n";
        $B[$A[$i]] = 1;
        $cover = $i;
		}
		else {
        $i++;
		}
}
print "The first covering prefix is $cover\n";

