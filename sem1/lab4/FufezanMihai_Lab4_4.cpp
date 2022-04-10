/*
 *  Fufezan Mihai, 2012, lab04, ex 4
 *
 *  Define an array of characters that will be displayed using cout. Display
 *  enother character arrays and use escape sequences. Verify the usage of the
 *  whitespaces.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
  const char *s1 = "doing c/c++\n";
  const char *s2 = "\ttab example\n";
  const char *s3 = "\\yet another\rexample\n";

  cout << s1 << s2 << s3;

  return 0;
}
