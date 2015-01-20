//Recursive fibonacci series
#include <iostream>

using namespace std;

unsigned long fibonacci(unsigned long);

int main() {
  unsigned long result, number;

  //obtain integer from user
  cout << "Enter an integer: ";
  cin >> number;

  //calculate fibonacci value for number input by user
  result = fibonacci(number);

  //display result
  cout << "Fibonacci(" << number << ") = " << result << endl;

  return 0;
}

//resursive definition of function fibonacci
unsigned long fibonacci(unsigned long n) {
  //base case
  if (n == 0 || n == 1)
    return n;

  //resursive step
  else
    return fibonacci(n-1) + fibonacci(n-2);
}
