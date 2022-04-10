/*
 * Fufezan Mihai, 2012, lab02, ex 11
 *
 * Read from the keyboard a positive integer value n (base 10). Use a recursive
 * function for converting n into another base 1<b<10, also read from the
 * keyboard
 */

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

string convert(int n, int base);

int main() {
  int n, base;

  cout << "Enter a number to convert: ";
  cin >> n;
  cout << "Enter a base to convert to (2-10): ";
  cin >> base;
  assert(base <= 10);

  cout << "The number " << n << " converted to base " << base << " is "
       << convert(n, base);
}

string convert(int n, int base) {
  if (n == 0 or base == 1)
    return "";

  return convert(n / base, base) +
         std::string{static_cast<char>(n % base + '0')};
}
