/*
 * Fufezan Mihai, 2012, lab04, ex 05
 *
 * Add some new sorting methods to the code presented in the examples area
 * (example 2 - selection sort, shell sort, etc.). Read from the keyboard the
 * number of elements from the array and pass it as parameter to each sorting
 * function. Compare the working times scored by each implemented sorting
 * algorithm.
 */

#include <iostream>
#include <vector>

using namespace std;

// tester function
template <class Func> int test_alg(int n, Func alg);

// main sorting functions
void selection(int *p, int n);
void bubble(int *p, int n);
void quick_sort(int *p, int r, int l = 0);
void shell_sort(int array[], int n);
void mergeSort(int arr[], int r, int l = 0);

// helper functions
void merge(int arr[], int p, int q, int r);
int cmp(const void *a, const void *b);
void printalg(double x, const char *alg);

// starters (should use 2 args, very hacky fix)
void quick_sort_jmpstart(int *p, int last) { quick_sort(p, last); }
void mergeSort_jmpstart(int *p, int last) { mergeSort(p, last); }
void qsort_jmpstart(int *p, int n) { qsort(p, n, sizeof(int), cmp); }

int main() {
  int n;
  int x;
  cout << "Enter the number of elements to generate: ";
  cin >> n;

  clock_t start, end;

  start = clock();

  vector<int> v;
  srand(time(0));
  for (int i{}; i < n; i++)
    v.push_back(rand());

  end = clock();

  cout << "\nGenerating " << n << " elements takes " << end - start
       << " clocks, " << (float)(end - start) / CLOCKS_PER_SEC * 1000
       << " ms.\n";

  cout << "\nThe algorithms' times are:\n";

  // Selection and Bubble are very slow at over 10000 elements
  x = test_alg(n, selection);
  printalg(x, "Selection sort");
  x = test_alg(n, bubble);
  printalg(x, "Bubble sort");

  x = test_alg(n, shell_sort);
  printalg(x, "Shell sort");
  x = test_alg(n, mergeSort_jmpstart);
  printalg(x, "Merge sort");
  x = test_alg(n, qsort_jmpstart);
  printalg(x, "Qsort");

  // something's wrong with this algorithm, it will sometimes cause a segfault
  x = test_alg(n, quick_sort_jmpstart);
  printalg(x, "Quick sort");
}

template <class Func> int test_alg(int n, Func alg) {
  clock_t start, end;
  vector<int> v;

  srand(time(0));
  for (int i{}; i < n; i++)
    v.push_back(rand());

  start = clock();

  alg(&v[0], n);

  end = clock();

  return end - start;
}

void selection(int *p, int n) {
  int minpos;

  for (int i = 0; i < n; i++) {
    minpos = i;
    for (int j = i + 1; j < n; j++)
      if (p[minpos] > p[j])
        minpos = j;

    swap(p[minpos], p[i]);
  }
}

void bubble(int *p, int n) {
  for (int i = 1; i < n; i++)
    for (int j = n - 1; j >= i; j--)
      if (p[j - 1] > p[j])
        swap(p[j], p[j - 1]);
}

void quick_sort(int *p, int r, int l) {
  int i, j, pivot;
  i = l;
  j = r;
  pivot = p[r];

  do {
    while (p[i] < pivot)
      i++;
    while (p[j] > pivot)
      j--;
    if (i < j)
      swap(p[i], p[j]);
    if (i <= j)
      j--, i++;
  } while (i < j);

  if (l < j)
    quick_sort(p, l, j);
  if (i < r)
    quick_sort(p, i, r);
}

void shell_sort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i], j;

      for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
        array[j] = array[j - interval];

      array[j] = temp;
    }
  }
}

// Merge two subarrays L and M into arr
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

// Divide the array into two subarrays, sort them and merge them
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

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void printalg(double x, const char *alg) {
  cout << (int)x << " clocks, " << x / CLOCKS_PER_SEC * 1000 << " ms, " << alg
       << endl;
}
