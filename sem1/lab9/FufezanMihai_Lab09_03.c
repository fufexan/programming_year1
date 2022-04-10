/*
 * Fufezan Mihai, 2012, lab09, ex 3
 *
 * Write a C/C++ program that fills-up a float-type, one-dimensional array with
 * values read from the keyboard. Write a function that copies into another
 * array the values greater than the average of all elements from the array, by
 * using pointers. Both arrays should be displayed in the main() function.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void read_arr(int, float *);
float avg(int, float *);
void gt_avg2arr(int, int*, float *, float *);

int main() {
  int n, m;
  // read array size
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // read array
  float arr[n], arr2[n];
  read_arr(n, arr);

  // copy the values greater than average to a separate array
  gt_avg2arr(n, &m, arr, arr2);

  printf("The average value of the first array is %.1f\n", avg(n, arr));

  // print both arrays
  printf("\nThe first array is:\n");
  for(int i = 0; i < n; i++)
    printf("%.1f ", *(arr + i));

  printf("\nThe second array is:\n");
  for(int i = 0; i < m; i++)
    printf("%.1f ", *(arr2 + i));
}

void read_arr(int n, float *arr) {
  // reads an array
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%f", arr + i);
  }
}

float avg(int n, float *arr) {
  // compute the average value of an array
  float avg = 0;

  for (int i = 0; i < n; i++)
    avg += *(arr + i);

  return avg / n;
}

void gt_avg2arr(int n, int *m, float *arr, float *arr2) {
  // copy all elements greater than average to a second array
  float average = avg(n, arr);
  *m = 0;

  for (int i = 0; i < n; i++) {
    if (*(arr + i) > average)
      *(arr2 + (*m)++) = *(arr + i);
  }
}