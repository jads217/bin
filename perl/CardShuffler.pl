#program to shuffle a 52 card deck
use strict;
use warnings;

my @deck = (1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13);
my @shuffledDeck = Shuffle(@deck);
print "shuffled deck is @shuffledDeck\n";

my $win = 0;
my $loss = 0;
my @preferredSlot = (0,0,1,2,3,4,4,5,6,7,8,8,9);
my @slotArray;
my $index = 0;
while (($win < 10) && ($loss < 6)) {
    my $card = $shuffledDeck[$index];
    print "Drawn card is $card\n";
    my $slot = $preferredSlot[$card-1];
    print "preferred slot is $slot\n";
    if ($slotArray[$slot]) {
	if ($slotArray[$slot] == $card) {
	    print "Throw away $card, no penalty\n";
	} elsif ($card > $slotArray[$slot]) {
	    #see if we can place it in next slot
	    if (($slot + 1) < 10) {
		if ($slotArray[$slot+1]) {
		    if ($card == $slotArray[$slot+1]) {
			print "Throw away $card, no penalty\n";
		    } else {
			$loss++;
			print "$card collided with $slotArray[$slot] and $slotArray[$slot+1], discard #$loss\n";
		    }
		} else {
		    $slotArray[$slot+1] = $card;
		    $win++;
		    print "place $card in open slot ($slot+1), $win placed\n";
		}
	    } else {
		$loss++;
		print "$card bounded, discard #$loss\n";
	    }
	} else {
	    #card is smaller than card in slot, see if we can put it in previous slot
	    if (($slot - 1) >= 0) {
		if ($slotArray[$slot-1]) {
		    if ($card == $slotArray[$slot-1]) {
			print "Throw away $card, no penalty\n";
		    } else {
			#another collision, discard
			$loss++;
			print "$card collided with $slotArray[$slot] and $slotArray[$slot-1], discard #$loss\n";
		    }
		} else {
		    #place card in open slot
		    $slotArray[$slot-1] = $card;
		    $win++;
		    print "place $card in open slot ($slot-1), $win placed\n";
		}
	    } else {
		#we are bounded, discard
		$loss++;
		print "$card bounded, discard #$loss\n";
	    }
	}
    } else {
	#place card in open slot
	$slotArray[$slot] = $card;
	$win++;
	print "place $card in open slot $slot, $win placed\n";
    }
    $index++;
}
if ($win == 10) {
    print "You won the game!\n";
} elsif ($loss == 6) {
    print "You lost :(\n";
}
print "Game Over - Slots: @slotArray\n";

sub Shuffle {
    @deck = @_;
    for (my $i = 0; $i < 52; $i++) {
	my $deckSize = (@deck-1);
	my $randNum = int(rand($deckSize));
#	print "deck size is $deckSize, randnum is $randNum\n";
	$shuffledDeck[$i] = $deck[$randNum];
	if ($randNum == 0) {
	    @deck = (@deck[($randNum+1)..$deckSize]);
	} elsif ($randNum == $deckSize) {
	    @deck = (@deck[0..($randNum-1)]);
	} else {
	    @deck = (@deck[0..($randNum-1)],@deck[($randNum+1)..$deckSize]);
	}
    }
    return @shuffledDeck;
}
