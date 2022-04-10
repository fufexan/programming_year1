/*
 * Fufezan Mihai, 2012, lab02, ex 02
 *
 * Write a recursive function that calculates c(n, k), where n and k are read
 * from the keyboard, k<n.
 */

#include <cassert>
#include <iostream>

using namespace std;

int combination(int, int);
int factorial(int);

int main() {
  int n, k;

  cout << "Enter n and k for a combination: ";
  cin >> n >> k;
  assert(n > k);

  cout << "The combination has the result " << combination(n, k)
       << "\nAnd the result computed using factorials is "
       << factorial(n) / (factorial(k) * factorial(n - k));
}

int combination(int n, int k) {
  if (k == 0 || k == n)
    return 1;
  else
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int factorial(int n) { return n == 0 ? 1 : n * factorial(n - 1); }
