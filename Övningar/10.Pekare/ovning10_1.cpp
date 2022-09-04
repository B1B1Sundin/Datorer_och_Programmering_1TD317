//-------------------------------------------
// uppgift1.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a = 3;
  int *b = &a;

  cout << "\n b = " << b << endl;   // b = addressen för a
  cout << "\n *b = " << *b << endl; // *b = 3,
  cout << "\n a = " << a << endl;
  int c = 7;
  b = &c;
  cout << "\n b = " << b << endl;   // addressen av c
  cout << "\n *b = " << *b << endl; // *b = c = 5
  return 0;
}
