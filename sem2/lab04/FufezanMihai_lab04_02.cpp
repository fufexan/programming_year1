/*
 * Fufezan Mihai, 2012, lab04, ex 02
 *
 * Modify the program that implements the Quick-Sort algorithm so that it will
 * sort decreasingly the initial array of values.
 */

#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int *, int, int);

int main() {
  int n, x;
  int *arr = nullptr;

  // read size
  cout << "How many elements do you want to sort? ";
  cin >> n;
  arr = new int[n];

  // read elements
  cout << "Enter the elements:\n";
  for (int i = 0; i < n; i++) {
    cout << "[" << i << "] = ";
    cin >> arr[i];
  }

  // print initial array
  cout << "\nThe initial array is:\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';

  // print sorted array
  cout << "\nThe sorted array is:\n";
  quick_sort(arr, 0, n - 1);
  for (int i{}; i < n; i++)
    cout << arr[i] << ' ';
}

// function to find the partition position
int partition(int *array, int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] >= pivot) {

      // if element greater than pivot is found
      // swap it with the smaller element pointed by i
      i++;

      // swap element at i with element at j
      swap(array[i], array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(array[i + 1], array[high]);

  // return the partition point
  return (i + 1);
}

void quick_sort(int *array, int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quick_sort(array, low, pi - 1);

    // recursive call on the right of pivot
    quick_sort(array, pi + 1, high);
  }
}
