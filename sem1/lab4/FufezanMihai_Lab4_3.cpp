/*
 *  Fufezan Mihai, 2012, lab04, ex 3
 *
 *  Write a C/C++ application that defines an integer variable, initialized with
 *  several constant values. Display its value by overloading the << operator
 *  and by using the cout object.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  cout << a << endl;
  a = 4;
  cout << a << endl;
  a = 8;
  cout << a << endl;

  return 0;
}
