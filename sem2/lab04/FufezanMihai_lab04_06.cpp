/*
 * Fufezan Mihai, 2012, lab04, ex 06
 *
 * Read from the keyboard an array of m integers and an integer value n<m. Split
 * the array in 2 subarrays as it follows:
 * a) the first subarray will contain the first n elements of the initial array
 * b) the second subarray will contain the rest elements of the initial array
 * Realize the following operations:
 * - sort increasingly the subarrays
 * - sort the initial array, by interlacing the sorted subarrays (merge-sort)
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int arr[], int r, int l = 0);
void merge(int arr[], int p, int q, int r);

int main() {
  vector<int> v, s1, s2;
  int n, m, x;

  // read array length
  cout << "How long is the array? ";
  cin >> m;

  // read subarray1 length
  cout << "How long is the subarray? (less than array length) ";
  cin >> n;

  // check that subarray is smaller than array
  assert(n < m);

  // read array
  cout << "Enter an array of integers:\n";
  for (int i{}; i < m; i++) {
    cout << "[" << i << "] = ";
    cin >> x;
    v.push_back(x);
  }

  // copy the subarrays
  copy_n(v.begin(), n, back_inserter(s1));
  copy(v.begin() + n, v.end(), back_inserter(s2));

  // sort the two subarrays
  mergeSort(&s1[0], 0, s1.size() - 1);
  mergeSort(&s2[0], 0, s2.size() - 1);

  // merge the arrays
  v.clear();
  copy(s1.begin(), s1.end(), back_inserter(v));
  copy(s2.begin(), s2.end(), back_inserter(v));

  sort(v.begin(), v.end());

  cout << "\nThe sorted array using merge sort is:\n";
  for (int i : v)
    cout << i << ' ';
}

void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int r, int l) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}