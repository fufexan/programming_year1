/*
 * Fufezan Mihai, 2012, lab04, ex 04
 *
 * Write a C/C++ application that reads from the keyboard 2 arrays of positive
 * numbers. The program determines a 3-rd array that contains all the elements
 * in the initial arrays, increasingly ordered. The elements that have the same
 * value must appear a single time in the ordered array.
 */

#include <iostream>
#include <vector>

using namespace std;

int cmp(const void *a, const void *b);
void rmdup(vector<int> &v);

int main() {
  vector<int> a, b, c;
  int n, m, x;

  cout << "Enter the size of first array: ";
  cin >> n;
  cout << "Enter the size of second array: ";
  cin >> m;

  cout << "\nEnter the elements in the first array:\n";
  for (int i{}; i < n; i++) {
    cout << "[" << i << "] = ";
    cin >> x;
    a.push_back(x);
  }

  cout << "\nEnter the elements in the second array:\n";
  for (int i{}; i < m; i++) {
    cout << "[" << i << "] = ";
    cin >> x;
    b.push_back(x);
  }

  // merge arrays
  c = a;
  copy(b.begin(), b.end(), back_inserter(c));

  // sort resulting array
  qsort(&c[0], c.size(), sizeof(int), cmp);

  // remove duplicates
  rmdup(c);

  cout << "\nThe merged array with no duplicates is:\n";
  for (int i : c)
    cout << i << ' ';
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void rmdup(vector<int> &v) {
  for (int i{}; i < v.size() - 1; i++)
    if (v[i] == v[i + 1])
      v.erase(v.begin() + i + 1);
}