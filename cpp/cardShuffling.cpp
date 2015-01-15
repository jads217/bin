//Card shuffling dealing program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[]);

int main() {
  //initialize suit array
  const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  //initialize face array
  const char *face[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                          "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  //initialize deck array
  int deck[4][13] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, 
		     {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}, 
                     {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39}, 
                     {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52}};

  srand(time(0)); // seed random number generator

  cout << "*** Unshuffled Deck ***\n";
  deal(deck, face, suit);
  shuffle(deck);
  cout << "\n*** Shuffled Deck ***\n\n";
  deal(deck, face, suit);

  return 0;

} //main

void shuffle(int wDeck[][13]) {
  int row;
  int column;
  int randrow;
  int randcolumn;
  int temp;
  //for each of the 52 cards, choose slot of deck randomly
  for (int row = 0; row <= 3; row++) {
    for (int column = 0; column <= 12; column++) {
      //swap with random location
      randrow = rand() % 4;
      randcolumn = rand() % 13;
      temp = wDeck[row][column];
      wDeck[row][column] = wDeck[randrow][randcolumn];
      wDeck[randrow][randcolumn] = temp;
    }
  }

} //shuffle

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]) {
  int suit;
  int face;
  //loop through rows of wDeck
  for (int row = 0; row <= 3; row++) {
    //loop through columns of wDeck for current row
    for (int column = 0; column <= 12; column++) {
      //determine suit and face of given card
      if (wDeck[row][column] < 14) {
	suit = 0;
	face = wDeck[row][column] - 1;
      } else {
	suit = floor((wDeck[row][column] - 1) / 13);
	face = (wDeck[row][column] - 1) % 13;
      }
      cout << wFace[face] << " of " << wSuit[suit] << '\n';
    }
  }
} //deal
