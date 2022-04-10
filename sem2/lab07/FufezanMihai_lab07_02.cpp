/*
 * Fufezan Mihai, 2012, lab07, ex 02
 *
 * Write a C/C++ application that models in OOP a real numbers one dimensional
 * array. Instantiate two objects of this class with the same length n and store
 * in a third one the results of subtracting each of the two real number arrays’
 * elements. If the source arrays have different lengths, the result has the
 * length of the shortest array.
 */

#include <iostream>

using namespace std;

class NumberArray {
  int length;
  double *arr = nullptr;

public:
  NumberArray(int len = 0) {
    length = len;
    if (length > 0)
      arr = (double *)malloc(sizeof(double) * length);
  }
  //~NumberArray() { free(arr); }

  void setArray(double *arr, int length = sizeof(arr)) {
    this->arr = arr;
    this->length = length;
  }

  void resize(int pos) {
    if (length + pos < 0) {
      cerr << "Cannot allocate negative positions!\n";
      return;
    }

    length += pos;

    arr = (double *)realloc(arr, sizeof(double) * length);
  }

  void push(double x) {
    resize(1);

    arr[length - 1] = x;
  }

  double pop() {
    double x = arr[length - 1];

    resize(-1);

    return x;
  }

  int size() { return length; }

  // easy access
  double &operator[](int pos) {
    if (pos >= length || pos < 0) {
      cerr << "\nArray out of bounds!\n";
      exit(1);
    }
    return arr[pos];
  }

  NumberArray subtract(NumberArray x) {
    NumberArray res;

    // compute array
    for (int i{}; i < min(x.size(), this->size()); i++)
      res.push(arr[i] - x.arr[i]);

    return res;
  }

  void readArray() {
    cout << "\nEnter the size of the array: ";
    cin >> length;
    arr = (double *)malloc(sizeof(double) * length);
    cout << "Enter the elements:\n";
    for (int i{}; i < length; i++) {
      cout << "[" << i << "] = ";
      cin >> arr[i];
    }
  }
};

int main() {
  NumberArray arr1, arr2;

  cout << "\nFirst array:\n";
  arr1.readArray();

  cout << "\nSecond array:\n";
  arr2.readArray();

  cout << "\nArray 2 subtracted from Array 1:\n";
  arr1 = arr1.subtract(arr2);

  for (int i = 0; i < arr1.size(); i++)
    cout << arr1[i] << ' ';
}
