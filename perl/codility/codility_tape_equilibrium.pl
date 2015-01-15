# you can use print for debugging purposes, e.g.
# print "this is a debug message\n";
use strict;
use List::Util qw(sum);

sub solution {
    my (@A)=@_;
    # write your code in Perl 5.14
    my $N = @A;
    my $lowSum;
    my $highSum;
    my $difference;
    my $endLoop;

    #another solution
    my $j = 0;
    my $k = $N - 1;
    $lowSum = @A[$j];
    $highSum = @A[$k];
    print "low is $lowSum, high is $highSum\n";
    while ($j < ($k-1)) {
        if ($lowSum < $highSum) {
            if (@A[$k-1] < 0) {
                $k--;
                $highSum = $highSum + @A[$k];
            }
            else {
                $j++;
                $lowSum = $lowSum + @A[$j];
            }
        }
        else {
            if (@A[$j+1] < 0) {
                $j++;
                $lowSum = $lowSum + @A[$j];
            }
            else {
                $k--;
                $highSum = $highSum + @A[$k];
            }
        }
        print "low is $lowSum, high is $highSum\n";
    }
    $difference = abs($highSum - $lowSum);
    print "difference is $difference\n";
    return $difference;

    # Start as close to the middle of the array as possible
##    my $P = (int $N / 2);
#    print "P starts as $P in size $N array\n";
##    my @low = @A;
 ##   splice @low,$P,$N-$P;
  ##  my @high = @A;
##    splice @high,0,$P;
 ##   $lowSum = sum(@low);
  ##  $highSum = sum(@high);
#    $lowSum = 0;
#    $highSum = 0;
#    my $i;
#    for ($i = 0; $i < $N; $i++) {
#        if ($i < $P) {
#            $lowSum = $lowSum + @A[$i];
#        }
#        else {
#            $highSum = $highSum + @A[$i];
#        }
#    }
    #set up initial conditions for comparing values of arrays
##    if ($lowSum == $highSum) {
 ##       $difference = 0;
  ##      $endLoop = 1;
##        return $difference;
 ##   }
  ##  else {
##        $difference = 1000;
 ##       $endLoop = 0;
  ##  }
    #loop will determine which direction to travel for finding lowest difference
##    while ($endLoop == 0) {
 ##       if ($lowSum > $highSum) {
  ##          print "Low sum is bigger\n";
##            if (($lowSum - $highSum) > $difference) {
 ##               print "the difference is only going to get bigger so we're done\n";
  ##              $endLoop = 1;
##                return $difference;
 ##           }
  ##          else {
##                print "assign new difference, move P to the left and re-calculate sums\n";
 ##               $difference = $lowSum - $highSum;
  ##              $P = $P - 1;
##                $lowSum = $lowSum - @A[$P];
 ##               $highSum = $highSum + @A[$P];
  ##              $endLoop = 0;
##            }
 ##       }
  ##      else {
##            print "High sum is bigger\n";
 ##           if (($highSum - $lowSum) > $difference) {
  ##              print "the difference is only going to get bigger\n";
##                $endLoop = 1;
 ##               return $difference;
  ##          }
##            else {
 ##               print "assign new difference, move P to the right and re-calculate sums\n";
  ##              $difference = $highSum - $lowSum;
##                $P = $P + 1;
 ##               $lowSum = $lowSum + @A[$P];
  ##              $highSum = $highSum - @A[$P];
##                $endLoop = 0;
 ##           }
  ##      }
##    }

}
