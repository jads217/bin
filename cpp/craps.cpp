//Craps
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

int rollDice (void);

int main()
{
  //enumeration constants represent game status
  enum Status {CONTINUE, WON, LOST};

  int sum;
  int myPoint;

  Status gameStatus;
  // randomize random number generator using current time
  srand(time(0));
  sum = rollDice(); // first roll of the dice

  // determine game status and point based on sum of dice
  switch (sum) {
    // win on first roll
    case 7:
    case 11:
      gameStatus = WON;
      break;

    // lose on first roll
    case 2:
    case 3:
    case 12:
      gameStatus = LOST;
      break;

    // remember point
    default:
      gameStatus = CONTINUE;
      myPoint = sum;
      cout << "Point is " << myPoint << endl;
      break;
  } //end of switch

  // while game not complete...
  while (gameStatus == CONTINUE) {
    sum = rollDice(); // roll dice again
    //determine game status
    if (sum == myPoint) {
      gameStatus = WON;
    }
    else {
      if (sum == 7) {
	gameStatus = LOST;
      }
    }
  } //end while

  // display won or lost message
  if (gameStatus == WON) {
    cout << "Player wins" << endl;
  } else {
    cout << "Player loses" << endl;
  }

  return 0;
} //end main

// roll dice, calculate sum and display results
int rollDice(void) {
  int die1;
  int die2;
  int workSum;

  die1 = 1 + rand() % 6;
  die2 = 1 + rand() % 6;
  workSum = die1 + die2;

  cout << "Player rolled " << die1 << " + " << die2 << " = " << workSum << endl;

  return workSum;
} //end rollDice
