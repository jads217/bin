//Recursive factorial function
#include <iostream>
#include <iomanip>

using namespace std;

unsigned long factorial(unsigned long);

int main() {
  //loop 10 times. During each iteration, calculate factorial( i ) and display result
  for (int i = 0; i <=10; i++)
    cout << setw(2) << i << "! = " << factorial(i) << endl;

  return 0;
}

unsigned long factorial(unsigned long number) {
  //base case
  if (number <= 1)
    return 1;
  else
    return number * factorial(number - 1);
}
