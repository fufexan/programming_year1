/*
 * Fufezan Mihai, 2012, lab02, ex 10
 *
 * Consider a one dimensional array of n (<=30) integer_values. Determine
 * (recursively and non-recursively) the number of times a certain value x read
 * from the keyboard appears in the array.
 */

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int apparitions(vector<int>);
int rec_apparitions(vector<int>);

int x;

int main() {
  vector<int> arr;
  int n;

  cout << "Enter the number of elements in an array: ";
  cin >> n;
  assert(n <= 30);

  cout << "Enter the values: ";
  for (int i = 0; i < n; i++) {
    cout << '[' << i << "] = ";
    cin >> x;
    arr.push_back(x);
  }

  cout << "Enter an element to count how many times it appears: ";
  cin >> x;

  cout << "\nUsing loops, " << x << " appeared " << apparitions(arr)
       << " times.";
  cout << "\nUsing recursion, " << x << " appeared " << rec_apparitions(arr)
       << " times.";
}

int apparitions(vector<int> arr) {
  int times{};

  for (int i : arr)
    if (i == x)
      times++;

  return times;
}

int rec_apparitions(vector<int> arr) {
  if (!arr.empty()) {
    int le = arr.back();
    arr.pop_back();

    if (le == x) {
      return 1 + rec_apparitions(arr);
    } else
      return rec_apparitions(arr);
  }
  return 0;
}
