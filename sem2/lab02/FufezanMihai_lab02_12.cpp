/*
 * Fufezan Mihai, 2012, lab02, ex 12
 *
 * Consider the 2-nd degree equation x^2 – sx + p = 0. Without calculating the
 * solutions x1 and x2 determine, if it is possible, Sn = x1^n + x2^n using this
 * sum’s recursive definition:
 * Sum(n) = { 2, if n=0;
 *            s, if n=1;
 *            s*Sum(n-1) – p*Sum(n-2), if n>1;
 * }
 * s and p are float values, n is an integer value, all read from the keyboard.
 */

#include <cassert>
#include <iostream>

using namespace std;

float sum(int);

float s, p;

int main() {
  int n;

  cout << "Enter the coefficient for x and the free term in a 2nd degree "
          "polynomial: ";
  cin >> s >> p;
  cout << "Enter a number n, which will help compute the function (>0): ";
  cin >> n;
  assert(n >= 0);

  cout << "Without calculating the roots x1 or x2, the solution is: " << sum(n);
}

float sum(int n) {
  if (n == 0)
    return 2;
  else if (n == 1)
    return s;
  else {
    return s * sum(n - 1) - p * sum(n - 2);
  }
}
