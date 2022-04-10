/*
 * Fufezan Mihai, 2012, lab01, ex 07
 *
 * Write a program that performs a simple coding operation by increasing with 3
 * the value of the ASCII code of a character using macro functions. For
 * example, A becomes C, etc.
 */

#include <iostream>

using namespace std;

#define INC(a)                                                                 \
  { a += 3; }

int main() {
  char x;

  cout << "Enter a character: ";
  cin >> x;
  INC(x);
  cout << "The character increased with 3 is " << x << '.';
}
