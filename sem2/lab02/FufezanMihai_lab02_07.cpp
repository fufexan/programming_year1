/*
 * Fufezan Mihai, 2012, lab02, ex 07
 *
 * Calculate the sum of the odd numbers from an array of integer values, using a
 * recursive function. The numbers from the array are read from a file. The
 * first value in the array represents the array’s length.
 */

#include <fstream>
#include <iostream>

using namespace std;

ifstream fi("numbers.txt");

int sum_odd(int *arr, int n);

int main() {
  int n;

  fi >> n;
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
    fi >> arr[i];

  cout << "The sum of all odd elements in the array is: " << sum_odd(arr, n);
  
  delete[] arr;
}

int sum_odd(int *arr, int n) {
  if (n != 0) {
    if (arr[n - 1] % 2)
      return (arr[n - 1] + sum_odd(arr, n - 1));
    else
      return sum_odd(arr, n - 1);
  }
  return 0;
}
