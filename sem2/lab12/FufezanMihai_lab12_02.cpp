/*
 * Fufezan Mihai, 2012, lab12, ex 02
 *
 * Write a C++ application that reads from the keyboard a series of values of
 * various types. Display the values using the standard manipulators.
 */

#include <iomanip>
#include <iostream>

using namespace std;

ostream &init(ostream &stream);

int main() {
  int a;
  float b;
  char c;
  double d;

  cout << "Enter an int, float, char, double: ";
  cin >> a >> b >> c >> d;

  cout << "Int: " << init << a << '\n';
  cout << "Float: " << init << b << '\n';
  cout << "Char: " << init << c << '\n';
  cout << "Double: " << init << d << '\n';
}

ostream &init(ostream &stream) {
  stream.width(15);
  stream.precision(8);
  return stream;
}
