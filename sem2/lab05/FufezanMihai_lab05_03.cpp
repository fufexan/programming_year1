/*
 * Fufezan Mihai, 2012, lab05, ex 03
 *
 * Write a program that reads from the keyboard an array of maximum 10
 * characters and performs all the operations implemented in the class defined
 * at problem 3.
 */

#include "strClass.h"
#include <iostream>

using namespace std;

int main() {
  String string_ops;
  char str[11], c;

  cout << "Enter a string(max 10 chars): ";
  cin.getline(str, 11);

  // a
  cout << endl
       << "The string is " << string_ops.length(str) << " characters long."
       << endl;

  cout << endl << "Enter a character to search for in the string: ";
  cin >> c;

  // b & c
  cout << endl
       << c << " was found " << string_ops.occurences(str, c)
       << " times, and its last position is " << string_ops.lastPos(str, c)
       << "." << endl;

  // d
  cout << endl
       << "The string converted to uppercase is:" << endl
       << string_ops.toUpper(str);
}
