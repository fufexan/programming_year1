/*
 * Fufezan Mihai, 2012, lab11, ex 05
 *
 * Define an abstract class that contains 3 pure virtual methods declarations
 * for concatenating, interlacing two arrays of characters and for reverting the
 * character array received as parameter. A subclass implements the methods
 * declared in the base class. Instantiate the 2-nd class and display the
 * results produced by applying the methods mentioned above upon some data read
 * from the keyboard. Examine the error given by the attempt of instantiating
 * the base class.
 */

#include <iostream>
using namespace std;
#include "FufezanMihai_lab11_05.hpp"

int main() {
  char str1[500], str2[500];

  cout << "Enter 2 strings:\n";
  cin >> str1 >> str2;

  SubCharr sc;
  cout << "\nConcatenated string: " << sc.concat(str1, str2);
  cout << "\nInterlaced string: " << sc.interlace(str1, str2);
  cout << "\nFirst string reversed: " << sc.reverse(str1);
}
