/*
 * Fufezan Mihai, 2012, lab01, ex 08
 *
 * Write a program that displays the name of the program, the compilation date
 * and time and the number of code lines included in the program using standard
 * macrofunctions.
 */

#include <iostream>

using namespace std;

int main() {
  cout << "The name of the program is: " << __FILE__ << ".\n";
  cout << "It contains " << __LINE__ + 2 << " lines.\n";
  cout << "It was compiled on " << __DATE__ << " at " << __TIME__ <<  ".\n";
}
