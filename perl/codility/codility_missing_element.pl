# you can use print for debugging purposes, e.g.
# print "this is a debug message\n";
use strict;

sub solution {
    my (@A)=@_;
    # write your code in Perl 5.14
    my $N = @A;
    my $missingElem = 0;
    my $i;
    #classic insertion sort
    for ($i = 1; $i < $N; $i++) {
        my $temp = @A[$i];
        my $j = $i;
        while (($j > 0) && ($A[$j-1] > $temp)) {
            @A[$j] = @A[$j-1];
            $j--;
        }
        @A[$j] = $temp;
    }

    #modified sort
#    for ($i = 0; $i < $N; $i++) {
#        if (($i + 1) == @A[$i]) {
#            print "integer @A[$i] is in correct place $i\n";
#        }
#        else {
            #place integer in it's correct spot
#            my $temp = @A[@A[$i]-1];
#            @A[@A[$i]-1] = @A[$i];
#        }
#    }
    
    #go over sorted array to find missing element
    print "sorted array @A\n";
    $i = 0;
    while (($missingElem == 0) && ($i < $N)) {
        if (($i + 1) == @A[$i]) {
#            print "integer @A[$i] is in correct place $i\n";
            $i++;
        }
        else {
            $missingElem = $i + 1;
        }
    }
    if ($missingElem == 0) {
        $missingElem = $N + 1;
    }
    print "Missing element is $missingElem\n";
    return $missingElem;
}
