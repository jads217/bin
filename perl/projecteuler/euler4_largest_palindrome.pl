#A palindromic number reads the same both ways. The largest palindrome made from the product of
# two 2-digit numbers is 9009 = 91 × 99.
#Find the largest palindrome made from the product of two 3-digit numbers.
use strict;

my $maxnum = 998001;
my $pal;
my $bit1 = 9;
my $bit2;
my $bit3;
my $solved = 0;

while ($bit1 >= 0 && $solved == 0) {
    $bit2 = 9;
    while ($bit2 >= 0 && $solved == 0) {
	if ($bit1 == 9 && $bit2 == 9) {
	    $bit3 = 7;
	}
	else {
	    $bit3 = 9;
	}
	while ($bit3 >= 0 && $solved == 0) {
	    $pal = $bit1 . $bit2 . $bit3 . $bit3 . $bit2 . $bit1;
	    print "palindrome is $pal\n";
	    $solved = find_factor($pal);
	    $bit3--;
	}
	$bit2--;
    }
    $bit1--;
}

print "Largest palindrome with two 3 digit factors is $solved\n";

sub find_factor {
    my $factor;
    my $num;
    for ($num = 999; $num >= 100; $num--) {
	if ($pal % $num) {
            #not a factor
	}
	else {
	    print "$num is a factor of $pal\n";
	    $factor = $pal / $num;
	    if (length $factor == 3) {
		print "Both factors ($num and $factor) are 3 digits\n";
		return $pal;
	    }
	    else {
		print "Second factor $factor is not 3 digits\n";
	    }
	}
    }
    #tried all 3 digit numbers
    return 0;
}
