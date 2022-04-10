/*
 * Fufezan Mihai, 2012, lab04, ex 11
 *
 * Allocate an array of n integer numbers that will be read from the keyboard.
 * Read another value that represents a searching key. Using the lfind()
 * function, search and display all the positions in which the key appears in
 * the initial array. Handle the cases in which the key is found on more than 1
 * position or is not found at all. Sort the array using the qsort() function
 * and display the result. Use the bsearch() function for searching the same
 * key in the ordered array and print on the screen its positions.
 */

#include <iostream>
#include <search.h>
#include <vector>

using namespace std;

int cmp(const void *a, const void *b);

int main() {
  vector<int> v;
  int x, key;
  size_t n;

  cout << "Enter the number of elements you want to read: ";
  cin >> n;

  cout << "\nEnter the elements:\n";
  for (int i{}; i < n; i++) {
    cout << "[" << i << "] = ";
    cin >> x;
    v.push_back(x);
  }

  cout << "\nEnter an element to search for: ";
  cin >> key;

  int *p = (int *)lfind(&key, &v[0], &n, sizeof(int), cmp);

  if (p) {
    int pos, k{};
    size_t num;
    cout << "\nThe element was found on position(s): ";

    do {
      pos = p - &v[0] + 1;
      num = n - pos;
      k++;

      cout << pos - 1 << ' ';
    } while ((p = (int *)lfind(&key, &v[pos], &num, sizeof(int), cmp)));

    cout << "\nIt was found " << k << " time(s).";
  } else {
    cout << "\nThe element was not found.";
    return EXIT_FAILURE;
  }

  qsort(&v[0], n, sizeof(int), cmp);

  cout << "\n\nThe sorted array is:\n";
  for (int i : v)
    cout << i << ' ';

  p = (int *)bsearch(&key, &v[0], n, sizeof(int), cmp);
}

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}
