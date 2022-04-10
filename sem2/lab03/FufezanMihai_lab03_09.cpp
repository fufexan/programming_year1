/*
 * Fufezan Mihai, 2012, lab03, ex 09
 *
 * Write a C/C++ application that generates max 10 integer random values and
 * stores them in an array. Check if another randomly generated value belongs to
 * this array, using _lsearch() function.
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int cmp(const void *a, const void *b);

int main() {
  int n = 10, key;
  vector<int> arr{};
  srand(time(0));

  cout << "The generated array is:\n";
  for (int i = 0; i < n; i++) {
    arr.push_back(rand());
    cout << arr.back() << ' ';
  }

  key = rand();
  cout << "\nThe search term is " << key << ".\n";

  int *search = (int *)lsearch(&key, &arr[0], n, sizeof(int), cmp);

  if (!search) {
    cout << "Search term isn't in the array!";
    exit(1);
  } else {
    cout << "The search term was found on position " << search - &arr[0];
  }
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
