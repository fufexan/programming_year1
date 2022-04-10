/*
 *  Fufezan Mihai, 2012, lab04, ex 6
 *
 *  Define several symbolic constants of different types (integer numbers, real
 *  numbers, arrays of characters). Display their values using cout and the <<
 *  operator.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
  const int integer = 5;
  const float real = 34.67;
  const char *chstr = "string of characters";

  cout << integer << endl;
  cout << real << endl;
  cout << chstr << endl;

  return 0;
}
