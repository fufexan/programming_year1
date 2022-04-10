/*
 * Fufezan Mihai, 2012, lab03, ex 07
 *
 * Write a program that uses the „divide et impera” method for determining the
 * greatest common divider of a series of maximum 2000 values stored in an
 * array. All the numbers are entered from the keyboard or read from a
 * previously created file.
 */

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b);
int gcd_vector(vector<int> v, int first, int last);

int main() {
  vector<int> v{};
  int n;

  cout << "Enter the number of elements you want in the array: ";
  cin >> n;

  cout << "\nEnter the elements:\n";
  int x;
  for (int i = 0; i < n; i++) {
    cout << "[" << i << "] = ";
    cin >> x;
    v.push_back(x);
  }

  cout << "\nThe Greatest Common Divisor of the array is "
       << gcd_vector(v, 0, n - 1);
}

int gcd(int a, int b) {
  int r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int gcd_vector(vector<int> v, int first, int last) {
  int x{}, y{};

  if (first == last)
    return v[first];

  x = abs(gcd_vector(v, first, (first + last) / 2));
  y = abs(gcd_vector(v, (first + last) / 2 + 1, last));

  while (x != y) {
    if (x > y)
      x -= y;
    else
      y -= x;
  }

  return x;
}
