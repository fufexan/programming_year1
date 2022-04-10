/*
 * Fufezan Mihai, 2012, lab02, ex 03
 *
 * Calculate the greatest common divider of 2 numbers using a recursive
 * function.
 */

#include <iostream>

using namespace std;

int gcd(int, int);

int main() {
  int a, b;

  cout << "Enter 2 numbers to find the greatest common divisor: ";
  cin >> a >> b;
  cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b);
}

int gcd(int a, int b) {
  if (a == 0 || b == 0 || a == b)
    return min(a, b);

  if (a > b)
    return gcd(a - b, b);
  else
    return gcd(a, b - a);
}
