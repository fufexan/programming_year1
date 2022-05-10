/*
 * Fufezan Mihai, 2012, lab12, ex 01
 *
 * Write a C++ program that displays some numerical values in decimal, octal and
 * hexadecimal. Display the values left and right aligned, inside a field that
 * can hold 15 characters. Use the setfill() manipulator for setting the filling
 * character and the width() and precision() methods for setting the displaying
 * field size and the values representation precision.
 */

#include <iomanip>
#include <iostream>

using namespace std;

ostream &init(ostream &stream);

int main() {
  double a = 5.234567545233;
  cout << init << dec << a << '\n';
  cout << right << init << oct << a << '\n';
  cout << left << init << hex << a << '\n';
}

ostream &init(ostream &stream) {
  stream << setfill('$');
  stream.width(15);
  stream.precision(8);

  return stream;
}