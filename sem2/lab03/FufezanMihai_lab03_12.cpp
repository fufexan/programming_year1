/*
 * Fufezan Mihai, 2012, lab03, ex 12
 *
 * Using a file that contains real ordered numbers, look for a value read from
 * the keyboard. The searching method will rely on an iterative binary search,
 * the recursive algorithm and the bsearch() library function. Display the
 * values read from the file, the value to be searched and the position it was
 * found (if any).
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("numbers.txt");

int bsearch_i(vector<float> arr, int search_val);
int bsearch_r(vector<float> arr, int search_val, int first, int last);
int cmp(const void *a, const void *b);
void print_result(int pos, const char *type);

int main() {
  // declare variables & vector
  vector<float> arr{};
  float x, search_val;

  // read elements
  while (fin >> x)
    arr.push_back(x);

  // print array
  cout << "The array is:\n";
  for (float i : arr)
    cout << i << ' ';

  // take search value
  cout << "\nEnter a value to search: ";
  cin >> search_val;

  // print results
  print_result(bsearch_i(arr, search_val), "iterative");
  print_result(bsearch_r(arr, search_val, 0, arr.size() - 1), "recursive");

  // bsearch
  float *position =
      (float *)bsearch(&search_val, &arr[0], arr.size(), sizeof(float), cmp);
  float pos = position - &arr[0];

  // print result
  cout << "Using the stdlib bsearch function, the value ";
  if (position == nullptr)
    cout << "couldn't be found.";
  else
    cout << "was found at position " << pos + 1;
}

// binary search, iterative
int bsearch_i(vector<float> arr, int search_val) {
  bool found = false;
  int first = 0;
  int last = arr.size() - 1;
  int m;

  while (first <= last && !found) {
    m = (first + last) / 2;

    if (arr[m] == search_val)
      return m;
    else if (arr[m] < search_val)
      first = m + 1;
    else
      last = m - 1;
  }

  // fail
  return -1;
}

// binary search, recursive
int bsearch_r(vector<float> arr, int search_val, int first, int last) {
  int m = first + (last - first) / 2;

  if (first <= last) {
    if (arr[m] == search_val)
      return m;
    if (arr[m] > search_val)
      return bsearch_r(arr, search_val, first, m - 1);
    return bsearch_r(arr, search_val, m + 1, last);
  }

  // fail
  return -1;
}

int cmp(const void *a, const void *b) { return *(float *)a - *(float *)b; };

// print results based on position returned and type of algorithm
void print_result(int pos, const char *type) {
  cout << "Using the " << type << " algorithm, the value ";
  if (pos == -1)
    cout << "couldn't be found.";
  else
    cout << "was found at position " << pos + 1;
  cout << endl;
}
