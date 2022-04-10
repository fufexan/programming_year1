/*
 * Fufezan Mihai, 2012, lab02, ex 13
 *
 * Write a program that calculates recursively and non-recursively (two distinct
 * functions) the value of the harmonic series sn=1/1+1/2+1/3+...1/n, where n is
 * a natural number. Call the functions with 2 different values for n.
 */

#include <iostream>

using namespace std;

long double harmonic(int);

int main() {
  int n;

  cout << "Enter a value to calculate the harmonic series for: ";
  cin >> n;

  cout << "The harmonic series is: " << harmonic(n);
}

long double harmonic(int n) {
  if (n == 0)
    return 0;
  else
    return (1.0f / n) + harmonic(n - 1);
}
