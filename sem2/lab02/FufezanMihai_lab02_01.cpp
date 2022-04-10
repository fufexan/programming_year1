/*
 * Fufezan Mihai, 2012, lab02, ex 01
 *
 * Write a recursive function that calculates k-permutations p(n, k), where n
 * and k are read form the keyboard, k<n. Verify the result using the factorial
 * definition.
 */

#include <cassert>
#include <iostream>

using namespace std;

int arrangements(int, int);
int factorial(int);

int main() {
  int n, k;

  cout << "Enter n and k for an arrangement (n > k): ";
  cin >> n >> k;
  assert(n > k);
  cout << "The k-permutations result using its function is: "
       << arrangements(n, k) << "\nand using the factorial function it is "
       << factorial(n) / factorial(n - k);
}

int arrangements(int n, int k) {
  if (k == 1)
    return n;
  if (n == 0)
    return 1;
  else
    return n * arrangements(n - 1, k - 1);
}

int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}
