/*
 * Fufezan Mihai, 2012, lab02, ex 08
 *
 * Using the code developed for the previous problem, calculate the sum of the
 * prime numbers in the array.
 */

#include <fstream>
#include <iostream>

using namespace std;

ifstream fi("numbers.txt");

bool prime(int x);
int sum_prime(int *arr, int n);

int main() {
  int n;

  fi >> n;
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
    fi >> arr[i];

  cout << "The sum of all prime elements in the array is: "
       << sum_prime(arr, n);

  delete[] arr;
}

bool prime(int x) {
  if (x == 2)
    return true;
  else if (x == 1 || x % 2 == 0)
    return false;
  else {
    for (int i = 3; i * i <= x; i += 2)
      if (x % i == 0)
        return false;
  }

  return true;
}

int sum_prime(int *arr, int n) {
  if (n != 0) {
    if (prime(arr[n - 1]))
      return (arr[n - 1] + sum_prime(arr, n - 1));
    else
      return sum_prime(arr, n - 1);
  }
  return 0;
}