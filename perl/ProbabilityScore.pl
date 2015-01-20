use strict;
use warnings;

my @probArray;
my %probScores;
for (my $i = 0; $i <= 10; $i++) {
    $probArray[$i] = Prob($i,5);
    $probScores{$probArray[$i]} = $i;
    print "Probability of a $i is $probArray[$i]\n";
}
@probArray = sort(@probArray);
@probArray = reverse(@probArray);
my @scoreProbArray;
my @scoreArray;
#We know the most likely combination is the highest probability score with itself.
$scoreProbArray[0] = $probArray[0] * $probArray[0];
$scoreArray[0] = "$probScores{$probArray[0]}-$probScores{$probArray[0]}";
for (my $j = 0; $j < 5; $j++) {
    for (my $k = $j; $k < 5; $k++) {
	my $index = 1;
	my $arrayLength = @scoreProbArray;
	if ($k == 0) {
	    #We already did this combo, move on
	} else {
	    my $tempProb = $probArray[$j] * $probArray[$k];
	    while ($tempProb < $scoreProbArray[$index]) {
		$index++;
	    }
	    if ($j == $k) {
		@scoreProbArray = (@scoreProbArray[0..($index-1)],$tempProb,@scoreProbArray[$index..$arrayLength]);
		@scoreArray = (@scoreArray[0..($index-1)],"$probScores{$probArray[$j]}-$probScores{$probArray[$k]}",@scoreArray[$index..$arrayLength]);
	    } else {
		@scoreProbArray = (@scoreProbArray[0..($index-1)],$tempProb,$tempProb,@scoreProbArray[$index..$arrayLength]);
		@scoreArray = (@scoreArray[0..($index-1)],"$probScores{$probArray[$j]}-$probScores{$probArray[$k]}","$probScores{$probArray[$k]}-$probScores{$probArray[$j]}",@scoreArray[$index..$arrayLength]);
	    }
	}
    }
}
print "The ten most likely scores with corresponding probability are:\n";
for (my $m = 0; $m < 10; $m++) {
    my $n = $m + 1;
    print "$n. $scoreArray[$m] ($scoreProbArray[$m])\n";
}

sub Prob {
    my $s = $_[0];
    my $r = $_[1];
    if ($r == 1) {
	if ($s == 0) {
	    return 0.5;
	} elsif ($s == 1) {
	    return 0.3;
	} elsif ($s == 2) {
	    return 0.2;
	} else {
	  #  print "Bad Case!\n";
	    return 0;
	}
    } else {
	if ($s == 0) {
	    return 0.5*Prob($s,($r-1));
	} elsif ($s == 1) {
	    return 0.5*Prob($s,($r-1)) + 0.3*Prob(($s-1),($r-1));
	} else {
	    return 0.5*Prob($s,($r-1)) + 0.3*Prob(($s-1),($r-1)) + 0.2*Prob(($s-2),($r-1));
	}
    }
}
