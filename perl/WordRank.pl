#!/usr/bin/perl
#
# @File AthenaWordRank.pm
# @Author Jonathan Adams
#         jonathan.r.adams@gmail.com
# @Created Oct 13, 2014 11:53:38 AM
#

use strict;
use warnings;

print "Input your string:\n";
my $word = <STDIN>; #input word
chomp $word;
my @wordArray = split(//, $word); #switch to array
my $wordLength = @wordArray; #get the number of letters in the word
my @sortedWord = sort(@wordArray); #sort array to give each letter a value and compare to base case
my @fArray; #array to hold factorial values for each integer up to wordLength
#Set up hash values to track each letter's count, value, and following letter
my %letterCount;
my %letterValue;
my %nextLetter;
#Array to track which unique letters have more than one instance
my @repeatingLetters;
my $repeatIndex = 0;

for (my $i = 0; $i < $wordLength; $i++) {
    #check if we've seen the letter or if we're encountering it for the first time
    if ($letterCount{$sortedWord[$i]}) { #we've already seen this letter, increment
        $letterCount{$sortedWord[$i]} = $letterCount{$sortedWord[$i]} + 1;
        if ($letterCount{$sortedWord[$i]} == 2) {
            $repeatingLetters[$repeatIndex] = $sortedWord[$i];
            $repeatIndex++;
        }
    } else { #first time we've seen this letter
        $letterCount{$sortedWord[$i]} = 1;
        $letterValue{$sortedWord[$i]} = $i;
    }
    #Assign next letter for each letter in string. Handle end case specially
    if (($i + 1) == $wordLength) {
        $nextLetter{$sortedWord[$i]} = "null";
    } else {
        if ($sortedWord[$i] ne $sortedWord[$i+1]) {
            $nextLetter{$sortedWord[$i]} = $sortedWord[$i+1];
        }
    }
    #Create array to store all factorial values up to length of input word
    if ($i == 0) {
        $fArray[$i] = 1;
    } else {
        $fArray[$i] = $fArray[$i-1] * $i;
    }
}

my $rank = 1; #stores the rank of the input word

#Determine what the factorial divisor will be
my $factorialDivisor = 1;
if ($repeatingLetters[0]) { #if there are no repeats we simply divide by 1
    for (my $k = 0; $k < $repeatIndex; $k++) {
        $factorialDivisor = $factorialDivisor * $fArray[$letterCount{$repeatingLetters[$k]}];
    }
}

#Traverse the input word from most significant to least significant letter and add
# value as you go. Each letter has a value according to its place in the sorted
# array of all input letters. Each iteration, we add to the rank of our word using
# this general formula:
# rank = rank + (letterValue * ((letters remaining)! / product of (number of repeats)! for every repeating letter))
for (my $j = 0; $j < $wordLength; $j++) {
    my $currentLetter = $wordArray[$j];
    my $lettersRemaining = $wordLength - ($j + 1);
    my $tempLetterValue = $letterValue{$currentLetter};
    if ($tempLetterValue < 0) { #negative numbers will distort rank (shouldn't happen but just in case)
        $tempLetterValue = 0;
    }

    #We use this formula to determine rank:
    $rank = $rank + ($tempLetterValue * ($fArray[$lettersRemaining] / $factorialDivisor));

    if ($letterCount{$currentLetter} > 1) { #decrement local count for letter
		#update value of $factorialDivisor to reflect change in number of instances for this number
		$factorialDivisor = $factorialDivisor / $fArray[$letterCount{$currentLetter}] * $fArray[$letterCount{$currentLetter}-1];
        $letterCount{$currentLetter} = $letterCount{$currentLetter} - 1;
    } else {
        if ($letterCount{$currentLetter} <= 0) { #something is wrong
            print "Error: Seeing a letter that has been used up already!\n";
        } else { #letter's local count is set to 0
            $letterCount{$currentLetter} = $letterCount{$currentLetter} - 1;
        }
    }

    #Decrement letterValue for all following letters
    while ($nextLetter{$currentLetter} ne "null") {
        $currentLetter = $nextLetter{$currentLetter};
        $letterValue{$currentLetter} = $letterValue{$currentLetter} - 1;
    }
}
print "Rank for $word is $rank\n";
