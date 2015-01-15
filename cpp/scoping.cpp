// A scoping example
#include <iostream>

using namespace std;

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x = 1; // global variable

int main()
{
  int x = 5; //local variable to main

  cout << "local x in main's outer scope is " << x << endl;

  { // start new scope
    int x = 7;
    cout << "local x in main's inner scope is " << x << endl;
  }

  cout << "local x in main's outer scope is " << x << endl;

  useLocal();
  useStaticLocal();
  useGlobal();
  useLocal();
  useStaticLocal();
  useGlobal();

  cout << "\nlocal x in main is " << x << endl;
} //main

//useLocal reinitializes local variable x during each call
void useLocal(void) {
  int x = 25;
  cout << endl << "local x is " << x << " on entering useLocal" << endl;
  ++x;
  cout << "local x is " << x << " on exiting useLocal" << endl;
}

//useStaticLocal initializes static local variable x only the first time
// the function is called; value of x is saved between calls to this function
void useStaticLocal(void) {
  //initialized only the first time useStaticLocal is called
  static int x = 50;
  cout << endl << "local static x is " << x << " on entering useStaticLocal" << endl;
  ++x;
  cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
}

//useGlobal modifies global variable x during each call
void useGlobal(void) {
  cout << endl << "global x is " << x << " on entering useGlobal" << endl;
  x *= 10;
  cout << "global x is " << x << " on exiting useGlobal" << endl;
}
