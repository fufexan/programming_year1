/*
 * Fufezan Mihai, 2012, lab03, ex 11
 *
 * Read from the keyboard a one-dimensional array of maximum 20 integer values.
 * Using the binary search mechanism, determine if another value a (also read
 * from the standard input) is part of the array. If so, determine and display
 * all its prime factors.
 */

#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

int cmp(const void *a, const void *b);
void prime_factors(int x, float div = 2.0f);

int main() {
  int arr[20], n, key;

  // read number of elements
  cout << "Enter the number of elements you want to add in the array(<=20): ";
  cin >> n;
  assert(n <= 20);

  // read elements
  cout << "Enter the elements:\n";
  for (int i{}; i < n; i++) {
    cout << "[" << i << "] = ";
    cin >> arr[i];
  }

  // read key
  cout << "\nEnter a value to search for in the array: ";
  cin >> key;

  // print key and its prime factors
  int *x = (int *)bsearch(&key, arr, n, sizeof(int), cmp);

  if (!x) {
    cout << "Element could not be found in array.";
    exit(1);
  }

  // print position and prime factors
  int pos = x - arr;
  cout << "\nElement was found on position " << pos
       << ". Its prime factors are:\n";
  prime_factors(key);
}

// bsearch compar function
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

// computes and displays the prime factors of an int, recursively
void prime_factors(int x, float div) {
  int power{}; // counts the power

  while (x / div == (int)(x / div)) {
    x /= div;
    power++;
  }

  if (power) {
    cout << div << '^' << power;
    if (x > div)
      cout << " * ";
  }

  if (x > div)
    prime_factors(x, div + 1);
}
