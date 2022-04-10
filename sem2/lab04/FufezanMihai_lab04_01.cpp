/*
 * Fufezan Mihai, 2012, lab04, ex 01
 *
 * Implement the Bubble-Sort method using a flag indicator and optimize the
 * inner loop. Write the function that orders an array of integer values read
 * from the keyboard. Display the original and the sorted arrays.
 */

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &);

int main() {
  int n, x;
  vector<int> arr;

  // read size
  cout << "How many elements do you want to sort? ";
  cin >> n;

  // read elements
  cout << "Enter the elements:\n";
  for (int i = 0; i < n; i++) {
    cout << "[" << i << "] = ";
    cin >> x;
    arr.push_back(x);
  }

  // print initial array
  cout << "\nThe initial array is:\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';

  // print sorted array
  cout << "\nThe sorted array is:\n";
  bubble_sort(arr);
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
}

void bubble_sort(vector<int> &arr) {
  bool sorted;
  do {
    sorted = false;
    for (int i = 0; i < arr.size() - 1; i++)
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        sorted = true;
      }
  } while (sorted);
}
