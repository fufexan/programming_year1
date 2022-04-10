/*
 * Fufezan Mihai, 2012, lab02, ex 06
 *
 * Determine the scalar product of 2 vectors using a recursive function
 * (one-dimensional array same dimension).
 */

#include <iostream>

using namespace std;

int scalar(int *a, int *b, int size);

int main() {
  int n;

  cout << "Enter the number of elements you want to enter: ";
  cin >> n;

  int *a = new int[n];
  int *b = new int[n];

  cout << "Enter the elements for the first array:\n";
  for (int i = 0; i < n; i++) {
    cout << '[' << i << "] = ";
    cin >> a[i];
  }
  cout << "Enter the elements for the second array:\n";
  for (int i = 0; i < n; i++) {
    cout << '[' << i << "] = ";
    cin >> b[i];
  }

  cout << "The scalar product of the two arrays is " << scalar(a, b, n);

  delete[] a;
  delete[] b;
}

int scalar(int *a, int *b, int size) {
  if (size != 0)
    return (a[size - 1] * b[size - 1] + scalar(a, b, size - 1));
  return 0;
}
