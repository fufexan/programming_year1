/*
 * Fufezan Mihai, 2012, lab01, ex 06
 *
 * Determine the minimum of a 10 float numbers from a one dimensional array
 * (implicit values or from the KB) using a function with a variable number of
 * parameters. The first 7 values will be considered initially, next the last 3,
 * and at the end these 2 values.
 */

#include <iostream>
#include <cstdarg>

using namespace std;

float minimum(int n, ...);

int main() {
  int n = 10;
  float arr[n];

  cout << "Enter 10 numbers:\n";
  for (int i = 0; i < n; i++) {
    cout << '[' << i << "] = ";
    cin >> arr[i];
  }

  cout << "\nThe minimum of all the numbers is: "
       << minimum(n, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6],
                  arr[7], arr[8], arr[9]);
}

float minimum(int n, ...) {
  // define variables
  double min, val;

  // define variable array
  va_list va;
  va_start(va, n);

  // check elements
  min = va_arg(va, double);
  for (int i = 0; i < n - 1; i++) {
    val = va_arg(va, double);
    if (val < min)
      min = val;
  }

  // end variable array and return
  va_end(va);
  return min;
}
